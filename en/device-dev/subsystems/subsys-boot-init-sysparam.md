# Parameter Management

## Overview

### Function Introduction

The parameter management module, namely, sysparam, provides an easy-to-use key-value pair access interface for system services to configure service functions based on their own system parameters.

### System Parameter Definition

Each subsystem defines the system parameters of its own modules, including the system parameter name, default value, and access permission information.
#### System Parameter Definition File

- The system parameter definition file ends with the **.para** extension. An example of the file format is as follows:

  ```
  const.product.name=OHOS-PRODUCT
  const.os.version.api=26
  const.telephony.enable=false|true
  ```

#### System Parameter Name (Key)

- Naming format

  A system parameter name consists of multiple segments in dotted notation. Each segment can be a string that consists of letters, digits, and underscores (_). The total length cannot exceed 96 bytes. System parameter names are categorized into the following two types.

  Naming of system parameters

  | Category| Name| Example| Description|
  | -------- | -------- | -------- | -------- |
  | Parameter| Parameter Name | const.product.name | Complete system parameter name. It does not end with a period (.).|
  | Directory| Parameter Directory | const.**.| Name of the directory storing system parameters with the same prefix. It ends with a period (.).|

- Type

  System parameters are categorized into three types.

  System parameter types

  | Category| Prefix| Description|
  | -------- | -------- | -------- |
  | Constant| const. | Constant parameter, which will not be changed once a value is assigned. The value can contain a maximum of 4,096 bytes (including the terminator).|
  | Writable| Others| Writable parameter, which will be lost after system restart. The value can contain a maximum of 96 bytes (including the terminator).|
  | Persistent| persist. | Writable and persistent parameter, which will not be lost after system restart. The value can contain a maximum of 96 bytes (including the terminator).|

  The general naming format is as follows:

  ```java
  [ const | persist ].$sub_system.$desc
  ```
  **$sub_system** is the name of the subsystem or module.

  **$desc** indicates the description of a system parameter. The description can contain multiple segments in dotted notation.

#### System Parameter Value

- Types

Types of system parameter values

| Category| Example| Description|
| -------- | -------- | -------- |
| String  | const.product.name=OHOS-PRODUCT | A multi-line string must be enclosed in double quotation marks ("").|
| Number    | const.os.version.api=26         | Numbers do not need to be enclosed in quotation marks.|
| Boolean    | const.telephony.enable=false    | A Boolean value can be **0**, **1**, **false**, or **true**.|

### System Parameter Permission Configuration

DAC and MAC are supported.

#### Default Permission

If no DAC or MAC permission has been defined for a system parameter, the default permission is as follows:

| [DAC] User | [DAC] Group | [DAC] UGO | [MAC] SELinux Label |
| ---------- | ----------- | --------- | ------------------- |
| root       | root        | 775       | default_param       |

Other processes access system parameters with the default permission as follows:

| Operation | System Native Process| System Application Process| Third-party Application Process|
| ----- | -------------- | ------------ | ------------ |
| get   | Allowed          | Allowed        | Allowed        |
| watch | Allowed          | Allowed        | Allowed        |
| set   | Not allowed        | Not allowed      | Not allowed      |

#### DAC Permission Configuration

- DAC definition file

  Currently, the control of system parameter access permissions is implemented in discretionary access control (DAC) mode. The access permission definition file ends with the **.para.dac** extension. It is available in the **/base/startup/init/services/etc/param/ohos.para.dac** directory of the init module. The following is an example of the file content:

  ```
  const.product.              = root:root:0775
  persist.init.               = root:root:0775
  startup.appspawn.           = root:root:0750
  startup.uevent.             = ueventd:ueventd:0775
  ```

  As shown above, we can use **parameter directory** to define the same access permission for system parameters with the same prefix. The DAC information is divided into three segments, user, group, and UGO rule, which are separated using a semicolon (:).

  The following figure shows the structure of the UGO rule.

  **Figure 1** UGO rule structure

  ![UGO rule](figures/dac-definition.png)

#### MAC Permission Configuration

