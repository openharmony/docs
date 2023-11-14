# 电源管理子系统公共事件定义
电源管理子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_BATTERY_CHANGED
表示电池充电状态、电平和其他信息发生变化的公共事件的动作。

- 值： usual.event.BATTERY_CHANGED
- 订阅者所需权限： 无

当电池电量、电池电压、电池温度、电池健康状态、设备连接的充电器类型、充电器最大电流、充电器最大电压、电池充电状态、充电次数、电池的总容量、电池剩余容量、电池的技术型号、当前电池的电流、电池的充电类型变化时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_BATTERY_LOW
表示电池电量低的普通事件的动作。

- 值： usual.event.BATTERY_LOW
- 订阅者所需权限： 无

当电池电量低于设备设置的低电量百分比值时，将会触发事件通知服务发布该系统公共事件。设备设置低电量百分比值请参考电量等级定制开发指导。

## COMMON_EVENT_BATTERY_OKAY
表示电池退出低电量状态的公共事件的动作。

- 值： usual.event.BATTERY_OKAY
- 订阅者所需权限： 无

当电池电量从低电量等级变化到电池电量高于低电量等级时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_POWER_CONNECTED
设备连接到外部电源的公共事件的动作。

- 值： usual.event.POWER_CONNECTED
- 订阅者所需权限： 无

当设备连接到外部可识别的充电器类型充电时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_POWER_DISCONNECTED
设备与外部电源断开的公共事件的动作。

- 值： usual.event.POWER_DISCONNECTED
- 订阅者所需权限： 无

当设备与外部电源断开时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_DISCHARGING
表示系统停止为电池充电的公共事件的动作。

- 值： usual.event.DISCHARGING
- 订阅者所需权限： 无

当系统停止为电池充电时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_CHARGING
表示系统开始为电池充电的公共事件的动作。

- 值： usual.event.CHARGING
- 订阅者所需权限： 无

当系统开始为电池充电时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_CHARGE_TYPE_CHANGED
表示系统充电类型改变的公共事件的动作。仅限系统应用使用。
- 值： usual.event.CHARGE_TYPE_CHANGED

- 订阅者所需权限： 无

当系统充电类型改变时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED
表示设备进入充电空闲模式的公共事件的动作。

- 值： usual.event.CHARGE_IDLE_MODE_CHANGED
- 订阅者所需权限： 无

当设备处于空闲、正在充电并且温升可接受的一种状态时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SHUTDOWN
表示设备正在关闭并将继续最终关闭的公共事件的操作。

- 值： usual.event.SHUTDOWN
- 订阅者所需权限： 无

当设备正在关闭并将继续最终关闭时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SCREEN_OFF
表示设备屏幕关闭且设备处于睡眠状态的普通事件的动作。

- 值： usual.event.SCREEN_OFF
- 订阅者所需权限： 无

当设备屏幕关闭且设备处于睡眠状态时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_SCREEN_ON
表示设备屏幕打开且设备处于交互状态的公共事件的操作。

- 值： usual.event.SCREEN_ON
- 订阅者所需权限： 无

当设备屏幕打开且设备处于交互状态时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_POWER_SAVE_MODE_CHANGED
表示系统节能模式更改的公共事件的动作。

- 值： usual.event.POWER_SAVE_MODE_CHANGED
- 订阅者所需权限： 无

当系统节能模式更改时，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_THERMAL_LEVEL_CHANGED
表示设备热状态的公共事件的动作。

- 值： usual.event.THERMAL_LEVEL_CHANGED
- 订阅者所需权限： 无

当设备热等级变化时，将会触发事件通知服务发布该系统公共事件。设备热等级配置请参考热等级定制开发指导。