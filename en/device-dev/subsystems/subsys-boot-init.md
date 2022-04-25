# init Module


## Introduction

The init module starts key service processes during system startup. If you would like to add a system service that automatically starts upon system startup, you can add a configuration file named in the **xxx.cfg** format. The system automatically analyzes the **.cfg** file and starts the corresponding service.

- Configuration file of the init module
  The configuration file of the init module, that is, **init.cfg**, contains service names, executable file paths, permissions, and other information of all key system services that need to be started by the init process. The file can be found in **/etc/** after burning is complete. The file is in JSON format, and its size cannot exceed 100 KB.

  After the init process starts, it reads the **/etc/init.cfg** file, parses the content in JSON format, and loads system services in sequence based on the parsing result.

  If you need to add a key service to a module, you can also add the **.cfg** file of the module. During compilation, copy the file to the **/system/etc/init** directory. The init process will parse the **.cfg** file and starts the corresponding service.

- init service startup control (for standard system or higher)
  The init process classifies services into three types based on service configurations and starts the services in different phases.

  - **boot**: services that need to be preferentially started in the system. This type of services are started after the init phase is complete.
  - **normal**: common services in the system. These services are started after the init command is executed successfully. This is the default service type.
  - **condition**: services with special requirements. You can run the **start xxx** command to start such a service. Generally, this type of services are started in a condition job or in a certain phase of the init process.

  If dependencies exist between services or between services and commands, you need to use **condition** to describe services. For example:

  
  ```
   "services" : [{
        "name" : "service1",
        "path" : ["/bin/process1", "param1", "param2"],
        "uid" : 1,
        "gid" : 1,
        "once" : 0,
        "importance" : 1,
        "caps" : [0, 1, 2, 5],
        "start-mode" : "condition",
        "cpucore" : [0],
        "critical" : [0, 5, 10],
        "apl" : "normal",
        "d-caps" : ["OHOS_DMS"]
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:service1_start",
            "on-stop" : "services:service1_stop",
            "on-restart" : "services:service1_restart"
       }
    },
  ```

- init parallel service control (for standard system or higher)
  The init module provides the parallel service processing function, which allows services to execute jobs in different phases.

  - **on-start**: a job executed after the service process is forked. The on-start jobs of different services can be executed in parallel. (The on-start job is executed in the subprocess of the service and affects only the subprocess.)
  - **on-stop**: a job executed when the service is stopped.
  - **on-restart**: a job executed when the service is restarted.

- init on-demand startup (for standard system or higher)
  Services managed by the init process can be started on demand. Such services are not automatically started during system startup. Instead, they are started by the init process only when a certain event occurs. Typical events that trigger service startup are as follows: Messages are sent over the socket listened by the init process. The samgr process receives a request from the client and needs to start the SA service.

  The **ondemand** attribute indicates whether a service is started on demand. If this attribute is set to **true** for a service, the service does not need to be started by running the **start** command. Instead, it is started only when the corresponding event occurs.

  - SA process on-demand startup
     1. When an application requests an SA handle, the samgr process checks whether the process to which the SA belongs can be dynamically started.
     2. If the SA process needs to be started, the samgr process blocks the request. After the init process starts and registers the SA process, the samgr process returns the SA handle.
  - Socket process on-demand startup
     1. The init process creates a socket for socket processes in the pre-fork phase, and listens to network events on this socket.
     2. When messages are detected on the socket, the init process starts the socket process for message processing. The init process then stops listening to network data over the socket and waits until the socket process completes message processing.
     3. If no more messages need to be processed, the socket process can automatically exit. After that, the init process reclaims the subprocess and listens to network data over the socket again.
  - The hot swap service process is started as required. Hot swap events can be started as required based on system parameter changes.

- Enhanced init process startup and recycling
  The CPU core binding, priority, MAC address, and AccessToken information of the service process can be configured in the configuration file during process startup.

  - Support of CPU core binding for service processes (through modification of the **.cfg** file)
  - Support of priority setting for service processes (through modification of the **.cfg** file)
  - Support of AccessToken setting for service processes and distributed capability setting for system service processes (through modification of the **.cfg** file)
  - Support of the suppression mechanism for service processes (through modification of the **.cfg** file)

- init fd proxy (for standard system or higher)
  fd proxy is an extended mechanism for on-demand startup. It can ensure that the fd state handle is not lost before the service process exits. Specifically, a service process sends the fd to the init process before it exits, and then reclaims the fd from the init process when it is started again.

  This mechanism is implemented using the API provided by the init process. Before a service process exits, it can call the related API to send the fd to the init process over the socket that supports IPC communication. After the service process is restarted, the init process returns the corresponding fd handle to it in the same way.

