# Cellular Data

The cellular data module provides basic mobile data management functions. You can obtain and set the default slot of the SIM card used for mobile data, and obtain the uplink and downlink connection status of cellular data services and connection status of the packet switched (PS) domain. Besides, you can check whether cellular data services and data roaming are enabled.

>**NOTE**
>
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import data from '@ohos.telephony.data';
```

## data.getDefaultCellularDataSlotId

getDefaultCellularDataSlotId(callback: AsyncCallback\<number\>): void 

Obtains the default slot of the SIM card used for mobile data. This API uses an asynchronous callback to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                   | Mandatory| Description                                      |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<number\> | Yes  | Callback used to return the result.<br>**0**: card slot 1<br>**1**: card slot 2|

**Example**

```js
data.getDefaultCellularDataSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.getDefaultCellularDataSlotId

getDefaultCellularDataSlotId(): Promise\<number\> 

Obtains the default slot of the SIM card used for mobile data. This API uses a promise to return the result. 

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<number\> | Promise used to return the result.<br>**0**: card slot 1<br>**1**: card slot 2|

**Example**

```js
let promise = data.getDefaultCellularDataSlotId();
promise.then((data) => {
    console.log(`getDefaultCellularDataSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`getDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getDefaultCellularDataSlotIdSync

getDefaultCellularDataSlotIdSync(): number

Obtains the default SIM card used for mobile data synchronously.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type             | Description                                                        |
| ------ | -------------------------------------------------- |
| number | Card slot ID.<br>**0**: card slot 1<br>**1**: card slot 2|

**Example**

```js
console.log("Result: "+ data.getDefaultCellularDataSlotIdSync())
```


## data.setDefaultCellularDataSlotId

setDefaultCellularDataSlotId(slotId: number, callback: AsyncCallback\<void\>): void 

Sets the default slot of the SIM card used for mobile data. This API uses an asynchronous callback to return the result. 

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description                                                        |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: clearing the default configuration|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result. |

**Example**

```js
data.setDefaultCellularDataSlotId(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.setDefaultCellularDataSlotId

setDefaultCellularDataSlotId(slotId: number): Promise\<void\> 

Sets the default slot of the SIM card used for mobile data. This API uses a promise to return the result. 

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | Yes  | SIM card slot ID. <br>- **0**: card slot 1<br>- **1**: card slot 2<br>- **-1**: clearing the default configuration|

**Return value**

| Type          | Description                           |
| -------------- | ------------------------------- |
| Promise<\void\> | Promise used to return the result. |

**Example**

```js
let promise = data.setDefaultCellularDataSlotId(0);
promise.then((data) => {
    console.log(`setDefaultCellularDataSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
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

```js
data.getCellularDataFlowType((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
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

```js
let promise = data.getCellularDataFlowType();
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataState

getCellularDataState(callback: AsyncCallback\<DataConnectState\>): void

Obtains the connection status of the PS domain. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                                                  | Mandatory| Description      |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#dataconnectstate)\> | Yes  | Callback used to return the result.|

**Example**

```js
data.getCellularDataState((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
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

```js
let promise = data.getCellularDataState();
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
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
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.<br>- **true**: The cellular data service is enabled.<br>- **false**: The cellular data service is disabled.|

**Example**

```js
data.isCellularDataEnabled((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
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
| Promise\<boolean\> | Promise used to return the result.<br>- **true**: The cellular data service is enabled.<br>- **false**: The cellular data service is disabled.|

**Example**

```js
let promise = data.isCellularDataEnabled();
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataRoamingEnabled

isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback\<boolean\>): void

Checks whether the cellular data roaming service is enabled. This API uses an asynchronous callback to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                    | Mandatory| Description                                                        |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                   | Yes  | Card slot ID.<br>**0**: card slot 1<br>**1**: card slot 2                    |
| callback | AsyncCallback\<boolean\> | Yes  | Callback used to return the result.<br>- **true**: The cellular data roaming service is enabled. <br>- **false**: The cellular data roaming service is disabled. |

