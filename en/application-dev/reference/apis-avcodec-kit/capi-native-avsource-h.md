# native_avsource.h

## Overview

The file declares the APIs for parsing audio and video media data.

**File to include**: <multimedia/player_framework/native_avsource.h>

**Library**: libnative_media_avsource.so

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Related module**: [AVSource](capi-avsource.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name| typedef Keyword| Description|
| -- | -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) | OH_AVSource | Describes a native object for the media source interface.|

### Functions

| Name| Description|
| -- | -- |
| [OH_AVSource *OH_AVSource_CreateWithDataSource(OH_AVDataSource *dataSource)](#oh_avsource_createwithdatasource) | Creates an OH_AVSource instance with a user-defined data source. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy).|
| [OH_AVSource *OH_AVSource_CreateWithDataSourceExt(OH_AVDataSourceExt *dataSource, void *userData)](#oh_avsource_createwithdatasourceext) | Creates an OH_AVSource instance with a user-defined data source. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy). User-defined data can be passed to its callback functions.|
| [OH_AVSource *OH_AVSource_CreateWithURI(char *uri)](#oh_avsource_createwithuri) | Creates an OH_AVSource instance based on a URI. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy).|
| [OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size)](#oh_avsource_createwithfd) | Creates an OH_AVSource instance based on an FD. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy). Note: If **offset** is not the start position of the file or **size** is not the file size, undefined errors such as creation failure and demultiplexing failure may occur due to incomplete data obtained.|
| [OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source)](#oh_avsource_destroy) | Destroys an OH_AVSource instance and clears internal resources. Note: An instance can be destroyed only once. The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to NULL after the instance is destroyed.|
| [OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source)](#oh_avsource_getsourceformat) | Obtains the basic information about a media resource file. You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the OH_AVFormat instance when its lifecycle ends.|
| [OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackIndex)](#oh_avsource_gettrackformat) | Obtains the basic information about a track. You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the OH_AVFormat instance when its lifecycle ends.|
| [OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source)](#oh_avsource_getcustommetadataformat) | Obtains the basic information about custom metadata. You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the OH_AVFormat instance when its lifecycle ends.|

## Function Description

### OH_AVSource_CreateWithDataSource()

```
OH_AVSource *OH_AVSource_CreateWithDataSource(OH_AVDataSource *dataSource)
```

**Description**

Creates an OH_AVSource instance with a user-defined data source. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDataSource](capi-codecbase-oh-avdatasource.md) *dataSource | Pointer to user-defined data source.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to the OH_AVSource instance created. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **dataSource** is nullptr.<br>2. The size of the data source is 0.<br>3. Setting the data source fails.<br>4. The memory is insufficient.<br>5. The decoder engine is nullptr.<br>6. dataSource-&gt;readAt == nullptr.|

### OH_AVSource_CreateWithDataSourceExt()

```
OH_AVSource *OH_AVSource_CreateWithDataSourceExt(OH_AVDataSourceExt *dataSource, void *userData)
```

**Description**

Creates an OH_AVSource instance with a user-defined data source. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br>User-defined data can be passed to its callback functions through the **userData** parameter.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVDataSourceExt](capi-codecbase-oh-avdatasourceext.md) *dataSource | Pointer to the data source struct, which is used to obtain the input data.|
| void *userData | Pointer to user-defined data.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to the OH_AVSource instance created. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **dataSource** is nullptr.<br>2. The size of the data source is 0.<br>3. Setting the data source fails.<br>4. The memory is insufficient.<br>5. The decoder engine is nullptr.<br>6. dataSource-&gt;readAt == nullptr.|

### OH_AVSource_CreateWithURI()

```
OH_AVSource *OH_AVSource_CreateWithURI(char *uri)
```

**Description**

Creates an OH_AVSource instance based on a URI. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy).

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| char *uri | URI of the media resource.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to the OH_AVSource instance created. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The network is abnormal.<br>2. The resource is invalid.<br>3. The file format is not supported.|

### OH_AVSource_CreateWithFD()

```
OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size)
```

**Description**

Creates an OH_AVSource instance based on an FD. You can release the instance by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br>If **offset** is not the start position of the file or **size** is not the file size, undefined errors such as creation failure and demultiplexing failure may occur due to incomplete data obtained.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| int32_t fd | FD of a media resource file.|
| int64_t offset | Position from which data is to read.|
| int64_t size | File size, in bytes.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to the OH_AVSource instance created. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The FD is invalid.<br>2. The offset is not the start position of the file.<br>3. The size is incorrect.<br>4. The resource is invalid.<br>5. The file format is not supported.|

### OH_AVSource_Destroy()

```
OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source)
```

**Description**

Destroys an OH_AVSource instance and clears internal resources. An instance can be destroyed only once.<br>The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to NULL after the instance is destroyed.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to an OH_AVSource instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVErrCode](_core.md#oh_averrcode-1) | **AV_ERR_OK**: The operation is successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The value of **source** is nullptr.<br>2. The value of **source** does not point to an OH_AVSource instance.|

### OH_AVSource_GetSourceFormat()

```
OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source)
```

**Description**

Obtains the basic information about a media resource file.<br>You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the OH_AVFormat instance when its lifecycle ends.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to an OH_AVSource instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVFormat](_core.md#oh_avformat) * | Basic information about the file. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **source** is nullptr.<br>2. The pointer is null or does not point to an OH_AVSource instance.<br>3. The source is not initialized.|

### OH_AVSource_GetTrackFormat()

```
OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackIndex)
```

**Description**

Obtains the basic information about a track.<br>You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the OH_AVFormat instance when its lifecycle ends.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to an OH_AVSource instance.|
| uint32_t trackIndex | Index of the track whose information is to be obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVFormat](_core.md#oh_avformat) * | Basic information about the track. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **source** is invalid (either nullptr or a pointer to a non-OH_AVSource instance).<br>2. The track index is out of range.<br>3. The source is not initialized.|

### OH_AVSource_GetCustomMetadataFormat()

```
OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source)
```

**Description**

Obtains the basic information about custom metadata.<br>You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the OH_AVFormat instance when its lifecycle ends.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 18


**Parameters**

| Name| Description|
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to an OH_AVSource instance.|

**Returns**

| Type| Description|
| -- | -- |
| [OH_AVFormat](_core.md#oh_avformat) * | Basic information about the metadata. If the operation fails, NULL is returned.<br>The possible causes of an operation failure are as follows:<br>1. The value of **source** is nullptr.<br>2. The pointer is null or does not point to an OH_AVSource instance.<br>3. The source is not initialized.|
