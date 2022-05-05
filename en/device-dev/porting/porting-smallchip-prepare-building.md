# Compilation and Building<a name="EN-US_TOPIC_0000001154212512"></a>

## Compilation Environment Setup<a name="section3336103410314"></a>

Set up the basic environment by following instructions in  [Ubuntu Build Environment](../quick-start/quickstart-lite-steps-hi3861-setting.md). Both the user space and LiteOS Cortex-A kernel space are compiled using the LLVM compiler. If you choose to port the Linux kernel, run the following command to install the gcc-arm-linux-gnueabi cross compiler for compiling the Linux kernel-space image:

```
sudo apt-get install gcc-arm-linux-gnueabi
```

## Introduction to the Compilation and Building Subsystem<a name="section354343816319"></a>

To learn more about the compilation and building subsystem, including the compilation and building process, compilation scripts, and building chipset source code or single components, see  [Compilation and Building](../subsystems/subsys-build-mini-lite.md).

## Adding a Chipset Solution<a name="section18612153175011"></a>

After learning the compilation framework and setting up the compilation environment, perform the following steps to create a chipset solution:

1.  <a name="li20894101862"></a>Create a category.

    The directory structure is as follows: device/\{_chipset solution vendor_\}/\{_development board_\}. For example, if you are using the hispark\_taurus development board from HiSilicon, create the following directory in the root directory of the code:

    ```
    mkdir -p device/hisilicon/hispark_taurus
    ```

    The chipset solution directory tree is as follows:

    ```
    device                                      
    └── company                         # Chipset solution vendor
        └── board                       # Name of the development board
            ├── BUILD.gn                # Build script
            ├── hals                    # Southbound APIs for OS adaptation
            ├── linux                   # Linux kernel version (optional)
            │   └── config.gni          # Build options for the Linux version
            └── liteos_a                # LiteOS kernel version (optional)
                └── config.gni          # Build options for the LiteOS Cortex-A version
    ```

    For example, if you are porting the Linux kernel to the hispark\_taurus development board, the directory tree is as follows:

    ```
    device                  
    └── hisilicon             
        └── hispark_tautus          
            ├── BUILD.gn    
            ├── hals        
            ├── ......      
            └── linux    
                └── config.gni  
    ```

    After the directory tree is created, store the source code related to the development board in the  **hispark\_taurus**  directory.

2.  Configure the build options of the development board.

    You can configure the build options in the  **config.gni**  file described in  [1](#li20894101862). The compilation and building framework will then compile all OS components in the user space based on your configuration. The  **config.gni**  file contains the following key fields:

    ```
    kernel_type:            kernel used by the development board, for example, liteos_a, liteos_m, or linux.
    kernel_version:         kernel version used by the development board, for example, 4.19.
    board_cpu:              CPU of the development board, for example, cortex-a7 or riscv32.
    board_arch:             chipset architecture of the development board, for example, armv7-a or rv32imac.
    board_toolchain:        name of the customized compiler used by the development board, for example, gcc-arm-none-eabi. If this field is not specified, ohos-clang will be used by default.
    board_toolchain_prefix: prefix of the compiler, for example, gcc-arm-none-eabi.
    board_toolchain_type:  compiler type, for example, gcc or clang. Currently, only GCC and clang are supported.
    board_cflags:          build options of the .c file configured for the development board.
    board_cxx_flags:       build options of the .cpp file configured for the development board.
    board_ld_flags:        link options configured for the development board.
    ```

    For HiSilicon's hispark\_taurus development board, the content in  **device/hisilicon/hispark\_taurus/config.gni**  is as follows:

    ```
    # Board CPU type, e.g. "cortex-a7", "riscv32".
    board_cpu = "cortex-a7"
    
    # Name of the compiler that is used for system building
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
    
    # Building flags related to the board
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

3.  Edit the build script of the development board.

    In the  **BUILD.gn**  file described in step  [1](#li20894101862), build code related to the development board, such as code for the on-device driver, on-device interface adaptation \(media and graphics\), and SDK on the development board.

    For example, edit the  **device/hisilicon/hispark\_taurus/BUILD.gn**  file as follows:

    ```
    # It is recommended that the group name be the same as the development board name.
    group("hispark_taurus") {   
      deps = [ "//kernel/linux/patches:linux_kernel" ] # Start kernel compilation.
      deps += [
      ...... # Other compilation units of the development board
      ]
    }
    ```

4.  Start building and debugging.

    In the directory of the development board, run the  **hb set**  and  **hb build**  commands to start building the chipset solution. The compilation framework starts the building with the  **BUILD.gn**  file in the directory as the entry.


