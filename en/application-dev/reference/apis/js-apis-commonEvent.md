# CommonEvent Module

> **Note:**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Required Permissions

| Common Event Macro| Common Event Name| Subscriber Permissions|
| ------------ | ------------------ | ---------------------- |
| COMMON_EVENT_BOOT_COMPLETED                                  | usual.event.BOOT_COMPLETED                                  | ohos.permission.RECEIVER_STARTUP_COMPLETED                   |
| COMMON_EVENT_SHUTDOWN                                        | usual.event.SHUTDOWN                                        | N/A|
| COMMON_EVENT_BATTERY_CHANGED                                 | usual.event.BATTERY_CHANGED                                 | N/A|
| COMMON_EVENT_BATTERY_LOW                                     | usual.event.BATTERY_LOW                                     | N/A|
| COMMON_EVENT_BATTERY_OKAY                                    | usual.event.BATTERY_OKAY                                    | N/A|
| COMMON_EVENT_POWER_CONNECTED                                 | usual.event.POWER_CONNECTED                                 | N/A|
| COMMON_EVENT_POWER_DISCONNECTED                              | usual.event.POWER_DISCONNECTED                              | N/A|
| COMMON_EVENT_SCREEN_OFF                                      | usual.event.SCREEN_OFF                                      | N/A|
| COMMON_EVENT_SCREEN_ON                                       | usual.event.SCREEN_ON                                       | N/A|
| COMMON_EVENT_USER_PRESENT                                    | usual.event.USER_PRESENT                                    | N/A|
| COMMON_EVENT_TIME_TICK                                       | usual.event.TIME_TICK                                       | N/A|
| COMMON_EVENT_TIME_CHANGED                                    | usual.event.TIME_CHANGED                                    | N/A|
| COMMON_EVENT_DATE_CHANGED                                    | usual.event.DATE_CHANGED                                    | N/A|
| COMMON_EVENT_TIMEZONE_CHANGED                                | usual.event.TIMEZONE_CHANGED                                | N/A|
| COMMON_EVENT_CLOSE_SYSTEM_DIALOGS                            | usual.event.CLOSE_SYSTEM_DIALOGS                            | N/A|
| COMMON_EVENT_PACKAGE_ADDED                                   | usual.event.PACKAGE_ADDED                                   | N/A|
| COMMON_EVENT_PACKAGE_REPLACED                                | usual.event.PACKAGE_REPLACED                                | N/A|
| COMMON_EVENT_MY_PACKAGE_REPLACED                             | usual.event.MY_PACKAGE_REPLACED                             | N/A|
| COMMON_EVENT_PACKAGE_REMOVED                                 | usual.event.PACKAGE_REMOVED                                 | N/A|
| COMMON_EVENT_PACKAGE_FULLY_REMOVED                           | usual.event.PACKAGE_FULLY_REMOVED                           | N/A|
| COMMON_EVENT_PACKAGE_CHANGED                                 | usual.event.PACKAGE_CHANGED                                 | N/A|
| COMMON_EVENT_PACKAGE_RESTARTED                               | usual.event.PACKAGE_RESTARTED                               | N/A|
| COMMON_EVENT_PACKAGE_DATA_CLEARED                            | usual.event.PACKAGE_DATA_CLEARED                            | N/A|
| COMMON_EVENT_PACKAGES_SUSPENDED                              | usual.event.PACKAGES_SUSPENDED                              | N/A|
| COMMON_EVENT_PACKAGES_UNSUSPENDED                            | usual.event.PACKAGES_UNSUSPENDED                            | N/A|
| COMMON_EVENT_MY_PACKAGE_SUSPENDED                            | usual.event.MY_PACKAGE_SUSPENDED                            | N/A|
| COMMON_EVENT_MY_PACKAGE_UNSUSPENDED                          | usual.event.MY_PACKAGE_UNSUSPENDED                          | N/A|
| COMMON_EVENT_UID_REMOVED                                     | usual.event.UID_REMOVED                                     | N/A|
| COMMON_EVENT_PACKAGE_FIRST_LAUNCH                            | usual.event.PACKAGE_FIRST_LAUNCH                            | N/A|
| COMMON_EVENT_PACKAGE_NEEDS_VERIFICATION                      | usual.event.PACKAGE_NEEDS_VERIFICATION                      | N/A|
| COMMON_EVENT_PACKAGE_VERIFIED                                | usual.event.PACKAGE_VERIFIED                                | N/A|
| COMMON_EVENT_EXTERNAL_APPLICATIONS_AVAILABLE                 | usual.event.EXTERNAL_APPLICATIONS_AVAILABLE                 | N/A|
| COMMON_EVENT_EXTERNAL_APPLICATIONS_UNAVAILABLE               | usual.event.EXTERNAL_APPLICATIONS_UNAVAILABLE               | N/A|
| COMMON_EVENT_CONFIGURATION_CHANGED                           | usual.event.CONFIGURATION_CHANGED                           | N/A|
| COMMON_EVENT_LOCALE_CHANGED                                  | usual.event.LOCALE_CHANGED                                  | N/A|
| COMMON_EVENT_MANAGE_PACKAGE_STORAGE                          | usual.event.MANAGE_PACKAGE_STORAGE                          | N/A|
| COMMON_EVENT_DRIVE_MODE                                      | common.event.DRIVE_MODE                                     | N/A|
| COMMON_EVENT_HOME_MODE                                       | common.event.HOME_MODE                                      | N/A|
| COMMON_EVENT_OFFICE_MODE                                     | common.event.OFFICE_MODE                                    | N/A|
| COMMON_EVENT_USER_STARTED                                    | usual.event.USER_STARTED                                    | N/A|
| COMMON_EVENT_USER_BACKGROUND                                 | usual.event.USER_BACKGROUND                                 | N/A|
| COMMON_EVENT_USER_FOREGROUND                                 | usual.event.USER_FOREGROUND                                 | N/A|
| COMMON_EVENT_USER_SWITCHED                                   | usual.event.USER_SWITCHED                                   | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_USER_UNLOCKED                                   | usual.event.USER_UNLOCKED                                   | N/A|
| COMMON_EVENT_USER_STOPPED                                    | usual.event.USER_STOPPED                                    | N/A|
| COMMON_EVENT_HWID_LOGIN                                      | common.event.HWID_LOGIN                                     | N/A|
| COMMON_EVENT_HWID_LOGOUT                                     | common.event.HWID_LOGOUT                                    | N/A|
| COMMON_EVENT_HWID_TOKEN_INVALID                              | common.event.HWID_TOKEN_INVALID                             | N/A|
| COMMON_EVENT_HWID_LOGOFF                                     | common.event.HWID_LOGOFF                                    | N/A|
| COMMON_EVENT_WIFI_POWER_STATE                                | usual.event.wifi.POWER_STATE                                | N/A|
| COMMON_EVENT_WIFI_SCAN_FINISHED                              | usual.event.wifi.SCAN_FINISHED                              | ohos.permission.LOCATION                                     |
| COMMON_EVENT_WIFI_RSSI_VALUE                                 | usual.event.wifi.RSSI_VALUE                                 | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_CONN_STATE                                 | usual.event.wifi.CONN_STATE                                 | N/A|
| COMMON_EVENT_WIFI_HOTSPOT_STATE                              | usual.event.wifi.HOTSPOT_STATE                              | N/A|
| COMMON_EVENT_WIFI_AP_STA_JOIN                                | usual.event.wifi.WIFI_HS_STA_JOIN                           | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_AP_STA_LEAVE                               | usual.event.wifi.WIFI_HS_STA_LEAVE                          | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_CONN_STATE                             | usual.event.wifi.p2p.CONN_STATE_CHANGE                      | ohos.permission.GET_WIFI_INFO and ohos.permission.LOCATION   |
| COMMON_EVENT_WIFI_P2P_STATE_CHANGED                          | usual.event.wifi.p2p.STATE_CHANGE                           | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_PEERS_STATE_CHANGED                    | usual.event.wifi.p2p.DEVICES_CHANGE                         | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_PEERS_DISCOVERY_STATE_CHANGED          | usual.event.wifi.p2p.PEER_DISCOVERY_STATE_CHANGE            | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_CURRENT_DEVICE_STATE_CHANGED           | usual.event.wifi.p2p.CURRENT_DEVICE_CHANGE                  | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_WIFI_P2P_GROUP_STATE_CHANGED                    | usual.event.wifi.p2p.GROUP_STATE_CHANGED                    | ohos.permission.GET_WIFI_INFO                                |
| COMMON_EVENT_BLUETOOTH_A2DPSOURCE_AVRCP_CONNECT_STATE_UPDATE | usual.event.bluetooth.a2dpsource.AVRCP_CONNECT_STATE_UPDATE | ohos.permission.USE_BLUETOOTH                                |
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_SDP_RESULT               | usual.event.bluetooth.remotedevice.SDP_RESULT               | N/A|
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_PAIRING_CANCEL           | usual.event.bluetooth.remotedevice.PAIRING_CANCEL           | N/A|
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REQ              | usual.event.bluetooth.remotedevice.CONNECT_REQ              | N/A|
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_REPLY            | usual.event.bluetooth.remotedevice.CONNECT_REPLY            | N/A|
| COMMON_EVENT_BLUETOOTH_REMOTEDEVICE_CONNECT_CANCEL           | usual.event.bluetooth.remotedevice.CONNECT_CANCEL           | N/A|
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_CONNECT_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.CONNECT_STATE_UPDATE    | N/A|
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AUDIO_STATE_UPDATE      | usual.event.bluetooth.handsfreeunit.AUDIO_STATE_UPDATE      | N/A|
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_COMMON_EVENT         | usual.event.bluetooth.handsfreeunit.AG_COMMON_EVENT         | N/A|
| COMMON_EVENT_BLUETOOTH_HANDSFREEUNIT_AG_CALL_STATE_UPDATE    | usual.event.bluetooth.handsfreeunit.AG_CALL_STATE_UPDATE    | N/A|
| COMMON_EVENT_BLUETOOTH_HOST_REQ_DISCOVERABLE                 | usual.event.bluetooth.host.REQ_DISCOVERABLE                 | N/A|
| COMMON_EVENT_NFC_ACTION_ADAPTER_STATE_CHANGED                | usual.event.nfc.action.ADAPTER_STATE_CHANGED                | N/A|
| COMMON_EVENT_DISCHARGING                                     | usual.event.DISCHARGING                                     | N/A|
| COMMON_EVENT_CHARGING                                        | usual.event.CHARGING                                        | N/A|
| COMMON_EVENT_DEVICE_IDLE_MODE_CHANGED                        | usual.event.DEVICE_IDLE_MODE_CHANGED                        | N/A|
| COMMON_EVENT_POWER_SAVE_MODE_CHANGED                         | usual.event.POWER_SAVE_MODE_CHANGED                         | N/A|
| COMMON_EVENT_USER_ADDED                                      | usual.event.USER_ADDED                                      | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_USER_REMOVED                                    | usual.event.USER_REMOVED                                    | ohos.permission.MANAGE_USERS                                 |
| COMMON_EVENT_LOCATION_MODE_STATE_CHANGED                     | usual.event.location.MODE_STATE_CHANGED                     | N/A|
| COMMON_EVENT_IVI_SLEEP                                       | common.event.IVI_SLEEP                                      | N/A|
| COMMON_EVENT_IVI_PAUSE                                       | common.event.IVI_PAUSE                                      | N/A|
| COMMON_EVENT_IVI_STANDBY                                     | common.event.IVI_STANDBY                                    | N/A|
| COMMON_EVENT_IVI_LASTMODE_SAVE                               | common.event.IVI_LASTMODE_SAVE                              | N/A|
| COMMON_EVENT_IVI_VOLTAGE_ABNORMAL                            | common.event.IVI_VOLTAGE_ABNORMAL                           | N/A|
| COMMON_EVENT_IVI_HIGH_TEMPERATURE                            | common.event.IVI_HIGH_TEMPERATURE                           | N/A|
| COMMON_EVENT_IVI_EXTREME_TEMPERATURE                         | common.event.IVI_EXTREME_TEMPERATURE                        | N/A|
| COMMON_EVENT_IVI_TEMPERATURE_ABNORMAL                        | common.event.IVI_TEMPERATURE_ABNORMAL                       | N/A|
| COMMON_EVENT_IVI_VOLTAGE_RECOVERY                            | common.event.IVI_VOLTAGE_RECOVERY                           | N/A|
| COMMON_EVENT_IVI_TEMPERATURE_RECOVERY                        | common.event.IVI_TEMPERATURE_RECOVERY                       | N/A|
| COMMON_EVENT_IVI_ACTIVE                                      | common.event.IVI_ACTIVE                                     | N/A|
| COMMON_EVENT_USB_DEVICE_ATTACHED                             | usual.event.hardware.usb.action.USB_DEVICE_ATTACHED         | N/A|
| COMMON_EVENT_USB_DEVICE_DETACHED                             | usual.event.hardware.usb.action.USB_DEVICE_DETACHED         | N/A|
| COMMON_EVENT_USB_ACCESSORY_ATTACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_ATTACHED      | N/A|
| COMMON_EVENT_USB_ACCESSORY_DETACHED                          | usual.event.hardware.usb.action.USB_ACCESSORY_DETACHED      | N/A|
| COMMON_EVENT_DISK_REMOVED                                    | usual.event.data.DISK_REMOVED                               | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_UNMOUNTED                                  | usual.event.data.DISK_UNMOUNTED                             | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_MOUNTED                                    | usual.event.data.DISK_MOUNTED                               | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_BAD_REMOVAL                                | usual.event.data.DISK_BAD_REMOVAL                           | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_DISK_EJECT                                      | usual.event.data.DISK_EJECT                                 | ohos.permission.WRITE_USER_STORAGE or ohos.permission.READ_USER_STORAGE|
| COMMON_EVENT_AIRPLANE_MODE_CHANGED                           | usual.event.AIRPLANE_MODE                                   | N/A|

