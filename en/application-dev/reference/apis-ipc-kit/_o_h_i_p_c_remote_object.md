# OHIPCRemoteObject


## Overview

Provides C interfaces for creating and destroying a remote object, transferring data, and observing the dead status of a remote object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [ipc_cremote_object.h](ipc__cremote__object_8h.md) | Provides C interfaces for creating and destroying a remote object, transferring data, and observing the dead status of a remote object.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) | Defines an IPC message.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef int(\* [OH_OnRemoteRequestCallback](#oh_onremoterequestcallback)) (uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, void \*userData) | Defines a callback used to process the remote data request at the stub.| 
| typedef void(\* [OH_OnRemoteDestroyCallback](#oh_onremotedestroycallback)) (void \*userData) | Defines a callback to be invoked when an observed object of the stub is destroyed.| 
| typedef void(\* [OH_OnDeathRecipientCallback](#oh_ondeathrecipientcallback)) (void \*userData) | Defines a callback to be invoked when the remote **OHIPCRemoteStub** object dies unexpectedly.| 
| typedef void(\* [OH_OnDeathRecipientDestroyCallback](#oh_ondeathrecipientdestroycallback)) (void \*userData) | Defines a callback to be invoked when the **OHIPCDeathRecipient** object is destroyed.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_IPC_RequestMode](#oh_ipc_requestmode) { OH_IPC_REQUEST_MODE_SYNC = 0, OH_IPC_REQUEST_MODE_ASYNC = 1 } | Enumerates the IPC request modes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| OHIPCRemoteStub \* [OH_IPCRemoteStub_Create](#oh_ipcremotestub_create) (const char \*descriptor, [OH_OnRemoteRequestCallback](#oh_onremoterequestcallback) requestCallback, [OH_OnRemoteDestroyCallback](#oh_onremotedestroycallback) destroyCallback, void \*userData) | Creates an **OHIPCRemoteStub** object.| 
| void [OH_IPCRemoteStub_Destroy](#oh_ipcremotestub_destroy) (OHIPCRemoteStub \*stub) | Destroys an **OHIPCRemoteStub** object.| 
| void [OH_IPCRemoteProxy_Destroy](#oh_ipcremoteproxy_destroy) (OHIPCRemoteProxy \*proxy) | Destroys an **OHIPCRemoteProxy** object.| 
| int [OH_IPCRemoteProxy_SendRequest](#oh_ipcremoteproxy_sendrequest) (const OHIPCRemoteProxy \*proxy, uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, const [OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) \*option) | Sends an IPC message.| 
| int [OH_IPCRemoteProxy_GetInterfaceDescriptor](#oh_ipcremoteproxy_getinterfacedescriptor) (OHIPCRemoteProxy \*proxy, char \*\*descriptor, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | Obtains the interface descriptor from the stub.| 
| OHIPCDeathRecipient \* [OH_IPCDeathRecipient_Create](#oh_ipcdeathrecipient_create) ([OH_OnDeathRecipientCallback](#oh_ondeathrecipientcallback) deathRecipientCallback, [OH_OnDeathRecipientDestroyCallback](#oh_ondeathrecipientdestroycallback) destroyCallback, void \*userData) | Creates an **OHIPCDeathRecipient** object, which triggers a notification when the **OHIPCRemoteStub** object dies unexpectedly.| 
| void [OH_IPCDeathRecipient_Destroy](#oh_ipcdeathrecipient_destroy) (OHIPCDeathRecipient \*recipient) | Destroys an **OHIPCDeathRecipient** object.| 
| int [OH_IPCRemoteProxy_AddDeathRecipient](#oh_ipcremoteproxy_adddeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | Subscribes to the death of an **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.| 
| int [OH_IPCRemoteProxy_RemoveDeathRecipient](#oh_ipcremoteproxy_removedeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | Unsubscribes from the death of the **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.| 
| int [OH_IPCRemoteProxy_IsRemoteDead](#oh_ipcremoteproxy_isremotedead) (const OHIPCRemoteProxy \*proxy) | Checks whether the **OHIPCRemoteStub** object corresponding to the **OHIPCRemoteProxy** object is dead.| 


## Type Description


### OH_OnDeathRecipientCallback

```
typedef void(* OH_OnDeathRecipientCallback) (void *userData)
```

**Description**

Defines a callback to be invoked when the remote **OHIPCRemoteStub** object dies unexpectedly.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| userData | Pointer to the private user data. It can be NULL.| 


### OH_OnDeathRecipientDestroyCallback

```
typedef void(* OH_OnDeathRecipientDestroyCallback) (void *userData)
```

**Description**

Defines a callback to be invoked when the **OHIPCDeathRecipient** object is destroyed.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| userData | Pointer to the private user data. It can be NULL.| 


### OH_OnRemoteDestroyCallback

```
typedef void(* OH_OnRemoteDestroyCallback) (void *userData)
```

**Description**

Defines a callback to be invoked when an observed object of the stub is destroyed.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| userData | Pointer to the private user data. It can be NULL.| 


### OH_OnRemoteRequestCallback

```
typedef int(* OH_OnRemoteRequestCallback) (uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)
```

**Description**

Defines a callback used to process the remote data request at the stub.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| code | Customized communication command word. <br>Value range: [0x01, 0x00ffffff]| 
| data | Pointer to the requested data object. It cannot be NULL or released in the function.| 
| reply | Pointer to the requested data object. It cannot be NULL or released in the function. If this function returns an error, data cannot be written to this parameter.| 
| userData | Pointer to the private user data. It can be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful;

returns a custom error code in the range [1909001, 1909999] or a system error code otherwise.

Returns [OH_IPC_ErrorCode#OH_IPC_INVALID_USER_ERROR_CODE](_o_h_i_p_c_error_code.md) if the custom error code is out of range. 


## Enum Description


### OH_IPC_RequestMode

```
enum OH_IPC_RequestMode
```

**Description**

Enumerates the IPC request modes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_IPC_REQUEST_MODE_SYNC | Synchronous request.| 
| OH_IPC_REQUEST_MODE_ASYNC | Asynchronous request.| 


## Function Description


### OH_IPCDeathRecipient_Create()

```
OHIPCDeathRecipient* OH_IPCDeathRecipient_Create (OH_OnDeathRecipientCallback deathRecipientCallback, OH_OnDeathRecipientDestroyCallback destroyCallback, void * userData)
```

**Description**

Creates an **OHIPCDeathRecipient** object, which triggers a notification when the **OHIPCRemoteStub** object dies unexpectedly.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| deathRecipientCallback | Callback to be invoked when the **OHIPCRemoteStub** object is dead. It cannot be NULL.| 
| destroyCallback | Callback to be invoked when the object is destroyed. It can be NULL.| 
| userData | Pointer to the private user data. It can be NULL.| 

**Returns**

Returns the pointer to the **OHIPCDeathRecipient** object created if the operation is successful; returns NULL otherwise.


### OH_IPCDeathRecipient_Destroy()

```
void OH_IPCDeathRecipient_Destroy (OHIPCDeathRecipient * recipient)
```

**Description**

Destroys an **OHIPCDeathRecipient** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| recipient | Pointer to the **OHIPCDeathRecipient** object to destroy.| 


### OH_IPCRemoteProxy_AddDeathRecipient()

```
int OH_IPCRemoteProxy_AddDeathRecipient (OHIPCRemoteProxy * proxy, OHIPCDeathRecipient * recipient)
```

**Description**

Subscribes to the death of an **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the **OHIPCRemoteProxy** object that subscribes to the death notification. It cannot be NULL.| 
| recipient | Pointer to the object that receives the death notification of the **OHIPCRemoteStub** object. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if incorrect parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md) in other cases.


### OH_IPCRemoteProxy_Destroy()

```
void OH_IPCRemoteProxy_Destroy (OHIPCRemoteProxy * proxy)
```

**Description**

Destroys an **OHIPCRemoteProxy** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the **OHIPCRemoteProxy** object to destroy.| 


### OH_IPCRemoteProxy_GetInterfaceDescriptor()

```
int OH_IPCRemoteProxy_GetInterfaceDescriptor (OHIPCRemoteProxy * proxy, char ** descriptor, int32_t * len, OH_IPC_MemAllocator allocator)
```

**Description**

Obtains the interface descriptor from the stub.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the **OHIPCRemoteProxy** object. It cannot be NULL.| 
| descriptor | Pointer to the address of the memory for holding the interface descriptor. The memory is allocated by the allocator provided by the user and needs to be released. This pointer cannot be NULL. If an error code is returned, you still need to check whether the memory is empty and release the memory. Otherwise, memory leaks may occur.| 
| len | Pointer to the length of the data written to the descriptor, including the terminator. It cannot be NULL.| 
| allocator | Memory allocator specified by the user for allocating memory. It cannot be empty.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if incorrect parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](_o_h_i_p_c_error_code.md) if the remote **OHIPCRemoteStub** object is dead. 

Returns [OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](_o_h_i_p_c_error_code.md) if memory allocation fails.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the data in the serialized object failed to be read.


### OH_IPCRemoteProxy_IsRemoteDead()

```
int OH_IPCRemoteProxy_IsRemoteDead (const OHIPCRemoteProxy * proxy)
```

**Description**

Checks whether the **OHIPCRemoteStub** object corresponding to the **OHIPCRemoteProxy** object is dead.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the **OHIPCRemoteProxy** object to check. It cannot be NULL.| 

**Returns**

Returns **1** if the **OHIPCRemoteStub** object is dead or invalid parameters are found; returns **0** otherwise. If invalid parameters are found, the **OHIPCRemoteStub** object does not exist.


### OH_IPCRemoteProxy_RemoveDeathRecipient()

```
int OH_IPCRemoteProxy_RemoveDeathRecipient (OHIPCRemoteProxy * proxy, OHIPCDeathRecipient * recipient)
```

**Description**

Unsubscribes from the death of the **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the **OHIPCRemoteProxy** object that unsubscribes from the death notification. It cannot be NULL.| 
| recipient | Pointer to the object that receives the death notification of the **OHIPCRemoteStub** object. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if incorrect parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md) in other cases.


### OH_IPCRemoteProxy_SendRequest()

```
int OH_IPCRemoteProxy_SendRequest (const OHIPCRemoteProxy * proxy, uint32_t code, const OHIPCParcel * data, OHIPCParcel * reply, const OH_IPC_MessageOption * option)
```

**Description**

Sends an IPC message.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| proxy | Pointer to the **OHIPCRemoteProxy** object. It cannot be NULL.| 
| code | Customized IPC command word, in the range [0x01, 0x00ffffff].| 
| data | Pointer to the requested data object. It cannot be NULL.| 
| reply | Pointer to the response data object. It cannot be NULL in the case of a synchronous request, and can be NULL in the case of an asynchronous request.| 
| option | Pointer to the message option. It can be NULL, which indicates a synchronous request.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](_o_h_i_p_c_error_code.md) if the remote **OHIPCRemoteStub** object is dead. 

Returns [OH_IPC_ErrorCode#OH_IPC_CODE_OUT_OF_RANGE](_o_h_i_p_c_error_code.md) if the code is out of range.

Returns [OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md) or a custom error code in other cases.


### OH_IPCRemoteStub_Create()

```
OHIPCRemoteStub* OH_IPCRemoteStub_Create (const char * descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallback destroyCallback, void * userData)
```

**Description**

Creates an **OHIPCRemoteStub** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| descriptor | Pointer to the descriptor of the **OHIPCRemoteStub** object to create. It cannot be NULL.| 
| requestCallback | Callback used to process the data request. It cannot be NULL.| 
| destroyCallback | Callback to be invoked when the object is destroyed. It can be NULL.| 
| userData | Pointer to the private user data. It can be NULL.| 

**Returns**

Returns the pointer to the **OHIPCRemoteStub** object created if the operation is successful; returns NULL otherwise.


### OH_IPCRemoteStub_Destroy()

```
void OH_IPCRemoteStub_Destroy (OHIPCRemoteStub * stub)
```

**Description**

Destroys an **OHIPCRemoteStub** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| stub | Pointer to the **OHIPCRemoteStub** object to destroy.| 
