# multimedia变更说明

## cl.multimedia.1 @ohos.multimedia.medialibrary变更

**访问级别**

系统接口与公开接口。

**变更原因**

由于工信部要求，需要能力变更。

**变更影响**

该变更为不兼容性变更，接口能力变更后，接口仍能编译成功，但是接口原本的功能无法正常使用，调用接口会抛出错误码8000001。

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