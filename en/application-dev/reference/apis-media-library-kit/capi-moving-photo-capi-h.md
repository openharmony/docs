# moving_photo_capi.h

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the APIs related to moving photos. You can use the APIs to obtain moving photo information.

**Library**: libmedia_asset_manager.so

**File to include**: <multimedia/media_library/moving_photo_capi.h>

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Since**: 13

**Related module**: [MediaAssetManager](capi-mediaassetmanager.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [MediaLibrary_ErrorCode OH_MovingPhoto_GetUri(OH_MovingPhoto* movingPhoto, const char** uri)](#oh_movingphoto_geturi) | Obtains the URI of a moving photo.|
| [MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUris(OH_MovingPhoto* movingPhoto, char* imageUri, char* videoUri)](#oh_movingphoto_requestcontentwithuris) | Requests the image data and video data of a moving photo and writes them to the specified URIs, respectively.|
| [MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUri(OH_MovingPhoto* movingPhoto, MediaLibrary_ResourceType resourceType, char* uri)](#oh_movingphoto_requestcontentwithuri) | Requests the moving photo content of the specified resource type and writes it to the specified URI.|
| [MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithBuffer(OH_MovingPhoto* movingPhoto, MediaLibrary_ResourceType resourceType, const uint8_t** buffer, uint32_t* size)](#oh_movingphoto_requestcontentwithbuffer) | Requests the moving photo content of the specified resource type and returns it in ArrayBuffer format.|
| [MediaLibrary_ErrorCode OH_MovingPhoto_Release(OH_MovingPhoto* movingPhoto)](#oh_movingphoto_release) | Releases an [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance.|

## Function Description

### OH_MovingPhoto_GetUri()

```
MediaLibrary_ErrorCode OH_MovingPhoto_GetUri(OH_MovingPhoto* movingPhoto, const char** uri)
```

**Description**

Obtains the URI of a moving photo.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md)* movingPhoto | Pointer to an [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance.|
| const char** uri | Double pointer to the URI of the moving photo obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MovingPhoto_RequestContentWithUris()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUris(OH_MovingPhoto* movingPhoto, char* imageUri,char* videoUri)
```

**Description**

Requests the image data and video data of a moving photo and writes them to the specified URIs, respectively.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md)* movingPhoto | Pointer to an [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance.|
| char* imageUri | Pointer to the URI of the file, to which the image data is written.|
| char* videoUri | Pointer to the URI of the file, to which the video data is written.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.<br>**MEDIA_LIBRARY_PERMISSION_DENIED**: no access permission.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error. |

### OH_MovingPhoto_RequestContentWithUri()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithUri(OH_MovingPhoto* movingPhoto,MediaLibrary_ResourceType resourceType, char* uri)
```

**Description**

Requests the moving photo content of the specified resource type and writes it to the specified URI.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md)* movingPhoto | Pointer to an [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance.|
| [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype) resourceType | Resource type, which is specified by [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype).|
| char* uri | Pointer to the URI of the file, to which the data is written.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.<br>**MEDIA_LIBRARY_PERMISSION_DENIED**: no access permission.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error. |

### OH_MovingPhoto_RequestContentWithBuffer()

```
MediaLibrary_ErrorCode OH_MovingPhoto_RequestContentWithBuffer(OH_MovingPhoto* movingPhoto,MediaLibrary_ResourceType resourceType, const uint8_t** buffer, uint32_t* size)
```

**Description**

Requests the moving photo content of the specified resource type and returns it in ArrayBuffer format.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md)* movingPhoto | Pointer to an [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance.|
| [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype) resourceType | Resource type, which is specified by [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype).|
| const uint8_t** buffer | Double pointer to the buffer for storing the target file data.|
| uint32_t* size | Pointer to the buffer size.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.<br>**MEDIA_LIBRARY_PERMISSION_DENIED**: no access permission.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MovingPhoto_Release()

```
MediaLibrary_ErrorCode OH_MovingPhoto_Release(OH_MovingPhoto* movingPhoto)
```

**Description**

Releases an [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md)* movingPhoto | Pointer to an [OH_MovingPhoto](capi-mediaassetmanager-oh-movingphoto.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.|
