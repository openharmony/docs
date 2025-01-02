# OHIPCRemoteObject


## 概述

提供远端对象创建、销毁、数据发送、远端对象死亡状态监听等功能C接口。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ipc_cremote_object.h](ipc__cremote__object_8h.md) | 提供远端对象创建、销毁、数据发送、远端对象死亡状态监听等功能C接口。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) | IPC消息选项定义。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef int(\* [OH_OnRemoteRequestCallback](#oh_onremoterequestcallback)) (uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, void \*userData) | Stub端用于处理远端数据请求的回调函数。 | 
| typedef void(\* [OH_OnRemoteDestroyCallback](#oh_onremotedestroycallback)) (void \*userData) | Stub端用于监听对象销毁的回调函数。 | 
| typedef void(\* [OH_OnDeathRecipientCallback](#oh_ondeathrecipientcallback)) (void \*userData) | 远端OHIPCRemoteStub对象死亡通知的回调函数类型。 | 
| typedef void(\* [OH_OnDeathRecipientDestroyCallback](#oh_ondeathrecipientdestroycallback)) (void \*userData) | OHIPCDeathRecipient对象销毁回调函数类型。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_IPC_RequestMode](#oh_ipc_requestmode) { OH_IPC_REQUEST_MODE_SYNC = 0, OH_IPC_REQUEST_MODE_ASYNC = 1 } | IPC请求模式定义 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OHIPCRemoteStub \* [OH_IPCRemoteStub_Create](#oh_ipcremotestub_create) (const char \*descriptor, [OH_OnRemoteRequestCallback](#oh_onremoterequestcallback) requestCallback, [OH_OnRemoteDestroyCallback](#oh_onremotedestroycallback) destroyCallback, void \*userData) | 创建OHIPCRemoteStub对象。 | 
| void [OH_IPCRemoteStub_Destroy](#oh_ipcremotestub_destroy) (OHIPCRemoteStub \*stub) | 销毁OHIPCRemoteStub对象。 | 
| void [OH_IPCRemoteProxy_Destroy](#oh_ipcremoteproxy_destroy) (OHIPCRemoteProxy \*proxy) | 销毁OHIPCRemoteProxy对象。 | 
| int [OH_IPCRemoteProxy_SendRequest](#oh_ipcremoteproxy_sendrequest) (const OHIPCRemoteProxy \*proxy, uint32_t code, const OHIPCParcel \*data, OHIPCParcel \*reply, const [OH_IPC_MessageOption](_o_h___i_p_c___message_option.md) \*option) | IPC消息发送函数。 | 
| int [OH_IPCRemoteProxy_GetInterfaceDescriptor](#oh_ipcremoteproxy_getinterfacedescriptor) (OHIPCRemoteProxy \*proxy, char \*\*descriptor, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | 从Stub端获取接口描述符。 | 
| OHIPCDeathRecipient \* [OH_IPCDeathRecipient_Create](#oh_ipcdeathrecipient_create) ([OH_OnDeathRecipientCallback](#oh_ondeathrecipientcallback) deathRecipientCallback, [OH_OnDeathRecipientDestroyCallback](#oh_ondeathrecipientdestroycallback) destroyCallback, void \*userData) | 创建远端OHIPCRemoteStub对象死亡通知对象OHIPCDeathRecipient。 | 
| void [OH_IPCDeathRecipient_Destroy](#oh_ipcdeathrecipient_destroy) (OHIPCDeathRecipient \*recipient) | 销毁OHIPCDeathRecipient对象。 | 
| int [OH_IPCRemoteProxy_AddDeathRecipient](#oh_ipcremoteproxy_adddeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | 向OHIPCRemoteProxy对象添加死亡监听，用于接收远端OHIPCRemoteStub对象死亡的回调通知。 | 
| int [OH_IPCRemoteProxy_RemoveDeathRecipient](#oh_ipcremoteproxy_removedeathrecipient) (OHIPCRemoteProxy \*proxy, OHIPCDeathRecipient \*recipient) | 移除向OHIPCRemoteProxy对象已经添加的死亡监听。 | 
| int [OH_IPCRemoteProxy_IsRemoteDead](#oh_ipcremoteproxy_isremotedead) (const OHIPCRemoteProxy \*proxy) | 判断OHIPCRemoteProxy对象对应的远端OHIPCRemoteStub对象是否死亡。 | 


## 类型定义说明


### OH_OnDeathRecipientCallback

```
typedef void(* OH_OnDeathRecipientCallback) (void *userData)
```

**描述**

远端OHIPCRemoteStub对象死亡通知的回调函数类型。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userData | 用户私有数据指针，可以为空。 | 


### OH_OnDeathRecipientDestroyCallback

```
typedef void(* OH_OnDeathRecipientDestroyCallback) (void *userData)
```

**描述**

OHIPCDeathRecipient对象销毁回调函数类型。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userData | 用户私有数据指针，可以为空。 | 


### OH_OnRemoteDestroyCallback

```
typedef void(* OH_OnRemoteDestroyCallback) (void *userData)
```

**描述**

Stub端用于监听对象销毁的回调函数。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userData | 用户私有数据，可以为空。 | 


### OH_OnRemoteRequestCallback

```
typedef int(* OH_OnRemoteRequestCallback) (uint32_t code, const OHIPCParcel *data, OHIPCParcel *reply, void *userData)
```

**描述**

Stub端用于处理远端数据请求的回调函数。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| code | 用户自定义通讯命令字，范围:[0x01, 0x00ffffff]。 | 
| data | 请求数据对象指针，不会为空，函数内不允许释放。 | 
| reply | 回应数据对象指针，不会为空，函数内不允许释放。如果函数返回错误，该值不允许写入数据。 | 
| userData | 用户私有数据，可以为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

否则返回用户自定义错误码或系统错误码，自定义错误码范围:[1909001, 1909999]；

如果用户自定义错误码超出范围，将返回[OH_IPC_ErrorCode#OH_IPC_INVALID_USER_ERROR_CODE](_o_h_i_p_c_error_code.md)。


## 枚举类型说明


### OH_IPC_RequestMode

```
enum OH_IPC_RequestMode
```

**描述**

IPC请求模式定义

**起始版本：** 12

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_IPC_REQUEST_MODE_SYNC | 同步请求模式。 | 
| OH_IPC_REQUEST_MODE_ASYNC | 异步请求模式。 | 


## 函数说明


### OH_IPCDeathRecipient_Create()

```
OHIPCDeathRecipient* OH_IPCDeathRecipient_Create (OH_OnDeathRecipientCallback deathRecipientCallback, OH_OnDeathRecipientDestroyCallback destroyCallback, void * userData )
```

**描述**

创建远端OHIPCRemoteStub对象死亡通知对象OHIPCDeathRecipient。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deathRecipientCallback | 远端OHIPCRemoteStub对象死亡通知的回调处理函数，不能为空。 | 
| destroyCallback | 对象销毁回调处理函数，可以为空。 | 
| userData | 用户私有数据指针，可以为空。 | 

**返回：**

成功返回OHIPCDeathRecipient对象指针;否则返回NULL。


### OH_IPCDeathRecipient_Destroy()

```
void OH_IPCDeathRecipient_Destroy (OHIPCDeathRecipient * recipient)
```

**描述**

销毁OHIPCDeathRecipient对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| recipient | 要销毁的OHIPCDeathRecipient对象指针。 | 


### OH_IPCRemoteProxy_AddDeathRecipient()

```
int OH_IPCRemoteProxy_AddDeathRecipient (OHIPCRemoteProxy * proxy, OHIPCDeathRecipient * recipient )
```

**描述**

向OHIPCRemoteProxy对象添加死亡监听，用于接收远端OHIPCRemoteStub对象死亡的回调通知。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 需要添加死亡通知的OHIPCRemoteProxy对象指针，不能为空。 | 
| recipient | 用于接收远程对象死亡通知的死亡对象指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

其它[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCRemoteProxy_Destroy()

```
void OH_IPCRemoteProxy_Destroy (OHIPCRemoteProxy * proxy)
```

**描述**

销毁OHIPCRemoteProxy对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 要销毁的OHIPCRemoteProxy对象指针。 | 


### OH_IPCRemoteProxy_GetInterfaceDescriptor()

```
int OH_IPCRemoteProxy_GetInterfaceDescriptor (OHIPCRemoteProxy * proxy, char ** descriptor, int32_t * len, OH_IPC_MemAllocator allocator )
```

**描述**

从Stub端获取接口描述符。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | OHIPCRemoteProxy对象指针，不能为空。 | 
| descriptor | 用于存储描述符的内存地址，该内存由用户提供的分配器进行内存分配，用户使用完后需要主动释放，不能为空。 接口返回失败时，用户依然需要判断该内存是否为空，并主动释放，否则会造成内存泄漏。 | 
| len | 写入descriptor的数据长度，包含结束符，不能为空。 | 
| allocator | 用户指定的用来分配descriptor的内存分配器，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

远端OHIPCRemoteStub对象死亡返回[OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](_o_h_i_p_c_error_code.md)；

内存分配失败返回[OH_IPC_ErrorCode#OH_IPC_MEM_ALLOCATOR_ERROR](_o_h_i_p_c_error_code.md)；

序列化读失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCRemoteProxy_IsRemoteDead()

```
int OH_IPCRemoteProxy_IsRemoteDead (const OHIPCRemoteProxy * proxy)
```

**描述**

判断OHIPCRemoteProxy对象对应的远端OHIPCRemoteStub对象是否死亡。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 需要判断远端是否死亡的OHIPCRemoteProxy对象指针，不能为空。 | 

**返回：**

远端OHIPCRemoteStub对象死亡返回1; 否则，返回0。参数非法时，说明其远端OHIPCRemoteStub对象不存在，返回1。


### OH_IPCRemoteProxy_RemoveDeathRecipient()

```
int OH_IPCRemoteProxy_RemoveDeathRecipient (OHIPCRemoteProxy * proxy, OHIPCDeathRecipient * recipient )
```

**描述**

移除向OHIPCRemoteProxy对象已经添加的死亡监听。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | 需要移除死亡通知的OHIPCRemoteProxy对象指针，不能为空。 | 
| recipient | 用于接收远程对象死亡通知的死亡对象指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数错误返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

其它[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCRemoteProxy_SendRequest()

```
int OH_IPCRemoteProxy_SendRequest (const OHIPCRemoteProxy * proxy, uint32_t code, const OHIPCParcel * data, OHIPCParcel * reply, const OH_IPC_MessageOption * option )
```

**描述**

IPC消息发送函数。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| proxy | OHIPCRemoteProxy对象指针，不能为空。 | 
| code | 用户定义的IPC命令字，范围:[0x01,0x00ffffff]。 | 
| data | 请求数据对象指针，不能为空。 | 
| reply | 回应数据对象指针，同步请求时，不能为空；异步请求时，可以为空。 | 
| option | 消息选项指针，可以为空，为空时按同步处理。 | 

**返回：**

发送成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

远端OHIPCRemoteStub对象死亡返回[OH_IPC_ErrorCode#OH_IPC_DEAD_REMOTE_OBJECT](_o_h_i_p_c_error_code.md)；

code超出范围返回[OH_IPC_ErrorCode#OH_IPC_CODE_OUT_OF_RANGE](_o_h_i_p_c_error_code.md)；

其它返回[OH_IPC_ErrorCode#OH_IPC_INNER_ERROR](_o_h_i_p_c_error_code.md)或用户自定义错误码。


### OH_IPCRemoteStub_Create()

```
OHIPCRemoteStub* OH_IPCRemoteStub_Create (const char * descriptor, OH_OnRemoteRequestCallback requestCallback, OH_OnRemoteDestroyCallback destroyCallback, void * userData )
```

**描述**

创建OHIPCRemoteStub对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| descriptor | OHIPCRemoteStub对象描述符，不能为空。 | 
| requestCallback | 数据请求处理函数，不能为空。 | 
| destroyCallback | 对象销毁回调函数，可以为空。 | 
| userData | 用户私有数据，可以为空。 | 

**返回：**

成功返回OHIPCRemoteStub对象指针，否则返回NULL。


### OH_IPCRemoteStub_Destroy()

```
void OH_IPCRemoteStub_Destroy (OHIPCRemoteStub * stub)
```

**描述**

销毁OHIPCRemoteStub对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| stub | 要销毁的OHIPCRemoteStub对象指针。 | 
