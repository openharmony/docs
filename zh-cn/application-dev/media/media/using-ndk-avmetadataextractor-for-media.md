# 使用AVMetadataExtractor获取元数据(C/C++)

使用AVMetadataExtractor可以实现从原始媒体资源中获取元数据，本开发指导将以获取一个音频资源的元数据作为示例，向开发者讲解AVMetadataExtractor元数据相关功能。视频资源的元数据获取流程与音频类似，由于视频没有专辑封面，所以无法获取视频资源的专辑封面。

获取音频资源的元数据的全流程包含：创建AVMetadataExtractor、设置资源、获取元数据、获取专辑封面、销毁资源。

## 开发步骤及注意事项
在 CMake 脚本中链接动态库。
```
target_link_libraries(entry PUBLIC libavmetadata_extractor.so libace_napi.z.so )
```

使用[OH_AVFormat](../../reference/apis-avcodec-kit/_core.md#oh_avformat)相关接口时，需引入如下头文件。
```
#include <multimedia/player_framework/native_avformat.h>
```

并在 CMake 脚本中链接如下动态库。
```
target_link_libraries(entry PUBLIC libnative_media_core.so)
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

开发者通过引入[avmetadata_extractor.h](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md)、[avmetadata_extractor_base.h](../../reference/apis-media-kit/capi-avmetadata-extractor-base-h.md)和[native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md)头文件，使用获取元数据相关API。
详细的API说明请参考[AVMetadataExtractor API参考](../../reference/apis-media-kit/capi-avmetadataextractor.md)。

1. 使用[OH_AVMetadataExtractor_Create()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_create)创建实例。
    ```c
    #include <multimedia/player_framework/avmetadata_extractor.h>
    // 创建OH_AVMetadataExtractor实例。
    OH_AVMetadataExtractor* mainExtractor = OH_AVMetadataExtractor_Create();
    ```

2. 设置视频资源的文件描述符：调用[OH_AVMetadataExtractor_SetFDSoucre()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_setfdsource)。
   > - 不同AVMetadataExtractor或者[AVImageGenerator](../../reference/apis-media-kit/capi-avimagegenerator.md)实例，如果需要操作同一资源，需要多次打开文件描述符，不要共用同一文件描述符。
    ```c
    #include "napi/native_api.h"
    #include <multimedia/player_framework/avmetadata_extractor.h>
    int64_t offset = 0; // 媒体源在文件描述符中的偏移量。
    int32_t fileDescribe = -1; // 媒体文件描述符。
    int32_t fileSize = 0; // 媒体文件大小。
    
    // GetInputParams为辅助函数，用于获取FetchAlbumCover、FetchMetadata的输入参数，实现见完整示例。
    if (!GetInputParams(env, info, offset, fileDescribe, fileSize)) {
        return nullptr;
    }
     // 设置视频资源的文件描述符。
    OH_AVErrCode avErrCode = OH_AVMetadataExtractor_SetFDSource(mainExtractor, fileDescribe, offset, fileSize);
    // 异常处理。
    if (avErrCode != AV_ERR_OK) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "SetFDSource for metadata extractor failed");
        return nullptr;
    }
    ```

3. 获取元数据：调用[OH_AVMetadataExtractor_FetchMetadata()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchmetadata)。
   > - 需要先调用OH_AVFormat_Create()函数创建一个OH_AVFormat对象，通过访问该对象的各个键值对，可以获取到元数据。使用完成需要调用OH_AVFormat_Destroy销毁该对象，防止产生内存泄漏，详细使用方法请参阅[OH_AVFormat](../../reference/apis-avcodec-kit/_core.md#oh_avformat)。
   ```c
   // 获取元数据。
   avErrCode = OH_AVMetadataExtractor_FetchMetadata(mainExtractor, avMetadata);
   ```

4. （可选）获取专辑封面：调用[OH_AVMetadataExtractor_FetchAlbumCover()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchalbumcover)，可以获取到专辑封面。
   > - 使用完成需要调用OH_PixelmapNative_Release释放OH_PixelmapNative对象资源，详细使用方法请参阅[Image_NativeModule](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_release)。
    ```c
    #include <multimedia/image_framework/image/pixelmap_native.h>
    #include <multimedia/player_framework/avmetadata_extractor.h>

    #include <hilog/log.h>
    // 获取专辑封面。
    OH_PixelmapNative* pixelMap = nullptr;
    avErrCode = OH_AVMetadataExtractor_FetchAlbumCover(mainExtractor, &pixelMap);
    ```

5. 释放资源：调用[OH_AVMetadataExtractor_Release()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_release)销毁实例，释放资源。
    ```c
    // 释放OH_AVMetadataExtractor资源。
    OH_AVMetadataExtractor_Release(mainExtractor);
    ```


## 运行示例工程

参考以下示例，获取一个音频的元数据和专辑封面。

1. 新建工程，下载[完整示例工程](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVMetadataExtractor/AVMetadataExtractorNDK)，并将示例工程的资源复制到对应目录。
    ```
    AVMetadataExtractorNDK
    entry/src/main/ets/
    └── pages
        └── Index.ets (获取元数据界面)
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
            └── test.mp3 (音频资源)
    ```
2. 编译新建工程并运行。