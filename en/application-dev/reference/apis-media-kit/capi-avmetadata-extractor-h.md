# avmetadata_extractor.h

## Overview

The file declares the AVMetadataExtractor APIs. You can use the APIs to obtain metadata from media assets.

**Library**: libavmetadata_extractor.so

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Related module**: [AVMetadataExtractor](capi-avmetadataextractor.md)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md) | OH_AVMetadataExtractor | Describes the OH_AVMetadataExtractor.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVMetadataExtractor* OH_AVMetadataExtractor_Create(void)](#oh_avmetadataextractor_create) | Creates an OH_AVMetadataExtractor instance.|
| [OH_AVErrCode OH_AVMetadataExtractor_SetFDSource(OH_AVMetadataExtractor* extractor,int32_t fd, int64_t offset, int64_t size)](#oh_avmetadataextractor_setfdsource) | Sets a data source based on the media file descriptor.|
| [OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata)](#oh_avmetadataextractor_fetchmetadata) | Obtains metadata from a media asset. This function must be called after [OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource).|
| [OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap)](#oh_avmetadataextractor_fetchalbumcover) | Obtains the cover of an audio album. This function must be called after [OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource).|
| [OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor)](#oh_avmetadataextractor_release) | Releases the resources used by the OH_AVMetadataExtractor instance and destroys the instance.|

## Function Description

### OH_AVMetadataExtractor_Create()

```
OH_AVMetadataExtractor* OH_AVMetadataExtractor_Create(void)
```

**Description**

Creates an OH_AVMetadataExtractor instance.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* | Pointer to the OH_AVMetadataExtractor instance created if the operation is successful; nullptr otherwise.<br>         Possible cause of failures: **HstEngineFactory::CreateAVMetadataHelperEngine** fails to run.|

### OH_AVMetadataExtractor_SetFDSource()

```
OH_AVErrCode OH_AVMetadataExtractor_SetFDSource(OH_AVMetadataExtractor* extractor,int32_t fd, int64_t offset, int64_t size)
```

**Description**

Sets a data source based on the media file descriptor.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | Pointer to the OH_AVMetadataExtractor instance.|
| int32_t fd | File descriptor of the media source.|
| int64_t offset | Offset of the media source in the file descriptor.|
| int64_t size | Size of the media source.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **extractor** is nullptr or a parameter is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is forbidden.<br>**AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVMetadataExtractor_FetchMetadata()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchMetadata(OH_AVMetadataExtractor* extractor, OH_AVFormat* avMetadata)
```

**Description**

Obtains metadata from a media asset.

This function must be called after [OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource).

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | Pointer to the OH_AVMetadataExtractor instance.|
| [OH_AVFormat](../apis-avcodec-kit/_core.md#oh_avformat)* avMetadata | Pointer to the OH_AVFormat instance, which contains the obtained metadata.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **extractor** is nullptr or a parameter is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is forbidden.<br>**AV_ERR_UNSUPPORTED_FORMAT**: The format is not supported.<br>**AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVMetadataExtractor_FetchAlbumCover()

```
OH_AVErrCode OH_AVMetadataExtractor_FetchAlbumCover(OH_AVMetadataExtractor* extractor, OH_PixelmapNative** pixelMap)
```

**Description**

Obtains the cover of an audio album.

This function must be called after [OH_AVMetadataExtractor_SetFDSource](#oh_avmetadataextractor_setfdsource).

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | Pointer to the OH_AVMetadataExtractor instance.|
| [OH_PixelmapNative](../apis-image-kit/capi-image-nativemodule-oh-pixelmapnative.md** pixelMap | Double pointer to the album cover obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **extractor** is nullptr or a parameter is invalid.<br>**AV_ERR_OPERATE_NOT_PERMIT**: The operation is forbidden.<br>**AV_ERR_UNSUPPORTED_FORMAT**: The format is not supported.<br>**AV_ERR_NO_MEMORY**: Internal memory allocation failed.|

### OH_AVMetadataExtractor_Release()

```
OH_AVErrCode OH_AVMetadataExtractor_Release(OH_AVMetadataExtractor* extractor)
```

**Description**

Releases the resources used by the OH_AVMetadataExtractor instance and destroys the instance.

**System capability**: SystemCapability.Multimedia.Media.AVMetadataExtractor

**Since**: 18


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_AVMetadataExtractor](capi-avmetadaextractor-oh-avmetadataextractor.md)* extractor | Pointer to the OH_AVMetadataExtractor instance.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](../apis-avcodec-kit/_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**: The input parameter **extractor** is nullptr or a parameter is invalid.|
