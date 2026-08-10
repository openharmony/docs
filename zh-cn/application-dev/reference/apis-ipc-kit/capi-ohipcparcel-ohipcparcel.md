# OHIPCParcel

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->

```c
typedef struct OHIPCParcel OHIPCParcel
```

## 概述

IPC序列化对象，用于在跨进程通信中序列化和反序列化数据。该对象需要通过相关函数创建和销毁，开发者需要遵循对象的生命周期管理规范，正确管理内存资源。

**起始版本：** 12

**相关模块：** [OHIPCParcel](capi-ohipcparcel.md)

**所在头文件：** [ipc_cparcel.h](capi-ipc-cparcel-h.md)
