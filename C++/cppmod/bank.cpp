#include <atomic>
#include <chrono>
#include <array>
#include <format>
#include <iostream>
#include <thread>
using namespace std;
using namespace std::chrono_literals;

void foo() {
  atomic transfer{10};
  int account_a = 20;
  int account_b = 20;
  const int total = account_a + account_b;
  std::jthread t1{[&transfer, &account_a] {
    // 设置占用一个cacheline
    // 看看会不会整合到一起
    int val = 3;
    array<int32_t, 2048> a1{};
    val = transfer.load(std::memory_order_relaxed);
    account_a -= val;
    val -= a1[20];
    transfer.store(val, memory_order_relaxed);
  }};
  std::jthread t2{[&account_b] {
    int val = 10;
    account_b += val;
  }};
  t1.join();
  t2.join();
  if (account_a + account_b != total)
    cout << format("account_a is {}, account_b is {}\n", account_a, account_b);
}

int main() {
  for (int i = 0; i < 1e8; ++i) foo();
}