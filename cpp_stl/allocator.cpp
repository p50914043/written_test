#include <iostream>
#include <memory>  // 默认包含allocator
#include <string>
template <typename T>
class Allocator {
 public:
  Allocator() = default;
  Allocator(const Allocator&) = delete;
  Allocator(Allocator&&) = delete;
  Allocator& operator=(const Allocator&) = delete;
  Allocator& operator=(Allocator&&) = delete;
  ~Allocator() = default;

  void* allocate(size_t size) {
    return ::operator new(size);  // 调用全局new运算符
  }

  void deallocate(void* ptr, size_t size) {
    ::operator delete(ptr, size);  // 调用全局delete运算符，若直接调用delete, 会先调用对象的析构函数
  }

  void destroy(T* ptr) {
    ptr->~T();
  }
};

class A {
 public:
  A() {
    std::cout << "A()" << std::endl;
  }
  ~A() {
    std::cout << "~A()" << std::endl;
  }
};

int main() {
  std::allocator<std::string> alloc;
  std::string* p = alloc.allocate(1);
  alloc.construct(p, "hello world");
  std::cout << *p << std::endl;
  alloc.destroy(p);        // 销毁对象
  alloc.deallocate(p, 1);  // 释放内存

  auto a = new A();
  delete (a);
}