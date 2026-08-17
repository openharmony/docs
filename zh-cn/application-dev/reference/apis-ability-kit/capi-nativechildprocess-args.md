# NativeChildProcess_Args

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

```c
typedef struct {...} NativeChildProcess_Args
```

## 概述

传递给子进程的参数。

**起始版本：** 13

**相关模块：** [ChildProcess](capi-childprocess.md)

**所在头文件：** [native_child_process.h](capi-native-child-process-h.md)

## 汇总

### 成员变量

| 名称                                          | 描述 |
|---------------------------------------------| -- |
| char* entryParams                           | 传递给子进程入口函数的参数字符串。entryParams通过IPC传输，IPC传输的数据量最大为200KB（详见[约束与限制](../../ipc/ipc-rpc-overview.md#约束与限制)），其中部分由系统占用，建议entryParams传入数据量不超过150KB，否则可能导致创建子进程失败。 |
| struct [NativeChildProcess_FdList](capi-nativechildprocess-fdlist.md) fdList | 传递给子进程的文件描述符信息列表，文件描述符记录个数不能超过16个。子进程可通过这些文件描述符与主进程进行通信。 |
