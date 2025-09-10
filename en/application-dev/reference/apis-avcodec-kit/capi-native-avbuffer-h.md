# native_avbuffer.h

## Overview

The file declares the functions of the media struct AVBuffer.

**File to include**: <multimedia/player_framework/native_avbuffer.h>

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Related module**: [Core](capi-core.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) | OH_AVBuffer | Describes a native object for the media memory interface.|
| [OH_NativeBuffer](capi-core-oh-nativebuffer.md) | OH_NativeBuffer | Describes a native object for the graphics memory interface.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVBuffer *OH_AVBuffer_Create(int32_t capacity)](#oh_avbuffer_create) | Creates an OH_AVBuffer instance. You must call [OH_AVBuffer_Destroy](capi-native-avbuffer-h.md#oh_avbuffer_destroy) to manually release the OH_AVBuffer instance returned.|
| [OH_AVErrCode OH_AVBuffer_Destroy(OH_AVBuffer *buffer)](#oh_avbuffer_destroy) | Releases an OH_AVBuffer instance. A buffer cannot be destroyed repeatedly.|
| [OH_AVErrCode OH_AVBuffer_GetBufferAttr(OH_AVBuffer *buffer, OH_AVCodecBufferAttr *attr)](#oh_avbuffer_getbufferattr) | Obtains the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.|
| [OH_AVErrCode OH_AVBuffer_SetBufferAttr(OH_AVBuffer *buffer, const OH_AVCodecBufferAttr *attr)](#oh_avbuffer_setbufferattr) | Sets the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.|
| [OH_AVFormat *OH_AVBuffer_GetParameter(OH_AVBuffer *buffer)](#oh_avbuffer_getparameter) | Obtains parameters except basic attributes of a buffer. The information is carried in an OH_AVFormat instance. You must call [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) to manually release the OH_AVFormat instance returned.|
| [OH_AVErrCode OH_AVBuffer_SetParameter(OH_AVBuffer *buffer, const OH_AVFormat *format)](#oh_avbuffer_setparameter) | Sets parameters except basic attributes of a buffer. The information is carried in an OH_AVFormat instance.|
| [uint8_t *OH_AVBuffer_GetAddr(OH_AVBuffer *buffer)](#oh_avbuffer_getaddr) | Obtains the virtual address of a data buffer.|
| [int32_t OH_AVBuffer_GetCapacity(OH_AVBuffer *buffer)](#oh_avbuffer_getcapacity) | Obtains the capacity (in bytes) of a buffer.|
| [OH_NativeBuffer *OH_AVBuffer_GetNativeBuffer(OH_AVBuffer *buffer)](#oh_avbuffer_getnativebuffer) | Obtains the pointer to an OH_NativeBuffer instance. You must call **OH_NativeBuffer_Unreference** to release the OH_NativeBuffer instance returned.|

## Function Description

### OH_AVBuffer_Create()

```
OH_AVBuffer *OH_AVBuffer_Create(int32_t capacity)
```

**Description**

Creates an OH_AVBuffer instance. You must call [OH_AVBuffer_Destroy](capi-native-avbuffer-h.md#oh_avbuffer_destroy) to manually release the OH_AVBuffer instance returned.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| int32_t capacity | Size of the created memory, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) * | Pointer to the OH_AVBuffer instance created. If the operation fails, NULL is returned.<br> The possible causes of an operation failure are as follows:<br>1. The value of **capacity** is less than or equal to **0**.<br>2. An internal error occurs, or the system does not have resources.|

### OH_AVBuffer_Destroy()

```
OH_AVErrCode OH_AVBuffer_Destroy(OH_AVBuffer *buffer)
```

**Description**

Releases an OH_AVBuffer instance. A buffer cannot be destroyed repeatedly.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>   **AV_ERR_INVALID_VAL**: The value of **buffer** is nullptr or fails format verification.<br> **AV_ERR_OPERATE_NOT_PERMIT**: The input buffer is not created by the user.|

### OH_AVBuffer_GetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_GetBufferAttr(OH_AVBuffer *buffer, OH_AVCodecBufferAttr *attr)
```

**Description**

Obtains the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|
| [OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) *attr | Pointer to an OH_AVCodecBufferAttr instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The possible causes are as follows:<br>1. The value of **buffer** or **attr** is nullptr.<br>2. The value of **buffer** fails parameter structure verification.|

### OH_AVBuffer_SetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_SetBufferAttr(OH_AVBuffer *buffer, const OH_AVCodecBufferAttr *attr)
```

**Description**

Sets the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|
| [const OH_AVCodecBufferAttr](capi-core-oh-avcodecbufferattr.md) *attr | Pointer to an OH_AVCodecBufferAttr instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The possible causes are as follows:<br>1. The value of **buffer** or **attr** is nullptr.<br>2. The value of **buffer** fails parameter structure verification.<br>3. The memory size or offset of the buffer is invalid.|

### OH_AVBuffer_GetParameter()

```
OH_AVFormat *OH_AVBuffer_GetParameter(OH_AVBuffer *buffer)
```

**Description**

Obtains parameters except basic attributes of a buffer. The information is carried in an OH_AVFormat instance. You must call [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) to manually release the OH_AVFormat instance returned.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The possible causes are as follows:<br>1. The value of **buffer** is nullptr.<br>2. The meta of the buffer is nullptr.<br>3. The value of **buffer** fails parameter structure verification.|

### OH_AVBuffer_SetParameter()

```
OH_AVErrCode OH_AVBuffer_SetParameter(OH_AVBuffer *buffer, const OH_AVFormat *format)
```

**Description**

Sets parameters except basic attributes of a buffer. The information is carried in an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|
| [const OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The possible causes are as follows:<br>1. The value of **buffer** or **format** is nullptr.<br>2. The meta of the buffer is nullptr.<br>3. The value of **buffer** fails parameter structure verification.|

### OH_AVBuffer_GetAddr()

```
uint8_t *OH_AVBuffer_GetAddr(OH_AVBuffer *buffer)
```

**Description**

Obtains the virtual address of a data buffer.

The capability to obtain virtual addresses varies in scenarios, as described in the table below.

**Encoding**

| Mode| Data Filling Mode|  Capability to Obtain Virtual Addresses|
| --------------- | -------- | -------- |
| Surface| OnNeedInputBuffer input | Not supported|
| Surface| OnNewOutputBuffer output | Supported|
| Buffer | OnNeedInputBuffer input | Supported|
| Buffer | OnNewOutputBuffer output | Supported|

**Decoding**

| Mode| Data Filling Mode|  Capability to Obtain Virtual Addresses|
| --------------- | -------- | -------- |
| Surface| OnNeedInputBuffer input | Supported|
| Surface| OnNewOutputBuffer output | Not supported|
| Buffer | OnNeedInputBuffer input | Supported|
| Buffer | OnNewOutputBuffer output | Supported|

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| uint8_t * | Virtual address. If the operation fails, NULL is returned.<br> The possible causes of an operation failure are as follows:<br> 1. The value of **buffer** is a null pointer.<br>2. The value of **OH_AVBuffer** fails parameter structure verification.<br>3. An internal error occurs.|

### OH_AVBuffer_GetCapacity()

```
int32_t OH_AVBuffer_GetCapacity(OH_AVBuffer *buffer)
```

**Description**

Obtains the capacity (in bytes) of a buffer.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| int32_t | Capacity. If the operation fails, **-1** is returned.<br> The possible causes of an operation failure are as follows:<br>1. The value of **buffer** is a null pointer.<br>2. The value of **OH_AVBuffer** fails parameter structure verification.<br>3. An internal error occurs.|

### OH_AVBuffer_GetNativeBuffer()

```
OH_NativeBuffer *OH_AVBuffer_GetNativeBuffer(OH_AVBuffer *buffer)
```

**Description**

Obtains the pointer to an OH_NativeBuffer instance. You must call [OH_NativeBuffer_Unreference](../apis-arkgraphics2d/capi-native-buffer-h.md#oh_nativebuffer_unreference) to manually release the OH_NativeBuffer instance returned.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVBuffer](capi-core-oh-avbuffer.md) *buffer | Pointer to an OH_AVBuffer instance.|

**Returns**

| Type| Description|
| -- | -- |
| OH_NativeBuffer * | Pointer to the OH_NativeBuffer instance created. If the operation fails, NULL is returned.<br> The possible causes of an operation failure are as follows:<br>1. The value of **buffer** is a null pointer.<br>2. The value of **OH_AVBuffer** fails parameter structure verification.<br>3. An internal error occurs.|
<!--no_check-->