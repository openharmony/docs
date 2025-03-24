# 应用权限管理开发指导


## 运作机制

由于OpenHarmony允许安装三方应用，所以需要对三方应用的敏感权限调用进行管控，具体实现是应用在开发阶段就需要在应用配置文件中指明此应用在运行过程中可能会调用哪些敏感权限，这些权限包括静态权限和动态权限，静态权限表示只需要在安装阶段注册就可以，而动态权限一般表示获取用户的敏感信息，所以需要在运行时让用户确认才可以调用，授权方式包括系统设置应用手动授权等。除了运行时对应用调用敏感权限进行管控外，还需要利用应用签名管控手段确保应用安装包已经被设备厂商进行了确认。

  **表1** **OpenHarmony系统权限列表**
  
  | **OpenHarmony系统权限** | **授权方式** | **权限说明** | 
  | -------- | -------- | -------- |
  | ohos.permission.LISTEN_BUNDLE_CHANGE | system_grant（静态权限） | 允许该应用获取应用变化消息。 | 
  | ohos.permission.GET_BUNDLE_INFO | system_grant（静态权限） | 允许该应用获取应用信息。 | 
  | ohos.permission.INSTALL_BUNDLE | system_grant（静态权限） | 允许该应用安装应用。 | 
  | ohos.permission.CAMERA | user_grant（动态权限） | 此应用可随时使用相机拍摄照片和录制视频。 | 
  | ohos.permission.MODIFY_AUDIO_SETTINGS | system_grant（静态权限） | 允许该应用修改全局音频设置，例如音量和用于输出的扬声器。 | 
  | ohos.permission.READ_MEDIA | user_grant（动态权限） | 允许该应用读取您的视频收藏。 | 
  | ohos.permission.MICROPHONE | user_grant（动态权限） | 此应用可随时使用麦克风进行录音。 | 
  | ohos.permission.WRITE_MEDIA | user_grant（动态权限） | 允许该应用写入您的音乐收藏。 | 
  | ohos.permission.DISTRIBUTED_DATASYNC | user_grant（动态权限） | 管控分布式数据传输能力。 | 
  | ohos.permission.DISTRIBUTED_VIRTUALDEVICE | user_grant（动态权限） | 允许应用使用分布式虚拟能力。 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 
> 1. 静态权限指应用安装时由系统授予的权限，对应于权限敏感级别的system_grant。动态权限指应用在运行过程中需要用户授权的权限，对应于权限敏感级别的user_grant。
>
> 2. 不同应用模型的应用配置文件不同，FA模型为config.json，Stage模型为module.json5。应用模型相关解释可参考[应用模型解读](../../application-dev/application-models/application-models.md)。

## 场景介绍

应用权限是软件用来访问系统资源和使用系统能力的一种通行方式。在涉及用户隐私相关功能和数据的场景，例如：访问个人设备的硬件特性，如摄像头、麦克风，以及读写媒体文件等，OpenHarmony通过应用权限管理组件来保护这些数据以及能力。

在系统应用开发过程中，如果应用要使用敏感权限，开发者可以调用应用权限管理组件接口检查待访问权限是否被授权，如果未授权，操作不允许。


## 接口说明

应用权限管理提供的API接口，当前仅供系统应用和系统服务调用，具体API接口如下。

  **表2** 应用权限管理API接口功能介绍

| 接口名 | 描述 | 
| -------- | -------- |
| int&nbsp;CheckPermission(int&nbsp;uid,&nbsp;const&nbsp;char&nbsp;\*permissionName) | 检查指定UID的应用进程是否具有访问系统服务API的权限。 | 
| int&nbsp;CheckSelfPermission(const&nbsp;char&nbsp;\*permissionName) | 检查调用者是否具有访问系统服务API的权限。 | 
| int&nbsp;QueryPermission(const&nbsp;char&nbsp;\*identifier,&nbsp;PermissionSaved&nbsp;\*\*permissions,&nbsp;int&nbsp;\*permNum) | 查询应用申请的所有权限，并检查权限是否被授予。 | 
| int&nbsp;GrantPermission(const&nbsp;char&nbsp;\*identifier,&nbsp;const&nbsp;char&nbsp;\*permName) | 将指定权限授予应用程序。 | 
| int&nbsp;RevokePermission(const&nbsp;char&nbsp;\*identifier,&nbsp;const&nbsp;char&nbsp;\*permName) | 收回应用程序的指定权限。 | 
| int&nbsp;GrantRuntimePermission(int&nbsp;uid,&nbsp;const&nbsp;char&nbsp;\*permissionName) | 应用运行时动态授予指定权限。 | 
| int&nbsp;RevokeRuntimePermission(int&nbsp;uid,&nbsp;const&nbsp;char&nbsp;\*permissionName) | 应用运行时动态撤销指定权限。 | 


