# 芯片解决方案
### 芯片解决方案配置规则

- 芯片解决方案是指基于某款开发板的完整解决方案，包含驱动、设备侧接口适配、开发板sdk等。
- 芯片解决方案是一个特殊的部件，源码路径规则为：**device/{开发板}/{芯片解决方案厂商}**。
- 芯片解决方案部件会随产品选择的开发板默认编译。
- 芯片解决方案目录树规则如下：

```shell
  device                                      
  └── board                                   
      └── company                            # 芯片解决方案厂商
           └──  hispark_aries                # 开发板名称
                 ├── BUILD.gn                # 编译脚本
                 ├── hals                    # OS南向接口适配
                 ├── linux                   # 可选，linux内核版本
                 │   └── config.gni          # linux版本编译配置
                 └── liteos_a                # 可选，liteos内核版本
                     └── config.gni          # liteos_a版本编译配置
```

> **注意**：config.gni为开发板编译相关的配置，编译时会采用该配置文件中的参数编译所有OS部件，编译阶段系统全局可见。

- config.gni的关键字段介绍如下：

```shell
  kernel_type:            开发板使用的内核类型，例如：“liteos_a”, “liteos_m”, “linux”。
  kernel_version:         开发使用的内核版本，例如：“4.19”。
  board_cpu:              开发板CPU类型，例如：“cortex-a7”, “riscv32”。
  board_arch:             开发芯片arch, 例如： “armv7-a”, “rv32imac”。
  board_toolchain:        开发板自定义的编译工具链名称，例如：“gcc-arm-none-eabi”。若为空，则使用默认为ohos-clang。
  board_toolchain_prefix：编译工具链前缀，例如：“gcc-arm-none-eabi”。
  board_toolchain_type：  编译工具链类型，目前支持gcc和clang。例如：“gcc” ，“clang”。
  board_cflags：          开发板配置的c文件编译选项。
  board_cxx_flags：       开发板配置的cpp文件编译选项。
  board_ld_flags：        开发板配置的链接选项。
```

###  新增并编译芯片解决方案

编译构建支持添加新的芯片解决方案厂商，具体步骤如下：

1. 创建芯片解决方案目录。 按照芯片解决方案配置规则创建目录，以芯片厂商realtek的“rtl8720“开发板为例, 在代码根目录执行：

   ```shell
   mkdir -p device/board/realtek/rtl8720
   ```

2. 创建内核适配目录，并编写开发板编译配置config.gni文件。 以realtek的“rtl8720“开发板的liteos_a适配为例，device/board/realtek/rtl8720/liteos_a/config.gni的内容如下：

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

3. 编写编译脚本。 在开发板目录下创建BUILD.gn，target名称应与开发板名称一致。以realtek的rtl8720开发板为例，device/board/realtek/rtl8720/BUILD.gn内容可以是：

   ```shell
   group("rtl8720") { # target类型也可以shared_library, static_library, executable
     # 具体内容
     ......
   }
   ```

4. 编译芯片解决方案。 在开发板目录下执行hb build，即可启动芯片解决方案的编译。
