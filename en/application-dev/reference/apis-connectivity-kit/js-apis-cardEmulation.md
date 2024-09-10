# @ohos.nfc.cardEmulation (Standard NFC Card Emulation)

The **cardEmulation** module implements Near-Field Communication (NFC) card emulation. You can use the APIs provided by this module to determine the card emulation type supported and implement Host Card Emulation (HCE).
HCE provides card emulation that does not depend on a secure element. It allows an application to emulate a card and communicate with an NFC card reader through the NFC service.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## HCE and AID Declaration

Before developing an application related to HCE, you must declare NFC-related attributes in the **module.json5** file.
```json
{
  "module": {
    // other declared attributes.
    "abilities": [
      {
        // other declared attributes.
        "skills": [
          {
            "actions": [
              "ohos.nfc.cardemulation.action.HOST_APDU_SERVICE"
            ]
          }
        ],
        "metadata": [
          {
            "name": "payment-aid",
            "value": "your payment aid"
          },
          {
            "name": "other-aid",
            "value": "your other aid"
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        "name": "ohos.permission.NFC_CARD_EMULATION",
        // should add variable card_emulation_reason in string.json
        "reason": "$string:card_emulation_reason",
      }
    ]
  }
}
```
> **NOTE**
>- The **actions** field must contain **ohos.nfc.cardemulation.action.HOST_APDU_SERVICE** and cannot be changed.
>- The **name** fields under **metadata** must be **payment-aid** or **other-aid** when application IDs (AIDs) are declared. Incorrect setting will cause a parsing failure.
>- The **name** field of **requestPermissions** must be **ohos.permission.NFC_CARD_EMULATION** and cannot be changed.

## Modules to Import

```
import { cardEmulation } from '@kit.ConnectivityKit';
```

## FeatureType<sup>(deprecated)</sup>

Enumerates the NFC card emulation types.

