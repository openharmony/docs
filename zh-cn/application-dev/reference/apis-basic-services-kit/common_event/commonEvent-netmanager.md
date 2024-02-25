# 网络管理子系统公共事件定义
网络管理子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。


## COMMON_EVENT_CONNECTIVITY_CHANGE<sup>10+<sup>

提示网络连接状态变化。

- 值：usual.event.CONNECTIVITY_CHANGE
- 订阅者所需权限：无

各类网络（以太网、WIFI、蜂窝等）在发生连接状态状态变化时（断开、断开中、连接中、已连接等），将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_AIRPLANE_MODE_CHANGED<sup>10+<sup>

提示飞行模式状态变化。

- 值：usual.event.AIRPLANE_MODE
- 订阅者所需权限：无

在设置系统飞行模式状态后，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_HTTP_PROXY_CHANGE<sup>10+<sup>

提示网络Http代理配置信息更新。

- 值：usual.event.HTTP_PROXY_CHANGE
- 订阅者所需权限：无

在全局代理、各类网络（以太网、WIFI等）Http代理配置信息发生变化时，将会触发事件通知服务发布该系统公共事件。