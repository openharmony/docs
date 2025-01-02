# Introduction to the Image_NativeModule Structs

This topic describes certain structs provided by the Image_NativeModule module. For details about other structs, see the [API Reference](../../reference/apis-image-kit/_image___native_module.md#structs).

## OH_ImageNative Struct

OH_ImageNative is the image object struct encapsulated at the native layer. The struct cannot be directly operated. Instead, its fields must be operated by calling functions. The table below describes the content and operation mode of the OH_ImageNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| Image_Size| imageSize | Image size.|[OH_ImageNative_GetImageSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getimagesize) | Obtains the image size of an **OH_ImageNative** object.|
| uint32_t | types |Component type, which is used to describe the image's color component.|[OH_ImageNative_GetComponentTypes](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getcomponenttypes) | Obtains the component types of an **OH_ImageNative** object.|
| OH_NativeBuffer | nativeBuffer | Component buffer.|[OH_ImageNative_GetByteBuffer](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getbytebuffer) | Obtains the buffer corresponding to a component type in an **OH_ImageNative** object.|
| size_t | bufferSize | Buffer size.| [OH_ImageNative_GetBufferSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getbuffersize) | Obtains the size of the buffer corresponding to a component type in an **OH_ImageNative** object.|
| int32_t | rowStride | Row stride.| [OH_ImageNative_GetRowStride](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getrowstride) | Obtains the row stride corresponding to a component type in an **OH_ImageNative** object.|
| int32_t | pixelStride | Pixel stride.| [OH_ImageNative_GetPixelStride](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_getpixelstride) | Obtains the pixel stride corresponding to a component type in an **OH_ImageNative** object.|

You can run [OH_ImageNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagenative_release) to release an **OH_ImageNative** object.

## OH_ImagePackerNative Struct

OH_ImagePackerNative is the image packer struct encapsulated at the native layer. The struct cannot be directly operated. Instead, its fields must be operated by calling functions. The table below describes the content and operation mode of the OH_ImagePackerNative struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| OH_ImageSourceNative | imageSource | Image source.| [OH_ImagePackerNative_PackToDataFromImageSource](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtodatafromimagesource) | Encodes an image source into data in a given format.|
|OH_PixelmapNative | pixelmap | PixelMap at the native layer.| [OH_ImagePackerNative_PackToDataFromPixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtodatafrompixelmap) | Encodes a PixelMap into data in a given format.|
|int32_t | imagesourceFd | File descriptor of an image source.| [OH_ImagePackerNative_PackToFileFromImageSource](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtofilefromimagesource) | Encodes an image source into a file.|
|int32_t | pixelmapFd | File descriptor of a PixelMap.| [OH_ImagePackerNative_PackToFileFromPixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_packtofilefrompixelmap) | Encodes a PixelMap into a file.|

You can run [OH_ImagePackerNative_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_create) to create an **OH_ImagePackerNative** object.

You can run [OH_ImagePackerNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagepackernative_release) to release an **OH_ImagePackerNative** object.

## OH_PackingOptions Struct

OH_PackingOptions is the image packing option struct encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can run [OH_PackingOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_create) to create an **OH_PackingOptions** object.

You can run [OH_PackingOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_release) to release an **OH_PackingOptions** object.

The table below describes the content and operation mode of the OH_PackingOptions struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| Image_MimeType | mimeType | MIME type.| [OH_PackingOptions_GetMimeType](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_getmimetype) | Obtains the MIME type.|
| Image_MimeType | mimeType | MIME type.| [OH_PackingOptions_SetMimeType](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_setmimetype) | Sets the MIME type.|
| uint32_t | quality | Encoding quality.| [OH_PackingOptions_GetQuality](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_getquality) | Obtains the encoding quality.|
| uint32_t | quality | Encoding quality.| [OH_PackingOptions_SetQuality](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_setquality) | Sets the encoding quality.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_PackingOptions_GetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_getdesireddynamicrange) | Obtains the desired dynamic range during encoding.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_PackingOptions_SetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_packingoptions_setdesireddynamicrange) | Sets the desired dynamic range during encoding.|

## OH_ImageReceiverNative Struct

OH_ImageReceiverNative is the image receiver struct encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can run [OH_ImageReceiverNative_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_create) to create an **OH_ImageReceiverNative** object.

You can run [OH_ImageReceiverNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_release) to release an **OH_ImageReceiverNative** object.

