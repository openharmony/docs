# init Module<a name="EN-US_TOPIC_0000001062722441"></a>

-   [Configuration File](#section56901555917)
-   [Development Guidelines](#section15371931131117)
-   [Development Example](#section173413113565)

The init module starts key service processes during system startup. If you would like to add a system service that automatically starts upon system startup, you can add the service to the **init.cfg** file.

## Configuration File of the init Module<a name="section56901555917"></a>

The configuration file **init.cfg** of the init module contains service names, executable file paths, permissions, and other information of all key system services that need to be started by the init process. The file is stored in the code repository **vendor/huawei/camera/init\_configs/**, and can be found in **/etc/** after burning is complete. The file is in JSON format, and its size cannot exceed 100 KB.

After the init process starts, it reads the **/etc/init.cfg** file, parses the content in JSON format, and loads system services in sequence based on the parsing result.

## Development Guidelines<a name="section15371931131117"></a>

1.  Configure the **jobs** array.

    The init module completes the system startup in three phases:

    -   **pre-init**: operations required before system services are started, for example, mounting a file system, creating a folder, and modifying permissions.
    -   **init**: operations required for starting system services.
    -   **post-init**: operations required after system services are started.

    Each of the preceding phases is represented by a job, which corresponds to a command set. The init module initializes the system by executing the commands in each job in sequence. The **pre-init** job is executed first, then the **init** job, and finally the **post-init** job.

    ```
        "jobs" : [{
                "name" : "pre-init",      
                "cmds" : [                               
                    "mkdir /testdir",      
                    "chmod 0700 /testdir", 
                    "chown 99 99 /testdir",
                    "mkdir /testdir2",
                    "mount vfat /dev/mmcblk0p0 /testdir2 noexec nosuid" // mount command (format: mount file system type source target flags data)
                 ]
            }, {
                "name" : "init",          
                "cmds" : [
                    "start service1",     
                    "start service2"      
                 ]
            }, {
                 "name" : "post-init",  
                 "cmds" : []
            }
        ],
    ```

    **Table 1** Job description

    <a name="table1801509284"></a>
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
    <td class="cellrowborder" valign="top" width="86.6%" headers="mcps1.2.3.1.2 "><p id="p18116016285"><a name="p18116016285"></a><a name="p18116016285"></a>Job that is finally executed. Operations (for example, mounting the device after the driver initialization) required after the process startup are executed in this job.</p>
    </td>
    </tr>
    </tbody>
    </table>

    A single job can hold a maximum of 30 commands (only **start**, **mkdir**, **chmod**, **chown**, **mount**, and **loadcfg** are supported currently). The command name and parameters (128 bytes or less) must be separated by only one space.

    **Table 2** Commands supported by a job

    <a name="table122681439144112"></a>
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
    <td class="cellrowborder" valign="top" width="38.019999999999996%" headers="mcps1.2.4.1.3 "><p id="p13986141320510"><a name="p13986141320510"></a><a name="p13986141320510"></a>Loads other <strong>.cfg</strong> files. The maximum size of the target file (only 
<strong>/patch/fstab.cfg</strong> supported currently) is 50 KB. Each line in the <strong>/patch/fstab.cfg</strong> file is a command. The command types and formats must comply with their respective requirements mentioned in this table. A maximum of 20 commands are allowed.</p>
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
                "caps" : [0, 1, 2, 5]           
        }, {
                "name" : "service2",            
                "path" : "/bin/process2",
                "uid" : 2,
                "gid" : 2,
                "once" : 1,
                "importance" : 0,
                "caps" : [ ]
            }
        ]
    ```

    **Table 3** Fields in the services array

    <a name="table14737791471"></a>
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
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p166448210816"><a name="p166448210816"></a><a name="p166448210816"></a>Whether the current service process is a key system process.</p>
    <p id="p8572182712811"><a name="p8572182712811"></a><a name="p8572182712811"></a><strong>0</strong>: The current service process is not a key system process. If it exits, the init process does not reset or restart the system.</p>
    <p id="p11861032111516"><a name="p11861032111516"></a><a name="p11861032111516"></a><strong>1</strong>: The current service process is a key system process. If it exits, the init process resets and restarts the system.</p>
    </td>
    </tr>
    <tr id="row1689310618179"><td class="cellrowborder" valign="top" width="16.64%" headers="mcps1.2.3.1.1 "><p id="p108931367177"><a name="p108931367177"></a><a name="p108931367177"></a>caps</p>
    </td>
    <td class="cellrowborder" valign="top" width="83.36%" headers="mcps1.2.3.1.2 "><p id="p489313618173"><a name="p489313618173"></a><a name="p489313618173"></a>Capabilities required by the current service. They are evaluated based on the capabilities supported by the security subsystem and configured in accordance with the principle of least permission. Currently, a maximum of 100 values can be configured.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Development Example<a name="section173413113565"></a>

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
     }
     ]
}
```

After the configuration is complete, compile the package to burn the board.

1.  Run the **task -a** command for liteos-a or **ps** for Linux to check whether the MySystemApp service process is started.
2.  Run the **kill** command to kill the MySystemApp process, and then verify that the process will be restarted.
3.  Run the **kill** command to kill the MySystemApp process, and then verify that the development board will not be restarted.
