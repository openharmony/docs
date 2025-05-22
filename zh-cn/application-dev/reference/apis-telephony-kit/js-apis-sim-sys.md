# @ohos.telephony.sim (SIM卡管理)（系统接口）

SIM卡管理模块提供了SIM卡管理的基础能力，包括获取指定卡槽SIM卡的名称、号码、ISO国家码、归属PLMN号、服务提供商名称、SIM卡状态、卡类型、是否插卡、是否激活、锁状态，设置指定卡槽SIM卡显示的名称、号码、锁状态，激活、禁用指定卡槽SIM卡，更改Pin密码，以及解锁指定卡槽SIM卡密码、SIM卡密码的解锁密码等。

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.telephony.sim (SIM卡管理)](js-apis-sim.md)

## 导入模块

```ts
import { sim } from '@kit.TelephonyKit';
```

## sim.isOperatorSimCard<sup>11+</sup>

isOperatorSimCard\(slotId: number, operator: OperatorSimCard\): boolean

获取指定卡槽SIM卡是否为指定运营商卡。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型                                     | 必填 | 说明                                |
| ------ | --------------------------------------- | ---- | ---------------------------------  |
| slotId | number                                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| operator | [OperatorSimCard](#operatorsimcard11) | 是   | 运营商卡名称。(当前仅支持中国电信卡)|

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| boolean | 返回指定卡槽是否为指定运营商卡<br/>- true：是<br/>- false：否 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let slotId : number = 0;
let operator : sim.OperatorSimCard = sim.OperatorSimCard.CHINA_TELECOM_CARD;
try {
    let isOperatorSimCard: boolean = sim.isOperatorSimCard(slotId, operator);
    console.log(`is operator sim card: ` + isOperatorSimCard);
} catch (err) {
    console.error("isOperatorSimCard err: " + JSON.stringify(err));
}
```

## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId\(slotId: number, callback: AsyncCallback\<void\>\): void

设置默认语音业务的卡槽ID。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | 是   | SIM卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.setDefaultVoiceSlotId(0, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId\(slotId: number\): Promise\<void\>

设置默认语音业务的卡槽ID。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.setDefaultVoiceSlotId(0).then(() => {
    console.log(`setDefaultVoiceSlotId success.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setShowName<sup>8+</sup>

setShowName\(slotId: number, name: string, callback: AsyncCallback\<void\>\): void

设置指定卡槽SIM卡显示的名称。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| name     | string                    | 是   | SIM卡名称。                              |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let name: string = "ShowName";
sim.setShowName(0, name, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```

## sim.setShowName<sup>8+</sup>

setShowName\(slotId: number, name: string\): Promise\<void\>

设置指定卡槽SIM卡显示的名称。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| name   | string | 是   | SIM卡名称。                              |

**返回值：**

| 类型            | 说明                            |
| --------------- | ------------------------------- |
| Promise\<void\> | 以Promise形式异步返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let name: string = "ShowName";
sim.setShowName(0, name).then(() => {
    console.log(`setShowName success.`);
}).catch((err: BusinessError) => {
    console.error(`setShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getShowName<sup>8+</sup>

getShowName\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽SIM卡的名称。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。返回指定卡槽SIM卡的名称。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getShowName(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getShowName<sup>8+</sup>

getShowName\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的名称。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;string&gt; | 以Promise形式返回指定卡槽SIM卡的名称。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getShowName(0).then((data: string) => {
    console.log(`getShowName success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setShowNumber<sup>8+</sup>

setShowNumber\(slotId: number, number: string, callback: AsyncCallback\<void\>\): void

设置指定卡槽SIM卡的号码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| number   | string                    | 是   | SIM卡号码。                              |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let number: string = '+861xxxxxxxxxx';
sim.setShowNumber(0, number, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.setShowNumber<sup>8+</sup>

setShowNumber\(slotId: number, number: string\): Promise\<void\>

设置指定卡槽SIM卡的号码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| number | string | 是   | SIM卡号码。                              |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise<void\> | 以Promise形式异步返回设置结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let number: string = '+861xxxxxxxxxx';
sim.setShowNumber(0, number).then(() => {
    console.log(`setShowNumber success.`);
}).catch((err: BusinessError) => {
    console.error(`setShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getShowNumber<sup>8+</sup>

getShowNumber\(slotId: number, callback: AsyncCallback\<string\>): void

获取指定卡槽SIM卡的号码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。返回指定卡槽的号码。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getShowNumber(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getShowNumber<sup>8+</sup>

getShowNumber\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的号码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                              |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | 以Promise形式返回指定卡槽的号码。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getShowNumber(0).then((data: string) => {
    console.log(`getShowNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.activateSim<sup>8+</sup>

activateSim\(slotId: number, callback: AsyncCallback\<void\>\): void

激活指定卡槽SIM卡。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.activateSim(0, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.activateSim<sup>8+</sup>

activateSim\(slotId: number\): Promise\<void\>

激活指定卡槽SIM卡。使用Promise异步回调。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.activateSim(0).then(() => {
    console.log(`activateSim success.`);
}).catch((err: BusinessError) => {
    console.error(`activateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.deactivateSim<sup>8+</sup>

deactivateSim\(slotId: number, callback: AsyncCallback\<void\>\): void

禁用指定卡槽SIM卡。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.deactivateSim(0, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.deactivateSim<sup>8+</sup>

deactivateSim\(slotId: number\): Promise\<void\>

禁用指定卡槽SIM卡。使用Promise异步回调。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.deactivateSim(0).then(() => {
    console.log(`deactivateSim success.`);
}).catch((err: BusinessError) => {
    console.error(`deactivateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setLockState<sup>7+</sup>

setLockState\(slotId: number, options: LockInfo, callback: AsyncCallback\<LockStatusResponse\>\): void

设置指定卡槽SIM卡的锁状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                                                   |
| options  | [LockInfo](#lockinfo8)                                      | 是   | 锁信息。<br/>- lockType: [LockType](#locktype8)<br/>- password: string<br/>- state: [LockState](#lockstate8) |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let lockInfo: sim.LockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
sim.setLockState(0, lockInfo, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setLockState<sup>7+</sup>

setLockState\(slotId: number, options: LockInfo\): Promise\<LockStatusResponse\>

设置指定卡槽SIM卡的锁状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型                   | 必填 | 说明                                                         |
| ------- | ---------------------- | ---- | ------------------------------------------------------------ |
| slotId  | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| options | [LockInfo](#lockinfo8) | 是   | 锁信息。<br/>- lockType: [LockType](#locktype8)<br/>- password: string<br/>- state: [LockState](#lockstate8) |

**返回值：**

| 类型                                                 | 说明                                         |
| ---------------------------------------------------- | -------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回获取指定卡槽SIM卡的锁状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let lockInfo: sim.LockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
sim.setLockState(0, lockInfo).then((data: sim.LockStatusResponse) => {
    console.log(`setLockState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`setLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getLockState<sup>8+</sup>

getLockState\(slotId: number, lockType: LockType, callback: AsyncCallback\<LockState\>\): void

获取指定卡槽SIM卡的锁状态。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                    |
| -------- | ----------------------------------------- | ---- | --------------------------------------- |
| slotId   | number                                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |
| callback | AsyncCallback\<[LockState](#lockstate8)\> | 是   | 回调函数。                              |
| options  | [LockType](#locktype8)                    | 是   | 锁类型。<br/>- 1: PIN锁<br/>- 2: PIN2锁 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getLockState(0, 1, (err: BusinessError, data: sim.LockState) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getLockState<sup>8+</sup>

getLockState\(slotId: number, lockType: LockType\): Promise\<LockState\>

获取指定卡槽SIM卡的锁状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型                   | 必填 | 说明                                    |
| ------- | ---------------------- | ---- | --------------------------------------- |
| slotId  | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |
| options | [LockType](#locktype8) | 是   | 锁类型。<br/>- 1: PIN锁<br/>- 2: PIN2锁 |

**返回值：**

| 类型                               | 说明                                         |
| ---------------------------------- | -------------------------------------------- |
| Promise<[LockState](#lockstate8)\> | 以Promise形式返回获取指定卡槽SIM卡的锁状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getLockState(0, 1).then((data: sim.LockState) => {
    console.log(`getLockState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin<sup>7+</sup>

alterPin\(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback\<LockStatusResponse\>\): void

更改Pin密码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                   |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                             |
| newPin   | string                                                      | 是   | 新密码。                               |
| oldPin   | string                                                      | 是   | 旧密码。                               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.alterPin(0, "1234", "0000", (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin<sup>7+</sup>

alterPin\(slotId: number, newPin: string, oldPin: string\): Promise\<LockStatusResponse\>

更改Pin密码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin | string | 是   | 新密码。                               |
| oldPin | string | 是   | 旧密码。                               |

**返回值：**

| 类型                                                 | 说明                                          |
| ---------------------------------------------------- | --------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回指定卡槽SIM卡的Pin是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.alterPin(0, "1234", "0000").then((data: sim.LockStatusResponse) => {
    console.log(`alterPin success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`alterPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin2<sup>8+</sup>

alterPin2\(slotId: number, newPin2: string, oldPin2: string, callback: AsyncCallback\<LockStatusResponse\>\): void

更改Pin2密码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                   |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                             |
| newPin2  | string                                                      | 是   | 新密码。                               |
| oldPin2  | string                                                      | 是   | 旧密码。                               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.alterPin2(0, "1234", "0000", (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin2<sup>8+</sup>

alterPin2\(slotId: number, newPin2: string, oldPin2: string\): Promise\<LockStatusResponse\>

更改Pin2密码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型   | 必填 | 说明                                   |
| ------- | ------ | ---- | -------------------------------------- |
| slotId  | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin2 | string | 是   | 新密码。                               |
| oldPin2 | string | 是   | 旧密码。                               |

**返回值：**

| 类型                                                 | 说明                                          |
| ---------------------------------------------------- | --------------------------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回指定卡槽SIM卡的Pin是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.alterPin2(0, "1234", "0000").then((data: sim.LockStatusResponse) => {
    console.log(`alterPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`alterPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPin<sup>7+</sup>

unlockPin\(slotId: number, pin: string, callback: AsyncCallback\<LockStatusResponse\>\): void

解锁指定卡槽SIM卡密码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin      | string                                                       | 是   | SIM卡的密码。                            |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let pin: string = '1234';
sim.unlockPin(0, pin, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPin<sup>7+</sup>

unlockPin\(slotId: number, pin: string\): Promise\<LockStatusResponse\>

解锁指定卡槽SIM卡密码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin    | string | 是   | SIM卡的密码。                            |

**返回值：**

| 类型                                                 | 说明                                               |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let pin: string = '1234';
sim.unlockPin(0, pin).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPin success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPuk<sup>7+</sup>

unlockPuk\(slotId: number, newPin: string, puk: string, callback: AsyncCallback\<LockStatusResponse\>\): void

解锁指定卡槽SIM卡密码的解锁密码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin   | string                                                       | 是   | 重置SIM卡的密码。                        |
| puk      | string                                                       | 是   | SIM卡密码的解锁密码。                    |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let puk: string = '1xxxxxxx';
let newPin: string = '1235';
sim.unlockPuk(0, newPin, puk, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPuk<sup>7+</sup>

unlockPuk\(slotId: number, newPin: string, puk: string\): Promise\<LockStatusResponse\>

解锁指定卡槽SIM卡密码的解锁密码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin | string | 是   | 重置SIM卡的密码。                        |
| puk    | string | 是   | SIM卡密码的解锁密码。                    |

**返回值：**

| 类型                                                 | 说明                                               |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let puk: string = '1xxxxxxx';
let newPin: string = '1235';
sim.unlockPuk(0, newPin, puk).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPuk success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPuk failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPin2<sup>8+</sup>

unlockPin2\(slotId: number, pin2: string, callback: AsyncCallback\<LockStatusResponse\>\): void

解锁指定卡槽SIM卡密码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin2     | string                                                       | 是   | SIM卡的密码。                            |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let pin2: string = '1234';
sim.unlockPin2(0, pin2, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPin2<sup>8+</sup>

unlockPin2\(slotId: number, pin2: string\): Promise\<LockStatusResponse\>

解锁指定卡槽SIM卡密码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin2   | string | 是   | SIM卡的密码。                            |

**返回值：**

| 类型                                                  | 说明                                               |
| ----------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let pin2: string = '1234';
sim.unlockPin2(0, pin2).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockPuk2<sup>8+</sup>

unlockPuk2\(slotId: number, newPin2: string, puk2: string, callback: AsyncCallback\<LockStatusResponse\>\): void

解锁指定卡槽SIM卡密码的解锁密码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin2  | string                                                       | 是   | 重置SIM卡的密码。                        |
| puk2     | string                                                       | 是   | SIM卡密码的解锁密码。                    |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let puk2: string = '1xxxxxxx';
let newPin2: string = '1235';
sim.unlockPuk2(0, newPin2, puk2, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockPuk2<sup>8+</sup>

unlockPuk2\(slotId: number, newPin2: string, puk2: string\): Promise\<LockStatusResponse\>

解锁指定卡槽SIM卡密码的解锁密码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型   | 必填 | 说明                                   |
| ------- | ------ | ---- | -------------------------------------- |
| slotId  | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin2 | string | 是   | 重置SIM卡的密码。                        |
| puk2    | string | 是   | SIM卡密码的解锁密码。                    |

**返回值：**

| 类型                                                 | 说明                                               |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let puk2: string = '1xxxxxxx';
let newPin2: string = '1235';
sim.unlockPuk2(0, newPin2, puk2).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPuk2 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPuk2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimIccId<sup>7+</sup>

getSimIccId\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽SIM卡的ICCID。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimIccId(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimIccId<sup>7+</sup>

getSimIccId\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的ICCID。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                        |
| ---------------- | ------------------------------------------- |
| Promise<string\> | 以Promise形式返回获取指定卡槽SIM卡的ICCID。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimIccId(0).then((data:string) => {
    console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimIccId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽中SIM卡语音信箱的alpha标识符。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getVoiceMailIdentifier(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier\(slotId: number\): Promise\<string\>

获取指定卡槽中SIM卡语音信箱的alpha标识符。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------- |
| Promise<string\> | 以Promise形式返回获取指定卡槽SIM卡的alpha标识符。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getVoiceMailIdentifier(0).then((data: string) => {
    console.log(`getVoiceMailIdentifier success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getVoiceMailIdentifier failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber\(slotId: number, callback: AsyncCallback\<string\>): void

获取指定卡槽中SIM卡的语音信箱号。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getVoiceMailNumber(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber\(slotId: number\): Promise\<string\>

获取指定卡槽中SIM卡的语音信箱号。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                             |
| ---------------- | ------------------------------------------------ |
| Promise<string\> | 以Promise形式返回获取指定卡槽SIM卡的语音信箱号。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getVoiceMailNumber(0).then((data: string) => {
    console.log(`getVoiceMailNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getVoiceMailNumber failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo\(slotId: number, mailName: string, mailNumber: string, callback: AsyncCallback\<void\>\): void

设置语音邮件信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                   |
| ---------- | -------------------- | ---- | -------------------------------------- |
| slotId     | number               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| mailName   | string               | 是   | 邮件名字                               |
| mailNumber | string               | 是   | 邮件号码                               |
| callback   | AsyncCallback<void\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com", (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo\(slotId: number, mailName: string, mailNumber: string\): Promise\<void\>

设置语音邮件信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名     | 类型   | 必填 | 说明                                   |
| ---------- | ------ | ---- | -------------------------------------- |
| slotId     | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| mailName   | string | 是   | 邮件名字。                               |
| mailNumber | string | 是   | 邮件号码。                               |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| Promise<void\> | 以Promise形式返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com").then(() => {
    console.log(`setVoiceMailInfo success.`);
}).catch((err: BusinessError) => {
    console.error(`setVoiceMailInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽中SIM卡的MSISDN。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_PHONE_NUMBERS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimTelephoneNumber(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber\(slotId: number\): Promise\<string\>

获取指定卡槽中SIM卡的MSISDN。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_PHONE_NUMBERS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                         |
| ---------------- | -------------------------------------------- |
| Promise<string\> | 以Promise形式返回获取指定卡槽SIM卡的MSISDN。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimTelephoneNumber(0).then((data: string) => {
    console.log(`getSimTelephoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimTelephoneNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimGid1<sup>7+</sup>

getSimGid1\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽中SIM卡的组标识符级别1（GID1）。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimGid1(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimGid1<sup>7+</sup>

getSimGid1\(slotId: number\): Promise\<string\>

获取指定卡槽中SIM卡的组标识符级别1（GID1）。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------- |
| Promise<string\> | 以Promise形式返回获取指定卡槽SIM卡的标识符级别1。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimGid1(0).then((data: string) => {
    console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimGid1 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getIMSI

getIMSI\(slotId: number, callback: AsyncCallback\<string\>\): void

获取国际移动用户识别码。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getIMSI(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getIMSI

getIMSI\(slotId: number\): Promise\<string\>

获取国际移动用户识别码。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                        |
| ---------------- | ------------------------------------------- |
| Promise<string\> | 以Promise形式返回获取的国际移动用户识别码。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getIMSI(0).then((data: string) => {
    console.log(`getIMSI success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getIMSI failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs\(slotId: number, callback: AsyncCallback\<Array\<OperatorConfig\>\>\): void

获取运营商配置。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                   |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<Array<[OperatorConfig](#operatorconfig8)\>> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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
import { sim } from '@kit.TelephonyKit';

sim.getOperatorConfigs(0, (err: BusinessError, data: Array<sim.OperatorConfig>) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs\(slotId: number\): Promise\<Array\<OperatorConfig\>\>

获取运营商配置。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                                | 说明                          |
| --------------------------------------------------- | ----------------------------- |
| Promise<Array<[OperatorConfig](#operatorconfig8)\>> | 以Promise形式返回运营商配置。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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
import { sim } from '@kit.TelephonyKit';

sim.getOperatorConfigs(0).then((data: Array<sim.OperatorConfig>) => {
    console.log(`getOperatorConfigs success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getOperatorConfigs failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers\(slotId: number, type: ContactType, callback: AsyncCallback\<Array\<DiallingNumbersInfo\>\>\): void

查询SIM卡联系人号码。使用callback异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type     | [ContactType](#contacttype8)                                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| callback | AsyncCallback<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> | 是   | 回调函数。                                          |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.queryIccDiallingNumbers(0, 1, (err: BusinessError, data: Array<sim.DiallingNumbersInfo>) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers\(slotId: number, type: ContactType\): Promise\<Array\<DiallingNumbersInfo\>\>

查询SIM卡联系人号码。使用Promise异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型        | 必填 | 说明                                                       |
| ------ | ----------- | ---- | ---------------------------------------------------------- |
| slotId | number      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type   | [ContactType](#contacttype8)  | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |

**返回值：**

| 类型                                                         | 说明                           |
| ------------------------------------------------------------ | ------------------------------ |
| Promise<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> | 以Promise形式返回Icc拨号号码。|

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.queryIccDiallingNumbers(0, 1).then((data:  Array<sim.DiallingNumbersInfo>) => {
    console.log(`queryIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`queryIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void\>\): void

添加SIM卡联系人号码。使用callback异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |
| callback        | AsyncCallback<void\>                         | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    pin2: "1234"
};
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo\): Promise\<void\>

添加SIM卡联系人号码。使用Promise异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 以Promise形式返回添加结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {
    console.log(`addIccDiallingNumbers success.`);
}).catch((err: BusinessError) => {
    console.error(`addIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void\>\): void

删除SIM卡联系人号码。使用callback异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |
| callback        | AsyncCallback<void\>                         | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123,
    pin2: "1234"
};
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo\): Promise\<void\>

删除SIM卡联系人号码。使用Promise异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 以Promise形式返回删除结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {
    console.log(`delIccDiallingNumbers success.`);
}).catch((err: BusinessError) => {
    console.error(`delIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback\<void\>\): void 

更新SIM卡联系人号码。使用callback异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |
| callback        | AsyncCallback<void\>                         | 是   | 回调函数。                                                   |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123,
    pin2: "1234"
};
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers\(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo\): Promise\<void\>

更新SIM卡联系人号码。使用Promise异步回调。

>**说明：** 
>
>SIM卡联系人存在缓存机制，对联系人进行增删改操作时会维护一套由卡槽slotId和联系人类型type对应的SIM卡联系人缓存，所以需要先调用sim.queryIccDiallingNumbers接口传入所需的slotId和type查询SIM卡联系人，生成缓存数据，在没有缓存的情况下直接调用sim.addIccDiallingNumbers、sim.delIccDiallingNumbers、sim.updateIccDiallingNumbers等接口会失败。
>

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise<void\> | 以Promise形式返回更新的结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let diallingNumbersInof: sim.DiallingNumbersInfo = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123
};
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof).then(() => {
    console.log(`updateIccDiallingNumbers success.`);
}).catch((err: BusinessError) => {
    console.error(`updateIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd\(slotId: number, cmd: string, callback: AsyncCallback\<void\>\): void

发送信封命令。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                   |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| cmd      | string               | 是   | 命令。                                   |
| callback | AsyncCallback<void\> | 是   | 回调函数。                                     |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.sendEnvelopeCmd(0, "ls", (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd\(slotId: number, cmd: string\): Promise\<void\>

发送信封命令。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| cmd    | string | 是   | 命令。                                   |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 以Promise形式返回发送结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.sendEnvelopeCmd(0, "ls").then(() => {
    console.log(`sendEnvelopeCmd success.`);
}).catch((err: BusinessError) => {
    console.error(`sendEnvelopeCmd failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd\(slotId: number, cmd: string, callback: AsyncCallback\<void\>\): void

发送终端响应命令。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                   |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| cmd      | string               | 是   | 命令。                                   |
| callback | AsyncCallback<void\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.sendTerminalResponseCmd(0, "ls", (err: BusinessError) => {
    console.log(`callback: err->${JSON.stringify(err)}`);
});
```


## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd\(slotId: number, cmd: string\): Promise\<void\>

发送终端响应命令。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| cmd    | string | 是   | 命令。                                   |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 以Promise形式返回发送结果。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.sendTerminalResponseCmd(0, "ls").then(() => {
    console.log(`sendTerminalResponseCmd success.`);
}).catch((err: BusinessError) => {
    console.error(`sendTerminalResponseCmd failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.unlockSimLock<sup>8+</sup>

unlockSimLock\(slotId: number, lockInfo: PersoLockInfo, callback: AsyncCallback\<LockStatusResponse\>\): void

解锁SIM卡锁。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                   |
| -------- | ---------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                     | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| lockInfo | [PersoLockInfo](#persolockinfo8)                           | 是   | 定制锁类型信息。                         |
| callback | AsyncCallback<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let persoLockInfo: sim.PersoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
sim.unlockSimLock(0, persoLockInfo, (err: BusinessError, data: sim.LockStatusResponse) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockSimLock<sup>8+</sup>

unlockSimLock\(slotId: number, lockInfo: PersoLockInfo\): Promise\<LockStatusResponse\>

解锁SIM卡锁。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                   |
| -------- | -------------------------------- | ---- | -------------------------------------- |
| slotId   | number                           | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| lockInfo | [PersoLockInfo](#persolockinfo8) | 是   | 定制锁类型信息。                         |

**返回值：**

| 类型                                                 | 说明                      |
| ---------------------------------------------------- | ------------------------- |
| Promise<[LockStatusResponse](#lockstatusresponse7)\> | 以Promise形式返回锁状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

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
| 8301002  | The SIM card failed to read or update data.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let persoLockInfo: sim.PersoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
sim.unlockSimLock(0, persoLockInfo).then((data: sim.LockStatusResponse) => {
    console.log(`unlockSimLock success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockSimLock failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getDsdsMode<sup>11+</sup>

getDsdsMode\(callback: AsyncCallback\<DsdsMode\>\): void

获取设备支持的DSDS（Dual Sim Dual Standby） Mode。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明       |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;DsdsMode&gt; | 是   | 回调函数。返回设备支持的DSDS Mode。<br/>- 0：DSDS_MODE_V2<br/>- 1：DSDS_MODE_V3<br/>- 2：DSDS_MODE_V5_TDM<br/>- 3：DSDS_MODE_V5_DSDA |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getDsdsMode((err: BusinessError, data: sim.DsdsMode) => {
    if (err) {
        console.error(`getDsdsMode failed, callback: err->${JSON.stringify(err)}`);
    } else {
        console.log(`getDsdsMode success, callback: data->${JSON.stringify(data)}`);
    }
});
```

## sim.getDsdsMode<sup>11+</sup>

getDsdsMode\(\): Promise\<DsdsMode\>

获取设备支持的DSDS（Dual Sim Dual Standby） Mode。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<DsdsMode\> | 以Promise形式返回设备支持的DSDS Mode。<br/>- 0：DSDS_MODE_V2<br/>- 1：DSDS_MODE_V3<br/>- 2：DSDS_MODE_V5_TDM<br/>- 3：DSDS_MODE_V5_DSDA |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

let promise = sim.getDsdsMode();
promise.then((data: sim.DsdsMode) => {
    console.log(`getDsdsMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDsdsMode failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimAuthentication<sup>14+</sup>

getSimAuthentication\(slotId: number, authType: AuthType, authData: string\): Promise\<SimAuthenticationResponse\>

SIM卡鉴权。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                   |
| -------- | -------------------------------- | ---- | -------------------------------------- |
| slotId   | number                           | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| authType | [AuthType](#authtype14)          | 是   | 身份验证类型。                         |
| authData | string                           | 是   | 密码或其他认证信息。                   |

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<[SimAuthenticationResponse](#simauthenticationresponse14)\> | 以Promise形式返回身份验证响应的字符串。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card.                                 |
| 8300999  | Unknown error.                               |
| 8301002  | An error occurred when operating the SIM card.                              |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimAuthentication(0, sim.AuthType.SIM_AUTH_EAP_SIM_TYPE, "test").then(() => {
    console.log(`getSimAuthentication success.`);
}).catch((err: BusinessError) => {
    console.error(`getSimAuthentication failed, promise: err->${JSON.stringify(err)}`);
});
```

## LockType<sup>8+</sup>

锁类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称     | 值   | 说明        |
| -------- | ---- | ----------- |
| PIN_LOCK | 1    | SIM卡密码锁。 |
| FDN_LOCK | 2    | 固定拨号锁。  |

## LockState<sup>8+</sup>

锁状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称     | 值   | 说明       |
| -------- | ---- | ---------- |
| LOCK_OFF | 0    | 锁关闭状态。 |
| LOCK_ON  | 1    | 锁开启状态。 |

## PersoLockType<sup>8+</sup>

定制锁类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称         | 值   | 说明                                             |
| ------------ | ---- | ------------------------------------------------ |
| PN_PIN_LOCK  | 0    | 定制网络PIN锁(参照 3GPP TS 22.022 [33])。         |
| PN_PUK_LOCK  | 1    | 定制网络PUk锁。                                   |
| PU_PIN_LOCK  | 2    | 定制网络子集PIN锁(参照 3GPP TS 22.022 [33])。     |
| PU_PUK_LOCK  | 3    | 定制网络子集PUK锁。                               |
| PP_PIN_LOCK  | 4    | 定制服务提供者PIN锁(参照 3GPP TS 22.022 [33])。   |
| PP_PUK_LOCK  | 5    | 定制服务提供者PUK锁。                             |
| PC_PIN_LOCK  | 6    | 定制企业PIN锁(参照 3GPP TS 22.022 [33])。         |
| PC_PUK_LOCK  | 7    | 定制企业Puk锁。                                   |
| SIM_PIN_LOCK | 8    | 定制SIM的PIN锁(参照 3GPP TS 22.022 [33])。        |
| SIM_PUK_LOCK | 9    | 定制SIM的PUK锁。                                  |

## LockStatusResponse<sup>7+</sup>

锁状态响应。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称            | 类型   | 必填 | 说明                  |
| --------------- | ------ | ---- | --------------------- |
| result          | number |  是  | 当前操作的结果。      |
| remain          | number |  否  | 剩余次数（可以为空）。|

## LockInfo<sup>8+</sup>

锁状态响应。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称     |           类型           | 必填 |   说明   |
| -------- | ------------------------ | ---- | -------- |
| lockType | [LockType](#locktype8)   |  是  | 锁类型。 |
| password | string                   |  是  | 密码。   |
| state    | [LockState](#lockstate8) |  是  | 锁状态。 |

## PersoLockInfo<sup>8+</sup>

锁状态响应。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称     |               类型               | 必填 |      说明     |
| -------- | -------------------------------- | ---- | ------------- |
| lockType | [PersoLockType](#persolocktype8) |  是  | 定制锁的类型。|
| password | string                           |  是  | 密码。        |



## OperatorConfig<sup>8+</sup>

运营商配置。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称  | 类型   | 必填 | 说明 |
| ----- | ------ | ---- | ---- |
| field | string |  是  | 字段。 |
| value | string |  是  | 值。   |

## DiallingNumbersInfo<sup>8+</sup>

拨号号码信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称         | 类型   | 必填 |    说明    |
| ------------ | ------ | ---- | ---------- |
| alphaTag     | string |  是  | 标签。     |
| number       | string |  是  | 号码。     |
| recordNumber | number |  否  | 记录编号,如未传入，默认值为undefined。 |
| pin2         | string |  否  | pin2密码。 |

## ContactType<sup>8+</sup>

联系人类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称            | 值   | 说明       |
| --------------- | ---- | ---------- |
| GENERAL_CONTACT | 1    | 通用联系人。 |
| FIXED_DIALING   | 2    | 固定拨号。   |

## OperatorConfigKey<sup>9+</sup>

运营商配置键。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

|                             名称                        |                             值                         |         说明         |
| ------------------------------------------------------- | ------------------------------------------------------ | -------------------- |
| KEY_VOICE_MAIL_NUMBER_STRING                            | "voice_mail_number_string"                             | 语音邮件号码。       |
| KEY_IMS_SWITCH_ON_BY_DEFAULT_BOOL                       | "ims_switch_on_by_default_bool"                        | 固定拨号。           |
| KEY_HIDE_IMS_SWITCH_BOOL                                | "hide_ims_switch_bool"                                 | 是否隐藏ims开关。    |
| KEY_VOLTE_SUPPORTED_BOOL                                | "volte_supported_bool"                                 | 是否支持volte模式。  |
| KEY_NR_MODE_SUPPORTED_LIST_INT_ARRAY                    | "nr_mode_supported_list_int_array"                     | nr模式支持的列表。   |
| KEY_VOLTE_PROVISIONING_SUPPORTED_BOOL                   | "volte_provisioning_supported_bool"                    | 是否支持配置VOLTE。  |
| KEY_SS_OVER_UT_SUPPORTED_BOOL                           | "ss_over_ut_supported_bool"                            | SS服务是否支持UT。   |
| KEY_IMS_GBA_REQUIRED_BOOL                               | "ims_gba_required_bool"                                | IMS是否需要GBA。     |
| KEY_UT_PROVISIONING_SUPPORTED_BOOL                      | "ut_provisioning_supported_bool"                       | 是否支持UT配置。     |
| KEY_IMS_PREFER_FOR_EMERGENCY_BOOL                       | "ims_prefer_for_emergency_bool"                        | IMS紧急首选项。      |
| KEY_CALL_WAITING_SERVICE_CLASS_INT                      | "call_waiting_service_class_int"                       | 呼叫等待服务。       |
| KEY_CALL_TRANSFER_VISIBILITY_BOOL                       | "call_transfer_visibility_bool"                        | 呼叫转移可见性。     |
| KEY_IMS_CALL_DISCONNECT_REASON_INFO_MAPPING_STRING_ARRAY| "ims_call_disconnect_reason_info_mapping_string_array" | IMS呼叫结束原因列表。|
| KEY_FORCE_VOLTE_SWITCH_ON_BOOL                          | "force_volte_switch_on_bool"                           | 强制VOLTE开关。      |
| KEY_ENABLE_OPERATOR_NAME_CUST_BOOL                      | "enable_operator_name_cust_bool"                       | 是否显示运营商名称。 |
| KEY_OPERATOR_NAME_CUST_STRING                           | "operator_name_cust_string"                            | 运营商名称。         |
| KEY_SPN_DISPLAY_CONDITION_CUST_INT                      | "spn_display_condition_cust_int"                       | SPN显示规则。        |
| KEY_PNN_CUST_STRING_ARRAY                               | "pnn_cust_string_array"                                | PLMN名称。           |
| KEY_OPL_CUST_STRING_ARRAY                               | "opl_cust_string_array"                                | 运营商PLMN信息。     |
| KEY_EMERGENCY_CALL_STRING_ARRAY                         | "emergency_call_string_array"                          | 紧急呼叫列表。       |

## DsdsMode<sup>11+</sup>

设备支持的DSDS Mode。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称               | 值   | 说明                        |
| -------------------| ---- | -------------------------- |
| DSDS_MODE_V2       | 0    | 设备支持DSDS 2.0 Mode。      |
| DSDS_MODE_V3       | 1    | 设备支持DSDS 3.0 Mode。      |
| DSDS_MODE_V5_TDM   | 2    | 设备支持DSDS 5.0 TDM Mode。  |
| DSDS_MODE_V5_DSDA  | 3    | 设备支持DSDS 5.0 DSDA Mode。 |

## OperatorSimCard<sup>11+</sup>

运营商名称。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                | 值                    | 说明      |
| ------------------ | --------------------- | -------- |
| CHINA_TELECOM_CARD | "china_telecom_card"  | 中国电信卡。 |

## AuthType<sup>14+</sup>

身份验证类型。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                | 值                    | 说明      |
| ------------------ | --------------------- | -------- |
| SIM_AUTH_EAP_SIM_TYPE   | 128  | 鉴权类型为EAP-SIM。 |
| SIM_AUTH_EAP_AKA_TYPE   | 129  | 鉴权类型为EAP-AKA。 |

## SimAuthenticationResponse<sup>14+</sup>

SIM卡鉴权响应。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称         | 类型   | 必填 |    说明    |
| ------------ | ------ | ---- | ---------- |
| simStatusWord1 | number |  是  | SIM卡状态字1。 |
| simStatusWord2 | number |  是  | SIM卡状态字2。 |
| response       | string |  是  | 鉴权响应。     |