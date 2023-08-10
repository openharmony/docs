# 编译构建

## 编译环境搭建

首先请搭建OpenHarmony基础环境，相关操作请参考[快速入门环境搭建章节](../quick-start/quickstart-overview.md)。用户态和LiteOS-A的内核态编译均使用llvm编译器编译，安装方法在搭建基础环境中已提供。若选择移植linux内核，请执行如下命令安装gcc-arm-linux-gnueabi交叉编译工具链，用于编译linux内核态镜像：


```
sudo apt-get install gcc-arm-linux-gnueabi
```


## 编译构建系统介绍

编译构建流程、编译脚本编写、目录规则、独立编译单个组件、独立编译芯片解决方案等介绍请见[编译构建子系统介绍](../subsystems/subsys-build-all.md)。


## 新建芯片解决方案

了解编译框架和搭建完编译环境后，请参考如下步骤新建芯片解决方案：

1. 新建目录

   芯片解决方案的目录规则为：`device/{芯片解决方案厂商}/{开发板}`。以海思的hispark_taurus开发板为例，在代码根目录执行如下命令建立目录：

   
   ```
   mkdir -p device/hisilicon/hispark_taurus
   ```

   芯片解决方案目录树的规则如下：

   
   ```
   device                                      
   └── company                         # 芯片解决方案厂商
       └── board                       # 开发板名称
           ├── BUILD.gn                # 编译脚本
           ├── hals                    # OS南向接口适配
           ├── linux                   # 可选，linux内核版本
           │   └── config.gni          # linux版本编译配置
           └── liteos_a                # 可选，liteos内核版本
               └── config.gni          # liteos_a版本编译配置
   ```

   以hispark_taurus移植linux内核为例，目录树应该如下：

   
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

   目录树建立后开发板相关的源码放到hispark_taurus目录下。

2. 配置开发板编译选项

   步骤1中的`config.gni`可配置开发板相关的编译选项，编译构建框架将会遵照该配置文件中的参数编译所有用户态OS组件。其中关键的字段说明如下：

   
   ```
   kernel_type:            开发板使用的内核类型，例如：“liteos_a”, “liteos_m”, “linux”。
   kernel_version:         开发板使用的内核版本，例如：“4.19”。
   board_cpu:              开发板CPU类型，例如：“cortex-a7”, “riscv32”。
   board_arch:             开发板芯片arch, 例如： “armv7-a”, “rv32imac”。
   board_toolchain:        开发板自定义的编译工具链名称，例如：“gcc-arm-none-eabi”。若为空，则使用默认为ohos-clang。
   board_toolchain_prefix：编译工具链前缀，例如：“gcc-arm-none-eabi”。
   board_toolchain_type：  编译工具链类型，目前支持gcc和clang。例如：“gcc” ，“clang”。
   board_cflags：          开发板配置的c文件编译选项。
   board_cxx_flags：       开发板配置的cpp文件编译选项。
   board_ld_flags：        开发板配置的链接选项。
   ```

     还以海思的hispark_taurus开发板为例，对应的`device/hisilicon/hispark_taurus/config.gni`内容如下：
   
   ```
   # Board CPU type, e.g. "cortex-a7", "riscv32".
   board_cpu = "cortex-a7"
   
   # Toolchain name used for system compiling.
   # E.g. gcc-arm-none-eabi, arm-linux-harmonyeabi-gcc, ohos-clang,  riscv32-unknown-elf.
   # Note: The default toolchain is "ohos-clang". It's not mandatory if you use the default toochain.
   board_toolchain = "mips-linux-gnu-gcc"
   
   # The toolchain path installed, it's not mandatory if you have added toolchain path to your ~/.bashrc.
   board_toolchain_path = 
       rebase_path("//prebuilts/gcc/linux-x86/arm/arm-linux-ohoseabi-gcc/bin",
                   root_build_dir)
   
   # Compiler prefix.
   board_toolchain_prefix = "arm-linux-ohoseabi-"
   
   # Compiler type, "gcc" or "clang".
   board_toolchain_type = "gcc"
   
   # Board related common compile flags.
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

3. 编写开发板编译脚本

   步骤1中的`BUILD.gn`为新增的开发板的编译入口，主要用于编译开发板相关的代码，主要为设备侧驱动、设备侧接口适配(媒体，图形等)和开发板的SDK等等。

   海思的hispark_taurus开发板的`device/hisilicon/hispark_taurus/BUILD.gn`可写成：

   
   ```
   # group名称建议与开发板名称一致
   group("hispark_taurus") {   
     deps = [ "//kernel/linux/patches:linux_kernel" ] # 拉起内核编译
     deps += [
     ...... # 开发板其他编译单元
     ]
   }
   ```

4. 编译调试

   在开发板目录下执行`hb set`和`hb build`即可启动芯片解决方案的编译，编译框架会以开发板下的`BUILD.gn`为入口启动编译。
