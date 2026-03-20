#include <iostream>

#include "test.pb.h"

int main() {
  test::Test test;
  for (int i = 0; i < 11; i++) {
    test.set_id(i);
    std::cout << test.DebugString() << std::endl;
  }
  test.set_name("hello1111110000000000000000000000000111");
  std::cout << test.DebugString() << std::endl;
  return 0;
}
