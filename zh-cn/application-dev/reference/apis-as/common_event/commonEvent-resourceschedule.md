# 资源调度子系统公共事件定义
资源调度子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED
表示设备上待机状态变化，触发公共事件发布动作。

- 常量值："usual.event.DEVICE_IDLE_MODE_CHANGED"
- 订阅方需要的权限：无需权限

如果用户一段时间没有使用设备且屏幕已经关闭情况下，系统延迟后台应用程序CPU和网络访问，将会触发公共事件服务发布该系统公共事件。

与这个公共事件相关的接口：power，具体参看[接口文档](../js-apis-power.md#powerisstandby10)。

## COMMON_EVENT_DEVICE_IDLE_EXEMPTION_LIST_UPDATED
表示待机状态下解除资源使用限制的豁免名单出现变化，触发公共事件发布动作。

- 常量值："usual.event.DEVICE_IDLE_EXEMPTION_LIST_UPDATED"
- 订阅方需要的权限：无需权限

待机状态下后台应用程序CPU和网络访问被限制，系统应用可以申请解除资源使用限制，将会触发公共事件服务发布该系统公共事件。
资源包括应用网络访问、Timer使用、WorkScheduler任务使用等。
系统应用可以调用JS API接口申请解除资源使用限制。

与这个公共事件相关的接口：deviceStandby，具体参看[接口文档](../js-apis-resourceschedule-deviceStandby.md#devicestandbyrequestexemptionresource)。