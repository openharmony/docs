# CommonEvent Module

> **Note:**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Required Permissions

| Common Event Macro     | Common Event Name         | Subscriber Permissions    |
| ------------ | ------------------ | ---------------------- |
| COMMON_EVENT_BOOT_COMPLETED                                  | usual.event.BOOT_COMPLETED                                  | ohos.permission.RECEIVER_STARTUP_COMPLETED                   |
| COMMON_EVENT_SHUTDOWN                                        | usual.event.SHUTDOWN                                        | N/A                                                          |
| COMMON_EVENT_BATTERY_CHANGED                                 | usual.event.BATTERY_CHANGED                                 | N/A                                                          |
| COMMON_EVENT_BATTERY_LOW                                     | usual.event.BATTERY_LOW                                     | N/A                                                          |
| COMMON_EVENT_BATTERY_OKAY                                    | usual.event.BATTERY_OKAY                                    | N/A                                                          |
| COMMON_EVENT_POWER_CONNECTED                                 | usual.event.POWER_CONNECTED                                 | N/A                                                          |
| COMMON_EVENT_POWER_DISCONNECTED                              | usual.event.POWER_DISCONNECTED                              | N/A                                                          |
| COMMON_EVENT_SCREEN_OFF                                      | usual.event.SCREEN_OFF                                      | N/A                                                          |
| COMMON_EVENT_SCREEN_ON                                       | usual.event.SCREEN_ON                                       | N/A                                                          |
| COMMON_EVENT_USER_PRESENT                                    | usual.event.USER_PRESENT                                    | N/A                                                          |
| COMMON_EVENT_TIME_TICK                                       | usual.event.TIME_TICK                                       | N/A                                                          |
| COMMON_EVENT_TIME_CHANGED                                    | usual.event.TIME_CHANGED                                    | N/A                                                          |
| COMMON_EVENT_DATE_CHANGED                                    | usual.event.DATE_CHANGED                                    | N/A                                                          |
| COMMON_EVENT_TIMEZONE_CHANGED                                | usual.event.TIMEZONE_CHANGED                                | N/A                                                          |
| COMMON_EVENT_CLOSE_SYSTEM_DIALOGS                            | usual.event.CLOSE_SYSTEM_DIALOGS                            | N/A                                                          |
| COMMON_EVENT_PACKAGE_ADDED                                   | usual.event.PACKAGE_ADDED                                   | N/A                                                          |
| COMMON_EVENT_PACKAGE_REPLACED                                | usual.event.PACKAGE_REPLACED                                | N/A                                                          |
| COMMON_EVENT_MY_PACKAGE_REPLACED                             | usual.event.MY_PACKAGE_REPLACED                             | N/A                                                          |
| COMMON_EVENT_PACKAGE_REMOVED                                 | usual.event.PACKAGE_REMOVED                                 | N/A                                                          |
| COMMON_EVENT_PACKAGE_FULLY_REMOVED                           | usual.event.PACKAGE_FULLY_REMOVED                           | N/A                                                          |
| COMMON_EVENT_PACKAGE_CHANGED                                 | usual.event.PACKAGE_CHANGED                                 | N/A                                                          |
| COMMON_EVENT_PACKAGE_RESTARTED                               | usual.event.PACKAGE_RESTARTED                               | N/A                                                          |
| COMMON_EVENT_PACKAGE_DATA_CLEARED                            | usual.event.PACKAGE_DATA_CLEARED                            | N/A                                                          |
| COMMON_EVENT_PACKAGES_SUSPENDED                              | usual.event.PACKAGES_SUSPENDED                              | N/A                                                          |
| COMMON_EVENT_PACKAGES_UNSUSPENDED                            | usual.event.PACKAGES_UNSUSPENDED                            | N/A                                                          |
| COMMON_EVENT_MY_PACKAGE_SUSPENDED                            | usual.event.MY_PACKAGE_SUSPENDED                            | N/A                                                          |
| COMMON_EVENT_MY_PACKAGE_UNSUSPENDED                          | usual.event.MY_PACKAGE_UNSUSPENDED                          | N/A                                                          |
| COMMON_EVENT_UID_REMOVED                                     | usual.event.UID_REMOVED                                     | N/A                                                          |
| COMMON_EVENT_PACKAGE_FIRST_LAUNCH                            | usual.event.PACKAGE_FIRST_LAUNCH                            | N/A                                                          |
| COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION                      | usual.event.PACKAGE_NEEDS_VERIFICATION                      | N/A                                                          |
| COMMON_EVENT_PACKAGE_VERIFIED                                | usual.event.PACKAGE_VERIFIED                                | N/A                                                          |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE                 | usual.event.EXTERNAL_APPLICATIONS_AVAILABLE                 | N/A                                                          |
| COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE               | usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE               | N/A                                                          |
| COMMON_EVENT_CONFIGURATION_CHANGED                           | usual.event.CONFIGURATION_CHANGED                           | N/A                                                          |
| COMMON_EVENT_LOCALE_CHANGED                                  | usual.event.LOCALE_CHANGED                                  | N/A                                                          |
| COMMON_EVENT_MANAGE_PACKAGE_STORAGE                          | usual.event.MANAGE_PACKAGE_STORAGE                          | N/A                                                          |
| COMMON_EVENT_DRIVE_MODE                                      | common.event.DRIVE_MODE                                     | N/A                                                          |
| COMMON_EVENT_HOME_MODE                                       | common.event.HOME_MODE                                      | N/A                                                          |
| COMMON_EVENT_OFFICE_MODE                                     | common.event.OFFICE_MODE                                    | N/A                                                          |
| COMMON_EVENT_USER_STARTED                                    | usual.event.USER_STARTED                                    | N/A                                                          |
| COMMON_EVENT_USER_BACKGROUND                                 | usual.event.USER_BACKGROUND                                 | N/A                                                          |
| COMMON_EVENT_USER_FOREGROUND                                 | usual.event.USER_FOREGROUND                                 | N/A                                                          |
| COMMON_EVENT_USER_SWITCHED                                   | usual.event.USER_SWITCHED                                   | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_USER_UNLOCKED                                   | usual.event.USER_UNLOCKED                                   | N/A                                                          |
| COMMON_EVENT_USER_STOPPED                                    | usual.event.USER_STOPPED                                    | N/A                                                          |
| COMMON_EVENT_HWID_LOGIN                                      | common.event.HWID_LOGIN                                     | N/A                                                          |
| COMMON_EVENT_HWID_LOGOUT                                     | common.event.HWID_LOGOUT                                    | N/A                                                          |
| COMMON_EVENT_HWID_TOKEN_INVALID                              | common.event.HWID_TOKEN_INVALID                             | N/A                                                          |
| COMMON_EVENT_HWID_LOGOFF                                     | common.event.HWID_LOGOFF                                    | N/A                                                          |
| COMMON_EVENT_WIFI_POWER_STATE                                | usual.event.wifi.POWER_STATE                                | N/A                                                          |
| COMMON_EVENT_WIFI_SCAN_FINISHED                              | usual.event.wifi.SCAN_FINISHED                              | ohos.permission.LOCATION                                     |
| COMMON_EVENT_WIFI_RSSI_VALUE                                 | usual.event.wifi.RSSI_VALUE                                 | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_CONN_STATE                                 | usual.event.wifi.CONN_STATE                                 | N/A                                                          |
| COMMON_EVENT_WIFI_HOTSPOT_STATE                              | usual.event.wifi.HOTSPOT_STATE                              | N/A                                                          |
| COMMON_EVENT_WIFI_AP_STA_JOIN                                | usual.event.wifi.WIFI_HS_STA_JOIN                           | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_AP_STA_LEAVE                               | usual.event.wifi.WIFI_HS_STA_LEAVE                          | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_CONN_STATE                             | usual.event.wifi.p2p.CONN_STATE_CHANGE                      | ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION   |
| COMMON_EVENT_WIFI_P2P_STATE_CHANGED                          | usual.event.wifi.p2p.STATE_CHANGE                           | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED                    | usual.event.wifi.p2p.DEVICES_CHANGE                         | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED          | usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE            | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED           | usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE                  | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED                    | usual.event.wifi.p2p.GROUP_STATE_CHANGED                    | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT               | usual.event.bluetooth.remotedevice.SDP_RESULT               | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL           | usual.event.bluetooth.remotedevice.PAIRING_CANCEL           | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ              | usual.event.bluetooth.remotedevice.CONNECT_REQ              | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY            | usual.event.bluetooth.remotedevice.CONNECT_REPLY            | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL           | usual.event.bluetooth.remotedevice.CONNECT_CANCEL           | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE    | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE      | usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE      | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT         | usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT         | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE    | N/A                                                          |
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE                 | usual.event.bluetooth.host.REQ_DISCOVERABLE                 | N/A                                                          |
| COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED                | usual.event.nfc.action.ADAPTER_STATE_CHANGED                | N/A                                                          |
| COMMON_EVENT_DISCHARGING                                     | usual.event.DISCHARGING                                     | N/A                                                          |
| COMMON_EVENT_CHARGING                                        | usual.event.CHARGING                                        | N/A                                                          |
| COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED                        | usual.event.DEVICE_IDLE_MODE_CHANGED                        | N/A                                                          |
| COMMON_EVENT_POWER_SAVE_MODE_CHANGED                         | usual.event.POWER_SAVE_MODE_CHANGED                         | N/A                                                          |
| COMMON_EVENT_USER_ADDED                                      | usual.event.USER_ADDED                                      | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_USER_REMOVED                                    | usual.event.USER_REMOVED                                    | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_LOCATION_MODE_STATE_CHANGED                     | usual.event.location.MODE_STATE_CHANGED                     | N/A                                                          |
| COMMON_EVENT_IVI_SLEEP                                       | common.event.IVI_SLEEP                                      | N/A                                                          |
| COMMON_EVENT_IVI_PAUSE                                       | common.event.IVI_PAUSE                                      | N/A                                                          |
| COMMON_EVENT_IVI_STANDBY                                     | common.event.IVI_STANDBY                                    | N/A                                                          |
| COMMON_EVENT_IVI_LASTMODE_SAVE                               | common.event.IVI_LASTMODE_SAVE                              | N/A                                                          |
| COMMON_EVENT_IVI_VOLTAGE_ABNORMAL                            | common.event.IVI_VOLTAGE_ABNORMAL                           | N/A                                                          |
| COMMON_EVENT_IVI_HIGH_TEMPERATURE                            | common.event.IVI_HIGH_TEMPERATURE                           | N/A                                                          |
| COMMON_EVENT_IVI_EXTREME_TEMPERATURE                         | common.event.IVI_EXTREME_TEMPERATURE                        | N/A                                                          |
| COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL                        | common.event.IVI_TEMPERATURE_ABNORMAL                       | N/A                                                          |
| COMMON_EVENT_IVI_VOLTAGE_RECOVERY                            | common.event.IVI_VOLTAGE_RECOVERY                           | N/A                                                          |
| COMMON_EVENT_IVI_TEMPERATURE_RECOVERY                        | common.event.IVI_TEMPERATURE_RECOVERY                       | N/A                                                          |
| COMMON_EVENT_IVI_ACTIVE                                      | common.event.IVI_ACTIVE                                     | N/A                                                          |
| COMMON_EVENT_USB_DEVICE_ATTACHED                             | usual.event.hardware.usb.action.USB_DEVICE_ATTACHED         | N/A                                                          |
| COMMON_EVENT_USB_DEVICE_DETACHED                             | usual.event.hardware.usb.action.USB_DEVICE_DETACHED         | N/A                                                          |
| COMMON_EVENT_USB_ACCESSORY_ATTACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED      | N/A                                                          |
| COMMON_EVENT_USB_ACCESSORY_DETACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED      | N/A                                                          |
| COMMON_EVENT_DISK_REMOVED                                    | usual.event.data.DISK_REMOVED                               | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_UNMOUNTED                                  | usual.event.data.DISK_UNMOUNTED                             | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_MOUNTED                                    | usual.event.data.DISK_MOUNTED                               | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_BAD_REMOVAL                                | usual.event.data.DISK_BAD_REMOVAL                           | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_EJECT                                      | usual.event.data.DISK_EJECT                                 | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_AIRPLANE_MODE_CHANGED                           | usual.event.AIRPLANE_MODE                                   | N/A                                                          |

