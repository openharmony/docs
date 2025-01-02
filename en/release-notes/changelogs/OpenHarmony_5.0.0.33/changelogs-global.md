
# Globalization Changelog

## cl.global.1 Change in the Resource Matching Logic

**Access Level**

Public API

**Reason for Change**

The resources in the mcc directory cannot be obtained properly when the SIM card is inserted, affecting resource customization.

**Change Impact**

This change is a non-compatible change.

Before change: Differentiated resources such as the mcc directory are configured for an application. However, when a SIM card is inserted, resources in the default language directory are displayed. When no SIM card is inserted, resources in the mcc directory are displayed.

For example, **Wi-Fi** is displayed when a SIM card is inserted, and **WLAN** is displayed when no SIM card is inserted.

After change: When a SIM card is inserted, resources in the mcc directory are displayed. If no SIM card is inserted, resources in the default language directory are displayed.

For example, **WLAN** is displayed when a SIM card is inserted, and **Wi-Fi** is displayed when no SIM card is inserted.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.33

**Key API/Component Changes**

**SystemCapability.Global.ResourceManager** provides APIs for resource management.
For details about the APIs, see [API Reference](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-localization-kit/js-apis-resource-manager.md).

**Adaptation Guide**

Before the change, if the string **WLAN** is configured in the default language directory and the string **Wi-Fi** is configured in the mcc directory, you need to configure the string **WLAN** in the mcc directory and the string **Wi-Fi** in the default language directory.

## cl.LocalizationKit.2 Change in the raw_file Header File

**Access Level**

Public API

**Reason for Change**

The raw_file module references the string header file, which is a C++ standard library file. As a result, the raw_file module cannot be used in the C language environment.

**Change Impact**

This change is a non-compatible change.

Before change:

In the C++ environment, if you use the **raw_file.h** header file but do not reference the string header file, the compilation is successful when you call string library functions such as **std::string**.

```cpp
#include <rawfile/raw_file_manager.h>
#include <rawfile/raw_file.h>

static napi_value GetRawFileContent(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2] = {NULL};
    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
    size_t strSize;
    char strBuf[256];
    napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
    std::string filename(strBuf, strSize);   // Compilation is successful.
    RawFile *rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, filename.c_str());
}
```

After change:

In the C++ environment, if you use the **raw_file.h** header file but do not reference the string header file, the compilation fails when you call string library functions such as **std::string**.

```cpp
#include <rawfile/raw_file_manager.h>
#include <rawfile/raw_file.h>

static napi_value GetRawFileContent(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2] = {NULL};
    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
    size_t strSize;
    char strBuf[256];
    napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
    std::string filename(strBuf, strSize);   // Compilation fails.
    RawFile *rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, filename.c_str());
}
```

**Start API Level**

API 8

**Change Since**

OpenHarmony SDK 5.0.0.33

**Key API/Component Changes**

| Before Change                     | After Change                                                         |
|----------------------------|--------------------------------------------------------------|
| `#include <string>`| #include <stddef.h><br>#include <stdint.h><br>#include <stdbool.h> |

**Adaptation Guide**

In the C++ environment, if you use the **raw_file.h** header file but do not reference the string header file, you need to include the string header file so that the compilation is successful when you call string library functions such as **std::string**.

```cpp
#include <rawfile/raw_file_manager.h>
#include <rawfile/raw_file.h>
#include <string>           // Manually reference the string header file.

static napi_value GetRawFileContent(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value argv[2] = {NULL};
    napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
    napi_valuetype valueType;
    napi_typeof(env, argv[0], &valueType);
    NativeResourceManager *mNativeResMgr = OH_ResourceManager_InitNativeResourceManager(env, argv[0]);
    size_t strSize;
    char strBuf[256];
    napi_get_value_string_utf8(env, argv[1], strBuf, sizeof(strBuf), &strSize);
    std::string filename(strBuf, strSize);   // Compilation is successful.
    RawFile *rawFile = OH_ResourceManager_OpenRawFile(mNativeResMgr, filename.c_str());
}
```

