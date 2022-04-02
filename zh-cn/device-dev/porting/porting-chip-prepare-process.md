# 编译构建适配流程


编译构建的详细介绍请见[编译构建子系统介绍](../subsystems/subsys-build-mini-lite.md)。新增三方芯片时，编译相关的适配流程如下：


## 编译构建适配流程

首先，创建开发板目录，以芯片解决方案厂商realtek的rtl8720开发板为例，需创建device/realtek/rtl8720目录。编译相关的适配步骤如下：

1. 编译工具链和编译选项配置。
   构建系统默认使用ohos-clang编译工具链，也支持芯片解决方案厂商按开发板自定义配置。开发板编译配置文件编译相关的变量如下：

   - kernel_type: 开发板使用的内核类型，例如："liteos_a", "liteos_m", "linux"。
   - kernel_version: 开发使用的内核版本，例如："4.19"。
   - board_cpu: 开发板CPU类型，例如："cortex-a7", "riscv32"。
   - board_arch: 开发芯片arch, 例如： "armv7-a", "rv32imac"。
   - board_toolchain: 开发板自定义的编译工具链名称，例如："gcc-arm-none-eabi"。若为空，则使用默认为ohos-clang。
   - board_toolchain_prefix：编译工具链前缀，例如："gcc-arm-none-eabi"。
   - board_toolchain_type：编译工具链类型，目前支持gcc和clang。例如："gcc" ，"clang"。
   - board_cflags：开发板配置的c文件编译选项。
   - board_cxx_flags：开发板配置的cpp文件编译选项。
   - board_ld_flags：开发板配置的链接选项。
      编译构建会按产品的选择的开发板，加载对应的config.gni，该文件中变量对系统组件全局可见。

   以芯片解决方案厂商realtek的rtl8720开发板为例，device/realtek/rtl8720/liteos_m/config.gni的内容如下：

     
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
   
   # The toolchain path instatlled, it's not mandatory if you have added toolchian path to your ~/.bashrc.
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

2. 开发板编译脚本。
   新增的开发板，对应目录下需要新增BUILD.gn文件作为开发板编译的总入口。以芯片解决方案厂商realtek的rtl8720开发板为例，对应的device/realtek/rtl8720/BUILD.gn为：

     
   ```
   group("rtl8720") {
     ...
   }
   ```

3. 编译调试开发板。
   1. 任意目录执行hb set按提示设置源码路径和要编译的产品。

   2. 在开发板目录下执行hb build, 即可启动开发板的编译。

4. 编译调试产品
   将开发板和组件信息写入产品配置文件，该配置文件字段说明如下：

   - product_name：产品名称，支持自定义，建议与vendor下的三级目录名称一致。
   - ohos_version：OpenHarmony版本号，应与实际下载的版本一致。
   - device_company：芯片解决方案厂商名称，建议与device的二级目录名称一致。
   - board：开发板名称，建议与device的三级级目录名称一致。
   - kernel_type：内核类型，应与开发板支持的内核类型匹配。
   - kernel_version：内核版本号，应与开发板支持的内核版本匹配。
   - subsystem：产品选择的子系统，应为OS支持的子系统，OS支持的子系统请见build/lite/components目录下的各子系统描述文件。
   - components：产品选择的某个子系统下的组件，应为某个子系统支持的组件，子系统支持的组件请见build/lite/components/子系统.json文件。
   - features：产品配置的某个组件的特性，组件支持的特性请见build/lite/components/子系统.json中对应组件的features字段。

   以基于rtl8720开发板的wifiiot模组为例，vendor/my_company/wifiiot/config.json如下：

     
   ```
   {
       "product_name": "wifiiot",                        # 产品名称
       "ohos_version": "OpenHarmony 1.0",                # 使用的OS版本
       "device_company": "realtek",                      # 芯片解决方案厂商名称
       "board": "rtl8720",                               # 开发板名称
       "kernel_type": "liteos_m",                        # 选择的内核类型
       "kernel_version": "3.0.0",                        # 选择的内核版本
       "subsystems": [                            
         {
           "subsystem": "kernel",                        # 选择的子系统
           "components": [
             { "component": "liteos_m", "features":[] }  # 选择的组件和组件特性
           ]
         },
         ...
         {
            更多子系统和组件
         }
       ]
   }
   ```
