# Standard NFC Card Emulation

Implements Near-Field Communication (NFC) card emulation.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## **Modules to Import**

```
import cardEmulation from '@ohos.nfc.cardEmulation';
```


## cardEmulation.isSupported

isSupported(feature: number): boolean

Checks whether a certain type of card emulation is supported.

**System capability**: SystemCapability.Communication.NFC

**Return value**

  | **Type**| **Description**|
  | -------- | -------- |
  | boolean | Returns **true** if the card emulation is supported; returns **false** otherwise.|

## HceService

Implements Host-based Card Emulation (HCE). Before calling any API in **HceService**, you must use **new cardEmulation.HceService()** to create an **HceService** instance.

### startHCE

startHCE(aidList: string[]): boolean

Starts HCE.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| aidList | string[] | Yes  | Application ID (AID) list to be registered for card emulation.|

### stopHCE

stopHCE(): boolean

Stops HCE.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC

### on

on(type: "hceCmd", callback: AsyncCallback<number[]>): void;

Subscribes to messages from the peer device after **startHCE()**.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                        |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes  | Event type to subscribe to. The value is **hceCmd**.                        |
| callback | AsyncCallback<number[]> | Yes  | Callback invoked to return the subscribed event. The input parameter is a data array that complies with the Application Protocol Data Unit (APDU).|

### sendResponse

sendResponse(responseApdu: number[]): void;

Sends a response to the peer device.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name      | Type    | Mandatory| Description                                              |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | Yes  | Data to send, which is an array that complies with the APDU.|

**Example**

```js
var hceService = new cardEmulation.HceService();
hceService.startHCE([
    "F0010203040506", "A0000000041010"
])
hceService.stopHCE();
hceService.on("hceCmd", (err, res) => {
    if(err.data === 0) {
        console.log('callback => Operation hceCmd succeeded. Data: ' + JSON.stringify(res));
          hceService.sendResponse([0x00,0xa4,0x04,0x00,
          0x0e,0x32,0x50,0x41,0x59,0x2e,0x53,0x59,0x53,0x2e,0x44,0x44,
          0x46,0x30,0x31,0x00]);
    } else {
        console.log('callback => Operation hceCmd failed. Cause: ' + err.data);
    }
})
```
