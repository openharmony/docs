# 公共事件模块

本模块提供了公共事件的能力，包括公共事件的权限列表，发布公共事件，订阅或取消订阅公共事件，获取或修改公共事件结果代码、结果数据等。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 权限列表

| 系统公共事件宏      | 系统公共事件名称          | 订阅者所需权限     |
| ------------ | ------------------ | ---------------------- |
| COMMON_EVENT_BOOT_COMPLETED                                  | usual.event.BOOT_COMPLETED                                  | ohos.permission.RECEIVER_STARTUP_COMPLETED                   |
| COMMON_EVENT_LOCKED_BOOT_COMPLETED                           | usual.event.LOCKED_BOOT_COMPLETED                           | ohos.permission.RECEIVER_STARTUP_COMPLETED                   |
| COMMON_EVENT_SHUTDOWN                                        | usual.event.SHUTDOWN                                        | 无                                                           |
| COMMON_EVENT_BATTERY_CHANGED                                 | usual.event.BATTERY_CHANGED                                 | 无                                                           |
| COMMON_EVENT_BATTERY_LOW                                     | usual.event.BATTERY_LOW                                     | 无                                                           |
| COMMON_EVENT_BATTERY_OKAY                                    | usual.event.BATTERY_OKAY                                    | 无                                                           |
| COMMON_EVENT_POWER_CONNECTED                                 | usual.event.POWER_CONNECTED                                 | 无                                                           |
| COMMON_EVENT_POWER_DISCONNECTED                              | usual.event.POWER_DISCONNECTED                              | 无                                                           |
| COMMON_EVENT_SCREEN_OFF                                      | usual.event.SCREEN_OFF                                      | 无                                                           |
| COMMON_EVENT_SCREEN_ON                                       | usual.event.SCREEN_ON                                       | 无                                                           |
| COMMON_EVENT_THERMAL_LEVEL_CHANGED                           | usual.event.THERMAL_LEVEL_CHANGED                           | 无                                                           |
| COMMON_EVENT_USER_PRESENT                                    | usual.event.USER_PRESENT                                    | 无                                                           |
| COMMON_EVENT_TIME_TICK                                       | usual.event.TIME_TICK                                       | 无                                                           |
| COMMON_EVENT_TIME_CHANGED                                    | usual.event.TIME_CHANGED                                    | 无                                                           |
| COMMON_EVENT_DATE_CHANGED                                    | usual.event.DATE_CHANGED                                    | 无                                                           |
| COMMON_EVENT_TIMEZONE_CHANGED                                | usual.event.TIMEZONE_CHANGED                                | 无                                                           |
| COMMON_EVENT_CLOSE_SYSTEM_DIALOGS                            | usual.event.CLOSE_SYSTEM_DIALOGS                            | 无                                                           |
| COMMON_EVENT_PACKAGE_ADDED                                   | usual.event.PACKAGE_ADDED                                   | 无                                                           |
| COMMON_EVENT_PACKAGE_REPLACED                                | usual.event.PACKAGE_REPLACED                                | 无                                                           |
| COMMON_EVENT_MY_PACKAGE_REPLACED                             | usual.event.MY_PACKAGE_REPLACED                             | 无                                                           |
| COMMON_EVENT_PACKAGE_REMOVED                                 | usual.event.PACKAGE_REMOVED                                 | 无                                                           |
| COMMON_EVENT_BUNDLE_REMOVED                                  | usual.event.BUNDLE_REMOVED                                  | 无                                                           |
| COMMON_EVENT_PACKAGE_FULLY_REMOVED                           | usual.event.PACKAGE_FULLY_REMOVED                           | 无                                                           |
| COMMON_EVENT_PACKAGE_CHANGED                                 | usual.event.PACKAGE_CHANGED                                 | 无                                                           |
| COMMON_EVENT_PACKAGE_RESTARTED                               | usual.event.PACKAGE_RESTARTED                               | 无                                                           |
| COMMON_EVENT_PACKAGE_DATA_CLEARED                            | usual.event.PACKAGE_DATA_CLEARED                            | 无                                                           |
| COMMON_EVENT_PACKAGES_SUSPENDED                              | usual.event.PACKAGES_SUSPENDED                              | 无                                                           |
| COMMON_EVENT_PACKAGES_UNSUSPENDED                            | usual.event.PACKAGES_UNSUSPENDED                            | 无                                                           |
| COMMON_EVENT_MY_PACKAGE_SUSPENDED                            | usual.event.MY_PACKAGE_SUSPENDED                            | 无                                                           |
| COMMON_EVENT_MY_PACKAGE_UNSUSPENDED                          | usual.event.MY_PACKAGE_UNSUSPENDED                          | 无                                                           |
| COMMON_EVENT_UID_REMOVED                                     | usual.event.UID_REMOVED                                     | 无                                                           |
| COMMON_EVENT_PACKAGE_FIRST_LAUNCH                            | usual.event.PACKAGE_FIRST_LAUNCH                            | 无                                                           |
| COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION                      | usual.event.PACKAGE_NEEDS_VERIFICATION                      | 无                                                           |
| COMMON_EVENT_PACKAGE_VERIFIED                                | usual.event.PACKAGE_VERIFIED                                | 无                                                           |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE                 | usual.event.EXTERNAL_APPLICATIONS_AVAILABLE                 | 无                                                           |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE               | usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE               | 无                                                           |
| COMMON_EVENT_CONFIGURATION_CHANGED                           | usual.event.CONFIGURATION_CHANGED                           | 无                                                           |
| COMMON_EVENT_LOCALE_CHANGED                                  | usual.event.LOCALE_CHANGED                                  | 无                                                           |
| COMMON_EVENT_MANAGE_PACKAGE_STORAGE                          | usual.event.MANAGE_PACKAGE_STORAGE                          | 无                                                           |
| COMMON_EVENT_DRIVE_MODE                                      | common.event.DRIVE_MODE                                     | 无                                                           |
| COMMON_EVENT_HOME_MODE                                       | common.event.HOME_MODE                                      | 无                                                           |
| COMMON_EVENT_OFFICE_MODE                                     | common.event.OFFICE_MODE                                    | 无                                                           |
| COMMON_EVENT_USER_STARTED                                    | usual.event.USER_STARTED                                    | 无                                                           |
| COMMON_EVENT_USER_BACKGROUND                                 | usual.event.USER_BACKGROUND                                 | 无                                                           |
| COMMON_EVENT_USER_FOREGROUND                                 | usual.event.USER_FOREGROUND                                 | 无                                                           |
| COMMON_EVENT_USER_SWITCHED                                   | usual.event.USER_SWITCHED                                   | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_USER_STARTING                                   | usual.event.USER_STARTING                                   | ohos.permission.INTERACT_ACROSS_USERS                        |
| COMMON_EVENT_USER_UNLOCKED                                   | usual.event.USER_UNLOCKED                                   | 无                                                           |
| COMMON_EVENT_USER_STOPPING                                   | usual.event.USER_STOPPING                                   | ohos.permission.INTERACT_ACROSS_USERS                        |
| COMMON_EVENT_USER_STOPPED                                    | usual.event.USER_STOPPED                                    | 无                                                           |
| COMMON_EVENT_HWID_LOGIN                                      | common.event.HWID_LOGIN                                     | 无                                                           |
| COMMON_EVENT_HWID_LOGOUT                                     | common.event.HWID_LOGOUT                                    | 无                                                           |
| COMMON_EVENT_HWID_TOKEN_INVALID                              | common.event.HWID_TOKEN_INVALID                             | 无                                                           |
| COMMON_EVENT_HWID_LOGOFF                                     | common.event.HWID_LOGOFF                                    | 无                                                           |
| COMMON_EVENT_WIFI_POWER_STATE                                | usual.event.wifi.POWER_STATE                                | 无                                                           |
| COMMON_EVENT_WIFI_SCAN_FINISHED                              | usual.event.wifi.SCAN_FINISHED                              | ohos.permission.LOCATION                                     |
| COMMON_EVENT_WIFI_RSSI_VALUE                                 | usual.event.wifi.RSSI_VALUE                                 | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_CONN_STATE                                 | usual.event.wifi.CONN_STATE                                 | 无                                                           |
| COMMON_EVENT_WIFI_HOTSPOT_STATE                              | usual.event.wifi.HOTSPOT_STATE                              | 无                                                           |
| COMMON_EVENT_WIFI_AP_STA_JOIN                                | usual.event.wifi.WIFI_HS_STA_JOIN                           | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_AP_STA_LEAVE                               | usual.event.wifi.WIFI_HS_STA_LEAVE                          | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_MPLINK_STATE_CHANGE                        | usual.event.wifi.mplink.STATE_CHANGE                        | ohos.permission.MPLINK_CHANGE_STATE                          |
| COMMON_EVENT_WIFI_P2P_CONN_STATE                             | usual.event.wifi.p2p.CONN_STATE_CHANGE                      | ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION   |
| COMMON_EVENT_WIFI_P2P_STATE_CHANGED                          | usual.event.wifi.p2p.STATE_CHANGE                           | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED                    | usual.event.wifi.p2p.DEVICES_CHANGE                         | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED          | usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE            | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED           | usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE                  | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED                    | usual.event.wifi.p2p.GROUP_STATE_CHANGED                    | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CONNECT_STATE_UPDATE     | usual.event.bluetooth.handsfree.ag.CONNECT_STATE_UPDATE     | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_CURRENT_DEVICE_UPDATE    | usual.event.bluetooth.handsfree.ag.CURRENT_DEVICE_UPDATE    | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HANDSFREE_AG_AUDIO_STATE_UPDATE       | usual.event.bluetooth.handsfree.ag.AUDIO_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CONNECT_STATE_UPDATE       | usual.event.bluetooth.a2dpsource.CONNECT_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CURRENT_DEVICE_UPDATE      | usual.event.bluetooth.a2dpsource.CURRENT_DEVICE_UPDATE      | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_PLAYING_STATE_UPDATE       | usual.event.bluetooth.a2dpsource.PLAYING_STATE_UPDATE       | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_CODEC_VALUE_UPDATE         | usual.event.bluetooth.a2dpsource.CODEC_VALUE_UPDATE         | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_DISCOVERED               | usual.event.bluetooth.remotedevice.DISCOVERED               | ohos.permission.LOCATION and ohos.permission.USE_BLUETOOTH   |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CLASS_VALUE_UPDATE       | usual.event.bluetooth.remotedevice.CLASS_VALUE_UPDATE       | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_CONNECTED            | usual.event.bluetooth.remotedevice.ACL_CONNECTED            | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_ACL_DISCONNECTED         | usual.event.bluetooth.remotedevice.ACL_DISCONNECTED         | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_NAME_UPDATE              | usual.event.bluetooth.remotedevice.NAME_UPDATE              | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIR_STATE               | usual.event.bluetooth.remotedevice.PAIR_STATE               | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_BATTERY_VALUE_UPDATE     | usual.event.bluetooth.remotedevice.BATTERY_VALUE_UPDATE     | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT               | usual.event.bluetooth.remotedevice.SDP_RESULT               | 无                                                           |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_UUID_VALUE               | usual.event.bluetooth.remotedevice.UUID_VALUE               | ohos.permission.DISCOVER_BLUETOOTH                           |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_REQ              | usual.event.bluetooth.remotedevice.PAIRING_REQ              | ohos.permission.DISCOVER_BLUETOOTH                           |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL           | usual.event.bluetooth.remotedevice.PAIRING_CANCEL           | 无                                                           |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ              | usual.event.bluetooth.remotedevice.CONNECT_REQ              | 无                                                           |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY            | usual.event.bluetooth.remotedevice.CONNECT_REPLY            | 无                                                           |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL           | usual.event.bluetooth.remotedevice.CONNECT_CANCEL           | 无                                                           |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE    | 无                                                           |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE      | usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE      | 无                                                           |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT         | usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT         | 无                                                           |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE    | 无                                                           |
| COMMON_EVENT_BLUETOOTH_HOST_STATE_UPDATE                     | usual.event.bluetooth.host.STATE_UPDATE                     | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE                 | usual.event.bluetooth.host.REQ_DISCOVERABLE                 | 无                                                           |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_ENABLE                       | usual.event.bluetooth.host.REQ_ENABLE                       | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISABLE                      | usual.event.bluetooth.host.REQ_DISABLE                      | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HOST_SCAN_MODE_UPDATE                 | usual.event.bluetooth.host.SCAN_MODE_UPDATE                 | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_STARTED                | usual.event.bluetooth.host.DISCOVERY_STARTED                | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HOST_DISCOVERY_FINISHED               | usual.event.bluetooth.host.DISCOVERY_FINISHED               | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_HOST_NAME_UPDATE                      | usual.event.bluetooth.host.NAME_UPDATE                      | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_CONNECT_STATE_UPDATE         | usual.event.bluetooth.a2dpsink.CONNECT_STATE_UPDATE         | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_PLAYING_STATE_UPDATE         | usual.event.bluetooth.a2dpsink.PLAYING_STATE_UPDATE         | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_A2DPSINK_AUDIO_STATE_UPDATE           | usual.event.bluetooth.a2dpsink.AUDIO_STATE_UPDATE           | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED                | usual.event.nfc.action.ADAPTER_STATE_CHANGED                | 无                                                           |
| COMMON_EVENT_NFC_ACTION_RF_FIELD_ON_DETECTED                 | usual.event.nfc.action.RF_FIELD_ON_DETECTED                 | ohos.permission.MANAGE_SECURE_SETTINGS                       |
| COMMON_EVENT_NFC_ACTION_RF_FIELD_OFF_DETECTED                | usual.event.nfc.action.RF_FIELD_OFF_DETECTED                | ohos.permission.MANAGE_SECURE_SETTINGS                       |
| COMMON_EVENT_DISCHARGING                                     | usual.event.DISCHARGING                                     | 无                                                           |
| COMMON_EVENT_CHARGING                                        | usual.event.CHARGING                                        | 无                                                           |
| COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED                        | usual.event.DEVICE_IDLE_MODE_CHANGED                        | 无                                                           |
| COMMON_EVENT_POWER_SAVE_MODE_CHANGED                         | usual.event.POWER_SAVE_MODE_CHANGED                         | 无                                                           |
| COMMON_EVENT_USER_ADDED                                      | usual.event.USER_ADDED                                      | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_USER_REMOVED                                    | usual.event.USER_REMOVED                                    | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_ABILITY_ADDED                                   | usual.event.ABILITY_ADDED                                   | ohos.permission.LISTEN_BUNDLE_CHANGE                         |
| COMMON_EVENT_ABILITY_REMOVED                                 | usual.event.ABILITY_REMOVED                                 | ohos.permission.LISTEN_BUNDLE_CHANGE                         |
| COMMON_EVENT_ABILITY_UPDATED                                 | usual.event.ABILITY_UPDATED                                 | ohos.permission.LISTEN_BUNDLE_CHANGE                         |
| COMMON_EVENT_LOCATION_MODE_STATE_CHANGED                     | usual.event.location.MODE_STATE_CHANGED                     | 无                                                           |
| COMMON_EVENT_IVI_SLEEP                                       | common.event.IVI_SLEEP                                      | 无                                                           |
| COMMON_EVENT_IVI_PAUSE                                       | common.event.IVI_PAUSE                                      | 无                                                           |
| COMMON_EVENT_IVI_STANDBY                                     | common.event.IVI_STANDBY                                    | 无                                                           |
| COMMON_EVENT_IVI_LASTMODE_SAVE                               | common.event.IVI_LASTMODE_SAVE                              | 无                                                           |
| COMMON_EVENT_IVI_VOLTAGE_ABNORMAL                            | common.event.IVI_VOLTAGE_ABNORMAL                           | 无                                                           |
| COMMON_EVENT_IVI_HIGH_TEMPERATURE                            | common.event.IVI_HIGH_TEMPERATURE                           | 无                                                           |
| COMMON_EVENT_IVI_EXTREME_TEMPERATURE                         | common.event.IVI_EXTREME_TEMPERATURE                        | 无                                                           |
| COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL                        | common.event.IVI_TEMPERATURE_ABNORMAL                       | 无                                                           |
| COMMON_EVENT_IVI_VOLTAGE_RECOVERY                            | common.event.IVI_VOLTAGE_RECOVERY                           | 无                                                           |
| COMMON_EVENT_IVI_TEMPERATURE_RECOVERY                        | common.event.IVI_TEMPERATURE_RECOVERY                       | 无                                                           |
| COMMON_EVENT_IVI_ACTIVE                                      | common.event.IVI_ACTIVE                                     | 无                                                           |
| COMMON_EVENT_USB_DEVICE_ATTACHED                             | usual.event.hardware.usb.action.USB_DEVICE_ATTACHED         | 无                                                           |
| COMMON_EVENT_USB_DEVICE_DETACHED                             | usual.event.hardware.usb.action.USB_DEVICE_DETACHED         | 无                                                           |
| COMMON_EVENT_USB_ACCESSORY_ATTACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED      | 无                                                           |
| COMMON_EVENT_USB_ACCESSORY_DETACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED      | 无                                                           |
| COMMON_EVENT_DISK_REMOVED                                    | usual.event.data.DISK_REMOVED                               | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_DISK_UNMOUNTED                                  | usual.event.data.DISK_UNMOUNTED                             | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_DISK_MOUNTED                                    | usual.event.data.DISK_MOUNTED                               | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_DISK_BAD_REMOVAL                                | usual.event.data.DISK_BAD_REMOVAL                           | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_DISK_UNMOUNTABLE                                | usual.event.data.DISK_UNMOUNTABLE                           | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_DISK_EJECT                                      | usual.event.data.DISK_EJECT                                 | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_VOLUME_REMOVED                                  | usual.event.data.VOLUME_REMOVED                             | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_VOLUME_UNMOUNTED                                | usual.event.data.VOLUME_UNMOUNTED                           | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_VOLUME_MOUNTED                                  | usual.event.data.VOLUME_MOUNTED                             | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_VOLUME_BAD_REMOVAL                              | usual.event.data.VOLUME_BAD_REMOVAL                         | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_VOLUME_EJECT                                    | usual.event.data.VOLUME_EJECT                               | ohos.permission.WRITE_USER_STORAGE 或 ohos.permission.READ_USER_STORAGE |
| COMMON_EVENT_VISIBLE_ACCOUNTS_UPDATED                        | usual.event.data.VISIBLE_ACCOUNTS_UPDATED                   | ohos.permission.GET_APP_ACCOUNTS                             |
| COMMON_EVENT_ACCOUNT_DELETED                                 | usual.event.data.ACCOUNT_DELETED                            | ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS               |
| COMMON_EVENT_FOUNDATION_READY                                | usual.event.data.FOUNDATION_READY                           | ohos.permission.RECEIVER_STARTUP_COMPLETED                   |
| COMMON_EVENT_AIRPLANE_MODE_CHANGED                           | usual.event.AIRPLANE_MODE                                   | 无                                                           |
| COMMON_EVENT_SPLIT_SCREEN                                    | usual.event.SPLIT_SCREEN                                    | ohos.permission.RECEIVER_SPLIT_SCREEN                        |

