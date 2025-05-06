# OHIPCParcel


## 概述

提供IPC序列化/反序列化C接口。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [ipc_cparcel.h](ipc__cparcel_8h.md) | 提供IPC序列化/反序列化C接口。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void \*(\* [OH_IPC_MemAllocator](#oh_ipc_memallocator)) (int32_t len) | 内存分配函数类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OHIPCParcel \* [OH_IPCParcel_Create](#oh_ipcparcel_create) (void) | 创建OHIPCParcel对象，对象可序列化大小不能超过204800字节。 | 
| void [OH_IPCParcel_Destroy](#oh_ipcparcel_destroy) (OHIPCParcel \*parcel) | 销毁OHIPCParcel对象。 | 
| int [OH_IPCParcel_GetDataSize](#oh_ipcparcel_getdatasize) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象包含的数据的大小。 | 
| int [OH_IPCParcel_GetWritableBytes](#oh_ipcparcel_getwritablebytes) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象可以写入的字节数。 | 
| int [OH_IPCParcel_GetReadableBytes](#oh_ipcparcel_getreadablebytes) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象还可以读取的字节数。 | 
| int [OH_IPCParcel_GetReadPosition](#oh_ipcparcel_getreadposition) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象当前读取位置。 | 
| int [OH_IPCParcel_GetWritePosition](#oh_ipcparcel_getwriteposition) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象当前写入位置。 | 
| int [OH_IPCParcel_RewindReadPosition](#oh_ipcparcel_rewindreadposition) (OHIPCParcel \*parcel, uint32_t newReadPos) | 重置OHIPCParcel对象读取位置。 | 
| int [OH_IPCParcel_RewindWritePosition](#oh_ipcparcel_rewindwriteposition) (OHIPCParcel \*parcel, uint32_t newWritePos) | 重置OHIPCParcel对象写入位置。 | 
| int [OH_IPCParcel_WriteInt8](#oh_ipcparcel_writeint8) (OHIPCParcel \*parcel, int8_t value) | 向OHIPCParcel对象写入int8_t值。 | 
| int [OH_IPCParcel_ReadInt8](#oh_ipcparcel_readint8) (const OHIPCParcel \*parcel, int8_t \*value) | 从OHIPCParcel对象读取int8_t值。 | 
| int [OH_IPCParcel_WriteInt16](#oh_ipcparcel_writeint16) (OHIPCParcel \*parcel, int16_t value) | 向OHIPCParcel对象写入int16_t值。 | 
| int [OH_IPCParcel_ReadInt16](#oh_ipcparcel_readint16) (const OHIPCParcel \*parcel, int16_t \*value) | 从OHIPCParcel对象读取int16_t值。 | 
| int [OH_IPCParcel_WriteInt32](#oh_ipcparcel_writeint32) (OHIPCParcel \*parcel, int32_t value) | 向OHIPCParcel对象写入int32_t值。 | 
| int [OH_IPCParcel_ReadInt32](#oh_ipcparcel_readint32) (const OHIPCParcel \*parcel, int32_t \*value) | 从OHIPCParcel对象读取int32_t值。 | 
| int [OH_IPCParcel_WriteInt64](#oh_ipcparcel_writeint64) (OHIPCParcel \*parcel, int64_t value) | 向OHIPCParcel对象写入int64_t值。 | 
| int [OH_IPCParcel_ReadInt64](#oh_ipcparcel_readint64) (const OHIPCParcel \*parcel, int64_t \*value) | 从OHIPCParcel对象读取int64_t值。 | 
| int [OH_IPCParcel_WriteFloat](#oh_ipcparcel_writefloat) (OHIPCParcel \*parcel, float value) | 向OHIPCParcel对象写入float值。 | 
| int [OH_IPCParcel_ReadFloat](#oh_ipcparcel_readfloat) (const OHIPCParcel \*parcel, float \*value) | 从OHIPCParcel对象读取float值。 | 
| int [OH_IPCParcel_WriteDouble](#oh_ipcparcel_writedouble) (OHIPCParcel \*parcel, double value) | 向OHIPCParcel对象写入double值。 | 
| int [OH_IPCParcel_ReadDouble](#oh_ipcparcel_readdouble) (const OHIPCParcel \*parcel, double \*value) | 从OHIPCParcel对象读取double值。 | 
| int [OH_IPCParcel_WriteString](#oh_ipcparcel_writestring) (OHIPCParcel \*parcel, const char \*str) | 向OHIPCParcel对象写入字符串，包含字符串结束符。 | 
| const char \* [OH_IPCParcel_ReadString](#oh_ipcparcel_readstring) (const OHIPCParcel \*parcel) | 从OHIPCParcel对象读取字符串，用户可通过strlen获取字符串长度。 | 
| int [OH_IPCParcel_WriteBuffer](#oh_ipcparcel_writebuffer) (OHIPCParcel \*parcel, const uint8_t \*buffer, int32_t len) | 向OHIPCParcel对象写入指定长度的内存信息。 | 
| const uint8_t \* [OH_IPCParcel_ReadBuffer](#oh_ipcparcel_readbuffer) (const OHIPCParcel \*parcel, int32_t len) | 从OHIPCParcel对象读取指定长度内存信息。 | 
| int [OH_IPCParcel_WriteRemoteStub](#oh_ipcparcel_writeremotestub) (OHIPCParcel \*parcel, const OHIPCRemoteStub \*stub) | 向OHIPCParcel对象写入OHIPCRemoteStub对象。 | 
| OHIPCRemoteStub \* [OH_IPCParcel_ReadRemoteStub](#oh_ipcparcel_readremotestub) (const OHIPCParcel \*parcel) | 从OHIPCParcel对象读取OHIPCRemoteStub对象。 | 
| int [OH_IPCParcel_WriteRemoteProxy](#oh_ipcparcel_writeremoteproxy) (OHIPCParcel \*parcel, const OHIPCRemoteProxy \*proxy) | 向OHIPCParcel对象写入OHIPCRemoteProxy对象。 | 
| OHIPCRemoteProxy \* [OH_IPCParcel_ReadRemoteProxy](#oh_ipcparcel_readremoteproxy) (const OHIPCParcel \*parcel) | 从OHIPCParcel对象读取OHIPCRemoteProxy对象。 | 
| int [OH_IPCParcel_WriteFileDescriptor](#oh_ipcparcel_writefiledescriptor) (OHIPCParcel \*parcel, int32_t fd) | 向OHIPCParcel对象写入文件描述符。 | 
| int [OH_IPCParcel_ReadFileDescriptor](#oh_ipcparcel_readfiledescriptor) (const OHIPCParcel \*parcel, int32_t \*fd) | 从OHIPCParcel对象读取文件描述符。 | 
| int [OH_IPCParcel_Append](#oh_ipcparcel_append) (OHIPCParcel \*parcel, const OHIPCParcel \*data) | OHIPCParcel对象数据拼接。 | 
| int [OH_IPCParcel_WriteInterfaceToken](#oh_ipcparcel_writeinterfacetoken) (OHIPCParcel \*parcel, const char \*token) | 向OHIPCParcel对象写入接口描述符，用于接口身份校验。 | 
| int [OH_IPCParcel_ReadInterfaceToken](#oh_ipcparcel_readinterfacetoken) (const OHIPCParcel \*parcel, char \*\*token, int32_t \*len, [OH_IPC_MemAllocator](#oh_ipc_memallocator) allocator) | 从OHIPCParcel对象读取接口描述符信息，用于接口身份校验。 | 


## 类型定义说明


### OH_IPC_MemAllocator

```
typedef void*(* OH_IPC_MemAllocator) (int32_t len)
```

**描述**

内存分配函数类型。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| len | 分配内存长度。 | 

**返回：**

成功返回分配的内存地址；失败返回NULL。


## 函数说明


### OH_IPCParcel_Append()

```
int OH_IPCParcel_Append (OHIPCParcel * parcel, const OHIPCParcel * data)
```

**描述**

OHIPCParcel对象数据拼接。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | 拼接目标OHIPCParcel对象的指针，不能为空。 | 
| data | 源OHIPCParcel对象的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

拼接失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_Create()

```
OHIPCParcel* OH_IPCParcel_Create (void)
```

**描述**

创建OHIPCParcel对象，对象可序列化大小不能超过204800字节。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**返回：**

成功返回OHIPCParcel对象指针；失败返回NULL。


### OH_IPCParcel_Destroy()

```
void OH_IPCParcel_Destroy (OHIPCParcel * parcel)
```

**描述**

销毁OHIPCParcel对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | 需要销毁OHIPCParcel对象的指针。 | 


### OH_IPCParcel_GetDataSize()

```
int OH_IPCParcel_GetDataSize (const OHIPCParcel * parcel)
```

**描述**

获取OHIPCParcel对象包含的数据的大小。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

返回数据大小，参数不合法时返回-1。


### OH_IPCParcel_GetReadableBytes()

```
int OH_IPCParcel_GetReadableBytes (const OHIPCParcel * parcel)
```

**描述**

获取OHIPCParcel对象还可以读取的字节数。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

返回可读字节数大小，参数不合法时返回-1。


### OH_IPCParcel_GetReadPosition()

```
int OH_IPCParcel_GetReadPosition (const OHIPCParcel * parcel)
```

**描述**

获取OHIPCParcel对象当前读取位置。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

返回当前读位置，参数不合法时返回-1。


### OH_IPCParcel_GetWritableBytes()

```
int OH_IPCParcel_GetWritableBytes (const OHIPCParcel * parcel)
```

**描述**

获取OHIPCParcel对象可以写入的字节数。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

返回可写字节数大小，参数不合法时返回-1。


### OH_IPCParcel_GetWritePosition()

```
int OH_IPCParcel_GetWritePosition (const OHIPCParcel * parcel)
```

**描述**

获取OHIPCParcel对象当前写入位置。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

返回当前写入位置，参数不合法时返回-1。


### OH_IPCParcel_ReadBuffer()

```
const uint8_t* OH_IPCParcel_ReadBuffer (const OHIPCParcel * parcel, int32_t len)
```

**描述**

从OHIPCParcel对象读取指定长度内存信息。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| len | 读取内存的长度。 | 

**返回：**

成功返回读取到的内存地址；参数不合法或len超过parcel可读长度时返回NULL。


### OH_IPCParcel_ReadDouble()

```
int OH_IPCParcel_ReadDouble (const OHIPCParcel * parcel, double * value)
```

**描述**

从OHIPCParcel对象读取double值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 存储读取数据的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadFileDescriptor()

```
int OH_IPCParcel_ReadFileDescriptor (const OHIPCParcel * parcel, int32_t * fd)
```

**描述**

从OHIPCParcel对象读取文件描述符。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| fd | 存储读取文件描述符的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadFloat()

```
int OH_IPCParcel_ReadFloat (const OHIPCParcel * parcel, float * value)
```

**描述**

从OHIPCParcel对象读取float值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 存储读取数据的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadInt16()

```
int OH_IPCParcel_ReadInt16 (const OHIPCParcel * parcel, int16_t * value)
```

**描述**

从OHIPCParcel对象读取int16_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 存储读取数据的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadInt32()

```
int OH_IPCParcel_ReadInt32 (const OHIPCParcel * parcel, int32_t * value)
```

**描述**

从OHIPCParcel对象读取int32_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 存储读取数据的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadInt64()

```
int OH_IPCParcel_ReadInt64 (const OHIPCParcel * parcel, int64_t * value)
```

**描述**

从OHIPCParcel对象读取int64_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 存储读取数据的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadInt8()

```
int OH_IPCParcel_ReadInt8 (const OHIPCParcel * parcel, int8_t * value)
```

**描述**

从OHIPCParcel对象读取int8_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 存储读取数据的指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadInterfaceToken()

```
int OH_IPCParcel_ReadInterfaceToken (const OHIPCParcel * parcel, char ** token, int32_t * len, OH_IPC_MemAllocator allocator)
```

**描述**

从OHIPCParcel对象读取接口描述符信息，用于接口身份校验。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| token | 用于存储接口描述符信息的内存地址，该内存由用户提供的分配器进行内存分配，用户使用完后需要主动释放，不能为空。 接口返回失败时，用户依然需要判断该内存是否为空，并主动释放，否则会造成内存泄漏。 | 
| len | 存储读取接口描述符的长度，包含结束符，不能为空。 | 
| allocator | 用户指定的用来分配token的内存分配器，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

读取失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_ReadRemoteProxy()

```
OHIPCRemoteProxy* OH_IPCParcel_ReadRemoteProxy (const OHIPCParcel * parcel)
```

**描述**

从OHIPCParcel对象读取OHIPCRemoteProxy对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

成功返回OHIPCRemoteProxy对象指针；失败返回NULL。


### OH_IPCParcel_ReadRemoteStub()

```
OHIPCRemoteStub* OH_IPCParcel_ReadRemoteStub (const OHIPCParcel * parcel)
```

**描述**

从OHIPCParcel对象读取OHIPCRemoteStub对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

成功返回OHIPCRemoteStub对象指针；失败返回NULL。


### OH_IPCParcel_ReadString()

```
const char* OH_IPCParcel_ReadString (const OHIPCParcel * parcel)
```

**描述**

从OHIPCParcel对象读取字符串，用户可通过strlen获取字符串长度。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 

**返回：**

成功返回读取字符串地址；参数不合法或读取失败时返回NULL。


### OH_IPCParcel_RewindReadPosition()

```
int OH_IPCParcel_RewindReadPosition (OHIPCParcel * parcel, uint32_t newReadPos)
```

**描述**

重置OHIPCParcel对象读取位置。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| newReadPos | 新的读取位置，范围：[0, 当前数据大小]。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_RewindWritePosition()

```
int OH_IPCParcel_RewindWritePosition (OHIPCParcel * parcel, uint32_t newWritePos)
```

**描述**

重置OHIPCParcel对象写入位置。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| newWritePos | 新的写入位置，范围：[0, 当前数据大小]。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteBuffer()

```
int OH_IPCParcel_WriteBuffer (OHIPCParcel * parcel, const uint8_t * buffer, int32_t len)
```

**描述**

向OHIPCParcel对象写入指定长度的内存信息。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| buffer | 写入内存信息地址。 | 
| len | 写入信息长度。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteDouble()

```
int OH_IPCParcel_WriteDouble (OHIPCParcel * parcel, double value)
```

**描述**

向OHIPCParcel对象写入double值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 要写入的值。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteFileDescriptor()

```
int OH_IPCParcel_WriteFileDescriptor (OHIPCParcel * parcel, int32_t fd)
```

**描述**

向OHIPCParcel对象写入文件描述符。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| fd | 要写入的文件描述符。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteFloat()

```
int OH_IPCParcel_WriteFloat (OHIPCParcel * parcel, float value)
```

**描述**

向OHIPCParcel对象写入float值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 要写入的值。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteInt16()

```
int OH_IPCParcel_WriteInt16 (OHIPCParcel * parcel, int16_t value)
```

**描述**

向OHIPCParcel对象写入int16_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 要写入的值。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteInt32()

```
int OH_IPCParcel_WriteInt32 (OHIPCParcel * parcel, int32_t value)
```

**描述**

向OHIPCParcel对象写入int32_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 要写入的值。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteInt64()

```
int OH_IPCParcel_WriteInt64 (OHIPCParcel * parcel, int64_t value)
```

**描述**

向OHIPCParcel对象写入int64_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 要写入的值。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteInt8()

```
int OH_IPCParcel_WriteInt8 (OHIPCParcel * parcel, int8_t value)
```

**描述**

向OHIPCParcel对象写入int8_t值。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| value | 要写入的值。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteInterfaceToken()

```
int OH_IPCParcel_WriteInterfaceToken (OHIPCParcel * parcel, const char * token)
```

**描述**

向OHIPCParcel对象写入接口描述符，用于接口身份校验。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| token | 需要写入的接口描述符信息，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteRemoteProxy()

```
int OH_IPCParcel_WriteRemoteProxy (OHIPCParcel * parcel, const OHIPCRemoteProxy * proxy)
```

**描述**

向OHIPCParcel对象写入OHIPCRemoteProxy对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| proxy | 需要写入的OHIPCRemoteProxy对象指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteRemoteStub()

```
int OH_IPCParcel_WriteRemoteStub (OHIPCParcel * parcel, const OHIPCRemoteStub * stub)
```

**描述**

向OHIPCParcel对象写入OHIPCRemoteStub对象。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| stub | 需要写入的OHIPCRemoteStub对象指针，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。


### OH_IPCParcel_WriteString()

```
int OH_IPCParcel_WriteString (OHIPCParcel * parcel, const char * str)
```

**描述**

向OHIPCParcel对象写入字符串，包含字符串结束符。

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| parcel | OHIPCParcel对象的指针，不能为空。 | 
| str | 写入字符串，不能为空。 | 

**返回：**

成功返回[OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md)；

参数不合法时返回[OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md)；

写入失败返回[OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md)。
