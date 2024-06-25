# Porting Preparation


The OpenHarmony project must be built in the Linux environment. This topic describes how to set up the build environment, obtain the OpenHarmony source code, and create a vendor working directory to adapt the compilation framework of the vendor chip.


## Setting Up the Build Environment

Before porting, set up the build environment as instructed in [Setting Up the Windows Environment](../quick-start/quickstart-ide-env-win.md).


## Obtaining Source Code


### Procedure

Download and compile the source code by following instructions in [Obtaining Source Code](https://gitee.com/openharmony/docs/blob/master/en/device-dev/get-code/sourcecode-acquire.md).

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> This document applies only to OpenHarmony LTS 3.0.1 and earlier versions. Make sure you obtain the source code for one of these versions.


### Directory Structure

Table 1 describes the main directories of the OpenHarmony source code. The **device** and **vendor** directories are the working areas of chip and device module vendors. For details, see [Setting Up the Compilation Framework](#setting-up-the-compilation-framework).

**Table 1** Main directories of OpenHarmony source code

| Directory| Description|
| -------- | -------- |
| build | Directory where the compilation framework is located.|
| kernel/liteos_m | Directory where the kernel is located. The **arch** directory describes the supported kernel architecture.|
| device | Directory for adaptation by the chip vendor, where the **config.gni** file describes the architecture, toolchain, and linking options used by the current chip.|
| vendor | Directory for adaptation by the device module vendor, where the **config.json** file describes the list of OpenHarmony subsystems to be integrated.|
| utils | Adaptation related to files and KVs.|


## Setting Up the Compilation Framework

During porting, the vendor must create a working directory in the project based on your company name, chip model, and development board model, and add the created directory to the OpenHarmony compilation framework so that the working directory can participate in compilation. You can perform the following steps:

1. Add the chip vendor.
   
   To adapt to OpenHarmony based on a chip, create a chip vendor directory in the **device** directory. The files in the directory describe the kernel type, compiler toolchain, linking options, and kernel configuration options.
   
   Directory format: device/{*Chip vendor*}/{*Chip development board*}
   
   Example: **device/MyDeviceCompany/MyBoard**
   
   ```
   device
   ├── hisilicon                                   # HiSilicon chip-related directory, which can be used as a reference during directory creation.
   ├── MyDeviceCompany                             # Chip vendor
   │   └── MyBoard                                 # Chip model
   │          ├── BUILD.gn
   │          ├── liteos_m
   │          │   └── config.gni                   # Chip toolchain and compilation linking options
   │          └── target_config.h                  # Kernel configuration options
   └── qemu                                        # QEMU-related
   ```
   
   Build script: Add the files in **device/MyDeviceCompany/MyBoard** to the OpenHarmony compilation framework.
   
   Path: **device/MyDeviceCompany/MyBoard/BUILD.gn**
   
   
   ```
   group("MyBoard") {    # Add the BUILD.gn file for parsing.
       print("MyDeviceCompany MyBoard is under developing.")
   }
   ```
   
   Compilation configuration of the development board: This includes the kernel type, toolchain type, and compilation parameters. For details, see Table 2.
   
   Path: **device/MyDeviceCompany/MyBoard/liteos_m/config.gni**
   
   
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
   
   **Table 2** Main configuration items in config.gni
   
   | Configuration Item| Description|
   | -------- | -------- |
   | kernel_type | Kernel type of the development board, for example, **"liteos_a"**, **"liteos_m"**, or **"linux"**.|
   | kernel_version | Kernel version of the development board.|
   | board_cpu | CPU type of the development board, for example, **"cortex-m4"**, **"cortex-a7"**, or **"riscv32"**.|
   | board_arch | Architecture instruction set of the development board, for example, **"armv7-a"**.|
   | board_toolchain | Name of the customized compiler toolchain used by the development board, for example, **"gcc-arm-none-eabi"**. If this parameter is not specified, **ohos-clang** will be used by default.|
   | board_toolchain_path | Path of the compiler toolchain. If this parameter is left empty, the toolchain in the environment variable is used.|
   | board_toolchain_prefix | Prefix of the compiler toolchain, for example, **"arm-none-eabi-"**.|
   | board_toolchain_type | Type of the compiler toolchain, which can be **gcc** or **clang**.|
   | board_cflags | Build options of the .c file configured for the development board.|
   | board_cxx_flags | Build options of the .cpp file configured for the development board.|
   | board_ld_flags | Linking options configured for the development board.|
   | board_include_dirs | List of system header files configured on the development board.|
   | board_adapter_dir | Adaptation files of the development board.|
   
2. Add the device module vendor.
   
   To develop a device module based on a chip with the OpenHarmony capability, create a module vendor directory under **vendor** and configure the OpenHarmony subsystem capabilities.
   
   Directory format: vendor/{Product module vendor}/{Product module name}.
   
   Example: **vendor/MyVendorCompany/MyProduct**
   
   ```
   vendor
   ├── hisilicon                                            # HiSilicon chip-related directory, which can be used as a reference during directory creation.
   └── MyVendorCompany                                      # Module vendor
          └── MyProduct                                     # Product
                 ├── BUILD.gn
                 └── config.json                            # Product subsystem list
   ```
   
   Build script: Add the files in **vendor/MyVendorCompany/MyProduct/BUILD.gn** to the OpenHarmony compilation framework.
   
   Path: **vendor/MyVendorCompany/MyProduct/BUILD.gn**
   
   
   ```
   group("MyProduct") {
       print("MyVendorCompany MyProduct is under developing.")
   }
   ```
   
   Product configuration information: Add the product name, device vendor, kernel type, and subsystem list. For details, see Table 3.
   
   Path: **vendor/MyVendorCompany/MyProduct/config.json**
   
   
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
   
   **Table 3** Configuration items in the config.json file
   
   | Configuration Item| Description|
   | -------- | -------- |
   | product_name | Product name, which is displayed during **hb set**.|
   | ohos_version | OpenHarmony version number, which must be the same as the actual version number.|
   | device_company | Chip vendor name, which is the same as the level-2 directory name under **device**.|
   | board | Name of the development board, which is the same as the level-3 directory name under **device**.|
   | kernel_type | Kernel type, which must match the kernel type of the OpenHarmony system ported to the development board.|
   | kernel_version | Kernel version number, which matches the value of **kernel_version** in **config.gni**.|
   | subsystem | Subsystem, which must be one supported by the OS. For details about the subsystem definition, see the description file of each subsystem in **build/lite/components**.|
   | components | Components of the subsystem. For details about the components supported by a specific subsystem, see the **build/lite/components/{*Subsystem*}.json** file.|
   | features | Features of the component configured for the product. For details, see the **BUILD.gn** file corresponding to the subsystem source code directory.|
   | vendor_adapter_dir | Directory used for adaptation to IoT peripherals and UtilsFile file read and write capabilities. Generally, the value points to a directory under **device**. For details, see Step 2 in [Porting the File Subsystem](porting-minichip-subsys-filesystem.md#example).|
   | third_party_dir | Third-party software directory of the chip vendor, such as **mbedtls** and **lwip**. If the third-party software provided by OpenHarmony is used, leave this parameter empty or refer to the configuration for **hispark_pegasus**.|
   | product_adapter_dir | Directory used for adaptation to hal_token and system parameters. Generally, the value points to a directory under **vendor**. For details, see Step 1 in [Porting the Startup Subsystem](porting-minichip-subsys-startup.md#example).|
   
   > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
   >
   > The compilation and build system checks the validity of fields.
   >
   > - The values of **device_company**, **board**, **kernel_type**, and **kernel_version** must match those configured by the chip vendor.
   >
   > - The values of **subsystem** and **component** must match the component description under **build/lite/components**.