**Example**

```js
data.isCellularDataRoamingEnabled(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.isCellularDataRoamingEnabled

isCellularDataRoamingEnabled(slotId: number): Promise\<boolean\>

Checks whether the cellular data roaming service is enabled. This API uses a promise to return the result.

**Required permission**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>**0**: card slot 1<br>**1**: card slot 2|

**Return value**

| Type              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | Promise used to return the result.<br>- **true**: The cellular data roaming service is enabled.<br>- **false**: The cellular data roaming service is disabled.|

**Example**

```js
let promise = data.isCellularDataRoamingEnabled(0);
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.enableCellularData

enableCellularData(callback: AsyncCallback<void\>): void

Enables the cellular data service. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
data.enableCellularData((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.enableCellularData

enableCellularData(): Promise<void\>

Enables the cellular data service. This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type           | Description                   |
| --------------- | ----------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let promise = data.enableCellularData();
promise.then((data) => {
    console.log(`enableCellularData success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`enableCellularData fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.disableCellularData

disableCellularData(callback: AsyncCallback<void\>): void

Disables the cellular data service. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.|

**Example**

```js
data.disableCellularData((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.disableCellularData

disableCellularData(): Promise<void\>

Disables the cellular data service. This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Return value**

| Type           | Description                       |
| --------------- | --------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let promise = data.disableCellularData();
promise.then((data) => {
    console.log(`disableCellularData success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`disableCellularData fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.enableCellularDataRoaming

enableCellularDataRoaming(slotId: number, callback: AsyncCallback<void\>): void

Enables the cellular data roaming service. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description                                    |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | Yes  | Card slot ID.<br>**0**: card slot 1<br>**1**: card slot 2|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                              |

**Example**

```js
data.enableCellularDataRoaming(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.enableCellularDataRoaming

enableCellularDataRoaming(slotId: number): Promise<void\>

Enables the cellular data roaming service. This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>**0**: card slot 1<br>**1**: card slot 2|

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let promise = data.enableCellularDataRoaming(0);
promise.then((data) => {
    console.log(`enableCellularDataRoaming success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`enableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.disableCellularDataRoaming

disableCellularDataRoaming(slotId: number, callback: AsyncCallback<void\>): void

Disables the cellular data roaming service. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name  | Type                 | Mandatory| Description                                    |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | Yes  | Card slot ID.<br>**0**: card slot 1<br>**1**: card slot 2|
| callback | AsyncCallback\<void\> | Yes  | Callback used to return the result.                              |

**Example**

```js
data.disableCellularDataRoaming(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.disableCellularDataRoaming

disableCellularDataRoaming(slotId: number): Promise<void\>

Disables the cellular data roaming service. This API uses a promise to return the result.

This is a system API.

**Required permission**: ohos.permission.SET_TELEPHONY_STATE

**System capability**: SystemCapability.Telephony.CellularData

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | Yes  | Card slot ID.<br>**0**: card slot 1<br>**1**: card slot 2|

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
let promise = data.disableCellularDataRoaming(0);
promise.then((data) => {
    console.log(`disableCellularDataRoaming success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`disableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
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

Describes the connection status of a cellular data connection.

**System capability**: SystemCapability.Telephony.CellularData

| Name                   | Value  | Description                      |
| ----------------------- | ---- | -------------------------- |
| DATA_STATE_UNKNOWN      | -1   | The status of the cellular data connection is unknown.    |
| DATA_STATE_DISCONNECTED | 0    | The cellular data connection is disconnected.   |
| DATA_STATE_CONNECTING   | 1    | The cellular data connection is being established.|
| DATA_STATE_CONNECTED    | 2    | The cellular data connection is established.  |
| DATA_STATE_SUSPENDED    | 3    | The cellular data connection is suspended.  |