- SELinux tag

  To add a SELinux tag to system parameters, you first need to define the tag in the **/base/security/selinux_adapter/sepolicy/base/public/parameter.te** file. For example:

  ```java
  type servicectrl_param, parameter_attr
  ```

  After the tag is defined, add the system parameter prefix associated with the tag to **/base/security/selinux_adapter/sepolicy/base/public/parameter_contexts**. The following uses the prefix **ohos.servicectrl** as an example:

  ```java
  ohos.servicectrl.           u:object_r:servicectrl_param:s0
  ```

- Grant operation permissions. For example, to grant operation permissions such as map for the init process, add the following content to the **/base/security/selinux/sepolicy/ohos_policy/startup/init/public/init.te** file:

  ```java
  allow servicectrl_param tmpfs:filesystem associate;
  allow init servicectrl_param:file { map open read relabelto relabelfrom };
  ```

- Set the write permission. For example, grant the system parameter write permission for services such as **init**, **samgr**, and **hdf_devmgr**.

  ```java
  allow { init samgr hdf_devmgr } servicectrl_param:parameter_service { set };
  ```

- Set the read permission. If you want to grant the permission only for certain services, replace **xxx** with the services in the following code:

  ```java
  allow { xxx } servicectrl_param:file { map open read };
  ```

- If you want to grant the permission for all services, use the following code:

  ```java
  allow { domain -limit_domain } servicectrl_param:file { map open read };
  ```

#### Basic Requirements for System Parameter Permissions

The system parameters mapping to a SELinux tag take up an independent shared memory area. It is recommended that system parameters of the same type share a SELinux tag to reduce the overhead of the system shared memory.

Take the sample component as an example. You are advised to add the following types of tags for access control:

a) For open read-only system parameters, use **default_param** instead of defining new tags. .

b) For writable system parameters, add the **{component}_writable_param** tag.

c) For readable system parameters (privacy data) within a component, add the **[optional]{component}_private_param** tag.

### System Parameter Tag Configuration

#### Configuring the Size of the System Parameter Tag File

By default, 1 KB memory is allocated to each tag, which can store about five system parameters. If a large number of system parameters are supported under a tag, expand the memory size for the tag in the **ohso.para.size** file.

This can be done through either **/system/etc/param/ohos.para.size** or **/sys_prod/etc/param/ohos.para.size**.

The configuration rule is as follows:

System parameter tag = Size

Example:

```
devinfo_public_param=30720
hilog_param=40960
```

Default shared memory size of system parameters: 80 KB

#### Description of System Parameter Tags

The init process creates the corresponding shared memory mapping file in the **/dev/__parameters__/** directory based on the system parameter tag. The shared memory is used to store the system parameters bound to the tag.

Example of a shared memory file:

```
-rwxr-xr-- 1 root root 30720 2017-08-10 16:22 u:object_r:default_param:s0
-rwxr-xr-- 1 root root  1024 2017-08-10 16:22 u:object_r:devinfo_private_param:s0
-rwxr-xr-- 1 root root 30720 2017-08-10 16:22 u:object_r:devinfo_public_param:s0
-rwxr-xr-- 1 root root 40960 2017-08-10 16:22 u:object_r:hilog_param:s0
```

The system parameter tags are defined in the **/base/security/selinux_adapter/sepolicy/base/public/parameter.te** file.

System parameter tag definition:

```
type default_param, parameter_attr;
type devinfo_private_param, parameter_attr;
type devinfo_public_param, parameter_attr;
type hilog_param, parameter_attr;
```

The mappings between system parameter tags and system parameters are defined in the **/base/security/selinux_adapter/sepolicy/base/public/parameter_contexts** file.

The following uses the **hilog_param** tag as an example:

```
hilog.                   u:object_r:hilog_param:s0  # System parameters with the hilog. prefix are stored in the shared memory corresponding to the hilog_param tag.
persist.sys.hilog.       u:object_r:hilog_param:s0  # System parameters with the persist.sys.hilog. prefix are also stored in the shared memory corresponding to the hilog_param tag.
```

### Checking Shared Memory Usage of System Parameters

You can run the **param dump [verbose]** command to query the shared memory usage of system parameters.

The following is an example of the query result:

