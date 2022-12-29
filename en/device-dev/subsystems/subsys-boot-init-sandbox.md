# Sandbox Management

## Overview
### Function
OpenHarmony supports two types of sandbox, namely, system sandbox and chipset sandbox.

The system sandbox and chipset sandbox are created in the init module. Native services choose to enter the system sandbox or chipset sandbox based on their functions. 

Sandbox components can be isolated through the **mount** attribute if **mount-bind-paths** or **mount-bind-files** is set for them in configuration files such as **system-sandbox.json** and **chipset-sandbox.json**. In addition, a sandbox debugging tool is provided to facilitate sandbox debugging, verification, and optimization. For details about commands, see [Description of begetctl Commands](subsys-boot-init-plugin.md#parameters).

### Constraints

The sandbox management module is available only for the standard system.

## How to Develop
### Parameters
  **Table 1** Parameters in the sandbox configuration file

  | JSON Prefix| Description|
  | ---------- | ---------- |
  | sandbox-root | Root directory of the sandbox.|
  | mount-bind-paths | Directory to mount.|
  | mount-bind-files | File to mount.|
  | src-path | Source path of the directory or file to mount.|
  | sandbox-path | Target path in the sandbox.|
  | sandbox-flags | Mount flag. The default value is **bind rec**.|
  | ignore | Whether to ignore a mounting failure. If the value is set to 1, the system ignores the mounting failure and proceeds with the subsequent step. |
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
    int ns;                    // namespace                                // namespace
} sandbox_t;
```
### How to Develop
1. Create a sandbox.
      - Create a system or chipset sandbox and configure the corresponding **system-sandbox.json** or **chipset-sandbox.json** file. For details about how to configure the JSON file, see [Sandbox JSON File Configuration](#sandbox).
      - By default, the sandbox function of a service is enabled. If you do not want to move the service to the sandbox, set **sandbox** to **0** in the **.cfg** file. Otherwsie, set **sandbox** to **1**.
        ```
        "sandbox" : 1
        ```

2.  Modify the JSON file configuration of the sandbox.
    - Go to the **/system/etc/sandbox/** directory, and run **cat system-sandbox.json** and **cat chipset-sandbox.json**. 
     If you are using a 64-bit system, run **cat system-sandbox64.json** and **cat chipset-sandbox64.json** instead.
    - Modify the sandbox configuration files in the **base/startup/init_lite/interfaces/innerkits/sandbox** directory. After that, restart the system.

### Development Example
Sandbox JSON File Configuration

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
### Failed to Create a Sandbox

**Symptom**

**Sandbox %s has not been created.** is printed in the dmesg or hilog.

**Cause Analysis**

Creating a sandbox failed because of a mounting and linking error.

**Solution**
1. Check whether the JSON file is correctly configured.
2. Check whether the created sandbox is supported.
