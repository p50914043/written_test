#include <stdio.h>
#include <unistd.h>

// 子函数1：耗时短
void func1() {
  int i, sum = 0;
  for (i = 0; i < 1000000; i++) {
    sum += i;
  }
}

// 子函数2：耗时长
void func2() {
  int i, sum = 0;
  for (i = 0; i < 100000000; i++) {
    sum += i;
  }
  sleep(1);  // 非CPU耗时（gprof统计不到）
}

// 主函数：调用子函数
int main() {
  int i;
  for (i = 0; i < 3; i++) {
    func1();  // 调用3次
  }
  func2();  // 调用1次
  return 0;
}