# init Module<a name="EN-US_TOPIC_0000001062722441"></a>

## Introduction<a name="section56901555916">

  The init module starts key service processes during system startup. If you would like to add a system service that automatically starts upon system startup, you can add a configuration file named in the **xxx.cfg** format. The system automatically analyzes the **.cfg** file and starts the corresponding service.

- Configuration file of the init module<a name="section56901555917"></a>

   The configuration file of the init module, that is, **init.cfg**, contains service names, executable file paths, permissions, and other information of all key system services that need to be started by the init process. The file can be found in **/etc/** after burning is complete. The file is in JSON format, and its size cannot exceed 100 KB.

  After the init process starts, it reads the **/etc/init.cfg** file, parses the content in JSON format, and loads system services in sequence based on the parsing result.

  If you need to add a key service to a module, you can also add the **.cfg** file of the module. During compilation, copy the file to the **/system/etc/init** directory. The init process will parse the **.cfg** file and starts the corresponding service.

- init service startup control (for standard system or higher)<a name="section56901555918"></a>

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
- init parallel service control (for standard system or higher)<a name="section56901555919"></a>

  The init module provides the parallel service processing function, which allows services to execute jobs in different phases.

  - **on-start**: a job executed after the service process is forked. The on-start jobs of different services can be executed in parallel. (The on-start job is executed in the subprocess of the service and affects only the subprocess.)
  - **on-stop**: a job executed when the service is stopped.
  - **on-restart**: a job executed when the service is restarted.

- init on-demand startup (for standard system or higher)<a name="section56901555920"></a>

  Services managed by the init process can be started on demand. Such services are not automatically started during system startup. Instead, they are started by the init process only when a certain event occurs. Typical events that trigger service startup are as follows: Messages are sent over the socket listened by the init process. The samgr process receives a request from the client and needs to start the SA service.

  The **ondemand** attribute indicates whether a service is started on demand. If this attribute is set to **true** for a service, the service does not need to be started by running the **start** command. Instead, it is started only when the corresponding event occurs.

  - SA process on-demand startup
    1. When an application requests an SA handle, the samgr process checks whether the process to which the SA belongs can be dynamically started.
    2. If the SA process needs to be started, the samgr process blocks the request. After the init process starts and registers the SA process, the samgr process returns the SA handle.

  - Socket process on-demand startup
    1. The init process creates a socket for socket processes in the pre-fork phase, and listens to network events on this socket.
    2. When messages are detected on the socket, the init process starts the socket process for message processing. The init process then stops listening to network data over the socket and waits until the socket process completes message processing.
    3. If no more messages need to be processed, the socket process can automatically exit. After that, the init process reclaims the subprocess and listens to network data over the socket again.

  - Hot-swap service process on-demand startup
    <br> &emsp; The hot-swap service process can be started to process hot swap events based on system parameter changes.

- Enhanced init process startup and recycling<a name="section56901555921"></a>

  The CPU core binding, priority, MAC address, and AccessToken information of the service process can be configured in the configuration file during process startup.

  - Support of CPU core binding for service processes (through modification of the **.cfg** file)
  - Support of priority setting for service processes (through modification of the **.cfg** file)
  - Support of AccessToken setting for service processes and distributed capability setting for system service processes (through modification of the **.cfg** file)
  - Support of the suppression mechanism for service processes (through modification of the **.cfg** file)

- init fd proxy (for standard system or higher)<a name="section56901555922"></a>

  fd proxy is an extended mechanism for on-demand startup. It can ensure that the fd state handle is not lost before the service process exits. Specifically, a service process sends the fd to the init process before it exits, and then reclaims the fd from the init process when it is started again.

  This mechanism is implemented using the API provided by the init process. Before a service process exits, it can call the related API to send the fd to the init process over the socket that supports IPC communication. After the service process is restarted, the init process returns the corresponding fd handle to it in the same way.

