# Building Adaptation Process


For details about compilation and building, see [Compilation and Building Guide](../subsystems/subsys-build-all.md). When adding third-party chips, perform the following steps to complete building adaptation:


## Building Adaptation Process

You need to create a directory for the development board. For example, for the RTL8720 development board from SoC provider Realtek, the **device/realtek/rtl8720** directory must be created. To complete the building adaptation, perform the following steps:

1. Configure the toolchain and building options.
   
   The **ohos-clang** toolchain is used by default. SoC providers can also customize the configuration based on their development boards. The building-related variables in the building configuration file of the development board are described as follows:

   - **kernel_type**: kernel used by the development board, for example, **"liteos_a"**, **"liteos_m"**, or **"linux"**.
   - **kernel_version**: kernel version of the development board, for example, **"4.19"**.
   - **board_cpu**: CPU of the development board, for example, **"cortex-a7"** or **"riscv32"**.
   - **board_arch**: chipset architecture of the development board, for example, **"armv7-a"** or **"rv32imac"**.
   - **board_toolchain**: name of the customized build toolchain used by the development board, for example, **"gcc-arm-none-eabi"**. If this field is not specified, **ohos-clang** will be used.
   - **board_toolchain_prefix**: prefix of the build toolchain, for example, **"gcc-arm-none-eabi"**.
   - **board_toolchain_type**: build toolchain type. Currently, only GCC (**"gcc"**) and clang (**"clang"**) are supported.
   - **board_cflags**: build options of the .c file configured for the development board.
   - **board_cxx_flags**: build options of the **.cpp** file configured for the development board.
   - **board_ld_flags**: linking options configured for the development board.
      The corresponding **config.gni** file will be loaded based on the development board selected by the product. The variables in this file are globally visible to system modules.
   
   The following is an example of the **device/realtek/rtl8720/liteos_m/config.gni** file for the RTL8720 development board:
   
   
      ```
      # Kernel type, e.g. "linux", "liteos_a", "liteos_m".
      kernel_type = "liteos_m"
      
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
      
      # The toolchain path installed, it's not mandatory if you have added toolchain path to your ~/.bashrc.
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

2. Write the build script of the development board.

   For a newly added development board, the **BUILD.gn** file that functions as the entry for building must be added to the board directory. The following is an example of the **device/realtek/rtl8720/BUILD.gn** file for the RTL8720 development board:
   
   
      ```
      group("rtl8720") {
        ...
      }
      ```
   
3. Build and debug the development board.
   1. Run the **hb set** command in any directory to set the source code path and the product to build.

   2. Run the **hb build** command in the development board directory to start the build.

4. Build and debug the product.

   Write the development board and module information to the product configuration file. Fields in the configuration file are as follows:

   - **product_name**: product name, which can be customized. It is recommended that the value be the same as the level-3 directory name under the **vendor** directory.
   - **ohos_version**: OpenHarmony version number, which must be the same as the actual version number.
   - **device_company**: name of the chip solution vendor. It is recommended that the value be the same as the level-2 directory name under the **device** directory.
   - **board**: name of the development board. It is recommended that the value be the same as the level-3 directory name under the **device** directory.
   - **kernel_type**: kernel type, which must match the kernel type supported by the development board.
   - **kernel_version**: kernel version, which must match the kernel version supported by the development board.
   - **subsystem**: subsystem selected for the product. For details about the supported subsystem, see the descriptions of the subsystems in the **build/lite/components** directory.
   - **components**: subsystem-specific modules selected for the product. For details about the modules supported by the selected subsystem, see the **build/lite/components/*Specific subsystem*.json** file.
   - **features**: module-specific features configured for the product. For details about the features supported by the selected module, see the **features** field of the module in **build/lite/components/*Specific subsystem*.json** file.

   The following is an example of the **vendor/my_company/wifiiot/config.json** file for the Wi-Fi IoT module on the RTL8720 development board:


      ```
      {
          "product_name": "wifiiot",                        # Product name
          "ohos_version": "OpenHarmony 1.0",                # OS version
          "device_company": "realtek",                      # Name of the chipset solution vendor
          "board": "rtl8720",                               # Name of the development board
          "kernel_type": "liteos_m",                        # Kernel type
          "kernel_version": "3.0.0",                        # Kernel version
          "subsystems": [                            
            {
              "subsystem": "kernel",                        # Subsystem
              "components": [
                { "component": "liteos_m", "features":[] }  # Module and its features
              ]
            },
            ...
            {
               More subsystems and modules
            }
          ]
      }
      ```