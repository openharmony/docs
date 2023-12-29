# @ohos.telephony.data (Cellular Data)

The **data** module provides basic mobile data management functions. You can obtain and set the default slot of the SIM card used for mobile data, and obtain the uplink and downlink connection status of cellular data services and connection status of the packet switched (PS) domain. Besides, you can check whether cellular data services and data roaming are enabled.

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import data from '@ohos.telephony.data';
```

## data.getDefaultCellularDataSlotId

getDefaultCellularDataSlotId(callback: AsyncCallback\<number\>): void 

Obtains the default slot of the SIM card used for mobile data. This API uses an asynchronous callback to return the result. 

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                   | Mandatory| Description                                      |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.<br>**0**: card slot 1.<br>**1**: card slot 2.|

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.getDefaultCellularDataSlotId((err: BusinessError, data: number) => {
    if(err){
        console.error(`getDefaultCellularDataSlotId fail,callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    }else{
        console.log(`getDefaultCellularDataSlotId success`);
    }
});
```

## data.getDefaultCellularDataSlotId

getDefaultCellularDataSlotId(): Promise\<number\> 

Obtains the default slot of the SIM card used for mobile data. This API uses a promise to return the result. 

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.<br>**0**: card slot 1.<br>**1**: card slot 2.|

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.getDefaultCellularDataSlotId().then((data: number) => {
    console.log(`getDefaultCellularDataSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getDefaultCellularDataSlotIdSync<sup>9+</sup>

getDefaultCellularDataSlotIdSync(): number

Obtains the default SIM card used for mobile data synchronously.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                                        |
| ------ | -------------------------------------------------- |
| number | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.|

**Example**

```ts
import data from '@ohos.telephony.data';

console.log("Result: "+ data.getDefaultCellularDataSlotIdSync())
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
| slotId   | number                | Yes  | SIM card slot ID. <br>- **0**: card slot 1.<br>- **1**: card slot 2.<br>- **-1**: Clears the default configuration.|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |
| 8301001  | SIM card is not activated.                   |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1.<br>- **1**: card slot 2.<br>- **-1**: Clears the default configuration.|

**Return value**

| Type           | Description                           |
| --------------- | ------------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |
| 8301001  | SIM card is not activated.                   |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.setDefaultCellularDataSlotId(0).then(() => {
    console.log(`setDefaultCellularDataSlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataFlowType

getCellularDataFlowType(callback: AsyncCallback\<DataFlowType\>): void

