# 屏幕管理简介

屏幕管理主要是针对设备的各种屏幕（包括物理屏、虚拟屏、折叠屏）进行管理，管理其各种属性信息，并当做广播者，将监听到的信息广播给各个需要屏幕信息的订阅服务。

屏幕管理主要包括以下几方面能力：

- 可获取屏幕当前的属性信息，包括屏幕分辨率、物理像素密度、屏幕尺寸等。
- 可监听屏幕发生的各种事件变化，包括屏幕旋转变化、屏幕分辨率变化、屏幕刷新率变化、折叠状态变化等。
- 提供虚拟屏的创建和使用，此部分能力仅对系统应用开放。

针对屏幕属性相关信息的查询和监听，可见[使用OH_DisplayManager实现屏幕基础信息查询和状态监听 (C/C++)](native-display-manager.md)和[使用Display实现屏幕属性查询及状态监听 (ArkTS)](screenProperty-guideline.md)<!--Del-->，虚拟屏的相关使用具体可见[虚拟屏的创建和使用 (ArkTS) (仅对系统应用开放)](virtualScreen-guideline.md)<!--DelEnd-->。

## 约束和限制

- 需要在支持SystemCapability.Window.SessionManager能力的系统上使用Display和Screen接口，更详细的系统能力请参考[系统能力SystemCapability使用指南](../reference/syscap.md)。
- 在多屏实现中，Screen接口仅支持系统应用使用，且部分接口需要申请ohos.permission.CAPTURE_SCREEN权限。