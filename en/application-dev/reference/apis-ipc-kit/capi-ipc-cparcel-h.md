# ipc_cparcel.h
<!--Kit: IPC Kit-->
<!--Subsystem: Communication-->
<!--Owner: @xdx19211@luodonghui0157-->
<!--SE: @zhaopeng_gitee-->
<!--TSE: @maxiaorong2-->

## Overview

Provides C APIs for IPC serialization and deserialization.

**Library**: libipc_capi.so

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Related module**: [OHIPCParcel](capi-ohipcparcel.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) | OHIPCParcel | Defines an IPC serialized object.|
| [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) | OHIPCRemoteProxy | Defines an IPC remote proxy object.|
| [OHIPCRemoteStub](capi-ohipcparcel-ohipcremotestub.md) | OHIPCRemoteStub | Defines an IPC remote service object.|

### Function

| Name| typedef Keyword| Description|
| ---- | ------------- | ---- |
| [typedef void* (\*OH_IPC_MemAllocator)(int32_t len)](#oh_ipc_memallocator) | OH_IPC_MemAllocator | Defines the type of a memory allocation function.|
| [OHIPCParcel* OH_IPCParcel_Create(void)](#oh_ipcparcel_create) | - | Creates an **OHIPCParcel** object, which cannot exceed 204,800 bytes.|
| [void OH_IPCParcel_Destroy(OHIPCParcel *parcel)](#oh_ipcparcel_destroy) | - | Destroys an **OHIPCParcel** object.|
| [int OH_IPCParcel_GetDataSize(const OHIPCParcel *parcel)](#oh_ipcparcel_getdatasize) | - | Obtains the size of the data contained in an **OHIPCParcel** object.|
| [int OH_IPCParcel_GetWritableBytes(const OHIPCParcel *parcel)](#oh_ipcparcel_getwritablebytes) | - | Obtains the number of bytes that can be written to an **OHIPCParcel** object.|
| [int OH_IPCParcel_GetReadableBytes(const OHIPCParcel *parcel)](#oh_ipcparcel_getreadablebytes) | - | Obtains the number of bytes that can be read from an **OHIPCParcel** object.|
| [int OH_IPCParcel_GetReadPosition(const OHIPCParcel *parcel)](#oh_ipcparcel_getreadposition) | - | Obtains the position where data is read in an **OHIPCParcel** object.|
| [int OH_IPCParcel_GetWritePosition(const OHIPCParcel *parcel)](#oh_ipcparcel_getwriteposition) | - | Obtains the position where data is written in an **OHIPCParcel** object.|
| [int OH_IPCParcel_RewindReadPosition(OHIPCParcel *parcel, uint32_t newReadPos)](#oh_ipcparcel_rewindreadposition) | - | Resets the position to read data in an **OHIPCParcel** object.|
| [int OH_IPCParcel_RewindWritePosition(OHIPCParcel *parcel, uint32_t newWritePos)](#oh_ipcparcel_rewindwriteposition) | - | Resets the position to write data in an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteInt8(OHIPCParcel *parcel, int8_t value)](#oh_ipcparcel_writeint8) | - | Writes an int8_t value to an **OHIPCParcel** object.|
| [int OH_IPCParcel_ReadInt8(const OHIPCParcel *parcel, int8_t *value)](#oh_ipcparcel_readint8) | - | Reads an int8_t value from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteInt16(OHIPCParcel *parcel, int16_t value)](#oh_ipcparcel_writeint16) | - | Writes an int16_t value to an **OHIPCParcel** object.|
| [int OH_IPCParcel_ReadInt16(const OHIPCParcel *parcel, int16_t *value)](#oh_ipcparcel_readint16) | - | Reads an int16_t value from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteInt32(OHIPCParcel *parcel, int32_t value)](#oh_ipcparcel_writeint32) | - | Writes an int32_t value to an **OHIPCParcel** object.|
| [int OH_IPCParcel_ReadInt32(const OHIPCParcel *parcel, int32_t *value)](#oh_ipcparcel_readint32) | - | Reads an int32_t value from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteInt64(OHIPCParcel *parcel, int64_t value)](#oh_ipcparcel_writeint64) | - | Writes an int64_t value to an **OHIPCParcel** object.|
| [int OH_IPCParcel_ReadInt64(const OHIPCParcel *parcel, int64_t *value)](#oh_ipcparcel_readint64) | - | Reads an int64_t value from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteFloat(OHIPCParcel *parcel, float value)](#oh_ipcparcel_writefloat) | - | Writes a float value to an **OHIPCParcel** object.|
| [int OH_IPCParcel_ReadFloat(const OHIPCParcel *parcel, float *value)](#oh_ipcparcel_readfloat) | - | Reads a float value from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteDouble(OHIPCParcel *parcel, double value)](#oh_ipcparcel_writedouble) | - | Writes a double value to an **OHIPCParcel** object.|
| [int OH_IPCParcel_ReadDouble(const OHIPCParcel *parcel, double *value)](#oh_ipcparcel_readdouble) | - | Reads a double value from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteString(OHIPCParcel *parcel, const char *str)](#oh_ipcparcel_writestring) | - | Writes a string including a string terminator to an **OHIPCParcel** object.|
| [const char OH_IPCParcel_ReadString(const OHIPCParcel *parcel)](#oh_ipcparcel_readstring) | - | Reads a string from an **OHIPCParcel** object. You can obtain the length of the string from **strlen**.|
| [int OH_IPCParcel_Writebuffer(OHIPCParcel *parcel, const uint8_t *buffer, size_t len)](#oh_ipcparcel_writebuffer) | - | Writes data of the specified length from the memory to an **OHIPCParcel** object.|
| [const uint8_t *OH_IPCParcel_ReadBuffer(const OHIPCParcel *parcel, int32_t len)](#oh_ipcparcel_readbuffer) | - | Reads memory information of the specified length from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteRemoteStub(OHIPCParcel *parcel, const OHRemoteObject *stub)](#oh_ipcparcel_writeremotestub) | - | Writes an **OHRemoteObject** object to an **OHIPCParcel** object.|
| [OHIPCRemoteStub* OH_IPCParcel_ReadRemoteStub(OHIPCParcel *parcel)](#oh_ipcparcel_readremotestub) | - | Reads the **OHRemoteObject** object from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteRemoteProxy(OHIPCParcel *parcel, const OHRemoteObject *proxy)](#oh_ipcparcel_writeremoteproxy) | - | Writes an **OHRemoteObject** object to an **OHIPCParcel** object.|
| [OHIPCRemoteProxy* OH_IPCParcel_ReadRemoteProxy(OHIPCParcel *parcel)](#oh_ipcparcel_readremoteproxy) | - | Reads the **OHRemoteObject** object from an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteFileDescriptor(OHIPCParcel *parcel, int32_t fd)](#oh_ipcparcel_writefiledescriptor) | - | Writes a file descriptor to an **OHIPCParcel** object.|
| [int OH_IPCParcel_ReadFileDescriptor(OHIPCParcel *parcel int32_t *fd)](#oh_ipcparcel_readfiledescriptor) | - | Reads a file descriptor from an **OHIPCParcel** object.|
| [int OH_IPCParcel_Append(OHIPCParcel *parcel, const OHIPCParcel *data)](#oh_ipcparcel_append) | - | Appends data to an **OHIPCParcel** object.|
| [int OH_IPCParcel_WriteInterfaceToken(OHIPCParcel *parcel, const char *token)](#oh_ipcparcel_writeinterfacetoken) | - | Writes an interface token to an **OHIPCParcel** object for interface identity verification.|
| [int OH_IPCParcel_ReadInterfaceToken(OHIPCParcel *parcel, char **token, int32_t *len)](#oh_ipcparcel_readinterfacetoken) | - | Reads an interface token from an **OHIPCParcel** object for interface identity verification.|

## Function Description

### OH_IPC_MemAllocator()

```C
typedef void* (OH_IPC_MemAllocator)(int32_t len)
```

**Description**

Defines the type of a memory allocation function.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
|int32_t len | Length of the memory to be allocated.|

**Returns**

| Type| Description|
| ---- | ---- |
| void* | Returns the address of the memory allocated if the operation is successful; returns NULL otherwise.|

### OH_IPCParcel_Create()

```C
OHIPCParcel* OH_IPCParcel_Create(void)
```

**Description**

Creates an **OHIPCParcel** object, which cannot exceed 204,800 bytes.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Returns**

| Type| Description|
| ---- | ---- |
| OHIPCParcel* | Returns the pointer to the **OHIPCParcel** object created if the operation is successful; returns NULL otherwise.|

### OH_IPCParcel_Destroy()

```C
void OH_IPCParcel_Destroy(OHIPCParcel *parcel)
```

**Description**

Destroys an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object to destroy.|

### OH_IPCParcel_GetDataSize()

``` C
int OH_IPCParcel_GetDataSize(const OHIPCParcel *parcel)
```

**Description**
Obtains the size of the data contained in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns the data size obtained if the operation is successful; returns **-1** if invalid parameters are found.|

### OH_IPCParcel_GetWritableBytes()

```C
int OH_IPCParcel_GetWritableBytes(const OHIPCParcel *parcel)
```

**Description**

Obtains the number of bytes that can be written to an **OHIPCParcel** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns the number of bytes that can be written to the **OHIPCParcel** object; returns **-1** if invalid parameters are found.|

### OH_IPCParcel_GetReadableBytes()

```C
int OH_IPCParcel_GetReadableBytes(const OHIPCParcel *parcel)
```

**Description**

Obtains the number of bytes that can be read from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns the number of bytes that can be read from the **OHIPCParcel** object; returns **-1** if invalid parameters are found.|

### OH_IPCParcel_GetReadPosition()

```C
int OH_IPCParcel_GetReadPosition(const OH_IPCParcel *parcel)
```

**Description**

Obtains the position where data is read in an **OHIPCParcel** object.

**Parameters**

| Name| Description|
| ---- | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns the current read position obtained if the operation is successful; returns **-1** if invalid parameters are found.|

### OH_IPCParcel_GetWritePosition()

```C
int OH_IPCParcel_GetWritePosition(const OHIPCParcel *parcel)
```

**Description**

Obtains the position where data is written in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ----- | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns the current write position obtained if the operation is successful; returns **-1** if invalid parameters are found.|

### OH_IPCParcel_RewindReadPosition()

```c
int OH_IPCParcel_RewindReadPosition(OHIPCParcel *parcel, uint32_t newReadPos)
```

**Description**

Resets the position to read data in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| uint32_t newReadPos | New position to read data. The value ranges from **0** to the current data size.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found.|

### OH_IPCParcel_RewindWritePosition()

```C
int OH_IPCParcel_RewindWritePosition(OHIPCParcel *parcel, uint32_t newWritePos);
```

**Description**

Resets the position to write data in an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| uint32_t newWritePos | New position to write data. The value ranges from **0** to the current data size.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found.|

### OH_IPCParcel_WriteInt8()

```C
int OH_IPCParcel_WriteInt8(OHIPCParcel *parcel, int8_t value)
```

**Description**

Writes an int8_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC.Core

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int8_t value | Value to write.|

**Returns**

| Type| Description|
| -----| ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadInt8()

```C
int OH_IPCParcel_ReadInt8(OHIPCParcel *parcel, int8_t *value)
```

**Description**

Reads an int8_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int8_t *value | Pointer to the buffer for holding the read data. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|

### OH_IPCParcel_WriteInt16()

```C
int OH_IPCParcel_WriteInt16(OHIPCParcel *parcel, int16_t value)
```

**Description**
Writes an int16_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int16_t value | Value to write.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadInt16()

```C
int OH_IPCParcel_ReadInt16(const OHIPCParcel *parcel, int16_t *value)
```

**Description**

Reads an int16_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int16_t *value | Pointer to the buffer for holding the read data. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|

### OH_IPCParcel_WriteInt32()

```C
int OH_IPCParcel_WriteInt32(OHIPCParcel *parcel, int32_t value)
```

**Description**
Writes an int32_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int32_t value | Value to write.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadInt32()

```C
int OH_IPCParcel_ReadInt32(const OHIPCParcel *parcel, int32_t *value)
```

**Description**

Reads an int32_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int32_t *value | Pointer to the buffer for holding the read data. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|

### OH_IPCParcel_WriteInt64()

```C
int OH_IPCParcel_WriteInt64(OHIPCParcel *parcel, int64_t value)
```

**Description**
Writes an int64_t value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int64_t value | Value to write.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadInt64()

```C
int OH_IPCParcel_ReadInt16(const OHIPCParcel *parcel, int64_t *value)
```

**Description**

Reads an int64_t value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int64_t *value | Pointer to the buffer for holding the read data. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|

### OH_IPCParcel_WriteFloat()

```C
int OH_IPCParcel_WriteFloat(OHIPCParcel *parcel, float value)
```

**Description**
Writes a float value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| float value | Value to write.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadFloat()

```C
int OH_IPCParcel_ReadFloat(const OHIPCParcel *parcel, float *value)
```

**Description**

Reads a float value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| float *value | Pointer to the buffer for holding the read data. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|

### OH_IPCParcel_WriteDouble()

```C
int OH_IPCParcel_WriteDouble(OHIPCParcel *parcel, double value)
```

**Description**
Writes a double value to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| double value | Value to write.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadDouble()

```C
int OH_IPCParcel_ReadDouble(const OHIPCParcel *parcel, double *value)
```

**Description**

Reads a double value from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| double *value | Pointer to the buffer for holding the read data. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|

### OH_IPCParcel_WriteString()

```C
int OH_IPCParcel_WriteString(OHIPCParcel *parcel, const char *str)
```

**Description**
Writes a string including a string terminator to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| const char *str | Pointer to the string to write. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadString()

```C
const OH_IPCParcel_ReadString(const OHIPCParcel *parcel)
```

**Description**

Reads a string from an **OHIPCParcel** object. You can obtain the length of the string from **strlen**.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| const | Returns the address of the string read if the operation is successful; returns NULL if the operation fails or invalid parameters are found.|

### OH_IPCParcel_WriteBuffer()

```C
int OH_IPCParcel_WriteBuffer(OHIPCParcel *parcel, const uint8_t *buffer, int32_t len)
```

**Description**
Writes data of the specified length from the memory to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| const uint8_t *buffer | Pointer to the address of the memory information to write.|
| int32_t len | Length of the data to write.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadBuffer()

```C
const unit8_t* OH_IPCParcel_ReadBuffer(const OHIPCParcel *parcel, int32_t len)
```

**Description**

Reads memory information of the specified length from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int32_t len | Length of the memory to be read.|

**Returns**

| Type| Description|
| ---- | ---- |
| const | Returns the memory address read if the operation is successful; returns NULL if invalid parameters are found or **len** exceeds the readable length of **parcel**.|

### OH_IPCParcel_WriteRemoteStub()

```C
int OH_IPCParcel_WriteRemoteStub(OHIPCParcel *parcel, const OHIPCRemoteStub *stub)
```

**Description**

Writes an **OHIPCRemoteStub** object to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| const [OHIPCRemoteStub](capi-ohipcparcel-ohipcremotestub.md) *stub | Pointer to the **OHIPCRemoteStub** object to write. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadRemoteStub()

```C
OHIPCRemoteStub* OH_IPCParcel_ReadRemoteStub(const OHIPCParcel *parcel)
```

**Description**

Reads the **OHIPCRemoteStub** object from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| OHIPCRemoteStub* | Returns the pointer to the **OHIPCRemoteStub** object read if the operation is successful; returns NULL otherwise.|

### OH_IPCParcel_WriteRemoteProxy()

```C
int OH_IPCParcel_WriteRemoteProxy(OHIPCParcel *parcel, const OHIPCRemoteProxy *proxy)
```

**Description**

Writes an **OHIPCRemoteProxy** object to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| const [OHIPCRemoteProxy](capi-ohipcparcel-ohipcremoteproxy.md) *proxy | Pointer to the **OHIPCRemoteProxy** object to write. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadRemoteProxy()

```C
OHIPCRemoteProxy* OH_IPCParcel_ReadRemoteProxy(const OHIPCParcel *parcel)
```

**Description**

Reads the **OHIPCRemoteProxy** object from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| OHIPCRemoteProxy* | Returns the pointer to the **OHIPCRemoteProxy** object created if the operation is successful; returns NULL otherwise.|

### OH_IPCParcel_WriteFileDescriptor()

```C
int OH_IPCParcel_WriteFileDescriptor(OHIPCParcel *parcel, int32_t fd)
```

**Description**
Writes a file descriptor to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int32_t fd | Pointer to the file descriptor to write.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadFileDescriptor()

```C
const unit8_t* OH_IPCParcel_ReadFileDescriptor(const OHIPCParcel *parcel, int32_t *fd)
```

**Description**

Reads a file descriptor from an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| int32_t *fd | Pointer to the file descriptor to read. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|

### OH_IPCParcel_Append()

```C
const unit8_t* OH_IPCParcel_Append(OHIPCParcel *parcel, const OHIPCParcel *data)
```

**Description**

Appends data to an **OHIPCParcel** object.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| const [OHIPCParcel](capi-ohipcparcel.md) *data | Pointer to the data to append. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the operation fails.|

### OH_IPCParcel_WriteInterfaceToken()

```C
int OH_IPCParcel_WriteInterfaceToken(OHIPCParcel *parcel, const char *token)
```

**Description**
Writes an interface token to an **OHIPCParcel** object for interface identity verification.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| const char *token | Pointer to the interface token to write. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found;<br> returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_WRITE_ERROR](capi-ipc-error-code-h.md) if the write operation fails.|

### OH_IPCParcel_ReadInterfaceToken()

```C
int OH_IPCParcel_ReadInterfaceToken(const OHIPCParcel *parcel, char **token, int32_t *len, OH_IPC_MemAllocator allocator)
```

**Description**

Reads an interface token from an **OHIPCParcel** object for interface identity verification.

**System capability**: SystemCapability.Communication.IPC

**Since**: 12

**Parameters**

| Name| Description|
| ------ | ---- |
| const [OHIPCParcel](capi-ohipcparcel.md) *parcel | Pointer to the **OHIPCParcel** object. It cannot be NULL.|
| char **token | Double pointer to the interface token to read. The memory is allocated by the allocator provided by the user and needs to be released. This pointer cannot be NULL. If an error code is returned, you still need to check whether the memory is empty and release the memory. Otherwise, memory leaks may occur.|
| int32_t *len | Pointer to the length of the interface token read, including the terminator. It cannot be NULL.|
| [OH_IPC_MemAllocator](#oh_ipc_memallocator) allocator | Memory allocator specified by the user for allocating memory for **token**. It cannot be NULL.|

**Returns**

| Type| Description|
| ---- | ---- |
| int | Returns [OH_IPC_ErrorCode#OH_IPC_SUCCESS](capi-ipc-error-code-h.md) if the operation is successful;<br> returns [OH_IPC_ErrorCode#OH_IPC_CHECK_PARAM_ERROR](capi-ipc-error-code-h.md) if invalid parameters are found; returns [OH_IPC_ErrorCode#OH_IPC_PARCEL_READ_ERROR](capi-ipc-error-code-h.md) if the read operation fails.|
