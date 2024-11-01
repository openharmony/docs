# Image_NativeModule


## Overview

The Image_NativeModule module provides image processing capabilities, including encoding and decoding an image and obtaining image data from the native layer.

The APIs of this module do not need to be imported through the JS interface. You can directly use the NDK to develop the features.

**Since**: 12


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [image_common.h](image__common_8h.md) | Declares the common enums and structs used by the image interface.| 
| [image_native.h](image__native_8h.md) | Declares the cropping rectangle, size, and component data of an image.| 
| [image_packer_native.h](image__packer__native_8h.md) | Declares the APIs for image encoding.| 
| [image_receiver_native.h](image__receiver__native_8h.md) | Declares the APIs used to obtain image data from the native layer.| 
| [image_source_native.h](image__source__native_8h.md) | Declares the APIs for image decoding.| 
| [pixelmap_native.h](pixelmap__native_8h.md) | Declares the APIs for accessing a pixel map.| 


### Structs

| Name| Description| 
| -------- | -------- |
| struct  [Image_Size](_image___size.md) | Describes the image size. | 
| struct  [Image_Region](_image___region.md) | Describes the region of an image to decode. | 
| struct  [Image_String](_image___string.md) | Describes an image string. | 
| struct  [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) | Describes the static metadata values available for the key **HDR_STATIC_METADATA**. | 
| struct  [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) | Describes the dynamic metadata values available for the key **DR_DYNAMIC_METADATA**. | 
| struct  [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) | Describes the gain map metadata values available for the key **HDR_GAINMAP_METADATA**. For details, see ISO 21496-1. | 
| struct  [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) | Describes the HDR metadata values used by the pixel map and available for the key **OH_Pixelmap_HdrMetadataKey**. | 

### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [Image_Size](_image___size.md) [Image_Size](#image_size) | Defines a struct for the image size. | 
| typedef struct [Image_Region](_image___region.md) [Image_Region](#image_region) | Defines a struct for the region of an image to decode. | 
| typedef struct [Image_String](_image___string.md) [Image_String](#image_string) | Defines a struct for an image string. | 
| typedef struct [Image_String](_image___string.md) [Image_MimeType](#image_mimetype) | Defines a struct for an image format type. | 
| typedef struct [OH_ImageNative](#oh_imagenative) [OH_ImageNative](#oh_imagenative) | Defines the alias for an image object at the native layer. | 
| typedef struct [OH_ImagePackerNative](#oh_imagepackernative) [OH_ImagePackerNative](#oh_imagepackernative) | Defines the **ImagePacker** struct, which is used to perform operations related to an image packer.| 
| typedef struct [OH_PackingOptions](#oh_packingoptions) [OH_PackingOptions](#oh_packingoptions) | Defines a struct for image encoding parameters.| 
| typedef struct [OH_ImageReceiverNative](#oh_imagereceivernative) [OH_ImageReceiverNative](#oh_imagereceivernative) | Defines the data type name of the image receiver at the native layer. | 
| typedef struct [OH_ImageReceiverOptions](#oh_imagereceiveroptions) [OH_ImageReceiverOptions](#oh_imagereceiveroptions) | Defines the data type name of the image receiver options. | 
| typedef void(\* [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | Defines the callbacks for the image receiver at the native layer. | 
| typedef struct [OH_ImageSourceNative](#oh_imagesourcenative) [OH_ImageSourceNative](#oh_imagesourcenative) | Defines the **ImageSource** struct, which is used to perform operations related to an image source.| 
| typedef struct [OH_ImageSource_Info](#oh_imagesource_info) [OH_ImageSource_Info](#oh_imagesource_info) | Defines a struct for the image source information, which is created by calling [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create).| 
| typedef struct [OH_DecodingOptions](#oh_decodingoptions) [OH_DecodingOptions](#oh_decodingoptions) | Defines a struct for decoding parameters, which are used in [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap).| 
| typedef struct [OH_PixelmapNative](#oh_pixelmapnative) [OH_PixelmapNative](#oh_pixelmapnative) | Defines the **Pixelmap** struct, which is used to perform operations related to a pixel map.| 
| typedef struct [OH_NativeBuffer](#oh_nativebuffer) [OH_NativeBuffer](#oh_nativebuffer) | Defines the **NativeBuffer** struct, which is used to perform operations related to the native buffer.| 
| typedef struct [OH_Pixelmap_HdrStaticMetadata](_o_h___pixelmap___hdr_static_metadata.md) [OH_Pixelmap_HdrStaticMetadata](#oh_pixelmap_hdrstaticmetadata) | Defines a struct for the static metadata values available for the key **HDR_STATIC_METADATA**. | 
| typedef struct [OH_Pixelmap_HdrDynamicMetadata](_o_h___pixelmap___hdr_dynamic_metadata.md) [OH_Pixelmap_HdrDynamicMetadata](#oh_pixelmap_hdrdynamicmetadata) | Defines a struct for the dynamic metadata values available for the key **DR_DYNAMIC_METADATA**. | 
| typedef struct [OH_Pixelmap_HdrGainmapMetadata](_o_h___pixelmap___hdr_gainmap_metadata.md) [OH_Pixelmap_HdrGainmapMetadata](#oh_pixelmap_hdrgainmapmetadata) | Defines a struct for the gain map metadata values available for the key **HDR_GAINMAP_METADATA**. For details, see ISO 21496-1. | 
| typedef struct [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) [OH_Pixelmap_HdrMetadataValue](#oh_pixelmap_hdrmetadatavalue) | Defines a struct for the HDR metadata values used by the pixel map a the key [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey). It is used in [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata). |
| typedef struct [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) | Defines a struct for the initialization parameters.| 
| typedef struct [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) | Defines a struct for the image information.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](#image_errorcode) {<br>IMAGE_SUCCESS = 0, <br>IMAGE_BAD_PARAMETER = 401, <br>IMAGE_UNSUPPORTED_MIME_TYPE = 7600101, <br>IMAGE_UNKNOWN_MIME_TYPE = 7600102,<br>IMAGE_TOO_LARGE = 7600103, <br>IMAGE_DMA_NOT_EXIST = 7600173, <br>IMAGE_DMA_OPERATION_FAILED = 7600174, <br>IMAGE_UNSUPPORTED_OPERATION = 7600201,<br>IMAGE_UNSUPPORTED_METADATA = 7600202, <br>IMAGE_UNSUPPORTED_CONVERSION = 7600203, <br>IMAGE_INVALID_REGION = 7600204, <br>IMAGE_ALLOC_FAILED = 7600301,<br>IMAGE_COPY_FAILED = 7600302, <br>IMAGE_UNKNOWN_ERROR = 7600901, <br>IMAGE_BAD_SOURCE = 7700101, <br>IMAGE_DECODE_FAILED = 7700301,<br>IMAGE_ENCODE_FAILED = 7800301<br>} | Enumerates the error codes. | 
| [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range) {<br>IMAGE_PACKER_DYNAMIC_RANGE_AUTO = 0,<br>IMAGE_PACKER_DYNAMIC_RANGE_SDR = 1 } | Enumerates the desired dynamic range for encoding.| 
| [IMAGE_DYNAMIC_RANGE](#image_dynamic_range) {<br>IMAGE_DYNAMIC_RANGE_AUTO = 0,<br>IMAGE_DYNAMIC_RANGE_SDR = 1,<br>IMAGE_DYNAMIC_RANGE_HDR = 2 } | Enumerates the desired dynamic range for decoding.| 
| [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type) {<br>PIXELMAP_ALPHA_TYPE_UNKNOWN = 0,<br>PIXELMAP_ALPHA_TYPE_OPAQUE = 1,<br>PIXELMAP_ALPHA_TYPE_PREMULTIPLIED = 2 } | Enumerates the alpha types of a pixel map.| 
| [PIXEL_FORMAT](#pixel_format) {<br>PIXEL_FORMAT_UNKNOWN = 0, PIXEL_FORMAT_RGB_565 = 2,<br>PIXEL_FORMAT_RGBA_8888 = 3, PIXEL_FORMAT_BGRA_8888 = 4,<br>PIXEL_FORMAT_RGB_888 = 5, PIXEL_FORMAT_ALPHA_8 = 6,<br>PIXEL_FORMAT_RGBA_F16 = 7, PIXEL_FORMAT_NV21 = 8,<br>PIXEL_FORMAT_NV12 = 9<br>} | Enumerates the image pixel formats.| 
| [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) { <br>OH_PixelmapNative_AntiAliasing_NONE = 0, <br>OH_PixelmapNative_AntiAliasing_LOW = 1, <br>OH_PixelmapNative_AntiAliasing_MEDIUM = 2, <br>OH_PixelmapNative_AntiAliasing_HIGH = 3 <br>} | Enumerates the antialiasing levels used for scaling pixel maps. | 
| [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) { <br>HDR_METADATA_TYPE = 0, <br>HDR_STATIC_METADATA = 1, <br>HDR_DYNAMIC_METADATA = 2, <br>HDR_GAINMAP_METADATA = 3 } | Enumerates the keys of the HDR related metadata information used by the pixel map. It is used in [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata). | 
| [OH_Pixelmap_HdrMetadataType](#oh_pixelmap_hdrmetadatatype) { <br>HDR_METADATA_TYPE_NONE = 0, <br>HDR_METADATA_TYPE_BASE = 1, <br>HDR_METADATA_TYPE_GAINMAP = 2, <br>HDR_METADATA_TYPE_ALTERNATE = 3 } | Enumerates the HDR metadata types, which are the values of **HDR_METADATA_TYPE**. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetImageSize](#oh_imagenative_getimagesize) ([OH_ImageNative](#oh_imagenative) \*image, [Image_Size](_image___size.md) \*size) | Obtains the [Image_Size](_image___size.md) information of an [OH_ImageNative](#oh_imagenative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetComponentTypes](#oh_imagenative_getcomponenttypes) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t \*\*types, size_t \*typeSize) | Obtains the component types of an [OH_ImageNative](#oh_imagenative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetByteBuffer](#oh_imagenative_getbytebuffer) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, OH_NativeBuffer \*\*nativeBuffer) | Obtains the buffer corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetBufferSize](#oh_imagenative_getbuffersize) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, size_t \*size) | Obtains the size of the buffer corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetRowStride](#oh_imagenative_getrowstride) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, int32_t \*rowStride) | Obtains the row stride corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_GetPixelStride](#oh_imagenative_getpixelstride) ([OH_ImageNative](#oh_imagenative) \*image, uint32_t componentType, int32_t \*pixelStride) | Obtains the pixel stride corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageNative_Release](#oh_imagenative_release) ([OH_ImageNative](#oh_imagenative) \*image) | Releases an [OH_ImageNative](#oh_imagenative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_Create](#oh_packingoptions_create) ([OH_PackingOptions](#oh_packingoptions) \*\*options) | Creates the pointer to an **OH_PackingOptions** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetMimeType](#oh_packingoptions_getmimetype) ([OH_PackingOptions](#oh_packingoptions) \*options, [Image_MimeType](#image_mimetype) \*format) | Obtains the MIME type.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetMimeType](#oh_packingoptions_setmimetype) ([OH_PackingOptions](#oh_packingoptions) \*options, [Image_MimeType](#image_mimetype) \*format) | Sets the MIME type.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetQuality](#oh_packingoptions_getquality) ([OH_PackingOptions](#oh_packingoptions) \*options, uint32_t \*quality) | Obtains the encoding quality.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetQuality](#oh_packingoptions_setquality) ([OH_PackingOptions](#oh_packingoptions) \*options, uint32_t quality) | Sets the encoding quality.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_GetDesiredDynamicRange](#oh_packingoptions_getdesireddynamicrange) ([OH_PackingOptions](#oh_packingoptions) \*options, int32_t \*desiredDynamicRange) | Obtains the desired dynamic range during encoding.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_SetDesiredDynamicRange](#oh_packingoptions_setdesireddynamicrange) ([OH_PackingOptions](#oh_packingoptions) \*options, int32_t desiredDynamicRange) | Sets the desired dynamic range during encoding.| 
| [Image_ErrorCode](#image_errorcode) [OH_PackingOptions_Release](#oh_packingoptions_release) ([OH_PackingOptions](#oh_packingoptions) \*options) | Releases the pointer to an **OH_PackingOptions** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_Create](#oh_imagepackernative_create) ([OH_ImagePackerNative](#oh_imagepackernative) \*\*imagePacker) | Creates the pointer to an **OH_ImagePackerNative** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromImageSource](#oh_imagepackernative_packtodatafromimagesource) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_ImageSourceNative](#oh_imagesourcenative) \*imageSource, uint8_t \*outData, size_t \*size) | Encodes an image source into data in a given format.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToDataFromPixelmap](#oh_imagepackernative_packtodatafrompixelmap) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*outData, size_t \*size) | Encodes a pixel map into data in a given format.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromImageSource](#oh_imagepackernative_packtofilefromimagesource) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_ImageSourceNative](#oh_imagesourcenative) \*imageSource, int32_t fd) | Encodes an image source into a file.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_PackToFileFromPixelmap](#oh_imagepackernative_packtofilefrompixelmap) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker, [OH_PackingOptions](#oh_packingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, int32_t fd) | Encodes a pixel map into a file.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImagePackerNative_Release](#oh_imagepackernative_release) ([OH_ImagePackerNative](#oh_imagepackernative) \*imagePacker) | Releases the pointer to an **OH_ImagePackerNative** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_Create](#oh_imagereceiveroptions_create) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*\*options) | Creates an **OH_ImageReceiverOptions** object at the application layer.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_GetSize](#oh_imagereceiveroptions_getsize) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) \*size) | Obtains the [Image_Size](_image___size.md) information of an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_SetSize](#oh_imagereceiveroptions_setsize) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [Image_Size](_image___size.md) size) | Sets the [Image_Size](_image___size.md) information for an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_GetCapacity](#oh_imagereceiveroptions_getcapacity) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, int32_t \*capacity) | Obtains the capacity of an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_SetCapacity](#oh_imagereceiveroptions_setcapacity) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, int32_t capacity) | Sets the capacity for an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverOptions_Release](#oh_imagereceiveroptions_release) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options) | Releases an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Create](#oh_imagereceivernative_create) ([OH_ImageReceiverOptions](#oh_imagereceiveroptions) \*options, [OH_ImageReceiverNative](#oh_imagereceivernative) \*\*receiver) | Creates an **OH_ImageReceiverNative** object at the application layer.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetReceivingSurfaceId](#oh_imagereceivernative_getreceivingsurfaceid) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, uint64_t \*surfaceId) | Obtains the receiver ID through an [OH_ImageReceiverNative](#oh_imagereceivernative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_ReadLatestImage](#oh_imagereceivernative_readlatestimage) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageNative](#oh_imagenative) \*\*image) | Obtains the latest image through an [OH_ImageReceiverNative](#oh_imagereceivernative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_ReadNextImage](#oh_imagereceivernative_readnextimage) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageNative](#oh_imagenative) \*\*image) | Obtains the next image through an [OH_ImageReceiverNative](#oh_imagereceivernative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_On](#oh_imagereceivernative_on) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) callback) | Registers a callback, which is an [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Off](#oh_imagereceivernative_off) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | Unregisters a callback, which is an [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetSize](#oh_imagereceivernative_getsize) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, [Image_Size](_image___size.md) \*size) | Obtains the size of an image receiver, which is an [OH_ImageReceiverNative](#oh_imagereceivernative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_GetCapacity](#oh_imagereceivernative_getcapacity) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver, int32_t \*capacity) | Obtains the capacity of an image receiver, which is an [OH_ImageReceiverNative](#oh_imagereceivernative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageReceiverNative_Release](#oh_imagereceivernative_release) ([OH_ImageReceiverNative](#oh_imagereceivernative) \*receiver) | Releases an [OH_ImageReceiverNative](#oh_imagereceivernative) object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create) ([OH_ImageSource_Info](#oh_imagesource_info) \*\*info) | Creates the pointer to an **OH_ImageSource_Info** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetWidth](#oh_imagesourceinfo_getwidth) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, uint32_t \*width) | Obtains the image width.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetHeight](#oh_imagesourceinfo_getheight) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, uint32_t \*height) | Obtains the image height.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_GetDynamicRange](#oh_imagesourceinfo_getdynamicrange) ([OH_ImageSource_Info](#oh_imagesource_info) \*info, bool \*isHdr) | Obtains the dynamic range of an image.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceInfo_Release](#oh_imagesourceinfo_release) ([OH_ImageSource_Info](#oh_imagesource_info) \*info) | Releases the pointer to an **OH_ImageSource_Info** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_Create](#oh_decodingoptions_create) ([OH_DecodingOptions](#oh_decodingoptions) \*\*options) | Creates the pointer to an **OH_DecodingOptions** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetPixelFormat](#oh_decodingoptions_getpixelformat) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t \*pixelFormat) | Obtains the pixel format.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetPixelFormat](#oh_decodingoptions_setpixelformat) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t pixelFormat) | Sets the pixel format.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetIndex](#oh_decodingoptions_getindex) ([OH_DecodingOptions](#oh_decodingoptions) \*options, uint32_t \*index) | Obtains the index of an image.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetIndex](#oh_decodingoptions_setindex) ([OH_DecodingOptions](#oh_decodingoptions) \*options, uint32_t index) | Sets the index for an image.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetRotate](#oh_decodingoptions_getrotate) ([OH_DecodingOptions](#oh_decodingoptions) \*options, float \*rotate) | Obtains the rotation degree.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetRotate](#oh_decodingoptions_setrotate) ([OH_DecodingOptions](#oh_decodingoptions) \*options, float rotate) | Sets the rotation angle.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredSize](#oh_decodingoptions_getdesiredsize) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | Obtains the desired output size.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredSize](#oh_decodingoptions_setdesiredsize) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Size](_image___size.md) \*desiredSize) | Sets the desired output size.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredRegion](#oh_decodingoptions_getdesiredregion) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | Obtains the region to decode.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredRegion](#oh_decodingoptions_setdesiredregion) ([OH_DecodingOptions](#oh_decodingoptions) \*options, [Image_Region](_image___region.md) \*desiredRegion) | Sets the region to decode.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_GetDesiredDynamicRange](#oh_decodingoptions_getdesireddynamicrange) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t \*desiredDynamicRange) | Obtains the desired dynamic range configured during decoding.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_SetDesiredDynamicRange](#oh_decodingoptions_setdesireddynamicrange) ([OH_DecodingOptions](#oh_decodingoptions) \*options, int32_t desiredDynamicRange) | Sets the desired dynamic range during decoding.| 
| [Image_ErrorCode](#image_errorcode) [OH_DecodingOptions_Release](#oh_decodingoptions_release) ([OH_DecodingOptions](#oh_decodingoptions) \*options) | Releases the pointer to an **OH_DecodingOptions** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromUri](#oh_imagesourcenative_createfromuri) (char \*uri, size_t uriSize, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object based on a URI.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromFd](#oh_imagesourcenative_createfromfd) (int32_t fd, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object based on a file descriptor.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromData](#oh_imagesourcenative_createfromdata) (uint8_t \*data, size_t dataSize, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object based on buffer data.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreateFromRawFile](#oh_imagesourcenative_createfromrawfile) (RawFileDescriptor \*rawFile, [OH_ImageSourceNative](#oh_imagesourcenative) \*\*res) | Creates the pointer to an **OH_ImageSourceNative** object by using the raw file descriptor of an image resource file.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [OH_DecodingOptions](#oh_decodingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | Creates the pointer to an **OH_PixelmapNative** object based on image decoding parameters.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_CreatePixelmapList](#oh_imagesourcenative_createpixelmaplist) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [OH_DecodingOptions](#oh_decodingoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*resVecPixMap[], size_t size) | Creates an array of **OH_PixelmapNative** objects based on image decoding parameters.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetDelayTimeList](#oh_imagesourcenative_getdelaytimelist) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, int32_t \*delayTimeList, size_t size) | Obtains the image delay time list.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetImageInfo](#oh_imagesourcenative_getimageinfo) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, int32_t index, [OH_ImageSource_Info](#oh_imagesource_info) \*info) | Obtains the information about an image with a given index.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetImageProperty](#oh_imagesourcenative_getimageproperty) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | Obtains the value of an image property.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_ModifyImageProperty](#oh_imagesourcenative_modifyimageproperty) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, [Image_String](_image___string.md) \*key, [Image_String](_image___string.md) \*value) | Modifies the value of an image property.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source, uint32_t \*frameCount) | Obtains the number of image frames.| 
| [Image_ErrorCode](#image_errorcode) [OH_ImageSourceNative_Release](#oh_imagesourcenative_release) ([OH_ImageSourceNative](#oh_imagesourcenative) \*source) | Releases the pointer to an **OH_ImageSourceNative** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_Create](#oh_pixelmapinitializationoptions_create) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*\*options) | Creates the pointer to an **OH_Pixelmap_InitializationOptions** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetWidth](#oh_pixelmapinitializationoptions_getwidth) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t \*width) | Obtains the image width.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetWidth](#oh_pixelmapinitializationoptions_setwidth) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t width) | Sets the image width.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetHeight](#oh_pixelmapinitializationoptions_getheight) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t \*height) | Obtains the image height.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetHeight](#oh_pixelmapinitializationoptions_setheight) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, uint32_t height) | Sets the image height.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetPixelFormat](#oh_pixelmapinitializationoptions_getpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*pixelFormat) | Obtains the pixel format.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetPixelFormat](#oh_pixelmapinitializationoptions_setpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t pixelFormat) | Sets the pixel format.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetSrcPixelFormat](#oh_pixelmapinitializationoptions_getsrcpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*srcpixelFormat) | Obtains the source pixel format.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetSrcPixelFormat](#oh_pixelmapinitializationoptions_setsrcpixelformat) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t srcpixelFormat) | Sets the source pixel format.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetRowStride](#oh_pixelmapinitializationoptions_getrowstride) (OH_Pixelmap_InitializationOptions \*options, int32_t \*rowStride) | Obtains the row stride. | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetRowStride](#oh_pixelmapinitializationoptions_setrowstride) (OH_Pixelmap_InitializationOptions \*options, int32_t rowStride) | Sets the row stride. | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_GetAlphaType](#oh_pixelmapinitializationoptions_getalphatype) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t \*alphaType) | Obtains the alpha type.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_SetAlphaType](#oh_pixelmapinitializationoptions_setalphatype) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, int32_t alphaType) | Sets the alpha type.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapInitializationOptions_Release](#oh_pixelmapinitializationoptions_release) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options) | Releases the pointer to an **OH_Pixelmap_InitializationOptions** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_Create](#oh_pixelmapimageinfo_create) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*\*info) | Creates the pointer to an **OH_Pixelmap_ImageInfo** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetWidth](#oh_pixelmapimageinfo_getwidth) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*width) | Obtains the image width.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetHeight](#oh_pixelmapimageinfo_getheight) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*height) | Obtains the image height.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetRowStride](#oh_pixelmapimageinfo_getrowstride) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, uint32_t \*rowStride) | Obtains the row stride.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetPixelFormat](#oh_pixelmapimageinfo_getpixelformat) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, int32_t \*pixelFormat) | Obtains the pixel format.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetAlphaType](#oh_pixelmapimageinfo_getalphatype) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, int32_t \*alphaType) | Obtains the alpha type.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_GetDynamicRange](#oh_pixelmapimageinfo_getdynamicrange) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info, bool \*isHdr) | Obtains the dynamic range of a pixel map.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapImageInfo_Release](#oh_pixelmapimageinfo_release) ([OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*info) | Releases the pointer to an **OH_Pixelmap_ImageInfo** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_CreatePixelmap](#oh_pixelmapnative_createpixelmap) (uint8_t \*data, size_t dataLength, [OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | Creates a **PixelMap** object based on properties. By default, the BGRA_8888 format is used for data processing.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ReadPixels](#oh_pixelmapnative_readpixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*destination, size_t \*bufferSize) | Reads the image pixel data and writes the data to an ArrayBuffer.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_WritePixels](#oh_pixelmapnative_writepixels) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, uint8_t \*source, size_t bufferSize) | Reads the image pixel data in the buffer and writes the data to a pixel map.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ToSdr](#oh_pixelmapnative_tosdr) (OH_PixelmapNative \*pixelmap) | Converts an HDR image into an SDR image. | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetImageInfo](#oh_pixelmapnative_getimageinfo) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_Pixelmap_ImageInfo](#oh_pixelmap_imageinfo) \*imageInfo) | Obtains the image information.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Opacity](#oh_pixelmapnative_opacity) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float rate) | Sets the opacity rate to enable the pixel map to achieve the corresponding opacity effect.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Scale](#oh_pixelmapnative_scale) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float scaleX, float scaleY) | Scales an image based on a given width and height.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ScaleWithAntiAliasing](#oh_pixelmapnative_scalewithantialiasing) (OH_PixelmapNative \*pixelmap, float scaleX, float scaleY, [OH_PixelmapNative_AntiAliasingLevel](#oh_pixelmapnative_antialiasinglevel) level) | Scales an image based on the specified antialiasing level, width, and height. | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Translate](#oh_pixelmapnative_translate) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float x, float y) | Translates an image based on given coordinates.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Rotate](#oh_pixelmapnative_rotate) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, float angle) | Rotates an image based on a given angle.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Flip](#oh_pixelmapnative_flip) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically) | Flips an image based on a given angle.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Crop](#oh_pixelmapnative_crop) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [Image_Region](_image___region.md) \*region) | Crops an image based on a given size.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_Release](#oh_pixelmapnative_release) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap) | Releases the pointer to an **OH_PixelmapNative** object.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_ConvertAlphaFormat](#oh_pixelmapnative_convertalphaformat) ([OH_PixelmapNative](#oh_pixelmapnative) \*pixelmap, [OH_PixelmapNative](#oh_pixelmapnative) \*dstpixelmap, const bool isPremul) | Converts pixel data of a pixel map from premultiplied alpha to non-premultiplied alpha, or vice versa.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_CreateEmptyPixelmap](#oh_pixelmapnative_createemptypixelmap) ([OH_Pixelmap_InitializationOptions](#oh_pixelmap_initializationoptions) \*options, [OH_PixelmapNative](#oh_pixelmapnative) \*\*pixelmap) | Creates an empty pixel map using **OH_Pixelmap_InitializationOptions**. The memory data is 0.| 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetNativeBuffer](#oh_pixelmapnative_getnativebuffer) (OH_PixelmapNative \*pixelmap, OH_NativeBuffer \*\*nativeBuffer) | Obtains the **NativeBuffer** object from a pixel map in the DMA memory. | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata) (OH_PixelmapNative \*pixelmap, [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key, [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) \*\*value) | Obtains the metadata. | 
| [Image_ErrorCode](#image_errorcode) [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) (OH_PixelmapNative \*pixelmap, [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey) key, [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md) \*value) | Sets the metadata. | 


### Variables

| Name| Description| 
| -------- | -------- |
| static const char \*[MIME_TYPE_BMP](#mime_type_bmp) = "image/bmp" | BMP image format.| 
| static const char \*[MIME_TYPE_JPEG](#mime_type_jpeg) = "image/jpeg" | JPEG image format.| 
| static const char \*[MIME_TYPE_HEIC](#mime_type_heic) = "image/heic" | HEIF image format.| 
| static const char \*[MIME_TYPE_PNG](#mime_type_png) = "image/png" | PNG image format.| 
| static const char \*[MIME_TYPE_WEBP](#mime_type_webp) = "image/webp" | WebP image format.| 
| static const char \*[MIME_TYPE_GIF](#mime_type_gif) = "image/gif" | GIF image format.| 
| static const char \*[MIME_TYPE_ICON](#mime_type_icon) = "image/x-icon" | ICO image format.| 
| static const char \*[OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE](#ohos_image_property_bits_per_sample) = "BitsPerSample" | Number of bits per sample.| 
| static const char \*[OHOS_IMAGE_PROPERTY_ORIENTATION](#ohos_image_property_orientation) = "Orientation" | Image orientation.| 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_LENGTH](#ohos_image_property_image_length) = "ImageLength" | Image length.| 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_WIDTH](#ohos_image_property_image_width) = "ImageWidth" | Image width.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE](#ohos_image_property_gps_latitude) = "GPSLatitude" | Image latitude.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE](#ohos_image_property_gps_longitude) = "GPSLongitude" | Image longitude.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF](#ohos_image_property_gps_latitude_ref) = "GPSLatitudeRef" | Whether the latitude is north or south latitude.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF](#ohos_image_property_gps_longitude_ref) = "GPSLongitudeRef" | Whether the longitude is east or west longitude.| 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL](#ohos_image_property_date_time_original) = "DateTimeOriginal" | Shooting time, for example, 2022:09:06 15:48:00.| 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_TIME](#ohos_image_property_exposure_time) = "ExposureTime" | Exposure time, for example, 1/33 seconds.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_TYPE](#ohos_image_property_scene_type) = "SceneType" | Type of the scene, for example, portrait, scenery, motion, and night.| 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS](#ohos_image_property_iso_speed_ratings) = "ISOSpeedRatings" | ISO sensitivity or ISO speed, for example, 400.| 
| static const char \*[OHOS_IMAGE_PROPERTY_F_NUMBER](#ohos_image_property_f_number) = "FNumber" | F number, for example, f/1.8.| 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL](#ohos_image_property_compressed_bits_per_pixel) = "CompressedBitsPerPixel" | Number of bits per pixel. It is specific to compressed data.| 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPRESSION](#ohos_image_property_compression) = "Compression" | Compression scheme used on the image data.| 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION](#ohos_image_property_photometric_interpretation) = "PhotometricInterpretation" | Color space of the image data, for example, RGB or YCbCr.| 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_OFFSETS](#ohos_image_property_strip_offsets) = "StripOffsets" | Byte offset of each strip.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL](#ohos_image_property_samples_per_pixel) = "SamplesPerPixel" | Number of components per pixel. The value is **3** for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data.| 
| static const char \*[OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP](#ohos_image_property_rows_per_strip) = "RowsPerStrip" | Number of rows per strip.| 
| static const char \*[OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS](#ohos_image_property_strip_byte_counts) = "StripByteCounts" | Number of bytes in each strip after compression.| 
| static const char \*[OHOS_IMAGE_PROPERTY_X_RESOLUTION](#ohos_image_property_x_resolution) = "XResolution" | Number of pixels per ResolutionUnit in the image width (X) direction.| 
| static const char \*[OHOS_IMAGE_PROPERTY_Y_RESOLUTION](#ohos_image_property_y_resolution) = "YResolution" | Number of pixels per ResolutionUnit in the image height (Y) direction.| 
| static const char \*[OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION](#ohos_image_property_planar_configuration) = "PlanarConfiguration" | Storage format of components of each pixel, which can be chunky or planar.| 
| static const char \*[OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT](#ohos_image_property_resolution_unit) = "ResolutionUnit" | Unit of measurement for XResolution and YResolution.| 
| static const char \*[OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION](#ohos_image_property_transfer_function) = "TransferFunction" | Transfer function for the image, which is usually used for color correction.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SOFTWARE](#ohos_image_property_software) = "Software" | Name and version number of the software used to create the image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_ARTIST](#ohos_image_property_artist) = "Artist" | Person who created the image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_WHITE_POINT](#ohos_image_property_white_point) = "WhitePoint" | Chromaticity of the white point of the image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES](#ohos_image_property_primary_chromaticities) = "PrimaryChromaticities" | Chromaticities of the primaries of the image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS](#ohos_image_property_ycbcr_coefficients) = "YCbCrCoefficients" | Transformation from RGB to YCbCr image data.| 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING](#ohos_image_property_ycbcr_sub_sampling) = "YCbCrSubSampling" | Subsampling factors used for the chrominance components of a YCbCr image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING](#ohos_image_property_ycbcr_positioning) = "YCbCrPositioning" | Positioning of subsampled chrominance components relative to luminance samples.| 
| static const char \*[OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE](#ohos_image_property_reference_black_white) = "ReferenceBlackWhite" | A pair of headroom and footroom image data values (codes) for each pixel component.| 
| static const char \*[OHOS_IMAGE_PROPERTY_COPYRIGHT](#ohos_image_property_copyright) = "Copyright" | Copyright notice of the image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT](#ohos_image_property_jpeg_interchange_format) = "JPEGInterchangeFormat" | Offset of the SOI marker of a JPEG interchange format bitstream.| 
| static const char \*[OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH](#ohos_image_property_jpeg_interchange_format_length) = "JPEGInterchangeFormatLength" | Number of bytes of the JPEG stream.| 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM](#ohos_image_property_exposure_program) = "ExposureProgram" | Class of the program used by the camera to set exposure when the image was captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY](#ohos_image_property_spectral_sensitivity) = "SpectralSensitivity" | Spectral sensitivity of each channel of the camera.| 
| static const char \*[OHOS_IMAGE_PROPERTY_OECF](#ohos_image_property_oecf) = "OECF" | Opto-Electric Conversion Function (OECF) specified in ISO 14524.| 
| static const char \*[OHOS_IMAGE_PROPERTY_EXIF_VERSION](#ohos_image_property_exif_version) = "ExifVersion" | Version of the supported EXIF standard.| 
| static const char \*[OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED](#ohos_image_property_date_time_digitized) = "DateTimeDigitized" | Date and time when the image was stored as digital data, in the format of YYYY:MM:DD HH:MM:SS.| 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION](#ohos_image_property_components_configuration) = "ComponentsConfiguration" | Specific information about compressed data.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE](#ohos_image_property_shutter_speed_value) = "ShutterSpeedValue" | Shutter speed, expressed in Additive System of Photographic Exposure (APEX) values.| 
| static const char \*[OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE](#ohos_image_property_brightness_value) = "BrightnessValue" | Value of brightness, expressed in APEX values.| 
| static const char \*[OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE](#ohos_image_property_max_aperture_value) = "MaxApertureValue" | Smallest F number of the lens.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE](#ohos_image_property_subject_distance) = "SubjectDistance" | Distance to the subject, in meters.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_AREA](#ohos_image_property_subject_area) = "SubjectArea" | Location and area of the main subject in the entire scene.| 
| static const char \*[OHOS_IMAGE_PROPERTY_MAKER_NOTE](#ohos_image_property_maker_note) = "MakerNote" | Marker used by EXIF/DCF manufacturers to record any required information.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME](#ohos_image_property_subsec_time) = "SubsecTime" | Tag used to record fractions of seconds for the **DateTime** tag.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL](#ohos_image_property_subsec_time_original) = "SubsecTimeOriginal" | Tag used to record fractions of seconds for the **DateTimeOriginal** tag.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED](#ohos_image_property_subsec_time_digitized) = "SubsecTimeDigitized" | Tag used to record fractions of seconds for the **DateTimeDigitized** tag.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION](#ohos_image_property_flashpix_version) = "FlashpixVersion" | FlashPix format version supported by an FPXR file. It is used to enhance device compatibility.| 
| static const char \*[OHOS_IMAGE_PROPERTY_COLOR_SPACE](#ohos_image_property_color_space) = "ColorSpace" | Color space information, which is usually recorded as a color space specifier.| 
| static const char \*[OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE](#ohos_image_property_related_sound_file) = "RelatedSoundFile" | Name of an audio file related to the image data.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FLASH_ENERGY](#ohos_image_property_flash_energy) = "FlashEnergy" | Strobe energy at the time the image was captured, in Beam Candle Power Seconds (BCPS).| 
| static const char \*[OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE](#ohos_image_property_spatial_frequency_response) = "SpatialFrequencyResponse" | Spatial frequency table of the camera or input device.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION](#ohos_image_property_focal_plane_x_resolution) = "FocalPlaneXResolution" | Number of pixels in the image width (X) direction per FocalPlaneResolutionUnit.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION](#ohos_image_property_focal_plane_y_resolution) = "FocalPlaneYResolution" | Number of pixels in the image height (Y) direction per FocalPlaneResolutionUnit.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT](#ohos_image_property_focal_plane_resolution_unit) = "FocalPlaneResolutionUnit" | Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION](#ohos_image_property_subject_location) = "SubjectLocation" | Location of the main subject relative to the left edge.| 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX](#ohos_image_property_exposure_index) = "ExposureIndex" | Exposure index selected at the time the image is captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SENSING_METHOD](#ohos_image_property_sensing_method) = "SensingMethod" | Type of the image sensor on the camera.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FILE_SOURCE](#ohos_image_property_file_source) = "FileSource" | Image source.| 
| static const char \*[OHOS_IMAGE_PROPERTY_CFA_PATTERN](#ohos_image_property_cfa_pattern) = "CFAPattern" | Color Filter Array (CFA) geometric pattern of the image sensor.| 
| static const char \*[OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED](#ohos_image_property_custom_rendered) = "CustomRendered" | Special processing on image data.| 
| static const char \*[OHOS_IMAGE_PROPERTY_EXPOSURE_MODE](#ohos_image_property_exposure_mode) = "ExposureMode" | Exposure mode set when the image was captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO](#ohos_image_property_digital_zoom_ratio) = "DigitalZoomRatio" | Digital zoom ratio when the image was captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE](#ohos_image_property_scene_capture_type) = "SceneCaptureType" | Type of the scene that was captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GAIN_CONTROL](#ohos_image_property_gain_control) = "GainControl" | Degree of overall image gain adjustment.| 
| static const char \*[OHOS_IMAGE_PROPERTY_CONTRAST](#ohos_image_property_contrast) = "Contrast" | Direction of contrast processing used by the camera.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SATURATION](#ohos_image_property_saturation) = "Saturation" | Direction of saturation processing used by the camera.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SHARPNESS](#ohos_image_property_sharpness) = "Sharpness" | Direction of sharpness processing used by the camera.| 
| static const char \*[OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION](#ohos_image_property_device_setting_description) = "DeviceSettingDescription" | Information about the photographing conditions of a specific camera model.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE](#ohos_image_property_subject_distance_range) = "SubjectDistanceRange" | Distance to the subject.| 
| static const char \*[OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID](#ohos_image_property_image_unique_id) = "ImageUniqueID" | Unique identifier assigned to each image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_VERSION_ID](#ohos_image_property_gps_version_id) = "GPSVersionID" | Version of GPSInfoIFD.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF](#ohos_image_property_gps_altitude_ref) = "GPSAltitudeRef" | Whether the latitude is north or south latitude.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_ALTITUDE](#ohos_image_property_gps_altitude) = "GPSAltitude" | Altitude based on the reference in GPSAltitudeRef.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SATELLITES](#ohos_image_property_gps_satellites) = "GPSSatellites" | GPS satellites used for measurement.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_STATUS](#ohos_image_property_gps_status) = "GPSStatus" | Status of the GPS receiver when the image was recorded.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE](#ohos_image_property_gps_measure_mode) = "GPSMeasureMode" | GPS measurement pmode.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DOP](#ohos_image_property_gps_dop) = "GPSDOP" | GPS DOP (data degree of precision)| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED_REF](#ohos_image_property_gps_speed_ref) = "GPSSpeedRef" | Unit used to express the movement speed of the GPS receiver.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_SPEED](#ohos_image_property_gps_speed) = "GPSSpeed" | Movement speed of the GPS receiver.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK_REF](#ohos_image_property_gps_track_ref) = "GPSTrackRef" | Reference of the movement direction of the GPS receiver.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_TRACK](#ohos_image_property_gps_track) = "GPSTrack" | Movement direction of the GPS receiver.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF](#ohos_image_property_gps_img_direction_ref) = "GPSImgDirectionRef" | Reference of the direction of the image when it was captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION](#ohos_image_property_gps_img_direction) = "GPSImgDirection" | Direction of the image when it was captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM](#ohos_image_property_gps_map_datum) = "GPSMapDatum" | Geodetic survey data used by the GPS receiver.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF](#ohos_image_property_gps_dest_latitude_ref) = "GPSDestLatitudeRef" | Whether the latitude of the destination point is north or south latitude.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE](#ohos_image_property_gps_dest_latitude) = "GPSDestLatitude" | Latitude of the destination point.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF](#ohos_image_property_gps_dest_longitude_ref) = "GPSDestLongitudeRef" | Whether the longitude of the destination point is east or west longitude.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD](#ohos_image_property_gps_processing_method) = "GPSProcessingMethod" | String that records the name of the method used for positioning.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION](#ohos_image_property_gps_area_information) = "GPSAreaInformation" | String that records the name of the GPS area.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL](#ohos_image_property_gps_differential) = "GPSDifferential" | Whether differential correction is applied to the GPS receiver. It is critical to accurate location accuracy.| 
| static const char \*[OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER](#ohos_image_property_body_serial_number) = "BodySerialNumber" | Serial number of the camera body.| 
| static const char \*[OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME](#ohos_image_property_camera_owner_name) = "CameraOwnerName" | Name of the camera owner.| 
| static const char \*[OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE](#ohos_image_property_composite_image) = "CompositeImage" | Whether the image is a composite image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_DNG_VERSION](#ohos_image_property_dng_version) = "DNGVersion" | DNG version. It encodes the DNG 4-tier version number.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE](#ohos_image_property_gps_dest_longitude) = "GPSDestLongitude" | Longitude of the destination point.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF](#ohos_image_property_gps_dest_bearing_ref) = "GPSDestBearingRef" | Reference of the bearing to the destination point.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING](#ohos_image_property_gps_dest_bearing) = "GPSDestBearing" | Bearing to the destination point.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF](#ohos_image_property_gps_dest_distance_ref) = "GPSDestDistanceRef" | Unit used to express the distance to the destination point.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE](#ohos_image_property_gps_dest_distance) = "GPSDestDistance" | Distance to the destination point.| 
| static const char \*[OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE](#ohos_image_property_default_crop_size) = "DefaultCropSize" | Size of the final image area, in raw image coordinates, taking into account extra pixels around the edges of the final image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GAMMA](#ohos_image_property_gamma) = "Gamma" | Gamma value.| 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY](#ohos_image_property_iso_speed_latitudeyyy) = "ISOSpeedLatitudeyyy" | ISO speed latitude yyy value of the camera or input device, which is defined in ISO 12232.| 
| static const char \*[OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ](#ohos_image_property_iso_speed_latitudezzz) = "ISOSpeedLatitudezzz" | ISO speed latitude zzz value of the camera or input device, which is defined in ISO 12232.| 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MAKE](#ohos_image_property_lens_make) = "LensMake" | Manufacturer of the lens.| 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_MODEL](#ohos_image_property_lens_model) = "LensModel" | Model of the lens.| 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER](#ohos_image_property_lens_serial_number) = "LensSerialNumber" | Serial number of the lens.| 
| static const char \*[OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION](#ohos_image_property_lens_specification) = "LensSpecification" | Specifications of the lens.| 
| static const char \*[OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE](#ohos_image_property_new_subfile_type) = "NewSubfileType" | Data type of a subfile, such as a full-resolution image, a thumbnail, or a part of a multi-frame image. The value is a bit mask. The value 0 indicates a full-resolution image, **1** indicates a thumbnail, and **2** indicates a part of a multi-frame image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME](#ohos_image_property_offset_time) = "OffsetTime" | Time with an offset from UTC when the image was captured, in the format of ±HH:MM.| 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED](#ohos_image_property_offset_time_digitized) = "OffsetTimeDigitized" | Time with an offset from UTC when the image was digitized. It helps to accurately adjust the timestamp.| 
| static const char \*[OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL](#ohos_image_property_offset_time_original) = "OffsetTimeOriginal" | Time with an offset from UTC when the original image was created. It is critical for time-sensitive applications.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE](#ohos_image_property_source_exposure_times_of_composite_image) = "SourceExposureTimesOfCompositeImage" | Exposure time of source images of the composite image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE](#ohos_image_property_source_image_number_of_composite_image) = "SourceImageNumberOfCompositeImage" | Number of source images of the composite image.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SUBFILE_TYPE](#ohos_image_property_subfile_type) = "SubfileType" | Type of data contained in this subfile. This tag has been deprecated. Use **NewSubfileType** instead.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR](#ohos_image_property_gps_h_positioning_error) = "GPSHPositioningError" | Horizontal positioning error, in meters.| 
| static const char \*[OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY](#ohos_image_property_photographic_sensitivity) = "PhotographicSensitivity" | Sensitivity of the camera or input device when the image was captured.| 
| static const char \*[OHOS_IMAGE_PROPERTY_BURST_NUMBER](#ohos_image_property_burst_number) = "HwMnoteBurstNumber" | Number of burst shooting times.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_CONF](#ohos_image_property_face_conf) = "HwMnoteFaceConf" | Face confidence.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER](#ohos_image_property_face_leye_center) = "HwMnoteFaceLeyeCenter" | Left eye centered. It is used in **OH_ImageSource_GetImageProperty** and **OH_ImageSource_ModifyImageProperty**.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER](#ohos_image_property_face_mouth_center) = "HwMnoteFaceMouthCenter" | Mouth centered.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_POINTER](#ohos_image_property_face_pointer) = "HwMnoteFacePointer" | Face pointer.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_RECT](#ohos_image_property_face_rect) = "HwMnoteFaceRect" | Face rectangle.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER](#ohos_image_property_face_reye_center) = "HwMnoteFaceReyeCenter" | Right eye centered.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE](#ohos_image_property_face_smile_score) = "HwMnoteFaceSmileScore" | Smile score of for faces.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FACE_VERSION](#ohos_image_property_face_version) = "HwMnoteFaceVersion" | Facial recognition algorithm version.| 
| static const char \*[OHOS_IMAGE_PROPERTY_FRONT_CAMERA](#ohos_image_property_front_camera) = "HwMnoteFrontCamera" | Whether the front camera is used to take a selfie.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_POINTER](#ohos_image_property_scene_pointer) = "HwMnoteScenePointer" | Pointer to the scene.| 
| static const char \*[OHOS_IMAGE_PROPERTY_SCENE_VERSION](#ohos_image_property_scene_version) = "HwMnoteSceneVersion" | Scene algorithm version.| 
| static const char \*[OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT](#ohos_image_property_gif_loop_count) = "GIFLoopCount" | Number of GIF loops.| 


## Type Description


### Image_MimeType

```
typedef struct Image_String Image_MimeType
```

**Description**

Defines a struct for an image format type.

**Since**: 12


### Image_Region

```
typedef struct Image_Region Image_Region
```

**Description**

Defines a struct for the region of an image to decode.

**Since**: 12


### Image_Size

```
typedef struct Image_Size Image_Size
```

**Description**

Defines a struct for the image size.

**Since**: 12


### Image_String

```
typedef struct Image_String Image_String
```

**Description**

Defines a struct for an image string.

**Since**: 12


### OH_DecodingOptions

```
typedef struct OH_DecodingOptions OH_DecodingOptions
```

**Description**

Defines a struct for decoding parameters, which are used in [OH_ImageSourceNative_CreatePixelmap](#oh_imagesourcenative_createpixelmap).

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_DecodingOptions Struct](../../media/image/image-structure-c.md#oh_decodingoptions-struct).

**Since**: 12


### OH_ImageNative

```
typedef struct OH_ImageNative OH_ImageNative
```

**Description**

Defines the alias for an image object at the native layer.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_ImageNative Struct](../../media/image/image-structure-c.md#oh_imagenative-struct).

**Since**: 12


### OH_ImagePackerNative

```
typedef struct OH_ImagePackerNative OH_ImagePackerNative
```

**Description**

Defines the **ImagePacker** struct, which is used to perform operations related to an image packer.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_ImagePackerNative Struct](../../media/image/image-structure-c.md#oh_imagepackernative-struct).

**Since**: 12


### OH_ImageReceiver_OnCallback

```
typedef void(*OH_ImageReceiver_OnCallback) (OH_ImageReceiverNative *receiver)
```

**Description**

Defines the callbacks for the image receiver at the native layer.

**Since**: 12


### OH_ImageReceiverNative

```
typedef struct OH_ImageReceiverNative OH_ImageReceiverNative
```

**Description**

Defines the data type name of the image receiver at the native layer.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_ImageReceiverNative Struct](../../media/image/image-structure-c.md#oh_imagereceivernative-struct).

**Since**: 12


### OH_ImageReceiverOptions

```
typedef struct OH_ImageReceiverOptionsOH_ImageReceiverOptions
```

**Description**

Defines the data type name of the image receiver options.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_ImageReceiverOptions Struct](../../media/image/image-structure-c.md#oh_imagereceiveroptions-struct).

**Since**: 12


### OH_Pixelmap_HdrDynamicMetadata

```
typedef struct OH_Pixelmap_HdrDynamicMetadata OH_Pixelmap_HdrDynamicMetadata
```

**Description**

Defines a struct for the dynamic metadata values available for the key **DR_DYNAMIC_METADATA**.

**Since**: 12


### OH_Pixelmap_HdrGainmapMetadata

```
typedef struct OH_Pixelmap_HdrGainmapMetadata OH_Pixelmap_HdrGainmapMetadata
```

**Description**

Defines a struct for the gain map metadata values available for the key **HDR_GAINMAP_METADATA**. For details, see ISO 21496-1.

**Since**: 12


### OH_Pixelmap_HdrMetadataValue

```
typedef struct OH_Pixelmap_HdrMetadataValue OH_Pixelmap_HdrMetadataValue
```

**Description**

Defines a struct for the HDR metadata values used by the pixel map. It corresponds to the key [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey).

It is used in [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata).

**Since**: 12


### OH_Pixelmap_HdrStaticMetadata

```
typedef struct OH_Pixelmap_HdrStaticMetadata OH_Pixelmap_HdrStaticMetadata
```

**Description**

Defines a struct for the static metadata values available for the key **HDR_STATIC_METADATA**.

**Since**: 12


### OH_ImageSource_Info

```
typedef struct OH_ImageSource_Info OH_ImageSource_Info
```

**Description**

Defines a struct for the image source information, which is created by calling [OH_ImageSourceInfo_Create](#oh_imagesourceinfo_create).

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_ImageSource_Info Struct](../../media/image/image-structure-c.md#oh_imagesource_info-struct).

**Since**: 12


### OH_ImageSourceNative

```
typedef struct OH_ImageSourceNative OH_ImageSourceNative
```

**Description**

Defines the **ImageSource** struct, which is used to perform operations related to an image source.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_ImageSourceNative Struct](../../media/image/image-structure-c.md#oh_imagesourcenative-struct).

**Since**: 12


### OH_PackingOptions

```
typedef struct OH_PackingOptions OH_PackingOptions
```

**Description**

Defines a struct for image encoding parameters.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_PackingOptions Struct](../../media/image/image-structure-c.md#oh_packingoptions-struct).

**Since**: 12


### OH_Pixelmap_ImageInfo

```
typedef struct OH_Pixelmap_ImageInfo OH_Pixelmap_ImageInfo
```

**Description**

Defines a struct for the image information.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_Pixelmap_ImageInfo Struct](../../media/image/image-structure-c.md#oh_pixelmap_imageinfo-struct).

**Since**: 12


### OH_Pixelmap_InitializationOptions

```
typedef struct OH_Pixelmap_InitializationOptions OH_Pixelmap_InitializationOptions
```

**Description**

Defines a struct for the initialization parameters.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_Pixelmap_InitializationOptions Struct](../../media/image/image-structure-c.md#oh_pixelmap_initializationoptions-struct).

**Since**: 12


### OH_PixelmapNative

```
typedef struct OH_PixelmapNative OH_PixelmapNative
```

**Description**

Defines the **Pixelmap** struct, which is used to perform operations related to a pixel map.

The fields in this struct cannot be directly operated. Instead, they must be manipulated via function calls. For details about the struct content and operation mode, see [OH_PixelmapNative Struct](../../media/image/image-structure-c.md#oh_pixelmapnative-struct).

**Since**: 12


### OH_NativeBuffer

```
typedef struct OH_NativeBuffer OH_NativeBuffer
```

**Description**

Defines the **NativeBuffer** struct, which is used to perform operations related to the native buffer.


**Since**: 12


## Enum Description


### IMAGE_DYNAMIC_RANGE

```
enum IMAGE_DYNAMIC_RANGE
```

**Description**

Enumerates the desired dynamic range for decoding.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IMAGE_DYNAMIC_RANGE_AUTO | Adaptive processing.| 
| IMAGE_DYNAMIC_RANGE_SDR | Standard dynamic range (SDR).| 
| IMAGE_DYNAMIC_RANGE_HDR | High dynamic range (HDR).| 


### Image_ErrorCode

```
enum Image_ErrorCode
```

**Description**

Enumerates the error codes.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IMAGE_SUCCESS  | Operation successful.| 
| IMAGE_BAD_PARAMETER  | Invalid parameter.| 
| IMAGE_UNSUPPORTED_MIME_TYPE  | Unsupported MIME type.| 
| IMAGE_UNKNOWN_MIME_TYPE  | Unknown MIME type.| 
| IMAGE_TOO_LARGE  | The data or image is too large.| 
| IMAGE_DMA_NOT_EXIST  | The memory is not the DMA memory.| 
| IMAGE_DMA_OPERATION_FAILED  | The operation on the DMA memory fails.| 
| IMAGE_UNSUPPORTED_OPERATION  | Unsupported operation.| 
| IMAGE_UNSUPPORTED_METADATA  | Unsupported metadata.| 
| IMAGE_UNSUPPORTED_CONVERSION  | Unsupported conversion.| 
| IMAGE_INVALID_REGION  | Invalid region.| 
| IMAGE_ALLOC_FAILED  | Failed to allocate the memory.| 
| IMAGE_COPY_FAILED  | Failed to copy the memory.| 
| IMAGE_UNKNOWN_ERROR  | Unknown error.| 
| IMAGE_BAD_SOURCE  | Abnormal data source.| 
| IMAGE_DECODE_FAILED  | Decoding failed.| 
| IMAGE_ENCODE_FAILED  | Encoding failed.| 


### IMAGE_PACKER_DYNAMIC_RANGE

```
enum IMAGE_PACKER_DYNAMIC_RANGE
```

**Description**

Enumerates the desired dynamic range for encoding.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| IMAGE_PACKER_DYNAMIC_RANGE_AUTO | Adaptive processing.| 
| IMAGE_PACKER_DYNAMIC_RANGE_SDR | SDR.| 


### PIXEL_FORMAT

```
enum PIXEL_FORMAT
```

**Description**

Enumerates the image pixel formats.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| PIXEL_FORMAT_UNKNOWN | Unknown format.| 
| PIXEL_FORMAT_RGB_565 | RGB_565 format.| 
| PIXEL_FORMAT_RGBA_8888 | RGBA_8888 format.| 
| PIXEL_FORMAT_BGRA_8888 | BGRA_8888 format.| 
| PIXEL_FORMAT_RGB_888 | RGB_888 format.| 
| PIXEL_FORMAT_ALPHA_8 | ALPHA_8 format.| 
| PIXEL_FORMAT_RGBA_F16 | RGBA_F16 format.| 
| PIXEL_FORMAT_NV21 | NV21 format.| 
| PIXEL_FORMAT_NV12 | NV12 format.| 


### OH_Pixelmap_HdrMetadataKey

```
enum OH_Pixelmap_HdrMetadataKey
```

**Description**

Enumerates the keys of the HDR related metadata information used by the pixel map. It is used in [OH_PixelmapNative_SetMetadata](#oh_pixelmapnative_setmetadata) and [OH_PixelmapNative_GetMetadata](#oh_pixelmapnative_getmetadata).

**Since**: 12

| Value| Description| 
| -------- | -------- |
| HDR_METADATA_TYPE  | Metadata type used by the pixel map.  | 
| HDR_STATIC_METADATA  | Static metadata.  | 
| HDR_DYNAMIC_METADATA  | Dynamic metadata.  | 
| HDR_GAINMAP_METADATA  | Metadata used by gain maps.  | 


### OH_Pixelmap_HdrMetadataType

```
enum OH_Pixelmap_HdrMetadataType
```

**Description**

Enumerates the HDR metadata types, which are the values of **HDR_METADATA_TYPE**.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| HDR_METADATA_TYPE_NONE  | No metadata.  | 
| HDR_METADATA_TYPE_BASE  | Metadata used for base graphics.  | 
| HDR_METADATA_TYPE_GAINMAP  | Metadata used for gain maps.  | 
| HDR_METADATA_TYPE_ALTERNATE  | Metadata used for synthesized HDR graphics.  | 


### OH_PixelmapNative_AntiAliasingLevel

```
enum OH_PixelmapNative_AntiAliasingLevel
```

**Description**

Enumerates the antialiasing levels used for scaling pixel maps.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| OH_PixelmapNative_AntiAliasing_NONE  | Nearest neighbor.  | 
| OH_PixelmapNative_AntiAliasing_LOW  | Bilinear interpolation.  | 
| OH_PixelmapNative_AntiAliasing_MEDIUM  | Bilinear interpolation with mipmap enabled.  | 
| OH_PixelmapNative_AntiAliasing_HIGH  | Cubic convolution.  | 


### PIXELMAP_ALPHA_TYPE

```
enum PIXELMAP_ALPHA_TYPE
```

**Description**

Enumerates the alpha types of a pixel map.

**Since**: 12

| Value| Description| 
| -------- | -------- |
| PIXELMAP_ALPHA_TYPE_UNKNOWN | Unknown format.| 
| PIXELMAP_ALPHA_TYPE_OPAQUE | Opaque format.| 
| PIXELMAP_ALPHA_TYPE_PREMULTIPLIED | Premultiplied format.| 


## Function Description


### OH_DecodingOptions_Create()

```
Image_ErrorCode OH_DecodingOptions_Create (OH_DecodingOptions ** options)
```

**Description**

Creates the pointer to an **OH_DecodingOptions** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Double pointer to the **OH_DecodingOptions** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredDynamicRange (OH_DecodingOptions * options, int32_t * desiredDynamicRange )
```

**Description**

Obtains the desired dynamic range configured during decoding.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| desiredDynamicRange | Pointer to the desired dynamic range. For details about the available options, see [IMAGE_DYNAMIC_RANGE](#image_dynamic_range). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_GetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredRegion (OH_DecodingOptions * options, Image_Region * desiredRegion )
```

**Description**

Obtains the region to decode.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| desiredRegion | Pointer to the region to decode. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_GetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_GetDesiredSize (OH_DecodingOptions * options, Image_Size * desiredSize )
```

**Description**

Obtains the desired output size.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| desiredSize | Pointer to the desired output size. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_GetIndex()

```
Image_ErrorCode OH_DecodingOptions_GetIndex (OH_DecodingOptions * options, uint32_t * index )
```

**Description**

Obtains the index of an image.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| index | Pointer to the index of the image to decode. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_GetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_GetPixelFormat (OH_DecodingOptions * options, int32_t * pixelFormat )
```

**Description**

Obtains the pixel format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| pixelFormat | Pointer to the pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).| 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_GetRotate()

```
Image_ErrorCode OH_DecodingOptions_GetRotate (OH_DecodingOptions * options, float * rotate )
```

**Description**

Obtains the rotation degree.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| rotate | Pointer to the angle to rotate, in degrees. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_Release()

```
Image_ErrorCode OH_DecodingOptions_Release (OH_DecodingOptions * options)
```

**Description**

Releases the pointer to an **OH_DecodingOptions** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).



### OH_DecodingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredDynamicRange (OH_DecodingOptions * options, int32_t desiredDynamicRange )
```

**Description**

Sets the desired dynamic range during decoding.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| desiredDynamicRange | Desired dynamic range. For details about the available options, see [IMAGE_DYNAMIC_RANGE](#image_dynamic_range). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).




### OH_DecodingOptions_SetDesiredRegion()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredRegion (OH_DecodingOptions * options, Image_Region * desiredRegion )
```

**Description**

Sets the region to decode.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| desiredRegion | Pointer to the region to decode. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_SetDesiredSize()

```
Image_ErrorCode OH_DecodingOptions_SetDesiredSize (OH_DecodingOptions * options, Image_Size * desiredSize )
```

**Description**

Sets the desired output size.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| desiredSize | Pointer to the desired output size. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_SetIndex()

```
Image_ErrorCode OH_DecodingOptions_SetIndex (OH_DecodingOptions * options, uint32_t index )
```

**Description**

Sets the index for an image.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| index | Index of the image to decode. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_SetPixelFormat()

```
Image_ErrorCode OH_DecodingOptions_SetPixelFormat (OH_DecodingOptions * options, int32_t pixelFormat )
```

**Description**

Sets the pixel format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| pixelFormat | Pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_DecodingOptions_SetRotate()

```
Image_ErrorCode OH_DecodingOptions_SetRotate (OH_DecodingOptions * options, float rotate )
```

**Description**

Sets the rotation angle.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_DecodingOptions** object. | 
| rotate | Angle to rotate, in degrees. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageNative_GetBufferSize()

```
Image_ErrorCode OH_ImageNative_GetBufferSize (OH_ImageNative * image, uint32_t componentType, size_t * size )
```

**Description**

Obtains the size of the buffer corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an [OH_ImageNative](#oh_imagenative) object. | 
| componentType | Component type. | 
| size | Pointer to the size of the buffer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageNative_GetByteBuffer()

```
Image_ErrorCode OH_ImageNative_GetByteBuffer (OH_ImageNative * image, uint32_t componentType, OH_NativeBuffer ** nativeBuffer )
```

**Description**

Obtains the buffer corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an [OH_ImageNative](#oh_imagenative) object. | 
| componentType | Component type. | 
| nativeBuffer | Double pointer to the buffer, which is an **OH_NativeBuffer** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageNative_GetComponentTypes()

```
Image_ErrorCode OH_ImageNative_GetComponentTypes (OH_ImageNative * image, uint32_t ** types, size_t * typeSize )
```

**Description**

Obtains the component types of an [OH_ImageNative](#oh_imagenative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an [OH_ImageNative](#oh_imagenative) object. | 
| types | Double pointer to the component types obtained. | 
| typeSize | Pointer to the number of component types obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageNative_GetImageSize()

```
Image_ErrorCode OH_ImageNative_GetImageSize (OH_ImageNative * image, Image_Size * size )
```

**Description**

Obtains the [Image_Size](_image___size.md) information of an [OH_ImageNative](#oh_imagenative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an [OH_ImageNative](#oh_imagenative) object. | 
| size | Pointer to the [Image_Size](_image___size.md) object obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageNative_GetPixelStride()

```
Image_ErrorCode OH_ImageNative_GetPixelStride (OH_ImageNative * image, uint32_t componentType, int32_t * pixelStride )
```

**Description**

Obtains the pixel stride corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an [OH_ImageNative](#oh_imagenative) object. | 
| componentType | Component type. | 
| pixelStride | Pointer to the pixel stride obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageNative_GetRowStride()

```
Image_ErrorCode OH_ImageNative_GetRowStride (OH_ImageNative * image, uint32_t componentType, int32_t * rowStride )
```

**Description**

Obtains the row stride corresponding to a component type in an [OH_ImageNative](#oh_imagenative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an [OH_ImageNative](#oh_imagenative) object. | 
| componentType | Component type. | 
| rowStride | Pointer to the row stride obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageNative_Release()

```
Image_ErrorCode OH_ImageNative_Release (OH_ImageNative * image)
```

**Description**

Releases an [OH_ImageNative](#oh_imagenative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| image | Pointer to an [OH_ImageNative](#oh_imagenative) object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImagePackerNative_Create()

```
Image_ErrorCode OH_ImagePackerNative_Create (OH_ImagePackerNative ** imagePacker)
```

**Description**

Creates the pointer to an **OH_ImagePackerNative** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Double pointer to the **OH_ImagePackerNative** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImagePackerNative_PackToDataFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromImageSource (OH_ImagePackerNative * imagePacker, OH_PackingOptions * options, OH_ImageSourceNative * imageSource, uint8_t * outData, size_t * size )
```

**Description**

Encodes an image source into data in a given format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imagePacker | Pointer to an **OH_ImagePackerNative** object. | 
| options | Pointer to an [OH_PackingOptions](#oh_packingoptions) object. | 
| imageSource | Pointer to the image source to encode. | 
| outData | Pointer to the buffer used to store the output data. | 
| size | Pointer to the size of the buffer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_DECODE_FAILED** if image decoding fails; returns **IMAGE_ALLOC_FAILED** if memory allocation fails; returns **IMAGE_TOO_LARGE** if the data or image is too large; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImagePackerNative_PackToDataFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToDataFromPixelmap (OH_ImagePackerNative * imagePacker, OH_PackingOptions * options, OH_PixelmapNative * pixelmap, uint8_t * outData, size_t * size )
```

**Description**

Encodes a pixel map into data in a given format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imagePacker | Pointer to an **OH_ImagePackerNative** object. | 
| options | Pointer to an [OH_PackingOptions](#oh_packingoptions) object.| 
| pixelmap | Pointer to the pixel map to encode. | 
| outData | Pointer to the buffer used to store the output data. | 
| size | Pointer to the size of the buffer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_DECODE_FAILED** if image decoding fails; returns **IMAGE_ALLOC_FAILED** if memory allocation fails; returns **IMAGE_TOO_LARGE** if the data or image is too large; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImagePackerNative_PackToFileFromImageSource()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromImageSource (OH_ImagePackerNative * imagePacker, OH_PackingOptions * options, OH_ImageSourceNative * imageSource, int32_t fd )
```

**Description**

Encodes an image source into a file.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imagePacker | Pointer to an **OH_ImagePackerNative** object. | 
| options | Pointer to an [OH_PackingOptions](#oh_packingoptions) object.| 
| imageSource | Pointer to the image source to encode. | 
| fd | File descriptor, which is writable. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_DECODE_FAILED** if image decoding fails; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImagePackerNative_PackToFileFromPixelmap()

```
Image_ErrorCode OH_ImagePackerNative_PackToFileFromPixelmap (OH_ImagePackerNative * imagePacker, OH_PackingOptions * options, OH_PixelmapNative * pixelmap, int32_t fd )
```

**Description**

Encodes a pixel map into a file.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imagePacker | Pointer to an **OH_ImagePackerNative** object. | 
| options | Pointer to an [OH_PackingOptions](#oh_packingoptions) object.| 
| pixelmap | Pointer to the pixel map to encode. | 
| fd | File descriptor, which is writable. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_DECODE_FAILED** if image decoding fails; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImagePackerNative_Release()

```
Image_ErrorCode OH_ImagePackerNative_Release (OH_ImagePackerNative * imagePacker)
```

**Description**

Releases the pointer to an **OH_ImagePackerNative** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| imagePacker | Pointer to an **OH_ImagePackerNative** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageReceiverNative_Create()

```
Image_ErrorCode OH_ImageReceiverNative_Create (OH_ImageReceiverOptions * options, OH_ImageReceiverNative ** receiver )
```

**Description**

Creates an **OH_ImageReceiverNative** object at the application layer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object. | 
| receiver | Double pointer to the [OH_ImageReceiverNative](#oh_imagereceivernative) object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_ALLOC_FAILED** if memory allocation fails. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageReceiverNative_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverNative_GetCapacity (OH_ImageReceiverNative * receiver, int32_t * capacity )
```

**Description**

Obtains the capacity of an image receiver, which is an [OH_ImageReceiverNative](#oh_imagereceivernative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 
| capacity | Pointer to the capacity obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative)


### OH_ImageReceiverNative_GetReceivingSurfaceId()

```
Image_ErrorCode OH_ImageReceiverNative_GetReceivingSurfaceId (OH_ImageReceiverNative * receiver, uint64_t * surfaceId )
```

**Description**

Obtains the receiver ID through an [OH_ImageReceiverNative](#oh_imagereceivernative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 
| surfaceId | Pointer to the surface ID obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative)


### OH_ImageReceiverNative_GetSize()

```
Image_ErrorCode OH_ImageReceiverNative_GetSize (OH_ImageReceiverNative * receiver, Image_Size * size )
```

**Description**

Obtains the size of an image receiver, which is an [OH_ImageReceiverNative](#oh_imagereceivernative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 
| size | Pointer to the [Image_Size](_image___size.md) object obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative), [Image_Size](_image___size.md)


### OH_ImageReceiverNative_Off()

```
Image_ErrorCode OH_ImageReceiverNative_Off (OH_ImageReceiverNative * receiver)
```

**Description**

Unregisters a callback, which is an [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) object.

The callback is registered by calling [OH_ImageReceiverNative_On](#oh_imagereceivernative_on).

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageReceiverNative_On](#oh_imagereceivernative_on)


### OH_ImageReceiverNative_On()

```
Image_ErrorCode OH_ImageReceiverNative_On (OH_ImageReceiverNative * receiver, OH_ImageReceiver_OnCallback callback )
```

**Description**

Registers a callback, which is an [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) object.

This callback is triggered whenever a new image is received.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 
| callback | Callback, which is an [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback) object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageReceiver_OnCallback](#oh_imagereceiver_oncallback)


### OH_ImageReceiverNative_ReadLatestImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadLatestImage (OH_ImageReceiverNative * receiver, OH_ImageNative ** image )
```

**Description**

Obtains the latest image through an [OH_ImageReceiverNative](#oh_imagereceivernative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 
| image | Double pointer to the image obtained, which is an **OH_ImageNative** object at the application layer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs; returns **IMAGE_ALLOC_FAILED** if memory allocation fails. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageNative](#oh_imagenative)


### OH_ImageReceiverNative_ReadNextImage()

```
Image_ErrorCode OH_ImageReceiverNative_ReadNextImage (OH_ImageReceiverNative * receiver, OH_ImageNative ** image )
```

**Description**

Obtains the next image through an [OH_ImageReceiverNative](#oh_imagereceivernative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 
| image | Double pointer to the image obtained, which is an **OH_ImageNative** object at the application layer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs; returns **IMAGE_ALLOC_FAILED** if memory allocation fails. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative), [OH_ImageNative](#oh_imagenative)


### OH_ImageReceiverNative_Release()

```
Image_ErrorCode OH_ImageReceiverNative_Release (OH_ImageReceiverNative * receiver)
```

**Description**

Releases an [OH_ImageReceiverNative](#oh_imagereceivernative) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| receiver | Pointer to an [OH_ImageReceiverNative](#oh_imagereceivernative) object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverNative](#oh_imagereceivernative)


### OH_ImageReceiverOptions_Create()

```
Image_ErrorCode OH_ImageReceiverOptions_Create (OH_ImageReceiverOptions ** options)
```

**Description**

Creates an **OH_ImageReceiverOptions** object at the application layer.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Double pointer to the [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_ALLOC_FAILED** if memory allocation fails. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageReceiverOptions_GetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_GetCapacity (OH_ImageReceiverOptions * options, int32_t * capacity )
```

**Description**

Obtains the capacity of an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object. | 
| capacity | Pointer to the capacity obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageReceiverOptions_GetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_GetSize (OH_ImageReceiverOptions * options, Image_Size * size )
```

**Description**

Obtains the [Image_Size](_image___size.md) information of an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object. | 
| size | Pointer to the [Image_Size](_image___size.md) object obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageReceiverOptions_Release()

```
Image_ErrorCode OH_ImageReceiverOptions_Release (OH_ImageReceiverOptions * options)
```

**Description**

Releases an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).

**See**

[OH_ImageReceiverOptions](#oh_imagereceiveroptions)


### OH_ImageReceiverOptions_SetCapacity()

```
Image_ErrorCode OH_ImageReceiverOptions_SetCapacity (OH_ImageReceiverOptions * options, int32_t capacity )
```

**Description**

Sets the capacity for an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object. | 
| capacity | Capacity to set. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageReceiverOptions_SetSize()

```
Image_ErrorCode OH_ImageReceiverOptions_SetSize (OH_ImageReceiverOptions * options, Image_Size size )
```

**Description**

Sets the [Image_Size](_image___size.md) information for an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an [OH_ImageReceiverOptions](#oh_imagereceiveroptions) object. | 
| size | [Image_Size](_image___size.md) object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceInfo_Create()

```
Image_ErrorCode OH_ImageSourceInfo_Create (OH_ImageSource_Info ** info)
```

**Description**

Creates the pointer to an **OH_ImageSource_Info** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Double pointer to the **OH_ImageSource_Info** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceInfo_GetDynamicRange()

```
Image_ErrorCode OH_ImageSourceInfo_GetDynamicRange (OH_ImageSource_Info * info, bool * isHdr )
```

**Description**

Obtains the dynamic range of an image.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_ImageSource_Info** object. | 
| isHdr | Pointer to a Boolean that specifies whether the HDR is used. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceInfo_GetHeight()

```
Image_ErrorCode OH_ImageSourceInfo_GetHeight (OH_ImageSource_Info * info, uint32_t * height )
```

**Description**

Obtains the image height.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_ImageSource_Info** object. | 
| height | Pointer to the image height, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceInfo_GetWidth()

```
Image_ErrorCode OH_ImageSourceInfo_GetWidth (OH_ImageSource_Info * info, uint32_t * width )
```

**Description**

Obtains the image width.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_ImageSource_Info** object. | 
| width | Pointer to the image width, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceInfo_Release()

```
Image_ErrorCode OH_ImageSourceInfo_Release (OH_ImageSource_Info * info)
```

**Description**

Releases the pointer to an **OH_ImageSource_Info** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_ImageSource_Info** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_CreateFromData()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromData (uint8_t * data, size_t dataSize, OH_ImageSourceNative ** res )
```

**Description**

Creates the pointer to an **OH_ImageSourceNative** object based on buffer data.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| data | Pointer to the buffer data. | 
| dataSize | Size of the buffer. | 
| res | Double pointer to the **OH_ImageSourceNative** object created at the C++ local layer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_BAD_SOURCE** if the data source is abnormal. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_CreateFromFd()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromFd (int32_t fd, OH_ImageSourceNative ** res )
```

**Description**

Creates the pointer to an **OH_ImageSourceNative** object based on a file descriptor.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| fd | File descriptor. | 
| res | Double pointer to the **OH_ImageSourceNative** object created at the C++ local layer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_CreateFromRawFile()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromRawFile (RawFileDescriptor * rawFile, OH_ImageSourceNative ** res )
```

**Description**

Creates the pointer to an **OH_ImageSourceNative** object by using the raw file descriptor of an image resource file.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| rawFile | Pointer to the file descriptor of the raw file. | 
| res | Double pointer to the **OH_ImageSourceNative** object created at the C++ local layer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_CreateFromUri()

```
Image_ErrorCode OH_ImageSourceNative_CreateFromUri (char * uri, size_t uriSize, OH_ImageSourceNative ** res )
```

**Description**

Creates the pointer to an **OH_ImageSourceNative** object based on a URI.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| uri | Pointer to the URI of the image source. Only file URIs or Base64 URIs are accepted. Currently, only absolute paths are supported. |
| uriSize | URI length. | 
| res | Double pointer to the **OH_ImageSourceNative** object created at the C++ local layer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_BAD_SOURCE** if the data source is abnormal. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_CreatePixelmap()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmap (OH_ImageSourceNative * source, OH_DecodingOptions * options, OH_PixelmapNative ** pixelmap )
```

**Description**

Creates the pointer to an **OH_PixelmapNative** object based on image decoding parameters.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 
| options | Pointer to the image decoding parameters. | 
| resPixMap | Double pointer to the **OH_PixelmapNative** object created at the C++ local layer. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_CreatePixelmapList()

```
Image_ErrorCode OH_ImageSourceNative_CreatePixelmapList (OH_ImageSourceNative * source, OH_DecodingOptions * options, OH_PixelmapNative * resVecPixMap[], size_t size )
```

**Description**

Creates an array of **OH_PixelmapNative** objects based on image decoding parameters.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 
| options | Pointer to the image decoding parameters. | 
| resVecPixMap | Pointer to an array of **OH_PixelmapNative** objects created at the C++ local layer. | 
| size | Size of the array. You can use [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) to obtain the size. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNSUPPORTED_OPERATION** if the operation is not supported. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_GetDelayTimeList()

```
Image_ErrorCode OH_ImageSourceNative_GetDelayTimeList (OH_ImageSourceNative * source, int32_t * delayTimeList, size_t size )
```

**Description**

Obtains the image delay time list.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 
| delayTimeList | Pointer to the delay time list obtained. It cannot be a null pointer. | 
| size | Size of the delay time list. You can use [OH_ImageSourceNative_GetFrameCount](#oh_imagesourcenative_getframecount) to obtain the size. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_GetFrameCount()

```
Image_ErrorCode OH_ImageSourceNative_GetFrameCount (OH_ImageSourceNative * source, uint32_t * frameCount )
```

**Description**

Obtains the number of image frames.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 
| frameCount | Pointer to the number of frames obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_GetImageInfo()

```
Image_ErrorCode OH_ImageSourceNative_GetImageInfo (OH_ImageSourceNative * source, int32_t index, OH_ImageSource_Info * info )
```

**Description**

Obtains the information about an image with a given index.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 
| index | Index of an image. For a GIF image, the value range is [0, N-1], where N indicates the number of GIF frames. For an image with only one frame, you can pass in **0**. | 
| info | Pointer to the image information obtained, which is an **OH_ImageSource_Info** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_GetImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_GetImageProperty (OH_ImageSourceNative * source, Image_String * key, Image_String * value )
```

**Description**

Obtains the value of an image property.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 
| key | Pointer to the property key. For details, see [Image_String](_image___string.md). For details about the value range of **key**, see the definition of **OHOS_IMAGE_PROPERTY_XXX**. The memory must be released after the image source is used. For details, see [OH_ImageSourceNative_Release](#oh_imagesourcenative_release). | 
| value | Pointer to the value obtained. You can pass in a null pointer with the size set to zero. In this case, the system will allocate memory, but you must release the memory after use. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_ModifyImageProperty()

```
Image_ErrorCode OH_ImageSourceNative_ModifyImageProperty (OH_ImageSourceNative * source, Image_String * key, Image_String * value )
```

**Description**

Modifies the value of an image property.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 
| key | Pointer to the property key. For details, see [Image_String](_image___string.md). **key** is an EXIF constant. The memory must be released after the image source is used. For details, see [OH_ImageSourceNative_Release](#oh_imagesourcenative_release). | 
| value | Pointer to the new value. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_ImageSourceNative_Release()

```
Image_ErrorCode OH_ImageSourceNative_Release (OH_ImageSourceNative * source)
```

**Description**

Releases the pointer to an **OH_ImageSourceNative** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_ImageSourceNative** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_Create()

```
Image_ErrorCode OH_PackingOptions_Create (OH_PackingOptions ** options)
```

**Description**

Creates the pointer to an **OH_PackingOptions** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Double pointer to the **OH_PackingOptions** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_GetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_GetDesiredDynamicRange (OH_PackingOptions * options, int32_t * desiredDynamicRange )
```

**Description**

Obtains the desired dynamic range during encoding.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_PackingOptions** object. | 
| desiredDynamicRange | Pointer to the desired dynamic range. For details about the available options, see [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_GetMimeType()

```
Image_ErrorCode OH_PackingOptions_GetMimeType (OH_PackingOptions * options, Image_MimeType * format )
```

**Description**

Obtains the MIME type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_PackingOptions** object. | 
| format | Pointer to the image format. You can pass in a null pointer with the size set to zero. In this case, the system will allocate memory, but you must release the memory after use. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_GetQuality()

```
Image_ErrorCode OH_PackingOptions_GetQuality (OH_PackingOptions * options, uint32_t * quality )
```

**Description**

Obtains the encoding quality.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_PackingOptions** object. | 
| quality | Pointer to the encoding quality. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_Release()

```
Image_ErrorCode OH_PackingOptions_Release (OH_PackingOptions * options)
```

**Description**

Releases the pointer to an **OH_PackingOptions** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_PackingOptions** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_SetDesiredDynamicRange()

```
Image_ErrorCode OH_PackingOptions_SetDesiredDynamicRange (OH_PackingOptions * options, int32_t desiredDynamicRange )
```

**Description**

Sets the desired dynamic range during encoding.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_PackingOptions** object. | 
| desiredDynamicRange | Desired dynamic range. For details about the available options, see [IMAGE_PACKER_DYNAMIC_RANGE](#image_packer_dynamic_range). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_SetMimeType()

```
Image_ErrorCode OH_PackingOptions_SetMimeType (OH_PackingOptions * options, Image_MimeType * format )
```

**Description**

Sets the MIME type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_PackingOptions** object. | 
| format | Pointer to the image format. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PackingOptions_SetQuality()

```
Image_ErrorCode OH_PackingOptions_SetQuality (OH_PackingOptions * options, uint32_t quality )
```

**Description**

Sets the encoding quality.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_PackingOptions** object. | 
| quality | Encoding quality. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_Create()

```
Image_ErrorCode OH_PixelmapImageInfo_Create (OH_Pixelmap_ImageInfo ** info)
```

**Description**

Creates the pointer to an **OH_Pixelmap_ImageInfo** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Double pointer to the **OH_Pixelmap_ImageInfo** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_GetAlphaType()

```
Image_ErrorCode OH_PixelmapImageInfo_GetAlphaType (OH_Pixelmap_ImageInfo * info, int32_t * alphaType )
```

**Description**

Obtains the alpha type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_Pixelmap_ImageInfo** object. | 
| alphaType | Pointer to the alpha type. For details about the available options, see [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_GetDynamicRange()

```
Image_ErrorCode OH_PixelmapImageInfo_GetDynamicRange (OH_Pixelmap_ImageInfo * info, bool * isHdr )
```

**Description**

Obtains the dynamic range of a pixel map.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_Pixelmap_ImageInfo** object. | 
| isHdr | Pointer to a Boolean that specifies whether the HDR is used. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_GetHeight()

```
Image_ErrorCode OH_PixelmapImageInfo_GetHeight (OH_Pixelmap_ImageInfo * info, uint32_t * height )
```

**Description**

Obtains the image height.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_Pixelmap_ImageInfo** object. | 
| height | Pointer to the image height, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapImageInfo_GetPixelFormat (OH_Pixelmap_ImageInfo * info, int32_t * pixelFormat )
```

**Description**

Obtains the pixel format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_Pixelmap_ImageInfo** object. | 
| pixelFormat | Pointer to the pixel format. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_GetRowStride()

```
Image_ErrorCode OH_PixelmapImageInfo_GetRowStride (OH_Pixelmap_ImageInfo * info, uint32_t * rowStride )
```

**Description**

Obtains the row stride.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_Pixelmap_ImageInfo** object. | 
| rowStride | Pointer to the row stride, which is the number of bytes from one row of pixels in memory to the next row of pixels in memory. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_GetWidth()

```
Image_ErrorCode OH_PixelmapImageInfo_GetWidth (OH_Pixelmap_ImageInfo * info, uint32_t * width )
```

**Description**

Obtains the image width.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_Pixelmap_ImageInfo** object. | 
| width | Pointer to the image width, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapImageInfo_Release()

```
Image_ErrorCode OH_PixelmapImageInfo_Release (OH_Pixelmap_ImageInfo * info)
```

**Description**

Releases the pointer to an **OH_Pixelmap_ImageInfo** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| info | Pointer to an **OH_Pixelmap_ImageInfo** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_Create()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Create (OH_Pixelmap_InitializationOptions ** options)
```

**Description**

Creates the pointer to an **OH_Pixelmap_InitializationOptions** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Double pointer to the **OH_Pixelmap_InitializationOptions** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_GetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetAlphaType (OH_Pixelmap_InitializationOptions * options, int32_t * alphaType )
```

**Description**

Obtains the alpha type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| alphaType | Pointer to the alpha type. For details about the available options, see [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_GetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetHeight (OH_Pixelmap_InitializationOptions * options, uint32_t * height )
```

**Description**

Obtains the image height.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| height | Pointer to the image height, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_GetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetPixelFormat (OH_Pixelmap_InitializationOptions * options, int32_t * pixelFormat )
```

**Description**

Obtains the pixel format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| pixelFormat | Pointer to the pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).| 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_GetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetRowStride (OH_Pixelmap_InitializationOptions * options, int32_t * rowStride )
```

**Description**

Obtains the row stride.

The stride is the actual memory size occupied by each row of the image, in bytes. Stride = Width \*Number of bytes per pixel + Padding, where padding refers to the extra space added at the end of each row for memory alignment purposes.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| rowStride | Pointer to the stride, in bytes. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNKNOWN_ERROR** if the object pointed to by **options** is released. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_GetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetSrcPixelFormat(OH_Pixelmap_InitializationOptions *ops, int32_t *srcpixelFormat)
```

**Description**

Obtains the source pixel format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object.| 
| srcpixelFormat | Pointer to the source pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).| 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_GetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_GetWidth (OH_Pixelmap_InitializationOptions * options, uint32_t * width )
```

**Description**

Obtains the image width.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| width | Pointer to the image width, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_Release()

```
Image_ErrorCode OH_PixelmapInitializationOptions_Release (OH_Pixelmap_InitializationOptions * options)
```

**Description**

Releases the pointer to an **OH_Pixelmap_InitializationOptions** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_SetAlphaType()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetAlphaType (OH_Pixelmap_InitializationOptions * options, int32_t alphaType )
```

**Description**

Sets the alpha type.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| alphaType | Alpha type. For details about the available options, see [PIXELMAP_ALPHA_TYPE](#pixelmap_alpha_type). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_SetHeight()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetHeight (OH_Pixelmap_InitializationOptions * options, uint32_t height )
```

**Description**

Sets the image height.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| height | Image height, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_SetPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetPixelFormat (OH_Pixelmap_InitializationOptions * options, int32_t pixelFormat )
```

**Description**

Sets the pixel format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| pixelFormat | Pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format).| 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_SetRowStride()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetRowStride (OH_Pixelmap_InitializationOptions * options, int32_t rowStride )
```

**Description**

Sets the row stride.

The stride is the actual memory size occupied by each row of the image, in bytes. Stride = Width \*Number of bytes per pixel + Padding, where padding refers to the extra space added at the end of each row for memory alignment purposes.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| rowStride | Pointer to the stride, in bytes. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNKNOWN_ERROR** if the object pointed to by **options** is released. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_SetSrcPixelFormat()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetSrcPixelFormat (OH_Pixelmap_InitializationOptions * options, int32_t srcpixelFormat )
```

**Description**

Sets the source pixel format.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| srcpixelFormat | Source pixel format. For details about the available options, see [PIXEL_FORMAT](#pixel_format). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapInitializationOptions_SetWidth()

```
Image_ErrorCode OH_PixelmapInitializationOptions_SetWidth (OH_Pixelmap_InitializationOptions * options, uint32_t width )
```

**Description**

Sets the image width.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to an **OH_Pixelmap_InitializationOptions** object. | 
| width | Image width, in px. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_ConvertAlphaFormat()

```
Image_ErrorCode OH_PixelmapNative_ConvertAlphaFormat (OH_PixelmapNative * srcpixelmap, OH_PixelmapNative * dstpixelmap, const bool isPremul )
```

**Description**

Converts pixel data of a pixel map from premultiplied alpha to non-premultiplied alpha, or vice versa.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| srcpixelmap | Pointer to the source pixel map, which is an **OH_PixelmapNative** object. | 
| dstpixelmap | Pointer to the destination pixel map, which is an **OH_PixelmapNative** object. This pointer must be different from the pointer to the source pixel map. | 
| isPremul | Conversion mode. The value **true** means a conversion from premultiplied alpha to non-premultiplied alpha, and **false** means a conversion from non-premultiplied alpha to premultiplied alpha. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_CreateEmptyPixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreateEmptyPixelmap (OH_Pixelmap_InitializationOptions * options, OH_PixelmapNative ** pixelmap )
```

**Description**

Creates an empty pixel map using **OH_Pixelmap_InitializationOptions**. The memory data is 0.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| options | Pointer to the properties. | 
| pixelmap | Double pointer to the **OH_PixelmapNative** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_CreatePixelmap()

```
Image_ErrorCode OH_PixelmapNative_CreatePixelmap (uint8_t * data, size_t dataLength, OH_Pixelmap_InitializationOptions * options, OH_PixelmapNative ** pixelmap )
```

**Description**

Creates a **PixelMap** object based on properties. By default, the BGRA_8888 format is used for data processing.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| data | Pointer to the color array in BGRA_8888 format. | 
| dataLength | Size of the array. | 
| options | Pointer to the properties. | 
| pixelmap | Double pointer to the **OH_PixelmapNative** object created. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNSUPPORTED_OPERATION** if the operation is not supported. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_Crop()

```
Image_ErrorCode OH_PixelmapNative_Crop (OH_PixelmapNative * pixelmap, Image_Region * region )
```

**Description**

Crops an image based on a given size.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| region | Pointer to the region of the image after cropping. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_Flip()

```
Image_ErrorCode OH_PixelmapNative_Flip (OH_PixelmapNative * pixelmap, bool shouldFilpHorizontally, bool shouldFilpVertically )
```

**Description**

Flips an image based on a given angle.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| shouldFilpHorizontally | Whether to flip the image horizontally. | 
| shouldFilpVertically | Whether to flip the image vertically. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_GetImageInfo()

```
Image_ErrorCode OH_PixelmapNative_GetImageInfo (OH_PixelmapNative * pixelmap, OH_Pixelmap_ImageInfo * imageInfo )
```

**Description**

Obtains the image information.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| imageInfo | Pointer to the image information. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_GetMetadata()

```
Image_ErrorCode OH_PixelmapNative_GetMetadata (OH_PixelmapNative * pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue ** value )
```

**Description**

Obtains the metadata.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| key | Metadata key. For details, see [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey). | 
| value | Double pointer to the value of the metadata key. For details, see [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_DMA_NOT_EXIST** if the DMA memory does not exist; returns **IMAGE_COPY_FAILED** if the memory copy fails. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_GetNativeBuffer()

```
Image_ErrorCode OH_PixelmapNative_GetNativeBuffer (OH_PixelmapNative * pixelmap, OH_NativeBuffer ** nativeBuffer )
```

**Description**

Obtains the **NativeBuffer** object from a pixel map in the DMA memory.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to the pixel map. | 
| nativeBuffer | Double pointer to the **NativeBuffer** object obtained. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_DMA_NOT_EXIST** if the memory is not the DMA memory; returns **IMAGE_DMA_OPERATION_FAILED** if the operation on the DMA memory fails. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_Opacity()

```
Image_ErrorCode OH_PixelmapNative_Opacity (OH_PixelmapNative * pixelmap, float rate )
```

**Description**

Sets the opacity rate to enable the pixel map to achieve the corresponding opacity effect.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| rate | Opacity rate to set. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_ReadPixels()

```
Image_ErrorCode OH_PixelmapNative_ReadPixels (OH_PixelmapNative * pixelmap, uint8_t * destination, size_t * bufferSize )
```

**Description**

Reads pixel data of an image and writes the data to the buffer based on the pixel format of the pixel map.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| destination | Pointer to the buffer to which the image pixel map data will be written. | 
| bufferSize | Pointer to the buffer size. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_Release()

```
Image_ErrorCode OH_PixelmapNative_Release (OH_PixelmapNative * pixelmap)
```

**Description**

Releases the pointer to an **OH_PixelmapNative** object.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_Rotate()

```
Image_ErrorCode OH_PixelmapNative_Rotate (OH_PixelmapNative * pixelmap, float angle )
```

**Description**

Rotates an image based on a given angle.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| angle | Image rotation angle, in degrees. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_Scale()

```
Image_ErrorCode OH_PixelmapNative_Scale (OH_PixelmapNative * pixelmap, float scaleX, float scaleY )
```

**Description**

Scales an image based on a given width and height.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| scaleX | Scale ratio of the width. | 
| scaleY | Scale ratio of the height. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_ScaleWithAntiAliasing()

```
Image_ErrorCode OH_PixelmapNative_ScaleWithAntiAliasing (OH_PixelmapNative * pixelmap, float scaleX, float scaleY, OH_PixelmapNative_AntiAliasingLevel level )
```

**Description**

Scales an image based on the specified antialiasing level, width, and height.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| scaleX | Scale ratio of the width. | 
| scaleY | Scale ratio of the height. | 
| level | Antialiasing level. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_TOO_LARGE** if the image is too large; returns **IMAGE_ALLOC_FAILED** if memory allocation fails; returns **IMAGE_UNKNOWN_ERROR** if the object pointed to by **pixelmap** is released. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_SetMetadata()

```
Image_ErrorCode OH_PixelmapNative_SetMetadata (OH_PixelmapNative * pixelmap, OH_Pixelmap_HdrMetadataKey key, OH_Pixelmap_HdrMetadataValue * value )
```

**Description**

Sets metadata.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| key | Pointer to the metadata key. For details, see [OH_Pixelmap_HdrMetadataKey](#oh_pixelmap_hdrmetadatakey). | 
| value | Pointer to the value of the metadata key. For details, see [OH_Pixelmap_HdrMetadataValue](_o_h___pixelmap___hdr_metadata_value.md). | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_DMA_NOT_EXIST** if the DMA memory does not exist; returns **IMAGE_COPY_FAILED** if the memory copy fails. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_ToSdr()

```
Image_ErrorCode OH_PixelmapNative_ToSdr (OH_PixelmapNative * pixelmap)
```

**Description**

Converts an HDR image into an SDR image.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNSUPPORTED_OPERATION** if the operation is not supported. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_Translate()

```
Image_ErrorCode OH_PixelmapNative_Translate (OH_PixelmapNative * pixelmap, float x, float y )
```

**Description**

Translates an image based on given coordinates.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| x | X coordinate to translate. | 
| y | Y coordinate to translate. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect. For details, see [Image_ErrorCode](#image_errorcode).


### OH_PixelmapNative_WritePixels()

```
Image_ErrorCode OH_PixelmapNative_WritePixels (OH_PixelmapNative * pixelmap, uint8_t * source, size_t bufferSize )
```

**Description**

Reads the pixel data in the buffer and writes the result to the pixel map based on the pixel format of the pixel map.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| pixelmap | Pointer to an **OH_PixelmapNative** object. | 
| source | Pointer to the buffer from which the image data will be read. | 
| bufferSize | Buffer size. | 

**Returns**

Returns **IMAGE_SUCCESS** if the operation is successful; returns **IMAGE_BAD_PARAMETER** if a parameter is incorrect; returns **IMAGE_UNSUPPORTED_OPERATION** if the operation is not supported; returns **IMAGE_UNKNOWN_ERROR** if an unknown error occurs. For details, see [Image_ErrorCode](#image_errorcode).


## Variable Description


### MIME_TYPE_BMP

```
static const char* MIME_TYPE_BMP = "image/bmp"
```

**Description**

BMP image format.

**Since**: 12


### MIME_TYPE_GIF

```
static const char* MIME_TYPE_GIF = "image/gif"
```

**Description**

GIF image format.

**Since**: 12


### MIME_TYPE_HEIC

```
static const char* MIME_TYPE_HEIC = "image/heic"
```

**Description**

HEIF image format.

**Since**: 12


### MIME_TYPE_ICON

```
static const char* MIME_TYPE_ICON = "image/x-icon"
```

**Description**

ICO image format.

**Since**: 12


### MIME_TYPE_JPEG

```
static const char* MIME_TYPE_JPEG = "image/jpeg"
```

**Description**

JPEG image format.

**Since**: 12


### MIME_TYPE_PNG

```
static const char* MIME_TYPE_PNG = "image/png"
```

**Description**

PNG image format.

**Since**: 12


### MIME_TYPE_WEBP

```
static const char* MIME_TYPE_WEBP = "image/webp"
```

**Description**

WebP image format.

**Since**: 12


### OHOS_IMAGE_PROPERTY_ARTIST

```
static const char* OHOS_IMAGE_PROPERTY_ARTIST = "Artist"
```

**Description**

Person who created the image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE

```
static const char* OHOS_IMAGE_PROPERTY_BITS_PER_SAMPLE = "BitsPerSample"
```

**Description**

Number of bits per sample.

**Since**: 12


### OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_BODY_SERIAL_NUMBER = "BodySerialNumber"
```

**Description**

Serial number of the camera body.

**Since**: 12


### OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE

```
static const char* OHOS_IMAGE_PROPERTY_BRIGHTNESS_VALUE = "BrightnessValue"
```

**Description**

Value of brightness, expressed in APEX values.

**Since**: 12


### OHOS_IMAGE_PROPERTY_BURST_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_BURST_NUMBER = "HwMnoteBurstNumber"
```

**Description**

Number of burst shooting times.

**Since**: 12


### OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME

```
static const char* OHOS_IMAGE_PROPERTY_CAMERA_OWNER_NAME = "CameraOwnerName"
```

**Description**

Name of the camera owner.

**Since**: 12


### OHOS_IMAGE_PROPERTY_CFA_PATTERN

```
static const char* OHOS_IMAGE_PROPERTY_CFA_PATTERN = "CFAPattern"
```

**Description**

Color Filter Array (CFA) geometric pattern of the image sensor.

**Since**: 12


### OHOS_IMAGE_PROPERTY_COLOR_SPACE

```
static const char* OHOS_IMAGE_PROPERTY_COLOR_SPACE = "ColorSpace"
```

**Description**

Color space information, which is usually recorded as a color space specifier.

**Since**: 12


### OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION

```
static const char* OHOS_IMAGE_PROPERTY_COMPONENTS_CONFIGURATION = "ComponentsConfiguration"
```

**Description**

Specific information about compressed data.

**Since**: 12


### OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE

```
static const char* OHOS_IMAGE_PROPERTY_COMPOSITE_IMAGE = "CompositeImage"
```

**Description**

Whether the image is a composite image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL

```
static const char* OHOS_IMAGE_PROPERTY_COMPRESSED_BITS_PER_PIXEL = "CompressedBitsPerPixel"
```

**Description**

Number of bits per pixel. It is specific to compressed data.

**Since**: 12


### OHOS_IMAGE_PROPERTY_COMPRESSION

```
static const char* OHOS_IMAGE_PROPERTY_COMPRESSION = "Compression"
```

**Description**

Compression scheme used on the image data.

**Since**: 12


### OHOS_IMAGE_PROPERTY_CONTRAST

```
static const char* OHOS_IMAGE_PROPERTY_CONTRAST = "Contrast"
```

**Description**

Direction of contrast processing used by the camera.

**Since**: 12


### OHOS_IMAGE_PROPERTY_COPYRIGHT

```
static const char* OHOS_IMAGE_PROPERTY_COPYRIGHT = "Copyright"
```

**Description**

Copyright notice of the image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED

```
static const char* OHOS_IMAGE_PROPERTY_CUSTOM_RENDERED = "CustomRendered"
```

**Description**

Special processing on image data.

**Since**: 12


### OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED

```
static const char* OHOS_IMAGE_PROPERTY_DATE_TIME_DIGITIZED = "DateTimeDigitized"
```

**Description**

Date and time when the image was stored as digital data, in the format of YYYY:MM:DD HH:MM:SS.

**Since**: 12


### OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL

```
static const char* OHOS_IMAGE_PROPERTY_DATE_TIME_ORIGINAL = "DateTimeOriginal"
```

**Description**

Shooting time, for example, 2022:09:06 15:48:00.

**Since**: 12


### OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE

```
static const char* OHOS_IMAGE_PROPERTY_DEFAULT_CROP_SIZE = "DefaultCropSize"
```

**Description**

Size of the final image area, in raw image coordinates, taking into account extra pixels around the edges of the final image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION

```
static const char* OHOS_IMAGE_PROPERTY_DEVICE_SETTING_DESCRIPTION = "DeviceSettingDescription"
```

**Description**

Information about the photographing conditions of a specific camera model.

**Since**: 12


### OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO

```
static const char* OHOS_IMAGE_PROPERTY_DIGITAL_ZOOM_RATIO = "DigitalZoomRatio"
```

**Description**

Digital zoom ratio when the image was captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_DNG_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_DNG_VERSION = "DNGVersion"
```

**Description**

DNG version. It encodes the DNG 4-tier version number.

**Since**: 12


### OHOS_IMAGE_PROPERTY_EXIF_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_EXIF_VERSION = "ExifVersion"
```

**Description**

Version of the supported EXIF standard.

**Since**: 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_INDEX = "ExposureIndex"
```

**Description**

Exposure index selected at the time the image is captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_MODE

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_MODE = "ExposureMode"
```

**Description**

Exposure mode set when the image was captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_PROGRAM = "ExposureProgram"
```

**Description**

Class of the program used by the camera to set exposure when the image was captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_EXPOSURE_TIME

```
static const char* OHOS_IMAGE_PROPERTY_EXPOSURE_TIME = "ExposureTime"
```

**Description**

Exposure time, for example, 1/33 seconds.

**Since**: 12


### OHOS_IMAGE_PROPERTY_F_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_F_NUMBER = "FNumber"
```

**Description**

F number, for example, f/1.8.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_CONF

```
static const char* OHOS_IMAGE_PROPERTY_FACE_CONF = "HwMnoteFaceConf"
```

**Description**

Face confidence.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_LEYE_CENTER = "HwMnoteFaceLeyeCenter"
```

**Description**

Left eye centered. It is used in **OH_ImageSource_GetImageProperty** and **OH_ImageSource_ModifyImageProperty**.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_MOUTH_CENTER = "HwMnoteFaceMouthCenter"
```

**Description**

Mouth centered.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_POINTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_POINTER = "HwMnoteFacePointer"
```

**Description**

Face pointer.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_RECT

```
static const char* OHOS_IMAGE_PROPERTY_FACE_RECT = "HwMnoteFaceRect"
```

**Description**

Face rectangle.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER

```
static const char* OHOS_IMAGE_PROPERTY_FACE_REYE_CENTER = "HwMnoteFaceReyeCenter"
```

**Description**

Right eye centered.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE

```
static const char* OHOS_IMAGE_PROPERTY_FACE_SMILE_SCORE = "HwMnoteFaceSmileScore"
```

**Description**

Smile score of for faces.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FACE_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_FACE_VERSION = "HwMnoteFaceVersion"
```

**Description**

Facial recognition algorithm version.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FILE_SOURCE

```
static const char* OHOS_IMAGE_PROPERTY_FILE_SOURCE = "FileSource"
```

**Description**

Image source.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FLASH_ENERGY

```
static const char* OHOS_IMAGE_PROPERTY_FLASH_ENERGY = "FlashEnergy"
```

**Description**

Strobe energy at the time the image was captured, in Beam Candle Power Seconds (BCPS).

**Since**: 12


### OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_FLASHPIX_VERSION = "FlashpixVersion"
```

**Description**

FlashPix format version supported by an FPXR file. It is used to enhance device compatibility.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT

```
static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_RESOLUTION_UNIT = "FocalPlaneResolutionUnit"
```

**Description**

Unit for measuring FocalPlaneXResolution and FocalPlaneYResolution.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_X_RESOLUTION = "FocalPlaneXResolution"
```

**Description**

Number of pixels in the image width (X) direction per FocalPlaneResolutionUnit.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_FOCAL_PLANE_Y_RESOLUTION = "FocalPlaneYResolution"
```

**Description**

Number of pixels in the image height (Y) direction per FocalPlaneResolutionUnit.

**Since**: 12


### OHOS_IMAGE_PROPERTY_FRONT_CAMERA

```
static const char* OHOS_IMAGE_PROPERTY_FRONT_CAMERA = "HwMnoteFrontCamera"
```

**Description**

Whether the front camera is used to take a selfie.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GAIN_CONTROL

```
static const char* OHOS_IMAGE_PROPERTY_GAIN_CONTROL = "GainControl"
```

**Description**

Degree of overall image gain adjustment.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GAMMA

```
static const char* OHOS_IMAGE_PROPERTY_GAMMA = "Gamma"
```

**Description**

Gamma value.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT

```
static const char* OHOS_IMAGE_PROPERTY_GIF_LOOP_COUNT = "GIFLoopCount"
```

**Description**

Number of GIF loops.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_ALTITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE = "GPSAltitude"
```

**Description**

Altitude based on the reference in GPSAltitudeRef.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_ALTITUDE_REF = "GPSAltitudeRef"
```

**Description**

Whether the latitude is north or south latitude.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION

```
static const char* OHOS_IMAGE_PROPERTY_GPS_AREA_INFORMATION = "GPSAreaInformation"
```

**Description**

String that records the name of the GPS area.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING = "GPSDestBearing"
```

**Description**

Bearing to the destination point.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_BEARING_REF = "GPSDestBearingRef"
```

**Description**

Reference of the bearing to the destination point.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE = "GPSDestDistance"
```

**Description**

Distance to the destination point.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_DISTANCE_REF = "GPSDestDistanceRef"
```

**Description**

Unit used to express the distance to the destination point.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE = "GPSDestLatitude"
```

**Description**

Latitude of the destination point.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LATITUDE_REF = "GPSDestLatitudeRef"
```

**Description**

Whether the latitude of the destination point is north or south latitude.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE = "GPSDestLongitude"
```

**Description**

Longitude of the destination point.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DEST_LONGITUDE_REF = "GPSDestLongitudeRef"
```

**Description**

Whether the longitude of the destination point is east or west longitude.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DIFFERENTIAL = "GPSDifferential"
```

**Description**

Whether differential correction is applied to the GPS receiver. It is critical to accurate location accuracy.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_DOP

```
static const char* OHOS_IMAGE_PROPERTY_GPS_DOP = "GPSDOP"
```

**Description**

GPS DOP (data degree of precision)

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR

```
static const char* OHOS_IMAGE_PROPERTY_GPS_H_POSITIONING_ERROR = "GPSHPositioningError"
```

**Description**

Horizontal positioning error, in meters.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION

```
static const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION = "GPSImgDirection"
```

**Description**

Direction of the image when it was captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_IMG_DIRECTION_REF = "GPSImgDirectionRef"
```

**Description**

Reference of the direction of the image when it was captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE = "GPSLatitude"
```

**Description**

Image latitude.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LATITUDE_REF = "GPSLatitudeRef"
```

**Description**

Whether the latitude is north or south latitude.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE = "GPSLongitude"
```

**Description**

Image longitude.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_LONGITUDE_REF = "GPSLongitudeRef"
```

**Description**

Whether the longitude is east or west longitude.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM

```
static const char* OHOS_IMAGE_PROPERTY_GPS_MAP_DATUM = "GPSMapDatum"
```

**Description**

Geodetic survey data used by the GPS receiver.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE

```
static const char* OHOS_IMAGE_PROPERTY_GPS_MEASURE_MODE = "GPSMeasureMode"
```

**Description**

GPS measurement pmode.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD

```
static const char* OHOS_IMAGE_PROPERTY_GPS_PROCESSING_METHOD = "GPSProcessingMethod"
```

**Description**

String that records the name of the method used for positioning.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_SATELLITES

```
static const char* OHOS_IMAGE_PROPERTY_GPS_SATELLITES = "GPSSatellites"
```

**Description**

GPS satellites used for measurement.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_SPEED

```
static const char* OHOS_IMAGE_PROPERTY_GPS_SPEED = "GPSSpeed"
```

**Description**

Movement speed of the GPS receiver.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_SPEED_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_SPEED_REF = "GPSSpeedRef"
```

**Description**

Unit used to express the movement speed of the GPS receiver.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_STATUS

```
static const char* OHOS_IMAGE_PROPERTY_GPS_STATUS = "GPSStatus"
```

**Description**

Status of the GPS receiver when the image was recorded.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_TRACK

```
static const char* OHOS_IMAGE_PROPERTY_GPS_TRACK = "GPSTrack"
```

**Description**

Movement direction of the GPS receiver.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_TRACK_REF

```
static const char* OHOS_IMAGE_PROPERTY_GPS_TRACK_REF = "GPSTrackRef"
```

**Description**

Reference of the movement direction of the GPS receiver.

**Since**: 12


### OHOS_IMAGE_PROPERTY_GPS_VERSION_ID

```
static const char* OHOS_IMAGE_PROPERTY_GPS_VERSION_ID = "GPSVersionID"
```

**Description**

Version of GPSInfoIFD.

**Since**: 12


### OHOS_IMAGE_PROPERTY_IMAGE_LENGTH

```
static const char* OHOS_IMAGE_PROPERTY_IMAGE_LENGTH = "ImageLength"
```

**Description**

Image length.

**Since**: 12


### OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID

```
static const char* OHOS_IMAGE_PROPERTY_IMAGE_UNIQUE_ID = "ImageUniqueID"
```

**Description**

Unique identifier assigned to each image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_IMAGE_WIDTH

```
static const char* OHOS_IMAGE_PROPERTY_IMAGE_WIDTH = "ImageWidth"
```

**Description**

Image width.

**Since**: 12


### OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY

```
static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEYYY = "ISOSpeedLatitudeyyy"
```

**Description**

ISO speed latitude yyy value of the camera or input device, which is defined in ISO 12232.

**Since**: 12


### OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ

```
static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_LATITUDEZZZ = "ISOSpeedLatitudezzz"
```

**Description**

ISO speed latitude zzz value of the camera or input device, which is defined in ISO 12232.

**Since**: 12


### OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS

```
static const char* OHOS_IMAGE_PROPERTY_ISO_SPEED_RATINGS = "ISOSpeedRatings"
```

**Description**

ISO sensitivity or ISO speed, for example, 400.

**Since**: 12


### OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT

```
static const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT = "JPEGInterchangeFormat"
```

**Description**

Offset of the SOI marker of a JPEG interchange format bitstream.

**Since**: 12


### OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH

```
static const char* OHOS_IMAGE_PROPERTY_JPEG_INTERCHANGE_FORMAT_LENGTH = "JPEGInterchangeFormatLength"
```

**Description**

Number of bytes of the JPEG stream.

**Since**: 12


### OHOS_IMAGE_PROPERTY_LENS_MAKE

```
static const char* OHOS_IMAGE_PROPERTY_LENS_MAKE = "LensMake"
```

**Description**

Manufacturer of the lens.

**Since**: 12


### OHOS_IMAGE_PROPERTY_LENS_MODEL

```
static const char* OHOS_IMAGE_PROPERTY_LENS_MODEL = "LensModel"
```

**Description**

Model of the lens.

**Since**: 12


### OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER

```
static const char* OHOS_IMAGE_PROPERTY_LENS_SERIAL_NUMBER = "LensSerialNumber"
```

**Description**

Serial number of the lens.

**Since**: 12


### OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION

```
static const char* OHOS_IMAGE_PROPERTY_LENS_SPECIFICATION = "LensSpecification"
```

**Description**

Specifications of the lens.

**Since**: 12


### OHOS_IMAGE_PROPERTY_MAKER_NOTE

```
static const char* OHOS_IMAGE_PROPERTY_MAKER_NOTE = "MakerNote"
```

**Description**

Marker used by EXIF/DCF manufacturers to record any required information.

**Since**: 12


### OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE

```
static const char* OHOS_IMAGE_PROPERTY_MAX_APERTURE_VALUE = "MaxApertureValue"
```

**Description**

Smallest F number of the lens.

**Since**: 12


### OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_NEW_SUBFILE_TYPE = "NewSubfileType"
```

**Description**

Data type of a subfile, such as a full-resolution image, a thumbnail, or a part of a multi-frame image. The value is a bit mask. The value 0 indicates a full-resolution image, **1** indicates a thumbnail, and **2** indicates a part of a multi-frame image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_OECF

```
static const char* OHOS_IMAGE_PROPERTY_OECF = "OECF"
```

**Description**

Opto-Electric Conversion Function (OECF) specified in ISO 14524.

**Since**: 12


### OHOS_IMAGE_PROPERTY_OFFSET_TIME

```
static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME = "OffsetTime"
```

**Description**

Time with an offset from UTC when the image was captured, in the format of ±HH:MM.

**Since**: 12


### OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED

```
static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_DIGITIZED = "OffsetTimeDigitized"
```

**Description**

Time with an offset from UTC when the image was digitized. It helps to accurately adjust the timestamp.

**Since**: 12


### OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL

```
static const char* OHOS_IMAGE_PROPERTY_OFFSET_TIME_ORIGINAL = "OffsetTimeOriginal"
```

**Description**

Time with an offset from UTC when the original image was created. It is critical for time-sensitive applications.

**Since**: 12


### OHOS_IMAGE_PROPERTY_ORIENTATION

```
static const char* OHOS_IMAGE_PROPERTY_ORIENTATION = "Orientation"
```

**Description**

Image orientation.

**Since**: 12


### OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY

```
static const char* OHOS_IMAGE_PROPERTY_PHOTOGRAPHIC_SENSITIVITY = "PhotographicSensitivity"
```

**Description**

Sensitivity of the camera or input device when the image was captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION

```
static const char* OHOS_IMAGE_PROPERTY_PHOTOMETRIC_INTERPRETATION = "PhotometricInterpretation"
```

**Description**

Color space of the image data, for example, RGB or YCbCr.

**Since**: 12


### OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION

```
const char* OHOS_IMAGE_PROPERTY_PLANAR_CONFIGURATION = "PlanarConfiguration"
```

**Description**

Storage format of components of each pixel, which can be chunky or planar.

**Since**: 12


### OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES

```
static const char* OHOS_IMAGE_PROPERTY_PRIMARY_CHROMATICITIES = "PrimaryChromaticities"
```

**Description**

Chromaticities of the primaries of the image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE

```
static const char* OHOS_IMAGE_PROPERTY_REFERENCE_BLACK_WHITE = "ReferenceBlackWhite"
```

**Description**

A pair of headroom and footroom image data values (codes) for each pixel component.

**Since**: 12


### OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE

```
static const char* OHOS_IMAGE_PROPERTY_RELATED_SOUND_FILE = "RelatedSoundFile"
```

**Description**

Name of an audio file related to the image data.

**Since**: 12


### OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT

```
static const char* OHOS_IMAGE_PROPERTY_RESOLUTION_UNIT = "ResolutionUnit"
```

**Description**

Unit of measurement for XResolution and YResolution.

**Since**: 12


### OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP

```
static const char* OHOS_IMAGE_PROPERTY_ROWS_PER_STRIP = "RowsPerStrip"
```

**Description**

Number of rows per strip.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL

```
static const char* OHOS_IMAGE_PROPERTY_SAMPLES_PER_PIXEL = "SamplesPerPixel"
```

**Description**

Number of components per pixel. The value is **3** for RGB and YCbCr images. The **JPEG** key is used in JPEG compressed data.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SATURATION

```
static const char* OHOS_IMAGE_PROPERTY_SATURATION = "Saturation"
```

**Description**

Direction of saturation processing used by the camera.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_CAPTURE_TYPE = "SceneCaptureType"
```

**Description**

Type of the scene that was captured.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SCENE_POINTER

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_POINTER = "HwMnoteScenePointer"
```

**Description**

Pointer to the scene.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SCENE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_TYPE = "SceneType"
```

**Description**

Type of the scene, for example, portrait, scenery, motion, and night.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SCENE_VERSION

```
static const char* OHOS_IMAGE_PROPERTY_SCENE_VERSION = "HwMnoteSceneVersion"
```

**Description**

Scene algorithm version.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SENSING_METHOD

```
static const char* OHOS_IMAGE_PROPERTY_SENSING_METHOD = "SensingMethod"
```

**Description**

Type of the image sensor on the camera.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SHARPNESS

```
static const char* OHOS_IMAGE_PROPERTY_SHARPNESS = "Sharpness"
```

**Description**

Direction of sharpness processing used by the camera.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE

```
static const char* OHOS_IMAGE_PROPERTY_SHUTTER_SPEED_VALUE = "ShutterSpeedValue"
```

**Description**

Shutter speed, expressed in Additive System of Photographic Exposure (APEX) values.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SOFTWARE

```
static const char* OHOS_IMAGE_PROPERTY_SOFTWARE = "Software"
```

**Description**

Name and version number of the software used to create the image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE

```
static const char* OHOS_IMAGE_PROPERTY_SOURCE_EXPOSURE_TIMES_OF_COMPOSITE_IMAGE = "SourceExposureTimesOfCompositeImage"
```

**Description**

Exposure time of source images of the composite image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE

```
static const char* OHOS_IMAGE_PROPERTY_SOURCE_IMAGE_NUMBER_OF_COMPOSITE_IMAGE = "SourceImageNumberOfCompositeImage"
```

**Description**

Number of source images of the composite image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE

```
static const char* OHOS_IMAGE_PROPERTY_SPATIAL_FREQUENCY_RESPONSE = "SpatialFrequencyResponse"
```

**Description**

Spatial frequency table of the camera or input device.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY

```
static const char* OHOS_IMAGE_PROPERTY_SPECTRAL_SENSITIVITY = "SpectralSensitivity"
```

**Description**

Spectral sensitivity of each channel of the camera.

**Since**: 12


### OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS

```
static const char* OHOS_IMAGE_PROPERTY_STRIP_BYTE_COUNTS = "StripByteCounts"
```

**Description**

Number of bytes in each strip after compression.

**Since**: 12


### OHOS_IMAGE_PROPERTY_STRIP_OFFSETS

```
static const char* OHOS_IMAGE_PROPERTY_STRIP_OFFSETS = "StripOffsets"
```

**Description**

Byte offset of each strip.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBFILE_TYPE

```
static const char* OHOS_IMAGE_PROPERTY_SUBFILE_TYPE = "SubfileType"
```

**Description**

Type of data contained in this subfile. This tag has been deprecated. Use **NewSubfileType** instead.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBJECT_AREA

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_AREA = "SubjectArea"
```

**Description**

Location and area of the main subject in the entire scene.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE = "SubjectDistance"
```

**Description**

Distance to the subject, in meters.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_DISTANCE_RANGE = "SubjectDistanceRange"
```

**Description**

Distance to the subject.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION

```
static const char* OHOS_IMAGE_PROPERTY_SUBJECT_LOCATION = "SubjectLocation"
```

**Description**

Location of the main subject relative to the left edge.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBSEC_TIME

```
static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME = "SubsecTime"
```

**Description**

Tag used to record fractions of seconds for the **DateTime** tag.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED

```
static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME_DIGITIZED = "SubsecTimeDigitized"
```

**Description**

Tag used to record fractions of seconds for the **DateTimeDigitized** tag.

**Since**: 12


### OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL

```
static const char* OHOS_IMAGE_PROPERTY_SUBSEC_TIME_ORIGINAL = "SubsecTimeOriginal"
```

**Description**

Tag used to record fractions of seconds for the **DateTimeOriginal** tag.

**Since**: 12


### OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION

```
static const char* OHOS_IMAGE_PROPERTY_TRANSFER_FUNCTION = "TransferFunction"
```

**Description**

Transfer function for the image, which is usually used for color correction.

**Since**: 12


### OHOS_IMAGE_PROPERTY_WHITE_POINT

```
static const char* OHOS_IMAGE_PROPERTY_WHITE_POINT = "WhitePoint"
```

**Description**

Chromaticity of the white point of the image.

**Since**: 12


### OHOS_IMAGE_PROPERTY_X_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_X_RESOLUTION = "XResolution"
```

**Description**

Number of pixels per ResolutionUnit in the image width (X) direction.

**Since**: 12


### OHOS_IMAGE_PROPERTY_Y_RESOLUTION

```
static const char* OHOS_IMAGE_PROPERTY_Y_RESOLUTION = "YResolution"
```

**Description**

Number of pixels per ResolutionUnit in the image height (Y) direction.

**Since**: 12


### OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS

```
static const char* OHOS_IMAGE_PROPERTY_YCBCR_COEFFICIENTS = "YCbCrCoefficients"
```

**Description**

Transformation from RGB to YCbCr image data.

**Since**: 12


### OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING

```
static const char* OHOS_IMAGE_PROPERTY_YCBCR_POSITIONING = "YCbCrPositioning"
```

**Description**

Positioning of subsampled chrominance components relative to luminance samples.

**Since**: 12


### OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING

```
static const char* OHOS_IMAGE_PROPERTY_YCBCR_SUB_SAMPLING = "YCbCrSubSampling"
```

**Description**

Subsampling factors used for the chrominance components of a YCbCr image.

**Since**: 12
