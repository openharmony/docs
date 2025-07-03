# AVSource


## Overview

The AVSource module provides the functions for constructing media resource objects.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10


## Summary


### Files

| Name| Description| 
| -------- | -------- |
| [native_avsource.h](native__avsource_8h.md) | Declares the APIs for parsing audio and video media data. | 


### Types

| Name| Description| 
| -------- | -------- |
| typedef struct [OH_AVSource](#oh_avsource) [OH_AVSource](#oh_avsource) | Defines a struct that describes a native object for the media resource interface. | 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_AVSource](#oh_avsource) \* [OH_AVSource_CreateWithDataSource](#oh_avsource_createwithdatasource) ([OH_AVDataSource](_o_h___a_v_data_source.md) \*dataSource) | Creates an **OH_AVSource** instance with a user-defined data source. You can release the instance by calling **OH_AVSource_Destroy**. |
| [OH_AVSource](#oh_avsource) \* [OH_AVSource_CreateWithURI](#oh_avsource_createwithuri) (char \*uri) | Creates an **OH_AVSource** instance based on a URI. | 
| [OH_AVSource](#oh_avsource) \* [OH_AVSource_CreateWithFD](#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | Creates an **OH_AVSource** instance based on a file descriptor (FD). | 
| [OH_AVErrCode](_core.md#oh_averrcode) [OH_AVSource_Destroy](#oh_avsource_destroy) ([OH_AVSource](#oh_avsource) \*source) | Destroys an **OH_AVSource** instance and clears internal resources. | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetSourceFormat](#oh_avsource_getsourceformat) ([OH_AVSource](#oh_avsource) \*source) | Obtains the basic information about a media resource file. | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetTrackFormat](#oh_avsource_gettrackformat) ([OH_AVSource](#oh_avsource) \*source, uint32_t trackIndex) | Obtains the basic information about a track. | 
| [OH_AVFormat](_core.md#oh_avformat) \* [OH_AVSource_GetCustomMetadataFormat](#oh_avsource_getcustommetadataformat) ([OH_AVSource](#oh_avsource) \*source) | Obtains the basic information about custom metadata.| 


## Type Description


### OH_AVSource

```
typedef struct OH_AVSource OH_AVSource
```

**Description**

Defines a struct that describes a native object for the media resource interface.

**Since**: 10


## Function Description


### OH_AVSource_CreateWithDataSource()

```
OH_AVSource* OH_AVSource_CreateWithDataSource (OH_AVDataSource * dataSource)
```

**Description**

Creates an **OH_AVSource** instance with a user-defined data source. You can release the instance by calling **OH_AVSource_Destroy**.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| dataSource | User-defined data source. | 

**Returns**

Returns the pointer to the **OH_AVSource** instance created if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The value of **dataSource** is a null pointer.

2. The size of the data source is 0.

3. Setting the data source fails.

4. The memory is insufficient.

5. The decoder engine is a null pointer.
6. dataSource-&gt;readAt == nullptr.


### OH_AVSource_CreateWithFD()

```
OH_AVSource* OH_AVSource_CreateWithFD (int32_t fd, int64_t offset, int64_t size)
```

**Description**

Creates an **OH_AVSource** instance based on an FD.

You can release the instance by calling **OH_AVSource_Destroy**.

If **offset** is not the start position of the file or **size** is not the file size, undefined errors such as creation failure and demultiplexing failure may occur due to incomplete data obtained.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| fd | FD of a media resource file. | 
| offset | Position from which data is to read. | 
| size | File size, in bytes. | 

**Returns**

Returns the pointer to the **OH_AVSource** instance created if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The FD is invalid.

2. The offset is not the start position of the file.

3. The size is incorrect.

4. The resource is invalid.

5. The file format is not supported.


### OH_AVSource_CreateWithURI()

```
OH_AVSource* OH_AVSource_CreateWithURI (char *uri)
```

**Description**

Create an **OH_AVSource** instance based on a URI. You can release the instance by calling **OH_AVSource_Destroy**.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| uri | URI of the media resource. | 

**Returns**

Returns the pointer to the **OH_AVSource** instance created if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The network is abnormal.

2. The resource is invalid.

3. The file format is not supported.


### OH_AVSource_Destroy()

```
OH_AVErrCode OH_AVSource_Destroy (OH_AVSource *source)
```

**Description**

Destroys an **OH_AVSource** instance and clears internal resources.

An instance can be destroyed only once. The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to **NULL** after the instance is destroyed.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance. | 

**Returns**

Returns either of the following result codes:

**AV_ERR_OK**: The operation is successful.

**AV_ERR_INVALID_VAL**: The operation fails.
    
    1. The source pointer is invalid.
    2. The pointer is null or does not point to an **OH_AVSource** instance.


### OH_AVSource_GetCustomMetadataFormat()

```
OH_AVFormat *OH_AVSource_GetCustomMetadataFormat(OH_AVSource *source)
```

**Description**

Obtains the basic information about custom metadata.

You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the **OH_AVFormat** instance when its lifecycle ends.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 18

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance.| 

**Returns**

Returns the basic information about the metadata if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The source pointer is invalid.
2. The pointer is null or does not point to an **OH_AVSource** instance.
3. The source is not initialized.


### OH_AVSource_GetSourceFormat()

```
OH_AVFormat* OH_AVSource_GetSourceFormat (OH_AVSource *source)
```

**Description**

Obtains the basic information about a media resource file.

You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the **OH_AVFormat** instance when its lifecycle ends.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance. | 

**Returns**

Returns the basic information about the file if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The source pointer is invalid.
2. The pointer is null or does not point to an **OH_AVSource** instance.
3. The source is not initialized.


### OH_AVSource_GetTrackFormat()

```
OH_AVFormat* OH_AVSource_GetTrackFormat (OH_AVSource *source, uint32_t trackIndex)
```

**Description**

Obtains the basic information about a track.

You must call [OH_AVFormat_Destroy](_core.md#oh_avformat_destroy) to release the **OH_AVFormat** instance when its lifecycle ends.

**System capability**: SystemCapability.Multimedia.Media.Spliter

**Since**: 10

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance. | 
| trackIndex | Index of the track whose information is to be obtained. | 

**Returns**

Returns the basic information about the track if the operation is successful; returns NULL otherwise.

The possible causes of an operation failure are as follows:

1. The value of **source** is invalid (either a null pointer or a pointer to a non-OH_AVSource instance).
2. The track index is out of range.
3. The source is not initialized.
