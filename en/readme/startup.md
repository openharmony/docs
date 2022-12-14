# Startup

## Introduction

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


## Directory Structure

**Table  1**  Directory structure of the source code for the startup subsystem

| Directory                      | Description                                                  | Applicable Platform                                 |
| ------------------------------ | ------------------------------------------------------------ | --------------------------------------------------- |
| base/startup/appspawn_lite     | appspawn module of the Lite edition for spawning application processes. It receives Ability Manager Service (AMS) messages via IPC, parses the messages, starts application processes based on the parsing result, and grants permissions to them. | Platforms using the LiteOS Cortex-A kernel          |
| base/startup/appspawn_standard | appspawn module of the Standard version for spawning application processes. It receives Ability Manager Service (AMS) messages via IPC, parses the messages, starts application processes based on the parsing result, and grants permissions to them. | Platforms using the Linux kernel                    |
| base/startup/bootstrap_lite    | bootstrap module for starting all services except core system services. | Platforms using the LiteOS Cortex-M kernel          |
| base/startup/init         | init module for implementing the init process, which is the first user-space process loaded after the kernel is initialized. Upon startup, the process parses the configuration file in **/etc/init.cfg**. Based on the parsing result, the process then starts other key system processes and grants required permissions to them. | Platforms using the LiteOS Cortex-A or Linux kernel |
| base/startup/syspara_lite      | syspara module that provides APIs to obtain device information, including the product name, brand name, category name, and manufacturer name. | All platforms                                       |




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
├── init                 # init module
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

## Repositories Involved

[Startup subsystem](../device-dev/subsystems/subsys-boot-overview.md)

[startup\_appspawn\_lite](https://gitee.com/openharmony/startup_appspawn_lite)

[startup\_appspawn](https://gitee.com/openharmony/startup_appspawn)

[startup\_bootstrap\_lite](https://gitee.com/openharmony/startup_bootstrap_lite)

[startup_init_lite](https://gitee.com/openharmony/startup_init_lite)

[startup\_syspara\_lite](https://gitee.com/openharmony/startup_syspara_lite)