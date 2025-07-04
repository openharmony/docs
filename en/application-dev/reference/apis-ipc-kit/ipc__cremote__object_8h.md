# ipc_cremote_object.h


## Overview

Provides C APIs for creating and destroying a remote object, transferring data, and observing the dead status of a remote object.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCRemoteObject](_o_h_i_p_c_remote_object.md)

**Header file**: [ipc_cremote_object.h](ipc__cremote__object_8h.md)

## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) | Defines an IPC message.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef int(\* [OH_OnRemoteRequestCallback](_o_h_i_p_c_remote_object.md#oh_onremoterequestcallback)) (uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, void \*userData) | Defines a callback used to process the remote data request at the stub.| 
| typedef void(\* [OH_OnRemoteDestroyCallback](_o_h_i_p_c_remote_object.md#oh_onremotedestroycallback)) (void \*userData) | Defines a callback to be invoked when an observed object of the stub is destroyed.| 
| typedef void(\* [OH_OnDeathRecipientCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientcallback)) (void \*userData) | Defines a callback to be invoked when the remote **OHIPCRemoteStub** object dies unexpectedly.| 
| typedef void(\* [OH_OnDeathRecipientDestroyCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientdestroycallback)) (void \*userData) | Defines a callback to be invoked when the **OHIPCDeathRecipient** object is destroyed.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_IPC_RequestMode](_o_h_i_p_c_remote_object.md#oh_ipc_requestmode) {<br>OH_IPC_REQUEST_MODE_SYNC = 0,<br>OH_IPC_REQUEST_MODE_ASYNC = 1<br>} | Enumerates the IPC request modes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| OHIPCRemoteStub \* [OH_IPCRemoteStub_Create](_o_h_i_p_c_remote_object.md#oh_ipcremotestub_create) (const char \*descriptor, [OH_OnRemoteRequestCallback](_o_h_i_p_c_remote_object.md#oh_onremoterequestcallback) requestCallback, [OH_OnRemoteDestroyCallback](_o_h_i_p_c_remote_object.md#oh_onremotedestroycallback) destroyCallback, void \*userData) | Creates an **OHIPCRemoteStub** object.| 
| void [OH_IPCRemoteStub_Destroy](_o_h_i_p_c_remote_object.md#oh_ipcremotestub_destroy) (OHIPCRemoteStub \*stub) | Destroys an **OHIPCRemoteStub** object.| 
| void [OH_IPCRemoteProxy_Destroy](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy) (OHIPCRemoteProxy \*proxy) | Destroys an **OHIPCRemoteProxy** object.| 
| int [OH_IPCRemoteProxy_SendRequest](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_sendrequest) (const OHIPCRemoteProxy \*proxy, uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, const [OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) \*option) | Sends an IPC message.| 
| int [OH_IPCRemoteProxy_GetInterfaceDescriptor](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_getinterfacedescriptor) (OHIPCRemoteProxy \*proxy, char \*\*descriptor, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | Obtains the interface descriptor from the stub.| 
| OHIPCDeathRecipient \* [OH_IPCDeathRecipient_Create](_o_h_i_p_c_remote_object.md#oh_ipcdeathrecipient_create) ([OH_OnDeathRecipientCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientcallback) deathRecipientCallback, [OH_OnDeathRecipientDestroyCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientdestroycallback) destroyCallback, void \*userData) | Creates an **OHIPCDeathRecipient** object, which triggers a notification when the **OHIPCRemoteStub** object dies unexpectedly.| 
| void [OH_IPCDeathRecipient_Destroy](_o_h_i_p_c_remote_object.md#oh_ipcdeathrecipient_destroy) (OHIPCDeathRecipient \*recipient) | Destroys an **OHIPCDeathRecipient** object.| 
| int [OH_IPCRemoteProxy_AddDeathRecipient](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_adddeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | Subscribes to the death of an **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.| 
| int [OH_IPCRemoteProxy_RemoveDeathRecipient](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_removedeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | Unsubscribes from the death of the **OHIPCRemoteStub** object for an **OHIPCRemoteProxy** object.| 
| int [OH_IPCRemoteProxy_IsRemoteDead](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_isremotedead) (const OHIPCRemoteProxy \*proxy) | Checks whether the **OHIPCRemoteStub** object corresponding to the **OHIPCRemoteProxy** object is dead.| 
