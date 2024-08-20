# @ohos.telephony.radio (Radio) (System API)

The **radio** module provides basic network search management functions. You can obtain the radio access technology (RAT) used in the CS and PS domains, network status, current network selection mode, ISO country code of the registered network, ID of the slot in which the primary card is located, list of signal strengths of the registered network, carrier name, and IMEI, MEID, and unique device ID of the SIM card in the specified slot. Besides, you can check whether the current device supports 5G\(NR\) and whether the radio service is enabled on the primary SIM card.

>**NOTE**
>
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.telephony.radio (Radio)](js-apis-radio.md).

## Modules to Import

```ts
import { radio } from '@kit.TelephonyKit';
```


## radio.setPrimarySlotId<sup>8+</sup>

setPrimarySlotId\(slotId: number, callback: AsyncCallback\<void\>\): void

Sets the ID of the slot in which the primary card is located. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                 | Mandatory| Description                                  |
| -------- | --------------------- | ---- | -------------------------------------- |
| slotId   | number                | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.         |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.setPrimarySlotId(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`setPrimarySlotId failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setPrimarySlotId success.`);
});
```


## radio.setPrimarySlotId<sup>8+</sup>

setPrimarySlotId\(slotId: number\): Promise\<void\>

Sets the ID of the slot in which the primary card is located. This API uses a promise to return the result.

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

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.setPrimarySlotId(slotId).then(() => {
    console.log(`setPrimarySlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setPrimarySlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getIMEI<sup>8+</sup>

getIMEI\(callback: AsyncCallback\<string\>\): void

