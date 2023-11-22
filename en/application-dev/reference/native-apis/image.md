# Image


## Overview

The **Image** package provides APIs for accessing the **Image** module. For example, you can use the APIs to obtain image data, pixel map data, and pixel map information.

\@Syscap SystemCapability.Multimedia.Image

**Since**

8


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [image_mdk.h](image__mdk_8h.md) | Declares the functions that access the image rectangle, size, format, and component data.<br>**File to include**: &lt;multimedia/image_framework/image_mdk.h&gt;<br>**Library**: libimage_ndk.z.so| 
| [image_mdk_common.h](image__mdk__common_8h.md) | Declares the common enums and structs used by the image interface.<br>**File to include**: &lt;multimedia/image_framework/image_mdk_common.h&gt;<br>**Library**: libimage_ndk.z.so| 
| [image_pixel_map_mdk.h](image__pixel__map__mdk_8h.md) | Declares the APIs that can lock, access, and unlock a pixel map.<br>**File to include**: &lt;multimedia/image_framework/image_pixel_map_mdk.h&gt;<br>**Library**: libpixelmap_ndk.z.so| 
| [image_pixel_map_napi.h](image__pixel__map__napi_8h.md) | Declares the APIs that can lock, access, and unlock a pixel map.<br>**File to include**: &lt;multimedia/image_framework/image_pixel_map_napi.h&gt;<br>**Library**: libpixelmap_ndk.z.so| 
| [image_receiver_mdk.h](image__receiver__mdk_8h.md) | Declares the APIs for obtaining image data from the native layer.<br>**File to include**: &lt;multimedia/image_framework/image_receiver_mdk.h&gt;<br>**Library**: libimage_receiver_ndk.z.so| 
| [image_source_mdk.h](image__source__mdk_8h.md) | Declares the APIs for decoding an image source into a pixel map.<br>**File to include**: &lt;multimedia/image_framework/image_source_mdk.h&gt;<br>**Library**: libimage_source_ndk.z.so| 


### Structs

| Name| Description| 
| -------- | -------- |
| [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) | Defines the information about an image rectangle.| 
| [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) | Defines the information about an image component.| 
| [OhosImageSize](_ohos_image_size.md) | Defines the image size.| 
| [OhosPixelMapInfos](_ohos_pixel_map_infos.md) | Defines the information about a pixel map.| 
| [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) | Defines the options for creating a pixel map.| 
| [OHOS::Media::OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) | Defines the information about a pixel map.| 
| [OhosImageReceiverInfo](_ohos_image_receiver_info.md) | Defines the information about an image receiver.| 
| [OhosImageRegion](_ohos_image_region.md) | Defines the region of an image source to decode.| 
| [OhosImageSourceOps](_ohos_image_source_ops.md) | Defines the image source options.| 
| [OhosImageDecodingOps](_ohos_image_decoding_ops.md) | Defines the options for decoding an image source.| 
| [OhosImageSourceInfo](_ohos_image_source_info.md) | Defines the information about an image source.| 
| [OhosImageSource](_ohos_image_source.md) | Defines the input resource of an image source. Only one type of resource is accepted at a time.| 
| [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) | Defines the delay time list of an image source.| 
| [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md) | Defines the format string supported by an image source.| 
| [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) | Defines the format string list supported by an image source.| 
| [OhosImageSourceProperty](_ohos_image_source_property.md) | Defines the property string (in key-value format) of an image source.| 
| [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) | Defines the update data of an image source.| 


### Types

