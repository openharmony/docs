# ArkUI子系统Changelog

## cl.arkui.1 ToastShowMode.TOP_MOST接口废弃

**访问级别**

公开接口

**变更原因**

TOP_MOST模式层级高，可以通过Toast形成遮挡劫持，有安全风险。

**变更影响**

该变更为不兼容变更。

变更前：设置ToastShowMode.TOP_MOST时，Toast 显示在应用之上。

变更后：设置ToastShowMode.TOP_MOST时，Toast 显示在应用内, 与ToastShowMode.DEFAULT行为一致。

**起始API Level**

11

**变更发生版本**

从OpenHarmony 5.0.0.38 版本开始。

**变更的接口/组件**

ToastShowMode.TOP_MOST。

**适配指导**

使用ToastShowMode.DEFAULT代替ToastShowMode.TOP_MOST。