## 导入模块

```js
import CommonEvent from '@ohos.commonEvent';
```

## CommonEvent.publish

publish(event: string, callback: AsyncCallback\<void>): void

发布公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称     | 读写属性 | 类型                 | 必填 | 描述                   |
| -------- | -------- | -------------------- | ---- | ---------------------- |
| event    | 只读     | string               | 是   | 表示要发送的公共事件。 |
| callback | 只读     | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
//发布公共事件回调
function PublishCallBack(err) {
	if (err.code) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

//发布公共事件
CommonEvent.publish("event", PublishCallBack);
```



## CommonEvent.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

发布公共事件指定发布信息（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称     | 读写属性 | 类型                   | 必填 | 描述                   |
| -------- | -------- | ---------------------- | ---- | ---------------------- |
| event    | 只读     | string                 | 是   | 表示要发布的公共事件。  |
| options  | 只读     | [CommonEventPublishData](#commoneventpublishdata) | 是   | 表示发布公共事件的属性。 |
| callback | 只读     | AsyncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**示例：**


```js
//公共事件相关信息
var options = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
	isOrdered: true	 //有序公共事件
}

//发布公共事件回调
function PublishCallBack(err) {
	if (err.code) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

//发布公共事件
CommonEvent.publish("event", options, PublishCallBack);
```



## CommonEvent.publishAsUser<sup>8+</sup>

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

向指定用户发布公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 读写属性 | 类型                 | 必填 | 描述                               |
| -------- | -------- | -------------------- | ---- | ---------------------------------- |
| event    | 只读     | string               | 是   | 表示要发送的公共事件。             |
| userId   | 只读     | number               | 是   | 表示指定向该用户ID发送此公共事件。 |
| callback | 只读     | AsyncCallback\<void> | 是   | 表示被指定的回调方法。             |

**示例：**

```js
//发布公共事件回调
function PublishAsUserCallBack(err) {
	if (err.code) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
var userId = 100;

//发布公共事件
CommonEvent.publishAsUser("event", userId, PublishAsUserCallBack);
```



## CommonEvent.publishAsUser<sup>8+</sup>

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

向指定用户发布公共事件并指定发布信息（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数：**

| 名称     | 读写属性 | 类型                   | 必填 | 描述                   |
| -------- | -------- | ---------------------- | ---- | ---------------------- |
| event    | 只读     | string                 | 是   | 表示要发布的公共事件。  |
| userId | 只读 | number | 是 | 表示指定向该用户ID发送此公共事件。 |
| options  | 只读     | [CommonEventPublishData](#commoneventpublishdata) | 是   | 表示发布公共事件的属性。 |
| callback | 只读     | AsyncCallback\<void>   | 是   | 表示被指定的回调方法。  |

**示例：**


```js
//公共事件相关信息
var options = {
	code: 0,			 //公共事件的初始代码
	data: "initial data",//公共事件的初始数据
}

//发布公共事件回调
function PublishAsUserCallBack(err) {
	if (err.code) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

//指定发送的用户
var userId = 100;

//发布公共事件
CommonEvent.publishAsUser("event", userId, options, PublishAsUserCallBack);
```



## CommonEvent.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

创建订阅者（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称          | 读写属性 | 类型                                                         | 必填 | 描述                       |
| ------------- | -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | 只读     | [CommonEventSubscribeInfo](#commoneventsubscribeinfo)        | 是   | 表示订阅信息。             |
| callback      | 只读     | AsyncCallback\<[CommonEventSubscriber](#commoneventsubscriber)> | 是   | 表示创建订阅者的回调方法。 |

**示例：**


```js
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
	events: ["event"]
};

//创建订阅者回调
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err.code) {
        console.error("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    }
}

//创建订阅者
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
```



## CommonEvent.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

创建订阅者（Promise形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称          | 读写属性 | 类型                                                  | 必填 | 描述           |
| ------------- | -------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | 只读     | [CommonEventSubscribeInfo](#commoneventsubscribeinfo) | 是   | 表示订阅信息。 |

**返回值：**
| 类型                                                      | 说明             |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](#commoneventsubscriber)> | 返回订阅者对象。 |

**示例：**

```js
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
	events: ["event"]
};

//创建订阅者
CommonEvent.createSubscriber(subscribeInfo).then((commonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err) => {
    console.error("createSubscriber failed " + JSON.stringify(err));
});
```



## CommonEvent.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

订阅公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称       | 读写属性 | 类型                                                | 必填 | 描述                             |
| ---------- | -------- | --------------------------------------------------- | ---- | -------------------------------- |
| subscriber | 只读     | [CommonEventSubscriber](#commoneventsubscriber)     | 是   | 表示订阅者对象。                 |
| callback   | 只读     | AsyncCallback\<[CommonEventData](#commoneventdata)> | 是   | 表示接收公共事件数据的回调函数。 |

**示例：**

```js
var subscriber; //用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
    events: ["event"]
};

