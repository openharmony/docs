# media_asset_manager_capi.h

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

## Overview

The file declares the APIs of the media asset manager. You can use the functions to request media assets in the media library.

**Library**: libmedia_asset_manager.so

**File to include**: <multimedia/media_library/media_asset_manager_capi.h>

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Since**: 12

**Related module**: [MediaAssetManager](capi-mediaassetmanager.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [OH_MediaAssetManager* OH_MediaAssetManager_Create(void)](#oh_mediaassetmanager_create) | Creates an OH_MediaAssetManager instance.|
| [MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath(OH_MediaAssetManager* manager, const char* uri, MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)](#oh_mediaassetmanager_requestimageforpath) | Requests an image in the specified directory.|
| [MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath(OH_MediaAssetManager* manager, const char* uri, MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)](#oh_mediaassetmanager_requestvideoforpath) | Requests a video in the specified directory.|
| [bool OH_MediaAssetManager_CancelRequest(OH_MediaAssetManager* manager, const MediaLibrary_RequestId requestId)](#oh_mediaassetmanager_cancelrequest) | Cancels a request based on the request ID.|
| [MediaLibrary_ErrorCode OH_MediaAssetManager_RequestMovingPhoto(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId, OH_MediaLibrary_OnMovingPhotoDataPrepared callback)](#oh_mediaassetmanager_requestmovingphoto) | Requests a moving photo based on different policies.|
| [MediaLibrary_ErrorCode OH_MediaAssetManager_RequestImage(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId, OH_MediaLibrary_OnImageDataPrepared callback)](#oh_mediaassetmanager_requestimage) | Requests an image based on different policies.|
| [MediaLibrary_ErrorCode OH_MediaAssetManager_Release(OH_MediaAssetManager* manager)](#oh_mediaassetmanager_release) | Releases an [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md) instance.|

## Function Description

### OH_MediaAssetManager_Create()

```
OH_MediaAssetManager* OH_MediaAssetManager_Create(void)
```

**Description**

Creates an OH_MediaAssetManager instance.

**Since**: 12

**Return value**

| Type| Description|
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* | Pointer to the OH_MediaAssetManager instance created.|

### OH_MediaAssetManager_RequestImageForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath(OH_MediaAssetManager* manager, const char* uri,MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**Description**

Requests an image in the specified directory.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | Pointer to an OH_MediaAssetManager instance.|
| const char* uri | Pointer to the URI of the requested image.|
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | Options related to the media asset quality and delivery mode.|
| const char* destPath | Pointer to the destination directory of the requested image.|
| [OH_MediaLibrary_OnDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_ondataprepared) callback | Callback to be invoked when the requested image is ready.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) | Request ID.|

### OH_MediaAssetManager_RequestVideoForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath(OH_MediaAssetManager* manager, const char* uri,MediaLibrary_RequestOptions requestOptions, const char* destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**Description**

Requests a video in the specified directory.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | Pointer to an OH_MediaAssetManager instance.|
| const char* uri | Pointer to the URI of the requested video.|
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | Options related to the media asset quality and delivery mode.|
| const char* destPath | Pointer to the destination directory of the requested video.|
| [OH_MediaLibrary_OnDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_ondataprepared) callback | Callback to be invoked when the requested video is ready.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) | Request ID.|

### OH_MediaAssetManager_CancelRequest()

```
bool OH_MediaAssetManager_CancelRequest(OH_MediaAssetManager* manager, const MediaLibrary_RequestId requestId)
```

**Description**

Cancels a request based on the request ID.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | Pointer to an OH_MediaAssetManager instance.|
| const [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md) requestId | ID of the request to cancel.|

**Return value**

| Type| Description|
| -- | -- |
| bool | Operation result. The value **true** is returned if the request is successfully canceled, and **false** is returned otherwise.|

### OH_MediaAssetManager_RequestMovingPhoto()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_RequestMovingPhoto(OH_MediaAssetManager* manager,OH_MediaAsset* mediaAsset, MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId,OH_MediaLibrary_OnMovingPhotoDataPrepared callback)
```

**Description**

Requests a moving photo based on different policies.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | Pointer to an [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md) instance.|
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to the [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance to be requested.|
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | Options related to the media asset quality and delivery mode. The options are specified by [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md).|
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md)* requestId | Pointer to the request ID, which is specified by [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md).|
| [OH_MediaLibrary_OnMovingPhotoDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onmovingphotodataprepared) callback | Callback to be invoked when the requested moving photo is ready. The callback is specified by [OH_MediaLibrary_OnMovingPhotoDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onmovingphotodataprepared).|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.<br>**MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: unsupported operation.<br>**MEDIA_LIBRARY_PERMISSION_DENIED**: no access permission.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAssetManager_RequestImage()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_RequestImage(OH_MediaAssetManager* manager, OH_MediaAsset* mediaAsset,MediaLibrary_RequestOptions requestOptions, MediaLibrary_RequestId* requestId,OH_MediaLibrary_OnImageDataPrepared callback)
```

**Description**

Requests an image based on different policies.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | Pointer to an [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md) instance.|
| [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md)* mediaAsset | Pointer to the [OH_MediaAsset](capi-mediaassetmanager-oh-mediaasset.md) instance to be requested.|
| [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md) requestOptions | Options related to the media asset quality and delivery mode. The options are specified by [MediaLibrary_RequestOptions](capi-mediaassetmanager-medialibrary-requestoptions.md).|
| [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md)* requestId | Pointer to the request ID, which is specified by [MediaLibrary_RequestId](capi-mediaassetmanager-medialibrary-requestid.md).|
| [OH_MediaLibrary_OnImageDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onimagedataprepared) callback | Callback to be invoked when the requested image is ready. The callback is specified by [OH_MediaLibrary_OnImageDataPrepared](capi-media-asset-base-capi-h.md#oh_medialibrary_onimagedataprepared).|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.<br>**MEDIA_LIBRARY_OPERATION_NOT_SUPPORTED**: unsupported operation.<br>**MEDIA_LIBRARY_PERMISSION_DENIED**: no access permission.<br>**MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|

### OH_MediaAssetManager_Release()

```
MediaLibrary_ErrorCode OH_MediaAssetManager_Release(OH_MediaAssetManager* manager)
```

**Description**

Releases an [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md) instance.

**Since**: 13


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md)* manager | Pointer to an [OH_MediaAssetManager](capi-mediaassetmanager-oh-mediaassetmanager.md) instance.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>**MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible causes:<br>1. A mandatory parameter is not specified.<br>2. A parameter type is incorrect.<br>3. Parameter verification fails.|
