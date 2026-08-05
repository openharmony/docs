# OH_PackingOptionsForSequence

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=80c0a43cc0af3435c23af3413e3b0da162d4ceb8 translatedAt=2026-08-03T04:00:49.670Z pushedAt=2026-08-04T07:10:58.059Z -->

```c
typedef struct OH_PackingOptionsForSequence OH_PackingOptionsForSequence
```

## Overview

OH_PackingOptionsForSequence is a GIF sequence encoding option struct encapsulated at the native layer. It cannot be manipulated directly; instead, functions shall be called to create and release the struct and to operate on its specific fields.

The [OH_PackingOptionsForSequence_Create](capi-image-packer-native-h.md#oh_packingoptionsforsequence_create) function is used to create an OH_PackingOptionsForSequence object.

The [OH_PackingOptionsForSequence_Release](capi-image-packer-native-h.md#oh_packingoptionsforsequence_release) function is used to release an OH_PackingOptionsForSequence object.

Usage restrictions: OH_PackingOptionsForSequence is used to configure encoding parameters when a PixelMap sequence is encoded into the GIF format. It must be passed to [OH_ImagePackerNative_PackToDataFromPixelmapSequence](capi-image-packer-native-h.md#oh_imagepackernative_packtodatafrompixelmapsequence) or [OH_ImagePackerNative_PackToFileFromPixelmapSequence](capi-image-packer-native-h.md#oh_imagepackernative_packtofilefrompixelmapsequence).

Resource management: After OH_PackingOptionsForSequence is used, [OH_PackingOptionsForSequence_Release](capi-image-packer-native-h.md#oh_packingoptionsforsequence_release) shall be called to release it. Once released, it must not be passed into image sequence encoding APIs or its field getter and setter APIs. Arrays passed in through [OH_PackingOptionsForSequence_SetDelayTimeList](capi-image-packer-native-h.md#oh_packingoptionsforsequence_setdelaytimelist) and [OH_PackingOptionsForSequence_SetDisposalTypes](capi-image-packer-native-h.md#oh_packingoptionsforsequence_setdisposaltypes) are not copied. The caller must ensure that the array data remains valid while the OH_PackingOptionsForSequence object is in use. Releasing the OH_PackingOptionsForSequence object does not release these arrays.

The content and operation methods of the OH_PackingOptionsForSequence struct are as follows.

| Field Type | Field Name | Field Description | Field Getter Function | Field Setting Function |
| -- | -- | -- | -- | -- |
| uint32_t | frameCount | Number of frames specified for encoding. It must be greater than 0 during encoding. | [OH_PackingOptionsForSequence_GetFrameCount](capi-image-packer-native-h.md#oh_packingoptionsforsequence_getframecount) | [OH_PackingOptionsForSequence_SetFrameCount](capi-image-packer-native-h.md#oh_packingoptionsforsequence_setframecount) |
| int32_t * | delayTimeList | Array of delay times for images during encoding. Each delay time in the array must be greater than 0 and not exceed 65535, in units of 10 milliseconds (ms). | [OH_PackingOptionsForSequence_GetDelayTimeList](capi-image-packer-native-h.md#oh_packingoptionsforsequence_getdelaytimelist) | [OH_PackingOptionsForSequence_SetDelayTimeList](capi-image-packer-native-h.md#oh_packingoptionsforsequence_setdelaytimelist) |
| uint32_t * | disposalTypes | Array of transition frame modes for images during encoding. Each value in the array must be less than or equal to 3. For the meaning of each value, see [OH_PackingOptionsForSequence_SetDisposalTypes](capi-image-packer-native-h.md#oh_packingoptionsforsequence_setdisposaltypes). | [OH_PackingOptionsForSequence_GetDisposalTypes](capi-image-packer-native-h.md#oh_packingoptionsforsequence_getdisposaltypes) | [OH_PackingOptionsForSequence_SetDisposalTypes](capi-image-packer-native-h.md#oh_packingoptionsforsequence_setdisposaltypes) |
| uint32_t | loopCount | Number of times the image loops during encoding. The value range is [0, 65535]. | [OH_PackingOptionsForSequence_GetLoopCount](capi-image-packer-native-h.md#oh_packingoptionsforsequence_getloopcount) | [OH_PackingOptionsForSequence_SetLoopCount](capi-image-packer-native-h.md#oh_packingoptionsforsequence_setloopcount) |

**Since**: 18

**Related module**: [Image_NativeModule](capi-image-nativemodule.md)

**Header file**: [image_packer_native.h](capi-image-packer-native-h.md)