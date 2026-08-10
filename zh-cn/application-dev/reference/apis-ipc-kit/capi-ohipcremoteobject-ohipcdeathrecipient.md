# OHIPCDeathRecipient
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->

```c
typedef struct OHIPCDeathRecipient OHIPCDeathRecipient
```

## 概述

IPC死亡通知对象，用于监听IPC远程对象的死亡事件。创建OHIPCDeathRecipient对象后，必须注册到OHIPCRemoteObject对象才能生效；若未注册，将无法监听死亡事件。当远程进程意外终止或主动销毁时，注册了死亡监听的本地进程将收到死亡通知回调，从而及时释放相关资源或进行错误处理。

**起始版本：** 12

**相关模块：** [OHIPCRemoteObject](capi-ohipcremoteobject.md)

**所在头文件：** [ipc_cremote_object.h](capi-ipc-cremote-object-h.md)
