# Core


## Overview

The Core module provides the basic backbone capabilities for the media framework, including functions related to the memory, error code, and media struct.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [media_types.h](media__types_8h.md) | Declares the common media types.| 
| [native_audio_channel_layout.h](native__audio__channel__layout_8h.md) | Declares the functions related to the speaker layout during recording and playback.| 
| [native_avbuffer.h](native__avbuffer_8h.md) | Declares the functions of the media struct **AVBuffer**.| 
| [native_avbuffer_info.h](native__avbuffer__info_8h.md) | Declares the attribute definition of the media struct **AVBuffer**.| 
| [native_averrors.h](native__averrors_8h.md) | Declares the error codes used by the media framework.| 
| [native_avformat.h](native__avformat_8h.md) | Declares the functions and enums related to **OH_AVFormat**.| 
| [native_avmemory.h](native__avmemory_8h.md) | Declares the attribute definition of the media struct **AVMemory**.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) | Describes the description information about the buffer of an **OH_AVCodec** instance. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_Core_HdrType](#oh_core_hdrtype) [OH_Core_HdrType](#oh_core_hdrtype) | Defines an enum for the HDR types.| 
| typedef enum [OH_AudioChannelSet](#oh_audiochannelset-1) [OH_AudioChannelSet](#oh_audiochannelset) | Defines an enum for the audio channel sets.| 
| typedef enum [OH_AmbAttributeSet](#oh_ambattributeset-1) [OH_AmbAttributeSet](#oh_ambattributeset) | Defines an enum for the Hi-Fi stereo reverberation settings.| 
| typedef enum [OH_AudioChannelLayout](#oh_audiochannellayout-1) [OH_AudioChannelLayout](#oh_audiochannellayout) | Defines an enum for the audio channel layouts.| 
| typedef struct [OH_AVBuffer](#oh_avbuffer) [OH_AVBuffer](#oh_avbuffer) | Defines a struct that describes a native object for the media memory interface.| 
| typedef struct [OH_NativeBuffer](#oh_nativebuffer) [OH_NativeBuffer](#oh_nativebuffer) | Defines a struct that describes a native object for the graphics memory interface.| 
| typedef enum [OH_AVCodecBufferFlags](#oh_avcodecbufferflags-1) [OH_AVCodecBufferFlags](#oh_avcodecbufferflags) | Defines an enum for the flags for the buffer of an **OH_AVCodec** instance.| 
| typedef struct [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) [OH_AVCodecBufferAttr](#oh_avcodecbufferattr) | Defines the description information about the buffer of an **OH_AVCodec** instance.| 
| typedef enum [OH_AVErrCode](#oh_averrcode-1) [OH_AVErrCode](#oh_averrcode) | Defines an enum for the error codes used by the media framework.| 
| typedef struct [OH_AVFormat](#oh_avformat) [OH_AVFormat](#oh_avformat) | Defines a struct for a native object for the **OH_AVFormat** interface.| 
| typedef enum [OH_AVPixelFormat](#oh_avpixelformat-1) [OH_AVPixelFormat](#oh_avpixelformat) | Defines an enum for the video pixel formats.| 
| typedef struct [OH_AVMemory](#oh_avmemory) [OH_AVMemory](#oh_avmemory) | Defines a struct that describes a native object for the audio and video memory interface.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_Core_HdrType](#oh_core_hdrtype-1) {<br> OH_CORE_HDR_TYPE_NONE = 0, <br>OH_CORE_HDR_TYPE_VIVID = 1 } | Enumerates the HDR types.| 
| [OH_AudioChannelSet](#oh_audiochannelset-1) {<br>CH_SET_FRONT_LEFT = 1ULL &lt;&lt; 0U,<br>CH_SET_FRONT_RIGHT = 1ULL &lt;&lt; 1U,<br>CH_SET_FRONT_CENTER = 1ULL &lt;&lt; 2U,<br>CH_SET_LOW_FREQUENCY = 1ULL &lt;&lt; 3U,<br>CH_SET_BACK_LEFT = 1ULL &lt;&lt; 4U,<br>CH_SET_BACK_RIGHT = 1ULL &lt;&lt; 5U,<br>CH_SET_FRONT_LEFT_OF_CENTER = 1ULL &lt;&lt; 6U,<br>CH_SET_FRONT_RIGHT_OF_CENTER = 1ULL &lt;&lt; 7U,<br>CH_SET_BACK_CENTER = 1ULL &lt;&lt; 8U,<br>CH_SET_SIDE_LEFT = 1ULL &lt;&lt; 9U,<br>CH_SET_SIDE_RIGHT = 1ULL &lt;&lt; 10U,<br>CH_SET_TOP_CENTER = 1ULL &lt;&lt; 11U,<br>CH_SET_TOP_FRONT_LEFT = 1ULL &lt;&lt; 12U,<br>CH_SET_TOP_FRONT_CENTER = 1ULL &lt;&lt; 13U,<br>CH_SET_TOP_FRONT_RIGHT = 1ULL &lt;&lt; 14U,<br>CH_SET_TOP_BACK_LEFT = 1ULL &lt;&lt; 15U,<br>CH_SET_TOP_BACK_CENTER = 1ULL &lt;&lt; 16U,<br>CH_SET_TOP_BACK_RIGHT = 1ULL &lt;&lt; 17U,<br>CH_SET_STEREO_LEFT = 1ULL &lt;&lt; 29U,<br>CH_SET_STEREO_RIGHT = 1ULL &lt;&lt; 30U,<br>CH_SET_WIDE_LEFT = 1ULL &lt;&lt; 31U,<br>CH_SET_WIDE_RIGHT = 1ULL &lt;&lt; 32U,<br>CH_SET_SURROUND_DIRECT_LEFT = 1ULL &lt;&lt; 33U,<br>CH_SET_SURROUND_DIRECT_RIGHT = 1ULL &lt;&lt; 34U,<br>CH_SET_LOW_FREQUENCY_2 = 1ULL &lt;&lt; 35U,<br>CH_SET_TOP_SIDE_LEFT = 1ULL &lt;&lt; 36U,<br>CH_SET_TOP_SIDE_RIGHT = 1ULL &lt;&lt; 37U,<br>CH_SET_BOTTOM_FRONT_CENTER = 1ULL &lt;&lt; 38U,<br>CH_SET_BOTTOM_FRONT_LEFT = 1ULL &lt;&lt; 39U,<br>CH_SET_BOTTOM_FRONT_RIGHT = 1ULL &lt;&lt; 40U<br>} | Enumerates the audio channel sets.| 
| [OH_AmbAttributeSet](#oh_ambattributeset-1) {<br>AMB_ORD_1 = 1ULL &lt;&lt; 0U,<br>AMB_ORD_2 = 2ULL &lt;&lt; 0U,<br>AMB_ORD_3 = 3ULL &lt;&lt; 0U,<br>AMB_COM_ACN = 0ULL &lt;&lt; 8U,<br>AMB_COM_FUMA = 1ULL &lt;&lt; 8U,<br>AMB_NOR_N3D = 0ULL &lt;&lt; 12U,<br>AMB_NOR_SN3D = 1ULL &lt;&lt; 12U,<br>AMB_MODE = 1ULL &lt;&lt; 44U<br>} | Enumerates the Hi-Fi stereo reverberation settings.| 
| [OH_AudioChannelLayout](#oh_audiochannellayout-1) {<br>CH_LAYOUT_UNKNOWN = 0ULL,<br>CH_LAYOUT_MONO = CH_SET_FRONT_CENTER,<br>CH_LAYOUT_STEREO = CH_SET_FRONT_LEFT \| CH_SET_FRONT_RIGHT,<br>CH_LAYOUT_STEREO_DOWNMIX = CH_SET_STEREO_LEFT \| CH_SET_STEREO_RIGHT,<br>CH_LAYOUT_2POINT1 = CH_LAYOUT_STEREO \| CH_SET_LOW_FREQUENCY,<br>CH_LAYOUT_3POINT0 = CH_LAYOUT_STEREO \| CH_SET_BACK_CENTER,<br>CH_LAYOUT_SURROUND = CH_LAYOUT_STEREO \| CH_SET_FRONT_CENTER,<br>CH_LAYOUT_3POINT1 = CH_LAYOUT_SURROUND \| CH_SET_LOW_FREQUENCY,<br>CH_LAYOUT_4POINT0 = CH_LAYOUT_SURROUND \| CH_SET_BACK_CENTER,<br>CH_LAYOUT_QUAD_SIDE = CH_LAYOUT_STEREO \| CH_SET_SIDE_LEFT \| CH_SET_SIDE_RIGHT,<br>CH_LAYOUT_QUAD = CH_LAYOUT_STEREO \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br>CH_LAYOUT_2POINT0POINT2 = CH_LAYOUT_STEREO \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br>CH_LAYOUT_AMB_ORDER1_ACN_N3D = AMB_MODE \| AMB_ORD_1 \| AMB_COM_ACN \| AMB_NOR_N3D, CH_LAYOUT_AMB_ORDER1_ACN_SN3D = AMB_MODE \| AMB_ORD_1 \| AMB_COM_ACN \| AMB_NOR_SN3D,<br>CH_LAYOUT_AMB_ORDER1_FUMA = AMB_MODE \| AMB_ORD_1 \| AMB_COM_FUMA,<br>CH_LAYOUT_4POINT1 = CH_LAYOUT_4POINT0 \| CH_SET_LOW_FREQUENCY,<br>CH_LAYOUT_5POINT0 = CH_LAYOUT_SURROUND \| CH_SET_SIDE_LEFT \| CH_SET_SIDE_RIGHT,<br>CH_LAYOUT_5POINT0_BACK = CH_LAYOUT_SURROUND \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br>CH_LAYOUT_2POINT1POINT2 = CH_LAYOUT_2POINT0POINT2 \| CH_SET_LOW_FREQUENCY,<br>CH_LAYOUT_3POINT0POINT2 = CH_LAYOUT_2POINT0POINT2 \| CH_SET_FRONT_CENTER,<br>CH_LAYOUT_5POINT1 = CH_LAYOUT_5POINT0 \| CH_SET_LOW_FREQUENCY,<br>CH_LAYOUT_5POINT1_BACK = CH_LAYOUT_5POINT0_BACK \| CH_SET_LOW_FREQUENCY,<br>CH_LAYOUT_6POINT0 = CH_LAYOUT_5POINT0 \| CH_SET_BACK_CENTER,<br>CH_LAYOUT_3POINT1POINT2 = CH_LAYOUT_3POINT1 \| CH_SET_TOP_FRONT_LEFT \| CH_SET_TOP_FRONT_RIGHT,<br>CH_LAYOUT_6POINT0_FRONT = CH_LAYOUT_QUAD_SIDE \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br>CH_LAYOUT_HEXAGONAL = CH_LAYOUT_5POINT0_BACK \| CH_SET_BACK_CENTER,<br>CH_LAYOUT_6POINT1 = CH_LAYOUT_5POINT1 \| CH_SET_BACK_CENTER,<br>CH_LAYOUT_6POINT1_BACK = CH_LAYOUT_5POINT1_BACK \| CH_SET_BACK_CENTER,<br>CH_LAYOUT_6POINT1_FRONT = CH_LAYOUT_6POINT0_FRONT \| CH_SET_LOW_FREQUENCY,<br>CH_LAYOUT_7POINT0 = CH_LAYOUT_5POINT0 \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br>CH_LAYOUT_7POINT0_FRONT = CH_LAYOUT_5POINT0 \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br>CH_LAYOUT_7POINT1 = CH_LAYOUT_5POINT1 \| CH_SET_BACK_LEFT \| CH_SET_BACK_RIGHT,<br>CH_LAYOUT_OCTAGONAL = CH_LAYOUT_5POINT0 \| CH_SET_BACK_LEFT \| CH_SET_BACK_CENTER \| CH_SET_BACK_RIGHT,<br>CH_LAYOUT_5POINT1POINT2 = CH_LAYOUT_5POINT1 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br>CH_LAYOUT_7POINT1_WIDE = CH_LAYOUT_5POINT1 \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br>CH_LAYOUT_7POINT1_WIDE_BACK = CH_LAYOUT_5POINT1_BACK \| CH_SET_FRONT_LEFT_OF_CENTER \| CH_SET_FRONT_RIGHT_OF_CENTER,<br>CH_LAYOUT_AMB_ORDER2_ACN_N3D = AMB_MODE \| AMB_ORD_2 \| AMB_COM_ACN \| AMB_NOR_N3D,<br>CH_LAYOUT_AMB_ORDER2_ACN_SN3D = AMB_MODE \| AMB_ORD_2 \| AMB_COM_ACN \| AMB_NOR_SN3D,<br>CH_LAYOUT_AMB_ORDER2_FUMA = AMB_MODE \| AMB_ORD_2 \| AMB_COM_FUMA,<br>CH_LAYOUT_5POINT1POINT4,<br>CH_LAYOUT_7POINT1POINT2 = CH_LAYOUT_7POINT1 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br>CH_LAYOUT_7POINT1POINT4,<br>CH_LAYOUT_10POINT2,<br>CH_LAYOUT_9POINT1POINT4 = CH_LAYOUT_7POINT1POINT4 \| CH_SET_WIDE_LEFT \| CH_SET_WIDE_RIGHT,<br>CH_LAYOUT_9POINT1POINT6 = CH_LAYOUT_9POINT1POINT4 \| CH_SET_TOP_SIDE_LEFT \| CH_SET_TOP_SIDE_RIGHT,<br>CH_LAYOUT_HEXADECAGONAL,<br>CH_LAYOUT_AMB_ORDER3_ACN_N3D = AMB_MODE \| AMB_ORD_3 \| AMB_COM_ACN \| AMB_NOR_N3D,<br>CH_LAYOUT_AMB_ORDER3_ACN_SN3D = AMB_MODE \| AMB_ORD_3 \| AMB_COM_ACN \| AMB_NOR_SN3D,<br>CH_LAYOUT_AMB_ORDER3_FUMA = AMB_MODE \| AMB_ORD_3 \| AMB_COM_FUMA,<br>CH_LAYOUT_22POINT2<br>} | Enumerates the audio channel layouts.| 
| [OH_AVCodecBufferFlags](#oh_avcodecbufferflags-1) {<br>AVCODEC_BUFFER_FLAGS_NONE = 0,<br>AVCODEC_BUFFER_FLAGS_EOS = 1 &lt;&lt; 0, AVCODEC_BUFFER_FLAGS_SYNC_FRAME = 1 &lt;&lt; 1, AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME = 1 &lt;&lt; 2,<br>AVCODEC_BUFFER_FLAGS_CODEC_DATA = 1 &lt;&lt; 3, <br>AVCODEC_BUFFER_FLAGS_DISCARD = 1 &lt;&lt; 4, <br>AVCODEC_BUFFER_FLAGS_DISPOSABLE = 1 &lt;&lt; 5<br>} | Enumerates the flags for the buffer of an **OH_AVCodec** instance. | 
| [OH_AVErrCode](#oh_averrcode-1)  {<br>AV_ERR_OK = 0,<br>AV_ERR_NO_MEMORY = 1,<br>AV_ERR_OPERATE_NOT_PERMIT = 2,<br>AV_ERR_INVALID_VAL = 3,<br>AV_ERR_IO = 4,<br>AV_ERR_TIMEOUT = 5,<br>AV_ERR_UNKNOWN = 6,<br>AV_ERR_SERVICE_DIED = 7,<br>AV_ERR_INVALID_STATE = 8,<br>AV_ERR_UNSUPPORT = 9, <br>AV_ERR_UNSUPPORTED_FORMAT = 11,<br>AV_ERR_EXTEND_START = 100,<br>AV_ERR_DRM_BASE = 200,<br>AV_ERR_DRM_DECRYPT_FAILED = 201,<br>AV_ERR_VIDEO_BASE = 300,<br>AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION = 301<br>} | Enumerates the error codes used by the media framework. |
| [OH_AVPixelFormat](#oh_avpixelformat-1) {<br>AV_PIXEL_FORMAT_YUVI420 = 1,<br>AV_PIXEL_FORMAT_NV12 = 2,<br>AV_PIXEL_FORMAT_NV21 = 3,<br>AV_PIXEL_FORMAT_SURFACE_FORMAT = 4,<br>AV_PIXEL_FORMAT_RGBA = 5<br>} | Enumerates the video pixel formats.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVBuffer](#oh_avbuffer) \* [OH_AVBuffer_Create](#oh_avbuffer_create) (int32_t capacity) | Creates an **OH_AVBuffer** instance. You must call [OH_AVBuffer_Destroy](#oh_avbuffer_destroy) to manually release the **OH_AVBuffer** instance returned.| 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_Destroy](#oh_avbuffer_destroy) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | Releases an **OH_AVBuffer** instance.| 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_GetBufferAttr](#oh_avbuffer_getbufferattr) ([OH_AVBuffer](#oh_avbuffer) \*buffer, [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | Obtains the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.| 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_SetBufferAttr](#oh_avbuffer_setbufferattr) ([OH_AVBuffer](#oh_avbuffer) \*buffer, const [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) \*attr) | Sets the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.| 
| [OH_AVFormat](#oh_avformat) \* [OH_AVBuffer_GetParameter](#oh_avbuffer_getparameter) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | Obtains parameters except basic attributes of a buffer. The information is carried in an **OH_AVFormat** instance.| 
| [OH_AVErrCode](#oh_averrcode) [OH_AVBuffer_SetParameter](#oh_avbuffer_setparameter) ([OH_AVBuffer](#oh_avbuffer) \*buffer, const [OH_AVFormat](#oh_avformat) \*format) | Sets parameters except basic attributes of a buffer. The information is carried in an **OH_AVFormat** instance.| 
| uint8_t \* [OH_AVBuffer_GetAddr](#oh_avbuffer_getaddr) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | Obtains the virtual address of a data buffer.| 
| int32_t [OH_AVBuffer_GetCapacity](#oh_avbuffer_getcapacity) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | Obtains the capacity (in bytes) of a buffer.| 
| [OH_NativeBuffer](#oh_nativebuffer) \* [OH_AVBuffer_GetNativeBuffer](#oh_avbuffer_getnativebuffer) ([OH_AVBuffer](#oh_avbuffer) \*buffer) | Obtains the pointer to an **OH_NativeBuffer** instance.| 
| struct [OH_AVFormat](#oh_avformat) \* [OH_AVFormat_Create](#oh_avformat_create) (void) | Create an **OH_AVFormat** instance for reading and writing data.| 
| struct [OH_AVFormat](#oh_avformat) \* [OH_AVFormat_CreateAudioFormat](#oh_avformat_createaudioformat) (const char \*mimeType, int32_t sampleRate, int32_t channelCount) | Creates an audio **OH_AVFormat** instance with specified parameters for reading and writing data.| 
| struct [OH_AVFormat](#oh_avformat) \* [OH_AVFormat_CreateVideoFormat](#oh_avformat_createvideoformat) (const char \*mimeType, int32_t width, int32_t height) | Creates a video **OH_AVFormat** instance with specified parameters for reading and writing data.| 
| void [OH_AVFormat_Destroy](#oh_avformat_destroy) (struct [OH_AVFormat](#oh_avformat) \*format) | Destroys an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_Copy](#oh_avformat_copy) (struct [OH_AVFormat](#oh_avformat) \*to, struct [OH_AVFormat](#oh_avformat) \*from) | Copies an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_SetIntValue](#oh_avformat_setintvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int32_t value) | Assigns a value of the int type to a key in an **OH_AVFormat** instance.|
| bool [OH_AVFormat_SetLongValue](#oh_avformat_setlongvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int64_t value) | Assigns a value of the long type to a key in an **OH_AVFormat** instance.|
| bool [OH_AVFormat_SetFloatValue](#oh_avformat_setfloatvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, float value) | Assigns a value of the float type to a key in an **OH_AVFormat** instance.|
| bool [OH_AVFormat_SetDoubleValue](#oh_avformat_setdoublevalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, double value) | Assigns a value of the double type to a key in an **OH_AVFormat** instance.|
| bool [OH_AVFormat_SetStringValue](#oh_avformat_setstringvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, const char \*value) | Assigns a value of the string type to a key in an **OH_AVFormat** instance.|
| bool [OH_AVFormat_SetBuffer](#oh_avformat_setbuffer) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, const uint8_t \*addr, size_t size) | Writes data blocks of a specified length to an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_GetIntValue](#oh_avformat_getintvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int32_t \*out) | Obtains the value of the int type of a key in an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_GetLongValue](#oh_avformat_getlongvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, int64_t \*out) | Obtains the value of the long type of a key in an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_GetFloatValue](#oh_avformat_getfloatvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, float \*out) | Obtains the value of the float type of a key in an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_GetDoubleValue](#oh_avformat_getdoublevalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, double \*out) | Obtains the value of the double type of a key in an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_GetStringValue](#oh_avformat_getstringvalue) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, const char \*\*out) | Obtains the value of the string type of a key in an **OH_AVFormat** instance.| 
| bool [OH_AVFormat_GetBuffer](#oh_avformat_getbuffer) (struct [OH_AVFormat](#oh_avformat) \*format, const char \*key, uint8_t \*\*addr, size_t \*size) | Reads data blocks of a specified length from an **OH_AVFormat** instance.| 
| const char \* [OH_AVFormat_DumpInfo](#oh_avformat_dumpinfo) (struct [OH_AVFormat](#oh_avformat) \*format) | Returns a string consisting of key-value pairs contained in an **OH_AVFormat**.| 
| [OH_AVMemory](#oh_avmemory) \* [OH_AVMemory_Create](#oh_avmemory_create) (int32_t size) | Creates an **OH_AVMemory** instance. (This function is deprecated in API version 11.)| 
| uint8_t \* [OH_AVMemory_GetAddr](#oh_avmemory_getaddr) (struct [OH_AVMemory](#oh_avmemory) \*mem) | Obtains the virtual memory address. (This function is deprecated in API version 11.)| 
| int32_t [OH_AVMemory_GetSize](#oh_avmemory_getsize) (struct [OH_AVMemory](#oh_avmemory) \*mem) | Obtains the memory length. (This function is deprecated in API version 11.)| 
| [OH_AVErrCode](#oh_averrcode) [OH_AVMemory_Destroy](#oh_avmemory_destroy) (struct [OH_AVMemory](#oh_avmemory) \*mem) | Releases an **OH_AVMemory** instance. (This function is deprecated in API version 11.)| 


## Type Description


### OH_AmbAttributeSet

```
typedef enum OH_AmbAttributeSet OH_AmbAttributeSet
```

**Description**

Defines an enum for the Hi-Fi stereo reverberation settings.

int64_t integers are used to indicate the Hi-Fi stereo reverberation attributes.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


### OH_AudioChannelLayout

```
typedef enum OH_AudioChannelLayout OH_AudioChannelLayout
```

**Description**

Defines an enum for the audio channel layouts.

int64_t integers are used to indicate the appearance and sequence of speakers during recording or playback.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


### OH_AudioChannelSet

```
typedef enum OH_AudioChannelSet OH_AudioChannelSet
```

**Description**

Defines an enum for the audio channel sets.

Each audio channel is mapped to an int64_t variable.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11


### OH_AVBuffer

```
typedef struct OH_AVBuffer OH_AVBuffer
```
**Description**

Defines a struct that describes a native object for the media memory interface.

**Since**: 11


### OH_AVCodecBufferAttr

```
typedef struct OH_AVCodecBufferAttr OH_AVCodecBufferAttr
```

**Description**

Defines the description information about the buffer of an **OH_AVCodec** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


### OH_AVCodecBufferFlags

```
typedef enum OH_AVCodecBufferFlags OH_AVCodecBufferFlags
```

**Description**

Defines an enum for the flags for the buffer of an **OH_AVCodec** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


### OH_AVErrCode

```
typedef enum OH_AVErrCode OH_AVErrCode
```

**Description**

Defines an enum for the error codes used by the media framework.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


### OH_AVFormat

```
typedef struct OH_AVFormat OH_AVFormat
```
**Description**

Defines a struct for a native object for the **OH_AVFormat** interface.

**Since**: 9


### OH_AVMemory

```
typedef struct OH_AVMemory OH_AVMemory
```
**Description**

Defines a struct that describes a native object for the audio and video memory interface.

**Since**: 9


### OH_AVPixelFormat

```
typedef enum OH_AVPixelFormat OH_AVPixelFormat
```

**Description**

Defines an enum for the video pixel formats.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```
**Description**

Defines a struct that describes a native object for the graphics memory interface.

**Since**: 11


### OH_Core_HdrType

```
typedef enum OH_Core_HdrType OH_Core_HdrType
```

**Description**

Defines an enum for the HDR types.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 18


## Enum Description


### OH_AmbAttributeSet

```
enum OH_AmbAttributeSet
```

**Description**

Enumerates the Hi-Fi stereo reverberation settings.

int64_t integers are used to indicate the Hi-Fi stereo reverberation attributes.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| AMB_ORD_1 | First-order Hi-Fi stereo reverberation.| 
| AMB_ORD_2 | Second-order Hi-Fi stereo reverberation.| 
| AMB_ORD_3 | Third-order Hi-Fi stereo reverberation.| 
| AMB_COM_ACN | Hi-Fi stereo reverberation with ACN channel sorting.| 
| AMB_COM_FUMA | Hi-Fi stereo reverberation with FUMA channel sorting.| 
| AMB_NOR_N3D | N3D normalized Hi-Fi stereo reverberation.| 
| AMB_NOR_SN3D | SN3D normalized Hi-Fi stereo reverberation.| 
| AMB_MODE | Audio channel layout for Hi-Fi stereo reverberation.| 


### OH_AudioChannelLayout

```
enum OH_AudioChannelLayout
```

**Description**

Enumerates the audio channel layouts.

int64_t integers are used to indicate the appearance and sequence of speakers during recording or playback.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CH_LAYOUT_UNKNOWN | Unknown.| 
| CH_LAYOUT_MONO | Mono layout; 1 audio channel in total.| 
| CH_LAYOUT_STEREO | Stereo layout; 2 audio channels in total.| 
| CH_LAYOUT_STEREO_DOWNMIX | Stereo downmix layout; 2 audio channels in total.| 
| CH_LAYOUT_2POINT1 | 2.1 layout; 3 audio channels in total.| 
| CH_LAYOUT_3POINT0 | 3.0 layout; 3 audio channels in total.| 
| CH_LAYOUT_SURROUND | Surround; 3 audio channels in total.| 
| CH_LAYOUT_3POINT1 | 3.1 layout; 4 audio channels in total.| 
| CH_LAYOUT_4POINT0 | 4.0 layout; 4 audio channels in total.| 
| CH_LAYOUT_QUAD_SIDE | Quad side layout; 4 audio channels in total.| 
| CH_LAYOUT_QUAD | Quad layout; 4 audio channels in total.| 
| CH_LAYOUT_2POINT0POINT2 | 2.0.2 layout; 4 audio channels in total.| 
| CH_LAYOUT_AMB_ORDER1_ACN_N3D | First-order FOA layout in ACN_N3D (ITU standards); 4 audio channels in total| 
| CH_LAYOUT_AMB_ORDER1_ACN_SN3D | First-order FOA layout in ACN_SN3D (ITU standards); 4 audio channels in total| 
| CH_LAYOUT_AMB_ORDER1_FUMA | First-order FOA layout in FUMA (ITU standards); 4 audio channels in total| 
| CH_LAYOUT_4POINT1 | 4.1 layout; 5 audio channels in total.| 
| CH_LAYOUT_5POINT0 | 5.0 layout; 5 audio channels in total.| 
| CH_LAYOUT_5POINT0_BACK | 5.0 rear layout; 5 audio channels in total.| 
| CH_LAYOUT_2POINT1POINT2 | 2.1.2 layout; 5 audio channels in total.| 
| CH_LAYOUT_3POINT0POINT2 | 3.0.2 layout; 5 audio channels in total.| 
| CH_LAYOUT_5POINT1 | 5.1 layout; 6 audio channels in total.| 
| CH_LAYOUT_5POINT1_BACK | 5.1 rear layout; 6 audio channels in total.| 
| CH_LAYOUT_6POINT0 | 6.0 layout; 6 audio channels in total.| 
| CH_LAYOUT_3POINT1POINT2 | 3.1.2 layout; 6 audio channels in total.| 
| CH_LAYOUT_6POINT0_FRONT | 6.0 front layout; 6 audio channels in total.| 
| CH_LAYOUT_HEXAGONAL | Hexagonal layout; 6 audio channels in total.| 
| CH_LAYOUT_6POINT1 | 6.1 layout; 7 audio channels in total.| 
| CH_LAYOUT_6POINT1_BACK | 6.1 rear layout; 7 audio channels in total.| 
| CH_LAYOUT_6POINT1_FRONT | 6.1 front layout; 7 audio channels in total.| 
| CH_LAYOUT_7POINT0 | 7.0 layout; 7 audio channels in total.| 
| CH_LAYOUT_7POINT0_FRONT | 7.0 front layout; 7 audio channels in total.| 
| CH_LAYOUT_7POINT1 | 7.1 layout; 8 audio channels in total.| 
| CH_LAYOUT_OCTAGONAL | Octagonal layout; 8 audio channels in total.| 
| CH_LAYOUT_5POINT1POINT2 | 5.1.2 layout; 8 audio channels in total.| 
| CH_LAYOUT_7POINT1_WIDE | 7.1 wide layout; 8 audio channels in total.| 
| CH_LAYOUT_7POINT1_WIDE_BACK | 7.1 rear wide layout; 8 audio channels in total.| 
| CH_LAYOUT_AMB_ORDER2_ACN_N3D | Second-order HOA layout in ACN_N3D (ITU standards); 9 audio channels in total| 
| CH_LAYOUT_AMB_ORDER2_ACN_SN3D | Second-order HOA layout in ACN_SN3D (ITU standards); 9 audio channels in total| 
| CH_LAYOUT_AMB_ORDER2_FUMA | Second-order HOA layout in FUMA (ITU standards); 9 audio channels in total| 
| CH_LAYOUT_5POINT1POINT4 | 5.1.4 layout; 10 audio channels in total.| 
| CH_LAYOUT_7POINT1POINT2 | 7.1.2 layout; 10 audio channels in total.| 
| CH_LAYOUT_7POINT1POINT4 | 7.1.4 layout; 12 audio channels in total.| 
| CH_LAYOUT_10POINT2 | 10.2 layout; 12 audio channels in total.| 
| CH_LAYOUT_9POINT1POINT4 | 9.1.4 layout; 14 audio channels in total.| 
| CH_LAYOUT_9POINT1POINT6 | 9.1.6 layout; 16 audio channels in total.| 
| CH_LAYOUT_HEXADECAGONAL | Hexadecagonal layout; 16 audio channels in total.| 
| CH_LAYOUT_AMB_ORDER3_ACN_N3D | Third-order HOA layout in ACN_N3D (ITU standards); 16 audio channels in total| 
| CH_LAYOUT_AMB_ORDER3_ACN_SN3D | Third-order HOA layout in ACN_SN3D (ITU standards); 16 audio channels in total| 
| CH_LAYOUT_AMB_ORDER3_FUMA | Third-order HOA layout in FUMA (ITU standards); 16 audio channels in total| 
| CH_LAYOUT_22POINT2 | 22.2 layout; 24 audio channels in total.| 


### OH_AudioChannelSet

```
enum OH_AudioChannelSet
```

**Description**

Enumerates the audio channel sets.

Each audio channel is mapped to an int64_t variable.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

| Value| Description| 
| -------- | -------- |
| CH_SET_FRONT_LEFT | Front left channel.| 
| CH_SET_FRONT_RIGHT | Front right channel| 
| CH_SET_FRONT_CENTER | Front center channel.| 
| CH_SET_LOW_FREQUENCY | Low-frequency channel.| 
| CH_SET_BACK_LEFT | Rear left channel.| 
| CH_SET_BACK_RIGHT | Rear right channel| 
| CH_SET_FRONT_LEFT_OF_CENTER | Front left center channel.| 
| CH_SET_FRONT_RIGHT_OF_CENTER | Front right center channel.| 
| CH_SET_BACK_CENTER | Rear center channel.| 
| CH_SET_SIDE_LEFT | Left channel.| 
| CH_SET_SIDE_RIGHT | Right channel.| 
| CH_SET_TOP_CENTER | Top center channel.| 
| CH_SET_TOP_FRONT_LEFT | Top left front channel.| 
| CH_SET_TOP_FRONT_CENTER | Top center front channel.| 
| CH_SET_TOP_FRONT_RIGHT | Top right front channel.| 
| CH_SET_TOP_BACK_LEFT | Top left rear channel.| 
| CH_SET_TOP_BACK_CENTER | Top center rear channel.| 
| CH_SET_TOP_BACK_RIGHT | Top right rear channel.| 
| CH_SET_STEREO_LEFT | Stereo left channel.| 
| CH_SET_STEREO_RIGHT | Stereo right channel.| 
| CH_SET_WIDE_LEFT | Wide left channel.| 
| CH_SET_WIDE_RIGHT | Wide right channel.| 
| CH_SET_SURROUND_DIRECT_LEFT | Left surround channel.| 
| CH_SET_SURROUND_DIRECT_RIGHT | Right surround channel.| 
| CH_SET_LOW_FREQUENCY_2 | Low-frequency channel 2.| 
| CH_SET_TOP_SIDE_LEFT | Top left channel.| 
| CH_SET_TOP_SIDE_RIGHT | Top right channel.| 
| CH_SET_BOTTOM_FRONT_CENTER | Bottom center front channel.| 
| CH_SET_BOTTOM_FRONT_LEFT | Bottom left front channel.| 
| CH_SET_BOTTOM_FRONT_RIGHT | Bottom right front channel.| 


### OH_AVCodecBufferFlags

```
enum OH_AVCodecBufferFlags
```

**Description**

Enumerates the flags for the buffer of an **OH_AVCodec** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

| Value| Description| 
| -------- | -------- |
| AVCODEC_BUFFER_FLAGS_NONE | Common frame.| 
| AVCODEC_BUFFER_FLAGS_EOS | The buffer is an end-of-stream frame.| 
| AVCODEC_BUFFER_FLAGS_SYNC_FRAME | The buffer contains key frames.| 
| AVCODEC_BUFFER_FLAGS_INCOMPLETE_FRAME | The data in the buffer is only part of the frame.| 
| AVCODEC_BUFFER_FLAGS_CODEC_DATA | The buffer contains codec-specific data.| 
| AVCODEC_BUFFER_FLAGS_DISCARD  | The decoding process depends on the buffer, and the decoded data can be discarded.<br>**Since**: 12| 
| AVCODEC_BUFFER_FLAGS_DISPOSABLE  | The buffer can be disposed directly.<br>**Since**: 12| 


### OH_AVErrCode

```
enum OH_AVErrCode
```

**Description**

Enumerates the error codes used by the media framework.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

| Value| Description| 
| -------- | -------- |
| AV_ERR_OK  | Operation successful.  | 
| AV_ERR_NO_MEMORY  | No memory.  | 
| AV_ERR_OPERATE_NOT_PERMIT  | Operation not allowed.  | 
| AV_ERR_INVALID_VAL  | Invalid value.  | 
| AV_ERR_IO  | I/O error.  | 
| AV_ERR_TIMEOUT  | Timeout.  | 
| AV_ERR_UNKNOWN  | Unknown error.  | 
| AV_ERR_SERVICE_DIED  | Unavailable service.  | 
| AV_ERR_INVALID_STATE  | Unsupported operation in this state.  | 
| AV_ERR_UNSUPPORT  | Unsupported feature.  | 
| AV_ERR_UNSUPPORTED_FORMAT | Coding format not supported.<br>**Since**: 18| 
| AV_ERR_EXTEND_START  | Initial value for extended error codes.  | 
| AV_ERR_DRM_BASE  | DRM start error code.<br>**Since**: 12| 
| AV_ERR_DRM_DECRYPT_FAILED  | DRM decryption failed.<br>**Since**: 12| 
| AV_ERR_VIDEO_BASE   | Video start error code.<br>**Since**: 12|
| AV_ERR_VIDEO_UNSUPPORTED_COLOR_SPACE_CONVERSION   | Color Space Conversion (CSC) is not supported.<br>**Since**: 12|

### OH_AVPixelFormat

```
enum OH_AVPixelFormat
```

**Description**

Enumerates the video pixel formats.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

| Value| Description| 
| -------- | -------- |
| AV_PIXEL_FORMAT_YUVI420 | YUV 420 Planar.| 
| AV_PIXEL_FORMAT_NV12 | NV12. YUV 420 semi-planar.| 
| AV_PIXEL_FORMAT_NV21 | NV21. YVU 420 semi-planar.| 
| AV_PIXEL_FORMAT_SURFACE_FORMAT | Pixel format obtained from the surface.| 
| AV_PIXEL_FORMAT_RGBA | RGBA8888.| 


### OH_Core_HdrType

```
enum OH_Core_HdrType
```

**Description**

Enumerates the HDR types.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 18

| Value| Description| 
| -------- | -------- |
| OH_CORE_HDR_TYPE_NONE | Non-HDR type.| 
| OH_CORE_HDR_TYPE_VIVID | HDR Vivid type.| 


## Function Description


### OH_AVBuffer_Create()

```
OH_AVBuffer* OH_AVBuffer_Create (int32_t capacity)
```

**Description**

Creates an **OH_AVBuffer** instance. You must call [OH_AVBuffer_Destroy](#oh_avbuffer_destroy) to manually release the **OH_AVBuffer** instance returned.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| capacity | Size of the created memory, in bytes.| 

**Returns**

Returns the pointer to the **OH_AVBuffer** instance created if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The value of **capacity** is less than or equal to 0.
2. An internal error occurs, or the system does not have resources.


### OH_AVBuffer_Destroy()

```
OH_AVErrCode OH_AVBuffer_Destroy (OH_AVBuffer *buffer)
```

**Description**

Releases an **OH_AVBuffer** instance. A buffer cannot be destroyed repeatedly.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 

**Returns**

Returns any of the following result code:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The passed-in value of **buffer** is a null pointer or fails parameter structure verification.

**AV_ERR_OPERATE_NOT_PERMIT**: The input buffer is not created by the user.


### OH_AVBuffer_GetAddr()

```
uint8_t* OH_AVBuffer_GetAddr (OH_AVBuffer *buffer)
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
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 

**Returns**

Returns the virtual address if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **buffer** is a null pointer.
2. The passed-in value of **OH_AVBuffer** fails parameter structure verification.
3. An internal error occurred.


### OH_AVBuffer_GetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_GetBufferAttr (OH_AVBuffer *buffer, OH_AVCodecBufferAttr *attr)
```

**Description**

Obtains the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 
| attr | Pointer to an [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) instance.| 

**Returns**

Returns any of the following result code:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The operation fails.

    Possible causes are as follows:
    1. The passed-in value of **buffer** or **attr** is a null pointer.
    2. The passed-in value of **buffer** fails parameter structure verification.


### OH_AVBuffer_GetCapacity()

```
int32_t OH_AVBuffer_GetCapacity (OH_AVBuffer *buffer)
```

**Description**

Obtains the capacity (in bytes) of a buffer.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 

**Returns**

Returns the capacity if the operation is successful; returns **-1** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **buffer** is a null pointer.
2. The passed-in value of **OH_AVBuffer** fails parameter structure verification.
3. An internal error occurred.


### OH_AVBuffer_GetNativeBuffer()

```
OH_NativeBuffer* OH_AVBuffer_GetNativeBuffer (OH_AVBuffer *buffer)
```

**Description**

Obtains the pointer to an **OH_NativeBuffer** instance. You must call [OH_NativeBuffer_Unreference](../apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_unreference) to manually release the **OH_NativeBuffer** instance returned.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 

**Returns**

Returns the pointer to the **OH_NativeBuffer** instance created if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **buffer** is a null pointer.
2. The passed-in value of **OH_AVBuffer** fails parameter structure verification.
3. An internal error occurred.


### OH_AVBuffer_GetParameter()

```
OH_AVFormat* OH_AVBuffer_GetParameter (OH_AVBuffer *buffer)
```

**Description**

Obtains parameters except basic attributes of a buffer. The information is carried in an **OH_AVFormat** instance. You must call [OH_AVFormat_Destroy](#oh_avformat_destroy) to manually release the **OH_AVFormat** instance returned.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 

**Returns**

Returns any of the following result code:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The operation fails.

    Possible causes are as follows:
    1. The passed-in value of **buffer** is a null pointer.
    2. The meta of the buffer is a null pointer.
    3. The passed-in value of **buffer** fails parameter structure verification.


### OH_AVBuffer_SetBufferAttr()

```
OH_AVErrCode OH_AVBuffer_SetBufferAttr (OH_AVBuffer *buffer, const OH_AVCodecBufferAttr *attr)
```

**Description**

Sets the basic attributes, including **pts**, **size**, **offset**, and **flags**, of a buffer.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 
| attr | Pointer to an [OH_AVCodecBufferAttr](_o_h___a_v_codec_buffer_attr.md) instance.| 

**Returns**

Returns any of the following result code:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The operation fails.

    Possible causes are as follows:
    1. The passed-in value of **buffer** or **attr** is a null pointer.
    2. The passed-in value of **buffer** fails parameter structure verification.
    3. The memory size or offset of the buffer is invalid.


### OH_AVBuffer_SetParameter()

```
OH_AVErrCode OH_AVBuffer_SetParameter (OH_AVBuffer *buffer, const OH_AVFormat *format)
```

**Description**

Sets parameters except basic attributes of a buffer. The information is carried in an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| buffer | Pointer to an **OH_AVBuffer** instance.| 
| format | Pointer to an **OH_AVFormat** instance.| 

**Returns**

Returns any of the following result code:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The operation fails.

    Possible causes are as follows:
    1. The passed-in value of **buffer** or **format** is a null pointer.
    2. The meta of the buffer is a null pointer.
    3. The passed-in value of **buffer** fails parameter structure verification.


### OH_AVFormat_Copy()

```
bool OH_AVFormat_Copy (struct OH_AVFormat *to, struct OH_AVFormat *from)
```

**Description**

Copies an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| to | Pointer to the **OH_AVFormat** instance to which the data will be copied.| 
| from | Pointer to the **OH_AVFormat** instance from which the data will be copied.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The input parameter is a null pointer.
2. The passed-in value of **OH_AVFormat** fails parameter structure verification.


### OH_AVFormat_Create()

```
struct OH_AVFormat* OH_AVFormat_Create (void)
```

**Description**

Create an **OH_AVFormat** instance for reading and writing data.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Returns**

Returns the pointer to an **OH_AVFormat** instance; returns NULL if system resources are insufficient.


### OH_AVFormat_CreateAudioFormat()

```
struct OH_AVFormat* OH_AVFormat_CreateAudioFormat (const char *mimeType, int32_t sampleRate, int32_t channelCount)
```

**Description**

Creates an audio **OH_AVFormat** instance with specified parameters for reading and writing data.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mimeType | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables).| 
| sampleRate | Sampling rate, in Hz.| 
| channelCount | Number of audio channels. For example, 1 indicates mono and 2 indicates stereo.| 

**Returns**

Returns the pointer to an **OH_AVFormat** instance; returns NULL if the passed-in value of **mimeType** is NULL or system resources are insufficient.


### OH_AVFormat_CreateVideoFormat()

```
struct OH_AVFormat* OH_AVFormat_CreateVideoFormat (const char *mimeType, int32_t width, int32_t height)
```

**Description**

Creates a video **OH_AVFormat** instance with specified parameters for reading and writing data.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| mimeType | Pointer to a string that describes the MIME type. For details, see [AVCODEC_MIMETYPE](_codec_base.md#variables).| 
| width | Luminance width, in pixels.| 
| height | Luminance height, in pixels.| 

**Returns**

Returns the pointer to an **OH_AVFormat** instance; returns NULL if the passed-in value of **mimeType** is NULL or system resources are insufficient.


### OH_AVFormat_Destroy()

```
void OH_AVFormat_Destroy (struct OH_AVFormat *format)
```

**Description**

Destroys an **OH_AVFormat** instance. The instance cannot be destroyed repeatedly.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 

**Returns**

No return value.

### OH_AVFormat_DumpInfo()

```
const char* OH_AVFormat_DumpInfo (struct OH_AVFormat *format)
```

**Description**

Returns a string consisting of key-value pairs contained in an **OH_AVFormat**. A string of up to 1024 bytes can be returned. The string pointer is released when the **OH_AVFormat** instance is destroyed.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 

**Returns**

Returns the pointer to a collection of strings, in the format of key-value pairs; returns NULL if the passed-in value of **format** is NULL or system resources are insufficient.


### OH_AVFormat_GetBuffer()

```
bool OH_AVFormat_GetBuffer (struct OH_AVFormat *format, const char *key, uint8_t ** addr, size_t *size)
```

**Description**

Reads data blocks of a specified length from an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| addr | Double pointer to the address where the data read is stored. The data read is destroyed when the **OH_AVFormat** instance is destroyed. To hold the data for an extended period of time, copy it to the memory.| 
| size | Pointer to the size of the data read.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **addr** is a null pointer.
5. The passed-in value of **size** is a null pointer.
6. The obtained key does not exist or is not set.


### OH_AVFormat_GetDoubleValue()

```
bool OH_AVFormat_GetDoubleValue (struct OH_AVFormat *format, const char *key, double *out)
```

**Description**

Obtains the value of the double type of a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **out** is a null pointer.
5. The obtained key does not exist or is not set.


### OH_AVFormat_GetFloatValue()

```
bool OH_AVFormat_GetFloatValue (struct OH_AVFormat *format, const char *key, float *out)
```

**Description**

Obtains the value of the float type of a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **out** is a null pointer.
5. The obtained key does not exist or is not set.


### OH_AVFormat_GetIntValue()

```
bool OH_AVFormat_GetIntValue (struct OH_AVFormat *format, const char *key, int32_t *out)
```

**Description**

Obtains the value of the int type of a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **out** is a null pointer.
5. The obtained key does not exist or is not set.


### OH_AVFormat_GetLongValue()

```
bool OH_AVFormat_GetLongValue (struct OH_AVFormat *format, const char *key, int64_t *out)
```

**Description**

Obtains the value of the long type of a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Pointer to the value of the data read.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **out** is a null pointer.
5. The obtained key does not exist or is not set.


### OH_AVFormat_GetStringValue()

```
bool OH_AVFormat_GetStringValue (struct OH_AVFormat *format, const char *key, const char ** out)
```

**Description**

Obtains the value of the string type of a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to read.| 
| out | Double pointer to the string read. The lifecycle of the **out** data matches the string in **format**. To keep the **out** data for an extended period of time, you must copy it to the memory. The maximum length of the output string is 256 bytes. If the length exceeds 256 bytes, **false** is returned.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **out** is a null pointer.
5. The system resources are insufficient.
6. The obtained key does not exist or is not set.
7. The length of the **out** data exceeds 256 bytes.


### OH_AVFormat_SetBuffer()

```
bool OH_AVFormat_SetBuffer (struct OH_AVFormat *format, const char *key, const uint8_t *addr, size_t size)
```

**Description**

Writes data blocks of a specified length to an **OH_AVFormat** instance. This function can be used to set only parameters of the buffer type. For details, see [CodecBase](_codec_base.md).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| addr | Double-pointer to the address to which data is written. The lifecycle is managed by the developer.| 
| size | Length of the data written, in MB. The value range is (0, 1].| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **addr** is a null pointer.
5. The size is 0 or exceeds the upper limit (1 MB).
6. The value type corresponding to the key is incorrect.


### OH_AVFormat_SetDoubleValue()

```
bool OH_AVFormat_SetDoubleValue (struct OH_AVFormat *format, const char *key, double value)
```

**Description**

Assigns a value of the double type to a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance. This function can be used to set only parameters of the double type. For details, see [CodecBase](_codec_base.md).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The value type corresponding to the key is incorrect.


### OH_AVFormat_SetFloatValue()

```
bool OH_AVFormat_SetFloatValue (struct OH_AVFormat *format, const char *key, float value)
```

**Description**

Assigns a value of the float type to a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance. This function can be used to set only parameters of the float type. For details, see [CodecBase](_codec_base.md).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The value type corresponding to the key is incorrect.

### OH_AVFormat_SetIntValue()

```
bool OH_AVFormat_SetIntValue (struct OH_AVFormat *format, const char *key, int32_t value)
```

**Description**

Assigns a value of the int type to a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance. This function can be used to set only parameters of the int type. For details, see [CodecBase](_codec_base.md).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The value type corresponding to the key is incorrect.


### OH_AVFormat_SetLongValue()

```
bool OH_AVFormat_SetLongValue (struct OH_AVFormat *format, const char *key, int64_t value)
```

**Description**

Assigns a value of the long type to a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance. This function can be used to set only parameters of the long type. For details, see [CodecBase](_codec_base.md).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Value of the data to write.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The value type corresponding to the key is incorrect.


### OH_AVFormat_SetStringValue()

```
bool OH_AVFormat_SetStringValue (struct OH_AVFormat *format, const char *key, const char *value)
```

**Description**

Assigns a value of the string type to a [key](_codec_base.md#media-data-key-value-pairs) in an **OH_AVFormat** instance. This function can be used to set only parameters of the string type. For details, see [CodecBase](_codec_base.md).

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| format | Pointer to an **OH_AVFormat** instance.| 
| key | Pointer to the key of the data to write.| 
| value | Pointer to the data to be written to the string. The length should not exceed 256 bytes.| 

**Returns**

Returns **TRUE** if the operation is successful; returns **FALSE** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **format** is a null pointer.
2. The passed-in value of **format** fails parameter structure verification.
3. The passed-in value of **key** is a null pointer.
4. The passed-in value of **value** is a null pointer.
5. The value type corresponding to the key is incorrect.


### OH_AVMemory_Create()

```
OH_AVMemory* OH_AVMemory_Create (int32_t size)
```

**Description**

Creates an **OH_AVMemory** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_Create](#oh_avbuffer_create)

**Parameters**

| Name| Description| 
| -------- | -------- |
| size | Size of the created memory, in bytes.| 

**Returns**

Returns the pointer to the **OH_AVMemory** instance created if the operation is successful; returns NULL otherwise. The instance must be released by calling **OH_AVMemory_Destroy** when it is no longer required.


### OH_AVMemory_Destroy()

```
OH_AVErrCode OH_AVMemory_Destroy (struct OH_AVMemory *mem)
```

**Description**

Releases an **OH_AVMemory** instance.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 10

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_Destroy](#oh_avbuffer_destroy)

**Parameters**

| Name| Description| 
| -------- | -------- |
| mem | Pointer to an **OH_AVMemory** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](#oh_averrcode-1) otherwise.


### OH_AVMemory_GetAddr()

```
uint8_t* OH_AVMemory_GetAddr (struct OH_AVMemory *mem)
```

**Description**

Obtains the virtual memory address.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_GetAddr](#oh_avbuffer_getaddr)

**Parameters**

| Name| Description| 
| -------- | -------- |
| mem | Pointer to an **OH_AVMemory** instance.| 

**Returns**

Returns the pointer to the virtual memory address if the memory is valid; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **mem** is a null pointer.
2. The passed-in value of **mem** fails parameter structure verification.
3. The memory in the passed-in value of **mem** is a null pointer.


### OH_AVMemory_GetSize()

```
int32_t OH_AVMemory_GetSize (struct OH_AVMemory *mem)
```

**Description**

Obtains the memory length.

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 9

**Deprecated from**: 11

**Substitute**: [OH_AVBuffer_GetCapacity](#oh_avbuffer_getcapacity)

**Parameters**

| Name| Description| 
| -------- | -------- |
| mem | Pointer to an **OH_AVMemory** instance.| 

**Returns**

Returns the memory size if the memory is valid; returns **-1** otherwise.

The possible causes of an operation failure are as follows:

1. The passed-in value of **mem** is a null pointer.
2. The passed-in value of **mem** fails parameter structure verification.
3. The memory in the passed-in value of **mem** is a null pointer.
