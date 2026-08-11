# native_audio_vivid.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650--->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=01b83f7f3d1ff1b424af3de357499307e5dc2db9 translatedAt=2026-08-01T07:19:35.969Z pushedAt=2026-08-01T07:47:41.569Z -->

## Overview

The file declares the functions and enums related to Audio Vivid.

**File to include**: <multimedia/player_framework/native_audio_vivid.h>

**Library**: libnative_media_core.so

**System capability**: SystemCapability.Multimedia.Media.Core

**Since**: 26.0.0

**Related module**: [Core](capi-core.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_CartesianPosition](capi-core-oh-cartesianposition.md) | OH_CartesianPosition | Describes the position of the audio object source in the Cartesian coordinate system. The Cartesian coordinate system uses the X, Y, and Z axes to define a position in three-dimensional space.|
| [OH_PolarPosition](capi-core-oh-polarposition.md) | OH_PolarPosition | Describes a position in the polar coordinate system (also known as the spherical coordinate system). The polar coordinate system uses the azimuth, elevation, and distance to define the position of an audio object source in three-dimensional space.|
| [OH_AudioObjectPosition](capi-core-oh-audioobjectposition.md) | OH_AudioObjectPosition | Describes the position of an audio object source in three-dimensional space. The position can be represented by Cartesian coordinates or polar coordinates.|
| [OH_AudioVividMetaBuilderStruct](capi-core-oh-audiovividmetabuilderstruct.md) | OH_AudioVividMetaBuilder | Forward declaration of OH_AudioVividMetaBuilder.|

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AudioVividSignalFormat](#oh_audiovividsignalformat) | OH_AudioVividSignalFormat | Enumerates the signal formats of the Audio Vivid encoder.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVErrCode OH_AudioVividMetaBuilder_Create(OH_AudioVividMetaBuilder **builder, const OH_AVFormat *format)](#oh_audiovividmetabuilder_create) | Creates an Audio Vivid metadata builder.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_UpdateObjectPos(OH_AudioVividMetaBuilder *builder, int32_t objectIndex, OH_AudioObjectPosition pos)](#oh_audiovividmetabuilder_updateobjectpos) | Updates the position of the audio object when the Audio Vivid signal format is [OH_AudioVividSignalFormat](capi-native-audio-vivid-h.md#oh_audiovividsignalformat).OH_AUDIO_VIVID_SIGNAL_FORMAT_MIX. In this signal format, the channel arrangement in the input encoded Pulse Code Modulation (PCM) data is as follows: bed channels come first, followed by object channels.<br> The object channels correspond to **objectIndex** in sequence, starting from 0.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_UpdateObjectGain(OH_AudioVividMetaBuilder *builder, int32_t objectIndex, float gain)](#oh_audiovividmetabuilder_updateobjectgain) | Updates the linear gain of audio object rendering when the Audio Vivid signal format is [OH_AudioVividSignalFormat](capi-native-audio-vivid-h.md#oh_audiovividsignalformat).OH_AUDIO_VIVID_SIGNAL_FORMAT_MIX.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_GetMetaLen(const OH_AudioVividMetaBuilder *builder, bool withStaticMeta, int32_t *len)](#oh_audiovividmetabuilder_getmetalen) | Obtains the length of metadata.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_GetMeta(const OH_AudioVividMetaBuilder *builder, bool withStaticMeta, uint8_t *buffer, int32_t len)](#oh_audiovividmetabuilder_getmeta) | Obtains the metadata buffer.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_Destroy(OH_AudioVividMetaBuilder *builder)](#oh_audiovividmetabuilder_destroy) | Destroys an Audio Vivid metadata builder and releases resources.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_CreateEmptyBuilder(OH_AudioVividMetaBuilder **builder)](#oh_audiovividmetabuilder_createemptybuilder) | Creates an empty Audio Vivid metadata builder. This function is used to merge Audio Vivid metadata. After creating an empty metadata builder, you can add, modify, or remove audio objects by calling the [OH_AudioVividMetaBuilder_UpdateBaseMeta](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updatebasemeta) API.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_UpdateBaseMeta(OH_AudioVividMetaBuilder *builder, const uint8_t *buffer, int32_t len)](#oh_audiovividmetabuilder_updatebasemeta) | Updates the basic metadata of the Audio Vivid metadata builder. The buffer must contain complete Audio Vivid metadata. The builder will retain the audio bed and audio object information in the metadata.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_AddObject(OH_AudioVividMetaBuilder *builder, int32_t *objectIndex)](#oh_audiovividmetabuilder_addobject) | Adds an audio object to the Audio Vivid metadata builder. After adding the audio object, you can update its position and linear gain for object rendering via the [OH_AudioVividMetaBuilder_UpdateObjectPos](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updateobjectpos) and [OH_AudioVividMetaBuilder_UpdateObjectGain](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updateobjectgain) APIs.|
| [OH_AVErrCode OH_AudioVividMetaBuilder_RemoveObject(OH_AudioVividMetaBuilder *builder, int32_t objectIndex)](#oh_audiovividmetabuilder_removeobject) | Deletes an audio object from the Audio Vivid metadata builder. Only audio objects added via the [OH_AudioVividMetaBuilder_AddObject](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_addobject) function can be deleted. Objects added via the [OH_AudioVividMetaBuilder_UpdateBaseMeta](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updatebasemeta) function cannot be deleted. After an audio object is deleted, the indexes of other audio objects remain unchanged.|

## Enumeration Description

### OH_AudioVividSignalFormat

```c
enum OH_AudioVividSignalFormat
```

**Description**

Enumerates the signal formats of the Audio Vivid encoder.

**Since**: 26.0.0

| Value| Description|
| -- | -- |
| OH_AUDIO_VIVID_SIGNAL_FORMAT_MONO = 0 | Mono. The encoder accepts mono data and internally sets the channel layout to [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_MONO.|
| OH_AUDIO_VIVID_SIGNAL_FORMAT_STEREO = 1 | Stereo. The encoder accepts stereo data and internally sets the channel layout to [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_STEREO.|
| OH_AUDIO_VIVID_SIGNAL_FORMAT_MC = 2 | Multi-channel audio. The encoder supports the following channel layouts: [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_5POINT1, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_5POINT1POINT2, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_5POINT1POINT4, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_7POINT1, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_7POINT1POINT2, and [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_7POINT1POINT4.|
| OH_AUDIO_VIVID_SIGNAL_FORMAT_MIX = 4 | Hybrid mode, including a bed and an object. The bed supports the following channel layouts: [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_STEREO, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_5POINT1, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_5POINT1POINT2, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_5POINT1POINT4, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_7POINT1, [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_7POINT1POINT2, and [OH_AudioChannelLayout](./capi-native-audio-channel-layout-h.md#oh_audiochannellayout).CH_LAYOUT_7POINT1POINT4.|

## Function Description

### OH_AudioVividMetaBuilder_Create()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_Create(OH_AudioVividMetaBuilder **builder, const OH_AVFormat *format)
```

**Description**

Creates an Audio Vivid metadata builder.

> **NOTE**
> 
> Lifecycle management:
> * If an instance created using this function is no longer needed, you must call [OH_AudioVividMetaBuilder_Destroy](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_destroy) to manually release the instance to avoid memory leaks.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) **builder | Output parameter, which is used to obtain the double pointer to the **OH_AudioVividMetaBuilder** instance.|
| [const OH_AVFormat](capi-core-oh-avformat.md) *format | Pointer to **OH_AVFormat** that contains the audio format information.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The **builder** or **format** parameter is a null pointer or invalid.<br>         **AV_ERR_UNSUPPORT**: This function is not supported on the device.<br>         **AV_ERR_UNKNOWN**: Failed to create the builder. This is an unknown error. Check the log for details.|

### OH_AudioVividMetaBuilder_UpdateObjectPos()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_UpdateObjectPos(OH_AudioVividMetaBuilder *builder, int32_t objectIndex, OH_AudioObjectPosition pos)
```

**Description**

Updates the position of the audio object when the Audio Vivid signal format is [OH_AudioVividSignalFormat](capi-native-audio-vivid-h.md#oh_audiovividsignalformat).OH_AUDIO_VIVID_SIGNAL_FORMAT_MIX. In this signal format, the channel arrangement in the input encoded Pulse Code Modulation (PCM) data is as follows: bed channels come first, followed by object channels.<br> The object channels correspond to **objectIndex** in sequence, starting from 0.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder**.|
| int32_t objectIndex | Index of the audio object to be updated, starting from 0. The value cannot be greater than [OH_MD_KEY_AUDIO_OBJECT_NUMBER](./capi-codecbase.md#key-value-pairs-dedicated-for-audio) set in the **format** parameter passed to [OH_AudioVividMetaBuilder_Create](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_create) for creating the builder.|
| [OH_AudioObjectPosition](capi-core-oh-audioobjectposition.md) pos | New position of the audio object source.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The **builder** parameter is a null pointer or invalid, or the **objectIndex** or **pos** parameter is invalid.|

### OH_AudioVividMetaBuilder_UpdateObjectGain()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_UpdateObjectGain(OH_AudioVividMetaBuilder *builder, int32_t objectIndex, float gain)
```

**Description**

Updates the linear gain of audio object rendering when the Audio Vivid signal format is [OH_AudioVividSignalFormat](capi-native-audio-vivid-h.md#oh_audiovividsignalformat).OH_AUDIO_VIVID_SIGNAL_FORMAT_MIX.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder**.|
| int32_t objectIndex | Index of the audio object to be updated, starting from 0. The value cannot be greater than [OH_MD_KEY_AUDIO_OBJECT_NUMBER](./capi-codecbase.md#key-value-pairs-dedicated-for-audio) set in the **format** parameter passed to [OH_AudioVividMetaBuilder_Create](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_create) for creating the builder.|
| float gain | Linear gain applied during object rendering. The value range is [0.0, 6.0], where **0.0** indicates silence, and **1.0** indicates no change. |

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The **builder** parameter is a null pointer or invalid, or the **objectIndex** or **gain** parameter is invalid.|

### OH_AudioVividMetaBuilder_GetMetaLen()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_GetMetaLen(const OH_AudioVividMetaBuilder *builder, bool withStaticMeta, int32_t *len)
```

**Description**

Obtains the length of metadata.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder**.|
| bool withStaticMeta | Whether the output length includes static metadata. The value **true** indicates that the output length includes static metadata, and the value **false** indicates that the output length includes only dynamic metadata.|
| int32_t *len | Pointer used to receive the metadata length. The unit is bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The **builder** parameter is a null pointer or invalid, or the **len** parameter is a null pointer.|

### OH_AudioVividMetaBuilder_GetMeta()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_GetMeta(const OH_AudioVividMetaBuilder *builder, bool withStaticMeta, uint8_t *buffer, int32_t len)
```

**Description**

Obtains the metadata buffer.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| const [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder**.|
| bool withStaticMeta | Whether the output buffer includes static metadata. The value **true** indicates that the output buffer includes static metadata, and the value **false** indicates that the output buffer includes only dynamic metadata.|
| uint8_t *buffer | Pointer to the buffer for receiving the metadata.|
| int32_t len | Buffer length, in bytes. The value must be greater than or equal to the length of the data to be obtained, which can be obtained via [OH_AudioVividMetaBuilder_GetMetaLen](#oh_audiovividmetabuilder_getmetalen).|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The **builder** parameter is a null pointer or invalid, the **buffer** parameter is a null pointer, or the **len** parameter value is insufficient.|

### OH_AudioVividMetaBuilder_Destroy()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_Destroy(OH_AudioVividMetaBuilder *builder)
```

**Description**

Destroys an Audio Vivid metadata builder and releases resources.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder** to be destroyed.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The **builder** parameter is a null pointer.|

### OH_AudioVividMetaBuilder_CreateEmptyBuilder()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_CreateEmptyBuilder(OH_AudioVividMetaBuilder **builder)
```

**Description**

Creates an empty Audio Vivid metadata builder. This function is used to merge Audio Vivid metadata. After creating an empty metadata builder, you can add, modify, or remove audio objects by calling the [OH_AudioVividMetaBuilder_UpdateBaseMeta](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updatebasemeta) API.

> **NOTE**
> 
> Lifecycle management:
> - If an instance created using this function is no longer needed, you must call [OH_AudioVividMetaBuilder_Destroy](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_destroy) to manually release it to avoid memory leaks.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) **builder | Output parameter, which is used to obtain the double pointer to the **OH_AudioVividMetaBuilder** instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | <ul><br>         <li>**AV_ERR_OK**: The operation is successful.</li><br>         <li>**AV_ERR_INVALID_VAL**: The **builder** parameter is a null pointer or invalid.</li><br>         <li>**AV_ERR_UNSUPPORT**: This function is not supported on the device.</li><br>         <li>**AV_ERR_UNKNOWN**: Failed to create the builder. This is an unknown error. Check the log for details.</li><br>         </ul> |

### OH_AudioVividMetaBuilder_UpdateBaseMeta()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_UpdateBaseMeta(OH_AudioVividMetaBuilder *builder, const uint8_t *buffer, int32_t len)
```

**Description**

Updates the basic metadata of the Audio Vivid metadata builder. The buffer must contain complete Audio Vivid metadata. The builder will retain the audio bed and audio object information in the metadata.

> **NOTE**
> 
> Constraints:
> - The total number of audio bed channels and objects in the basic metadata must be less than or equal to 16.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder**.|
| const uint8_t *buffer | Pointer to the basic metadata.|
| int32_t len | Buffer length, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | <ul><br>         <li>**AV_ERR_OK**: The operation is successful.</li><br>         <li>**AV_ERR_INVALID_VAL**: The **builder** or **format** parameter is a null pointer or invalid.</li><br>         </ul> |

### OH_AudioVividMetaBuilder_AddObject()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_AddObject(OH_AudioVividMetaBuilder *builder, int32_t *objectIndex)
```

**Description**

Adds an audio object to the Audio Vivid metadata builder. After adding the audio object, you can update its position and linear gain for object rendering via the [OH_AudioVividMetaBuilder_UpdateObjectPos](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updateobjectpos) and [OH_AudioVividMetaBuilder_UpdateObjectGain](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updateobjectgain) APIs.

> **NOTE**
>
> Constraints:
> - The total number of audio bed channels and objects in the audio must be less than or equal to 16.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder**.|
| int32_t *objectIndex | Output parameter, which is used to output the index of the new object.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | <ul><br>         <li>**AV_ERR_OK**: The operation is successful.</li><br>         <li>**AV_ERR_INVALID_VAL**: The **builder** or **objectIndex** parameter is a null pointer or invalid.</li><br>         <li>**AV_ERR_UNKNOWN**: Failed to add the object. This is an unknown error. Check the log for details.</li><br>         </ul> |

### OH_AudioVividMetaBuilder_RemoveObject()

```c
OH_AVErrCode OH_AudioVividMetaBuilder_RemoveObject(OH_AudioVividMetaBuilder *builder, int32_t objectIndex)
```

**Description**

Deletes an audio object from the Audio Vivid metadata builder. Only audio objects added via the [OH_AudioVividMetaBuilder_AddObject](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_addobject) function can be deleted. Objects added via the [OH_AudioVividMetaBuilder_UpdateBaseMeta](capi-native-audio-vivid-h.md#oh_audiovividmetabuilder_updatebasemeta) function cannot be deleted. After an audio object is deleted, the indexes of other audio objects remain unchanged.

**Since**: 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| [OH_AudioVividMetaBuilder](capi-core-oh-audiovividmetabuilderstruct.md) *builder | Pointer to **OH_AudioVividMetaBuilder**.|
| int32_t objectIndex | Index of the audio object to be removed.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | <ul><br>         <li>**AV_ERR_OK**: The operation is successful.</li><br>         <li>**AV_ERR_INVALID_VAL**: </li><br>         <li>    1. The **builder** parameter is a null pointer or invalid. </li><br>         <li>    2. The **objectIndex** parameter is set to an invalid value.</li><br>         </ul> |