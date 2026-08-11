# OHIPCErrorCode
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供IPC错误码定义，用于标识和处理IPC通信过程中可能发生的各类错误。开发者可根据返回的错误码快速定位问题原因，如参数错误、序列化失败、内存分配失败、远端对象死亡等场景，从而采取相应的错误处理措施。

**系统能力：** SystemCapability.Communication.IPC.Core

**设备类型说明：** 支持所有设备类型

**起始版本：** 12

## 文件汇总

| 名称 | 描述 |
| ---- | ---- |
| [ipc_error_code.h](capi-ipc-error-code-h.md) | 定义IPC错误码常量，包含进程间通信中可能出现的各类错误码定义及说明，供开发者在IPC开发中使用。 |