The table below describes the content and operation mode of the OH_ImageReceiverNative struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint64_t | surfaceId | Surface ID of the receiver.| [OH_ImageReceiverNative_GetReceivingSurfaceId](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_getreceivingsurfaceid) |Obtains the receiver ID of an **OH_ImageReceiverNative** object.|
| OH_ImageNative | image | Image at the native layer.| [OH_ImageReceiverNative_ReadLatestImage](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_readlatestimage) | Obtains the latest image through an **OH_ImageReceiverNative** object.|
| OH_ImageNative | image | Image at the native layer.| [OH_ImageReceiverNative_ReadNextImage](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_readnextimage) |Obtains the next image through an **OH_ImageReceiverNative** object.|
| OH_ImageReceiver_OnCallback | callback| Callback function of the image receiver.| [OH_ImageReceiverNative_On](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_on) |Registers an **OH_ImageReceiver_OnCallback**.|
| OH_ImageReceiver_OnCallback | callback| Callback function of the image receiver.| [OH_ImageReceiverNative_Off](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_off) |Unregisters an **OH_ImageReceiver_OnCallback**.|
| Image_Size | size | Size of an image receiver.| [OH_ImageReceiverNative_GetSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_getsize) |Obtains the size of an **OH_ImageReceiverNative**.|
|int32_t | capacity| Capacity of an image receiver.| [OH_ImageReceiverNative_GetCapacity](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceivernative_getcapacity) |Obtains the capacity of an **OH_ImageReceiverNative**.|

## OH_ImageReceiverOptions Struct

OH_ImageReceiverOptions is the image receiver option setter struct encapsulated at the native layer. It is used to pass parameters during the creation of an **OH_ImageReceiverNative** object.
The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can run [OH_ImageReceiverOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_create) to create an **OH_ImageReceiverOptions** object.

You can run [OH_ImageReceiverOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_release) to release an **OH_ImageReceiverOptions** object.

