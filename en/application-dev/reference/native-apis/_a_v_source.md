# AVSource


## Overview

The AVSource module provides functions for constructing audio and video resource objects.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Since**

10


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [native_avsource.h](native__avsource_8h.md) | Declares the native APIs used to construct audio and video resource objects.<br>**File to include**: <multimedia/player_framework/native_avsource.h><br>**Library**: libnative_media_avsource.so| 


### Functions

| Name| Description| 
| -------- | -------- |
| \*[OH_AVSource_CreateWithURI](#oh_avsource_createwithuri) (char \*uri) | Creates an **OH_AVSource** instance based on a URI.| 
| \*[OH_AVSource_CreateWithFD](#oh_avsource_createwithfd) (int32_t fd, int64_t offset, int64_t size) | Creates an **OH_AVSource** instance based on a file descriptor (FD).| 
| [OH_AVSource_Destroy](#oh_avsource_destroy) (OH_AVSource \*source) | Destroys an **OH_AVSource** instance and clears internal resources. An instance can be destroyed only once.| 
| \*[OH_AVSource_GetSourceFormat](#oh_avsource_getsourceformat) (OH_AVSource \*source) | Obtains the basic information about a media resource.| 
| \*[OH_AVSource_GetTrackFormat](#oh_avsource_gettrackformat) (OH_AVSource \*source, uint32_t trackIndex) | Obtains the basic information about a track.| 


## Function Description


### OH_AVSource_CreateWithFD()

  
```
OH_AVSource* OH_AVSource_CreateWithFD (int32_t fd, int64_t offset, int64_t size)
```

**Description**

Creates an **OH_AVSource** instance based on an FD.

You can release the instance by calling **OH_AVSource_Destroy**.

If **offset** is not the start position of the file or **size** is not the file size, undefined errors such as creation failure and decapsulation failure may occur due to incomplete data obtained.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| fd | FD of a media resource file.| 
| offset | Position from which data is to read.| 
| size | File size, in bytes.| 

**Returns**

Returns the pointer to an **OH_AVSource** instance.

**Since**

10


### OH_AVSource_CreateWithURI()

  
```
OH_AVSource* OH_AVSource_CreateWithURI (char *uri)
```

**Description**

Create an **OH_AVSource** instance object based on a URI. You can release the instance by calling **OH_AVSource_Destroy**.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| uri | URI of the media resource.| 

**Returns**

Returns the pointer to an **OH_AVSource** instance.

**Since**

10


### OH_AVSource_Destroy()

  
```
OH_AVErrCode OH_AVSource_Destroy (OH_AVSource *source)
```

**Description**

Destroys an **OH_AVSource** instance and clears internal resources.

An instance can be destroyed only once.

The destroyed instance cannot be used until it is re-created. You are advised to set the pointer to **NULL** after the instance is destroyed.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance.| 

**Returns**

Returns **AV_ERR_OK** if the operation is successful; returns an error code defined in [OH_AVErrCode](_core.md#oh_averrcode) otherwise.

**Since**

10


### OH_AVSource_GetSourceFormat()

  
```
OH_AVFormat* OH_AVSource_GetSourceFormat (OH_AVSource *source)
```

**Description**

Obtains the basic information about a media resource.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance.| 

**Returns**

Returns the basic information obtained.

**Since**

10


### OH_AVSource_GetTrackFormat()

  
```
OH_AVFormat* OH_AVSource_GetTrackFormat (OH_AVSource *source, uint32_t trackIndex)
```

**Description**

Obtains the basic information about a track.

\@syscap SystemCapability.Multimedia.Media.Spliter

**Parameters**

| Name| Description| 
| -------- | -------- |
| source | Pointer to an **OH_AVSource** instance.| 
| trackIndex | Index of the track whose information is to be obtained.| 

**Returns**

Returns the basic information obtained.

**Since**

10
