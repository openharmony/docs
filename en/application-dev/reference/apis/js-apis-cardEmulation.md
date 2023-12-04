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

## HceService<sup>8+</sup>

Implements HCE, including receiving Application Protocol Data Units (APDUs) from the peer card reader and sending a response. Before using HCE-related APIs, check whether the device supports HCE. This API is used only for declaration and cannot be used currently.

### startHCE<sup>8+</sup>

startHCE(aidList: string[]): boolean

Starts HCE, including setting the application to be foreground preferred and dynamically registering the application identifier (AID) list. This API is used only for declaration and cannot be used currently.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [start](#start9).

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| aidList | string[] | Yes  | AID list to register.|

### start<sup>9+</sup>

start(elementName: ElementName, aidList: string[]): void

Starts HCE, including setting the application to be foreground preferred and dynamically registering the application identifier (AID) list. This API is used only for declaration and cannot be used currently.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| elementName | ElementName | Yes  | Element name of the service capability.|
| aidList | string[] | Yes  | List of AIDs. This parameter can be left empty.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

### stopHCE<sup>8+</sup>

stopHCE(): boolean

Stops HCE, including removing the foreground preferred attribute and releasing the dynamically registered AID list. This API is used only for declaration and cannot be used currently.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [stop](#stop).

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

### stop<sup>9+</sup>

stop(elementName: ElementName): void;

Stops HCE, including removing the foreground preferred attribute and releasing the dynamically registered AID list. This API is used only for declaration and cannot be used currently.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| elementName | ElementName | Yes  | Element name of a service capability.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

### on<sup>8+</sup>

on(type: "hceCmd", callback: AsyncCallback<number[]>): void;

Registers a callback to receive APDUs from the peer card reader. This API is used only for declaration and cannot be used currently.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name  | Type                   | Mandatory| Description                                        |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes  | Event type to subscribe to. The value is **hceCmd**.                        |
| callback | AsyncCallback<number[]> | Yes  | Callback invoked to return the APDU, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

### sendResponse<sup>8+</sup>

sendResponse(responseApdu: number[]): void;

Sends a response to the peer card reader. This API is used only for declaration and cannot be used currently.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [transmit](#transmit9).

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name      | Type    | Mandatory| Description                                              |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | Yes  | Response APDU sent to the peer card reader. The value consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

### transmit<sup>9+</sup>

transmit(response: number[]): Promise\<void>;

Sends a response to the peer card reader. This API is used only for declaration and cannot be used currently.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name      | Type    | Mandatory| Description                                              |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | Yes  | Response APDU sent to the peer card reader. The value consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Return value**

| **Type** | **Description**                                |
| ------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

### transmit<sup>9+</sup>

transmit(response: number[], callback: AsyncCallback\<void>): void;

Sends a response to the peer card reader. This API is used only for declaration and cannot be used currently.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| responseApdu | number[] | Yes  | Response APDU sent to the peer card reader. The value consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| callback | AsyncCallback\<void> | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
| 3100301 | Card emulation running state is abnormal in service. |

**Example**

```js
import cardEmulation from '@ohos.nfc.cardEmulation';
import bundleManager from '@ohos.bundle.bundleManager';

let isHceSupported = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
}

let hasHceCap = cardEmulation.hasHceCapability();
if (!hasHceCap) {
    console.log('this device hasHceCapability false, ignore it.');
}

let elementName: bundleManager.ElementName = {
    bundleName : "com.example.myapplication",
    abilityName : "EntryAbility",
};
let isDefaultService = cardEmulation.isDefaultService(elementName, cardEmulation.CardType.PAYMENT);
console.log('is the app is default service for this card type: ' + isDefaultService);
```
