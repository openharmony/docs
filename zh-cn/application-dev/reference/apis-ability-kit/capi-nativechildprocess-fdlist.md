# NativeChildProcess_FdList

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

```c
typedef struct NativeChildProcess_FdList {...} NativeChildProcess_FdList
```

## 概述

传递给子进程的文件描述符信息列表，文件描述符记录个数不能超过16个，超过限制将导致创建子进程失败。

**起始版本：** 13

**相关模块：** [ChildProcess](capi-childprocess.md)

**所在头文件：** [native_child_process.h](capi-native-child-process-h.md)

## 汇总

### 成员变量

| 名称                                     | 描述 |
|----------------------------------------| -- |
| struct [NativeChildProcess_Fd](capi-nativechildprocess-fd.md)* head | 子进程文件描述符记录链表中的第一个记录。 |
