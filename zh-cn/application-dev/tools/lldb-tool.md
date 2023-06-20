# LLDB调试器使用指导
## 概述
LLDB（Low Lever Debugger）是新一代高性能调试器。

当前OpenHarmony中的LLDB工具是在[llvm15.0.4](https://github.com/llvm/llvm-project/releases/tag/llvmorg-15.0.4)基础上适配演进出来的工具，支持在桌面和Openharmony设备或模拟器上调试。

## 工具获取
通过OpenHarmony的SDK获取,从以下链接获取SDK：http://ci.openharmony.cn/dailys/dailybuilds

lldb工具在SDK中的路径：
```
\ohos-sdk\[system]\native\llvm
```
其中system可选windows/linux/darwin。

以windows平台为例，解压SDK后，lldb.exe的存放路径为：
```
\ohos-sdk\windows\native\llvm\bin
```

## 支持平台与架构

### 本地调试
#### linux平台调试使用示例
1.获取到与lldb同一版本的clang编译器生成的带有调试信息的可执行文件filename

2.指定调试的文件名，终端窗口执行命令：
```
./lldb filename
```
3.在代码中main函数处打断点，lldb界面下执行命令：
```
(lldb) b main
```
4.运行程序，使程序停在断点处，lldb界面下执行命令：
```
(lldb) run
```
5.执行后续调试操作
### 远程调试

> **说明：远程调试时需要lldb-server和lldb配合使用**
- windows平台ohos设备调试(arm架构调试)
- windows平台ohos设备调试(aarch64架构调试)
- windows平台模拟器调试
- mac(M1)平台ohos设备调试(arm架构调试)
- mac(M1)平台ohos设备调试(aarch64架构调试)
- mac(M1)平台模拟器调试
- mac(x86)平台ohos设备调试(arm架构调试)
- mac(x86)平台ohos设备调试(aarch64架构调试)
- mac(x86)平台模拟器调试
- linux平台ohos设备调试(arm架构调试)
- linux平台ohos设备调试(aarch64架构调试)

#### 远程调试使用示例

linux平台连接arm架构ohos设备远程调试

1.设备上运行带有调试信息的可执行文件：

```
./filename
```
2.将lldb-server推送到设备，运行lldb-server。

命令行窗口1：

```
hdc file send lldb-server /data/local/tmp
hdc shell ./data/local/tmp/lldb-server p --server --listen "*:8080"
```
> **说明：其中/data/local/tmp为设备上指定的目录，8080为监听端口，均可自定义**

3.在另一窗口启动lldb，选择远端ohos并连接。

命令行窗口2：

```
./lldb
(lldb) platform select remote-ohos
(lldb) platform connect connect://localhost:8080
```
4.打断点，以及后续调试操作。

命令行窗口2：

```
(lldb) breakpoint set --file <filename> --line <linenum>
(lldb) process attach --name process-name
```
## lldb调试器提供功能列表
- 将程序加载到lldb
- 设置断点
- 设置观察点
- 启动或attach到程序
- 控制程序的执行
- 检查线程状态
- 检查栈帧状态

## 其他更多功能与具体命令请参考
[LLDB工具使用指导](https://gitee.com/openharmony/third_party_llvm-project/blob/master/lldb/README_zh.md)

