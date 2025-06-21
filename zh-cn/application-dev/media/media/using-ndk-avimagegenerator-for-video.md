# 使用AVImageGenerator获取视频帧(C/C++)

使用AVImageGenerator可以实现从原始媒体资源中获取指定时间的视频帧，本开发指导将以获取视频帧作为示例，向开发者讲解AVImageGenerator相关功能。

获取视频帧的全流程包含：创建AVImageGenerator对象、设置资源、获取视频帧、销毁资源。

## 开发步骤及注意事项
在 CMake 脚本中链接动态库。
```
target_link_libraries(entry PUBLIC libavimage_generator.so libace_napi.z.so)
```

使用[OH_PixelmapNative_ConvertPixelmapNativeToNapi()](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_convertpixelmapnativetonapi)接口将nativePixelMap对象转换为PixelMapnapi对象、[OH_PixelmapNative_Release()](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_release)接口释放OH_PixelmapNative对象资源，需引入如下头文件。
```
#include <multimedia/image_framework/image/pixelmap_native.h>
```

并在 CMake 脚本中链接如下动态库。
```
target_link_libraries(entry PUBLIC libpixelmap.so libpixelmap_ndk.z.so)
```

开发者使用系统日志能力时，需引入如下头文件。
```
#include <hilog/log.h>
```

并需要在 CMake 脚本中链接如下动态库。
```
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```