Obtains the IMEI of the primary SIM card of the device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                      |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.  If the IMEI does not exist, an empty string is returned.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.getIMEI((err: BusinessError, data: string) => {
    if (err) {
        console.error(`getIMEI failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getIMEI success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getIMEI<sup>8+</sup>

getIMEI\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the IMEI of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                      |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2    |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.  If the IMEI does not exist, an empty string is returned.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getIMEI(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getIMEI failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getIMEI success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getIMEI<sup>8+</sup>

getIMEI\(slotId?: number\): Promise\<string\>

Obtains the IMEI of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                      |
| ----------------- | ------------------------------------------ |
| Promise\<string\> | Promise used to return the result. If the IMEI does not exist, an empty string is returned.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getIMEI(slotId).then((data: string) => {
    console.log(`getIMEI success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getIMEI failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getMEID<sup>8+</sup>

getMEID\(callback: AsyncCallback\<string\>\): void

Obtains the MEID of the SIM card. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description      |
| -------- | ----------------------- | ---- | ---------- |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.  If the MEID does not exist, an empty string is returned.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.getMEID((err: BusinessError, data: string) => {
    if (err) {
        console.error(`getMEID failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getMEID success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getMEID<sup>8+</sup>

getMEID\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the MEID of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.  If the MEID does not exist, an empty string is returned.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getMEID(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getMEID failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getMEID success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getMEID<sup>8+</sup>

getMEID\(slotId?: number\): Promise\<string\>

Obtains the MEID of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                   |
| ----------------- | --------------------------------------- |
| Promise\<string\> | Promise used to return the result. If the MEID does not exist, an empty string is returned.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getMEID(slotId).then((data: string) => {
    console.log(`getMEID success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getMEID failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getUniqueDeviceId<sup>8+</sup>

getUniqueDeviceId\(callback: AsyncCallback\<string\>\): void

Obtains the unique device ID of the primary SIM card of the device. This API uses an asynchronous callback to return the result.

If the device registers with a 3GPP network, an IMEI is returned. If the device registers with a 3GPP2 network, an MEID is returned.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description      |
| -------- | ----------------------- | ---- | ---------- |
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.getUniqueDeviceId((err: BusinessError, data: string) => {
    if (err) {
        console.error(`getUniqueDeviceId failed, callback: err->${JSON.stringify(err)}}`);
        return;
    }
    console.log(`getUniqueDeviceId success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getUniqueDeviceId<sup>8+</sup>

getUniqueDeviceId\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the unique device ID of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

If the device registers with a 3GPP network, an IMEI is returned. If the device registers with a 3GPP2 network, an MEID is returned.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.       |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getUniqueDeviceId(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getUniqueDeviceId failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getUniqueDeviceId success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getUniqueDeviceId<sup>8+</sup>

getUniqueDeviceId\(slotId?: number\): Promise\<string\>

Obtains the unique device ID of the SIM card in the specified slot. This API uses a promise to return the result.

If the device registers with a 3GPP network, an IMEI is returned. If the device registers with a 3GPP2 network, an MEID is returned.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                         |
| ----------------- | --------------------------------------------- |
| Promise\<string\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getUniqueDeviceId(slotId).then((data: string) => {
    console.log(`getUniqueDeviceId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getUniqueDeviceId failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.sendUpdateCellLocationRequest<sup>8+</sup>

sendUpdateCellLocationRequest\(callback: AsyncCallback\<void\>\): void

Sends a cell location update request. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.sendUpdateCellLocationRequest((err: BusinessError) => {
    if (err) {
        console.error(`sendUpdateCellLocationRequest failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`sendUpdateCellLocationRequest success.`);
});
```

## radio.sendUpdateCellLocationRequest<sup>8+</sup>

sendUpdateCellLocationRequest\(slotId: number, callback: AsyncCallback\<void\>\): void

Sends a cell location update request for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.sendUpdateCellLocationRequest(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`sendUpdateCellLocationRequest failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`sendUpdateCellLocationRequest success.`);
});
```

## radio.sendUpdateCellLocationRequest<sup>8+</sup>

sendUpdateCellLocationRequest\(slotId?: number\): Promise\<void\>

Sends a cell location update request for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.sendUpdateCellLocationRequest(slotId).then(() => {
    console.log(`sendUpdateCellLocationRequest success.`);
}).catch((err: BusinessError) => {
    console.error(`sendUpdateCellLocationRequest failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getCellInformation<sup>8+</sup>

getCellInformation\(callback: AsyncCallback\<Array\<CellInformation\>\>\): void

Obtains cell information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                    |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<Array<[CellInformation](#cellinformation8)\>\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.getCellInformation((err: BusinessError, data: Array<radio.CellInformation>) => {
    if (err) {
        console.error(`getCellInformation failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getCellInformation success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getCellInformation<sup>8+</sup>

getCellInformation\(slotId: number, callback: AsyncCallback\<Array\<CellInformation\>\>\): void

Obtains cell information of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<Array<[CellInformation](#cellinformation8)\>\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getCellInformation(slotId, (err: BusinessError, data: Array<radio.CellInformation>) => {
    if (err) {
        console.error(`getCellInformation failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getCellInformation success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getCellInformation<sup>8+</sup>

getCellInformation\(slotId?: number\): Promise\<Array\<CellInformation\>\>

Obtains cell information of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                   | Description                   |
| ------------------------------------------------------- | ----------------------- |
| Promise\<Array<[CellInformation](#cellinformation8)\>\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getCellInformation(slotId).then((data: Array<radio.CellInformation>) => {
    console.log(`getCellInformation success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCellInformation failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.setNetworkSelectionMode

setNetworkSelectionMode\(options: NetworkSelectionModeOptions, callback: AsyncCallback\<void\>\): void

Sets the network selection mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                       | Mandatory| Description              |
| -------- | ----------------------------------------------------------- | ---- | ------------------ |
| options  | [NetworkSelectionModeOptions](#networkselectionmodeoptions) | Yes  | Network selection mode.|
| callback | AsyncCallback\<void\>                                       | Yes  | Callback used to return the result.      |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let networkInformation: radio.NetworkInformation = {
    operatorName: "China Mobile",
    operatorNumeric: "898600",
    state: radio.NetworkInformationState.NETWORK_AVAILABLE,
    radioTech: "CS"
}
let networkSelectionModeOptions: radio.NetworkSelectionModeOptions = {
    slotId: 0,
    selectMode: radio.NetworkSelectionMode.NETWORK_SELECTION_AUTOMATIC,
    networkInformation: networkInformation,
    resumeSelection: true
}
radio.setNetworkSelectionMode(networkSelectionModeOptions, (err: BusinessError) => {
    if (err) {
        console.error(`setNetworkSelectionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setNetworkSelectionMode success.`);
});
```

## radio.setNetworkSelectionMode

setNetworkSelectionMode\(options: NetworkSelectionModeOptions\): Promise\<void\>

Sets the network selection mode. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type                                                       | Mandatory| Description              |
| ------- | ----------------------------------------------------------- | ---- | ------------------ |
| options | [NetworkSelectionModeOptions](#networkselectionmodeoptions) | Yes  | Network selection mode.|

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let networkInformation: radio.NetworkInformation = {
    operatorName: "China Mobile",
    operatorNumeric: "898600",
    state: radio.NetworkInformationState.NETWORK_AVAILABLE,
    radioTech: "CS"
}
let networkSelectionModeOptions: radio.NetworkSelectionModeOptions = {
    slotId: 0,
    selectMode: radio.NetworkSelectionMode.NETWORK_SELECTION_AUTOMATIC,
    networkInformation: networkInformation,
    resumeSelection: true
}
radio.setNetworkSelectionMode(networkSelectionModeOptions).then(() => {
    console.log(`setNetworkSelectionMode success.`);
}).catch((err: BusinessError) => {
    console.error(`setNetworkSelectionMode failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getNetworkSearchInformation

getNetworkSearchInformation\(slotId: number, callback: AsyncCallback\<NetworkSearchResult\>\): void

Obtains network search information of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[NetworkSearchResult](#networksearchresult)\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.getNetworkSearchInformation(0, (err: BusinessError, data: radio.NetworkSearchResult) => {
    if (err) {
        console.error(`getNetworkSearchInformation failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNetworkSearchInformation success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getNetworkSearchInformation

getNetworkSearchInformation\(slotId: number\): Promise\<NetworkSearchResult\>

Obtains network search information of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                                  | Description                   |
| ------------------------------------------------------ | ----------------------- |
| Promise\<[NetworkSearchResult](#networksearchresult)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.getNetworkSearchInformation(0).then((data: radio.NetworkSearchResult) => {
    console.log(`getNetworkSearchInformation success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNetworkSearchInformation failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getNrOptionMode<sup>(deprecated)</sup>

getNrOptionMode\(callback: AsyncCallback\<NrOptionMode\>\): void

Obtains the NR option mode of the SIM card. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 10. You are advised to use [getNROptionMode](#radiogetnroptionmode10).

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                           | Mandatory| Description      |
| -------- | ----------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NrOptionMode](#nroptionmodedeprecated)\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

radio.getNrOptionMode((err: BusinessError, data: radio.NrOptionMode) => {
    if (err) {
        console.error(`getNrOptionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNrOptionMode success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getNrOptionMode<sup>(deprecated)</sup>

getNrOptionMode\(slotId: number, callback: AsyncCallback\<NrOptionMode\>\): void

Obtains the NR option mode of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 10. You are advised to use [getNROptionMode](#radiogetnroptionmode10).

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                           | Mandatory| Description                                  |
| -------- | ----------------------------------------------- | ---- | ------------------------------------- |
| slotId   | number                                          | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[NrOptionMode](#nroptionmodedeprecated)\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNrOptionMode(slotId, (err: BusinessError, data: radio.NrOptionMode) => {
    if (err) {
        console.error(`getNrOptionModecallback failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNrOptionModecallback success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getNrOptionMode<sup>(deprecated)</sup>

getNrOptionMode\(slotId?: number\): Promise\<NrOptionMode\>

Obtains the NR option mode of the SIM card in the specified slot. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 10. You are advised to use [getNROptionMode](#radiogetnroptionmode10-1).

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                              | Description                   |
| -------------------------------------------------- | ----------------------- |
| Promise\<[NrOptionMode](#nroptionmodedeprecated)\> | Promise used to return the result. |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNrOptionMode(slotId).then((data: radio.NrOptionMode) => {
    console.log(`getNrOptionMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNrOptionMode failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.turnOnRadio<sup>7+</sup>

turnOnRadio\(callback: AsyncCallback\<void\>\): void

Turns on the radio function. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.turnOnRadio((err: BusinessError) => {
    if (err) {
        console.error(`turnOnRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOnRadio success.`);
});
```


## radio.turnOnRadio<sup>7+</sup>

turnOnRadio\(slotId: number, callback: AsyncCallback\<void\>\): void

Enables the radio service for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                 | Mandatory| Description                                  |
| -------- | --------------------- | ---- | -------------------------------------- |
| slotId   | number                | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.       |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.turnOnRadio(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`turnOnRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOnRadio success.`);
});
```


## radio.turnOnRadio<sup>7+</sup>

turnOnRadio(slotId?: number): Promise\<void\>

Turns on the radio function for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.turnOnRadio(slotId).then(() => {
    console.log(`turnOnRadio success.`);
}).catch((err: BusinessError) => {
    console.error(`turnOnRadio failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.turnOffRadio<sup>7+</sup>

turnOffRadio\(callback: AsyncCallback\<void\>\): void

Turns off the radio function. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

radio.turnOffRadio((err: BusinessError) => {
    if (err) {
        console.error(`turnOffRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOffRadio success.`);
});
```


## radio.turnOffRadio<sup>7+</sup>

turnOffRadio\(slotId: number, callback: AsyncCallback\<void\>\): void

Disables the radio service for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                 | Mandatory| Description                                  |
| -------- | --------------------- | ---- | -------------------------------------- |
| slotId   | number                | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.turnOffRadio(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`turnOffRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOffRadio success.`);
});
```


## radio.turnOffRadio<sup>7+</sup>

turnOffRadio\(slotId?: number\): Promise\<void\>

Turns off the radio function for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.turnOffRadio(slotId).then(() => {
    console.log(`turnOffRadio success.`);
}).catch((err: BusinessError) => {
    console.error(`turnOffRadio failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.setPreferredNetwork<sup>8+</sup>

setPreferredNetwork\(slotId: number, networkMode: PreferredNetworkMode, callback: AsyncCallback\<void\>\): void

Sets the preferred network of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name     | Type                                          | Mandatory| Description                                  |
| ----------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId      | number                                         | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| networkMode | [PreferredNetworkMode](#preferrednetworkmode8) | Yes  | Preferred network mode.                      |
| callback    | AsyncCallback\<void\>                          | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
let mode: radio.PreferredNetworkMode = radio.PreferredNetworkMode.PREFERRED_NETWORK_MODE_GSM;
radio.setPreferredNetwork(slotId, mode, (err: BusinessError) => {
    if (err) {
        console.error(`setPreferredNetwork failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setPreferredNetwork success.`);
});
```

## radio.setPreferredNetwork<sup>8+</sup>

setPreferredNetwork\(slotId: number, networkMode: PreferredNetworkMode\): Promise\<void\>

Sets the preferred network of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name     | Type                                          | Mandatory| Description                                  |
| ----------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId      | number                                         | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| networkMode | [PreferredNetworkMode](#preferrednetworkmode8) | Yes  | Preferred network mode.|

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                    |
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

let slotId: number = 0;
let mode: radio.PreferredNetworkMode = radio.PreferredNetworkMode.PREFERRED_NETWORK_MODE_GSM;
radio.setPreferredNetwork(slotId, mode).then(() => {
    console.log(`setPreferredNetwork success.`);
}).catch((err: BusinessError) => {
    console.error(`setPreferredNetwork failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getPreferredNetwork<sup>8+</sup>

getPreferredNetwork\(slotId: number, callback: AsyncCallback\<PreferredNetworkMode\>\): void

Obtains the preferred network of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  |                              Type                              | Mandatory| Description                                  |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<[PreferredNetworkMode](#preferrednetworkmode8)\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getPreferredNetwork(slotId, (err: BusinessError, data: radio.PreferredNetworkMode) => {
    if (err) {
        console.error(`getPreferredNetwork failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getPreferredNetwork success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getPreferredNetwork<sup>8+</sup>

getPreferredNetwork\(slotId: number\): Promise\<PreferredNetworkMode\>

Obtains the preferred network of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<[PreferredNetworkMode](#preferrednetworkmode8)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.getPreferredNetwork(slotId).then((data: radio.PreferredNetworkMode) => {
    console.log(`getPreferredNetwork success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getPreferredNetwork failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getImsRegInfo<sup>9+</sup>

getImsRegInfo\(slotId: number, imsType: ImsServiceType, callback: AsyncCallback\<ImsRegInfo\>\): void

Obtains the IMS registration status of the specified IMS service type for the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                      | Mandatory| Description                                  |
| -------- | ------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                     | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| imsType  | [ImsServiceType](#imsservicetype9)         | Yes  | IMS service type.                         |
| callback | AsyncCallback<[ImsRegInfo](#imsreginfo9)\> | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.getImsRegInfo(slotId, mode, (err: BusinessError, data: radio.ImsRegInfo) => {
    if (err) {
        console.error(`getImsRegInfo failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getImsRegInfo success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getImsRegInfo<sup>9+</sup>

getImsRegInfo\(slotId: number, imsType: ImsServiceType\): Promise\<ImsRegInfo\>

Obtains the IMS registration status of the specified IMS service type for the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name | Type                              | Mandatory| Description                                  |
| ------- | ---------------------------------- | ---- | -------------------------------------- |
| slotId  | number                             | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| imsType | [ImsServiceType](#imsservicetype9) | Yes  | IMS service type.                         |

**Return value**

| Type                                 | Description                   |
| ------------------------------------- | ----------------------- |
| Promise\<[ImsRegInfo](#imsreginfo9)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.getImsRegInfo(slotId, mode).then((data: radio.ImsRegInfo) => {
    console.log(`getImsRegInfo success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getImsRegInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.on('imsRegStateChange')<sup>9+</sup>

on\(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback: Callback\<ImsRegInfo\>\): void

Enables listening for **imsRegStateChange** events of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                | Mandatory| Description                                  |
| -------- | ------------------------------------ | ---- | -------------------------------------- |
| type     | string                               | Yes  | IMS registration status change. This field has a fixed value of **imsRegStateChange**.               |
| slotId   | number                               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| imsType  | [ImsServiceType](#imsservicetype9)   | Yes  | IMS service type.                         |
| callback | Callback<[ImsRegInfo](#imsreginfo9)> | Yes  | Callback used to return the result.               |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.on('imsRegStateChange', slotId, mode, (data: radio.ImsRegInfo) => {
    console.log(`on imsRegStateChange success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.off('imsRegStateChange')<sup>9+</sup>

off\(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback?: Callback\<ImsRegInfo\>\): void

Disables listening for **imsRegStateChange** events of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                | Mandatory| Description                                  |
| -------- | ------------------------------------ | ---- | -------------------------------------- |
| type     | string                               | Yes  | IMS registration status change. This field has a fixed value of **imsRegStateChange**.    |
| slotId   | number                               | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| imsType  | [ImsServiceType](#imsservicetype9)   | Yes  | IMS service type.                         |
| callback | Callback<[ImsRegInfo](#imsreginfo9)> | No  | Callback used to return the result.  If it is left unspecified, it indicates the callback for all the events will be unsubscribed. The value must be the same as the value of **callback** in **on('imsRegStateChange')**.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.off('imsRegStateChange', slotId, mode, (data: radio.ImsRegInfo) => {
    console.log(`off imsRegStateChange success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getBasebandVersion<sup>10+</sup>

getBasebandVersion\(slotId: number, callback: AsyncCallback\<string\>\): void

Obtains the device baseband version of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | ------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| callback | AsyncCallback\<string\> | Yes  | Callback used to return the result.             |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                    |
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

let slotId: number = 0;
radio.getBasebandVersion(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getBasebandVersion failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getBasebandVersion success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getBasebandVersion<sup>10+</sup>

getBasebandVersion\(slotId: number\): Promise\<string\>

Obtains the device baseband version of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                    | Mandatory| Description                                 |
| -------- | ----------------------- | ---- | ------------------------------------- |
| slotId   | number                  | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type             | Description                                   |
| ----------------- | -------------------------------------- |
| Promise\<string\> | Promise used to return the result.     |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                    |
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

let slotId: number = 0;
radio.getBasebandVersion(slotId).then((data: string) => {
    console.log(`getBasebandVersion success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getBasebandVersion failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.setNROptionMode<sup>10+</sup>

setNROptionMode\(slotId: number, mode: NROptionMode, callback: AsyncCallback\<void\>\): void

Sets the NR mode of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                             | Mandatory| Description                                  |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                           | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2 |
| mode     | [NROptionMode](#nroptionmode10)                  | Yes  | Enumerates NR selection modes.                         |
| callback | AsyncCallback\<void\>                            | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                    |
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

let slotId: number = 0;
let mode: radio.NROptionMode = radio.NROptionMode.NR_OPTION_NSA_ONLY;
radio.setNROptionMode(slotId, mode, (err: BusinessError) => {
    if (err) {
        console.error(`setNROptionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setNROptionMode success.`);
});
```


## radio.setNROptionMode<sup>10+</sup>

setNROptionMode\(slotId: number, mode: NROptionMode\): Promise\<void\>

Sets the NR mode of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name|              Type              | Mandatory| Description                                  |
| ------ | ------------------------------- | ---- | ------------------------------------- |
| slotId | number                          | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| mode   | [NROptionMode](#nroptionmode10) | Yes  | NR mode.  |

**Return value**

|        Type      |            Description        |
| ----------------- | ----------------------- |
| Promise\<void\>   | Promise used to return the result. |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                     |
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

let slotId: number = 0;
let mode: radio.NROptionMode = radio.NROptionMode.NR_OPTION_NSA_ONLY;
radio.setNROptionMode(slotId, mode).then(() => {
    console.log(`setNROptionMode success`);
}).catch((err: BusinessError) => {
    console.error(`setNROptionMode failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNROptionMode<sup>10+</sup>

getNROptionMode\(slotId: number, callback: AsyncCallback\<NROptionMode\>\): void

Obtains the NR option mode of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  | Type                                             | Mandatory| Description                                  |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                           | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2 |
| callback | AsyncCallback\<[NROptionMode](#nroptionmode10)\> | Yes  | Callback used to return the result.            |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNROptionMode(slotId, (err: BusinessError, data: radio.NROptionMode) => {
    if (err) {
        console.error(`getNROptionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNROptionMode success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getNROptionMode<sup>10+</sup>

getNROptionMode\(slotId: number\): Promise\<NROptionMode\>

Obtains the NR option mode of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | ------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type                                     | Description                   |
| ----------------------------------------- | ----------------------- |
| Promise\<[NROptionMode](#nroptionmode10)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNROptionMode(slotId).then((data: radio.NROptionMode) => {
    console.log(`getNROptionMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNROptionMode failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkCapability<sup>10+</sup>

getNetworkCapability\(slotId: number, type: NetworkCapabilityType, callback: AsyncCallback\<NetworkCapabilityState\>\): void

Obtains the network capability of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  |                              Type                                      | Mandatory| Description                                 |
| -------- | -----------------------------------------------------------------------| ---- | ----------------------------------- |
| slotId   | number                                                                 | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type     | [NetworkCapabilityType](#networkcapabilitytype10)                      | Yes  | Network capability type.                       |
| callback | AsyncCallback\<[NetworkCapabilityState](#networkcapabilitystate10)\>   | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
radio.getNetworkCapability(slotId, type, (err: BusinessError, data: radio.NetworkCapabilityState) => {
    if (err) {
        console.error(`getNetworkCapability failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNetworkCapability success, callback: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkCapability<sup>10+</sup>

getNetworkCapability\(slotId: number, type: NetworkCapabilityType\): Promise\<NetworkCapabilityState\>

Obtains the network capability of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  |                              Type                              | Mandatory| Description                                  |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type     | [NetworkCapabilityType](#networkcapabilitytype10)               | Yes  | Network capability type.                       |

**Return value**

| Type                                                        | Description                   |
| ------------------------------------------------------------- | ----------------------- |
| Promise\<[NetworkCapabilityState](#networkcapabilitystate10)\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
radio.getNetworkCapability(slotId, type).then((data: radio.NetworkCapabilityState) => {
    console.log(`getNetworkCapability success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNetworkCapability failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.setNetworkCapability<sup>10+</sup>

setNetworkCapability\(slotId: number, type: NetworkCapabilityType, state: NetworkCapabilityState,
      callback: AsyncCallback\<void\>\): void

Sets the network capability of the SIM card in the specified slot. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  |                              Type                              | Mandatory| Description                                  |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type     | [NetworkCapabilityType](#networkcapabilitytype10)               | Yes  | Network capability type.                       |
| state    | [NetworkCapabilityState](#networkcapabilitystate10)             | Yes  | Network capability status.                       |
| callback | AsyncCallback\<void\>                                           | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
let state: radio.NetworkCapabilityState = radio.NetworkCapabilityState.SERVICE_CAPABILITY_ON;
radio.setNetworkCapability(slotId, type, state, (err: BusinessError) => {
    if (err) {
        console.error(`setNetworkCapability failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setNetworkCapability success.`);
});
```


## radio.setNetworkCapability<sup>10+</sup>

setNetworkCapability\(slotId: number, type: NetworkCapabilityType, state: NetworkCapabilityState\): Promise\<void\>

Sets the network capability of the SIM card in the specified slot. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  |                              Type                              | Mandatory| Description                                  |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| type     | [NetworkCapabilityType](#networkcapabilitytype10)               | Yes  | Network capability type.                       |
| state    | [NetworkCapabilityState](#networkcapabilitystate10)             | Yes  | Network capability status.                       |

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
let state: radio.NetworkCapabilityState = radio.NetworkCapabilityState.SERVICE_CAPABILITY_ON;
radio.setNetworkCapability(slotId, type, state).then(() => {
    console.log(`setNetworkCapability success`);
}).catch((err: BusinessError) => {
    console.error(`setNetworkCapability failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.factoryReset<sup>11+</sup>

factoryReset\(slotId: number\): Promise\<void\>

Restores the radio service to factory settings. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name  |                              Type                              | Mandatory| Description                                  |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | Yes  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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

let slotId: number = 0;
radio.factoryReset(slotId).then(() => {
    console.log(`factoryReset success`);
}).catch((err: BusinessError) => {
    console.error(`factoryReset failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getIMEISV<sup>12+</sup>

getIMEISV\(slotId: number\): string

Obtains the software version of the SIM card in the specified slot.

**System API**: This is a system API.

**Required permission**: ohos.permission.GET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CoreService

**Parameters**

| Name| Type  | Mandatory| Description                                  |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | No  | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|


**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
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
let slotId: number = 0;
let data: string = radio.getIMEISV(slotId);
console.log(`IMEISV is:` + data);
```

## PreferredNetworkMode<sup>8+</sup>

Enumerates preferred network modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name                                                     | Value  | Description                                         |
| --------------------------------------------------------- | ---- | --------------------------------------------- |
| PREFERRED_NETWORK_MODE_GSM                                | 1    | GSM network mode.                            |
| PREFERRED_NETWORK_MODE_WCDMA                              | 2    | WCDMA network mode.                          |
| PREFERRED_NETWORK_MODE_LTE                                | 3    | LTE network mode.                            |
| PREFERRED_NETWORK_MODE_LTE_WCDMA                          | 4    | LTE+WCDMA network mode.                      |
| PREFERRED_NETWORK_MODE_LTE_WCDMA_GSM                      | 5    | LTE+WCDMA+GSM network mode.                  |
| PREFERRED_NETWORK_MODE_WCDMA_GSM                          | 6    | WCDMA+GSM network mode.                      |
| PREFERRED_NETWORK_MODE_CDMA                               | 7    | CDMA network mode.                           |
| PREFERRED_NETWORK_MODE_EVDO                               | 8    | EVDO network mode.                           |
| PREFERRED_NETWORK_MODE_EVDO_CDMA                          | 9    | EVDO+CDMA network mode.                      |
| PREFERRED_NETWORK_MODE_WCDMA_GSM_EVDO_CDMA                | 10   | WCDMA+GSM+EVDO+CDMA network mode.            |
| PREFERRED_NETWORK_MODE_LTE_EVDO_CDMA                      | 11   | LTE+EVDO+CDMA network mode.                  |
| PREFERRED_NETWORK_MODE_LTE_WCDMA_GSM_EVDO_CDMA            | 12   | LTE+WCDMA+GSM+EVDO+CDMA network mode.        |
| PREFERRED_NETWORK_MODE_TDSCDMA                            | 13   | TD-SCDMA network mode.                        |
| PREFERRED_NETWORK_MODE_TDSCDMA_GSM                        | 14   | TD-SCDMA+GSM network mode.                    |
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA                      | 15   | TD-SCDMA+WCDMA network mode.                  |
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA_GSM                  | 16   | TD-SCDMA+WCDMA+GSM network mode.              |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA                        | 17   | LTE+TD-SCDMA network mode.                    |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_GSM                    | 18   | LTE+TD-SCDMA+GSM network mode.                |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA                  | 19   | LTE+TD-SCDMA+WCDMA network mode.              |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA_GSM              | 20   | LTE+TD-SCDMA+WCDMA+GSM network mode.          |
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA_GSM_EVDO_CDMA        | 21   | TD-SCDMA+WCDMA+GSM+EVDO+CDMA network mode.    |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA_GSM_EVDO_CDMA    | 22   | LTE+TD-SCDMA+WCDMA+GSM+EVDO+CDMA network mode.|
| PREFERRED_NETWORK_MODE_NR                                 | 31   | NR network mode.                             |
| PREFERRED_NETWORK_MODE_NR_LTE                             | 32   | NR+LTE network mode.                         |
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA                       | 33   | NR+LTE+WCDMA network mode.                   |
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA_GSM                   | 34   | NR+LTE+WCDMA+GSM network mode.               |
| PREFERRED_NETWORK_MODE_NR_LTE_EVDO_CDMA                   | 35   | NR+LTE+EVDO+CDMA network mode.               |
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA_GSM_EVDO_CDMA         | 36   | NR+LTE+WCDMA+GSM+EVDO+CDMA network mode.     |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA                     | 37   | NR+LTE+TD-SCDMA network mode.                 |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_GSM                 | 38   | NR+LTE+TD-SCDMA+GSM network mode.             |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA               | 39   | NR+LTE+TD-SCDMA+WCDMA network mode.           |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA_GSM           | 40   | NR+LTE+TD-SCDMA+WCDMA+GSM network mode.       |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA_GSM_EVDO_CDMA | 41   | NR+LTE+TD-SCDMA+WCDMA+GSM+EVDO+CDMA network mode.       |
| PREFERRED_NETWORK_MODE_MAX_VALUE                          | 99   | Maximum value of the preferred network mode.                         |

## CellInformation<sup>8+</sup>

Defines the cell information.

**System capability**: SystemCapability.Telephony.CoreService

| Name             |                  Type                  | Mandatory|                           Description                              |
| ----------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |                           
| isCamped          | boolean                                 |  Yes | Cell status.<br>**System API**: This is a system API.         |
| timeStamp         | number                                  |  Yes | Timestamp when cell information is obtained.<br>**System API**: This is a system API.   |                              
| data              | [CdmaCellInformation](#cdmacellinformation8) \| [GsmCellInformation](#gsmcellinformation8) \| [LteCellInformation](#ltecellinformation8) \| [NrCellInformation](#nrcellinformation8) \| [TdscdmaCellInformation](#tdscdmacellinformation8)\|[WcdmaCellInformation](#wcdmacellinformation8) |  Yes | CDMA cell information\|GSM cell information\|LTE cell information\|NR cell information\|TD-SCDMA cell information\|WCDMA.<br>**System API**: This is a system API.|

## CdmaCellInformation<sup>8+</sup>

Defines the CDMA cell information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| baseId    | number |  Yes | Base station ID.    |
| latitude  | number |  Yes | Latitude.      |
| longitude | number |  Yes | Longitude.      |
| nid       | number |  Yes | Network ID.|
| sid       | number |  Yes | System ID.|

## GsmCellInformation<sup>8+</sup>

Defines the GSM cell information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name  | Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| lac    | number |  Yes | Location area code.        |
| cellId | number |  Yes | Cell ID.            |
| arfcn  | number |  Yes | Absolute radio frequency channel number.|
| bsic   | number |  Yes | Base station ID.        |
| mcc    | string |  Yes | Mobile country code.        |
| mnc    | string |  Yes | Mobile network code.          |

## LteCellInformation<sup>8+</sup>

LTE cell information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name         | Type   | Mandatory| Description                   |
| ------------- | ------- | ---- | ----------------------- |
| cgi           | number  |  Yes | Cell global identification.         |
| pci           | number  |  Yes | Physical cell ID.         |
| tac           | number  |  Yes | Tracking area code.         |
| earfcn        | number  |  Yes | Absolute radio frequency channel number.   |
| bandwidth     | number  |  Yes | Bandwidth.                 |
| mcc           | string  |  Yes | Mobile country code.           |
| mnc           | string  |  Yes | Mobile network code.             |
| isSupportEndc | boolean |  Yes | Whether New Radio Dual Connectivity (NR-DC) is supported.|

## NrCellInformation<sup>8+</sup>

Defines the 5G NR cell information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name   | Type  | Mandatory| Description            |
| ------- | ------ | ---- | ---------------- |
| nrArfcn | number |  Yes | 5G frequency number.      |
| pci     | number |  Yes | Physical cell ID.  |
| tac     | number |  Yes | Tracking area code.  |
| nci     | number |  Yes | 5G network cell ID.|
| mcc     | string |  Yes | Mobile country code.    |
| mnc     | string |  Yes | Mobile network code.      |

## TdscdmaCellInformation<sup>8+</sup>

Defines the TD-SCDMA cell information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name  | Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| lac    | number |  Yes | Location area code.|
| cellId | number |  Yes | Cell ID.    |
| cpid   | number |  Yes | Cell parameter ID.|
| uarfcn | number |  Yes | Absolute radio frequency number.|
| mcc    | string |  Yes | Mobile country code.|
| mnc    | string |  Yes | Mobile network code.  |

## WcdmaCellInformation<sup>8+</sup>

Defines the WCDMA cell information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name  | Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| lac    | number |  Yes | Location area code.|
| cellId | number |  Yes | Cell ID.    |
| psc    | number |  Yes | Primary scrambling code.    |
| uarfcn | number |  Yes | Absolute radio frequency number.|
| mcc    | string |  Yes | Mobile country code.|
| mnc    | string |  Yes | Mobile network code.  |

## NrOptionMode<sup>(deprecated)</sup>

Enumerates NR selection modes.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 10. You are advised to use [NROptionMode](#nroptionmode10).

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name                | Value  | Description                              |
| -------------------- | ---- | ---------------------------------- |
| NR_OPTION_UNKNOWN    | 0    | Unknown NR selection mode.                |
| NR_OPTION_NSA_ONLY   | 1    | NR selection mode in 5G non-standalone networking.        |
| NR_OPTION_SA_ONLY    | 2    | NR selection mode in 5G non-standalone networking.          |
| NR_OPTION_NSA_AND_SA | 3    | NR selection mode in non-standalone and standalone networking.|

## NROptionMode<sup>10+</sup>

Enumerates NR selection modes.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name                | Value  | Description                             |
| -------------------- | ---- | --------------------------------- |
| NR_OPTION_UNKNOWN    | 0    | Unknown NR selection mode.                |
| NR_OPTION_NSA_ONLY   | 1    | NR selection mode in 5G non-standalone networking.        |
| NR_OPTION_SA_ONLY    | 2    | NR selection mode in 5G non-standalone networking.          |
| NR_OPTION_NSA_AND_SA | 3    | NR selection mode in non-standalone and standalone networking. |

## NetworkSearchResult

Defines the network search result.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name                  | Type                                             | Mandatory| Description          |
| ---------------------- | ------------------------------------------------- | ---- | -------------- |
| isNetworkSearchSuccess | boolean                                           |  Yes | Successful network search.|
| networkSearchResult    | Array<[NetworkInformation](#networkinformation)\> |  Yes | Network search result.|

## NetworkInformation

Defines the network information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name           |                         Type                       | Mandatory| Description          |
| --------------- | --------------------------------------------------- | ---- | -------------- |
| operatorName    | string                                              |  Yes | Carrier name.|
| operatorNumeric | string                                              |  Yes | Carrier number.  |
| state           | [NetworkInformationState](#networkinformationstate) |  Yes | Network information status.|
| radioTech       | string                                              |  Yes | Radio access technology.  |

## NetworkInformationState

Enumerates network information states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name             | Value  | Description            |
| ----------------- | ---- | ---------------- |
| NETWORK_UNKNOWN   | 0    | Unknown state.  |
| NETWORK_AVAILABLE | 1    | Available for registration.|
| NETWORK_CURRENT   | 2    | Registered state.|
| NETWORK_FORBIDDEN | 3    | Unavailable for registration.  |

## NetworkSelectionModeOptions

Defines the network selection mode.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name              |                    Type                      | Mandatory|                 Description                  |
| ------------------ | --------------------------------------------- | ---- | -------------------------------------- |
| slotId             | number                                        |  Yes | Card slot ID.<br>- **0**: card slot 1<br>- **1**: card slot 2|
| selectMode         | [NetworkSelectionMode](js-apis-radio.md#networkselectionmode) |  Yes | Network selection mode.                        |
| networkInformation | [NetworkInformation](#networkinformation)     |  Yes | Network information.                            |
| resumeSelection    | boolean                                       |  Yes | Whether to resume selection.                            |

## ImsRegState<sup>9+</sup>

Enumerates IMS registration states.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name            | Value  | Description    |
| ---------------- | ---- | -------- |
| IMS_UNREGISTERED | 0    | Not registered.|
| IMS_REGISTERED   | 1    | Registered.|

## ImsRegTech<sup>9+</sup>

Enumerates IMS registration technologies.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name                   | Value  | Description           |
| ----------------------- | ---- | --------------- |
| REGISTRATION_TECH_NONE  | 0    | None.   |
| REGISTRATION_TECH_LTE   | 1    | LTE.  |
| REGISTRATION_TECH_IWLAN | 2    | I-WLAN.|
| REGISTRATION_TECH_NR    | 3    | NR.   |

## ImsRegInfo<sup>9+</sup>

Defines the IMS registration information.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name       | Type                        | Mandatory| Description         |
| ----------- | ---------------------------- | ---- | ------------- |
| imsRegState | [ImsRegState](#imsregstate9) |  Yes | IMS registration state.|
| imsRegTech  | [ImsRegTech](#imsregtech9)   |  Yes | IMS registration technology.|

## ImsServiceType<sup>9+</sup>

Enumerates IMS service types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name      | Value  | Description      |
| ---------- | ---- | ---------- |
| TYPE_VOICE | 0    | Voice service.|
| TYPE_VIDEO | 1    | Video service.|
| TYPE_UT    | 2    | UT service.  |
| TYPE_SMS   | 3    | SMS service.|

## NetworkCapabilityType<sup>10+</sup>

Enumerates network capability types.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name            | Value  | Description      |
| -----------------| ---- | ---------- |
| SERVICE_TYPE_LTE | 0    | LTE service.|
| SERVICE_TYPE_NR  | 1    | NR service.|

## NetworkCapabilityState<sup>10+</sup>

Defines the network capability switch status.

**System API**: This is a system API.

**System capability**: SystemCapability.Telephony.CoreService

| Name                  | Value  | Description      |
| -----------------------| ---- | ---------- |
| SERVICE_CAPABILITY_OFF | 0    | The network capability is disabled.|
| SERVICE_CAPABILITY_ON  | 1    | The network capability is enabled.|
