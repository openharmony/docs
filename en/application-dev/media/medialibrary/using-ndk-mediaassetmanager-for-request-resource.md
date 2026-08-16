# Requesting Media Assets Using MediaAssetManager (C/C++)

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=6edd6d27aaca62496dc96318d4c8a47f63927216 translatedAt=2026-08-11T01:58:40.151Z pushedAt=2026-08-12T03:44:20.252Z -->

You can use **MediaAssetManager** to copy a media asset to a sandbox directory. This topic walks you through on how to use **MediaAssetManager** to copy an image to the specified sandbox directory.

The procedure is as follows: 1. <br>Create a MediaAssetManager instance. 2.<br>Set parameters for requesting an image and request the image.<br>3. (Optional) Cancel the request.

## How to Develop

Add the dynamic library in the CMake script.

```c
target_link_libraries(sample PUBLIC libmedia_asset_manager.so)
```

Include the [media_asset_manager_capi.h](../../reference/apis-media-library-kit/capi-media-asset-manager-capi-h.md) and [media_asset_base_capi.h](../../reference/apis-media-library-kit/capi-media-asset-base-capi-h.md) header files to use the APIs of MediaAssetManager.

For detailed API descriptions, refer to [MediaAssetManager API](../../reference/apis-media-library-kit/capi-mediaassetmanager.md).

> **NOTE**<br>
> The application must have the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Before You Start](photoAccessHelper-preparation.md).

1. Call **OH_MediaAssetManager_Create()** to create a MediaAssetManager instance.

2. Set the URI of the image to request, destination URI, asset requesting policy, and callback used to return the result.

3. Call **OH_MediaAssetManager_RequestImageForPath()** to copy the image to the target URI.

4. (Optional) Call **OH_MediaAssetManager_CancelRequest()** to cancel the request.  

## Example

<!-- @[request_media_assets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/RequestMediaAssetsCppSample/entry/src/main/cpp/napi_init.cpp) -->  

``` C++
#include "napi/native_api.h"
#include "multimedia/media_library/media_asset_base_capi.h"
#include "multimedia/media_library/media_asset_manager_capi.h"
#include <cstdio>
#include <cstring>

const char ERROR_REQUEST_ID[UUID_STR_MAX_LENGTH] = "00000000-0000-0000-0000-000000000000";

// Callback to be invoked when the request image is ready.
void OnDataPrepared(int32_t result, MediaLibrary_RequestId requestIdStruct)
{
    printf("OnDataPrepared requestId: %s result: %d\n", requestIdStruct.requestId, result);
}

// ...

static napi_value RequestMediaAssets(napi_env env, napi_callback_info info)
{
    // Create a MediaAssetManager instance.
    OH_MediaAssetManager *manager = OH_MediaAssetManager_Create();
    if (manager == nullptr) {
        // Exception handling.
        printf("Get MediaAssetManager failed.\n");
        // ...
    } else {
        // Set the callback.
        OH_MediaLibrary_OnDataPrepared callback = OnDataPrepared;
        
        // Set the delivery mode.
        MediaLibrary_RequestOptions options;
        options.deliveryMode = MEDIA_LIBRARY_HIGH_QUALITY_MODE;

        // The URI format is: const char *srcUri = "file://media/Photo/[albumId]/[photoName].[ext]". In actual use, the URI must be obtained through the Media Library API.
        // Preset the URI of the image with the default high quality. The URI used is an example only. You need to create or obtain the URI based on actual requirements.
        const char *srcUri = "file://media/Photo/87/VID_1712195295_025/request_image_src.jpg";

        // URI of the destination directory. The URI used is an example. You need to create or obtain the URI based on actual requirements.
        const char *destUri = "file://media/Photo/9/IMG_1712195237_008/request_image_dest.jpg";

        // Request the image and write it to the destination directory.
        MediaLibrary_RequestId requestIdStruct = OH_MediaAssetManager_RequestImageForPath(manager, srcUri,
            options, destUri, callback);
        if (strcmp(requestIdStruct.requestId, ERROR_REQUEST_ID) == 0) {
            // Exception handling.
            printf("Request image failed requestId: %s\n", requestIdStruct.requestId);
            // ...
        } else {
            // Print the request ID if the request is successful.
            printf("Request image success, requestId: %s\n", requestIdStruct.requestId);

            // Call CancelRequest() to cancel the request being processed.
            // Note that OH_MediaAssetManager_CancelRequest is optional.
            bool ret = OH_MediaAssetManager_CancelRequest(manager, requestIdStruct);
            // ...
        }
    }
}
```