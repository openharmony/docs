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

> **NOTE**
> This parameter is supported since API version 6 and deprecated since API version 9. You are advised to use [hasHceCapability](#hashcecapability9).

**System capability**: SystemCapability.Communication.NFC.CardEmulation

| Name  | Value   | Description      |
| ---- | ---- | -------- |
| HCE  | 0    | HCE.|
| UICC | 1    | Subscriber identity module (SIM) card emulation.|
| ESE  | 2    | embedded Secure Element (eSE) emulation. |

## CardType<sup>9+</sup>

Enumerates the types of services used by the card emulation application.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

| Name     | Value        | Description               |
| ------- | --------- | ----------------- |
| PAYMENT | "payment" | Payment type.|
| OTHER   | "other"   | Other types.|

## isSupported

isSupported(feature: number): boolean

Checks whether a certain type of card emulation is supported.

> **NOTE**
> This parameter is supported since API version 6 and deprecated since API version 9. You are advised to use [hasHceCapability](#hashcecapability9).

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name    | Type    | Mandatory  | Description                                      |
| ------- | ------ | ---- | ---------------------------------------- |
| feature | number | Yes   | Card emulation type. For details, see [FeatureType](#featuretype).|

**Return value**

| **Type** | **Description**                                |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the card emulation type is supported; returns **false** otherwise.|

## hasHceCapability<sup>9+</sup>

hasHceCapability(): boolean

Checks whether HCE is supported.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**Return value**

| **Type** | **Description**                          |
| ------- | -------------------------------- |
| boolean | Returns **true** if HCE is supported; returns **false** otherwise.|

## isDefaultService<sup>9+</sup>

isDefaultService(elementName: ElementName, type: CardType): boolean

Checks whether an application is the default application of the specified service type.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**Parameters**

| Name        | Type                                      | Mandatory  | Description                     |
| ----------- | ---------------------------------------- | ---- | ----------------------- |
| elementName | [ElementName](js-apis-bundleManager-elementName.md#elementname) | Yes   | Application description, which consists of the bundle name and component name.|
| type        | [CardType](#cardtype9)                   | Yes   | Card emulation service type.               |

**Return value**

| **Type** | **Description**                              |
| ------- | ------------------------------------ |
| boolean | Returns **true** if the application is the default payment application; returns **false** otherwise.|

**Example**

```js
import cardEmulation from '@ohos.nfc.cardEmulation';

var isHceSupported = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
}

var hasHceCap = cardEmulation.hasHceCapability();
if (!hasHceCap) {
    console.log('this device hasHceCapability false, ignore it.');
}

var elementName = {
    "bundleName": "com.example.myapplication",
    "abilityName": "EntryAbility",
};
var isDefaultService = cardEmulation.isDefaultService(elementName, cardEmulation.CardType.PAYMENT);
console.log('is the app is default service for this card type: ' + isDefaultService);
```
