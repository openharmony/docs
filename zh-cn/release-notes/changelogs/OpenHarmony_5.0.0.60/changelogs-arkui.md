# ArkUI子系统Changelog

## cl.ArkUI.1 FormMenu实现的功能变更为不支持穿戴设备

**访问级别**

公开接口

**变更原因**

穿戴设备上禁止使用FormMenu创建“添加至桌面”菜单。

**变更影响**

该变更为不兼容变更。

变更前：FormMenu组件在穿戴设备上允许使用。

变更后：FormMenu组件在穿戴设备上禁止使用。


**起始 API Level**

API 12

**变更发生版本**

从OpenHarmony SDK 5.0.0.60开始。

**变更的接口/组件**  

@ohos.arkui.advanced.FormMenu.d.ets文件的AddFormMenuItem接口

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。
