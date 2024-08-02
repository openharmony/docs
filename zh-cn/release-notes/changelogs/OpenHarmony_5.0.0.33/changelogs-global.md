
# 全球化子系统变更说明

## cl.global.1 资源匹配逻辑变更

**访问级别**

公开接口

**变更原因**

插入SIM卡时未能获取到正确的mcc目录资源，影响开发者差异化定制资源。

**变更影响**

该变更为不兼容变更。

变更前：应用配置了mcc目录等差异化资源，插sim卡显示的是默认语言目录下资源，未插sim卡显示的是mcc目录下资源。

如：插卡时会显示“Wi-Fi”字串，不插卡时会显示“WLAN”字串。

变更后：插sim卡显示的是mcc目录下资源，未插sim卡显示的是默认语言目录下资源。

如：插卡时会显示“WLAN”字串，不插卡时会显示“Wi-Fi”字串。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

SystemCapability.Global.ResourceManager获取资源相关接口。
相关接口查看[接口文档](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-localization-kit/js-apis-resource-manager.md)

**适配指导**

变更前开发者如果有在默认语言目录配置“WLAN”字串，mcc目录配置“Wi-Fi”字串，变更后需要适配将“WLAN”字串配置在mcc目录，“Wi-Fi”字串配置在默认语言目录。

## cl.golbal.2 string头文件变更

**访问级别**

公开接口

**变更原因**

string库文件是C++标准库，影响头文件在C语言环境下正常使用。

**变更影响**

该变更为不兼容变更

变更前：开发者使用了raw_file.h头文件，但没有引用string头文件，调用了"std::string"等string库函数。

变更后：会出现编译不过的情况。

**起始API Level**

API 8

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

| 变更前               | 变更后                                                          |
|-------------------|--------------------------------------------------------------|
| #include <string><br>| #include <stddef.h><br>#include <stdint.h><br>#include <stdbool.h> |

**适配指导**

1、开发者使用raw_file.h头文件，但没有引用string头文件，调用了"std::string"等string库函数，需要进行适配，通过include引入string头文件即可解决。

2、开发者使用raw_file.h头文件且引用了string头文件，无需进行适配。

3、开发者仅使用raw_file.h头文件，没有调用string库函数，无需进行适配。

## cl.golbal.3 raw_file模块接口废弃

**访问级别**

公开接口

**废弃原因**

接口中使用了引用参数，影响接口在C语言环境下正常使用。

**废弃影响**

该变更为兼容性变更

变更前开发者使用了 OH_ResourceManager_GetRawFileDescriptor 和OH_ResourceManager_ReleaseRawFileDescriptor 接口，变更后则需要适配新的接口。

**废弃发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**废弃的接口/组件**

| 接口声明                                                                                                | 废弃说明    | 替代接口                                                                                                    |
|-----------------------------------------------------------------------------------------------------|---------|---------------------------------------------------------------------------------------------------------|
| bool OH_ResourceManager_GetRawFileDescriptor(const RawFile \*rawFile, RawFileDescriptor &descriptor) | 使用接口获取rawfile文件描述符 | bool OH_ResourceManager_GetRawFileDescriptorData(const RawFile \*rawFile, RawFileDescriptor \*descriptor) |
| bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor)               | 使用接口释放rawfile文件描述符 | bool OH_ResourceManager_ReleaseRawFileDescriptorData(const RawFileDescriptor \*descriptor)               |


**适配指导**

变更后则需要适配新的接口，调用新接口 OH_ResourceManager_GetRawFileDescriptorData 获取rawfile文件描述符来读取rawfile文件内容，调用新接口 OH_ResourceManager_ReleaseRawFileDescriptorData 来释放已获取到的rawfile文件描述符。

## cl.golbal.4 ohresmgr模块接口废弃

**访问级别**

公开接口

**废弃原因**

接口中使用了可选参数，影响接口在c语言环境下正常使用。

**废弃影响**

该变更为兼容性变更

接口已废弃不推荐使用，推荐适配使用新接口。

**废弃发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**废弃的接口/组件**

| 接口声明                                                                                                                                                                                                                        | 废弃说明    | 替代接口                                                                                                                                                                                                                    |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager \*mgr, uint32_t resId,     char \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                            | 使用接口通过资源id获取媒体文件base64编码值 | ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager \*mgr, uint32_t resId,     char \*\*resultValue, uint64_t \*resultLen, uint32_t density)                                        |
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager \*mgr,     const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                 | 使用接口通过资源名称获取媒体文件base64编码值| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager \*mgr,     const char \*resName, char \*\*resultValue, uint64_t \*resultLen, uint32_t density)                             |
| ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager \*mgr, uint32_t resId,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                               | 使用接口通过资源id获取媒体文件内容 | ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager \*mgr, uint32_t resId,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density)                                           |
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager \*mgr, const char \*resName,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density = 0)                                    | 使用接口通过资源名称获取媒体文件内容 | ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager \*mgr, const char \*resName,     uint8_t \*\*resultValue, uint64_t \*resultLen, uint32_t density)                                |
| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager \*mgr,     uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density = 0, uint32_t type = 0)            | 使用接口通过资源id获取图片的描述符 | ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager \*mgr,     uint32_t resId, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type)            |
| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager \*mgr,     const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density = 0, uint32_t type = 0) | 使用接口通过资源名称获取图片的描述符 | ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager \*mgr,     const char \*resName, ArkUI_DrawableDescriptor \*\*drawableDescriptor, uint32_t density, uint32_t type) |
| ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager \*mgr, char \*\*\*resultValue,     uint32_t \*resultLen, bool includeSystem = false)                                                         | 使用接口获取当前语言和地区信息 | ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager \*mgr, char \*\*\*resultValue,     uint32_t \*resultLen, bool includeSystem)                                                         |


**适配指导**

开发者需要停止使用可选参数的函数接口，在新版本开发过程中，使用新接口。

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