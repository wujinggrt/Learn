import torch
import torch.nn as nn
import math

class MultiHeadAttention(nn.Module):
    def __init__(self, hidden_dim=256, num_heads=4):
        """
        hidden_dim: 输入的维度
        num_heads: 输入分成的注意头数量

        维护的是
        """
        super().__init__()
        self.hidden_dim = hidden_dim
        self.num_heads = num_heads
        assert hidden_dim % num_heads == 0, "hidden_dim must be the integer times of num_heads"
        # query, key, value, and output
        # learning parameter matrices由一下layer维护
        self.Wq = nn.Linear(hidden_dim, hidden_dim, bias=False)
        self.Wk = nn.Linear(hidden_dim, hidden_dim, bias=False)
        self.Wv = nn.Linear(hidden_dim, hidden_dim, bias=False)
        # multi-head attention最后一步，在num_heads的结果输出后，将这些向量concat，并输入此fc
        self.Wo = nn.Linear(hidden_dim, hidden_dim, bias=False)

    def _check_scaled_dot_product_attention_inputs(self, x):
        """
        check scaled dot-product attention inputs
        """
        assert x.size(1) == self.num_heads, f"expects that x has shape as:" \
             f" ({-1, self.num_heads, -1, self.hidden_dim // self.num_heads})," \
             f"but get {x.size()}"
        assert x.size(3) == self.hidden_dim

    def _scaled_dot_product_attention(self, query, key, value, 
                                      attention_mask=None, key_padding_mask=None):
        """
        query: tensor, shape is (batch_size, num_heads, query_sequence_length, hidden_dim // num_heads)
        key: tensor, shape is (batch_size, num_heads, key_sequence_length, hidden_dim // num_heads)
        value: tensor, shape is (batch_size, num_heads, value_sequence_length, hidden_dim // num_heads)
        attention_mask: tensor, shape is (query_sequence_length, key_sequence_length)
        key_padding_mask: tensor, shape is (sequence_length, key_sequence_length)

        query最开始是(batch_size, query_sequence_length, hidden_dim)的,w，经过split_into_heads后的结果。
        """
        self._check_scaled_dot_product_attention_inputs(query)
        self._check_scaled_dot_product_attention_inputs(key)
        self._check_scaled_dot_product_attention_inputs(value)

        d_k = key.size(-1)
        tgt_len, src_len = query.size(-2), key.size(-2)

        # logits = (B, H, tgt_len, E) * (B, H, E, src_len) = (B, H, tgt_len, src_len)
        logits = torch.matmul(query, key.transpose(-2, -1)) / math.sqrt(d_k)

        # 注意力遮罩
        if attention_mask:
            if attention_mask.dim() == 2:
                assert attention_mask.size() == (tgt_len, src_len)
                # 广播到 (1, query_sequence_length, key_sequence_length)
                attention_mask = attention_mask.unsqueeze(0)
                logits = logits + attention_mask
            else:
                raise ValueError(f"attention_mask.size() is invalid: {attention_mask.size()}")

        if key_padding_mask:
            # Broadcast to fit logits
            # 广播到 query_sequence_length, 1, 1, key_sequence_length)
            key_padding_mask = key_padding_mask.unsqueeze(1).unsqueeze(2)
            logits = logits + key_padding_mask
        
        attention = torch.softmax(logits, dim=-1)
        # (batch_size, num_heads, sequence_length, hidden_dim)
        output = torch.matmul(attention, value)
        return output, attention

    def _split_into_heads(self, x):
        batch_size, seq_length, hidden_dim = x.size()
        d_k = hidden_dim // self.num_heads
        x = x.view(batch_size, seq_length, self.num_heads, d_k)
        # 最终返回(batch_size, num_heads, seq_length, hidden_dim // num_heads)
        return x.transpose(1, 2)

    # 上一个方法的逆操作
    def _combine_heads(self, x):
        batch_size, num_heads, seq_length, head_hidden_dim = x.size()
        return x.transpose(1, 2).contiguous().view(
            batch_size, seq_length, num_heads * head_hidden_dim
        )

    def forward(self, q, k, v, attention_mask=None, key_padding_mask=None):
        """
        q: tensor, shape is (batch_size, query_sequence_length, hidden_dim)
        k: tensor, shape is (batch_size, key_sequence_length, hidden_dim)
        v: tensor, shape is (batch_size, value_sequence_length, hidden_dim)
        attention_mask: tensor, shape is (query_sequence_length, key_sequence_length)
        key_padding_mask: tensor, shape is (sequence_length, key_sequence_length)
        """
        q = self.Wq(q)
        k = self.Wk(k)
        v = self.Wv(v)

        q = self._split_into_heads(q)
        k = self._split_into_heads(k)
        v = self._split_into_heads(v)

        attention_values, attention_weights = self._scaled_dot_product_attention(
            q, k, v, attention_mask, key_padding_mask)
        grouped = self._combine_heads(attention_values)
        output = self.Wo(grouped)

        self.attention_weights = attention_weights
        return output

