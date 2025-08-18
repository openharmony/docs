# @ohos.telephony.sim (SIM Management) (System API)

The **sim** module provides basic SIM card management functions. You can obtain the name, number, ISO country code, home PLMN ID, service provider name, SIM card status, type, installation status, activation status, and lock status of the SIM card in the specified slot. Besides, you can set the name, number, and lock status of the SIM card, activate or deactivate the SIM card, and change the PIN or unlock the PIN or PUK of the SIM card.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.telephony.sim (SIM Management)](js-apis-sim.md).

## Modules to Import

```ts
import { sim } from '@kit.TelephonyKit';
```

## sim.isOperatorSimCard<sup>11+</sup>

isOperatorSimCard\(slotId: number, operator: OperatorSimCard\): boolean

Checks whether the SIM card in the specified slot is provided by a specified carrier.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type                                    | Mandatory| Description                               |
| ------ | --------------------------------------- | ---- | ---------------------------------  |
| slotId | number                                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| operator | [OperatorSimCard](#operatorsimcard11) | Yes  | Carrier name. (Currently, only SIM cards of China Telecom are supported.)|

**Return value**

| Type                 | Description                              |
| --------------------- | ---------------------------------- |
| boolean | Boolean value indicating whether the SIM card in the specified slot is provided by the specified carrier.<br>- **true**: The SIM card in the specified slot is provided by the specified carrier.<br>- **false**: The SIM card in the specified slot is not provided by the specified carrier.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { sim } from '@kit.TelephonyKit';

let slotId : number = 0;
let operator : sim.OperatorSimCard = sim.OperatorSimCard.CHINA_TELECOM_CARD;
try {
    let isOperatorSimCard: boolean = sim.isOperatorSimCard(slotId, operator);
    console.log(`is operator sim card: ` + isOperatorSimCard);
} catch (err) {
    console.error("isOperatorSimCard err: " + JSON.stringify(err));
}
```

## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId\(slotId: number, callback: AsyncCallback\<void\>\): void

Sets the default slot ID of the SIM card that provides voice services. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: Clears the default configuration.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.setDefaultVoiceSlotId(0, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId\(slotId: number\): Promise\<void\>

Sets the default slot ID of the SIM card that provides voice services. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: Clears the default configuration.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.setDefaultVoiceSlotId(0).then(() => {
    console.log(`setDefaultVoiceSlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setShowName<sup>8+</sup>

setShowName\(slotId: number, name: string, callback: AsyncCallback\<void\>\): void

Sets a display name for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| name     | string                    | Yes  | SIM card name.                             |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let name: string = "ShowName";
sim.setShowName(0, name, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```

## sim.setShowName<sup>8+</sup>

setShowName\(slotId: number, name: string\): Promise\<void\>

Sets a display name for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| name   | string | Yes  | SIM card name.                             |

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let name: string = "ShowName";
sim.setShowName(0, name).then(() => {
    console.log(`setShowName success.`);
}).catch((err: BusinessError) => {
    console.error(`setShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getShowName<sup>8+</sup>

getShowName\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the name of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getShowName(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getShowName<sup>8+</sup>

getShowName\(slotId: number\): Promise\<string\>

Obtains the name of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                                  |
| --------------------- | -------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getShowName(0).then((data: string) => {
    console.log(`getShowName success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setShowNumber<sup>8+</sup>

setShowNumber\(slotId: number, number: string, callback: AsyncCallback\<void\>\): void

Sets a display number for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| number   | string                    | Yes  | SIM card number.                             |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let number: string = '+861xxxxxxxxxx';
sim.setShowNumber(0, number, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.setShowNumber<sup>8+</sup>

setShowNumber\(slotId: number, number: string\): Promise\<void\>

Sets a display number for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| number | string | Yes  | SIM card number.                             |

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let number: string = '+861xxxxxxxxxx';
sim.setShowNumber(0, number).then(() => {
    console.log(`setShowNumber success.`);
}).catch((err: BusinessError) => {
    console.error(`setShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getShowNumber<sup>8+</sup>

getShowNumber\(slotId: number, callback: AsyncCallback\<string\>): void

Obtains the display number of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description                                  |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getShowNumber(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getShowNumber<sup>8+</sup>

getShowNumber\(slotId: number\): Promise\<string\>

Obtains the display number of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getShowNumber(0).then((data: string) => {
    console.log(`getShowNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.activateSim<sup>8+</sup>

activateSim\(slotId: number, callback: AsyncCallback\<void\>\): void

Activates the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.activateSim(0, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.activateSim<sup>8+</sup>

activateSim\(slotId: number\): Promise\<void\>

Activates the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.activateSim(0).then(() => {
    console.log(`activateSim success.`);
}).catch((err: BusinessError) => {
    console.error(`activateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.deactivateSim<sup>8+</sup>

deactivateSim\(slotId: number, callback: AsyncCallback\<void\>\): void

Disables the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                     | Mandatory| Description                                  |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.deactivateSim(0, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.deactivateSim<sup>8+</sup>

deactivateSim\(slotId: number\): Promise\<void\>

Disables the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.deactivateSim(0).then(() => {
    console.log(`deactivateSim success.`);
}).catch((err: BusinessError) => {
    console.error(`deactivateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setLockState<sup>7+</sup>

setLockState\(slotId: number, options: LockInfo, callback: AsyncCallback\<LockStatusResponse\>\): void

Sets the lock status of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                                        |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                                                  |
| options  | [LockInfo](#lockinfo8)                                      | Yes  | Lock information.<br>- lockType: [LockType](#locktype8)<br>- password: string<br>- state: [LockState](#lockstate8) |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let lockInfo: sim.LockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
sim.setLockState(0, lockInfo, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setLockState<sup>7+</sup>

setLockState\(slotId: number, options: LockInfo\): Promise\<LockStatusResponse\>

Sets the lock status of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type                  | Mandatory| Description                                                        |
| ------- | ---------------------- | ---- | ------------------------------------------------------------ |
| slotId  | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                      |
| options | [LockInfo](#lockinfo8) | Yes  | Lock information.<br>- lockType: [LockType](#locktype8)<br>- password: string<br>- state: [LockState](#lockstate8) |

**Return value**

| Type                                                | Description                                        |
| ---------------------------------------------------- | -------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let lockInfo: sim.LockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
sim.setLockState(0, lockInfo).then((data: sim.LockStatusResponse) => {
    console.log(`setLockState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`setLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getLockState<sup>8+</sup>

getLockState\(slotId: number, lockType: LockType, callback: AsyncCallback\<LockState\>\): void

Obtains the lock status of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                     | Mandatory| Description                                   |
| -------- | ----------------------------------------- | ---- | --------------------------------------- |
| slotId   | number                                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2 |
| callback | AsyncCallback\<[LockState](#lockstate8)\> | Yes  | Callback used to return the result.                             |
| options  | [LockType](#locktype8)                    | Yes  | Lock type.<br>- **1**: PIN lock<br>- **2**: PIN 2 lock|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getLockState(0, 1, (err: BusinessError, data: sim.LockState) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getLockState<sup>8+</sup>

getLockState\(slotId: number, lockType: LockType\): Promise\<LockState\>

Obtains the lock status of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type                  | Mandatory| Description                                   |
| ------- | ---------------------- | ---- | --------------------------------------- |
| slotId  | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2 |
| options | [LockType](#locktype8) | Yes  | Lock type.<br>- **1**: PIN lock<br>- **2**: PIN 2 lock|

**Return value**

| Type                              | Description                                        |
| ---------------------------------- | -------------------------------------------- |
| Promise<[LockState](#lockstate8)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getLockState(0, 1).then((data: sim.LockState) => {
    console.log(`getLockState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin<sup>7+</sup>

alterPin\(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback\<LockStatusResponse\>\): void

Changes the PIN of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                  |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                            |
| newPin   | string                                                      | Yes  | New PIN.                              |
| oldPin   | string                                                      | Yes  | Old PIN.                              |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.alterPin(0, "1234", "0000", (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin<sup>7+</sup>

alterPin\(slotId: number, newPin: string, oldPin: string\): Promise\<LockStatusResponse\>

Changes the PIN of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin | string | Yes  | New PIN.                              |
| oldPin | string | Yes  | Old PIN.                              |

**Return value**

| Type                                                | Description                                         |
| ---------------------------------------------------- | --------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.alterPin(0, "1234", "0000").then((data: sim.LockStatusResponse) => {
    console.log(`alterPin success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`alterPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin2<sup>8+</sup>

alterPin2\(slotId: number, newPin2: string, oldPin2: string, callback: AsyncCallback\<LockStatusResponse\>\): void

Changes PIN 2 of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description                                  |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                            |
| newPin2  | string                                                      | Yes  | New PIN.                              |
| oldPin2  | string                                                      | Yes  | Old PIN.                              |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.alterPin2(0, "1234", "0000", (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin2<sup>8+</sup>

alterPin2\(slotId: number, newPin2: string, oldPin2: string\): Promise\<LockStatusResponse\>

Changes PIN 2 of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type  | Mandatory| Description                                  |
| ------- | ------ | ---- | -------------------------------------- |
| slotId  | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin2 | string | Yes  | New PIN.                              |
| oldPin2 | string | Yes  | Old PIN.                              |

**Return value**

| Type                                                | Description                                         |
| ---------------------------------------------------- | --------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.alterPin2(0, "1234", "0000").then((data: sim.LockStatusResponse) => {
    console.log(`alterPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`alterPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPin<sup>7+</sup>

unlockPin\(slotId: number, pin: string, callback: AsyncCallback\<LockStatusResponse\>\): void

Unlocks the PIN of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin      | string                                                       | Yes  | PIN of the SIM card.                           |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let pin: string = '1234';
sim.unlockPin(0, pin, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPin<sup>7+</sup>

unlockPin\(slotId: number, pin: string\): Promise\<LockStatusResponse\>

Unlocks the PIN of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin    | string | Yes  | PIN of the SIM card.                           |

**Return value**

| Type                                                | Description                                              |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let pin: string = '1234';
sim.unlockPin(0, pin).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPin success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPuk<sup>7+</sup>

unlockPuk\(slotId: number, newPin: string, puk: string, callback: AsyncCallback\<LockStatusResponse\>\): void

Unlocks the PUK of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin   | string                                                       | Yes  | New PIN.                       |
| puk      | string                                                       | Yes  | PUK of the SIM card.                   |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let puk: string = '1xxxxxxx';
let newPin: string = '1235';
sim.unlockPuk(0, newPin, puk, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPuk<sup>7+</sup>

unlockPuk\(slotId: number, newPin: string, puk: string\): Promise\<LockStatusResponse\>

Unlocks the PUK of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin | string | Yes  | New PIN.                       |
| puk    | string | Yes  | PUK of the SIM card.                   |

**Return value**

| Type                                                | Description                                              |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let puk: string = '1xxxxxxx';
let newPin: string = '1235';
sim.unlockPuk(0, newPin, puk).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPuk success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPuk failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPin2<sup>8+</sup>

unlockPin2\(slotId: number, pin2: string, callback: AsyncCallback\<LockStatusResponse\>\): void

Unlocks the PIN of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin2     | string                                                       | Yes  | PIN of the SIM card.                           |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let pin2: string = '1234';
sim.unlockPin2(0, pin2, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPin2<sup>8+</sup>

unlockPin2\(slotId: number, pin2: string\): Promise\<LockStatusResponse\>

Unlocks the PIN of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| pin2   | string | Yes  | PIN of the SIM card.                           |

**Return value**

| Type                                                 | Description                                              |
| ----------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let pin2: string = '1234';
sim.unlockPin2(0, pin2).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPuk2<sup>8+</sup>

unlockPuk2\(slotId: number, newPin2: string, puk2: string, callback: AsyncCallback\<LockStatusResponse\>\): void

Unlocks the PUK of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin2  | string                                                       | Yes  | New PIN 2.                       |
| puk2     | string                                                       | Yes  | PUK of the SIM card.                   |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let puk2: string = '1xxxxxxx';
let newPin2: string = '1235';
sim.unlockPuk2(0, newPin2, puk2, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPuk2<sup>8+</sup>

unlockPuk2\(slotId: number, newPin2: string, puk2: string\): Promise\<LockStatusResponse\>

Unlocks the PUK of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type  | Mandatory| Description                                  |
| ------- | ------ | ---- | -------------------------------------- |
| slotId  | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| newPin2 | string | Yes  | New PIN 2.                       |
| puk2    | string | Yes  | PUK of the SIM card.                   |

**Return value**

| Type                                                | Description                                              |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let puk2: string = '1xxxxxxx';
let newPin2: string = '1235';
sim.unlockPuk2(0, newPin2, puk2).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPuk2 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPuk2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimIccId<sup>7+</sup>

getSimIccId\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the ICCID of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getSimIccId(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimIccId<sup>7+</sup>

getSimIccId\(slotId: number\): Promise\<string\>

Obtains the ICCID of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                       |
| ---------------- | ------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getSimIccId(0).then((data:string) => {
    console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimIccId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the voice mailbox alpha identifier of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getVoiceMailIdentifier(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier\(slotId: number\): Promise\<string\>

Obtains the voice mailbox alpha identifier of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getVoiceMailIdentifier(0).then((data: string) => {
    console.log(`getVoiceMailIdentifier success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getVoiceMailIdentifier failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber\(slotId: number, callback: AsyncCallback\<string\>): void

Obtains the voice mailbox number of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getVoiceMailNumber(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber\(slotId: number\): Promise\<string\>

Obtains the voice mailbox number of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                            |
| ---------------- | ------------------------------------------------ |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getVoiceMailNumber(0).then((data: string) => {
    console.log(`getVoiceMailNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getVoiceMailNumber failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo\(slotId: number, mailName: string, mailNumber: string, callback: AsyncCallback\<void\>\): void

Sets voice mailbox information for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name    | Type                | Mandatory| Description                                  |
| ---------- | -------------------- | ---- | -------------------------------------- |
| slotId     | number               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| mailName   | string               | Yes  | Voice mailbox name.                              |
| mailNumber | string               | Yes  | Voice mailbox number.                             |
| callback   | AsyncCallback<void\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com", (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo\(slotId: number, mailName: string, mailNumber: string\): Promise\<void\>

Sets voice mailbox information for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name    | Type  | Mandatory| Description                                  |
| ---------- | ------ | ---- | -------------------------------------- |
| slotId     | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| mailName   | string | Yes  | Voice mailbox name.                              |
| mailNumber | string | Yes  | Voice mailbox number.                              |

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com").then(() => {
    console.log(`setVoiceMailInfo success.`);
}).catch((err: BusinessError) => {
    console.error(`setVoiceMailInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the MSISDN of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_PHONE_NUMBERS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                  | Mandatory| Description                                  |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<string\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getSimTelephoneNumber(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber\(slotId: number\): Promise\<string\>

Obtains the MSISDN of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_PHONE_NUMBERS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                        |
| ---------------- | -------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getSimTelephoneNumber(0).then((data: string) => {
    console.log(`getSimTelephoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimTelephoneNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimGid1<sup>7+</sup>

getSimGid1\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the group identifier level 1 (GID1) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getSimGid1(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimGid1<sup>7+</sup>

getSimGid1\(slotId: number\): Promise\<string\>

Obtains the GID1 of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getSimGid1(0).then((data: string) => {
    console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimGid1 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getIMSI

getIMSI\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the international mobile subscriber identity (IMSI) of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getIMSI(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getIMSI

getIMSI\(slotId: number\): Promise\<string\>

Obtains the IMSI of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type            | Description                                       |
| ---------------- | ------------------------------------------- |
| Promise<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.getIMSI(0).then((data: string) => {
    console.log(`getIMSI success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getIMSI failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs\(slotId: number, callback: AsyncCallback\<Array\<OperatorConfig\>\>\): void

Obtains the carrier configuration of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                     | Mandatory| Description                                  |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                    | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback<Array<[OperatorConfig](#operatorconfig8)\>> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getOperatorConfigs(0, (err: BusinessError, data: Array<sim.OperatorConfig>) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs\(slotId: number\): Promise\<Array\<OperatorConfig\>\>

Obtains the carrier configuration of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                               | Description                         |
| --------------------------------------------------- | ----------------------------- |
| Promise<Array<[OperatorConfig](#operatorconfig8)\>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getOperatorConfigs(0).then((data: Array<sim.OperatorConfig>) => {
    console.log(`getOperatorConfigs success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getOperatorConfigs failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers\(slotId: number, type: ContactType, callback: AsyncCallback\<Array\<DiallingNumbersInfo\>\>\): void

Queries contact numbers of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.READ_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                      |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type     | [ContactType](#contacttype8)                                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING|
| callback | AsyncCallback<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> | Yes  | Callback used to return the result.                                         |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.queryIccDiallingNumbers(0, 1, (err: BusinessError, data: Array<sim.DiallingNumbersInfo>) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers\(slotId: number, type: ContactType\): Promise\<Array\<DiallingNumbersInfo\>\>

Queries contact numbers of the SIM card in the specified slot. This API uses a promise to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.READ_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type       | Mandatory| Description                                                      |
| ------ | ----------- | ---- | ---------------------------------------------------------- |
| slotId | number      | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type   | [ContactType](#contacttype8)  | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING|

**Return value**

| Type                                                        | Description                          |
| ------------------------------------------------------------ | ------------------------------ |
| Promise<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.queryIccDiallingNumbers(0, 1).then((data:  Array<sim.DiallingNumbersInfo>) => {
    console.log(`queryIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`queryIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void\>\): void

Adds contact numbers to the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |
| callback        | AsyncCallback<void\>                         | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    pin2: "1234"
};
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo\): Promise\<void\>

Adds contact numbers to the SIM card in the specified slot. This API uses a promise to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {
    console.log(`addIccDiallingNumbers success.`);
}).catch((err: BusinessError) => {
    console.error(`addIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void\>\): void

Deletes contact numbers from the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |
| callback        | AsyncCallback<void\>                         | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123,
    pin2: "1234"
};
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo\): Promise\<void\>

Deletes contact numbers from the SIM card in the specified slot. This API uses a promise to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {
    console.log(`delIccDiallingNumbers success.`);
}).catch((err: BusinessError) => {
    console.error(`delIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void\>\): void 

Updates contact numbers for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |
| callback        | AsyncCallback<void\>                         | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123,
    pin2: "1234"
};
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo\): Promise\<void\>

Updates contact numbers for the SIM card in the specified slot. This API uses a promise to return the result.

>**NOTE**
>
>A cache mechanism is available for SIM card contacts. When a contact is added, deleted, or modified, a SIM card contact cache is maintained based on the corresponding card slot ID and contact type. Therefore, when calling **sim.queryIccDiallingNumbers** to query contact numbers, you must pass the card slot ID and contact type to generate a a SIM card contact cache. If no cache is generated, the attempt to call the **sim.addIccDiallingNumbers**, **sim.delIccDiallingNumbers**, or **sim.updateIccDiallingNumbers** API will fail.
>

**System API**: This is a system API.

**Permission required**: ohos.permission.WRITE_CONTACTS

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name         | Type                                        | Mandatory| Description                                                      |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2                    |
| type            | [ContactType](#contacttype8)                 | Yes  | Contact type.<br>- **1**: GENERAL_CONTACT<br>- **2**: FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | Yes  | Contact number information.                                              |

**Return value**

| Type          | Description                         |
| -------------- | ----------------------------- |
| Promise<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123
};
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {
    console.log(`updateIccDiallingNumbers success.`);
}).catch((err: BusinessError) => {
    console.error(`updateIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd\(slotId: number, cmd: string, callback: AsyncCallback\<void\>\): void

Sends an envelope command to the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                | Mandatory| Description                                  |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd      | string               | Yes  | Envelope command.                                  |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                                    |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.sendEnvelopeCmd(0, "ls", (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd\(slotId: number, cmd: string\): Promise\<void\>

Sends an envelope command to the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd    | string | Yes  | Envelope command.                                  |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.sendEnvelopeCmd(0, "ls").then(() => {
    console.log(`sendEnvelopeCmd success.`);
}).catch((err: BusinessError) => {
    console.error(`sendEnvelopeCmd failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd\(slotId: number, cmd: string, callback: AsyncCallback\<void\>\): void

Sends a terminal response command to the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                | Mandatory| Description                                  |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd      | string               | Yes  | Envelope command.                                  |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.sendTerminalResponseCmd(0, "ls", (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd\(slotId: number, cmd: string\): Promise\<void\>

Sends a terminal response command to the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| cmd    | string | Yes  | Envelope command.                                  |

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

sim.sendTerminalResponseCmd(0, "ls").then(() => {
    console.log(`sendTerminalResponseCmd success.`);
}).catch((err: BusinessError) => {
    console.error(`sendTerminalResponseCmd failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.unlockSimLock<sup>8+</sup>

unlockSimLock\(slotId: number, lockInfo: PersoLockInfo, callback: AsyncCallback\<LockStatusResponse\>\): void

Unlocks the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                      | Mandatory| Description                                  |
| -------- | ---------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                     | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| lockInfo | [PersoLockInfo](#persolockinfo8)                           | Yes  | Personalized lock information.                        |
| callback | AsyncCallback<[LockStatusResponse](#lockstatusresponse7)\> | Yes  | Callback used to return the result.                              |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let persoLockInfo: sim.PersoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
sim.unlockSimLock(0, persoLockInfo, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockSimLock<sup>8+</sup>

unlockSimLock\(slotId: number, lockInfo: PersoLockInfo\): Promise\<LockStatusResponse\>

Unlocks the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                            | Mandatory| Description                                  |
| -------- | -------------------------------- | ---- | -------------------------------------- |
| slotId   | number                           | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| lockInfo | [PersoLockInfo](#persolockinfo8) | Yes  | Personalized lock information.                        |

**Return value**

| Type                                                | Description                     |
| ---------------------------------------------------- | ------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
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

let persoLockInfo: sim.PersoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
sim.unlockSimLock(0, persoLockInfo).then((data: sim.LockStatusResponse) => {
    console.log(`unlockSimLock success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockSimLock failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getDsdsMode<sup>11+</sup>

getDsdsMode\(callback: AsyncCallback\<DsdsMode\>\): void

Obtains the Dual Sim Dual Standby (DSDS) mode supported by the device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                       | Mandatory| Description      |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;DsdsMode&gt; | Yes  | Callback used to return the result, which can be:<br>- **0**: DSDS_MODE_V2<br>- **1**: DSDS_MODE_V3<br>- **2**: DSDS_MODE_V5_TDM<br>- **3**: DSDS_MODE_V5_DSDA|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getDsdsMode((err: BusinessError, data: sim.DsdsMode) => {
    if (err) {
        console.error(`getDsdsMode failed, callback: err->${JSON.stringify(err)}`);
    } else {
        console.log(`getDsdsMode success, callback: data->${JSON.stringify(data)}`);
    }
});
```

## sim.getDsdsMode<sup>11+</sup>

getDsdsMode\(\): Promise\<DsdsMode\>

Obtains the Dual Sim Dual Standby (DSDS) mode supported by the device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<DsdsMode\> | Promise used to return the result.<br>- **0**: DSDS_MODE_V2<br>- **1**: DSDS_MODE_V3<br>- **2**: DSDS_MODE_V5_TDM<br>- **3**: DSDS_MODE_V5_DSDA|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let promise = sim.getDsdsMode();
promise.then((data: sim.DsdsMode) => {
    console.log(`getDsdsMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDsdsMode failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimAuthentication<sup>14+</sup>

getSimAuthentication\(slotId: number, authType: AuthType, authData: string\): Promise\<SimAuthenticationResponse\>

Obtains SIM card authentication information. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                            | Mandatory| Description                                  |
| -------- | -------------------------------- | ---- | -------------------------------------- |
| slotId   | number                           | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| authType | [AuthType](#authtype14)          | Yes  | Authentication type.                        |
| authData | string                           | Yes  | Password or other authentication information.                  |

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<[SimAuthenticationResponse](#simauthenticationresponse14)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card.                                 |
| 8300999  | Unknown error.                               |
| 8301002  | An error occurred when operating the SIM card.                              |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimAuthentication(0, sim.AuthType.SIM_AUTH_EAP_SIM_TYPE, "test").then(() => {
    console.log(`getSimAuthentication success.`);
}).catch((err: BusinessError) => {
    console.error(`getSimAuthentication failed, promise: err->${JSON.stringify(err)}`);
});
```

## LockType<sup>8+</sup>

Enumerates lock types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name    | Value  | Description       |
| -------- | ---- | ----------- |
| PIN_LOCK | 1    | SIM card password lock.|
| FDN_LOCK | 2    | Fixed dialing lock. |

## LockState<sup>8+</sup>

Enumerates lock states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name    | Value  | Description      |
| -------- | ---- | ---------- |
| LOCK_OFF | 0    | The lock is off.|
| LOCK_ON  | 1    | The lock is on.|

## PersoLockType<sup>8+</sup>

Enumerates personalized lock types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name        | Value  | Description                                            |
| ------------ | ---- | ------------------------------------------------ |
| PN_PIN_LOCK  | 0    | Personalized network PIN lock. For details, see *3GPP TS 22.022 [33]*.        |
| PN_PUK_LOCK  | 1    | Personalized network PUK lock.                                  |
| PU_PIN_LOCK  | 2    | Personalized network subset PIN lock. For details, see *3GPP TS 22.022 [33]*.    |
| PU_PUK_LOCK  | 3    | Personalized network subset PUK lock.                              |
| PP_PIN_LOCK  | 4    | Personalized service provider PIN lock. For details, see *3GPP TS 22.022 [33]*.  |
| PP_PUK_LOCK  | 5    | Personalized service provider PUK lock.                             |
| PC_PIN_LOCK  | 6    | Personalized corporate PIN lock. For details, see *3GPP TS 22.022 [33]*.        |
| PC_PUK_LOCK  | 7    | Personalized corporate PUK lock.                                   |
| SIM_PIN_LOCK | 8    | Personalized SIM card PIN lock. For details, see *3GPP TS 22.022 [33]*.       |
| SIM_PUK_LOCK | 9    | Personalized SIM card PUK lock.                                  |

## LockStatusResponse<sup>7+</sup>

Defines the personalized lock information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name           | Type  | Mandatory| Description                 |
| --------------- | ------ | ---- | --------------------- |
| result          | number |  Yes | Operation result.     |
| remain          | number |  No | Remaining attempts (can be null).|

## LockInfo<sup>8+</sup>

Defines the personalized lock information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name    |           Type          | Mandatory|   Description  |
| -------- | ------------------------ | ---- | -------- |
| lockType | [LockType](#locktype8)   |  Yes | Lock type.|
| password | string                   |  Yes | Password.  |
| state    | [LockState](#lockstate8) |  Yes | Lock state.|

## PersoLockInfo<sup>8+</sup>

Defines the personalized lock information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name    |               Type              | Mandatory|      Description    |
| -------- | -------------------------------- | ---- | ------------- |
| lockType | [PersoLockType](#persolocktype8) |  Yes | Personalized lock type.|
| password | string                           |  Yes | Password.       |



## OperatorConfig<sup>8+</sup>

Defines the carrier configuration.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name | Type  | Mandatory| Description|
| ----- | ------ | ---- | ---- |
| field | string |  Yes | Field.|
| value | string |  Yes | Value.  |

## DiallingNumbersInfo<sup>8+</sup>

Defines the contact number information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name        | Type  | Mandatory|    Description   |
| ------------ | ------ | ---- | ---------- |
| alphaTag     | string |  Yes | Tag.    |
| number       | string |  Yes | Call transfer number.    |
| recordNumber | number |  No | Record number. If no record number is specified, the value is **undefined** by default.|
| pin2         | string |  No | PIN 2.|

## ContactType<sup>8+</sup>

Enumerates contact types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name           | Value  | Description      |
| --------------- | ---- | ---------- |
| GENERAL_CONTACT | 1    | Common contact number.|
| FIXED_DIALING   | 2    | Fixed dialing number.  |

## OperatorConfigKey<sup>9+</sup>

Enumerates carrier configuration keys.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

|                             Name                       |                             Value                        |         Description        |
| ------------------------------------------------------- | ------------------------------------------------------ | -------------------- |
| KEY_VOICE_MAIL_NUMBER_STRING                            | "voice_mail_number_string"                             | Voice mailbox number.      |
| KEY_IMS_SWITCH_ON_BY_DEFAULT_BOOL                       | "ims_switch_on_by_default_bool"                        | Fixed dialing number.          |
| KEY_HIDE_IMS_SWITCH_BOOL                                | "hide_ims_switch_bool"                                 | Whether to hide the IMS switch.   |
| KEY_VOLTE_SUPPORTED_BOOL                                | "volte_supported_bool"                                 | Whether to support VoLTE. |
| KEY_NR_MODE_SUPPORTED_LIST_INT_ARRAY                    | "nr_mode_supported_list_int_array"                     | List of supported NR modes.  |
| KEY_VOLTE_PROVISIONING_SUPPORTED_BOOL                   | "volte_provisioning_supported_bool"                    | Whether to support VoLTE provisioning. |
| KEY_SS_OVER_UT_SUPPORTED_BOOL                           | "ss_over_ut_supported_bool"                            | Whether SS over UT is supported.  |
| KEY_IMS_GBA_REQUIRED_BOOL                               | "ims_gba_required_bool"                                | Whether GBA is required for IMS.    |
| KEY_UT_PROVISIONING_SUPPORTED_BOOL                      | "ut_provisioning_supported_bool"                       | Whether to support UT provisioning.    |
| KEY_IMS_PREFER_FOR_EMERGENCY_BOOL                       | "ims_prefer_for_emergency_bool"                        | IMS preferences for emergency.     |
| KEY_CALL_WAITING_SERVICE_CLASS_INT                      | "call_waiting_service_class_int"                       | Call waiting service.      |
| KEY_CALL_TRANSFER_VISIBILITY_BOOL                       | "call_transfer_visibility_bool"                        | Call transfer visibility.    |
| KEY_IMS_CALL_DISCONNECT_REASON_INFO_MAPPING_STRING_ARRAY| "ims_call_disconnect_reason_info_mapping_string_array" | List of IMS call disconnection reasons.|
| KEY_FORCE_VOLTE_SWITCH_ON_BOOL                          | "force_volte_switch_on_bool"                           | Whether to forcibly turn on VoLTE.     |
| KEY_ENABLE_OPERATOR_NAME_CUST_BOOL                      | "enable_operator_name_cust_bool"                       | Whether to display the carrier name.|
| KEY_OPERATOR_NAME_CUST_STRING                           | "operator_name_cust_string"                            | Carrier name.        |
| KEY_SPN_DISPLAY_CONDITION_CUST_INT                      | "spn_display_condition_cust_int"                       | SPN display rule.       |
| KEY_PNN_CUST_STRING_ARRAY                               | "pnn_cust_string_array"                                | PLMN name          |
| KEY_OPL_CUST_STRING_ARRAY                               | "opl_cust_string_array"                                | PLMN information of the carrier.    |
| KEY_EMERGENCY_CALL_STRING_ARRAY                         | "emergency_call_string_array"                          | Emergency call list.      |

## DsdsMode<sup>11+</sup>

Enumerates DSDS modes supported by the device.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name              | Value  | Description                       |
| -------------------| ---- | -------------------------- |
| DSDS_MODE_V2       | 0    | DSDS 2.0 mode.     |
| DSDS_MODE_V3       | 1    | DSDS 3.0 mode.     |
| DSDS_MODE_V5_TDM   | 2    | DSDS 5.0 TDM mode. |
| DSDS_MODE_V5_DSDA  | 3    | DSDS 5.0 DSDA mode.|

## OperatorSimCard<sup>11+</sup>

Carrier name.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name               | Value                   | Description     |
| ------------------ | --------------------- | -------- |
| CHINA_TELECOM_CARD | "china_telecom_card"  | SIM card of China Telecom.|

## AuthType<sup>14+</sup>

Enumerates authentication types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name               | Value                   | Description     |
| ------------------ | --------------------- | -------- |
| SIM_AUTH_EAP_SIM_TYPE   | 128  | EAP-SIM authentication.|
| SIM_AUTH_EAP_AKA_TYPE   | 129  | EAP-AKA authentication.|

## SimAuthenticationResponse<sup>14+</sup>

Defines the SIM card authentication response.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name        | Type  | Mandatory|    Description   |
| ------------ | ------ | ---- | ---------- |
| simStatusWord1 | number |  Yes | SIM card status word 1.|
| simStatusWord2 | number |  Yes | SIM card status word 2.|
| response       | string |  Yes | Authentication response.    |
