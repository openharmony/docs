# OHIPCParcel


## Overview

Provides C interfaces for IPC serialization and deserialization.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [ipc_cparcel.h](ipc__cparcel_8h.md) | Provides C interfaces for IPC serialization and deserialization.| 


### Types

| Name| Description| 
| -------- | -------- |
| typedef void \*(\* [OH_IPC_MemAllocator](#oh_ipc_memallocator)) (int32_t len) | Defines the type of a memory allocation function.| 


### Functions

| Name| Description| 
| -------- | -------- |
| OHIPCParcel \* [OH_IPCParcel_Create](#oh_ipcparcel_create) (void) | Creates an **OHIPCParcel** object, which cannot exceed 204,800 bytes.| 
| void [OH_IPCParcel_Destroy](#oh_ipcparcel_destroy) (OHIPCParcel \*parcel) | Destroys an **OHIPCParcel** object.| 
| int [OH_IPCParcel_GetDataSize](#oh_ipcparcel_getdatasize) (const OHIPCParcel \*parcel) | Obtains the size of the data contained in an **OHIPCParcel** object.| 
| int [OH_IPCParcel_GetWritableBytes](#oh_ipcparcel_getwritablebytes) (const OHIPCParcel \*parcel) | Obtains the number of bytes that can be written to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_GetReadableBytes](#oh_ipcparcel_getreadablebytes) (const OHIPCParcel \*parcel) | Obtains the number of bytes that can be read from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_GetReadPosition](#oh_ipcparcel_getreadposition) (const OHIPCParcel \*parcel) | Obtains the position where data is read in an **OHIPCParcel** object.| 
| int [OH_IPCParcel_GetWritePosition](#oh_ipcparcel_getwriteposition) (const OHIPCParcel \*parcel) | Obtains the position where data is written in an **OHIPCParcel** object.| 
| int [OH_IPCParcel_RewindReadPosition](#oh_ipcparcel_rewindreadposition) (OHIPCParcel \*parcel, uint32_t newReadPos) | Resets the position to read data in an **OHIPCParcel** object.| 
| int [OH_IPCParcel_RewindWritePosition](#oh_ipcparcel_rewindwriteposition) (OHIPCParcel \*parcel, uint32_t newWritePos) | Resets the position to write data in an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteInt8](#oh_ipcparcel_writeint8) (OHIPCParcel \*parcel, int8_t value) | Writes an int8_t value to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_ReadInt8](#oh_ipcparcel_readint8) (const OHIPCParcel \*parcel, int8_t \*value) | Reads an int8_t value from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteInt16](#oh_ipcparcel_writeint16) (OHIPCParcel \*parcel, int16_t value) | Writes an int16_t value to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_ReadInt16](#oh_ipcparcel_readint16) (const OHIPCParcel \*parcel, int16_t \*value) | Reads an int16_t value from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteInt32](#oh_ipcparcel_writeint32) (OHIPCParcel \*parcel, int32_t value) | Writes an int32_t value to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_ReadInt32](#oh_ipcparcel_readint32) (const OHIPCParcel \*parcel, int32_t \*value) | Reads an int32_t value from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteInt64](#oh_ipcparcel_writeint64) (OHIPCParcel \*parcel, int64_t value) | Writes an int64_t value to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_ReadInt64](#oh_ipcparcel_readint64) (const OHIPCParcel \*parcel, int64_t \*value) | Reads an int64_t value from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteFloat](#oh_ipcparcel_writefloat) (OHIPCParcel \*parcel, float value) | Writes a float value to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_ReadFloat](#oh_ipcparcel_readfloat) (const OHIPCParcel \*parcel, float \*value) | Reads a float value from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteDouble](#oh_ipcparcel_writedouble) (OHIPCParcel \*parcel, double value) | Writes a double value to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_ReadDouble](#oh_ipcparcel_readdouble) (const OHIPCParcel \*parcel, double \*value) | Reads a double value from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteString](#oh_ipcparcel_writestring) (OHIPCParcel \*parcel, const char \*str) | Writes a string including a string terminator to an **OHIPCParcel** object.| 
| const char \* [OH_IPCParcel_ReadString](#oh_ipcparcel_readstring) (const OHIPCParcel \*parcel) | Reads a string from an **OHIPCParcel** object. You can obtain the length of the string from **strlen**.| 
| int [OH_IPCParcel_WriteBuffer](#oh_ipcparcel_writebuffer) (OHIPCParcel \*parcel, const uint8_t \*buffer, int32_t len) | Writes data of the specified length from the memory to an **OHIPCParcel** object.| 
| const uint8_t \* [OH_IPCParcel_ReadBuffer](#oh_ipcparcel_readbuffer) (const OHIPCParcel \*parcel, int32_t len) | Reads memory information of the specified length from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteRemoteStub](#oh_ipcparcel_writeremotestub) (OHIPCParcel \*parcel, const OHIPCRemoteStub \*stub) | Writes an **OHIPCRemoteStub** object to an **OHIPCParcel** object.| 
| OHIPCRemoteStub \* [OH_IPCParcel_ReadRemoteStub](#oh_ipcparcel_readremotestub) (const OHIPCParcel \*parcel) | Reads the **OHIPCRemoteStub** object from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteRemoteProxy](#oh_ipcparcel_writeremoteproxy) (OHIPCParcel \*parcel, const OHIPCRemoteProxy \*proxy) | Writes an **OHIPCRemoteProxy** object to an **OHIPCParcel** object.| 
| OHIPCRemoteProxy \* [OH_IPCParcel_ReadRemoteProxy](#oh_ipcparcel_readremoteproxy) (const OHIPCParcel \*parcel) | Reads the **OHIPCRemoteProxy** object from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteFileDescriptor](#oh_ipcparcel_writefiledescriptor) (OHIPCParcel \*parcel, int32_t fd) | Writes a file descriptor to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_ReadFileDescriptor](#oh_ipcparcel_readfiledescriptor) (const OHIPCParcel \*parcel, int32_t \*fd) | Reads a file descriptor from an **OHIPCParcel** object.| 
| int [OH_IPCParcel_Append](#oh_ipcparcel_append) (OHIPCParcel \*parcel, const OHIPCParcel \*data) | Appends data to an **OHIPCParcel** object.| 
| int [OH_IPCParcel_WriteInterfaceToken](#oh_ipcparcel_writeinterfacetoken) (OHIPCParcel \*parcel, const char \*token) | Writes an interface token to an **OHIPCParcel** object for interface identity verification.| 
| int [OH_IPCParcel_ReadInterfaceToken](#oh_ipcparcel_readinterfacetoken) (const OHIPCParcel \*parcel, char \*\*token, int32_t \*len, [OH_IPC_MemAllocator](#oh_ipc_memallocator) allocator) | Reads an interface token from an **OHIPCParcel** object for interface identity verification.| 


## Type Description


### OH_IPC_MemAllocator

```
typedef void*(* OH_IPC_MemAllocator) (int32_t len)
```

**Description**

Defines the type of a memory allocation function.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| len | Length of the allocated memory.| 

**Returns**

Returns the address of the memory allocated if the operation is successful; returns NULL otherwise.


## Function Description


### OH_IPCParcel_Append()

```
int OH_IPCParcel_Append (OHIPCParcel * parcel, const OHIPCParcel * data)
```

**Description**

Appends data to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the target **OHIPCParcel** object. It cannot be NULL.| 
| data | Pointer to the data to append. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_Create()

```
OHIPCParcel* OH_IPCParcel_Create (void)
```

**Description**

Creates an **OHIPCParcel** object, which cannot exceed 204,800 bytes.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

Returns the pointer to the **OHIPCParcel** object created if the operation is successful; returns NULL otherwise.


### OH_IPCParcel_Destroy()

```
void OH_IPCParcel_Destroy (OHIPCParcel * parcel)
```

**Description**

Destroys an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object to destroy.| 


### OH_IPCParcel_GetDataSize()

```
int OH_IPCParcel_GetDataSize (const OHIPCParcel * parcel)
```

**Description**

Obtains the size of the data contained in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the data size obtained if the operation is successful.<br>Returns **-1** if invalid parameters are found.


### OH_IPCParcel_GetReadableBytes()

```
int OH_IPCParcel_GetReadableBytes (const OHIPCParcel * parcel)
```

**Description**

Obtains the number of bytes that can be read from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the number of bytes that can be read from the **OHIPCParcel** object. <br>Returns **-1** if invalid parameters are found.


### OH_IPCParcel_GetReadPosition()

```
int OH_IPCParcel_GetReadPosition (const OHIPCParcel * parcel)
```

**Description**

Obtains the position where data is read in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the current read position obtained if the operation is successful. <br>Returns **-1** if invalid parameters are found.


### OH_IPCParcel_GetWritableBytes()

```
int OH_IPCParcel_GetWritableBytes (const OHIPCParcel * parcel)
```

**Description**

Obtains the number of bytes that can be written to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the number of bytes that can be written to the **OHIPCParcel** object. <br>Returns **-1** if invalid parameters are found.


### OH_IPCParcel_GetWritePosition()

```
int OH_IPCParcel_GetWritePosition (const OHIPCParcel * parcel)
```

**Description**

Obtains the position where data is written in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the current write position obtained if the operation is successful.<br>Returns **-1** if invalid parameters are found.


### OH_IPCParcel_ReadBuffer()

```
const uint8_t* OH_IPCParcel_ReadBuffer (const OHIPCParcel * parcel, int32_t len)
```

**Description**

Reads memory information of the specified length from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| len | Length of the memory to be read.| 

**Returns**

Returns the memory address read if the operation is successful.<br>Returns NULL if invalid parameters are found or **len** exceeds the readable length of **parcel**.


### OH_IPCParcel_ReadDouble()

```
int OH_IPCParcel_ReadDouble (const OHIPCParcel * parcel, double * value)
```

**Description**

Reads a double value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Pointer to the buffer for holding the read data. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadFileDescriptor()

```
int OH_IPCParcel_ReadFileDescriptor (const OHIPCParcel * parcel, int32_t * fd)
```

**Description**

Reads a file descriptor from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| fd | Pointer to the file descriptor to read. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadFloat()

```
int OH_IPCParcel_ReadFloat (const OHIPCParcel * parcel, float * value)
```

**Description**

Reads a float value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Pointer to the buffer for holding the read data. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadInt16()

```
int OH_IPCParcel_ReadInt16 (const OHIPCParcel * parcel, int16_t * value)
```

**Description**

Reads an int16_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Pointer to the buffer for holding the read data. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadInt32()

```
int OH_IPCParcel_ReadInt32 (const OHIPCParcel * parcel, int32_t * value)
```

**Description**

Reads an int32_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Pointer to the buffer for holding the read data. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadInt64()

```
int OH_IPCParcel_ReadInt64 (const OHIPCParcel * parcel, int64_t * value)
```

**Description**

Reads an int64_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Pointer to the buffer for holding the read data. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadInt8()

```
int OH_IPCParcel_ReadInt8 (const OHIPCParcel * parcel, int8_t * value)
```

**Description**

Reads an int8_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Pointer to the buffer for holding the read data. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadInterfaceToken()

```
int OH_IPCParcel_ReadInterfaceToken (const OHIPCParcel * parcel, char ** token, int32_t * len, OH_IPC_MemAllocator allocator)
```

**Description**

Reads an interface token from an **OHIPCParcel** object for interface identity verification.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| token | Pointer to the interface token to read. The memory is allocated by the allocator provided by the user and needs to be released. This pointer cannot be NULL. If an error code is returned, you still need to check whether the memory is empty and release the memory. Otherwise, memory leaks may occur.| 
| len | Pointer to the length of the interface token read, including the terminator. It cannot be NULL.| 
| allocator | Memory allocator specified by the user for allocating memory. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](_o_h_i_p_c_error_code.md) if the read operation fails.


### OH_IPCParcel_ReadRemoteProxy()

```
OHIPCRemoteProxy* OH_IPCParcel_ReadRemoteProxy (const OHIPCParcel * parcel)
```

**Description**

Reads the **OHIPCRemoteProxy** object from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the pointer to the **OHIPCRemoteProxy** object created if the operation is successful; returns NULL otherwise.


### OH_IPCParcel_ReadRemoteStub()

```
OHIPCRemoteStub* OH_IPCParcel_ReadRemoteStub (const OHIPCParcel * parcel)
```

**Description**

Reads the **OHIPCRemoteStub** object from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the pointer to the **OHIPCRemoteStub** object read if the operation is successful; returns NULL otherwise.


### OH_IPCParcel_ReadString()

```
const char* OH_IPCParcel_ReadString (const OHIPCParcel * parcel)
```

**Description**

Reads a string from an **OHIPCParcel** object. You can obtain the length of the string from **strlen**.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 

**Returns**

Returns the address of the string read if the operation is successful; returns NULL if the operation fails or invalid parameters are found.


### OH_IPCParcel_RewindReadPosition()

```
int OH_IPCParcel_RewindReadPosition (OHIPCParcel * parcel, uint32_t newReadPos)
```

**Description**

Resets the position to read data in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| newReadPos | New position to read data. The value ranges from **0** to the current data size.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.


### OH_IPCParcel_RewindWritePosition()

```
int OH_IPCParcel_RewindWritePosition (OHIPCParcel * parcel, uint32_t newWritePos)
```

**Description**

Resets the position to write data in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| newWritePos | New position to write data. The value ranges from **0** to the current data size.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.


### OH_IPCParcel_WriteBuffer()

```
int OH_IPCParcel_WriteBuffer (OHIPCParcel * parcel, const uint8_t * buffer, int32_t len)
```

**Description**

Writes data of the specified length from the memory to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| buffer | Pointer to the address for writing memory information.| 
| len | Length of the data to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteDouble()

```
int OH_IPCParcel_WriteDouble (OHIPCParcel * parcel, double value)
```

**Description**

Writes a double value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Value to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteFileDescriptor()

```
int OH_IPCParcel_WriteFileDescriptor (OHIPCParcel * parcel, int32_t fd)
```

**Description**

Writes a file descriptor to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| fd | Pointer to the file descriptor to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteFloat()

```
int OH_IPCParcel_WriteFloat (OHIPCParcel * parcel, float value)
```

**Description**

Writes a float value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Value to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteInt16()

```
int OH_IPCParcel_WriteInt16 (OHIPCParcel * parcel, int16_t value)
```

**Description**

Writes an int16_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Value to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteInt32()

```
int OH_IPCParcel_WriteInt32 (OHIPCParcel * parcel, int32_t value)
```

**Description**

Writes an int32_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Value to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteInt64()

```
int OH_IPCParcel_WriteInt64 (OHIPCParcel * parcel, int64_t value)
```

**Description**

Writes an int64_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Value to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteInt8()

```
int OH_IPCParcel_WriteInt8 (OHIPCParcel * parcel, int8_t value)
```

**Description**

Writes an int8_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| value | Value to write.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteInterfaceToken()

```
int OH_IPCParcel_WriteInterfaceToken (OHIPCParcel * parcel, const char * token)
```

**Description**

Writes an interface token to an **OHIPCParcel** object for interface identity verification.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| token | Pointer to the interface token to write. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteRemoteProxy()

```
int OH_IPCParcel_WriteRemoteProxy (OHIPCParcel * parcel, const OHIPCRemoteProxy * proxy)
```

**Description**

Writes an **OHIPCRemoteProxy** object to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| proxy | Pointer to the **OHIPCRemoteProxy** object to write. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteRemoteStub()

```
int OH_IPCParcel_WriteRemoteStub (OHIPCParcel * parcel, const OHIPCRemoteStub * stub)
```

**Description**

Writes an **OHIPCRemoteStub** object to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| stub | Pointer to the **OHIPCRemoteStub** object to write. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.


### OH_IPCParcel_WriteString()

```
int OH_IPCParcel_WriteString (OHIPCParcel * parcel, const char * str)
```

**Description**

Writes a string including a string terminator to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.| 
| str | Pointer to the string to write. It cannot be NULL.| 

**Returns**

Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](_o_h_i_p_c_error_code.md) if the operation is successful.

Returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](_o_h_i_p_c_error_code.md) if invalid parameters are found.

Returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](_o_h_i_p_c_error_code.md) if the operation fails.
