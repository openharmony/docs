# 全球化子系统接口废弃说明

## cl.golbal.1 raw_file模块接口废弃

**访问级别**

公开接口

**废弃原因**

接口中使用了引用参数，影响接口在C语言环境下正常使用

**废弃影响**

该变更为非兼容变更

  1.若变更后开发者引用了string库函数，且未手动引入string库头文件，则会出现编译不过的问题

  2.变更前开发者使用了 OH_ResourceManager_GetRawFileDescriptor 和OH_ResourceManager_ReleaseRawFileDescriptor 接口，变更后则需要适配新的接口。


**废弃发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**废弃的接口/组件**

| 接口声明                                                                                                | 废弃说明    | 替代接口                                                                                                    |
|-----------------------------------------------------------------------------------------------------|---------|---------------------------------------------------------------------------------------------------------|
| bool OH_ResourceManager_GetRawFileDescriptor(const RawFile *rawFile, RawFileDescriptor &descriptor) | 使用接口获取rawfile文件描述符 | bool OH_ResourceManager_GetRawFileDescriptorData(const RawFile *rawFile, RawFileDescriptor *descriptor) |
| bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor)               | 使用接口释放rawfile文件描述符 | bool OH_ResourceManager_ReleaseRawFileDescriptorData(const RawFileDescriptor *descriptor)               |


**适配指导**

1.若开发者在变更前引用了string库函数，且未手动引入string库头文件依赖raw_file.h头文件，可以通过引入#include 解决。

2.变更后则需要适配新的接口，调用新接口 OH_ResourceManager_GetRawFileDescriptorData 获取rawfile文件描述符来读取rawfile文件内容，调用新接口 OH_ResourceManager_ReleaseRawFileDescriptorData 来释放已获取到的rawfile文件描述符

## cl.golbal.2 ohresmgr模块接口废弃

**访问级别**

公开接口

**废弃原因**

接口中使用了可选参数，影响接口在c语言环境下正常使用

**废弃影响**

该变更为非兼容变更

接口已废弃不推荐使用，推荐使用新接口，若使用废弃接口会导致后续版本出现接口异


**废弃发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**废弃的接口/组件**

| 接口声明                                                                                                                                                                                                                        | 废弃说明    | 替代接口                                                                                                                                                                                                                    |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId,     char **resultValue, uint64_t *resultLen, uint32_t density = 0)                                            | 使用接口通过资源id获取媒体文件base64编码值 | ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager *mgr, uint32_t resId,     char **resultValue, uint64_t *resultLen, uint32_t density)                                        |
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr,     const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0)                                 | 使用接口通过资源名称获取媒体文件base64编码值| ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager *mgr,     const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density)                             |
| ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId,     uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)                                               | 使用接口通过资源id获取媒体文件内容 | ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager *mgr, uint32_t resId,     uint8_t **resultValue, uint64_t *resultLen, uint32_t density)                                           |
| ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager *mgr, const char *resName,     uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0)                                    | 使用接口通过资源名称获取媒体文件内容 | ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager *mgr, const char *resName,     uint8_t **resultValue, uint64_t *resultLen, uint32_t density)                                |
| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr,     uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0)            | 使用接口通过资源id获取图片的描述符 | ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager *mgr,     uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type)            |
| ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr,     const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0) | 使用接口通过资源名称获取图片的描述符 | ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager *mgr,     const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type) |
| ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager *mgr, char ***resultValue,     uint32_t *resultLen, bool includeSystem = false)                                                         | 使用接口获取当前语言和地区信息 | ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager *mgr, char ***resultValue,     uint32_t *resultLen, bool includeSystem)                                                         |


**适配指导**

开发者需要停止使用可选参数的函数接口，在新版本开发过程中，使用新接口。

ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(const NativeResourceManager *mgr, uint32_t resId,
    char **resultValue, uint64_t *resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(const NativeResourceManager *mgr,
    const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(const NativeResourceManager *mgr, uint32_t resId,
    uint8_t **resultValue, uint64_t *resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(const NativeResourceManager *mgr, const char *resName,
    uint8_t **resultValue, uint64_t *resultLen, uint32_t density);

ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(const NativeResourceManager *mgr,
    uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type);

ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(const NativeResourceManager *mgr,
    const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density, uint32_t type);

ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(const NativeResourceManager *mgr, char ***resultValue,
    uint32_t *resultLen, bool includeSystem);