- init job<a name="section56901555923"></a>

  A job provided by the init process. It is actually a set of commands. A job can be configured in the **init.cfg** file or the custom **.cfg** file of the module. The parser of the init process aggregates commands of the jobs with the same name into one job. For jobs with the same name, the init process only ensures that the commands in the **init.cfg** file are executed in preference. It does not guarantee the execution sequence of commands in other **cfg** files.

  - Common job: A job executed in a fixed phase during init process startup, for example, pre-init, init, or post-init.

  - Custom job: A job is triggered based on certain rules.
    - job: A user-defined job, which can be executed using the **trigger** command.
    - Control job (for standard system or higher): A job triggered based on specified conditions. You can set trigger conditions in such a job. When the corresponding attribute values meet the trigger conditions, the job will be triggered. && and || operations are supported for trigger conditions, and these operations can be used in flexible combinations as needed.

## Development Guidelines<a name="section56901555924"></a>

  1. Configure the **jobs** array.

      The init module completes the system startup in three phases:

      -   **pre-init**: operations required before system services are started, for example, mounting a file system, creating a folder, and modifying permissions.
      -   **init**: operations required for starting system services.
      -   **post-init**: operations required after system services are started.

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

**Table 1** Job description<a name="table1801509284"></a>
<table><thead align="left"><tr id="row680703289"><th class="cellrowborder" valign="top" width="13.4%" id="mcps1.2.3.1.1"><p id="p11805012282"><a name="p11805012282"></a><a name="p11805012282"></a>Job</p>
    </th>
<th class="cellrowborder" valign="top" width="86.6%" id="mcps1.2.3.1.2"><p id="p2811605289"><a name="p2811605289"></a><a name="p2811605289"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row178140112810"><td class="cellrowborder" valign="top" width="13.4%" headers="mcps1.2.3.1.1 "><p id="p6811809281"><a name="p6811809281"></a><a name="p6811809281"></a>pre-init</p>
    </td>
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p18115019284"><a name="p18115019284"></a><a name="p18115019284"></a>Job that is executed first. Operations (for example, creating a folder) required before the process startup are executed in the pre-init job.</p>
    </td>
    </tr>
    <tr id="row381120182817"><td class="cellrowborder" valign="top" width="13.4%" headers="mcps1.2.3.1.1 "><p id="p148116002812"><a name="p148116002812"></a><a name="p148116002812"></a>init</p>
    </td>
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p14818016288"><a name="p14818016288"></a><a name="p14818016288"></a>Job that is executed in between. Operations (for example, service startup) are executed in this job.</p>
    </td>
    </tr>
    <tr id="row181100162813"><td class="cellrowborder" valign="top" width="13.4%" headers="mcps1.2.3.1.1 "><p id="p3811804281"><a name="p3811804281"></a><a name="p3811804281"></a>post-init</p>
    </td>
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p18116016285"><a name="p18116016285"></a><a name="p18116016285"></a>Job that is finally executed. Operations (for example, mounting the device after the driver initialization) required after the process startup are executed in this job. A single job can hold a maximum of 30 commands (Only <strong>start</strong>, <strong>mkdir</strong>, <strong>chmod</strong>, <strong>chown</strong>, <strong>mount</strong>, and <strong>loadcfg</strong> are supported currently). The command name and parameters (128 bytes or less) must be separated by only one space.</p>
    </td>
    </tr>
    </tbody>
    </table>

**Table 2** Commands supported by a job<a name="table122681439144112"></a>
<table><thead align="left"><tr id="row826873984116"><th class="cellrowborder" valign="top" width="10.15%" id="mcps1.2.4.1.1"><p id="p826833919412"><a name="p826833919412"></a><a name="p826833919412"></a>Command</p>
    </th>
