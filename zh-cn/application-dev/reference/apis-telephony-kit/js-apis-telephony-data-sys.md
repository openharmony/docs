# @ohos.telephony.data (蜂窝数据)(系统接口)

蜂窝数据提供了移动数据管理能力，包括设置默认移动数据的SIM卡，启用、禁用蜂窝数据服务和蜂窝数据漫游。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.telephony.data (蜂窝数据)](js-apis-telephony-data.md)。


## 导入模块

```ts
import { data } from '@kit.TelephonyKit';
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
| slotId   | number                | 是   | SIM卡槽ID。<br/>- 0：卡槽1。 <br/>- 1：卡槽2。 |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。                                                   |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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

**示例：**

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

设置默认移动数据的SIM卡，使用Promise方式作为异步方法。 

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | 是   | SIM卡槽ID。<br/>- 0：卡槽1。 <br/>- 1：卡槽2。 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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

**示例：**

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

启用蜂窝数据服务，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

启用蜂窝数据服务，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

禁用蜂窝数据服务，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

禁用蜂窝数据服务，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**返回值：**

| 类型            | 说明                        |
| --------------- | --------------------------- |
| Promise\<void\> | 以Promise形式返回禁用结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

启用蜂窝数据漫游，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                     |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | 是   | 卡槽ID。<br/>- 0：卡槽1。 <br/>- 1：卡槽2。 |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

启用蜂窝数据漫游，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。 <br/>- 1：卡槽2。 |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<void\> | 以Promise形式返回启用结果 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

禁用蜂窝数据漫游，使用callback方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                     |
| -------- | --------------------- | ---- | ---------------------------------------- |
| slotId   | number                | 是   | 卡槽ID。<br/>- 0：卡槽1。 <br/>- 1：卡槽2。 |
| callback | AsyncCallback\<void\> | 是   | 以callback形式异步返回结果。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

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

禁用蜂窝数据漫游，使用Promise方式作为异步方法。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CellularData

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。 <br/>- 1：卡槽2。 |

**返回值：**

| 类型            | 说明                      |
| --------------- | ------------------------- |
| Promise\<void\> | 以Promise形式返回禁用结果 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { data } from '@kit.TelephonyKit';
import { BusinessError } from '@kit.BasicServicesKit';

data.disableCellularDataRoaming(0).then(() => {
    console.log(`disableCellularDataRoaming success.`);
}).catch((err: BusinessError) => {
    console.error(`disableCellularDataRoaming fail, promise: err->${JSON.stringify(err)}`);
});
```
