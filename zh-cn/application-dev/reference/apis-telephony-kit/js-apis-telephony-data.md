# @ohos.telephony.data (蜂窝数据)

<!--Kit: Telephony Kit-->
<!--Subsystem: Telephony-->
<!--Owner: @k_lee9575-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

蜂窝数据提供了移动数据管理能力，包括获取默认移动数据的SIM卡、获取蜂窝数据业务的上下行数据流状态、蜂窝数据业务链路连接状态，以及检查蜂窝数据业务和漫游是否启用等。

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
| callback | AsyncCallback\<number\> | 是   | 以callback形式异步返回结果。<br />- 0：卡槽1。 <br />- 1：卡槽2。<br />- 2：esim和天际通场景下，默认移动数据的slotId为2。 |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getDefaultCellularDataSlotId((err: BusinessError, contextData: number) => {
    if(err) {
        console.error(`getDefaultCellularDataSlotId fail. code: ${err.code}, message: ${err.message}, contextData: ${contextData}`);
    } else {
        console.info(`getDefaultCellularDataSlotId success`);
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
| Promise\<number\> | 以Promise形式返回获取默认移动数据的SIM卡。<br />- 0：卡槽1。 <br />- 1：卡槽2。<br />- 2：esim和天际通场景下，默认移动数据的slotId为2。 |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getDefaultCellularDataSlotId().then((contextData: number) => {
    console.info(`getDefaultCellularDataSlotId success, contextData: ${contextData}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultCellularDataSlotId fail. code: ${err.code}, message: ${err.message}`);
});
```

## data.getDefaultCellularDataSlotIdSync<sup>9+</sup>

getDefaultCellularDataSlotIdSync(): number

获取默认移动数据的SIM卡。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ------ | -------------------------------------------------- |
| number | 获取默认移动数据的SIM卡。<br />- 0：卡槽1。 <br />- 1：卡槽2。<br />- 2：esim和天际通场景下，默认移动数据的slotId为2。 |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

console.info("Result: "+ data.getDefaultCellularDataSlotIdSync())
```


## data.getCellularDataFlowType

getCellularDataFlowType(callback: AsyncCallback\<DataFlowType\>): void

获取蜂窝网络的数据流类型（对应信号栏旁边的上下行箭头），使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                                           | 必填 | 说明       |
| -------- | ---------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[DataFlowType](#dataflowtype)\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied. [since 22]                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getCellularDataFlowType((err: BusinessError, contextData: data.DataFlowType) => {
    if(err) {
        console.error(`getCellularDataFlowType fail. code: ${err.code}, message: ${err.message}, contextData: ${contextData}`);
    } else {
        console.info(`getCellularDataFlowType success`);
    }
});
```

## data.getCellularDataFlowType

getCellularDataFlowType(): Promise\<DataFlowType\>

获取蜂窝网络的数据流类型（对应信号栏旁边的上下行箭头），使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                     | 说明                                            |
| ---------------------------------------- | ----------------------------------------------- |
| Promise\<[DataFlowType](#dataflowtype)\> | 以Promise形式返回蜂窝网络的数据流类型（对应信号栏旁边的上下行箭头）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied. [since 22]                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getCellularDataFlowType().then((contextData: data.DataFlowType) => {
    console.info(`getCellularDataFlowType success, contextData: ${contextData}`);
}).catch((err: BusinessError) => {
    console.error(`getCellularDataFlowType fail. code: ${err.code}, message: ${err.message}`);
});
```

## data.getCellularDataState

getCellularDataState(callback: AsyncCallback\<DataConnectState\>): void

获取蜂窝数据业务的连接状态，使用callback方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明       |
| -------- | ------------------------------------------------------ | ---- | ---------- |
| callback | AsyncCallback\<[DataConnectState](#dataconnectstate)\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied. [since 22]                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getCellularDataState((err: BusinessError, contextData: data.DataConnectState) => {
    if(err) {
        console.error(`getCellularDataState fail. code: ${err.code}, message: ${err.message}, contextData: ${contextData}`);
    } else {
        console.info(`getCellularDataState success`);
    }
});
```

## data.getCellularDataState

getCellularDataState(): Promise\<DataConnectState\>

获取蜂窝数据业务的连接状态，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型                                             | 说明                                  |
| ------------------------------------------------ | ------------------------------------- |
| Promise\<[DataConnectState](#dataconnectstate)\> | 以Promise形式返回获取PS域的连接状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied. [since 22]                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getCellularDataState().then((contextData: data.DataConnectState) => {
    console.info(`getCellularDataState success, contextData: ${contextData}`);
}).catch((err: BusinessError) => {
    console.error(`getCellularDataState fail. code: ${err.code}, message: ${err.message}`);
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档和[电话子系统错误码](errorcode-telephony.md)。

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
    if(err) {
        console.error(`isCellularDataEnabled fail. code: ${err.code}, message: ${err.message}, contextData: ${contextData}`);
    } else {
        console.info(`isCellularDataEnabled success`);
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档和[电话子系统错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Internal error.                               |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.isCellularDataEnabled().then((contextData: boolean) => {
    console.info(`isCellularDataEnabled success, contextData: ${contextData}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataEnabled fail. code: ${err.code}, message: ${err.message}`);
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档和[电话子系统错误码](errorcode-telephony.md)。

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                          |

**示例：**

<!--code_no_check-->

```ts
import { data } from '@kit.TelephonyKit';

try {
    let isEnabled: boolean = data.isCellularDataEnabledSync();
    console.info(`isCellularDataEnabledSync success : ${isEnabled}`);
} catch (err) {
    console.error(`isCellularDataEnabledSync fail. code: ${err.code}, message: ${err.message}`);  
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档和[电话子系统错误码](errorcode-telephony.md)。

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
    if(err) {
        console.error(`isCellularDataRoamingEnabled fail. code: ${err.code}, message: ${err.message}, contextData: ${contextData}`);
    } else {
        console.info(`isCellularDataRoamingEnabled success`);
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档和[电话子系统错误码](errorcode-telephony.md)。

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
    console.info(`isCellularDataRoamingEnabled success, contextData: ${contextData}`);
}).catch((err: BusinessError) => {
    console.error(`isCellularDataRoamingEnabled fail. code: ${err.code}, message: ${err.message}`);
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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档和[电话子系统错误码](errorcode-telephony.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
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
    console.info(`isCellularDataRoamingEnabledSync success : ${isEnabled}`);
} catch (err) {
    console.error(`isCellularDataRoamingEnabledSync fail. code: ${err.code}, message: ${err.message}`);  
}
```

## data.getDefaultCellularDataSimId<sup>10+</sup>

getDefaultCellularDataSimId(): number

获取默认移动数据的SIM卡ID。

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                                         |
| ------ | -------------------------------------------------- |
| number | 获取默认移动数据的SIM卡ID。<br/>与SIM卡绑定，从1开始递增。<br/>- 0：无SIM卡。<br/>- 9999：esim场景下，默认移动数据的SIM卡ID为9999。<br/>- 99999：天际通场景下，默认移动数据的SIM卡ID为99999。 |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';

console.info("Result: "+ data.getDefaultCellularDataSimId());
```

## data.queryAllApns<sup>16+</sup>

queryAllApns(): Promise\<Array\<ApnInfo\>\>

异步获取默认移动数据的SIM卡的APN（access point name，接入点名称）信息。

**需要权限**：ohos.permission.MANAGE_APN_SETTING（该权限是受限开放权限，仅需要连接移动数据专网进行办公时可以申请该权限，权限介绍参见[权限定义](../../security/AccessToken/restricted-permissions.md#ohospermissionmanage_apn_setting)）

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                         |
| ------ |--------------------------------------------|
| Promise\<Array\<[ApnInfo](#apninfo16)\>\> | Promise对象，返回默认移动数据的SIM卡的APN信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.queryAllApns().then((apnInfos: Array<data.ApnInfo>) => {
    console.info(`queryAllApns success, promise: apnInfos->${JSON.stringify(apnInfos)}`);
}).catch((err: BusinessError) => {
    console.error(`queryAllApns failed. code: ${err.code}, message: ${err.message}`);
});
```

## data.queryApnIds<sup>16+</sup>

queryApnIds(apnInfo: ApnInfo): Promise\<Array\<number\>\>

异步获取传入的ApnInfo对应的ApnId信息。

**需要权限**：ohos.permission.MANAGE_APN_SETTING（该权限是受限开放权限，仅需要连接移动数据专网进行办公室可以申请该权限，权限介绍参见[权限定义](../../security/AccessToken/restricted-permissions.md#ohospermissionmanage_apn_setting)）

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| apnInfo | [ApnInfo](#apninfo16) | 是   | 要查询的APN参数。 |


**返回值：**

| 类型              | 说明                          |
| ------ |-----------------------------|
| Promise\<Array\<number\>\> | Promise对象，返回传入的ApnInfo对应的ApnId信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let apnInfo: data.ApnInfo;
apnInfo = {
  apnName: "CMNET",
  apn: "cmnet",
  mcc: "460",
  mnc: "07",
};

data.queryApnIds(apnInfo).then((apnIds: Array<number>) => {
    console.info(`queryApnIds success, apnIds: ${apnIds}`);
}).catch((err: BusinessError) => {
    console.error(`queryApnIds failed. code: ${err.code}, message: ${err.message}`);
});
```

## data.setPreferredApn<sup>16+</sup>

setPreferredApn(apnId: number): Promise\<boolean\>

异步设置apnId对应的APN为首选APN。

> 注意:
>
> 如果传入的apnId为无效的apnId，切回运营商默认配置的优选Apn。

**需要权限**：ohos.permission.MANAGE_APN_SETTING（该权限是受限开放权限，仅需要连接移动数据专网进行办公室可以申请该权限，权限介绍参见[权限定义](../../security/AccessToken/restricted-permissions.md#ohospermissionmanage_apn_setting)）

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| apnId | number | 是   | 要设置的apnId，可以通过[queryApnIds](#dataqueryapnids16)查询。 |

**返回值：**

| 类型              | 说明                     |
| ------ |------------------------|
| Promise\<boolean\> | Promise对象，返回设置的结果，在未插卡时会返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

let apnId: number = 0; // apnId为通过queryApnIds返回的有效值，setPreferredApn传入无效的apnId会切回运营商默认配置的优选APN。
data.setPreferredApn(apnId).then((result: boolean) => {
    console.info(`setPreferredApn result: ${result}`);
}).catch((err: BusinessError) => {
    console.error(`setPreferredApn failed. code: ${err.code}, message: ${err.message}`);
});
```

## data.getActiveApnName<sup>20+</sup>

getActiveApnName(): Promise\<string\>

异步获取默认移动数据SIM卡对应的处于激活状态的数据业务APN（access point name，接入点名称）name信息，若不处于激活状态，返回为空字符串。

**需要权限**：ohos.permission.GET_NETWORK_INFO

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型              | 说明                                         |
| ------ |--------------------------------------------|
| Promise\<string\> | Promise对象，返回默认移动数据SIM卡对应的处于激活状态的数据业务APN name信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.getActiveApnName().then((apn: string) => {
    console.info(`getActiveApnName success, apn: ${apn}`);
}).catch((err: BusinessError) => {
    console.error(`getActiveApnName failed. code: ${err.code}, message: ${err.message}`);
});
```

## data.showSystemApnSettings

showSystemApnSettings(context: Context): Promise\<void>

打开当前默认移动数据卡对应的APN配置界面。使用Promise异步回调。

> **说明：**
>
>- 该接口仅支持查看和选择当前已添加的通用APN，不支持新建或修改。
>
>- 若未插入SIM卡或设备不支持APN配置，将无法打开该配置界面。

**起始版本**：26.0.0

**系统能力**：SystemCapability.Telephony.CellularData

**模型约束**：此接口仅可在Stage模型下使用。

**设备行为差异**：该接口在Phone、Tablet中可正常调用，在其他设备类型中调用不生效。

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| context    | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | 是   | Stage模型的应用上下文（仅支持UIAbilityContext和ExtensionContext）。 |

**返回值：**

| 类型                                                    | 说明                          |
| ------------------------------------------------------- | ----------------------------- |
| Promise\<void>  |Promise对象。无返回结果的Promise对象。|

**示例：**

> **说明：** 
>
> 在本文档的示例中，通过this.context来获取UIAbilityContext，其中this代表继承自UIAbility的UIAbility实例。如需在页面中使用UIAbilityContext提供的能力，请参见[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

```ts
import { data } from '@kit.TelephonyKit';
import { common } from '@kit.AbilityKit';

let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
data.showSystemApnSettings(context).then(() => {
  console.info("showSystemApnSettings success");
}).catch(() => {
  console.error("showSystemApnSettings failed");
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
| mcc       | string     | 否      | 否         | SIM卡的mcc。 |
| mnc       | string     | 否      | 否         | SIM卡的mnc。 |
| user      | string     | 否      | 是         | 用户名。     |
| type      | string     | 否      | 是         | APN类型。    |
| proxy     | string     | 否      | 是         | 代理地址。   |
| mmsproxy  | string     | 否      | 是         | 彩信代理。   |