## Modules to Import

```js
import CommonEvent from '@ohos.commonEvent';
```

## CommonEvent.publish

publish(event: string, callback: AsyncCallback\<void>): void

Publishes a common event. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Readable/Writable| Type                | Mandatory| Description                  |
| -------- | -------- | -------------------- | ---- | ---------------------- |
| event    | Read-only    | string               | Yes  | Name of the common event to publish.|
| callback | Read-only    | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
// Callback for common event publication
function PublishCallBack(err) {
	if (err.code) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
CommonEvent.publish("event", PublishCallBack);
```



## CommonEvent.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Readable/Writable| Type                  | Mandatory| Description                  |
| -------- | -------- | ---------------------- | ---- | ---------------------- |
| event    | Read-only    | string                 | Yes  | Name of the common event to publish. |
| options  | Read-only    | [CommonEventPublishData](#commoneventpublishdata) | Yes  | Attributes of the common event to publish.|
| callback | Read-only    | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Example**


```js
// Attributes of a common event.
var options = {
	code: 0,			 // Result code of the common event
	data: "initial data";// Result data of the common event
	isOrdered: true	 // The common event is an ordered one.
}

// Callback for common event publication
function PublishCallBack(err) {
	if (err.code) {
        console.error("publish failed " + JSON.stringify(err));
    } else {
        console.info("publish");
    }
}

// Publish a common event.
CommonEvent.publish("event", options, PublishCallBack);
```



## CommonEvent.publishAsUser

publishAsUser(event: string, userId: number, callback: AsyncCallback\<void>): void

Publishes a common event to a specific user. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Readable/Writable| Type                | Mandatory| Description                              |
| -------- | -------- | -------------------- | ---- | ---------------------------------- |
| event    | Read-only    | string               | Yes  | Name of the common event to publish.            |
| userId   | Read-only    | number               | Yes  | User ID.|
| callback | Read-only    | AsyncCallback\<void> | Yes  | Callback used to return the result.            |

**Example**

```js
// Callback for common event publication
function PublishAsUserCallBack(err) {
	if (err.code) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
var userId = 100;

// Publish a common event.
CommonEvent.publishAsUser("event", userId, PublishAsUserCallBack);
```



## CommonEvent.publishAsUser

publishAsUser(event: string, userId: number, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes to a specific user. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name    | Readable/Writable| Type                  | Mandatory| Description                  |
| -------- | -------- | ---------------------- | ---- | ---------------------- |
| event    | Read-only    | string                 | Yes  | Name of the common event to publish. |
| userId | Read-only| number | Yes| User ID.|
| options  | Read-only    | [CommonEventPublishData](#commoneventpublishdata) | Yes  | Attributes of the common event to publish.|
| callback | Read-only    | AsyncCallback\<void>   | Yes  | Callback used to return the result. |

**Example**


```js
// Attributes of a common event.
var options = {
	code: 0;			 // Result code of the common event
	data: "initial data";// Result data of the common event
}

// Callback for common event publication
function PublishAsUserCallBack(err) {
	if (err.code) {
        console.error("publishAsUser failed " + JSON.stringify(err));
    } else {
        console.info("publishAsUser");
    }
}

// Specify the user to whom the common event will be published.
var userId = 100;

// Publish a common event.
CommonEvent.publishAsUser("event", userId, options, PublishAsUserCallBack);
```



## CommonEvent.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

Creates a subscriber. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Readable/Writable| Type                                                        | Mandatory| Description                      |
| ------------- | -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | Read-only    | [CommonEventSubscribeInfo](#commoneventsubscribeinfo)        | Yes  | Subscriber information.            |
| callback      | Read-only    | AsyncCallback\<[CommonEventSubscriber](#commoneventsubscriber)> | Yes  | Callback used to return the result.|

**Example**


```js
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information
var subscribeInfo = {
	events: ["event"]
};

// Callback for subscriber creation
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err.code) {
        console.error("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
```



## CommonEvent.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

Creates a subscriber. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name         | Readable/Writable| Type                                                 | Mandatory| Description          |
| ------------- | -------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | Read-only    | [CommonEventSubscribeInfo](#commoneventsubscribeinfo) | Yes  | Subscriber information.|

**Return value**
| Type                                                     | Description            |
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](#commoneventsubscriber)> | Promise used to return the subscriber object.|

**Example**

```js
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information
var subscribeInfo = {
	events: ["event"]
};

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo).then((commonEventSubscriber) => {
    console.info("createSubscriber");
    subscriber = commonEventSubscriber;
}).catch((err) => {
    console.error("createSubscriber failed " + JSON.stringify(err));
});
```



## CommonEvent.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

Subscribes to common events. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Readable/Writable| Type                                               | Mandatory| Description                            |
| ---------- | -------- | --------------------------------------------------- | ---- | -------------------------------- |
| subscriber | Read-only    | [CommonEventSubscriber](#commoneventsubscriber)     | Yes  | Subscriber object.                |
| callback   | Read-only    | AsyncCallback\<[CommonEventData](#commoneventdata)> | Yes  | Callback used to return the result.|

**Example**

Unordered common event:

```js
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information
var subscribeInfo = {
    events: ["event"]
};

// Callback for common event subscription
function SubscribeCallBack(err, data) {
    if (err.code) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

// Callback for subscriber creation
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err.code) {
        console.error("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        CommonEvent.subscribe(subscriber, SubscribeCallBack);
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
```

 Ordered common event:

```js
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information
var subscribeInfo = {
    events: ["event"]
};

// Callback for result code setting of an ordered common event
function SetCodeCallBack(err) {
    if (err.code) {
        console.error("setCode failed " + JSON.stringify(err));
    } else {
        console.info("setCode");
    }
}

// Callback for result data setting of an ordered common event
function SetDataCallBack(err) {
    if (err.code) {
        console.error("setData failed " + JSON.stringify(err));
    } else {
        console.info("setData");
    }
}

// Callback for ordered common event processing
function FinishCommonEventCallBack(err) {
    if (err.code) {
        console.error("finishCommonEvent failed " + JSON.stringify(err));
    } else {
        console.info("finishCommonEvent");
    }
}

// Callback for common event subscription
function SubscribeCallBack(err, data) {
    if (err.code) {
        console.error("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe " + JSON.stringify(data));
        // Set the result code for the ordered common event.
        subscriber.setCode(0, SetCodeCallBack);
        // Set the result data for the ordered common event.
        subscriber.setData("publish_data_changed", SetDataCallBack);
        // Complete the processing of the ordered common event.
        subscriber.finishCommonEvent(FinishCommonEventCallBack)
    }
}

// Callback for subscriber creation
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err.code) {
        console.error("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        CommonEvent.subscribe(subscriber, SubscribeCallBack);
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
```



## CommonEvent.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

Unsubscribes from common events. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name      | Readable/Writable| Type                 | Mandatory| Description                    |
| ---------- | -------- | --------------------- | ---- | ------------------------ |
| subscriber | Read-only    | CommonEventSubscriber | Yes  | Subscriber object.        |
| callback   | Read-only    | AsyncCallback\<void>  | Yes  | Callback used to return the result.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.

// Subscriber information
var subscribeInfo = {
	events: ["event"]
};

// Callback for common event subscription
function SubscribeCallBack(err, data) {
    if (err.code) {
        console.info("subscribe failed " + JSON.stringify(err));
    } else {
        console.info("subscribe " + JSON.stringify(data));
    }
}

// Callback for subscriber creation
function CreateSubscriberCallBack(err, commonEventSubscriber) {
    if (err.code) {
        console.info("createSubscriber failed " + JSON.stringify(err));
    } else {
        console.info("createSubscriber");
        subscriber = commonEventSubscriber;
        // Subscribe to a common event.
        CommonEvent.subscribe(subscriber, SubscribeCallBack);
    }
}

// Callback for common event unsubscription
function UnsubscribeCallBack(err) {
	if (err.code) {
        console.info("unsubscribe failed " + JSON.stringify(err));
    } else {
        console.info("unsubscribe");
    }
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);

// Unsubscribe from the common event.
CommonEvent.unsubscribe(subscriber, UnsubscribeCallBack);
```

## CommonEventPublishData

| Name                 | Readable/Writable| Type                | Mandatory| Description                                                        |
| --------------------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName            | Read-only    | string               | No  | Bundle name.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| code                  | Read-only    | number               | No  | Result code of the common event.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| data                  | Read-only    | string               | No  | Custom result data of the common event.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| subscriberPermissions | Read-only    | Array\<string>       | No  | Permissions required for subscribers to receive the common event.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| isOrdered             | Read-only    | boolean              | No  | Whether the common event is an ordered one.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| parameters            | Read-only    | {[key: string]: any} | No  | Additional information about the common event.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|

## CommonEventSubscribeInfo

| Name               | Readable/Writable| Type          | Mandatory| Description                                                        |
| ------------------- | -------- | -------------- | ---- | ------------------------------------------------------------ |
| events              | Read-only    | Array\<string> | Yes  | Common events to subscribe to.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| publisherPermission | Read-only    | string         | No  | Permission required for the publisher.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| publisherDeviceId   | Read-only    | string         | No  | Device ID. The value must be the ID of an existing device on the same network.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| userId              | Read-only    | number         | No  | User ID. The default value is the ID of the current user. If this parameter is specified, the value must be an existing user ID in the system.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| priority            | Read-only    | number         | No  | Subscriber priority. The value ranges from -100 to 1000.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|

## CommonEventData

| Name      | Readable/Writable| Type                | Mandatory| Description                                                        |
| ---------- | -------- | -------------------- | ---- | ------------------------------------------------------------ |
| event      | Read-only    | string               | Yes  | Name of the common event to subscribe to.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| bundleName | Read-only    | string               | No  | Bundle name.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| code       | Read-only    | number               | No  | Result code of the common event, which is used to transfer data of the int type.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| data       | Read-only    | string               | No  | Custom result data of the common event, which is used to transfer data of the string type.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|
| parameters | Read-only    | {[key: string]: any} | No  | Additional information about the common event.<br>**System capabilities**: SystemCapability.Notification.CommonEvent|

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

Obtains the result code of this common event. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description              |
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result code.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
getCode() {
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

Obtains the result code of this common event. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description                |
| ---------------- | -------------------- |
| Promise\<number> | Promise used to return the result code.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.getCode().then((Code) => {
    console.info("getCode " + JSON.stringify(Code));
}).catch((err) => {
    console.error("getCode failed " + JSON.stringify(err));
});
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

Sets the result code for this common event. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Sets the result code for this common event. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes  | Callback used to return the result code.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.setCode(1).then(() => {
    console.info("setCode");
}).catch((err) => {
    console.error("setCode failed " + JSON.stringify(err));
});
```

### getData

getData(callback: AsyncCallback\<string>): void

Obtains the result data of this common event. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                  | Mandatory| Description                |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the result data.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Obtains the result data of this common event. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Return value**

| Type            | Description              |
| ---------------- | ------------------ |
| Promise\<string> | Promise used to return the result data.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.getData().then((Data) => {
    console.info("getData " + JSON.stringify(Data));
}).catch((err) => {
    console.error("getData failed " + JSON.stringify(err));
});
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

Sets the result data for this common event. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | Yes  | Result data of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Sets the result data for this common event. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes  | Callback used to return the result data.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.setData("publish_data_changed").then(() => {
    console.info("setData");
}).catch((err) => {
    console.error("setData failed " + JSON.stringify(err));
});
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

Sets the result code and result data for this common event. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                  |
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes  | Result code of the common event.  |
| data     | string               | Yes  | Result data of the common event.  |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Sets the result code and result data for this common event. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes  | Result code of the common event.|
| data   | string | Yes  | Callback used to return the result data.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
    console.info("setCodeAndData");
}).catch((err) => {
    console.info("setCodeAndData failed " + JSON.stringify(err));
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is an ordered one. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Checks whether this common event is an ordered one. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                            |
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.isOrderedCommonEvent().then((isOrdered) => {
    console.info("isOrdered " + JSON.stringify(isOrdered));
}).catch((err) => {
    console.error("isOrdered failed " + JSON.stringify(err));
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This method takes effect only for ordered common events. It uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This method takes effect only for ordered common events. It uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.abortCommonEvent().then(() => {
    console.info("abortCommonEvent");
}).catch((err) => {
    console.error("abortCommonEvent failed " + JSON.stringify(err));
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

Clears the aborted state of this common event. This method takes effect only for ordered common events. It uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Clears the aborted state of this common event. This method takes effect only for ordered common events. It uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.clearAbortCommonEvent().then(() => {
    console.info("clearAbortCommonEvent");
}).catch((err) => {
    console.error("clearAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is in the aborted state. This method takes effect only for ordered common events. It uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                   | Mandatory| Description                              |
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

getAbortCommonEvent(): Promise\<void>

Checks whether this common event is in the aborted state. This method takes effect only for ordered common events. It uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Return value**

| Type             | Description                              |
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.getAbortCommonEvent().then((AbortCommonEvent) => {
    console.info("AbortCommonEvent " + JSON.stringify(AbortCommonEvent));
}).catch((err) => {
    console.error("getAbortCommonEvent failed " + JSON.stringify(err));
});
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

Obtains the subscriber information. This method uses a callback to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Parameters**

| Name  | Type                                                        | Mandatory| Description                  |
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Yes  | Callback used to return the subscriber information.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

// Callback for result data setting of an ordered common event
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

Obtains the subscriber information. This method uses a promise to return the result.

**System capabilities**: SystemCapability.Notification.CommonEvent

**Return value**

| Type                                                        | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Promise used to return the subscriber information.|

**Example**

```js
var subscriber;	// Subscriber object successfully created

subscriber.getSubscribeInfo().then((SubscribeInfo) => {
    console.info("SubscribeInfo " + JSON.stringify(SubscribeInfo));
}).catch((err) => {
    console.error("getSubscribeInfo failed " + JSON.stringify(err));
});
```
