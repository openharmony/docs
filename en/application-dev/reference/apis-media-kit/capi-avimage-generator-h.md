# avimage_generator.h

## Overview

The **avimage_generator.h** file declares the AVImageGenerator APIs. You can use the APIs to extract video frames at given time points from videos.

**Library**: libavimage_generator.so

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

**Related module**: [AVImageGenerator](capi-avimagegenerator.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md) | OH_AVImageGenerator | Defines the type used for generating video frames at given time points.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVImageGenerator* OH_AVImageGenerator_Create(void)](#oh_avimagegenerator_create) | Creates an **OH_AVImageGenerator** instance, which is used to generate video frames at given time points.|
| [OH_AVErrCode OH_AVImageGenerator_SetFDSource(OH_AVImageGenerator* generator,int32_t fd, int64_t offset, int64_t size)](#oh_avimagegenerator_setfdsource) | Sets a data source based on the media file descriptor.|
| [OH_AVErrCode OH_AVImageGenerator_FetchFrameByTime(OH_AVImageGenerator* generator,int64_t timeUs, OH_AVImageGenerator_QueryOptions options, OH_PixelmapNative** pixelMap)](#oh_avimagegenerator_fetchframebytime) | Extracts a video frame at a given time from a video.<br>This function must be called after [OH_AVImageGenerator_SetFDSource](#oh_avimagegenerator_setfdsource).|
| [OH_AVErrCode OH_AVImageGenerator_Release(OH_AVImageGenerator* generator)](#oh_avimagegenerator_release) | Releases the resources used by the **OH_AVImageGenerator** instance and destroys the instance.|

## Function Description

### OH_AVImageGenerator_Create()

```
OH_AVImageGenerator* OH_AVImageGenerator_Create(void)
```

**Description**

Creates an **OH_AVImageGenerator** instance, which is used to generate video frames at given time points.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md)* | Pointer to the **OH_AVImageGenerator** instance created if the operation is successful; a null pointer otherwise.<br>         Possible cause of failures: HstEngineFactory fails to create an AVMetadataHelperEngine.|

### OH_AVImageGenerator_SetFDSource()

```
OH_AVErrCode OH_AVImageGenerator_SetFDSource(OH_AVImageGenerator* generator,int32_t fd, int64_t offset, int64_t size)
```

**Description**

Sets a data source based on the media file descriptor.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md)* generator | Pointer to the **OH_AVImageGenerator** instance.|
| int32_t fd | File descriptor of the media source.|
| int64_t offset | Offset of the media source in the file descriptor.|
| int64_t size | Size of the media source.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The input parameter **generator** is a null pointer or a parameter is invalid.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is forbidden.<br>         **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVImageGenerator_FetchFrameByTime()

```
OH_AVErrCode OH_AVImageGenerator_FetchFrameByTime(OH_AVImageGenerator* generator,int64_t timeUs, OH_AVImageGenerator_QueryOptions options, OH_PixelmapNative** pixelMap)
```

**Description**

Extracts a video frame at a given time from a video.

This function must be called after [OH_AVImageGenerator_SetFDSource](#oh_avimagegenerator_setfdsource).

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md)* generator | Pointer to the **OH_AVImageGenerator** instance.|
| int64_t timeUs | Time point of the video frame to be extracted in the video, in μs.|
| [OH_AVImageGenerator_QueryOptions](capi-avimage-generator-base-h.md#oh_avimagegenerator_queryoptions) options | Mappings between the given time points and video frames.|
| [OH_PixelmapNative](../apis-image-kit/_image___native_module.md#oh_pixelmapnative)** pixelMap | Double pointer to the video frame object obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The input parameter **generator** is a null pointer or a parameter is invalid.<br>         **AV_ERR_OPERATE_NOT_PERMIT**: The operation is forbidden.<br>         **AV_ERR_UNSUPPORTED_FORMAT**: The format is not supported.<br>         **AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVImageGenerator_Release()

```
OH_AVErrCode OH_AVImageGenerator_Release(OH_AVImageGenerator* generator)
```

**Description**

Releases the resources used by the **OH_AVImageGenerator** instance and destroys the instance.

**System capability**: SystemCapability.Multimedia.Media.AVImageGenerator

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVImageGenerator](capi-oh-avimagegenerator.md)* generator | Pointer to the **OH_AVImageGenerator** instance.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>         **AV_ERR_INVALID_VAL**: The input parameter **generator** is a null pointer or a parameter is invalid.|
