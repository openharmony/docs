# native_avformat.h


## Overview

Declares the format-related functions and enums.

**Since:**
9

**Related Modules:**

[Core](_core.md)


## Summary


### Types

| Name | Description | 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#oh_avpixelformat) | Enumerates the audio and video pixel formats.  | 


### Enums

| Name | Description | 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#oh_avpixelformat) {<br/>AV_PIXEL_FORMAT_YUVI420 = 1, AV_PIXEL_FORMAT_NV12 = 2, AV_PIXEL_FORMAT_NV21 = 3, AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br/>AV_PIXEL_FORMAT_RGBA = 5<br/>} | Enumerates the audio and video pixel formats.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_AVFormat_Create](_core.md#oh_avformat_create) (void) | Creates an **OH_AVFormat** instance for reading and writing data.  | 
| [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) (struct OH_AVFormat \*format) | Destroys an **OH_AVFormat** instance.  | 
| [OH_AVFormat_Copy](_core.md#oh_avformat_copy) (struct OH_AVFormat \*to, struct OH_AVFormat \*from) | Copies the resources from an **OH_AVFormat** instance to another.  | 
| [OH_AVFormat_SetIntValue](_core.md#oh_avformat_setintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t value) | Writes data of the int type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetLongValue](_core.md#oh_avformat_setlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t value) | Writes data of the long type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetFloatValue](_core.md#oh_avformat_setfloatvalue) (struct OH_AVFormat \*format, const char \*key, float value) | Writes data of the float type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetDoubleValue](_core.md#oh_avformat_setdoublevalue) (struct OH_AVFormat \*format, const char \*key, double value) | Writes data of the double type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetStringValue](_core.md#oh_avformat_setstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*value) | Writes data of the string type to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_SetBuffer](_core.md#oh_avformat_setbuffer) (struct OH_AVFormat \*format, const char \*key, const uint8_t \*addr, size_t size) | Writes data with a specified size to an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetIntValue](_core.md#oh_avformat_getintvalue) (struct OH_AVFormat \*format, const char \*key, int32_t \*out) | Reads data of the int type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetLongValue](_core.md#oh_avformat_getlongvalue) (struct OH_AVFormat \*format, const char \*key, int64_t \*out) | Reads data of the long type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetFloatValue](_core.md#oh_avformat_getfloatvalue) (struct OH_AVFormat \*format, const char \*key, float \*out) | Reads data of the float type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetDoubleValue](_core.md#oh_avformat_getdoublevalue) (struct OH_AVFormat \*format, const char \*key, double \*out) | Reads data of the double type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetStringValue](_core.md#oh_avformat_getstringvalue) (struct OH_AVFormat \*format, const char \*key, const char \*\*out) | Reads data of the double type from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_GetBuffer](_core.md#oh_avformat_getbuffer) (struct OH_AVFormat \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | Reads data with a specified size from an **OH_AVFormat** instance.  | 
| [OH_AVFormat_DumpInfo](_core.md#oh_avformat_dumpinfo) (struct OH_AVFormat \*format) |  Dumps the information contained in an **OH_AVFormat** instance as a string.  | 
