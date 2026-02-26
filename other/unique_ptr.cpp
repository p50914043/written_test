#include <iostream>
#include <memory>

// 手动实现一个简单的 unique_ptr 类：

template <typename T>
class unique_ptr {
 public:
  unique_ptr(T *p = nullptr) : p_(p) {}
  unique_ptr(unique_ptr &&other) : p_(other.p_) { other.p_ = nullptr; }
  unique_ptr &operator=(unique_ptr &&other) {
    delete p_;
    p_ = other.p_;
    other.p_ = nullptr;
    return *this;
  }
  ~unique_ptr() { delete p_; }
  T &operator*() { return *p_; }

  T *operator->() { return p_; }

  T *get() const { return p_; }

 private:
  T *p_;
};

int main() {
  unique_ptr<int> p(new int(42));
  std::cout << *p << std::endl;
  unique_ptr<int> q(std::move(p));
  std::cout << *q << std::endl;
  std::cout << p.get() << std::endl;
}