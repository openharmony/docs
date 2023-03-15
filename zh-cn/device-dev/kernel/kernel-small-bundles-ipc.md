# 轻量级进程间通信


## 基本概念

LiteIPC是OpenHarmony LiteOS-A内核提供的一种新型IPC（Inter-Process Communication，即进程间通信）机制，不同于传统的System V IPC机制，LiteIPC主要是为RPC（Remote Procedure Call，即远程过程调用）而设计的，而且是通过设备文件的方式对上层提供接口的，而非传统的API函数方式。

LiteIPC中有两个主要概念，一个是ServiceManager，另一个是Service。整个系统只能有一个ServiceManager，而Service可以有多个。

**ServiceManager有两个主要功能：**

- 一是负责Service的注册和注销，

- 二是负责管理Service的访问权限（只有有权限的任务（Task）可以向对应的Service发送IPC消息）。


## 运行机制

首先将需要接收IPC消息的任务通过ServiceManager注册成为一个Service，然后通过ServiceManager为该Service任务配置访问权限，即指定哪些任务可以向该Service任务发送IPC消息。

LiteIPC的核心思想就是在内核态为每个Service任务维护一个IPC消息队列，该消息队列通过LiteIPC设备文件向上层用户态程序分别提供代表收取IPC消息的读操作和代表发送IPC消息的写操作。


## 开发指导


### 接口说明

  **表1** LiteIPC模块接口（仅LiteOS-A内部使用）

| 功能分类      | 接口描述                                                     |
| ------------- | ------------------------------------------------------------ |
| 模块初始化    | OsLiteIpcInit：初始化LiteIPC模块                             |
| IPC消息内存池 | -&nbsp;LiteIpcPoolInit：初始化进程的IPC消息内存池<br/>-&nbsp;LiteIpcPoolReInit：重新初始化进程的IPC消息内存池<br/>-&nbsp;LiteIpcPoolDelete：释放进程的IPC消息内存池 |
| Service管理   | LiteIpcRemoveServiceHandle：删除指定的Service                |

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>  LiteIPC模块接口都只在LiteOS-A内部使用。