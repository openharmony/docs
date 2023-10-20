# Core


## Overview

The **Core** module provides the basic backbone capabilities for the media playback framework, including functions related to the memory, error code, and format carrier.

\@syscap SystemCapability.Multimedia.Media.Core

**Since**

9


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_averrors.h](native__averrors_8h.md) | Declares the error codes used by the media playback framework.<br>**File to include**: <multimedia/player_framework/native_averrors.h><br>**Library**: libnative_media_core.so| 
| [native_avformat.h](native__avformat_8h.md) | Declares the format-related functions and enums.<br>**File to include**: <multimedia/player_framework/native_avformat.h><br>**Library**: libnative_media_core.so| 
| [native_avmemory.h](native__avmemory_8h.md) | Declares the memory-related functions.<br>**File to include**: <multimedia/player_framework/native_avmemory.h><br>**Library**: libnative_media_core.so| 


### Types

| Name| Description| 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) | Defines an enum that enumerates the audio and video error codes.| 
| [OH_AVPixelFormat](#oh_avpixelformat) | Defines an enum that enumerates the audio and video pixel formats.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) {<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_OK = 0,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_NO_MEMORY = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_OPERATE_NOT_PERMIT = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_INVALID_VAL = 3,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_IO = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_TIMEOUT = 5,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_UNKNOWN = 6,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_SERVICE_DIED = 7,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_INVALID_STATE = 8,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_UNSUPPORT = 9,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_ERR_EXTEND_START = 100<br>} | Enumerates the audio and video error codes.| 
| [OH_AVPixelFormat](#oh_avpixelformat) {<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_YUVI420 = 1,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_NV12 = 2,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_NV21 = 3,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br>&nbsp;&nbsp;&nbsp;&nbsp;AV_PIXEL_FORMAT_RGBA = 5<br>} | Enumerates the audio and video pixel formats.| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVFormat_Create](#oh_avformat_create) (void) | Creates an **OH_AVFormat** instance for reading data.| 
| \*[OH_AVFormat_CreateAudioFormat](#oh_avformat_createaudioformat) (const char \*mimeType, int32_t sampleRate, int32_t channelCount) | Creates an audio **OH_AVFormat** instance for reading and writing data.| 
| \*[OH_AVFormat_CreateVideoFormat](#oh_avformat_createvideoformat) (const char \*mimeType, int32_t width, int32_t height) | Creates a video **OH_AVFormat** instance for reading and writing data.| 
| [OH_AVFormat_Destroy](#oh_avformat_destroy) (struct OH_AVFormat \*format) | Destroys an **OH_AVFormat** instance.| 
| [OH_AVFormat_Copy](#oh_avformat_copy) (struct OH_AVFormat \*to, struct OH_AVFormat \*from) | Copies an **OH_AVFormat** instance.| 
| [OH_AVFormat_SetIntValue](#oh_avformat_setintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t value) | Writes data of the int type to an **OH_AVFormat** instance.| 
| [OH_AVFormat_SetLongValue](#oh_avformat_setlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t value) | Writes data of the long type to an **OH_AVFormat** instance.| 
| [OH_AVFormat_SetFloatValue](#oh_avformat_setfloatvalue) (struct OH_AVFormat \*format, const char \*key, float value) | Writes data of the float type to an **OH_AVFormat** instance.| 
| [OH_AVFormat_SetDoubleValue](#oh_avformat_setdoublevalue) (struct OH_AVFormat \*format, const char \*key, double value) | Writes data of the double type to an **OH_AVFormat** instance.| 
| [OH_AVFormat_SetStringValue](#oh_avformat_setstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*value) | Writes data of the string type to an **OH_AVFormat** instance.| 
| [OH_AVFormat_SetBuffer](#oh_avformat_setbuffer) (struct OH_AVFormat \*format, const char \*key, const uint8_t \*addr, size_t size) | Writes data blocks of a specified length to an **OH_AVFormat** instance.| 
| [OH_AVFormat_GetIntValue](#oh_avformat_getintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t \*out) | Reads data of the int type from an **OH_AVFormat** instance.| 
| [OH_AVFormat_GetLongValue](#oh_avformat_getlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t \*out) | Reads data of the long type from an **OH_AVFormat** instance.| 
| [OH_AVFormat_GetFloatValue](#oh_avformat_getfloatvalue) (struct OH_AVFormat \*format, const char \*key, float \*out) | Reads data of the float type from an **OH_AVFormat** instance.| 
| [OH_AVFormat_GetDoubleValue](#oh_avformat_getdoublevalue) (struct OH_AVFormat \*format, const char \*key, double \*out) | Reads data of the double type from an **OH_AVFormat** instance.| 
| [OH_AVFormat_GetStringValue](#oh_avformat_getstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*\*out) | Reads data of the string type from an **OH_AVFormat** instance.| 
| [OH_AVFormat_GetBuffer](#oh_avformat_getbuffer) (struct OH_AVFormat \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | Reads data blocks of a specified length from an **OH_AVFormat** instance.| 
| \*[OH_AVFormat_DumpInfo](#oh_avformat_dumpinfo) (struct OH_AVFormat \*format) | Dumps the information contained in an **OH_AVFormat** instance as a string.| 
| \*[OH_AVMemory_Create](#oh_avmemory_create) (int32_t size) | Creates an **OH_AVMemory** instance.| 
| \*[OH_AVMemory_GetAddr](#oh_avmemory_getaddr) (struct OH_AVMemory \*mem) | Obtains the virtual memory address of an **OH_AVMemory** instance.| 
| [OH_AVMemory_GetSize](#oh_avmemory_getsize) (struct OH_AVMemory \*mem) | Obtains the memory size of an **OH_AVMemory** instance.| 
| [OH_AVMemory_Destroy](#oh_avmemory_destroy) (struct OH_AVMemory \*mem) | Releases an **OH_AVMemory** instance.| 


## Type Description


### OH_AVErrCode

  
```
typedef enum OH_AVErrCode OH_AVErrCode
```

**Description**

Defines an enum that enumerates the audio and video error codes.

\@syscap SystemCapability.Multimedia.Media.Core

**Since**

9


### OH_AVPixelFormat

  
```
typedef enum OH_AVPixelFormat OH_AVPixelFormat
```

**Description**

Defines an enum that enumerates the video pixel formats.

\@syscap SystemCapability.Multimedia.Media.Core

**Since**

9


## Enum Description


### OH_AVErrCode

  
```
enum OH_AVErrCode
```

**Description**

Enumerates the audio and video error codes.

\@syscap SystemCapability.Multimedia.Media.Core

**Since**

9

| Value| Description|
| -------- | -------- |
| AV_ERR_OK | Operation successful.| 
| AV_ERR_NO_MEMORY | No memory.| 
| AV_ERR_OPERATE_NOT_PERMIT | Operation not allowed.| 
| AV_ERR_INVALID_VAL | Invalid value.| 
| AV_ERR_IO | I/O error.| 
| AV_ERR_TIMEOUT | Timeout.| 
| AV_ERR_UNKNOWN | Unknown error.| 
| AV_ERR_SERVICE_DIED | Unavailable service.| 
| AV_ERR_INVALID_STATE | Unsupported operation in this state.| 
| AV_ERR_UNSUPPORT | Unsupported API.| 
| AV_ERR_EXTEND_START | Initial value for extended error codes.| 


### OH_AVPixelFormat

  
```
enum OH_AVPixelFormat
```

**Description**

Enumerates the video pixel formats.

\@syscap SystemCapability.Multimedia.Media.Core

**Since**

9

| Value| Description|
| -------- | -------- |
| AV_PIXEL_FORMAT_YUVI420 | YUV 420 Planar.| 
| AV_PIXEL_FORMAT_NV12 | NV12. YUV 420 semi-planar.| 
| AV_PIXEL_FORMAT_NV21 | NV21. YVU 420 semi-planar.| 
| AV_PIXEL_FORMAT_SURFACE_FORMAT | Surface.| 
| AV_PIXEL_FORMAT_RGBA | RGBA8888.| 


## Function Description


### OH_AVFormat_Copy()

  
```
bool OH_AVFormat_Copy (struct OH_AVFormat *to, struct OH_AVFormat *from)
```

**Description**

Copies an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| to | Handle to the **OH_AVFormat** instance to which the data will be copied.| 
| from | Handle to the **OH_AVFormat** instance from which the data will be copied.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_Create()

  
```
struct OH_AVFormat* OH_AVFormat_Create (void)
```

**Description**

Creates an **OH_AVFormat** instance for reading data.

\@syscap SystemCapability.Multimedia.Media.Core

**Returns**

Returns the pointer to an **OH_AVFormat** instance.

**Since**

9


### OH_AVFormat_CreateAudioFormat()

  
```
struct OH_AVFormat* OH_AVFormat_CreateAudioFormat (const char *mimeType, int32_t sampleRate, int32_t channelCount)
```

**Description**

Creates an audio **OH_AVFormat** instance for reading and writing data.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| mimeType | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables).| 
| sampleRate | Sampling rate, in Hz.| 
| channelCount | Number of audio channels. For example, 1 indicates mono and 2 indicates stereo.| 

**Returns**

Returns the pointer to an **OH_AVFormat** instance.

**Since**

10


### OH_AVFormat_CreateVideoFormat()

  
```
struct OH_AVFormat* OH_AVFormat_CreateVideoFormat (const char *mimeType, int32_t width, int32_t height)
```

**Description**

Creates a video **OH_AVFormat** instance for reading and writing data.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| mimeType | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables).| 
| width | Video width, in pixels.| 
| height | Video height, in pixels.| 

**Returns**

Returns the pointer to an **OH_AVFormat** instance.

**Since**

10


### OH_AVFormat_Destroy()

  
```
void OH_AVFormat_Destroy (struct OH_AVFormat *format)
```

**Description**

Destroys an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 

**Since**

9


### OH_AVFormat_DumpInfo()

  
```
const char* OH_AVFormat_DumpInfo (struct OH_AVFormat *format)
```

**Description**

Dumps the information contained in an **OH_AVFormat** instance as a string.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 

**Returns**

Returns the pointer to a collection of strings, each of which consists of a key and value.

**Since**

9


### OH_AVFormat_GetBuffer()

  
```
bool OH_AVFormat_GetBuffer (struct OH_AVFormat *format, const char *key, uint8_t **addr, size_t *size)
```

**Description**

Reads data blocks of a specified length from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| addr | Double pointer to the address where the data read is stored. The data read is destroyed when the **OH_AVFormat** instance is destroyed. To hold the data for an extended period of time, copy it to the memory.| 
| size | Pointer to the size of the data read.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_GetDoubleValue()

  
```
bool OH_AVFormat_GetDoubleValue (struct OH_AVFormat *format, const char *key, double *out)
```

**Description**

Reads data of the double type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_GetFloatValue()

  
```
bool OH_AVFormat_GetFloatValue (struct OH_AVFormat *format, const char *key, float *out)
```

**Description**

Reads data of the float type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_GetIntValue()

  
```
bool OH_AVFormat_GetIntValue (struct OH_AVFormat *format, const char *key, int32_t *out)
```

**Description**

Reads data of the int type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.


### OH_AVFormat_GetLongValue()

  
```
bool OH_AVFormat_GetLongValue (struct OH_AVFormat *format, const char *key, int64_t *out)
```

**Description**

Reads data of the long type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_GetStringValue()

  
```
bool OH_AVFormat_GetStringValue (struct OH_AVFormat *format, const char *key, const char **out)
```

**Description**

Reads data of the string type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Double pointer to the data read. The data read is destroyed when the **OH_AVFormat** instance is destroyed. To hold the data for an extended period of time, copy it to the memory.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_SetBuffer()

  
```
bool OH_AVFormat_SetBuffer (struct OH_AVFormat *format, const char *key, const uint8_t *addr, size_t size)
```

**Description**

Writes data blocks of a specified length to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| addr | Pointer to the address where the data is written.| 
| size | Size of the data written.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_SetDoubleValue()

  
```
bool OH_AVFormat_SetDoubleValue (struct OH_AVFormat *format, const char *key, double value)
```

**Description**

Writes data of the double type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_SetFloatValue()

  
```
bool OH_AVFormat_SetFloatValue (struct OH_AVFormat *format, const char *key, float value)
```

**Description**

Writes data of the float type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_SetIntValue()

  
```
bool OH_AVFormat_SetIntValue (struct OH_AVFormat *format, const char *key, int32_t value)
```

**Description**

Writes data of the int type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_SetLongValue()

  
```
bool OH_AVFormat_SetLongValue (struct OH_AVFormat *format, const char *key, int64_t value)
```

**Description**

Writes data of the long type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVFormat_SetStringValue()

  
```
bool OH_AVFormat_SetStringValue (struct OH_AVFormat *format, const char *key, const char *value)
```

**Description**

Writes data of the string type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **true** if the operation is successful; returns **false** otherwise.

**Since**

9


### OH_AVMemory_Create()

  
```
OH_AVMemory* OH_AVMemory_Create (int32_t size)
```

**Description**

Creates an **OH_AVMemory** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| size | Size of the created memory, in bytes.| 

**Returns**

Returns the pointer to the **OH_AVMemory** instance created if the operation is successful; returns a null pointer otherwise. The instance must be released by calling **OH_AVMemory_Destroy** when it is no longer required.

**Since**

10


### OH_AVMemory_Destroy()

  
```
OH_AVErrCode OH_AVMemory_Destroy (struct OH_AVMemory *mem)
```

**Description**

Releases an **OH_AVMemory** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| mem | Pointer to an **OH_AVMemory** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](#oh_averrcode) otherwise.

**Since**

10


### OH_AVMemory_GetAddr()

  
```
uint8_t* OH_AVMemory_GetAddr (struct OH_AVMemory *mem)
```

**Description**

Obtains the virtual memory address of an **OH_AVMemory** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| mem | Pointer to an **OH_AVMemory** instance.| 

**Returns**

Returns the pointer to the virtual memory address if the memory is valid; returns a null pointer otherwise.

**Since**

9


### OH_AVMemory_GetSize()

  
```
int32_t OH_AVMemory_GetSize (struct OH_AVMemory *mem)
```

**Description**

Obtains the memory size of an **OH_AVMemory** instance.

\@syscap SystemCapability.Multimedia.Media.Core

**Parameters**

| Name| Description| 
| -------- | -------- |
| mem | Pointer to an **OH_AVMemory** instance.| 

**Returns**

Returns the memory size if the memory is valid; returns **-1** otherwise.

**Since**

9