class PositionalEncoding(nn.Module):
    def __init__(self, d_model, dropout=0.1, max_len=5000):
        super().__init__()
        self.dropout = dropout
        
        pe = torch.zeros(max_len, d_model)
        # shape: (max_len, 1)
        positions = torch.arange(max_len, dtype=torch.float).unsqueeze(1)
        # 10000^((2*i)/d_model)
        division_term = torch.exp(torch.arange(0, d_model, 2).float() * 
                                  (-math.log(10_000) / d_model) )
        pe[:, 0::2] = torch.sin(positions / division_term);
        pe[:, 1::2] = torch.cos(positions / division_term);
        # shape: (1, max_len, d_model)
        pe = pe.unsqueeze(0)
        self.register_buffer("pe", pe)

    def forward(self, x):
        """
        x: Tensor, shape is [batch_size, sequence_length, embedding_dim]
        """
        # 通过广播，每个batch，都会在pe[0, :x.size(1), :]处加上对应的结果。
        x = x + self.pe[:, :x.size(1), :]
        return x

class PositionWiseFeedForward(nn.Module):
    def __init__(self, d_model: int, d_ff: int):
        super().__init__()
        self.fc1 = nn.Linear(d_model, d_ff)
        self.relu = nn.ReLU()
        self.fc2 = nn.Linear(d_ff, d_model)

    def forward(self, x):
        x = self.fc1(x)
        x = self.relu(x)
        x = self.fc2(x)
        return x

class EncoderBlock(nn.Module):
    def __init__(self, n_dim: int, dropout: float, n_heads: int) -> None:
        super().__init__()
        self.mha = MultiHeadAttention(hidden_dim=n_dim, num_heads=n_heads)
        self.norm1 = nn.LayerNorm(n_dim)
        self.dropout = nn.Dropout(dropout)
        self.feed_forward = PositionWiseFeedForward(n_dim, n_dim)
        self.norm2 = nn.LayerNorm(n_dim)

    def forward(self, x, src_padding_mask=None):
        assert x.ndim == 3, f"Expected input to be 3-dim, got {x.ndim}"
        attention_output = self.mha(x, x, x, key_padding_mask=src_padding_mask)
        attention_output = self.norm1(attention_output)
        x = x + self.dropout(attention_output)

        x = self.feed_forward(x)
        x = self.norm2(x)
        return x

class Encoder(nn.Module):
    def __init__(self, vocab_size: int, n_dim: int, 
                 dropout: float, n_encoder_blocks: int, n_heads: int) -> None:
        super().__init__()
        self.n_dim = n_dim
        self.embedding = nn.Embedding(num_embeddings=vocab_size, embedding_dim=n_dim)
        self.positional_encoding = PositionalEncoding(n_dim, dropout=dropout)
        self.encoder_blocks = nn.ModuleList(
            [EncoderBlock(n_dim, dropout, n_heads) for _ in range(n_encoder_blocks)])
        
    def forward(self, x, padding_mask=None):
        # Transformer论文中，指出需要对embedding vector乘以sqrt(d_model)
        x = self.embedding(x) * math.sqrt(self.n_dim)
        x = self.positional_encoding(x)
        for block in self.encoder_blocks:
            x = block(x, padding_mask)
        return x

class DecoderBlock(nn.Module):
    def __init__(self, n_dim: int, dropout: float, n_heads: int) -> None:
        super().__init__()
        # The first multi-head attention is to be masked to prevent seeing the future infomations.
        self.self_attention = MultiHeadAttention(hidden_dim=n_dim, num_heads=n_heads)
        self.norm1 = nn.LayerNorm(n_dim)
        # The second multi-head attention takes the outputs from encoder
        self.cross_attention = MultiHeadAttention(hidden_dim=n_dim, num_heads=n_heads)
        self.norm2 = nn.LayerNorm(n_dim)

        self.feed_forward = PositionWiseFeedForward(n_dim, n_dim)
        self.norm3 = nn.LayerNorm(n_dim)

    def forward(self, tgt, memory, tgt_mask=None, tgt_padding_mask=None, memory_padding_mask=None):
        """
        memory: come from encoder
        """
        masked_attention_output = self.self_attention(
            q=tgt, k=tgt, v=tgt, attention_mask=tgt_mask, key_padding_mask=tgt_padding_mask
        )
        x1 = tgt + self.norm1(masked_attention_output)

        cross_attention_output = self.cross_attention(
            q=x1, k=memory, v=memory, attention_mask=None, key_padding_mask=memory_padding_mask
        )
        x2 = x1 + self.norm2(cross_attention_output)
        ff_output = self.feed_forward(x2)
        output = x2 + self.norm3(ff_output)
        return output

class Decoder(nn.Module):
    def __init__(self, vocab_size: int, n_dim: int, dropout: float, n_decoder_blocks: int, n_heads: int) -> None:
        super().__init__()
        self.embedding = nn.Embedding(num_embeddings=vocab_size, embedding_dim=n_dim)
        self.positional_encoding = PositionalEncoding(d_model=n_dim, dropout=dropout)
        self.decoder_blocks = nn.ModuleList([
            DecoderBlock(n_dim=n_dim, dropout=dropout, n_heads=n_heads) for _ in range(n_decoder_blocks)
        ])

    def forward(self, tgt, memory, tgt_mask=None, tgt_padding_mask=None, memory_padding_mask=None):
        x = self.embedding(tgt)
        x = self.positional_encoding(x)
        for block in self.decoder_blocks:
            x = block(tgt=x, memory=memory, tgt_mask=tgt_mask, 
                      tgt_padding_mask=tgt_padding_mask, memory_padding_mask=memory_padding_mask)
        return x