# @ohos.telephony.radio (网络搜索)（系统接口）

网络搜索模块提供管理网络搜索的一些基础功能，包括获取当前接入的CS域和PS域无线接入技术、获取网络状态、获取当前选网模式、获取注册网络所在国家的ISO国家码、获取主卡所在卡槽的索引号、获取指定SIM卡槽对应的注册网络信号强度信息列表、获取运营商名称、获取设备的指定卡槽的IMEI、获取设备的指定卡槽的MEID、获取设备的指定卡槽的唯一设备ID，判断当前设备是否支持5G\(NR\)、判断主卡的Radio是否打开等。

>**说明：**
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.telephony.radio (网络搜索)](js-apis-radio.md)

## 导入模块

```ts
import { radio } from '@kit.TelephonyKit';
```


## radio.setPrimarySlotId<sup>8+</sup>

setPrimarySlotId\(slotId: number, callback: AsyncCallback\<void\>\): void

设置主卡所在卡槽的索引号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                   |
| -------- | --------------------- | ---- | -------------------------------------- |
| slotId   | number                | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回设置主卡的执行结果。        |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.setPrimarySlotId(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`setPrimarySlotId failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setPrimarySlotId success.`);
});
```


## radio.setPrimarySlotId<sup>8+</sup>

setPrimarySlotId\(slotId: number\): Promise\<void\>

设置主卡所在卡槽的索引号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.setPrimarySlotId(slotId).then(() => {
    console.log(`setPrimarySlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setPrimarySlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getIMEI<sup>8+</sup>

getIMEI\(callback: AsyncCallback\<string\>\): void

