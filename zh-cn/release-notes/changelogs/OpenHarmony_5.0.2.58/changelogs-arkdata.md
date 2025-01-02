# ArkData子系统Changelog

## cl.arkdata.1 UDMF @ohos.data.unifiedDataChannel.d.ts中setAppShareOptions、removeAppShareOptions、DRAG更改system API为public API，接口所需权限变更。

**访问级别**

系统接口->公开接口

**变更原因**

设置或者删除本应用数据的拖拽范围接口需开放为public API。

**变更影响**

该变更为不兼容变更。

变更前：SetAppShareOptions()和RemoveAppShareOptions()以及DRAG枚举为System Api，只有系统应用可以调用。应用设置或者删除本应用数据的拖拽范围时不会校验ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION。

变更后：SetAppShareOptions()和RemoveAppShareOptions()以及DRAG枚举为Public Api，申请权限ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION的普通应用可以调用。如未申请，应用在设置或者删除本应用数据的拖拽范围时，访问会被拦截。

**起始API Level** 

12

**变更发生版本**

从OpenHarmony SDK 5.0.2.58开始。

**变更的接口/组件**

1. function setAppShareOptions(intention: Intention, shareOptions: ShareOptions): void;

2. function removeAppShareOptions(intention: Intention): void;

3. DRAG = 'Drag'

**适配指导**

应用需申请受限权限ohos.permission.MANAGE_UDMF_APP_SHARE_OPTION，申请方式可参考[申请使用受限权限](../../../application-dev/security/AccessToken/declare-permissions-in-acl.md)。