# native_avcodec_videobase.h
<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @mr-chencxy-->
<!--Designer: @dpy2650-->
<!--Tester: @baotianhao-->
<!--Adviser: @w_Machine_cc-->

## Overview

The file declares the native APIs for basic video encoding and decoding functionalities, as well as video-specific configurations and parameters.

**File to include**: <multimedia/player_framework/native_avcodec_videobase.h>

**Library**: libnative_media_codecbase.so

**System capability**: SystemCapability.Multimedia.Media.CodecBase

**Since:** 26.0.0

**Related module**: [CodecBase](capi-codecbase.md)

## Summary

### Enums

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_VideoMetadataRoiSemanticLabel](#oh_videometadataroisemanticlabel) | OH_VideoMetadataRoiSemanticLabel | Enumerates semantic labels for regions of interest (ROIs) in video encoding.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVErrCode OH_VideoMetadata_AppendRoiString(char **roiStrInOut, OH_AVFormat *format)](#oh_videometadata_appendroistring) | Converts the ROI configuration in the OH_AVFormat handle into a string and appends it to the target string. This function extracts ROI attributes (such as coordinates, quantization parameter offset, and semantic label) from the provided format handle, constructs a standard ROI string, and appends it to the end of the string pointed to by `roiStrInOut`. If `*roiStrInOut` is NULL, a new string is allocated. If it is not NULL, the existing string is reallocated to append the new configuration.|
| [OH_AVErrCode OH_VideoMetadata_GetRoiCount(const char *roiStr, uint32_t *outCount)](#oh_videometadata_getroicount) | Obtains the ROI string to retrieve the number of valid ROI regions it contains. This API is not affected by specific backend capacity limits and identifies the number of ROI regions that meet the rule requirements in the ROI string based on the syntax rules.|
| [OH_AVErrCode OH_VideoMetadata_ParseRoiString(const char *roiStr, OH_AVFormat **outOwnedFormats, uint32_t maxCapacity, uint32_t *outCount)](#oh_videometadata_parseroistring) | Parses the ROI string and fills the OH_AVFormat array provided by the caller.|

### Variables

| Name| Description|
| -- | -- |
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_TOP | Pointer to the key that describes the top coordinate (y) of a single ROI rectangle. The value type is int32_t. The origin of the coordinate system is at the upper-left corner of the video. The value range is [0, OH_MD_KEY_VIDEO_METADATA_ROI_BOTTOM). This key is mandatory for ROI configuration.<br>**Since:** 26.0.0<br>**System capability**: SystemCapability.Multimedia.Media.CodecBase|
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_LEFT | Pointer to the key that describes the left coordinate (x) of a single ROI rectangle. The value type is int32_t. The origin of the coordinate system is at the upper-left corner of the video. The value range is [0, OH_MD_KEY_VIDEO_METADATA_ROI_RIGHT). This key is mandatory for ROI configuration.<br>**Since:** 26.0.0|
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_BOTTOM | Pointer to the key that describes the bottom coordinate (y) of a single ROI rectangle. The value type is int32_t. The origin of the coordinate system is at the upper-left corner of the video. The value range is (OH_MD_KEY_VIDEO_METADATA_ROI_TOP, OH_MD_KEY_VIDEO_HEIGHT]. This key is mandatory for ROI configuration.<br>**Since:** 26.0.0|
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_RIGHT | Pointer to the key that describes the right coordinate (x) of a single ROI rectangle. The value type is int32_t. The origin of the coordinate system is at the upper-left corner of the video. The value range is (OH_MD_KEY_VIDEO_METADATA_ROI_LEFT, OH_MD_KEY_VIDEO_WIDTH]. This key is mandatory for ROI configuration.<br>**Since:** 26.0.0|
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_DELTA_QP | Pointer to the key that describes the relative quantization parameter (QP) offset value of a single ROI. The value type is int32_t. The value range is [-51, 51]. This key is optional for ROI configuration. If this key is not set, the encoder will use its default quantization parameter strategy for this region.<br>**Since:** 26.0.0|
| const char * OH_MD_KEY_VIDEO_METADATA_ROI_SEM_LABEL | Pointer to the key that describes the semantic label of a single ROI. The value type is int32_t. The value must correspond to [OH_VideoMetadataRoiSemanticLabel](capi-native-avcodec-videobase-h.md#oh_videometadataroisemanticlabel). This key is optional for ROI configuration. If this key is not set, the region will use the default semantic processing strategy.<br>**Since:** 26.0.0|

## Enum Description

### OH_VideoMetadataRoiSemanticLabel

```c
enum OH_VideoMetadataRoiSemanticLabel
```

**Description**

Enumerates semantic labels for regions of interest (ROIs) in video encoding.

**Since:** 26.0.0

| Value| Description|
| -- | -- |
| OH_VIDEO_METADATA_ROI_SEM_LABEL_OTHER = 0 | Unspecified or unknown region.<br>**Since:** 26.0.0|
| OH_VIDEO_METADATA_ROI_SEM_LABEL_FACE = 1 | The ROI contains human faces.<br>**Since:** 26.0.0|


## Function Description

### OH_VideoMetadata_AppendRoiString()

```c
OH_AVErrCode OH_VideoMetadata_AppendRoiString(char **roiStrInOut, OH_AVFormat *format)
```

**Description**

Converts the ROI configuration in the OH_AVFormat handle into a string and appends it to the target string. This function extracts ROI attributes (such as coordinates, quantization parameter offset, and semantic label) from the provided format handle, constructs a standard ROI string, and appends it to the end of the string pointed to by `roiStrInOut`. If `*roiStrInOut` is NULL, a new string is allocated. If it is not NULL, the existing string is reallocated to append the new configuration.

> **NOTE**
> 
> The caller owns the memory allocated for `*roiStrInOut`.
> The memory is allocated using the C standard library allocator (`malloc`/`realloc`).
> When the string is no longer needed, the caller must release it using the matching C standard library deallocator (`free`), and set the pointer to `NULL` to prevent repeated freeing.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| char **roiStrInOut | Double pointer to the target string. The pointer itself must not be NULL. If `*roiStrInOut` is NULL, a new string is allocated.|
| OH_AVFormat *format | OH_AVFormat handle containing the ROI parameters to be appended. It must not be NULL.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AVErrCode | `AV_ERR_OK`: The string is successfully converted and appended.<br> `AV_ERR_INVALID_VAL`: The `roiStrInOut` pointer or `format` handle is NULL, or the format lacks the required ROI key.<br> `AV_ERR_NO_MEMORY`: Internal memory allocation or reallocation fails.|

### OH_VideoMetadata_GetRoiCount()

```c
OH_AVErrCode OH_VideoMetadata_GetRoiCount(const char *roiStr, uint32_t *outCount)
```

**Description**

Pre-parse the ROI string to retrieve the number of valid ROI regions it contains. This API is not affected by specific backend capacity limits and identifies the number of ROI regions that meet the rule requirements in the ROI string based on the syntax rules.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| const char *roiStr | Input ROI configuration string.|
| uint32_t *outCount | Returns the number of valid ROI regions parsed from the string.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AVErrCode | `AV_ERR_OK`: The operation is successful.<br> `AV_ERR_INVALID_VAL`: `roiStr` or `outCount` is NULL.|

### OH_VideoMetadata_ParseRoiString()

```c
OH_AVErrCode OH_VideoMetadata_ParseRoiString(const char *roiStr, OH_AVFormat **outOwnedFormats, uint32_t maxCapacity, uint32_t *outCount)
```

**Description**

Parses the ROI string and fills the OH_AVFormat array provided by the caller.

>**NOTE**
>The caller takes ownership of each successfully created OH_AVFormat handle. On return, the valid handles are stored in the first `outCount` elements of the `outOwnedFormats` array. - On complete or partial success (`outCount` > 0), the caller must destroy each valid handle using [OH_AVFormat_Destroy](./capi-native-avformat-h.md#oh_avformat_destroy) to prevent memory leaks. - On complete failure (`outCount` == 0), no handles are created, and no destruction is required.

**Since:** 26.0.0

**Parameters**

| Name| Description|
| -- | -- |
| const char *roiStr | Input ROI configuration string.|
| OH_AVFormat **outOwnedFormats | Pointer array allocated by the caller, which is used to receive the parsed OH_AVFormat handles. The caller owns each non-NULL handle in this array.|
| uint32_t maxCapacity | Indicates the maximum physical capacity of the `outOwnedFormats` array to prevent out-of-bounds writes.|
| uint32_t *outCount | Returns the actual number of ROIs that are successfully parsed and filled into the array.|

**Returns**

| Type| Description|
| -- | -- |
| OH_AVErrCode | `AV_ERR_OK`: The operation is successful.<br> `AV_ERR_INVALID_VAL`: `roiStr`, `outOwnedFormats`, or `outCount` is NULL.|
