# multimedia变更说明

## cl.multimedia.1 @ohos.multimedia.movingphotoview变更

**访问级别**

系统接口与公开接口。

**变更原因**

此变更为MovingphotoView接口SysCap变更，MovingPhotoView是基于ArkUI框架开发的媒体库能力组件，根据能力组件归属从通用ArkUI组件划分为Media Library Kit的UI组件，MovingPhotoView接口SysCap从SystemCapability.ArkUI.ArkUI.Full修改为SystemCapability.FileManagement.PhotoAccessHelper.Core。

**变更影响**

此变更为不兼容变更，仅对接口所依赖的SystemCapability进行调整，对接口本身的使用方式无影响。

变更前：

该组件的系统能力要求为“SystemCapability.ArkUI.ArkUI.Full”。判断设备是否支持使用MovingPhotoView组件需使用canIUse("SystemCapability.ArkUI.ArkUI.Full")。

变更后：

该组件的系统能力要求为“SystemCapability.FileManagement.PhotoAccessHelper.Core”。判断设备是否支持使用MovingPhotoView组件需改为使用canIUse("SystemCapability.FileManagement.PhotoAccessHelper.Core")。

**起始 API Level**

12

**变更发生的版本**

从OpenHarmony SDK 5.0.0.27开始。

**变更的接口/组件**

@ohos.multimedia.movingphotoview模块中的所有接口。

**适配指导**

当前SDK默认定义的device-define都同时包含或同时不包含SystemCapability.ArkUI.ArkUI.Full和SystemCapability.FileManagement.PhotoAccessHelper.Core，因此涉及MovingPhotoView组件的功能代码原则上无需适配。但如果代码中涉及调用canIUse()方法对MovingPhotoView组件的支持情况进行判断，则应修改canIUse()方法传入的SystemCapability。