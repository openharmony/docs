# Using AVImageGenerator to Obtain Video Frames (C/C++)

You can use the AVImageGenerator to obtain the video frame at the specified time from the raw media asset.

The full process of obtaining the video frame includes creating an AVImageGenerator instance, setting resources, obtaining the video frame, and releasing the instance.

## How to Develop
Link the dynamic library in the CMake script.
```
target_link_libraries(entry PUBLIC libavimage_generator.so libace_napi.z.so)
```

To use [OH_PixelmapNative_ConvertPixelmapNativeToNapi()](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_convertpixelmapnativetonapi) to convert a nativePixelMap object into a PixelMapnapi object and use [OH_PixelmapNative_Release()](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_release) to release the OH_PixelmapNative object, include the following header file:
```
#include <multimedia/image_framework/image/pixelmap_native.h>
```

In addition, link the following dynamic link library in the CMake script:
```
target_link_libraries(entry PUBLIC libpixelmap.so libpixelmap_ndk.z.so)
```

To use system logging, include the following header file:
```
#include <hilog/log.h>
```

In addition, link the following dynamic link library in the CMake script:
```
target_link_libraries(entry PUBLIC libhilog_ndk.z.so)
```

(Optional) You can use [OH_AVMetadataExtractor_FetchMetadata()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchmetadata) to obtain the duration information of the media resource (OH_AVMETADATA_EXTRACTOR_DURATION, ../../reference/apis-media-kit/capi-avmetadata-extractor-base-h.md#variables), and specify the time to obtain a video frame. Include the following header files:
```
#include "multimedia/player_framework/avmetadata_extractor.h"
#include "multimedia/player_framework/avmetadata_extractor_base.h"
```

In addition, link the following dynamic link library in the CMake script:
```
target_link_libraries(entry PUBLIC libavmetadata_extractor.so libnative_media_core.so)
```

You can use the APIs related to video frame retrieval by including the header files [avimage_generator.h](../../reference/apis-media-kit/capi-avimage-generator-h.md), [avimage_generator_base.h](../../reference/apis-media-kit/capi-avimage-generator-base-h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md).

Read [AVImageGenerator](../../reference/apis-media-kit/capi-avimagegenerator.md) for the API reference.

1. Call [OH_AVImageGenerator_Create()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_create) to create an instance.
   ```c
   #include <multimedia/player_framework/avimage_generator.h>
   // Create an OH_AVImageGenerator instance.
   OH_AVImageGenerator* generator = OH_AVImageGenerator_Create();
   ```

2. Call [OH_AVImageGenerator_SetFDSource()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_setfdsource) to set the file descriptor of a video resource.
    ```c
    #include "napi/native_api.h"
    #include <multimedia/player_framework/avimage_generator.h>
    #include <multimedia/player_framework/native_averrors.h>

    int64_t offset = 0; // Offset of the media source in the file descriptor.
    int32_t fileDescribe = -1; // File descriptor of the media file.
    int32_t fileSize = 0; // Size of the media file.
        
    // Set the file descriptor of the video resource.
    OH_AVErrCode avErrCode = OH_AVImageGenerator_SetFDSource(generator, fileDescribe, offset, fileSize);
    // Handle exceptions.
    if (avErrCode != AV_ERR_OK) {
        OH_AVImageGenerator_Release(generator);
        napi_throw_error(env, "EFAILED", "SetFDSource failed");
        return nullptr;
    }
    ```

3. (Optional) Obtain the duration information of the media resource and specify the time to obtain the video frame.
    ```c
    #include "napi/native_api.h"
    #include "multimedia/player_framework/avmetadata_extractor.h"
    #include "multimedia/player_framework/avmetadata_extractor_base.h"
    static napi_value OhAVMetadataExtractorGetDuration(napi_env env, napi_callback_info info)
    {
        int64_t offset = 0;
        int32_t fileDescribe = -1;
        int64_t fileSize = 0;
        // Use helper functions to obtain input parameters. For details, see the complete example.
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
        // Obtain the metadata of the resource file.
        avErrCode = OH_AVMetadataExtractor_FetchMetadata(mainExtractor, avMetadata);
        if (avErrCode != AV_ERR_OK) {
            OH_AVFormat_Destroy(avMetadata);
            OH_AVMetadataExtractor_Release(mainExtractor);
            napi_throw_error(env, "EFAILED", "Fetch metadata failed");
            return nullptr;
        }
        int64_t out;
        // Obtain the duration of the resource file from the metadata.
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

3. Call [OH_AVImageGenerator_FetchFrameByTime()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_fetchframebytime) to obtain the video frame at a specified time, which is an OH_PixelmapNative object.
   > - When the object is no longer required, call **OH_PixelmapNative_Release** to release the object. For details, see [Image_NativeModule](../../reference/apis-image-kit/capi-pixelmap-native-h.md#oh_pixelmapnative_release).
    ```c
    #include "napi/native_api.h"
    #include <multimedia/image_framework/image/pixelmap_native.h>
    #include <multimedia/player_framework/avimage_generator.h>
    #include <multimedia/player_framework/avimage_generator_base.h>
    #include <multimedia/player_framework/native_averrors.h>

    // Input parameters for FetchFrameByTime.
    struct FetchFrameParams {
        int64_t timeUs = 0; // Specified time (in us).
        int64_t offset = 0; // Offset of the media source in the file descriptor.
        int32_t fileDescribe = -1; // File descriptor of the media file.
        int32_t fileSize = 0; // Size of the media file.
        int32_t options = OH_AVIMAGE_GENERATOR_QUERY_CLOSEST; // OH_AVIMAGE_GENERATOR_QUERY_CLOSEST means that the key frame closest to the specified time is selected.
    };

    static napi_value OhAvImageGeneratorFetchFrameByTime(napi_env env, napi_callback_info info)
    {
        FetchFrameParams fetchFrameParams;
        // Use helper functions to obtain input parameters. For details, see the complete example.
        if (!GetFetchFrameByTimeParams(env, info, fetchFrameParams)) {
            return nullptr;
        }
        int64_t timeUs = fetchFrameParams.timeUs;
        int64_t offset = fetchFrameParams.offset;
        int32_t fileDescribe = fetchFrameParams.fileDescribe;
        int32_t fileSize = fetchFrameParams.fileSize;
        int32_t options = fetchFrameParams.options;
        // Create an OH_AVImageGenerator instance.
        OH_AVImageGenerator* generator = OH_AVImageGenerator_Create();
        // Handle exceptions.
        if (!generator) {
            napi_throw_error(env, "EFAILED", "Create generator failed");
            return nullptr;
        }
        // Set the file descriptor of the video resource.
        OH_AVErrCode avErrCode = OH_AVImageGenerator_SetFDSource(generator, fileDescribe, offset, fileSize);
        // Handle exceptions.
        if (avErrCode != AV_ERR_OK) {
            OH_AVImageGenerator_Release(generator);
            napi_throw_error(env, "EFAILED", "SetFDSource failed");
            return nullptr;
        }
        // Obtain the video frame at a specified time.
        OH_PixelmapNative* pixelMap = nullptr;
        avErrCode = OH_AVImageGenerator_FetchFrameByTime(generator, timeUs,
            (OH_AVImageGenerator_QueryOptions)options, &pixelMap);
        // Handle exceptions.
        if (avErrCode != AV_ERR_OK || !pixelMap) {
            OH_AVImageGenerator_Release(generator);
            napi_throw_error(env, "EFAILED", "FetchFrameByTime failed");
            return nullptr;
        }
        // Convert the nativePixelMap object into a PixelMapnapi object.
        napi_value pixelmapNapi = nullptr;
        Image_ErrorCode errCode = OH_PixelmapNative_ConvertPixelmapNativeToNapi(env, pixelMap, &pixelmapNapi);
        // Release the OH_PixelmapNative resource.
        OH_PixelmapNative_Release(pixelMap);
        // Release the OH_AVImageGenerator resource.
        OH_AVImageGenerator_Release(generator);
        // Handle exceptions.
        if (errCode != IMAGE_SUCCESS) {
            napi_throw_error(env, "EFAILED", "Convert PixelMap failed");
            return nullptr;
        }
        return pixelmapNapi;
    }
    ```
4. Call [OH_AVImageGenerator_Release()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_release) to destroy the instance and release resources.
    ```c
    // Release the OH_AVImageGenerator resource.
    OH_AVImageGenerator_Release(generator);
    ```

## Running the Sample Project

Refer to the sample project to obtain the video frame at a specified time.

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVImageGenerator/AVImageGeneratorNDK), and copy its resources to the corresponding directories.
    ```
    AVImageGeneratorNDK
    entry/src/main/ets/
    └── pages
        └── Index.ets (Thumbnail retrieval UI)
    entry/src/main/
    ├── cpp
    │   ├── types
    │   │   └── libentry
    │   │       └── Index.d.ts (JavaScript mapping of NDK functions)
    │   ├── CMakeLists.txt (CMake script)
    │   └── napi_init.cpp (NDK functions)
    └── resources
        ├── base
        │   ├── element
        │   │   ├── color.json
        │   │   ├── float.json
        │   │   └── string.json
        │   └── media
        │
        └── rawfile
            └── H264_AAC.mp4 (Video resource)
    ```
2. Compile and run the project.
