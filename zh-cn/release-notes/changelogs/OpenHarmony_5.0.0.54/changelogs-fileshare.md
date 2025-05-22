# 文件管理子系统Changelog

## cl.filemanagement.持久化权限激活接口实现从sandbox_manager模块切换到UPMS模块

**访问级别**

公开接口

**变更原因**

sandbox_manager权限清理存在时序问题，需要在临时授权中添加时间戳，所有的临时授权调节到UPMS统一添加时间戳处理。

**变更影响**

该变更为不兼容变更。

变更前：fileShare.activatePermission和OH_FileShare_ActivatePermission激活接口调用sandbox_manager接口能力实现激活功能，应用退出阶段可以进行激活持久化权限。

变更后：fileShare.activatePermission和OH_FileShare_ActivatePermission激活接口调用UPMS接口能力实现激活功能，且在应用退出阶段不能进行持久化权限激活操作（退出阶段激活的权限在退出之后也会进行权限回收，这个阶段的激活操作实际没有意义）。

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony 5.0.0.54 版本开始。

**变更的接口/组件**

@ohos.fileshare.d.ts中如下接口：[ohos.fileshare.activatePermission](../../../application-dev/reference/apis-core-file-kit/js-apis-fileShare.md)

oh_file_share.h中的NDK接口OH_FileShare_ActivatePermission： [OH_FileShare_ActivatePermission持久化授权激活接口](../../../application-dev/reference/apis-core-file-kit/oh__file__share_8h.md)

**适配指导**

开发者在使用时无需重新适配，接口内部处理流程更新。

如果开发者在应用退出阶段调用了激活接口：

变更前，会激活成功；

变更后，返回13900001错误码，提示不允许操作。

由于该阶段的激活属于无效操作，因此建议开发者删除此阶段的激活操作或者忽略此阶段的激活失败。