## 开发步骤

本部分以包管理器的应用权限开发为例进行讲解。开发过程中，首先需要明确涉及的敏感权限，并在config.json中声明该权限，在安装应用程序时，包管理器会调用应用权限管理组件的接口检查该权限是否被授予，若授予，安装流程正常进行，否则安装失败。

1. 在开发过程中，包管理器明确需要安装应用的权限（ohos.permission.INSTALL_BUNDLE），并在config.json中声明该权限。
  FA模型：需要在config.json中声明权限，示例：
  ```json
  {
    "module": {
        "package": "ohos.demo.kitframework",
        "deviceType": [
            "phone", "tv","tablet", "car","smartWatch","sportsWatch","smartCamera", "smartVision"
        ],
        "reqPermissions": [{
          "name": "ohos.permission.INSTALL_BUNDLE",
          "reason": "install bundle",
          "usedScene": {
            "ability": [
              "KitFramework"
              ],
            "when": "always"
          }
        },
        {
          "name": "ohos.permission.LISTEN_BUNDLE_CHANGE",
          "reason": "install bundle",
          "usedScene": {
            "ability": [
              "KitFramework"
              ],
            "when": "always"
          }
        },
        {
          "name": "ohos.permission.GET_BUNDLE_INFO",
          "reason": "install bundle",
          "usedScene": {
            "ability": [
              "KitFramework"
              ],
            "when": "always"
          }
        }
      ]
    }
  }
  ```
  Stage模型：需要在module.json5中声明权限，示例：
  ```json
  {
    "module": {
      "requestPermissions": [{
        "name": "ohos.permission.INSTALL_BUNDLE",
        "reason": "install bundle",
        "usedScene": {
          "ability": [
            "KitFramework"
          ],
          "when": "always"
        }
      },
      {
        "name": "ohos.permission.LISTEN_BUNDLE_CHANGE",
        "reason": "install bundle",
        "usedScene": {
          "ability": [
            "KitFramework"
          ],
          "when": "always"
        }
      },
      {
        "name": "ohos.permission.GET_BUNDLE_INFO",
        "reason": "install bundle",
        "usedScene": {
          "ability": [
            "KitFramework"
          ],
          "when": "always"
        }
      }]
    }
  }
  ```

2. 当包管理器开发应用安装功能接口时，会调用权限管理相关接口检查自身是否具有安装应用程序的权限，例如：以安装应用的权限名"ohos.permission.INSTALL_BUNDLE"作为入参，调用CheckPermission接口检查包管理器是否具有安装应用的权限，如果有权限，安装流程继续执行，否则返回安装失败。
     
   ```c++
   constexpr static char PERMISSION_INSTALL_BUNDLE[] = "ohos.permission.INSTALL_BUNDLE";
   
   bool Install(const char *hapPath, const InstallParam *installParam, InstallerCallback installerCallback)
   {
       if ((hapPath == nullptr) || (installerCallback == nullptr) || (installParam == nullptr)) {
           HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to nullptr parameters");
           return false;
       }
       // 检查ohos.permission.INSTALL_BUNDLE权限是否被授予。
       if (CheckPermission(0, static_cast<const char *>(PERMISSION_INSTALL_BUNDLE)) != GRANTED) {
           HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to permission denied");
           return false;  // 返回安装失败。
       }
       // 安装流程。
       ...
   }
   ```
