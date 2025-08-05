# media_asset_change_request_capi.h

## Overview

The file declares the APIs related to media asset change requests. You can use the APIs to change media assets.

**Library**: libmedia_asset_manager.so

**File to include**: <multimedia/media_library/media_asset_change_request_capi.h>

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Since**: 12

**Related module**: [MediaAssetManager](capi-mediaassetmanager.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest* OH_MediaAssetChangeRequest_Create(OH_MediaAsset* mediaAsset)](#oh_mediaassetchangerequest_create) | Creates an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|
| [MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithUri(OH_MediaAssetChangeRequest* changeRequest,MediaLibrary_ResourceType resourceType, char* fileUri)](#oh_mediaassetchangerequest_addresourcewithuri) | Adds a resource of the given URI.|
| [MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithBuffer(OH_MediaAssetChangeRequest* changeRequest,MediaLibrary_ResourceType resourceType, uint8_t* buffer, uint32_t length)](#oh_mediaassetchangerequest_addresourcewithbuffer) | Adds a resource using ArrayBuffer data.|
| [MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_GetWriteCacheHandler(OH_MediaAssetChangeRequest* changeRequest,int32_t* fd)](#oh_mediaassetchangerequest_getwritecachehandler) | Obtains the handler used for writing a file to cache.|
| [MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_SaveCameraPhoto(OH_MediaAssetChangeRequest* changeRequest,MediaLibrary_ImageFileType imageFileType)](#oh_mediaassetchangerequest_savecameraphoto) | Saves the photo taken by the camera.|
| [MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_DiscardCameraPhoto(OH_MediaAssetChangeRequest* changeRequest)](#oh_mediaassetchangerequest_discardcameraphoto) | Discards the photo taken by the camera.|
| [MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_Release(OH_MediaAssetChangeRequest* changeRequest)](#oh_mediaassetchangerequest_release) | Releases an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|

## Function Description

### OH_MediaAssetChangeRequest_Create()

```
OH_MediaAssetChangeRequest* OH_MediaAssetChangeRequest_Create(OH_MediaAsset* mediaAsset)
```

**Description**

Creates an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to an [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAssetChangeRequest_AddResourceWithUri()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithUri(OH_MediaAssetChangeRequest* changeRequest,MediaLibrary_ResourceType resourceType, char* fileUri)
```

**Description**

Adds a resource of the given URI.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* changeRequest | Pointer to an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|
| [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype) resourceType | Type of the resource to add, which is specified by [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype).|
| char* fileUri | Pointer to the URI of the file.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_NO_SUCH_FILE**: The file does not exist.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.<br>**MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: unsupported operation.|

### OH_MediaAssetChangeRequest_AddResourceWithBuffer()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_AddResourceWithBuffer(OH_MediaAssetChangeRequest* changeRequest,MediaLibrary_ResourceType resourceType, uint8_t* buffer, uint32_t length)
```

**Description**

Adds a resource using ArrayBuffer data.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* changeRequest | Pointer to an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|
| [MediaLibrary_ResourceType](capi-media-asset-base-capi-h.md#medialibrary_resourcetype) resourceType | Type of the resource to add.|
| uint8_t* buffer | Pointer to the data buffer.|
| uint32_t length | Length of the data buffer.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.<br>**MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: unsupported operation.|

### OH_MediaAssetChangeRequest_GetWriteCacheHandler()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_GetWriteCacheHandler(OH_MediaAssetChangeRequest* changeRequest,int32_t* fd)
```

**Description**

Obtains the handler used for writing a file to cache.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* changeRequest | Pointer to an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|
| int32_t* fd | Pointer to the file descriptor (FD) obtained.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.<br>**MEDIA_LIBRARY_PERMISSION_DENIED**: no access permission.<br>**MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: unsupported operation.|

### OH_MediaAssetChangeRequest_SaveCameraPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_SaveCameraPhoto(OH_MediaAssetChangeRequest* changeRequest,MediaLibrary_ImageFileType imageFileType)
```

**Description**

Saves the photo taken by the camera.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* changeRequest | Pointer to an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|
| [MediaLibrary_ImageFileType](capi-media-asset-base-capi-h.md#medialibrary_imagefiletype) imageFileType | Type of the image file of the photo.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.<br>**MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: unsupported operation.|

### OH_MediaAssetChangeRequest_DiscardCameraPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_DiscardCameraPhoto(OH_MediaAssetChangeRequest* changeRequest)
```

**Description**

Discards the photo taken by the camera.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* changeRequest | Pointer to an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.<br>**MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: unsupported operation.|

### OH_MediaAssetChangeRequest_Release()

```
MediaLibrary_ErrorCode OH_MediaAssetChangeRequest_Release(OH_MediaAssetChangeRequest* changeRequest)
```

**Description**

Releases an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* changeRequest | Pointer to an [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.|
