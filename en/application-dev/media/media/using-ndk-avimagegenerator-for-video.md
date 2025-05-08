# Using AVImageGenerator to Obtain Video Frames (C/C++)

You can use the AVImageGenerator to obtain the video frame at the specified time from the raw media asset.

The full process of obtaining the video frame includes creating an AVImageGenerator instance, setting resources, obtaining the video frame, and releasing the instance.

## How to Develop
Link the dynamic library in the CMake script.
```
target_link_libraries(entry PUBLIC libavimage_generator.so libace_napi.z.so)
```

To use [OH_PixelmapNative_ConvertPixelmapNativeToNapi()](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_convertpixelmapnativetonapi) to convert a nativePixelMap object into a PixelMapnapi object and use [OH_PixelmapNative_Release()](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_release) to release the OH_PixelmapNative object, include the following header file:
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

You can use the APIs related to video frame retrieval by including the header files [avimage_generator.h](../../reference/apis-media-kit/avimage__generator_8h.md), [avimage_generator_base.h](../../reference/apis-media-kit/avimage__generator__base_8h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md).
Read [AVImageGenerator](../../reference/apis-media-kit/_a_v_image_generator.md) for the API reference.

1. Call [OH_AVImageGenerator_Create()](../../reference/apis-media-kit/_a_v_image_generator.md#oh_avimagegenerator_create) to create an instance.

2. Call [OH_AVImageGenerator_SetFDSource()](../../reference/apis-media-kit/_a_v_image_generator.md#oh_avimagegenerator_setfdsource) to set the file descriptor of a video resource.

3. Call [OH_AVImageGenerator_FetchFrameByTime()](../../reference/apis-media-kit/_a_v_image_generator.md#oh_avimagegenerator_fetchframebytime) to obtain the video frame at a specified time, which is an **OH_PixelmapNative** object.
   
> When the object is no longer required, call **OH_PixelmapNative_Release** to release the object. For details, see [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md).
   
4. Call [OH_AVImageGenerator_Release()](../../reference/apis-media-kit/_a_v_image_generator.md#oh_avimagegenerator_release) to destroy the instance and release resources.

## Sample Code

Refer to the sample code below to set the file descriptor and obtain the video frame of a video at the specified time.

```c
#include "napi/native_api.h"

#include <multimedia/image_framework/image/pixelmap_native.h>
#include <multimedia/player_framework/avimage_generator.h>
#include <multimedia/player_framework/avimage_generator_base.h>
#include <multimedia/player_framework/native_averrors.h>

#include <hilog/log.h>

#define LOG_PRINT_DOMAIN 0xFF00
#define APP_LOG_DOMAIN 0x0001
constexpr const char *APP_LOG_TAG = "AVImageGenerator";
#define H_LOGI(...) ((void)OH_LOG_Print(LOG_APP, LOG_INFO, LOG_DOMAIN, APP_LOG_TAG, __VA_ARGS__))

// Auxiliary function: Check the number and type of parameters.
bool CheckArgs(napi_env env, napi_callback_info info, size_t expectedArgc) {
    size_t argc;
    napi_value thisArg;
    void* data;
    napi_get_cb_info(env, info, &argc, nullptr, &thisArg, &data);
    if (argc < expectedArgc) {
        napi_throw_error(env, "EINVAL", "Insufficient arguments");
        return false;
    }
    napi_value argv[expectedArgc];
    napi_get_cb_info(env, info, &argc, argv, &thisArg, &data);
    for (size_t i = 0; i < expectedArgc; ++i) {
        napi_valuetype type;
        napi_typeof(env, argv[i], &type);
        if (type != napi_number) {
            napi_throw_type_error(env, "EINVAL", "All arguments must be numbers");
            return false;
        }
    }
    return true;
}

// Auxiliary function: Obtain a value of the int32 type and perform error processing.
bool GetInt32Value(napi_env env, napi_value value, int32_t* result) {
    napi_status status = napi_get_value_int32(env, value, result);
    if (status != napi_ok) {
        napi_throw_error(env, "EINVAL", "Failed to get int32 value");
        return false;
    }
    return true;
}

// Auxiliary function: Obtain a value of the int64 type and perform error processing.
bool GetInt64Value(napi_env env, napi_value value, int64_t* result) {
    napi_status status = napi_get_value_int64(env, value, result);
    if (status != napi_ok) {
        napi_throw_error(env, "EINVAL", "Failed to get int64 value");
        return false;
    }
    return true;
}

// Describe the mapped OhAvImageGeneratorFetchFrameByTime method in the index.d.ts file.
// export const OhAvImageGeneratorFetchFrameByTime: (fdsrc : number, size : number, timeus : number, 
// options : number, offset : number) => image.PixelMap; 
// Pass in the media file descriptor (fdsrc), media file size (size), and specified time (timeus, in μs).
// Specify the mappings between the time points and the video frames (options) and the offset of the media source in the file descriptor.
// Return a PixelMap object.
static napi_value OhAvImageGeneratorFetchFrameByTime(napi_env env, napi_callback_info info)
{
    if (!CheckArgs(env, info, 5)) {
        return nullptr;
    }
    size_t argc = 5;
    napi_value argv[5];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    int64_t timeUs = 0;
    int64_t offset = 0;
    int32_t fileDescribe = -1;
    int32_t fileSize = 0;
    int32_t options = OH_AVIMAGE_GENERATOR_QUERY_CLOSEST;
    if (!GetInt32Value(env, argv[0], &fileDescribe)) return nullptr;
    if (!GetInt32Value(env, argv[1], &fileSize)) return nullptr;
    if (!GetInt64Value(env, argv[2], &timeUs)) return nullptr;
    if (!GetInt32Value(env, argv[3], &options)) return nullptr;
    if (!GetInt64Value(env, argv[4], &offset)) return nullptr;
    // Verify the parameter.
    if (options < OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC || options > OH_AVIMAGE_GENERATOR_QUERY_CLOSEST) {
        napi_throw_range_error(env, "EINVAL", "Invalid options value");
        return nullptr;
    }
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

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"OhAvImageGeneratorFetchFrameByTime", nullptr, OhAvImageGeneratorFetchFrameByTime, nullptr, nullptr, nullptr, napi_default, nullptr},
    };
    napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
    return exports;
}
EXTERN_C_END

static napi_module demoModule = {
    .nm_version = 1,
    .nm_flags = 0,
    .nm_filename = nullptr,
    .nm_register_func = Init,
    .nm_modname = "entry",
    .nm_priv = ((void *)0),
    .reserved = {0},
};

extern "C" __attribute__((constructor)) void RegisterEntryModule(void)
{
    napi_module_register(&demoModule);
}
```
