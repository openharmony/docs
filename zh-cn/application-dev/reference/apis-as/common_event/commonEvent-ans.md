# 通知服务公共事件定义
通知服务面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_SLOT_CHANGE
表示通知渠道或通知开关发生变化。

- 常量值："usual.event.SLOT_CHANGE"
- 订阅方需要的权限：ohos.permission.NOTIFICATION_CONTROLLER

通知设置里修改应用的渠道参数、渠道开关，或者开启、关闭通知使能开关时，都会触发通知服务发布这个系统公共事件。

与这个公共事件相关的接口：setSlotByBundle、setNotificationEnableSlot、setNotificationEnable，这些为系统API，一般都是通知设置应用调用，具体参看[通知接口文档](../js-apis-notificationManager.md)。

