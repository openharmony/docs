# exec

## 命令功能

exec命令属于shell内置命令，在exec执行命令时，不启用新的shell进程。目前实现最基础的执行用户态程序的功能。

## 命令格式

exec &lt;_executable-file_&gt;

## 参数说明

**表1** 参数说明

| 参数            | 参数说明           |
| --------------- | ------------------ |
| executable-file | 有效的可执行文件。 |

## 使用指南

该命令当前仅支持执行有效的二进制程序，程序成功执行，默认后台运行，但与Shell共用终端，可能会导致程序打印输出与Shell输出交错显示。

## 使用实例

举例：

输入exec helloworld。

## 输出说明

```
OHOS # exec helloworld
OHOS # hello world!
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
>  可执行文件执行后，先打印“OHOS \#”提示符原因：目前Shell “exec”命令执行均为后台执行，结果可能导致提示符提前打印。