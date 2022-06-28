# Standard NFC

Implements Near-Field Communication (NFC).

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## **Modules to Import**

```
import controller from '@ohos.nfc.controller';
```


## controller.isNfcAvailable

isNfcAvailable(): boolean

Checks whether NFC is available.

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if NFC is available; returns **false** otherwise.|


## controller.openNfc

openNfc(): boolean

Opens NFC.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise. |

## controller.closeNfc

closeNfc(): boolean

Closes NFC.

**Required permissions**: ohos.permission.MANAGE_SECURE_SETTINGS

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                                   |
| -------- | ------------------------------------------- |
| boolean  | Returns **true** if the operation is successful; returns **false** otherwise.|

## controller.isNfcOpen

isNfcOpen(): boolean

Checks whether NFC is open.

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                           |
| -------- | ----------------------------------- |
| boolean  | Returns **true** if NFC is open; returns **false** otherwise.|

## controller.getNfcState

getNfcState(): NfcState

Obtains the NFC state.

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**              |
| -------- | ---------------------- |
| NfcState | NFC state obtained. For details, see [NfcState](#nfcstate).|

## controller.on('nfcStateChange')

on(type: "nfcStateChange", callback: Callback&lt;NfcState&gt;): void

Subscribes to NFC state changes.

**System capability**: SystemCapability.Communication.NFC

**Parameter**
  
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to subscribe to. The value is **nfcStateChange**.|
  | callback | Callback&lt;NfcState&gt; | Yes| Callback invoked to return the NFC state changes.|



## controller.off('nfcStateChange')

off(type: "nfcStateChange", callback?: Callback&lt;NfcState&gt;): void

Unsubscribes from the NFC state changes.

**System capability**: SystemCapability.Communication.NFC

**Parameter**
  
  | **Name**| **Type**| **Mandatory**| **Description**|
  | -------- | -------- | -------- | -------- |
  | type | string | Yes| Event type to unsubscribe from. The value is **nfcStateChange**.|
| callback | Callback&lt;NfcState&gt; | No| Callback used to return the NFC state changes. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|
  
**Example**

  ```js
  import nfcController from '@ohos.nfcController';
  
  var NFC_STATE_NOTIFY = "nfcStateChange";
  
  var recvNfcStateNotifyFunc = result => {
      console.info("nfc state receive state: " + result);
  }
  
  // Subscribe to the NFC state changes.
  nfcController.on(NFC_STATE_NOTIFY, recvNfcStateNotifyFunc);
  
  // Unsubscribe from the NFC state changes.
  nfcController.off(NFC_STATE_NOTIFY, recvNfcStateNotifyFunc);
  ```

## NfcState

Enumerates the NFC states.

| Name| Default Value| Description|
| -------- | -------- | -------- |
| STATE_OFF | 1 | Off|
| STATE_TURNING_ON | 2 | Turning on|
| STATE_ON | 3      | On|
| STATE_TURNING_OFF | 4      | Turning off|
