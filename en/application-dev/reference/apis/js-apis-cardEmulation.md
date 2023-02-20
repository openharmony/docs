# @ohos.nfc.cardEmulation (Standard NFC Card Emulation)

The **cardEmulation** module implements Near-Field Communication (NFC) card emulation. You can use the APIs provided by this module to determine the card emulation type supported and implement Host-based Card Emulation (HCE).

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import cardEmulation from '@ohos.nfc.cardEmulation';
```

## FeatureType

Enumerates the NFC card emulation types.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

| Name| Value| Description|
| -------- | -------- | -------- |
| HCE | 0 | HCE.|
| UICC | 1 | Subscriber identity module (SIM) card emulation.|
| ESE | 2      | embedded Secure Element (eSE) emulation.|

## CardType

Enumerates the card emulation application types.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

| Name| Value| Description|
| -------- | -------- | -------- |
| PAYMENT | "payment" | Payment type.|
| OTHER | "other" | Other types. |

## cardEmulation.isSupported

isSupported(feature: number): boolean

Checks whether a certain type of card emulation is supported.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| feature | number | Yes  | Card emulation type. For details, see [FeatureType](#featuretype).|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the card emulation type is supported; returns **false** otherwise.|

## cardEmulation.isDefaultService

isDefaultService(elementName: ElementName, type: CardType): boolean

Checks whether the specified application is of the default payment type.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md#elementname) | Yes| Application description, which includes the bundle name and component name.|
| type | [CardType](#cardtype) | Yes| Application description, which includes the bundle name and component name.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the application is the default payment application; returns **false** otherwise.|

## HceService<sup>8+</sup>

Implements HCE, including receiving Application Protocol Data Units (APDUs) from the peer card reader and sending a response. Before using HCE-related APIs, check whether the device supports HCE.

### startHCE<sup>8+</sup>

startHCE(aidList: string[]): boolean

Starts HCE, including setting the application to be foreground preferred and dynamically registering the application identifier (AID) list.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| aidList | string[] | Yes  | AID list to register.|

### stopHCE<sup>8+</sup>

stopHCE(): boolean

Stops HCE, including removing the foreground preferred attribute and releasing the dynamically registered AID list.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

### on<sup>8+</sup>

on(type: "hceCmd", callback: AsyncCallback<number[]>): void;

Registers a callback to receive APDUs from the peer card reader.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name  | Type                   | Mandatory| Description                                        |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes  | Event type to subscribe to. The value is **hceCmd**.                        |
| callback | AsyncCallback<number[]> | Yes  | Callback invoked to return the APDU, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

### sendResponse<sup>8+</sup>

sendResponse(responseApdu: number[]): void;

Sends a response to the peer card reader.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name      | Type    | Mandatory| Description                                              |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | Yes  | Response APDU sent to the peer card reader. The value consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import cardEmulation from '@ohos.nfc.cardEmulation';

var isHceSupported = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
    return;
}

var elementName = {
    "bundleName": "com.test.cardemulation",
    "abilityName": "com.test.cardemulation.MainAbility",
};
var isDefaultService = cardEmulation.isDefaultService(elementName, cardEmulation.CardType.PAYMENT);
console.log('is the app is default service for this card type: ' + isDefaultService);

// The device supports HCE and transimits APDUs with the remote NFC reader.
var hceService = new cardEmulation.HceService();
hceService.startHCE([
    "F0010203040506", "A0000000041010"
]);

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

// stop HCE when the application exit the nfc card emulation.
hceService.stopHCE();
```
