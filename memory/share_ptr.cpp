#include <iostream>
#include <memory>

using namespace std;

//  手动实现SharedPtr类型
template <typename T>
class SharedPtr {
 public:
  SharedPtr(T *ptr) : ptr_(ptr), count_(new int(1)) {
  }
  SharedPtr(const SharedPtr &other) : ptr_(other.ptr_), count_(other.count_) {
    ++(*count_);
  }
  SharedPtr &operator=(const SharedPtr &other) {
    if (this != &other) {
      --(*count_);
      ptr_ = other.ptr_;
      count_ = other.count_;
      ++(*count_);
    }
    return *this;
  }
  ~SharedPtr() {
    --(*count_);
    if (*count_ == 0) {
      delete ptr_;
      delete count_;
    }
  }

  T &operator*() {
    return *ptr_;
  }

  T *operator->() {
    return ptr_;
  }

  int use_count() const {
    return *count_;
  }

 private:
  T *ptr_;
  int *count_;
};

int main() {
  std::shared_ptr<int> p3(new int(10));
  auto p4 = std::make_shared<int>(10);
  auto p5 = std::weak_ptr<int>(p4);
  std::cout << "p4.use_count(): " << p4.use_count() << std::endl;
  p5.lock();
  p5.reset();
  p5.expired();
  std::cout << "p4.use_count(): " << p4.use_count() << std::endl;
  SharedPtr<int> p1(new int(10));
  SharedPtr<int> p2(p1);
  std::cout << "p1.use_count(): " << p1.use_count() << std::endl;
  std::cout << "p2.use_count(): " << p2.use_count() << std::endl;
  // 测试使用new初始化SharedPtr造成的内存泄漏
  std::shared_ptr<int> p4 = std::make_shared<int>(10);

  return 0;
}
