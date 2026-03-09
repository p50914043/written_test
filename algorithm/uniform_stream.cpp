// 无限字符串流的均匀随机采样
// 从接收的字符串中随机返回一个字符串
// 传入的总长度：count_， 从中选择一个随机数，返回该随机数对应的字符串
#include <chrono>
#include <iostream>
#include <optional>
#include <random>
#include <string>

class UniformStream {
 public:
  UniformStream() : count_(0), selected_(""), rng_(std::chrono::system_clock::now().time_since_epoch().count()) {
  }

  void process_next(const std::string& str) {
    count_++;

    std::uniform_int_distribution<int> dist(0, count_);  // 创建一个均匀分布
    int random_ = dist(rng_);                            // 从分布中采样一个随机数

    if (random_ == 1) {  // 选中该字符串，可以是任意整数
      selected_ = str;
    }
  }

  std::optional<std::string> get_selected() {
    if (count_ > 0) {
      return selected_;
    }
    return std::nullopt;
  }

 private:
  int count_;
  std::string selected_;
  std::mt19937 rng_;
};

int main() {
  std::cout << ss.str() << std::endl;
}