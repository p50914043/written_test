#include <iostream>
#include <tuple>

int main() {
  std::tuple<int, int, int> t1(1, 2, 3);
  t1.swap(t1);
  std::cout << std::get<0>(t1) << std::endl;
  return 0;
}
