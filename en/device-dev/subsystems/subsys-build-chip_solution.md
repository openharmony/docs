# Chipset Solution
### Configuration Rules

- The chipset solution is a special component. It is built based on a development board, including the drivers, device API adaptation, and SDK.
- The source code path is named in the **device/{Development_board}/{Chipset_solution_vendor}** format.
- The chipset solution component is built by default based on the development board selected.

The chipset solution directory structure is as follows:

```shell
  device                                      
  └── board                                   
      └── company                           # Chipset solution vendor
           └──  hispark_aries               # Development board name
                 ├── BUILD.gn               # Build script
                 ├── hals                   # OS device API adaptation
                 ├── linux                  # (Optional) Linux kernel version
                 │   └── config.gni         # Linux build configuration
                 └── liteos_a               # (Optional) LiteOS kernel version
                     └── config.gni         # LiteOS_A build configuration
```

**CAUTION**<br>The **config.gni** file contains the configuration related to the build of the development board. The parameters in this file are used to compile all OS components and are globally visible during the build process.

- The **config.gni** file contains the following key parameters:

```shell
  kernel_type:            Kernel used by the development board, for example, LiteOS_A, LiteOS_M, or Linux.
  kernel_version:         Kernel version of the development board, for example, 4.19.
  board_cpu:              CPU of the development board, for example, Cortex-A7 or RISCV32.
  board_arch:             Chipset architecture of the development board, for example, ARMv7-A or RV32IMAC.
  board_toolchain:        Name of the customized build toolchain used by the development board, for example, gcc-arm-none-eabi. If this field is not specified, ohos-clang will be used.
  board_toolchain_prefix: Prefix of the toolchain, for example, gcc-arm-none-eabi.
  board_toolchain_type:   Toolchain type. Currently, only GCC and clang are supported.
  board_cflags:           Build options of the .c file configured for the development board.
  board_cxx_flags:        Build options of the .cpp file configured for the development board.
  board_ld_flags:         Linking options configured for the development board.
```

###  Adding and Building a Chipset Solution

The following uses the RTL8720 development board provided by Realtek as an example. The procedure is as follows:

1. Create a directory for the chipset solution.

   Run the following command in the root code directory:

   ```shell
   mkdir -p device/board/realtek/rtl8720
   ```

   

2. Create a directory for kernel adaptation and configure the **config.gni** file of the development board.

   For example, to adapt the LiteOS-A kernel to the RTL8720 development board, configure the **device/board/realtek/rtl8720/liteos_a/config.gni** file as follows:

   ```shell
   # Kernel type, e.g. "linux", "liteos_a", "liteos_m".
   kernel_type = "liteos_a"
   
   # Kernel version.
   kernel_version = "3.0.0"
   
   # Board CPU type, e.g. "cortex-a7", "riscv32".
   board_cpu = "real-m300"
   
   # Board arch, e.g. "armv7-a", "rv32imac".
   board_arch = ""
   
   # Toolchain name used for system compiling.
   # E.g. gcc-arm-none-eabi, arm-linux-harmonyeabi-gcc, ohos-clang, riscv32-unknown-elf.
   # Note: The default toolchain is "ohos-clang". It's not mandatory if you use the default toochain.
   board_toolchain = "gcc-arm-none-eabi"
   
   # The toolchain path instatlled, it's not mandatory if you have added toolchain path to your ~/.bashrc.
   board_toolchain_path =
       rebase_path("//prebuilts/gcc/linux-x86/arm/gcc-arm-none-eabi/bin",
                   root_build_dir)
   
   # Compiler prefix.
   board_toolchain_prefix = "gcc-arm-none-eabi-"
   
   # Compiler type, "gcc" or "clang".
   board_toolchain_type = "gcc"
   
   # Board related common compile flags.
   board_cflags = []
   board_cxx_flags = []
   board_ld_flags = []
   ```

3. Write the build script.

   Create the **BUILD.gn** file in the development board directory. The target name must be the same as that of the development board. The following is an example of the **device/board/realtek/rtl8720/BUILD.gn** file for the RTL8720 development board:

   ```shell
   group("rtl8720") { # The build target can be shared_library, static_library, or an executable file.
     # Content
     ...
   }
   ```

4. Build the chipset solution.

   Run the **hb build** command in the development board directory to start the build.

