#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

// 一个最简单的 TCP 服务器示例：
// - 创建套接字 socket()
// - 绑定地址 bind()
// - 监听 listen()
// - 接受连接 accept()
// 只处理一个客户端连接，发送一条消息后关闭。

int main() {
  // AF_INET: IPv4, SOCK_STREAM: TCP
  int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) {
    perror("socket");
    return 1;
  }

  // 填充服务器地址结构
  sockaddr_in addr{};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;  // 监听所有网卡
  addr.sin_port = htons(8888);        // 端口 8888

  // bind 将套接字与地址和端口绑定
  if (bind(listen_fd, (sockaddr*)&addr, sizeof(addr)) < 0) {
    perror("bind");
    close(listen_fd);
    return 1;
  }

  // listen 将套接字标记为被动，准备接受连接
  if (listen(listen_fd, 5) < 0) {
    perror("listen");
    close(listen_fd);
    return 1;
  }

  std::cout << "server listening on 0.0.0.0:8888" << std::endl;

  while (true) {
    sockaddr_in client{};
    socklen_t len = sizeof(client);
    int conn_fd = accept(listen_fd, (sockaddr*)&client, &len);  // 接受连接, 返回新的套接字描述符
    if (conn_fd < 0) {
      perror("accept");
      continue;
    }

    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client.sin_addr, ip, sizeof(ip));
    std::cout << "accepted connection from " << ip << ":" << ntohs(client.sin_port) << std::endl;

    const char* msg = "Hello from server!\n";
    write(conn_fd, msg, strlen(msg));

    close(conn_fd);
  }

  close(listen_fd);
  return 0;
}
