# @ohos.telephony.data (蜂窝数据)

蜂窝数据提供了移动数据管理能力，包括获取默认移动数据的SIM卡、获取蜂窝数据业务的上下行和分组交换域(PS域)的连接状态，以及检查蜂窝数据业务和漫游是否启用等。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 导入模块

```ts
import { data } from '@kit.TelephonyKit';
```

## data.getDefaultCellularDataSlotId

getDefaultCellularDataSlotId(callback: AsyncCallback\<number\>): void 

获取默认移动数据的SIM卡，使用callback方式作为异步方法。 

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                       |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<number\> | 是   | 以callback形式异步返回结果。<br />- 0：卡槽1。 <br />- 1：卡槽2。 |

**示例：**

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

获取默认移动数据的SIM卡，使用Promise方式作为异步方法。 

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<number\> | 以Promise形式返回获取默认移动数据的SIM卡。<br />- 0：卡槽1。 <br />- 1：卡槽2。 |

**示例：**

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

获取默认移动数据的SIM卡。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ------ | -------------------------------------------------- |
| number | 获取默认移动数据的SIM卡。<br />- 0：卡槽1。 <br />- 1：卡槽2。 |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

console.log("Result: "+ data.getDefaultCellularDataSlotIdSync())
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

获取蜂窝数据业务的上下行状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                     | 说明                                            |
| ---------------------------------------- | ----------------------------------------------- |
| Promise\<[DataFlowType](#dataflowtype)\> | 以Promise形式返回获取蜂窝数据业务的上下行状态。 |

**示例：**

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

获取分组交换域(PS域)的连接状态，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#dataconnectstate)\> | 是   | 以callback形式异步返回结果。 |

**示例：**

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

获取分组交换域(PS域)的连接状态，使用Promise方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                             | 说明                                  |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[DataConnectState](#dataconnectstate)\> | 以Promise形式返回获取PS域的连接状态。 |

**示例：**

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

检查蜂窝数据业务是否启用，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<boolean\> | 是   | 以callback形式异步返回结果。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

检查蜂窝数据业务是否启用，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回检查蜂窝数据业务是否启用。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

检查蜂窝数据业务是否启用，调用此API返回结果。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 用来返回检查蜂窝数据业务是否启用。<br />true：蜂窝数据业务已启用。<br />false：蜂窝数据业务已禁用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

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

检查蜂窝数据业务是否启用漫游，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ------------------------ | ---- | ------------------------------------------------------------ |
| slotId   | number                   | 是   | 卡槽ID。<br />- 0：卡槽1。<br />- 1：卡槽2。                     |
| callback | AsyncCallback\<boolean\> | 是   | 以callback形式异步返回结果。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

检查蜂窝数据业务是否启用漫游，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br />- 0：卡槽1。<br />- 1：卡槽2。 |

**返回值：**

| 类型               | 说明                                                         |
| ------------------ | ------------------------------------------------------------ |
| Promise\<boolean\> | 以Promise形式返回检查蜂窝数据业务是否启用漫游。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

检查蜂窝数据业务是否启用漫游，调用此API返回结果。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br />- 0：卡槽1。<br />- 1：卡槽2。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 用来返回检查蜂窝数据业务是否启用漫游。<br />true：蜂窝数据业务已启用漫游。<br />false：蜂窝数据业务已禁用漫游。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; |
| 8300001  | Invalid parameter value.                                     |
| 8300002  | Operation failed. Cannot connect to service.                 |
| 8300003  | System internal error.                                       |
| 8300999  | Unknown error code.                                          |

**示例：**

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

获取默认移动数据的SIM卡ID。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ------ | -------------------------------------------------- |
| number | 获取默认移动数据的SIM卡ID。<br/>与SIM卡绑定，从1开始递增。 |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

console.log("Result: "+ data.getDefaultCellularDataSimId());
```

## data.queryAllApns<sup>16+</sup>

queryAllApns(): Promise\<Array\<ApnInfo\>\>

获取默认移动数据的SIM卡的APN（access point name，接入点名称）信息。

**需要权限**：ohos.permission.MANAGE_APN_SETTING

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                         |
| ------ |--------------------------------------------|
| Promise\<Array\<ApnInfo\>\> | 获取默认移动数据的SIM卡的APN信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

cellular.queryAllApns().then((data: Array<cellular.ApnInfo>) => {
    console.info(`queryAllApns success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`queryAllApns failed, promise: err->${JSON.stringify(err)}`);
});
```

## data.queryApnIds<sup>16+</sup>

queryApnIds(apnInfo: ApnInfo): Promise\<Array\<number\>\>

获取传入的ApnInfo对应的ApnId信息。

**需要权限**：ohos.permission.MANAGE_APN_SETTING

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                          |
| ------ |-----------------------------|
| Promise\<Array\<number\>\> | 获取到的传入的ApnInfo对应的ApnId信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

let apnInfo: cellular.ApnInfo;
apnInfo = {
  apnName: "CMNET",
  apn: "cmnet",
  mcc: "460",
  mnc: "07",
};

cellular.queryApnIds(apnInfo).then((data: Array<number>) => {
    console.info(`queryApnIds success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`queryApnIds failed, promise: err->${JSON.stringify(err)}`);
});
```

## data.setPreferredApn<sup>16+</sup>

setPreferredApn(apnId: number): Promise\<boolean\>

设置apnId对应的APN为首选APN。

> 注意:
>
> 如果传入的apnId为无效的apnId，切回运营商默认配置的优选Apn。

**需要权限**：ohos.permission.MANAGE_APN_SETTING

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                     |
| ------ |------------------------|
| Promise\<boolean\> | 设置的返回结果，在未插卡时会返回fasle。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

let apnId: number = 0; // apnId为通过queryApnIds返回的有效值，setPreferredApn传入无效的apnId会切回运营商默认配置的优选APN。
cellular.setPreferredApn(apnId).then((data: boolean) => {
    console.info(`setPreferredApn success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`setPreferredApn failed, promise: err->${JSON.stringify(err)}`);
});
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

## ApnInfo<sup>16+</sup>

APN信息。

**系统能力**：SystemCapability.Telephony.CellularData

| 名称       | 类型      | 只读    |  可选      | 说明         |
|------------|----------|---------|------------|-------------|
| apnName   | string     | 否      | 否         | APN名称。    |
| apn       | string     | 否      | 否         | APN。        |
| mcc       | string     | 否      | 否         | Sim卡的mcc。 |
| mnc       | string     | 否      | 否         | Sim卡的mnc。 |
| user      | string     | 否      | 是         | 用户名。     |
| type      | string     | 否      | 是         | APN类型。    |
| proxy     | string     | 否      | 是         | 代理地址。   |
| mmsproxy  | string     | 否      | 是         | 彩信代理。   |
