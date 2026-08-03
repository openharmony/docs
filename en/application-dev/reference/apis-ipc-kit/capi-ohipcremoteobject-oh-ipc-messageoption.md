# OH_IPC_MessageOption

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=9f8e1a64bd74ee011099413e1e72ea230f3c7180 translatedAt=2026-07-30T02:33:33.006Z pushedAt=2026-07-30T03:26:59.537Z -->

```c
typedef struct {...} OH_IPC_MessageOption
```

## Overview

Defines the IPC message options, which are used to configure request parameters for IPC communication.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCRemoteObject](capi-ohipcremoteobject.md)

**Header file**: [ipc_cremote_object.h](capi-ipc-cremote-object-h.md)

## Summary

### Member Variables

| Name| Description|
| ---- | ---- |
| [OH_IPC_RequestMode](capi-ipc-cremote-object-h.md#oh_ipc_requestmode) mode | Message request mode, which specifies the request method for IPC messages. You can select the synchronous mode or asynchronous mode. The synchronous mode is suitable for scenarios where you need to wait for the return result, while the asynchronous mode is suitable for scenarios where you do not need to wait for the result. When the synchronous mode is set, the call blocks the current thread to wait for the return result. When the asynchronous mode is set, the call returns immediately without waiting for the result. In C language, this member must be explicitly initialized. It is advised to initialize it to the synchronous mode (when a return result is required) or the asynchronous mode (when no return result is required). |
| uint32_t timeout | RPC reserved parameter. In RPC communication scenarios, a timeout period can be set. This parameter is invalid for IPC communication and can be ignored when using IPC. The unit is seconds. The value range is [0, 4294967295]. In RPC scenarios, it is advised to set a reasonable timeout period based on service requirements (for example, 30000 ms for common requests and 60000 ms for large data transfers) to avoid prolonged blocking. After the timeout, the RPC call fails and returns a timeout error. In C language, this member must be explicitly initialized. It is advised to initialize it to **0**. |
| void* reserved | Reserved parameter. NULL must be passed. Passing a non-null pointer may cause the API call to fail or result in undefined behavior. |