//订阅公共事件回调
function SubscribeCallBack(err, data) {
    if (err.code) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

//创建订阅者回调
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err.code) {
        console.error("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        CommonEvent.subscribe(subscriber, SubscribeCallBack);
    }
}

//创建订阅者
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
```



## CommonEvent.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

取消订阅公共事件（callback形式）。

**系统能力：** SystemCapability.Notification.CommonEvent

**参数：**

| 名称       | 读写属性 | 类型                                             | 必填 | 描述                     |
| ---------- | -------- | ----------------------------------------------- | ---- | ------------------------ |
| subscriber | 只读     | [CommonEventSubscriber](#commoneventsubscriber) | 是   | 表示订阅者对象。         |
| callback   | 只读     | AsyncCallback\<void>                            | 否   | 表示取消订阅的回调方法。 |

**示例：**

```js
var subscriber;	//用于保存创建成功的订阅者对象，后续使用其完成订阅及退订的动作

//订阅者信息
var subscribeInfo = {
	events: ["event"]
};

//订阅公共事件回调
function SubscribeCallBack(err, data) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

//创建订阅者回调
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err.code) {
        console.info("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        //订阅公共事件
        CommonEvent.subscribe(subscriber, SubscribeCallBack);
    }
}

//取消订阅公共事件回调
function UnsubscribeCallBack(err) {
	if (err.code) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe");
    }
}

