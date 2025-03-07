# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理AbilityInfo.d.ts中新增必选属性orientationId。

包管理[AbilityInfo.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/bundleManager/AbilityInfo.d.ts)中新增必选属性orientationId。

**访问级别**
公开接口

**变更原因**
按照终端设备用户的使用习惯，应用应当能够根据设备类型配置默认的窗口旋转方式，应用在orientation配置资源引用，使用时根据资源ID orientationId解析具体配置。

**变更影响**<br>
此变更涉及应用适配。

变更前：应用在构造AbilityInfo时编译无问题。
变更后：应用在构造AbilityInfo时需要添加必选参数orientationId。

**起始 API Level**
API 9

**变更发生版本**
从OpenHarmony SDK 5.0.2.57开始。

**关键的接口/组件变更**<br>
AbilityInfo.d.ts中新增必选属性orientationId。

**适配指导**<br>
升级到API14后，如果应用在自己的业务中构造了AbilityInfo结构体，则需要在构造的AbilityInfo结构体中新增必选属性orientationId。