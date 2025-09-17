# native_avformat.h

## Overview

The file declares the functions and enums related to OH_AVFormat.

**File to include**: <multimedia/player_framework/native_avformat.h>

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](capi-core.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) | OH_AVFormat | Describes a native object for the OH_AVFormat interface.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVPixelFormat](#oh_avpixelformat) | OH_AVPixelFormat | Enumerates the video pixel formats.|

### Functions

| Name| Description|
| -- | -- |
| [struct OH_AVFormat *OH_AVFormat_Create(void)](#oh_avformat_create) | Create an OH_AVFormat instance for reading data.|
| [struct OH_AVFormat *OH_AVFormat_CreateAudioFormat(const char *mimeType,int32_t sampleRate,int32_t channelCount)](#oh_avformat_createaudioformat) | Creates an audio OH_AVFormat instance with specified parameters for reading and writing data.|
| [struct OH_AVFormat *OH_AVFormat_CreateVideoFormat(const char *mimeType,int32_t width,int32_t height)](#oh_avformat_createvideoformat) | Creates a video OH_AVFormat instance with specified parameters for reading and writing data.|
| [void OH_AVFormat_Destroy(struct OH_AVFormat *format)](#oh_avformat_destroy) | Destroys an OH_AVFormat instance. The instance cannot be destroyed repeatedly.|
| [bool OH_AVFormat_Copy(struct OH_AVFormat *to, struct OH_AVFormat *from)](#oh_avformat_copy) | Copies an OH_AVFormat instance.|
| [bool OH_AVFormat_SetIntValue(struct OH_AVFormat *format, const char *key, int32_t value)](#oh_avformat_setintvalue) | Assigns a value of the int type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_SetLongValue(struct OH_AVFormat *format, const char *key, int64_t value)](#oh_avformat_setlongvalue) | Assigns a value of the long type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_SetFloatValue(struct OH_AVFormat *format, const char *key, float value)](#oh_avformat_setfloatvalue) | Assigns a value of the float type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_SetDoubleValue(struct OH_AVFormat *format, const char *key, double value)](#oh_avformat_setdoublevalue) | Assigns a value of the double type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_SetStringValue(struct OH_AVFormat *format, const char *key, const char *value)](#oh_avformat_setstringvalue) | Assigns a value of the string type to a key in an OH_AVFormat instance.|
| [bool OH_AVFormat_SetBuffer(struct OH_AVFormat *format, const char *key, const uint8_t *addr, size_t size)](#oh_avformat_setbuffer) | Writes data blocks of a specified length to an OH_AVFormat instance.|
| [bool OH_AVFormat_GetIntValue(struct OH_AVFormat *format, const char *key, int32_t *out)](#oh_avformat_getintvalue) | Obtains the value of the int type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_GetLongValue(struct OH_AVFormat *format, const char *key, int64_t *out)](#oh_avformat_getlongvalue) | Obtains the value of the long type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_GetFloatValue(struct OH_AVFormat *format, const char *key, float *out)](#oh_avformat_getfloatvalue) | Obtains the value of the float type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_GetDoubleValue(struct OH_AVFormat *format, const char *key, double *out)](#oh_avformat_getdoublevalue) | Obtains the value of the double type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_GetStringValue(struct OH_AVFormat *format, const char *key, const char **out)](#oh_avformat_getstringvalue) | Obtains the value of the string type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.|
| [bool OH_AVFormat_GetBuffer(struct OH_AVFormat *format, const char *key, uint8_t **addr, size_t *size)](#oh_avformat_getbuffer) | Reads data blocks of a specified length from an OH_AVFormat instance.|
| [bool OH_AVFormat_GetIntBuffer(struct OH_AVFormat *format, const char *key, int32_t **addr, size_t *size)](#oh_avformat_getintbuffer) | Reads an array of int32_t data from an OH_AVFormat instance. Note that the buffer lifecycle is bound to the OH_AVFormat instance. The buffer becomes invalid automatically when the OH_AVFormat instance is destroyed.<br>To keep the data for an extended period, explicitly copy the data to newly allocated memory.|
| [const char *OH_AVFormat_DumpInfo(struct OH_AVFormat *format)](#oh_avformat_dumpinfo) | Returns a string consisting of key-value pairs in an OH_AVFormat instance. A string of up to 1024 bytes can be returned. The string pointer is released when the OH_AVFormat instance is destroyed.|
| [bool OH_AVFormat_SetIntBuffer(struct OH_AVFormat *format, const char *key, const int32_t *addr, size_t size)](#oh_avformat_setintbuffer) | Writes data blocks of the int32_t type with a specified length to an OH_AVFormat instance.|

## Enum Description

### OH_AVPixelFormat

```
enum OH_AVPixelFormat
```

**Description**

Enumerates the video pixel formats.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

| Value| Description|
| -- | -- |
| AV_PIXEL_FORMAT_YUVI420 = 1 | YUV 420 Planar.|
| AV_PIXEL_FORMAT_NV12 = 2 | NV12. YUV 420 semi-planar.|
| AV_PIXEL_FORMAT_NV21 = 3 | NV21. YVU 420 semi-planar.|
| AV_PIXEL_FORMAT_SURFACE_FORMAT = 4 | Pixel format obtained from the surface. This value takes effect only in surface mode.|
| AV_PIXEL_FORMAT_RGBA = 5 | RGBA8888.|
| AV_PIXEL_FORMAT_RGBA1010102 = 6 | RGBA1010102.<br>**Since**: 20|


## Function Description

### OH_AVFormat_Create()

```
struct OH_AVFormat *OH_AVFormat_Create(void)
```

**Description**

Create an OH_AVFormat instance for reading data.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) * | Pointer to an OH_AVFormat instance. If system resources are insufficient, NULL is returned.|

### OH_AVFormat_CreateAudioFormat()

```
struct OH_AVFormat *OH_AVFormat_CreateAudioFormat(const char *mimeType,int32_t sampleRate,int32_t channelCount)
```

**Description**

Creates an audio OH_AVFormat instance with specified parameters for reading and writing data.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| const char *mimeType | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](capi-native-avcodec-base-h.md#variables).|
| int32_t sampleRate | Sampling rate, in Hz.|
| int32_t channelCount | Number of audio channels. For example, 1 indicates mono and 2 indicates stereo.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) * | Pointer to the OH_AVFormat instance created. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **mimeType** is NULL.<br>2. System resources are insufficient.|

### OH_AVFormat_CreateVideoFormat()

```
struct OH_AVFormat *OH_AVFormat_CreateVideoFormat(const char *mimeType,int32_t width,int32_t height)
```

**Description**

Creates a video OH_AVFormat instance with specified parameters for reading and writing data.

**System capability**: SystemCapability.Multimedia.Media.Core


**Parameters**

| Name| Description|
| -- | -- |
| const char *mimeType | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](capi-native-avcodec-base-h.md#variables).|
| int32_t width | Luminance width, in pixels.|
| int32_t height | Luminance height, in pixels.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) * | Pointer to the OH_AVFormat instance created. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **mimeType** is NULL.<br>2. System resources are insufficient.|

### OH_AVFormat_Destroy()

```
void OH_AVFormat_Destroy(struct OH_AVFormat *format)
```

**Description**

Destroys an OH_AVFormat instance. The instance cannot be destroyed repeatedly.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|

### OH_AVFormat_Copy()

```
bool OH_AVFormat_Copy(struct OH_AVFormat *to, struct OH_AVFormat *from)
```

**Description**

Copies an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *to | Pointer to the OH_AVFormat instance to which the data will be copied.|
| [struct OH_AVFormat](capi-core-oh-avformat.md) *from | Pointer to the OH_AVFormat instance from which the data will be copied.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The input parameter is nullptr.<br>2. The value of **OH_AVFormat** fails parameter structure verification.|

### OH_AVFormat_SetIntValue()

```
bool OH_AVFormat_SetIntValue(struct OH_AVFormat *format, const char *key, int32_t value)
```

**Description**

Assigns a value of the int type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance. This function can be used to set only parameters of the int type. For details, see [native_avcodec_base.h](capi-native-avcodec-base-h.md#variables).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to write.|
| int32_t value | Value of the data to write.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value type corresponding to the key is incorrect.|

### OH_AVFormat_SetLongValue()

```
bool OH_AVFormat_SetLongValue(struct OH_AVFormat *format, const char *key, int64_t value)
```

**Description**

Assigns a value of the long type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance. This function can be used to set only parameters of the long type. For details, see [native_avcodec_base.h](capi-native-avcodec-base-h.md#variables).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to write.|
| int64_t value | Value of the data to write.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value type corresponding to the key is incorrect.|

### OH_AVFormat_SetFloatValue()

```
bool OH_AVFormat_SetFloatValue(struct OH_AVFormat *format, const char *key, float value)
```

**Description**

Assigns a value of the float type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance. This function can be used to set only parameters of the float type. For details, see [native_avcodec_base.h](capi-native-avcodec-base-h.md#variables).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to write.|
| float value | Value of the data to write.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value type corresponding to the key is incorrect.|

### OH_AVFormat_SetDoubleValue()

```
bool OH_AVFormat_SetDoubleValue(struct OH_AVFormat *format, const char *key, double value)
```

**Description**

Assigns a value of the double type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance. This function can be used to set only parameters of the double type. For details, see [native_avcodec_base.h](capi-native-avcodec-base-h.md#variables).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to write.|
| double value | Value of the data to write.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value type corresponding to the key is incorrect.|

### OH_AVFormat_SetStringValue()

```
bool OH_AVFormat_SetStringValue(struct OH_AVFormat *format, const char *key, const char *value)
```

**Description**

Assigns a value of the string type to a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance. This function can be used to set only parameters of the string type. For details, see [native_avcodec_base.h](capi-native-avcodec-base-h.md#variables).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to write.|
| const char *value | Pointer to the data to be written to the string. The length should not exceed 256 bytes.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The passed-in value of **value** is a null pointer.<br>5. The value type corresponding to the key is incorrect.|

### OH_AVFormat_SetBuffer()

```
bool OH_AVFormat_SetBuffer(struct OH_AVFormat *format, const char *key, const uint8_t *addr, size_t size)
```

**Description**

Writes data blocks of a specified length to an OH_AVFormat instance. This function can be used to set only parameters of the buffer type. For details, see [native_avcodec_base.h](capi-native-avcodec-base-h.md#variables).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to write.|
| const uint8_t *addr | Pointer to the address to which data is written. The lifecycle is managed by the developer.|
| size_t size | Length of the data written, in MB. The value range is (0, 1].|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **addr** is nullptr.<br>5. The size is 0 or exceeds the upper limit 1 MB.<br>6. The value type corresponding to the key is incorrect.|

### OH_AVFormat_GetIntValue()

```
bool OH_AVFormat_GetIntValue(struct OH_AVFormat *format, const char *key, int32_t *out)
```

**Description**

Obtains the value of the int type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to read.|
| int32_t *out | Pointer to the value of the data read.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **out** is nullptr.<br>5. The obtained key does not exist or is not set.|

### OH_AVFormat_GetLongValue()

```
bool OH_AVFormat_GetLongValue(struct OH_AVFormat *format, const char *key, int64_t *out)
```

**Description**

Obtains the value of the long type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to read.|
| int64_t *out | Pointer to the value of the data read.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **out** is nullptr.<br>5. The obtained key does not exist or is not set.|

### OH_AVFormat_GetFloatValue()

```
bool OH_AVFormat_GetFloatValue(struct OH_AVFormat *format, const char *key, float *out)
```

**Description**

Obtains the value of the float type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to read.|
| float *out | Pointer to the value of the data read.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **out** is nullptr.<br>5. The obtained key does not exist or is not set.|

### OH_AVFormat_GetDoubleValue()

```
bool OH_AVFormat_GetDoubleValue(struct OH_AVFormat *format, const char *key, double *out)
```

**Description**

Obtains the value of the double type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to read.|
| double *out | Pointer to the value of the data read.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **out** is nullptr.<br>5. The obtained key does not exist or is not set.|

### OH_AVFormat_GetStringValue()

```
bool OH_AVFormat_GetStringValue(struct OH_AVFormat *format, const char *key, const char **out)
```

**Description**

Obtains the value of the string type of a [key](capi-codecbase.md#media-data-key-value-pairs) in an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to read.|
| const char **out | Double pointer to the string read. The lifecycle of the **out** data matches the string in **format**. To keep the **out** data for an extended period of time, you must copy it to the memory. The maximum length of the output string is 256 bytes. If the length exceeds 256 bytes, **false** is returned.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **out** is nullptr.<br>5. The system resources are insufficient.<br>6. The obtained key does not exist or is not set.<br>7. The length of the **out** data exceeds 256 bytes.|

### OH_AVFormat_GetBuffer()

```
bool OH_AVFormat_GetBuffer(struct OH_AVFormat *format, const char *key, uint8_t **addr, size_t *size)
```

**Description**

Reads data blocks of a specified length from an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to read.|
| uint8_t **addr | Double pointer to the address where the data read is stored. The data read is destroyed when the OH_AVFormat instance is destroyed. To hold the data for an extended period of time, copy it to the memory.|
| size_t *size | Pointer to the size of the data read.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **addr** is nullptr.<br>5. The value of **size** is nullptr.<br>6. The obtained key does not exist or is not set.|

### OH_AVFormat_GetIntBuffer()

```
bool OH_AVFormat_GetIntBuffer(struct OH_AVFormat *format, const char *key, int32_t **addr, size_t *size)
```

**Description**

Reads an array of int32_t data from an OH_AVFormat instance.

Note that the buffer lifecycle is bound to the OH_AVFormat instance. The buffer becomes invalid automatically when the OH_AVFormat instance is destroyed.

To keep the data for an extended period, explicitly copy the data to newly allocated memory.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to read.|
| int32_t **addr | Double pointer to the memory where the data is stored.|
| size_t *size | Pointer to the number of elements read.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **addr** is nullptr.<br>5. The value of **size** is nullptr.|

### OH_AVFormat_DumpInfo()

```
const char *OH_AVFormat_DumpInfo(struct OH_AVFormat *format)
```

**Description**

Returns a string consisting of key-value pairs in an OH_AVFormat instance. A string of up to 1024 bytes can be returned. The string pointer is released when the OH_AVFormat instance is destroyed.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|

**Returns**

| Type| Description|
| -- | -- |
| const char * | A string consisting of key-value pairs. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is NULL.<br>2. System resources are insufficient.|

### OH_AVFormat_SetIntBuffer()

```
bool OH_AVFormat_SetIntBuffer(struct OH_AVFormat *format, const char *key, const int32_t *addr, size_t size)
```

**Description**

Writes data blocks of the int32_t type with a specified length to an OH_AVFormat instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to an OH_AVFormat instance.|
| const char *key | Pointer to the key of the data to write.|
| const int32_t *addr | Pointer to the address to which data is written. The lifecycle is managed by the developer.|
| size_t size | Length of the data to write, in units of elements, not bytes.|

**Returns**

| Type| Description|
| -- | -- |
| bool | **true** if the operation is successful; **false** otherwise.<br>The possible causes of an operation failure are as follows:<br>1. The value of **format** is nullptr.<br>2. The value of **format** fails parameter structure verification.<br>3. The value of **key** is nullptr.<br>4. The value of **addr** is nullptr.<br>5. The value of **size** is nullptr.|
