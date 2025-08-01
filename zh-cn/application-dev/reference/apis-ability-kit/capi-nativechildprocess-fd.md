# NativeChildProcess_Fd

## 概述

传递给子进程的文件描述符信息。

**起始版本：** 13

**相关模块：** [ChildProcess](capi-childprocess.md)

**所在头文件：** [native_child_process.h](capi-native-child-process-h.md)

## 汇总

### 成员变量

| 名称                                     | 描述 |
|----------------------------------------| -- |
| char* fdName                           | 文件描述符的键，最大长度为20字符。 |
| int32_t fd                             | 文件描述符的值。 |
| struct [NativeChildProcess_Fd](capi-nativechildprocess-fd.md)* next | 下一个文件描述记录指针。 |
