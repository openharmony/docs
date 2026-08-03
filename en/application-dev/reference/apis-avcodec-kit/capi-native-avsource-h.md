# native_avsource.h

<!--Kit: AVCodec Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zhanghongran-->
<!--Designer: @dpy2650--->
<!--Tester: @cyakee-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=604a8dc842a12def692ac58e3e04542721ec7378 translatedAt=2026-08-01T07:27:14.215Z pushedAt=2026-08-01T09:09:28.283Z -->

## Overview

Declares the interfaces for parsing audio and video media data.

**File to include:** <multimedia/player_framework/native_avsource.h>

**Library:** libnative_media_avsource.so

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Related module:** [AVSource](capi-avsource.md)

**Sample**: [AVCodec](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/AVCodec)

## Summary

### Structs

| Name | typedef Keyword | Description |
| -- | -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) | OH_AVSource | Defines a native layer object for the media resource interface. |

### Function

| Name | Description |
| -- | -- |
| [OH_AVSource *OH_AVSource_CreateWithDataSource(OH_AVDataSource *dataSource)](#oh_avsource_createwithdatasource) | Creates an OH_AVSource instance for a resource object with a user-defined data source. The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br>The lifecycle of the dataSource parameter must be consistent with that of the returned pointer OH_AVSource *. |
| [OH_AVSource *OH_AVSource_CreateWithDataSourceExt(OH_AVDataSourceExt *dataSource, void *userData)](#oh_avsource_createwithdatasourceext) | Creates an OH_AVSource instance for a resource object with a user-defined data source. The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br> The callback supports passing user-defined data through userData.<br>The lifecycle of the dataSource parameter must be consistent with that of the returned pointer OH_AVSource *. |
| [OH_AVSource *OH_AVSource_CreateWithURI(char *uri)](#oh_avsource_createwithuri) | Creates an OH_AVSource instance for the resource object corresponding to a Uniform Resource Identifier. The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy). This API supports only HTTP progressive streaming, not HLS/DASH streaming. For HLS/DASH streaming playback, use the AVPlayer component. |
| [OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size)](#oh_avsource_createwithfd) | Creates an OH_AVSource instance for the resource object corresponding to a file descriptor. The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br> If the offset passed is not the start position of the file, or size is not the file size, undefined errors such as OH_AVSource creation failure or subsequent demuxing failure may occur due to incomplete data retrieval. |
| [OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source)](#oh_avsource_destroy) | Destroys an OH_AVSource instance and cleans up internal resources.<br> An instance can be destroyed only once. A destroyed instance cannot be used again until it is re-created. It is recommended to set the pointer to NULL after the instance is successfully destroyed. |
| [OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source)](#oh_avsource_getsourceformat) | Obtains the basic information of a media resource file.<br> Note that the OH_AVFormat instance pointed to must be released by the caller through [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) at the end of its lifecycle. |
| [OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackIndex)](#oh_avsource_gettrackformat) | Obtains the basic information of a track.<br> Note that the OH_AVFormat instance pointed to must be released by the caller through [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) at the end of its lifecycle. |
| [OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source)](#oh_avsource_getcustommetadataformat) | Obtains the basic information of custom metadata.<br> Note that the OH_AVFormat instance pointed to must be released by the developer through [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) at the end of its lifecycle. |

## Function Description

### OH_AVSource_CreateWithDataSource()

```c
OH_AVSource *OH_AVSource_CreateWithDataSource(OH_AVDataSource *dataSource)
```

**Description**

Creates an OH_AVSource instance for a resource object with a user-defined data source. The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br>The lifecycle of the dataSource parameter must be consistent with that of the returned OH_AVSource pointer.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVDataSource](capi-codecbase-oh-avdatasource.md) *dataSource | User-defined data source. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to the OH_AVSource instance if the operation is successful; NULL otherwise.<br> Possible causes of failure:<br> 1. dataSource is nullptr.<br> 2. dataSource->size == 0.<br> 3. Failed to set the data source.<br> 4. Insufficient memory.<br> 5. The decoder engine is nullptr.<br> 6. dataSource-&gt;readAt == nullptr. |

### OH_AVSource_CreateWithDataSourceExt()

```c
OH_AVSource *OH_AVSource_CreateWithDataSourceExt(OH_AVDataSourceExt *dataSource, void *userData)
```

**Description**

Creates an OH_AVSource instance for a resource object with a user-defined data source. The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br> The callback supports passing user-defined data through userData.<br> The lifecycle of the dataSource parameter must be consistent with that of the returned OH_AVSource pointer.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since:** 20

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVDataSourceExt](capi-codecbase-oh-avdatasourceext.md) *dataSource | Pointer to the data source struct, which is used to obtain input data. |
| void *userData | Pointer to the user-defined data. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to the OH_AVSource instance if the operation is successful; NULL otherwise.<br> Possible causes of failure:<br> 1. dataSource is nullptr.<br> 2. dataSource->size == 0.<br> 3. Failed to set the data source.<br> 4. Insufficient memory.<br> 5. The decoder engine is nullptr.<br> 6. dataSource-&gt;readAt is nullptr. |

### OH_AVSource_CreateWithURI()

```c
OH_AVSource *OH_AVSource_CreateWithURI(char *uri)
```

**Description**

Creates an OH_AVSource instance for the resource object corresponding to a Uniform Resource Identifier (URI). The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy). This API supports only HTTP progressive streaming, not HLS/DASH streaming. For HLS/DASH streaming playback, the AVPlayer component is recommended.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| char *uri | Uniform Resource Identifier (URI) of the remote media resource. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to an OH_AVSource instance if the operation is successful; NULL otherwise.<br> Possible causes of failure:<br> 1. Network exception.<br> 2. Invalid resource.<br> 3. Unsupported file format.<br> 4. Plaintext interception configured for the app. |

