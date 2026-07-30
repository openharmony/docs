# ipc_cremote_object.h

<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--Designer: @zhaopeng_gitee-->
<!--Tester: @maxiaorong-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=9f8e1a64bd74ee011099413e1e72ea230f3c7180 translatedAt=2026-07-30T05:59:36.165Z pushedAt=2026-07-30T08:17:52.703Z -->

## Overview

This file provides C APIs for remote object creation, destruction, data sending, and remote object death status listening. These APIs are suitable for Inter-Process Communication (IPC) and Remote Procedure Call (RPC) communication scenarios.

For the corresponding development guide and samples, see [IPC and RPC Development (C/C++)](../../ipc/ipc-capi-development-guideline.md).

**File to include**: <IPCKit/ipc_cremote_object.h>

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCRemoteObject](capi-ohipcremoteobject.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [OH_IPC_MessageOption](capi-ohipcremoteobject-oh-ipc-messageoption.md) | - | Defines IPC message options.|
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) | OHIPCDeathRecipient | Defines an object that receives death notifications.|

### Enums

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [OH_IPC_RequestMode](#oh_ipc_requestmode) | OH_IPC_RequestMode | Enumerates the IPC request modes.|

### Functions

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [typedef int (\*OH_OnRemoteRequestCallback)(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)](#oh_onremoterequestcallback) | OH_OnRemoteRequestCallback | Defines the callback function used to process the remote data requests at the stub side.|
| [typedef void (\*OH_OnRemoteDestroyCallback)(void *userData)](#oh_onremotedestroycallback) | OH_OnRemoteDestroyCallback | Callback function used to listen for object destruction.|
| [OHIPCRemoteStub* OH_IPCRemoteStub_Create(const char *descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallback destroyCallback, void *userData)](#oh_ipcremotestub_create) | - | Creates an **OHIPCRemoteStub** object.|
| [void OH_IPCRemoteStub_Destroy(OHIPCRemoteStub *stub)](#oh_ipcremotestub_destroy) | - | Destroys an **OHIPCRemoteStub** object.|
| [void OH_IPCRemoteProxy_Destroy(OHIPCRemoteProxy *proxy)](#oh_ipcremoteproxy_destroy) | - | Destroys an **OHIPCRemoteProxy** object.|
| [int OH_IPCRemoteProxy_SendRequest(const OHIPCRemoteProxy *proxy, uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, const OH_IPC_MessageOption *option)](#oh_ipcremoteproxy_sendrequest) | - | Sends an IPC message.|
| [int OH_IPCRemoteProxy_GetInterfaceDescriptor(OHIPCRemoteProxy *proxy, char **descriptor, int32_t *len, OH_IPC_MemAllocator allocator)](#oh_ipcremoteproxy_getinterfacedescriptor) | - | Obtains the interface descriptor from the stub.|
| [typedef void (\*OH_OnDeathRecipientCallback)(void *userData)](#oh_ondeathrecipientcallback) | OH_OnDeathRecipientCallback | Defines the callback function for remote **OHIPCRemoteStub** object death notifications.|
| [typedef void (\*OH_OnDeathRecipientDestroyCallback)(void *userData)](#oh_ondeathrecipientdestroycallback) | OH_OnDeathRecipientDestroyCallback | Defines the callback function for **OHIPCDeathRecipient** object destruction. |
| [OHIPCDeathRecipient* OH_IPCDeathRecipient_Create(OH_OnDeathRecipientCallback deathRecipientCallback, OH_OnDeathRecipientDestroyCallback destroyCallback, void *userData)](#oh_ipcdeathrecipient_create) | - | Creates an **OHIPCDeathRecipient** object.|
| [void OH_IPCDeathRecipient_Destroy(OHIPCDeathRecipient *recipient)](#oh_ipcdeathrecipient_destroy) | - | Destroys an **OHIPCDeathRecipient** object.|
| [int OH_IPCRemoteProxy_AddDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)](#oh_ipcremoteproxy_adddeathrecipient) | - | Adds a death listener to the **OH_IPCRemoteProxy** object to receive callback notifications when the remote **OH_IPCRemoteStub** object dies.|
| [int OH_IPCRemoteProxy_RemoveDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)](#oh_ipcremoteproxy_removedeathrecipient) | - | Removes a previously added death listener from the **OH_IPCRemoteProxy** object.|
| [int OH_IPCRemoteProxy_IsRemoteDead(const OHIPCRemoteProxy *proxy)](#oh_ipcremoteproxy_isremotedead)| - | Checks whether the **OHIPCRemoteStub** object corresponding to the **OHIPCRemoteProxy** object is dead.|

## Enum Description

### OH_IPC_RequestMode

```C
enum OH_IPC_RequestMode
```

**Description**

Enumerates the IPC request modes. The synchronous request mode is suitable for scenarios where you need to wait for a response from the remote side. The asynchronous request mode is suitable for scenarios where you do not need to wait for a response or where you need to improve concurrent performance.

**Since**: 12

| Enum Item| Description|
| ------ | ---- |
| OH_IPC_REQUEST_MODE_SYNC = 0 | Synchronous request, which is suitable for scenarios where you need to wait for a return result, such as query operations and simple request-response scenarios. |
| OH_IPC_REQUEST_MODE_ASYNC = 1 | Asynchronous request, which is suitable for scenarios where you do not need to obtain the result immediately or where operations are time-consuming, such as large-data transmission and background processing. |

## Function Description

### OH_OnRemoteRequestCallback()

```C
typedef int(*OH_OnRemoteRequestCallback)(uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)
```

**Description**

Callback function used to process the remote data requests at the stub side. This callback is triggered when the proxy sends a request through [OH_IPCRemoteProxy_SendRequest](#oh_ipcremoteproxy_sendrequest). The callback is executed in the Binder thread pool. Therefore, pay attention to thread security. The callback should return as soon as possible to avoid long-time blocking. Otherwise, the processing of other IPC requests may be affected.

**Use cases**

- This function is used to receive and process cross-process requests from the client when the server implements a custom IPC communication protocol.

- When the server capabilities need to be called across processes, the server uses this callback to process the specific service logic.

- This function serves as the entry for message distribution and processing when the RPC server capability is implemented.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| uint32_t code | Custom IPC command word, in the range [0x01, 0x00ffffff]. It is advised to define code values in segments based on service modules to avoid conflicts between different functional commands. For example, 0x01 to 0x100 can be used for basic functions, and 0x101 to 0x200 for extended functions. |
| const [OHIPCParcel](capi-ohipcparcel.md) *data | Pointer to the requested data object. It cannot be NULL or released in the function. |
| [OHIPCParcel](capi-ohipcparcel.md) *reply | Pointer to the response data object. It cannot be NULL or released in the function. If this function returns an error, data cannot be written to this parameter. |
| void *userData | Pointer to user private data. Pass this parameter when user-defined data needs to be accessed in the callback. If user data does not need to be accessed, this parameter can be omitted or set to NULL. If this parameter is set to NULL, the callback function cannot access the user's private data. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the operation is successful.<br> Returns a custom error code in the range [1909001, 1909999] or a system error code otherwise.<br> If the custom error code is out of range, [OH_IPC_ErrorCode#OH_IPC_INVALID_USER_ERROR_CODE](capi-ipc-error-code-h.md#oh_ipc_errorcode) is returned.|

### OH_OnRemoteDestroyCallback()

```C
typedef void(*OH_OnRemoteDestroyCallback)(void *userData)
```

**Description**

Callback function used to listen for object destruction.

**Use cases**

- Release related resources (such as memory and file handles) when the stub object is destroyed.

- Notify other modules to synchronize the status when the object is destroyed.

- Clear private user data when the object is destroyed.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ----- | ----- |
| void *userData | User private data. This parameter is passed when user-defined data needs to be accessed in the callback function. If user data does not need to be accessed, this parameter can be set to NULL. If this parameter is not passed, the callback function cannot access the user's private data. |

### OH_IPCRemoteStub_Create()

```C
OHIPCRemoteStub* OH_IPCRemoteStub_Create(const char *descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallback destroyCallback, void *userData)
```

**Description**

Creates an **OHIPCRemoteStub** object, which is used on the stub side to create a server-side object for processing remote data requests from the proxy side.

**Use cases**

- When a server needs to provide cross-process service capabilities, it can create a stub object as the server-side entity.

- It can also be used to implement the server side of custom IPC communication protocols, building RPC server capabilities.

**Development suggestion**

- After the stub object is created, it is typically registered with the service manager through the **OH_IPCRemoteProxy** related APIs, so that the proxy side can discover and connect to it.

- It is recommended to create the Stub object when the app starts and destroy it when the app exits.

- **requestCallback** should avoid time-consuming operations, as they may block IPC communication.

- If time-consuming tasks need to be handled, you can return an error code in the callback and use a thread pool to process the tasks asynchronously.

- Ensure that the lifecycle of **userData** covers the lifecycle of the stub object to avoid dangling pointers.

**Pairing requirements**

- After the object is created via [OH_IPCRemoteStub_Create()](#oh_ipcremotestub_create), it must be destroyed using [OH_IPCRemoteStub_Destroy()](#oh_ipcremotestub_destroy) after use to release resources.

- Failure to destroy it may result in memory leaks.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const char *descriptor | Pointer to the descriptor of the **OHIPCRemoteStub** object to create. It cannot be NULL. The string length range is (0, 204800], in bytes. If the value is out of range, NULL is returned. You are advised to use a unique identifier string, for example, **com.example.myservice** or **MyService**. The format is typically a reverse domain name or a simple service name, used to identify different IPC service APIs. |
| [OH_OnRemoteRequestCallback](#oh_onremoterequestcallback) requestCallback | Data request processing function. It cannot be NULL. |
| [OH_OnRemoteDestroyCallback](#oh_onremotedestroycallback) destroyCallback | Callback function for object destruction. Pass this parameter when you need to perform cleanup operations (such as releasing **userData** resources) when the stub object is destroyed. If cleanup is not required, you can omit it or pass NULL. If not passed, no callback notifications will be triggered upon object destruction. |
| void *userData | User private data. This parameter is passed when user-defined data needs to be accessed in the callback function. If user data does not need to be accessed, this parameter can be set to NULL. If this parameter is set to NULL, the callback function cannot access the user's private data. |

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

**Use cases**

- Release the stub object when the server no longer needs to provide the IPC service.

- Clear IPC resources when the server exits or the module is uninstalled.

**Pairing requirements**

- This function and [OH_IPCRemoteStub_Create()](#oh_ipcremotestub_create) must be used in pairs.

- This method must be called when the stub object is no longer used.

- After the destruction, the **destroyCallback** callback is automatically triggered to release **userData**.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteStub](capi-ohipcparcel-ohipcremotestub.md) *stub | Pointer to the **OHIPCRemoteStub** object to destroy. It cannot be NULL. |

### OH_IPCRemoteProxy_Destroy()

```C
void OH_IPCRemoteProxy_Destroy(OHIPCRemoteProxy *proxy)
```

**Description**

Destroys an **OHIPCRemoteProxy** object.

**Use cases**

- Release the proxy object when the client no longer needs to call the remote service.

- Clear IPC resources when the client exits or the module is uninstalled.

**Destruction prerequisites**

- You **must** call [OH_IPCRemoteProxy_RemoveDeathRecipient()](#oh_ipcremoteproxy_removedeathrecipient) to remove all added death event listeners.

- If the proxy object is destroyed when the listeners are not removed, the death event listener callback will be abnormal or memory leakage will occur.

**Post-destruction restrictions**

- After the destruction, no method of the proxy can be called.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object to destroy. It cannot be NULL. |

### OH_IPCRemoteProxy_SendRequest()

```C
int OH_IPCRemoteProxy_SendRequest(const OHIPCRemoteProxy *proxy, uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, const OH_IPC_MessageOption *option)
```

**Description**

Sends an IPC message from the proxy to the remote stub. This function supports both synchronous and asynchronous communication modes.

**Use cases**

- When the client needs to call server capabilities across processes, it sends a request and receives a response.

- This function enables IPC communication between the client and the server.

- This function can call service APIs of the remote service.

**Development suggestion**

- The synchronous mode is suitable for requests that need to wait for a result, such as query operations, while the asynchronous mode is suitable for requests that do not need to wait for a result, such as log reporting.

- Synchronous calls block the current thread. Avoid using them in UI threads to prevent lag.

- Although asynchronous calls do not block the thread, you should still be mindful of the call frequency to avoid overloading the IPC channel.

- It is advised to check whether the remote side is alive using [OH_IPCRemoteProxy_IsRemoteDead()](#oh_ipcremoteproxy_isremotedead) before making a call.

- In case of call failure, it is advised to retry or perform error handling based on the returned error code.

- Frequent IPC calls may affect performance. It is advised to design the communication protocol properly to reduce the number of calls.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object. It cannot be NULL. |
| uint32_t code | Custom IPC command word, in the range [0x01, 0x00ffffff]. If the value is out of range, the **OH_IPC_CODE_OUT_OF_RANGE** error is returned. It is advised to define code values in segments based on service modules, and ensure that the same command word definitions are used on both the proxy side and the stub side. Different operations of the same service API should use distinct code values for identification. |
| const [OHIPCParcel](capi-ohipcparcel.md) *data | Pointer to the requested data object. It cannot be NULL. |
| [OHIPCParcel](capi-ohipcparcel.md) *reply | Pointer to the response data object. For a synchronous request, this parameter cannot be null and is used to store the response result. For an asynchronous request, this parameter can be null, in which case the response result is not stored. |
| const [OH_IPC_MessageOption](capi-ohipcremoteobject-oh-ipc-messageoption.md) *option | Pointer to the message option, which is used to configure the IPC message sending mode (synchronous/asynchronous). Pass this parameter when the asynchronous mode or custom message option is required. For asynchronous requests, the corresponding request mode must be passed and set. For synchronous requests, you may omit it or pass NULL. If omitted or NULL is passed, the synchronous mode (**OH_IPC_REQUEST_MODE_SYNC**) is used by default. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the message is sent successfully.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) if invalid parameters are found.<br> Returns [OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the remote **OHIPCRemoteStub** object dies.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CODE_OUT_OF_RANGE](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the code is out of range.<br> Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) or a custom error code (range: [1909001, 1909999]) in other cases. |

### OH_IPCRemoteProxy_GetInterfaceDescriptor()

```C
int OH_IPCRemoteProxy_GetInterfaceDescriptor(OHIPCRemoteProxy *proxy, char **descriptor, int32_t *len, OH_IPC_MemAllocator allocator)
```

**Description**

Obtains the interface descriptor from the Stub. The interface descriptor is the unique identifier of the Stub object, used to identify the remote service type. This function obtains the descriptor string from the remote Stub through an IPC call and stores the result using the memory allocator provided by the user.

**Memory management**

The memory for the returned descriptor string is allocated by the user-provided allocator. The user must actively release it after use to prevent memory leaks. Even if the function call fails, you should still check whether the descriptor is not NULL and release it accordingly.

**Use cases**

- When the interface type of the remote service needs to be identified.

- When service version compatibility check is required.

- When it is necessary to verify whether the remote service implements a specific interface.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object. It cannot be NULL. |
| char **descriptor | Pointer to the address of the memory for holding the interface descriptor. The memory is allocated by the allocator provided by the user and needs to be released. This pointer cannot be NULL. If an error code is returned, you still need to check whether the memory is empty and release the memory. Otherwise, memory leaks may occur. You are advised to release it immediately after use to prevent memory leaks. |
| int32_t *len | Pointer to the length of the data written to the descriptor, including the terminator. It cannot be NULL. |
| [OH_IPC_MemAllocator](capi-ipc-cparcel-h.md#oh_ipc_memallocator) allocator | Memory allocator specified by the user for allocating memory. It cannot be NULL. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the message is sent successfully.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the parameters are incorrect.<br> Returns [OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the remote **OHIPCRemoteStub** object dies.<br> Returns [OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the memory allocation fails.<br> Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) or a custom error code if the data in the serialized object fails to be read.|

### OH_OnDeathRecipientCallback()

```C
typedef void (*OH_OnDeathRecipientCallback)(void *userData)
```

**Description**

Callback function type for the death notification of the remote **OH_IPCRemoteStub** object. When the process hosting the remote stub object exits abnormally or is killed by the system, this callback is triggered to notify the client. The callback is executed in the Binder thread. Pay attention to thread safety. It is advised not to perform complex IPC operations in the callback to avoid potential deadlock risks.

**Use cases**

- When the client needs to detect abnormal exit or crash of the server.

- When resource cleanup or state reset is required upon the death of the server object.

- When it is necessary to implement server liveness monitoring and fault recovery mechanisms.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| void *userData | Pointer to user private data. Pass this parameter when user-defined data needs to be accessed in the death notification callback. If user data does not need to be accessed, this parameter can be omitted or set to NULL. If this parameter is set to NULL, the callback function cannot access the user's private data. |

### OH_OnDeathRecipientDestroyCallback()

```C
typedef void (*OH_OnDeathRecipientDestroyCallback)(void *userData)
```

**Description**

Defines a callback to be invoked when the **OHIPCDeathRecipient** object is destroyed.

**Use cases**

- When user private data needs to be released upon the destruction of the death listener object.

- When resources related to death listening need to be cleaned up.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| void *userData | Pointer to user private data. Pass this parameter when user-defined data needs to be accessed in the death notification callback. If user data does not need to be accessed, this parameter can be omitted or set to NULL. If this parameter is set to NULL, the callback function cannot access the user's private data. |

### OH_IPCDeathRecipient_Create()

```C
OHIPCDeathRecipient* OH_IPCDeathRecipient_Create(OH_OnDeathRecipientCallback deathRecipientCallback, OH_OnDeathRecipientDestroyCallback destroyCallback, void *userData)
```

**Description**

Creates an **OHIPCDeathRecipient** object for the death notification of the remote **OHIPCRemoteStub** object. It is used to listen for the death status of the remote Stub object.

**Use cases**

- When the client needs to listen for the death event of the server object.

- When it is necessary to implement a mechanism for detecting abnormal exit of the server.

- When fault handling or automatic reconnection is required upon server crash.

**Development suggestion**

- The death callback is triggered when the remote Stub object is destroyed or the process crashes. It is advised to release related resources, reset state, and attempt reconnection in the callback.

- The death callback may be executed on any thread, so thread safety must be taken into account. Avoid performing time-consuming operations in the callback.

- It is recommended not to destroy the [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) object directly in the callback. Destruction should be performed outside the callback.

- Multiple proxies can share the same [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) object. Ensure that it is removed from all proxies before destruction.

- If the proxy is already dead, adding a death listener will immediately trigger the callback. Therefore, you need to check the status before adding the listener.

- It is recommended that you create and add a death listener during application initialization, and remove and destroy it when the application exits.

**Pairing requirements**

- After creation, the object must be added to the proxy object via [OH_IPCRemoteProxy_AddDeathRecipient()](#oh_ipcremoteproxy_adddeathrecipient).

- When the listener is no longer needed, you must first remove it via [OH_IPCRemoteProxy_RemoveDeathRecipient()](#oh_ipcremoteproxy_removedeathrecipient).

- After removal, the object must be destroyed by calling [OH_IPCDeathRecipient_Destroy()](#oh_ipcdeathrecipient_destroy).

**Usage flow**

Create → AddDeathRecipient → (In Use) → RemoveDeathRecipient → Destroy

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OH_OnDeathRecipientCallback](#oh_ondeathrecipientcallback) deathRecipientCallback | Callback function for **OHIPCRemoteStub** object death notifications. It cannot be NULL. |
| [OH_OnDeathRecipientDestroyCallback](#oh_ondeathrecipientdestroycallback) destroyCallback | Callback function for object destruction. It can be NULL. If this parameter is NULL, the object destruction event is not listened to. Pass this parameter when you need to perform cleanup operations (such as releasing **userData** resources) when the **OHIPCDeathRecipient** object is destroyed. If cleanup is not required, you can omit it or pass NULL. If this parameter is not passed, no callback notifications will be triggered upon object destruction. |
| void *userData | Pointer to the user private data. It can be NULL. |

**Returns**

| Type| Description|
| ---- | ---- |
| OHIPCDeathRecipient* | Pointer to the **OHIPCDeathRecipient** object created if the operation is successful. Otherwise, NULL is returned.|

### OH_IPCDeathRecipient_Destroy()

```C
void OH_IPCDeathRecipient_Destroy(OHIPCDeathRecipient *recipient)
```

**Description**

Destroys an **OHIPCDeathRecipient** object.

**Use cases**

- Listening for the death event of the remote object is no longer required.

- When the client exits or the module is unloaded, clean up death listening resources.

**Pairing requirements**

- This function and [OH_IPCDeathRecipient_Create()](#oh_ipcdeathrecipient_create) must be used in pairs.

**Destruction prerequisites**

- You must call [OH_IPCRemoteProxy_RemoveDeathRecipient()](#oh_ipcremoteproxy_removedeathrecipient) to remove the listener object from all proxies before destroying it.

- Destroying without removing the listener may cause callback exceptions.

**Destruction timing**

- Destroy the death listening object when it is no longer needed.

- After the destruction, **destroyCallback** is automatically triggered to release **userData**.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) *recipient | Pointer to the **OHIPCDeathRecipient** object to destroy. It cannot be NULL. |

### OH_IPCRemoteProxy_AddDeathRecipient()

```C
int OH_IPCRemoteProxy_AddDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)
```

**Description**

Subscribes to the death of an **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.

**Use cases:**

- After the client starts, register the server death listener to detect server exceptions in a timely manner.

- Implement server fault detection and automatic recovery mechanisms.

- Release related resources or notify the user in a timely manner when the server becomes unavailable.

**Pairing requirements**

- After the death listener is added, you need to call [OH_IPCRemoteProxy_RemoveDeathRecipient()](#oh_ipcremoteproxy_removedeathrecipient) to remove the listener before destroying the proxy or recipient.

- Destroying the listener object without removing it first may cause callback exceptions or memory leaks.

**Usage sequence**

1. First call [OH_IPCDeathRecipient_Create()](#oh_ipcdeathrecipient_create) to create a listener object.

2. Call [OH_IPCRemoteProxy_AddDeathRecipient()](#oh_ipcremoteproxy_adddeathrecipient) to add a listener.

3. The listener callback will be triggered during use.

4. Call [OH_IPCRemoteProxy_RemoveDeathRecipient()](#oh_ipcremoteproxy_removedeathrecipient) to remove the listener.

5. Call [OH_IPCDeathRecipient_Destroy()](#oh_ipcdeathrecipient_destroy) to destroy the listener object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object to which the death notification is to be added. It cannot be NULL. |
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) *recipient | Pointer to the death recipient object used to receive death notifications of the remote object. It cannot be NULL. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the operation is successful.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the parameters are incorrect.<br> Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) in other cases.|

### OH_IPCRemoteProxy_RemoveDeathRecipient()

```C
int OH_IPCRemoteProxy_RemoveDeathRecipient(OHIPCRemoteProxy *proxy, OHIPCDeathRecipient *recipient)
```

**Description**

Unsubscribes from the death of the **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.

**Use cases**

- Unregister the death listener when it is no longer needed to listen for the death event of the remote object.

- Remove the old death listener when switching to another service instance.

**Next steps**

- If a listener object is no longer needed, call [OH_IPCDeathRecipient_Destroy()](#oh_ipcdeathrecipient_destroy) to destroy it.

- Failure to destroy it may result in memory leaks.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object from which the death notification needs to be removed. It cannot be NULL. |
| [OHIPCDeathRecipient](capi-ohipcremoteobject-ohipcdeathrecipient.md) *recipient | Pointer to the death recipient object used to receive death notifications of the remote object. It cannot be NULL. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the operation is successful.<br> Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) if the parameters are incorrect.<br> Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](capi-ipc-error-code-h.md#oh_ipc_errorcode) in other cases.|

### OH_IPCRemoteProxy_IsRemoteDead()

```C
int OH_IPCRemoteProxy_IsRemoteDead(const OHIPCRemoteProxy *proxy)
```

**Description**

Checks whether the **OHIPCRemoteStub** object corresponding to the **OHIPCRemoteProxy** object is dead.

**Usage cases**

- Before sending an IPC request, proactively check whether the server is alive.

- In the reconnection mechanism, determine whether the connection needs to be re-established.

- Adopt different handling strategies in service logic based on the server's liveness status.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object to check. It cannot be NULL. |

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns **1** if the remote **OH_IPCRemoteStub** object is dead; otherwise, returns **0**. If the parameter is invalid, it indicates that the remote **OH_IPCRemoteStub** object does not exist, and **1** is returned.|