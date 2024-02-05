# 主题框架子系统-锁屏管理公共事件定义
主题框架子系统-锁屏管理面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_SCREEN_LOCKED
表示屏幕锁定的公共事件。

- 常量值： usual.event.SCREEN_LOCKED
- 订阅方需要的权限： 无需权限

当锁屏锁定时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SCREEN_UNLOCKED
表示屏幕解锁的公共事件。

- 常量值： usual.event.SCREEN_UNLOCKED
- 订阅方需要的权限： 无需权限

当锁屏解锁时，将会触发事件通知服务发布该系统公共事件。
