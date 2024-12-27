# ArkUI子系统Changelog

## cl.arkui.1 Navigation的toolbarConfiguration属性行为变更

**访问级别**

公开接口

**变更原因**

Navigation的toolbarConfiguration属性，不支持在ArkTS卡片中使用。

**变更影响**

该变更为不兼容变更。

变更前：toolbarConfiguration属性，支持在ArkTS卡片中使用。

变更后：toolbarConfiguration属性，不支持在ArkTS卡片中使用。

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.0.0.60开始。

**变更的接口/组件**

navigation.d.ts文件的toolbarConfiguration属性。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.2 uiObserver的NavDestinationState枚举行为变更

**访问级别**

公开接口

**变更原因**

uiObserver的NavDestinationState枚举，不支持在ArkTS卡片中使用。

**变更影响**

该变更为不兼容变更。

变更前：NavDestinationState枚举，支持在ArkTS卡片中使用。

变更后：NavDestinationState枚举，不支持在ArkTS卡片中使用。

**起始API Level**

API 10

**变更发生版本**

从OpenHarmony SDK 5.0.0.60开始。

**变更的接口/组件**

@ohos.arkui.observer.d.ts文件的NavDestinationState枚举。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.ArkUI.3 FormMenu实现的功能变更为不支持穿戴设备

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