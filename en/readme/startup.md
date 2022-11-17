# Startup<a name="EN-US_TOPIC_0000001124561621"></a>

## Introduction<a name="section11660541593"></a>

The startup subsystem is responsible for starting key system processes and services after the kernel is started and before applications are started. The subsystem consists of the following modules:

-   init

    This module can be used on platforms powered by LiteOS Cortex-A or Linux kernel.

    The module starts system service processes from the time the kernel loads the first user-space process to the time the first application is started. In addition to loading key system processes, it needs to configure their permissions during the startup and keep the specified process alive after sub-processes are started. If a key process exits abnormally, the module needs to perform a system restart. For details, see [init Module](../device-dev/subsystems/subsys-boot-init-cfg.md).


-   appspawn

    This module comes with the Lite and Standard editions. The Lite edition can be used on platforms powered by the LiteOS-A kernel, and the Standard edition can be used on platforms powered by the Linux kernel.

    The module spawns application processes upon receiving commands from the application framework, configures permissions for new processes, and calls the entry function of the application framework.

-   bootstrap

    This module can be used on platforms powered by the LiteOS Cortex-M kernel. 

    The module provides entry identifiers for starting services and features. When SAMGR is started, the entry function identified by **bootstrap** is invoked and system services are started.

-   syspara

    This module obtains and sets system attributes.

    The module can be used on all platforms. Supported system attributes consist of default, OEM-specified, and custom system attributes. OEM-specified system attributes provide only default values. The specific values need to be adjusted as required. For details, see [syspara Module](../device-dev/subsystems/subsys-boot-init-sysparam.md).


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
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>appspawn module of the Lite edition for spawning application processes. It receives Ability Manager Service (AMS) messages via IPC, parses the messages, starts application processes based on the parsing result, and grants permissions to them.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 ">Platforms using the LiteOS Cortex-A kernel
</td>
</tr>
<tr id="row17977171010144"><td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>base/startup/appspawn_standard</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>appspawn module of the Standard version for spawning application processes. It receives Ability Manager Service (AMS) messages via IPC, parses the messages, starts application processes based on the parsing result, and grants permissions to them.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 ">Platforms using the Linux kernel
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p37931659101311"><a name="p37931659101311"></a><a name="p37931659101311"></a>base/startup/bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p6793059171318"><a name="p6793059171318"></a><a name="p6793059171318"></a>bootstrap module for starting all services except core system services.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 ">Platforms using the LiteOS Cortex-M kernel
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" align="left" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p117935599130"><a name="p117935599130"></a><a name="p117935599130"></a>base/startup/init_lite</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p0793185971316"><a name="p0793185971316"></a><a name="p0793185971316"></a>init_lite module for implementing the init process, which is the first user-space process loaded after the kernel is initialized. Upon startup, the process parses the configuration file in **/etc/init.cfg**. Based on the parsing result, the process then starts other key system processes and grants required permissions to them.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 ">Platforms using the LiteOS Cortex-A or Linux kernel</td>
</tr>
<tr id="row1897841071415"><td class="cellrowborder" valign="top" width="20.880000000000003%" headers="mcps1.2.4.1.1 "><p id="p469782418557"><a name="p469782418557"></a><a name="p469782418557"></a>base/startup/syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="65.2%" headers="mcps1.2.4.1.2 "><p id="p15697102412558"><a name="p15697102412558"></a><a name="p15697102412558"></a>syspara module that provides APIs to obtain device information, including the product name, brand name, category name, and manufacturer name.</p>
</td>
<td class="cellrowborder" valign="top" width="13.919999999999998%" headers="mcps1.2.4.1.3 ">All platforms</td>
</tr>
</tbody>
</table>


```
base/startup/
├── appspawn_standard         # appspawn module for the standard system
│   ├── include               # Header files
│   ├── parameter             # System parameters
│   ├── src                   # Source files 
│   └── test                  # Test cases 
├── appspawn_lite             # appspawn module for the mini system
│   └── services
│       ├── include           # Header files 
│       ├── src              # Source files 
│       └── test              # Test cases
├── bootstrap_lite           # bootstrap module
│   └── services
│       └── source            # Source files 
├── init_lite                 # init module
│   ├── initsync              # Source files
│   ├── interfaces            # External APIs
│   └── services
│       ├── include           # Header files 
│       ├── src               # Source files 
│       └── test              # Test cases
└── syspara_lite              # syspara module
    ├── adapter               # Adaptation code
    ├── frameworks            # Source files
    ├── hals                  # Header files for the hardware abstraction layer (HAL)
    ├── interfaces            # External APIs
    └── simulator             # Simulator adaptation
```

## Repositories Involved<a name="section1371113476307"></a>

[Startup subsystem](../device-dev/subsystems/subsys-boot-overview.md)

[startup\_appspawn\_lite](https://gitee.com/openharmony/startup_appspawn_lite)

[startup\_appspawn](https://gitee.com/openharmony/startup_appspawn)

[startup\_bootstrap\_lite](https://gitee.com/openharmony/startup_bootstrap_lite)

[startup_init_lite](https://gitee.com/openharmony/startup_init_lite)

[startup\_syspara\_lite](https://gitee.com/openharmony/startup_syspara_lite)
