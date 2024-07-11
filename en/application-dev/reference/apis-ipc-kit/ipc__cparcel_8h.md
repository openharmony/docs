# ipc_cparcel.h


## Overview

Provides C interfaces for IPC serialization and deserialization.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCParcel](_o_h_i_p_c_parcel.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef void \*(\* [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator)) (int32_t len) | Defines the type of a memory allocation function. | 


### Functions

| Name| Description| 
| -------- | -------- |
| OHIPCParcel \* [OH_IPCParcel_Create](_o_h_i_p_c_parcel.md#oh_ipcparcel_create) (void) | Creates an **OHIPCParcel** object, which cannot exceed 204,800 bytes. | 
| void [OH_IPCParcel_Destroy](_o_h_i_p_c_parcel.md#oh_ipcparcel_destroy) (OHIPCParcel \*parcel) | Destroys an **OHIPCParcel** object. | 
| int [OH_IPCParcel_GetDataSize](_o_h_i_p_c_parcel.md#oh_ipcparcel_getdatasize) (const OHIPCParcel \*parcel) | Obtains the size of the data contained in an **OHIPCParcel** object. | 
| int [OH_IPCParcel_GetWritableBytes](_o_h_i_p_c_parcel.md#oh_ipcparcel_getwritablebytes) (const OHIPCParcel \*parcel) | Obtains the number of bytes that can be written to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_GetReadableBytes](_o_h_i_p_c_parcel.md#oh_ipcparcel_getreadablebytes) (const OHIPCParcel \*parcel) | Obtains the number of bytes that can be read from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_GetReadPosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_getreadposition) (const OHIPCParcel \*parcel) | Obtains the position where data is read in an **OHIPCParcel** object. | 
| int [OH_IPCParcel_GetWritePosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_getwriteposition) (const OHIPCParcel \*parcel) | Obtains the position where data is written in an **OHIPCParcel** object. | 
| int [OH_IPCParcel_RewindReadPosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_rewindreadposition) (OHIPCParcel \*parcel, uint32_t newReadPos) | Resets the position to read data in an **OHIPCParcel** object. | 
| int [OH_IPCParcel_RewindWritePosition](_o_h_i_p_c_parcel.md#oh_ipcparcel_rewindwriteposition) (OHIPCParcel \*parcel, uint32_t newWritePos) | Resets the position to write data in an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteInt8](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint8) (OHIPCParcel \*parcel, int8_t value) | Writes an int8_t value to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_ReadInt8](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint8) (const OHIPCParcel \*parcel, int8_t \*value) | Reads an int8_t value from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteInt16](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint16) (OHIPCParcel \*parcel, int16_t value) | Writes an int16_t value to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_ReadInt16](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint16) (const OHIPCParcel \*parcel, int16_t \*value) | Reads an int16_t value from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteInt32](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint32) (OHIPCParcel \*parcel, int32_t value) | Writes an int32_t value to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_ReadInt32](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint32) (const OHIPCParcel \*parcel, int32_t \*value) | Reads an int32_t value from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteInt64](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeint64) (OHIPCParcel \*parcel, int64_t value) | Writes an int64_t value to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_ReadInt64](_o_h_i_p_c_parcel.md#oh_ipcparcel_readint64) (const OHIPCParcel \*parcel, int64_t \*value) | Reads an int64_t value from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteFloat](_o_h_i_p_c_parcel.md#oh_ipcparcel_writefloat) (OHIPCParcel \*parcel, float value) | Writes a float value to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_ReadFloat](_o_h_i_p_c_parcel.md#oh_ipcparcel_readfloat) (const OHIPCParcel \*parcel, float \*value) | Reads a float value from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteDouble](_o_h_i_p_c_parcel.md#oh_ipcparcel_writedouble) (OHIPCParcel \*parcel, double value) | Writes a double value to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_ReadDouble](_o_h_i_p_c_parcel.md#oh_ipcparcel_readdouble) (const OHIPCParcel \*parcel, double \*value) | Reads a double value from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteString](_o_h_i_p_c_parcel.md#oh_ipcparcel_writestring) (OHIPCParcel \*parcel, const char \*str) | Writes a string including a string terminator to an **OHIPCParcel** object. | 
| const char \* [OH_IPCParcel_ReadString](_o_h_i_p_c_parcel.md#oh_ipcparcel_readstring) (const OHIPCParcel \*parcel) | Reads a string from an **OHIPCParcel** object. You can obtain the length of the string from **strlen**. | 
| int [OH_IPCParcel_WriteBuffer](_o_h_i_p_c_parcel.md#oh_ipcparcel_writebuffer) (OHIPCParcel \*parcel, const uint8_t \*buffer, int32_t len) | Writes data of the specified length from the memory to an **OHIPCParcel** object. | 
| const uint8_t \* [OH_IPCParcel_ReadBuffer](_o_h_i_p_c_parcel.md#oh_ipcparcel_readbuffer) (const OHIPCParcel \*parcel, int32_t len) | Reads memory information of the specified length from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteRemoteStub](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeremotestub) (OHIPCParcel \*parcel, const OHIPCRemoteStub \*stub) | Writes an **OHIPCRemoteStub** object to an **OHIPCParcel** object. | 
| OHIPCRemoteStub \* [OH_IPCParcel_ReadRemoteStub](_o_h_i_p_c_parcel.md#oh_ipcparcel_readremotestub) (const OHIPCParcel \*parcel) | Reads the **OHIPCRemoteStub** object from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteRemoteProxy](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeremoteproxy) (OHIPCParcel \*parcel, const OHIPCRemoteProxy \*proxy) | Writes an **OHIPCRemoteProxy** object to an **OHIPCParcel** object. | 
| OHIPCRemoteProxy \* [OH_IPCParcel_ReadRemoteProxy](_o_h_i_p_c_parcel.md#oh_ipcparcel_readremoteproxy) (const OHIPCParcel \*parcel) | Reads the **OHIPCRemoteProxy** object from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteFileDescriptor](_o_h_i_p_c_parcel.md#oh_ipcparcel_writefiledescriptor) (OHIPCParcel \*parcel, int32_t fd) | Writes a file descriptor to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_ReadFileDescriptor](_o_h_i_p_c_parcel.md#oh_ipcparcel_readfiledescriptor) (const OHIPCParcel \*parcel, int32_t \*fd) | Reads a file descriptor from an **OHIPCParcel** object. | 
| int [OH_IPCParcel_Append](_o_h_i_p_c_parcel.md#oh_ipcparcel_append) (OHIPCParcel \*parcel, const OHIPCParcel \*data) | Appends data to an **OHIPCParcel** object. | 
| int [OH_IPCParcel_WriteInterfaceToken](_o_h_i_p_c_parcel.md#oh_ipcparcel_writeinterfacetoken) (OHIPCParcel \*parcel, const char \*token) | Writes an interface token to an **OHIPCParcel** object for interface identity verification. | 
| int [OH_IPCParcel_ReadInterfaceToken](_o_h_i_p_c_parcel.md#oh_ipcparcel_readinterfacetoken) (const OHIPCParcel \*parcel, char \*\*token, int32_t \*len, [OH_IPC_MemAllocator](_o_h_i_p_c_parcel.md#oh_ipc_memallocator) allocator) | Reads an interface token from an **OHIPCParcel** object for interface identity verification. | 