```
Dump all parameters begin ...
Local security information
pid: 1612 uid: 0 gid: 0
map file: u:object_r:default_param:s0            // Name of the system parameter tag (name of the shared memory mapping file)
total size: 10485720                             // Size of the system parameter tag file (size of the shared memory mapped to the tag)
first offset: 0                                  // Offset of the first parameter node
current offset: 15948                            // Offset of the current parameter node
total node: 242                                  // Total number of nodes in the tag
total param node: 219                            // Total number of parameter nodes
total security node: 0                           // Number of SELinux nodes
commitId        : 26                             //
commitPersistId : 0                              //
node info:                                       // Information about all nodes under the tag
... ...
```

### System Parameter Loading

The following table describes the sequence of loading system parameters.

| Category| Path| Description|
| -------- | -------- | -------- |
| Kernel parameters   | /proc/cmdline | Convert some values of kernel parameters into system parameters. Specifically, convert all **ohospara.xxx=valXXX** parameters to **ohos.boot.xxx=valXXX** parameters.|
| OS system parameters| /system/etc/param/ohos_const/*.para | Load the definition file containing OS constants preferentially.                              |
| Vendor parameters| /vendor/etc/param/*.para | Load the system parameters defined by vendors with the secondary priority.                            |
| System parameters| /system/etc/param/*.para | Load the parameters defined by each subsystem. If a system parameter already exists, ignore it.|
| Persistent parameters| /data/parameters/ | If persistent parameters exist, load them at last. Persistent parameters will overwrite the default system parameters that have been loaded.|

### Parameter and Tag Viewing

Currently, parameter and tag statistics are recorded in the database by subsystem and component. You can set up the [OpenHarmony real-time architecture information collection and analysis system](https://gitee.com/handyohos/ohos_archinfo/tree/master) to view the statistics.

For details about how to set up the system, see the [Analyser Module](https://gitee.com/handyohos/ohos_archinfo/blob/master/analyser/README.md) for OpenHarmony real-time architecture information analysis.

For details about how to collect database information, see the [Collector Module](https://gitee.com/handyohos/ohos_archinfo/tree/master#/handyohos/ohos_archinfo/blob/master/collector/README.md) for OpenHarmony real-time architecture information collection.

You can also obtain the database from the daily dayu200-db build.

### Basic System Parameter Operations

Operation primitives for system parameters

![System parameter operation primitives](figures/system-parameter-operation-primitives.png)

Description of operation primitives

| Function| Description|
| -------- | -------- |
| get      | Obtains the value of a system parameter.       |
| set      | Sets the value of a system parameter.       |
| wait     | Waits for value change of a system parameter synchronously.|
| watch    | Observes value change of a system parameter asynchronously.|

### Constraints

The service management module is available only for the mini system and standard system.

## How to Develop

### Overview

You can set specific system parameters as needed to meet your service demand.

### APIs

- Shell commands

  You can manage system parameters by using shell commands. This operation mode is available only for the standard system. The following table lists the shell commands.

  **Table 6** Description of shell commands

  | Function| Description|
  | -------- | -------- |
  | param get [**key**] | Obtains the system parameter value of the specified key. If no key name is specified, all system parameter values will be returned.|
  | param set **key value** | Sets the specified value for the specified key.|
  | param wait **key** **value** | Waits for the system parameter value of the specified key to match the specified value. Fuzzy match is supported. For example, <strong>*</strong> indicates any value, and <strong>val*</strong> indicates matching of only the first three val characters.|

- syspara APIs

  The following table lists the APIs used to obtain system parameter values. The return result is a const string and the free operation is not supported.

  **Table 7** Description of syspara APIs

  | API| Description|
  | -------- | -------- |
  | int&nbsp;GetParameter(const&nbsp;char\*&nbsp;key,&nbsp;const&nbsp;char\*&nbsp;def,&nbsp;char\*&nbsp;value,&nbsp;unsigned&nbsp;int&nbsp;len) | Obtains system parameters.|
  | int&nbsp;SetParameter(const&nbsp;char\*&nbsp;key,&nbsp;const&nbsp;char\*&nbsp;value) | Sets or updates system parameters.|
  | const&nbsp;char\*&nbsp;GetDeviceType(void) | Obtains the device type.|
  | const&nbsp;char\*&nbsp;GetManufacture(void) | Obtains the device manufacturer.|
  | const&nbsp;char\*&nbsp;GetBrand(void) | Obtains the device brand.|
  | const&nbsp;char\*&nbsp;GetMarketName(void) | Obtains the device marketing name.|
  | const&nbsp;char\*&nbsp;GetProductSeries(void) | Obtains the device series name.|
  | const&nbsp;char\*&nbsp;GetProductModel(void) | Obtains the device authentication model.|
  | const&nbsp;char\*&nbsp;GetSoftwareModel(void) | Obtains the device software model.|
  | const&nbsp;char\*&nbsp;GetHardwareModel(void) | Obtains the device hardware model.|
  | const&nbsp;char\*&nbsp;GetHardwareProfile(void) | Obtains the device hardware profile.|
  | const&nbsp;char\*&nbsp;GetSerial(void) | Obtains the device serial number (SN).|
  | const&nbsp;char\*&nbsp;GetOSFullName(void) | Obtains the operating system name.|
  | const&nbsp;char\*&nbsp;GetDisplayVersion(void) | Obtains the software version visible to users.|
  | const&nbsp;char\*&nbsp;GetBootloaderVersion(void) | Obtains the bootloader version of this device.|
  | const&nbsp;char\*&nbsp;GetSecurityPatchTag(void) | Obtains the security patch tag.|
  | const&nbsp;char\*&nbsp;GetAbiList(void) | Obtains the list of application binary interfaces (ABIs) supported on this device.|
  | int&nbsp;GetSdkApiVersion(void) | Obtains the SDK API level that matches the current system software.|
  | int&nbsp;GetFirstApiVersion(void) | Obtains the first SDK API level of the system software.|
  | const&nbsp;char\*&nbsp;GetIncrementalVersion(void) | Obtains the incremental version.|
  | const&nbsp;char\*&nbsp;GetVersionId(void) | Obtains the version ID.|
  | const&nbsp;char\*&nbsp;GetBuildType(void) | Obtains the build type.|
  | const&nbsp;char\*&nbsp;GetBuildUser(void) | Obtains the build account user name.|
  | const&nbsp;char\*&nbsp;GetBuildHost(void) | Obtains the build host name.|
  | const&nbsp;char\*&nbsp;GetBuildTime(void) | Obtains the build time.|
  | const&nbsp;char\*&nbsp;GetBuildRootHash(void) | Obtains the buildroot hash value of this version.|
  | const&nbsp;char\*&nbsp;GetOsReleaseType(void) | Obtains the system release type.|
  | int&nbsp;GetDevUdid(char&nbsp;\*udid,&nbsp;int&nbsp;size) | Obtains the device identifier (UDID).|
  | const char *AclGetSerial(void) | Obtains the device SN (with ACL check).|
  | int AclGetDevUdid(char *udid, int size) | Obtains the UDID (with ACL check).|

### Procedure

1. System parameter definition

   You can define default system parameters and implement permission control on them by configuring the subsystem or product **.para** and **.para.dac** files. 

   ​On a standard system, use the **ohos_prebuilt_para** template to install the configuration file to the **/etc/param/** directory. The following is an example of the GN script:

   ```go
   import("//base/startup/init/services/etc/param/param_fixer.gni")

   ohos_prebuilt_para("ohos.para") {
       source = "//base/startup/init/services/etc/ohos.para"
       part_name = "init"
       module_install_dir = "etc/param"
   }

   ohos_prebuilt_para("ohos.para.dac") {
       source = "//base/startup/init/services/etc/ohos.para.dac"
       part_name = "init"
       module_install_dir = "etc/param"
   }
   ```

   On a small system, run the **copy** command to copy the corresponding system parameter definition file to the **system/etc/param** directory.
   ```go
   copy("ohos.para") {
     sources = [ "//base/startup/init/services/etc/param/ohos.para" ]
     outputs = [ "$root_out_dir/system/etc/param/ohos.para" ]
   }
   copy("ohos.para.dac") {
     sources = [ "//base/startup/init/services/etc/param/ohos.para.dac" ]
     outputs = [ "$root_out_dir/system/etc/param/ohos.para.dac" ]
   }
   ```
   On a mini system, convert all defined default system parameters into header files through **action** and compile them into the system.
   ```go
   action("lite_const_param_to") {
     script = "//base/startup/init/scripts/param_cfg_to_code.py"
     args = [
       "--source",
       rebase_path(
           "//base/startup/init/services/etc_lite/param/ohos_const/ohospara"),
       "--dest_dir",
       rebase_path("$root_out_dir/gen/init/"),
       "--priority",
       "0",
     ]
     outputs = [ "$target_gen_dir/${target_name}_param_cfg_to_code.log" ]
   }
   ```
2. Development example

   ```
   // set && get
   char key1[] = "rw.sys.version";
   char value1[] = "10.1.0";
   int ret = SetParameter(key1, value1);
   char valueGet1[128] = {0};
   ret = GetParameter(key1, "version=10.1.0", valueGet1, 128);

   // get sysparm
   char* value1 = GetDeviceType();
   printf("Product type =%s\n", value1);

   char* value2 = GetManufacture();
   printf("Manufacture =%s\n", value2);

   char* value3 = GetBrand();
   printf("GetBrand =%s\n", value3);

   char* value4 = GetMarketName();
   printf("MarketName =%s\n", value4);

   char* value5 = GetProductSeries();
   printf("ProductSeries =%s\n", value5);

   char* value6 = GetProductModel();
   printf("ProductModel =%s\n", value6);

   char* value7 = GetSoftwareModel();
   printf("SoftwareModel =%s\n", value7);

   char* value8 = GetHardwareModel();
   printf("HardwareModel =%s\n", value8);

   char* value9 = GetHardwareProfile();
   printf("Software profile =%s\n", value9);

   char* value10 = GetSerial();
   printf("Serial =%s\n", value10);

   char* value11 = GetOSFullName();
   printf("OS name =%s\n", value11);

   char* value12 = GetDisplayVersion();
   printf("Display version =%s\n", value12);

   char* value13 = GetBootloaderVersion();
   printf("bootloader version =%s\n", value13);

   char* value14 = GetSecurityPatchTag();
   printf("secure patch level =%s\n", value14);

   char* value15 = GetAbiList();
   printf("abi list =%s\n", value15);

   int value16 = GetFirstApiVersion();
   printf("first api level =%d\n", value16);

   char* value17 = GetIncrementalVersion();
   printf("Incremental version = %s\n", value17);

   char* value18 = GetVersionId();
   printf("formal id =%s\n", value18);

   char* value19 = GetBuildType();
   printf("build type =%s\n", value19);

   char* value20 = GetBuildUser();
   printf("build user =%s\n", value20);

   char* value21 = GetBuildHost();
   printf("Build host = %s\n", value21);

   char* value22 = GetBuildTime();
   printf("build time =%s\n", value22);

   char* value23 = GetBuildRootHash();
   printf("build root later..., %s\n", value23);

   char* value24 = GetOsReleaseType();
   printf("OS release type =%s\n", value24);

   char* value25 = GetOsReleaseType();
   printf("OS release type =%s\n", value25);

   char value26[65] = {0};
   GetDevUdid(value26, 65);
   printf("device udid =%s\n", value26);
   ```
### System Parameter Error Codes

**Description of system parameter error codes**

| Enum                            | Value| Description                                     |
| -------------------------------- | ------ | ----------------------------------------- |
| PARAM_CODE_ERROR                 | -1     | System error.                                 |
| PARAM_CODE_SUCCESS               | 0      | Operation success.                                     |
| PARAM_CODE_INVALID_PARAM         | 100    | Empty input parameter of the system parameter API.                    |
| PARAM_CODE_INVALID_NAME          | 101    | Invalid length or invalid characters in the system parameter key.     |
| PARAM_CODE_INVALID_VALUE         | 102    | Invalid length or invalid characters in the system parameter value. |
| PARAM_CODE_REACHED_MAX           | 103    | Number of tree nodes reaching the maximum.                         |
| PARAM_CODE_NOT_SUPPORT           | 104    | API not supported.                             |
| PARAM_CODE_TIMEOUT               | 105    | Server access timed out.                           |
| PARAM_CODE_NOT_FOUND             | 106    | Parameter not found.                           |
| PARAM_CODE_READ_ONLY             | 107    | System parameter read-only.                       |
| PARAM_CODE_IPC_ERROR             | 108    | IPC communication error.                              |
| PARAM_CODE_NODE_EXIST            | 109    | System parameter node already exists.                       |
| PARAM_WATCHER_CALLBACK_EXIST     | 110    | Watcher callback repeatedly added.                |
| PARAM_WATCHER_GET_SERVICE_FAILED | 111    | Failed to obtain the service for watcher.                      |
| PARAM_CODE_MEMORY_MAP_FAILED     | 112    | Failed to create the shared memory mapping for a file.                 |
| PARAM_WORKSPACE_NOT_INIT         | 113    | Workspace not initialized.                     |
| PARAM_CODE_FAIL_CONNECT          | 114    | Failed to connect to paramServer.                     |
| PARAM_CODE_MEMORY_NOT_ENOUGH     | 115    | Insufficient system parameter space.                         |
| DAC_RESULT_INVALID_PARAM         | 1000   | Unused code, which defines the start value of permission errors.               |
| DAC_RESULT_FORBIDED              | 1001   | DAC permission disabled.                            |
| SELINUX_RESULT_FORBIDED          | 1002   | SELinux permission disabled.                        |
| PARAM_CODE_MAX                   | 1003   | Maximum enum value.                               |

**Key Logs for Locating Errors**

- system parameter set:

    SetParameter failed! the errNum is: xx!

    SystemSetParameter failed! name is : xxx, errNum is: xx!

- system parameter get:

    GetParameter_ failed! the errNum is: xx!

    SystemReadParam failed! name is: xxxx, errNum is: xx!

- system parameter wait:

    WaitParameter failed! the errNum is: xx!

    SystemWaitParameter failed! name is: xxx, errNum is: xx!

- system parameter Watcher:

  WatchParameter failed! the errNum is xx!

  SystemWatchParameter is failed! keyPrefix is:xxx, errNum is:xx!

## FAQs

### How to Set a System Parameter

1. On the shell side, run **hdc shell** to launch the shell CLI of the device, and then run **param set param.key.***system parameter key* param.value.*system parameter value* to set the system parameter. If the operation is successful, no further processing is required.

2. On the application side, call **SetParameter** to set the system parameter. For details, see [APIs](#apis).
  
3. If **param set** fails, locate the fault based on the log.

   - If the fault is due to insufficient DAC permissions, declare the required permissions by referring to [DAC Permission Configuration](#dac-permission-configuration).

   - If the fault is due to insufficient SELinux permissions, grant the required permissions by referring to the **avc:  denied** alarm information.

   - If the fault is due to insufficient memory, expand the memory by referring to [System Parameter Tag Configuration](#system-parameter-tag-configuration).

### How to Read a System Parameter

1. On the shell side, run **hdc shell** to launch the shell CLI of the device, and then run **param get param.key.***system parameter key* to obtain the system parameter. If the operation is successful, no further processing is required.

2. On the application side, call **GetParameter** to obtain the system parameter. For details, see [APIs](#apis).

3. If **param get** fails, locate the fault based on the log.

   Check whether the parameter has been set. If yes, go to the next step. If no, set the system parameter.

   If the fault is due to insufficient DAC permissions, declare the required permissions by referring to [DAC Permission Configuration](#dac-permission-configuration).

   If the fault is due to insufficient SELinux permissions, grant the required permissions by referring to the **avc:  denied** alarm information.

### How to Subscribe to System Parameter Changes

1. On the shell side, run **hdc shell** to launch the shell CLI of the device, and then run **param shell** to switch to the parameter shell CLI. Run **watcher parameter param.key.***system parameter key* to subscribe to changes of the system parameter. If there is a change in the system parameter, a message similar to "Receive parameter commit 691 change aaa.aaa 11111" is received.

2. On the application side, call **WatchParameter** to subscribe to changes of the system parameter. For details, see [APIs](#apis).

3. If **watcher parameter** fails, locate the fault based on the log.

   If the fault is due to insufficient DAC permissions, declare the required permissions by referring to [DAC Permission Configuration](#dac-permission-configuration).

   If the fault is due to insufficient SELinux permissions, grant the required permissions by referring to the **avc:  denied** alarm information.

### How to Enable Third-Party Applications to Access System Parameters

The default DAC rules grant only the **get** and **watch** permissions for third-party applications. If a third-party application requires the **set** permission, you need to reset DAC rules. In addition, SELinux permissions of third-party applications are left unspecified by default. If needed, set the SELinux permissions by referring to the [MAC Permission Configuration](#mac-permission-configuration).

<!--no_check-->