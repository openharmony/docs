# OH_IPC_MessageOption
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong2-->
<!--Adviser: @zhang_yixin13-->

## 概述

IPC消息选项定义。

**起始版本：** 12

**相关模块：** [OHIPCRemoteOhject](capi-ohipcremoteobject.md)

**所在头文件：** [ipc_cremote_object.h](capi-ipc-cremote-object-h.md)

## 汇总

### 成员变量

| 名称 | 描述 |
| ---- | ---- |
| OH_IPC_RequestMode mode | 消息请求模式。 |
| uint32_t timeout | RPC预留参数，该参数对IPC无效。 |
| void* reserced | 保留参数，必须为空 |