### OH_AVSource_CreateWithFD()

```c
OH_AVSource *OH_AVSource_CreateWithFD(int32_t fd, int64_t offset, int64_t size)
```

**Description**

Creates an OH_AVSource instance for the resource object corresponding to a file descriptor. The instance can be released by calling [OH_AVSource_Destroy](#oh_avsource_destroy).<br> When this API is called, if the offset passed in is not the start position of the file, or the size is not the file size, OH_AVSource creation or subsequent demuxing may fail due to incomplete data retrieval.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| int32_t fd | File descriptor of the data resource. |
| int64_t offset | Position to start reading data, in bytes. |
| int64_t size | File size in bytes, indicating the length of data that can be read starting from the position specified by **offset**. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) * | Pointer to an OH_AVSource instance if the operation is successful; NULL otherwise.<br> Possible failure causes:<br> 1. **fd** is invalid.<br> 2. **offset** passed in is not the start position of the file.<br> 3. **size** is incorrect.<br> 4. The resource is invalid.<br> 5. The file format is not supported. |

### OH_AVSource_Destroy()

```c
OH_AVErrCode OH_AVSource_Destroy(OH_AVSource *source)
```

**Description**

Destroys an OH_AVSource instance and clears internal resources. An instance can be destroyed only once. A destroyed instance cannot be used again until it is re-created. It is recommended that the pointer be set to NULL after the instance is successfully destroyed.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to the OH_AVSource instance. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVErrCode](capi-native-averrors-h.md#oh_averrcode) | Result code.<br>**AV_ERR_OK**: operation successful.<br>**AV_ERR_INVALID_VAL**:<br>1. The **source** pointer is invalid (null pointer).<br>2. Not an OH_AVSource instance. |

### OH_AVSource_GetSourceFormat()

```c
OH_AVFormat *OH_AVSource_GetSourceFormat(OH_AVSource *source)
```

**Description**

Obtains the basic information of a media source file.<br>Note that the OH_AVFormat instance pointed to must be released by the caller through [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) at the end of its lifecycle.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to the OH_AVSource instance. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | Pointer to the basic information of the file if the operation is successful; returns NULL otherwise.<br>Possible failure causes:<br>1. The source pointer is invalid.<br>2. Null pointer or non-OH_AVSource instance.<br>3. The source is not initialized. |

### OH_AVSource_GetTrackFormat()

```c
OH_AVFormat *OH_AVSource_GetTrackFormat(OH_AVSource *source, uint32_t trackIndex)
```

**Description**

Obtains the basic information of a track.<br> Note that the caller must release the OH_AVFormat instance pointed to by calling [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) at the end of its lifecycle.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to the OH_AVSource instance. |
| uint32_t trackIndex | Index of the track whose information is to be obtained. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | Basic information of the track if the operation is successful; NULL otherwise.<br> Possible causes of failure:<br> 1. The source pointer is invalid, is a null pointer, or is not an OH_AVSource instance.<br> 2. The track index is out of range.<br> 3. The source is not initialized. |

### OH_AVSource_GetCustomMetadataFormat()

```c
OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source)
```

**Description**

Obtains the basic information of custom metadata.<br> Note that the caller must release the OH_AVFormat instance pointed to by calling [OH_AVFormat_Destroy](capi-native-avformat-h.md#oh_avformat_destroy) when its lifecycle ends.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 18

**Parameters**

| Name | Description |
| -- | -- |
| [OH_AVSource](capi-avsource-oh-avsource.md) *source | Pointer to the OH_AVSource instance. |

**Returns**

| Type | Description |
| -- | -- |
| [OH_AVFormat](capi-core-oh-avformat.md) * | Basic information of the metadata if the operation is successful; NULL otherwise.<br> Possible fault causes:<br> 1. The source pointer is invalid.<br> 2. Null pointer or non-OH_AVSource instance.<br> 3. The source is not initialized. |