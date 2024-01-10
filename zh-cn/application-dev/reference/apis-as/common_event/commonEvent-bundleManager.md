# 包管理子系统公共事件定义
包管理服务框架面向应用发布如下系统公共事件。

## COMMON_EVENT_PACKAGE_ADDED

表示设备上已安装新应用包的公共事件的动作。

- 常量值："usual.event.PACKAGE_ADDED"
- 订阅方需要的权限：无

在设备上指定用户下安装了新的应用程序，将会触发事件通知服务发布该系统公共事件。

与这个公共事件相关的接口：install，具体参看[接口文档](../js-apis-installer.md#bundleinstallerinstall)。

## COMMON_EVENT_PACKAGE_REMOVED

表示已从设备卸载已安装的应用程序，但应用程序数据保留的公共事件的操作。

- 常量值："usual.event.PACKAGE_REMOVED"
- 订阅方需要的权限：无

在设备指定用户下卸载指定的应用程序包，将会触发事件通知服务发布该系统公共事件。

与这个公共事件相关的接口：uninstall，具体参看[接口文档](../js-apis-installer.md#bundleinstalleruninstall)。

## COMMON_EVENT_PACKAGE_CHANGED

表示应用包已更改的公共事件的动作（例如，包中的组件已启用或禁用）。

- 常量值："usual.event.PACKAGE_CHANGED"
- 订阅方需要的权限：无

在设备上安装的应用程序包更新或者包的组件被禁用使能，将会触发事件通知服务发布该系统公共事件。

与这个公共事件相关的接口：setApplicationEnabled 和 setAbilityEnabled，具体参看[接口文档](../js-apis-bundleManager.md#bundlemanagersetapplicationenabled)。

## COMMON_EVENT_PACKAGE_CACHE_CLEARED

表示用户清除应用包缓存数据的公共事件的动作。

- 常量值："usual.event.PACKAGE_CACHE_CLEARED"
- 订阅方需要的权限：无

对设备上安装的应用程序包清除缓存时，将会触发事件通知服务发布该系统公共事件。

与这个公共事件相关的接口：cleanBundleCacheFiles，具体参看[接口文档](../js-apis-bundleManager.md#bundlemanagercleanbundlecachefiles)。
