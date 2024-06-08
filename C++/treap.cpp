#include <climits>
#include <iostream>
#include <random>

int random_int() {
  static std::random_device r;
  static std::mt19937 gen(r());
  static std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
  return dist(gen);
}

struct TreapNode {
  TreapNode(int value) : value{value}, size{1}, rank{random_int()} {}

  TreapNode *left{};
  TreapNode *right{};
  int value;
  int size;
  int rank;
};

int query_pre(int val) {             // 要查前驱的权值
  auto temp = split(root, val - 1);  // 按照 val-1 分裂

  if (temp.first == nullptr) {  // 前驱不存在
    return -2147483647;
  }

  int res = query_val_by_rank(temp.first, temp.first->siz);
  root = merge(temp.first, temp.second);  // 最后合并回去
  return res;
}