# ipc_cparcel.h


## 概述

提供IPC序列化/反序列化C接口。

**库：** libipc_capi.so

**系统能力：** SystemCapability.Communication.IPC.Core

**起始版本：** 12

**相关模块：**[OHIPCParcel](_o_h_i_p_c_parcel.md)


## 汇总


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef void \*(\* [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator)) (int32_t len) | 内存分配函数类型。  | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| OHIPCParcel \* [OH_IPCParcel_Create](_o_h_i_p_c_parcel.md#oh_ipcparcel_create) (void) | 创建OHIPCParcel对象，对象可序列化大小不能超过204800字节。  | 
| void [OH_IPCParcel_Destroy](_o_h_i_p_c_parcel.md#oh_ipcparcel_destroy) (OHIPCParcel \*parcel) | 销毁OHIPCParcel对象.  | 
| int [OH_IPCParcel_GetDataSize](_o_h_i_p_c_parcel.md#oh_ipcparcel_getdatasize) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象包含的数据的大小。  | 
| int [OH_IPCParcel_GetWritableBytes](_o_h_i_p_c_parcel.md#oh_ipcparcel_getwritablebytes) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象可以写入的字节数。  | 
| int [OH_IPCParcel_GetReadableBytes](_o_h_i_p_c_parcel.md#oh_ipcparcel_getreadablebytes) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象还可以读取的字节数。  | 
| int [OH_IPCParcel_GetReadPosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_getreadposition) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象当前读取位置。  | 
| int [OH_IPCParcel_GetWritePosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_getwriteposition) (const OHIPCParcel \*parcel) | 获取OHIPCParcel对象当前写入位置。  | 
| int [OH_IPCParcel_RewindReadPosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_rewindreadposition) (OHIPCParcel \*parcel, uint32_t newReadPos) | 重置OHIPCParcel对象读取位置。  | 
| int [OH_IPCParcel_RewindWritePosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_rewindwriteposition) (OHIPCParcel \*parcel, uint32_t newWritePos) | 重置OHIPCParcel对象写入位置。  | 
| int [OH_IPCParcel_WriteInt8](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint8) (OHIPCParcel \*parcel, int8_t value) | 向OHIPCParcel对象写入int8_t值。  | 
| int [OH_IPCParcel_ReadInt8](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint8) (const OHIPCParcel \*parcel, int8_t \*value) | 从OHIPCParcel对象读取int8_t值。  | 
| int [OH_IPCParcel_WriteInt16](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint16) (OHIPCParcel \*parcel, int16_t value) | 向OHIPCParcel对象写入int16_t值。  | 
| int [OH_IPCParcel_ReadInt16](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint16) (const OHIPCParcel \*parcel, int16_t \*value) | 从OHIPCParcel对象读取int16_t值。  | 
| int [OH_IPCParcel_WriteInt32](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint32) (OHIPCParcel \*parcel, int32_t value) | 向OHIPCParcel对象写入int32_t值。  | 
| int [OH_IPCParcel_ReadInt32](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint32) (const OHIPCParcel \*parcel, int32_t \*value) | 从OHIPCParcel对象读取int32_t值。  | 
| int [OH_IPCParcel_WriteInt64](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint64) (OHIPCParcel \*parcel, int64_t value) | 向OHIPCParcel对象写入int64_t值。  | 
| int [OH_IPCParcel_ReadInt64](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint64) (const OHIPCParcel \*parcel, int64_t \*value) | 从OHIPCParcel对象读取int64_t值。  | 
| int [OH_IPCParcel_WriteFloat](_o_h_i_p_c_parcel.md#oh_ipcparcel_writefloat) (OHIPCParcel \*parcel, float value) | 向OHIPCParcel对象写入float值。  | 
| int [OH_IPCParcel_ReadFloat](_o_h_i_p_c_parcel.md#oh_ipcparcel_readfloat) (const OHIPCParcel \*parcel, float \*value) | 从OHIPCParcel对象读取float值。  | 
| int [OH_IPCParcel_WriteDouble](_o_h_i_p_c_parcel.md#oh_ipcparcel_writedouble) (OHIPCParcel \*parcel, double value) | 向OHIPCParcel对象写入double值。  | 
| int [OH_IPCParcel_ReadDouble](_o_h_i_p_c_parcel.md#oh_ipcparcel_readdouble) (const OHIPCParcel \*parcel, double \*value) | 从OHIPCParcel对象读取double值。  | 
| int [OH_IPCParcel_WriteString](_o_h_i_p_c_parcel.md#oh_ipcparcel_writestring) (OHIPCParcel \*parcel, const char \*str) | 向OHIPCParcel对象写入字符串，包含字符串结束符。  | 
| const char \* [OH_IPCParcel_ReadString](_o_h_i_p_c_parcel.md#oh_ipcparcel_readstring) (const OHIPCParcel \*parcel) | 从OHIPCParcel对象读取字符串，用户可通过strlen获取字符串长度。  | 
| int [OH_IPCParcel_WriteBuffer](_o_h_i_p_c_parcel.md#oh_ipcparcel_writebuffer) (OHIPCParcel \*parcel, const uint8_t \*buffer, int32_t len) | 向OHIPCParcel对象写入指定长度的内存信息。  | 
| const uint8_t \* [OH_IPCParcel_ReadBuffer](_o_h_i_p_c_parcel.md#oh_ipcparcel_readbuffer) (const OHIPCParcel \*parcel, int32_t len) | 从OHIPCParcel对象读取指定长度内存信息。  | 
| int [OH_IPCParcel_WriteRemoteStub](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeremotestub) (OHIPCParcel \*parcel, const OHIPCRemoteStub \*stub) | 向OHIPCParcel对象写入OHIPCRemoteStub对象。  | 
| OHIPCRemoteStub \* [OH_IPCParcel_ReadRemoteStub](_o_h_i_p_c_parcel.md#oh_ipcparcel_readremotestub) (const OHIPCParcel \*parcel) | 从OHIPCParcel对象读取OHIPCRemoteStub对象。  | 
| int [OH_IPCParcel_WriteRemoteProxy](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeremoteproxy) (OHIPCParcel \*parcel, const OHIPCRemoteProxy \*proxy) | 向OHIPCParcel对象写入OHIPCRemoteProxy对象。  | 
| OHIPCRemoteProxy \* [OH_IPCParcel_ReadRemoteProxy](_o_h_i_p_c_parcel.md#oh_ipcparcel_readremoteproxy) (const OHIPCParcel \*parcel) | 从OHIPCParcel对象读取OHIPCRemoteProxy对象。  | 
| int [OH_IPCParcel_WriteFileDescriptor](_o_h_i_p_c_parcel.md#oh_ipcparcel_writefiledescriptor) (OHIPCParcel \*parcel, int32_t fd) | 向OHIPCParcel对象写入文件描述符。  | 
| int [OH_IPCParcel_ReadFileDescriptor](_o_h_i_p_c_parcel.md#oh_ipcparcel_readfiledescriptor) (const OHIPCParcel \*parcel, int32_t \*fd) | 从OHIPCParcel对象读取文件描述符。  | 
| int [OH_IPCParcel_Append](_o_h_i_p_c_parcel.md#oh_ipcparcel_append) (OHIPCParcel \*parcel, const OHIPCParcel \*data) | OHIPCParcel对象数据拼接。  | 
| int [OH_IPCParcel_WriteInterfaceToken](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeinterfacetoken) (OHIPCParcel \*parcel, const char \*token) | 向OHIPCParcel对象写入接口描述符，用于接口身份校验。  | 
| int [OH_IPCParcel_ReadInterfaceToken](_o_h_i_p_c_parcel.md#oh_ipcparcel_readinterfacetoken) (const OHIPCParcel \*parcel, char \*\*token, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | 从OHIPCParcel对象读取接口描述符信息，用于接口身份校验。  | 
