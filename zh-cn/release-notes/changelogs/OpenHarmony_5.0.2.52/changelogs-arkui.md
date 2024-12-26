# ArkUI子系统Changelog

## cl.arkui.1 Toast和Popup/Menu同时存在时，点击Toast子窗不再关闭Popup/Menu

**访问级别**

公开接口

**变更原因**

子窗口中显示Popup/Menu，弹出与其有相同父窗口的Toast时，Toast窗口上的点击事件会关闭Popup/Menu。

**变更影响**

该变更为不兼容变更。

变更前：点击Toast窗口时，会主动关闭与其有相同父窗口的Popup/Menu。

变更后：点击Toast窗口时，不再主动关闭与其有相同父窗口的Popup/Menu。


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.2.52开始。

**变更的接口/组件**

不涉及。

**适配指导**
默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。
