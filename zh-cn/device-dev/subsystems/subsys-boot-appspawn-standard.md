# appspawn系统应用孵化组件<a name="ZH-CN_TOPIC_0000001063680582"></a>

## 小型系统

### 基本概念

appspawn被init启动后，向IPC框架注册服务名称，之后等待接收进程间消息，根据消息解析结果启动应用服务并赋予其对应权限。

appspawn注册的服务名称为“appspawn”，可通过包含“interfaces/innerkits/include/appspawn_msg.h“头文件，获取服务名称对应的宏APPSPAWN_SOCKET_NAME定义。在安全子系统限制规则下，目前仅Ability Manager Service有权限可以向appspawn发送的进程间消息。

appspawn接收的消息为json格式，如下所示：
  ```
  "{"bundleName":"testvalid1","identityID":"1234","uID":1000,"gID":1000,"capability":[0]}"
  ```

  **表 1**  小型系统字段说明
  | 字段名 | 说明 |
  | -------- | -------- |
  | bundleName | 即将启动的应用服务进程名，长度≥7字节，≤127字节。 |
  | identityID | AMS为新进程生成的标识符，由appspawn透传给新进程，长度≥1字节，≤24字节 |
  | uID | 即将启动的应用服务进程的uID，必须为正值。 |
  | gID | 即将启动的应用服务进程的gID，必须为正值。 |
  | capability | 即将启动的应用服务进程所需的capability权限，数量≤10个。 |

## 标准系统

### 基本概念<a name="section56901555912"></a>

appspawn注册的服务名称为“appspawn”。appspawn 通过监听本地socket，接收来自客户端的请求消息。消息类型为AppParameter的结构体，定义路径为：“interfaces/innerkits/include/appspawn_msg.h“。


  **表 2**  标准系统字段说明
  | 字段名 | 说明 |
  | -------- | -------- |
  | processName | 即将启动的应用服务进程名，最大256字节。 |
  | bundleName | 即将启动的应用程序包名，最大256字节。 |
  | soPath | 即应用程序指定的动态库的路径，最大256字节。 |
  | uid | 即将启动的应用进程的uid，必须为正值。 |
  | gid | 即将启动的应用进程的gid，必须为正值。 |
  | gidTable | 即将启动的应用进程组信息，长度由gidCount指定，最大支持64个进程组，必须为正值。 |
  | gidCount | 即将启动的应用进程组个数。 |
  | accessTokenId | 即应用进程权限控制的token id。 |
  | apl | 即应用进程权限控制的apl，最大32字节. |
  | renderCmd | 即图形图像渲染命令， 最大1024字节。 |
  | flags | 即冷启动标志位。 |
  | pid | 即渲染进程pid，查询渲染进程退出状态。 |
  | AppOperateType | 即App操作类型，0： 默认状态； 1：获取渲染终止状态。 |

### 功能简介<a name="section56901555911"></a>

- 安全控制
  <br> &emsp; 支持为app设置SELinux标签。

  SELinux标签接口代码如下：
    ```
    AppSpawnClientExt *appProperty = (AppSpawnClientExt *)client;
    HapContext hapContext;
    ret = hapContext.HapDomainSetcontext(appProperty->property.apl, appProperty->property.processName);
    if (ret != 0) {
        APPSPAWN_LOGE("AppSpawnServer::Failed to hap domain set context, errno = %d %s",
            errno, appProperty->property.apl);
    } else {
        APPSPAWN_LOGI("AppSpawnServer::Success to hap domain set context, ret = %d", ret);
    }
    ```
- 应用进程控制

  - 支持为app设置AccessToken。
  - 支持重启前，appspawn停止后，可同时停止所有已孵化的app进程。

  AccessToken接口代码如下：
    ```
    AppSpawnClientExt *appProperty = (AppSpawnClientExt *)client;
    int32_t ret = SetSelfTokenID(appProperty->property.accessTokenId);
    APPSPAWN_LOGI("AppSpawnServer::set access token id = %d, ret = %d %d", appProperty->property.accessTokenId, ret, getuid());
    ```

- 冷启动
  <br> &emsp; 支持通过aa命令冷启动应用。

    ```
    param set appspawn.cold.boot true // 打开冷启动开关
    aa start -d 12345 -a $name -b $package -C
    参考：
    aa start -d 12345 -a ohos.acts.startup.sysparam.function.MainAbility -b ohos.acts.startup.sysparam.function -C
    ```

### 开发指导<a name="section56901555913"></a>

  接口定义路径： “/interfaces/innerkits/include/client_socket.h“，接口说明参见表3。

#### 接口说明<a name="section56901555914"></a>

  **表 2**  标准系统接口说明
  | 接口名 | 说明 |
  | -------- | -------- |
  | CreateClient | 创建client。 |
  | CloseClient | 关闭client。 |
  | ConnectSocket | 向appspawn服务发起连接请求。 |
  | WriteSocketMessage | 发送消息到appspawn服务。 |
  | ReadSocketMessage | 接收来自appspawn服务的消息。 |


#### 开发实例<a name="section56901555915"></a>

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

### 常见问题<a name="section56901555916"></a>

#### 冷启动应用失败<a name="section56901555917"></a>

   &emsp; **现象描述**
   <br> &emsp; &emsp; 通过命令冷启动应用失败。

   &emsp; **解决方法**
    <br> &emsp;  &emsp; 1. 确认是否打开冷启动设置。
    <br> &emsp; &emsp; 2. 确认冷启动命令是否正确。
