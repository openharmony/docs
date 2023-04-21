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
>
### 本地调试：

- linux平台上调试
- windows平台上调试
- mac(M1)平台上调试
- mac(x86)平台上调试

>
### 远程调试：

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
>
## 常见使用使用场景：linux平台调试程序
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

