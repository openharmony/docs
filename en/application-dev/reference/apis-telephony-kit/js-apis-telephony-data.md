# @ohos.telephony.data (Cellular Data)

The **data** module provides basic mobile data management functions. You can obtain the default slot of the SIM card used for mobile data, and obtain the uplink and downlink connection status of cellular data services and connection status of the packet switched (PS) domain. Besides, you can check whether cellular data services and data roaming are enabled.

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { data } from '@kit.TelephonyKit';
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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { data } from '@kit.TelephonyKit';

console.log("Result: "+ data.getDefaultCellularDataSlotIdSync())
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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.isCellularDataEnabled().then((data: boolean) => {
    console.log(`isCellularDataEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataEnabledSync<sup>12+</sup>

isCellularDataEnabledSync(): boolean

Checks whether the cellular data service is enabled. This API returns the result synchronously.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Whether the cellular data service is enabled.<br>**true**: The cellular data service is enabled.<br>**false**: The cellular data service is disabled.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**Example**

<!--code_no_check-->

```ts
import { data } from '@kit.TelephonyKit';

try {
    let isEnabled: boolean = data.isCellularDataEnabledSync();
    console.log(`isCellularDataEnabledSync success : ${isEnabled}`);
} catch (error) {
    console.error(`isCellularDataEnabledSync fail : err->${JSON.stringify(error)}`);  
}
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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

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
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.isCellularDataRoamingEnabled(0).then((data: boolean) => {
    console.log(`isCellularDataRoamingEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataRoamingEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataRoamingEnabledSync<sup>12+</sup>

isCellularDataRoamingEnabledSync(slotId: number): boolean

Checks whether roaming is enabled for the cellular data service. This API returns the result synchronously.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>**0**: card slot 1.<br>**1**: card slot 2.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Whether roaming is enabled for the cellular data service.<br>**true**: Roaming is enabled for the cellular data service.<br>**false**: Roaming is disabled for the cellular data service.|

**Error codes**

For details about the error codes, see[ohos.telephony (Telephony) Error Codes](errorcode-telephony.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; |
| 8300001  | Invalid parameter value.                                     |
| 8300002  | Operation failed. Cannot connect to service.                 |
| 8300003  | System internal error.                                       |
| 8300999  | Unknown error code.                                          |

**Example**

<!--code_no_check-->

```ts
import { data } from '@kit.TelephonyKit';

try {
    let isEnabled: boolean = data.isCellularDataRoamingEnabledSync(0);
    console.log(`isCellularDataRoamingEnabledSync success : ${isEnabled}`);
} catch (error) {
    console.error(`isCellularDataRoamingEnabledSync fail : err->${JSON.stringify(error)}`);  
}
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
import { data } from '@kit.TelephonyKit';

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
