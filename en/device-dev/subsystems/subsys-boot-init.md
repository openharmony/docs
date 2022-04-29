# init Module

## Introduction

The init module starts key service processes during system startup. If you would like to add a system service that automatically starts upon system startup, you can add a configuration file named in the **xxx.cfg** format. The system automatically analyzes the **.cfg** file and starts the corresponding service.

- Configuration file of the init module

  The configuration file of the init module, that is, **init.cfg**, contains service names, executable file paths, permissions, and other information of all key system services that need to be started by the init process. The file can be found in **/etc/** after burning is complete. The file is in JSON format, and its size cannot exceed 100 KB.

  After the init process starts, it reads the **/etc/init.cfg** file, parses the content in JSON format, and loads system services in sequence based on the parsing result.

  If you need to add a key service to a module, you can also add the **.cfg** file of the module. The file will be copied to the **/system/etc/init** directory during compilation.

  The init process scans the **.cfg** files in the **/etc/init** directory and parses them one by one. The following describes the file scanning rules and format.

  - File scanning rules

    For the mini and standard systems, the same API is used for scanning **.cfg** files. The code is as follows:
    ```
    void ReadConfig(void)
    {
        // parse cfg
        if (InChargerMode() == 1) {
            ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
            ReadFileInDir(OTHER_CHARGE_PATH, ".cfg", ParseInitCfg, NULL);
        } else if (InUpdaterMode() == 0) {
            ParseInitCfg(INIT_CONFIGURATION_FILE, NULL);
            ReadFileInDir(OTHER_CFG_PATH, ".cfg", ParseInitCfg, NULL);
            ReadFileInDir("/vendor/etc/init", ".cfg", ParseInitCfg, NULL);
        } else {
            ReadFileInDir("/etc", ".cfg", ParseInitCfg, NULL);
        }
    }
    ```
    The macro definition in the code is as follows:

    ```
    #define INIT_CONFIGURATION_FILE "/etc/init.cfg"

    #define OTHER_CHARGE_PATH "/system/etc/charge"

    #define OTHER_CFG_PATH "/system/etc/init"
    ```
    The following describes how the init process scans **.cfg** files in normal system startup. File scanning in charging mode and update mode is beyond the scope of this document.
    1. Call the file parsing API to parse the **/etc/init.cfg** file, because this file is one that needs to be preferentially parsed.
    2. Traverse the **.cfg** files in the **/etc/init** directory, and call the parsing API to parse the file when a **.cfg** file is matched. (**/etc** is a symbolic link pointing to **/system/etc** and can be regarded as an equivalent.)
    3. Traverse the **.cfg** files in the **/vendor/etc/init** directory, and call the parsing API to parse the file when a **.cfg** file is matched. The **.cfg** files in this directory are usually related to the hardware platform.

  - File format

    The **.cfg** file format is as follows:
    ```
    {
        "import" : [
                "/etc/init.xxx.cfg",
                "/vendor/etc/init.${ohos.boot.hardware}.cfg"
        ],
        "jobs" : [{
                "name" : "example-stage",
                "cmds" : [
                    "write /example/file 0",
                    "start example"
                ]
            }
        ],
        "services" : [{
                "name" : "example",
                "path" : ["/system/bin/example"],
            }
        ]
    }
    ```
    As mentioned earlier, a **.cfg** file is a text file in JSON format. For the startup module, the init process is required to parse the following types of JSON objects in the **.cfg** file: **import**, **jobs**, and **services**. The three types of JSON objects are described as follows:

    1. "import": other **.cfg** files into the current **.cfg** file. These files will be parsed in sequence after the current **.cfg** file is parsed.
    2. "jobs": command set with a name. Execution of a job is the process of executing commands in **cmds** one by one in sequence. Details about how to trigger a job will be provided in the following sections.
    3. "services": a collection of services. The simplest service can be one that has only a name and an executable file path. The basic logic of a service is to fork a subprocess in the init process and then run the executable file of the service in the subprocess. Services form the core of the startup module. The service configuration in the **.cfg** file also includes various attributes and service control modes. More details will be provided in the following sections.

