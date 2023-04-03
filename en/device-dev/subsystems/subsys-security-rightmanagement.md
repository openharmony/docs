# Development on App Permission Management


## Working Principles

OpenHarmony allows users to install third-party applications and controls calls made by third-party applications to sensitive permissions. When developing an application, you need to declare the sensitive permissions required by the application in the application configuration file. The permissions can be static or dynamic. Static permissions are registered during application installation, and dynamic permissions must be authorized by users. Authorization modes include system settings, manual authorization, and others. In addition, application signatures are used to ensure that the application installation packages have been confirmed by device vendors.

  **Table 1** OpenHarmony permission list
  
  | **Permission**| **Authorization Mode**| **Description**| 
  | -------- | -------- | -------- |
  | ohos.permission.LISTEN_BUNDLE_CHANGE | system_grant (static permission)| Allows an application to listen for application changes.| 
  | ohos.permission.GET_BUNDLE_INFO | system_grant (static permission)| Allows an application to obtain information about other applications.| 
  | ohos.permission.INSTALL_BUNDLE | system_grant (static permission)| Allows an application to install other applications.| 
  | ohos.permission.CAMERA | user_grant (dynamic permission)| Allows an application to use the camera to take photos and record videos at any time.| 
  | ohos.permission.MODIFY_AUDIO_SETTINGS | system_grant (static permission)| Allows an application to modify global audio settings, such as the volume and speaker.| 
  | ohos.permission.READ_MEDIA | user_grant (dynamic permission)| Allows an application to read users' favorite videos.| 
  | ohos.permission.MICROPHONE | user_grant (dynamic permission)| Allows an application to use the microphone for audio recording at any time.| 
  | ohos.permission.WRITE_MEDIA | user_grant (dynamic permission)| Allows an application to write users' favorite music.| 
  | ohos.permission.DISTRIBUTED_DATASYNC | user_grant (dynamic permission)| Allows an application to manage distributed data transmission.| 
  | ohos.permission.DISTRIBUTED_VIRTUALDEVICE | user_grant (dynamic permission)| Allows an application to use distributed virtualization features.| 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> 
> 1. Static permission is a permission granted by the system during application installation. The sensitivity level of this type of permission is **system_grant**. Dynamic permission is a permission granted by users during application running. The sensitivity level of this type of permission is **user_grant**.
>
> 2. The application configuration file varies depending on the application model. It is **config.json** for the application based on the FA model and **module.json5** for the application based on the stage mode. For details about the application models, see [Interpretation of the Application Model](../../application-dev/application-models/application-model-description.md).

## When to Use

App permissions are required for software to access system resources and use system capabilities. When the functions and data related to user privacy are used, for example, when personal devices, such as cameras and microphones, are used or media files are read or written, OpenHarmony uses the application permission management component to protect the data and capabilities.

When developing a system application that requires a sensitive permission, you can call the corresponding API of the application permission management component to check whether the required permission is granted. If the permission is not granted, the application cannot use it.


## Available APIs

The table below lists the APIs available for application permission management. These APIs can be called only by system applications and services.

  **Table 2** App permission management APIs

| API| Description| 
| -------- | -------- |
| int&nbsp;CheckPermission(int&nbsp;uid,&nbsp;const&nbsp;char&nbsp;\*permissionName) | Checks whether the application with the specified UID has the permission to access system service APIs.| 
| int&nbsp;CheckSelfPermission(const&nbsp;char&nbsp;\*permissionName) | Checks whether the caller has the permission to access system service APIs.| 
| int&nbsp;QueryPermission(const&nbsp;char&nbsp;\*identifier,&nbsp;PermissionSaved&nbsp;\*\*permissions,&nbsp;int&nbsp;\*permNum) | Queries all permissions requested by the application and checks whether the requested permissions have been granted.| 
| int&nbsp;GrantPermission(const&nbsp;char&nbsp;\*identifier,&nbsp;const&nbsp;char&nbsp;\*permName) | Grants a permission to the app.| 
| int&nbsp;RevokePermission(const&nbsp;char&nbsp;\*identifier,&nbsp;const&nbsp;char&nbsp;\*permName) | Revokes a permission from the app.| 
| int&nbsp;GrantRuntimePermission(int&nbsp;uid,&nbsp;const&nbsp;char&nbsp;\*permissionName) | Grants a runtime permission to the app.| 
| int&nbsp;RevokeRuntimePermission(int&nbsp;uid,&nbsp;const&nbsp;char&nbsp;\*permissionName) | Revokes a runtime permission from the app.| 


## How to Develop

The following uses the BMS as an example to describe the application permission development. Before you start, declare the required sensitive permissions in the **config.json** file. During application installation, the BMS calls APIs of the application permission management component to check whether the required permissions are available. If yes, the installation proceeds; otherwise, the installation fails.

1. Declare the required permission (**ohos.permission.INSTALL_BUNDLE**) in the **config.json** file.
  If the FA model is used, declare the permission in the **config.json** file. The following is an example:
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
  If the stage model is used, declare the permission in **module.json5**. The following is an example:
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

2. When an application is to be installed, the BMS checks whether it has the permission to install the app. For example, the BMS calls **CheckPermission** with **ohos.permission.INSTALL_BUNDLE** as an input parameter. If it has the permission, the installation proceeds; otherwise, the installation fails.
     
   ```c++
   constexpr static char PERMISSION_INSTALL_BUNDLE[] = "ohos.permission.INSTALL_BUNDLE";
   
   bool Install(const char *hapPath, const InstallParam *installParam, InstallerCallback installerCallback)
   {
       if ((hapPath == nullptr) || (installerCallback == nullptr) || (installParam == nullptr)) {
           HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to nullptr parameters");
           return false;
       }
       // Check whether the ohos.permission.INSTALL_BUNDLE permission has been granted.
       if (CheckPermission(0, static_cast<const char *>(PERMISSION_INSTALL_BUNDLE)) != GRANTED) {
           HILOG_ERROR(HILOG_MODULE_APP, "BundleManager install failed due to permission denied");
           return false;  // App installation fails.
       }
       // Installation process.
       ...
   }
   ```
