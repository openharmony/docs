# @ohos.nfc.cardEmulation (Standard NFC Card Emulation) (System API)

The **cardEmulation** module implements Near-Field Communication (NFC) card emulation. You can use the APIs provided by this module to determine the card emulation type supported and implement Host Card Emulation (HCE).
HCE provides card emulation that does not depend on a secure element. It allows an application to emulate a card and communicate with an NFC card reader through the NFC service.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](js-apis-cardEmulation.md).


## Modules to Import

```
import { cardEmulation } from '@kit.ConnectivityKit';
```

## getPaymentServices<sup>11+</sup>

getPaymentServices(): [AbilityInfo](../apis-ability-kit/js-apis-bundleManager-abilityInfo.md)[]

Obtains all payment services. If an application declares the support for the HCE feature and **payment-aid**, the application is contained in the payment service list. For details, see [HCE and AID Declaration](js-apis-cardEmulation.md#hce-and-aid-declaration).

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NFC.CardEmulation

**Required permissions**: ohos.permission.NFC_CARD_EMULATION

**Return value**

| **Type** | **Description**                              |
| ------- | ------------------------------------ |
| [AbilityInfo](../apis-ability-kit/js-apis-bundleManager-abilityInfo.md)[] | List of payment services obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| -------- | ---------------------------- |
|201 | Permission denied.                 |
|202 | Non-system applications are not allowed to use system APIs. |
|801 | Capability not supported.          |

**Example**
```js
import { cardEmulation } from '@kit.ConnectivityKit';

let paymentServices = cardEmulation.getPaymentServices();
if (paymentServices == undefined || paymentServices.length == 0) {
  console.log('paymentServices is null.');
}

```
