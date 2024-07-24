# MediaAssetManager


## Overview

Provides APIs for requesting media library assets.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [media_asset_base_capi.h](media__asset__base__capi_8h.md) | Defines the structs and enums of the media asset manager.|
| [media_asset_manager_capi.h](media__asset__manager__capi_8h.md) | Defines the functions of the media asset manager.|


### Structs

| Name| Description|
| -------- | -------- |
| struct  [MediaLibrary_RequestId](_media_library___request_id.md) | Defines a request ID.|
| struct  [MediaLibrary_RequestOptions](_media_library___request_options.md) | Defines the options related to the media asset quality and delivery mode to set.|


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_MediaAssetManager](#oh_mediaassetmanager) [OH_MediaAssetManager](#oh_mediaassetmanager) | Defines a struct for the media asset manager.|
| typedef struct [MediaLibrary_RequestId](_media_library___request_id.md) [MediaLibrary_RequestId](#medialibrary_requestid) | Defines a struct for the request ID.|
| typedef enum [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) [MediaLibrary_DeliveryMode](#medialibrary_deliverymode) | Defines an enum for the delivery mode of the requested media asset.|
| typedef void(\* [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared)) (int32_t result, [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | Defines a function pointer to the callback to be triggered when the requested media asset is ready.|
| typedef struct [MediaLibrary_RequestOptions](_media_library___request_options.md) [MediaLibrary_RequestOptions](#medialibrary_requestoptions) | Defines the options related to the media asset quality and delivery mode to set.|


### Enums

| Name| Description|
| -------- | -------- |
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) {<br>MEDIA_LIBRARY_FAST_MODE = 0,<br>MEDIA_LIBRARY_HIGH_QUALITY_MODE = 1,<br>MEDIA_LIBRARY_BALANCED_MODE = 2<br>} | Enumerates the delivery modes of the requested media asset.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_MediaAssetManager](#oh_mediaassetmanager) \* [OH_MediaAssetManager_Create](#oh_mediaassetmanager_create) (void) | Creates a **MediaAssetManager** instance.|
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestImageForPath](#oh_mediaassetmanager_requestimageforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | Requests an image in the specified directory.|
| [MediaLibrary_RequestId](_media_library___request_id.md) [OH_MediaAssetManager_RequestVideoForPath](#oh_mediaassetmanager_requestvideoforpath) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const char \*uri, [MediaLibrary_RequestOptions](_media_library___request_options.md) requestOptions, const char \*destPath, [OH_MediaLibrary_OnDataPrepared](#oh_medialibrary_ondataprepared) callback) | Requests a video in the specified directory.|
| bool [OH_MediaAssetManager_CancelRequest](#oh_mediaassetmanager_cancelrequest) ([OH_MediaAssetManager](#oh_mediaassetmanager) \*manager, const [MediaLibrary_RequestId](_media_library___request_id.md) requestId) | Cancels a request based on the request ID.|


### Variables

| Name| Description|
| -------- | -------- |
| char [MediaLibrary_RequestId::requestId](#requestid) [UUID_STR_MAX_LENGTH] | Request ID.|
| [MediaLibrary_DeliveryMode](#medialibrary_deliverymode-1) [MediaLibrary_RequestOptions::deliveryMode](#deliverymode) | Delivery mode.|


## Type Description


### MediaLibrary_DeliveryMode

```
typedef enum MediaLibrary_DeliveryMode MediaLibrary_DeliveryMode
```

**Description**

Defines an enum for the delivery mode of the requested media asset.

The delivery modes include the following:

- **MEDIA_LIBRARY_FAST_MODE**: deliver the media asset available without considering its quality.

- **MEDIA_LIBRARY_HIGH_QUALITY_MODE**: deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

- **MEDIA_LIBRARY_BALANCED_MODE**: return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12


### MediaLibrary_RequestId

```
typedef struct MediaLibrary_RequestId MediaLibrary_RequestId
```

**Description**

Defines a request ID.

A value of this type is returned when a media asset is requested. The request ID can be used to cancel a request. If a request fails, an all-zero value, for example, **00000000-0000-0000-0000-000000000000** is returned.

**Since**: 12


### MediaLibrary_RequestOptions

```
typedef struct MediaLibrary_RequestOptions MediaLibrary_RequestOptions
```

**Description**

Defines how media assets are requested and processed.

You can use this struct to set options related to the media asset quality, delivery mode, and more.

**Since**: 12


### OH_MediaAssetManager

```
typedef struct OH_MediaAssetManager OH_MediaAssetManager
```

**Description**

Defines a struct for the media asset manager.

You can use this struct to create a media asset manager instance. If the creation fails, a null pointer is returned.

**Since**: 12


### OH_MediaLibrary_OnDataPrepared

```
typedef void(* OH_MediaLibrary_OnDataPrepared) (int32_t result, MediaLibrary_RequestId requestId)
```

**Description**

Defines a function pointer to the callback to be triggered when the requested media asset is ready.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| result | Processing result of the requested asset.|
| requestId | Request ID.|


## Enum Description


### MediaLibrary_DeliveryMode

```
enum MediaLibrary_DeliveryMode
```

**Description**

Enumerates the delivery modes of the requested media asset.

The delivery modes include the following:

- **MEDIA_LIBRARY_FAST_MODE**: deliver the media asset available without considering its quality.

- **MEDIA_LIBRARY_HIGH_QUALITY_MODE**: deliver a media asset with high quality. If there is no high-quality asset available, trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

- **MEDIA_LIBRARY_BALANCED_MODE**: return the high-quality asset if there is any. Otherwise, return a low-quality asset first and trigger the process for creating a high-quality asset. Then, return the high-quality asset that is successfully created.

**Since**: 12

| Value| Description|
| -------- | -------- |
| MEDIA_LIBRARY_FAST_MODE | Fast mode.|
| MEDIA_LIBRARY_HIGH_QUALITY_MODE | High-quality mode.|
| MEDIA_LIBRARY_BALANCED_MODE | Balance mode.|


## Function Description


### OH_MediaAssetManager_CancelRequest()

```
bool OH_MediaAssetManager_CancelRequest (OH_MediaAssetManager *manager, const MediaLibrary_RequestId requestId)
```

**Description**

Cancels a request based on the request ID.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| manager | Pointer to the **OH_MediaAssetManager** instance.|
| requestId | ID of the request to cancel.|

**Required permissions**

ohos.permission.READ_IMAGEVIDEO

**Returns**

Returns **true** if the request is successfully canceled; returns **false** otherwise.


### OH_MediaAssetManager_Create()

```
OH_MediaAssetManager* OH_MediaAssetManager_Create (void )
```

**Description**

Creates a **MediaAssetManager** instance.

**Since**: 12

**Returns**

Returns the pointer to the **MediaAssetManager** instance created.


### OH_MediaAssetManager_RequestImageForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestImageForPath (OH_MediaAssetManager *manager, const char *uri, MediaLibrary_RequestOptions requestOptions, const char *destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**Description**

Requests an image in the specified directory.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| manager | Pointer to the **OH_MediaAssetManager** instance.|
| uri | Pointer to the URI of the requested image asset.|
| requestOptions | Options related to the image asset quality and delivery mode.|
| destPath | Pointer to the destination directory of the requested image asset.|
| callback | Callback to be invoked when the requested image asset is ready.|

**Required permissions**

ohos.permission.READ_IMAGEVIDEO

**Returns**

Returns the request ID.


### OH_MediaAssetManager_RequestVideoForPath()

```
MediaLibrary_RequestId OH_MediaAssetManager_RequestVideoForPath (OH_MediaAssetManager *manager, const char *uri, MediaLibrary_RequestOptions requestOptions, const char *destPath, OH_MediaLibrary_OnDataPrepared callback)
```

**Description**

Requests a video asset in the specified directory.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| manager | Pointer to the **OH_MediaAssetManager** instance.|
| uri | Pointer to the URI of the requested video asset.|
| requestOptions | Options related to the video asset quality and delivery mode.|
| destPath | Pointer to the destination directory of the requested video asset.|
| callback | Callback to be invoked when the requested video asset is ready.|

**Required permissions**

ohos.permission.READ_IMAGEVIDEO

**Returns**

Returns the request ID.


## Variable Description


### deliveryMode

```
MediaLibrary_DeliveryMode MediaLibrary_RequestOptions::deliveryMode
```

**Description**

Defines the delivery mode.


### requestId

```
char MediaLibrary_RequestId::requestId[UUID_STR_MAX_LENGTH]
```

**Description**

Defines a request ID.