The table below describes the content and operation mode of the OH_ImageReceiverOptions struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| Image_Size | size | Image size.| [OH_ImageReceiverOptions_GetSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_getsize)	|Obtains the image size of an **OH_ImageReceiverOptions** object.|
| Image_Size | size | Image size.| [OH_ImageReceiverOptions_SetSize](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_setsize)	|Sets the image size for an **OH_ImageReceiverOptions** object.|
| int32_t | capacity | Capacity of the image buffer.| [OH_ImageReceiverOptions_GetCapacity](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_getcapacity)	|Obtains the capacity of an **OH_ImageReceiverOptions** object.|
| int32_t | capacity | Capacity of the image buffer.| [OH_ImageReceiverOptions_SetCapacity](../../reference/apis-image-kit/_image___native_module.md#oh_imagereceiveroptions_setcapacity)	|Sets the capacity for an **OH_ImageReceiverOptions** object.|

## OH_ImageSourceNative Struct

OH_ImageSourceNative is the image source struct encapsulated at the native layer and is used to create image data. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can create an **OH_ImageSourceNative** object in multiple ways, as described below.
| Function| Description|
| -------- | -------- |
| [OH_ImageSourceNative_CreateFromUri](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromuri)	|Creates an **OH_ImageSourceNative** object based on a URI.|
| [OH_ImageSourceNative_CreateFromFd](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromfd)	|Creates an **OH_ImageSourceNative** object based on a file descriptor.|
| [OH_ImageSourceNative_CreateFromData](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromdata)	|Creates an **OH_ImageSourceNative** object based on buffer data.|
| [OH_ImageSourceNative_CreateFromRawFile](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createfromrawfile)	|Creates an **OH_ImageSourceNative** object by using the raw file descriptor of an image resource file.|
| [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmap)	|Creates an **OH_PixelmapNative** object based on image decoding parameters.|
| [OH_ImageSourceNative_CreatePixelmapList](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmaplist)	|Creates an array of **OH_PixelmapNative** objects based on image decoding parameters.|

You can run [OH_ImageSourceNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_release) to release an **OH_ImageSourceNative** object.

The table below describes the content and operation mode of the OH_ImageSourceNative struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| int32_t | delayTimeList | Image delay time list.| [OH_ImageSourceNative_GetDelayTimeList](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getdelaytimelist)	|Obtains the image delay time list.|
| OH_ImageSource_Info | info | Image source information.| [OH_ImageSourceNative_GetImageInfo](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getimageinfo)	|Obtains the information about an image with a given index.|
| Image_String | value | Configuration item.| [OH_ImageSourceNative_GetImageProperty](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getimageproperty)	|Obtains the value of an image property.|
| Image_String | value | Configuration item.| [OH_ImageSourceNative_ModifyImageProperty](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_modifyimageproperty)	|Modifies the value of an image property.|
| uint32_t | frameCount | Number of frames| [OH_ImageSourceNative_GetFrameCount](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_getframecount)	|Obtains the number of image frames.|

## OH_ImageSource_Info Struct

OH_ImageSource_Info is the image source information struct encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can run [OH_ImageSourceInfo_Create](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_create) to create an **OH_ImageSource_Info** object.

You can run [OH_ImageSourceInfo_Release](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_release) to release an **OH_ImageSource_Info** object.

The table below describes the content and operation mode of the OH_ImageSource_Info struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width.| [OH_ImageSourceInfo_GetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_getwidth)	|Obtains the image width.|
| uint32_t | height | Image height.| [OH_ImageSourceInfo_GetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_getheight)	|Obtains the image height.|
| bool | isHdr | Dynamic range.| [OH_ImageSourceInfo_GetDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourceinfo_getdynamicrange)	|Obtains the dynamic range of an image.|

## OH_DecodingOptions Struct

OH_DecodingOptions is the decoding options struct encapsulated at the native layer. This struct is used to set decoding options and is passed in as an input parameter for creating a PixelMap. For details, see [OH_ImageSourceNative_CreatePixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_imagesourcenative_createpixelmap).

The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

You can run [OH_DecodingOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_create) to create an **OH_DecodingOptions** object.

You can run [OH_DecodingOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_release) to release an **OH_DecodingOptions** object.

The table below describes the content and operation mode of the OH_DecodingOptions struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| int32_t | pixelFormat | Pixel format.| [OH_DecodingOptions_GetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getpixelformat)	|Obtains the pixel format.|
| int32_t | pixelFormat | Pixel format.| [OH_DecodingOptions_SetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setpixelformat)	| Sets the pixel format.|
| uint32_t | index | Index of the image to decode.| [OH_DecodingOptions_GetIndex](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getindex)	| Obtains the index of an image.|
| uint32_t | index | Index of the image to decode.| [OH_DecodingOptions_SetIndex](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setindex)	| Sets the index for an image.|
| float | rotate | Rotation angle.| [OH_DecodingOptions_GetRotate](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getrotate)	| Obtains the rotation degree.|
| float | rotate | Rotation angle.| [OH_DecodingOptions_SetRotate](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setrotate)	| Sets the rotation angle.|
| Image_Size | desiredSize | Desired output size.| [OH_DecodingOptions_GetDesiredSize](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getdesiredsize)	| Obtains the desired output size.|
| Image_Size | desiredSize | Desired output size.| [OH_DecodingOptions_SetDesiredSize](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setdesiredsize)	| Sets the desired output size.|
| Image_Region | desiredRegion | Region to decode.| [OH_DecodingOptions_GetDesiredRegion](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getdesiredregion) | Obtains the region to decode.|
| Image_Region | desiredRegion | Region to decode.| [OH_DecodingOptions_SetDesiredRegion](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setdesiredregion) | Sets the region to decode.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_DecodingOptions_GetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_getdesireddynamicrange)	|Obtains the desired dynamic range configured during decoding.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_DecodingOptions_SetDesiredDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_decodingoptions_setdesireddynamicrange)|Sets the desired dynamic range during decoding.|

## OH_PixelmapNative Struct

OH_PixelmapNative is an uncompressed PixelMap format struct encapsulated at the native layer after images are decoded.

You can run [OH_PixelmapNative_CreatePixelmap](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_createpixelmap) to create an **OH_PixelmapNative** object. By default, the BGRA_8888 format is used to process data.

You can run [OH_PixelmapNative_Release](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_release) to release an **OH_PixelmapNative** object.

