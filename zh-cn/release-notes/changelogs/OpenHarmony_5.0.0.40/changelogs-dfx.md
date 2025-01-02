# DFX子系统变更说明

## cl.DFX.1 命令行调试工具使用权限缩小

**访问级别**

其他

**变更原因**

基于对应用的安全隐私保护，调试能力遵循以下原则进行调整：

1.在开发者模式下，开发者只能调试自己的应用，无法调试其他三方APP。

2.调试信息不包含开发者无权读取的信息。

**变更影响**

该变更为不兼容变更。

调试命令使用权限缩小，部分命令仅debug应用可用，详见“变更的接口/组件”。

**变更发生版本**

从OpenHarmony SDK 5.0.0.40 开始

**变更的接口/组件**


| 组件 | 命令  | 变更前 | 变更后 |
| -------- | ----- | ----- | -------- |
| hidumper   | hidumper --mem-smaps pid [-v] | 有内存信息打印，且能获取内存地址信息 | 将打印帮助信息，不支持该命令   |
| hidumper   | hidumper -p [pid] | 可以导出任意进程的maps信息以及/proc/pid/mountinfo等信息 | 只支持导出debug应用的基础信息，所有进程均不支持导出maps信息   |
| hiprofiler | nativehook      | nativehook插件可以对任意进程进行调优      | 使用nativehook插件仅支持对debug应用进行调试         |
| hiperf         | hiperf record/stat      | 支持对release应用进行调试      | 仅支持对debug应用进行调试         |
| hiperf         | hiperf dump      | 可以输出采集进程的maps信息以及其他信息 | 不输出maps信息，其他信息不变       |
| hiperf         | 日志输出      | 可以输出hiperf日志信息      | 不支持该功能         |


**适配指导**

将release应用修改为debug应用，重新编译调试

## cl.DFX.2 hdc工具tmode usb命令功能废弃

**访问级别**

其他

**变更原因**

hdc同时支持USB调试和无线调试

**变更影响**

变更前：命令执行后将关闭无线调试通道，同时打开USB调试通道。

变更后：命令功能废弃，可通过调测设备的开发者选项界面中USB调试开关控制USB调试通道开启和关闭。如需关闭无线调试通道请使用hdc tmode port close命令。


**变更发生版本**

从OpenHarmony SDK 5.0.0.40 开始

**变更的接口/组件**


| 组件 | 命令  |
| -------- | ------------  |
|    hdc   | hdc tmode usb |


**适配指导**

根据功能变更后命令进行调整适配