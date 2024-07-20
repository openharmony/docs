# 元能力子系统公共事件定义

## Ability Kit

元能力面向应用发布如下系统公共事件。

### COMMON_EVENT_BOOT_COMPLETED

表示用户已完成引导并加载系统。

在设备上指定用户已完成引导并加载系统，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** ohos.permission.RECEIVER_STARTUP_COMPLETED（该权限仅系统应用可申请）

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.BOOT_COMPLETED"

### COMMON_EVENT_PACKAGE_RESTARTED

表示用户重启应用包并杀死其所有进程。

在设备上指定用户重启应用包并杀死其所有进程，将会触发事件通知服务发布该系统公共事件。

**订阅者所需权限：** 无

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_RESTARTED"

### COMMON_EVENT_PACKAGE_DATA_CLEARED

表示用户清除应用包数据。

在设备上指定用户清除应用包数据，将会触发事件通知服务发布该系统公共事件。

**订阅者所需权限：** 无

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_DATA_CLEARED"

### COMMON_EVENT_QUICK_FIX_APPLY_RESULT

表示快速修复应用。

在设备上指定用户快速修复应用，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** 无

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.QUICK_FIX_APPLY_RESULT"

### COMMON_EVENT_QUICK_FIX_REVOKE_RESULT<sup>10+<sup>

表示撤销快速修复。

在设备上撤销快速修复时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** 无

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.QUICK_FIX_REVOKE_RESULT"
