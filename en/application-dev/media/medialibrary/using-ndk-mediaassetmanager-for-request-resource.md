# Requesting Media Assets Using MediaAssetManager (C/C++)

You can use **MediaAssetManager** to copy a media asset to a sandbox directory. This topic walks you through on how to use **MediaAssetManager** to copy an image to the specified sandbox directory.

The procedure is as follows:

1. Create a **MediaAssetManager** instance.
2. Set parameters for requesting an image and request the image.
3. (Optional) Cancel the request.
## How to Develop

Add the dynamic library in the CMake script.

```
target_link_libraries(sample PUBLIC libmedia_asset_manager.so)
```

Import [media_asset_manager.h](../../reference/apis-media-library-kit/media__asset__manager__capi_8h.md) and [media_asset_base_capi.h](../../reference/apis-media-library-kit/media__asset__base__capi_8h.md) header files.
For details about the APIs, see [MediaAssetManager API](../../reference/apis-media-library-kit/_media_asset_manager.md).

> **NOTE**<br>
> The application must have the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Before You Start](photoAccessHelper-preparation.md).

1. Use **OH_MediaAssetManager_Create()** to create a **MediaAssetManager** instance.
2. Set the URI of the image to request, destination URI, asset requesting policy, and callback used to return the result.
3. Use **OH_MediaAssetManager_RequestImageForPath()** to copy the image to the target URI.
4. (Optional) Use **OH_MediaAssetManager_CancelRequest()** to cancel the request.  

## Example

```c
#include "napi/native_api.h"
#include "multimedia/media_library/media_asset_base_capi.h"
#include "multimedia/media_library/media_asset_manager_capi.h"
#include "hilog/log.h"
#include <stdio.h>
#include <string.h>

const char ERROR_REQUEST_ID[UUID_STR_MAX_LENGTH] = "00000000-0000-0000-0000-000000000000";

// Callback to be invoked when the request image is ready.
void OnDataPrepared(int32_t result, MediaLibrary_RequestId requestIdStruct)
{
    printf("OnDataPrepared requestId: %s result: %d\n", requestIdStruct.requestId, result);
}

int main()
{
    // Create a MediaAssetManager instance.
    OH_MediaAssetManager *manager = OH_MediaAssetManager_Create();
    if (manager == nullptr) {
        // Exception handling.
        printf("Get MediaAssetManager failed.\n");
    } else {
        // Set the callback.
        OH_MediaLibrary_OnDataPrepared callback = OnDataPrepared;
        
        // Set the delivery mode.
        MediaLibrary_RequestOptions options;
        options.deliveryMode = MEDIA_LIBRARY_HIGH_QUALITY_MODE;

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
        } else {
            // Print the request ID if the request is successful.
            printf("Request image success, requestId: %s\n", requestIdStruct.requestId);

            // Call CancelRequest() to cancel the request being processed.
            // Note that OH_MediaAssetManager_CancelRequest is optional.
            bool ret = OH_MediaAssetManager_CancelRequest(manager, requestId);
        }
    }
    return 0;
}
```
