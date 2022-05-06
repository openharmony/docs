# appspawn应用孵化组件


## 概述

appspawn被init启动后，等待接收进程间消息，根据消息内容启动应用服务并赋予其对应权限。


## 功能简介

- 安全控制<br />  支持为app设置SELinux标签。

- 应用进程控制
  - 支持为app设置AccessToken。
  - 支持重启前，appspawn停止后，可同时停止所有已孵化的app进程。

- 冷启动<br />  支持应用通过aa命令冷启动应用。
    
  ```
  param set appspawn.cold.boot true // 打开冷启动开关
  aa start -d 12345 -a $name -b $package -C 
  参考命令：
  aa start -d 12345 -a ohos.acts.startup.sysparam.function.MainAbility -b ohos.acts.startup.sysparam.function -C 
  ```


## 基本概念

appspawn注册的服务名称为“appspawn”。appspawn 通过监听本地socket，接收来自客户端的请求消息。消息类型为AppProperty的结构体，定义路径为：“base/startup/appspawn_standard/interfaces/innerkits/include/sclient_socket.h”。

  **表1** 字段说明

| 字段名 | 说明 | 
| -------- | -------- |
| processName | 即将启动的应用服务进程名，最大256字节。 | 
| bundleName | 即将启动的应用程序包名，最大256字节。 | 
| soPath | 应用程序指定的动态库的路径，最大256字节。 | 
| uid | 即将启动的应用进程的uid，必须为正值。 | 
| gid | 即将启动的应用进程的gid，必须为正值。 | 
| gidTable | 即将启动的应用进程组信息，长度由gidCount指定，最大支持64个进程组，必须为正值。 | 
| gidCount | 即将启动的应用进程组个数。 | 
| accessTokenId | 应用进程权限控制的token&nbsp;id。 | 
| apl | 应用进程权限控制的apl，最大32字节。 | 


## 开发指导

接口定义路径： “base/startup/appspawn_standard/interfaces/innerkits/include/client_socket.h”，表 2为接口说明。


### 接口说明

  **表2** 接口说明

| 接口名 | 说明 | 
| -------- | -------- |
| CreateClient | 创建client。 | 
| CloseClient | 关闭client。 | 
| ConnectSocket | 向appspawn服务发起连接请求。 | 
| WriteSocketMessage | 发送消息到appspawn服务。 | 
| ReadSocketMessage | 接收来自appspawn服务的消息。 | 


## 开发实例

接口使用参考：

  
```
std::shared_ptr<AppSpawn::ClientSocket> clientSocket = std::make_unique<AppSpawn::ClientSocket>("AppSpawn");
    if (clientSocket == nullptr) {
        return -1;
    }
    if (clientSocket->CreateClient() != ERR_OK) {
        return -1;
    }
    if (clientSocket->ConnectSocket() != ERR_OK) {
        return -1;;
    }
    // property 构造AppProperty
    clientSocket->WriteSocketMessage((void *)&property, sizeof(AppSpawn::AppProperty));
    // 读结果
    int pid;
    clientSocket->ReadSocketMessage((void *)&pid, sizeof(pid));
    // 如果失败，返回pid小于等于0；否则返回应用的进程id
```


## 常见问题


### 冷启动应用失败

**现象描述**

通过命令冷启动应用失败。

**解决方法**

1. 确认是否打开冷启动设置。

2. 确认冷启动命令是否正确。
