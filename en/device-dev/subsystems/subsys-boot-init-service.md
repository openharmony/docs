# Service Management
## Overview
### Function
Service configuration allows you to configure services on demand to create different value-added services. Currently, the following value-added services are supported: startup control, on-demand startup, command execution, scheduled startup, FD proxy, and [sandbox](subsys-boot-init-sandbox.md).

### Basic Concepts

- init service parameter options

  For details, see [Description of service Fields](#table14737791471).

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

  The following is an example of service configuration:
  ```
  "services" : [{
        "name" : "serviceName",
        "path" : ["/system/bin/serviceName"]
        "jobs" : {
            "on-boot" : "boot",
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

  - Support of CPU core binding for service processes (through modification of the <strong>*.cfg</strong> file)
  - Support of priority setting for service processes (through modification of the <strong>*.cfg</strong> file)
  - Support of MAC address setting (that is, SELinux tag setting) for service processes (through modification of the <strong>*.cfg</strong> file)
  - Support of AccessToken setting for service processes and distributed capability setting for system service processes (through modification of the <strong>*.cfg</strong> file)
  - Support of the suppression mechanism for service processes (through modification of the <strong>*.cfg</strong> file)

  The following is the example configuration for enhanced init process startup and recycling:
    ```
    "services" : [{
        "name" : "serviceName",
        "path" : ["/system/bin/serviceName"]
        "importance" : 1,                  // Priority setting for service processes
        "cpucore" : [0],                   // CPU binding for service processes
        "critical" : [1, 5, 10],           // Suppression for service processes
        "apl" : "normal",                  // Ability privilege level setting for service processes
        "d-caps" : ["OHOS_DMS"],           // Distributed capability setting for service processes
        "secon" : "u:r:distributedsche:s0" // SELinux tag setting for service processes. In this example, u:r:distributedsche:s0 is the SELinux tag.
    }
    ```

- SELinux tag

  To enable the SELinux policy for a service, add the SELinux tag to the service in the **secon** field. For example, to add the SELinux tag to watchdog_service, use the following code snippet:

    ```
    "services" : [{
              "name" : "watchdog_service",
              "secon" : "u:r:watchdog_service:s0"
    }]
    ```
    Note that you need to define the tag in SELinux. For details, see the appropriate SELinux guide.

- init service FD proxy (for standard system or higher)

  FD proxy is an extended mechanism for on-demand startup. It can ensure that the FD state handle is not lost before the service process exits. Specifically, a service process sends the FD to the init process before it exits, and then reclaims the FD from the init process when it is started again.

  This mechanism is implemented using the API provided by the init process. Before a service process exits, it can call the related API to send the FD to the init process over the socket that supports IPC communication. After the service process is restarted, the init process returns the corresponding FD handle to it in the same way. For details about the APIs, see [FD Proxy APIs](#table14737791479).
  
- Scheduled startup

  Scheduled startup means to start a service at the specified time. If the service has been started, it will not be started again. For details about the command, see [Description of begetctl Commands](subsys-boot-init-plugin.md#parameters).
  ```
  timer_start servicename timeout
  ```
- Sandbox

  For details, see [Sandbox Management](subsys-boot-init-sandbox.md).

### Constraints

The service management module is available only for the mini system and standard system.

## How to Develop
### Use Cases
By parsing the <strong>*.cfg</strong> file, you can obtain **service** fields, and then set and start the service.

### Parameters
   **Table 1** Description of service fields<a name="table14737791471"></a>
   | Name| Meaning| Description| Supported System Type|
   | ---------- |-------- | --------| --------|
   | name          | Name of the current service. (Mandatory)|  Type: string. The value cannot be empty and can contain a maximum of 32 bytes.| Small and standard systems |
   | path          | Full path (including parameters) of the executable file for the current service. This is an array. (Mandatory)| The first element is the path of the executable file, and the maximum number of elements is 20.<br> Each element is a string that contains a maximum of 64 bytes.| Small and standard systems|
   | uid           | User ID (UID) of the current service process.| Type: int or string.| Small and standard systems|
   | gid           | Group ID (GID) of the current service process.| Type: int, int[], string, or string array.| Small and standard systems|
   | once          | Whether the current service process is a one-off process.| <strong>1</strong>: The current service process is a one-off process. If the process exits, the init process does not restart it.<br><strong>0</strong>: The current service process is not a one-off process. If the process exits, the init process restarts it upon receiving the SIGCHLD signal.| Small and standard systems|
   | importance    | Standard system: service priority<br>Small system: service importance| <br>Standard system: The service priority ranges from -20 to 19. A value beyond the range is invalid.<br>Small system: The value <strong>0</strong> indicates an unimportant process and a value greater than <strong>0</strong> indicates an important process.| Small and standard systems|
   | caps          | Capabilities required by the current service. They are evaluated based on the capabilities supported by the security subsystem and configured in accordance with the principle of least permission.| Type: number or string array. If you set the value to a number, use the standard Linux capability. If you set the value to a string array, use the standard macro name.| Small and standard systems|
   | critical      | Suppression mechanism for services. If the number of times a service is restarted exceeds the value N within the specified period T, the system will be restarted.| <br>Standard system:<br>Type: int array, for example, <strong>"critical": [M, N, T]</strong>.<br>- <strong>M</strong>: enable flag (<strong>0</strong>: disable; <strong>1</strong>: enable).<br>- <strong>N</strong>: number of times the service is started.<br>- <strong>T</strong>: period of time, in seconds.<br> Both <strong>M</strong> and <strong>N</strong> are greater than <strong>0</strong>.<br> Small and standard systems:<br>Type: int, for example, <strong>"critical": M</strong>.<br><strong>M</strong>: enable flag (<strong>0</strong>: disable; <strong>1</strong>: enable).<br> By default, <strong>N</strong> is <strong>4</strong> and <strong>T</strong> is <strong>20</strong>.| Standard system|
   | cpucore      | Number of CPU cores bound to the service.| Type: int array, for example, <strong>"cpucore": [N1, N2, ...]</strong>. <strong>N1</strong> and <strong>N2</strong> indicate the indicate of the CPU cores to be bound. For a single-core device, <strong>cpucore</strong> is <strong>0</strong>.| Standard system|
   | d-caps       | Distributed service capability.| Type: string array, for example, <strong>"d-caps": ["OHOS_DMS"]</strong>.| Standard system|
   | apl          | Ability privilege level.| Type: string, for example, <strong>"apl": "system_core"</strong>.<br> The value can be <strong>system_core</strong> (default), <strong>normal</strong>, or <strong>system_basic</strong>.| Standard system|
   | start-mode   | Service startup mode.| Type: string, for example, **"start-mode": "condition"**.<br>The value can be <strong>boot</strong>, <strong>normal</strong>, or <strong>condition</strong>. For details, see [init service startup control](#section56901555918).| Standard system|
   | ondemand     | Whether on-demand startup is enabled.| Type: bool, for example, **"ondemand": true**. For small systems, this feature is available only on the Linux kernel.<br>For details, see [init Service On-Demand Startup](#section56901555920).| Small and standard systems|
   | disable | Reserved.| None.| Small and standard systems|
   | sandbox | Whether the sandbox function is enabled.| <strong>1</strong> (default): Enable the sandbox function.<br><strong>0</strong>: Disable the sandbox function.| Standard system|

   **Table 2** Description of socket fields
   | Name| Description|
   | -------- | -------- |
   | name | Name of the socket. It does not need to be the same as the service name. The value must not be empty and can contain a maximum of 32 bytes.|
   | family | Address family to which the socket belongs. Currently, the AF_UNIX and AF_NETLINK families are supported.|
   | type | Socket type. Currently, connection-based sockets, SOCK_SEQPACKET and SOCK_STREAM, and UDP-based connectionless socket, SOCK_DGRAM, are supported.|
   | protocol | Protocol used for socket communication. Unless otherwise required, set the value to **default** so that the socket automatically selects a proper protocol based on the socket address family and socket type. In addition to the default protocol, the NETLINK_KOBJECT_UEVENT protocol is also supported.|
   | permissions | Permissions of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | uid | User ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | gid | Group ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | option | Socket option. This field is passed when **setsockopt** is called. Currently, the available options include <strong>SOCKET_OPTION_PASSCRED</strong>, <strong>SOCKET_OPTION_RCVBUFFORCE</strong>, <strong>SOCK_CLOEXEC</strong>, and <strong>SOCK_NONBLOCK</strong>.|

### Available APIs
  **Table 3** FD proxy APIs<a name="table14737791479"></a>
   | API    | Function| Description |
   | ---------- |  ----------  |--------|
   | int *ServiceGetFd(const char *serviceName, size_t *outfdCount) | Obtains the proxy FD from the init process.| Return value: Returns the pointer to the fd array if the operation is successful; returns **NULL** otherwise. (Note: Manual release is required.)<br>Arguments:<br> **serviceName**: service name.<br>**outfdCount**: length of the returned FD array.|
   | int ServiceSaveFd(const char *serviceName, int *fds, int fdCount) | Requests the init process for FD proxy.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br> **serviceName**: service name.<br> **fds**: pointer to the FD array for FD proxy.<br>**fdCount**: length of the FD array.
   | int ServiceSaveFdWithPoll(const char *serviceName, int *fds, int fdCount)  | Requests FD proxy in poll mode.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br> **serviceName**: service name.<br> **fds**: pointer to the FD array.<br> **fdCount**: length of the FD array.

  **Table 4** Service control APIs
   | API| Function| Description|
   | :----------  |  :----------  |:--------|
   | int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | Configures service parameters.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.<br> **extArgv**: parameter array.<br> **extArgc**: number of parameters.|
   | int ServiceControl(const char *serviceName, int action)  | Controls the service behavior.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.|
   | int ServiceWaitForStatus(const char *serviceName, ServiceStatus status, int waitTimeout) | waiting for the service status.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br>**serviceName**: service name.<br> **status**: service status.<br> **waitTimeout**: waiting timeout interval.|
   | int ServiceSetReady(const char *serviceName) | Sets a service as being ready.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br> **serviceName**: service name.|
   | int StartServiceByTimer(const char *serviceName, uint64_t timeout) | Starts a service by timer.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br> **serviceName**: service name.<br> timeout: timeout interval.|
   | int StopServiceTimer(const char *serviceName)  | Stops a service timer.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Arguments:<br> **serviceName**: service name.|

-  DAC configuration for service control APIs

   Go to **/base/startup/init/services/etc/group** and add the correct user ID to **servicectrl**. For example:

   ```java
   servicectrl:x:1050:root,shell,system,samgr,hdf_devmgr
   ```

-  SELinux configuration for service control APIs

   Add the required SELinux permissions to the **init.te** file. For example, grant the system parameter write permission for services such as **init**, **samgr**, and **hdf_devmgr**.

   ```java
   allow { init samgr hdf_devmgr } servicectrl_param:parameter_service { set };
   ```

### How to Develop
   The following describes how to add a system service named **MySystemApp**:

```
{
    "jobs" : [{
    "name" : "pre-init",
    "cmds" : [
        "mkdir /storage/MyDir",       // Create a folder before starting the MySystemApp service. This operation is executed in the pre-init job.
        "chmod 0600 /storage/MyDir",  // Modify the permission because the MySystemApp service requires that only the current user and its owner group have the read and write permissions on the file.
        "chown 10 10 /storage/MyDir"
        ]
}, {
      "name" : "init",
      "cmds" : [
          "start MySystemApp"         // Start the MySystemApp service in the init job.
      ]
}, {
    "name" : "post-init",
    "cmds" : []                       // Do not configure the post-init job because no other operations are required after the MySystemApp system service is started.
    }
],
    "services" : [{
        "name" : "MySystemApp",       // Name of the system service
        "path" : ["/bin/MySystemAppExe", "param1", "param2", "param3"],    // The executable file path of the MySystemApp service is /bin/MySystemAppExe. To start the service, three parameters ("param1", "param2", and "param3") need to be passed.
        "socket" : [{
          "name" : "ueventd",
          "family" : "AF_NETLINK",
          "type" : "SOCK_DGRAM",
          "protocol" : "NETLINK_KOBJECT_UEVENT",
          "permissions" : "0660",
          "uid" : "system",
          "gid" : "system",
          "option" : [
            "SOCKET_OPTION_PASSCRED",
            "SOCKET_OPTION_RCVBUFFORCE",
            "SOCK_CLOEXEC",
            "SOCK_NONBLOCK"
          ]
        }],
        "uid" : 20,                   // UID of the MySystemApp service: 20
        "gid" : 20,                   // GID of the MySystemApp service: 20
        "once" : 0,                   // Not a one-off process of the MySystemApp service. If MySystemApp exits, the init process needs to restart it.
        "importance" : 0,             // Not a key system process of the MySystemApp service. If MySystemApp exits, the init process does not need to restart the development board.
        "caps" : [],                  // Do not perform capability-related operations because capabilities are not required by the MySystemApp service.
        "start-mode" : "condition",
        "critical": [1, 2, 10],       // Configure the critical field for MySystemApp system services. You need to pass three parameters, wherein, 1 means to enable system restarting, 2 means the number of times the critical service is restarted, and 10 means the time within which the critical service is restarted.
        "cpucore" : [0, 1],           // The device has two cores and both of them are bound to the CPU.
        "apl" : "system_core",
        "d-caps" : ["OHOS_DMS"],
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:MySystemApp_start",
            "on-stop" : "services:MySystemApp_stop",
            "on-restart" : "services:MySystemApp_restart"
        }
      }
    ]
}
```

After the configuration is complete, compile the package to burn the board.
  1. Run the **task -a** command for liteos-a or **ps** for Linux to check whether the MySystemApp service process is started.
  2. Run the **kill** command to kill the MySystemApp process, and verify that the process will be restarted.
  3. Run the **kill** command to kill the MySystemApp process, and verify that the development board will not be restarted.


## FAQs
### Service Not Exist

**Symptom**

"Failed get servName" is recorded in the kernel log.

**Cause Analysis**

After a code review on the init process, it is found that the service does not exist.

**Solution**

1. Check whether the service is correctly configured in the **.cfg** file.
2. Check whether the **.cfg** file of the service is loaded normally.
3. Check whether the format of the **.cfg** file is correct.

### Requesting FD Proxy for Other Services Failed

**Symptom**

"Service' xxx '(pid = xxx) is not valid or request with unexpected process(pid = xxx)" is recorded in the kernel log.

**Cause Analysis**

The kernel log is printed by the init process. After a code review on the init process, it is found that FD proxy is requested for other services.

**Solution**

Request FD proxy for the current service, but not other services.