> **NOTE**
> This API is supported since API version 6 and deprecated since API version 9. Use [hasHceCapability](#hashcecapability9) instead.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

| Name  | Value   | Description      |
| ---- | ---- | -------- |
| HCE  | 0    | HCE.|
| UICC | 1    | Subscriber identity module (SIM) card emulation.|
| ESE  | 2    | embedded Secure Element (eSE) emulation. |

## CardType<sup>9+</sup>

Enumerates the types of services used by the card emulation application.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name     | Value        | Description               |
| ------- | --------- | ----------------- |
| PAYMENT | "payment" | Payment service.|
| OTHER   | "other"   | Other services.|

## isSupported<sup>(deprecated)</sup>

isSupported(feature: number): boolean

Checks whether a certain type of card emulation is supported.

> **NOTE**
> This API is supported since API version 6 and deprecated since API version 9. Use [hasHceCapability](#hashcecapability9) instead.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name    | Type    | Mandatory  | Description                                      |
| ------- | ------ | ---- | ---------------------------------------- |
| feature | number | Yes   | Card emulation type to check. For details, see [FeatureType](#featuretypedeprecated).|

**Return value**

| **Type** | **Description**                                |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the card emulation type is supported; returns **false** otherwise.|

**Example**

```js
import { cardEmulation } from '@kit.ConnectivityKit';

let isHceSupported: boolean = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
}
```

## hasHceCapability<sup>9+</sup>

hasHceCapability(): boolean

Checks whether the device supports HCE.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type** | **Description**                          |
| ------- | -------------------------------- |
| boolean | Returns **true** if HCE is supported; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |

**Example**

```js
import { cardEmulation } from '@kit.ConnectivityKit';

let isHceSupported: boolean = cardEmulation.isSupported(cardEmulation.FeatureType.HCE);
if (!isHceSupported) {
    console.log('this device is not supported for HCE, ignore it.');
}

let hasHceCap: boolean = cardEmulation.hasHceCapability();
if (!hasHceCap) {
    console.log('this device hasHceCapability false, ignore it.');
}
```

## isDefaultService<sup>9+</sup>

isDefaultService(elementName: ElementName, type: CardType): boolean

Checks whether an application is the default application of the specified service type.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name        | Type                                      | Mandatory  | Description                     |
| ----------- | ---------------------------------------- | ---- |-------------------------|
| elementName | [ElementName](../apis-ability-kit/js-apis-bundle-ElementName.md#elementname) | Yes   | Information about the page, on which the application declares the NFC card emulation capability. It cannot be empty and must contain at least **bundleName** and **abilityName**.|
| type        | [CardType](#cardtype9)                   | Yes   | Card emulation service type. Currently, only the default payment application can be queried.  |

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message |
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |

**Return value**

| **Type** | **Description**                              |
| ------- | ------------------------------------ |
| boolean | Returns **true** if the application is the default payment application; returns **false** otherwise.|


**Example**
```js
import { cardEmulation } from '@kit.ConnectivityKit';
import { bundleManager, Want } from '@kit.AbilityKit';

// Initialize elementName here. bundleName and abilityName are required.
let want: Want = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};
let elementName: bundleManager.ElementName = {
  bundleName: "com.example.myapplication",
  moduleName: "entry",
  abilityName: "EntryAbility"
};

let isDefaultService: boolean = cardEmulation.isDefaultService(elementName, cardEmulation.CardType.PAYMENT);
// Do something according to the isDefaultService value.
```


## HceService<sup>8+</sup>

Provides APIs for implementing HCE, including receiving Application Protocol Data Units (APDUs) from the peer card reader and sending a response. Before using HCE-related APIs, check whether the device supports HCE.

### startHCE<sup>(deprecated)</sup>

startHCE(aidList: string[]): boolean

Starts HCE, including enabling this application to run in the foreground preferentially and dynamically registering the AID list.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. Use [start](#start9) instead.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| aidList | string[] | Yes  | AID list to register.|

**Return value**

| **Type** | **Description**                                |
| ------- | -------------------------------------- |
| boolean | Returns **true** if HCE is started or has been started; returns **false** otherwise.|

### start<sup>9+</sup>

start(elementName: [ElementName](../apis-ability-kit/js-apis-bundle-ElementName.md#elementname), aidList: string[]): void

Starts HCE, including enabling this application to run in the foreground preferentially and dynamically registering the AID list.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| elementName | [ElementName](../apis-ability-kit/js-apis-bundle-ElementName.md#elementname) | Yes  | Information about the page, on which the application declares the NFC card emulation capability. It must contain at least **bundleName** and **abilityName**, and cannot be empty.|
| aidList | string[] | Yes  | List of AIDs to register. This parameter can be left empty.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
| 3100301 | Card emulation running state is abnormal in service. |

### stopHCE<sup>(deprecated)</sup>

stopHCE(): boolean

Stops HCE, including exiting the current application from the foreground, releasing the dynamically registered AID list, and canceling the subscription of **hceCmd**.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. Use [stop](#stop9) instead.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Return value**

| **Type** | **Description**                                |
| ------- | -------------------------------------- |
| boolean | Returns **true** is HCE is stopped; returns **false** otherwise.|

**Example**

For details, see the example of [on](#on8).

### stop<sup>9+</sup>

stop(elementName: [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md#elementname)): void 

Stops HCE, including canceling the subscription of APDU data, exiting this application from the foreground, and releasing the dynamically registered AID list. The application needs to call this API in **onDestroy** of the HCE page.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| elementName | [ElementName](../apis-ability-kit/js-apis-bundle-ElementName.md#elementname) | Yes  | Information about the page, on which the application declares the NFC card emulation capability. It must contain at least **bundleName** and **abilityName**, and cannot be empty.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
| 3100301 | Card emulation running state is abnormal in service. |

### on<sup>8+</sup>

on(type: 'hceCmd', callback: AsyncCallback\<number[]>): void

Registers a callback to receive APDUs from the peer card reader. The application needs to call this API in **onCreate()** of the HCE page.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                        |
| -------- | ----------------------- | ---- | -------------------------------------------- |
| type     | string                  | Yes  | Callback type to register. It has a fixed value of **hceCmd**.                        |
| callback | AsyncCallback\<number[]> | Yes  | Callback used to return the APDU, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**
```js
import { hilog } from '@kit.PerformanceAnalysisKit';
import { cardEmulation } from '@kit.ConnectivityKit';
import { AsyncCallback } from '@kit.BasicServicesKit';
import { ElementName } from './bundleManager/ElementName'
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

let hceService: cardEmulation.HceService = new cardEmulation.HceService();
let element: ElementName;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, param: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testHce', '%{public}s', 'Ability onCreate');
    element = {
      bundleName: want.bundleName ?? '',
      abilityName: want.abilityName ?? '',
      moduleName: want.moduleName
    }
    const apduCallback: AsyncCallback<number[]> = (err, data) => {
      //handle the data and err
      console.log("got apdu data");
    };
    hceService.on('hceCmd', apduCallback);
  }
  onDestroy() {
    hilog.info(0x0000, 'testHce', '%{public}s', 'Ability onDestroy');
    hceService.stop(element)
  }
  // other life cycle method...
}
```


### sendResponse<sup>(deprecated)</sup>

sendResponse(responseApdu: number[]): void

Sends a response to the peer card reader.

> **NOTE**
> This API is supported since API version 8 and deprecated since API version 9. Use [transmit](#transmit9) instead.

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Parameters**

| Name      | Type    | Mandatory| Description                                              |
| ------------ | -------- | ---- | -------------------------------------------------- |
| responseApdu | number[] | Yes  | Response APDU sent to the peer card reader. The value consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

### transmit<sup>9+</sup>

transmit(response: number[]): Promise\<void>

Transmits an APDU to the peer card reader. This API uses a promise to return the result. The application calls this API only after receiving an APDU sent by the card reader via [on](#on8).

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name      | Type    | Mandatory| Description                                              |
| ------------ | -------- | ---- | -------------------------------------------------- |
| response | number[] | Yes  | Response APDU sent to the peer card reader. The value consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Return value**

| **Type** | **Description**                                |
| ------- | -------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
| 3100301 | Card emulation running state is abnormal in service. |

**Example**
```js
import { cardEmulation } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let hceService: cardEmulation.HceService = new cardEmulation.HceService();

// the data app wanna send, just a example data
const responseData = [0x1, 0x2];
hceService.transmit(responseData).then(() => {
  // handle the transmit promise
  console.log("transmit Promise success.");
}).catch((err: BusinessError) => {
  console.log("transmit Promise error:", err);
});
```

### transmit<sup>9+</sup>

transmit(response: number[], callback: AsyncCallback\<void>): void

Transmits an APDU to the peer card reader. This API uses an asynchronous callback to return the result. The application calls this API only after receiving an APDU sent by the card reader via [on](#on8).

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name | Type    | Mandatory| Description                   |
| ------- | -------- | ---- | ----------------------- |
| response | number[] | Yes  | Response APDU sent to the peer card reader. The value consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message |
| ------- | -------|
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
| 3100301 | Card emulation running state is abnormal in service. |

**Example**
```js
import { cardEmulation } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let hceService: cardEmulation.HceService = new cardEmulation.HceService();

// the data app wanna send, just a example data
try {
  const responseData = [0x1, 0x2];

  hceService.transmit(responseData, (err : BusinessError)=> {
    if (err) {
      console.error(`transmit AsyncCallback err Code: ${err.code}, message: ${err.message}`);
    } else {
      console.log("transmit AsyncCallback success.");
    }
  });
} catch (error) {
  console.error(`transmit AsyncCallback catch Code: ${(error as BusinessError).code}, ` +
    `message: ${(error as BusinessError).message}`);
}
```