//创建订阅者
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);

//取消订阅公共事件
CommonEvent.unsubscribe(subscriber, UnsubscribeCallBack);
```

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

获取公共事件的结果代码（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                   | 必填 | 描述               |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | 是   | 公共事件的结果代码。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//获取有序公共事件的结果代码回调
function getCodeCallback(err, Code) {
    if (err.code) {
        console.error("getCode failed " + JSON.stringify(err));
    } else {
        console.info("getCode " + JSON.stringify(Code));
    }
}
subscriber.getCode(getCodeCallback);
```

### getCode

getCode(): Promise\<number>

获取公共事件的结果代码（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<number> | 公共事件的结果代码。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.getCode().then((Code) => {
    console.info("getCode " + JSON.stringify(Code));
}).catch((err) => {
    console.error("getCode failed " + JSON.stringify(err));
});
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

设置公共事件的结果代码（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果代码回调
function setCodeCallback(err) {
    if (err.code) {
        console.error("setCode failed " + JSON.stringify(err));
    } else {
        console.info("setCode");
    }
}
subscriber.setCode(1, setCodeCallback);
```

### setCode

setCode(code: number): Promise\<void>

设置公共事件的结果代码（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 描述               |
| ------ | ------ | ---- | ------------------ |
| code   | number | 是   | 公共事件的结果代码。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error("setCode failed " + JSON.stringify(err));
});
```