<th class="cellrowborder" valign="top" width="51.83%" id="mcps1.2.4.1.2"><p id="p3381142134118"><a name="p3381142134118"></a><a name="p3381142134118"></a>Format and Example</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.019999999999996%" id="mcps1.2.4.1.3"><p id="p1268539154110"><a name="p1268539154110"></a><a name="p1268539154110"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row142681039124116"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p2083714604313"><a name="p2083714604313"></a><a name="p2083714604313"></a>mkdir</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p143811842154111"><a name="p143811842154111"></a><a name="p143811842154111"></a>mkdir <i>target folder</i></p>
    <p id="p4377174213435"><a name="p4377174213435"></a><a name="p4377174213435"></a>Example: mkdir /storage/myDirectory</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p56817536457"><a name="p56817536457"></a><a name="p56817536457"></a>Creates a folder. <strong>mkdir</strong> and the target folder must be separated by only one space.</p>
    </td>
    </tr>
    <tr id="row1268133919413"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p97961563461"><a name="p97961563461"></a><a name="p97961563461"></a>chmod</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p20381144234118"><a name="p20381144234118"></a><a name="p20381144234118"></a>chmod <i>permission</i> <i>target</i></p>
    <p id="p6334213124413"><a name="p6334213124413"></a><a name="p6334213124413"></a>Example: chmod 0600 /storage/myFile.txt</p>
    <p id="p1748214543444"><a name="p1748214543444"></a><a name="p1748214543444"></a>chmod 0750 /storage/myDir</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p2023822074614"><a name="p2023822074614"></a><a name="p2023822074614"></a>Modifies the permission, which must be in the <strong>0xxx</strong> format. <strong>chmod</strong>, <i>permission</i>, and <i>target</i> must be separated by only one space.</p>
    </td>
    </tr>
    <tr id="row7268143918416"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p8255346174610"><a name="p8255346174610"></a><a name="p8255346174610"></a>chown</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p238114423418"><a name="p238114423418"></a><a name="p238114423418"></a>chown uid gid <i>target</i></p>
    <p id="p1118592184518"><a name="p1118592184518"></a><a name="p1118592184518"></a>Example: chown 900 800 /storage/myDir</p>
    <p id="p1235374884510"><a name="p1235374884510"></a><a name="p1235374884510"></a>chown 100 100 /storage/myFile.txt</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p18408185817467"><a name="p18408185817467"></a><a name="p18408185817467"></a>Modifies the owner group. <strong>chown</strong>, <strong>uid</strong>, <strong>gid</strong>, and <i>target</i> must be separated by only one space.</p>
    </td>
    </tr>
    <tr id="row109751379478"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p1017823174717"><a name="p1017823174717"></a><a name="p1017823174717"></a>mount</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p10381124244117"><a name="p10381124244117"></a><a name="p10381124244117"></a>mount fileSystemType src dst flags data</p>
    <p id="p572019493485"><a name="p572019493485"></a><a name="p572019493485"></a>Example: mount vfat /dev/mmcblk0 /sdc rw,umask=000</p>
    <p id="p7381173625313"><a name="p7381173625313"></a><a name="p7381173625313"></a>mount jffs2 /dev/mtdblock3 /storage nosuid</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p11976107144710"><a name="p11976107144710"></a><a name="p11976107144710"></a>Mounts devices. Every two parameters must be separated by only one space. Currently, supported flags include <strong>nodev</strong>, <strong>noexec</strong>, <strong>nosuid</strong>, <strong>rdonly</strong>, and optionally <strong>data</strong>.</p>
    </td>
    </tr>
    <tr id="row1334911198482"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p1214153117480"><a name="p1214153117480"></a><a name="p1214153117480"></a>start</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p133816420411"><a name="p133816420411"></a><a name="p133816420411"></a>start serviceName</p>
    <p id="p2036714132541"><a name="p2036714132541"></a><a name="p2036714132541"></a>Example: start foundation</p>
    <p id="p115951820185412"><a name="p115951820185412"></a><a name="p115951820185412"></a>start shell</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p4350121915488"><a name="p4350121915488"></a><a name="p4350121915488"></a>Starts services. <i>serviceName</i> must be contained in the <strong>services</strong> array.</p>
    </td>
    </tr>
    <tr id="row96921442712"><td class="cellrowborder" valign="top" width="10.15%" headers="mcps1.2.4.1.1 "><p id="p1693642018"><a name="p1693642018"></a><a name="p1693642018"></a>loadcfg</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.83%" headers="mcps1.2.4.1.2 "><p id="p1969364211116"><a name="p1969364211116"></a><a name="p1969364211116"></a>loadcfg filePath</p>
    <p id="p1858112368211"><a name="p1858112368211"></a><a name="p1858112368211"></a>Example: loadcfg /patch/fstab.cfg</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p13986141320510"><a name="p13986141320510"></a><a name="p13986141320510"></a>Loads other <strong>.cfg</strong> files. The maximum size of the target file (Only /patch/fstab.cfg supported currently) is 50 KB. Each line in the /patch/fstab.cfg file is a command. The command types and formats must comply with their respective requirements mentioned in this table. A maximum of 20 commands are allowed.</p>
    </td>
    </tr>
    </tbody>
    </table>

  2.  Configure the  <strong>services</strong> array, which holds all system services (a maximum of 100) that need to be started by the init process.

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