The table below describes the content and operation mode of the OH_PixelmapNative struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint8_t | data | Image pixel data.| [OH_PixelmapNative_ReadPixels](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_readpixels)	| Reads the image pixel data and writes the data to an ArrayBuffer.|
| uint8_t | data | Image pixel data.| [OH_PixelmapNative_WritePixels](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_writepixels)	| Reads the image pixel data in the buffer and writes the data to a PixelMap.|
| OH_Pixelmap_ImageInfo | imageInfo | Image information.| [OH_PixelmapNative_GetImageInfo](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_getimageinfo)	| Obtains the image information.|
| float | alphaRate | Opacity rate.| [OH_PixelmapNative_Opacity](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_opacity)	| Sets the opacity rate to enable the PixelMap to achieve the corresponding opacity effect.|
|float, float, | scaleX, scaleY | Scale ratios along the X axis and Y axis, respectively.|[OH_PixelmapNative_Scale](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_scale)	| Scales an image based on a given width and height.|
| float, float| x, y | Distances to translate along the X axis and Y axis, respectively.| [OH_PixelmapNative_Translate](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_translate)	| Translates an image based on given coordinates.|
| float | angle | Rotation angle.|[OH_PixelmapNative_Rotate](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_rotate) | Rotates an image based on a given angle.|
| bool, bool | shouldFilpHorizontally, shouldFilpVertically | Whether to flip horizontally or vertically| [OH_PixelmapNative_Flip](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_flip)	| Flips an image based on a given angle.|
| Image_Region | region | Cropping region.| [OH_PixelmapNative_Crop](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_crop)	| Crops a PixelMap based on a given size.|

## OH_Pixelmap_InitializationOptions Struct

OH_Pixelmap_InitializationOptions is the initialization option struct encapsulated at the native layer. It is used to set the initialization parameters for a PixelMap.

You can run [OH_PixelmapInitializationOptions_Create](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_create) to create an **OH_Pixelmap_InitializationOptions** object.

You can run [OH_PixelmapInitializationOptions_Release](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_release) to release an **OH_Pixelmap_InitializationOptions** object.

The table below describes the content and operation mode of the OH_Pixelmap_InitializationOptions struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width.| [OH_PixelmapInitializationOptions_GetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getwidth)	|Obtains the image width.|
| uint32_t | width | Image width.| [OH_PixelmapInitializationOptions_SetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setwidth)	|Sets the image width.|
| uint32_t | height | Image height.| [OH_PixelmapInitializationOptions_GetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getheight)	|Obtains the image height.|
| uint32_t | height | Image height.| [OH_PixelmapInitializationOptions_SetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setheight)	|Sets the image height.|
| int32_t | pixelFormat | Pixel format.| [OH_PixelmapInitializationOptions_GetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getpixelformat)	|Obtains the pixel format.|
| int32_t | pixelFormat | Pixel format.| [OH_PixelmapInitializationOptions_SetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setpixelformat)	|Sets the pixel format.|
| int32_t | alphaType | Alpha type.| [OH_PixelmapInitializationOptions_GetAlphaType](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_getalphatype)	|Obtains the alpha type.|
| int32_t | alphaType | Alpha type.| [OH_PixelmapInitializationOptions_SetAlphaType](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_setalphatype)	|Sets the alpha type.|

## OH_Pixelmap_ImageInfo Struct

OH_Pixelmap_ImageInfo is the image information struct encapsulated at the native layer. It stores the width, height, row stride, pixel format, and HDR of an image.

You can run [OH_PixelmapImageInfo_Create](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_create) to create an **OH_Pixelmap_ImageInfo** object.

You can run [OH_PixelmapImageInfo_Release](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_release) to release an **OH_Pixelmap_ImageInfo** object.

The table below describes the content and operation mode of the OH_Pixelmap_ImageInfo struct.
| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| uint32_t | width | Image width.| [OH_PixelmapImageInfo_GetWidth](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getwidth)	| Obtains the image width.|
| uint32_t | height | Image height.| [OH_PixelmapImageInfo_GetHeight](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getheight)	| Obtains the image height.|
| uint32_t | rowStride | Row stride.| [OH_PixelmapImageInfo_GetRowStride](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getrowstride)	| Obtains the row stride.|
| int32_t | pixelFormat| Pixel format.| [OH_PixelmapImageInfo_GetPixelFormat](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getpixelformat)	|Obtains the pixel format.|
| int32_t | alphaType | Alpha type.| [OH_PixelmapImageInfo_GetAlphaType](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getalphatype)	|Obtains the alpha type.|
| bool | isHdr | Dynamic range.| [OH_PixelmapImageInfo_GetDynamicRange](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapimageinfo_getdynamicrange)	|Obtains the dynamic range of a PixelMap.|
