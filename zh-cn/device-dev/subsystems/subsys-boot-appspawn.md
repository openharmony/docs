# appspawn应用孵化组件<a name="ZH-CN_TOPIC_0000001063680582"></a>

## 概述

### 功能简介

  应用孵化器，负责接受应用程序框架的命令孵化应用进程，设置其对应权限，并调用应用程序框架的入口。

### 基本概念

  appspawn注册的服务名称为“appspawn”。appspawn 通过监听本地socket，接收来自客户端的请求消息。消息类型为AppParameter的结构体，定义路径为：“interfaces/innerkits/include/appspawn_msg.h“。

  **表 1**  字段说明
  | 字段名 | 说明 |
  | -------- | -------- |
  | processName | 即将启动的应用服务进程名，最大256字节。 |
  | bundleName | 即将启动的应用程序包名，最大256字节。 |
  | soPath | 即应用程序指定的动态库的路径，最大256字节。 |
  | uid | 即将启动的应用进程的uid。 |
  | gid | 即将启动的应用进程的gid。 |
  | gidTable | 即将启动的应用进程组信息，长度由gidCount指定，最大支持64个进程组，必须为正值。 |
  | gidCount | 即将启动的应用进程组个数。 |
  | accessTokenId | 即应用进程权限控制的token id。 |
  | apl | 即应用进程权限控制的apl，最大32字节. |
  | renderCmd | 即图形图像渲染命令， 最大1024字节。 |
  | flags | 即冷启动标志位。 |
  | pid | 即渲染进程pid，查询渲染进程退出状态。 |
  | AppOperateType | 即App操作类型，0： 默认状态； 1：获取渲染终止状态。 |

### 约束与限制
仅限标准系统下使用

## 开发指导

### 场景介绍

- 安全控制

  支持为app设置SELinux标签。

  SELinux标签接口代码如下：
    ```c++
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

  支持通过aa命令冷启动应用。
    ```
    param set startup.appspawn.cold.boot 1 // 打开冷启动开关
    aa start -d 12345 -a $name -b $package -C
    参考：
    aa start -d 12345 -a ohos.acts.startup.sysparam.function.MainAbility -b ohos.acts.startup.sysparam.function -C
    ```

- 应用沙盒

  应用独立运行于自身沙盒环境。应用沙盒中，只保留应用依赖的库或文件，同时，应用之间数据的也进行隔离。

### 接口说明

  接口定义路径： "/base/startup/appspawn/interfaces/innerkits/include/client_socket.h"，接口说明参见表2。

  **表 2**  接口说明
  | 接口名 | 说明 |
  | -------- | -------- |
  | CreateClient | 创建client。 |
  | CloseClient | 关闭client。 |
  | ConnectSocket | 向appspawn服务发起连接请求。 |
  | WriteSocketMessage | 发送消息到appspawn服务。 |
  | ReadSocketMessage | 接收来自appspawn服务的消息。 |

### 开发步骤

  沙盒配置说明：

  ```
    {
        "common" : [{                                           // 应用沙盒通用挂载项
            "top-sandbox-switch": "ON",                         // 沙盒总开关 ON: 打开， OFF： 关闭
            "app-base" : [{
                "sandbox-root" : "/mnt/sandbox/<PackageName>",  // 沙盒根路径
                "mount-paths" : [{
                        "src-path" : "/config",                 // mount的源目录
                        "sandbox-path" : "/config",             // 沙盒挂载路径
                        "sandbox-flags" : [ "bind", "rec" ],    // 挂载方式
                        "check-action-status": "false"          // false 不检查当前项挂载结果， true： 检查当前项挂载结果
                    }
                ],
                "symbol-links" : [{                             // link 的目录项
                        "target-name" : "/system/bin",          // link 的源目录
                        "link-name" : "/bin",                   // 链接名称
                        "check-action-status": "false"
                    }
                ]
            }],
        // 应用独有配置参考
        "individual" : [{                                        // 个别应用单独挂载项
            "com.ohos.medialibrary.MediaLibraryDataA" : [{       // 应用名
                "sandbox-switch": "ON",                          // ON： 挂载沙盒路径， OFF: 挂载根路径
                "sandbox-root" : "/mnt/sandbox/<PackageName>",   // 沙盒根路径
                "mount-paths" : [{
                        "src-path" : "/storage/media/<currentUserId>",
                        "sandbox-path" : "/storage/media",
                        "sandbox-flags" : [ "bind", "rec" ],
                        "check-action-status": "false"
                    }
                ],
                "symbol-links" : []
            }]
        }]
    }
  ```

   参考沙盒配置说明，修改配置文件。

   - 进入设备下：/system/etc/sandbox/路径下，直接修改对应沙盒配置文件， 重新启动。
   - 代码路径下：base/startup/appspawn_standard， 修改对应沙盒配置文件。

  **表 3**  沙盒配置文件解释

  | 沙盒配置文件 | 解释 |
  | -------- | -------- |
  | appdata-sandbox-app.json            | 新特性沙盒应用挂载点配置 |
  | appdata-sandbox-asan.json           | 新特性沙盒asan版本额外挂载点配置 |
  | appdata-sandbox-isolated-new.json   | native进程新特性沙盒挂载点配置  |
  | appdata-sandbox-isolated.json       | native进程沙盒挂载点配置 |
  | appdata-sandbox-nweb.json           | 新特性沙盒渲染进程挂载点配置 |
  | appdata-sandbox.json                | 32位系统的沙盒配置 |
  | appdata-sandbox64.json              | 64位系统的沙盒配置 |
  | appspawn_preload.json               | 预加载配置 |

### 开发实例
以launcher应用新增独有配置应用为例：
  ```c++
  "com.ohos.launcher" : [{
      "sandbox-switch": "ON",
      "sandbox-root" : "/mnt/sandbox/<PackageName>",
      "mount-paths" : [{
              "src-path" : "/data/app/el1/bundle/public/",
              "sandbox-path" : "/data/bundles/",
              "sandbox-flags" : [ "bind", "rec" ],
              "check-action-status": "true"
          }
      ],
      "symbol-links" : []
  }],
  ```

## 常见问题

### 冷启动应用失败

   &emsp;**现象描述**
   <br>&emsp;&emsp;通过命令冷启动应用， 应用拉起失败。

   &emsp;**解决方法**
    <br>&emsp;&emsp;1. 需要设置 param set startup.appspawn.cold.boot 1生效。
    <br>&emsp;&emsp;2. 确认冷启动命令是否正确。