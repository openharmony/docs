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

默认行为变更，无需适配。

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

默认行为变更，无需适配。