- init service startup control (for standard system or higher)<a name = "section56901555918">

  The init process classifies services into three types based on service configurations and starts the services in different phases.

  - **boot**: services that need to be preferentially started in the system. This type of services are started in the init phase.
  - **normal**: common services in the system. This type of services are started in the post-init phase. This is the default service type.
  - condition: services that are started based on the specified conditions. You can run the **start xxx** command to start such a service. Generally, this type of services are started in a condition job or in a certain phase of the init process.

  If dependencies exist between services or between services and commands, you need to use **condition** to describe services. For example:
    ```
    "services" : [{
        "name" : "serviceName",
        "start-mode" : "condition",
    },
    ```
- init parallel service control (for standard system or higher)<a name="section56901555919"></a>

  The init module provides the parallel service processing function, which allows services to execute jobs in different phases.

  - **on-start**: a job executed after the service process is forked. The on-start jobs of different services can be executed in parallel. (The on-start job is executed in the subprocess of the service and affects only the subprocess.)
  - **on-stop**: a job executed when the service is stopped.
  - **on-restart**: a job executed when the service is restarted.

  The following is the example configuration:
    ```
  "services" : [{
        "name" : "serviceName",
        "jobs" : {
            "on-boot" : "boot",
            "on-start" : "services:serviceName_start",
            "on-stop" : "services:serviceName_stop",
            "on-restart" : "services:serviceName_restart"
       }
    },
    ```

- init on-demand startup (for standard system or higher)<a name="section56901555920"></a>

  Services managed by the init process can be started on demand. Such services are not automatically started during system startup. Instead, they are started by the init process only when a certain event occurs. Typical events that trigger service startup are as follows: Messages are sent over the socket listened by the init process. The samgr process receives a request from the client and needs to start the SA service.

  The **ondemand** attribute indicates whether a service is started on demand. If this attribute is set to **true** for a service, the service does not need to be started by running the **start** command. Instead, it is started only when the corresponding event occurs.

  The following is the example configuration:
    ```
    "services" : [{
      "name" : "serviceName",
      "ondemand" : true,
  }]
  ```

  - SA process on-demand startup
     1. When an application requests an SA handle, the samgr process checks whether the process to which the SA belongs can be dynamically started.
     2. If the SA process needs to be started, the samgr process blocks the request. After the init process starts and registers the SA process, the samgr process returns the SA handle.
  - Socket process on-demand startup
     1. The init process creates a socket for socket processes in the pre-fork phase and listens to network events on this socket.
     2. When messages are detected on the socket, the init process starts the socket process for message processing. The init process then stops listening to network data over the socket and waits until the socket process completes message processing.
     3. If no more messages need to be processed, the socket process can automatically exit. After that, the init process reclaims the subprocess and listens to network data over the socket again.
  - The hot swap service process is started as required. Hot swap events can be started as required based on system parameter changes.

- Enhanced init process startup and recycling

  The CPU core binding, priority, MAC address, and AccessToken information of the service process can be configured in the configuration file during process startup.

  - Support of CPU core binding for service processes (through modification of the **\*.cfg** file)
  - Support of priority setting for service processes (through modification of the **\*.cfg** file)
  - Support of MAC address setting (that is, SELinux tag setting) for service processes (through modification of the **\*.cfg** file)
  - Support of AccessToken setting for service processes and distributed capability setting for system service processes (through modification of the **\*.cfg** file)
  - Support of the suppression mechanism for service processes (through modification of the **\*.cfg** file)

  The following is the example configuration for enhanced init process startup and recycling:
    ```
    "services" : [{
        "name" : "serviceName",
        "importance" : 1,           // Priority setting for service processes
        "cpucore" : [0],            // CPU binding for service processes
        "critical" : [1, 5, 10],    // Suppression for service processes
        "apl" : "normal",           // Ability privilege level setting for service processes
        "d-caps" : ["OHOS_DMS"],    // Distributed capability setting for service processes
        "secon" : "u:r:distributedsche:s0" // SELinux tag setting for service processes. In this example, u:r:distributedsche:s0 is the SELinux tag.
    },
    ```
