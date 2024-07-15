# @ohos.telephony.data (Cellular Data) (System API)

The **data** module provides basic mobile data management functions. With the APIs provided by this module, you can set the default slot of the SIM card used for cellular data services and enable or disable cellular data services and data roaming.

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
>This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.telephony.data (Cellular Data)](js-apis-telephony-data.md).


## Modules to Import

```ts
import { data } from '@kit.TelephonyKit';
```


## data.setDefaultCellularDataSlotId

setDefaultCellularDataSlotId(slotId: number, callback: AsyncCallback\<void\>): void 

Sets the default slot of the SIM card used for mobile data. This API uses an asynchronous callback to return the result. 

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                | Yes  | SIM card slot ID. <br>- **0**: card slot 1.<br>- **1**: card slot 2.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                                                  |

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.setDefaultCellularDataSlotId(0, (err: BusinessError) => {
    if(err){
        console.error(`setDefaultCellularDataSlotId fail,callback: err->${JSON.stringify(err)}.`);
    }else{
        console.log(`setDefaultCellularDataSlotId success`);
    }
});
```

## data.setDefaultCellularDataSlotId

setDefaultCellularDataSlotId(slotId: number): Promise\<void\> 

Sets the default slot of the SIM card used for mobile data. This API uses a promise to return the result. 

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1.<br>- **1**: card slot 2.|

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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                            |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |
| 8301001  | SIM card is not activated.                   |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.setDefaultCellularDataSlotId(0).then(() => {
    console.log(`setDefaultCellularDataSlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```


## data.enableCellularData

enableCellularData(callback: AsyncCallback\<void\>): void

Enables the cellular data service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.enableCellularData((err: BusinessError) => {
    if(err){
        console.error(`enableCellularData fail,callback: callback: err->${JSON.stringify(err)}`);
    }else{
        console.log(`enableCellularData success`);
    }
});
```

## data.enableCellularData

enableCellularData(): Promise\<void\>

Enables the cellular data service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

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
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.enableCellularData().then(() => {
    console.log(`enableCellularData success.`);
}).catch((err: BusinessError) => {
    console.error(`enableCellularData fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.disableCellularData

disableCellularData(callback: AsyncCallback\<void\>): void

Disables the cellular data service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.disableCellularData((err: BusinessError) => {
    if(err){
        console.error(`disableCellularData fail,callback: callback: err->${JSON.stringify(err)}`);
    }else{
        console.log(`disableCellularData success`);
    }
});
```

## data.disableCellularData

disableCellularData(): Promise\<void\>

Disables the cellular data service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type           | Description                       |
| --------------- | --------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.disableCellularData().then(() => {
    console.log(`disableCellularData success.`);
}).catch((err: BusinessError) => {
    console.error(`disableCellularData fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.enableCellularDataRoaming

enableCellularDataRoaming(slotId: number, callback: AsyncCallback\<void\>): void

Enables the cellular data roaming service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description                                    |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | Yes  | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                              |

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.enableCellularDataRoaming(0, (err: BusinessError) => {
    if(err){
        console.error(`enableCellularDataRoaming fail,callback: err->${JSON.stringify(err)}`);
    }else{
        console.log(`enableCellularDataRoaming success`);
    }
});
```

## data.enableCellularDataRoaming

enableCellularDataRoaming(slotId: number): Promise\<void\>

Enables the cellular data roaming service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.|

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.enableCellularDataRoaming(0).then(() => {
    console.log(`enableCellularDataRoaming success.`);
}).catch((err: BusinessError) => {
    console.error(`enableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.disableCellularDataRoaming

disableCellularDataRoaming(slotId: number, callback: AsyncCallback\<void\>): void

Disables the cellular data roaming service. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description                                    |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | Yes  | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                              |

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.disableCellularDataRoaming(0, (err: BusinessError) => {
    if(err){
        console.error(`disableCellularDataRoaming fail,callback: err->${JSON.stringify(err)}`);
    }else{
        console.log(`disableCellularDataRoaming success`);
    }
});
```

## data.disableCellularDataRoaming

disableCellularDataRoaming(slotId: number): Promise\<void\>

Disables the cellular data roaming service. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.|

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.disableCellularDataRoaming(0).then(() => {
    console.log(`disableCellularDataRoaming success.`);
}).catch((err: BusinessError) => {
    console.error(`disableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
});
```
