# @ohos.telephony.data (蜂窝数据)

蜂窝数据提供了移动数据管理能力，包括获取、设置默认移动数据的SIM卡，获取蜂窝数据业务的上下行和分组交换域（PS域）的连接状态，以及检查蜂窝数据业务和漫游是否启用等。

>**说明：**
>
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import data from '@ohos.telephony.data';
```

## data.getDefaultCellularDataSlotId

getDefaultCellularDataSlotId(callback: AsyncCallback\<number\>): void 

获取默认移动数据的SIM卡，使用callback方式作为异步方法。 

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                       |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<number\> | 是   | 以callback形式异步返回结果。<br />0：卡槽1。<br />1：卡槽2。 |

**示例：**

```ts
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

获取默认移动数据的SIM卡，使用Promise方式作为异步方法。 

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取默认移动数据的SIM卡。<br />0：卡槽1。<br />1：卡槽2。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.getDefaultCellularDataSlotId().then((data: number) => {
    console.log(`getDefaultCellularDataSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getDefaultCellularDataSlotIdSync<sup>9+</sup>

getDefaultCellularDataSlotIdSync(): number

获取默认移动数据的SIM卡

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ------ | -------------------------------------------------- |
| number | 获取默认移动数据的SIM卡。<br />0：卡槽1。<br />1：卡槽2。 |

**示例：**

```ts
console.log("Result: "+ data.getDefaultCellularDataSlotIdSync())
```

## data.setDefaultCellularDataSlotId

setDefaultCellularDataSlotId(slotId: number, callback: AsyncCallback\<void\>): void 

设置默认移动数据的SIM卡，使用callback方式作为异步方法。 

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                                         |
| -------- | --------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                | 是   | SIM卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。<br/>- -1：清除默认配置。 |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。                                                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.setDefaultCellularDataSlotId(0, (err: BusinessError) => {
    if(err){
        console.error(`setDefaultCellularDataSlotId fail,callback: callback: err->${JSON.stringify(err)}.`);
    }else{
        console.log(`setDefaultCellularDataSlotId success`);
    }
});
```

## data.setDefaultCellularDataSlotId

setDefaultCellularDataSlotId(slotId: number): Promise\<void\> 

设置默认移动数据的SIM卡，使用Promise方式作为异步方法。 

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | 是   | SIM卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。<br/>- -1：清除默认配置。 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.setDefaultCellularDataSlotId(0).then(() => {
    console.log(`setDefaultCellularDataSlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultCellularDataSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataFlowType

getCellularDataFlowType(callback: AsyncCallback\<DataFlowType\>): void

获取蜂窝数据业务的上下行状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                                           | 必填 | 说明       |
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[DataFlowType](#dataflowtype)\> | 是   | 以callback形式异步返回结果。 |

**示例：**

```ts
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

获取蜂窝数据业务的上下行状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                     | 说明                                            |
| ---------------------------------------- | ----------------------------------------------- |
| Promise\<[DataFlowType](#dataflowtype)\> | 以Promise形式返回获取蜂窝数据业务的上下行状态。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.getCellularDataFlowType().then((data: data.DataFlowType) => {
    console.log(`getCellularDataFlowType success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCellularDataFlowType fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getCellularDataState

getCellularDataState(callback: AsyncCallback\<DataConnectState\>): void

获取分组交换域（PS域）的连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#dataconnectstate)\> | 是   | 以callback形式异步返回结果。 |

**示例：**

```ts
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

获取分组交换域(PS域)的连接状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                             | 说明                                  |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[DataConnectState](#dataconnectstate)\> | 以Promise形式返回获取PS域的连接状态。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.getCellularDataState().then((data: data.DataConnectState) => {
    console.log(`getCellularDataState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCellularDataState fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataEnabled

isCellularDataEnabled(callback: AsyncCallback\<boolean\>): void

检查蜂窝数据业务是否启用，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean\> | 是   | 以callback形式异步返回结果。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.isCellularDataEnabled((err: BusinessError, data: boolean) => {
    if(err){
        console.error(`isCellularDataEnabled fail,callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
    }else{
        console.log(`isCellularDataEnabled success`);
    }
});
```

## data.isCellularDataEnabled

isCellularDataEnabled(): Promise\<boolean\>

检查蜂窝数据业务是否启用，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回检查蜂窝数据业务是否启用。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.isCellularDataEnabled().then((data: boolean) => {
    console.log(`isCellularDataEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.isCellularDataRoamingEnabled

isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback\<boolean\>): void

检查蜂窝数据业务是否启用漫游，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                   | 是   | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。                     |
| callback | AsyncCallback\<boolean\> | 是   | 以callback形式异步返回结果。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
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

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.isCellularDataRoamingEnabled(0).then((data: boolean) => {
    console.log(`isCellularDataRoamingEnabled success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataRoamingEnabled fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.enableCellularData

enableCellularData(callback: AsyncCallback\<void\>): void

启用蜂窝数据服务，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.enableCellularData((err: BusinessError) => {
    if(err){
        console.error(`enableCellularData fail,callback: err->${JSON.stringify(err)}`);
    }else{
        console.log(`enableCellularData success`);
    }
});
```

## data.enableCellularData

enableCellularData(): Promise\<void\>

启用蜂窝数据服务，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.enableCellularData().then(() => {
    console.log(`enableCellularData success.`);
}).catch((err: BusinessError) => {
    console.error(`enableCellularData fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.disableCellularData

disableCellularData(callback: AsyncCallback\<void\>): void

禁用蜂窝数据服务，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.disableCellularData((err: BusinessError) => {
    if(err){
        console.error(`disableCellularData fail,callback: err->${JSON.stringify(err)}`);
    }else{
        console.log(`disableCellularData success`);
    }
});
```

## data.disableCellularData

disableCellularData(): Promise\<void\>

禁用蜂窝数据服务，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型            | 说明                        |
| --------------- | --------------------------- |
| Promise\<void\> | 以Promise形式返回禁用结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.disableCellularData().then(() => {
    console.log(`disableCellularData success.`);
}).catch((err: BusinessError) => {
    console.error(`disableCellularData fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.enableCellularDataRoaming

enableCellularDataRoaming(slotId: number, callback: AsyncCallback\<void\>): void

启用蜂窝数据漫游，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                     |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | 是   | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。 |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。                               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
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

启用蜂窝数据漫游，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。 |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<void\> | 以Promise形式返回启用结果 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.enableCellularDataRoaming(0).then(() => {
    console.log(`enableCellularDataRoaming success.`);
}).catch((err: BusinessError) => {
    console.error(`enableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.disableCellularDataRoaming

disableCellularDataRoaming(slotId: number, callback: AsyncCallback\<void\>): void

禁用蜂窝数据漫游，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                     |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | 是   | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。 |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。                               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
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

禁用蜂窝数据漫游，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br />0：卡槽1。<br />1：卡槽2。 |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<void\> | 以Promise形式返回禁用结果 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

data.disableCellularDataRoaming(0).then(() => {
    console.log(`disableCellularDataRoaming success.`);
}).catch((err: BusinessError) => {
    console.error(`disableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
});
```

## data.getDefaultCellularDataSimId<sup>10+</sup>

getDefaultCellularDataSimId(): number

获取默认移动数据的SIM卡ID。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ------ | -------------------------------------------------- |
| number | 获取默认移动数据的SIM卡ID。<br/>与SIM卡绑定，从1开始递增。 |

**示例：**

```ts
console.log("Result: "+ data.getDefaultCellularDataSimId());
```

## DataFlowType

描述蜂窝数据流类型。 

**系统能力**：SystemCapability.Telephony.CellularData

| 名称                   | 值   | 说明                                       |
| ---------------------- | ---- | ------------------------------------------ |
| DATA_FLOW_TYPE_NONE    | 0    | 表示没有上行或下行数据。                   |
| DATA_FLOW_TYPE_DOWN    | 1    | 表示只有下行数据。                         |
| DATA_FLOW_TYPE_UP      | 2    | 表示只有上行数据。                         |
| DATA_FLOW_TYPE_UP_DOWN | 3    | 表示有上下行数据。                         |
| DATA_FLOW_TYPE_DORMANT | 4    | 表示没有上下行数据，底层链路处于休眠状态。 |

## DataConnectState

描述蜂窝数据链路连接状态。 

**系统能力**：SystemCapability.Telephony.CellularData

| 名称                    | 值   | 说明                       |
| ----------------------- | ---- | -------------------------- |
| DATA_STATE_UNKNOWN      | -1   | 表示蜂窝数据链路未知。     |
| DATA_STATE_DISCONNECTED | 0    | 表示蜂窝数据链路断开。     |
| DATA_STATE_CONNECTING   | 1    | 表示正在连接蜂窝数据链路。 |
| DATA_STATE_CONNECTED    | 2    | 表示蜂窝数据链路已连接。   |
| DATA_STATE_SUSPENDED    | 3    | 表示蜂窝数据链路被挂起。   |
