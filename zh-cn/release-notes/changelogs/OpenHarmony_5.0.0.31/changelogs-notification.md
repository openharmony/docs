## 应用请求通知使能接口废弃
**访问级别**

其他

**变更原因**

无context入参接口无法跟随应用窗口弹窗，与权限授权弹窗体验不一致。

**变更影响**

该变更为非兼容性变更。

开发者需要使用推荐的带context入参接口。

**API Level**

9

**变更发生版本**

从OpenHarmony API 12开始。

**变更的接口/组件**

受影响的组件：distributed_notification_service。

**适配指导**
替换使用带context入参的请求通知使能接口requestEnableNotification。

