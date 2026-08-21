# @ohos.bluetooth.hid (Bluetooth HID Module)

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=14ca614ebb030bf413b2d8393352ad7521a1d1b9 translatedAt=2026-08-19T10:01:26.528Z pushedAt=2026-08-20T01:23:05.649Z -->

The **hid** module provides Bluetooth capabilities based on Bluetooth Classic's [Human Interface Device Profile (HID)](../../connectivity/bluetooth/terminology.md#hid), such as obtaining the Bluetooth connection status.

When the local device is registered as an HID device, you can use the APIs provided by [HidDeviceProfile](#hiddeviceprofile23). The local device can connect to and interact with only classic Bluetooth devices.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { hid } from '@kit.ConnectivityKit';
```

## BaseProfile

type BaseProfile = baseProfile.BaseProfile

Defines the **BaseProfile** API, which provides common capabilities such as subscription to connection status and connection status obtaining.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Type                           | Description        |
| ----------------------------- | ---------- |
| [baseProfile.BaseProfile](js-apis-bluetooth-baseProfile.md#baseprofile) | **BaseProfile** API definition.|

## BluetoothAddress<sup>23+</sup>

type BluetoothAddress = common.BluetoothAddress

Defines the address information of a Bluetooth device, including the address and address type.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| Type                 | Description                 |
| ------------------- | ------------------- |
| [common.BluetoothAddress](js-apis-bluetooth-common.md#bluetoothaddress) | Address information of the Bluetooth device.|

## hid.createHidHostProfile

createHidHostProfile(): HidHostProfile

Creates a Bluetooth [HID host](../../connectivity/bluetooth/terminology.md#hid-host) instance. Through this instance, you can use the local device as the HID host and implement functions such as obtaining the Bluetooth HID connection status.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| HidHostProfile | HID host instance.<br>- The **HidHostProfile** class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class.<br>- The counterpart of the HID host role is the [HID device](../../connectivity/bluetooth/terminology.md#hid-device) role. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|401 | Invalid parameter. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.                 |
|801 | Capability not supported.          |

**Example**

```js
try {
    let hidHostProfile = hid.createHidHostProfile();
    console.info('hidHost success');
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## hid.createHidDeviceProfile<sup>23+</sup>

createHidDeviceProfile(): HidDeviceProfile

Creates a Bluetooth [HID device](../../connectivity/bluetooth/terminology.md#hid-device) instance. Through this instance, you can use the local device as the HID device and implement functions such as obtaining the Bluetooth HID connection status.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| [HidDeviceProfile](#hiddeviceprofile23) | HID device instance.<br>- The **HidHostProfile** class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class.<br>- The role corresponding to this instance role is [HID host](../../connectivity/bluetooth/terminology.md#hid-host). |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|801 | Capability not supported.          |

**Example**

```js
try {
    let hidDeviceProfile = hid.createHidDeviceProfile();
    console.info('hidDevice success');
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## HidDeviceProfile<sup>23+</sup>

Represents the [HID Device](../../connectivity/bluetooth/terminology.md#hid-device) role in Bluetooth HID communication.

- This class is inherited from [BaseProfile](#baseprofile). Therefore, you can use the APIs in its parent class.

- Before using the APIs of this class, you need to construct an instance of the class by calling [createHidDeviceProfile](#hidcreatehiddeviceprofile23).

- You can use this instance to operate the device, for example, call [registerHidDevice](#registerhiddevice23) to register an HID device and call [sendReport](#sendreport23) to send a report.

- The role corresponding to this instance role is [HID host](../../connectivity/bluetooth/terminology.md#hid-host).

### registerHidDevice<sup>23+</sup>

registerHidDevice(sdp: HidDeviceSdp, inQos: HidDeviceQos, outQos: HidDeviceQos, callback: Callback&lt;boolean&gt;): void

Registers an HID device so that the application can communicate with an HID host (such as a computer or mobile phone). This API uses an asynchronous callback to return the result.

- After calling this API to register the HID device successfully, the application can call the [connect](#connect23) API to connect to the HID host.

- Only one application can successfully register an HID device at a time. If the same application registers the HID device repeatedly, the registration will fail. After the registration is successful, other applications will also fail to register the HID device.

- When the application no longer needs the HID device, it needs to call the [unregisterHidDevice](#unregisterhiddevice23) API to unregister the HID device.

- When this API is called, the application must be in the foreground. Otherwise, the registration will fail.

- After the registration is successful, if the application transitions to the background, the HID device will be automatically unregistered. The registration status change is reported to the upper-layer application through a callback.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**  | Type                           | **Mandatory**| Description      |
| ------- | ---------------------------     |-----| --------- |
| sdp     | [HidDeviceSdp](#hiddevicesdp23) | Yes |   Service capability record of an HID device, which defines the device type, descriptor, and other information.      |
| inQos   | [HidDeviceQos](#hiddeviceqos23) | Yes | QoS configuration of the input channel, which is used to define the data flow parameters from the peer end to the local end.|
| outQos  | [HidDeviceQos](#hiddeviceqos23) | Yes | QoS configuration of the output channel, which is used to define the data flow parameters from the local end to the peer end.|
| callback | Callback&lt;boolean&gt; | Yes | Callback used to return the registration status. **true** is returned if the HID device is registered; **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
|201 | Permission denied.                             |
|801 | Capability not supported.                      |
|2900003 | Bluetooth disabled.                        |
|2900099 | Operation failed.                          |
|2903050 | Application is not in the foreground.      |
|2903051 | Any app has been registered.               |

**Example**

```js
let descriptors: Uint8Array = new Uint8Array([
    // Descriptor example, which must comply with the USB HID specifications.
    0x05, 0x01,        // The device category is the universal desktop control.
    0x09, 0x06,        // The specific device is a keyboard.
    0xA1, 0x01,        // The application set starts.
    
    // Key field definition.
    0x05, 0x07,        // Switch to the keyboard/key area.
    0x19, 0x00,        // Define the minimum key code as 0 (no key).
    0x29, 0x01,        // Define the maximum key code as 1 (only two values are supported).
    0x15, 0x00,        // Logical minimum value 0 (lower limit of the data range).
    0x25, 0x01,        // Logical maximum value 1 (upper limit of the data range).
    0x75, 0x08,        // Each field contains eight bits.
    0x95, 0x01,        // There is only one field.
    0x81, 0x00,        // Define the input field: data field. The value is the key array.
    
    // End the device definition.
    0xC0               // The application set ends.
]);
// Use the keyboard as an example.
let sdp: hid.HidDeviceSdp = {
    "name": "testName",
    "description": "testDescription",
    "provider": "testProvider",
    "subclass": hid.Subclass.SUBCLASS_KEYBOARD,
    "descriptors": descriptors,
};
let inqos: hid.HidDeviceQos = {
    "serviceType": hid.ServiceType.SERVICE_BEST_EFFORT,
    "tokenRate": 0,
    "tokenBucketSize": 0,
    "peakBandwidth": 0,
    "latency": -1,
    "delayVariation": -1,
};
let outqos: hid.HidDeviceQos = {};
function registerStateCallback(callback: boolean) {
    console.info(`state: ${callback}`);
}

try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.registerHidDevice(sdp, inqos, outqos, registerStateCallback)
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### unregisterHidDevice<sup>23+</sup>

unregisterHidDevice(): void

Unregisters an HID device and releases all related resources.

- If the local end has established a connection with the HID host by calling [connect](#connect23) before this API is called, the connection will be disconnected after this API is called.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
|201 | Permission denied.                             |
|801 | Capability not supported.                      |
|2900003 | Bluetooth disabled.                        |
|2900099 | Operation failed.                          |

**Example**

```js
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.unregisterHidDevice();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### connect<sup>23+</sup>

connect(deviceId: BluetoothAddress): void

Initiates a connection to a specified HID host.

- Before calling this API, call [registerHidDevice](#registerhiddevice23) to register the HID device.

- You can call [on('connectionStateChange')](js-apis-bluetooth-baseProfile.md#baseprofileonconnectionstatechange) to subscribe to connection status change events.

- If the connection is no longer needed, call [disconnect](#disconnect23) for disconnection.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**  |Type   | **Mandatory**|  Description |
| ------- | -------|-----|--------|
| deviceId | [BluetoothAddress](js-apis-bluetooth-common.md#bluetoothaddress) | Yes   | Address information of the peer Bluetooth device to be connected. **rawAddressType** is not involved in the HID device and does not need to be set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
|201 | Permission denied.                             |
|801 | Capability not supported.                      |
|2900003 | Bluetooth disabled.                        |
|2900004 | Remote Device profile not supported.       |
|2900099 | Operation failed.                          |
|2903052 | App not register.                          |

**Example**

```js
import { common } from '@kit.ConnectivityKit';

let device: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.connect(device);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### disconnect<sup>23+</sup>

disconnect(): void

Disconnects from the HID host and releases related resources.

- After the call is successful, the capability registration status of the current HID device is not affected. The application is still in the registration status and can call [connect](#connect23) again to connect to a new HID host.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
|201 | Permission denied.                             |
|801 | Capability not supported.                      |
|2900003 | Bluetooth disabled.                        |
|2900099 | Operation failed.                          |
|2903052 | App not register.                          |

**Example**

```js
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.disconnect();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### sendReport<sup>23+</sup>

sendReport(id: number, reportData: Uint8Array): void

Sends report data to a connected HID host.

- Before calling this API, ensure that [registerHidDevice](#registerhiddevice23) has been called to complete the registration and [connect](#connect23) has been called to establish a connection with the HID host.

- The length and content of the report data must be the same as those defined by [HidDeviceSdp](#hiddevicesdp23) during HID device registration. Otherwise, the HID host cannot correctly parse the report data.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**  | Type    | **Mandatory**| Description      |
| ------- | ----------     |-----| --------- |
| id | number | Yes   | Report ID defined in the descriptor provided by [HidDeviceSdp](#hiddevicesdp23) during HID device registration, which is used to identify the report type. For a simple device without an ID, this parameter must be set to **0**. For a device that defines multiple report IDs, the corresponding ID value must be passed, which must be the same as the value defined in the descriptor.|
| reportData | Uint8Array | Yes   | Report data. The content length and parsing mode must strictly match the format defined for the report ID in the descriptor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
|201 | Permission denied.                             |
|801 | Capability not supported.                      |
|2900003 | Bluetooth disabled.                        |
|2900099 | Operation failed.                          |
|2903052 | App not register.                          |
|2903053 | Device not connected.                      |

**Example**

```js
let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
let id: number = 0;
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.sendReport(id, reportData);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### replyReport<sup>23+</sup>

replyReport(type: ReportType, id: number, reportData: Uint8Array): void

Replies to a specific request from a connected HID host.

- Before calling this API, ensure that [registerHidDevice](#registerhiddevice23) has been called to complete the registration and [connect](#connect23) has been called to establish a connection with the HID host.

- You can call [onGetReport](#ongetreport23) to subscribe to events for receiving requests from hosts.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**  | Type                           | **Mandatory**| Description      |
| ------- | ---------------------------     |-----| --------- |
| type | [ReportType](#reporttype23) | Yes   | Type of the report to be replied.|
| id | number | Yes   | Report ID defined in the descriptor provided by [HidDeviceSdp](#hiddevicesdp23) during HID device registration, which is used to identify the report type. For a simple device without an ID, this parameter must be set to **0**. For a device that defines multiple report IDs, the corresponding ID value must be passed, which must be the same as the value defined in the descriptor.|
| reportData | Uint8Array | Yes   | Report data. The content length and parsing mode must strictly match the format defined for the report ID in the descriptor.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
|201 | Permission denied.                             |
|801 | Capability not supported.                      |
|2900003 | Bluetooth disabled.                        |
|2900099 | Operation failed.                          |
|2903052 | App not register.                          |
|2903053 | Device not connected.                      |

**Example**

```js
let type = hid.ReportType.REPORT_TYPE_INPUT;
let id: number = 0;
let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.replyReport(type, id, reportData);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### reportError<sup>23+</sup>

reportError(error: ErrorReason): void

Reports errors of a specific type to a connected HID host.

- Before calling this API, ensure that [registerHidDevice](#registerhiddevice23) has been called to complete the registration and [connect](#connect23) has been called to establish a connection with the HID host.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**  | Type                           | **Mandatory**| Description      |
| ------- | ---------------------------     |-----| --------- |
| error | [ErrorReason](#errorreason23) | Yes   | Type of the error to be reported to the HID host.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Bluetooth Error Codes](errorcode-bluetoothManager.md).

| ID| Error Message                                 |
| -------- | ---------------------------------------- |
|201 | Permission denied.                             |
|801 | Capability not supported.                      |
|2900003 | Bluetooth disabled.                        |
|2900099 | Operation failed.                          |
|2903052 | App not register.                          |
|2903053 | Device not connected.                      |

**Example**

```js
let error = hid.ErrorReason.RSP_SUCCESS;
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.reportError(error);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### onGetReport<sup>23+</sup>

onGetReport(callback: Callback&lt;GetReportData&gt;): void

Subscribes to the events for sending [GET_REPORT](../../connectivity/bluetooth/terminology.md#hid) transmission requests by an HID host to an HID device. This API uses an asynchronous callback to return the result. After receiving the callback, you can call the [replyReport](#replyreport23) API to reply. When the received data does not meet the expectation, you can call the [reportError](#reporterror23) API to reply.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[GetReportData](#getreportdata23)&gt; | Yes | Callback used to return the received report data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|801     | Capability not supported.                |

**Example**

```js
function onReceiveEvent(callback: hid.GetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, bufferSize: ${callback.bufferSize}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onGetReport(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### offGetReport<sup>23+</sup>

offGetReport(callback?: Callback&lt;GetReportData&gt;): void

Unsubscribes from the events for sending [GET_REPORT](../../connectivity/bluetooth/terminology.md#hid) transmission requests by an HID host to an HID device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[GetReportData](#getreportdata23)&gt; | No | Callback to unregister. If this parameter is specified, it must be the same as the callback in [onGetReport](#ongetreport23). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.             |
|801     | Capability not supported.      |

**Example**

```js
function onReceiveEvent(callback: hid.GetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, bufferSize: ${callback.bufferSize}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onGetReport(onReceiveEvent);
    hidDevice.offGetReport(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### onSetReport<sup>23+</sup>

onSetReport(callback: Callback&lt;SetReportData&gt;): void

Subscribes to the events for sending [SET_REPORT](../../connectivity/bluetooth/terminology.md#hid) transmission requests by an HID host to an HID device. This API uses an asynchronous callback to return the result. When the received data does not meet the expectation, you can call the [reportError](#reporterror23) API to reply.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[SetReportData](#setreportdata23)&gt; | Yes | Callback used to return the received report data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.             |
|801     | Capability not supported.      |

**Example**

```js
function onReceiveEvent(callback: hid.SetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, dataSize: ${callback.data.length}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onSetReport(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### offSetReport<sup>23+</sup>

offSetReport(callback?: Callback&lt;SetReportData&gt;): void

Unsubscribes from the events for sending [SET_REPORT](../../connectivity/bluetooth/terminology.md#hid) transmission requests by an HID host to an HID device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[SetReportData](#setreportdata23)&gt; | No | Callback to unregister. If this parameter is specified, it must be the same as the callback in [onSetReport](#onsetreport23). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|801     | Capability not supported.                |

**Example**

```js
function onReceiveEvent(callback: hid.SetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, dataSize: ${callback.data.length}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onSetReport(onReceiveEvent);
    hidDevice.offSetReport(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### onInterruptDataReceived<sup>23+</sup>

onInterruptDataReceived(callback: Callback&lt;InterruptData&gt;): void

Subscribes to the events where an HID host sends data through the interrupt transfer channel. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[InterruptData](#interruptdata23)&gt; | Yes | Callback used to return the received interrupt data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.             |
|801     | Capability not supported.      |

**Example**

```js
function onReceiveEvent(callback: hid.InterruptData) {
    console.info(`id: ${callback.id}, dataSize: ${callback.data.length}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onInterruptDataReceived(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### offInterruptDataReceived<sup>23+</sup>

offInterruptDataReceived(callback?: Callback&lt;InterruptData&gt;): void

Unsubscribes from the events where an HID host sends data through the interrupt transfer channel. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[InterruptData](#interruptdata23)&gt; | No | Callback to unregister. If this parameter is specified, it must be the same as the callback in [onInterruptDataReceived](#oninterruptdatareceived23). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|801     | Capability not supported.                |

**Example**

```js
function onReceiveEvent(callback: hid.InterruptData) {
    console.info(`id: ${callback.id}, dataSize: ${callback.data.length}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onInterruptDataReceived(onReceiveEvent);
    hidDevice.offInterruptDataReceived(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### onSetProtocol<sup>23+</sup>

onSetProtocol(callback: Callback&lt;ProtocolData&gt;): void

Subscribes to the events for sending [SET_PROTOCOL](../../connectivity/bluetooth/terminology.md#hid) requests by an HID host to an HID device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[ProtocolData](#protocoldata23)&gt; | Yes | Callback used to return the received protocol data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.             |
|801     | Capability not supported.      |

**Example**

```js
function onReceiveEvent(callback: hid.ProtocolData) {
    console.info(`protocol: ${callback.protocol}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onSetProtocol(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### offSetProtocol<sup>23+</sup>

offSetProtocol(callback?: Callback&lt;ProtocolData&gt;): void

Unsubscribes from the events for sending [SET_PROTOCOL](../../connectivity/bluetooth/terminology.md#hid) requests by an HID host to an HID device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;[ProtocolData](#protocoldata23)&gt; | No | Callback to unregister. If this parameter is specified, it must be the same as the callback in [onSetProtocol](#onsetprotocol23). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.                       |
|801     | Capability not supported.                |

**Example**

```js
function onReceiveEvent(callback: hid.ProtocolData) {
    console.info(`protocol: ${callback.protocol}`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onSetProtocol(onReceiveEvent);
    hidDevice.offSetProtocol(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### onVirtualCableUnplug<sup>23+</sup>

onVirtualCableUnplug(callback: Callback&lt;void&gt;): void

Subscribes to the events where an HID host disconnects the virtual link from an HID device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;void&gt; | Yes | Callback returned when the host disconnects the virtual link.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.             |
|801     | Capability not supported.      |

**Example**

```js
function onReceiveEvent() {
    console.info(`onVirtualCableUnplug`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onVirtualCableUnplug(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

### offVirtualCableUnplug<sup>23+</sup>

offVirtualCableUnplug(callback?: Callback&lt;void&gt;): void

Unsubscribes from the events where an HID host disconnects the virtual link from an HID device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| **Name**     | Type | **Mandatory**  | Description              |
| -------- | ----------- | ----- | ------------- |
| callback | Callback&lt;void&gt; | No | Callback to unregister. If this parameter is specified, it must be the same as the callback in [onVirtualCableUnplug](#onvirtualcableunplug23). If this parameter is not specified, all callbacks corresponding to the event type are unsubscribed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201     | Permission denied.             |
|801     | Capability not supported.      |

**Example**

```js
function onReceiveEvent() {
    console.info(`onVirtualCableUnplug`);
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onVirtualCableUnplug(onReceiveEvent);
    hidDevice.offVirtualCableUnplug(onReceiveEvent);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

## HidDeviceSdp<sup>23+</sup>

Describes the service registration configuration of an HID device in the service discovery protocol ([SDP](../../connectivity/bluetooth/terminology.md#sdp)). This API defines the identity, capability description, and protocol characteristics of an HID device, which are key parameters for an HID host to discover, identify, and connect an HID device.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**     | Type                 |**Read-Only**  |**Optional**  | Description                                    |
| --------- | ----------------------- | ---- | ---- | ------------------------------ |
| name  |  string       | No| No| Name of an HID device, in bytes. The value range is [1, 50].   |
| description  | string | No| No| Description of an HID device, in bytes. The value range is [1, 50]. |
| provider  | string | No| No| Manufacturer information of an HID device, in bytes. The value range is [1, 50]. |
| subclass  | [Subclass](#subclass23) | No| No| Type of an HID device. |
| descriptors  | Uint8Array | No| No| Descriptor used to define Bluetooth HID device capabilities. The descriptors will assign a unique ID to each supported report and define the length, structure, and field meanings in the report. Setting this parameter must comply with the [USB HID](https://www.usb.org/hid) specifications. |

## HidDeviceQos<sup>23+</sup>

Describes the QoS parameters of an HID device. This API defines the traffic control, delay guarantee, and reliability policy of an HID data transmission channel, optimizing Bluetooth transmission performance and ensuring real-time responsiveness of the device.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**     | Type                 |**Read-Only**  |**Optional**  | Description                                    |
| --------- | ----------------------- | ---- | ---- | ------------------------------ |
| serviceType  |  [ServiceType](#servicetype23)   | No| Yes| Service type. The default value is **SERVICE_BEST_EFFORT**.   |
| tokenRate  | number | No| Yes| Average amount of data that can be transmitted per unit time, in byte/s. The default value is **0**, indicating that there is no limit on the average amount of data. |
| tokenBucketSize  | number | No| Yes| Maximum amount of data that can exceed the value of **tokenRate** in a short period of time. The default value is **0**, indicating that there is no limit on the maximum amount of data. |
| peakBandwidth  | number | No| Yes| Maximum transmission rate, in byte/s. The default value is **0**, indicating that there is no limit on the transmission rate. |
| latency  | number | No| Yes| Maximum latency allowed, in μs. The default value is **-1**, indicating that there is no latency limit. |
| delayVariation  | number | No| Yes| Latency fluctuation range allowed, in μs. The default value is **-1**, indicating that there is no latency fluctuation range limit. |

## GetReportData<sup>23+</sup>

Describes the events for sending [GET_REPORT](../../connectivity/bluetooth/terminology.md#hid) transmission requests by an HID host to an HID device.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**      | Type | **Read-Only**| **Optional**  | Description     |
| -------- | ------ |---- |---- | ----------- |
| type | [ReportType](#reporttype23)   | No|  No   | Report type.|
| id | number | No|  No   | Report ID defined in the descriptor provided by [HidDeviceSdp](#hiddevicesdp23) during HID device registration, which is used to identify the report type. For a simple device without an ID, this parameter must be set to **0**. For a device that defines multiple report IDs, the corresponding ID value must be passed, which must be the same as the value defined in the descriptor.|
| bufferSize | number   | No|  No   | Length of received data, in bytes.|

## SetReportData<sup>23+</sup>

Describes the events for sending [SET_REPORT](../../connectivity/bluetooth/terminology.md#hid) transmission requests by an HID host to an HID device.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**      | Type | **Read-Only**| **Optional**  | Description         |
| -------- | ------ |---- |---- | ----------- |
| type | [ReportType](#reporttype23)   | No|  No   | Report type.|
| id | number | No|  No   | Report ID defined in the descriptor provided by [HidDeviceSdp](#hiddevicesdp23) during HID device registration, which is used to identify the report type. For a simple device without an ID, this parameter must be set to **0**. For a device that defines multiple report IDs, the corresponding ID value must be passed, which must be the same as the value defined in the descriptor.|
| data | Uint8Array   | No|  No   | Configuration data. The content length and parsing mode must strictly match the format defined for the report ID in the descriptor.|

## InterruptData<sup>23+</sup>

Describes the interrupt data received from an HID host.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**      | Type | **Read-Only**| **Optional**  | Description         |
| -------- | ------ |---- |---- | ----------- |
| id | number | No|  No   | Report ID defined in the descriptor provided by [HidDeviceSdp](#hiddevicesdp23) during HID device registration, which is used to identify the report type. For a simple device without an ID, this parameter must be set to **0**. For a device that defines multiple report IDs, the corresponding ID value must be passed, which must be the same as the value defined in the descriptor.|
| data | Uint8Array   | No|  No   | Interrupt data. The content length and parsing mode must strictly match the format defined for the report ID in the descriptor provided by [HidDeviceSdp](#hiddevicesdp23) during HID device registration.|

## ProtocolData<sup>23+</sup>

Describes the communication protocol data received from an HID host.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**      | Type | **Read-Only**| **Optional**  | Description         |
| -------- | ------ |---- |---- | ----------- |
| protocol | [ProtocolType](#protocoltype23)   | No|  No   | Communication protocol type of the host.|

## Subclass<sup>23+</sup>

Enumerates HID device types.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**                     | **Value**  | Description         |
| --------------------------| ----| --------------|
| SUBCLASS_UNCATEGORIZED    |  0  | Uncategorized HID device. |
| SUBCLASS_JOYSTICK         |  1  | Joystick.      |
| SUBCLASS_GAMEPAD          |  2  | Gamepad.  |
| SUBCLASS_REMOTE_CONTROL   |  3  | Remote control.    |
| SUBCLASS_SENSING_DEVICE   |  4  | Sensing device.      |
| SUBCLASS_DIGITIZER_TABLET |  5  | Digital tablet.    |
| SUBCLASS_CARD_READER      |  6  | Card reader.    |
| SUBCLASS_KEYBOARD         | 64  | Standard keyboard.  |
| SUBCLASS_MOUSE            | 128 | Standard mouse.  |
| SUBCLASS_COMBO            | 192 | Composite input device.  |

## ReportType<sup>23+</sup>

Enumerates report types.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**               | **Value**| Description                   |
| --------------------| --| -----------------------|
| REPORT_TYPE_INPUT   | 1 | Input report, indicating the data sent by the local end to an HID host.|
| REPORT_TYPE_OUTPUT  | 2 | Output report, indicating the data sent by an HID host to the local end. |
| REPORT_TYPE_FEATURE | 3 | Feature report, indicating the configuration data for bidirectional transmission.      |

## ServiceType<sup>23+</sup>

Enumerates the service types of the connection between an HID host and an HID device.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**                | **Value**| Description             |
| --------------------| --| ----------------- |
| SERVICE_NO_TRAFFIC  | 0 | Low-power mode. Only the connection is maintained, and no application data is transmitted. The power consumption is the lowest.  |
| SERVICE_BEST_EFFORT | 1 | High-speed mode. The transmission rate is the fastest, but data packets may be lost or out of order. This mode is applicable to scenarios that are sensitive to latency but insensitive to packet loss.  |
| SERVICE_GUARANTEED  | 2 | Reliable mode. The transmission speed is slow, but data is correctly delivered. This mode is applicable to scenarios such as file transfer.  |

## ErrorReason<sup>23+</sup>

Enumerates error causes.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**                  | **Value**| Description                 |
| -----------------------| --| --------------------- |
| RSP_SUCCESS            | 0 | Success. No exception occurs.          |
| RSP_NOT_READY          | 1 | The device is not ready to process the request. It is recommended that the host retry the operation later. |
| RSP_INVALID_REPORT_ID  | 2 | Invalid report ID. It is recommended that the host confirm the supported ID list and resend the message using the correct ID.        |
| RSP_UNSUPPORTED_REQ    | 3 | The current request is not supported. It is recommended that the host check whether the current request type or report type is supported by the local end in the current protocol mode.      |
| RSP_INVALID_PARAM      | 4 | Invalid parameter. It is recommended that the host check whether the parameters in the request are beyond the scope declared by the local end or do not comply with the definition of the report descriptor.            |
| RSP_UNKNOWN            |14 | Unknown error. It is recommended that the host record the error context and try again.        |

## ProtocolType<sup>23+</sup>

Enumerates the protocol types for communication between an HID device and an HID host.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Model restriction**: This API can be used only in the stage model.

| **Name**                               | **Value**   | Description             |
| ------------------------------------| ------| ---------------- |
| PROTOCOL_BOOT_MODE  | 0 |  Compatible mode. Ensures that the device can be identified as a basic input device during system startup and on all platforms. This mode provides the best compatibility but limited capabilities, and is suitable for simple peripheral development such as keyboards and mice. |
| PROTOCOL_REPORT_MODE | 1 | Complete report protocol mode, which allows the device to use the complete HID descriptor and all report types. This mode is suitable for complex peripherals that require rich capabilities and custom data formats, such as gamepads and touchscreens. |