**Table 3** Service field description<a name="table14737791471"></a>

<table><thead align="left"><tr id="row273839577"><th class="cellrowborder" valign="top" width="16.64%" id="mcps1.2.3.1.1"><p id="p107382095711"><a name="p107382095711"></a><a name="p107382095711"></a>Field</p>
    </th>
    <th class="cellrowborder" valign="top" width="83.36%" id="mcps1.2.3.1.2"><p id="p17738189277"><a name="p17738189277"></a><a name="p17738189277"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17386911716"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p17384912710"><a name="p17384912710"></a><a name="p17384912710"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p1173818913714"><a name="p1173818913714"></a><a name="p1173818913714"></a>Name of the current service. The value cannot be empty and can contain a maximum of 32 bytes.</p>
    </td>
    </tr>
    <tr id="row1473810916714"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p127381991571"><a name="p127381991571"></a><a name="p127381991571"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p1073815910717"><a name="p1073815910717"></a><a name="p1073815910717"></a>Full path (including parameters) of the executable file for the current service. This is an array. Ensure that the first element is the path of the executable file, the maximum number of elements is 20, and each element is a string that contains a maximum of 64 bytes.</p>
    </td>
    </tr>
    <tr id="row77381291271"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p77381391770"><a name="p77381391770"></a><a name="p77381391770"></a>uid</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p107387920711"><a name="p107387920711"></a><a name="p107387920711"></a>User ID (UID) of the current service process.</p>
    </td>
    </tr>
    <tr id="row127381591673"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p47388919715"><a name="p47388919715"></a><a name="p47388919715"></a>gid</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p12738691479"><a name="p12738691479"></a><a name="p12738691479"></a>Group ID (GID) of the current service process.</p>
    </td>
    </tr>
    <tr id="row188301014171116"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p183112146115"><a name="p183112146115"></a><a name="p183112146115"></a>once</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p18548317195715"><a name="p18548317195715"></a><a name="p18548317195715"></a>Whether the current service process is a one-off process.</p>
    <p id="p103571840105812"><a name="p103571840105812"></a><a name="p103571840105812"></a><strong>1</strong>: The current service process is a one-off process. If the process exits, the init process does not restart it.</p>
    <p id="p5831191431116"><a name="p5831191431116"></a><a name="p5831191431116"></a><strong>0</strong>: The current service process is not a one-off process. If the process exits, the init process restarts it upon receiving the SIGCHLD signal.</p>
    <p id="p378912714010"><a name="p378912714010"></a><a name="p378912714010"></a>Note: If a non-one-off process exits for five consecutive times within four minutes, the init process will no longer restart it at the fifth exit.</p>
    </td>
    </tr>
    <tr id="row386110321155"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p14861113212156"><a name="p14861113212156"></a><a name="p14861113212156"></a>importance</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p166448210816"><a name="p166448210816"></a><a name="p166448210816"></a>Standard system:<br>Priority of a service process. The value ranges from <strong>-20</strong> to <strong>19</strong>.<br>Small system:<br><strong>0</strong>: non-critical process<br><strong>1</strong>: critical process</p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>caps</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Capabilities required by the current service. They are evaluated based on the capabilities supported by the security subsystem and configured in accordance with the principle of least permission. Currently, a maximum of 100 values can be configured.</p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>critical</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Whether to enable system restarting when a critical service fails to be restarted for a specified number of times. If this field is enabled, the critical service will be started in M seconds. If the restarting fails for N times, the system will be restarted. The default value of N is <strong>4</strong> and that of M is <strong>20</strong>. (Only for standard system or higher. Configuration: [0, 2, 10], in int array.)<a name="section56901555917"></a><a name="section56901555917"></a></p>
    <p id="p8572182712811"><a name="p8572182712811"></a><a name="p8572182712811"></a><strong>0</strong>: enable</p>
    <p id="p11861032111517"><a name="p11861032111517"></a><a name="p11861032111517"></a><strong>1</strong>: disable</p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>cpucore</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Number of CPU cores bound to the service. The value is an int array.<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>d-caps</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Distributed capabilities (Only for standard system or higher)<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>apl</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Ability privilege level: <strong>system_core</strong>, <strong>normal</strong>, or <strong>system_basic</strong>. The default value is <strong>system_core</strong>. (Only for the standard system or higher).<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>start-mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Service startup mode. For details, see init Service Startup Control. (Only for standard system or higher)<a name="section56901555917"></a><a name="section56901555917"></a></p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>jobs</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Jobs that can be executed by the current service in different phases. For details, see init Service Parallel Service Control. (Only for standard system or higher)<a name="section56901555917"></a></p>
    </td>
    </tr>
    </tbody>
    </table>

  **Table 4**  APIs

  | API    | Function|Description |
  | :----------  |  :----------  |:--------|
  | int *ServiceGetFd(const char *serviceName, size_t *outfdCount) | Obtains the fd from the init process.| Return value: Returns the pointer to the fd array if the operation is successful; returns **NULL** otherwise. (Note: Manual release is required.)<br>Input arguments:<br> **serviceName**: service name.<br>**outfdCount**: length of the returned fd array.|
  | int ServiceSaveFd(const char *serviceName, int *fds, int fdCount) | Requests the init process for fd proxy.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Input arguments:<br> **serviceName**: service name.<br> **fds**: pointer to the fd array for fd proxy.<br>**fdCount**: length of the fd array
  | int ServiceControlWithExtra(const char *serviceName, int action, const char *extArgv[], int extArgc) | Configures service parameters.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Input arguments:<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.<br> **extArgv**: parameter array.<br> **extArgc**: number of parameters.
  | int ServiceControl(const char *serviceName, int action)  | Controls the service behavior.| Return value: Returns **0** if the operation is successful; returns **-1** otherwise.<br> Input arguments:<br> **serviceName**: service name.<br> **action**: service action, which can be **start**, **stop**, or **restart**.

