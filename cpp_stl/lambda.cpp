#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
  int a = 0;
  auto f = [&a](int x) -> int {
    a++;
    return x * x;
  };

  auto f1 = [a](int x) mutable -> int {
    a++;
    return x * x;
  };

  std::cout << f(5) << std::endl;
  std::cout << f1(5) << std::endl;
  std::cout << a << std::endl;
  return 0;
}
