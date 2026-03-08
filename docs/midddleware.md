# 内存管理

## jemalloc

# 通信中间件

## fastdds

服务发现流程
fastDDS通信原理，服务发布与订阅模型：

* 服务发现
  * PDP： 组播发送participant信息（anouncement)， 相同的domainID可以匹配，并进入EDP阶段（通过其中的IP&端口建立点到点连接）
  * EDP： 实体（Reader\Writer）发现和匹配（topic、type、endpoint(用于消息传输）)
* EDP连接后就可以实现节点之间的通信了

fastdds在使用过程中遇到的问题（**重点**）：
一类是软件bug，如：

1. qos不匹配：比如一端用零拷贝，一端用共享内存；
2. 软件bug：
   1. 复杂动态类型会崩溃；
   2. 动态类型发现过程复杂；
   3. 零拷贝长度计算跟实际内存布局不符；
   4. reliable模式会导致流量风暴的问题

## vsomeip

SOME/IP通信原理：

* 服务发现流程
  * 服务端启动与服务发布：初始等待阶段（避免网络风暴）；重复发送阶段(快速发送）；主阶段（周期发送Offer)；其中包含ServiceID、InstanceID、版本号、IP地址、端口号
  * 发送服务发现报文主动发现或者通过接收Offer Service被动发现
  * 建立连接
* 停止服务：发送StopOfferService报文，宣告服务实例不可用，停止所有业务通信和事件发布

## ros2

## cyberRT

## iceoryx

## mqtt

# 序列化框架

## protobuf

特点：序列化数据体积小（二进制格式），序列化速度快（基于内存操作），跨平台（支持多种语言），支持动态扩展（可以在不修改代码的情况下添加新的字段）

## cdr