（可选）开发者可以使用[OH_AVMetadataExtractor_FetchMetadata()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchmetadata)获取媒体资源时长信息[OH_AVMETADATA_EXTRACTOR_DURATION](../../reference/apis-media-kit/capi-avmetadata-extractor-base-h.md#变量)，进而选择获取视频帧的时间。使用需引入如下头文件。
```
#include "multimedia/player_framework/avmetadata_extractor.h"
#include "multimedia/player_framework/avmetadata_extractor_base.h"
```

并需要在 CMake 脚本中链接如下动态库。
```
target_link_libraries(entry PUBLIC libavmetadata_extractor.so libnative_media_core.so)
```

开发者通过引入[avimage_generator.h](../../reference/apis-media-kit/capi-avimage-generator-h.md)、[avimage_generator_base.h](../../reference/apis-media-kit/capi-avimage-generator-base-h.md)和[native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md)头文件，使用获取视频帧相关API。
详细的API说明请参考[AVImageGenerator API参考](../../reference/apis-media-kit/capi-avimagegenerator.md)。

1. 使用[OH_AVImageGenerator_Create()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_create)创建实例。
   ```c
   #include <multimedia/player_framework/avimage_generator.h>
   // 创建OH_AVImageGenerator实例。
   OH_AVImageGenerator* generator = OH_AVImageGenerator_Create();
   ```

2. 设置视频资源的文件描述符：调用[OH_AVImageGenerator_SetFDSource()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_setfdsource)。
    ```c
    #include "napi/native_api.h"
    #include <multimedia/player_framework/avimage_generator.h>
    #include <multimedia/player_framework/native_averrors.h>

    int64_t offset = 0; // 媒体源在文件描述符中的偏移量。
    int32_t fileDescribe = -1; // 媒体文件描述符。
    int32_t fileSize = 0; // 媒体文件大小。
        
    // 设置视频资源的文件描述符。
    OH_AVErrCode avErrCode = OH_AVImageGenerator_SetFDSource(generator, fileDescribe, offset, fileSize);
    // 异常处理。
    if (avErrCode != AV_ERR_OK) {
        OH_AVImageGenerator_Release(generator);
        napi_throw_error(env, "EFAILED", "SetFDSource failed");
        return nullptr;
    }
    ```

3. （可选）获取媒体资源时长信息，并指定获取视频帧的时间。
    ```c
    #include "napi/native_api.h"
    #include "multimedia/player_framework/avmetadata_extractor.h"
    #include "multimedia/player_framework/avmetadata_extractor_base.h"
    static napi_value OhAVMetadataExtractorGetDuration(napi_env env, napi_callback_info info)
    {
        int64_t offset = 0;
        int32_t fileDescribe = -1;
        int64_t fileSize = 0;
        // 通过辅助函数，获取输入参数，实现见完整示例。
        if (!GetGetDurationParams(env, info, offset, fileDescribe, fileSize)) {
            return nullptr;
        }
        OH_AVMetadataExtractor* mainExtractor = OH_AVMetadataExtractor_Create();
        if (!mainExtractor) {
            napi_throw_error(env, "EFAILED", "Create metadata extractor failed");
            return nullptr;
        }
        OH_AVErrCode avErrCode = OH_AVMetadataExtractor_SetFDSource(mainExtractor, fileDescribe, offset, fileSize);
        if (avErrCode != AV_ERR_OK) {
            OH_AVMetadataExtractor_Release(mainExtractor);
            napi_throw_error(env, "EFAILED", "SetFDSource for metadata extractor failed");
            return nullptr;
        }
        OH_AVFormat* avMetadata = OH_AVFormat_Create();
        // 获取资源文件的元数据信息。
        avErrCode = OH_AVMetadataExtractor_FetchMetadata(mainExtractor, avMetadata);
        if (avErrCode != AV_ERR_OK) {
            OH_AVFormat_Destroy(avMetadata);
            OH_AVMetadataExtractor_Release(mainExtractor);
            napi_throw_error(env, "EFAILED", "Fetch metadata failed");
            return nullptr;
        }
        int64_t out;
        // 从元数据中获取资源文件的时长。
        if (!OH_AVFormat_GetLongValue(avMetadata, OH_AVMETADATA_EXTRACTOR_DURATION, &out)) {
            OH_AVFormat_Destroy(avMetadata);
            OH_AVMetadataExtractor_Release(mainExtractor);
            napi_throw_error(env, "EFAILED", "Get duration failed");
            return nullptr;
        }
        napi_value duration;
        napi_create_int64(env, out, &duration);
        OH_AVFormat_Destroy(avMetadata);
        OH_AVMetadataExtractor_Release(mainExtractor);
        return duration;
    }
    ```

3. 获取指定时间的视频帧：调用[OH_AVImageGenerator_FetchFrameByTime()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_fetchframebytime)，可以获取到一个OH_PixelmapNative对象，该对象可用于图片显示。
   > - 使用完成需要调用OH_PixelmapNative_Release释放OH_PixelmapNative对象资源，详细使用方法请参阅[Image_NativeModule](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_release)。
    ```c
    #include "napi/native_api.h"
    #include <multimedia/image_framework/image/pixelmap_native.h>
    #include <multimedia/player_framework/avimage_generator.h>
    #include <multimedia/player_framework/avimage_generator_base.h>
    #include <multimedia/player_framework/native_averrors.h>

    // FetchFrameByTime的输入参数。
    struct FetchFrameParams {
        int64_t timeUs = 0; // 指定的时间（单位us）。
        int64_t offset = 0; // 媒体源在文件描述符中的偏移量。
        int32_t fileDescribe = -1; // 媒体文件描述符。
        int32_t fileSize = 0; // 媒体文件大小。
        int32_t options = OH_AVIMAGE_GENERATOR_QUERY_CLOSEST; // OH_AVIMAGE_GENERATOR_QUERY_CLOSEST表示选取离传入时间点最近的关键帧。
    };

    static napi_value OhAvImageGeneratorFetchFrameByTime(napi_env env, napi_callback_info info)
    {
        FetchFrameParams fetchFrameParams;
        // 通过辅助函数，获取输入参数，实现见完整示例。
        if (!GetFetchFrameByTimeParams(env, info, fetchFrameParams)) {
            return nullptr;
        }
        int64_t timeUs = fetchFrameParams.timeUs;
        int64_t offset = fetchFrameParams.offset;
        int32_t fileDescribe = fetchFrameParams.fileDescribe;
        int32_t fileSize = fetchFrameParams.fileSize;
        int32_t options = fetchFrameParams.options;
        // 创建OH_AVImageGenerator实例。
        OH_AVImageGenerator* generator = OH_AVImageGenerator_Create();
        // 异常处理。
        if (!generator) {
            napi_throw_error(env, "EFAILED", "Create generator failed");
            return nullptr;
        }
        // 设置视频资源的文件描述符。
        OH_AVErrCode avErrCode = OH_AVImageGenerator_SetFDSource(generator, fileDescribe, offset, fileSize);
        // 异常处理。
        if (avErrCode != AV_ERR_OK) {
            OH_AVImageGenerator_Release(generator);
            napi_throw_error(env, "EFAILED", "SetFDSource failed");
            return nullptr;
        }
        // 取指定时间的视频帧。
        OH_PixelmapNative* pixelMap = nullptr;
        avErrCode = OH_AVImageGenerator_FetchFrameByTime(generator, timeUs,
            (OH_AVImageGenerator_QueryOptions)options, &pixelMap);
        // 异常处理。
        if (avErrCode != AV_ERR_OK || !pixelMap) {
            OH_AVImageGenerator_Release(generator);
            napi_throw_error(env, "EFAILED", "FetchFrameByTime failed");
            return nullptr;
        }
        // 将nativePixelMap对象转换为PixelMapnapi对象。
        napi_value pixelmapNapi = nullptr;
        Image_ErrorCode errCode = OH_PixelmapNative_ConvertPixelmapNativeToNapi(env, pixelMap, &pixelmapNapi);
        // 释放OH_PixelmapNative资源。
        OH_PixelmapNative_Release(pixelMap);
        // 释放OH_AVImageGenerator资源。
        OH_AVImageGenerator_Release(generator);
        // 异常处理。
        if (errCode != IMAGE_SUCCESS) {
            napi_throw_error(env, "EFAILED", "Convert PixelMap failed");
            return nullptr;
        }
        return pixelmapNapi;
    }
    ```
4. 释放资源：调用[OH_AVImageGenerator_Release()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_release)销毁实例，释放资源。
    ```c
    // 释放OH_AVImageGenerator资源。
    OH_AVImageGenerator_Release(generator);
    ```

## 运行示例工程

参考以下示例，获取一个视频指定时间的视频帧。

1. 新建工程，下载[完整示例工程](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVImageGenerator/AVImageGeneratorNDK)，并将示例工程的资源复制到对应目录。
    ```
    AVImageGeneratorNDK
    entry/src/main/ets/
    └── pages
        └── Index.ets (获取缩略图界面)
    entry/src/main/
    ├── cpp
    │   ├── types
    │   │   └── libentry
    │   │       └── Index.d.ts (NDK函数对应的js映射)
    │   ├── CMakeLists.txt (CMake脚本)
    │   └── napi_init.cpp (NDK函数)
    └── resources
        ├── base
        │   ├── element
        │   │   ├── color.json
        │   │   ├── float.json
        │   │   └── string.json
        │   └── media
        │
        └── rawfile
            └── H264_AAC.mp4 (视频资源)
    ```
2. 编译新建工程并运行。