# ArkUI子系统Changelog

## cl.arkui.1 鼠标事件回调中的XY坐标值变更

**访问级别**

公开接口

**变更原因**

在开发者为组件配置鼠标事件后，若该组件同时设置了scale、rotate、translate等图形变换属性，此时组件收到的鼠标事件回调中的XY坐标会出现错误，导致坐标无法正常使用。此变更确保了开发者能够接收到准确的鼠标事件XY坐标。


**变更影响**

该变更为不兼容变更。

变更前：开发者为组件配置了鼠标事件后，如果该组件同时设置了scale、rotate、translate等图形变换属性，此时组件接收到的鼠标事件回调中的XY坐标可能会出现错误。

变更后：开发者为组件配置了鼠标事件后，如果该组件同时配置了scale、rotate、translate等图形变换属性，此时该组件接收到的鼠标事件回调中的XY坐标正确。

**起始API Level**

API 8

**变更发生版本**

从OpenHarmony SDK 5.0.0.55开始。

**变更的接口/组件**

ArkTS的onMouse接口和Native的OH_NativeXComponent_GetMouseEvent接口。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。