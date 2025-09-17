# 系统定义的公共事件（系统接口）

<!--Kit: Basic Services Kit-->
<!--Subsystem: Notification-->
<!--Owner: @peixu-->
<!--Designer: @dongqingran; @wulong158-->
<!--Tester: @wanghong1997-->
<!--Adviser: @fang-jinxu-->

本文档提供了系统定义的公共事件清单。

公共事件类型定义在[ohos.commonEventManager模块的Support枚举](../js-apis-commonEventManager.md#support)中。

> **说明：**
>
> 当前界面仅包含本模块的系统接口，其他公开接口参见[系统公共事件定义](../common_event/commonEventManager-definitions.md)。




## Ability Kit


### COMMON_EVENT_BOOT_COMPLETED

表示用户已完成引导并加载系统。

在设备上指定用户已完成引导并加载系统，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.RECEIVER_STARTUP_COMPLETED（该权限仅系统应用可申请）


**取值：** "usual.event.BOOT_COMPLETED"



### COMMON_EVENT_PACKAGE_INSTALLATION_STARTED<sup>12+</sup>

当一个包被验证时，由系统包验证者发送。

在设备上指定用户下开始安装应用程序，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** "usual.event.PACKAGE_INSTALLATION_STARTED"


### COMMON_EVENT_BUNDLE_RESOURCES_CHANGED<sup>15+</sup>

表示包管理资源数据刷新的公共事件。

在切换语言、切换主题等场景，包管理资源数据刷新完成时，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.GET_BUNDLE_RESOURCES

**取值：** "usual.event.BUNDLE_RESOURCES_CHANGED"


### COMMON_EVENT_DEFAULT_APPLICATION_CHANGED<sup>19+</sup>

表示文件默认打开应用发生变更的公共事件。

在文件默认打开应用发生变更时，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.CHANGE_DEFAULT_APPLICATION

**取值：** "usual.event.DEFAULT_APPLICATION_CHANGED"


### COMMON_EVENT_SHORTCUT_CHANGED<sup>20+</sup>

表示应用快捷方式发生变化的公共事件。

在应用快捷方式的更改设置完成时（例如调用shortcutManager模块的[setShortcutVisibleForSelf](../../apis-ability-kit/js-apis-shortcutManager.md#shortcutmanagersetshortcutvisibleforself)成功时），会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.MANAGE_SHORTCUTS

**取值：** "usual.event.SHORTCUT_CHANGED"


### COMMON_EVENT_KIOSK_MODE_ON<sup>20+</sup>

进入Kiosk模式时，事件通知服务将触发并发布系统公共事件。此事件仅由系统发送。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.KIOSK_MODE_ON


### COMMON_EVENT_KIOSK_MODE_OFF<sup>20+</sup>

退出Kiosk模式时，事件通知服务将触发并发布系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.KIOSK_MODE_OFF


## Background Tasks Kit 

### COMMON_EVENT_DEVICE_IDLE_EXEMPTION_LIST_UPDATED<sup>10+<sup>

表示待机状态下解除资源使用限制的豁免名单出现变化，触发公共事件发布动作。

待机状态下后台应用程序CPU和网络访问被限制，系统应用可以申请解除资源使用限制，将会触发公共事件服务发布该系统公共事件。
资源包括应用网络访问、Timer使用、WorkScheduler任务使用等。

系统应用可以调用JS API接口申请解除资源使用限制。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** "usual.event.DEVICE_IDLE_EXEMPTION_LIST_UPDATED"

## Basic Services Kit-定制

### COMMON_EVENT_CUSTOM_CONFIG_POLICY_UPDATED<sup>20+</sup>

表示设备的配置目录层级与系统参数发生变化的公共事件。

在系统对设备的归属区域和漫游区域识别完成后，会对设备的配置目录层级与系统参数进行刷新，刷新完成后会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** "usual.event.CUSTOM_CONFIG_POLICY_UPDATED"

### COMMON_EVENT_CUSTOM_ROAMING_REGION_UPDATED<sup>20+</sup>

表示设备漫游区域发生变化的公共事件。

在设备注入网络、驻留网络、GPS定位等属性变化时，系统服务会进行漫游区域识别。当识别到漫游区域发生变化，则会更新设备漫游区域参数，在更新完成后会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** "usual.event.CUSTOM_ROAMING_REGION_UPDATED"

## Basic Services Kit-电源

### COMMON_EVENT_CHARGE_TYPE_CHANGED<sup>10+<sup>

表示系统充电类型改变的公共事件的动作。

当系统充电类型改变时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** "usual.event.CHARGE_TYPE_CHANGED"


### COMMON_EVENT_USER_ADDED

表示用户已添加到系统中的公共事件的动作。

创建系统账号将会触发事件通知服务发布该系统公共事件，事件携带系统账号ID。

与这个公共事件相关的接口：createOsAccount、createOsAccountForDomain, 这些为系统API，具体参看[系统账号接口文档](../js-apis-osAccount.md)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（该权限仅系统应用可申请）

**取值：** "usual.event.USER_ADDED"


### COMMON_EVENT_USER_REMOVED

表示用户已从系统中删除的公共事件的动作。

删除系统账号将会触发事件通知服务发布该系统公共事件，事件携带系统账号ID。

与这个公共事件相关的接口：removeOsAccount, 为系统API，具体参看[系统账号接口文档](../js-apis-osAccount.md)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.MANAGE_LOCAL_ACCOUNTS（该权限仅系统应用可申请）

**取值：** "usual.event.USER_REMOVED"


### COMMON_EVENT_DOMAIN_ACCOUNT_STATUS_CHANGED

表示域账号状态发生变化。

域账号认证、删除、令牌更新、令牌失效将会触发事件通知服务发布该系统公共事件，事件携带域账号名、域名、域账号状态等信息。

与这个公共事件相关的接口：removeOsAccount、DomainAccountManager.auth、updateAccountToken, 这些为系统API，具体参看[系统账号接口文档](../js-apis-osAccount.md)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.GET_LOCAL_ACCOUNTS（该权限仅系统应用可申请）

**取值：** "usual.event.DOMAIN_ACCOUNT_STATUS_CHANGED"


### COMMON_EVENT_USER_SWITCHED

表示用户切换完成的公共事件的动作。

切换系统账号将会触发事件通知服务发布该系统公共事件，事件携带系统账号ID。

与这个公共事件相关的接口：activateOsAccount, 为系统API，具体参看[系统账号接口文档](../js-apis-osAccount.md)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 在API version 21之前，需要申请ohos.permission.MANAGE_LOCAL_ACCOUNTS权限；从API version 21开始，需要申请ohos.permission.MANAGE_LOCAL_ACCOUNTS或ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS权限

**取值：** "usual.event.USER_SWITCHED"


### COMMON_EVENT_USER_LOCKING

表示用户即将被锁定的公共事件的动作。

锁定用户前将会触发事件通知服务发布该系统公共事件，事件携带系统账号ID。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.USER_LOCKING"


### COMMON_EVENT_USER_LOCKED

表示用户锁定完成的公共事件的动作。

完成锁定用户将会触发事件通知服务发布该系统公共事件，事件携带系统账号ID。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.USER_LOCKED"


## Core File Kit

文件管理子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。


### COMMON_EVENT_VOLUME_REMOVED

表示外部存储设备正常移除的公共事件。

当外部存储设备处于卸载状态，移除该设备时，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**取值：** "usual.event.data.VOLUME_REMOVED"



### COMMON_EVENT_VOLUME_UNMOUNTED

表示外部存储设备状态变更为卸载的公共事件。

当外部存储设备处于挂载状态时，用户选择通过调用unmount接口或者直接移除设备的方法弹出该设备，并且已将外部存储设备卸载成功后，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**取值：** "usual.event.data.VOLUME_UNMOUNTED"


### COMMON_EVENT_VOLUME_MOUNTED

表示外部存储设备状态变更为挂载的公共事件。

当用户插入外部存储设备自动挂载成功或者将处于卸载状态的外部存储设备调用mount接口进行挂载成功后，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**取值：** "usual.event.data.VOLUME_MOUNTED"


### COMMON_EVENT_VOLUME_BAD_REMOVAL

表示外部存储设备异常移除的公共事件。

当外部存储设备处于挂载状态时，用户直接移除该外部存储设备，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**取值：** "usual.event.data.VOLUME_BAD_REMOVAL"


### COMMON_EVENT_VOLUME_EJECT

表示外部存储设备即将被弹出的公共事件。

当外部存储设备处于挂载状态时，用户选择通过调用unmount接口或者直接移除设备的方法弹出该设备时，会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.STORAGE_MANAGER

**取值：** "usual.event.data.VOLUME_EJECT"


### COMMON_EVENT_RESTORE_START<sup>13+<sup>

表示某个应用开始恢复的公共事件。

当数据迁移相关应用拉起备份恢复框架进行恢复任务，某个应用恢复开始时会发送此公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.START_RESTORE_NOTIFICATION

**取值：** "usual.event.RESTORE_START"


## Media Kit

### COMMON_EVENT_SCREEN_SHARE

表示系统中发生了屏幕共享事件。

这是一个受保护的公共事件，只能由系统发送。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.RECEIVE_SMS（该权限仅系统应用可申请）

**取值：** usual.event.SCREEN_SHARE


## Telephony Kit

### COMMON_EVENT_SMS_RECEIVE_COMPLETED<sup>10+<sup>

提示短信接收完成。

在设备接收到短信时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.RECEIVE_SMS（该权限仅系统应用可申请）

**取值：** usual.event.SMS_RECEIVED_COMPLETED


### COMMON_EVENT_SMS_EMERGENCY_CB_RECEIVE_COMPLETED<sup>10+<sup>

提示紧急小区广播短信接收完成。

在设备接收到紧急小区广播短信时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.RECEIVE_SMS（该权限仅系统应用可申请）

**取值：** usual.event.SMS_EMERGENCY_CB_RECEIVE_COMPLETED


### COMMON_EVENT_SMS_CB_RECEIVE_COMPLETED<sup>10+<sup>

提示小区广播短信接收完成。

在设备接收到小区广播短信时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.RECEIVE_SMS（该权限仅系统应用可申请）

**取值：** usual.event.SMS_CB_RECEIVE_COMPLETED





### COMMON_EVENT_OPERATOR_CONFIG_CHANGED<sup>10+<sup>

提示运营商配置已更新。

在设备运营商配置更新时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.OPERATOR_CONFIG_CHANGED


### COMMON_EVENT_SIM_CARD_DEFAULT_SMS_SUBSCRIPTION_CHANGED<sup>10+<sup>

提示SIM卡默认短信主卡已更新。

在设备SIM卡默认短信主卡更新时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.DEFAULT_SMS_SUBSCRIPTION_CHANGED


### COMMON_EVENT_SIM_CARD_DEFAULT_DATA_SUBSCRIPTION_CHANGED<sup>10+<sup>

提示SIM卡默认数据主卡已更新。

在设备SIM卡默认数据主卡更新时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.DEFAULT_DATA_SUBSCRIPTION_CHANGED


### COMMON_EVENT_SIM_CARD_DEFAULT_MAIN_SUBSCRIPTION_CHANGED<sup>10+<sup>

提示SIM卡默认主卡已更新。

在设备SIM卡默认主卡更新时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.SIM.DEFAULT_MAIN_SUBSCRIPTION_CHANGED


### COMMON_EVENT_SET_PRIMARY_SLOT_STATUS<sup>11+<sup>

提示设置SIM卡默认主卡的动作，其状态更新为执行中或已完成。

在设备上设置SIM卡默认主卡时，当执行状态发生变化（比如状态更新到执行中或已完成），将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.SET_PRIMARY_SLOT_STATUS


### COMMON_EVENT_PRIMARY_SLOT_ROAMING<sup>11+<sup>

提示SIM卡默认主卡的漫游状态已更新。

在设备SIM卡默认主卡的漫游状态发生变化时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.PRIMARY_SLOT_ROAMING


### COMMON_EVENT_SIM_CARD_DEFAULT_VOICE_SUBSCRIPTION_CHANGED<sup>10+<sup>

提示SIM卡默认语音主卡已更新。

在设备SIM卡默认语音主卡更新时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.DEFAULT_VOICE_SUBSCRIPTION_CHANGED


### COMMON_EVENT_CELLULAR_DATA_STATE_CHANGED<sup>10+<sup>

提示蜂窝数据状态更新。

在设备蜂窝数据状态更新时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.CELLULAR_DATA_STATE_CHANGED


### COMMON_EVENT_INCOMING_CALL_MISSED<sup>10+<sup>

提示未接来电。

在设备有未接来电时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.GET_TELEPHONY_STATE（该权限仅系统应用可申请）

**取值：** usual.event.INCOMING_CALL_MISSED


### COMMON_EVENT_RADIO_STATE_CHANGE<sup>10+<sup>

提示设备modem上下电状态变化。

在设备modem上下电状态变化时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.RADIO_STATE_CHANGE


### COMMON_EVENT_SPECIAL_CODE<sup>10+<sup>

提示暗码发送成功。

在设备上发送暗码成功时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.DIALER_SPECIAL_CODE


### COMMON_EVENT_AUDIO_QUALITY_CHANGE<sup>10+<sup>

提示音频质量发生变化。

在设备音频质量发送变化时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.AUDIO_QUALITY_CHANGE


## 预留公共事件

以下事件为预留公共事件，暂未支持。

### COMMON_EVENT_STK_COMMAND<sup>10+<sup>

（预留事件，暂未支持）提示STK命令。

在发送STK命令时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.STK_COMMAND


### COMMON_EVENT_STK_SESSION_END<sup>10+<sup>

（预留事件，暂未支持）提示STK会话结束。

在STK会话结束时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.STK_SESSION_END


### COMMON_EVENT_STK_CARD_STATE_CHANGED<sup>10+<sup>

（预留事件，暂未支持）提示STK卡状态已更新。

在STK卡状态更新时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无


**取值：** usual.event.STK_CARD_STATE_CHANGED

### COMMON_EVENT_STK_ALPHA_IDENTIFIER<sup>10+<sup>

（预留事件，暂未支持）提示STK ALPHA标识符。

在发送STK ALPHA标识符时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** 无

**取值：** usual.event.STK_ALPHA_IDENTIFIER


### COMMON_EVENT_SMS_WAPPUSH_RECEIVE_COMPLETED<sup>10+<sup>

（预留事件，暂未支持）提示服务信息短信接收完成。

在设备接收服务信息短信完成时，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** ohos.permission.RECEIVE_SMS（该权限仅系统应用可申请）

**取值：** usual.event.SMS_WAPPUSH_RECEIVE_COMPLETED