| Name| Description| 
| -------- | -------- |
| [ImageNative](#imagenative) | Defines an image object at the native layer.| 
| [NativePixelMap](#nativepixelmap) | Defines the data type name of the pixel map at the native layer.| 
| [OhosPixelMapInfos](#ohospixelmapinfos) | Defines the information about a pixel map.| 
| [ImageReceiverNative](#imagereceivernative) | Defines the data type name of the image receiver at the native layer.| 
| (\*[OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)) () | Defines the callbacks for the image interface at the native layer.| 
| [ImageSourceNative](#imagesourcenative) | Defines an image source object at the native layer.| 

### Macros

| Name| Description| 
| -------- | -------- |
| **IMAGE_RESULT_BASE** 62980096 | Defines the basic value returned by the interface. |

### Enums

| Name| Description| 
| -------- | -------- |
| { OHOS_IMAGE_FORMAT_YCBCR_422_SP = 1000,<br>OHOS_IMAGE_FORMAT_JPEG = 2000, } | Enumerates the image formats.| 
| { OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y = 1,<br>OHOS_IMAGE_COMPONENT_FORMAT_YUV_U = 2,<br>OHOS_IMAGE_COMPONENT_FORMAT_YUV_V = 3,<br>OHOS_IMAGE_COMPONENT_FORMAT_JPEG = 4, } | Enumerates the image components.| 
| [IRNdkErrCode](#irndkerrcode) {<br>IMAGE_RESULT_SUCCESS = 0,<br>IMAGE_RESULT_BAD_PARAMETER = -1,<br>IMAGE_RESULT_IMAGE_RESULT_BASE = IMAGE_RESULT_BASE,<br>IMAGE_RESULT_ERR_IPC = IMAGE_RESULT_BASE + 1,<br>IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST = IMAGE_RESULT_BASE + 2,<br>IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL = IMAGE_RESULT_BASE + 3,<br>IMAGE_RESULT_DECODE_ABNORMAL = IMAGE_RESULT_BASE + 4,<br>IMAGE_RESULT_DATA_ABNORMAL = IMAGE_RESULT_BASE + 5,<br>IMAGE_RESULT_MALLOC_ABNORMAL = IMAGE_RESULT_BASE + 6,<br>IMAGE_RESULT_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 7,<br>IMAGE_RESULT_INIT_ABNORMAL = IMAGE_RESULT_BASE + 8,<br>IMAGE_RESULT_GET_DATA_ABNORMAL = IMAGE_RESULT_BASE + 9,<br>IMAGE_RESULT_TOO_LARGE = IMAGE_RESULT_BASE + 10,<br>IMAGE_RESULT_TRANSFORM = IMAGE_RESULT_BASE + 11,<br>IMAGE_RESULT_COLOR_CONVERT = IMAGE_RESULT_BASE + 12,<br>IMAGE_RESULT_CROP = IMAGE_RESULT_BASE + 13,<br>IMAGE_RESULT_SOURCE_DATA = IMAGE_RESULT_BASE + 14,<br>IMAGE_RESULT_SOURCE_DATA_INCOMPLETE = IMAGE_RESULT_BASE + 15,<br>IMAGE_RESULT_MISMATCHED_FORMAT = IMAGE_RESULT_BASE + 16,<br>IMAGE_RESULT_UNKNOWN_FORMAT = IMAGE_RESULT_BASE + 17,<br>IMAGE_RESULT_SOURCE_UNRESOLVED = IMAGE_RESULT_BASE + 18,<br>IMAGE_RESULT_INVALID_PARAMETER = IMAGE_RESULT_BASE + 19,<br>IMAGE_RESULT_DECODE_FAILED = IMAGE_RESULT_BASE + 20,<br>IMAGE_RESULT_PLUGIN_REGISTER_FAILED = IMAGE_RESULT_BASE + 21,<br>IMAGE_RESULT_PLUGIN_CREATE_FAILED = IMAGE_RESULT_BASE + 22,<br>IMAGE_RESULT_ENCODE_FAILED = IMAGE_RESULT_BASE + 23,<br>IMAGE_RESULT_ADD_PIXEL_MAP_FAILED = IMAGE_RESULT_BASE + 24,<br>IMAGE_RESULT_HW_DECODE_UNSUPPORT = IMAGE_RESULT_BASE + 25,<br>IMAGE_RESULT_DECODE_HEAD_ABNORMAL = IMAGE_RESULT_BASE + 26,<br>IMAGE_RESULT_DECODE_EXIF_UNSUPPORT = IMAGE_RESULT_BASE + 27,<br>IMAGE_RESULT_PROPERTY_NOT_EXIST = IMAGE_RESULT_BASE + 28,<br>IMAGE_RESULT_MEDIA_DATA_UNSUPPORT = IMAGE_RESULT_BASE + 30,<br>IMAGE_RESULT_MEDIA_TOO_LARGE = IMAGE_RESULT_BASE + 31,<br>IMAGE_RESULT_MEDIA_MALLOC_FAILED = IMAGE_RESULT_BASE + 32,<br>IMAGE_RESULT_MEDIA_END_OF_STREAM = IMAGE_RESULT_BASE + 33,<br>IMAGE_RESULT_MEDIA_IO_ABNORMAL = IMAGE_RESULT_BASE + 34,<br>IMAGE_RESULT_MEDIA_MALFORMED = IMAGE_RESULT_BASE + 35,<br>IMAGE_RESULT_MEDIA_BUFFER_TOO_SMALL = IMAGE_RESULT_BASE + 36,<br>IMAGE_RESULT_MEDIA_OUT_OF_RANGE = IMAGE_RESULT_BASE + 37,<br>IMAGE_RESULT_MEDIA_STATUS_ABNORMAL = IMAGE_RESULT_BASE + 38,<br>IMAGE_RESULT_MEDIA_VALUE_INVALID = IMAGE_RESULT_BASE + 39,<br>IMAGE_RESULT_MEDIA_NULL_POINTER = IMAGE_RESULT_BASE + 40,<br>IMAGE_RESULT_MEDIA_INVALID_OPERATION = IMAGE_RESULT_BASE + 41,<br>IMAGE_RESULT_MEDIA_ERR_PLAYER_NOT_INIT = IMAGE_RESULT_BASE + 42,<br>IMAGE_RESULT_MEDIA_EARLY_PREPARE = IMAGE_RESULT_BASE + 43,<br>IMAGE_RESULT_MEDIA_SEEK_ERR = IMAGE_RESULT_BASE + 44,<br>IMAGE_RESULT_MEDIA_PERMISSION_DENIED = IMAGE_RESULT_BASE + 45,<br>IMAGE_RESULT_MEDIA_DEAD_OBJECT = IMAGE_RESULT_BASE + 46,<br>IMAGE_RESULT_MEDIA_TIMED_OUT = IMAGE_RESULT_BASE + 47,<br>IMAGE_RESULT_MEDIA_TRACK_NOT_ALL_SUPPORTED = IMAGE_RESULT_BASE + 48,<br>IMAGE_RESULT_MEDIA_ADAPTER_INIT_FAILED = IMAGE_RESULT_BASE + 49,<br>IMAGE_RESULT_MEDIA_WRITE_PARCEL_FAIL = IMAGE_RESULT_BASE + 50,<br>IMAGE_RESULT_MEDIA_READ_PARCEL_FAIL = IMAGE_RESULT_BASE + 51,<br>IMAGE_RESULT_MEDIA_NO_AVAIL_BUFFER = IMAGE_RESULT_BASE + 52,<br>IMAGE_RESULT_MEDIA_INVALID_PARAM = IMAGE_RESULT_BASE + 53, IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 54,<br>IMAGE_RESULT_MEDIA_CREATE_CODEC_ADAPTER_FAILED = IMAGE_RESULT_BASE + 55,<br>IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 56,<br>IMAGE_RESULT_MEDIA_ZCODEC_CREATE_FAILED = IMAGE_RESULT_BASE + 57,<br>IMAGE_RESULT_MEDIA_ZCODEC_NOT_EXIST = IMAGE_RESULT_BASE + 58,<br>IMAGE_RESULT_MEDIA_JNI_CLASS_NOT_EXIST = IMAGE_RESULT_BASE + 59,<br>IMAGE_RESULT_MEDIA_JNI_METHOD_NOT_EXIST = IMAGE_RESULT_BASE + 60,<br>IMAGE_RESULT_MEDIA_JNI_NEW_OBJ_FAILED = IMAGE_RESULT_BASE + 61,<br>IMAGE_RESULT_MEDIA_JNI_COMMON_ERROR = IMAGE_RESULT_BASE + 62,<br>IMAGE_RESULT_MEDIA_DISTRIBUTE_NOT_SUPPORT = IMAGE_RESULT_BASE + 63,<br>IMAGE_RESULT_MEDIA_SOURCE_NOT_SET = IMAGE_RESULT_BASE + 64,<br>IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_INIT = IMAGE_RESULT_BASE + 65,<br>IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_EXIST = IMAGE_RESULT_BASE + 66,<br>IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT = IMAGE_RESULT_BASE + 67,<br>IMAGE_RESULT_MEDIA_RTSP_CAPTURE_NOT_INIT = IMAGE_RESULT_BASE + 68,<br>IMAGE_RESULT_MEDIA_RTSP_SOURCE_URL_INVALID = IMAGE_RESULT_BASE + 69,<br>IMAGE_RESULT_MEDIA_RTSP_VIDEO_TRACK_NOT_FOUND = IMAGE_RESULT_BASE + 70,<br>IMAGE_RESULT_MEDIA_RTSP_CAMERA_NUM_REACH_MAX = IMAGE_RESULT_BASE + 71,<br>IMAGE_RESULT_MEDIA_SET_VOLUME = IMAGE_RESULT_BASE + 72,<br>IMAGE_RESULT_MEDIA_NUMBER_OVERFLOW = IMAGE_RESULT_BASE + 73,<br>IMAGE_RESULT_MEDIA_DIS_PLAYER_UNSUPPORTED = IMAGE_RESULT_BASE + 74,<br>IMAGE_RESULT_MEDIA_DENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 75,<br>IMAGE_RESULT_MEDIA_ENCODE_ICC_FAILED = IMAGE_RESULT_BASE + 76,<br>IMAGE_RESULT_MEDIA_READ_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 150,<br>IMAGE_RESULT_MEDIA_WRITE_PIXELMAP_FAILED = IMAGE_RESULT_BASE + 151,<br>IMAGE_RESULT_MEDIA_PIXELMAP_NOT_ALLOW_MODIFY = IMAGE_RESULT_BASE + 152,<br>IMAGE_RESULT_MEDIA_CONFIG_FAILED = IMAGE_RESULT_BASE + 153,<br>IMAGE_RESULT_JNI_ENV_ABNORMAL = IMAGE_RESULT_BASE + 154,<br>IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED = IMAGE_RESULT_BASE + 155,<br>IMAGE_RESULT_CREATE_SURFACE_FAILED = IMAGE_RESULT_BASE + 156,<br>IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED = IMAGE_RESULT_BASE + 157,<br>IMAGE_RESULT_GET_SURFACE_FAILED = IMAGE_RESULT_BASE + 158,<br>IMAGE_RESULT_SURFACE_ACQUIRE_BUFFER_FAILED = IMAGE_RESULT_BASE + 159,<br>IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED = IMAGE_RESULT_BASE + 160,<br>IMAGE_RESULT_REGISTER_LISTENER_FAILED = IMAGE_RESULT_BASE + 161,<br>IMAGE_RESULT_REGISTER_BUFFER_FAILED = IMAGE_RESULT_BASE + 162,<br>IMAGE_RESULT_FREAD_FAILED = IMAGE_RESULT_BASE + 163,<br>IMAGE_RESULT_PEEK_FAILED = IMAGE_RESULT_BASE + 164,<br>IMAGE_RESULT_SEEK_FAILED = IMAGE_RESULT_BASE + 165,<br>IMAGE_RESULT_STREAM_SIZE_ERROR = IMAGE_RESULT_BASE + 166,<br>IMAGE_RESULT_FILE_FD_ERROR = IMAGE_RESULT_BASE + 167,<br>IMAGE_RESULT_FILE_DAMAGED = IMAGE_RESULT_BASE + 168,<br>IMAGE_RESULT_CREATE_DECODER_FAILED = IMAGE_RESULT_BASE + 169,<br>IMAGE_RESULT_CREATE_ENCODER_FAILED = IMAGE_RESULT_BASE + 170,<br>IMAGE_RESULT_CHECK_FORMAT_ERROR = IMAGE_RESULT_BASE + 171,<br>IMAGE_RESULT_THIRDPART_SKIA_ERROR = IMAGE_RESULT_BASE + 172,<br>IMAGE_RESULT_HW_DECODE_FAILED = IMAGE_RESULT_BASE + 173,<br>IMAGE_RESULT_ALLOCATER_TYPE_ERROR = IMAGE_RESULT_BASE + 174,<br>IMAGE_RESULT_ALPHA_TYPE_ERROR = IMAGE_RESULT_BASE + 175,<br>IMAGE_RESULT_INDEX_INVALID = IMAGE_RESULT_BASE + 176,<br>IMAGE_RESULT_MEDIA_UNKNOWN = IMAGE_RESULT_BASE + 200<br>} | Enumerates the return values that may be used by the interface.| 
| { OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN = 0,<br>OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE = 1,<br>OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL = 2,<br>OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL = 3 } | Enumerates the pixel map alpha types.| 
| { OHOS_PIXEL_MAP_READ_ONLY = 0,<br>OHOS_PIXEL_MAP_EDITABLE = 1 } | Enumerates the pixel map editing types.| 
| { OHOS::Media::OHOS_IMAGE_RESULT_SUCCESS = 0,<br>OHOS::Media::OHOS_IMAGE_RESULT_BAD_PARAMETER = -1 } | Enumerates the error codes returned by the functions.| 
| { OHOS::Media::OHOS_PIXEL_MAP_FORMAT_NONE = 0,<br>OHOS::Media::OHOS_PIXEL_MAP_FORMAT_RGBA_8888 = 3,<br>OHOS::Media::OHOS_PIXEL_MAP_FORMAT_RGB_565 = 2 } | Enumerates the pixel map formats.| 
| { OHOS::Media::OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE = 0,<br>OHOS::Media::OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP = 1 } | Enumerates the pixel map scale modes.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_Image_InitImageNative](#oh_image_initimagenative) (napi_env env, napi_value source) | Parses an **ImageNative** object from an **Image** object at the JavaScript native layer.| 
| [OH_Image_ClipRect](#oh_image_cliprect) (const [ImageNative](#imagenative) \*native, struct [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) \*rect) | Obtains [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) of an **ImageNative** object.| 
| [OH_Image_Size](#oh_image_size) (const [ImageNative](#imagenative) \*native, struct [OhosImageSize](_ohos_image_size.md) \*size) | Obtains [OhosImageSize](_ohos_image_size.md) of an **ImageNative** object.| 
| [OH_Image_Format](#oh_image_format) (const [ImageNative](#imagenative) \*native, int32_t \*format) | Obtains the image format of an **ImageNative** object.| 
| [OH_Image_GetComponent](#oh_image_getcomponent) (const [ImageNative](#imagenative) \*native, int32_t componentType, struct [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) \*componentNative) | Obtains [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) of an **ImageNative** object.| 
| [OH_Image_Release](#oh_image_release) ([ImageNative](#imagenative) \*native) | Releases an **ImageNative** object.| 
| [OH_PixelMap_CreatePixelMap](#oh_pixelmap_createpixelmap) (napi_env env, [OhosPixelMapCreateOps](_ohos_pixel_map_create_ops.md) info, void \*buf, size_t len, napi_value \*res) | Creates a **PixelMap** object.| 
| [OH_PixelMap_CreateAlphaPixelMap](#oh_pixelmap_createalphapixelmap) (napi_env env, napi_value source, napi_value \*alpha) | Creates a **PixelMap** object that contains only alpha channel information.| 
| [OH_PixelMap_InitNativePixelMap](#oh_pixelmap_initnativepixelmap) (napi_env env, napi_value source) | Initializes a **PixelMap** object.| 
| [OH_PixelMap_GetBytesNumberPerRow](#oh_pixelmap_getbytesnumberperrow) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*num) | Obtains the number of bytes per row of a **NativePixelMap** object.| 
| [OH_PixelMap_GetIsEditable](#oh_pixelmap_getiseditable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*editable) | Checks whether a **NativePixelMap** object is editable.| 
| [OH_PixelMap_IsSupportAlpha](#oh_pixelmap_issupportalpha) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*alpha) | Checks whether a **NativePixelMap** object supports alpha channels.| 
| [OH_PixelMap_SetAlphaAble](#oh_pixelmap_setalphaable) (const [NativePixelMap](#nativepixelmap) \*native, int32_t alpha) | Sets an alpha channel for a **NativePixelMap** object.| 
| [OH_PixelMap_GetDensity](#oh_pixelmap_getdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t \*density) | Obtains the pixel density of a **NativePixelMap** object.| 
| [OH_PixelMap_SetDensity](#oh_pixelmap_setdensity) (const [NativePixelMap](#nativepixelmap) \*native, int32_t density) | Sets the pixel density for a **NativePixelMap** object.| 
| [OH_PixelMap_SetOpacity](#oh_pixelmap_setopacity) (const [NativePixelMap](#nativepixelmap) \*native, float opacity) | Sets the opacity for a **NativePixelMap** object.| 
| [OH_PixelMap_Scale](#oh_pixelmap_scale) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | Scales a **NativePixelMap** object.| 
| [OH_PixelMap_Translate](#oh_pixelmap_translate) (const [NativePixelMap](#nativepixelmap) \*native, float x, float y) | Translates a **NativePixelMap** object.| 
| [OH_PixelMap_Rotate](#oh_pixelmap_rotate) (const [NativePixelMap](#nativepixelmap) \*native, float angle) | Rotates a **NativePixelMap** object.| 
| [OH_PixelMap_Flip](#oh_pixelmap_flip) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y) | Flips a **NativePixelMap** object.| 
| [OH_PixelMap_Crop](#oh_pixelmap_crop) (const [NativePixelMap](#nativepixelmap) \*native, int32_t x, int32_t y, int32_t width, int32_t height) | Crops a **NativePixelMap** object.| 
| [OH_PixelMap_GetImageInfo](#oh_pixelmap_getimageinfo) (const [NativePixelMap](#nativepixelmap) \*native, [OhosPixelMapInfos](_ohos_pixel_map_infos.md) \*info) | Obtains the image information of a **NativePixelMap** object.| 
| [OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels) (const [NativePixelMap](#nativepixelmap) \*native, void \*\*addr) | Obtains the memory address of a **NativePixelMap** object and locks the memory.| 
| [OH_PixelMap_UnAccessPixels](#oh_pixelmap_unaccesspixels) (const [NativePixelMap](#nativepixelmap) \*native) | Unlocks the memory of a **NativePixelMap** object. This function is used with [OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels) in pairs.| 
| [OHOS::Media::OH_GetImageInfo](#oh_getimageinfo) (napi_env env, napi_value value, [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) \*info) | Obtains the information about a **PixelMap** object and stores the information to the [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) struct.| 
| [OHOS::Media::OH_AccessPixels](#oh_accesspixels) (napi_env env, napi_value value, void \*\*addrPtr) | Obtains the memory address of a **PixelMap** object and locks the memory.| 
| [OHOS::Media::OH_UnAccessPixels](#oh_unaccesspixels) (napi_env env, napi_value value) | Unlocks the memory of a **PixelMap** object. This function is used with **OH_AccessPixels** in pairs.| 
| [OH_Image_Receiver_CreateImageReceiver](#oh_image_receiver_createimagereceiver) (napi_env env, struct [OhosImageReceiverInfo](_ohos_image_receiver_info.md) info, napi_value \*res) | Creates an **ImageReceiver** object at the application layer.| 
| [OH_Image_Receiver_InitImageReceiverNative](#oh_image_receiver_initimagereceivernative) (napi_env env, napi_value source) | Initializes an [ImageReceiverNative](#imagereceivernative) object through an **ImageReceiver** object.| 
| [OH_Image_Receiver_GetReceivingSurfaceId](#oh_image_receiver_getreceivingsurfaceid) (const [ImageReceiverNative](#imagereceivernative) \*native, char \*id, size_t len) | Obtains the receiver ID through an [ImageReceiverNative](#imagereceivernative) object.| 
| [OH_Image_Receiver_ReadLatestImage](#oh_image_receiver_readlatestimage) (const [ImageReceiverNative](#imagereceivernative) \*native, napi_value \*image) | Obtains the latest image through an [ImageReceiverNative](#imagereceivernative) object.| 
| [OH_Image_Receiver_ReadNextImage](#oh_image_receiver_readnextimage) (const [ImageReceiverNative](#imagereceivernative) \*native, napi_value \*image) | Obtains the next image through an [ImageReceiverNative](#imagereceivernative) object.| 
| [OH_Image_Receiver_On](#oh_image_receiver_on) (const [ImageReceiverNative](#imagereceivernative) \*native, [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback) | Registers an [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback. This callback is triggered whenever a new image is received.| 
| [OH_Image_Receiver_GetSize](#oh_image_receiver_getsize) (const [ImageReceiverNative](#imagereceivernative) \*native, struct [OhosImageSize](_ohos_image_size.md) \*size) | Obtains the size of the image receiver through an [ImageReceiverNative](#imagereceivernative) object.| 
| [OH_Image_Receiver_GetCapacity](#oh_image_receiver_getcapacity) (const [ImageReceiverNative](#imagereceivernative) \*native, int32_t \*capacity) | Obtains the capacity of the image receiver through an [ImageReceiverNative](#imagereceivernative) object.| 
| [OH_Image_Receiver_GetFormat](#oh_image_receiver_getformat) (const [ImageReceiverNative](#imagereceivernative) \*native, int32_t \*format) | Obtains the format of the image receiver through an [ImageReceiverNative](#imagereceivernative) object.| 
| [OH_Image_Receiver_Release](#oh_image_receiver_release) ([ImageReceiverNative](#imagereceivernative) \*native) | Releases an [ImageReceiverNative](#imagereceivernative) object. Note: This function is not used to release an **ImageReceiver** object.| 
| [OH_ImageSource_Create](#oh_imagesource_create) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*src, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object at the JavaScript native layer based on the specified [OhosImageSource](_ohos_image_source.md) and [OhosImageSourceOps](_ohos_image_source_ops.md) structs.| 
| [OH_ImageSource_CreateIncremental](#oh_imagesource_createincremental) (napi_env env, struct [OhosImageSource](_ohos_image_source.md) \*source, struct [OhosImageSourceOps](_ohos_image_source_ops.md) \*ops, napi_value \*res) | Creates an **ImageSource** object at the JavaScript native layer based on the specified [OhosImageSource](_ohos_image_source.md) and [OhosImageSourceOps](_ohos_image_source_ops.md) structs. The image source data will be updated through **OH_ImageSource_UpdateData**.| 
| [OH_ImageSource_GetSupportedFormats](#oh_imagesource_getsupportedformats) (struct [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) \*res) | Obtains all supported decoding formats.| 
| [OH_ImageSource_InitNative](#oh_imagesource_initnative) (napi_env env, napi_value source) | Converts an **ImageSource** object at the JavaScript native layer to an [ImageSourceNative](#imagesourcenative) object.| 
| [OH_ImageSource_CreatePixelMap](#oh_imagesource_createpixelmap) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | Decodes an **ImageSourceNative** object to obtain a **PixelMap** object at the JavaScript native layer based on the specified [OhosImageDecodingOps](_ohos_image_decoding_ops.md) struct.| 
| [OH_ImageSource_CreatePixelMapList](#oh_imagesource_createpixelmaplist) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageDecodingOps](_ohos_image_decoding_ops.md) \*ops, napi_value \*res) | Decodes an **ImageSourceNative** object to obtain all **PixelMap** objects at the JavaScript native layer based on the specified [OhosImageDecodingOps](_ohos_image_decoding_ops.md) struct.| 
| [OH_ImageSource_GetDelayTime](#oh_imagesource_getdelaytime) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) \*res) | Obtains the delay time list from an **ImageSourceNative** object (such as GIF image source).| 
| [OH_ImageSource_GetFrameCount](#oh_imagesource_getframecount) (const [ImageSourceNative](#imagesourcenative) \*native, uint32_t \*res) | Obtains the number of frames from an **ImageSourceNative** object.| 
| [OH_ImageSource_GetImageInfo](#oh_imagesource_getimageinfo) (const [ImageSourceNative](#imagesourcenative) \*native, int32_t index, struct [OhosImageSourceInfo](_ohos_image_source_info.md) \*info) | Obtains image source information from an **ImageSourceNative** object by index.| 
| [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | Obtains the value of an image property from an **ImageSourceNative** object.| 
| [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*key, struct [OhosImageSourceProperty](_ohos_image_source_property.md) \*value) | Modifies the value of an image property of an **ImageSourceNative** object.| 
| [OH_ImageSource_UpdateData](#oh_imagesource_updatedata) (const [ImageSourceNative](#imagesourcenative) \*native, struct [OhosImageSourceUpdateData](_ohos_image_source_update_data.md) \*data) | Updates the data of an **ImageSourceNative** object.| 
| [OH_ImageSource_Release](#oh_imagesource_release) ([ImageSourceNative](#imagesourcenative) \*native) | Releases an **ImageSourceNative** object.| 


### Variables

| Name| Description| 
| -------- | -------- |
| [OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](#ohos_image_property_bits_per_sample) = "BitsPerSample" | Defines a pointer to bits per sample, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_ORIENTATION](#ohos_image_property_orientation) = "Orientation" | Defines a pointer to the orientation, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](#ohos_image_property_image_length) = "ImageLength" | Defines a pointer to the image length, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](#ohos_image_property_image_width) = "ImageWidth" | Defines a pointer to the image width, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_GPS_LATITUDE](#ohos_image_property_gps_latitude) = "GPSLatitude" | Defines a pointer to the GPS latitude, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](#ohos_image_property_gps_longitude) = "GPSLongitude" | Defines a pointer to the GPS longitude, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | Defines a pointer to the GPS latitude reference information, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | Defines a pointer to the GPS longitude reference information, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](#ohos_image_property_date_time_original) = "DateTimeOriginal" | Defines a pointer to the created date and time, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](#ohos_image_property_exposure_time) = "ExposureTime" | Defines a pointer to the exposure time, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_SCENE_TYPE](#ohos_image_property_scene_type) = "SceneType" | Defines a pointer to the scene type, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | Defines a pointer to the ISO speed ratings, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_F_NUMBER](#ohos_image_property_f_number) = "FNumber" | Defines a pointer to the f-number of the image, one of the image properties.| 
| [OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | Defines a pointer to the compressed bits per pixel, one of the image properties.| 
| [OhosImageRegion::x](#x) | Defines the X coordinate of the start point, in pixels.| 
| [OhosImageRegion::y](#y) | Defines the Y coordinate of the start point, in pixels.| 
| [OhosImageRegion::width](#width) | Defines the width of the region, in pixels.| 
| [OhosImageRegion::height](#height) | Defines the height of the region, in pixels.| 
| [OhosImageSourceOps::density](#density-12) | Defines the pixel density of the image source.| 
| [OhosImageSourceOps::pixelFormat](#pixelformat-13) | Defines the pixel format of the image source. It is usually used to describe the YUV buffer.| 
| [OhosImageSourceOps::size](#size-17) | Defines the pixel width and height of the image source.| 
| [OhosImageDecodingOps::editable](#editable) | Defines whether the output pixel map is editable.| 
| [OhosImageDecodingOps::pixelFormat](#pixelformat-23) | Defines the pixel format of the output pixel map.| 
| [OhosImageDecodingOps::fitDensity](#fitdensity) | Defines the pixel density of the output pixel map.| 
| [OhosImageDecodingOps::index](#index) | Defines the index of the output pixel map.| 
| [OhosImageDecodingOps::sampleSize](#samplesize) | Defines the size of the sample.| 
| [OhosImageDecodingOps::rotate](#rotate) | Defines the decoding rotation option.| 
| [OhosImageDecodingOps::size](#size-27) | Defines the pixel width and height of the output pixel map.| 
| [OhosImageDecodingOps::region](#region) | Defines the region of the output pixel map.| 
| [OhosImageSourceInfo::pixelFormat](#pixelformat-33) | Defines the pixel format of the image source. It is set in [OH_ImageSource_Create](#oh_imagesource_create).| 
| [OhosImageSourceInfo::colorSpace](#colorspace) | Defines the color space of the image source.| 
| [OhosImageSourceInfo::alphaType](#alphatype) | Defines the alpha type of the image source.| 
| [OhosImageSourceInfo::density](#density-22) | Defines the image density of the image source. It is set in [OH_ImageSource_Create](#oh_imagesource_create).| 
| [OhosImageSourceInfo::size](#size-37) | Defines the pixel width and height of the image source.| 
| [OhosImageSource::uri](#uri) = nullptr | Defines a pointer to the image source URI. Only a file URI or Base64 URI is accepted.| 
| [OhosImageSource::uriSize](#urisize) = 0 | Defines the length of the image source URI.| 
| [OhosImageSource::fd](#fd) = -1 | Defines the descriptor of the image source.| 
| [OhosImageSource::buffer](#buffer-12) = nullptr | Defines a pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted.| 
| [OhosImageSource::bufferSize](#buffersize-12) = 0 | Defines the size of the image source buffer.| 
| [OhosImageSourceDelayTimeList::delayTimeList](#delaytimelist) | Defines a pointer to the head of the image source delay time list.| 
| [OhosImageSourceDelayTimeList::size](#size-47) = 0 | Defines the size of the image source delay time list.| 
| [OhosImageSourceSupportedFormat::format](#format) = nullptr | Defines a pointer to the head of the format string.| 
| [OhosImageSourceSupportedFormat::size](#size-57) = 0 | Defines the size of the format string.| 
| [OhosImageSourceSupportedFormatList::supportedFormatList](#supportedformatlist) = nullptr | Defines a double pointer to the head of the format string list.| 
| [OhosImageSourceSupportedFormatList::size](#size-67) = 0 | Defines the size of the format string list.| 
| [OhosImageSourceProperty::value](#value) = nullptr | Defines a pointer to the head of the property string.| 
| [OhosImageSourceProperty::size](#size-77) = 0 | Defines the size of the property string.| 
| [OhosImageSourceUpdateData::buffer](#buffer-22) = nullptr | Defines a pointer to the buffer for storing the update data.| 
| [OhosImageSourceUpdateData::bufferSize](#buffersize-22) = 0 | Defines the size of the buffer.| 
| [OhosImageSourceUpdateData::offset](#offset) = 0 | Defines the offset of the update data in the buffer.| 
| [OhosImageSourceUpdateData::updateLength](#updatelength) = 0 | Defines the length of the update data in the buffer.| 
| [OhosImageSourceUpdateData::isCompleted](#iscompleted) = 0 | Defines whether the image source data update is completed.| 


## Type Description


### ImageNative


```
typedef struct ImageNative_ ImageNative
```

**Description**

Defines an image object at the native layer.

**Since**

10


### ImageReceiverNative

```
typedef struct ImageReceiverNative_ ImageReceiverNative
```

**Description**

Defines the data type name of the image receiver at the native layer.

**Since**

10


### ImageSourceNative

```
typedef struct ImageSourceNative_ ImageSourceNative
```

**Description**

Defines an image source object at the native layer.

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### NativePixelMap

```
typedef struct NativePixelMap_ NativePixelMap
```

**Description**

Defines the data type name of the pixel map at the native layer.

**Since**

10


### OH_Image_Receiver_On_Callback

```
typedef void(* OH_Image_Receiver_On_Callback) ()
```

**Description**

Defines the callbacks for the image interface at the native layer.

**Since**

10


### OhosPixelMapInfos

```
typedef struct OhosPixelMapInfosOhosPixelMapInfos
```

**Description**

Defines the information about a pixel map.

**Since**

10


## Enum Description


### anonymous enum [1/3]

```
anonymous enum
```

**Description**

Enumerates the image formats.

**Since**

10

| Value| Description| 
| -------- | -------- |
| OHOS_IMAGE_FORMAT_YCBCR_422_SP | YCbCr422 semi-planar format.| 
| OHOS_IMAGE_FORMAT_JPEG | JPEG encoding format.| 


### anonymous enum [2/3]

```
anonymous enum
```

**Description**

Enumerates the pixel map alpha types.

**Since**

10

| Value| Description| 
| -------- | -------- |
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNKNOWN | Unknown format.| 
| OHOS_PIXEL_MAP_ALPHA_TYPE_OPAQUE | Opaque format.| 
| OHOS_PIXEL_MAP_ALPHA_TYPE_PREMUL | Premultiplied format.| 
| OHOS_PIXEL_MAP_ALPHA_TYPE_UNPREMUL | Unpremultiplied format.| 


### anonymous enum [3/3]

```
anonymous enum
```

**Description**

Enumerates the error codes returned by the functions.

**Since**

8

**Deprecated from**

10

| Value| Description| 
| -------- | -------- |
| OHOS_IMAGE_RESULT_SUCCESS | Operation success.| 
| OHOS_IMAGE_RESULT_BAD_PARAMETER | Invalid parameter.| 


### anonymous enum [1/3]

```
anonymous enum
```

**Description**

Enumerates the image components.

**Since**

10

| Value| Description| 
| -------- | -------- |
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_Y | Luminance component.| 
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_U | Chrominance component - blue projection.| 
| OHOS_IMAGE_COMPONENT_FORMAT_YUV_V | Chrominance component - red projection.| 
| OHOS_IMAGE_COMPONENT_FORMAT_JPEG | JPEG format.| 


### anonymous enum [2/3]

```
anonymous enum
```

**Description**

Enumerates the pixel map editing types.

**Since**

10

| Value| Description| 
| -------- | -------- |
| OHOS_PIXEL_MAP_READ_ONLY | Read-only.| 
| OHOS_PIXEL_MAP_EDITABLE | Editable.| 


### anonymous enum [3/3]

```
anonymous enum
```

**Description**

Enumerates the pixel map formats.

**Since**

8

**Deprecated from**

10

| Value| Description| 
| -------- | -------- |
| OHOS_PIXEL_MAP_FORMAT_NONE | Unknown format.| 
| OHOS_PIXEL_MAP_FORMAT_RGBA_8888 | 32-bit RGBA, with 8 bits each for R (red), G (green), B (blue), and A (alpha). The data is stored from the most significant bit to the least significant bit.| 
| OHOS_PIXEL_MAP_FORMAT_RGB_565 | 16-bit RGB, with 5, 6, and 5 bits for R, G, and B, respectively. The storage sequence is from the most significant bit to the least significant bit.| 


### anonymous enum

```
anonymous enum
```

**Description**

Enumerates the pixel map scale modes.

**Since**

10

| Value| Description| 
| -------- | -------- |
| OHOS_PIXEL_MAP_SCALE_MODE_FIT_TARGET_SIZE | Adapting to the target image size.| 
| OHOS_PIXEL_MAP_SCALE_MODE_CENTER_CROP | Cropping the center portion of an image to the target size.| 


### IRNdkErrCode

```
enum IRNdkErrCode
```

**Description**

Enumerates the return values that may be used by the interface.

**Since**

10

| Value| Description| 
| -------- | -------- |
| IMAGE_RESULT_SUCCESS | Operation success.| 
| IMAGE_RESULT_BAD_PARAMETER | Invalid parameter.| 
| IMAGE_RESULT_IMAGE_RESULT_BASE | Operation failed.| 
| IMAGE_RESULT_ERR_IPC | IPC error.| 
| IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST | Failed to share the memory.| 
| IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL | Abnormal data in the shared memory.| 
| IMAGE_RESULT_DECODE_ABNORMAL | Failed to decode the image.| 
| IMAGE_RESULT_DATA_ABNORMAL | Abnormal input data.| 
| IMAGE_RESULT_MALLOC_ABNORMAL | an error occurs during memory allocation.| 
| IMAGE_RESULT_DATA_UNSUPPORT | The image type is not supported.| 
| IMAGE_RESULT_INIT_ABNORMAL | Failed to initialize the image.| 
| IMAGE_RESULT_GET_DATA_ABNORMAL | An error occurs during image data retrieval.| 
| IMAGE_RESULT_TOO_LARGE | The image is too large.| 
| IMAGE_RESULT_TRANSFORM | An error occurs during image transformation.| 
| IMAGE_RESULT_COLOR_CONVERT | An error occurs during image color conversion.| 
| IMAGE_RESULT_CROP | An error occurs during image cropping.| 
| IMAGE_RESULT_SOURCE_DATA | The image source data is incorrect.| 
| IMAGE_RESULT_SOURCE_DATA_INCOMPLETE | The image source data is incomplete.| 
| IMAGE_RESULT_MISMATCHED_FORMAT | The image format does not match.| 
| IMAGE_RESULT_UNKNOWN_FORMAT | Unknown image format.| 
| IMAGE_RESULT_SOURCE_UNRESOLVED | The image source is not parsed.| 
| IMAGE_RESULT_INVALID_PARAMETER | Invalid image parameter.| 
| IMAGE_RESULT_DECODE_FAILED | Failed to decode the image.| 
| IMAGE_RESULT_PLUGIN_REGISTER_FAILED | Failed to register the plug-in.| 
| IMAGE_RESULT_PLUGIN_CREATE_FAILED | Failed to create the plug-in.| 
| IMAGE_RESULT_ENCODE_FAILED | Failed to encode the image.| 
| IMAGE_RESULT_ADD_PIXEL_MAP_FAILED | Failed to add the pixel map.| 
| IMAGE_RESULT_HW_DECODE_UNSUPPORT | Hardware decoding is not supported.| 
| IMAGE_RESULT_DECODE_HEAD_ABNORMAL | Failed to decode the image header.| 
| IMAGE_RESULT_DECODE_EXIF_UNSUPPORT | Exchangeable Image File (EXIF) is not supported for image decoding.| 
| IMAGE_RESULT_PROPERTY_NOT_EXIST | The image property does not exist.| 
| IMAGE_RESULT_MEDIA_DATA_UNSUPPORT | The media type is not supported.| 
| IMAGE_RESULT_MEDIA_TOO_LARGE | The media is too large.| 
| IMAGE_RESULT_MEDIA_MALLOC_FAILED | Memory allocation failed.| 
| IMAGE_RESULT_MEDIA_END_OF_STREAM | Failed to end the media data stream.| 
| IMAGE_RESULT_MEDIA_IO_ABNORMAL | Abnormal input and output streams.| 
| IMAGE_RESULT_MEDIA_MALFORMED | The media service functions abnormally.| 
| IMAGE_RESULT_MEDIA_BUFFER_TOO_SMALL | The media data is too small.| 
| IMAGE_RESULT_MEDIA_OUT_OF_RANGE | The media is out of range.| 
| IMAGE_RESULT_MEDIA_STATUS_ABNORMAL | Abnormal media status.| 
| IMAGE_RESULT_MEDIA_VALUE_INVALID | Invalid media value.| 
| IMAGE_RESULT_MEDIA_NULL_POINTER | Media operation failed.| 
| IMAGE_RESULT_MEDIA_INVALID_OPERATION | Invalid media operation.| 
| IMAGE_RESULT_MEDIA_ERR_PLAYER_NOT_INIT | an error occurs during media initialization.| 
| IMAGE_RESULT_MEDIA_EARLY_PREPARE | Media preprocessing is carried out too early.| 
| IMAGE_RESULT_MEDIA_SEEK_ERR | The seek operation failed.| 
| IMAGE_RESULT_MEDIA_PERMISSION_DENIED | Permission denied.| 
| IMAGE_RESULT_MEDIA_DEAD_OBJECT | The media object is deregistered.| 
| IMAGE_RESULT_MEDIA_TIMED_OUT | A timeout occurs.| 
| IMAGE_RESULT_MEDIA_TRACK_NOT_ALL_SUPPORTED | The media capability is not supported.| 
| IMAGE_RESULT_MEDIA_ADAPTER_INIT_FAILED | Failed to initialize the media adapter.| 
| IMAGE_RESULT_MEDIA_WRITE_PARCEL_FAIL | Failed to write data to the parcel.| 
| IMAGE_RESULT_MEDIA_READ_PARCEL_FAIL | Failed to read data from the parcel.| 
| IMAGE_RESULT_MEDIA_NO_AVAIL_BUFFER | Invalid data.| 
| IMAGE_RESULT_MEDIA_INVALID_PARAM | Invalid parameters.| 
| IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_EXIST | The media codec adapter does not exist.| 
| IMAGE_RESULT_MEDIA_CREATE_CODEC_ADAPTER_FAILED | Failed to create the media codec adapter.| 
| IMAGE_RESULT_MEDIA_CODEC_ADAPTER_NOT_INIT | The media codec adapter is not initialized.| 
| IMAGE_RESULT_MEDIA_ZCODEC_CREATE_FAILED | Failed to create the media codec.| 
| IMAGE_RESULT_MEDIA_ZCODEC_NOT_EXIST | The media codec does not exist.| 
| IMAGE_RESULT_MEDIA_JNI_CLASS_NOT_EXIST | The media JNI layer class does not exist.| 
| IMAGE_RESULT_MEDIA_JNI_METHOD_NOT_EXIST | The media JNI layer method does not exist.| 
| IMAGE_RESULT_MEDIA_JNI_NEW_OBJ_FAILED | Failed to create the object at the media JNI layer.| 
| IMAGE_RESULT_MEDIA_JNI_COMMON_ERROR | The media JNI layer is abnormal.| 
| IMAGE_RESULT_MEDIA_DISTRIBUTE_NOT_SUPPORT | The distributed feature is not supported.| 
| IMAGE_RESULT_MEDIA_SOURCE_NOT_SET | The media source is not set.| 
| IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_INIT | The media RTSP adapter is not initialized.| 
| IMAGE_RESULT_MEDIA_RTSP_ADAPTER_NOT_EXIST | The media RTSP adapter does not exist.| 
| IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT | The media does not support the RTSP surface.| 
| IMAGE_RESULT_MEDIA_RTSP_CAPTURE_NOT_INIT | Failed to initialize the media RTSP capturer.| 
| IMAGE_RESULT_MEDIA_RTSP_SOURCE_URL_INVALID | Invalid media RTSP source path.| 
| IMAGE_RESULT_MEDIA_RTSP_VIDEO_TRACK_NOT_FOUND | No video capability is found in the media RTSP.| 
| IMAGE_RESULT_MEDIA_RTSP_CAMERA_NUM_REACH_MAX | The maximum number of RTSP cameras has been reached.| 
| IMAGE_RESULT_MEDIA_SET_VOLUME | Failed to set the volume.| 
| IMAGE_RESULT_MEDIA_NUMBER_OVERFLOW | The number of operations overflows.| 
| IMAGE_RESULT_MEDIA_DIS_PLAYER_UNSUPPORTED | The distributed media player is not supported.| 
| IMAGE_RESULT_MEDIA_DENCODE_ICC_FAILED | Failed to decode the ICC.| 
| IMAGE_RESULT_MEDIA_ENCODE_ICC_FAILED | Failed to encode the ICC.| 
| IMAGE_RESULT_MEDIA_READ_PIXELMAP_FAILED | Failed to read the pixel map.| 
| IMAGE_RESULT_MEDIA_WRITE_PIXELMAP_FAILED | Failed to write the pixel map.| 
| IMAGE_RESULT_MEDIA_PIXELMAP_NOT_ALLOW_MODIFY | The pixel map cannot be modified.| 
| IMAGE_RESULT_MEDIA_CONFIG_FAILED | Configuration failed.| 
| IMAGE_RESULT_JNI_ENV_ABNORMAL | The JNI environment is abnormal.| 
| IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED | Failed to allocate memory for the surface.| 
| IMAGE_RESULT_CREATE_SURFACE_FAILED | Failed to create the surface.| 
| IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED | Failed to obtain parameters from the surface.| 
| IMAGE_RESULT_GET_SURFACE_FAILED | Failed to obtain the surface.| 
| IMAGE_RESULT_SURFACE_ACQUIRE_BUFFER_FAILED | Failed to apply for a buffer.| 
| IMAGE_RESULT_SURFACE_REQUEST_BUFFER_FAILED | Failed to request a buffer.| 
| IMAGE_RESULT_REGISTER_LISTENER_FAILED | Failed to register the listener.| 
| IMAGE_RESULT_REGISTER_BUFFER_FAILED | Failed to register the buffer.| 
| IMAGE_RESULT_FREAD_FAILED | Failed to read the file.| 
| IMAGE_RESULT_PEEK_FAILED | Failed to peek the file.| 
| IMAGE_RESULT_SEEK_FAILED | Failed to seek the file.| 
| IMAGE_RESULT_STREAM_SIZE_ERROR | The data stream is damaged.| 
| IMAGE_RESULT_FILE_FD_ERROR | The file descriptor is damaged.| 
| IMAGE_RESULT_FILE_DAMAGED | The file is damaged.| 
| IMAGE_RESULT_CREATE_DECODER_FAILED | Failed to create a decoder.| 
| IMAGE_RESULT_CREATE_ENCODER_FAILED | Failed to create an encoder.| 
| IMAGE_RESULT_CHECK_FORMAT_ERROR | Failed to check the format.| 
| IMAGE_RESULT_THIRDPART_SKIA_ERROR | Skia decoding failed.| 
| IMAGE_RESULT_HW_DECODE_FAILED | Hardware decoding failed.| 
| IMAGE_RESULT_ALLOCATER_TYPE_ERROR | Failed to verify the memory type.| 
| IMAGE_RESULT_ALPHA_TYPE_ERROR | Failed to verify the alpha type.| 
| IMAGE_RESULT_INDEX_INVALID | Invalid parameter.| 
| IMAGE_RESULT_MEDIA_UNKNOWN | Unknown error.| 


## Function Description


### OH_AccessPixels()

```
int32_t OHOS::Media::OH_AccessPixels (napi_env env, napi_value value, void ** addrPtr )
```

**Description**

Obtains the memory address of a **PixelMap** object and locks the memory.

**\*addrPtr** is the memory address obtained. After finishing the access, you must use **OH_UnAccessPixels** to unlock the memory. Then the memory cannot be accessed or operated.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| value | **PixelMap** object at the application layer.| 
| addrPtr | Double pointer to the memory address.| 

**Returns**

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

8

**Deprecated from**

10

**See**

UnAccessPixels


### OH_GetImageInfo()

```
int32_t OHOS::Media::OH_GetImageInfo (napi_env env, napi_value value, OhosPixelMapInfo * info )
```

**Description**

Obtains the information about a **PixelMap** object and stores the information to the [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md) struct.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| value | **PixelMap** object at the application layer.| 
| info | Pointer to the object that stores the information obtained. For details, see [OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md).| 

**Returns**

Returns **0** if the information is obtained and stored successfully; returns an error code otherwise.

**Since**

8

**Deprecated from**

10

**See**

[OhosPixelMapInfo](_o_h_o_s_1_1_media_1_1_ohos_pixel_map_info.md)


### OH_Image_ClipRect()

```
int32_t OH_Image_ClipRect (const ImageNative * native, struct OhosImageRect * rect )
```

**Description**

Obtains [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) of an **ImageNative** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an **ImageNative** object.| 
| rect | Pointer to the [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md) object obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED** if parameters fail to be obtained from the surface.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

**Since**

10

**See**

ImageNative, [OhosImageRect](_o_h_o_s_1_1_media_1_1_ohos_image_rect.md)


### OH_Image_Format()

```
int32_t OH_Image_Format (const ImageNative * native, int32_t * format )
```

**Description**

Obtains the image format of an **ImageNative** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an **ImageNative** object.| 
| format | Pointer to the image format obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED** if parameters fail to be obtained from the surface.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

**Since**

10

**See**

ImageNative


### OH_Image_GetComponent()

```
int32_t OH_Image_GetComponent (const ImageNative * native, int32_t componentType, struct OhosImageComponent * componentNative )
```

**Description**

Obtains [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) of an **ImageNative** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an **ImageNative** object.| 
| componentType | Type of the component.| 
| componentNative | Pointer to the [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md) object obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED** if parameters fail to be obtained from the surface.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

**Since**

10

**See**

ImageNative, [OhosImageComponent](_o_h_o_s_1_1_media_1_1_ohos_image_component.md)


### OH_Image_InitImageNative()

```
ImageNative* OH_Image_InitImageNative (napi_env env, napi_value source )
```

**Description**

Parses an **ImageNative** object from an **Image** object at the JavaScript native layer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the JNI environment.| 
| source | **Image** object at the JavaScript native layer.| 

**Returns**

Returns a pointer to the **ImageNative** object if the operation is successful; returns a null pointer otherwise.

**Since**

10

**See**

ImageNative, OH_Image_Release


### OH_Image_Receiver_CreateImageReceiver()

```
int32_t OH_Image_Receiver_CreateImageReceiver (napi_env env, struct OhosImageReceiverInfo info, napi_value * res )
```

**Description**

Creates an **ImageReceiver** object at the application layer.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| info | Options for setting the **ImageReceiver** object.| 
| res | Pointer to the **ImageReceiver** object at the application layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid or a parameter fails to be obtained from the surface.

Returns **IMAGE_RESULT_CREATE_SURFACE_FAILED** if the surface fails to be created.

Returns **IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED** if the buffer fails to be allocated to the surface.

Returns **IMAGE_RESULT_GET_SURFACE_FAILED** if the surface fails to be obtained.

Returns **IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT** if the media RTSP surface is not supported.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT** if the media type is not supported.

**Since**

10

**See**

[OhosImageReceiverInfo](_ohos_image_receiver_info.md)


### OH_Image_Receiver_GetCapacity()

```
int32_t OH_Image_Receiver_GetCapacity (const ImageReceiverNative * native, int32_t * capacity )
```

**Description**

Obtains the capacity of the image receiver through an [ImageReceiverNative](#imagereceivernative) object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 
| capacity | Pointer to the capacity obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative), [OhosImageSize](_ohos_image_size.md)


### OH_Image_Receiver_GetFormat()

```
int32_t OH_Image_Receiver_GetFormat (const ImageReceiverNative * native, int32_t * format )
```

**Description**

Obtains the format of the image receiver through an [ImageReceiverNative](#imagereceivernative) object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 
| format | Pointer to the format obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_GetReceivingSurfaceId()

```
int32_t OH_Image_Receiver_GetReceivingSurfaceId (const ImageReceiverNative * native, char * id, size_t len )
```

**Description**

Obtains the receiver ID through an [ImageReceiverNative](#imagereceivernative) object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 
| id | Pointer to the buffer that stores the ID string obtained.| 
| len | Size of the buffer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid or a parameter fails to be obtained from the surface.

Returns **IMAGE_RESULT_GET_SURFACE_FAILED** if the surface fails to be obtained.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT** if the media type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_GetSize()

```
int32_t OH_Image_Receiver_GetSize (const ImageReceiverNative * native, struct OhosImageSize * size )
```

**Description**

Obtains the size of the image receiver through an [ImageReceiverNative](#imagereceivernative) object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 
| size | Pointer to the [OhosImageSize](_ohos_image_size.md) object obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative), [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback)


### OH_Image_Receiver_InitImageReceiverNative()

```
ImageReceiverNative* OH_Image_Receiver_InitImageReceiverNative (napi_env env, napi_value source )
```

**Description**

Initializes an [ImageReceiverNative](#imagereceivernative) object through an **ImageReceiver** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| source | **ImageReceiver** object.| 

**Returns**

Returns a pointer to the [ImageReceiverNative](#imagereceivernative) object obtained if the operation is successful; returns a null pointer otherwise.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative), [OH_Image_Receiver_Release](#oh_image_receiver_release)


### OH_Image_Receiver_On()

```
int32_t OH_Image_Receiver_On (const ImageReceiverNative * native, OH_Image_Receiver_On_Callback callback )
```

**Description**

Registers an [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback. This callback is triggered whenever a new image is received.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 
| callback | [OH_Image_Receiver_On_Callback](#oh_image_receiver_on_callback) callback to register.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid or a parameter fails to be obtained from the surface.

Returns **IMAGE_RESULT_GET_SURFACE_FAILED** if the surface fails to be obtained.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT** if the media type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_ReadLatestImage()

```
int32_t OH_Image_Receiver_ReadLatestImage (const ImageReceiverNative * native, napi_value * image )
```

**Description**

Obtains the latest image through an [ImageReceiverNative](#imagereceivernative) object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 
| image | Pointer to an **Image** object at the application layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid or a parameter fails to be obtained from the surface.

Returns **IMAGE_RESULT_CREATE_SURFACE_FAILED** if the surface fails to be created.

Returns **IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED** if the buffer fails to be allocated to the surface.

Returns **IMAGE_RESULT_GET_SURFACE_FAILED** if the surface fails to be obtained.

Returns **IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT** if the media RTSP surface is not supported.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT** if the media type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_ReadNextImage()

```
int32_t OH_Image_Receiver_ReadNextImage (const ImageReceiverNative * native, napi_value * image )
```

**Description**

Obtains the next image through an [ImageReceiverNative](#imagereceivernative) object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 
| image | Pointer to an **Image** object at the application layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid or a parameter fails to be obtained from the surface.

Returns **IMAGE_RESULT_CREATE_SURFACE_FAILED** if the surface fails to be created.

Returns **IMAGE_RESULT_SURFACE_GRALLOC_BUFFER_FAILED** if the buffer fails to be allocated to the surface.

Returns **IMAGE_RESULT_GET_SURFACE_FAILED** if the surface fails to be obtained.

Returns **IMAGE_RESULT_MEDIA_RTSP_SURFACE_UNSUPPORT** if the media RTSP surface is not supported.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_MEDIA_DATA_UNSUPPORT** if the media type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Receiver_Release()

```
int32_t OH_Image_Receiver_Release (ImageReceiverNative * native)
```

**Description**

Releases an [ImageReceiverNative](#imagereceivernative) object. Note: This function is not used to release an **ImageReceiver** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageReceiverNative](#imagereceivernative) object.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

[ImageReceiverNative](#imagereceivernative)


### OH_Image_Release()

```
int32_t OH_Image_Release (ImageNative * native)
```

**Description**

Releases an **ImageNative** object. Note: This function is not used to release an **Image** object at the JavaScript native API. It is used to release an **ImageNative** object parsed by calling **OH_Image_InitImageNative**.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an **ImageNative** object.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

**Since**

10

**See**

ImageNative, OH_Image_InitImageNative


### OH_Image_Size()

```
int32_t OH_Image_Size (const ImageNative * native, struct OhosImageSize * size )
```

**Description**

Obtains [OhosImageSize](_ohos_image_size.md) of an **ImageNative** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an **ImageNative** object.| 
| size | Pointer to the [OhosImageSize](_ohos_image_size.md) object obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_SURFACE_GET_PARAMETER_FAILED** if parameters fail to be obtained from the surface.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

**Since**

10

**See**

ImageNative, [OhosImageSize](_ohos_image_size.md)


### OH_ImageSource_Create()

```
int32_t OH_ImageSource_Create (napi_env env, struct OhosImageSource * src, struct OhosImageSourceOps * ops, napi_value * res )
```

**Description**

Creates an **ImageSource** object at the JavaScript native layer based on the specified [OhosImageSource](_ohos_image_source.md) and [OhosImageSourceOps](_ohos_image_source_ops.md) structs.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the JNI environment.| 
| src | Pointer to the input resource of the image source. For details, see [OhosImageSource](_ohos_image_source.md).| 
| ops | Pointer to the options for creating the image source. For details, see [OhosImageSourceOps](_ohos_image_source_ops.md).| 
| res | Pointer to an **ImageSource** object at the JavaScript native layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_SOURCE_DATA_INCOMPLETE** if the image source data is incomplete.

Returns **IMAGE_RESULT_SOURCE_DATA** if the image source data is incorrect.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_TOO_LARGE** if the image is too large.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

Returns **IMAGE_RESULT_FILE_DAMAGED** if the file is damaged.

Returns **IMAGE_RESULT_FILE_FD_ERROR** if the file descriptor is incorrect.

Returns **IMAGE_RESULT_STREAM_SIZE_ERROR** if the data stream is incorrect.

Returns **IMAGE_RESULT_SEEK_FAILED** if seeking the file fails.

Returns **IMAGE_RESULT_PEEK_FAILED** if peeking the file fails.

Returns **IMAGE_RESULT_FREAD_FAILED** if reading the file fails.

**Since**

10

**See**

[OhosImageSource](_ohos_image_source.md), [OhosImageSourceOps](_ohos_image_source_ops.md)


### OH_ImageSource_CreateIncremental()

```
int32_t OH_ImageSource_CreateIncremental (napi_env env, struct OhosImageSource * source, struct OhosImageSourceOps * ops, napi_value * res )
```

**Description**

Creates an **ImageSource** object at the JavaScript native layer based on the specified [OhosImageSource](_ohos_image_source.md) and [OhosImageSourceOps](_ohos_image_source_ops.md) structs. The image source data will be updated through **OH_ImageSource_UpdateData**.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the JNI environment.| 
| src | Pointer to the input resource of the image source. Only the buffer type is accepted. For details, see [OhosImageSource](_ohos_image_source.md).| 
| ops | Pointer to the options for creating the image source. For details, see [OhosImageSourceOps](_ohos_image_source_ops.md).| 
| res | Pointer to an **ImageSource** object at the JavaScript native layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_SOURCE_DATA_INCOMPLETE** if the image source data is incomplete.

Returns **IMAGE_RESULT_SOURCE_DATA** if the image source data is incorrect.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_TOO_LARGE** if the image is too large.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

Returns **IMAGE_RESULT_FILE_DAMAGED** if the file is damaged.

Returns **IMAGE_RESULT_FILE_FD_ERROR** if the file descriptor is incorrect.

Returns **IMAGE_RESULT_STREAM_SIZE_ERROR** if the data stream is incorrect.

Returns **IMAGE_RESULT_SEEK_FAILED** if seeking the file fails.

Returns **IMAGE_RESULT_PEEK_FAILED** if peeking the file fails.

Returns **IMAGE_RESULT_FREAD_FAILED** if reading the file fails.

**Since**

10

**See**

[OhosImageSource](_ohos_image_source.md), [OhosImageSourceOps](_ohos_image_source_ops.md), [OH_ImageSource_UpdateData](#oh_imagesource_updatedata)


### OH_ImageSource_CreatePixelMap()

```
int32_t OH_ImageSource_CreatePixelMap (const ImageSourceNative * native, struct OhosImageDecodingOps * ops, napi_value * res )
```

**Description**

Decodes an **ImageSourceNative** object to obtain a **PixelMap** object at the JavaScript native layer based on the specified [OhosImageDecodingOps](_ohos_image_decoding_ops.md) struct.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| ops | Pointer to the options for decoding the image source. For details, see [OhosImageDecodingOps](_ohos_image_decoding_ops.md).| 
| res | Pointer to a **PixelMap** object at the JavaScript native layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_CREATE_ENCODER_FAILED** if the encoder fails to be created.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_INIT_ABNORMAL** if the image fails to be initialized.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ENCODE_FAILED** if the image fails to be encoded.

Returns **IMAGE_RESULT_HW_DECODE_UNSUPPORT** if hardware decoding is not supported.

Returns **IMAGE_RESULT_HW_DECODE_FAILED** if hardware decoding fails.

Returns **IMAGE_RESULT_ERR_IPC** if IPC fails.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OhosImageDecodingOps](_ohos_image_decoding_ops.md)


### OH_ImageSource_CreatePixelMapList()

```
int32_t OH_ImageSource_CreatePixelMapList (const ImageSourceNative * native, struct OhosImageDecodingOps * ops, napi_value * res )
```

**Description**

Decodes an **ImageSourceNative** object to obtain all **PixelMap** objects at the JavaScript native layer based on the specified [OhosImageDecodingOps](_ohos_image_decoding_ops.md) struct.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| ops | Pointer to the options for decoding the image source. For details, see [OhosImageDecodingOps](_ohos_image_decoding_ops.md).| 
| res | Pointer to **PixelMap** objects at the JavaScript native layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_CREATE_ENCODER_FAILED** if the encoder fails to be created.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_INIT_ABNORMAL** if the image fails to be initialized.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ENCODE_FAILED** if the image fails to be encoded.

Returns **IMAGE_RESULT_HW_DECODE_UNSUPPORT** if hardware decoding is not supported.

Returns **IMAGE_RESULT_HW_DECODE_FAILED** if hardware decoding fails.

Returns **IMAGE_RESULT_ERR_IPC** if IPC fails.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OhosImageDecodingOps](_ohos_image_decoding_ops.md)


### OH_ImageSource_GetDelayTime()

```
int32_t OH_ImageSource_GetDelayTime (const ImageSourceNative * native, struct OhosImageSourceDelayTimeList * res )
```

**Description**

Obtains the delay time list from an **ImageSourceNative** object (such as GIF image source).

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| res | Pointer to the [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md) object obtained. When the input **delayTimeList** is a null pointer and **size** is **0**, the size of the delay time list is returned through **size** in **res**. To obtain the complete delay time list, a space greater than **size** is required.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceDelayTimeList](_ohos_image_source_delay_time_list.md)


### OH_ImageSource_GetFrameCount()

```
int32_t OH_ImageSource_GetFrameCount (const ImageSourceNative * native, uint32_t * res )
```

**Description**

Obtains the number of frames from an **ImageSourceNative** object.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| res | Pointer to the frame count.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative)


### OH_ImageSource_GetImageInfo()

```
int32_t OH_ImageSource_GetImageInfo (const ImageSourceNative * native, int32_t index, struct OhosImageSourceInfo * info )
```

**Description**

Obtains image source information from an **ImageSourceNative** object by index.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| index | Index.| 
| info | Pointer to the [OhosImageSourceInfo](_ohos_image_source_info.md) object obtained.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceInfo](_ohos_image_source_info.md)


### OH_ImageSource_GetImageProperty()

```
int32_t OH_ImageSource_GetImageProperty (const ImageSourceNative * native, struct OhosImageSourceProperty * key, struct OhosImageSourceProperty * value )
```

**Description**

Obtains the value of an image property from an **ImageSourceNative** object.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| key | Pointer to the property. For details, see [OhosImageSourceProperty](_ohos_image_source_property.md).| 
| value | Pointer to the [OhosImageSourceProperty](_ohos_image_source_property.md) object obtained. If the input **value** is a null pointer and **size** is **0**, the size of the property value is returned through **size** in **value**. To obtain the complete property value, a space greater than **size** is required.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceProperty](_ohos_image_source_property.md)


### OH_ImageSource_GetSupportedFormats()

```
int32_t OH_ImageSource_GetSupportedFormats (struct OhosImageSourceSupportedFormatList * res)
```

**Description**

Obtains all supported decoding formats.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| res | Pointer to the [OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md) struct. If the input **supportedFormatList** is a null pointer and **size** is 0, the size of the supported formats is returned through **size** in **res**.<br>To obtain all formats, a space larger than **size** is required. In addition, sufficient space must be reserved for each format supported.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

**Since**

10

**See**

[OhosImageSourceSupportedFormatList](_ohos_image_source_supported_format_list.md), [OhosImageSourceSupportedFormat](_ohos_image_source_supported_format.md)


### OH_ImageSource_InitNative()

```
ImageSourceNative* OH_ImageSource_InitNative (napi_env env, napi_value source )
```

**Description**

Converts an **ImageSource** object at the JavaScript native layer to an [ImageSourceNative](#imagesourcenative) object.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the JNI environment.| 
| source | Pointer to an **ImageSource** object at the JavaScript native layer.| 

**Returns**

Returns a pointer to the [ImageSourceNative](#imagesourcenative) object if the operation is successful; returns a null pointer otherwise.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OH_ImageSource_Release](#oh_imagesource_release)


### OH_ImageSource_ModifyImageProperty()

```
int32_t OH_ImageSource_ModifyImageProperty (const ImageSourceNative * native, struct OhosImageSourceProperty * key, struct OhosImageSourceProperty * value )
```

**Description**

Modifies the value of an image property of an **ImageSourceNative** object.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| key | Pointer to the property. For details, see [OhosImageSourceProperty](_ohos_image_source_property.md).| 
| value | Pointer to the new value of the property.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_DECODE_EXIF_UNSUPPORT** if EXIF is not supported for image decoding.

Returns **IMAGE_RESULT_PROPERTY_NOT_EXIST** if the image property does not exist.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceProperty](_ohos_image_source_property.md)


### OH_ImageSource_Release()

```
int32_t OH_ImageSource_Release (ImageSourceNative * native)
```

**Description**

Releases an **ImageSourceNative** object.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OH_ImageSource_Create](#oh_imagesource_create), [OH_ImageSource_CreateIncremental](#oh_imagesource_createincremental)


### OH_ImageSource_UpdateData()

```
int32_t OH_ImageSource_UpdateData (const ImageSourceNative * native, struct OhosImageSourceUpdateData * data )
```

**Description**

Updates the data of an **ImageSourceNative** object.

\@Syscap SystemCapability.Multimedia.Image

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to an [ImageSourceNative](#imagesourcenative) object.| 
| data | Pointer to the update data. For details, see [OhosImageSourceUpdateData](_ohos_image_source_update_data.md).| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_CREATE_ENCODER_FAILED** if the encoder fails to be created.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

Returns **IMAGE_RESULT_INIT_ABNORMAL** if the image fails to be initialized.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ENCODE_FAILED** if the image fails to be encoded.

Returns **IMAGE_RESULT_HW_DECODE_UNSUPPORT** if hardware decoding is not supported.

Returns **IMAGE_RESULT_HW_DECODE_FAILED** if hardware decoding fails.

Returns **IMAGE_RESULT_ERR_IPC** if IPC fails.

Returns **IMAGE_RESULT_INDEX_INVALID** if the index is invalid.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

[ImageSourceNative](#imagesourcenative), [OhosImageSourceUpdateData](_ohos_image_source_update_data.md)


### OH_PixelMap_AccessPixels()

```
int32_t OH_PixelMap_AccessPixels (const NativePixelMap * native, void ** addr )
```

**Description**

Obtains the memory address of a **NativePixelMap** object and locks the memory.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| addr | Double pointer to the memory address.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

AccessPixels


### OH_PixelMap_CreateAlphaPixelMap()

```
int32_t OH_PixelMap_CreateAlphaPixelMap (napi_env env, napi_value source, napi_value * alpha )
```

**Description**

Creates a **PixelMap** object that contains only alpha channel information.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| source | Options for setting the **PixelMap** object.| 
| alpha | Pointer to the alpha channel.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_CREATE_ENCODER_FAILED** if the encoder fails to be created.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_INIT_ABNORMAL** if the image fails to be initialized.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ENCODE_FAILED** if the image fails to be encoded.

Returns **IMAGE_RESULT_HW_DECODE_UNSUPPORT** if hardware decoding is not supported.

Returns **IMAGE_RESULT_HW_DECODE_FAILED** if hardware decoding fails.

Returns **IMAGE_RESULT_INDEX_INVALID** if a parameter is invalid.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

CreateAlphaPixelMap


### OH_PixelMap_CreatePixelMap()

```
int32_t OH_PixelMap_CreatePixelMap (napi_env env, OhosPixelMapCreateOps info, void * buf, size_t len, napi_value * res )
```

**Description**

Creates a **PixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| info | Options for setting the **PixelMap** object.| 
| buf | Pointer to the buffer of the image.| 
| len | Image size.| 
| res | Pointer to the **PixelMap** object at the application layer.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_DECODE_HEAD_ABNORMAL** if an error occurs during decoding of the image header.

Returns **IMAGE_RESULT_CREATE_DECODER_FAILED** if the decoder fails to be created.

Returns **IMAGE_RESULT_CREATE_ENCODER_FAILED** if the encoder fails to be created.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_DECODE_ABNORMAL** if image decoding fails.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_INIT_ABNORMAL** if the image fails to be initialized.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ENCODE_FAILED** if the image fails to be encoded.

Returns **IMAGE_RESULT_HW_DECODE_UNSUPPORT** if hardware decoding is not supported.

Returns **IMAGE_RESULT_HW_DECODE_FAILED** if hardware decoding fails.

Returns **IMAGE_RESULT_INDEX_INVALID** if a parameter is invalid.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

CreatePixelMap


### OH_PixelMap_Crop()

```
int32_t OH_PixelMap_Crop (const NativePixelMap * native, int32_t x, int32_t y, int32_t width, int32_t height )
```

**Description**

Crops a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| x | X-coordinate of the upper left corner of the target image.| 
| y | Y-coordinate of the upper left corner of the target image.| 
| width | Width of the cropped region.| 
| height | Height of the cropped region.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

Crop


### OH_PixelMap_Flip()

```
int32_t OH_PixelMap_Flip (const NativePixelMap * native, int32_t x, int32_t y )
```

**Description**

Flips a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| x | Whether to flip around the x axis.| 
| y | Whether to flip around the y axis.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

Flip


### OH_PixelMap_GetBytesNumberPerRow()

```
int32_t OH_PixelMap_GetBytesNumberPerRow (const NativePixelMap * native, int32_t * num )
```

**Description**

Obtains the number of bytes per row of a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| num | Pointer to the number of bytes per row.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

GetBytesNumberPerRow


### OH_PixelMap_GetDensity()

```
int32_t OH_PixelMap_GetDensity (const NativePixelMap * native, int32_t * density )
```

**Description**

Obtains the pixel density of a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| density | Pointer to the pixel density.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

GetDensity


### OH_PixelMap_GetImageInfo()

```
int32_t OH_PixelMap_GetImageInfo (const NativePixelMap * native, OhosPixelMapInfos * info )
```

**Description**

Obtains the image information of a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| info | Pointer to the image information.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

[OhosPixelMapInfos](_ohos_pixel_map_infos.md)


### OH_PixelMap_GetIsEditable()

```
int32_t OH_PixelMap_GetIsEditable (const NativePixelMap * native, int32_t * editable )
```

**Description**

Checks whether a **NativePixelMap** object is editable.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| editable | Pointer to the editing type of the **NativePixelMap** object.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

GetIsEditable


### OH_PixelMap_InitNativePixelMap()

```
NativePixelMap* OH_PixelMap_InitNativePixelMap (napi_env env, napi_value source )
```

**Description**

Initializes a **PixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| source | Options for setting the **PixelMap** object.| 

**Returns**

Returns a pointer to the **NativePixelMap** object if the operation is successful; returns an error code otherwise.

**Since**

10

**See**

InitNativePixelMap


### OH_PixelMap_IsSupportAlpha()

```
int32_t OH_PixelMap_IsSupportAlpha (const NativePixelMap * native, int32_t * alpha )
```

**Description**

Checks whether a **NativePixelMap** object supports alpha channels.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| alpha | Pointer to the support for alpha channels.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

IsSupportAlpha


### OH_PixelMap_Rotate()

```
int32_t OH_PixelMap_Rotate (const NativePixelMap * native, float angle )
```

**Description**

Rotates a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| angle | Angle to rotate.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

Rotate


### OH_PixelMap_Scale()

```
int32_t OH_PixelMap_Scale (const NativePixelMap * native, float x, float y )
```

**Description**

Scales a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| x | Scaling ratio of the width.| 
| y | Scaling ratio of the height.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_INIT_ABNORMAL** if the image fails to be initialized.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

Scale


### OH_PixelMap_SetAlphaAble()

```
int32_t OH_PixelMap_SetAlphaAble (const NativePixelMap * native, int32_t alpha )
```

**Description**

Sets an alpha channel for a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| alpha | Alpha channel to set.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

SetAlphaAble


### OH_PixelMap_SetDensity()


```
int32_t OH_PixelMap_SetDensity (const NativePixelMap * native, int32_t density )
```

**Description**

Sets the pixel density for a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| density | Pixel density to set.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

GetDensity


### OH_PixelMap_SetOpacity()

```
int32_t OH_PixelMap_SetOpacity (const NativePixelMap * native, float opacity )
```

**Description**

Sets the opacity for a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| opacity | Opacity to set.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the image type is not supported.

**Since**

10

**See**

SetOpacity


### OH_PixelMap_Translate()

```
int32_t OH_PixelMap_Translate (const NativePixelMap * native, float x, float y )
```

**Description**

Translates a **NativePixelMap** object.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 
| x | Horizontal distance to translate.| 
| y | Vertical distance to translate.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

Translate


### OH_PixelMap_UnAccessPixels()

```
int32_t OH_PixelMap_UnAccessPixels (const NativePixelMap * native)
```

**Description**

Unlocks the memory of a **NativePixelMap** object. This function is used with [OH_PixelMap_AccessPixels](#oh_pixelmap_accesspixels) in pairs.

**Parameters**

| Name| Description| 
| -------- | -------- |
| native | Pointer to a **NativePixelMap** object.| 

**Returns**

For details, see [IRNdkErrCode](#irndkerrcode).

Returns **IMAGE_RESULT_SUCCESS** if the operation is successful.

Returns **IMAGE_RESULT_BAD_PARAMETER** if a parameter is incorrect.

Returns **IMAGE_RESULT_JNI_ENV_ABNORMAL** if the JNI environment is abnormal.

Returns **IMAGE_RESULT_INVALID_PARAMETER** if a parameter is invalid.

Returns **IMAGE_RESULT_GET_DATA_ABNORMAL** if an error occurs during image data retrieval.

Returns **IMAGE_RESULT_DECODE_FAILED** if decoding fails.

Returns **IMAGE_RESULT_CHECK_FORMAT_ERROR** if the format check fails.

Returns **IMAGE_RESULT_THIRDPART_SKIA_ERROR** if skia decoding fails.

Returns **IMAGE_RESULT_DATA_ABNORMAL** if the input image data is incorrect.

Returns **IMAGE_RESULT_ERR_SHAMEM_NOT_EXIST** if sharing the memory fails.

Returns **IMAGE_RESULT_ERR_SHAMEM_DATA_ABNORMAL** if the data in the shared memory is abnormal.

Returns **IMAGE_RESULT_MALLOC_ABNORMAL** if an error occurs during memory allocation.

Returns **IMAGE_RESULT_DATA_UNSUPPORT** if the attribute is invalid or the image data is not supported.

Returns **IMAGE_RESULT_CROP** if cropping fails.

Returns **IMAGE_RESULT_UNKNOWN_FORMAT** if the image format is unknown.

Returns **IMAGE_RESULT_PLUGIN_REGISTER_FAILED** if the plug-in fails to be registered.

Returns **IMAGE_RESULT_PLUGIN_CREATE_FAILED** if the plug-in fails to be created.

Returns **IMAGE_RESULT_ALPHA_TYPE_ERROR** if the alpha type is incorrect.

Returns **IMAGE_RESULT_ALLOCATER_TYPE_ERROR** if the memory allocation type is incorrect.

**Since**

10

**See**

UnAccessPixels


### OH_UnAccessPixels()

```
int32_t OHOS::Media::OH_UnAccessPixels (napi_env env, napi_value value )
```

**Description**

Unlocks the memory of a **PixelMap** object. This function is used with **OH_AccessPixels** in pairs.

**Parameters**

| Name| Description| 
| -------- | -------- |
| env | Pointer to the NAPI environment.| 
| value | **PixelMap** object at the application layer.| 

**Returns**

Returns **OHOS_IMAGE_RESULT_SUCCESS** if the operation is successful; returns an error code otherwise.

**Since**

8

**Deprecated from**

10

**See**

AccessPixels


## Variable Description


### alphaType

```
int32_t OhosImageSourceInfo::alphaType
```

**Description**

Defines the alpha type of the image source.

**Since**

10


### buffer [1/2]

```
uint8_t* OhosImageSource::buffer = nullptr
```

**Description**

Defines a pointer to the image source buffer. Only a formatted packet buffer or Base64 buffer is accepted.

**Since**

10


### buffer [2/2]

```
uint8_t* OhosImageSourceUpdateData::buffer = nullptr
```

**Description**

Defines a pointer to the buffer for storing the update data.

**Since**

10


### bufferSize [1/2]

```
size_t OhosImageSource::bufferSize = 0
```

**Description**

Defines the size of the image source buffer.

**Since**

10


### bufferSize [2/2]

```
size_t OhosImageSourceUpdateData::bufferSize = 0
```

**Description**

Defines the size of the buffer.

**Since**

10


### colorSpace

```
int32_t OhosImageSourceInfo::colorSpace
```

**Description**

Defines the color space of the image source.

**Since**

10


### delayTimeList

```
int32_t* OhosImageSourceDelayTimeList::delayTimeList
```

**Description**

Defines a pointer to the head of the image source delay time list.

**Since**

10


### density [1/2]

```
int32_t OhosImageSourceOps::density
```

**Description**

Defines the pixel density of the image source.

**Since**

10


### density [2/2]

```
int32_t OhosImageSourceInfo::density
```

**Description**

Defines the image density of the image source. It is set in [OH_ImageSource_Create](#oh_imagesource_create).

**Since**

10


### editable

```
int8_t OhosImageDecodingOps::editable
```

**Description**

Defines whether the output pixel map is editable.

**Since**

10


### fd

```
int32_t OhosImageSource::fd = -1
```

**Description**

Defines the descriptor of the image source.

**Since**

10


### fitDensity

```
int32_t OhosImageDecodingOps::fitDensity
```

**Description**

Defines the pixel density of the output pixel map.

**Since**

10


### format

```
char* OhosImageSourceSupportedFormat::format = nullptr
```

**Description**

Defines a pointer to the head of the format string.

**Since**

10


### height

```
int32_t OhosImageRegion::height
```

**Description**

Defines the height of the region, in pixels.

**Since**

10


### index

```
uint32_t OhosImageDecodingOps::index
```

**Description**

Defines the index of the output pixel map.

**Since**

10


### isCompleted

```
int8_t OhosImageSourceUpdateData::isCompleted = 0
```

**Description**

Defines whether the image source data update is completed.

**Since**

10


### offset

```
uint32_t OhosImageSourceUpdateData::offset = 0
```

**Description**

Defines the offset of the update data in the buffer.

**Since**

10


### OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE

```
const char* OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample"
```

**Description**

Defines a pointer to bits per sample, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL

```
const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel"
```

**Description**

Defines a pointer to the compressed bits per pixel, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL

```
const char* OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal"
```

**Description**

Defines a pointer to the created date and time, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_EXPOSURE_TIME

```
const char* OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime"
```

**Description**

Defines a pointer to the exposure time, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_F_NUMBER

```
const char* OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber"
```

**Description**

Defines a pointer to the f-number of the image, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE

```
const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude"
```

**Description**

Defines a pointer to the GPS latitude, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF

```
const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef"
```

**Description**

Defines a pointer to the GPS latitude reference information, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE

```
const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude"
```

**Description**

Defines a pointer to the GPS longitude, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF

```
const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef"
```

**Description**

Defines a pointer to the GPS longitude reference information, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_IMAGE_LENGTH

```
const char* OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength"
```

**Description**

Defines a pointer to the image length, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_IMAGE_WIDTH

```
const char* OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth"
```

**Description**

Defines a pointer to the image width, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS

```
const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings"
```

**Description**

Defines a pointer to the ISO speed ratings, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_ORIENTATION

```
const char* OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation"
```

**Description**

Defines a pointer to the orientation, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### OHOS_IMAGE_PROPERTY_SCENE_TYPE

```
const char* OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType"
```

**Description**

Defines a pointer to the scene type, one of the image properties. It is used in [OH_ImageSource_GetImageProperty](#oh_imagesource_getimageproperty) and [OH_ImageSource_ModifyImageProperty](#oh_imagesource_modifyimageproperty).

\@Syscap SystemCapability.Multimedia.Image

**Since**

10


### pixelFormat [1/3]

```
int32_t OhosImageSourceOps::pixelFormat
```

**Description**

Defines the pixel format of the image source. It is usually used to describe the YUV buffer.

**Since**

10


### pixelFormat [2/3]

```
int32_t OhosImageDecodingOps::pixelFormat
```

**Description**

Defines the pixel format of the output pixel map.

**Since**

10


### pixelFormat [3/3]

```
int32_t OhosImageSourceInfo::pixelFormat
```

**Description**

Defines the pixel format of the image source. It is set in [OH_ImageSource_Create](#oh_imagesource_create).

**Since**

10


### region

```
struct OhosImageRegion OhosImageDecodingOps::region
```

**Description**

Defines the region of the output pixel map.

**Since**

10


### rotate

```
uint32_t OhosImageDecodingOps::rotate
```

**Description**

Defines the decoding rotation.

**Since**

10


### sampleSize

```
uint32_t OhosImageDecodingOps::sampleSize
```

**Description**

Defines the size of the sample.

**Since**

10


### size [1/7]

```
struct OhosImageSize OhosImageSourceOps::size
```

**Description**

Defines the pixel width and height of the image source.

**Since**

10


### size [2/7]

```
struct OhosImageSize OhosImageDecodingOps::size
```

**Description**

Defines the pixel width and height of the output pixel map.

**Since**

10


### size [3/7]

```
struct OhosImageSize OhosImageSourceInfo::size
```

**Description**

Defines the pixel width and height of the image source.

**Since**

10


### size [4/7]

```
size_t OhosImageSourceDelayTimeList::size = 0
```

**Description**

Defines the size of the image source delay time list.

**Since**

10


### size [5/7]

```
size_t OhosImageSourceSupportedFormat::size = 0
```

**Description**

Defines the size of the format string.

**Since**

10


### size [6/7]

```
size_t OhosImageSourceSupportedFormatList::size = 0
```

**Description**

Defines the size of the format string list.

**Since**

10


### size [7/7]

```
size_t OhosImageSourceProperty::size = 0
```

**Description**

Defines the size of the property string.

**Since**

10


### supportedFormatList

```
struct OhosImageSourceSupportedFormat** OhosImageSourceSupportedFormatList::supportedFormatList = nullptr
```

**Description**

Defines a double pointer to the head of the format string list.

**Since**

10


### updateLength

```
uint32_t OhosImageSourceUpdateData::updateLength = 0
```

**Description**

Defines the length of the update data in the buffer.

**Since**

10


### uri

```
char* OhosImageSource::uri = nullptr
```

**Description**

Defines a pointer to the image source URI. Only a file URI or Base64 URI is accepted.

**Since**

10


### uriSize

```
size_t OhosImageSource::uriSize = 0
```

**Description**

Defines the length of the image source URI.

**Since**

10


### value

```
char* OhosImageSourceProperty::value = nullptr
```

**Description**

Defines a pointer to the head of the property string.

**Since**

10


### width

```
int32_t OhosImageRegion::width
```

**Description**

Defines the width of the region, in pixels.

**Since**

10


### x

```
int32_t OhosImageRegion::x
```

**Description**

Defines the X coordinate of the start point, in pixels.

**Since**

10


### y

```
int32_t OhosImageRegion::y
```

**Description**

Defines the Y coordinate of the start point, in pixels.

**Since**

10
