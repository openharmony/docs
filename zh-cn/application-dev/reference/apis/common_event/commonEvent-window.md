# 窗口管理子系统公共事件定义
窗口管理子系统支持发布下列系统公共事件，若需要订阅这些事件，请参见公共事件[接口文档](../js-apis-commonEventManager.md)。

### COMMON_EVENT_SPLIT_SCREEN<sup>10+</sup>
表示分屏行为的公共事件。

- 常量值： “usual.event.SPLIT_SCREEN”
- 订阅者需要的权限：无。

启动最近任务窗口、创建或销毁分屏条，都会触发通知服务发布这个系统公共事件。

