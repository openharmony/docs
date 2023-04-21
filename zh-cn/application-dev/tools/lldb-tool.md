# LLDB调试器使用指导
## 概述
LLDB（Low Lever Debugger）是新一代高性能调试器。当前Openharmony中的LLDB工具是在[llvm15.0.4](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.4)基础上适配演进出来的工具。LLDB支持在桌面和Openharmony设备或模拟器上调试。
## 工具获取
通过OpenHarmony的SDK获取，[获取路径](http://ci.openharmony.cn/dailys/dailybuilds)

lldb工具在SDK中的路径：**\ohos-sdk\\\[system]\native\llvm
> **说明：system可选windows/linux/darwin**
>
具体使用方法：以windows平台为例

- 解压sdk，直接在lldb工具所在路径\**\ohos-sdk\windows\native\llvm\bin运行lldb.exe即可。
## 支持平台与架构

### 常见使用使用场景：linux-x84/64场景下调试程序
>
### 具体调试场景

> **说明：远程调试时需要lldb-server和lldb配合使用**
- windows平台RK3568调试(arm架构调试)
- windows平台原型机调试(aarch64架构调试)
- windows平台模拟器调试
- mac(M1)平台RK3568调试(arm架构调试)
- mac(M1)平台原型机调试(aarch64架构调试)
- mac(M1)平台模拟器调试
- mac(x86)平台RK3568调试(arm架构调试)
- mac(x86)平台原型机调试(aarch64架构调试)
- mac(x86)平台模拟器调试

### lldb-server架构说明

| lldb-server所在路径                                          | 说明                                        |
| ------------------------------------------------------------ | ------------------------------------------- |
| **\ohos-sdk\\[system]\native\llvm\lib\clang\\\[version]\bin\aarch64-linux-ohos\lldb-server | 当调试的设备为ohos平台，aarch64架构时使用。 |
| **\ohos-sdk\\\[system]\native\llvm\lib\clang\\\[version]\bin\arm-linux-ohos\lldb-server | 当调试的设备为ohos平台，arm架构时使用。     |
| **\ohos-sdk\\\[system]\native\llvm\lib\clang\\\[version]\bin\x86_64-linux-ohos\lldb-server | 当调试的设备为ohos平台，x86_64架构时使用。  |



> 其中Mac平台的工具有arm64架构和x86_64架构区分。可根据”组件形态“进行区分，其中mac-sdk-full和mac-sdk-public的适用于x86_64架构。mac-sdk-m1-full和mac-sdk-m1-public的适用于arm64架构。
>
## 调试器提供功能
- 将程序加载到LLDB
- 设置断点
- 设置观察点
- 启动或attach到程序
- 控制程序的执行
- 检查线程状态
- 检查栈帧状态

其他更多功能参考：[LLDB工具使用指导](https://gitee.com/xwx1135370/third_party_llvm-project/blob/readme/lldb/README_zh.md)

## 具体使用命令
[LLDB工具使用指导](https://gitee.com/xwx1135370/third_party_llvm-project/blob/readme/lldb/README_zh.md)