获取设备的主卡的IMEI。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                       |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回设备主卡的IMEI。如果IMEI不存在，则返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.getIMEI((err: BusinessError, data: string) => {
    if (err) {
        console.error(`getIMEI failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getIMEI success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getIMEI<sup>8+</sup>

getIMEI\(slotId: number, callback: AsyncCallback\<string\>\): void

获取设备的指定卡槽的IMEI。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                       |
| -------- | ----------------------- | ---- | ------------------------------------------ |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2     |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回设备指定卡槽的IMEI。如果IMEI不存在，则返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getIMEI(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getIMEI failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getIMEI success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getIMEI<sup>8+</sup>

getIMEI\(slotId?: number\): Promise\<string\>

获取设备的指定卡槽的IMEI。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                       |
| ----------------- | ------------------------------------------ |
| Promise\<string\> | 以Promise形式异步返回设备指定卡槽的IMEI。如果IMEI不存在，则返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getIMEI(slotId).then((data: string) => {
    console.log(`getIMEI success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getIMEI failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getMEID<sup>8+</sup>

getMEID\(callback: AsyncCallback\<string\>\): void

获取设备的指定卡槽的MEID。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明       |
| -------- | ----------------------- | ---- | ---------- |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回设备的指定卡槽的MEID。如果MEID不存在，则返回空字符串。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.getMEID((err: BusinessError, data: string) => {
    if (err) {
        console.error(`getMEID failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getMEID success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getMEID<sup>8+</sup>

getMEID\(slotId: number, callback: AsyncCallback\<string\>\): void

获取设备的指定卡槽的MEID。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回设备的指定卡槽的MEID。如果MEID不存在，则返回空字符串。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getMEID(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getMEID failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getMEID success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getMEID<sup>8+</sup>

getMEID\(slotId?: number\): Promise\<string\>

获取设备的指定卡槽的MEID。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<string\> | 以Promise形式返回设备的指定卡槽的MEID。如果MEID不存在，则返回空字符串。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getMEID(slotId).then((data: string) => {
    console.log(`getMEID success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getMEID failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getUniqueDeviceId<sup>8+</sup>

getUniqueDeviceId\(callback: AsyncCallback\<string\>\): void

获取设备主卡的唯一设备ID。使用callback异步回调。

如果设备注册的是3GPP网络，则接口返回IMEI；如果注册的是3GPP2网络，则接口返回MEID。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明       |
| -------- | ----------------------- | ---- | ---------- |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回设备主卡的唯一设备ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.getUniqueDeviceId((err: BusinessError, data: string) => {
    if (err) {
        console.error(`getUniqueDeviceId failed, callback: err->${JSON.stringify(err)}}`);
        return;
    }
    console.log(`getUniqueDeviceId success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getUniqueDeviceId<sup>8+</sup>

getUniqueDeviceId\(slotId: number, callback: AsyncCallback\<string\>\): void

获取设备的指定卡槽的唯一设备ID。使用callback异步回调。

如果设备注册的是3GPP网络，则接口返回IMEI；如果注册的是3GPP2网络，则接口返回MEID。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回指定卡槽的唯一设备ID。      |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getUniqueDeviceId(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getUniqueDeviceId failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getUniqueDeviceId success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getUniqueDeviceId<sup>8+</sup>

getUniqueDeviceId\(slotId?: number\): Promise\<string\>

获取设备的指定卡槽的唯一设备ID。使用Promise异步回调。

如果设备注册的是3GPP网络，则接口返回IMEI；如果注册的是3GPP2网络，则接口返回MEID。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                          |
| ----------------- | --------------------------------------------- |
| Promise\<string\> | 以Promise形式返回设备的指定卡槽的唯一设备ID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getUniqueDeviceId(slotId).then((data: string) => {
    console.log(`getUniqueDeviceId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getUniqueDeviceId failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.sendUpdateCellLocationRequest<sup>8+</sup>

sendUpdateCellLocationRequest\(callback: AsyncCallback\<void\>\): void

发送更新小区位置请求。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回更新小区位置请求的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.sendUpdateCellLocationRequest((err: BusinessError) => {
    if (err) {
        console.error(`sendUpdateCellLocationRequest failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`sendUpdateCellLocationRequest success.`);
});
```

## radio.sendUpdateCellLocationRequest<sup>8+</sup>

sendUpdateCellLocationRequest\(slotId: number, callback: AsyncCallback\<void\>\): void

发送更新小区位置请求。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回更新小区位置请求的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.sendUpdateCellLocationRequest(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`sendUpdateCellLocationRequest failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`sendUpdateCellLocationRequest success.`);
});
```

## radio.sendUpdateCellLocationRequest<sup>8+</sup>

sendUpdateCellLocationRequest\(slotId?: number\): Promise\<void\>

发送更新小区位置请求。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回更新小区位置请求的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.sendUpdateCellLocationRequest(slotId).then(() => {
    console.log(`sendUpdateCellLocationRequest success.`);
}).catch((err: BusinessError) => {
    console.error(`sendUpdateCellLocationRequest failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getCellInformation<sup>8+</sup>

getCellInformation\(callback: AsyncCallback\<Array\<CellInformation\>\>\): void

获取小区信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                     |
| -------- | ------------------------------------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<Array<[CellInformation](#cellinformation8)\>\> | 是   | 回调函数。返回小区信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.getCellInformation((err: BusinessError, data: Array<radio.CellInformation>) => {
    if (err) {
        console.error(`getCellInformation failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getCellInformation success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getCellInformation<sup>8+</sup>

getCellInformation\(slotId: number, callback: AsyncCallback\<Array\<CellInformation\>\>\): void

获取小区信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<Array<[CellInformation](#cellinformation8)\>\> | 是   | 回调函数。返回小区信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getCellInformation(slotId, (err: BusinessError, data: Array<radio.CellInformation>) => {
    if (err) {
        console.error(`getCellInformation failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getCellInformation success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getCellInformation<sup>8+</sup>

getCellInformation\(slotId?: number\): Promise\<Array\<CellInformation\>\>

获取小区信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                    | 说明                    |
| ------------------------------------------------------- | ----------------------- |
| Promise\<Array<[CellInformation](#cellinformation8)\>\> | 以Promise形式返回小区信息结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getCellInformation(slotId).then((data: Array<radio.CellInformation>) => {
    console.log(`getCellInformation success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCellInformation failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.setNetworkSelectionMode

setNetworkSelectionMode\(options: NetworkSelectionModeOptions, callback: AsyncCallback\<void\>\): void

设置网络选择模式。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明               |
| -------- | ----------------------------------------------------------- | ---- | ------------------ |
| options  | [NetworkSelectionModeOptions](#networkselectionmodeoptions) | 是   | 网络选择模式选项。 |
| callback | AsyncCallback\<void\>                                       | 是   | 回调函数。返回设置网络选择模式的结果。     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let networkInformation: radio.NetworkInformation = {
    operatorName: "中国移动",
    operatorNumeric: "898600",
    state: radio.NetworkInformationState.NETWORK_AVAILABLE,
    radioTech: "CS"
}
let networkSelectionModeOptions: radio.NetworkSelectionModeOptions = {
    slotId: 0,
    selectMode: radio.NetworkSelectionMode.NETWORK_SELECTION_AUTOMATIC,
    networkInformation: networkInformation,
    resumeSelection: true
}
radio.setNetworkSelectionMode(networkSelectionModeOptions, (err: BusinessError) => {
    if (err) {
        console.error(`setNetworkSelectionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setNetworkSelectionMode success.`);
});
```

## radio.setNetworkSelectionMode

setNetworkSelectionMode\(options: NetworkSelectionModeOptions\): Promise\<void\>

设置网络选择模式。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型                                                        | 必填 | 说明               |
| ------- | ----------------------------------------------------------- | ---- | ------------------ |
| options | [NetworkSelectionModeOptions](#networkselectionmodeoptions) | 是   | 网络选择模式选项。 |

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回设置网络选择模式的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let networkInformation: radio.NetworkInformation = {
    operatorName: "中国移动",
    operatorNumeric: "898600",
    state: radio.NetworkInformationState.NETWORK_AVAILABLE,
    radioTech: "CS"
}
let networkSelectionModeOptions: radio.NetworkSelectionModeOptions = {
    slotId: 0,
    selectMode: radio.NetworkSelectionMode.NETWORK_SELECTION_AUTOMATIC,
    networkInformation: networkInformation,
    resumeSelection: true
}
radio.setNetworkSelectionMode(networkSelectionModeOptions).then(() => {
    console.log(`setNetworkSelectionMode success.`);
}).catch((err: BusinessError) => {
    console.error(`setNetworkSelectionMode failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getNetworkSearchInformation

getNetworkSearchInformation\(slotId: number, callback: AsyncCallback\<NetworkSearchResult\>\): void

获取网络搜索信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[NetworkSearchResult](#networksearchresult)\> | 是   | 回调函数。返回网络搜索信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.getNetworkSearchInformation(0, (err: BusinessError, data: radio.NetworkSearchResult) => {
    if (err) {
        console.error(`getNetworkSearchInformation failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNetworkSearchInformation success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getNetworkSearchInformation

getNetworkSearchInformation\(slotId: number\): Promise\<NetworkSearchResult\>

获取网络搜索信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                   | 说明                    |
| ------------------------------------------------------ | ----------------------- |
| Promise\<[NetworkSearchResult](#networksearchresult)\> | 以Promise形式返回网络搜索信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.getNetworkSearchInformation(0).then((data: radio.NetworkSearchResult) => {
    console.log(`getNetworkSearchInformation success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNetworkSearchInformation failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getNrOptionMode<sup>(deprecated)</sup>

getNrOptionMode\(callback: AsyncCallback\<NrOptionMode\>\): void

获取Nr选项模式。使用callback异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 10开始废弃。建议使用[getNROptionMode](#radiogetnroptionmode10)替代。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                            | 必填 | 说明       |
| -------- | ----------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<[NrOptionMode](#nroptionmodedeprecated)\> | 是   | 回调函数。返回Nr选项模式。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

radio.getNrOptionMode((err: BusinessError, data: radio.NrOptionMode) => {
    if (err) {
        console.error(`getNrOptionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNrOptionMode success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getNrOptionMode<sup>(deprecated)</sup>

getNrOptionMode\(slotId: number, callback: AsyncCallback\<NrOptionMode\>\): void

获取Nr选项模式 。使用callback异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 10开始废弃。建议使用[getNROptionMode](#radiogetnroptionmode10)替代。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                   |
| -------- | ----------------------------------------------- | ---- | ------------------------------------- |
| slotId   | number                                          | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[NrOptionMode](#nroptionmodedeprecated)\> | 是   | 回调函数。返回Nr选项模式。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNrOptionMode(slotId, (err: BusinessError, data: radio.NrOptionMode) => {
    if (err) {
        console.error(`getNrOptionModecallback failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNrOptionModecallback success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getNrOptionMode<sup>(deprecated)</sup>

getNrOptionMode\(slotId?: number\): Promise\<NrOptionMode\>

获取Nr选项模式 。使用Promise异步回调。

> **说明：**
>
> 从 API version 8开始支持，从API version 10开始废弃。建议使用[getNROptionMode](#radiogetnroptionmode10-1)替代。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                               | 说明                    |
| -------------------------------------------------- | ----------------------- |
| Promise\<[NrOptionMode](#nroptionmodedeprecated)\> | 以Promise形式返回Nr选项模式。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNrOptionMode(slotId).then((data: radio.NrOptionMode) => {
    console.log(`getNrOptionMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNrOptionMode failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.turnOnRadio<sup>7+</sup>

turnOnRadio\(callback: AsyncCallback\<void\>\): void

打开Radio。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回打开Radio的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.turnOnRadio((err: BusinessError) => {
    if (err) {
        console.error(`turnOnRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOnRadio success.`);
});
```


## radio.turnOnRadio<sup>7+</sup>

turnOnRadio\(slotId: number, callback: AsyncCallback\<void\>\): void

打开指定卡槽的Radio。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                   |
| -------- | --------------------- | ---- | -------------------------------------- |
| slotId   | number                | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回打开指定卡槽的Radio的操作结果。      |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.turnOnRadio(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`turnOnRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOnRadio success.`);
});
```


## radio.turnOnRadio<sup>7+</sup>

turnOnRadio(slotId?: number): Promise\<void\>

打开Radio。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回打开Radio的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.turnOnRadio(slotId).then(() => {
    console.log(`turnOnRadio success.`);
}).catch((err: BusinessError) => {
    console.error(`turnOnRadio failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.turnOffRadio<sup>7+</sup>

turnOffRadio\(callback: AsyncCallback\<void\>\): void

关闭Radio。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回关闭Radio的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

radio.turnOffRadio((err: BusinessError) => {
    if (err) {
        console.error(`turnOffRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOffRadio success.`);
});
```


## radio.turnOffRadio<sup>7+</sup>

turnOffRadio\(slotId: number, callback: AsyncCallback\<void\>\): void

关闭指定卡槽的Radio。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                  | 必填 | 说明                                   |
| -------- | --------------------- | ---- | -------------------------------------- |
| slotId   | number                | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<void\> | 是   | 回调函数。返回关闭指定卡槽的Radio的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.turnOffRadio(slotId, (err: BusinessError) => {
    if (err) {
        console.error(`turnOffRadio failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`turnOffRadio success.`);
});
```


## radio.turnOffRadio<sup>7+</sup>

turnOffRadio\(slotId?: number\): Promise\<void\>

关闭Radio。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回关闭Radio的操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.turnOffRadio(slotId).then(() => {
    console.log(`turnOffRadio success.`);
}).catch((err: BusinessError) => {
    console.error(`turnOffRadio failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.setPreferredNetwork<sup>8+</sup>

setPreferredNetwork\(slotId: number, networkMode: PreferredNetworkMode, callback: AsyncCallback\<void\>\): void

设置首选网络。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名      | 类型                                           | 必填 | 说明                                   |
| ----------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId      | number                                         | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| networkMode | [PreferredNetworkMode](#preferrednetworkmode8) | 是   | 设置首选网络模式。                       |
| callback    | AsyncCallback\<void\>                          | 是   | 回调函数。返回设置首选网络的结果。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.PreferredNetworkMode = radio.PreferredNetworkMode.PREFERRED_NETWORK_MODE_GSM;
radio.setPreferredNetwork(slotId, mode, (err: BusinessError) => {
    if (err) {
        console.error(`setPreferredNetwork failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setPreferredNetwork success.`);
});
```

## radio.setPreferredNetwork<sup>8+</sup>

setPreferredNetwork\(slotId: number, networkMode: PreferredNetworkMode\): Promise\<void\>

设置首选网络。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名      | 类型                                           | 必填 | 说明                                   |
| ----------- | ---------------------------------------------- | ---- | -------------------------------------- |
| slotId      | number                                         | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| networkMode | [PreferredNetworkMode](#preferrednetworkmode8) | 是   | 设置首选网络模式。|

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回返回设置首选网络的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                     |
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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.PreferredNetworkMode = radio.PreferredNetworkMode.PREFERRED_NETWORK_MODE_GSM;
radio.setPreferredNetwork(slotId, mode).then(() => {
    console.log(`setPreferredNetwork success.`);
}).catch((err: BusinessError) => {
    console.error(`setPreferredNetwork failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getPreferredNetwork<sup>8+</sup>

getPreferredNetwork\(slotId: number, callback: AsyncCallback\<PreferredNetworkMode\>\): void

获取首选网络。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   |                              类型                               | 必填 | 说明                                   |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[PreferredNetworkMode](#preferrednetworkmode8)\> | 是   | 回调函数。返回首选网络类型。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getPreferredNetwork(slotId, (err: BusinessError, data: radio.PreferredNetworkMode) => {
    if (err) {
        console.error(`getPreferredNetwork failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getPreferredNetwork success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getPreferredNetwork<sup>8+</sup>

getPreferredNetwork\(slotId: number\): Promise\<PreferredNetworkMode\>

获取首选网络。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<[PreferredNetworkMode](#preferrednetworkmode8)\> | 以Promise形式返回首选网络类型。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getPreferredNetwork(slotId).then((data: radio.PreferredNetworkMode) => {
    console.log(`getPreferredNetwork success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getPreferredNetwork failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getImsRegInfo<sup>9+</sup>

getImsRegInfo\(slotId: number, imsType: ImsServiceType, callback: AsyncCallback\<ImsRegInfo\>\): void

获取特定IMS服务类型的IMS注册状态信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                       | 必填 | 说明                                   |
| -------- | ------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                     | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| imsType  | [ImsServiceType](#imsservicetype9)         | 是   | IMS服务类型。                          |
| callback | AsyncCallback<[ImsRegInfo](#imsreginfo9)\> | 是   | 回调函数。返回指定IMS服务类型的IMS注册状态信息。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.getImsRegInfo(slotId, mode, (err: BusinessError, data: radio.ImsRegInfo) => {
    if (err) {
        console.error(`getImsRegInfo failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getImsRegInfo success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getImsRegInfo<sup>9+</sup>

getImsRegInfo\(slotId: number, imsType: ImsServiceType\): Promise\<ImsRegInfo\>

获取特定IMS服务类型的IMS注册状态信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型                               | 必填 | 说明                                   |
| ------- | ---------------------------------- | ---- | -------------------------------------- |
| slotId  | number                             | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| imsType | [ImsServiceType](#imsservicetype9) | 是   | IMS服务类型。                          |

**返回值：**

| 类型                                  | 说明                    |
| ------------------------------------- | ----------------------- |
| Promise\<[ImsRegInfo](#imsreginfo9)\> | 以Promise形式返回指定IMS服务类型的IMS注册状态信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.getImsRegInfo(slotId, mode).then((data: radio.ImsRegInfo) => {
    console.log(`getImsRegInfo success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getImsRegInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.on('imsRegStateChange')<sup>9+</sup>

on\(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback: Callback\<ImsRegInfo\>\): void

订阅imsRegStateChange事件，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                   |
| -------- | ------------------------------------ | ---- | -------------------------------------- |
| type     | string                               | 是   | 填写'imsRegStateChange'，表示IMS注册状态变化事件。                |
| slotId   | number                               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| imsType  | [ImsServiceType](#imsservicetype9)   | 是   | IMS服务类型。                          |
| callback | Callback<[ImsRegInfo](#imsreginfo9)> | 是   | 回调函数。返回IMS注册状态信息。              |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.on('imsRegStateChange', slotId, mode, (data: radio.ImsRegInfo) => {
    console.log(`on imsRegStateChange success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.off('imsRegStateChange')<sup>9+</sup>

off\(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback?: Callback\<ImsRegInfo\>\): void

取消订阅imsRegStateChange事件，使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                 | 必填 | 说明                                   |
| -------- | ------------------------------------ | ---- | -------------------------------------- |
| type     | string                               | 是   | 填写'imsRegStateChange'，表示IMS注册状态变化事件。     |
| slotId   | number                               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| imsType  | [ImsServiceType](#imsservicetype9)   | 是   | IMS服务类型。                          |
| callback | Callback<[ImsRegInfo](#imsreginfo9)> | 否   | 回调函数。返回IMS注册状态信息。缺省时，表示注销所有已注册事件回调。需与on('imsRegStateChange')的callback一致。   |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                    |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: Mandatory parameters are left unspecified.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
let slotId: number = 0;
let mode: radio.ImsServiceType = radio.ImsServiceType.TYPE_VIDEO;
radio.off('imsRegStateChange', slotId, mode, (data: radio.ImsRegInfo) => {
    console.log(`off imsRegStateChange success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getBasebandVersion<sup>10+</sup>

getBasebandVersion\(slotId: number, callback: AsyncCallback\<string\>\): void

获取设备的基带版本号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | ------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回设备的基带版本号。            |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                     |
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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getBasebandVersion(slotId, (err: BusinessError, data: string) => {
    if (err) {
        console.error(`getBasebandVersion failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getBasebandVersion success, callback: data->${JSON.stringify(data)}`);
});
```


## radio.getBasebandVersion<sup>10+</sup>

getBasebandVersion\(slotId: number\): Promise\<string\>

获取设备的基带版本号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                  |
| -------- | ----------------------- | ---- | ------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                    |
| ----------------- | -------------------------------------- |
| Promise\<string\> | 以Promise形式返回设备的基带版本号。      |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                     |
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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getBasebandVersion(slotId).then((data: string) => {
    console.log(`getBasebandVersion success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getBasebandVersion failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.setNROptionMode<sup>10+</sup>

setNROptionMode\(slotId: number, mode: NROptionMode, callback: AsyncCallback\<void\>\): void

设置NR选项模式。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                   |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                           | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |
| mode     | [NROptionMode](#nroptionmode10)                  | 是   | NR的选择模式。                          |
| callback | AsyncCallback\<void\>                            | 是   | 回调函数。返回设置NR选项模式的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                     |
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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.NROptionMode = radio.NROptionMode.NR_OPTION_NSA_ONLY;
radio.setNROptionMode(slotId, mode, (err: BusinessError) => {
    if (err) {
        console.error(`setNROptionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setNROptionMode success.`);
});
```


## radio.setNROptionMode<sup>10+</sup>

setNROptionMode\(slotId: number, mode: NROptionMode\): Promise\<void\>

设置NR选项模式 。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 |              类型               | 必填 | 说明                                   |
| ------ | ------------------------------- | ---- | ------------------------------------- |
| slotId | number                          | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| mode   | [NROptionMode](#nroptionmode10) | 是   | NR的选项模式。   |

**返回值：**

|        类型       |            说明         |
| ----------------- | ----------------------- |
| Promise\<void\>   | 以Promise形式返回设置NR选项模式的结果。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                      |
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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let mode: radio.NROptionMode = radio.NROptionMode.NR_OPTION_NSA_ONLY;
radio.setNROptionMode(slotId, mode).then(() => {
    console.log(`setNROptionMode success`);
}).catch((err: BusinessError) => {
    console.error(`setNROptionMode failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNROptionMode<sup>10+</sup>

getNROptionMode\(slotId: number, callback: AsyncCallback\<NROptionMode\>\): void

获取Nr选项模式 。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                              | 必填 | 说明                                   |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                           | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |
| callback | AsyncCallback\<[NROptionMode](#nroptionmode10)\> | 是   | 回调函数。返回NR选项模式。           |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                  错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNROptionMode(slotId, (err: BusinessError, data: radio.NROptionMode) => {
    if (err) {
        console.error(`getNROptionMode failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNROptionMode success, callback: data->${JSON.stringify(data)}`);
});
```

## radio.getNROptionMode<sup>10+</sup>

getNROptionMode\(slotId: number\): Promise\<NROptionMode\>

获取NR选项模式 。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | ------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                      | 说明                    |
| ----------------------------------------- | ----------------------- |
| Promise\<[NROptionMode](#nroptionmode10)\> | 以Promise形式返回NR选项模式。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.getNROptionMode(slotId).then((data: radio.NROptionMode) => {
    console.log(`getNROptionMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNROptionMode failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkCapability<sup>10+</sup>

getNetworkCapability\(slotId: number, type: NetworkCapabilityType, callback: AsyncCallback\<NetworkCapabilityState\>\): void

获取指定网络类型的开关状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   |                              类型                                       | 必填 | 说明                                  |
| -------- | -----------------------------------------------------------------------| ---- | ----------------------------------- |
| slotId   | number                                                                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type     | [NetworkCapabilityType](#networkcapabilitytype10)                      | 是   | 网络能力类型。                        |
| callback | AsyncCallback\<[NetworkCapabilityState](#networkcapabilitystate10)\>   | 是   | 回调函数。返回指定网络类型的开关状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
radio.getNetworkCapability(slotId, type, (err: BusinessError, data: radio.NetworkCapabilityState) => {
    if (err) {
        console.error(`getNetworkCapability failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`getNetworkCapability success, callback: err->${JSON.stringify(err)}`);
});
```


## radio.getNetworkCapability<sup>10+</sup>

getNetworkCapability\(slotId: number, type: NetworkCapabilityType\): Promise\<NetworkCapabilityState\>

获取指定网络类型的开关状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   |                              类型                               | 必填 | 说明                                   |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type     | [NetworkCapabilityType](#networkcapabilitytype10)               | 是   | 网络能力类型。                        |

**返回值：**

| 类型                                                         | 说明                    |
| ------------------------------------------------------------- | ----------------------- |
| Promise\<[NetworkCapabilityState](#networkcapabilitystate10)\> | 以Promise形式返回指定网络类型的开关状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
radio.getNetworkCapability(slotId, type).then((data: radio.NetworkCapabilityState) => {
    console.log(`getNetworkCapability success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getNetworkCapability failed, promise: err->${JSON.stringify(err)}`);
});
```


## radio.setNetworkCapability<sup>10+</sup>

setNetworkCapability\(slotId: number, type: NetworkCapabilityType, state: NetworkCapabilityState,
      callback: AsyncCallback\<void\>\): void

设置指定网络类型的开关状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   |                              类型                               | 必填 | 说明                                   |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type     | [NetworkCapabilityType](#networkcapabilitytype10)               | 是   | 网络能力类型。                        |
| state    | [NetworkCapabilityState](#networkcapabilitystate10)             | 是   | 网络能力状态。                        |
| callback | AsyncCallback\<void\>                                           | 是   | 回调函数。返回设置指定网络类型的开关状态的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
let state: radio.NetworkCapabilityState = radio.NetworkCapabilityState.SERVICE_CAPABILITY_ON;
radio.setNetworkCapability(slotId, type, state, (err: BusinessError) => {
    if (err) {
        console.error(`setNetworkCapability failed, callback: err->${JSON.stringify(err)}`);
        return;
    }
    console.log(`setNetworkCapability success.`);
});
```


## radio.setNetworkCapability<sup>10+</sup>

setNetworkCapability\(slotId: number, type: NetworkCapabilityType, state: NetworkCapabilityState\): Promise\<void\>

设置指定网络类型的开关状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   |                              类型                               | 必填 | 说明                                   |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| type     | [NetworkCapabilityType](#networkcapabilitytype10)               | 是   | 网络能力类型。                        |
| state    | [NetworkCapabilityState](#networkcapabilitystate10)             | 是   | 网络能力状态。                        |

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回设置指定网络类型的开关状态的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
let type: radio.NetworkCapabilityType = radio.NetworkCapabilityType.SERVICE_TYPE_NR;
let state: radio.NetworkCapabilityState = radio.NetworkCapabilityState.SERVICE_CAPABILITY_ON;
radio.setNetworkCapability(slotId, type, state).then(() => {
    console.log(`setNetworkCapability success`);
}).catch((err: BusinessError) => {
    console.error(`setNetworkCapability failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.factoryReset<sup>11+</sup>

factoryReset\(slotId: number\): Promise\<void\>

重置网络状态设置。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   |                              类型                               | 必填 | 说明                                   |
| -------- | --------------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                          | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型            | 说明                    |
| --------------- | ----------------------- |
| Promise\<void\> | 以Promise形式返回重置网络状态设置的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';

let slotId: number = 0;
radio.factoryReset(slotId).then(() => {
    console.log(`factoryReset success`);
}).catch((err: BusinessError) => {
    console.error(`factoryReset failed, promise: err->${JSON.stringify(err)}`);
});
```

## radio.getIMEISV<sup>12+</sup>

getIMEISV\(slotId: number\): string

获取设备指定卡槽的软件版本号。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 否   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |


**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
let slotId: number = 0;
let data: string = radio.getIMEISV(slotId);
console.log(`IMEISV is:` + data);
```

## PreferredNetworkMode<sup>8+</sup>

首选网络模式。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                                                      | 值   | 说明                                          |
| --------------------------------------------------------- | ---- | --------------------------------------------- |
| PREFERRED_NETWORK_MODE_GSM                                | 1    | 首选GSM网络模式。                             |
| PREFERRED_NETWORK_MODE_WCDMA                              | 2    | 首选WCDMA网络模式。                           |
| PREFERRED_NETWORK_MODE_LTE                                | 3    | 首选LTE网络模式。                             |
| PREFERRED_NETWORK_MODE_LTE_WCDMA                          | 4    | 首选LTE WCDMA网络模式。                       |
| PREFERRED_NETWORK_MODE_LTE_WCDMA_GSM                      | 5    | 首选LTE WCDMA GSM网络模式。                   |
| PREFERRED_NETWORK_MODE_WCDMA_GSM                          | 6    | 首选WCDMA GSM网络模式。                       |
| PREFERRED_NETWORK_MODE_CDMA                               | 7    | 首选CDMA网络模式。                            |
| PREFERRED_NETWORK_MODE_EVDO                               | 8    | 首选EVDO网络模式。                            |
| PREFERRED_NETWORK_MODE_EVDO_CDMA                          | 9    | 首选EVDO CDMA网络模式。                       |
| PREFERRED_NETWORK_MODE_WCDMA_GSM_EVDO_CDMA                | 10   | 首选WCDMA GSM EVDO CDMA网络模式。             |
| PREFERRED_NETWORK_MODE_LTE_EVDO_CDMA                      | 11   | 首选LTE EVDO CDMA网络模式。                   |
| PREFERRED_NETWORK_MODE_LTE_WCDMA_GSM_EVDO_CDMA            | 12   | 首选LTE WCDMA GSM EVDO CDMA网络模式。         |
| PREFERRED_NETWORK_MODE_TDSCDMA                            | 13   | 首选TDSCDMA网络模式。                         |
| PREFERRED_NETWORK_MODE_TDSCDMA_GSM                        | 14   | 首选TDSCDMA GSM网络模式。                     |
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA                      | 15   | 首选TDSCDMA_WCDMA网络模式。                   |
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA_GSM                  | 16   | 首选TDSCDMA_WCDMA_GSM网络模式。               |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA                        | 17   | 首选LTE TDSCDMA网络模式。                     |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_GSM                    | 18   | 首选LTE TDSCDMA GSM网络模式。                 |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA                  | 19   | 首选LTE TDSCDMA WCDMA网络模式。               |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA_GSM              | 20   | 首选LTE TDSCDMA WCDMA GSM网络模式。           |
| PREFERRED_NETWORK_MODE_TDSCDMA_WCDMA_GSM_EVDO_CDMA        | 21   | 首选TDSCDMA WCDMA GSM EVDO CDMA网络模式。     |
| PREFERRED_NETWORK_MODE_LTE_TDSCDMA_WCDMA_GSM_EVDO_CDMA    | 22   | 首选LTE TDSCDMA WCDMA GSM EVDO CDMA网络模式。 |
| PREFERRED_NETWORK_MODE_NR                                 | 31   | 首选NR网络模式。                              |
| PREFERRED_NETWORK_MODE_NR_LTE                             | 32   | 首选NR LTE网络模式。                          |
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA                       | 33   | 首选NR LTE WCDMA网络模式。                    |
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA_GSM                   | 34   | 首选NR LTE WCDMA GSM网络模式。                |
| PREFERRED_NETWORK_MODE_NR_LTE_EVDO_CDMA                   | 35   | 首选NR LTE EVDO CDMA网络模式。                |
| PREFERRED_NETWORK_MODE_NR_LTE_WCDMA_GSM_EVDO_CDMA         | 36   | 首选NR LTE WCDMA GSM EVDO CDMA网络模式。      |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA                     | 37   | 首选NR LTE TDSCDMA网络模式。                  |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_GSM                 | 38   | 首选NR LTE TDSCDMA GSM网络模式。              |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA               | 39   | 首选NR LTE TDSCDMA WCDMA网络模式。            |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA_GSM           | 40   | 首选NR LTE TDSCDMA WCDMA GSM网络模式。        |
| PREFERRED_NETWORK_MODE_NR_LTE_TDSCDMA_WCDMA_GSM_EVDO_CDMA | 41   | 首选NR LTE TDSCDMA WCDMA GSM EVDO CDMA网络模式。        |
| PREFERRED_NETWORK_MODE_MAX_VALUE                          | 99   | 首选网络模式最大值。                          |

## CellInformation<sup>8+</sup>

小区信息。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称              |                  类型                   | 必填 |                           说明                               |
| ----------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |                           
| isCamped          | boolean                                 |  是  | 获取服务单元的状态。<br>**系统接口：** 此接口为系统接口。<br/>true表示驻留小区，false表示非驻留小区。          |
| timeStamp         | number                                  |  是  | 获取单元格信息时获取时间戳。<br>**系统接口：** 此接口为系统接口。    |                              
| data              | [CdmaCellInformation](#cdmacellinformation8) \| [GsmCellInformation](#gsmcellinformation8) \| [LteCellInformation](#ltecellinformation8) \| [NrCellInformation](#nrcellinformation8) \| [TdscdmaCellInformation](#tdscdmacellinformation8)\|[WcdmaCellInformation](#wcdmacellinformation8) |  是  | Cdma小区信息 \|Gsm小区信息\|Lte小区信息\|Nr小区信息\|Tdscdma小区信息\|Wcdma小区信息。  <br>**系统接口：** 此接口为系统接口。|

## CdmaCellInformation<sup>8+</sup>

CDMA小区信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称      | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ------------ |
| baseId    | number |  是  | 基站Id。     |
| latitude  | number |  是  | 纬度。       |
| longitude | number |  是  | 经度。       |
| nid       | number |  是  | 网络识别码。 |
| sid       | number |  是  | 系统识别码。 |

## GsmCellInformation<sup>8+</sup>

GSM小区信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称   | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| lac    | number |  是  | 位置区编号。         |
| cellId | number |  是  | 小区号。             |
| arfcn  | number |  是  | 绝对无线频率信道号。 |
| bsic   | number |  是  | 基站识别号。         |
| mcc    | string |  是  | 移动国家码。         |
| mnc    | string |  是  | 移动网号。           |

## LteCellInformation<sup>8+</sup>

LTE小区信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称          | 类型    | 必填 | 说明                    |
| ------------- | ------- | ---- | ----------------------- |
| cgi           | number  |  是  | 小区全球标识。          |
| pci           | number  |  是  | 物理小区识别。          |
| tac           | number  |  是  | 跟踪区域代码。          |
| earfcn        | number  |  是  | 绝对无线频率信道号。    |
| bandwidth     | number  |  是  | 带宽。                  |
| mcc           | string  |  是  | 移动国家码。            |
| mnc           | string  |  是  | 移动网号。              |
| isSupportEndc | boolean |  是  | 是否支持新无线电_双连接。 |

## NrCellInformation<sup>8+</sup>

NR小区信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称    | 类型   | 必填 | 说明             |
| ------- | ------ | ---- | ---------------- |
| nrArfcn | number |  是  | 5G频点号。       |
| pci     | number |  是  | 物理小区识别。   |
| tac     | number |  是  | 跟踪区域代码。   |
| nci     | number |  是  | 5G网络小区标识。 |
| mcc     | string |  是  | 移动国家码。     |
| mnc     | string |  是  | 移动网号。       |

## TdscdmaCellInformation<sup>8+</sup>

TD-SCDMA小区信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称   | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| lac    | number |  是  | 位置区编号。 |
| cellId | number |  是  | 小区号。     |
| cpid   | number |  是  | 小区参数Id。 |
| uarfcn | number |  是  | 绝对射频号。 |
| mcc    | string |  是  | 移动国家码。 |
| mnc    | string |  是  | 移动网号。   |

## WcdmaCellInformation<sup>8+</sup>

WCDMA小区信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称   | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| lac    | number |  是  | 位置区编号。 |
| cellId | number |  是  | 小区号。     |
| psc    | number |  是  | 主扰码。     |
| uarfcn | number |  是  | 绝对射频号。 |
| mcc    | string |  是  | 移动国家码。 |
| mnc    | string |  是  | 移动网号。   |

## NrOptionMode<sup>(deprecated)</sup>

NR的选择模式。

> **说明：**
>
> 从 API version 8开始支持，从API version 10开始废弃。建议使用[NROptionMode](#nroptionmode10)替代。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                 | 值   | 说明                               |
| -------------------- | ---- | ---------------------------------- |
| NR_OPTION_UNKNOWN    | 0    | 未知的NR选择模式。                 |
| NR_OPTION_NSA_ONLY   | 1    | 仅非独立组网的NR选择模式。         |
| NR_OPTION_SA_ONLY    | 2    | 仅独立组网的NR选择模式。           |
| NR_OPTION_NSA_AND_SA | 3    | 非独立组网和独立组网的NR选择模式。 |

## NROptionMode<sup>10+</sup>

NR的选择模式。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                 | 值   | 说明                              |
| -------------------- | ---- | --------------------------------- |
| NR_OPTION_UNKNOWN    | 0    | 未知的NR选择模式。                 |
| NR_OPTION_NSA_ONLY   | 1    | 仅非独立组网的NR选择模式。         |
| NR_OPTION_SA_ONLY    | 2    | 仅独立组网的NR选择模式。           |
| NR_OPTION_NSA_AND_SA | 3    | 非独立组网和独立组网的NR选择模式。  |

## NetworkSearchResult

网络搜索结果。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                   | 类型                                              | 必填 | 说明           |
| ---------------------- | ------------------------------------------------- | ---- | -------------- |
| isNetworkSearchSuccess | boolean                                           |  是  | 网络搜索成功。 |
| networkSearchResult    | Array<[NetworkInformation](#networkinformation)\> |  是  | 网络搜索结果。 |

## NetworkInformation

网络信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称            |                         类型                        | 必填 | 说明           |
| --------------- | --------------------------------------------------- | ---- | -------------- |
| operatorName    | string                                              |  是  | 运营商的名称。 |
| operatorNumeric | string                                              |  是  | 运营商数字。   |
| state           | [NetworkInformationState](#networkinformationstate) |  是  | 网络信息状态。 |
| radioTech       | string                                              |  是  | 无线电技术。   |

## NetworkInformationState

网络信息状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称              | 值   | 说明             |
| ----------------- | ---- | ---------------- |
| NETWORK_UNKNOWN   | 0    | 网络状态未知。   |
| NETWORK_AVAILABLE | 1    | 网络可用于注册。 |
| NETWORK_CURRENT   | 2    | 已在网络中注册。 |
| NETWORK_FORBIDDEN | 3    | 网络无法注册。   |

## NetworkSelectionModeOptions

网络选择模式选项。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称               |                    类型                       | 必填 |                 说明                   |
| ------------------ | --------------------------------------------- | ---- | -------------------------------------- |
| slotId             | number                                        |  是  | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| selectMode         | [NetworkSelectionMode](js-apis-radio.md#networkselectionmode) |  是  | 网络选择模式。                         |
| networkInformation | [NetworkInformation](#networkinformation)     |  是  | 网络信息。                             |
| resumeSelection    | boolean                                       |  是  | 继续选择。                             |

## ImsRegState<sup>9+</sup>

IMS注册状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称             | 值   | 说明     |
| ---------------- | ---- | -------- |
| IMS_UNREGISTERED | 0    | 未注册。 |
| IMS_REGISTERED   | 1    | 已注册。 |

## ImsRegTech<sup>9+</sup>

IMS注册技术。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                    | 值   | 说明            |
| ----------------------- | ---- | --------------- |
| REGISTRATION_TECH_NONE  | 0    | 无注册技术。    |
| REGISTRATION_TECH_LTE   | 1    | LTE注册技术。   |
| REGISTRATION_TECH_IWLAN | 2    | IWLAN注册技术。 |
| REGISTRATION_TECH_NR    | 3    | NR注册技术。    |

## ImsRegInfo<sup>9+</sup>

IMS注册信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称        | 类型                         | 必填 | 说明          |
| ----------- | ---------------------------- | ---- | ------------- |
| imsRegState | [ImsRegState](#imsregstate9) |  是  | IMS注册状态。 |
| imsRegTech  | [ImsRegTech](#imsregtech9)   |  是  | IMS注册技术。 |

## ImsServiceType<sup>9+</sup>

IMS服务类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称       | 值   | 说明       |
| ---------- | ---- | ---------- |
| TYPE_VOICE | 0    | 语音服务。 |
| TYPE_VIDEO | 1    | 视频服务。 |
| TYPE_UT    | 2    | UT服务。   |
| TYPE_SMS   | 3    | 短讯服务。 |

## NetworkCapabilityType<sup>10+</sup>

网络能力类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称             | 值   | 说明       |
| -----------------| ---- | ---------- |
| SERVICE_TYPE_LTE | 0    | LTE服务类型。 |
| SERVICE_TYPE_NR  | 1    | NR服务类型。 |

## NetworkCapabilityState<sup>10+</sup>

网络能力开关状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                   | 值   | 说明       |
| -----------------------| ---- | ---------- |
| SERVICE_CAPABILITY_OFF | 0    | 网络能力关闭。 |
| SERVICE_CAPABILITY_ON  | 1    | 网络能力打开。 |
