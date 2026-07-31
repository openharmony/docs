# OHIPCDeathRecipient

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=6f4847d75b3f902aaed7dfe11fd309a2307ea051 translatedAt=2026-07-30T02:33:16.045Z pushedAt=2026-07-30T03:21:08.199Z -->

```c
typedef struct OHIPCDeathRecipient OHIPCDeathRecipient
```

## Overview

Defines an IPC death notification object used to listen for the death event of an IPC remote object. After an **OHIPCDeathRecipient** object is created, it must be registered with an **OHIPCRemoteObject** object to take effect. When the remote process terminates unexpectedly or is destroyed proactively, the local process that has registered the death event listener will receive a death notification callback, allowing it to release related resources or perform error handling in a timely manner.

**Since**: 12

**Related module**: [OHIPCRemoteObject](capi-ohipcremoteobject.md)

**Header file**: [ipc_cremote_object.h](capi-ipc-cremote-object-h.md)