- init job
  A job provided by the init process. It is actually a set of commands. A job can be configured in the **init.cfg** file or the custom **.cfg** file of the module. The parser of the init process aggregates commands of the jobs with the same name into one job. For jobs with the same name, the init process only ensures that the commands in the **init.cfg** file are executed in preference. It does not guarantee the execution sequence of commands in other **.cfg** files.

  - Common job: A job executed in a fixed phase during init process startup, for example, pre-init, init, or post-init.
  - Custom job: A job is triggered based on certain rules.
     - job: A user-defined job, which can be executed using the **trigger** command.
     - Control job (for standard system or higher): A job triggered based on specified conditions. You can set trigger conditions in such a job. When the corresponding attribute values meet the trigger conditions, the job will be triggered. &amp;&amp; and || operations are supported for trigger conditions, and these operations can be used in flexible combinations as needed.


## Development Guidelines

1. Configure the **jobs** array.
   The init module completes the system startup in three phases:

   - **pre-init**: operations required before system services are started, for example, mounting a file system, creating a folder, and modifying permissions.
   - **init**: operations required for starting system services.
   - **post-init**: operations required after system services are started.

     
   ```
    "jobs" : [{
             "name" : "pre-init",
             "cmds" : [
                 "mkdir /testdir",
                 "chmod 0700 /testdir",
                 "chown 99 99 /testdir",
                 "mount vfat /dev/mmcblk0p0 /testdir2 noexec nosuid" // mount command (format: mount file system type source target flags data)
             ]
             }, {
                 "name" : "init",
                 "cmds" : [
                     "start service1",
                     ]
                 }, {
                     "name" : "post-init",
                     "cmds" : []
                 }
             ]
   ```

     **Table 1** Job description
   
   | Job | Description |
   | -------- | -------- |
   | pre-init | Job that is executed first. Operations (for example, creating a folder) required before the process startup are executed in the pre-init job. |
   | init | Job that is executed in between. Operations (for example, service startup) are executed in this job. |
   | post-init | Job that is finally executed. Operations (for example, mounting the device after the driver initialization) required after the process startup are executed in this job. A single job can hold a maximum of 30 commands (Only <strong>start</strong>, <strong>mkdir</strong>, <strong>chmod</strong>, <strong>chown</strong>, <strong>mount</strong>, and <strong>loadcfg</strong> are supported currently). The command name and parameters (128 bytes or less) must be separated by only one space. |

     **Table 2** Commands supported by a job
   
   | Command | Format and Example | Description |
   | -------- | -------- | -------- |
   | mkdir | mkdir <i>target folder</i><br/>Example: mkdir /storage/myDirectory | Creates a folder. <strong>mkdir</strong> and the target folder must be separated by only one space. |
   | chmod | chmod <i>permission</i> <i>target</i><br/>Example:<br/>chmod 0600 /storage/myFile.txt<br/>chmod 0750 /storage/myDir | Modifies the permission, which must be in the <strong>0xxx</strong> format. <strong>chmod</strong>, <i>permission</i>, and <i>target</i> must be separated by only one space. |
   | chown | chown uid gid <i>target</i><br/>Example:<br/>chown 900 800 /storage/myDir<br/>chown 100 100 /storage/myFile.txt | Modifies the owner group. <strong>chown</strong>, <strong>uid</strong>, <strong>gid</strong>, and <i>target</i> must be separated by only one space. |
   | mount | mount fileSystemType src dst flags data<br/>Example:<br/>mount vfat /dev/mmcblk0 /sdc rw,umask=000<br/>mount jffs2 /dev/mtdblock3 /storage nosuid | Mounts devices. Every two parameters must be separated by only one space. Currently, supported flags include <strong>nodev</strong>, <strong>noexec</strong>, <strong>nosuid</strong>, <strong>rdonly</strong>, and optionally <strong>data</strong>. |
   | start | start serviceName<br/>Example:<br/>start foundation<br/>start shell | Starts services. <i>serviceName</i> must be contained in the <strong>services</strong> array. |
   | loadcfg | loadcfg filePath<br/>Example: loadcfg /patch/fstab.cfg | Loads other <strong>.cfg</strong> files. The maximum size of the target file (Only /patch/fstab.cfg supported currently) is 50 KB. Each line in the /patch/fstab.cfg file is a command. The command types and formats must comply with their respective requirements mentioned in this table. A maximum of 20 commands are allowed. |

