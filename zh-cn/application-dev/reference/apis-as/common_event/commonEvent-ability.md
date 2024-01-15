# 元能力子系统公共事件定义
元能力面向应用发布如下系统公共事件。

## COMMON_EVENT_BOOT_COMPLETED

指示用户已完成引导并加载系统的公共事件操作。

- 常量值："usual.event.BOOT_COMPLETED"
- 订阅方需要的权限：ohos.permission.RECEIVER_STARTUP_COMPLETED

在设备上指定用户已完成引导并加载系统，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_PACKAGE_RESTARTED

表示用户重启应用包并杀死其所有进程的普通事件的动作。

- 常量值："usual.event.PACKAGE_RESTARTED"
- 订阅方需要的权限：无

在设备上指定用户重启应用包并杀死其所有进程，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_PACKAGE_DATA_CLEARED

表示用户清除应用包数据的公共事件的动作。

- 常量值："usual.event.PACKAGE_DATA_CLEARED"
- 订阅方需要的权限：无

在设备上指定用户清除应用包数据，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_QUICK_FIX_APPLY_RESULT<sup>9+</sup>

指示快速修复应用的动作。

- 常量值："usual.event.QUICK_FIX_APPLY_RESULT"
- 订阅方需要的权限：无

在设备上指定用户快速修复应用，将会触发事件通知服务发布该系统公共事件。

## COMMON_EVENT_QUICK_FIX_REVOKE_RESULT<sup>10+<sup>

指示撤销快速修复的动作。

- 常量值："usual.event.QUICK_FIX_REVOKE_RESULT"
- 订阅方需要的权限：无

在设备上撤销快速修复时，将会触发事件通知服务发布该系统公共事件。
