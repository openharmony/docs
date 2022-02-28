# 蜂窝数据

>**说明：** 
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```
import data from '@ohos.telephony.data';
```

## data.getDefaultCellularDataSlotId<a name=data.getDefaultCellularDataSlotId-callback></a>

getDefaultCellularDataSlotId(callback: AsyncCallback\<number\>): void 

获取默认移动数据的SIM卡，使用callback方式作为异步方法。 

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                       |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<number\> | 是   | 回调函数。<br />0：卡槽1。<br />1：卡槽2。 |

**示例：**

```
data.getDefaultCellularDataSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.getDefaultCellularDataSlotId<a name=data.getDefaultCellularDataSlotId-promise></a>

getDefaultCellularDataSlotId(): Promise\<number\> 

获取默认移动数据的SIM卡，使用Promise方式作为异步方法。 

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取默认移动数据的SIM卡。<br />0：卡槽1。<br />1：卡槽2。 |

**示例：**

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

获取蜂窝数据业务的上下行状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                                           | 必填 | 说明       |
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[DataFlowType](#DataFlowType)\> | 是   | 回调函数。 |

**示例：**

```
data.getCellularDataFlowType((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.getCellularDataFlowType<a name=data.getCellularDataFlowType-promise></a>

getCellularDataFlowType(): Promise\<DataFlowType\>

获取蜂窝数据业务的上下行状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                     | 说明                                            |
| ---------------------------------------- | ----------------------------------------------- |
| Promise\<[DataFlowType](#DataFlowType)\> | 以Promise形式返回获取蜂窝数据业务的上下行状态。 |

**示例：**

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

获取分组交换域（PS域）的连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#DataConnectState)\> | 是   | 回调函数。 |

**示例：**

```
data.getCellularDataState((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.getCellularDataState<a name=data.getCellularDataState-promise></a>

getCellularDataState(): Promise\<DataConnectState\>

获取分组交换域(PS域)的连接状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                             | 说明                                  |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[DataConnectState](#DataConnectState)\> | 以Promise形式返回获取PS域的连接状态。 |

**示例：**

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

检查蜂窝数据业务是否启用，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |

**示例：**

```
data.isCellularDataEnabled((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.isCellularDataEnabled<a name=data.isCellularDataEnabled-promise></a>

isCellularDataEnabled(): Promise\<boolean\>

检查蜂窝数据业务是否启用，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回检查蜂窝数据业务是否启用。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |

**示例：**

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

检查蜂窝数据业务是否启用漫游，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                   | 是   | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。                     |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |

**示例：**

```
data.isCellularDataRoamingEnabled(0,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## data.isCellularDataRoamingEnabled<a name=data.isCellularDataRoamingEnabled-promise></a>

isCellularDataRoamingEnabled(slotId: number): Promise\<boolean\>

检查蜂窝数据业务是否启用漫游，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。 |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回检查蜂窝数据业务是否启用漫游。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |

**示例：**

```
let promise = data.isCellularDataRoamingEnabled(0);
promise.then((data) => {
    console.log(`test success, promise: data->${JSON.stringify(data)}`);
}).catch((err) => {
    console.error(`test fail, promise: err->${JSON.stringify(err)}`);
});
```

## DataFlowType<a name=DataFlowType></a>

 描述蜂窝数据流类型。 

| 参数名 | 值                     | 说明                                                         |
| ------ | ---------------------- | ------------------------------------------------------------ |
| 0      | DATA_FLOW_TYPE_NONE    | 表示没有上行或下行数据。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 1      | DATA_FLOW_TYPE_DOWN    | 表示只有下行数据。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 2      | DATA_FLOW_TYPE_UP      | 表示只有上行数据。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 3      | DATA_FLOW_TYPE_UP_DOWN | 表示有上下行数据。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 4      | DATA_FLOW_TYPE_DORMANT | 表示没有上下行数据，底层链路处于休眠状态。<br />**系统能力**：SystemCapability.Telephony.CellularData |

## DataConnectState<a name=DataConnectState></a>

 描述蜂窝数据链路连接状态。 

| 参数名 | 值                      | 说明                                                         |
| ------ | ----------------------- | ------------------------------------------------------------ |
| -1     | DATA_STATE_UNKNOWN      | 表示蜂窝数据链路未知。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 0      | DATA_STATE_DISCONNECTED | 表示蜂窝数据链路断开。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 1      | DATA_STATE_CONNECTING   | 表示正在连接蜂窝数据链路。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 2      | DATA_STATE_CONNECTED    | 表示蜂窝数据链路已连接。<br />**系统能力**：SystemCapability.Telephony.CellularData |
| 3      | DATA_STATE_SUSPENDED    | 表示蜂窝数据链路被挂起。<br />**系统能力**：SystemCapability.Telephony.CellularData |