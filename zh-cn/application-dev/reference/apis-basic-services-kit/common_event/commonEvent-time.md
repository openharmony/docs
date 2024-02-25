# 时间时区子系统公共事件定义
 时间时区子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_TIME_CHANGED
设置系统时间的公共事件的动作。

- 常量值： usual.event.TIME_CHANGED
- 订阅方需要的权限： 无需权限

当设置系统时间时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_TIME_TICK
表示系统时间更改的公共事件的动作。

- 常量值： usual.event.TIME_TICK
- 订阅方需要的权限： 无需权限

当以整分钟为单位的系统时间更改时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_TIMEZONE_CHANGED
表示系统时区更改的公共事件的动作。

- 常量值： usual.event.TIMEZONE_CHANGED
- 订阅方需要的权限： 无需权限

当系统时区更改时，将会触发事件通知服务发布该系统公共事件。