2. Configure the  <strong>services</strong> array, which holds all system services (a maximum of 100) that need to be started by the init process.
  
   ```
      "services" : [{
           "name" : "service1",
           "path" : ["/bin/process1", "param1", "param2"],
           "uid" : 1,
           "gid" : 1,
           "once" : 0,
           "importance" : 1,
           "caps" : [0, 1, 2, 5],
           "start-mode" : "condition",
           "cpucore" : [0],
           "critical" : [0, 5, 10],
           "apl" : "normal",
           "d-caps" : ["OHOS_DMS"]
           "jobs" : {
               "on-boot" : "boot",
               "on-start" : "services:service1_start",
               "on-stop" : "services:service1_stop",
               "on-restart" : "services:service1_restart"
          }
       }, {
           "name" : "service2",
           "path" : "/bin/process2",
           "uid" : 2,
           "gid" : 2,
           "once" : 1,
           "importance" : 0,
           "caps" : [ ],
           "cpucore" : 0,
           "critical" : [ ],
           "apl" : "normal",
           "d-caps" : [ ]
       }]
   ```

     **Table 3** Service field description
   
   | Field | Description |
   | -------- | -------- |
   | name | Name of the current service. The value must not be empty and can contain a maximum of 32 bytes. |
   | path | Full path (including parameters) of the executable file for the current service. This is an array. Ensure that the first element is the path of the executable file, the maximum number of elements is 20, and each element is a string that contains a maximum of 64 bytes. |
   | uid | User ID (UID) of the current service process. |
   | gid | Group ID (GID) of the current service process. |
   | once | Whether the current service process is a one-off process.<br/><strong>1</strong>: The current service process is a one-off process. If the process exits, the init process does not restart it.<br/><strong>0</strong>: The current service process is not a one-off process. If the process exits, the init process restarts it upon receiving the SIGCHLD signal.<br/>Note: If a non-one-off process exits for five consecutive times within four minutes, the init process will no longer restart it at the fifth exit. |
   |importance | Standard system:<br>Priority of a service process. The value ranges from <strong>-20</strong> to <strong>19</strong>.<br>Small system:<br><strong>0</strong>: non-critical process<br><strong>1</strong>: critical process</p>
   | caps | Capabilities required by the current service. They are evaluated based on the capabilities supported by the security subsystem and configured in accordance with the principle of least permission. Currently, a maximum of 100 values can be configured. |
   | critical | Whether to enable system restarting when a critical service fails to be restarted for a specified number of times. If this field is enabled, the critical service will be started in M seconds. If the restarting fails for N times, the system will be restarted. The default value of N is <strong>4</strong> and that of M is <strong>20</strong>. (Only for standard system or higher. Configuration: [0, 2, 10], in int array.) <br/><strong>0</strong>: disable<br/><strong>1</strong>: enable |
   | cpucore | Number of CPU cores bound to the service. The value is an int array. |
   | d-caps | Distributed capabilities. (Only for standard system or higher) |
   | apl | Ability privilege level, which can be **system_core**, **normal**, or **system_basic**. The default value is **system_core**. (Only for the standard system or higher) |
   | start-mode | Service startup mode. For details, see init Service Startup Control. (Only for standard system or higher) |
   | jobs | Jobs that can be executed by the current service in different phases. For details, see init Service Parallel Service Control. (Only for standard system or higher) |

