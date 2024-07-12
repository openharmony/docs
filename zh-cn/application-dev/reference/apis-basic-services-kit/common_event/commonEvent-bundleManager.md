# 系统公共事件定义
## Ability Kit

包管理服务框架面向应用发布如下系统公共事件。

### COMMON_EVENT_PACKAGE_ADDED

表示设备上已安装新应用包的公共事件的动作。

在设备上指定用户下安装了新的应用程序，将会触发事件通知服务发布该系统公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_ADDED"

### COMMON_EVENT_PACKAGE_REPLACED

表示设备上安装了新版本的应用程序包并替换了旧版本的动作。数据包含包的名称。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_REPLACED"

### COMMON_EVENT_MY_PACKAGE_REPLACED

表示设备上安装了新版本的应用程序包并替换了旧版本的应用程序包的动作，不包含额外的数据，只发送给被替换的应用程序。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.MY_PACKAGE_REPLACED"


### COMMON_EVENT_PACKAGE_REMOVED

表示已从设备卸载已安装的应用程序，但应用程序数据保留的公共事件的操作。

在设备指定用户下卸载指定的应用程序包，将会触发事件通知服务发布该系统公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_REMOVED"

### COMMON_EVENT_BUNDLE_REMOVED

表示现有的应用程序包从设备中移除的事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.BUNDLE_REMOVED"

### COMMON_EVENT_PACKAGE_FULLY_REMOVED

表示现有的应用程序包从设备上完全删除的事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_FULLY_REMOVED"


### COMMON_EVENT_PACKAGE_CHANGED

表示应用包已更改的公共事件的动作（例如，包中的组件已启用或禁用）。

在设备上安装的应用程序包更新或者包的组件被禁用使能，将会触发事件通知服务发布该系统公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_CHANGED"


### COMMON_EVENT_PACKAGE_CACHE_CLEARED

表示用户清除应用包缓存数据的公共事件的动作。

对设备上安装的应用程序包清除缓存时，将会触发事件通知服务发布该系统公共事件。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_CACHE_CLEARED"

### COMMON_EVENT_PACKAGES_SUSPENDED

表示包已经被挂起。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGES_SUSPENDED"

### COMMON_EVENT_PACKAGES_UNSUSPENDED

表示包已经被解除挂起。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGES_UNSUSPENDED"

### COMMON_EVENT_MY_PACKAGE_SUSPENDED

发送到已被系统挂起的包。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.MY_PACKAGE_SUSPENDED"

### COMMON_EVENT_MY_PACKAGE_UNSUSPENDED

发送到已被系统解除挂起的包。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.MY_PACKAGE_UNSUSPENDED"

### COMMON_EVENT_PACKAGE_FIRST_LAUNCH

应用程序在安装后首次启动。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_FIRST_LAUNCH"

### COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION

当一个包需要被验证时，由系统包验证者发送。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_NEEDS_VERIFICATION"

### COMMON_EVENT_PACKAGE_VERIFIED

当一个包被验证时，由系统包验证者发送。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_VERIFIED"

### COMMON_EVENT_MANAGE_PACKAGE_STORAGE

通知用户低内存状态并且应该启动包管理。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.MANAGE_PACKAGE_STORAGE"


### COMMON_EVENT_PACKAGE_INSTALLATION_STARTED<sup>12+</sup>

当一个包被验证时，由系统包验证者发送。

在设备上指定用户下开始安装应用程序，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.PACKAGE_INSTALLATION_STARTED"