Obtains the cellular data flow type, which can be uplink or downlink. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                                          | Mandatory| Description      |
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[DataFlowType](#dataflowtype)\> | Yes  | Callback used to return the result.|

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.getCellularDataFlowType((err: BusinessError, data: data.DataFlowType) => {
    if(err){
        console.error(`getCellularDataFlowType fail,callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    }else{
        console.log(`getCellularDataFlowType success`);
    }
});
```

## data.getCellularDataFlowType

getCellularDataFlowType(): Promise\<DataFlowType\>

Obtains the cellular data flow type, which can be uplink or downlink. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type                                    | Description                                           |
| ---------------------------------------- | ----------------------------------------------- |
| Promise\<[DataFlowType](#dataflowtype)\> | Promise used to return the result. |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.getCellularDataFlowType().then((data: data.DataFlowType) => {
    console.log(`getCellularDataFlowType success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCellularDataFlowType fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataState

getCellularDataState(callback: AsyncCallback\<DataConnectState\>): void

Obtains the connection status of the packet switched (PS) domain. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#dataconnectstate)\> | Yes  | Callback used to return the result.|

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.getCellularDataState((err: BusinessError, data: data.DataConnectState) => {
    if(err){
        console.error(`getCellularDataState fail,callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    }else{
        console.log(`getCellularDataState success`);
    }
});
```

## data.getCellularDataState

getCellularDataState(): Promise\<DataConnectState\>

Obtains the connection status of the PS domain. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type                                            | Description                                 |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[DataConnectState](#dataconnectstate)\> | Promise used to return the result.|

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.getCellularDataState().then((data: data.DataConnectState) => {
    console.log(`getCellularDataState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCellularDataState fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataEnabled

isCellularDataEnabled(callback: AsyncCallback\<boolean\>): void

Checks whether the cellular data service is enabled. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.<br>**true**: The cellular data service is enabled.<br>**false**: The cellular data service is disabled.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.isCellularDataEnabled((err: BusinessError, data: boolean) => {
    if(err){
        console.error(`isCellularDataEnabled fail,callback: callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    }else{
        console.log(`isCellularDataEnabled success`);
    }
});
```

## data.isCellularDataEnabled

isCellularDataEnabled(): Promise\<boolean\>

Checks whether the cellular data service is enabled. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.<br>**true**: The cellular data service is enabled.<br>**false**: The cellular data service is disabled.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.isCellularDataEnabled().then((data: boolean) => {
    console.log(`isCellularDataEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataRoamingEnabled

isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback\<boolean\>): void

Checks whether roaming is enabled for the cellular data service. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                   | Yes  | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.<br>**true**: Roaming is enabled for the cellular data service.<br>**false**: Roaming is disabled for the cellular data service.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.isCellularDataRoamingEnabled(0, (err: BusinessError, data: boolean) => {
    if(err){
        console.error(`isCellularDataRoamingEnabled fail,callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    }else{
        console.log(`isCellularDataRoamingEnabled success`);
    }
});
```

## data.isCellularDataRoamingEnabled

isCellularDataRoamingEnabled(slotId: number): Promise\<boolean\>

Checks whether roaming is enabled for the cellular data service. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.<br>**true**: Roaming is enabled for the cellular data service.<br>**false**: Roaming is disabled for the cellular data service.|

**Error codes**

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.isCellularDataRoamingEnabled(0).then((data: boolean) => {
    console.log(`isCellularDataRoamingEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataRoamingEnabled fail, promise: err->${JSON.stringify(err)}`);
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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

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

For details about the following error codes, see [Telephony Error Codes](../../reference/errorcodes/errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

```ts
import data from '@ohos.telephony.data';
import { BusinessError } from '@ohos.base';

data.disableCellularDataRoaming(0).then(() => {
    console.log(`disableCellularDataRoaming success.`);
}).catch((err: BusinessError) => {
    console.error(`disableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getDefaultCellularDataSimId<sup>10+</sup>

getDefaultCellularDataSimId(): number

Obtains the default ID of the SIM card used for mobile data.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                                        |
| ------ | -------------------------------------------------- |
| number | Obtains the default ID of the SIM card used for mobile data.<br>The return value is bound to the SIM card and increases from 1.|

**Example**

```ts
import data from '@ohos.telephony.data';

console.log("Result: "+ data.getDefaultCellularDataSimId());
```

## DataFlowType

Defines the cellular data flow type.

**System capability**: SystemCapability.Telephony.CellularData

| Name                  | Value  | Description                                      |
| ---------------------- | ---- | ------------------------------------------ |
| DATA_FLOW_TYPE_NONE    | 0    | No uplink or downlink data is available.                  |
| DATA_FLOW_TYPE_DOWN    | 1    | Only the downlink data is available.                        |
| DATA_FLOW_TYPE_UP      | 2    | Only the uplink data is available.                        |
| DATA_FLOW_TYPE_UP_DOWN | 3    | Both the uplink data and downlink data are available.                        |
| DATA_FLOW_TYPE_DORMANT | 4    | No uplink or downlink data is available because the lower-layer link is in the dormant state.|

## DataConnectState

Describes the connection status of a cellular data link.

**System capability**: SystemCapability.Telephony.CellularData

| Name                   | Value  | Description                      |
| ----------------------- | ---- | -------------------------- |
| DATA_STATE_UNKNOWN      | -1   | The status of the cellular data link is unknown.    |
| DATA_STATE_DISCONNECTED | 0    | The cellular data link is disconnected.    |
| DATA_STATE_CONNECTING   | 1    | The cellular data link is being connected.|
| DATA_STATE_CONNECTED    | 2    | The cellular data link is connected.  |
| DATA_STATE_SUSPENDED    | 3    | The cellular data link is suspended.  |
