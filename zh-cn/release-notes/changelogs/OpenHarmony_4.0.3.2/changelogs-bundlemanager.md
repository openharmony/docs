# 包管理子系统ChangeLog

## cl.bundlemanager.1 包管理使能系统api权限校验

包管理使能系统api权限校验，所有标有@systemapi的接口，只有系统应用允许调用。

**变更影响**<br>
包管理提供的系统api，将只有系统应用允许调用。

**关键的接口/组件变更**<br>
所有包管理系统api，对于api8及之前的接口，非系统应用调用系统api将返回错误；对于api9及之后的接口，非系统应用调用系统api将返回错误202。

**适配指导**<br>
非系统应用需要查询本身的包信息的，可以使用[@ohos.bundleManager.getBundleInfoForSelf](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)接口。