## Modules to Import

```js
import CommonEvent from '@ohos.commonevent';
```



## CommonEvent.publish

publish(event: string, callback: AsyncCallback\<void>): void

Publishes a common event. This method uses a callback to return the result.

**Parameters**

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | -------------------- | ---- | ---------------------- |
| event    | Read-only| string               | Yes| Name of the common event to publish.|
| callback | Read-only| AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```js
// Callback for common event publication
function PublishCallBack(err) {
	console.info("==========================>PublishCallBack=======================>");
    console.info("==========================>err:=======================>", err.code);
}
// Publish a common event.
CommonEvent.publish("publish_event", PublishCallBack);
```



## CommonEvent.publish

publish(event: string, options: CommonEventPublishData, callback: AsyncCallback\<void>): void

Publishes a common event with given attributes. This method uses a callback to return the result.

**Parameters**

| Name| Readable/Writable| Type| Mandatory| Description|
| -------- | -------- | ---------------------- | ---- | ---------------------- |
| event    | Read-only| string                 | Yes| Name of the common event to publish.|
| options  | Read-only| [CommonEventPublishData](#commoneventpublishdata) | Yes| Attributes of the common event to publish.|
| callback | Read-only| AsyncCallback\<void>   | Yes| Callback used to return the result.|

**Example**


```js
// Attributes of a common event.
var options = {
	code: 0;			 // Result code of the common event
	data: "initial data";// Result data of the common event
	isOrdered: true;	 // The common event is an ordered one.
}
// Callback for common event publication
function PublishCallBack(err) {
	console.info("==========================>PublishCallBack=======================>");
}
// Publish a common event.
CommonEvent.publish("publish_event", options, PublishCallBack);
```



## CommonEvent.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void

Creates a subscriber. This method uses a callback to return the result.

**Parameters**

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------- | -------- | ------------------------------------------------------------ | ---- | -------------------------- |
| subscribeInfo | Read-only| [CommonEventSubscribeInfo](#commoneventsubscribeinfo)        | Yes| Subscriber information.|
| callback      | Read-only| AsyncCallback\<[CommonEventSubscriber](#commoneventsubscriber)> | Yes| Callback used to return the result.|

**Example**


```js
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
// Subscriber information
var subscribeInfo = {
	events: ["event"]
};
// Callback for subscriber creation
function CreateSubscriberCallBack(err, data) {
    console.info("==========================>CreateSubscriberCallBack=======================>");
    subscriber = data;
}
// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
```



## CommonEvent.createSubscriber

createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>

Creates a subscriber. This method uses a promise to return the result.

**Parameters**

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------- | -------- | ----------------------------------------------------- | ---- | -------------- |
| subscribeInfo | Read-only| [CommonEventSubscribeInfo](#commoneventsubscribeinfo) | Yes| Subscriber information.|

**Return value**
| Type| Description|
| --------------------------------------------------------- | ---------------- |
| Promise\<[CommonEventSubscriber](#commoneventsubscriber)> | Promise returned with the subscriber object.|

**Example**

```js
var subscriber; // Used to save the created subscriber object for subsequent subscription and unsubscription.
// Subscriber information
var subscribeInfo = {
	events: ["event"]
};
// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo).then((data) => {
	console.info("==========================>createSubscriberPromise=======================>");
    subscriber = data;
});
```



## CommonEvent.subscribe

subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void

Subscribes to common events. This method uses a callback to return the result.

**Parameters**

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | --------------------------------------------------- | ---- | -------------------------------- |
| subscriber | Read-only| [CommonEventSubscriber](#commoneventsubscriber)     | Yes| Subscriber object.|
| callback   | Read-only| AsyncCallback\<[CommonEventData](#commoneventdata)> | Yes| Callback used to return the result.|

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
    console.info("==========================>SubscribeCallBack=======================>");
}
// Callback for subscriber creation
function CreateSubscriberCallBack(err, data) {
    console.info("==========================>CreateSubscriberCallBack=======================>");
    subscriber = data;
    // Subscribe to a common event.
    CommonEvent.subscribe(subscriber, SubscribeCallBack);
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
    console.info("==========================>SetCodeCallBack=======================>");
}
// Callback for result data setting of an ordered common event
function SetDataCallBack(err) {
    console.info("==========================>SetDataCallBack=======================>");
}
// Callback for ordered common event processing
function FinishCommonEventCallBack(err) {
    console.info("==========================>FinishCommonEventCallBack=======================>");
}
// Callback for common event subscription
function SubscribeCallBack(err, data) {
    console.info("==========================>SubscribeCallBack=======================>");
    // Set the result code for the ordered common event.
    subscriber.setCode(0, SetCodeCallBack);
    // Set the result data for the ordered common event.
    subscriber.setData("publish_data_changed", SetDataCallBack);
    // Complete the processing of the ordered common event.
    subscriber.finishCommonEvent(FinishCommonEventCallBack)
}

// Callback for subscriber creation
function CreateSubscriberCallBack(err, data) {
    console.info("==========================>CreateSubscriberCallBack=======================>");
    subscriber = data;
    // Subscribe to a common event.
    CommonEvent.subscribe(subscriber, SubscribeCallBack);
}

// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
```

 

## CommonEvent.unsubscribe

unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void

Unsubscribes from common events. This method uses a callback to return the result.

**Parameters**

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | --------------------- | ---- | ------------------------ |
| subscriber | Read-only| CommonEventSubscriber | Yes| Subscriber object.|
| callback   | Read-only| AsyncCallback\<void>  | Yes| Callback used to return the result.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Subscriber information
var subscribeInfo = {
	events: ["event"]
};
// Callback for common event subscription
function SubscribeCallBack(err, data) {
	console.info("==========================>SubscribeCallBack=======================>");
}
// Callback for subscriber creation
function CreateSubscriberCallBack(err, data) {
	console.info("==========================>CreateSubscriberCallBack=======================>");
	subscriber = data;
	// Subscribe to a common event.
	CommonEvent.subscribe(subscriber, SubscribeCallBack);
}
// Callback for common event unsubscription
function UnsubscribeCallBack(err) {
	console.info("==========================>UnsubscribeCallBack=======================>");
}
// Create a subscriber.
CommonEvent.createSubscriber(subscribeInfo, CreateSubscriberCallBack);
// Unsubscribe from the common event.
CommonEvent.unsubscribe(subscriber, UnsubscribeCallBack);
```

## CommonEventPublishData

| Name| Readable/Writable| Type| Mandatory| Description|
| --------------------- | -------- | -------------------- | ---- | ---------------------------- |
| bundleName            | Read-only| string               | No| Bundle name.|
| code                  | Read-only| number               | No| Result code of the common event.|
| data                  | Read-only| string               | No| Custom result data of the common event.|
| subscriberPermissions | Read-only| Array\<string>       | No| Permissions required for subscribers to receive the common event.|
| isOrdered             | Read-only| boolean              | No| Whether the common event is an ordered one.|
| parameters            | Read-only| {[key: string]: any} | No| Additional information about the common event.|

## CommonEventSubscribeInfo

| Name| Readable/Writable| Type| Mandatory| Description|
| ------------------- | -------- | -------------- | ---- | ------------------------------------------------------------ |
| events              | Read-only| Array\<string> | Yes| Common events to subscribe to.|
| publisherPermission | Read-only| string         | No| Permission required for the publisher.|
| publisherDeviceId   | Read-only| string         | No| Device ID. The value must be the ID of an existing device on the same network.|
| userId              | Read-only| number         | No| User ID. The default value is the ID of the current user. If this parameter is specified, the value must be an existing user ID in the system.|
| priority            | Read-only| number         | No| Subscriber priority. The value ranges from -100 to 1000.|

## CommonEventData

| Name| Readable/Writable| Type| Mandatory| Description|
| ---------- | -------- | -------------------- | ---- | ------------------------------------------------------ |
| event      | Read-only| string               | Yes| Name of the common event to subscribe to.|
| bundleName | Read-only| string               | No| Bundle name.|
| code       | Read-only| number               | No| Result code of the common event, which is used to transfer data of the int type.|
| data       | Read-only| string               | No| Custom result data of the common event, which is used to transfer data of the string type.|
| parameters | Read-only| {[key: string]: any} | No| Additional information about the common event.|

## CommonEventSubscriber

### getCode

getCode(callback: AsyncCallback\<number>): void

Obtains the result code of this common event. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------- | ---- | ------------------ |
| callback | AsyncCallback\<number> | Yes| Callback used to return the result code.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function getCodeCallback(err, data) {
    console.info("==========================>getCodeCallback=======================>");
    console.info("==========================>err:=======================>", err.code);
    console.info("==========================>code:=======================>", data);
}
subscriber.getCode(getCodeCallback);
```

### getCode

getCode(): Promise\<number>

Obtains the result code of this common event. This method uses a promise to return the result.

**Return value**

| Type| Description|
| ---------------- | -------------------- |
| Promise\<number> | Promise returned with the result code.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.getCode().then((data) => {
	console.info("==========================>getCodePromise=======================>");
    console.info("==========================>code:=======================>", data);
});
```

### setCode

setCode(code: number, callback: AsyncCallback\<void>): void

Sets the result code for this common event. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes| Result code of the common event.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function setCodeCallback(err) {
    console.info("==========================>setCodeCallback=======================>");
    console.info("==========================>err:=======================>", err.code);
}
subscriber.setCode(1, setCodeCallback);
```

### setCode

setCode(code: number): Promise\<void>

Sets the result code for this common event. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | ------------------ |
| code   | number | Yes| Result code of the common event.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.setCode(1).then(() => {
	console.info("==========================>setCodePromise=======================>");
});
```

### getData

getData(callback: AsyncCallback\<string>): void

Obtains the result data of this common event. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<string> | Yes| Callback used to return the result data.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function getDataCallback(err, data) {
    console.info("==========================>getDataCallback=======================>");
    console.info("==========================>err:=======================>", err.code);
    console.info("==========================>data:=======================>", data);
}
subscriber.getData(getDataCallback);
```

### getData

getData(): Promise\<string>

Obtains the result data of this common event. This method uses a promise to return the result.

**Return value**

| Type| Description|
| ---------------- | ------------------ |
| Promise\<string> | Promise returned with the result data.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.getData().then((data) => {
	console.info("==========================>getDataPromise=======================>");
    console.info("==========================>data:=======================>", data);
});
```

### setData

setData(data: string, callback: AsyncCallback\<void>): void

Sets the result data for this common event. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | -------------------- |
| data     | string               | Yes| Result data of the common event.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function setDataCallback(err) {
    console.info("==========================>setDataCallback=======================>");
    console.info("==========================>err:=======================>", err.code);
}
subscriber.setData("publish_data_changed", setDataCallback);
```

### setData

setData(data: string): Promise\<void>

Sets the result data for this common event. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------- |
| data   | string | Yes| Result data of the common event.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.setData("publish_data_changed").then(() => {
	console.info("==========================>setDataPromise=======================>");
});
```

### setCodeAndData

setCodeAndData(code: number, data: string, callback:AsyncCallback\<void>): void

Sets the result code and result data for this common event. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | ---------------------- |
| code     | number               | Yes| Result code of the common event.|
| data     | string               | Yes| Result data of the common event.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function setCodeDataCallback(err) {
    console.info("==========================>setCodeDataCallback=======================>");
    console.info("==========================>err:=======================>", err.code);
}
subscriber.setCodeAndData(1, "publish_data_changed", setCodeDataCallback);
```

### setCodeAndData

setCodeAndData(code: number, data: string): Promise\<void>

Sets the result code and result data for this common event. This method uses a promise to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | -------------------- |
| code   | number | Yes| Result code of the common event.|
| data   | string | Yes| Result data of the common event.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.setCodeAndData(1, "publish_data_changed").then(() => {
	console.info("==========================>setCodeAndData=======================>");
});
```

### isOrderedCommonEvent

isOrderedCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is an ordered one. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes| Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function isOrderedCallback(err, data) {
    console.info("==========================>isOrderedCallback=======================>");
    console.info("==========================>err:=======================>", err.code);
    console.info("==========================>isOrdered:=======================>", data);
}
subscriber.isOrderedCommonEvent(isOrderedCallback);
```

### isOrderedCommonEvent

isOrderedCommonEvent(): Promise\<boolean>

Checks whether this common event is an ordered one. This method uses a promise to return the result.

**Return value**

| Type| Description|
| ----------------- | -------------------------------- |
| Promise\<boolean> | Returns **true** if the common event is an ordered one; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.isOrderedCommonEvent().then((data) => {
	console.info("==========================>isOrdered:=======================>", data);
});
```

### abortCommonEvent

abortCommonEvent(callback: AsyncCallback\<void>): void

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This method takes effect only for ordered common events. It uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function abortCallback(err) {
    console.info("==========================>abortCallback=======================>");
 	console.info("==========================>err:=======================>", err.code);
}
subscriber.abortCommonEvent(abortCallback);
```

### abortCommonEvent

abortCommonEvent(): Promise\<void>

Aborts this common event. After the abort, the common event is not sent to the next subscriber. This method takes effect only for ordered common events. It uses a promise to return the result.

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.abortCommonEvent().then(() => {
	console.info("==========================>abortCommonEvent:=======================>");
});
```

### clearAbortCommonEvent

clearAbortCommonEvent(callback: AsyncCallback\<void>): void

Clears the aborted state of this common event. This method takes effect only for ordered common events. It uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function clearAbortCallback(err) {
    console.info("==========================>clearAbortCallback=======================>");
 	console.info("==========================>err:=======================>", err.code);
}
subscriber.clearAbortCommonEvent(clearAbortCallback);
```

### clearAbortCommonEvent

clearAbortCommonEvent(): Promise\<void>

Clears the aborted state of this common event. This method takes effect only for ordered common events. It uses a promise to return the result.

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.clearAbortCommonEvent().then(() => {
	console.info("==========================>clearAbortCommonEvent:=======================>");
});
```

### getAbortCommonEvent

getAbortCommonEvent(callback: AsyncCallback\<boolean>): void

Checks whether this common event is in the aborted state. This method takes effect only for ordered common events. It uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<boolean> | Yes| Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function getAbortCallback(err, data) {
    console.info("==========================>getAbortCallback=======================>");
 	console.info("==========================>err:=======================>", err.code);
    console.info("==========================>abort:=======================>", data);
}
subscriber.getAbortCommonEvent(getAbortCallback);
```

### getAbortCommonEvent

getAbortCommonEvent(): Promise\<void>

Checks whether this common event is in the aborted state. This method takes effect only for ordered common events. It uses a promise to return the result.

**Return value**

| Type| Description|
| ----------------- | ---------------------------------- |
| Promise\<boolean> | Returns **true** if the ordered common event is in the aborted state; returns **false** otherwise.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.getAbortCommonEvent().then((data) => {
	console.info("==========================>getAbortCommonEvent:=======================>");
    console.info("==========================>abort:=======================>", data);
});
```

### getSubscribeInfo

getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void

Obtains the subscriber information. This method uses a callback to return the result.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Yes| Callback used to return the subscriber information.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
// Callback for result data setting of an ordered common event
function getSubscribeInfoCallback(err, data) {
    console.info("==========================>getSubscribeInfoCallback=======================>");
 	console.info("==========================>err:=======================>", err.code);
    console.info("==========================>priority:=======================>", data.priority);
}
subscriber.getSubscribeInfo(getSubscribeInfoCallback);
```

### getSubscribeInfo

getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>

Obtains the subscriber information. This method uses a promise to return the result.

**Return value**

| Type| Description|
| ------------------------------------------------------------ | ---------------------- |
| Promise\<[CommonEventSubscribeInfo](#commoneventsubscribeinfo)> | Promise returned with the subscriber information.|

**Example**

```js
var subscriber;	// Used to save the created subscriber object for subsequent subscription and unsubscription.
subscriber.getSubscribeInfo().then((data) => {
	console.info("==========================>getSubscribeInfo:=======================>");
    console.info("==========================>priority:=======================>", data.priority);
});
```
