# 文件管理子系统公共事件定义

## Core File Kit

文件管理子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。




### COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>

表示外部存储设备正常移除的公共事件。

当外部存储设备处于卸载状态，移除该设备时，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.VOLUME_REMOVED"




### COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>

表示外部存储设备状态变更为卸载的公共事件。

当外部存储设备处于挂载状态时，用户选择通过调用unmount接口或者直接移除设备的方法弹出该设备，并且已将外部存储设备卸载成功后，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.VOLUME_UNMOUNTED"




### COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>

表示外部存储设备状态变更为挂载的公共事件。

当用户插入外部存储设备自动挂载成功或者将处于卸载状态的外部存储设备调用mount接口进行挂载成功后，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.VOLUME_MOUNTED"




### COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>

表示外部存储设备异常移除的公共事件。

当外部存储设备处于挂载状态时，用户直接移除该外部存储设备，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.VOLUME_BAD_REMOVAL"




### COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>

表示外部存储设备即将被弹出的公共事件。

当外部存储设备处于挂载状态时，用户选择通过调用unmount接口或者直接移除设备的方法弹出该设备时，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.VOLUME_EJECT"




### COMMON_EVENT_DISK_REMOVED

（预留事件，暂未支持）外部存储设备状态变更为移除时发送此公共事件。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.DISK_BAD_REMOVAL"




### COMMON_EVENT_DISK_UNMOUNTED

（预留事件，暂未支持）部存储设备状态变更为卸载时发送此公共事件。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.DISK_UNMOUNTABLE"




### COMMON_EVENT_DISK_MOUNTED

（预留事件，暂未支持）外部存储设备状态变更为挂载时发送此公共事件。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED"




### COMMON_EVENT_DISK_BAD_REMOVAL

（预留事件，暂未支持）外部存储设备状态变更为挂载状态下移除时发送此公共事件。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.DISK_REMOVED"




### COMMON_EVENT_DISK_UNMOUNTABLE

（预留事件，暂未支持）外部存储设备状态变更为插卡情况下无法挂载时发送此公共事件。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.DISK_UNMOUNTED"




### COMMON_EVENT_DISK_EJECT

（预留事件，暂未支持）用户已表示希望删除外部存储介质时发送此公共事件。

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.data.DISK_EJECT"