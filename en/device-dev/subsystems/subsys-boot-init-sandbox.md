# Sandbox Management

## Overview

### Function Introduction

OpenHarmony supports two types of sandbox, namely, system sandbox and chipset sandbox.

### Basic Concepts

The system sandbox and chipset sandbox are created in the init module. Native services choose to enter the system sandbox or chipset sandbox based on their functions. Sandbox components can be isolated through the **mount** attribute if **mount-bind-paths** or **mount-bind-files** is set for them in configuration files such as **system-sandbox.json** and **chipset-sandbox.json**. In addition, a sandbox debugging tool is provided to facilitate sandbox debugging, verification, and optimization. For details about commands, see [Description of begetctl Commands](subsys-boot-init-plugin.md#parameters).

### Constraints

The sandbox management module is available only for the standard system.

## How to Develop

### Parameter Description

  **Table 1** Parameters in the sandbox configuration file

  | JSON Prefix| Description|
  | ---------- | ---------- |
  | sandbox-root | Root directory of the sandbox.|
  | mount-bind-paths | Directory to mount.|
  | mount-bind-files | File to mount.|
  | src-path | Source path of the directory or file to mount.|
  | sandbox-path | Target path in the sandbox.|
  | sandbox-flags | Mount flag. The default value is **bind rec**.|
  | ignore | Whether to ignore a mounting failure. If the value is set to **1**, the system ignores the mounting failure and proceeds with the subsequent step.|
  | target-name | Directory to link.|
  | link-name | Target link in the sandbox.|

  **Table 2** Description of sandbox configuration files
  | Sandbox Configuration File| Description|
  | -------- | -------- |
  | chipset-sandbox64.json | Chipset sandbox configuration file for the 64-bit system|
  | chipset-sandbox.json | Chipset sandbox configuration file for the 32-bit system|
  | system-sandbox64.json  | System sandbox configuration file for the 64-bit system|
  | system-sandbox.json  | System sandbox configuration file for the 32-bit system|

### Available APIs

Logical storage structure of the sandbox:

```c++
// Main functions
// name is "system" or "chipset"
bool InitSandboxWithName(const char *name); // Parsing to the JSON structure

typedef struct {
    ListNode pathMountsHead;   // sandbox mount_path list head
    ListNode fileMountsHead;   // sandbox mount_file list head
    ListNode linksHead;        // sandbox symbolic link list head
    char *rootPath;            // /mnt/sandbox/system|vendor|xxx
    char name[MAX_BUFFER_LEN]; // name of sandbox. i.e system, chipset etc.
    bool isCreated;            // sandbox already created or not
    int ns;                    // namespace
} sandbox_t;
```
### Procedure

1. Create a sandbox.
      - Create a system or chipset sandbox and configure the corresponding **system-sandbox.json** or **chipset-sandbox.json** file. For details about how to configure the JSON file, see [Sandbox JSON File Configuration](#sandbox).
      - By default, the sandbox function of a service is enabled. To disable the sandbox function for a specific service, set **sandbox** to **0** in the **.cfg** file of the service. To enable the sandbox function for a specific service, set **sandbox** to **1**.
        ```
        "sandbox" : 1
        ```

2.  Modify the JSON file configuration of the sandbox.
    - Go to the **/system/etc/sandbox/** directory, and run **cat system-sandbox.json** and **cat chipset-sandbox.json**. 
     If you are using a 64-bit system, run **cat system-sandbox64.json** and **cat chipset-sandbox64.json** instead.
    - Modify the sandbox configuration files in the **base/startup/init/interfaces/innerkits/sandbox** directory. After that, restart the system.

### Development Example

JSON file configuration of the sandbox<a name = "sandbox"></a>

```json
{
    "sandbox-root" : "/mnt/sandbox/system",
    "mount-bind-paths" : [{
        "src-path" : "/system/lib/ndk",
        "sandbox-path" : "/system/lib/ndk",
        "sandbox-flags" : [ "bind", "rec", "private" ]
    }],
    "mount-bind-files" : [{
        "src-path" : "/system/lib/ld-musl-aarch64.so.1",
        "sandbox-path" : "/system/lib/ld-musl-aarch64.so.1",
        "sandbox-flags" : [ "bind", "rec", "private" ]
    }],
    "symbol-links" : [{
        "target-name" : "/vendor/lib",
        "link-name" : "/lib"
    }]
}
```

## FAQs

- **Cause Analysis**
     Related services cannot access required resource files such as **.so** file.
- **Solution**
    Check the hilog information, analyze the failure cause, enter the path of the corresponding **.so** file on the device, and modify the **BUILD.gn** file as appropriate. The operation procedure is as follows:

    - Search for keyword **failed** or **.so** in hilog.

      ```
      08-05 17:27:29.302   488   488 E C02500/driver_loader_full: get driver entry failed, /vendor/lib/libcamera_host_service_1.0.z.so load fail, Error loading shared library libdisplay_buffer_proxy_1.0.z.so: No such file or directory (needed by /system/lib/chipset-pub-sdk/libdisplay_buffer_hdi_impl.z.so)
      08-05 17:27:29.303   488   488 E C02500/devhost_service_full: DevHostServiceAddDevice failed and return -207
      08-05 17:27:29.305   488   488 E C02500/devhost_service_stub: Dis patch failed, add service failed and ret is -207
      08-05 17:27:29.307   488   488 I C02500/devhost_service_stub: add device 0x7000201
      08-05 17:27:29.308   488   488 E C02500/driver_loader_full: /vendor/lib/libhdi_media_layer_service.z.so no valid, errno:2
      ```

    - As shown in the preceding search result, the camera error is caused by the **libdisplay_buffer_proxy_1.0.z.so** loading failure. To rectify the fault, you can mount the file in the sandbox for quick recovery, or modify the corresponding **BUILD.gn** file.

      - Method 1: Mount the file in the sandbox for quick recovery. (Only local debugging is supported, and source code modification needs to be reviewed.) 

        - System sandbox: Edit the **/system/etc/sandbox/system-sandbox.json** file on the device. By default, only some files in the **/vendor** directory are mounted. If an error is reported, mount the files separately.
      
        - Chipset sandbox: Edit the **/system/etc/sandbox/chipset-sandbox.json** file on the device. By default, only some files in the **/system** directory are mounted. If an error is reported, mount the files separately.
        
        - For the preceding case, add the following information to /system/etc/sandbox/chipset-sandbox.json:
        
        ```
        "mount-bind-files" : [
        	{
                "src-path" : "/system/lib/libdisplay_buffer_proxy_1.0.z.so",
                "sandbox-path" : "/system/lib/libdisplay_buffer_proxy_1.0.z.so",
                "sandbox-flags" : [ "bind", "rec", "private" ]
            },{...}
        ],
        ```
        
      - Method 2: Add **innerapi_tags** to the **BUILD.gn** file.
      
        ```
        ohos_shared_library("xxx") {
        	...
        	innerapi_tags = [
            	"chipsetsdk",
            ]
        }
        ```
        
      - Description of **innerapi_tags**:
      
        -   Tags related to sandbox permissions include **passthrough**, **chipsetsdk**, **passthrough_indirect**, and **chipsetsdk_indirect**.
          
          -  You can view the **so** information on the OpenHarmony website. For indirectly dependent modules, use **chipsetsdk_indirect** or **passthrough_indirect**. For other modules, use **chipsetsdk** or **passthrough**.
          -  For the **.so** files installed in the system directory, use **chipsetsdk** and **chipsetsdk_indirect** for access by chip components.
          -  For the **.so** files installed in the chip directory, use **passthrough** and **passthrough_indirect** for access by system components.
        -  You can add **innerapi_tags** to specify the installation path of **.so** files. For example, if **chipsetsdk** is set, **.so** files are installed in the **/lib/chipset-sdk/** directory. The source code is available at **build/templates/cxx/cxx.gni**.
        ```gni
        #auto set auto_relative_install_dir by innerapi_tags
        if (defined(invoker.innerapi_tags)) {
      	    is_chipsetsdk = false
            is_platformsdk = false
            is_passthrough = false
            foreach(tag, filter_include(invoker.innerapi_tags, [ "chipsetsdk*" ])) {
              is_chipsetsdk = true
            }
            foreach(tag, filter_include(invoker.innerapi_tags, [ "platformsdk*" ])) {
              is_platformsdk = true
            }
            foreach(tag, filter_include(invoker.innerapi_tags, [ "passthrough*" ])) {
              is_passthrough = true
            }
            if (is_chipsetsdk && is_platformsdk) {
              auto_relative_install_dir = "chipset-pub-sdk"
            } else if (is_chipsetsdk) {
              auto_relative_install_dir = "chipset-sdk"
            } else if (is_platformsdk) {
              auto_relative_install_dir = "platformsdk"
            }
            if (is_passthrough) {
              auto_relative_install_dir = chipset_passthrough_dir
            }
            ...
        }
