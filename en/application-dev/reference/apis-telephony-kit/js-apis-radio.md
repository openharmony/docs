# @ohos.telephony.radio (Network Search)

The **radio** module provides basic network search management functions. Using the APIs provided by this module, you can obtain the radio access technology (RAT) used in the CS and PS domains, network status, current network selection mode, ISO country code of the registered network, ID of the slot in which the primary card is located, list of signal strengths of the registered network for the SIM card in the specified slot, and carrier name. Besides, you can check whether the current device supports New Radio \(NR\) and whether the radio service is enabled on the primary SIM card.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { radio } from '@kit.TelephonyKit';
```

## radio.getRadioTech

getRadioTech\(slotId: number, callback: AsyncCallback<[NetworkRadioTech](#networkradiotech11)\>\): void

Obtains the RAT used in the CS and PS domains for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<[NetworkRadioTech](#networkradiotech11)\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getRadioTech(slotId, (err: BusinessError, data: radio.NetworkRadioTech) => {
    if (err) {
        console.error(`getRadioTech failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getRadioTech success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getRadioTech

getRadioTech\(slotId: number\): Promise\<[NetworkRadioTech](#networkradiotech11)\>

Obtains the RAT used in the CS and PS domains for the SIM card in the specified slot. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                                                        | Description                                           |
| ------------------------------------------------------------ | ----------------------------------------------- |
| Promise\<[NetworkRadioTech](#networkradiotech11)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getRadioTech(slotId).then((data: radio.NetworkRadioTech) => {
    console.log(`getRadioTech success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getRadioTech failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkState

getNetworkState\(callback: AsyncCallback\<NetworkState\>\): void

Obtains the network status. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                          | Mandatory| Description      |
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NetworkState](#networkstate)\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

radio.getNetworkState((err: BusinessError, data: radio.NetworkState) => {
    if (err) {
        console.error(`getNetworkState failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNetworkState success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState

getNetworkState\(slotId: number, callback: AsyncCallback\<NetworkState\>\): void

Obtains the network status of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                          | Mandatory| Description                                  |
| -------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                         | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<[NetworkState](#networkstate)\> | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNetworkState(slotId, (err: BusinessError, data: radio.NetworkState) => {
    if (err) {
        console.error(`getNetworkState failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNetworkState success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkState

getNetworkState\(slotId?: number\): Promise\<NetworkState\>

Obtains the network status of the SIM card in the specified slot. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                                    | Description                       |
| ---------------------------------------- | --------------------------- |
| Promise\<[NetworkState](#networkstate)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNetworkState(slotId).then((data: radio.NetworkState) => {
    console.log(`getNetworkState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNetworkState failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkSelectionMode

getNetworkSelectionMode\(slotId: number, callback: AsyncCallback\<NetworkSelectionMode\>\): void

Obtains the network selection mode of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<[NetworkSelectionMode](#networkselectionmode)\> | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNetworkSelectionMode(slotId, (err: BusinessError, data: radio.NetworkSelectionMode) => {
    if (err) {
        console.error(`getNetworkSelectionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNetworkSelectionMode success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getNetworkSelectionMode

getNetworkSelectionMode\(slotId: number\): Promise\<NetworkSelectionMode\>

Obtains the network selection mode of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                                                    | Description                           |
| -------------------------------------------------------- | ------------------------------- |
| Promise\<[NetworkSelectionMode](#networkselectionmode)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNetworkSelectionMode(slotId).then((data: radio.NetworkSelectionMode) => {
    console.log(`getNetworkSelectionMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNetworkSelectionMode failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup>

getISOCountryCodeForNetwork\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                    |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2  |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result. which is a country code, for example, **CN** (China). If the device is not registered with any network, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getISOCountryCodeForNetwork(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getISOCountryCodeForNetwork failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getISOCountryCodeForNetwork success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getISOCountryCodeForNetwork<sup>7+</sup>

getISOCountryCodeForNetwork\(slotId: number\): Promise\<string\>

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the result, which is an ISO country code, for example, **CN** (China). If the device is not registered with any network, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getISOCountryCodeForNetwork(slotId).then((data: string) => {
    console.log(`getISOCountryCodeForNetwork success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getISOCountryCodeForNetwork failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getISOCountryCodeForNetworkSync<sup>10+</sup>

getISOCountryCodeForNetworkSync\(slotId: number\): string

Obtains the ISO country code of the network with which the SIM card in the specified slot is registered.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| string | ISO country code of the network, for example, **CN** (China). If the device is not registered with any network, an empty string is returned.|

**Example**

```ts
let slotId: number = 0;
let countryISO: string = radio.getISOCountryCodeForNetworkSync(slotId);
console.log(`the country ISO is:` + countryISO);
```



## radio.getPrimarySlotId<sup>7+</sup>

getPrimarySlotId\(callback: AsyncCallback\<number\>\): void

Obtains the ID of the slot in which the primary card is located. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

radio.getPrimarySlotId((err: BusinessError, data: number) => {
    if (err) {
        console.error(`getPrimarySlotId failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getPrimarySlotId success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getPrimarySlotId<sup>7+</sup>

getPrimarySlotId\(\): Promise\<number\>

Obtains the ID of the slot in which the primary card is located. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

radio.getPrimarySlotId().then((data: number) => {
    console.log(`getPrimarySlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getPrimarySlotId failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getSignalInformation<sup>7+</sup>

getSignalInformation\(slotId: number, callback: AsyncCallback\<Array\<SignalInformation\>\>\): void

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2                      |
| callback | AsyncCallback\<Array\<[SignalInformation](#signalinformation)\>\> | Yes  | Callback used to return the result, which is an array of child class objects derived from [SignalInformation](#signalinformation).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getSignalInformation(slotId, (err: BusinessError, data: Array<radio.SignalInformation>) => {
    if (err) {
        console.error(`getSignalInformation failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getSignalInformation success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getSignalInformation<sup>7+</sup>

getSignalInformation\(slotId: number\): Promise\<Array\<SignalInformation\>\>

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[SignalInformation](#signalinformation)\>\> | Promise used to return the result, which is a list of child class objects derived from [SignalInformation](#signalinformation).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getSignalInformation(slotId).then((data: Array<radio.SignalInformation>) => {
    console.log(`getSignalInformation success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSignalInformation failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getSignalInformationSync<sup>10+</sup>

getSignalInformationSync\(slotId: number\): Array\<SignalInformation\>

Obtains a list of signal strengths of the network with which the SIM card in the specified slot is registered.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                                                       | Description                                                        |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| Array\<[SignalInformation](#signalinformation)\>| Array of child class objects derived from [SignalInformation](#signalinformation).|


**Example**

```ts
let slotId: number = 0;
let signalInfo: Array<radio.SignalInformation> = radio.getSignalInformationSync(slotId);
console.log(`signal information size is:` + signalInfo.length);
```

## radio.isNrSupported<sup>8+(deprecated)</sup>

isNrSupported\(\): boolean

Check whether the current device supports NR.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [isNRSupported](#radioisnrsupported9).

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | - **true**: supported<br>- **false**: not supported|

**Example**

```ts
let result: boolean = radio.isNrSupported();
console.log("Result: "+ result);
```

## radio.isNrSupported<sup>(deprecated)</sup>

isNrSupported\(slotId: number\): boolean

Check whether the SIM card in the specified slot supports NR.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [isNRSupported](#radioisnrsupported9-1).

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| boolean | - **true**: supported<br>- **false**: not supported|

**Example**

```ts
let slotId: number = 0;
let result: boolean = radio.isNrSupported(slotId);
console.log("Result: "+ result);
```


## radio.isNRSupported<sup>9+</sup>

isNRSupported\(\): boolean

Check whether the current device supports NR.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type   | Description                            |
| ------- | -------------------------------- |
| boolean | - **true**: supported<br>- **false**: not supported|

**Example**

```ts
let result: boolean = radio.isNRSupported();
console.log("Result: "+ result);
```


## radio.isNRSupported<sup>9+</sup>

isNRSupported\(slotId: number\): boolean

Check whether the SIM card in the specified slot supports NR.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| boolean | - **true**: supported<br>- **false**: not supported|

**Example**

```ts
let slotId: number = 0;
let result: boolean = radio.isNRSupported(slotId);
console.log("Result: "+ result);
```


## radio.isRadioOn<sup>7+</sup>

isRadioOn\(callback: AsyncCallback\<boolean\>\): void

Checks whether the radio service is enabled on the primary SIM card. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                                   |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.  <br>- **true**: The radio service is enabled.<br>- **false**: The radio service is disabled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

radio.isRadioOn((err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isRadioOn failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`isRadioOn success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.isRadioOn<sup>7+</sup>

isRadioOn\(slotId: number, callback: AsyncCallback\<boolean\>\): void

Checks whether the radio service is enabled on the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                                   |
| -------- | ------------------------ | ---- | ------------------------------------------------------- |
| slotId   | number                   | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2                 |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.  <br>- **true**: The radio service is enabled.<br>- **false**: The radio service is disabled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.isRadioOn(slotId, (err: BusinessError, data: boolean) => {
    if (err) {
        console.error(`isRadioOn failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`isRadioOn success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.isRadioOn<sup>7+</sup>

isRadioOn\(slotId?: number\): Promise\<boolean\>

Checks whether the radio service is enabled on the SIM card in the specified slot. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2.<br>If the slot ID is not specified, this API is defaulted to check whether the radio service is enabled on the primary SIM card.|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.<br>- **true**: The radio service is enabled.<br>- **false**: The radio service is disabled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.isRadioOn(slotId).then((data: boolean) => {
    console.log(`isRadioOn success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isRadioOn failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getOperatorName<sup>7+</sup>

getOperatorName\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the carrier name of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                      |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2    |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the carrier name, for example, China Mobile.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getOperatorName(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getOperatorName failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getOperatorName success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getOperatorName<sup>7+</sup>

getOperatorName\(slotId: number\): Promise\<string\>

Obtains the carrier name of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the result, for example, China Mobile.               |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getOperatorName(slotId).then((data: string) => {
    console.log(`getOperatorName success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getOperatorName failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getOperatorNameSync<sup>10+</sup>

getOperatorNameSync\(slotId: number\): string

Obtains the carrier name of the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| string | Carrier name, for example, China Mobile.               |


**Example**

```ts
let slotId: number = 0;
let operatorName: string = radio.getOperatorNameSync(slotId);
console.log(`operator name is:` + operatorName);
```


## NetworkRadioTech<sup>11+</sup>

Defines the radio access technology for the packet switched (PS) or circuit switched (CS) network.

**System capability**: SystemCapability.Telephony.CoreService

|      Name      |           Type             | Mandatory|      Description         |
| --------------- | --------------------------- | ---- | ------------------ |
| psRadioTech     | [RadioTechnology](#radiotechnology) | Yes  | PS.|
| csRadioTech     | [RadioTechnology](#radiotechnology) | Yes  | CS.|

## RadioTechnology

Enumerates radio access technologies.

**System capability**: SystemCapability.Telephony.CoreService

| Name                     | Value  | Description                                                        |
| ------------------------- | ---- | ------------------------------------------------------------ |
| RADIO_TECHNOLOGY_UNKNOWN  | 0    | Unknown RAT                                   |
| RADIO_TECHNOLOGY_GSM      | 1    | Global System for Mobile Communication (GSM) |
| RADIO_TECHNOLOGY_1XRTT    | 2    | Single-Carrier Radio Transmission Technology (1XRTT)|
| RADIO_TECHNOLOGY_WCDMA    | 3    | Wideband Code Division Multiple Access (WCDMA)|
| RADIO_TECHNOLOGY_HSPA     | 4    | High Speed Packet Access (HSPA)              |
| RADIO_TECHNOLOGY_HSPAP    | 5    | Evolved High Speed Packet Access (HSPA+)    |
| RADIO_TECHNOLOGY_TD_SCDMA | 6    | TD-SCDMA.|
| RADIO_TECHNOLOGY_EVDO     | 7    | Evolution-Data Optimized (EVDO)                  |
| RADIO_TECHNOLOGY_EHRPD    | 8    | Evolved High Rate Package Data (EHRPD)       |
| RADIO_TECHNOLOGY_LTE      | 9    | Long Term Evolution (LTE)                    |
| RADIO_TECHNOLOGY_LTE_CA   | 10   | Long Term Evolution_Carrier Aggregation (LTE_CA)|
| RADIO_TECHNOLOGY_IWLAN    | 11   | Industrial Wireless LAN (IWLAN)              |
| RADIO_TECHNOLOGY_NR       | 12   | New Radio (NR)                               |


## SignalInformation

Defines the signal strength.

**System capability**: SystemCapability.Telephony.CoreService

|      Name      |           Type             | Mandatory|      Description         |
| --------------- | --------------------------- | ---- | ------------------ |
| signalType      | [NetworkType](#networktype) | Yes  | Signal strength type.|
| signalLevel     | number                      | Yes  | Signal strength level.|
| dBm<sup>9+</sup>| number                      | Yes  | Signal strength, in dBm.    |

## NetworkType

Enumerates network types.

**System capability**: SystemCapability.Telephony.CoreService

| Name                | Value  | Description                                                        |
| -------------------- | ---- | ------------------------------------------------------------ |
| NETWORK_TYPE_UNKNOWN | 0    | Unknown network.                                              |
| NETWORK_TYPE_GSM     | 1    | GSM network.   |
| NETWORK_TYPE_CDMA    | 2    | CDMA network.           |
| NETWORK_TYPE_WCDMA   | 3    | WCDMA network. |
| NETWORK_TYPE_TDSCDMA | 4    | TD-SCDMA network.|
| NETWORK_TYPE_LTE     | 5    | LTE network.                      |
| NETWORK_TYPE_NR      | 6    | NR network.                              |

## NetworkState

Defines the network status.

**System capability**: SystemCapability.Telephony.CoreService

|       Name          |                 Type               | Mandatory|                          Description                               |
| -------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| longOperatorName     | string                              |  Yes | Long carrier name of the registered network.                                    |
| shortOperatorName    | string                              |  Yes | Short carrier name of the registered network.                                    |
| plmnNumeric          | string                              |  Yes | PLMN code of the registered network.                                          |
| isRoaming            | boolean                             |  Yes | Whether the user is roaming.                                          |
| regState             | [RegState](#regstate)               |  Yes | Network registration status of the device.                                        |
| cfgTech<sup>8+</sup> | [RadioTechnology](#radiotechnology) |  Yes | RAT of the device.                                        |
| nsaState             | [NsaState](#nsastate)               |  Yes | NSA network registration status of the device.                                     |
| isCaActive           | boolean                             |  Yes | CA status.                                                  |
| isEmergency          | boolean                             |  Yes | Whether only emergency calls are allowed.                              |


## RegState

Defines the network registration status of the device.

**System capability**: SystemCapability.Telephony.CoreService

| Name                         | Value  | Description                      |
| ----------------------------- | ---- | -------------------------- |
| REG_STATE_NO_SERVICE          | 0    | The device cannot use any services, including data, SMS, and call services.    |
| REG_STATE_IN_SERVICE          | 1    | The device can use services properly, including data, SMS, and call services.    |
| REG_STATE_EMERGENCY_CALL_ONLY | 2    | The device can use only the emergency call service.|
| REG_STATE_POWER_OFF           | 3    | The device cannot communicate with the network because the cellular radio service is disabled or the modem is powered off.     |


## NsaState

Enumerates NSA network states.

**System capability**: SystemCapability.Telephony.CoreService

| Name                      | Value  | Description                                                      |
| -------------------------- | ---- | ---------------------------------------------------------- |
| NSA_STATE_NOT_SUPPORT      | 1    | The device is in idle or connected state in an LTE cell that does not support NSA.        |
| NSA_STATE_NO_DETECT        | 2    | The device is in the idle state in an LTE cell that supports NSA but not NR coverage detection.|
| NSA_STATE_CONNECTED_DETECT | 3    | The device is connected to the LTE network in an LTE cell that supports NSA and NR coverage detection.         |
| NSA_STATE_IDLE_DETECT      | 4    | The device is in the idle state in an LTE cell that supports NSA and NR coverage detection.          |
| NSA_STATE_DUAL_CONNECTED   | 5    | The device is connected to the LTE/NR network in an LTE cell that supports NSA.              |
| NSA_STATE_SA_ATTACHED      | 6    | The device is idle or connected to the NG-RAN cell when being attached to the 5G Core.     |


## NetworkSelectionMode

Enumerates network selection modes.

**System capability**: SystemCapability.Telephony.CoreService

| Name                       | Value  | Description          |
| --------------------------- | ---- | -------------- |
| NETWORK_SELECTION_UNKNOWN   | 0    | Unknown network selection mode.|
| NETWORK_SELECTION_AUTOMATIC | 1    | Automatic network selection mode.|
| NETWORK_SELECTION_MANUAL    | 2    | Manual network selection mode.|


## CellInformation<sup>8+</sup>

Defines the cell information.

**System capability**: SystemCapability.Telephony.CoreService

| Name             |                  Type                  | Mandatory|                           Description                              |
| ----------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| networkType       | [NetworkType](#networktype)             |  Yes | Network type of the cell.                                    |
| signalInformation | [SignalInformation](#signalinformation) |  Yes | Signal information.                                                  |
