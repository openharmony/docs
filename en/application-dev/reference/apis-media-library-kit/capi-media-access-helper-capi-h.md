# media_access_helper_capi.h

## Overview

The file declares the APIs for album management.

You can use the APIs to create an album, and access and modify the media data in the album.

**Library**: libmedia_asset_manager.so

**File to include**: <multimedia/media_library/media_access_helper_capi.h>

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Since**: 12

**Related module**: [MediaAssetManager](capi-mediaassetmanager.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [MediaLibrary_ErrorCode OH_MediaAccessHelper_ApplyChanges(OH_MediaAssetChangeRequest* changeRequest)](#oh_mediaaccesshelper_applychanges) | Applies changes to an asset or album.|

## Function Description

### OH_MediaAccessHelper_ApplyChanges()

```
MediaLibrary_ErrorCode OH_MediaAccessHelper_ApplyChanges(OH_MediaAssetChangeRequest* changeRequest)
```

**Description**

Applies changes to an asset or album.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Since**: 12


**Parameters**

| Parameter| Description|
| -- | -- |
| [OH_MediaAssetChangeRequest](capi-mediaassetmanager-oh-mediaassetchangerequest.md)* changeRequest | Change request.|

**Return value**

| Type| Description|
| -- | -- |
| [MediaLibrary_ErrorCode](capi-media-asset-base-capi-h.md#medialibrary_errorcode) | **MEDIA_LIBRARY_OK**: operation success.<br>      **MEDIA_LIBRARY_PARAMETER_ERROR**: incorrect parameters. Possible reasons:<br>                                      1. A mandatory parameter is not specified.<br>                                      2. A parameter type is incorrect.<br>                                      3. Parameter verification fails.<br>      **MEDIA_LIBRARY_PERMISSION_DENIED**: access denied due to lack of permission.<br>      **MEDIA_LIBRARY_INTERNAL_SYSTEM_ERROR**: internal system error.|
