#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// 值捕获
// 引用捕获
// this捕获
// 隐式捕获

// 捕获是编译过程的行为;参数是运行时行为
// 值捕获不允许修改捕获的变量，默认为const
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
