import torch
import time
import torch.nn as nn
import numpy as np
import matplotlib.pyplot as plt

from tqdm import tqdm
from torch.utils.data import Dataset
from torch.nn.utils.rnn import pad_sequence
from mpl_toolkits.axes_grid1 import ImageGrid

# 定义小型数据集，用于反转单词，比如"helloworld"->"dlrowolleh"
PAD_IDX = 0
SOS_IDX = 1
EOS_IDX = 2

np.random.seed(0)

def generate_random_string():
    len = np.random.randint(10, 20)
    return "".join([chr(x) for x in np.random.randint(97, 97+26, len)])

class ReverseDataset(Dataset):
    def __init__(self, n_samples, pad_idx, sos_idx, eos_idx):
        super().__init__()
        self.pad_idx = pad_idx
        self.sos_idx = sos_idx
        self.eos_idx = eos_idx
        self.values = [generate_random_string() for _ in range(n_samples)]
        self.labels = [x[::-1] for x in self.values]

    def __len__(self):
        return len(self.values)

    def __getitem__(self, index) -> Any:
        return self.text_transform(self.values[index].rstrip("\n")), \
            self.text_transform(self.labels[index].rstrip("\n"))

    def text_transform(self, x):
        return torch.tensor([self.sos_idx] + [ord(z)-97+3 for z in x] +
                            [self.eos_idx])

def train(model, optimizer, loader, loss_fn, epoch):
    model.train()
    losses = 0
    acc = 0
    history_loss = []
    history_acc = []

    with tqdm(loader, position=0, leave=True) as tepoch:
        for x, y in tepoch:
            tepoch.set_description(f"Epoch {epoch}")

            optimizer.zero_grad()
            logits = model(x, y[:, :-1])
            loss = loss_fn(logits.contiguous().view(-1, model.vocab_size), 
                           y[:, 1:].conguous().view(-1))
            loss.backward()
            optimizer.step()
            losses += loss

            preds = logits.softmax(dim=-1)
            masked_pred = preds * (y[:, 1:] != PAD_IDX)
            accuracy = (masked_pred == y[:, 1:]).float().mean()
            acc += accuracy.item()

            history_loss.append(loss.item())
            history_acc.append(accuracy.item())
            tepoch.set_postfix(loss=loss.item(), accuracy=100. * accuracy.item())
    return losses / len(list(loader)), acc / len(list(loader)), history_loss, history_acc

def evaluate(model, loader, loss_fn):
    model.eval()
    losses = 0
    acc = 0
    history_loss = []
    history_acc = []

    for x, y in tqdm(loader, position=0, leave=True):
        logits = model(x, y[:, :-1])
        loss = loss_fn(logits.contiguous().view(-1, model.vocab_size), 
                        y[:, 1:].conguous().view(-1))
        losses += loss

        preds = logits.softmax(dim=-1)
        masked_pred = preds * (y[:, 1:] != PAD_IDX)
        accuracy = (masked_pred == y[:, 1:]).float().mean()
        acc += accuracy.item()

        history_loss.append(loss.item())
        history_acc.append(accuracy.item())
    return losses / len(list(loader)), acc / len(list(loader)), history_loss, history_acc

def collate_fn(batch):
    """
    此函数使用PAD_IDX填充输入，使得批次
    """
    src_batch, tgt_batch = [], []
    for src_sample, tgt_sample in batch:
        src_batch.append(src_sample)
        tgt_batch.append(tgt_sample)
    src_batch = pad_sequence(src_batch, padding_value=PAD_IDX, batch_first=True)
    tgt_batch = pad_sequence(tgt_batch, padding_value=PAD_IDX, batch_first=True)
    return src_batch, tgt_batch

# hyperparameters
args = {
    "vocab_size": 128,
    "model_dim": 128,
    "dropout": 0.1,
    "n_encoder_layers": 1,
    "n_decoder_layers": 1,
    "n_heads": 4
}
