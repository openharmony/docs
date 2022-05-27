# Startup<a name="EN-US_TOPIC_0000001124561621"></a>

## Introduction<a name="section11660541593"></a>

The Startup subsystem provides the functions of starting key system processes and services after the kernel is started and before applications are started, and restoring the system to factory settings. The subsystem consists of the following modules:

-   init\_lite

    This module can be used on the Hi3516D V300 and Hi3518E V300 platforms powered by LiteOS Cortex-A.

    It starts system service processes from the time the kernel loads the first user-space process to the time the first application is started. In addition to loading key system processes, the module needs to configure their permissions during the startup and keep the specified process alive after sub-processes are started. If a process exits abnormally, the module needs to restart it, and to perform system reset for a special process.


-   appspawn\_lite

    This module can be used on the Hi3516D V300 and Hi3518E V300 platforms powered by LiteOS Cortex-A.

    This module spawns application processes upon receiving commands from the application framework, configures permissions for new processes, and calls the entry function of the application framework.

-   bootstrap\_lite

    This module can be used on the Hi3861 platform powered by LiteOS Cortex-M.

    This module provides entry identifiers for starting services and features. When Samgr starts, it will call the entry function identified by bootstrap\_lite and start system services.

-   syspara\_lite

    This module obtains and sets system attributes.

    It can be used on the Hi3861, Hi3516D V300, and Hi3518E V300 platforms powered by LiteOS Cortex-M and LiteOS Cortex-A. Supported system attributes consist of default, OEM-specified, and custom system attributes. OEM-specified system attributes provide only default values. The specific values need to be adjusted as required. For details, see  [Usage Guidelines](#section8533192617117).


## Directory Structure<a name="section161941989596"></a>

**Table  1**  Directory structure of the source code for the startup subsystem

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="20.880000000000003%" id="mcps1.2.4.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="65.2%" id="mcps1.2.4.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="13.919999999999998%" id="mcps1.2.4.1.3"><p id="p101617019356"><a name="p101617019356"></a><a name="p101617019356"></a>Applicable Platform</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>base/startup/appspawn_lite</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>appspawn_lite module for spawning application processes. It receives Ability Manager Service (AMS) messages via IPC, parses the messages, starts application processes based on the parsing result, and grants permissions to them.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p63463619360"><a name="p63463619360"></a><a name="p63463619360"></a>Hi3516D V300</p>
<p id="p141611802359"><a name="p141611802359"></a><a name="p141611802359"></a>Hi3518E V300</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p37931659101311"><a name="p37931659101311"></a><a name="p37931659101311"></a>base/startup/bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p6793059171318"><a name="p6793059171318"></a><a name="p6793059171318"></a>bootstrap_lite module for starting all services except core system services.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p101610019353"><a name="p101610019353"></a><a name="p101610019353"></a>Hi3861</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" align="left" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p117935599130"><a name="p117935599130"></a><a name="p117935599130"></a>base/startup/init_lite</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p0793185971316"><a name="p0793185971316"></a><a name="p0793185971316"></a>init_lite module for implementing the init process, which is the first user-space process loaded after the kernel is initialized. Upon startup, the process parses the configuration file in <strong id="b9210192971613"><a name="b9210192971613"></a><a name="b9210192971613"></a>/etc/init.cfg</strong>. Based on the parsing result, the process then starts other key system processes and grants required permissions to them.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p2176757193619"><a name="p2176757193619"></a><a name="p2176757193619"></a>Hi3516D V300</p>
<p id="p51611013358"><a name="p51611013358"></a><a name="p51611013358"></a>Hi3518E V300</p>
</td>
</tr>
<tr id="row1897841071415"><td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p469782418557"><a name="p469782418557"></a><a name="p469782418557"></a>base/startup/syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p15697102412558"><a name="p15697102412558"></a><a name="p15697102412558"></a>syspara_lite module that provides APIs to obtain device information, including the product name, brand name, category name, and manufacturer name.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p1956516512380"><a name="p1956516512380"></a><a name="p1956516512380"></a>Hi3861</p>
<p id="p2670195353812"><a name="p2670195353812"></a><a name="p2670195353812"></a>Hi3516D V300</p>
<p id="p116118053518"><a name="p116118053518"></a><a name="p116118053518"></a>Hi3518E V300</p>
</td>
</tr>
</tbody>
</table>

```
base/startup/
├── appspawn_standard         # appspawn_lite module for the standard system
│   ├── include               # Header files
│   ├── parameter             # System parameters
│   ├── src                   # Source files 
│   └── test                  # Test cases 
├── appspawn_lite             # appspawn_lite module for the mini system
│   └── services
│       ├── include           # Header files 
│       ├── src              # Source files 
│       └── test              # Test cases
├── bootstrap_lite           # bootstrap_lite module
│   └── services
│       └── source            # Source files 
├── init_lite                 # init_lite module
│   ├── initsync              # Source files
│   ├── interfaces            # External APIs
│   └── services
│       ├── include           # Header files 
│       ├── src               # Source files 
│       └── test              # Test cases
└── syspara_lite              # syspara_lite module
    ├── adapter               # Adaptation code
    ├── frameworks            # Source files
    ├── hals                  # Header files for the hardware abstraction layer (HAL)
    ├── interfaces            # External APIs
    └── simulator             # Simulator adaptation
```

## Constraints<a name="section1718733212019"></a>

OEM-specified system attributes provide only default values. The specific values need to be adjusted as required.

## Usage Guidelines<a name="section8533192617117"></a>

-   Configuration file of the init\_lite module

    The configuration file  **init.cfg**  of the init\_lite module contains service names, executable file paths, permissions, and other attributes of all key system services that need to be started by the init process. The file is stored in  **/vendor/hisilicon/hispark\_aries/init\_configs/**  under  **/etc/**. It is in JSON format, and its size cannot exceed 100 KB.

    After the init process starts, it reads the  **/etc/init.cfg**  file, parses the JSON content, and loads system services in sequence based on the parsing result. The format and content of the configuration file are described as follows:


```
{
    "jobs" : [{
            "name" : "pre-init",      -------- Job executed before the initialization. It can be used to store some operations (for example, creating a directory) performed before the init process is started.
            "cmds" : [                -------- Commands supported by the current job. Currently, only start, mkdir, chmod, chown, and mount are currently supported.
                                      -------- The command name and the parameters (128 bytes or less) must be separated by only one space.
                 "mkdir /testdir",      -------- Command for creating a directory. mkdir and the target directory must be separated by only one space.
                "chmod 0700 /testdir", -------- Command for modifying the permission. chmod, permission, and the target directory must be separated by only one space. The permission must be in the 0xxx format.
                "chown 99 99 /testdir",-------- Command for modifying the owner group. chown, UID, GID, and the target directory must be separated by only one space.
                "mkdir /testdir2",
                "mount vfat /dev/mmcblk0p0 /testdir2 noexec nosuid" -------- mount command in the following format: mount file system type source target flags data
                                                                    -------- Supported flags include only nodev, noexec, nosuid, and rdonly, which are separated by a space.
            ]
        }, {
            "name" : "init",          -------- Job name, which currently supports only pre-init, init, and post-init.
            "cmds" : [                -------- A single job currently supports a maximum of 30 commands.
                "start service1",     -------- Service startup command 1.
                "start service2"      -------- Service startup command 2. The sequence of the commands in the array can be adjusted as required. The init process then executes the commands in the same sequence as they are parsed.
             ]
        }, {
             "name" : "post-init",    -------- Job executed after the initialization. It can be used to store some operations performed after the init process is started.
             "cmds" : []
        }
    ],
    "services" : [{                         -------- Service set (in an array), including all system services that need to be started by the init process. Currently, a maximum of 100 services are supported.
            "name" : "service1",            -------- Name of the current service. A maximum of 32 bytes must be specified for the name.
            "path" : "/bin/process1"        -------- Full path of the executable file of the current service. A maximum of 64 bytes must be specified for the path.
            "uid" : 1,                      -------- UID of the current service process.
            "gid" : 1,                      -------- GID of the current service process.
            "once" : 0,                     -------- Whether the current service process is a one-off process.
                                                     0 --- The current service process is not a one-off process. If the process exits for a certain reason, the init_lite module restarts the service process upon receiving the SIGCHLD signal.
                                                   non-0 --- The current service process is a one-off process. If the process exits for a certain reason, the init_lite module does not restart the service process.
            "importance" : 1,               -------- Whether the current service process is a key system process
                                                     0 --- The current service process is not a key system process. If the process exits due to any reason, the init_lite module does not reset the system.
                                                   non-0 --- The current service process is a key system process. If the process exits due to any reason, the init_lite module resets and restarts the system upon receiving the SIGCHLD signal.
            "caps" : [0, 1, 2, 5]           -------- Capabilities required by the current service. They are determined by the capabilities supported by the security subsystem and configured in accordance with the principle of least permission. (Currently, a maximum of 100 values can be configured.)
    }, {
            "name" : "service2",            -------- Next service that needs to be started by the init_lite module. The service sequence is irrelevant to the startup sequence, which is determined by the command sequence in the previous job.
            "path" : "/bin/process2",
            "uid" : 2,
            "gid" : 2,
            "once" : 1,
            "importance" : 0,
            "caps" : [ ]
        }
    ]
}
```

**Table  2**  Supported commands

<a name="table9623104414018"></a>
<table><thead align="left"><tr id="row5623144194017"><th class="cellrowborder" valign="top" width="12.5%" id="mcps1.2.4.1.1"><p id="p56231449404"><a name="p56231449404"></a><a name="p56231449404"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="31.05%" id="mcps1.2.4.1.2"><p id="p962313447401"><a name="p962313447401"></a><a name="p962313447401"></a>Syntax</p>
</th>
<th class="cellrowborder" valign="top" width="56.45%" id="mcps1.2.4.1.3"><p id="p88724434113"><a name="p88724434113"></a><a name="p88724434113"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row962344416405"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p66231144104011"><a name="p66231144104011"></a><a name="p66231144104011"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p862384484010"><a name="p862384484010"></a><a name="p862384484010"></a>start ServiceName (Only one space is allowed.)</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p17872104184113"><a name="p17872104184113"></a><a name="p17872104184113"></a>Starts a service. The service name must be the same as that in the <strong id="b796816343013"><a name="b796816343013"></a><a name="b796816343013"></a>services</strong> array in the file.</p>
</td>
</tr>
<tr id="row962311443404"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p13837142094117"><a name="p13837142094117"></a><a name="p13837142094117"></a>mkdir</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p2624244204019"><a name="p2624244204019"></a><a name="p2624244204019"></a>mkdir /xxxx/xxx (Only one space is allowed.)</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p158722484112"><a name="p158722484112"></a><a name="p158722484112"></a>Creates a directory.</p>
</td>
</tr>
<tr id="row662404414406"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p3624444154011"><a name="p3624444154011"></a><a name="p3624444154011"></a>chmod</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p7624344134020"><a name="p7624344134020"></a><a name="p7624344134020"></a>chmod 0xxx /xxx/xx (Only one space is allowed.)</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p18872945418"><a name="p18872945418"></a><a name="p18872945418"></a>Changes the permission. The permission value must be in <strong id="b14310113211018"><a name="b14310113211018"></a><a name="b14310113211018"></a>0<em id="i81751135191019"><a name="i81751135191019"></a><a name="i81751135191019"></a>xxx</em></strong> format, for example, <strong id="b6674104131011"><a name="b6674104131011"></a><a name="b6674104131011"></a>0755</strong> or <strong id="b052484351010"><a name="b052484351010"></a><a name="b052484351010"></a>0600</strong>. This configuration must comply with the principle of least permission.</p>
</td>
</tr>
<tr id="row1462404494017"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p136241144144013"><a name="p136241144144013"></a><a name="p136241144144013"></a>chown</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p1624144194011"><a name="p1624144194011"></a><a name="p1624144194011"></a>chown uid gid /xxx/xx (Only one space is allowed.)</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p9872246417"><a name="p9872246417"></a><a name="p9872246417"></a>Changes the owner group.</p>
</td>
</tr>
<tr id="row1285512468412"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p1385515468413"><a name="p1385515468413"></a><a name="p1385515468413"></a>mount</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p358535124815"><a name="p358535124815"></a><a name="p358535124815"></a>mount fileSysType source target flags data (Only one space is allowed.)</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p1085544611415"><a name="p1085544611415"></a><a name="p1085544611415"></a>Mounts data. Currently, <strong id="b7289320311"><a name="b7289320311"></a><a name="b7289320311"></a>flags</strong> can only be <strong id="b83343113120"><a name="b83343113120"></a><a name="b83343113120"></a>nodev</strong>, <strong id="b733193123116"><a name="b733193123116"></a><a name="b733193123116"></a>noexec</strong>, <strong id="b1033173113116"><a name="b1033173113116"></a><a name="b1033173113116"></a>nosuid</strong>, or <strong id="b16332038317"><a name="b16332038317"></a><a name="b16332038317"></a>rdonly</strong>, and other strings are considered as <strong id="b1234103113120"><a name="b1234103113120"></a><a name="b1234103113120"></a>data</strong>.</p>
</td>
</tr>
</tbody>
</table>

It is worth noting that the modified  **init.cfg**  file must be in JSON format. Otherwise, the init process fails to parse the file, and no service will be started. The configured service permission  **uid/gid/capability**  must meet the requirements imposed by the security subsystem and comply with the principle of least permission. In addition, if the values of  **once**  and  **importance**  of a service are both  **0**  and the service exits for more than four consecutive times within four minutes, the init process will stop restarting the service.

-   System parameters
    -   OEM-specific system attributes

        For Hi3516D V300 and Hi3518E V300 development boards, you need to modify the source files in the  **vendor/hisilicon/hispark\_aries/hals/utils/sys\_param**  directory.

        ```
        static const char HOS_PRODUCT_TYPE[] = {"****"};
        static const char HOS_MANUFACTURE[] = {"****"};
        static const char HOS_BRAND[] = {"****"};
        static const char HOS_MARKET_NAME[] = {"****"};
        static const char HOS_PRODUCT_SERIES[] = {"****"};
        static const char HOS_PRODUCT_MODEL[] = {"****"};
        static const char HOS_SOFTWARE_MODEL[] = {"****"};
        static const char HOS_HARDWARE_MODEL[] = {"****"};
        static const char HOS_HARDWARE_PROFILE[] = {"aout:true,display:true"};
        static const char HOS_BOOTLOADER_VERSION[] = {"bootloader"};
        static const char HOS_SECURE_PATCH_LEVEL[] = {"2020-6-5"};
        static const char HOS_ABI_LIST[] = {"****"};
        ```

        For Hi3861 development boards, you need to modify the source files in the  **vendor/hisilicon/hispark\_pegasus/hals/utils/sys\_param**  directory.

        ```
        static const char HOS_PRODUCT_TYPE[] = {"****"};
        static const char HOS_MANUFACTURE[] = {"****"};
        static const char HOS_BRAND[] = {"****"};
        static const char HOS_MARKET_NAME[] = {"****"};
        static const char HOS_PRODUCT_SERIES[] = {"****"};
        static const char HOS_PRODUCT_MODEL[] = {"****"};
        static const char HOS_SOFTWARE_MODEL[] = {"****"};
        static const char HOS_HARDWARE_MODEL[] = {"****"};
        static const char HOS_HARDWARE_PROFILE[] = {"aout:true,display:true"};
        static const char HOS_BOOTLOADER_VERSION[] = {"bootloader"};
        static const char HOS_SECURE_PATCH_LEVEL[] = {"2020-6-5"};
        static const char HOS_ABI_LIST[] = {"****"};
        ```

    -   Obtaining default system attributes

        ```
        const char* value1 = GetProductType();
        printf("Product type =%s\n", value1);
        const char* value2 = GetManufacture();
        printf("Manufacture =%s\n", value2);
        const char* value3 = GetBrand();
        printf("GetBrand =%s\n", value3);
        ```


    -   Obtaining custom system attributes

        ```
        const char* defSysParam = "data of sys param ***...";
        char key[] = "rw.parameter.key";
        char value[] = "OEM-hisi-10.1.0";
        int ret = SetParameter(key, value);
        char valueGet[128] = {0};
        ret = GetParameter(key, defSysParam, valueGet, 128);
        printf("value = %s\n", valueGet);
        ```



## Repositories Involved<a name="section1371113476307"></a>

Startup subsystem

[startup\_init\_lite](https://gitee.com/openharmony/startup_init_lite)

[startup\_syspara\_lite](https://gitee.com/openharmony/startup_syspara_lite)

[startup\_bootstrap\_lite](https://gitee.com/openharmony/startup_bootstrap_lite)

[startup\_appspawn\_lite](https://gitee.com/openharmony/startup_appspawn_lite)

