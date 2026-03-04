// 管道
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <string>

// 有名管道

int main(int argc, char *argv[]) {
  // // 无名管道，通常用于父子进程通信
  // int pipefd[2];  // 管道文件描述符数组，pipefd[0]为读端，pipefd[1]为写端
  // if (pipe(pipefd) == -1) {
  //   std::cerr << "pipe error" << std::endl;
  //   return -1;
  // }

  // pid_t pid = fork();  //
  // if (pid == -1) {
  //   std::cerr << "fork error" << std::endl;
  //   return -1;
  // } else if (pid == 0) {
  //   // 子进程
  //   close(pipefd[1]);  // 子进程关闭写端
  //   char buf[1024];
  //   while (true) {
  //     ssize_t s = read(pipefd[0], buf, sizeof(buf));  // 子进程读取数据，阻塞等待数据到达
  //     if (s > 0) {
  //       buf[s] = '\0';
  //       std::cout << "child read: " << buf << std::endl;
  //     }
  //   }
  // } else {
  //   // 父进程
  //   close(pipefd[0]);                            // 父进程关闭读端
  //   write(pipefd[1], "hello", strlen("hello"));  // 父进程写入数据
  //   std::cout << "pid:" << pid << std::endl;
  // }

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <command>" << std::endl;
    return -1;
  }
  if (strcmp(argv[1], "write") == 0) {
    // 写端, 有名管道
    if (unlink("myfifo") == -1) {  // 删除管道文件, 避免重复创建报错
      std::cerr << "unlink error" << std::endl;
    }

    if (mkfifo("myfifo", 0666) == -1) {
      std::cerr << "mkfifo error" << std::endl;  // 如果文件已存在，则返回错误
      return -1;
    }
    int fd = open("myfifo", O_WRONLY);
    if (fd == -1) {
      std::cerr << "open error" << std::endl;
      return -1;
    }
    write(fd, "hello", strlen("hello"));
    close(fd);

  } else if (strcmp(argv[1], "read") == 0) {
    // 读端, 有名管道
    // if(mkfifo("myfifo", 0666) == -1) {
    //   std::cerr << "mkfifo error" << std::endl;
    //   return -1;
    // }
    int fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
      std::cerr << "open error" << std::endl;
      return -1;
    }
    char buf[1024];
    ssize_t s = read(fd, buf, sizeof(buf));
    if (s > 0) {
      buf[s] = '\0';
      std::cout << "read: " << buf << std::endl;
    }
    close(fd);

  } else {
    std::cerr << "Usage: " << argv[0] << " <command>" << std::endl;
    return -1;
  }

  return 0;
}
