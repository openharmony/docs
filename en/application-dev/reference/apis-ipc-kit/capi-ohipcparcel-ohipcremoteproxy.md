# OHIPCRemoteProxy

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=ceec5d18179ba29b1eca79fa9240e27795b5216c translatedAt=2026-07-28T02:19:19.092Z pushedAt=2026-07-29T07:06:42.719Z -->

```c
typedef struct OHIPCRemoteProxy OHIPCRemoteProxy
```

## Overview

IPC remote proxy object, which is used on the client side to proxy the capabilities of a remote service to implement cross-process communication. This object encapsulates a reference to the remote service and supports sending requests to and receiving responses from the remote service. It is applicable to scenarios that require cross-process service capability invocation, such as cross-process service calls, system service access, and cross-application data sharing. Using this object simplifies the implementation of cross-process communication and improves development efficiency.

**Since**: 12

**Related module**: [OHIPCParcel](capi-ohipcparcel.md)

**Header file**: [ipc_cparcel.h](capi-ipc-cparcel-h.md)