### getData

getData(callback: AsyncCallback\<string>): void

获取公共事件的结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                   | 必填 | 描述                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | 是   | 公共事件的结果数据。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//获取有序公共事件的结果数据回调
function getDataCallback(err, Data) {
    if (err.code) {
        console.error("getData failed " + JSON.stringify(err));
    } else {
        console.info("getData " + JSON.stringify(Data));
    }
}
subscriber.getData(getDataCallback);
```

### getData

getData(): Promise\<string>

获取公共事件的结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明               |
| ---------------- | ------------------ |
| Promise\<string> | 公共事件的结果数据。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.getData().then((Data) => {
    console.info("getData " + JSON.stringify(Data));
}).catch((err) => {
    console.error("getData failed " + JSON.stringify(err));
});
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

设置公共事件的结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | 是   | 公共事件的结果数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果数据回调
function setDataCallback(err) {
    if (err.code) {
        console.error("setData failed " + JSON.stringify(err));
    } else {
        console.info("setData");
    }
}
subscriber.setData("publish_data_changed", setDataCallback);
```

### setData

setData(data: string): Promise\<void>

设置公共事件的结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 描述                 |
| ------ | ------ | ---- | -------------------- |
| data   | string | 是   | 公共事件的结果数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error("setData failed " + JSON.stringify(err));
});
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