3. Add socket and on-demand startup configurations for a service. 
   You can configure the **socket** attribute for a service in the JSON format. If a service is configured with the **socket** attribute, the init process will create a socket for the service upon startup. The socket creation time depends on whether on-demand startup is enabled for the service.
   - If on-demand startup is enabled, the init process creates the socket based on the socket configuration obtained from parsing the service.
   - If on-demand startup is disabled, the init process creates a socket before executing the executable file to start the service.

   No matter whether on-demand startup is enabled, a service needs to obtain the handle of the socket created by the init process upon startup, so that it can take over the socket from the init process.
   If on-demand startup is enabled, the init process can also take future processing. Specifically, after creating a socket based on the parsed socket configuration, the init process checks whether the **ondemand** attribute of the service is **true**. If yes, the init process listens to messages sent over the socket in polling mode. When a message is received, the init process stops listening and starts the service to take over the socket and process message.
   
   The following uses the ueventd service as an example to explain how to add socket and on-demand startup configurations.
   ```
   "services" : [{
      "name" : "ueventd",
      "path" : ["/system/bin/ueventd"],
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
      "critical" : [ 0, 15, 5],
      "ondemand" : true,
      "start-mode" : "condition"
     }]
   ```
   **Table 4** Socket field description
   | Field | Description |
   | -------- | -------- |
   | name | Name of the socket. It does not need to be the same as the service name. The value must not be empty and can contain a maximum of 32 bytes.|
   | family | Address family to which the socket belongs. Currently, the AF_UNIX and AF_NETLINK families are supported.|
   | type | Socket type. Currently, connection-based sockets, SOCK_SEQPACKET and SOCK_STREAM, and UDP-based connectionless socket, SOCK_DGRAM, are supported.|
   | protocol | Protocol used for socket communication. Unless otherwise required, set the value to **default** so that the socket automatically selects a proper protocol based on the socket address family and socket type. In addition to the default protocol, the NETLINK_KOBJECT_UEVENT protocol is also supported.|
   | permissions | Permissions of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | uid | User ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | gid | Group ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   | option | Socket option. This field is passed when **setsockopt** is called. Currently, the available options include **SOCKET_OPTION_PASSCRED**, **SOCKET_OPTION_RCVBUFFORCE**, **SOCK_CLOEXEC**, and **SOCK_NONBLOCK**.|
   
   **Table 5** APIs
   
   | API | Function | Description |
   | -------- | -------- | -------- |
   | int *ServiceGetFd(const char *serviceName, size_t *outfdCount) | Obtains the fd from the init process. | Return value: Returns the pointer to the fd array if the operation is successful; returns **NULL** otherwise. (Note: Manual release is required.)<br>Input arguments:<br> **serviceName**: service name.<br>**outfdCount**: length of the returned fd array. |
   | int ServiceSaveFd(const char *serviceName, int *fds, int fdCount) | Requests the init process for fd proxy. | Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Input arguments:<br> **serviceName**: service name.<br> **fds**: pointer to the fd array for fd proxy.<br>**fdCount**: length of the fd array |
   | int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | Configures service parameters. | Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Input arguments:<br>**serviceName**: service name.<br>**action**: service action, which can be **start**, **stop**, or **restart**.<br> **extArgv**: parameter array.<br>**extArgc**: number of parameters. |
   | int ServiceControl(const char *serviceName, int action)  | Controls the service behavior. | Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br>Input arguments:<br>**serviceName**: service name.<br>**action**: service action, which can be **start**, **stop**, or **restart**. |


## Development Example

The following uses the MySystemApp service as an example to illustrate how to use the init process to start a system service.


```
{
    "jobs" : [{
    "name" : "pre-init",
    "cmds" : [
        "mkdir /storage/MyDir",      // Create a folder before starting the MySystemApp service. This operation is executed in the pre-init job.
       "chmod 0600 /storage/MyDir",          // Modify the permission because the MySystemApp service requires that only the current user and its owner group have the read and write permissions on the file.
       "chown 10 10 /storage/MyDir"
      ]
}, {
       "name" : "init",
       "cmds" : [
           "start MySystemApp"         // Start the MySystemApp service in the init job.
        ]
}, {
     "name" : "post-init",
     "cmds" : []                     // Do not configure the post-init job because no other operations are required after the MySystemApp system service is started.
   }
],
    "services" : [{
        "name" : "MySystemApp",       // Name of the system service
        "path" : ["/bin/MySystemAppExe", "param1", "param2", "param3"],    // The executable file path of the MySystemApp service is /bin/MySystemAppExe. To start the service, three parameters ("param1", "param2", and "param3") need to be passed.
        "uid" : 20,         // The UID of the MySystemApp service is 20.
        "gid" : 20,         // The GID of the MySystemApp service is 20.
        "once" : 0,         // Not a one-off process of the MySystemApp service. If MySystemApp exits, the init process needs to restart it.
        "importance" : 0,    // Not a key system process of the MySystemApp service. If MySystemApp exits, the init process does not need to restart the development board.
        "caps" : []           // Do not perform capability-related operations because capabilities are not required by the MySystemApp service.
        "start-mode" : "condition",
        "critical": [1, 2, 10],   // Configure the critical field for MySystemApp system services. You need to pass three parameters, wherein, 1 means to enable system restarting, 2 means the number of times the critical service is restarted, and 10 means the time within which the critical service is restarted.
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

"Failed get servName" is printed in the kernel log. 

**Cause Analysis**

The kernel log is printed by the init process. After a code review on the init process, it is found that the service does not exist.

**Solution**

1. Check whether the service is correctly configured in the **.cfg** file.

2. Check whether the **.cfg** file of the service is loaded normally.

3. Check whether the format of the **.cfg** file is correct.


### Requesting fd Proxy for Other Services Failed

**Symptom**

"Service \' xxx \'(pid = xxx) is not valid or request with unexpected process(pid = xxx)" is printed in the kernel log.

**Cause Analysis**

The kernel log is printed by the init process. After a code review on the init process, it is found that fd proxy is requested for other services.

**Solution**

Request fd proxy for the current service, but not other services.


### No ondemand Configuration

**Symptom**

"service: %s had started already" is printed in the kernel log.

**Cause Analysis**

The kernel log is printed by the init process. After a code review on the init process, it is found that **ondemand** is not configured for the service.

**Solution**

Correct the service configuration in the **.cfg** file as follows: "ondemand" : true
