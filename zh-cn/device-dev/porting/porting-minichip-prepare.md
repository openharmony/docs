# 移植准备


由于OpenHarmony工程需要在Linux环境下进行编译，此章节将指导厂商搭建OpenHarmony的编译环境、获取OpenHarmony源码，并且创建厂商工作目录完成厂商芯片的编译框架适配。


## 搭建编译环境

开展移植前请参考[开发环境准备](../quick-start/quickstart-ide-env-win.md)完成环境搭建工作。


## 获取源码


### 获取操作

请参考[获取源码](../get-code/sourcecode-acquire.md)完成源码下载并进行编译。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本文档仅适用于OpenHarmony LTS 3.0.1及之前版本，所以请获取对应版本的源码。


### 目录介绍

OpenHarmony源码重要目录介绍见表1 OpenHarmony重要目录，其中device和vendor目录为芯片厂商和终端模组厂商工作区域（在[搭建编译框架](#搭建编译框架)部分详细介绍）。

  **表1** OpenHarmony重要目录

| 目录 | 用途 | 
| -------- | -------- |
| build | 编译框架所在目录。 | 
| kernel/liteos_m | 内核所在的目录，其中arch目录描述支撑的内核架构。 | 
| device | 芯片厂商适配目录，其中“config.gni”描述当前芯片使用的arch，工具链，编译链接选项等。 | 
| vendor | 终端模组厂商适配目录，其中“config.json”描述需要集成的OpenHarmony子系统列表。 | 
| utils | file，kv等相关的适配。 | 


## 搭建编译框架

厂商开展移植工作时，需要在工程中按照公司名、芯片型号、开发板型号等创建工作目录，并且将所创目录加入到OpenHarmony的编译框架中，使厂商的工作目录能够参与编译，开发者可参照以下步骤进行操作。

1. 新增芯片厂商。
   基于某款芯片进行OpenHarmony的适配，需要在device目录下创建芯片厂商目录，目录内文件描述内核类型，编译工具链，编译链接选项，内核配置选项等。

   创建目录规则：“device/{芯片厂商}/{芯片开发板}”。

     例：“device/MyDeviceCompany/MyBoard”
     
   ```
   device
   ├── hisilicon                                   # hisilicon芯片相关目录，创建目录时可供参考
   ├── MyDeviceCompany                             # MyDeviceCompany 芯片厂商
   │   └── MyBoard                                 # MyBoard 芯片型号
   │          ├── BUILD.gn
   │          ├── liteos_m
   │          │   └── config.gni                   # 芯片工具链，编译链接选项
   │          └── target_config.h                  # 内核配置选项
   └── qemu                                        # qemu相关
   ```

   编译脚本：将“device/MyDeviceCompany/MyBoard”下的文件添加到OpenHarmony编译框架中。

   路径：“device/MyDeviceCompany/MyBoard/BUILD.gn”

     
   ```
   group("MyBoard") {    #将此BUILD.gn文件加入解析
       print("MyDeviceCompany MyBoard is under developing.")
   }
   ```

   开发板编译配置：包括内核类型、工具链类型以及编译参数等内容（详见表2“config.gni”主要配置项）。

   路径：“device/MyDeviceCompany/MyBoard/liteos_m/config.gni”

     
   ```
   # Kernel type, e.g. "linux", "liteos_a", "liteos_m".
   kernel_type = "liteos_m"
    
   # Kernel version.
   kernel_version = ""
    
   # Board CPU type, e.g. "cortex-a7", "riscv32".
   board_cpu = "cortex-m4"
    
   # Board arch, e.g.  "armv7-a", "rv32imac".
   board_arch = ""
    
   # Toolchain name used for system compiling.
   # E.g. gcc-arm-none-eabi, arm-linux-harmonyeabi-gcc, ohos-clang,  riscv32-unknown-elf.
   # Note: The default toolchain is "ohos-clang". It's not mandatory if you use the default toochain.
   board_toolchain = "arm-none-eabi-gcc"
    
   # The toolchain path instatlled, it's not mandatory if you have added toolchian path to your ~/.bashrc.
   board_toolchain_path = ""
    
   # Compiler prefix.
   board_toolchain_prefix = "arm-none-eabi-"
    
   # Compiler type, "gcc" or "clang".
   board_toolchain_type = "gcc"
    
   # Board related common compile flags.
   board_cflags = []
   board_cxx_flags = board_cflags
   board_ld_flags = []
    
   # Board related headfiles search path.
   board_include_dirs = []
    
   # Board adapter dir for OHOS components.
   board_adapter_dir =""
   ```

     **表2** “config.gni”主要配置项
   
   | 配置项 | 介绍 | 
   | -------- | -------- |
   | kernel_type | 开发板使用的内核类型，例如：“liteos_a”,“liteos_m”,“linux”。 | 
   | kernel_version | 开发板使用的内核版本。 | 
   | board_cpu | 开发板CPU类型，例如：“cortex-m4”，“cortex-a7”，“riscv32”。 | 
   | board_arch | 开发芯片arch指令集,&nbsp;例如：“armv7-a”。 | 
   | board_toolchain | 开发板自定义的编译工具链名称，例如：“gcc-arm-none-eabi”。若为空，则使用默认为ohos-clang。 | 
   | board_toolchain_path | 编译工具链路径，为空则默认使用环境变量中的工具链。 | 
   | board_toolchain_prefix | 编译工具链前缀，例如：“arm-none-eabi-”。 | 
   | board_toolchain_type | 编译工具链类型，目前支持gcc和clang。 | 
   | board_cflags | 开发板配置的c文件编译选项。 | 
   | board_cxx_flags | 开发板配置的cpp文件编译选项。 | 
   | board_ld_flags | 开发板配置的链接选项。 | 
   | board_include_dirs | 开发板配置的系统头文件路径列表。 | 
   | board_adapter_dir | 开发板适配文件路径。 | 

1. 新增模组终端厂商。
   基于某款具备OpenHarmony能力的芯片进行模组终端开发，需要在vendor下创建模组厂商目录，目录内容主要是使用的OpenHarmony子系统能力。

   创建目录规则：“vendor/{产品模组厂商}/{产品模组名称}”。

     例：“vendor/MyVendorCompany/MyProduct”
     
   ```
   vendor
   ├── hisilicon                                            # hisilicon 产品相关目录，可供参考。
   └── MyVendorCompany                                      # MyVendorCompany 产品模组厂商。
          └── MyProduct                                     # 具体产品。
                 ├── BUILD.gn
                 └── config.json                            # 产品子系统列表。
   ```

   编译脚本：将“vendor/MyVendorCompany/MyProduct/BUILD.gn”下的文件添加到OpenHarmony编译框架中。

   路径：“vendor/MyVendorCompany/MyProduct/BUILD.gn”

     
   ```
   group("MyProduct") {
       print("MyVendorCompany MyProduct is under developing.")
   }
   ```

   产品配置信息：包括产品名、设备厂商、内核类型以及所添加的子系统列表等信息（详见表3）。

   路径：“vendor/MyVendorCompany/MyProduct/config.json”

     
   ```
   {
       "product_name": "MyProduct",
       "ohos_version": "OpenHarmony 1.0",
       "device_company": "MyDeviceCompany",
       "board": "MyBoard",
       "kernel_type": "liteos_m",
       "kernel_version": "",
       "subsystems": [
         {
           "subsystem": "startup",
           "components": [
             { "component": "bootstrap", "features":[] },
             { "component": "syspara_lite", "features":
               [
                 "enable_ohos_startup_syspara_lite_use_thirdparty_mbedtls = false"
               ]
             }
           ]
         }
       ],
       "vendor_adapter_dir": "",
       "third_party_dir": "",
       "product_adapter_dir": "//vendor/MyVendorCompany/MyProduct/hals",
   }
   ```

     **表3** “config.json”文件配置项
   
   | 配置项 | 介绍 | 
   | -------- | -------- |
   | product_name | 产品名称，hb&nbsp;set时显示产品名称。 | 
   | ohos_version | OpenHarmony版本号，与实际版本保持一致即可。 | 
   | device_company | 芯片厂商名称，与device的二级目录名称一致。 | 
   | board | 开发板名称，与device的三级目录名称一致。 | 
   | kernel_type | 内核类型，应与开发板移植的OpenHarmony系统内核类型匹配。 | 
   | kernel_version | 内核版本号，与config.gni中kernel_version值匹配。 | 
   | subsystem | 产品选择的子系统，应为OS支持的子系统。子系统定义请见build/lite/components目录下的各子系统描述文件。 | 
   | components | 产品选择的某个子系统下的组件，子系统支持的组件详见build/lite/components/{子系统}.json文件。 | 
   | features | 产品配置的某个组件的特性，详见子系统源码目录对应的BUILD.gn文件。 | 
   | vendor_adapter_dir | 适配IOT外设，UtilsFile文件读写能力，一般指向device下目录。使用详见[文件子系统移植实例步骤2。](porting-minichip-subsys-filesystem.md#移植实例) | 
   | third_party_dir | 芯片厂自身三方软件目录，例如mbedtls，lwip等。如果使用OpenHarmony提供的三方软件，可暂时设空，也可参考hispark_pegasus的配置&nbsp;。 | 
   | product_adapter_dir | 适配hal_token以及系统参数，一般指向vendor下目录。使用详见[启动恢复子系统移植实例步骤1。](porting-minichip-subsys-startup.md#移植实例) | 

   > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
   > 1. 编译构建系统会对字段进行有效性检查，其中：
   > 
   > - device_company，board，kernel_type，kernel_version应与芯片厂商配置匹配。
   > 
   > - subsystem，component应与“build/lite/components”下的部件描述匹配。
