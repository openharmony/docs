# OHIPCRemoteStub

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=ceec5d18179ba29b1eca79fa9240e27795b5216c translatedAt=2026-07-28T02:19:31.635Z pushedAt=2026-07-29T07:03:54.144Z -->

```c
typedef struct OHIPCRemoteStub OHIPCRemoteStub;
```

## Overview

IPC remote service object. This struct is used to represent a remote service on the server side. It serves as the service proxy in IPC communication, handling client requests and implementing cross-process communication. **OHIPCRemoteStub** is a core struct provided by IPC Kit. **OHIPCRemoteStub** simplifies the IPC service development process by providing a unified request handling mechanism, helping you quickly implement cross‑process communication capabilities. It is mainly used for:

- Server-side IPC service development

- Cross-process communication proxy

- Request handling and response

**System capability:** SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCParcel](capi-ohipcparcel.md)

**Header file**: [ipc_cparcel.h](capi-ipc-cparcel-h.md)