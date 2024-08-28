# ArkUI子系统Changelog

## hideNonSecureWindows接口使用权限变更

**访问级别**

系统接口

**变更原因**

模态UIExtension默认隐藏不安全窗口且不允许取消隐藏，造成部分场景UX体验不佳。

**变更影响**

该变更为兼容变更。

变更前：模态UIExtension默认隐藏不安全窗口且不允许取消隐藏。

变更后：模态UIExtension默认隐藏不安全窗口，申请ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS权限后可取消隐藏。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.1.1开始。

**变更的接口/组件**

CreateModalUIExtension和hideNonSecureWindows接口。

**适配指导**

为避免不安全窗口先隐藏再显示导致闪烁，模态UIExtension在申请ohos.permission.ALLOW_SHOW_NON_SECURE_WINDOWS权限后，可以在``onSessionCreate``函数中调用``hideNonSecureWindows(false)``接口取消对不安全窗口的隐藏。此时应用需自行确保自身内容不会被遮挡，建议使用``createSubWindowWithOptions``接口创建模态置顶子窗，并将内容都加载在子窗中。