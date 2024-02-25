# appspawn Module<a name="EN-US_TOPIC_0000001063680582"></a>

## Overview

### Introduction

  The appspawn module spawns application processes upon receiving commands from the application framework, configures permissions for new processes, and calls the entry function of the application framework.

### Basic Concepts

  **appspawn** is a registered service name. The appspawn process receives requests from the client by listening to messages over the local socket. The message type is an **AppParameter** structure. It is defined in **interfaces/innerkits/include/appspawn_msg.h**.

  **Table 1**  Field description
  | Field| Description|
  | -------- | -------- |
  | processName | Name of the service process to be started. The value contains a maximum of 256 bytes.|
  | bundleName | Bundle name of the application to be started. The value contains a maximum of 256 bytes.|
  | soPath | Path of the dynamic library specified by the application. The value contains a maximum of 256 bytes.|
  | uid | UID of the application process to be started.|
  | gid | GID of the application process to be started.|
  | gidTable | Information about the application process group to be started. Its length is specified by **gidCount**. A maximum of 64 process groups are supported. The value must be a positive number.|
  | gidCount | Number of application process groups to be started.|
  | accessTokenId | Token ID for application process permission control.|
  | apl | APL for application process permission control. The value contains a maximum of 32 bytes.|
  | renderCmd | Image rendering command. The value contains a maximum of 1024 bytes.|
  | flags | Cold start flag.|
  | pid | PID of the rendering process, which is used to query the process exit status.|
  | AppOperateType | Application operation type. The value **0** means to obtain the default status, and the value **1** means to obtain the rendering termination status.|

### Constraints
The appspawn module is used only for the standard system.

## Development Guidelines

### Use Cases

- Application security control based on SELinux tags

   

  Example code:
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
- Application process control

  - Support for setting of AccessToken for applications
  - Support for simultaneous stopping of all spawn application processes (after stopping of the appspawn process and before a restart)

  Example code:
    ```
    AppSpawnClientExt *appProperty = (AppSpawnClientExt *)client;
    int32_t ret = SetSelfTokenID(appProperty->property.accessTokenId);
    APPSPAWN_LOGI("AppSpawnServer::set access token id = %d, ret = %d %d", appProperty->property.accessTokenId, ret, getuid());
    ```

- Support for cold start of applications by using the aa command

   
    ```
    param set startup.appspawn.cold.boot 1 // Enable the cold start function.
    aa start -d 12345 -a $name -b $package -C
    Reference command:
    aa start -d 12345 -a ohos.acts.startup.sysparam.function.MainAbility -b ohos.acts.startup.sysparam.function -C
    ```

- Application sandbox

  Applications run independently in their own sandbox environments. In an application sandbox, only necessary libraries or files of applications are retained and data of different applications is isolated.

### Available APIs

  The API definitions are provided in **/base/startup/appspawn/interfaces/innerkits/include/client_socket.h**. Table 2 is a list of available APIs.

  **Table 2**  API description
  | API| Description|
  | -------- | -------- |
  | CreateClient | Creates a client.|
  | CloseClient | Closes a client.|
  | ConnectSocket | Sends a connection request to the appspawn service.|
  | WriteSocketMessage | Sends a message to the appspawn service.|
  | ReadSocketMessage | Receives a message from the appspawn service.|

### How to Develop

  Sandbox configuration description:

  ```
    {
        "common" : [{                                           // Common mount options of the application sandbox
            "top-sandbox-switch": "ON",                         // Application sandbox switch. The value ON means to enable the applicable sandbox, and the value OFF means the opposite.
            "app-base" : [{
                "sandbox-root" : "/mnt/sandbox/<PackageName>",  // Root path of the application sandbox
                "mount-paths" : [{
                        "src-path" : "/config",                 // Source mount path
                        "sandbox-path" : "/config",             // Sandbox mount path
                        "sandbox-flags" : [ "bind", "rec" ],    // Mount mode
                        "check-action-status": "false"          // Whether to check the mount result. The value true means to check the mount result, and the value false means the opposite.
                    }
                ],
                "symbol-links" : [{                             // Link path
                        "target-name" : "/system/bin",          // Source link path
                        "link-name" : "/bin",                   // Link name
                        "check-action-status": "false"
                    }
                ]
            }],
        // Reference application-specific configuration
        "individual" : [{                                        // Independent mount options of an application
            "com.ohos.medialibrary.MediaLibraryDataA" : [{       // Application name
                "sandbox-switch": "ON",                          // Application sandbox switch. The value ON means to enable the applicable sandbox, and the value OFF means the opposite.
                "sandbox-root" : "/mnt/sandbox/<PackageName>",   // Root path of the application sandbox
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

   Modify configuration files by referring to the sandbox configuration description.

   - On the device, go to **/system/etc/sandbox/**, modify the sandbox configuration files, and restart the device.
   - In the code path, go to **base/startup/appspawn_standard**, and modify the sandbox configuration files.

  **Table 3**  Description of sandbox configuration files

  | Sandbox Configuration File| Description|
  | -------- | -------- |
  | appdata-sandbox64.json | Sandbox configuration for the 64-bit OS|
  | appdata-sandbox.json | Sandbox configuration for the 32-bit OS|
  | product-sandbox.json  | Product-specific configuration for the application sandbox|

### Development Example
The following is the sample code for adding product-specific configuration for the launcher application:
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

## FAQ

### Cold Start of Applications Failed

   **Symptom**
   <br>Applications fail to be started by running the cold start command.

   **Solution**
    <br>&emsp;&emsp;1. Set **param set startup.appspawn.cold.boot 1** for cold start to take effect.
    <br>&emsp;&emsp;2. Make sure that the cold start command is correct.
