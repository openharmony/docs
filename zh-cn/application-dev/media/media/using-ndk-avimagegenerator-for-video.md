# 使用AVImageGenerator获取视频帧(C/C++)

使用AVImageGenerator可以实现从原始媒体资源中获取指定时间的视频帧，本开发指导将以获取视频帧作为示例，向开发者讲解AVImageGenerator相关功能。

获取视频帧的全流程包含：创建AVImageGenerator对象、设置资源、获取视频帧、销毁资源。

## 开发步骤及注意事项
在 CMake 脚本中链接动态库。
```
target_link_libraries(entry PUBLIC libavimage_generator.so libace_napi.z.so)
```

使用[OH_PixelmapNative_ConvertPixelmapNativeToNapi()](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_convertpixelmapnativetonapi)接口将nativePixelMap对象转换为PixelMapnapi对象、[OH_PixelmapNative_Release()](../../reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_release)接口释放OH_PixelmapNative对象资源，需引入如下头文件。
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

开发者通过引入[avimage_generator.h](../../reference/apis-media-kit/capi-avimage-generator-h.md)、[avimage_generator_base.h](../../reference/apis-media-kit/capi-avimage-generator-base-h.md)和[native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md)头文件，使用获取视频帧相关API。
详细的API说明请参考[AVImageGenerator API参考](../../reference/apis-media-kit/capi-avimagegenerator.md)。

1. 使用[OH_AVImageGenerator_Create()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_create)创建实例。

2. 设置视频资源的文件描述符：调用[OH_AVImageGenerator_SetFDSource()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_setfdsource)。

3. 获取指定时间的视频帧：调用[OH_AVImageGenerator_FetchFrameByTime()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_fetchframebytime)，可以获取到一个OH_PixelmapNative对象，该对象可用于图片显示。
   > - 使用完成需要调用OH_PixelmapNative_Release释放OH_PixelmapNative对象资源，详细使用方法请参阅[Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md)。

4. 释放资源：调用[OH_AVImageGenerator_Release()](../../reference/apis-media-kit/capi-avimage-generator-h.md#oh_avimagegenerator_release)销毁实例，释放资源。

## 完整示例

参考以下示例，设置文件描述符，获取一个视频指定时间的视频帧。

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

// 辅助函数：检查参数数量和类型。
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

// 辅助函数：获取 int32 类型值并进行错误处理。
bool GetInt32Value(napi_env env, napi_value value, int32_t* result) {
    napi_status status = napi_get_value_int32(env, value, result);
    if (status != napi_ok) {
        napi_throw_error(env, "EINVAL", "Failed to get int32 value");
        return false;
    }
    return true;
}

// 辅助函数：获取 int64 类型值并进行错误处理。
bool GetInt64Value(napi_env env, napi_value value, int64_t* result) {
    napi_status status = napi_get_value_int64(env, value, result);
    if (status != napi_ok) {
        napi_throw_error(env, "EINVAL", "Failed to get int64 value");
        return false;
    }
    return true;
}

// 需要在index.d.ts文件内描述映射的OhAvImageGeneratorFetchFrameByTime方法。
// export const OhAvImageGeneratorFetchFrameByTime: (fdsrc : number, size : number, timeus : number, 
// options : number, offset : number) => image.PixelMap; 
// 需要传入媒体文件描述符fdsrc、媒体文件大小size、指定的时间timeus（单位us）、
// 指定时间点与视频帧的对应关系options、媒体源在文件描述符中的偏移量offset。
// 返回PixelMap对象。
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
    // 参数校验。
    if (options < OH_AVIMAGE_GENERATOR_QUERY_NEXT_SYNC || options > OH_AVIMAGE_GENERATOR_QUERY_CLOSEST) {
        napi_throw_range_error(env, "EINVAL", "Invalid options value");
        return nullptr;
    }
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