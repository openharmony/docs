# 全球化子系统变更说明

## cl.golbal.1 raw_file.h头文件接口变更

**访问级别**

公开接口

**变更原因**

接口中使用了引用参数，不符合CAPI标准规范

**变更影响**

该变更为非兼容变更
1、变更前开发者引用了string库函数，且未手动引入string库头文件依赖raw_file.h头文件传递进来，变更后需要手动引入string库函数
2、变更前开发者使用了OH_ResourceManager_GetRawFileDescriptor和OH_ResourceManager_ReleaseRawFileDescriptor接口，变更后需要适配新的接口

**起始 API Level**

API 8

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

bool OH_ResourceManager_GetRawFileDescriptor(const RawFile *rawFile, RawFileDescriptor &descriptor);
bool OH_ResourceManager_ReleaseRawFileDescriptor(const RawFileDescriptor &descriptor);

**适配指导**

1、开发者需要排查是否使用了string库函数，如果使用了且未引入string库头文件，可以通过手动引入#include <string>解决
2、开发者需要停止使用OH_ResourceManager_GetRawFileDescriptor和OH_ResourceManager_ReleaseRawFileDescriptor接口来操作RawFile文件，
并使用新接口OH_ResourceManager_GetRawFileDescriptorData和OH_ResourceManager_ReleaseRawFileDescriptorData接口来操作RawFile文件。
示例如下：
RawFileDescriptor *descriptor = new RawFileDescriptor();
OH_ResourceManager_GetRawFileDescriptorData(RawFile, descriptor);
OH_ResourceManager_ReleaseRawFileDescriptorData(descriptor);

## cl.golbal.2 ohresmgr.h头文件接口变更

**访问级别**

公开接口

**变更原因**

接口中使用了可选参数，不符合CAPI标准规范

**变更影响**

该变更为非兼容变更
变更前开发者使用了可选参数的函数接口，变更后适配新的接口

**起始 API Level**

API 12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64(const NativeResourceManager *mgr, uint32_t resId,
    char **resultValue, uint64_t *resultLen, uint32_t density = 0);
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64ByName(const NativeResourceManager *mgr,
    const char *resName, char **resultValue, uint64_t *resultLen, uint32_t density = 0);
ResourceManager_ErrorCode OH_ResourceManager_GetMedia(const NativeResourceManager *mgr, uint32_t resId,
    uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0);
ResourceManager_ErrorCode OH_ResourceManager_GetMediaByName(const NativeResourceManager *mgr, const char *resName,
    uint8_t **resultValue, uint64_t *resultLen, uint32_t density = 0);
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptor(const NativeResourceManager *mgr,
    uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0);
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorByName(const NativeResourceManager *mgr,
    const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, uint32_t density = 0, uint32_t type = 0);
ResourceManager_ErrorCode OH_ResourceManager_GetLocales(const NativeResourceManager *mgr, char ***resultValue,
    uint32_t *resultLen, bool includeSystem = false);

**适配指导**

开发者需要停止使用可选参数的函数接口，替换为新的接口
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64Data(NativeResourceManager *mgr, uint32_t resId,
    char **resultValue, uint64_t *resultLen, 0);
ResourceManager_ErrorCode OH_ResourceManager_GetMediaBase64DataByName(NativeResourceManager *mgr,
    const char *resName, char **resultValue, uint64_t *resultLen, 0);
ResourceManager_ErrorCode OH_ResourceManager_GetMediaData(NativeResourceManager *mgr, uint32_t resId,
    uint8_t **resultValue, uint64_t *resultLen, 0);
ResourceManager_ErrorCode OH_ResourceManager_GetMediaDataByName(NativeResourceManager *mgr, const char *resName,
    uint8_t **resultValue, uint64_t *resultLen, 0);
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorData(NativeResourceManager *mgr,
    uint32_t resId, ArkUI_DrawableDescriptor **drawableDescriptor, 0, 0);
ResourceManager_ErrorCode OH_ResourceManager_GetDrawableDescriptorDataByName(NativeResourceManager *mgr,
    const char *resName, ArkUI_DrawableDescriptor **drawableDescriptor, 0, 0);
ResourceManager_ErrorCode OH_ResourceManager_GetLocalesData(NativeResourceManager *mgr, char ***resultValue,
    uint32_t *resultLen, false);