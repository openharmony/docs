# AVImageGenerator


## Overview

The AVImageGenerator module provides the APIs for extracting video frames at given time points from videos.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [avimage_generator.h](avimage__generator_8h.md) | Declares the AVImageGenerator APIs. With these native APIs, you can extract video frames at given time points from videos. |
| [avimage_generator_base.h](avimage__generator__base_8h.md) | Declares the enums used by the AVImageGenerator. |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_AVImageGenerator](#oh_avimagegenerator) [OH_AVImageGenerator](#oh_avimagegenerator) | Defines a struct for the OH_AVImageGenerator. |
| typedef enum [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions-1) [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions) | Defines an enum for the mappings between time points and video frames. |


### Enums

| Name| Description|
| -------- | -------- |
| [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions-1) {<br> OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC = 0,<br>  OH_AVIMAGE_GENERATOR_QUERY_PREVIOUS_SYNC = 1, <br> OH_AVIMAGE_GENERATOR_QUERY_CLOSEST_SYNC = 2, <br> OH_AVIMAGE_GENERATOR_QUERY_CLOSEST = 3 } | Enumerates the mappings between time points and video frames. |


### Functions

| Name| Description|
| -------- | -------- |
| [OH_AVImageGenerator](#oh_avimagegenerator) \* [OH_AVImageGenerator_Create](#oh_avimagegenerator_create) (void) | Creates an **OH_AVImageGenerator** instance. |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_SetFDSource](#oh_avimagegenerator_setfdsource) ([OH_AVImageGenerator](#oh_avimagegenerator) \*generator, int32_t fd, int64_t offset, int64_t size) | Sets a data source based on the media file descriptor. |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_FetchFrameByTime](#oh_avimagegenerator_fetchframebytime) ([OH_AVImageGenerator](#oh_avimagegenerator) \*generator, int64_t timeUs, [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions) options, OH_PixelmapNative \*\*pixelMap) | Extracts a video frame at a given time from a video. |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode) [OH_AVImageGenerator_Release](#oh_avimagegenerator_release) ([OH_AVImageGenerator](#oh_avimagegenerator) \*generator) | Releases the resources used by the **OH_AVImageGenerator** instance and destroys the instance. |


## Type Description


### OH_AVImageGenerator

```
typedef struct OH_AVImageGenerator OH_AVImageGenerator
```
**Description**

Defines a struct for the OH_AVImageGenerator.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18


### OH_AVImageGenerator_QueryOptions

```
typedef enum OH_AVImageGenerator_QueryOptions OH_AVImageGenerator_QueryOptions
```
**Description**

Defines an enum for the mappings between time points and video frames.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18


## Enum Description


### OH_AVImageGenerator_QueryOptions

```
enum OH_AVImageGenerator_QueryOptions
```
**Description**

Enumerates the mappings between time points and video frames.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

| Value| Description|
| -------- | -------- |
| OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC  | Extracts the key frame at or next to the specified time.  |
| OH_AVIMAGE_GENERATOR_QUERY_PREVIOUS_SYNC  | Extracts the key frame at or prior to the specified time.  |
| OH_AVIMAGE_GENERATOR_QUERY_CLOSEST_SYNC  | Extracts the key frame closest to the specified time.  |
| OH_AVIMAGE_GENERATOR_QUERY_CLOSEST  | Extracts the frame (not necessarily a key frame) closest to the specified time.  |


## Function Description


### OH_AVImageGenerator_Create()

```
OH_AVImageGenerator* OH_AVImageGenerator_Create(void)
```
**Description**

Creates an **OH_AVImageGenerator** instance.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

**Returns**

Returns the pointer to the **OH_AVImageGenerator** instance created if the operation is successful; returns a null pointer otherwise.

Possible cause of failures: HstEngineFactory fails to create an AVMetadataHelperEngine.


### OH_AVImageGenerator_FetchFrameByTime()

```
OH_AVErrCode OH_AVImageGenerator_FetchFrameByTime(OH_AVImageGenerator* generator, int64_t timeUs, OH_AVImageGenerator_QueryOptions options, OH_PixelmapNative** pixelMap)
```
**Description**

Extracts a video frame at a given time from a video.

This function must be called after [SetFDSource](#oh_avimagegenerator_setfdsource).

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Parameters**

| Name| Description|
| -------- | -------- |
| generator | Pointer to an **OH_AVImageGenerator** instance. |
| timeUs | Time point of the video frame to be extracted in the video, in μs. |
| options | Mappings between the given time points and video frames. For details, see [OH_AVImageGenerator_QueryOptions](#oh_avimagegenerator_queryoptions-1). |
| pixelMap | Double pointer to the video frame object obtained. For details, see {@link OH_PixelmapNative}. |

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **generator** is a null pointer or an input parameter is invalid.

**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.

**AV_ERR_UNSUPPORTED_FORMAT**: The format is not supported.

**AV_ERR_NO_MEMORY**: Internal memory allocation failed.

### OH_AVImageGenerator_Release()

```
OH_AVErrCode OH_AVImageGenerator_Release(OH_AVImageGenerator* generator)
```
**Description**

Releases the resources used by the **OH_AVImageGenerator** instance and destroys the instance.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| generator | Pointer to an **OH_AVImageGenerator** instance. |

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **generator** is a null pointer or an input parameter is invalid.


### OH_AVImageGenerator_SetFDSource()

```
OH_AVErrCode OH_AVImageGenerator_SetFDSource(OH_AVImageGenerator* generator, int32_t fd, int64_t offset, int64_t size)
```
**Description**

Sets a data source based on the media file descriptor.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

**Parameters**

| Name| Description|
| -------- | -------- |
| generator | Pointer to an **OH_AVImageGenerator** instance. |
| fd | File descriptor of the media source. |
| offset | Offset of the media source in the file descriptor. |
| size | Size of the media source. |

**Returns**

Returns a result code defined in [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1). The following result codes are possible:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The input parameter **generator** is a null pointer or an input parameter is invalid.

**AV_ERR_OPERATE_NOT_PERMIT**: The operation is not allowed.

**AV_ERR_NO_MEMORY**: Internal memory allocation failed.
