# Cellular Data

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import data from '@ohos.telephony.data';
```

## data.getDefaultCellularDataSlotId<a name=data.getDefaultCellularDataSlotId-callback></a>

getDefaultCellularDataSlotId(callback: AsyncCallback\<number\>): void 

Obtains the default SIM card used for mobile data. This function uses an asynchronous callback to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<number\> | Yes| Callback used to return the result. <br /> **0**: slot 1 <br/>**1**: slot 2|

**Example**

```
data.getDefaultCellularDataSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.getDefaultCellularDataSlotId<a name=data.getDefaultCellularDataSlotId-promise></a>

getDefaultCellularDataSlotId(): Promise\<number\> 

Obtains the default SIM card used for mobile data. This function uses a promise to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type| Description|
| ----------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result, wherein: <br />**0**: slot 1 <br/>**1**: slot 2|

**Example**

```
let promise = data.getDefaultCellularDataSlotId();
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataFlowType<a name=data.getCellularDataFlowType-callback></a>

getCellularDataFlowType(callback: AsyncCallback\<DataFlowType\>): void

Obtains the cellular data flow type, which can be uplink or downlink. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[DataFlowType](#DataFlowType)\> | Yes| Callback used to return the result.|

**Example**

```
data.getCellularDataFlowType((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.getCellularDataFlowType<a name=data.getCellularDataFlowType-promise></a>

getCellularDataFlowType(): Promise\<DataFlowType\>

Obtains the cellular data flow type, which can be uplink or downlink. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type| Description|
| ---------------------------------------- | ----------------------------------------------- |
| Promise\<[DataFlowType](#DataFlowType)\> | Promise used to return the result. |

**Example**

```
let promise = data.getCellularDataFlowType();
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataState<a name=data.getCellularDataState-callback></a>

getCellularDataState(callback: AsyncCallback\<DataConnectState\>): void

Obtains the connection status of the packet switched (PS) domain. This function uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#DataConnectState)\> | Yes| Callback used to return the result.|

**Example**

```
data.getCellularDataState((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.getCellularDataState<a name=data.getCellularDataState-promise></a>

getCellularDataState(): Promise\<DataConnectState\>

Obtains the connection status of the PS domain. This function uses a promise to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type| Description|
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[DataConnectState](#DataConnectState)\> | Promise used to return the result.|

**Example**

```
let promise = data.getCellularDataState();
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataEnabled<a name=data.isCellularDataEnabled-callback></a>

isCellularDataEnabled(callback: AsyncCallback\<boolean\>): void

Checks whether the cellular data service is enabled. This function uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean\> | Yes| Callback used to return the result. <br />**true**: The cellular data service is enabled. <br />**false**: The cellular data service is disabled.|

**Example**

```
data.isCellularDataEnabled((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.isCellularDataEnabled<a name=data.isCellularDataEnabled-promise></a>

isCellularDataEnabled(): Promise\<boolean\>

Checks whether the cellular data service is enabled. This function uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type| Description|
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result, wherein: <br />**true**: The cellular data service is enabled. <br />**false**: The cellular data service is disabled.|

**Example**

```
let promise = data.isCellularDataEnabled();
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataRoamingEnabled<a name=data.isCellularDataRoamingEnabled-callback></a>

isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback\<boolean\>): void

Checks whether roaming is enabled for the cellular data service. This function uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                   | Yes| Card slot ID. The options are as follows: <br />**0**: slot 1 <br />**1**: slot 2|
| callback | AsyncCallback\<boolean\> | Yes| Callback used to return the result. <br />**true**: Roaming is enabled for the cellular data service. <br />**false**: Roaming is disabled for the cellular data service.|

**Example**

```
data.isCellularDataRoamingEnabled(0,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.isCellularDataRoamingEnabled<a name=data.isCellularDataRoamingEnabled-promise></a>

isCellularDataRoamingEnabled(slotId: number): Promise\<boolean\>

Checks whether roaming is enabled for the cellular data service. This method uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes| Card slot ID. The options are as follows: <br />**0**: slot 1 <br/>**1**: slot 2|

**Return value**

| Type| Description|
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result, wherein: <br />**true**: Roaming is enabled for the cellular data service. <br />**false**: Roaming is disabled for the cellular data service.|

**Example**

```
let promise = data.isCellularDataRoamingEnabled(0);
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## DataFlowType<a name=DataFlowType></a>

 Defines the cellular data flow type.

| Name| Value| Description|
| ------ | ---------------------- | ------------------------------------------------------------ |
| 0      | DATA_FLOW_TYPE_NONE    | No uplink or downlink data is available. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 1      | DATA_FLOW_TYPE_DOWN    | Only the downlink data is available. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 2      | DATA_FLOW_TYPE_UP      | Only the uplink data is available. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 3      | DATA_FLOW_TYPE_UP_DOWN | Both uplink data and downlink data are available. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 4      | DATA_FLOW_TYPE_DORMANT | No uplink or downlink data is available because the lower-layer link is in the dormant state. <br />**System capability**: SystemCapability.Telephony.CellularData|

## DataConnectState<a name=DataConnectState></a>

 Describes the connection status of a cellular data link.

| Name| Value| Description|
| ------ | ----------------------- | ------------------------------------------------------------ |
| -1     | DATA_STATE_UNKNOWN| The status of the cellular data link is unknown. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 0      | DATA_STATE_DISCONNECTED | The cellular data link is disconnected. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 1      | DATA_STATE_CONNECTING   | The cellular data link is being connected. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 2      | DATA_STATE_CONNECTED    | The cellular data link is connected. <br />**System capability**: SystemCapability.Telephony.CellularData|
| 3      | DATA_STATE_SUSPENDED    | The cellular data link is suspended. <br />**System capability**: SystemCapability.Telephony.CellularData|
