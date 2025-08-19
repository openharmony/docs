# media_asset_capi.h

## Overview

The file declares the APIs related to media assets. You can use the APIs to obtain image or video information.

**Library**: libmedia_asset_manager.so

**File to include**: <multimedia/media_library/media_asset_capi.h>

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Since**: 12

**Related module**: [MediaAssetManager](capi-mediaassetmanager.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [MediaLibrary_ErrorCode OH_MediaAsset_GetUri(OH_MediaAsset* mediaAsset, const char** uri)](#oh_mediaasset_geturi) | Obtains the URI of a media asset.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetMediaType(OH_MediaAsset* mediaAsset, MediaLibrary_MediaType* mediaType)](#oh_mediaasset_getmediatype) | Obtains the type of a media asset.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetMediaSubType(OH_MediaAsset* mediaAsset,MediaLibrary_MediaSubType* mediaSubType)](#oh_mediaasset_getmediasubtype) | Obtains the subtype of a media asset.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetDisplayName(OH_MediaAsset* mediaAsset, const char** displayName)](#oh_mediaasset_getdisplayname) | Obtains the display name of a media asset.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetSize(OH_MediaAsset* mediaAsset, uint32_t* size)](#oh_mediaasset_getsize) | Obtains the size of a media asset file.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetDateAdded(OH_MediaAsset* mediaAsset, uint32_t* dateAdded)](#oh_mediaasset_getdateadded) | Obtains the date when a media asset was added.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetDateModified(OH_MediaAsset* mediaAsset, uint32_t* dateModified)](#oh_mediaasset_getdatemodified) | Obtains the date when a media asset was last modified.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetDateTaken(OH_MediaAsset* mediaAsset, uint32_t* dateTaken)](#oh_mediaasset_getdatetaken) | Obtains the date when a media asset was taken.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetDateAddedMs(OH_MediaAsset* mediaAsset, uint32_t* dateAddedMs)](#oh_mediaasset_getdateaddedms) | Obtains the date when a media asset was added, in ms.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetDateModifiedMs(OH_MediaAsset* mediaAsset, uint32_t* dateModifiedMs)](#oh_mediaasset_getdatemodifiedms) | Obtains the date when a media asset was last modified, in ms.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetDuration(OH_MediaAsset* mediaAsset, uint32_t* duration)](#oh_mediaasset_getduration) | Obtains the duration of a media asset, in ms.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetWidth(OH_MediaAsset* mediaAsset, uint32_t* width)](#oh_mediaasset_getwidth) | Obtains the image width (in pixels) of a media asset.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetHeight(OH_MediaAsset* mediaAsset, uint32_t* height)](#oh_mediaasset_getheight) | Obtains the image height (in pixels) of a media asset.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetOrientation(OH_MediaAsset* mediaAsset, uint32_t* orientation)](#oh_mediaasset_getorientation) | Obtains the orientation of a media asset, in degrees.|
| [MediaLibrary_ErrorCode OH_MediaAsset_IsFavorite(OH_MediaAsset* mediaAsset, uint32_t* favorite)](#oh_mediaasset_isfavorite) | Checks whether a media asset is favorited.|
| [MediaLibrary_ErrorCode OH_MediaAsset_GetTitle(OH_MediaAsset* mediaAsset, const char** title)](#oh_mediaasset_gettitle) | Obtains the title of a media asset.|
| [MediaLibrary_ErrorCode OH_MediaAsset_Release(OH_MediaAsset* mediaAsset)](#oh_mediaasset_release) | Releases a media asset.|

## Function Description

### OH_MediaAsset_GetUri()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetUri(OH_MediaAsset* mediaAsset, const char** uri)
```

**Description**

Obtains the URI of a media asset.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| const char** uri | Double pointer to the URI obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetMediaType()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaType(OH_MediaAsset* mediaAsset, MediaLibrary_MediaType* mediaType)
```

**Description**

Obtains the type of a media asset.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| [MediaLibrary_MediaType](capi-media-asset-base-capi-h.md#medialibrary_mediatype)* mediaType | Pointer to the media asset type obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetMediaSubType()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetMediaSubType(OH_MediaAsset* mediaAsset,MediaLibrary_MediaSubType* mediaSubType)
```

**Description**

Obtains the subtype of a media asset.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| [MediaLibrary_MediaSubType](capi-media-asset-base-capi-h.md#medialibrary_mediasubtype)* mediaSubType | Pointer to the media asset subtype obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetDisplayName()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDisplayName(OH_MediaAsset* mediaAsset, const char** displayName)
```

**Description**

Obtains the display name of a media asset.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| const char** displayName | Double pointer to the display name obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetSize()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetSize(OH_MediaAsset* mediaAsset, uint32_t* size)
```

**Description**

Obtains the size of a media asset file.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* size | Pointer to the file size obtained, in bytes.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetDateAdded()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateAdded(OH_MediaAsset* mediaAsset, uint32_t* dateAdded)
```

**Description**

Obtains the date when a media asset was added.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* dateAdded | Pointer to the date obtained. The value is the number of seconds elapsed since the Unix Epoch time (00:00:00 UTC on January 1, 1970).|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetDateModified()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModified(OH_MediaAsset* mediaAsset, uint32_t* dateModified)
```

**Description**

Obtains the date when a media asset (content not the media asset name) was last modified.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* dateModified | Pointer to the date obtained. The value is the number of milliseconds elapsed since the Unix Epoch time.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetDateTaken()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateTaken(OH_MediaAsset* mediaAsset, uint32_t* dateTaken)
```

**Description**

Obtains the date when a media asset was taken.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* dateTaken | Pointer to the date obtained. The value is the number of seconds elapsed since the Unix Epoch time.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetDateAddedMs()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateAddedMs(OH_MediaAsset* mediaAsset, uint32_t* dateAddedMs)
```

**Description**

Obtains the date when a media asset was added, in ms.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* dateAddedMs | Pointer to the date obtained, in ms. The value is the number of milliseconds elapsed since the Unix Epoch time.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetDateModifiedMs()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDateModifiedMs(OH_MediaAsset* mediaAsset, uint32_t* dateModifiedMs)
```

**Description**

Obtains the date when a media asset (content not the media asset name) was last modified, in ms.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* dateModifiedMs | Pointer to the date obtained, in ms. The value is the number of milliseconds elapsed since the Unix Epoch time.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetDuration()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetDuration(OH_MediaAsset* mediaAsset, uint32_t* duration)
```

**Description**

Obtains the duration of a media asset, in ms.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* duration | Pointer to the duration obtained, in ms.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetWidth()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetWidth(OH_MediaAsset* mediaAsset, uint32_t* width)
```

**Description**

Obtains the image width (in pixels) of a media asset.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* width | Pointer to the image width obtained, in pixels.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetHeight()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetHeight(OH_MediaAsset* mediaAsset, uint32_t* height)
```

**Description**

Obtains the image height (in pixels) of a media asset.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* height | Pointer to the image height obtained, in pixels.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetOrientation()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetOrientation(OH_MediaAsset* mediaAsset, uint32_t* orientation)
```

**Description**

Obtains the orientation of a media asset, in degrees.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* orientation | Pointer to the orientation of the image obtained, in degrees.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_IsFavorite()

```
MediaLibrary_ErrorCode OH_MediaAsset_IsFavorite(OH_MediaAsset* mediaAsset, uint32_t* favorite)
```

**Description**

Checks whether a media asset is favorited.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| uint32_t* favorite | Pointer to the favorite status obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_GetTitle()

```
MediaLibrary_ErrorCode OH_MediaAsset_GetTitle(OH_MediaAsset* mediaAsset, const char** title)
```

**Description**

Obtains the title of a media asset.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|
| const char** title | Pointer to the media asset title obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAsset_Release()

```
MediaLibrary_ErrorCode OH_MediaAsset_Release(OH_MediaAsset* mediaAsset)
```

**Description**

Releases a media asset.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.|
