# appspawn标准系统应用孵化组件<a name="ZH-CN_TOPIC_0000001063680582"></a>

## 概述<a name="section56901555910"></a>

appspawn被init启动后，等待接收进程间消息，根据消息内容启动应用服务并赋予其对应权限。

### 功能简介<a name="section56901555911"></a>

- 安全控制
  <br> &emsp; 支持为app设置SELinux标签。

- 应用进程控制

  - 支持为app设置AccessToken。
  - 支持重启前，appspawn停止后，可同时停止所有已孵化的app进程。

- 冷启动
  <br> &emsp; 支持通过aa命令冷启动应用。

  ```
  param set appspawn.cold.boot true // 打开冷启动开关
  aa start -d 12345 -a $name -b $package -C 
  参考：
  aa start -d 12345 -a ohos.acts.startup.sysparam.function.MainAbility -b ohos.acts.startup.sysparam.function -C  
 
### 基本概念<a name="section56901555912"></a>

appspawn注册的服务名称为“appspawn”。appspawn 通过监听本地socket，接收来自客户端的请求消息。消息类型为AppProperty的结构体，定义路径为：“base/startup/appspawn_standard/interfaces/innerkits/include/sclient_socket.h“。

**表 1**  字段说明

<table><thead align="left"><tr id="row6650142913713"><th class="cellrowborder" valign="top" width="39.489999999999995%" id="mcps1.2.3.1.1"><p id="p17650112914379"><a name="p17650112914379"></a><a name="p17650112914379"></a>字段名</p>
</th>
<th class="cellrowborder" valign="top" width="60.51%" id="mcps1.2.3.1.2"><p id="p865032916376"><a name="p865032916376"></a><a name="p865032916376"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>processName</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>即将启动的应用服务进程名，最大256字节。</p>
</td>
</tr>
<tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>bundleName</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>即将启动的应用程序包名，最大256字节。</p>
</td>
</tr>
<tr id="row86501129183712"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p2065010298379"><a name="p2065010298379"></a><a name="p2065010298379"></a>soPath</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p13650192963715"><a name="p13650192963715"></a><a name="p13650192963715"></a>应用程序指定的动态库的路径，最大256字节。</p>
</td>
</tr>
<tr id="row13650329103719"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501292377"><a name="p16501292377"></a><a name="p16501292377"></a>uid</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p186503291371"><a name="p186503291371"></a><a name="p186503291371"></a>即将启动的应用进程的uid，必须为正值。</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>gid</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>即将启动的应用进程的gid，必须为正值。</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>gidTable</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>即将启动的应用进程组信息，长度由gidCount指定，最大支持64个进程组，必须为正值。</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>gidCount</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>即将启动的应用进程组个数。</p>
</td>
</tr>
<tr id="row106508294373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501829183715"><a name="p16501829183715"></a><a name="p16501829183715"></a>accessTokenId</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p11650182953717"><a name="p11650182953717"></a><a name="p11650182953717"></a>应用进程权限控制的token id。</p>
</td>
</tr>
<tr id="row106508294373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501829183715"><a name="p16501829183715"></a><a name="p16501829183715"></a>apl</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p11650182953717"><a name="p11650182953717"></a><a name="p11650182953717"></a>应用进程权限控制的apl，最大32字节。</p>
</td>
</tr>
</tbody>
</table>

## 开发指导<a name="section56901555913"></a>

  接口定义路径： “base/startup/appspawn_standard/interfaces/innerkits/include/client_socket.h“，表 2为接口说明。

### 接口说明<a name="section56901555914"></a>

**表 2**  接口说明
<table><thead align="left"><tr id="row6650142913713"><th class="cellrowborder" valign="top" width="39.489999999999995%" id="mcps1.2.3.1.1"><p id="p17650112914379"><a name="p17650112914379"></a><a name="p17650112914379"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="60.51%" id="mcps1.2.3.1.2"><p id="p865032916376"><a name="p865032916376"></a><a name="p865032916376"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>CreateClient</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>创建client。</p>
</td>
</tr>
<tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>CloseClient</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>关闭client。</p>
</td>
</tr>
<tr id="row86501129183712"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p2065010298379"><a name="p2065010298379"></a><a name="p2065010298379"></a>ConnectSocket</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p13650192963715"><a name="p13650192963715"></a><a name="p13650192963715"></a>向appspawn服务发起连接请求。</p>
</td>
</tr>
<tr id="row13650329103719"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501292377"><a name="p16501292377"></a><a name="p16501292377"></a>WriteSocketMessage</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p186503291371"><a name="p186503291371"></a><a name="p186503291371"></a>发送消息到appspawn服务。</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>ReadSocketMessage</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>接收来自appspawn服务的消息。</p>
</td>
</tr>
</tbody>
</table>

### 开发实例<a name="section56901555915"></a>

<br> &emsp; 接口使用参考：
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

## 常见问题<a name="section56901555916"></a>

### 冷启动应用失败<a name="section56901555917"></a>

   &emsp; **现象描述**
   <br> &emsp; &emsp; 通过命令冷启动应用失败。

   &emsp; **解决方法**
    <br> &emsp;  &emsp; 1. 确认是否打开冷启动设置。
    <br> &emsp; &emsp; 2. 确认冷启动命令是否正确。