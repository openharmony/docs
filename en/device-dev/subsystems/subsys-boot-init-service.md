# Service Management
## Overview

Service management is implemented by using the init process to parse the service process configuration files (**xxx.cfg** files), which are used to configure services based on service scenarios. Currently, the supported value-added services include startup control, on-demand startup, command execution, scheduled startup, FD proxy, and sandbox management.

## Description of Service Process Configuration Files

- Naming:

    Generally, the configuration file is named in the format of **serviceName.cfg**, where **serviceName** is the service process name, for example, **appspawn.cfg**.

- Format:

    The configuration file is based on the JSON format and complies with the basic rules of the JSON file.

- Content:

    The configuration file contains the following fields. Except mandatory fields, other fields can be configured based on service features.

   Table 1 Service configuration fields

   | Field| Configuration|Supported System Type| Description| Remarks|
   | ---------- | ------- | -------- | --------| --------|
   | name          | Mandatory| Small and standard systems | Name of the current service. (Mandatory)|  Type: string. The value cannot be empty and can contain a maximum of 32 bytes.|
   | path          | Mandatory| Small and standard systems| Full path (including parameters) of the executable file for the current service. This is an array. (Mandatory)| The first element is the path of the executable file, and the maximum number of elements is 20.<br> Each element is a string that contains a maximum of 64 bytes.|
   | uid           | Mandatory| Small and standard systems| User ID (UID) of the current service process.| Type: int or string.|
   | gid           | Mandatory| Small and standard systems| Group ID (GID) of the current service process.| Type: int, int[], string, or string array.|
   | once          | Optional| Small and standard systems| Whether the current service process is a one-off process.| **1**: The current service process is a one-off process. If the process exits, the init process does not restart it.<br>**0**: The current service process is not a one-off process. If the process exits, the init process restarts it upon receiving the SIGCHLD signal.|
   | importance    | Optional| Small and standard systems| Standard system: service priority<br>Small system: service importance or service priority| Standard system: The value of service priority ranges from **-20** to **19**. A smaller value indicates a higher priority. A value beyond the range is invalid.<br>Small system: The value of service importance can be **0** or a non-zero number. The value **0** indicates a non-important service, which does not require a system restart. A non-zero number indicates an important service, which requires a system restart. To switch to the service priority configuration, set the **init_feature_enable_lite_process_priority** macro to **true**. The service priority configuration is the same as that for the standard system.|
   | caps          | Optional| Small and standard systems| Capabilities required by the current service. They are evaluated based on the capabilities supported by the security subsystem and configured in accordance with the principle of least permission.| Type: number or string array. If you set the value to a number, use the standard Linux capability. If you set the value to a string array, use the standard macro name.|
   | critical      | Optional| Small and standard systems| Suppression mechanism for services. If the number of times a service is restarted exceeds the value N within the specified period T, the system will be restarted.| <br> Type: int[], for example, "critical": [M, N, T].<br>- **M**: enable flag (**0**: disable; **1**: enable).<br>- **N**: number of times the service is started.<br>- **T**: period of time, in seconds.<br> By default, **N** is **4** and **T** is **240**.|
   | cpucore      | Optional| Standard system| Number of CPU cores bound to the service.| Type: int array, for example, **"cpucore": [N1, N2, ...]**. **N1** and **N2** indicate the indices of the CPU cores to be bound. For a single-core device, **cpucore** is **0**.|
   | d-caps       | Optional| Standard system| Distributed service capability.| Type: string array, for example, **"d-caps": ["OHOS_DMS"]**.|
   | apl          | Optional| Standard system| Ability privilege level.| Type: string, for example, **"apl": "system_core"**.<br> The value can be **system_core** (default), **normal**, or **system_basic**.|
   | start-mode   | Optional| Standard system| Service startup mode.| Type: string, for example, **start-mode: condition**.<br>The value can be **boot**, **normal**, or **condition**. For details, see init Service Startup Control.|
   | ondemand     | Optional| Small and standard systems| Whether on-demand startup is enabled.| Type: bool, for example, **ondemand: true**. For small systems, this feature is available only on the Linux kernel.<br>For details, see [init Service On-Demand Startup](#section56901555920).|
   | disable | Optional| Small and standard systems| Reserved.| None.|
   | sandbox | Optional| Standard system| Whether the sandbox function is enabled.| **1** (default): Enable the sandbox function.<br>**0**: Disable the sandbox function.|
   | socket | Optional| Standard system| Socket attribute configuration.| This field is required for services that uses a socket connection.|
   | env | Optional| Standard system| Environment variable configuration.| Type: key-value pair array.<br>Multiple environment variables can be configured. For example:<br>"env" : [{<br> "name" : "SERVICE_NALE", <br>"value" : "ueventd"},{<br> "name" : "TEST",<br> "value" : "test_value" <br>}]|
   | period | Optional| Standard system| Scheduled startup upon service exit.| Type: int, for example, 60. This field specifies the interval for starting a scheduled task, in seconds.<br>If this function is enabled, a timer is started to periodically start the service upon service exit. For example, **"period": 60** indicates that the service is started 60 seconds upon service exit.|

   **Table 2** Description of socket fields
   | Field| Description|
   | -------- | -------- |
   | name | Name of the socket. It does not need to be the same as the service name. The value must not be empty and can contain a maximum of 32 bytes.|
   | family | Address family to which the socket belongs. Currently, the AF_UNIX and AF_NETLINK families are supported.|
   | type | Socket type. Currently, connection-based sockets, SOCK_SEQPACKET and SOCK_STREAM, and UDP-based connectionless socket, SOCK_DGRAM, are supported.|
   | protocol | Protocol used for socket communication. Unless otherwise required, set the value to **default** so that the socket automatically selects a proper protocol based on the socket address family and socket type. In addition to the default protocol, the NETLINK_KOBJECT_UEVENT protocol is also supported.|
   | permissions | Permissions of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | uid | User ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | gid | Group ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | option | Socket option. This field is passed when **setsockopt** is called. Currently, the available options include **SOCKET_OPTION_PASSCRED**, **SOCKET_OPTION_RCVBUFFORCE**, **SOCK_CLOEXEC**, and **SOCK_NONBLOCK**.|

  - init service startup control (for standard system or higher)<a name = "section56901555918">

    The init process classifies services into three types based on service configurations and starts the services in different phases.

    - **boot**: services that need to be preferentially started in the system. This type of services are started in the init phase.
    - **normal**: common services in the system. This type of services are started in the post-init phase. This is the default service type.
    - **condition**: services that are started by running the startup command. You can add the **start xxxx** command to **jobs** to start the corresponding service.

  - init service command execution (for standard system or higher)<a name="section56901555919"></a>

    The init module provides the service command execution function, which allows services to execute different commands in different phases.

    - **on-start**: execution of commands after the service process is forked. The on-start job is executed in the subprocess of the service and affects only the subprocess.
    - **on-stop**: execution of commands in the init process when the service is stopped.
    - **on-restart**: execution of commands in the init process when the service is restarted.

    Configure the parameters as follows:
    ```
    "services" : [{
          "name" : "serviceName",
          "path" : ["/system/bin/serviceName"]
          "jobs" : {
              "on-start" : "services:serviceName_start",
              "on-stop" : "services:serviceName_stop",
              "on-restart" : "services:serviceName_restart"
        }
    },
    ```

  With the parallel startup and command execution capabilities, processes can be started concurrently.

  - init service on-demand startup<a name="section56901555920">

    If on-demand startup is enabled, the init process starts a service only when it is required. The **ondemand** attribute is used to determine whether to enable on-demand startup for a service.

    The following is an example configuration of the **ondemand** attribute:
    ```
      "services" : [{
        "name" : "serviceName",
        "path" : ["/system/bin/serviceName"]
        "ondemand" : true
    }]
    ```
  - SA process on-demand startup

      For details, see [samgr Usage](https://gitee.com/openharmony/systemabilitymgr_samgr/blob/master/README.md).

  - Socket process on-demand startup
      1. The init process creates a socket for socket processes in the pre-fork phase and listens to read/write events on this socket.
      2. If a read/write event is received over the socket, the init process starts the native service corresponding to the socket process, cancels event listening on the socket, and transfers the socket to the corresponding native service for management.
      3. The native service automatically exits if no more packets need to be processed. When reclaiming subprocesses, the init process starts event listening over the socket again based on the service configuration.

  - Hot-swap service process on-demand startup

    The hot-swap service process can be started to process hot swap events based on system parameter changes.

  - Enhanced init process startup and recycling

    The CPU core binding, priority, MAC address, and AccessToken information of the service process can be configured in the configuration file during process startup.

    - Support of CPU core binding for service processes (through modification of the **.cfg** file)
    - Support of priority setting for service processes (through modification of the **.cfg** file)
    - Support of MAC address setting (that is, SELinux tag setting) for service processes (through modification of the **.cfg** file)
    - Support of AccessToken setting for service processes and distributed capability setting for system service processes (through modification of the **.cfg** file)
    - Support of the suppression mechanism for service processes (through modification of the **.cfg** file)

    The following is the example configuration for enhanced init process startup and recycling:
      ```
      "services" : [{
          "name" : "serviceName",
          "path" : ["/system/bin/serviceName"]
          "importance" : 1,                  // Priority for service processes
          "cpucore" : [0],                   // CPU binding for service processes
          "critical" : [1, 5, 10],           // Suppression for service processes
          "apl" : "normal",                  // Ability privilege level for service processes
          "d-caps" : ["OHOS_DMS"],           // Distributed capabilities for service processes
          "secon" : "u:r:distributedsche:s0" // SELinux tag for service processes. In this example, the SELinux tag is u:r:distributedsche:s0.
      }
      ```

  - Scheduled startup

    Scheduled startup means to start a service at the specified time. If the service has been started, it will not be started again. For details about the command, see [Description of begetctl Commands](subsys-boot-init-plugin.md).
    ```
    timer_start servicename timeout
    ```
## Basic Process of Creating a Service Process

### Configuring the Service Process Configuration File

  After finishing the service process code, create the **serviceName.cfg** file (**serviceName** indicates the service process name) and configure the file content based on service features.

  Install the configuration file in the corresponding directory. Configure the **/base/startup/init/services/etc/BUILD.gn** file of the init module as follows:

  ```
  ohos_prebuilt_etc("watchdog.cfg") {
    source = "//base/startup/init/services/etc/watchdog.cfg"
    relative_install_dir = "init"
    part_name = "init"
    subsystem_name = "startup"
  }

  ohos_prebuilt_etc("console.cfg") {
    source = "//base/startup/init/services/etc/console.cfg"
    relative_install_dir = "init"
    part_name = "init"
    subsystem_name = "startup"
  }

  ```

  Add the build path of the configuration file to the **bundle.json** file of the corresponding module. For example:

  ```
      "build": {
          "group_type": {
              "base_group": [],
              "fwk_group": [],
              "service_group": [
                  "//base/startup/init/ueventd:startup_ueventd",
                  "//base/startup/init/services/etc:ueventd.cfg"
              ]
            },
      }
  ```
### Configuring the DAC Permission for a Service Process

  Configure the DAC permission for the desired service process based on the GID and UID in the service process configuration file.

  If the corresponding GID and UID do not exist, add them to the **/init/services/etc/passwd** and **/init/services/etc/group** files of the init module.

  - Description of the **passwd** file:

  - Each entry corresponds to a user. User information is separated by colons (:) and divided into seven fields, as shown below:

    ```js
    root:x:0:0:::/bin/false
    bin:x:2:2:::/bin/false
    system:x:1000:1000:::/bin/false
    ```

  Fields in the **passwd** file
  |     SN  |   Field   |                            Description                             |
  | ---------- | --------- | ------------------------------------------------------------ |
  | 1| User name   | Use a name that is easy to remember, for example, **root**. Based on the mapping between user names and user ID (UIDs), the system identifies a user and grants the required user permissions.|
  | 2| Password flag     | **x** indicates that a password has bee set, but not the real password. The real password is stored in the **/etc/shadow** file.|
  | 3| UID       | Each user has a unique UID. The system identifies a user based on the UID.<br>A valid UID ranges from 0 to 65535. Numbers in different ranges represent different UIDs.<br>1. 0: administrator<br>2. 1 to 499: system users<br>3. 500 to 65535: common users|
  | 4| GID       | A GID indicates an initial group. A user has the permissions of the initial group once logging in to the system. Each user can have only one initial group. Generally, the initial group has the same name as the user name.|
  | 5| Description | This field provides a simple description of the user. It is usually left blank.                                              |
  | 6| Home directory   | This field specifies the home directory of a user. For example, the home directory of the **root** user is **/root**. This field is usually left blank.                         |
  | 7| Default shell| Shell is a Linux command interpreter and serves as a bridge between users and the Linux kernel. It is used to convert commands entered by users into machine languages that can be identified by the system. By default, the command interpreter used by the Linux system is usually **/bin/bash**.|

  - Description of the **group** file

  - Each entry corresponds to a user group. User group information is separated by colons (:) and divided into four fields, as shown below:

    ```js
    root:x:0:
    bin:x:2:
    system:x:1000:
    servicectrl:x:1050:root,shell,system,samgr,hdf_devmgr,foundation,update
    ```

  Fields in the **group** file
  |    SN   | Field     |                         Description                      |
  | ---------- | --------- | -------------------------------------------------- |
  | 1| Group name| This field indicates the user group name. For example, **servicectrl** indicates that the user group name is **servicectrl**.|
  | 2| Password flag| Similar to the **/etc/passwd** file, **x** is only the password flag. The encrypted group password is stored in the **/etc/gshdow** file.|
  | 3| GID | GIDs are used to identify different user groups.|
  | 4| Group member| This field indicates the members of a user group. For example, the members of the **servicectrl** group include **root**, **shell**, **system**, **samgr**, **hdf_devmgr**, **foundation**, and **update**.|

  - If the GID and UID are set to **root** or **system**, add a trustlist to the **security_config/high_privilege_process_list.json** file in the corresponding product directory. For example:

  ```
    {
        "high_privilege_process_list": [
            {
                "name": "appspawn",
                "uid": "root",
                "gid": "root"
            },
            {
                "name": "console",
                "uid": "root"
            },
            {
                "name": "testService",
                "uid": "root",
                "gid": "root"
            },
            {
                "name": "media_service",
                "gid": ["root", "system"]
            },
            {
                "name": "misc",
                "uid": "root",
                "gid": "root"
            } ... ...
        ]
    }

  ```
### Configuring the SELinux Permission for a Service Process

- Configuring the SELinux permission

  1. Check whether the service process can be started in permissive mode. If yes, you do not need to configure the **selinux** tag.

  2. To configure SELinux rules, you need to set the SELinux tag in the **secon** field in the configuration file of the service process.

  3. Define the service process tag in the SELinux module. The procedure is as follows:

  Define the tag for program execution in the **base/security/selinux_adapter/sepolicy/base/system/file_contexts** file. For example:

  ```
    /system/bin/watchdog_service        u:object_r:watchdog_service_exec:s0
    /system/bin/hdcd        u:object_r:hdcd_exec:s0
  ```

  Define the applicable scope of the tag in the **base/security/selinux_adapter/sepolicy/base/public/type.te** file. For example:

  ```
    type watchdog_service, sadomain, domain;
    type watchdog_service_exec, exec_attr, file_attr, system_file_attr;
  ```

##  Error Codes

Description of error codes

| Enum              | Value| Error Message                | Description                   |
| ------------------ | ------ | ------------------------ | ----------------------- |
| INIT_OK            | 0      |                          | Operation success.               |
| INIT_EPARAMETER    | 1      | parameter                | Invalid parameter.           |
| INIT_EFORMAT       | 2      | Format string fail       | String format error.       |
| INIT_ECFG          | 3      | cfg error                | Configuration parsing error.            |
| INIT_EPATH         | 4      | Invalid path             | Incorrect service path.       |
| INIT_EFORK         | 5      | Fork fail                | Failed to fork a subprocess.         |
| INIT_ESANDBOX      | 6      | Create sandbox fail      | Failed to add a service to the sandbox.         |
| INIT_EACCESSTOKEN  | 7      | Set access token fail    | Failed to set the access token.   |
| INIT_ESOCKET       | 8      | Create socket fail       | Failed to create a socket.         |
| INIT_EFILE         | 9      | Create file fail         | Failed to create a file.           |
| INIT_ECONSOLE      | 10     | Open console fail        | Failed to open the console.        |
| INIT_EHOLDER       | 11     | Publish holder fail      | Failed to publish the holder.     |
| INIT_EBINDCORE     | 12     | Bind core fail           | Failed to bind cores.               |
| INIT_EKEEPCAP      | 13     | Set keep capability fail | Failed to set **keep capability**.|
| INIT_EGIDSET       | 14     | Set gid fail             | Failed to set the service GID.        |
| INIT_ESECCOMP      | 15     | Set SECCOMP fail         | Failed to set the service security policy.       |
| INIT_EUIDSET       | 16     | Set uid fail             | Failed to set the service UID.        |
| INIT_ECAP          | 17     | Set capability fail      | Failed to set the service capability. |
| INIT_EWRITEPID     | 18     | Write pid fail           | Failed to write the PID.            |
| INIT_ECONTENT      | 19     | Set sub content fail     | Failed to set the service security context. |
| INIT_EPRIORITY     | 20     | Set priority fail        | Failed to set the service priority.     |
| INIT_EEXEC_CONTENT | 21     | Set exec content fail    | Failed to set the SELinux tag.    |
| INIT_EEXEC         | 22     | Exec fail                | Failed to run exec.           |

## Service Process Configuration Example

### Example Code

### Example Configuration

## Available APIs

  **Table 3** Service control APIs
| Function| Description| Parameter Description|
| :----------  |  :----------  |:--------|
| int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | Configures service parameters.| Return value: **0** if the operation is successful; **-1** otherwise.<br> Parameters:<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.<br> **extArgv**: parameter array.<br> **extArgc**: number of parameters.|
| int ServiceControl(const char *serviceName, int action)  | Controls the service behavior.| Return value: **0** if the operation is successful; **-1** otherwise.<br> Parameters:<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.|
| int ServiceWaitForStatus(const char *serviceName, ServiceStatus status, int waitTimeout) | Sets the service waiting status.| Return value: **0** if the operation is successful; **-1** otherwise.<br> Parameters:<br>**serviceName**: service name.<br> **status**: service status.<br> waitTimeout: timeout interval.|
| int ServiceSetReady(const char *serviceName) | Sets a service as being ready.| Return value: **0** if the operation is successful; **-1** otherwise.<br> Parameters:<br> **serviceName**: service name.|
| int StartServiceByTimer(const char *serviceName, uint64_t timeout) | Starts a service by timer.| Return value: **0** if the operation is successful; **-1** otherwise.<br> Parameters:<br> **serviceName**: service name.<br> timeout: timeout interval.|
| int StopServiceTimer(const char *serviceName)  | Stops a service timer.| Return value: **0** if the operation is successful; **-1** otherwise.<br> Parameters:<br> **serviceName**: service name.|

  - The service management APIs are privileged APIs. Therefore, you need to configure the DAC and SELinux permissions as follows:

   - Go to **/base/startup/init/services/etc/group** and add the correct user ID to **servicectrl**. For example:

    ```
    servicectrl:x:1050:root,shell,system,samgr,hdf_devmgr
    ```

  - SELinux configuration for service control APIs

    Add the required SELinux permissions to the **init.te** file. For example, grant the system parameter write permission for services such as **init**, **samgr**, and **hdf_devmgr**.

    ```java
    allow { init samgr hdf_devmgr } servicectrl_param:parameter_service { set };
    ```
## Constraints

The service management module is available only for the mini system and standard system.
## FAQs

For details, see [init Module FAQs](./subsys-boot-init-faqs.md).