设置公共事件的结果代码和结果数据（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                   |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | 是   | 公共事件的结果代码。   |
| data     | string               | 是   | 公共事件的结果数据。   |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//设置有序公共事件的结果代码和结果数据回调
function setCodeDataCallback(err) {
    if (err.code) {
        console.error("setCodeAndData failed " + JSON.stringify(err));
    } else {
        console.info("setCodeDataCallback");
    }
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCallback);
```

### setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

设置公共事件的结果代码和结果数据（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名 | 类型   | 必填 | 描述                 |
| ------ | ------ | ---- | -------------------- |
| code   | number | 是   | 公共事件的结果代码。 |
| data   | string | 是   | 公共事件的结果数据。 |

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.info("setCodeAndData failed " + JSON.stringify(err));
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

查询当前公共事件的是否为有序公共事件（callback形式）。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为有序公共事件。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为有序事件的回调
function isOrderedCallback(err, isOrdered) {
    if (err.code) {
        console.error("isOrderedCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isOrdered " + JSON.stringify(isOrdered));
    }
}
subscriber.isOrderedCommonEvent(isOrderedCallback);
```

### isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

查询当前公共事件的是否为有序公共事件（Promise形式）。

返回true代表是有序公共事件，false代表不是有序公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为有序公共事件。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### isStickyCommonEvent

