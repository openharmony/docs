# @ohos.nfc.controller (Standard NFC)

The **nfcController** module provides APIs for opening and closing Near-Field Communication (NFC) and reading the NFC state.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import controller from '@ohos.nfc.controller';
```

## NfcState

Enumerates the NFC states.

**System capability**: SystemCapability.Communication.NFC.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| STATE_OFF | 1 | NFC is closed (OFF).|
| STATE_TURNING_ON | 2 | NFC is turning on.|
| STATE_ON | 3      | NFC is open (ON).|
| STATE_TURNING_OFF | 4      | NFC is turning off.|

## controller.isNfcAvailable

isNfcAvailable(): boolean

Checks whether the device supports NFC.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the device supports NFC; returns **false** otherwise.|


## controller.openNfc

openNfc(): boolean

Opens NFC.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

## controller.closeNfc

closeNfc(): boolean

Closes NFC.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                                   |
| -------- | ------------------------------------------- |
| boolean  | Returns **true** if the operation is successful; returns **false** otherwise.|

## controller.isNfcOpen

isNfcOpen(): boolean

Checks whether NFC is open.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                           |
| -------- | ----------------------------------- |
| boolean  | Returns **true** if NFC is open; returns **false** otherwise.|

## controller.getNfcState

getNfcState(): [NfcState](#nfcstate)

Obtains the NFC state.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**              |
| -------- | ---------------------- |
| [NfcState](#nfcstate) | NFC state obtained. For details, see [NfcState](#nfcstate).|

## controller.on('nfcStateChange')

on(type: "nfcStateChange", callback: Callback&lt;[NfcState](#nfcstate)&gt;): void

Subscribes to NFC state changes. A callback will be invoked to return the NFC state when the NFC state changes.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameter**
  
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to subscribe to. The value is **nfcStateChange**.|
| callback | Callback&lt;[NfcState](#nfcstate)&gt; | Yes| Callback invoked to return the NFC state.|

## controller.off('nfcStateChange')

off(type: "nfcStateChange", callback?: Callback&lt;[NfcState](#nfcstate)&gt;): void

Unsubscribes from the NFC state changes. The subscriber will not receive NFC state change notifications.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameter**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type to unsubscribe from. The value is **nfcStateChange**.|
| callback | Callback&lt;[NfcState](#nfcstate)&gt; | No| Callback for the NFC state changes. This parameter can be left blank.|
  
**Example**

```js
import controller from '@ohos.nfc.controller';

// Register the callback to receive NFC state change notifications.
controller.on("nfcStateChange", (err, nfcState)=> {
  if (err) {
      console.log("controller on callback err: " + err);
  } else {
      console.log("controller on callback nfcState: " + nfcState);
  }
});

// Open NFC. Require permission: ohos.permission.MANAGE_SECURE_SETTINGS.
if (!controller.isNfcOpen()) {
  var ret = controller.openNfc();
  console.log("controller openNfc ret: " + ret);
}

// Close NFC. Require permission: ohos.permission.MANAGE_SECURE_SETTINGS.
if (controller.isNfcOpen()) {
  var ret = controller.closeNfc();
  console.log("controller closeNfc ret: " + ret);
}

// Unregister the callback.
controller.off("nfcStateChange");
```
