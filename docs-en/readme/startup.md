# Startup<a name="EN-US_TOPIC_0000001051344323"></a>

## Introduction<a name="section11660541593"></a>

The startup subsystem is responsible for starting key system processes and services after the kernel is started and before applications are started. This subsystem has the following modules:

-   **init**  for starting system service processes

This module can be used on the Hi3516DV300 and Hi3518EV300 platforms powered by LiteOS Cortex-A.

It starts system service processes from the time the kernel loads the first user-space process to the time the first application program is started. In addition to loading key system processes, the startup subsystem needs to configure required permissions during the startup, and keeps the specified process alive after sub-processes are started. If a process exits abnormally, the startup subsystem needs to restart it, and to perform system reset for a special process.

-   **appspawn**  for spawning applications

    This module can be used on the Hi3516DV300 and Hi3518EV300 platforms powered by LiteOS Cortex-A.

    It spawns application processes upon receiving commands from the application framework, configures required permissions, and invokes the entry of the application framework.

-   **bootstrap**  for starting service modules

    This module can be used on the Hi3861 platform powered by LiteOS Cortex-M.

    It provides identifiers for starting services and functions. When the SAMGR is started, the entry function identified by  **boostrap**  is invoked and system services are started.

-   **Syspara**

    This module can be used on the Hi3861, Hi3516DV300 and Hi3518EV300 platforms powered by LiteOS Cortex-M and LiteOS Cortex-A.

    It obtains and sets system attributes for the operating system.

    System attributes consist of default, OEM-specified, and custom system attributes. OEM-specified system attributes provide only default values. The specific values need to be adjusted as required. For details, see  [Usage](#section674513182447).


## Directory Structure<a name="section1464106163817"></a>

**Table  1**  Directory structure of the source code for the Startup subsystem

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="19.439999999999998%" id="mcps1.2.4.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="66.64%" id="mcps1.2.4.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="13.919999999999998%" id="mcps1.2.4.1.3"><p id="p101617019356"><a name="p101617019356"></a><a name="p101617019356"></a>Applicable Platform</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>base/startup/services/appspawn_lite</p>
</td>
<td class="cellrowborder" valign="top" width="66.64%" headers="mcps1.2.4.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a><strong id="b1374115724515"><a name="b1374115724515"></a><a name="b1374115724515"></a>appspawn</strong> module for spawning application processes. It receives AMS messages via lightweight IPC, parses the messages, starts application processes based on the parsing result, and grants permissions to them.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p63463619360"><a name="p63463619360"></a><a name="p63463619360"></a>Hi3516DV300</p>
<p id="p141611802359"><a name="p141611802359"></a><a name="p141611802359"></a>Hi3518EV300</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="p37931659101311"><a name="p37931659101311"></a><a name="p37931659101311"></a>base/startup/services/bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="66.64%" headers="mcps1.2.4.1.2 "><p id="p6793059171318"><a name="p6793059171318"></a><a name="p6793059171318"></a><strong id="b32551533153211"><a name="b32551533153211"></a><a name="b32551533153211"></a>bootstrap</strong> module for starting all services except core system services.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p101610019353"><a name="p101610019353"></a><a name="p101610019353"></a>Hi3861</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" align="left" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="p117935599130"><a name="p117935599130"></a><a name="p117935599130"></a>base/startup/services/init_lite</p>
</td>
<td class="cellrowborder" valign="top" width="66.64%" headers="mcps1.2.4.1.2 "><p id="p0793185971316"><a name="p0793185971316"></a><a name="p0793185971316"></a><strong id="b119834684710"><a name="b119834684710"></a><a name="b119834684710"></a>init</strong> module for the <strong id="b520684694710"><a name="b520684694710"></a><a name="b520684694710"></a>init</strong> process, which is the first user-space process loaded after the kernel is initialized. After the startup, the configuration file in <strong id="b8209124694718"><a name="b8209124694718"></a><a name="b8209124694718"></a>/etc/init.cfg</strong> is parsed. Based on the parsing result, other key system processes are started and granted required permissions.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p2176757193619"><a name="p2176757193619"></a><a name="p2176757193619"></a>Hi3516DV300</p>
<p id="p51611013358"><a name="p51611013358"></a><a name="p51611013358"></a>Hi3518EV300</p>
</td>
</tr>
<tr id="row1897841071415"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="p16793185961315"><a name="p16793185961315"></a><a name="p16793185961315"></a>base/startup/interfaces</p>
</td>
<td class="cellrowborder" valign="top" width="66.64%" headers="mcps1.2.4.1.2 "><p id="p20413161014013"><a name="p20413161014013"></a><a name="p20413161014013"></a>Open APIs provided by the <strong id="b9164175455011"><a name="b9164175455011"></a><a name="b9164175455011"></a>bootstrap</strong> module. The <strong id="b16929323105113"><a name="b16929323105113"></a><a name="b16929323105113"></a>main</strong> function directs the calls to these APIs to start the service framework.</p>
</td>
<td class="cellrowborder" rowspan="2" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 "><p id="p1956516512380"><a name="p1956516512380"></a><a name="p1956516512380"></a>Hi3861</p>
<p id="p2670195353812"><a name="p2670195353812"></a><a name="p2670195353812"></a>Hi3516DV300</p>
<p id="p116118053518"><a name="p116118053518"></a><a name="p116118053518"></a>Hi3518EV300</p>
</td>
</tr>
<tr id="row178841725886"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p88841825887"><a name="p88841825887"></a><a name="p88841825887"></a>base/startup/frameworks/syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p98851625589"><a name="p98851625589"></a><a name="p98851625589"></a><strong id="b112535588525"><a name="b112535588525"></a><a name="b112535588525"></a>syspara</strong> module. It provides APIs to obtain device information, including the product name, brand name, category name, and manufacturer name.</p>
</td>
</tr>
</tbody>
</table>

```
base
├──startup    Root directory of the startup subsystem
├──── frameworks
│     └── syspara_lite
│         ├── LICENSE     License file for open-source code
│         ├── parameter   Source files for the syspara module
│         │   ├── BUILD.gn
│         │   └── src
│         │       ├── BUILD.gn
│         │       ├── param_impl_hal     syspara module implemented based on LiteOS Cortex-M
│         │       └── param_impl_posix   syspara module implemented based on LiteOS Cortex-A
│         └── token
│             ├── BUILD.gn
│             └── src
│                 ├── token_impl_hal
│                 └── token_impl_posix
├──── hals         
│     └── syspara_lite       Header files at the hardware abstraction layer of the syspara module
├──── interfaces
│     └── kits
│         └── syspara_lite   Open APIs related to the syspara module
└──── services
      ├── appspawn_lite    appspawn module
      │   ├── BUILD.gn    Compilation and configuration of the appspawn module
      │   ├── include     Header files for the appspawn module
      │   ├── LICENSE     License file for open-source code
      │   ├── moduletest  Self-testing code for the appspawn module
      │   └── src         Source files for the appspawn module
      ├── bootstrap_lite   bootstrap module
      │   ├── BUILD.gn    Compilation and configuration of the bootstrap module
      │   ├── LICENSE     License file for open-source code
      │   └── source      Source files for the bootstrap module
      └── init_lite       init module
           ├── BUILD.gn    Compilation and configuration of the init module
          ├── include     Header files for the init module
          ├── LICENSE     License file for open-source code
          ├── moduletest  Self-testing code for the init module
          └── src         Sources for the init module
vendor
└──huawei
        └──camera
                └──init_configs  Configuration file of the init module (in JSON format, in the /etc/ directory)
```

## Constraints<a name="section1718733212019"></a>

-   The startup subsystem is developed using the C language.
-   OEM-specified system attributes provide only default values. The specific values need to be adjusted as required.

## Usage<a name="section674513182447"></a>

-   Configuration file of the init module

The configuration file  **init.cfg**  of the  **init**  module contains service names, executable file paths, permissions, and other attributes of all key system services that need to be started by the init process. The file is stored in  **/vendor/huawei/camera/init\_configs/**  under  **/etc/**. It is in JSON format, and its size cannot exceed 100 KB.

After the init process starts, it reads the  **/etc/init.cfg**  file, parses the JSON content, and loads system services in sequence based on the parsing result. The format and content of the configuration file are described as follows:

```
{
    "jobs" : [{
            "name" : "pre-init",      -------- Job executed before the initialization. It can be used to store some pre-operations (for example, creating a folder) before the init process is started.
            "cmds" : [
                 "mkdir /testdir",      -------- Command for creating a folder. mkdir and the target folder must be separated by only one space.
                "chmod 0700 /testdir", -------- Command for modifying the permission, which must be in the 0xxxx format. chmod, permission, and the target folder must be separated by only one space.
                "chown 99 99 /testdir",-------- Command for modifying the owner group. chown, UID, GID, and the target folder must be separated by only one space.
                "mkdir /testdir2",
                "mount vfat /dev/mmcblk0p0 /testdir2 noexec nosuid" -------- mount command in the following format: mount file system type source target flags data
                                                                    -------- flags currently supports only nodev, noexec, nosuid, and rdonly, which are separated by a space.
            ]
        }, {
            "name" : "init",          -------- Job name supported by the init process. Ensure that an extended job name contains a maximum of 32 bytes.
            "cmds" : [                -------- Command set supported by the current job. Only one space is allowed between the command name (less than 10 bytes) and the following parameter (less than 32 bytes).
                "start service1",     -------- First command of the current job
                "start service2"      -------- Second command of the current job (You can adjust the sequence of commands in the array as required. The init process executes the commands in the same order as they are parsed.)
             ]
        }, {
             "name" : "post-init",    -------- Job executed after the initialization. It can be used to store some operations performed after the init process is started.
             "cmds" : []
        }
    ],
    "services" : [{                         -------- service set (in an array), including all system services that need to be started by the init process
            "name" : "service1",            -------- Name of the current service. A maximum of 32 bytes must be specified for the name.
            "path" : "/bin/process1"        -------- Full path of the executable file of the current service. A maximum of 64 bytes must be specified for the path.
            "uid" : 1,                      -------- UID of the current service process
            "gid" : 1,                      -------- GID of the current service process
            "once" : 0,                     -------- Whether the current service process is a one-off process
                                                     0 --- The current service process is not a one-off process. If the process exits due to any reason, the init module restarts the service process upon receiving the SIGCHLD signal.
                                                   non-0 --- The current service is a one-off process. If the process exits due to any reason, the init module does not restart the service process.
            "importance" : 1,               -------- Whether the current service is a key system process
                                                     0 --- The current service is not a key system process. If the process exits due to any reason, the init module does not reset the system.
                                                   non-0 --- The current service is a key system process. If the process exits due to any reason, the init module resets and restarts the system upon receiving the SIGCHLD signal.
            "caps" : [0, 1, 2, 5]           -------- Capabilities required by the current service. They are evaluated based on the capabilities supported by the security subsystem and configured in accordance with the principle of least permission.
    }, {
            "name" : "service2",            -------- Next service that needs to be started by the init module. The service sequence is irrelevant to the startup sequence, which is determined by the cmd sequence in the previous job.
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
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p9607551369"><a name="p9607551369"></a><a name="p9607551369"></a>start ServiceName</p>
<p id="p862384484010"><a name="p862384484010"></a><a name="p862384484010"></a>Only one space is allowed.</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p17872104184113"><a name="p17872104184113"></a><a name="p17872104184113"></a>Starts a service. The service name must be the same as that in the <strong id="b21331241401"><a name="b21331241401"></a><a name="b21331241401"></a>services</strong> array in the file.</p>
</td>
</tr>
<tr id="row962311443404"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p13837142094117"><a name="p13837142094117"></a><a name="p13837142094117"></a>mkdir</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p637613010714"><a name="p637613010714"></a><a name="p637613010714"></a>mkdir  /xxxx/xxx</p>
<p id="p2624244204019"><a name="p2624244204019"></a><a name="p2624244204019"></a>Only one space is allowed.</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p158722484112"><a name="p158722484112"></a><a name="p158722484112"></a>Creates a directory.</p>
</td>
</tr>
<tr id="row662404414406"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p3624444154011"><a name="p3624444154011"></a><a name="p3624444154011"></a>chmod</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p68331741271"><a name="p68331741271"></a><a name="p68331741271"></a>chmod 0xxx /xxx/xx</p>
<p id="p7624344134020"><a name="p7624344134020"></a><a name="p7624344134020"></a>Only one space is allowed.</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p18872945418"><a name="p18872945418"></a><a name="p18872945418"></a>Changes the permission. The permission value must be in 0xxx format, for example, 0755 and 0600. This configuration must comply with the principle of least permission.</p>
</td>
</tr>
<tr id="row1462404494017"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p136241144144013"><a name="p136241144144013"></a><a name="p136241144144013"></a>chown</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p84976100714"><a name="p84976100714"></a><a name="p84976100714"></a>chown uid gid /xxx/xx</p>
<p id="p1624144194011"><a name="p1624144194011"></a><a name="p1624144194011"></a>Only one space is allowed.</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p9872246417"><a name="p9872246417"></a><a name="p9872246417"></a>Changes the owner group.</p>
</td>
</tr>
<tr id="row1285512468412"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.4.1.1 "><p id="p1385515468413"><a name="p1385515468413"></a><a name="p1385515468413"></a>mount</p>
</td>
<td class="cellrowborder" valign="top" width="31.05%" headers="mcps1.2.4.1.2 "><p id="p358535124815"><a name="p358535124815"></a><a name="p358535124815"></a>mount fileSysType source target flags data</p>
<p id="p178550463412"><a name="p178550463412"></a><a name="p178550463412"></a>Only one space is allowed.</p>
</td>
<td class="cellrowborder" valign="top" width="56.45%" headers="mcps1.2.4.1.3 "><p id="p1085544611415"><a name="p1085544611415"></a><a name="p1085544611415"></a>Mounts data. Currently, <strong id="b214336135420"><a name="b214336135420"></a><a name="b214336135420"></a>flags</strong> supports only <strong id="b13170651175311"><a name="b13170651175311"></a><a name="b13170651175311"></a>nodev</strong>, <strong id="b35185045310"><a name="b35185045310"></a><a name="b35185045310"></a>noexec</strong>, <strong id="b1364174916535"><a name="b1364174916535"></a><a name="b1364174916535"></a>nosuid</strong>, and <strong id="b157458477538"><a name="b157458477538"></a><a name="b157458477538"></a>rdonly</strong>, and other strings are considered as <strong id="b7280142315510"><a name="b7280142315510"></a><a name="b7280142315510"></a>data</strong>.</p>
</td>
</tr>
</tbody>
</table>

It is worth noting that the modified  **init.cfg**  file must be in JSON format. Otherwise, the init process fails to parse the file, and no service will be started. The configured service permission  **uid/gid/capability**  must meet the requirements imposed by the security subsystem and comply with the principle of least permission. In addition, if the values of  **once**  and  **importance**  of a service are both  **0**  and the service exits for more than four consecutive times within four minutes, the init process will stop restarting the service.

-   System parameters

    -   OEM-specific system attributes

    For Hi3516DV300 and Hi3518EV300 development boards, you need to modify the source files in the  **vendor/huawei/camera/hals/utils/sys\_param**  directory.

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

    For Hi3861 development boards, you need to modify the source files in the  **vendor/huawei/wifi-iot/hals/utils/sys\_param**  directory.

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
    char* value1 = GetProductType();
    printf("Product type =%s\n", value1);
    free(value1);
    char* value2 = GetManufacture();
    printf("Manufacture =%s\n", value2);
    free(value2);
    char* value3 = GetBrand();
    printf("GetBrand =%s\n", value3);
    free(value3);
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


## Repositories Involved<a name="section641143415335"></a>

startup\_frameworks\_syspara\_lite

startup\_hals\_syspara\_lite

startup\_interfaces\_kits\_syspara\_lite

startup\_appspawn\_lite

startup\_services\_bootstrap\_lite

startup\_init\_lite

