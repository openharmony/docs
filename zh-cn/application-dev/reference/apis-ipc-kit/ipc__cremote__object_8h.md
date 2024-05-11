# ipc_cremote_object.h


## 概述

提供远端对象创建、销毁、数据发送、远端对象死亡状态监听等功能C接口。

**库：** libipc_capi.so

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**相关模块：**[OHIPCRemoteObject](_o_h_i_p_c_remote_object.md)


## 汇总


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) | IPC消息选项定义。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef int(\* [OH_OnRemoteRequestCallback](_o_h_i_p_c_remote_object.md#oh_onremoterequestcallback)) (uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, void \*userData) | Stub端用于处理远端数据请求的回调函数。 | 
| typedef void(\* [OH_OnRemoteDestroyCallback](_o_h_i_p_c_remote_object.md#oh_onremotedestroycallback)) (void \*userData) | Stub端用于监听对象销毁的回调函数。 | 
| typedef void(\* [OH_OnDeathRecipientCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientcallback)) (void \*userData) | 远端OHIPCRemoteStub对象死亡通知的回调函数类型。 | 
| typedef void(\* [OH_OnDeathRecipientDestroyCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientdestroycallback)) (void \*userData) | OHIPCDeathRecipient对象销毁回调函数类型。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| OH_IPC_RequestMode {<br/>[OH_IPC_REQUEST_MODE_SYNC](_o_h_i_p_c_remote_object.md) = 0,<br/>[OH_IPC_REQUEST_MODE_ASYNC](_o_h_i_p_c_remote_object.md) = 1<br/>} | IPC请求模式定义。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OHIPCRemoteStub \* [OH_IPCRemoteStub_Create](_o_h_i_p_c_remote_object.md#oh_ipcremotestub_create) (const char \*descriptor, [OH_OnRemoteRequestCallback](_o_h_i_p_c_remote_object.md#oh_onremoterequestcallback) requestCallback, [OH_OnRemoteDestroyCallback](_o_h_i_p_c_remote_object.md#oh_onremotedestroycallback) destroyCallback, void \*userData) | 创建OHIPCRemoteStub对象。 | 
| void [OH_IPCRemoteStub_Destroy](_o_h_i_p_c_remote_object.md#oh_ipcremotestub_destroy) (OHIPCRemoteStub \*stub) | 销毁OHIPCRemoteStub对象。 | 
| void [OH_IPCRemoteProxy_Destroy](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_destroy) (OHIPCRemoteProxy \*proxy) | 销毁OHIPCRemoteProxy对象。 | 
| int [OH_IPCRemoteProxy_SendRequest](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_sendrequest) (const OHIPCRemoteProxy \*proxy, uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, const [OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) \*option) | IPC消息发送函数。 | 
| int [OH_IPCRemoteProxy_GetInterfaceDescriptor](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_getinterfacedescriptor) (OHIPCRemoteProxy \*proxy, char \*\*descriptor, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | 从Stub端获取接口描述符。 | 
| OHIPCDeathRecipient \* [OH_IPCDeathRecipient_Create](_o_h_i_p_c_remote_object.md#oh_ipcdeathrecipient_create) ([OH_OnDeathRecipientCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientcallback) deathRecipientCallback, [OH_OnDeathRecipientDestroyCallback](_o_h_i_p_c_remote_object.md#oh_ondeathrecipientdestroycallback) destroyCallback, void \*userData) | 创建远端OHIPCRemoteStub对象死亡通知对象OHIPCDeathRecipient。 | 
| void [OH_IPCDeathRecipient_Destroy](_o_h_i_p_c_remote_object.md#oh_ipcdeathrecipient_destroy) (OHIPCDeathRecipient \*recipient) | 销毁OHIPCDeathRecipient对象。 | 
| int [OH_IPCRemoteProxy_AddDeathRecipient](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_adddeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | 向OHIPCRemoteProxy对象添加死亡监听，用于接收远端OHIPCRemoteStub对象死亡的回调通知。 | 
| int [OH_IPCRemoteProxy_RemoveDeathRecipient](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_removedeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | 移除向OHIPCRemoteProxy对象已经添加的死亡监听。 | 
| int [OH_IPCRemoteProxy_IsRemoteDead](_o_h_i_p_c_remote_object.md#oh_ipcremoteproxy_isremotedead) (const OHIPCRemoteProxy \*proxy) | 判断OHIPCRemoteProxy对象对应的远端OHIPCRemoteStub对象是否死亡。 | 
