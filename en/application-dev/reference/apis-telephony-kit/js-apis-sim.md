# @ohos.telephony.sim (SIM Management)

The **sim** module provides basic SIM card management functions. With the APIs provided by this module, you can obtain the ISO country code, home PLMN ID, service provider name, SIM card status, type, installation status, and activation status of the SIM card in the specified slot.

> **NOTE**
>
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>

## Modules to Import

```ts
import { sim } from '@kit.TelephonyKit';
```

## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number, callback: AsyncCallback\<boolean\>\): void

Checks whether the SIM card in the specified slot is activated. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result, which indicates whether the SIM card in the specified slot is activated.<br>**true**: activated.<br>**false**: not activated.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.isSimActive(0, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number\): Promise\<boolean\>

Checks whether the SIM card in the specified slot is activated. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.<br>**true**: activated.<br>**false**: not activated.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.isSimActive(0).then((data: boolean) => {
    console.log(`isSimActive success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isSimActive failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.isSimActiveSync<sup>10+</sup>

isSimActiveSync\(slotId: number\): boolean

Checks whether the SIM card in the specified slot is activated.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| boolean | which indicates whether the SIM card in the specified slot is activated.<br>**true**: activated.<br>**false**: not activated.|

**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let isSimActive: boolean = sim.isSimActiveSync(0);
console.log(`the sim is active:` + isSimActive);
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(callback: AsyncCallback\<number\>\): void

Obtains the default slot ID of the SIM card that provides voice services. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description      |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result.<br>- **0**: card slot 1.<br>- **1**: card slot 2.<br>- **-1**: card slot not set or service not unavailable|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getDefaultVoiceSlotId((err: BusinessError, data: number) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(\): Promise\<number\>

Obtains the default slot ID of the SIM card that provides voice services. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<number\> | Promise used to return the result.<br>- **0**: card slot 1.<br>- **1**: card slot 2.<br>- **-1**: card slot not set or service not unavailable|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getDefaultVoiceSlotId().then((data: number) => {
    console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges\(slotId: number, callback: AsyncCallback\<boolean\>\): void

Checks whether the application (caller) has been granted the operator permission. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                    |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| slotId   | number                   | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result, which indicates whether the application (caller) has been granted the operator permission.<br>- **true**: The application (caller) has been granted the operator permission.<br>**false**: The application (caller) has not been granted the operator permission.                             |

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
import { sim } from '@kit.TelephonyKit';

sim.hasOperatorPrivileges(0, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges\(slotId: number\): Promise\<boolean\>

Checks whether the application (caller) has been granted the operator permission. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type              | Description                                                       |
| :----------------- | :---------------------------------------------------------- |
| Promise\<boolean\> | Promise used to return the result. The value **true** indicates that the application (caller) has been granted the carrier permission, and the value **false** indicates the opposite.|

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
import { sim } from '@kit.TelephonyKit';

sim.hasOperatorPrivileges(0).then((data: boolean) => {
    console.log(`hasOperatorPrivileges success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`hasOperatorPrivileges failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the ISO country code of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                    |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2  |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result, which is a country code, for example, **CN** (China).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getISOCountryCodeForSim(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number\): Promise\<string\>

Obtains the ISO country code of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | Promise used to return the result, which is the ISO country code of the SIM card in the specified slot, for example, **CN** (China).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getISOCountryCodeForSim(0).then((data: string) => {
    console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getISOCountryCodeForSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSimSync<sup>10+</sup>

getISOCountryCodeForSimSync\(slotId: number\): string

Obtains the ISO country code of the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| string | ISO country code of the SIM card in the specified slot, for example, **CN** (China).|


**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let countryCode: string = sim.getISOCountryCodeForSimSync(0);
console.log(`the country ISO is:` + countryCode);
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the home public land mobile network (PLMN) ID of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result, which is the home PLMN number of the SIM card in the specified slot.                         |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimOperatorNumeric(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number\): Promise\<string\>

Obtains the home PLMN ID of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                            |
| ----------------- | ------------------------------------------------ |
| Promise\<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimOperatorNumeric(0).then((data: string) => {
    console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimOperatorNumeric failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimOperatorNumericSync<sup>10+</sup>

getSimOperatorNumericSync\(slotId: number\): string

Obtains the home PLMN ID of the SIM card in the specified slot. This API returns the result synchronously.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                            |
| ----------------- | ------------------------------------------------ |
| string | Home PLMN number of the SIM card in the specified slot.|


**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let numeric: string = sim.getSimOperatorNumericSync(0);
console.log(`the sim operator numeric is:` + numeric);
```


## sim.getSimSpn

getSimSpn\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the service provider name (SPN) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result, which is the SPN of the SIM card in the specified slot.                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimSpn(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number\): Promise\<string\>

Obtains the SPN of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                     |
| ----------------- | ----------------------------------------- |
| Promise\<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimSpn(0).then((data: string) => {
    console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimSpn failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimSpnSync<sup>10+</sup>

getSimSpnSync\(slotId: number\): string

Obtains the SPN of the SIM card in the specified slot. This API returns the result synchronously.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                     |
| ----------------- | ----------------------------------------- |
| string | SPN of the SIM card in the specified slot.|


**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let spn: string = sim.getSimSpnSync(0);
console.log(`the sim card spn is:` + spn);
```


## sim.getSimState

getSimState\(slotId: number, callback: AsyncCallback\<SimState\>\): void

Obtains the state of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                  | Mandatory| Description                                  |
| -------- | -------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                 | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<[SimState](#simstate)\> | Yes  | Callback used to return the result, which is the state of the SIM card in the specified slot. For details, see [SimState](#simstate). |

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
import { sim } from '@kit.TelephonyKit';

sim.getSimState(0, (err: BusinessError, data: sim.SimState) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimState

getSimState\(slotId: number\): Promise\<SimState\>

Obtains the state of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                            | Description                                      |
| -------------------------------- | ------------------------------------------ |
| Promise\<[SimState](#simstate)\> | Promise used to return the result.|

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
import { sim } from '@kit.TelephonyKit';

sim.getSimState(0).then((data: sim.SimState) => {
    console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimStateSync<sup>10+</sup>

getSimStateSync\(slotId: number\): SimState

Obtains the state of the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                        | Description                                      |
| ---------------------------- | ------------------------------------------ |
| [SimState](#simstate) | State of the SIM card in the specified slot.|


**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let simState: sim.SimState = sim.getSimStateSync(0);
console.log(`The sim state is:` + simState);
```

## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number, callback: AsyncCallback\<CardType\>\): void

Obtains the type of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback\<[CardType](#cardtype7)\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getCardType(0, (err: BusinessError, data: sim.CardType) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number\): Promise\<CardType\>

Obtains the type of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<[CardType](#cardtype7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getCardType(0).then((data: sim.CardType) => {
    console.log(`getCardType success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCardType failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getCardTypeSync<sup>10+</sup>

getCardTypeSync\(slotId: number\): CardType

Obtains the type of the SIM card in the specified slot. 

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| [CardType](#cardtype7) | Type of the SIM card in the specified slot.|


**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let cardType: sim.CardType = sim.getCardTypeSync(0);
console.log(`the card type is:` + cardType);
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number, callback: AsyncCallback\<boolean\>\): void

Checks whether the SIM card in the specified slot is installed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;boolean&gt; | Yes | Callback used to return the result.<br>- **true**: installed.<br>- **false**: not installed.                          |

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
import { sim } from '@kit.TelephonyKit';

sim.hasSimCard(0, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number\): Promise\<boolean\>

Checks whether the SIM card in the specified slot is installed. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.<br>- **true**: installed.<br>- **false**: not installed.|

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
import { sim } from '@kit.TelephonyKit';

sim.hasSimCard(0).then((data: boolean) => {
    console.log(`hasSimCard success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`hasSimCard failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasSimCardSync<sup>10+</sup>

hasSimCardSync\(slotId: number\): boolean

Checks whether the SIM card in the specified slot is installed.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| boolean | Whether the SIM card in the specified slot is installed.<br>- **true**: installed.<br>- **false**: not installed.|

**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let hasSimCard: boolean = sim.hasSimCardSync(0);
console.log(`has sim card: ` + hasSimCard);
```

## sim.getSimAccountInfo<sup>10+</sup>

getSimAccountInfo\(slotId: number, callback: AsyncCallback\<IccAccountInfo\>\): void

Obtains account information of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

> **NOTE**
>
> The **GET_TELEPHONY_STATE** permission is required to obtain the ICCID and phone number. Such information is sensitive and not open to third-party applications. When this API is called, the returned ICCID and phone number are empty.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                               | Mandatory| Description                                  |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                              | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;[IccAccountInfo](#iccaccountinfo10)&gt; | Yes  | Callback used to return the result, which is the account information of the SIM card in the specified slot.                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |
| 8301002  | The SIM card failed to read or update data.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimAccountInfo(0, (err:BusinessError , data: sim.IccAccountInfo) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimAccountInfo<sup>10+</sup>

getSimAccountInfo\(slotId: number\): Promise\<IccAccountInfo\>

Obtains account information of the SIM card in the specified slot. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

> **NOTE**
>
> The **GET_TELEPHONY_STATE** permission is required to obtain the ICCID and phone number. Such information is sensitive and not open to third-party applications. When this API is called, the returned ICCID and phone number are empty.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type                                        | Description                                      |
| -------------------------------------------- | ------------------------------------------ |
| Promise&lt;[IccAccountInfo](#iccaccountinfo10)&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |
| 8301002  | The SIM card failed to read or update data.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimAccountInfo(0).then((data: sim.IccAccountInfo) => {
    console.log(`getSimAccountInfo success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimAccountInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getActiveSimAccountInfoList<sup>10+</sup>

getActiveSimAccountInfoList\(callback: AsyncCallback\<Array\<IccAccountInfo\>\>\): void

Obtains the list of activated SIM card accounts. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

> **NOTE**
>
> The **GET_TELEPHONY_STATE** permission is required to obtain the ICCID and phone number. Such information is sensitive and not open to third-party applications. When this API is called, the returned ICCID and phone number are empty.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description      |
| -------- | ----------------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;Array&lt;[IccAccountInfo](#iccaccountinfo10)&gt;&gt; | Yes  | Callback used to return the result, which is a list of activated SIM card accounts.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getActiveSimAccountInfoList((err: BusinessError, data: Array<sim.IccAccountInfo>) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.getMaxSimCount<sup>7+</sup>

getMaxSimCount\(\): number

Obtains the number of card slots.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| number | Number of card slots.|

**Example**

```ts
import { sim } from '@kit.TelephonyKit';

console.log("Result: "+ sim.getMaxSimCount());
```


## sim.getActiveSimAccountInfoList<sup>10+</sup>

getActiveSimAccountInfoList\(\): Promise\<Array\<IccAccountInfo\>\>

Obtains the list of activated SIM card accounts. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

> **NOTE**
>
> The **GET_TELEPHONY_STATE** permission is required to obtain the ICCID and phone number. Such information is sensitive and not open to third-party applications. When this API is called, the returned ICCID and phone number are empty.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type                                                | Description                                          |
| ---------------------------------------------------- | ---------------------------------------------- |
| Promise&lt;Array&lt;[IccAccountInfo](#iccaccountinfo10)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getActiveSimAccountInfoList().then((data: Array<sim.IccAccountInfo>) => {
    console.log(`getActiveSimAccountInfoList success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getActiveSimAccountInfoList failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getOpKey<sup>9+</sup>

getOpKey\(slotId: number, callback: AsyncCallback\<string\>): void

Obtains the opkey of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

try {
    sim.getOpKey(0, (err: BusinessError, data: string) => {
    if (err) {
      console.error("getOpKey failed, err: " + JSON.stringify(err));
    } else {
      console.log('getOpKey successfully, data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.error("getOpKey err: " + JSON.stringify(err));
}
```


## sim.getOpKey<sup>9+</sup>

getOpKey\(slotId: number\): Promise\<string\>

Obtains the opkey of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getOpKey(0).then((data: string) => {
    console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getOpKey failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpKeySync<sup>10+</sup>

getOpKeySync\(slotId: number\): string

Obtains the opkey of the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| string | opkey of the SIM card in the specified slot.|


**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let data: string = sim.getOpKeySync(0);
console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);
```

## sim.getOpName<sup>9+</sup>

getOpName\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the OpName of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

try {
    sim.getOpName(0, (err: BusinessError, data: string) => {
    if (err) {
      console.error("getOpName failed, err: " + JSON.stringify(err));
    } else {
      console.log('getOpName successfully, data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.error("getOpName err: " + JSON.stringify(err));
}
```


## sim.getOpName<sup>9+</sup>

getOpName\(slotId: number\): Promise\<string\>

Obtains the OpName of the SIM card in the specified slot. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                      |
| ---------------- | ------------------------------------------ |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getOpName(0).then((data: string) => {
    console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getOpName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpNameSync<sup>10+</sup>

getOpNameSync\(slotId: number\): string

Obtains the OpName of the SIM card in the specified slot.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                      |
| ---------------- | ------------------------------------------ |
| string | OpName of the SIM card in the specified slot.|


**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let data: string = sim.getOpNameSync(0);
console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);
```

## sim.getDefaultVoiceSimId<sup>10+</sup>

getDefaultVoiceSimId\(callback: AsyncCallback\<number\>\): void

Obtains the default slot ID of the SIM card that provides voice services. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description      |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result.<br>The return value is bound to the SIM card and increases from 1.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |
| 8301001  | SIM card is not activated.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getDefaultVoiceSimId((err: BusinessError, data: number) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.getDefaultVoiceSimId<sup>10+</sup>

getDefaultVoiceSimId\(\): Promise\<number\>

Obtains the default slot ID of the SIM card that provides voice services. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<number\> | Promise used to return the result.<br>The return value is bound to the SIM card and increases from 1.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |
| 8301001  | SIM card is not activated.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let promise = sim.getDefaultVoiceSimId();
promise.then((data: number) => {
    console.log(`getDefaultVoiceSimId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultVoiceSimId failed, promise: err->${JSON.stringify(err)}`);
});
```


## SimState

Enumerates SIM card states.

**System capability**: SystemCapability.Telephony.CoreService

| Name                 | Value  | Description                                                      |
| --------------------- | ---- | ---------------------------------------------------------- |
| SIM_STATE_UNKNOWN     | 0    | The SIM card is in **unknown** state; that is, the SIM card status cannot be obtained.                     |
| SIM_STATE_NOT_PRESENT | 1    | The SIM card is in **not present** state; that is, no SIM card is inserted into the card slot.     |
| SIM_STATE_LOCKED      | 2    | The SIM card is in **locked** state; that is, the SIM card is locked by the personal identification number (PIN), PIN unblocking key (PUK), or network.  |
| SIM_STATE_NOT_READY   | 3    | The SIM card is in **not ready** state; that is, the SIM card has been installed but cannot work properly.   |
| SIM_STATE_READY       | 4    | The SIM card is in **ready** state; that is, the SIM card has been installed and is working properly.           |
| SIM_STATE_LOADED      | 5    | The SIM card is in **loaded** state; that is, the SIM card is present and all its files have been loaded.|

## CardType<sup>7+</sup>

Enumerates SIM card types.

**System capability**: SystemCapability.Telephony.CoreService

| Name| Value| Description|
| ----- | ----- | ----- |
|UNKNOWN_CARD | -1 | Unknown type.|
|SINGLE_MODE_SIM_CARD | 10 | Single-card (SIM).|
|SINGLE_MODE_USIM_CARD | 20 | Single-card (USIM).|
|SINGLE_MODE_RUIM_CARD | 30 | Single-card (RUIM).|
|DUAL_MODE_CG_CARD | 40 | Dual-card (CDMA+GSM).|
|CT_NATIONAL_ROAMING_CARD | 41 | China Telecom internal roaming card.|
|CU_DUAL_MODE_CARD | 42 | China Unicom dual-mode card.|
|DUAL_MODE_TELECOM_LTE_CARD | 43 | China Telecom dual-mode LTE card.|
|DUAL_MODE_UG_CARD | 50 | Dual-mode card (UMTS+GSM).|
|SINGLE_MODE_ISIM_CARD<sup>8+</sup> | 60 | Single-card (ISIM).|

## IccAccountInfo<sup>10+</sup>

Defines the ICC account information.

**System capability**: SystemCapability.Telephony.CoreService

| Name      | Type   | Mandatory| Description            |
| ---------- | ------- | ---- | ---------------- |
| simId      | number  |  Yes | SIM card ID.         |
| slotIndex  | number  |  Yes | Card slot ID.          |
| isEsim     | boolean |  Yes | Whether the SIM card is an eSim.<br>- **true**: The SIM card is an eSim.<br>- **false**: The SIM card is not an eSim.|
| isActive   | boolean |  Yes | Whether the card is activated.<br>**true**: activated.<br>**false**: not activated. |
| iccId      | string  |  Yes | ICCID number.       |
| showName   | string  |  Yes | SIM card display name.   |
| showNumber | string  |  Yes | SIM card display number.   |
