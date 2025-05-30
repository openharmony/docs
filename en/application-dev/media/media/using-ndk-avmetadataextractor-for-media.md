# Using AVMetadataExtractor to Obtain Metadata (C/C++)

You can use the AVMetadataExtractor to obtain metadata from a raw media asset. This topc walks you through on how to obtain the metadata of an audio asset. The process of obtaining the metadata of a video asset is similar. The only difference is that the process of obtaining the album cover is not required for a video asset, because no album cover is available in the video asset.

The full process of obtaining the metadata of an audio asset includes creating an AVMetadataExtractor instance, setting resources, obtaining the metadata, obtaining the album cover, and releasing the instance.

## How to Develop
Link the dynamic library in the CMake script.
```
target_link_libraries(entry PUBLIC libavmetadata_extractor.so libace_napi.z.so )
```

To use [OH_AVFormat](../../reference/apis-avcodec-kit/_core.md#oh_avformat) APIs, include the following header file:
```
#include <multimedia/player_framework/native_avformat.h>
```

In addition, link the following dynamic link library in the CMake script:
```
target_link_libraries(entry PUBLIC libnative_media_core.so)
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

You can use the APIs related to metadata retrieval by including the header files [avmetadata_extractor.h](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md), [avmetadata_extractor_base.h](../../reference/apis-media-kit/capi-avmetadata-extractor-base-h.md), and [native_averrors.h](../../reference/apis-avcodec-kit/native__averrors_8h.md).

Read [AVMetadataExtractor](../../reference/apis-media-kit/capi-avmetadataextractor.md) for the API reference.

1. Call [OH_AVMetadataExtractor_Create()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_create) to create an instance.

2. Call [OH_AVMetadataExtractor_SetFDSoucre()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_setfdsource) to set the file descriptor of a video resource.
   
   If different AVMetadataExtractor or [AVImageGenerator](../../reference/apis-media-kit/capi-avimagegenerator.md) instances need to operate the same resource, the file descriptor needs to be opened for multiple times. Therefore, do not share a file descriptor.

3. Call [OH_AVMetadataExtractor_FetchMetadata()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchmetadata) to obtain metadata.
   
   First, call **OH_AVFormat_Create()** to create an **OH_AVFormat** object and obtain the metadata by accessing the key-value pairs of the object. When the object is no longer required, call **OH_AVFormat_Destroy** to release the object to prevent memory leakage. For details, see [OH_AVFormat](../../reference/apis-avcodec-kit/_core.md#oh_avformat).

4. (Optional) Call [OH_AVMetadataExtractor_FetchAlbumCover()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_fetchalbumcover) to obtain the album cover.
   
   When the object is no longer required, call **OH_PixelmapNative_Release** to release the object. For details, see [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md).

5. Call [OH_AVMetadataExtractor_Release()](../../reference/apis-media-kit/capi-avmetadata-extractor-h.md#oh_avmetadataextractor_release) to destroy the instance and release resources.


## Development Example

Refer to the sample code below to set the file descriptor and obtain the metadata and album cover of an audio asset.

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

// Auxiliary function: Convert a value of the string type to a napi object and perform error processing.
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

// Auxiliary function: Convert a value of the double type to a napi object and perform error processing.
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

// Auxiliary function: Convert a value of the int type to a napi object and perform error processing.
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

// Obtain the album cover.
// Describe the mapped OhAVMetadataExtractorFetchAlbumCover method in the index.d.ts file.
// export const OhAVMetadataExtractorFetchAlbumCover: (fdsrc : number, size : number, offset : number) => image.PixelMap;
// Pass the media file descriptor (fdsrc), media file size (size), and offset of the media source in the file descriptor (offset).
// Return a PixelMap object.
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
    // Create an OH_AVMetadataExtractor instance.
    OH_AVMetadataExtractor* mainExtractor = OH_AVMetadataExtractor_Create();
    // Handle exceptions.
    if (!mainExtractor) {
        napi_throw_error(env, "EFAILED", "Create metadata extractor failed");
        return nullptr;
    }
    // Set the file descriptor of the video resource.
    OH_AVErrCode avErrCode = OH_AVMetadataExtractor_SetFDSource(mainExtractor, fileDescribe, offset, fileSize);
    // Handle exceptions.
    if (avErrCode != AV_ERR_OK) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "SetFDSource for metadata extractor failed");
        return nullptr;
    }
    // Obtain the album cover.
    OH_PixelmapNative* pixelMap = nullptr;
    avErrCode = OH_AVMetadataExtractor_FetchAlbumCover(mainExtractor, &pixelMap);
    // Handle exceptions.
    if (avErrCode != AV_ERR_OK || !pixelMap) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Fetch album cover failed");
        return nullptr;
    }
    // Convert the nativePixelMap object into a PixelMapnapi object.
    napi_value pixelmapNapi = nullptr;
    Image_ErrorCode errCode = OH_PixelmapNative_ConvertPixelmapNativeToNapi(env, pixelMap, &pixelmapNapi);
    // Release the OH_PixelmapNative resource.
    OH_PixelmapNative_Release(pixelMap);
    // Release the OH_AVMetadataExtractor resource.
    OH_AVMetadataExtractor_Release(mainExtractor);
    // Handle exceptions.
    if (errCode != IMAGE_SUCCESS) {
        napi_throw_error(env, "EFAILED", "Convert PixelMap failed");
        return nullptr;
    }
    return pixelmapNapi;
}

// Obtain the metadata.
// Describe the mapped OhAVMetadataExtractorFetchMetadata method in the index.d.ts file.
// export const OhAVMetadataExtractorFetchMetadata: (fdsrc : number, size : number, offset : number) =>  media.AVMetadata;
// Pass the media file descriptor (fdsrc), media file size (size), and offset of the media source in the file descriptor (offset).
// Return the AVMetadata object.
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
    // Create an OH_AVMetadataExtractor instance.
    OH_AVMetadataExtractor* mainExtractor = OH_AVMetadataExtractor_Create();
    // Handle exceptions.
    if (!mainExtractor) {
        napi_throw_error(env, "EFAILED", "Create metadata extractor failed");
        return nullptr;
    }
    // Set the file descriptor of the video resource.
    OH_AVErrCode avErrCode = OH_AVMetadataExtractor_SetFDSource(mainExtractor, fileDescribe, offset, fileSize);
    // Handle exceptions.
    if (avErrCode != AV_ERR_OK) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "SetFDSource for metadata extractor failed");
        return nullptr;
    }
    // Create an OH_AVFormat object.
    OH_AVFormat* avMetadata = OH_AVFormat_Create();
    // Handle exceptions.
    if (!avMetadata) {
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Create AVFormat failed");
        return nullptr;
    }
    // Obtain the metadata.
    avErrCode = OH_AVMetadataExtractor_FetchMetadata(mainExtractor, avMetadata);
    // Handle exceptions.
    if (avErrCode != AV_ERR_OK) {
        OH_AVFormat_Destroy(avMetadata);
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Fetch metadata failed");
        return nullptr;
    }
    napi_value JsMetadata = nullptr;
    napi_status status = napi_create_object(env, &JsMetadata);
    // Handle exceptions.
    if (status != napi_ok) {
        OH_AVFormat_Destroy(avMetadata);
        OH_AVMetadataExtractor_Release(mainExtractor);
        napi_throw_error(env, "EFAILED", "Create JavaScript object failed");
        return nullptr;
    }

    const char* out = nullptr;
    bool ret = false;
    // Parse each metadata value from the OH_AVFormat object and save the value to the AVMetadata required by JS.
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
    // Release the OH_AVFormat resource.
    OH_AVFormat_Destroy(avMetadata);
    // Release the OH_AVMetadataExtractor resource.
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
