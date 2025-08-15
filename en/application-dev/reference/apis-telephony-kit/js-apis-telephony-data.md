# @ohos.telephony.data (Cellular Data)

The **data** module provides basic mobile data management functions. With the APIs provided by this module, you can obtain the default slot of the SIM card used for mobile data, obtain the cellular data flow type and connection status, and check whether cellular data and roaming are enabled.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

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
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getDefaultCellularDataSlotId((err: BusinessError, contextData: number) => {
    if(err){
        console.error(`getDefaultCellularDataSlotId fail,callback: err->${JSON.stringify(err)}, contextData->${JSON.stringify(contextData)}`);
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
| Promise\<number\> | Promise used to return the result.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getDefaultCellularDataSlotId().then((contextData: number) => {
    console.log(`getDefaultCellularDataSlotId success, promise: contextData->${JSON.stringify(contextData)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getDefaultCellularDataSlotIdSync<sup>9+</sup>

getDefaultCellularDataSlotIdSync(): number

Card slot ID.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                                        |
| ------ | -------------------------------------------------- |
| number | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

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

data.getCellularDataFlowType((err: BusinessError, contextData: data.DataFlowType) => {
    if(err){
        console.error(`getCellularDataFlowType fail,callback: err->${JSON.stringify(err)}, contextData->${JSON.stringify(contextData)}`);
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

data.getCellularDataFlowType().then((contextData: data.DataFlowType) => {
    console.log(`getCellularDataFlowType success, promise: contextData->${JSON.stringify(contextData)}`);
}).catch((err: BusinessError) => {
    console.error(`getCellularDataFlowType fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataState

getCellularDataState(callback: AsyncCallback\<DataConnectState\>): void

Obtains the cellular data connection status. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#dataconnectstate)\> | Yes  | Callback used to return the result.|

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getCellularDataState((err: BusinessError, contextData: data.DataConnectState) => {
    if(err){
        console.error(`getCellularDataState fail,callback: err->${JSON.stringify(err)}, contextData->${JSON.stringify(contextData)}`);
    }else{
        console.log(`getCellularDataState success`);
    }
});
```

## data.getCellularDataState

getCellularDataState(): Promise\<DataConnectState\>

Obtains the cellular data connection status. This API uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type                                            | Description                                 |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[DataConnectState](#dataconnectstate)\> | Promise used to return the result.|

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getCellularDataState().then((contextData: data.DataConnectState) => {
    console.log(`getCellularDataState success, promise: contextData->${JSON.stringify(contextData)}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Internal error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.isCellularDataEnabled((err: BusinessError, contextData: boolean) => {
    if(err){
        console.error(`isCellularDataEnabled fail,callback: callback: err->${JSON.stringify(err)}, contextData->${JSON.stringify(contextData)}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                 Error Message                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Internal error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.isCellularDataEnabled().then((contextData: boolean) => {
    console.log(`isCellularDataEnabled success, promise: contextData->${JSON.stringify(contextData)}`);
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Internal error.                          |

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
| slotId   | number                   | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.<br>**true**: Roaming is enabled for the cellular data service.<br>**false**: Roaming is disabled for the cellular data service.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Internal error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.isCellularDataRoamingEnabled(0, (err: BusinessError, contextData: boolean) => {
    if(err){
        console.error(`isCellularDataRoamingEnabled fail,callback: err->${JSON.stringify(err)}, contextData->${JSON.stringify(contextData)}`);
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
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.<br>**true**: Roaming is enabled for the cellular data service.<br>**false**: Roaming is disabled for the cellular data service.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID|                  Error Message                   |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Internal error.                               |

**Example**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.isCellularDataRoamingEnabled(0).then((contextData: boolean) => {
    console.log(`isCellularDataRoamingEnabled success, promise: contextData->${JSON.stringify(contextData)}`);
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
| slotId | number | Yes  | Card slot ID.<br>- **0**: card slot 1.<br>- **1**: card slot 2|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Whether roaming is enabled for the cellular data service.<br>**true**: Roaming is enabled for the cellular data service.<br>**false**: Roaming is disabled for the cellular data service.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Telephony Error Codes](errorcode-telephony.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 8300001  | Invalid parameter value.                                     |
| 8300002  | Operation failed. Cannot connect to service.                 |
| 8300003  | System internal error.                                       |
| 8300999  | Internal error.                                          |

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

## data.queryAllApns<sup>16+</sup>

queryAllApns(): Promise\<Array\<ApnInfo\>\>

Obtains the access point name (APN) of the default SIM card used for mobile data. This API returns the result asynchronously.

**Required permissions**: ohos.permission.MANAGE_APN_SETTING (Restricted permission used only to connect to the mobile data private network for office tasks. For details, see [Restricted Permissions](../../security/AccessToken/restricted-permissions.md#ohospermissionmanage_apn_setting).)

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                        |
| ------ |--------------------------------------------|
| Promise\<Array\<[ApnInfo](#apninfo16)\>\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**Example**

```ts
import { data } from '@kit.TelephonyKit';

data.queryAllApns().then((data: Array<data.ApnInfo>) => {
    console.info(`queryAllApns success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`queryAllApns failed, promise: err->${JSON.stringify(err)}`);
});
```

## data.queryApnIds<sup>16+</sup>

queryApnIds(apnInfo: ApnInfo): Promise\<Array\<number\>\>

Obtains the APN ID corresponding to the specified **ApnInfo**. This API returns the result asynchronously.

**Required permissions**: ohos.permission.MANAGE_APN_SETTING (Restricted permission used only to connect to the mobile data private network for office tasks. For details, see [Restricted Permissions](../../security/AccessToken/restricted-permissions.md#ohospermissionmanage_apn_setting).)

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| apnInfo | [ApnInfo](#apninfo16) | Yes  | APN to query.|


**Return value**

| Type             | Description                         |
| ------ |-----------------------------|
| Promise\<Array\<number\>\> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**Example**

```ts
import { data } from '@kit.TelephonyKit';

let apnInfo: data.ApnInfo;
apnInfo = {
  apnName: "CMNET",
  apn: "cmnet",
  mcc: "460",
  mnc: "07",
};

data.queryApnIds(apnInfo).then((data: Array<number>) => {
    console.info(`queryApnIds success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`queryApnIds failed, promise: err->${JSON.stringify(err)}`);
});
```

## data.setPreferredApn<sup>16+</sup>

setPreferredApn(apnId: number): Promise\<boolean\>

Sets the APN corresponding to the specified **apnId** as the preferred APN. This API returns the result asynchronously.

> **NOTE**
>
> If the input APN ID is invalid, the default preferred APN configured by the carrier is used.

**Required permissions**: ohos.permission.MANAGE_APN_SETTING (Restricted permission used only to connect to the mobile data private network for office tasks. For details, see [Restricted Permissions](../../security/AccessToken/restricted-permissions.md#ohospermissionmanage_apn_setting).)

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| apnId | number | Yes  | APN ID, which can be obtained by calling [queryApnIds](#dataqueryapnids16).|

**Return value**

| Type             | Description                    |
| ------ |------------------------|
| Promise\<boolean\> | Promise used to return the result. If no SIM card is installed, the value **false** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**Example**

```ts
import { data } from '@kit.TelephonyKit';

let apnId: number = 0; // apnId is a valid value returned by queryApnIds. If an invalid APN ID is passed to setPreferredApn, the default preferred APN configured by the carrier is used.
data.setPreferredApn(apnId).then((data: boolean) => {
    console.info(`setPreferredApn success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`setPreferredApn failed, promise: err->${JSON.stringify(err)}`);
});
```

## data.getActiveApnName<sup>20+</sup>

getActiveApnName(): Promise\<string\>

Obtains the access point name (APN) of the default SIM card used for mobile data. This API returns the result asynchronously.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                        |
| ------ |--------------------------------------------|
| Promise\<string\> | Promise used to return the result. If mobile data is not activated, an empty string is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**Example**

```ts
import { data } from '@kit.TelephonyKit';

data.getActiveApnName().then((data: string) => {
    console.info(`getActiveApnName success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getActiveApnName failed, promise: err->${JSON.stringify(err)}`);
});
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

## ApnInfo<sup>16+</sup>

Defines the APN information.

**System capability**: SystemCapability.Telephony.CellularData

| Name      | Type     | Read-Only   |  Optional     | Description        |
|------------|----------|---------|------------|-------------|
| apnName   | string     | No     | No        | APN name.   |
| apn       | string     | No     | No        | APN.       |
| mcc       | string     | No     | No        | Mobile country code (MCC) of the SIM card.|
| mnc       | string     | No     | No        | Mobile network code (MNC) of the SIM card.|
| user      | string     | No     | Yes        | User name.    |
| type      | string     | No     | Yes        | APN type.   |
| proxy     | string     | No     | Yes        | Proxy address.  |
| mmsproxy  | string     | No     | Yes        | Multimedia messaging service (MMS) proxy.  |