- init fd proxy (for standard system or higher)

  fd proxy is an extended mechanism for on-demand startup. It can ensure that the fd state handle is not lost before the service process exits. Specifically, a service process sends the fd to the init process before it exits, and then reclaims the fd from the init process when it is started again.

  This mechanism is implemented using the API provided by the init process. Before a service process exits, it can call the related API to send the fd to the init process over the socket that supports IPC communication. After the service process is restarted, the init process returns the corresponding fd handle to it in the same way. For details about the APIs, see [fd Proxy APIs](#table14737791479).

- init job

  A job provided by the init process. It is actually a set of commands. A job can be configured in the **init.cfg** file or the custom **.cfg** file of the module. The parser of the init process aggregates commands of the jobs with the same name into one job. For jobs with the same name, the init process only ensures that the commands in the **init.cfg** file are executed in preference. It does not guarantee the execution sequence of commands in other **.cfg** files.

  - Common job: A job executed in a fixed phase during init process startup, for example, pre-init, init, or post-init.
  - Custom job: A job is triggered based on certain rules.
     - job: A user-defined job, which can be executed using the **trigger** command.
     - Control job (for standard system or higher): A job triggered based on specified conditions. You can set trigger conditions in such a job. When the corresponding attribute values meet the trigger conditions, the job will be triggered. &amp;&amp; and || operations are supported for trigger conditions, and these operations can be used in flexible combinations as needed.

 - bootchart plug-in

   The bootchart plug-in is an open source tool used to evaluate system performance during Linux startup. It automatically collects information such as the CPU usage, disk throughput, and process status, and displays the evaluation result in graphics to facilitate system startup optimization. For details about the commands provided by begetctl, see [begetctl Command Description](#table14737791480).

    The following describes how to use begetctl in detail.

    Prerequisites
      1. Prepare the test environment by installing Python and PyCairo in Linux.
       pip install pycairo
      2. Decompress bootchart-master.tar.
      tar -zxvf  bootchart-master.tar

    The operation procedure is as follows:
      1. Start the system.
      2. Run the **begetctl bootchart enable** command.
      3. Restart the system.
      4. Run the **begetctl bootchart stop** command.
      5. Run the **begetctl bootchart disable** command.
      6. Export the following files from the **/data/bootchart** directory: <br>
        header<br>
        proc_diskstats.log<br>
        proc_ps.log<br>
        proc_stat.log<br>
       Save the files to the **bootchart** folder.
      7. Run the tar -zcvf bootchart.tgz * command to compress the bootchart.tgz file (only the Linux version is supported) and copy the compressed file to the linux:bootchart-master directory.
      8. Go to the 
        **bootchart-master** directory
        and run the **python3 pybootchartgui.py -f pdf bootchart.tgz** command.<br>

      Expected result: <br>
        &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;A **bootchart.pdf** file is generated in the **bootchart-master** directory.

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
   | :-------- | :-------- |
   | pre-init | Job that is executed first. Operations (for example, creating a folder) required before the process startup are executed in the pre-init job. |
   | init | Job that is executed in between. Operations (for example, service startup) are executed in this job. |
   | post-init | Job that is finally executed. Operations (for example, mounting the device after the driver initialization) required after the process startup are executed in this job. A single job can hold a maximum of 30 commands (Only <strong>start</strong>, <strong>mkdir</strong>, <strong>chmod</strong>, <strong>chown</strong>, <strong>mount</strong>, and <strong>loadcfg</strong> are supported currently). The command name and parameters (128 bytes or less) must be separated by only one space. |

     **Table 2** Commands supported by a job
   | Command | Format and Example | Description | System Type |
   | -------- | -------- | -------- | -------- |
   | mkdir | mkdir <i>target folder</i><br/>Example: mkdir /storage/myDirectory | Creates a folder. <strong>mkdir</strong> and the target folder must be separated by only one space. | small&amp;standard |
   | chmod | chmod <i>permission</i> <i>target</i><br/>Example:<br/>chmod 0600 /storage/myFile.txt<br/>chmod 0750 /storage/myDir | Modifies the permission, which must be in the <strong>0xxx</strong> format. <strong>chmod</strong>, <i>permission</i>, and <i>target</i> must be separated by only one space. | small&amp;standard |
   | chown | chown uid gid <i>target</i><br/>Example:<br/>chown 900 800 /storage/myDir<br/>chown 100 100 /storage/myFile.txt | Modifies the owner group. <strong>chown</strong>, <strong>uid</strong>, <strong>gid</strong>, and <i>target</i> must be separated by only one space. | small&amp;standard |
   | mount | mount fileSystemType src dst flags data<br/>Example:<br/>mount vfat /dev/mmcblk0 /sdc rw,umask=000<br/>mount jffs2 /dev/mtdblock3 /storage nosuid | Mounts devices. Every two parameters must be separated by only one space. Currently, supported flags include <strong>nodev</strong>, <strong>noexec</strong>, <strong>nosuid</strong>, <strong>rdonly</strong>, and optionally <strong>data</strong>. | small&amp;standard |
   | start | start serviceName<br/>Example:<br/>start foundation<br/>start shell | Starts services. <strong>start</strong> must be followed by <i>serviceName</i>, and <i>serviceName</i> must be contained in the <strong>services</strong> array. | small&amp;standard |
   | export | export key value<br/>Example:<br/>export TEST /data/test | Exports environment variables. <strong>key</strong> and <strong>value</strong> respectively indicate the environment variable and its value.| small&amp;standard |
   | rm | rm filename<br/>Example:<br/>rm /data/testfile | Removes a file. <strong>filename</strong> indicates the absolute file path. | small&amp;standard |
   | rmdir | rmdir dirname<br/>Example:<br/>rmdir /data/testdir | Removes a directory. <strong>dirname</strong> indicates the absolute path of the directory. | small&amp;standard | write | write filename value<br/>Example:<br/>write /data/testfile 0 | Writes a file. <strong>filename</strong> and <strong>value</strong> respectively indicate the absolute file path and the string to write. | small&amp;standard |
   | stop | stop servicename<br/>Example:<br/>stop console | Stops a service. <strong>servicename</strong> indicates the name of the service to stop. | small&amp;standard |
   | copy | copy oldfile newfile<br/>Example:<br/>copy /data/old /data/new | Copies a file. <strong>oldfile</strong> and <strong>newfile</strong> respectively indicate the old and new absolute file paths. | small&amp;standard |
   | reset | reset servicename<br/>Example:<br/>reset console | Resets a service. <strong>servicename</strong> indicates the name of the service to reset. If the service has not been started, this command will start the service. If the service is running, the command will stop the service and then restart it.| small&amp;standard |
   | reboot | reboot *subsystem*<br/>Example:<br/>reboot updater | Restarts the system. <strong>subsystem</strong> is optional. If it is not specified, the device enters the current system upon restarting. If it is specified, the device enters the correspoding subsystem upon restarting. For example, if you run **reboot updater**, the device enters the updater subsystem upon restarting. | small&amp;standard |
   | sleep | sleep time<br/>Example:<br/>sleep 5 | Enters the sleep state. <strong>time</strong> indicates the sleep time. | small&amp;standard |
   | domainname | domainname name<br/>Example:<br/>domainname localdomain | Sets a domain name. | small & standard |
   | hostname | hostname name<br/>Example:<br/>hostname localhost | Sets a host name. | small&amp;standard |
   | wait | wait PID<br/>Example:<br/>wait pid | Waits for a command.| small&amp;standard |
   | setrlimit | setrlimit resource curValue maxValue | Sets limitations on resource usage. | small&amp;standard |
   | write | write path content<br/>Example:<br/>write /proc/sys/kernel/sysrq 0 | Writes a file. | small&amp;standard |
   | exec | exec *Path of the executable file* *Parameters passed by the executable file*<br/>Example:<br/>exec /system/bin/udevadm trigger | Runs an executable file. | small&amp;standard |
   | mknode | mknod name { b \| c } Major Minor<br/>Example:<br/>mknod path b 0644 1 9 | Creates an index node corresponding to a directory entry and a special file. For details, see the **mknod** command. | standard |
   | makedev | makedev major minor<br/>Example:<br/>makedev -v update | Creates a static device node, which is usually in the **/dev** directory.| standard |
   | symlink | symlink path1 path2<br/>Example:<br/>symlink /proc/self/fd/0 /dev/stdin | Creates a symbolic link. | standard |
   | trigger | trigger jobName<br/>Example:<br/>trigger early-fs | Triggers a job. | standard |
   | insmod | insmod *ko file*<br/>Example:<br/>insmod *xxx*.ko| Loads a kernel module file. | standard |
   | setparam | setparam *paramname* *paramvalue*<br/>Example:<br/>setparam sys.usb.config hdc | Sets a system parameter.| standard |
   | load_persist_params | load persist params<br/>Example:<br/>load_persist_params&nbsp; | Loads **persist** parameters. There must be one and only one space after the **load_persist_params** command. | standard |
   | load_param | load params<br/>Example:<br/>load_param /data/test.normal.para | Loads the parameters from a file to the memory.| standard |
   | load_access_token_id | Example:<br/>load_access_token_id&nbsp; | Writes the access token to the **data/service/el0/access_token/nativetoken.json** file. There is one and only one space after **load_access_token_id**.| standard |
   | ifup | ifup *NIC*<br/>Example:<br/>ifup eth0 | Activates the specified NIC.| standard |
   | mount_fstab | mount_fstab fstab.test<br/>Example:<br/>mount_fstab /vendor/etc/fstab.test | Mounts partitions based on the **fstab** file. | standard |
   | umount_fstab | umount_fstab fstab.test<br/>Example:<br/>umount_fstab /vendor/etc/fstab.test | Unmounts partitions based on the **fstab** file. | standard |
   | restorecon | restorecon file or dir<br/>Example:<br/>restorecon /file | Reloads the SELinux context. | standard |
   | stopAllServices | stopAllServices [bool]<br/>Example:<br/>stopAllServices false<br/>stopAllServices | Stops all services. | standard |
   | umount |umount path<br/>Example:<br/>umount /vendor | Unmounts a mounted device. | standard |
   | sync | Example:<br/>sync&nbsp; | Writes data to the disk synchronously. There is only one and only one space after **sync**.| standard |
   | timer_start | timer_start serviceName<br/>Example:<br/>timer_start console | Starts the service timer. | standard |
   | timer_stop | timer_stop serviceName<br/>Example:<br/>timer_stop console | Stops the service timer. | standard |
   | init_global_key | init_global_key path<br/>Example:<br/>init_global_key /data | Initializes the encryption key of the data partition file.| standard |
   | init_main_user | Example:<br/>init_main_user| Encrypts the main user directory.| standard |
   | mkswap | mkswap file<br/>Example:<br/>mkswap /swapfile1 | Creates a swap partition on a file or device. | standard |
   | swapon | swapon file<br/>Example:<br/>swapon /swapfile1 | Activates the swap space. | standard |
   | loadcfg | loadcfg *filePath*<br/>Example:<br/>loadcfg /patch/fstab.cfg | Loads other <strong>.cfg</strong> files. The maximum size of the target file (Only /patch/fstab.cfg supported currently) is 50 KB. Each line in the /patch/fstab.cfg file is a command. The command types and formats must comply with their respective requirements mentioned in this table. A maximum of 20 commands are allowed. | small |

2.  Configure the <strong>services</strong> array, which holds all system services that need to be started by the init process.

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
        "d-caps" : ["OHOS_DMS"],
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

    **Table 3** Service field description<a name="table14737791471"></a>

    | Field | Description | Value | System Type |
    | ---------- |-------- | --------| --------|
    | name | Name of the current service. | Type: string. The value cannot be empty and can contain a maximum of 32 bytes.| small&amp;standard |
    | path | Full path (including parameters) of the current service's executable file, in array. | The first element is the path of the executable file, and the maximum number of elements is 20. <br>Each element is a string that contains a maximum of 64 bytes.| small&amp;standard |
    | uid | User ID (UID) of the current service process. | Type: int | small&standard |
    | gid | Group ID (GID) of the current service process. | Type: int | small&standard |
    | once | Whether the current service process is a one-off process. | **1**: The current service process is a one-off process. If the process exits, the init process does not restart it. <br>**0**: The current service process is not a one-off process. If the process exits, the init process restarts it upon receiving the SIGCHLD signal. | small&amp;standard |
    | importance | Current service priority. | Standard system: <br>The service priority ranges from **-20** to **19**. A value beyond the range is invalid. <br>Small-scale system:<br>**0**: unimportant process<br>non-0: important process | small&amp;standard |
    | caps | Capabilities required by the current service. They are evaluated based on the capabilities supported by the security subsystem and configured in accordance with the principle of least permission. | Type: number or string array. If you set the value to a number, use the standard Linux capability. If you set the value to a string array, use the standard macro name. | small&amp;standard |
    | critical | Suppression mechanism for services. If the number of times a service is restarted exceeds the value N within the specified period T, the system will be restarted. | Standard system:<br>Type: int array, for example, **"critical": [M, N, T]**.<br>- **M**: enable flag (**0**: disable; **1**: enable)<br>- N: number of times the service is started<br>- **T**: period of time, in seconds <br>Both **M** and **N** must be greater than **0**.<br>Small and standard systems:<br>Type: int, for example, **"critical": M**.<br>**M**: enable flag (**0**: disable; **1**: enable)<br>By default, **N** is **4** and **T** is **20**. | small&amp;standard |
    | cpucore | Number of CPU cores to be bound to the service. | Type: int array, for example, **"cpucore": [N1, N2, ...]**. **N1** and **N2** indicate the indices of the CPU cores to be bound.<br>For a single-core device, **cpucore** is **0**. | small&amp;standard |
    | d-caps | Service distribution capability. (Available only for the standard system or higher) | Type: string array, for example, **"d-caps": ["OHOS_DMS"]**. | standard |
    | apl | Ability privilege level. (Available only for the standard system or higher) | Type: string, for example, **"apl": "system_core"**. <br>The value can be **system_core** (default), **normal**, or **system_basic**. | standard |
    | start-mode | Service startup mode. (Available only for the standard system or higher) | Type: string, for example, **"start-mode": "condition"**. <br>The value can be **boot**, **normal**, or **condition**. For details, see [init service startup control](#section56901555918). | standard |
    | jobs | Jobs that can be executed by the current service in different phases. For details, see [init parallel control](#section56901555919). | small&amp;standard |
    | ondemand | Whether to enable on-demand service startup. |Type: bool, for example, **"ondemand": true**. For small systems, this feature is available only on the Linux kernel. For details, see [init on-demand startup](#section56901555920). | small&amp;standard |
    | disable | Reserved. | | small&amp;standard |
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
      "critical" : [ 0, 5, 15],
      "ondemand" : true,
      "start-mode" : "condition"
     }]
   ```

   **Table 4** Socket field description
   |Field| Description|
   | -------- | -------- |
   |name|Name of the socket. It does not need to be the same as the service name. The value must not be empty and can contain a maximum of 32 bytes.|
   |family|Address family to which the socket belongs. Currently, the AF_UNIX and AF_NETLINK families are supported.|
   |type|Socket type. Currently, connection-based sockets, SOCK_SEQPACKET and SOCK_STREAM, and UDP-based connectionless socket, SOCK_DGRAM, are supported.|
   |protocol|Protocol used for socket communication. Unless otherwise required, set the value to **default** so that the socket automatically selects a proper protocol based on the socket address family and socket type. In addition to the default protocol, the NETLINK_KOBJECT_UEVENT protocol is also supported.|
   |permissions|Permissions of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   |uid|User ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   |gid|Group ID of the socket node file. This field is valid only for sockets that have entity node files, such as the AF_UNIX address family.|
   |option|Socket option. This field is passed when **setsockopt** is called. Currently, the available options include **SOCKET_OPTION_PASSCRED**, **SOCKET_OPTION_RCVBUFFORCE**, **SOCK_CLOEXEC**, and **SOCK_NONBLOCK**.|

    **Table 5** fd proxy APIs<a name="table14737791479"></a>

   | API    | Description|Parameters |
   | ----------  |  ----------  |--------|
   | int *ServiceGetFd(const char *serviceName, size_t *outfdCount) | Obtains the fd from the init process.| Return value: Returns the pointer to the fd array if the operation is successful; returns **NULL** otherwise. (Note: Manual release is required.)<br>Parameters<br> **serviceName**: service name.<br>**outfdCount**: length of the returned fd array.|
   | int ServiceSaveFd(const char *serviceName, int *fds, int fdCount) | Requests the init process for fd proxy.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br> **serviceName**: service name.<br> **fds**: pointer to the fd array for fd proxy.<br>**fdCount**: length of the fd array
   | int ServiceSaveFdWithPoll(const char *serviceName, int *fds, int fdCount)  | Requests fd proxy in poll mode.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br> **serviceName**: service name.<br> **fds**: pointer to the fd array.<br> **fdCount**: length of the fd array.

    ** Table 6** Service control APIs

   | API    | Description|Parameters |
   | :----------  |  :----------  |:--------|
   | int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | Configures service parameters.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.<br> **extArgv**: parameter array.<br> **extArgc**: number of parameters.|
   | int ServiceControl(const char *serviceName, int action)  | Controls the service behavior.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.|
   | int ServiceWaitForStatus(const char *serviceName, ServiceStatus status, int waitTimeout) | Waiting for service status| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br>**serviceName**: service name.<br> **status**: service status.<br> **waitTimeout**: waiting timeout interval.|
   | int ServiceSetReady(const char *serviceName) | Sets a service as being ready.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br> **serviceName**: service name.|
   | int StartServiceByTimer(const char *serviceName, uint64_t timeout) | Starts a service by timer.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br> **serviceName**: service name.<br> timeout: timeout interval.|
   | int StopServiceTimer(const char *serviceName)  | Stops a service timer.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Parameters<br> **serviceName**: service name.|

    **Table 7** begetctl commands<a name="table14737791480"></a>

   | Command| Format and Example| Description|
   | :----------  |  :----------  |:--------|
   | init group test [stage] | Initializes a group test.<br/>Example:<br/>init group test| For details about **stage**, see **ServiceStatus**.|
   | param ls [-r] [name] | Displays system parameters.<br/>Example:<br/><br>begetctl param ls persist.sys.usb   | N/A|
   | param get [name] | Obtains system parameter information<br/>Example:<br/><br>begetctl param get<br/>param get| N/A|
   | param set name value| Sets system parameters.<br/>Example:<br/><br>begetctl param set ohos.servicectrl.display 1<br/>param set ohos.servicectrl.display 1| N/A|
   | param wait name [value] [timeout] | Waits for system parameters.<br/>Example:<br/><br>begetctl param wait persist.sys.usb.config hdc<br/>param wait persist.sys.usb.config hdc| The default value of **timeout** is **30**.|
   | param dump [verbose] | Dumps system parameter information.<br/>Example:<br/><br>begetctl param dump<br/>param dump| N/A|
   | param shell [name] | Enters the parameter shell.<br/>Example:<br/><br>begetctl param shell<br/>param shell| N/A|
   | timer_stop servicename | Stops the service timer.<br/>Example:<br/><br>begetctl timer_stop appspawn | The value of **servicename** can contain a maximum of 96 characters.|
   | timer_start servicename timeout | Starts the service timer.<br/>Example:<br/><br>begetctl timer_start appspawn | The value of **servicename** can contain a maximum of 96 characters. The default value of **timeout** is **10**.|
   | start_service servicename | Starts a service.<br/>Example:<br/><br>begetctl start_service appspawn<br/>start_service appspawn| N/A|
   | stop_service servicename | Stops a service.<br/>Example:<br/><br>begetctl stop_service appspawn<br/>stop_service appspawn| N/A|
   | service_control start servicename | Starts a service.<br/>Example:<br/><br>begetctl service_control start appspawn<br/>service_control start appspawn| N/A|
   | service_control stop servicename | Stops a service.<br/>Example:<br/><br>begetctl service_control stop appspawn<br/>service_control stop appspawn | N/A|
   | misc_daemon --write_logo xxx.rgb | Writes the startup logo.<br/>Example:<br/><br>begetctl misc_daemon --write_logo logo.rgb<br/>misc_daemon --write_logo logo.rgb| The maximum size of an RGB file is **1024*2038**. Only Hi3516D V300 is supported.|
   | reboot | Restarts the system.<br/>Example:<br/><br>begetctl reboot<br/>reboot|N/A|
   | reboot shutdown | Shuts down the system.<br/>Example:<br/><br>begetctl reboot shutdown<br/>reboot shutdown|N/A|
   | reboot suspend | Suspends the system.<br/>Example:<br/><br>begetctl reboot suspend<br/>reboot suspend| N/A|
   | reboot updater | Restarts the system and enters updater.<br/>Example:<br/><br>begetctl reboot updater<br/>reboot updater| N/A|
   | reboot updater[:options] | Restarts the system and enters updater.<br/>Example:<br/><br>begetctl reboot updater<br/>reboot updater| N/A|
   | reboot flashd | Restarts the system and enters flashd.<br/>Example:<br/><br>begetctl reboot flashd<br/>reboot flashd| N/A|
   | reboot flashd[:options] | Restarts the system and enters flashd.<br/>Example:<br/><br>begetctl reboot flashd<br/>reboot flashd| N/A|
   | reboot charing | Restarts the system and enters the charing mode.<br/>Example:<br/><br>begetctl reboot charing<br/>reboot charing| N/A|
   | reboot loader | Restarts the system and enters the burning mode.<br/>Example:<br/><br>begetctl reboot loader<br/>reboot loader| N/A|
   | bootchart stop | Stops chart analysis.<br/>Example:<br/><br>begetctl bootchart stop | Only rk3568 is supported.|
   | bootchart start | Starts chart analysis.<br/>Example:<br/><br>begetctl bootchart start | N/A|
   | bootchart disable | Disables chart analysis.<br/>Example:<br/><br>begetctl bootchart disable | N/A|
   | bootchart enable | Enables chart analysis.<br/>Example:<br/><br>begetctl bootchart enable | N/A|

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
        "cpucore" : [0, 1],  // The device has two cores and both of them are bound to the CPU.
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
