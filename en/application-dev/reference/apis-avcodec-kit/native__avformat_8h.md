# native_avformat.h


## Overview

The file declares the functions and enums related to OH_AVFormat.

**Library**: libnative_media_core.so

**File to include**: <multimedia/player_framework/native_avformat.h>

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Related module**: [Core](_core.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVFormat](_core.md#oh_avformat) [OH_AVFormat](_core.md#oh_avformat) | Defines a struct that describes a native object for the media format interface. |
| typedef enum [OH_AVPixelFormat](_core.md#oh_avpixelformat-1) [OH_AVPixelFormat](_core.md#oh_avpixelformat) | Defines an enum for the video pixel formats.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_AVPixelFormat](_core.md#oh_avpixelformat-1) {<br>AV_PIXEL_FORMAT_YUVI420 = 1,<br>AV_PIXEL_FORMAT_NV12 = 2,<br>AV_PIXEL_FORMAT_NV21 = 3,<br>AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br>AV_PIXEL_FORMAT_RGBA = 5,<br>AV_PIXEL_FORMAT_RGBA1010102 = 6<br>} | Enumerates the video pixel formats.| 


### Functions

| Name| Description| 
| -------- | -------- |
| struct [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVFormat_Create](_core.md#oh_avformat_create) (void) | Create an OH_AVFormat instance for reading and writing data.| 
| struct [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVFormat_CreateAudioFormat](_core.md#oh_avformat_createaudioformat) (const char \*mimeType, int32_t sampleRate, int32_t channelCount) | Creates an audio OH_AVFormat instance with specified parameters for reading and writing data.| 
| struct [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVFormat_CreateVideoFormat](_core.md#oh_avformat_createvideoformat) (const char \*mimeType, int32_t width, int32_t height) | Creates a video OH_AVFormat instance with specified parameters for reading and writing data.| 
| void [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) (struct [OH_AVFormat](_core.md#oh_avformat) \*format) | Destroys an OH_AVFormat instance.| 
| bool [OH_AVFormat_Copy](_core.md#oh_avformat_copy) (struct [OH_AVFormat](_core.md#oh_avformat) \*to, struct [OH_AVFormat](_core.md#oh_avformat) \*from) | Copies an OH_AVFormat instance.| 
| bool [OH_AVFormat_SetIntValue](_core.md#oh_avformat_setintvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int32_t value) | Assigns a value of the int type to a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_SetLongValue](_core.md#oh_avformat_setlongvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int64_t value) | Assigns a value of the long type to a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_SetFloatValue](_core.md#oh_avformat_setfloatvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, float value) | Assigns a value of the float type to a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_SetDoubleValue](_core.md#oh_avformat_setdoublevalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, double value) | Assigns a value of the double type to a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_SetStringValue](_core.md#oh_avformat_setstringvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, const char \*value) | Assigns a value of the string type to a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_SetBuffer](_core.md#oh_avformat_setbuffer) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, const uint8_t \*addr, size_t size) | Writes data blocks of a specified length to an OH_AVFormat instance.| 
| bool [OH_AVFormat_SetIntBuffer](_core.md#oh_avformat_setintbuffer) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, const int32_t \*addr, size_t size) | Writes data blocks of the int32_t type with a specified length to an OH_AVFormat instance.| 
| bool [OH_AVFormat_GetIntValue](_core.md#oh_avformat_getintvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int32_t \*out) | Obtains the value of the int type of a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_GetLongValue](_core.md#oh_avformat_getlongvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int64_t \*out) | Obtains the value of the long type of a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_GetFloatValue](_core.md#oh_avformat_getfloatvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, float \*out) | Obtains the value of the float type of a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_GetDoubleValue](_core.md#oh_avformat_getdoublevalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, double \*out) | Obtains the value of the double type of a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_GetStringValue](_core.md#oh_avformat_getstringvalue) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, const char \*\*out) | Obtains the value of the string type of a key contained in an OH_AVFormat instance.| 
| bool [OH_AVFormat_GetBuffer](_core.md#oh_avformat_getbuffer) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | Reads data blocks of a specified length from an OH_AVFormat instance.| 
| bool [OH_AVFormat_GetIntBuffer](_core.md#oh_avformat_getintbuffer) (struct [OH_AVFormat](_core.md#oh_avformat) \*format, const char \*key, int32_t \*\*addr, size_t \*size) | Reads an array of int32_t data from an OH_AVFormat instance.| 
| const char \* [OH_AVFormat_DumpInfo](_core.md#oh_avformat_dumpinfo) (struct [OH_AVFormat](_core.md#oh_avformat) \*format) | Returns a string consisting of key-value pairs contained in an OH_AVFormat instance.| 
