# 窗口管理子系统公共事件定义

## ArkUI

### COMMON_EVENT_SPLIT_SCREEN

表示分屏行为的公共事件。

启动最近任务窗口、创建或销毁分屏条，都会触发通知服务发布这个系统公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者需要的权限：** ohos.permission.RECEIVER_SPLIT_SCREEN

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**取值：** usual.event.SPLIT_SCREEN"