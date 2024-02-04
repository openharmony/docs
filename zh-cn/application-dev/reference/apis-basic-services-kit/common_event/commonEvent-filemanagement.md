# 文件管理子系统公共事件定义
文件管理子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_VOLUME_REMOVED<sup>9+<sup>
表示外部存储设备正常移除的公共事件。
- 值： usual.event.data.VOLUME_REMOVED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

当外部存储设备处于卸载状态，移除该设备时，会发送此公共事件。

## COMMON_EVENT_VOLUME_UNMOUNTED<sup>9+<sup>
表示外部存储设备状态变更为卸载的公共事件。
- 值： usual.event.data.VOLUME_UNMOUNTED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

当外部存储设备处于挂载状态时，用户选择通过调用[unmount](../js-apis-file-volumemanager.md)接口或者直接移除设备的方法弹出该设备，并且已将外部存储设备卸载成功后，会发送此公共事件。

## COMMON_EVENT_VOLUME_MOUNTED<sup>9+<sup>
表示外部存储设备状态变更为挂载的公共事件。
- 值： usual.event.data.VOLUME_MOUNTED
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

当用户插入外部存储设备自动挂载成功或者将处于卸载状态的外部存储设备调用[mount](../js-apis-file-volumemanager.md)接口进行挂载成功后，会发送此公共事件。

## COMMON_EVENT_VOLUME_BAD_REMOVAL<sup>9+<sup>
表示外部存储设备异常移除的公共事件。
- 值： usual.event.data.VOLUME_BAD_REMOVAL
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

当外部存储设备处于挂载状态时，用户直接移除该外部存储设备，会发送此公共事件。

## COMMON_EVENT_VOLUME_EJECT<sup>9+<sup>
表示外部存储设备即将被弹出的公共事件。
- 值： usual.event.data.VOLUME_EJECT
- 订阅者所需权限： ohos.permission.STORAGE_MANAGER

当外部存储设备处于挂载状态时，用户选择通过调用[unmount](../js-apis-file-volumemanager.md)接口或者直接移除设备的方法弹出该设备时，会发送此公共事件。
