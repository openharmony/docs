# image_mdk_common.h
<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--SE: @liyang_bryan-->
<!--TSE: @xchaosioda-->

## Overview

The file declares the common enums and structs used by the image interface.

**Library**: libimage_ndk.z.so

**System capability**: SystemCapability.Multimedia.Image

**Since**: 10

**Related module**: [Image](capi-image.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OhosImageSize](capi-image-ohosimagesize.md) | - | Describes the image size. It is a member variable of [OhosImageDecodingOps](capi-image-ohosimagedecodingops.md).|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [IRNdkErrCode](#irndkerrcode) | IRNdkErrCode | Enumerates the return values that may be used by the interface.|

## Enum Description

### IRNdkErrCode

```
enum IRNdkErrCode
```

**Description**

Enumerates the return values that may be used by the interface.

**Since**: 10

| Enum Item| Description|
| -- | -- |
| -------- | -------- |
| IMAGE_RESULT_SUCCESS = 0 | Operation succeeded.|
| IMAGE_RESULT_BAD_PARAMETER = -1 | Invalid parameter.|
| IMAGE_RESULT_IMAGE_RESULT_BASE = IMAGE_RESULT_BASE | Operation failed.|
| IMAGE_RESULT_ERR_IPC = IMAGE_RESULT_BASE + 1 | IPC error.|
| IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST = IMAGE_RESULT_BASE + 2 | Sharing the memory fails.|
| IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL = IMAGE_RESULT_BASE + 3 | Abnormal data in the shared memory.|
| IMAGE_RESULT_DECODE_ABNORMAL = IMAGE_RESULT_BASE + 4 | Failed to decode the image.|
| IMAGE_RESULT_DATA_ABNORMAL = IMAGE_RESULT_BASE + 5 | Abnormal input data.|
| IMAGE_RESULT_MALLOC_ABNORMAL = IMAGE_RESULT_BASE + 6 | An error occurs during memory allocation.|
| IMAGE_RESULT_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 7 | The image type is not supported.|
| IMAGE_RESULT_INIT_ABNORMAL = IMAGE_RESULT_BASE + 8 | Failed to initialize the image.|
| IMAGE_RESULT_GET_DATA_ABNORMAL = IMAGE_RESULT_BASE + 9 | An error occurs during image data retrieval.|
| IMAGE_RESULT_TOO_LARGE = IMAGE_RESULT_BASE + 10 | The image is too large.|
| IMAGE_RESULT_TRANSFORM = IMAGE_RESULT_BASE + 11 | An error occurs during image transformation.|
| IMAGE_RESULT_COLOR_CONVERT = IMAGE_RESULT_BASE + 12 | An error occurs during image color conversion.|
| IMAGE_RESULT_CROP = IMAGE_RESULT_BASE + 13 | An error occurs during image cropping.|
| IMAGE_RESULT_SOURCE_DATA = IMAGE_RESULT_BASE + 14 | The image source data is incorrect.|
| IMAGE_RESULT_SOURCE_DATA_INCOMPLETE = IMAGE_RESULT_BASE + 15 | The image source data is incomplete.|
| IMAGE_RESULT_MISMATCHED_FORMAT = IMAGE_RESULT_BASE + 16 | The image format does not match.|
| IIMAGE_RESULT_UNKNOWN_FORMAT = IMAGE_RESULT_BASE + 17 | Unknown image format.|
| IMAGE_RESULT_SOURCE_UNRESOLVED = IMAGE_RESULT_BASE + 18 | The image source is not parsed.|
| IMAGE_RESULT_INVALID_PARAMETER = IMAGE_RESULT_BASE + 19 | Invalid image parameter.|
| IMAGE_RESULT_DECODE_FAILED = IMAGE_RESULT_BASE + 20 | Failed to decode the image.|
| IMAGE_RESULT_PLUGIN_REGISTER_FAILED = IMAGE_RESULT_BASE + 21 | Failed to register the plug-in.|
| IMAGE_RESULT_PLUGIN_CREATE_FAILED = IMAGE_RESULT_BASE + 22 | Failed to create the plug-in.|
| IMAGE_RESULT_ENCODE_FAILED = IMAGE_RESULT_BASE + 23 | Failed to encode the image.|
| IMAGE_RESULT_ADD_PIXEL_MAP_FAILED = IMAGE_RESULT_BASE + 24 | Failed to add the PixelMap.|
| IIMAGE_RESULT_HW_DECODE_UNSUPPORT = IMAGE_RESULT_BASE + 25 | Hardware decoding is not supported.|
| IMAGE_RESULT_DECODE_HEAD_ABNORMAL = IMAGE_RESULT_BASE + 26 | Failed to decode the image header.|
| IMAGE_RESULT_DECODE_EXIF_UNSUPPORT = IMAGE_RESULT_BASE + 27 | Exchangeable Image File (EXIF) is not supported for image decoding.|
| IMAGE_RESULT_PROPERTY_NOT_EXIST = IMAGE_RESULT_BASE + 28 | The image property does not exist.|
| IMAGE_RESULT_MEDIA_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 30 | The media type is not supported.|
| IMAGE_RESULT_MEDIA_TOO_LARGE = IMAGE_RESULT_BASE + 31 | The media is too large.|
| IMAGE_RESULT_MEDIA_MALLOC_FAILED = IMAGE_RESULT_BASE + 32 | Memory allocation failed.|
| IMAGE_RESULT_MEDIA_END_OF_STREAM = IMAGE_RESULT_BASE + 33 | Failed to end the media data stream.|
| IMAGE_RESULT_MEDIA_IO_ABNORMAL = IMAGE_RESULT_BASE + 34 | Abnormal input and output streams.|
| IMAGE_RESULT_MEDIA_MALFORMED = IMAGE_RESULT_BASE + 35 | The media service functions abnormally.|
| IMAGE_RESULT_MEDIA_BUFFER_TOO_SMALL = IMAGE_RESULT_BASE + 36 | The media data is too small.|
| IMAGE_RESULT_MEDIA_OUT_OF_RANGE = IMAGE_RESULT_BASE + 37 | The media is out of range.|
| IMAGE_RESULT_MEDIA_STATUS_ABNORMAL = IMAGE_RESULT_BASE + 38 | Abnormal media status.|
| IMAGE_RESULT_MEDIA_VALUE_INVALID = IMAGE_RESULT_BASE + 39 | Invalid media value.|
| IMAGE_RESULT_MEDIA_NULL_POINTER = IMAGE_RESULT_BASE + 40 | Media operation failed.|
| IMAGE_RESULT_MEDIA_INVALID_OPERATION = IMAGE_RESULT_BASE + 41 | Invalid media operation.|
| IMAGE_RESULT_MEDIA_ERR_PLAYER_NOT_INIT = IMAGE_RESULT_BASE + 42 | An error occurs during media initialization.|
| IMAGE_RESULT_MEDIA_EARLY_PREPARE = IMAGE_RESULT_BASE + 43 | Media preprocessing is carried out too early.|
| IMAGE_RESULT_MEDIA_SEEK_ERR = IMAGE_RESULT_BASE + 44 | The seek operation failed.|
| IMAGE_RESULT_MEDIA_PERMISSION_DENIED = IMAGE_RESULT_BASE + 45 | Permission denied.|
| IMAGE_RESULT_MEDIA_DEAD_OBJECT = IMAGE_RESULT_BASE + 46 | The media object is deregistered.|
| IMAGE_RESULT_MEDIA_TIMED_OUT = IMAGE_RESULT_BASE + 47 | A timeout occurs.|
| IMAGE_RESULT_MEDIA_TRACK_NOT_ALL_SUPPORTED = IMAGE_RESULT_BASE + 48 | The media capability is not supported.|
| IMAGE_RESULT_MEDIA_ADAPTER_INIT_FAILED = IMAGE_RESULT_BASE + 49 | Failed to initialize the media adapter.|
| IMAGE_RESULT_MEDIA_WRITE_PARCEL_FAIL = IMAGE_RESULT_BASE + 50 | Failed to write data to the parcel.|
| IMAGE_RESULT_MEDIA_READ_PARCEL_FAIL = IMAGE_RESULT_BASE + 51 | Failed to read data from the parcel.|
| IMAGE_RESULT_MEDIA_NO_AVAIL_BUFFER = IMAGE_RESULT_BASE + 52 | Invalid data.|
| IMAGE_RESULT_MEDIA_INVALID_PARAM = IMAGE_RESULT_BASE + 53 | Invalid parameters.|
| IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 54 | The media codec adapter does not exist.|
| IMAGE_RESULT_MEDIA_CREATE_CODEC_ADAPTER_FAILED = IMAGE_RESULT_BASE + 55 | Failed to create the media codec adapter.|
| IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 56 | The media codec adapter is not initialized.|
| IMAGE_RESULT_MEDIA_ZCODEC_CREATE_FAILED = IMAGE_RESULT_BASE + 57 | Failed to create the media codec.|
| IMAGE_RESULT_MEDIA_ZCODEC_NOT_EXIST = IMAGE_RESULT_BASE + 58 | The media codec does not exist.|
| IMAGE_RESULT_MEDIA_JNI_CLASS_NOT_EXIST = IMAGE_RESULT_BASE + 59 | The media JNI layer class does not exist.|
| IMAGE_RESULT_MEDIA_JNI_METHOD_NOT_EXIST = IMAGE_RESULT_BASE + 60 | The media JNI layer method does not exist.|
| IMAGE_RESULT_MEDIA_JNI_NEW_OBJ_FAILED = IMAGE_RESULT_BASE + 61 | Failed to create the object at the media JNI layer.|
| IMAGE_RESULT_MEDIA_JNI_COMMON_ERROR = IMAGE_RESULT_BASE + 62 | The media JNI layer is abnormal.|
| IMAGE_RESULT_MEDIA_DISTRIBUTE_NOT_SUPPORT = IMAGE_RESULT_BASE + 63 | The distributed feature is not supported.|
| IMAGE_RESULT_MEDIA_SOURCE_NOT_SET = IMAGE_RESULT_BASE + 64 | The media source is not set.|
| IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 65 | The media RTSP adapter is not initialized.|
| IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 66 | The media RTSP adapter does not exist.|
| IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT = IMAGE_RESULT_BASE + 67 | The media does not support the RTSP surface.|
| IMAGE_RESULT_MEDIA_RTSP_CAPTURE_NOT_INIT = IMAGE_RESULT_BASE + 68 | Failed to initialize the media RTSP capturer.|
| IMAGE_RESULT_MEDIA_RTSP_SOURCE_URL_INVALID = IMAGE_RESULT_BASE + 69 | Invalid media RTSP source path.|
| IMAGE_RESULT_MEDIA_RTSP_VIDEO_TRACK_NOT_FOUND = IMAGE_RESULT_BASE + 70 | No video capability is found in the media RTSP.|
| IMAGE_RESULT_MEDIA_RTSP_CAMERA_NUM_REACH_MAX = IMAGE_RESULT_BASE + 71 | The maximum number of RTSP cameras has been reached.|
| IMAGE_RESULT_MEDIA_SET_VOLUME = IMAGE_RESULT_BASE + 72 | Failed to set the volume.|
| IMAGE_RESULT_MEDIA_NUMBER_OVERFLOW = IMAGE_RESULT_BASE + 73 | The number of operations overflows.|
| IMAGE_RESULT_MEDIA_DIS_PLAYER_UNSUPPORTED = IMAGE_RESULT_BASE + 74 | The distributed media player is not supported.|
| IIMAGE_RESULT_MEDIA_DENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 75 | Failed to decode the ICC.|
| IMAGE_RESULT_MEDIA_ENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 76 | Failed to encode the ICC.|
| IMAGE_RESULT_MEDIA_READ_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 150 | Failed to read the PixelMap.|
| IMAGE_RESULT_MEDIA_WRITE_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 151 | Failed to write the PixelMap.|
| IMAGE_RESULT_MEDIA_PIXELMAP_NOT_ALLOW_MODIFY = IMAGE_RESULT_BASE + 152 | The PixelMap cannot be modified.|
| IMAGE_RESULT_MEDIA_CONFIG_FAILED = IMAGE_RESULT_BASE + 153 | Configuration failed.|
| IMAGE_RESULT_JNI_ENV_ABNORMAL = IMAGE_RESULT_BASE + 154 | The JNI environment is abnormal.|
| IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED = IMAGE_RESULT_BASE + 155 | Failed to allocate memory for the surface.|
| IMAGE_RESULT_CREATE_SURFACE_FAILED = IMAGE_RESULT_BASE + 156 | Failed to create the surface.|
| IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED = IMAGE_RESULT_BASE + 157 | Failed to obtain parameters from the surface.|
| IMAGE_RESULT_GET_SURFACE_FAILED = IMAGE_RESULT_BASE + 158 | Failed to obtain the surface.| 
| IIMAGE_RESULT_SURFACE_ACQUIRE_BUFFER_FAILED = IMAGE_RESULT_BASE + 159 | Failed to allocate the memory.|
| IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED = IMAGE_RESULT_BASE + 160 | Failed to allocate the memory.|
| IMAGE_RESULT_REGISTER_LISTENER_FAILED = IMAGE_RESULT_BASE + 161 | Failed to register the listener.|
| IMAGE_RESULT_REGISTER_BUFFER_FAILED = IMAGE_RESULT_BASE + 162 | Failed to register the buffer.|
| IMAGE_RESULT_FREAD_FAILED = IMAGE_RESULT_BASE + 163 | Failed to read the file.|
| IMAGE_RESULT_PEEK_FAILED = IMAGE_RESULT_BASE + 164 | Failed to peek the file.|
| IMAGE_RESULT_SEEK_FAILED = IMAGE_RESULT_BASE + 165 | Failed to seek the file.|
| IMAGE_RESULT_STREAM_SIZE_ERROR = IMAGE_RESULT_BASE + 166 | The data stream is damaged.|
| IIMAGE_RESULT_FILE_FD_ERROR = IMAGE_RESULT_BASE + 167, | The file descriptor is corrupted.|
| IMAGE_RESULT_FILE_DAMAGED = IMAGE_RESULT_BASE + 168 | The file is damaged.|
| IIMAGE_RESULT_CREATE_DECODER_FAILED = IMAGE_RESULT_BASE + 169 | Failed to create a decoder.|
| IMAGE_RESULT_CREATE_ENCODER_FAILED = IMAGE_RESULT_BASE + 170 | Failed to create an encoder.|
| IMAGE_RESULT_CHECK_FORMAT_ERROR = IMAGE_RESULT_BASE + 171 | Failed to check the format.|
| IMAGE_RESULT_THIRDPART_SKIA_ERROR = IMAGE_RESULT_BASE + 172 | Skia decoding failed.|
| IMAGE_RESULT_HW_DECODE_FAILED = IMAGE_RESULT_BASE + 173 | Hardware decoding failed.|
| IMAGE_RESULT_ALLOCATER_TYPE_ERROR = IMAGE_RESULT_BASE + 174 | Failed to verify the memory type.|
| IMAGE_RESULT_ALPHA_TYPE_ERROR = IMAGE_RESULT_BASE + 175 | Failed to verify the alpha type.|
| IMAGE_RESULT_INDEX_INVALID = IMAGE_RESULT_BASE + 176 | Invalid parameter.|
| IMAGE_RESULT_MEDIA_UNKNOWN = IMAGE_RESULT_BASE + 200 | Unknown error.|
