# 使用MediaAssetManager请求媒体资源(C/C++)

使用MediaAssetManager可以实现请求媒体资源到目标沙箱路径，本开发指导将以请求一张图片作为示例，向开发者讲解MediaAssetManager相关功能。

请求图片资源的全流程包含：创建MediaAssetManager，设置请求资源，请求图片资源，取消本次请求(可选)。

## 开发步骤及注意事项

在CMake脚本中链接动态库

```
target_link_libraries(sample PUBLIC libmedia_asset_manager.so)
```

开发者通过引入[media_asset_manager.h](../../reference/apis-media-library-kit/media__asset__manager__capi_8h.md)和[media_asset_base_capi.h](../../reference/apis-media-library-kit/media__asset__base__capi_8h.md)头文件，使用MediaAssetManager相关API。
详细的API说明请参考[MediaAssetManager API](../../reference/apis-media-library-kit/_media_asset_manager.md)。

> **说明：**
> 开发前，需要参考[开发准备](photoAccessHelper-preparation.md)，申请`ohos.permission.READ_IMAGEVIDEO`权限。

1. 创建实例：OH_MediaAssetManager_Create()。
2. 设置资源：设置资源请求回调、设置资源请求策略、设置源图片Uri和目标Uri。
3. 请求图片资源：调用OH_MediaAssetManager_RequestImageForPath()请求图片资源到目标Uri。
4. 取消请求：调用OH_MediaAssetManager_CancelRequest()。(可选)

## 完整示例

```c
#include "napi/native_api.h"
#include "multimedia/media_library/media_asset_base_capi.h"
#include "multimedia/media_library/media_asset_manager_capi.h"
#include "hilog/log.h"
#include <stdio.h>
#include <string.h>

const char ERROR_REQUEST_ID[UUID_STR_MAX_LENGTH] = "00000000-0000-0000-0000-000000000000";

// 资源请求回调
void OnDataPrepared(int32_t result, MediaLibrary_RequestId requestIdStruct)
{
    printf("OnDataPrepared requestId: %s result: %d\n", requestIdStruct.requestId, result);
}

int main()
{
    // 创建MediaAssetManager实例
    OH_MediaAssetManager *manager = OH_MediaAssetManager_Create();
    if (manager == nullptr) {
        // 处理异常。
        printf("Get MediaAssetManager failed.\n");
    } else {
        // 设置资源请求回调
        OH_MediaLibrary_OnDataPrepared callback = OnDataPrepared;
        
        // 设置资源请求策略
        MediaLibrary_RequestOptions options;
        options.deliveryMode = MEDIA_LIBRARY_HIGH_QUALITY_MODE;

        // 预置图片资源Uri，默认为高质量图片。注：以下Uri是示例，开发者需根据实际情况创建或获取
        const char *srcUri = "file://media/Photo/87/VID_1712195295_025/request_image_src.jpg";

        // 提供目标路径Uri。注：以下Uri是示例，开发者需根据实际情况创建或获取
        const char *destUri = "file://media/Photo/9/IMG_1712195237_008/request_image_dest.jpg";

        // 将图片资源请求到目标路径
        MediaLibrary_RequestId requestIdStruct = OH_MediaAssetManager_RequestImageForPath(manager, srcUri,
            options, destUri, callback);

        if (strcmp(requestIdStruct.requestId, ERROR_REQUEST_ID) == 0) {
            // 处理异常
            printf("Request image failed requestId：%s\n", requestIdStruct.requestId);
        } else {
            // 请求成功，打印请求Id
            printf("Request image success, requestId: %s\n", requestIdStruct.requestId);

            // 调用CancelRequest接口，用来取消尚在处理中的请求
            // 注：OH_MediaAssetManager_CancelRequest不是必须流程，开发者可根据实际情况选择是否调用该接口来取消尚未回调返回的资源请求
            bool ret = OH_MediaAssetManager_CancelRequest(manager, requestIdStruct);
        }
    }
    return 0;
}
```