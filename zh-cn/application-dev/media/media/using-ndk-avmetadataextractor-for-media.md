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

开发者通过引入[avmetadata_extractor.h](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md)、[avmetadata_extractor_base.h](../../reference/apis-media-kit/capi-avmetadata-extractor-base-h.md)和[native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md)头文件，使用获取元数据相关API。
详细的API说明请参考[AVMetadataExtractor API参考](../../reference/apis-media-kit/capi-avmetadataextractor.md)。

1. 使用[OH_AVMetadataExtractor_Create()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_create)创建实例。

2. 设置视频资源的文件描述符：调用[OH_AVMetadataExtractor_SetFDSoucre()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_setfdsource)。
   > - 不同AVMetadataExtractor或者[AVImageGenerator](../../reference/apis-media-kit/capi-avimagegenerator.md)实例，如果需要操作同一资源，需要多次打开文件描述符，不要共用同一文件描述符。

3. 获取元数据：调用[OH_AVMetadataExtractor_FetchMetadata()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchmetadata)。
   > - 需要先调用OH_AVFormat_Create()函数创建一个OH_AVFormat对象，通过访问该对象的各个键值对，可以获取到元数据。使用完成需要调用OH_AVFormat_Destroy销毁该对象，防止产生内存泄漏，详细使用方法请参阅[OH_AVFormat](../../reference/apis-avcodec-kit/_core.md#oh_avformat)。

4. （可选）获取专辑封面：调用[OH_AVMetadataExtractor_FetchAlbumCover()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchalbumcover)，可以获取到专辑封面。
   > - 使用完成需要调用OH_PixelmapNative_Release释放OH_PixelmapNative对象资源，详细使用方法请参阅[Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md)。

5. 释放资源：调用[OH_AVMetadataExtractor_Release()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_release)销毁实例，释放资源。


## 完整示例

参考以下示例，设置文件描述符，获取一个音频的元数据和专辑封面。

```c
#include "napi/native_api.h"

#include <multimedia/image_framework/image/pixelmap_native.h>
#include <multimedia/player_framework/avmetadata_extractor.h>
#include <multimedia/player_framework/avmetadata_extractor_base.h>
#include <multimedia/player_framework/native_averrors.h>
#include <multimedia/player_framework/native_avformat.h>
#include <string>

#include <hilog/log.h>

#define LOG_PRINT_DOMAIN 0xFF00
#define APP_LOG_DOMAIN 0x0001
constexpr const char *APP_LOG_TAG = "AVMetadataExtractor";
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

// 辅助函数：将 string 类型值转为napi对象并进行错误处理。
bool SetPropertyString(napi_env env, napi_value &obj, const std::string &key, const std::string &value) {
    napi_value keyNapi = nullptr;
    napi_status status = napi_create_string_utf8(env, key.c_str(), NAPI_AUTO_LENGTH, &keyNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to create string key");
        return false;
    }
    napi_value valueNapi = nullptr;
    status = napi_create_string_utf8(env, value.c_str(), NAPI_AUTO_LENGTH, &valueNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to create string value");
        return false;
    }
    status = napi_set_property(env, obj, keyNapi, valueNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to set property");
        return false;
    }
    return true;
}

// 辅助函数：将 double 类型值转为napi对象并进行错误处理。
bool SetPropertyDouble(napi_env env, napi_value &obj, const std::string &key, double value) {
    napi_value keyNapi = nullptr;
    napi_status status = napi_create_string_utf8(env, key.c_str(), NAPI_AUTO_LENGTH, &keyNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to create string key");
        return false;
    }
    napi_value valueNapi = nullptr;
    status = napi_create_double(env, value, &valueNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to create double value");
        return false;
    }
    status = napi_set_property(env, obj, keyNapi, valueNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to set property");
        return false;
    }
    return true;
}

// 辅助函数：将 int 类型值转为napi对象并进行错误处理。
bool SetPropertyInt(napi_env env, napi_value &obj, const std::string &key, int value) {
    napi_value keyNapi = nullptr;
    napi_status status = napi_create_string_utf8(env, key.c_str(), NAPI_AUTO_LENGTH, &keyNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to create string key");
        return false;
    }
    napi_value valueNapi = nullptr;
    status = napi_create_int32(env, value, &valueNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to create int value");
        return false;
    }
    status = napi_set_property(env, obj, keyNapi, valueNapi);
    if (status != napi_ok) {
        // napi_throw_error(env, "EFAILED", "Failed to set property");
        return false;
    }
    return true;
}

// 获取专辑封面。
// 需要在index.d.ts文件内描述映射的OhAVMetadataExtractorFetchAlbumCover方法。
// export const OhAVMetadataExtractorFetchAlbumCover: (fdsrc : number, size : number, offset : number) => image.PixelMap;
// 需要传入媒体文件描述符fdsrc、媒体文件大小size、媒体源在文件描述符中的偏移量offset。
// 返回PixelMap对象。
static napi_value OhAVMetadataExtractorFetchAlbumCover(napi_env env, napi_callback_info info) {
    if (!CheckArgs(env, info, 3)) {
        return nullptr;
    }
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    int64_t offset = 0;
    int32_t fileDescribe = -1;
    int64_t fileSize = 0;
    if (!GetInt32Value(env, argv[0], &fileDescribe)) return nullptr;
    if (!GetInt64Value(env, argv[1], &fileSize)) return nullptr;
    if (!GetInt64Value(env, argv[2], &offset)) return nullptr;
    // 创建OH_AVMetadataExtractor实例。
    OH_AVMetadataExtractor* mainExtractor = OH_AVMetadataExtractor_Create();
    // 处理异常。
    if (!mainExtractor) {
        napi_throw_error(env, "EFAILED", "Create metadata extractor failed");
        return nullptr;
    }
    // 设置视频资源的文件描述符。
    OH_AVErrCode avErrCode = OH_AVMetadataExtractor_SetFDSource(mainExtractor, fileDescribe, offset, fileSize);
    // 处理异常。
    if (avErrCode != AV_ERR_OK) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "SetFDSource for metadata extractor failed");
        return nullptr;
    }
    // 获取专辑封面。
    OH_PixelmapNative* pixelMap = nullptr;
    avErrCode = OH_AVMetadataExtractor_FetchAlbumCover(mainExtractor, &pixelMap);
    // 处理异常。
    if (avErrCode != AV_ERR_OK || !pixelMap) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Fetch album cover failed");
        return nullptr;
    }
    // 将nativePixelMap对象转换为PixelMapnapi对象。
    napi_value pixelmapNapi = nullptr;
    Image_ErrorCode errCode = OH_PixelmapNative_ConvertPixelmapNativeToNapi(env, pixelMap, &pixelmapNapi);
    // 释放OH_PixelmapNative资源。
    OH_PixelmapNative_Release(pixelMap);
    // 释放OH_AVMetadataExtractor资源。
    OH_AVMetadataExtractor_Release(mainExtractor);
    // 处理异常。
    if (errCode != IMAGE_SUCCESS) {
        napi_throw_error(env, "EFAILED", "Convert PixelMap failed");
        return nullptr;
    }
    return pixelmapNapi;
}

// 获取元数据。
// 需要在index.d.ts文件内描述映射的OhAVMetadataExtractorFetchMetadata方法。
// export const OhAVMetadataExtractorFetchMetadata: (fdsrc : number, size : number, offset : number) =>  media.AVMetadata;
// 需要传入媒体文件描述符fdsrc、媒体文件大小size、媒体源在文件描述符中的偏移量offset。
// 返回AVMetadata对象。
static napi_value OhAVMetadataExtractorFetchMetadata(napi_env env, napi_callback_info info) {
 if (!CheckArgs(env, info, 3)) {
        return nullptr;
    }
    size_t argc = 3;
    napi_value argv[3];
    napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
    int64_t offset = 0;
    int32_t fileDescribe = -1;
    int64_t fileSize = 0;
    if (!GetInt32Value(env, argv[0], &fileDescribe)) return nullptr;
    if (!GetInt64Value(env, argv[1], &fileSize)) return nullptr;
    if (!GetInt64Value(env, argv[2], &offset)) return nullptr;
    // 创建OH_AVMetadataExtractor实例。
    OH_AVMetadataExtractor* mainExtractor = OH_AVMetadataExtractor_Create();
    // 异常处理。
    if (!mainExtractor) {
        napi_throw_error(env, "EFAILED", "Create metadata extractor failed");
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
    // 创建OH_AVFormat对象。
    OH_AVFormat* avMetadata = OH_AVFormat_Create();
    // 异常处理。
    if (!avMetadata) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Create AVFormat failed");
        return nullptr;
    }
    // 获取元数据。
    avErrCode = OH_AVMetadataExtractor_FetchMetadata(mainExtractor, avMetadata);
    // 异常处理。
    if (avErrCode != AV_ERR_OK) {
        OH_AVFormat_Destroy(avMetadata);
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Fetch metadata failed");
        return nullptr;
    }
    napi_value JsMetadata = nullptr;
    napi_status status = napi_create_object(env, &JsMetadata);
    // 异常处理。
    if (status != napi_ok) {
        OH_AVFormat_Destroy(avMetadata);
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Create JavaScript object failed");
        return nullptr;
    }

    const char* out = nullptr;
    bool ret = false;
    // 从OH_AVFormat对象中解析出各个元数据值，再保存到JS所需的AVMetadata中。
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_ALBUM, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_ALBUM : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_ALBUM,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_ALBUM_ARTIST,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_ARTIST, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_ARTIST : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_ARTIST,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_AUTHOR, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_AUTHOR : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_AUTHOR,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_DATE_TIME, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_DATE_TIME : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_DATE_TIME,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_DATE_TIME_FORMAT,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_COMPOSER, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_COMPOSER : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_COMPOSER,out);
    }

    int64_t duration = 0;
    ret = OH_AVFormat_GetLongValue(avMetadata, OH_AVMETADATA_EXTRACTOR_DURATION, &duration);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_DURATION : %{public}lld",duration);
    if (ret) {
        out = std::to_string(duration).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_DURATION,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_GENRE, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_GENRE : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_GENRE,out);
    }

    int32_t hasAudio;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_HAS_AUDIO, &hasAudio);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_HAS_AUDIO : %{public}d",hasAudio);
    if (ret) {
        out = std::to_string(hasAudio).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_HAS_AUDIO,out);
    }

    int32_t hasVideo;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_HAS_VIDEO, &hasVideo);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_HAS_VIDEO : %{public}d",hasVideo);
    if (ret) {
        out = std::to_string(hasVideo).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_HAS_VIDEO,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_MIME_TYPE, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_MIME_TYPE : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_MIME_TYPE,out);
    }

    int32_t trackCount;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_TRACK_COUNT, &trackCount);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_NUM_TRACKS : %{public}d",trackCount);
    if (ret) {
        out = std::to_string(trackCount).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_TRACK_COUNT,out);
    }

    int32_t sampleRate;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE, &sampleRate);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE : %{public}d",sampleRate);
    if (ret) {
        out = std::to_string(sampleRate).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_SAMPLE_RATE,out);
    }

    out = nullptr;
    ret = OH_AVFormat_GetStringValue(avMetadata, OH_AVMETADATA_EXTRACTOR_TITLE, &out);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_TITLE : %{public}s",out);
    if (ret && out) {
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_TITLE,out);
    }

    int32_t videoHeight;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT, &videoHeight);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT : %{public}d",videoHeight);
    if (ret) {
        out = std::to_string(videoHeight).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_HEIGHT,out);
    }

    int32_t videoWidth;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH, &videoWidth);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH : %{public}d",videoWidth);
    if (ret) {
        out = std::to_string(videoWidth).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_WIDTH,out);
    }

    int32_t videoOrientation;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION, &videoOrientation);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION : %{public}d",videoOrientation);
    if (ret) {
        out = std::to_string(videoOrientation).c_str();
        SetPropertyString(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_ORIENTATION,out);
    }

    int32_t hdrType;
    ret = OH_AVFormat_GetIntValue(avMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID, &hdrType);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID : %{public}d ret %{public}d",hdrType, ret);
    if (ret) {
        bool hh = SetPropertyInt(env, JsMetadata, OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID,hdrType);
        H_LOGI("OH_AVMETADATA_EXTRACTOR_VIDEO_IS_HDR_VIVID : %{public}d hh %{public}d",hdrType, hh);
    }

    napi_value location = nullptr;
    napi_create_object(env, &location);
    float latitude;
    bool retLatitude = OH_AVFormat_GetFloatValue(avMetadata, OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE, &latitude);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE : %{public}f",latitude);
    if (retLatitude) {
        SetPropertyDouble(env, location, OH_AVMETADATA_EXTRACTOR_LOCATION_LATITUDE,latitude);
    }

    float longitude;
    bool retLongitude = OH_AVFormat_GetFloatValue(avMetadata, OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE, &longitude);
    H_LOGI("OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE : %{public}f",longitude);
    if (retLongitude) {
        SetPropertyDouble(env, location, OH_AVMETADATA_EXTRACTOR_LOCATION_LONGITUDE,longitude);
    }

    if (retLatitude || retLongitude) {
        napi_value keyNapi = nullptr;
        std::string key = "location";
        napi_create_string_utf8(env, key.c_str(), NAPI_AUTO_LENGTH, &keyNapi);
        napi_set_property(env, JsMetadata, keyNapi, location);
    }
    // 释放OH_AVFormat资源。
    OH_AVFormat_Destroy(avMetadata);
    // 释放OH_AVMetadataExtractor资源。
    OH_AVMetadataExtractor_Release(mainExtractor);
    return JsMetadata;
}

EXTERN_C_START
static napi_value Init(napi_env env, napi_value exports)
{
    napi_property_descriptor desc[] = {
        {"OhAVMetadataExtractorFetchAlbumCover", nullptr, OhAVMetadataExtractorFetchAlbumCover, nullptr, nullptr, 
            nullptr, napi_default, nullptr},  
        {"OhAVMetadataExtractorFetchMetadata", nullptr, OhAVMetadataExtractorFetchMetadata, nullptr, nullptr, 
            nullptr, napi_default, nullptr},
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