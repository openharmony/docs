# Compilation and Building

## Compilation Environment Setup

Set up the basic environment by following instructions in [Quick Start Overview](../quick-start/quickstart-overview.md). Both the user space and LiteOS Cortex-A kernel space are compiled using the LLVM compiler. If you choose to port the Linux kernel, run the following command to install the gcc-arm-linux-gnueabi cross compiler for compiling the Linux kernel-space image:


```
sudo apt-get install gcc-arm-linux-gnueabi
```


## Introduction to the Compilation and Building Subsystem

To learn more about the Compilation and Building subsystem, including the compilation and building process, build scripts, and directory structure, see [Compilation and Building Guide](../subsystems/subsys-build-all.md).


## Adding a Chipset Solution

After learning the compilation framework and setting up the compilation environment, perform the following steps to create a chipset solution:

1. Create a category.
   
   The directory structure is as follows: device/{*chipset solution vendor*}/{*development board*}. For example, if you are using the hispark_taurus development board from HiSilicon, create the following directory in the root directory of the code:
   
   
   ```
   mkdir -p device/hisilicon/hispark_taurus
   ```

   The chipset solution directory tree is as follows:

   
   ```
   device                                      
   └── company                         # Chipset solution vendor
       └── board                       # Name of the development board
           ├── BUILD.gn                # Build script
           ├── hals                    # OS device API adaptation
           ├── linux                   # (Optional) Linux kernel version
           │   └── config.gni          # Linux build configuration
           └── liteos_a                # (Optional) LiteOS kernel version
               └── config.gni          # LiteOS_A build configuration
   ```

   For example, if you are porting the Linux kernel to the hispark_taurus development board, the directory tree is as follows:
   
   
   ```
   device                  
   └── hisilicon             
       └── hispark_taurus          
           ├── BUILD.gn    
           ├── hals        
           ├── ......      
           └── linux    
               └── config.gni  
   ```
   
   After the directory tree is created, store the source code related to the development board in the **hispark_taurus** directory.
   
2. Configure the build options of the development board.

   You can configure the build options in the **config.gni** file described in step 1. The compilation and building framework will then compile all OS components in the user space based on your configuration. The **config.gni** file contains the following key fields:


   ```
   kernel_type: Kernel used by the development board, for example, LiteOS_A, LiteOS_M, or Linux.
   kernel_version: Kernel version used by the development board, for example, 4.19.
   board_cpu: CPU of the development board, for example, Cortex-A7 or RISCV32.
   board_arch: Chipset architecture of the development board, for example, armv7-a or rv32imac.
   board_toolchain: Name of the customized build toolchain used by the development board, for example, gcc-arm-none-eabi. If this field is not specified, ohos-clang will be used.
   board_toolchain_prefix: Prefix of the toolchain, for example, gcc-arm-none-eabi.
   board_toolchain_type: Toolchain type. Currently, only GCC and clang are supported.
   board_cflags: Build options of the .c file configured for the development board.
   board_cxx_flags: Build options of the .cpp file configured for the development board.
   board_ld_flags: Linking options configured for the development board.
   ```

     For HiSilicon's hispark_taurus development board, the content in **device/hisilicon/hispark_taurus/config.gni** is as follows:
   
   ```
   # Board CPU type, e.g. "cortex-a7", "riscv32".
   board_cpu = "cortex-a7"
   
   # Name of the toolchain used for system building
   # E.g. gcc-arm-none-eabi, arm-linux-harmonyeabi-gcc, ohos-clang,  riscv32-unknown-elf.
   # Note: The "ohos-clang" toolchain is used by default. You can also customize the toolchain.
   board_toolchain = "mips-linux-gnu-gcc"
   
   # Path where the toolchain is installed, which can be left blank if the installation path has been added to ~/.bashrc.
   board_toolchain_path = 
       rebase_path("//prebuilts/gcc/linux-x86/arm/arm-linux-ohoseabi-gcc/bin",
                   root_build_dir)
   
   # Prefix of the toolchain
   board_toolchain_prefix = "arm-linux-ohoseabi-"
   
   # Type of the compiler, which can be gcc or clang
   board_toolchain_type = "gcc"
   
   # Build options related to the development board
   board_cflags = [
   ]
   board_cxx_flags = [
   ]
   board_ld_flags = []
   
   # Board related headfiles search path.
   board_include_dirs = []
   board_include_dirs += [ rebase_path(
           "//prebuilts/gcc/linux-x86/arm/arm-linux-ohoseabi-gcc/target/usr/include",
           root_build_dir) ]
   
   # Board adapter dir for OHOS components.
   board_adapter_dir = ""
   
   # Sysroot path.
   board_configed_sysroot = ""
   
   # Board storage type, it used for file system generation.
   storage_type = "emmc"
   ```

3. Edit the build script of the development board.

   In the **BUILD.gn** file described in step 1, build code related to the development board, such as code for the on-device driver, on-device interface adaptation (media and graphics), and SDK on the development board.

   For example, edit the **device/hisilicon/hispark_taurus/BUILD.gn** file as follows:

   
   ```
   # It is recommended that the group name be the same as the development board name.
   group("hispark_taurus") {   
     deps = [ "//kernel/linux/patches:linux_kernel" ] # Start kernel compilation.
     deps += [
     ...... # Other compilation units of the development board
     ]
   }
   ```

4. Start building and debugging.

   In the directory of the development board, run the **hb set** and **hb build** commands to start building the chipset solution. The compilation and building framework starts the building with the **BUILD.gn** file in the directory as the entry.