#include <climits>
#include <iostream>
#include <random>
#include <utility>

int random_int() {
  static std::random_device r;
  static std::mt19937 gen(r());
  static std::uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
  return dist(gen);
}

struct TreapNode {
  TreapNode(int value) : value{value}, size{1}, rank{random_int()}, repeat{1} {}

  void update_size() {
    size = repeat;
    if (left) size += left->size;
    if (right) size += right->size;
  }

  TreapNode *left{};
  TreapNode *right{};
  int value;
  int size;
  int rank;
  int repeat;
};

struct Treap {
  Treap() : root{nullptr} {}

  /**
   * Split the tree into two subtrees, one containing all the elements smaller
   * or equal to val, and the other containing all the elements greater than
   * val. return {<= val, > val};
   */
  std::pair<TreapNode *, TreapNode *> split(TreapNode *root, int val) {
    if (!root) {
      return {nullptr, nullptr};
    }
    if (root->value > val) {
      auto [l, r] = split(root->left, val);
      root->left = r;
      root->update_size();
      return {l, root};
    }
    auto [l, r] = split(root->right, val);
    root->right = l;
    root->update_size();
    return {root, r};
  }

  std::tuple<TreapNode *, TreapNode *, TreapNode *> split_by_rank(
      TreapNode *root, int rank) {
    if (!root) {
      return {nullptr, nullptr, nullptr};
    }
    const int left_szie = root->left ? root->left->size : 0;
    if (left_szie >= rank) {
      auto [l, m, r] = split_by_rank(root->left, rank);
      root->left = r;
      root->update_size();
      return {l, m, root};
    } else if (left_szie + root->repeat >= rank) {
      // left_size < rank && left_size + root->repeat >= rank
      auto l = std::exchange(root->left, nullptr);
      auto r = std::exchange(root->right, nullptr);
      return {l, root, r};
    } else {
      // left_size + root->repeat < rank
      auto [l, m, r] =
          split_by_rank(root->right, rank - left_szie - root->repeat);
      root->right = l;
      root->update_size();
      return {root, m, r};
    }
  }

  // u的值全部小于v的值。
  TreapNode *merge(TreapNode *u, TreapNode *v) {
    if (!u || !v) {
      return u ? u : v;
    }
    if (u->rank < v->rank) {
      // 维护小根堆，将u作为新的root
      u->right = merge(u->right, v);
      u->update_size();
      return u;
    }
    // v的rank更小，维护小根堆需要将v的left与u合并
    v->left = merge(u, v->left);
    v->update_size();
    return v;
  }

  void insert(int val) {
    auto [less_or_equal, greater] = split(root, val);
    auto [l, r] = split(less_or_equal, val - 1);
    if (r) {
      r->repeat++;
      r->update_size();
    } else {
      r = new TreapNode(val);
    }
    root = merge(merge(l, r), greater);
  }

  void remove(int val) {
    auto [less_or_equal, greater] = split(root, val);
    auto [l, r] = split(less_or_equal, val - 1);
    if (r) {
      if (r->repeat > 1) {
        r->repeat--;
        r->update_size();
        l = merge(l, r);
      } else {
        delete r;
        r = nullptr;
      }
    }
    root = merge(l, greater);
  }

  int query_rank_by_val(TreapNode *root, int val) {
    auto [less, greater_or_equal] = split(root, val - 1);
    const int result = 1 + (less ? less->size : 0);
    root = merge(less, greater_or_equal);
    return result;
  }

  int query_val_by_rank(TreapNode *root, int rank) {
    auto [l, m, r] = split_by_rank(root, rank);
    if (!m) {
      return INT_MIN;
    }
    const int result = m->value;
    root = merge(merge(l, m), r);
    return result;
  }

  int query_predecessor(int val) {
    auto [less, greater_or_equal] = split(root, val - 1);
    if (!less) {
      return INT_MIN;
    }
    const int result = query_val_by_rank(less, less->size);
    root = merge(less, greater_or_equal);
    return result;
  }

  int query_successor(int val) {
    auto [less_or_equal, greater] = split(root, val);
    if (!greater) {
      return INT_MAX;
    }
    const int result = query_val_by_rank(greater, 1);
    root = merge(less_or_equal, greater);
    return result;
  }

  TreapNode *root;
};

int main() {
  Treap t;
  t.insert(106465);
  using namespace std;
  std::cout << t.query_val_by_rank(t.root, 1) << "\n";
  t.insert(317721);
  t.insert(460929);
  t.insert(644985);
  t.insert(84185);
  t.insert(89851);
  cout << t.query_successor(81968) << endl;
  t.insert(492737);
  cout << t.query_predecessor(493598) << endl;
}