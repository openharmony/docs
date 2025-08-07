# ipc_cremote_object.h
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--SE: @zhaopeng_gitee-->
<!--TSE: @maxiaorong2-->

## Overview

Provides C APIs for creating and destroying a remote object, transferring data, and observing the dead status of a remote object.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCRemoteObject](capi-ohipcremoteobject.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [OH_IPC_MessageOption](capi-ohipcremoteobject-oh-ipc-messageoption.md) | - | Defines an IPC message.|
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) | OHIPCDeathRecipient | Defines an object that receives death notifications.|

### Enums

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [OH_IPC_RequestMode](#oh_ipc_requestmode) | OH_IPC_RequestMode | Enumerates the IPC request modes.|

### Function

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [typedf int (\*OH_OnRemoteRequestCallback)(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)](#oh_onremoterequestcallback) | OH_OnRemoteRequestCallback | Called to process the peer request at the stub.|
| [typedef void (\*OH_OnRemoteDestroyCallback)(void *userData)](#oh_onremotedestroycallback) | OH_OnRemoteDestroyCallback | Called when an observed object is destroyed.|
| [OHIPCRemoteStub* OH_IPCRemoteStub_Create(const char *descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallbac destroyCallback, void *userData)](#oh_ipcremotestub_create) | - | Creates an **OHIPCRemoteStub** object.|
| [void OH_IPCRemoteStub_Destroy(OHIPCRemoteStub *stub)](#oh_ipcremotestub_destroy) | - | Destroys an **OHIPCRemoteStub** object.|
| [void OH_IPCRemoteProxy_Destroy(OHIPCRemoteProxy *proxy)](#oh_ipcremoteproxy_destroy) | - | Destroys an **OHIPCRemoteProxy** object.|
| [int OH_IPCRemoteProxy_SendRequest(const OHIPCRemoteProxy *proxy, uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, const OH_IPC_MessageOption *option)](#oh_ipcremoteproxy_sendrequest) | - | Sends an IPC message.|
| [int OH_IPCRemoteProxy_GetInterfaceDescriptor(OHIPCRemoteProxy *proxy, char **descriptor, int32_t *len, OH_IPC_MemAllocator allocator)](#oh_ipcremoteproxy_getinterfacedescriptor) | - | Obtains the interface descriptor from the stub.|
| [typedof void (\*OH_OnDeathRecipientCallback)(void *userData)](#oh_ondeathrecipientcallback) | OH_OnDeathRecipientCallback | Defines a callback to be invoked when the remote **OHIPCRemoteStub** object dies unexpectedly.|
| [typedef void (\*OH_OnDeathRecipientDestroyCallback)(void *userData)](#oh_ondeathrecipientdestroycallback) | OH_OnDeathRecipientDestroyCallback | Defines a callback to be invoked when the **OHIPCDeathRecipient** object is destroyed.|
| [OHIPCDeathRecipient* OH_IPCDeathRecipient_Create(OH_OnDeathRecipientCallback deathRecipientCallback, OH_OnDeathRecipientDestroyCallback destroyCallback, void *userData)](#oh_ipcdeathrecipient_create) | - | Creates an **OHIPCDeathRecipient** object.|
| [void OH_IPCDeathRecipient_Destroy(OHIPCDeathRecipient *recipient)](#oh_ipcdeathrecipient_destroy) | - | Destroys an **OHIPCDeathRecipient** object.|
| [int OH_IPCRemoteProxy_AddDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)](#oh_ipcremoteproxy_adddeathrecipient) | - | Subscribes to the death of an **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.|
| [int OH_IPCRemoteProxy_RemoveDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)](#oh_ipcremoteproxy_removedeathrecipient) | - | Unsubscribes from the death of the **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.|
| [int OH_IPCRemoteProxy_IsRemoteDead(const OHIPCRemoteProxy *proxy)](#oh_ipcremoteproxy_isremotedead)| - | Checks whether the **OHIPCRemoteStub** object corresponding to the **OHIPCRemoteProxy** object is dead.|

## Enum Description

### OH_IPC_RequestMode

```C
enum OH_IPC_RequestMode
```

**Description**

Enumerates the IPC request modes.

**Since**: 12

| Enum Item| Description|
| ------ | ---- |
| OH_IPC_REQUEST_MODE_SYNC = 0 | Synchronous request.|
| OH_IPC_REQUEST_MODE_ASYNC = 1 | Asynchronous request.|

## Function Description

### OH_OnRemoteRequestCallback()

```C
typedef int(*OH_OnRemoteRequestCallback)(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)
```

**Description**

Called to process the peer request at the stub.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| uint32_t code | Customized communication command word.<br>Value range: [0x01, 0x00ffffff]|
| const [OHIPCParcel](capi-ohipcparcel.md) *data | Pointer to the requested data object. It cannot be NULL or released in the function.|
| [OHIPCParcel](capi-ohipcparcel.md) *reply | Pointer to the response data object. It cannot be NULL or released in the function. If this function returns an error, data cannot be written to this parameter.|
| userDavoid *userDatata | Pointer to the private user data. It can be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns a custom error code in the range [1909001, 1909999] or a system error code otherwise.<br> If the custom error code is out of range, [OH_IPC_ErrorCode#OH_IPC_INVALID_USER_ERROR_CODE](capi-ipc-error-code-h.md) is returned.|

### OH_OnRemoteDestroyCallback()

```C
typedef void(*OH_OnRemoteDestroyCallback)(void *userData)
```

**Description**

Called when an observed object is destroyed.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ----- | ----- |
| void *userData | Pointer to the private user data. It can be NULL.|

### OH_IPCRemoteStub_Create()

```C
OHIPCRemoteStub* OH_IPCRemoteStub_Create(const char *descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallback destroyCallback, void *userData)
```

**Description**

Creates an **OHIPCRemoteStub** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const char *descriptor | Pointer to the descriptor of the **OHIPCRemoteStub** object to create. It cannot be NULL.|
| [OH_OnRemoteRequestCallback](#oh_onremoterequestcallback) requestCallback | Callback used to process the data request. It cannot be NULL.|
| [OH_OnRemoteDestroyCallback](#oh_onremotedestroycallback) destroyCallback | Callback to be invoked when the object is destroyed. It can be NULL.|
| void *userData | Pointer to the private user data. It can be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| OHIPCRemoteStub* | Returns the pointer to the **OHIPCRemoteStub** object created if the operation is successful; returns NULL otherwise.|

### OH_IPCRemoteStub_Destroy()

```C
void OH_IPCRemoteStub_Destroy(OHIPCRemoteStub *stub)
```

**Description**

Destroys an **OHIPCRemoteStub** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteStub](capi-ohipcparcel-ohipcremotestub.md) *stub | Pointer to the **OHIPCRemoteStub** object to destroy.|

### OH_IPCRemoteProxy_Destroy()

```C
void OH_IPCRemoteProxy_Destroy(OHIPCRemoteProxy *proxy)
```

**Description**

Destroys an **OHIPCRemoteProxy** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object to destroy.|

### OH_IPCRemoteProxy_SendRequest()

```C
int OH_IPCRemoteProxy_SendRequest(const OHIPCRemoteProxy *proxy, uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, const OH_IPC_MessageOption *option)
```

**Description**

Sends an IPC message.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object. It cannot be NULL.|
| uint32_t code | Customized IPC command word, in the range [0x01, 0x00ffffff].|
| const [OHIPCParcel](capi-ohipcparcel.md) *data | Pointer to the requested data object. It cannot be NULL.|
| [OHIPCParcel](capi-ohipcparcel.md) *reply | Pointer to the response data object. It cannot be NULL in the case of a synchronous request, and can be NULL in the case of an asynchronous request.|
| const [OH_IPC_MessageOption](capi-ohipcremoteobject-oh-ipc-messageoption.md) *option | Pointer to the message option. It can be NULL, which indicates a synchronous request.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](capi-ipc-error-code-h.md) if the remote **OHIPCRemoteStub** object is dead;<br> returns [OH_IPC_ErrorCode#OH_IPC_CODE_OUT_OF_RANGE](capi-ipc-error-code-h.md) if the code is out of range;<br> returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md) or a custom error code in other cases.|

### OH_IPCRemoteProxy_GetInterfaceDescriptor()

```C
int OH_IPCRemoteProxy_GetInterfaceDescriptor(OHIPCRemoteProxy *proxy, char **descriptor, int32_t *len, OH_IPC_MemAllocator allocator)
```

**Description**

Obtains the interface descriptor from the stub.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object. It cannot be NULL.|
| char **descriptor | Pointer to the address of the memory for holding the interface descriptor. The memory is allocated by the allocator provided by the user and needs to be released. This pointer cannot be NULL. If an error code is returned, you still need to check whether the memory is empty and release the memory. Otherwise, memory leaks may occur.|
| int32_t *len | Pointer to the length of the data written to the descriptor, including the terminator. It cannot be NULL.|
| [OH_IPC_MemAllocator](capi-ipc-cparcel-h.md#oh_ipc_memallocator) allocator | Memory allocator specified by the user for allocating memory for **identity**. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if the parameter is incorrect;<br> returns [OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](capi-ipc-error-code-h.md) if the remote **OHIPCRemoteStub** object is dead;<br> returns [OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](capi-ipc-error-code-h.md) if memory allocation fails;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) or a custom error code if the data in the serialized object fails to be read.|

### OH_OnDeathRecipientCallback()

```C
typedef void(*OH_OnDeathRecipientCallback)(void *userData)
```

**Description**

Defines a callback to be invoked when the remote **OHIPCRemoteStub** object dies unexpectedly.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| void *userData | Pointer to the private user data. It can be NULL.|

### OH_OnDeathRecipientDestroyCallback()

```C
typedef void(*OH_OnDeathRecipientDestroyCallback)(void *userData)
```

**Description**

Defines a callback to be invoked when the **OHIPCDeathRecipient** object is destroyed.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| void *userData | Pointer to the private user data. It can be NULL.|

### OH_IPCDeathRecipient_Create()

```C
OHIPCDeathRecipient* OH_IPCDeathRecipient_Create(OH_OnDeathRecipientCallback deathRecipientCallback, OH_OnDeathRecipientDestroyCallback destroyCallback, void *userData)
```

**Description**

Creates an **OHIPCDeathRecipient** object, which triggers a notification when the **OHIPCRemoteStub** object dies unexpectedly.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OH_OnDeathRecipientCallback](#oh_ondeathrecipientcallback) deathRecipientCallback | Callback to be invoked when the **OHIPCRemoteStub** object is dead. It cannot be NULL.|
| [OH_OnDeathRecipientDestroyCallback](#oh_ondeathrecipientdestroycallback) destroyCallback | Callback to be invoked when the object is destroyed. It can be NULL.|
| void *userData | Pointer to the private user data. It can be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| OHIPCDeathRecipient* | Returns the pointer to the **OHIPCDeathRecipient** object created if the operation is successful; returns NULL otherwise.|

### OH_IPCDeathRecipient_Destroy()

```C
void OH_IPCDeathRecipient_Destroy(OHIPCDeathRecipient *recipient)
```

**Description**

Destroys an **OHIPCDeathRecipient** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) *recipient | Pointer to the **OHIPCDeathRecipient** object to destroy.|

### OH_IPCRemoteProxy_AddDeathRecipient()

```C
int OH_IPCRemoteProxy_AddDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)
```

**Description**

Subscribes to the death of an **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object that subscribes to the death notification. It cannot be NULL.|
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) *recipient | Pointer to the object that receives the death notification of the **OHIPCRemoteStub** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if the parameter is incorrect;<br> returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md) in other cases.|

### OH_IPCRemoteProxy_RemoveDeathRecipient()

```C
int OH_IPCRemoteProxy_RemoveDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)
```

**Description**

Unsubscribes from the death of the **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object that unsubscribes from the death notification. It cannot be NULL.|
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) *recipient | Pointer to the object that receives the death notification of the **OHIPCRemoteStub** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if the parameter is incorrect;<br> returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md) in other cases.|

### OH_IPCRemoteProxy_IsRemoteDead()

```C
int OH_IPCRemoteProxy_IsRemoteDead(const OHIPCRemoteProxy *proxy)
```

**Description**

Checks whether the **OHIPCRemoteStub** object corresponding to the **OHIPCRemoteProxy** object is dead.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object to check. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns **1** if the **OHIPCRemoteStub** object is dead or invalid parameters are found; returns **0** otherwise. If invalid parameters are found, the **OHIPCRemoteStub** object does not exist.|
