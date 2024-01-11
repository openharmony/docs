# 事件通知子系统ChangeLog

## cl.ans.1 事件通知子系统isRemoveAllowed权限变更

**访问级别**

系统接口

**变更原因**

通知的isRemoveAllowed属性即不可移除属性，需要进行权限管控。

**变更影响**

该变更为不兼容变更。
使用isRemoveAllowed属性时，开发者需提前申请ohos.permission.SET_UNREMOVABLE_NOTIFICATION

**API Level**

11

**变更发生版本**

从Openharmony SDK 4.1.5.5 开始

**变更的接口/组件**

isRemoveAllowed增加权限ohos.permission.SET_UNREMOVABLE_NOTIFICATION

**适配指导**

开发者需申请权限适配
变更后需要申请ohos.permission.SET_UNREMOVABLE_NOTIFICATION