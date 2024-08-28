# DFX子系统变更说明

## cl.DFX.1 命令行调试工具使用权限缩小

**访问级别**

其他

**变更原因**

应用安全隐私保护

**变更影响**

该变更为不兼容变更。

如下所述调试命令使用权限缩小

**变更发生版本**

从OpenHarmony SDK 5.0.0.40 开始

**变更的接口/组件**


| 组件 | 命令  | 变更前 | 变更后 |
| -------- | ----- | ----- | -------- |
| hidumper   | hidumper --mem-smaps pid [-v] | 有内存信息打印，且能获取内存地址信息 | 将打印帮助信息，该功能不可用   |
| hidumper   | hidumper -p [pid] | 可以导出任意进程的maps信息以及/proc/pid/mountinfo等信息 | 只支持导出debug应用的基础信息，所有进程均不支持导出maps信息   |
| hiprofiler | nativehook      | nativehook插件可以对任意进程进行调优      | 使用nativehook插件仅支持对debug应用进行调试         |
| hiperf         | hiperf record/stat      | 支持对release应用进行调试      | 仅支持对debug应用进行调试         |
| hiperf         | hiperf dump      | 可以输出maps信息      | 不输出maps信息         |
| hiperf         | 日志输出      | 可以输出hiperf日志信息      | 不输出hiperf日志信息         |


**适配指导**

将release应用修改为debug应用，重新编译调试