isStickyCommonEvent(callback: AsyncCallback\<boolean>): void

检查当前公共事件是否为一个粘性事件（callback形式）。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//获取当前公共事件是否为粘性事件的回调
function isStickyCallback(err, isSticky) {
    if (err.code) {
        console.error("isStickyCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("isSticky " + JSON.stringify(isSticky));
    }
}
subscriber.isStickyCommonEvent(isStickyCallback);
```

### isStickyCommonEvent

isStickyCommonEvent(): Promise\<boolean>

检查当前公共事件是否为一个粘性事件（Promise形式）。

返回true代表是粘性公共事件，false代表不是粘性公共事件。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                             |
| ----------------- | -------------------------------- |
| Promise\<boolean> | 当前公共事件的是否为粘性公共事件。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.isStickyCommonEvent().then((isSticky) => {
    console.info("isSticky " + JSON.stringify(isSticky));
}).catch((err) => {
    console.error("isSticky failed " + JSON.stringify(err));
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

取消当前的公共事件，仅对有序公共事件有效，取消后，公共事件不再向下一个订阅者传递（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 取消当前的公共事件。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//取消当前有序公共事件的回调
function abortCallback(err) {
    if (err.code) {
        console.error("abortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("abortCommonEvent");
    }
}
subscriber.abortCommonEvent(abortCallback);
```

### abortCommonEvent

abortCommonEvent(): Promise\<void>

取消当前的公共事件，仅对有序公共事件有效，取消后，公共事件不再向下一个订阅者传递（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error("abortCommonEvent failed " + JSON.stringify(err));
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

清除当前公共事件的取消状态，仅对有序公共事件有效（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                 | 必填 | 描述                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | 是   | 表示被指定的回调方法。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//清除当前公共事件取消状态的回调
function clearAbortCallback(err) {
    if (err.code) {
        console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("clearAbortCommonEvent");
    }
}
subscriber.clearAbortCommonEvent(clearAbortCallback);
```

### clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

清除当前公共事件的取消状态，仅对有序公共事件有效（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

获取当前有序公共事件是否取消的状态（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                    | 必填 | 描述                               |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//获取当前有序公共事件是否取消的回调
function getAbortCallback(err, AbortCommonEvent) {
    if (err.code) {
        console.error("getAbortCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("AbortCommonEvent " + AbortCommonEvent)
    }
}
subscriber.getAbortCommonEvent(getAbortCallback);
```

### getAbortCommonEvent

getAbortCommonEvent(): Promise\<boolean>

获取当前有序公共事件是否取消的状态（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型              | 说明                               |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | 表示当前有序公共事件是否取消的状态。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.getAbortCommonEvent().then((AbortCommonEvent) => {
    console.info("AbortCommonEvent " + JSON.stringify(AbortCommonEvent));
}).catch((err) => {
    console.error("getAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

获取订阅者的订阅信息（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                                                         | 必填 | 描述                   |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | 是   | 表示订阅者的订阅信息。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

//获取订阅者信息回调
function getSubscribeInfoCallback(err, SubscribeInfo) {
    if (err.code) {
        console.error("getSubscribeInfo failed " + JSON.stringify(err));
    } else {
        console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
    }
}
subscriber.getSubscribeInfo(getSubscribeInfoCallback);
```

### getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

获取订阅者的订阅信息（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型                                                         | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | 表示订阅者的订阅信息。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.getSubscribeInfo().then((SubscribeInfo) => {
    console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(callback: AsyncCallback\<void\>): void

结束当前有序公共事件（callback形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**参数：**

| 参数名   | 类型                  | 必填 | 描述                              |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | 是   | 表示有序公共事件结束后的回调函数。 |

**示例：**

```js
var subscriber; //创建成功的订阅者对象

//结束当前有序公共事件的回调
function finishCommonEventCallback(err) {
  if (err.code) {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
} else {
    console.info("FinishCommonEvent");
}
}
subscriber.finishCommonEvent(finishCommonEventCallback);
```

### finishCommonEvent<sup>9+</sup>

finishCommonEvent(): Promise\<void\>

结束当前有序公共事件（Promise形式）。

**系统能力**：SystemCapability.Notification.CommonEvent

**返回值：**

| 类型             | 说明                 |
| ---------------- | -------------------- |
| Promise\<void>   | 返回一个Promise的结果。 |

**示例：**

```js
var subscriber;	//创建成功的订阅者对象

subscriber.finishCommonEvent().then(() => {
    console.info("FinishCommonEvent");
}).catch((err) => {
    console.error("finishCommonEvent failed " + JSON.stringify(err));
});
```

## CommonEventData

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称       | 读写属性 | 类型                 | 必填 | 描述                                                    |
| ---------- | -------- | -------------------- | ---- | ------------------------------------------------------- |
| event      | 只读     | string               | 是   | 表示当前接收的公共事件名称。                              |
| bundleName | 只读     | string               | 否   | 表示包名称。                                              |
| code       | 只读     | number               | 否   | 表示公共事件的结果代码，用于传递int类型的数据。           |
| data       | 只读     | string               | 否   | 表示公共事件的自定义结果数据，用于传递string类型的数据。 |
| parameters | 只读     | {[key: string]: any} | 否   | 表示公共事件的附加信息。                                  |


## CommonEventPublishData

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                  | 读写属性 | 类型                 | 必填 | 描述                         |
| --------------------- | -------- | -------------------- | ---- | ---------------------------- |
| bundleName            | 只读     | string               | 否   | 表示包名称。                   |
| code                  | 只读     | number               | 否   | 表示公共事件的结果代码。       |
| data                  | 只读     | string               | 否   | 表示公共事件的自定义结果数据。 |
| subscriberPermissions | 只读     | Array\<string>       | 否   | 表示订阅者的权限。             |
| isOrdered             | 只读     | boolean              | 否   | 表示是否是有序事件。           |
| isSticky              | 只读     | boolean              | 否   | 表示是否是粘性事件。           |
| parameters            | 只读     | {[key: string]: any} | 否   | 表示公共事件的附加信息。       |

## CommonEventSubscribeInfo

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Notification.CommonEvent

| 名称                | 读写属性 | 类型           | 必填 | 描述                                                         |
| ------------------- | -------- | -------------- | ---- | ------------------------------------------------------------ |
| events              | 只读     | Array\<string> | 是   | 表示要发送的公共事件。                                         |
| publisherPermission | 只读     | string         | 否   | 表示发布者的权限。                                             |
| publisherDeviceId   | 只读     | string         | 否   | 表示设备ID，该值必须是同一ohos网络上的现有设备ID。             |
| userId              | 只读     | number         | 否   | 表示用户ID。此参数是可选的，默认值当前用户的ID。如果指定了此参数，则该值必须是系统中现有的用户ID。 |
| priority            | 只读     | number         | 否   | 表示订阅者的优先级。值的范围是-100到1000。                     |