# multimedia变更说明

## cl.multimedia.1 @ohos.multimedia.medialibrary变更

**访问级别**

系统接口与公开接口。

**变更原因**

根据工信部关于应用软件调用行为记录能力要求，需要进行媒体库接口能力变更。

**变更影响**

该变更为不兼容性变更。

@ohos.multimedia.medialibrary模块中的所有接口将从SDK中删除，不再支持新开发应用使用，历史代码工程编译报错。

针对已上架的应用，medialibrary接口原本的功能无法正常使用，调用接口会抛出错误码8000001。

**起始 API Level**

6

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

@ohos.multimedia.medialibrary模块中的所有接口。

**适配指导**

开发者需停止使用@ohos.multimedia.medialibrary模块，并使用@ohos.file.photoAccessHelper模块替代实现相关功能。

单个接口的替代关系可参考[原medialibrary接口文档](../../../application-dev/reference/apis-media-library-kit/js-apis-medialibrary.md)。

新接口使用指南请参考 [Media Library Kit使用指导](../../../application-dev/media/medialibrary/photoAccessHelper-overview.md)。

## cl.multimedia.2 @ohos.multimedia.movingphotoview变更

**访问级别**

系统接口与公开接口。

**变更原因**

此变更为MovingphotoView接口SysCap变更，MovingPhotoView从通用ArkUI组件的归属划分为Media Library Kit的UI组件，MovingPhotoView接口SysCap从SystemCapability.ArkUI.ArkUI.Full修改为SystemCapability.FileManagement.PhotoAccessHelper.Core。

**变更影响**

此变更为不兼容变更

变更前：根据API文档内容表达的是“使用canIUse("SystemCapability.ArkUI.ArkUI.Full")判断是否可以使用MovingPhotoView组件”。

变更后：根据API文档内容表达的是“使用canIUse("SystemCapability.FileManagement.PhotoAccessHelper.Core")判断是否可以使用MovingPhotoView组件”。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.33开始。

**变更的接口/组件**

@ohos.multimedia.movingphotoview模块中的所有接口。

**适配指导**

开发者需停止使用canIUse("SystemCapability.ArkUI.ArkUI.Full")判断是否可以使用MovingPhotoView组件，并使用canIUse("SystemCapability.FileManagement.PhotoAccessHelper.Core")判断是否可以使用MovingPhotoView组件