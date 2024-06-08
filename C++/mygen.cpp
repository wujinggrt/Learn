#include <bits/elements_of.h>
#include <cassert>

#include <cstddef>
#include <vector>
#include <format>
#include <generator>
#include <iostream>
#include <ostream>
#include <ranges>
#include <string_view>

std::generator<char> wrap(std::string_view sv) {
  for (char c : sv) {
    std::println(std::cout, "I will co_yield {}", c);
    co_yield c;
  }
}

std::generator<char> bar() {
  auto sv = "test";
  auto g = wrap(sv);
  // 调用yield_value 4
  co_yield std::ranges::elements_of{g};
}

std::generator<char> bar2() {
  auto sv = "test";
  auto wg = wrap(sv);
  // 调用版本3
  co_yield std::ranges::elements_of{std::move(wg)};
}

std::generator<char> foo1() {
  for (auto c : std::string_view{"test"}) {
    co_yield c;
  }
}

std::generator<char> foo2() {
  co_yield 't';
  for (auto c : std::string_view{"est"}) {
    co_yield c;
  }
}

std::generator<char> print_l_one() {
  co_yield 'l';
}

std::generator<int> print_l_two() {
  co_yield 'l';
}

template<typename T>
struct CharO {
  T value{static_cast<T>('o')};
  struct Iterator {
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    T* p{};
    T&& operator*() const {
      if (!p) {
        assert(false);
      }
      return std::move(*p);
    }

    Iterator& operator++() {
      p = {};
      return *this;
    }

    Iterator operator++(int) {
      Iterator ret{p};
      ++*this;
      return ret;
    }
    friend bool operator==(const Iterator& iter, std::default_sentinel_t) noexcept {
      return iter.p == nullptr;
    }
  };
  Iterator begin() {
    return {&value};
  }
  std::default_sentinel_t end() const noexcept { return std::default_sentinel; }
};

std::generator<char> overloaded1() {
  co_yield 'h';  // 调用重载1
  char c = 'e';
  co_yield c; // 调用重载2
  // elements_of的range数据成员是右值引用，调用重载3
  co_yield std::ranges::elements_of{print_l_one()};
  // co_yield el;
  // generator::begin()返回的迭代器在解引用后，可以转换为char&&类型
  // 调用重载调用4
  auto g = print_l_two();
  co_yield std::ranges::elements_of{g}; // 调用重载4
  // 编译失败，因为对array.begin()返回的迭代器解引用的类型是char&，
  // 不能够转换为char&&
  // co_yield std::ranges::elements_of{std::array{'o'}};
  // 自定义类模板调用begin()返回的迭代器解引用为int&&，随后可以类型转化为char&&
  // 调用重载调用4
  co_yield std::ranges::elements_of{CharO<int>{}};
}

std::generator<char&, char> overloaded2() {
  // co_yield 't'; // compile error
  for (auto c : std::string_view{"est"}) {
    co_yield c;
  }
}

int main() {
  auto g = overloaded1();
  for (char c : g) {
    std::cout << c;
  }
  std::cout << '\n';
}