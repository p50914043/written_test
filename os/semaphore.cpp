// 信号量（Semaphore）
// 本质是一个计数器，用于保护共享资源的访问
// 即P操作，用于等待信号量，对应sem_wait
// V操作，用于释放信号量，增加计数器值, 对应sem_post
// 分无名信号量和有名信号量
// 无名信号量用于在同一进程内的线程之间同步
// 有名信号量用于在不同进程之间同步
#include <semaphore.h>
#include <unistd.h>

#include <iostream>
#include <thread>

int main(int argc, char *argv[]) {
  // 无名信号量
  sem_t sem;
  if (sem_init(&sem, 0, 0) == -1) {
    std::cerr << "sem_init error" << std::endl;
    return -1;
  }
  // 临界区
  // 等待信号量
  if (sem_wait(&sem) == -1) {
    std::cerr << "sem_wait error" << std::endl;
    return -1;
  }

  if (sem_post(&sem) == -1) {
    std::cerr << "sem_post error" << std::endl;
    return -1;
  }
}