## cl.global.3 raw_file API Deprecated

**Access Level**

Public API

**Reason for Change**

Reference parameters are used in **OH_ResourceManager_GetRawFileDescriptor** and **OH_ResourceManager_ReleaseRawFileDescriptor**, which affects normal use of the APIs in the C environment.

**Change Impact**

This change is a compatible change.

After the change, you need to use the substitute APIs for **OH_ResourceManager_GetRawFileDescriptor** and **OH_ResourceManager_ReleaseRawFileDescriptor**.

**Change Since**

OpenHarmony SDK 5.0.0.33

**Deprecated APIs/Components**

| API                                                                                               | Description   | Substitute API                                                                                                   |
|-----------------------------------------------------------------------------------------------------|---------|---------------------------------------------------------------------------------------------------------|
| bool OH_ResourceManager_GetRawFileDescriptor(const RawFile \*rawFile, RawFileDescriptor &descriptor) | Obtains the rawfile file descriptor.| bool OH_ResourceManager_GetRawFileDescriptorData(const RawFile \*rawFile, RawFileDescriptor \*descriptor) |
| bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor)               | Releases the rawfile file descriptor.| bool OH_ResourceManager_ReleaseRawFileDescriptorData(const RawFileDescriptor \*descriptor)               |


**Adaptation Guide**

After the change, you need to call **OH_ResourceManager_GetRawFileDescriptorData** to obtain the rawfile descriptor to read the rawfile content, and call **OH_ResourceManager_ReleaseRawFileDescriptorData** to release the obtained rawfile descriptor.

## cl.global.4 ohresmgr API Deprecated

**Access Level**

Public API

**Reason for Change**

Optional parameters are used in certain ohresmgr APIs, which affects normal use of these APIs in the C environment.

**Change Impact**

This change is a compatible change.

The ohresmgr APIs that use optional parameters are deprecated and you are advised to use the substitute APIs.

**Change Since**

OpenHarmony SDK 5.0.0.33

**Deprecated APIs/Components**

| API                                                                                                                                                                                                                       | Description   | Substitute API                                                                                                                                                                                                                   |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager \*mgr, uint32_t resId,     char \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                            | Obtains the Base64 code of a media file based on the resource ID.| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager \*mgr, uint32_t resId,     char \*\*resultValue, uint64_t \*resultLen, uint32_t density)                                        |
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager \*mgr,     const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                 | Obtains the Base64 code of a media file based on the resource name.| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager \*mgr,     const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density)                             |
| ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager \*mgr, uint32_t resId,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                               | Obtains the content of a media file based on the resource ID.| ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager \*mgr, uint32_t resId,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density)                                           |
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager \*mgr, const char \*resName,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                    | Obtains the content of a media file based on the resource name.| ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager \*mgr, const char \*resName,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density)                                |
| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager \*mgr,     uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density = 0, uint32_t type = 0)            | Obtains the file descriptor or an image based on the resource ID.| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager \*mgr,     uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type)            |
| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager \*mgr,     const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density = 0, uint32_t type = 0) | Obtains the file descriptor or an image based on the resource name.| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager \*mgr,     const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type) |
| ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager \*mgr, char \*\*\*resultValue,     uint32_t \*resultLen, bool includeSystem = false)                                                         | Obtains the current language and locale.| ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager \*mgr, char \*\*\*resultValue,     uint32_t \*resultLen, bool includeSystem)                                                         |


**Adaptation Guide**

Substitute APIs that use optional parameters with new APIs.

ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager \*mgr, uint32_t resId,
    char \*\*resultValue, uint64_t \*resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager \*mgr,
    const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager \*mgr, uint32_t resId,
    uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager \*mgr, const char \*resName,
    uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager \*mgr,
    uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type);

ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager \*mgr,
    const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type);

ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager \*mgr, char \*\*\*resultValue,
    uint32_t \*resultLen, bool includeSystem);
