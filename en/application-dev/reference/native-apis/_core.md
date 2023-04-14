# Core


## Overview

Provides the basic backbone capabilities for the media playback framework, including functions related to the memory, error code, and format carrier.

\@syscap SystemCapability.Multimedia.Media.Core

**Since:**
9


## Summary


### Files

| Name | Description | 
| -------- | -------- |
| [native_averrors.h](native__averrors_8h.md) | Declares the error codes used by the media playback framework. <br>File to Include: <multimedia/player_framework/native_averrors.h>  | 
| [native_avformat.h](native__avformat_8h.md) | Declares the format-related functions and enums. <br>File to Include: <multimedia/player_framework/native_avformat.h> | 
| [native_avmemory.h](native__avmemory_8h.md) | Declares the memory-related functions. <br>File to Include: <multimedia/player_framework/native_avmemory.h> | 


### Types

| Name | Description | 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) | Enumerates the audio and video error codes.  | 
| [OH_AVPixelFormat](#oh_avpixelformat) | Enumerates the audio and video pixel formats.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_AVErrCode](#oh_averrcode) {<br/>AV_ERR_OK = 0, AV_ERR_NO_MEMORY = 1, AV_ERR_OPERATE_NOT_PERMIT = 2, AV_ERR_INVALID_VAL = 3,<br/>AV_ERR_IO = 4, AV_ERR_TIMEOUT = 5, AV_ERR_UNKNOWN = 6, AV_ERR_SERVICE_DIED = 7,<br/>AV_ERR_INVALID_STATE = 8, AV_ERR_UNSUPPORT = 9, AV_ERR_EXTEND_START = 100<br/>} | Enumerates the audio and video error codes.  | 
| [OH_AVPixelFormat](#oh_avpixelformat) {<br/>AV_PIXEL_FORMAT_YUVI420 = 1, AV_PIXEL_FORMAT_NV12 = 2, AV_PIXEL_FORMAT_NV21 = 3, AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br/>AV_PIXEL_FORMAT_RGBA = 5<br/>} | Enumerates the audio and video pixel formats.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_AVFormat_Create](#oh_avformat_create) (void) | Creates an **OH_AVFormat** instance for reading and writing data.  | 
| [OH_AVFormat_Destroy](#oh_avformat_destroy) (struct OH_AVFormat \*format) | Destroys an **OH_AVFormat** instance.  | 
| [OH_AVFormat_Copy](#oh_avformat_copy) (struct OH_AVFormat \*to, struct OH_AVFormat \*from) | Copies the resources from an **OH_AVFormat** instance to another.  | 
| [OH_AVFormat_SetIntValue](#oh_avformat_setintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t value) | Writes data of the int type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetLongValue](#oh_avformat_setlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t value) | Writes data of the long type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetFloatValue](#oh_avformat_setfloatvalue) (struct OH_AVFormat \*format, const char \*key, float value) | Writes data of the float type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetDoubleValue](#oh_avformat_setdoublevalue) (struct OH_AVFormat \*format, const char \*key, double value) | Writes data of the double type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetStringValue](#oh_avformat_setstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*value) | Writes data of the string type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetBuffer](#oh_avformat_setbuffer) (struct OH_AVFormat \*format, const char \*key, const uint8_t \*addr, size_t size) | Writes data with a specified size to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetIntValue](#oh_avformat_getintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t \*out) | Reads data of the int type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetLongValue](#oh_avformat_getlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t \*out) | Reads data of the long type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetFloatValue](#oh_avformat_getfloatvalue) (struct OH_AVFormat \*format, const char \*key, float \*out) | Reads data of the float type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetDoubleValue](#oh_avformat_getdoublevalue) (struct OH_AVFormat \*format, const char \*key, double \*out) | Reads data of the double type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetStringValue](#oh_avformat_getstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*\*out) | Reads data of the double type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetBuffer](#oh_avformat_getbuffer) (struct OH_AVFormat \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | Reads data with a specified size from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_DumpInfo](#oh_avformat_dumpinfo) (struct OH_AVFormat \*format) | Dumps the information contained in an**OH_AVFormat** instance as a string.  | 
| [OH_AVMemory_GetAddr](#oh_avmemory_getaddr) (struct OH_AVMemory \*mem) | Obtains the virtual memory address of an **OH_AVMemory** instance.  | 
| [OH_AVMemory_GetSize](#oh_avmemory_getsize) (struct OH_AVMemory \*mem) | Obtains the memory size of an **OH_AVMemory** instance.  | 


## Type Description


### OH_AVErrCode

  
```
typedef enum OH_AVErrCodeOH_AVErrCode
```
**Description**<br>
Enumerates the audio and video error codes.

\@syscap SystemCapability.Multimedia.Media.Core


### OH_AVPixelFormat

  
```
typedef enum OH_AVPixelFormatOH_AVPixelFormat
```
**Description**<br>
Enumerates the audio and video pixel formats.

\@syscap SystemCapability.Multimedia.Media.Core


## Enum Description


### OH_AVErrCode

  
```
enum OH_AVErrCode
```
**Description**<br>
Enumerates the audio and video error codes.

\@syscap SystemCapability.Multimedia.Media.Core

| Name | Description | 
| -------- | -------- |
| AV_ERR_OK  | Operation successful. | 
| AV_ERR_NO_MEMORY  | No memory. | 
| AV_ERR_OPERATE_NOT_PERMIT  | Invalid parameter. | 
| AV_ERR_INVALID_VAL  | Invalid value. | 
| AV_ERR_IO  | I/O error. | 
| AV_ERR_TIMEOUT  | Timeout. | 
| AV_ERR_UNKNOWN  | Unknown error. | 
| AV_ERR_SERVICE_DIED  | Unavailable media service. | 
| AV_ERR_INVALID_STATE  | Unsupported operation in this state. | 
| AV_ERR_UNSUPPORT  | Unsupported API. | 
| AV_ERR_EXTEND_START  | Initial value for extended error codes. | 


### OH_AVPixelFormat

  
```
enum OH_AVPixelFormat
```
**Description**<br>
Enumerates the audio and video pixel formats.

\@syscap SystemCapability.Multimedia.Media.Core

| Name | Description | 
| -------- | -------- |
| AV_PIXEL_FORMAT_YUVI420  | YUV 420 Planar. | 
| AV_PIXEL_FORMAT_NV12  | NV12. YUV 420 Semi-planar. | 
| AV_PIXEL_FORMAT_NV21  | NV21. YVU 420 Semi-planar. | 
| AV_PIXEL_FORMAT_SURFACE_FORMAT  | Surface. | 
| AV_PIXEL_FORMAT_RGBA  | RGBA8888. | 


## Function Description


### OH_AVFormat_Copy()

  
```
bool OH_AVFormat_Copy (struct OH_AVFormat * to, struct OH_AVFormat * from )
```
**Description**<br>
Copies the resources from an **OH_AVFormat** instance to another.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| to | Indicates the handle to the **OH_AVFormat** instance to which the data will be copied.  | 
| from | Indicates the handle to the **OH_AVFormat** instance from which the data will be copied.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_Create()

  
```
struct OH_AVFormat* OH_AVFormat_Create (void )
```
**Description**<br>
Creates an **OH_AVFormat** instance for reading and writing data.

\@syscap SystemCapability.Multimedia.Media.Core

**Returns**

Returns the handle to an **OH_AVFormat** instance.


### OH_AVFormat_Destroy()

  
```
void OH_AVFormat_Destroy (struct OH_AVFormat * format)
```
**Description**<br>
Destroys an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 

**Returns**

void


### OH_AVFormat_DumpInfo()

  
```
const char* OH_AVFormat_DumpInfo (struct OH_AVFormat * format)
```
**Description**<br>
Dumps the information contained in an**OH_AVFormat** instance as a string.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 

**Returns**

Returns the pointer to a collect of strings, each of which consists of a key and value.


### OH_AVFormat_GetBuffer()

  
```
bool OH_AVFormat_GetBuffer (struct OH_AVFormat * format, const char * key, uint8_t ** addr, size_t * size )
```
**Description**<br>
Reads data with a specified size from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to read.  | 
| addr | Indicates the double pointer to the address where the data read is stored. The data read is destroyed when the **OH_AVFormat** instance is destroyed. To hold the data for an extended period of time, copy it to the memory.  | 
| size | Indicates the pointer to the size of the data read.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_GetDoubleValue()

  
```
bool OH_AVFormat_GetDoubleValue (struct OH_AVFormat * format, const char * key, double * out )
```
**Description**<br>
Reads data of the double type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to read.  | 
| out | Indicates the pointer to the data read.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_GetFloatValue()

  
```
bool OH_AVFormat_GetFloatValue (struct OH_AVFormat * format, const char * key, float * out )
```
**Description**<br>
Reads data of the float type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to read.  | 
| out | Indicates the pointer to the data read.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_GetIntValue()

  
```
bool OH_AVFormat_GetIntValue (struct OH_AVFormat * format, const char * key, int32_t * out )
```
**Description**<br>
Reads data of the int type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to read.  | 
| out | Indicates the pointer to the data read.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_GetLongValue()

  
```
bool OH_AVFormat_GetLongValue (struct OH_AVFormat * format, const char * key, int64_t * out )
```
**Description**<br>
Reads data of the long type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to read.  | 
| out | Indicates the pointer to the data read.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_GetStringValue()

  
```
bool OH_AVFormat_GetStringValue (struct OH_AVFormat * format, const char * key, const char ** out )
```
**Description**<br>
Reads data of the double type from an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to read.  | 
| out | Indicates the double pointer to the data read. The data read is updated when **GetString** is called and destroyed when the **OH_AVFormat** instance is destroyed. To hold the data for an extended period of time, copy it to the memory.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_SetBuffer()

  
```
bool OH_AVFormat_SetBuffer (struct OH_AVFormat * format, const char * key, const uint8_t * addr, size_t size )
```
**Description**<br>
Writes data with a specified size to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to write.  | 
| addr | Indicates the pointer to the address where the data is written.  | 
| size | Indicates the size of the data written.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_SetDoubleValue()

  
```
bool OH_AVFormat_SetDoubleValue (struct OH_AVFormat * format, const char * key, double value )
```
**Description**<br>
Writes data of the double type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to write.  | 
| value | Indicates the value of the data to write.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_SetFloatValue()

  
```
bool OH_AVFormat_SetFloatValue (struct OH_AVFormat * format, const char * key, float value )
```
**Description**<br>
Writes data of the float type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to write.  | 
| value | Indicates the value of the data to write.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_SetIntValue()

  
```
bool OH_AVFormat_SetIntValue (struct OH_AVFormat * format, const char * key, int32_t value )
```
**Description**<br>
Writes data of the int type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to write.  | 
| value | Indicates the value of the data to write.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_SetLongValue()

  
```
bool OH_AVFormat_SetLongValue (struct OH_AVFormat * format, const char * key, int64_t value )
```
**Description**<br>
Writes data of the long type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to write.  | 
| value | Indicates the value of the data to write.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVFormat_SetStringValue()

  
```
bool OH_AVFormat_SetStringValue (struct OH_AVFormat * format, const char * key, const char * value )
```
**Description**<br>
Writes data of the string type to an **OH_AVFormat** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| format | Indicates the handle to an **OH_AVFormat** instance.  | 
| key | Indicates the pointer to the key of the data to write.  | 
| value | Indicates the pointer to the value of the data to write.  | 

**Returns**

Returns **TRUE** if the operation is successful.

Returns **FALSE** if the operation fails.


### OH_AVMemory_GetAddr()

  
```
uint8_t* OH_AVMemory_GetAddr (struct OH_AVMemory * mem)
```
**Description**<br>
Obtains the virtual memory address of an **OH_AVMemory** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| mem | Indicates the pointer to an **OH_AVMemory** instance.  | 

**Returns**

Returns the virtual address if the memory is valid.

Returns a null pointer if the memory is invalid.


### OH_AVMemory_GetSize()

  
```
int32_t OH_AVMemory_GetSize (struct OH_AVMemory * mem)
```
**Description**<br>
Obtains the memory size of an **OH_AVMemory** instance.

\@syscap SystemCapability.Multimedia.Media.Core

 **Parameters**

| Name | Description | 
| -------- | -------- |
| mem | Indicates the pointer to an **OH_AVMemory** instance.  | 

**Returns**

Returns the size if the memory is valid.

Returns **-1** if the memory is invalid.
