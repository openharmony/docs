# USB子系统公共事件定义
USB子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_USB_STATE
表示USB设备状态发生变化。

- 常量值："usual.event.hardware.usb.action.USB_STATE"
- 订阅方需要的权限：无

当USB断开或者连接时状态发生变化，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_USB_PORT_CHANGED

提示用户设备的USB端口状态发生改变。

- 常量值："usual.event.hardware.usb.action.USB_PORT_CHANGED"
- 订阅方需要的权限：无

当USB的端口状态发生变化，将会触发事件通知服务发布该系统公共事件。

与这个公共事件相关的接口：具体可见[setPortRoles](../js-apis-usbManager.md#usbsetportroles)中的dataRole参数。

## COMMON_EVENT_USB_DEVICE_ATTACHED

当用户设备作为USB主机时，提示USB设备已挂载。

- 常量值："usual.event.hardware.usb.action.USB_DEVICE_ATTACHED"
- 订阅方需要的权限：无

当USB连接时状态发生变化，将会触发事件通知服务发布该系统公共事件。

与这个公共事件相关的接口：具体可见[USBDevice](../js-apis-usbManager.md#usbdevice)。 

## COMMON_EVENT_USB_DEVICE_DETACHED

当用户设备作为USB主机时，提示USB设备被卸载。

- 常量值："usual.event.hardware.usb.action.USB_DEVICE_DETACHED"
- 订阅方需要的权限：无

当USB断开时状态发生变化，将会触发事件通知服务发布该系统公共事件。

与这个公共事件相关的接口：具体可见[USBDevice](../js-apis-usbManager.md#usbdevice)。

## COMMON_EVENT_USB_ACCESSORY_ATTACHED

（预留事件，暂未支持）表示已连接USB附件的公共事件的动作。

- 值： usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED
- 订阅者所需权限： 无

## COMMON_EVENT_USB_ACCESSORY_DETACHED

（预留事件，暂未支持）表示USB附件被卸载的公共事件的动作。

- 值： usual.event.data.DISK_MOUNTED
- 订阅者所需权限： 无