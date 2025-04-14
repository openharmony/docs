# OpenHarmony ABI

<!--RP1-->
OpenHarmony系统支持丰富的设备形态，支持多种架构指令集，支持多种操作系统内核；为了应用在各种OpenHarmony设备上的兼容性，本文定义了"OHOS" ABI（Application Binary Interface）的基础标准，包含如下方面。
<!--RP1End-->
## 字节序和字宽

"OHOS" ABI始终采用little-endian，32位系统采用ILP32，64位系统采用LP64。

## 过程调用规范

过程调用规范（Procedure Call Standard）定义了函数调用的参数传递方式，寄存器使用规则，栈操作规则等；不同C++编译器，不同操作系统，不同架构都有可能采用不同的调用规则。详细内容请参考《[不同C++编译器和操作系统的调用规范](https://www.agner.org/optimize/calling_conventions.pdf)》。架构相关的函数调用规范，请参考：

- ARM相关的调用规范请参考《[ARM32过程调用标准](https://github.com/ARM-software/abi-aa/tree/main/aapcs32)》。

- ARM64相关的调用规范请参考《[ARM64过程调用标准](https://github.com/ARM-software/abi-aa/tree/main/aapcs64)》。

## C++ ABI

OpenHarmony系统采用llvm项目中的libc++作为C++运行时库，在系统侧使用libc++.so库来承载，应用侧使用libc++_shared.so来承载，两侧共用一套代码，采用不同的C++命名空间。C++的符号重整规则请参考《[Itanium C++ ABI](https://itanium-cxx-abi.github.io/cxx-abi/)》。

## 浮点格式

采用IEEE754作为浮点编码格式，针对long double的格式定义，将在[支持架构ABI](#支持架构abi)具体说明。

## 可执行文件格式

OpenHarmony系统采用ELF文件格式作为全系统的二进制文件格式，具体格式详情，请参考《[System V Application Binary Interface](https://refspecs.linuxfoundation.org/elf/gabi4+/contents.html)》。CPU架构相关的格式定义，参考下面对应架构说明。

- arm相关的elf文件格式定义请参考《[arm架构elf文件格式](https://github.com/ARM-software/abi-aa/tree/main/aaelf32)》。

- arm64相关elf文件格式定义请参考《[arm64架构elf文件格式](https://github.com/ARM-software/abi-aa/tree/main/aaelf64)》。

## 支持架构ABI

下面介绍下当前“OHOS” ABI中支持的架构以及差异点。


### armeabi-v7a

此ABI是以[《ARM架构应用二进制接口》](https://developer.arm.com/Architectures/ABI)为基础制定，适用于32位armv7a架构的cpu，支持的核心包括Cortex-A5，Cortex-A7，Cortex-A8，Cortex-A9，Cortex-A12，Cortex-A15，以及Cortex-A17，支持arm32，thumb-2，VFPv3-D16指令。

此ABI使用-mfloat-cpu=softfp作为强制浮点数调用规则，本身不影响实际指令是否使用硬件浮点指令。Neon指令等其他扩展在此ABI中是可选的，为了更好的兼容性，建议应用开发者采用-mfpu=softvfp来编译native库 。

此ABI使用64位long double(IEEE binary64)。
<!--RP2--><!--RP2End-->

### arm64-v8a

此ABI是以《ARM架构应用二进制接口》为基础制定，支持AArch64指令集，默认支持neon特性。

此ABI使用-mfloat-cpu=softfp作为强制浮点数调用规则。

此ABI使用128位long double(IEEE binary128)。

### x86_64

此ABI是以Intel64和IA-32 ABI为基础，支持MMX、SSE、SSE2、SSE3、SSSE3、SSE4.1等指令，与x86相关的规范参考《System V Application Binary Interface》、《AMD64 Architecture Processor Supplement》。

此ABI使用128位long double(IEEE binary128)，x86架构上很多平台采用float80格式，OpenHarmony仍然采用128bit形式。

## 在编译架构中指定ABI

### DevEco Studio中设置

在OpenHarmony的C++工程中，找到C++代码所在项目build-profile.json5文件buildOption/externalNativeOptions字段，添加abiFilters字段：

```json
{
    “abiType”: 'stageMode',
    “buildOption”： {
        “externalNativeOptions”: {
            "path": "./src/main/cpp/CMakeLists.txt",
            "arguments": "",
            "abiFilters": [
                "armeabi-v7a",
                "arm64-v8a"
            ]
        }
    }
}
```
**注意**：如果DevEco Studio中不设置abiFilters字段，则默认配置的指定架构为：arm64-v8a。
### cmake中设置

通过SDK CAPI开发native代码的时候，在build/cmake/ohos.toolchain.cmake中定义了OpenHarmony系统一些交叉编译常用的环境变量设置。其中OHOS_ARCH变量定义了当前目标编译的ABI，可以设置下面三个ABI中的一种，arm64-v8a，armeabi-v7a，x86_64。
