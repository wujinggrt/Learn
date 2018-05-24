#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree; // 动态分配数组存储huffman tree

typedef char **HuffmanCode; // 动态分配数组存储huffmancode

void Select(HuffmanTree *pHT, int n, int *s1, int *s2);

// Huffmancode的第一格单元不用，也就是pHC[0]是没有存储数据的
// 利用指针来当做引用
// 对pHT指针指向的HuffmanTree构建，结果存储在pHC里面
void HuffmanCoding(HuffmanTree *pHT, HuffmanCode *pHC, int *w, int n);

// 打印huffmancode每个对应的的编码
void PrintHuffmanCode(const char *words, const HuffmanCode *phc, int size);

// n是元素个数
// dst: 使用了malloc申请了空间
void HuffmanDecoding(const char *src, char **dst, const HuffmanTree *pht, const char *words, int n);

void RunCode();

int main()
{
	RunCode();
	return 0;
}

// 输出上s1 < s2，这儿只是序号大小的比较而已
void Select(HuffmanTree *pHT, int n, int *s1, int *s2)
{
	// weight:s1_weight > s2_weight，所以只比较s1与(*pHT)[i],
	// 如果 .weight < s1_weight,在比较s2,小于S2再交换
	unsigned int s1_weight = UINT_MAX;
	unsigned int s2_weight = UINT_MAX;
	for (int i = 1; i <= n; ++i)
	{
		 if ((*pHT)[i].weight < s1_weight && (*pHT)[i].parent == 0)
		 {
			 *s1 = i;
			 s1_weight = (*pHT)[i].weight;
			 // 交换s1, s2，如果s1 < s2
			 if (s1_weight < s2_weight)
			 {
				 int temp_s = *s2;
				 unsigned int temp_weight = s2_weight;
				 *s2 = *s1;
				 s2_weight = s1_weight;
				 *s1 = temp_s;
				 s1_weight = temp_weight;
			 }
		 }
	}
	// 这儿是为了和书上输出一致，序号上的顺序
	if (*s1 > *s2)
	{
		int i_temp = *s1;
		*s1 = *s2;
		*s2 = i_temp;
	}
} 
			
void HuffmanCoding(HuffmanTree *pHT, HuffmanCode *pHC, int *w, int n)
{
	// w存放字符的权值（大于0）， 构造huffman tree，求出n个字符的huffman code
	if (n <= 1)
	{
		return;
	}
	// huffman tree值存在度为0， 2的树
	int m = 2 * n - 1;
	*pHT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); // 0号单元不用
	int i;
	HuffmanTree p;
	// 初始化
	p = *pHT;
	p->weight = 0;
	p->parent = 0;
	p->lchild = 0;
	p->rchild = 0;
	for (p = *pHT + 1, i = 1; i <= n; ++i, ++p, ++w)
	{
		p->weight = *w;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for( ; i <= m; ++i, ++p)
	{
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	// 构建huffman tree
	for (i = n + 1; i <= m; ++i)
	{
		int s1 = 0;
		int s2 = 0;
		// parent 为0，weight最小
		// s1 < s2
		Select(pHT, i - 1, &s1, &s2);
		(*pHT)[s1].parent = i;
		(*pHT)[s2].parent = i;
		(*pHT)[i].lchild = s1;
		(*pHT)[i].rchild = s2;
		(*pHT)[i].weight = (*pHT)[s1].weight + (*pHT)[s2].weight;
	}	
	// 从叶子到根逆向求编码
	*pHC = (HuffmanCode)malloc((n + 1) * sizeof(char *)); // 分配n个字符编码的头指针向量
	(*pHC)[0] = NULL;
	char *cd = (char *)malloc(n * sizeof(char)); // 编码的工作空间
	cd[n - 1] = '\0';
	for(i = 1; i <= n; ++i)
	{ 
		int start = n - 1;
		// from leaves to root
		int f;
		int c;
		for (c = i, f = (*pHT)[i].parent; f != 0; c = f, f = (*pHT)[f].parent)
		{
			if ((*pHT)[f].lchild == c)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
		}
		(*pHC)[i] = (char *)malloc((n - start) * sizeof(char)); // 分配第i个字符的编码空间
		strcpy((*pHC)[i], &cd[start]); // 从start开始到n-1
	}
	free(cd);
}// HuffmanCoding

void AssignWeight(char *s, int **w, char **word)
{
	int length = strlen(s);
	char *s_temp = (char *)malloc((length + 1) * sizeof(char));
	s_temp[length] = '\0';
	int last = 0; // word中最后一个字符位子
	// 把字符添加到word中
	for (int i = 0; i < length; ++i)
	{
		int exist = 0;
		for (int j = 0; j < last; ++j)
		{
			if (s_temp[j] == s[i])
			{
				exist = 1;
			}
		}
		if (!exist)
		{
			s_temp[last++] = s[i];
		}	
	}
	s_temp[last] = '\0';
	*word = (char *)malloc((last + 1) * sizeof(char));
	strcpy(*word, s_temp);
	free(s_temp);
	s_temp = NULL;
	// count the number of characters
	*w = (int *)malloc(last * sizeof(int));
	for (int i = 0; i < last; ++i)
	{
		int count = 0;
		for (int j = 0; j < length; ++j)
		{
			if ((*word)[i] == s[j])
			{
				++count;
			}
		}
		(*w)[i] = count;
	}
}
			
void PrintHuffmanCode(const char *words, const HuffmanCode *phc, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%c %s\n", words[i], (*phc)[i + 1]);
	}
}

// src以#结束
void HuffmanDecoding(const char *src, char **dst, const HuffmanTree *pht, const char *words, int n)
{
	int length = strlen(src);
	char *temp = (char *)malloc((length + 1)* sizeof(char));
	temp[length] = '\0';
	HuffmanTree p = (*pht) + 2 * n - 1;
	int temp_pos = 0;
	for (int i = 0; i < length && src[i] != '#'; ++i)
	{
		int direction = src[i] - '0';
		// code 为 1，向右边
		if (direction && p->rchild != 0)
		{
			p = *pht + p->rchild;
		}
		else if (p->lchild != 0)
		{
			p = *pht + p->lchild;
		}
		if (!p->lchild || !p->rchild)
		{
			int pos = p - *pht;						
			temp[temp_pos++] = words[pos - 1];
			temp[temp_pos++] = ' ';
			
			p = (*pht) + 2 * n - 1;
		}
	}
	temp[temp_pos] = '\0';
	*dst = (char *)malloc(temp_pos * sizeof(char));
	strcpy(*dst, temp);
	free(temp);
}

void RunCode()
{
	int *w;
	int n;
	HuffmanTree ht;
	HuffmanCode hc;
	scanf("%d", &n);
	// 忽略换行符，下同
	getchar();
	w = (int *)malloc(n * sizeof(int));
	char *words = (char *)malloc((n) * sizeof(char));
	for (int i = 0; i < n; ++i)
	{
		scanf("%c %d", words + i, w + i);
		// 忽略换行符，下同
		getchar();
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%c %d\n", words[i], w[i]);
	}
	const int MAX_BUFFER = 200;
	char coded_string[MAX_BUFFER];
	scanf("%s", coded_string);
	getchar();
	// 构建huffman
	printf("%s\n", coded_string);
	HuffmanCoding(&ht, &hc, w, n);
	PrintHuffmanCode(words, &hc, n);
	// 解码
	char *decoded_string = NULL;
	HuffmanDecoding(coded_string, &decoded_string, &ht, words, n);
	printf("%s", decoded_string);
}