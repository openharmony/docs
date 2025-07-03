# OH_PackingOptions

## Overview

The OH_PackingOptions struct describes the image packing options encapsulated at the native layer. The struct cannot be directly operated. Instead, functions must be called to create and release the struct and operate the fields in the struct.

To create an OH_PackingOptions object, call [OH_PackingOptions_Create](capi-image-packer-native-h.md#oh_packingoptions_create).

To release an OH_PackingOptions object, call [OH_PackingOptions_Release](capi-image-packer-native-h.md#oh_packingoptions_release).

The table below describes the content and operation mode of the OH_PackingOptions struct.

| Field Type| Field Name| Field Description|Operation Function| Function Description|
| -------- | -------- | -------- | -------- | -------- |
| Image_MimeType | mimeType | MIME type.| [OH_PackingOptions_GetMimeType](capi-image-packer-native-h.md#oh_packingoptions_getmimetype) | Obtains the MIME type.|
| Image_MimeType | mimeType | MIME type.| [OH_PackingOptions_SetMimeType](capi-image-packer-native-h.md#oh_packingoptions_setmimetype) | Sets the MIME type.|
| uint32_t | quality | Encoding quality.| [OH_PackingOptions_GetQuality](capi-image-packer-native-h.md#oh_packingoptions_getquality) | Obtains the encoding quality.|
| uint32_t | quality | Encoding quality.| [OH_PackingOptions_SetQuality](capi-image-packer-native-h.md#oh_packingoptions_setquality) | Sets the encoding quality.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_PackingOptions_GetDesiredDynamicRange](capi-image-packer-native-h.md#oh_packingoptions_getdesireddynamicrange) | Obtains the desired dynamic range during encoding.|
| int32_t | desiredDynamicRange | Desired dynamic range.| [OH_PackingOptions_SetDesiredDynamicRange](capi-image-packer-native-h.md#oh_packingoptions_setdesireddynamicrange) | Sets the desired dynamic range during encoding.|

**Since**: 12

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_packer_native.h](capi-image-packer-native-h.md)