## Development Example<a name="section56901555925"></a>

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

1.  Run the **task -a** command for liteos-a or **ps** for Linux to check whether the MySystemApp service process is started.
2.  Run the **kill** command to kill the MySystemApp process, and then verify that the process will be restarted.
3.  Run the **kill** command to kill the MySystemApp process, and then verify that the development board will not be restarted.

## FAQ<a name="section56901555926"></a>

### Service Not Exist<a name="section56901555927"></a>

  &emsp; **Symptom** <br>
    &emsp;&emsp; "Failed get servName" is recorded in the kernel log.

  &emsp; **Cause Analysis** <br>
     &emsp; &emsp; The kernel log is printed by the init process. After a code review on the init process, it is found that the service does not exist.

   &emsp; **Solution** <br>
   &emsp;  &emsp; 1. Check whether the service is correctly configured in the **.cfg** file. <br>
   &emsp;  &emsp; 2. Check whether the **.cfg** file of the service is loaded normally. <br>
   &emsp;  &emsp; 3. Check whether the format of the **.cfg** file is correct.

### Requesting FD Proxy for Other Services Failed<a name="section56901555928"></a>

&emsp; **Symptom**

   &emsp; &emsp; "Service \' xxx \'(pid = xxx) is not valid or request with unexpected process(pid = xxx)" is recorded in the kernel log.

  &emsp; **Cause Analysis** <br>
     &emsp; &emsp; The kernel log is printed by the init process. After a code review on the init process, it is found that fd proxy is requested for other services.

  &emsp; **Solution** <br>
    &emsp; &emsp; Request fd proxy for the current service, but not other services.

### No ondemand Configuration<a name="section56901555929"></a> is not configured for the service.

  &emsp; **Symptom** <br>
     &emsp; &emsp; "service: %s had started already" is recorded in the kernel log.

  &emsp; **Cause Analysis** <br>
     &emsp; &emsp; The kernel log is printed by the init process. After a code review on the init process, it is found that **ondemand** is not configured for the service.

  &emsp; **Solution** <br>
     &emsp; &emsp; Correct the service configuration in the **.cfg** file as follows: "ondemand" : true
