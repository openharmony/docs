# OH_IPC_MessageOption
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--SE: @zhaopeng_gitee-->
<!--TSE: @maxiaorong2-->

## Overview

Defines an IPC message.

**Since**: 12

**Related module**: [OHIPCRemoteOhject](capi-ohipcremoteobject.md)

**Header file**: [ipc_cremote_object.h](capi-ipc-cremote-object-h.md)

## Summary

### Member Variables

| Name| Description|
| ---- | ---- |
| OH_IPC_RequestMode mode | Message request mode.|
| uint32_t timeout | Parameter reserved for RPC. It is invalid for IPC.|
| void* reserced | Reserved parameter, which must be NULL.|
