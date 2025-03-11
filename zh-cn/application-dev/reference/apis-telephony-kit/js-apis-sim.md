# @ohos.telephony.sim (SIM卡管理)

SIM卡管理模块提供了SIM卡管理的基础能力，包括获取指定卡槽SIM卡的ISO国家码、归属PLMN号、服务提供商名称、SIM卡状态、卡类型、是否插卡、是否激活等。

> **说明：** 
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```ts
import { sim } from '@kit.TelephonyKit';
```

## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number, callback: AsyncCallback\<boolean\>\): void

获取指定卡槽SIM卡是否激活。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回指定卡槽是否激活，如果激活返回true。                             |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.isSimActive(0, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number\): Promise\<boolean\>

获取指定卡槽SIM卡是否激活。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式返回指定卡槽是否激活，如果激活返回true。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.isSimActive(0).then((data: boolean) => {
    console.log(`isSimActive success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`isSimActive failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.isSimActiveSync<sup>10+</sup>

isSimActiveSync\(slotId: number\): boolean

获取指定卡槽SIM卡是否激活。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| boolean | 返回指定卡槽是否激活，如果激活返回true。 |

**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let isSimActive: boolean = sim.isSimActiveSync(0);
console.log(`the sim is active:` + isSimActive);
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(callback: AsyncCallback\<number\>\): void

获取默认语音业务的卡槽ID。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明       |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。<br />- 0：卡槽1。<br />- 1：卡槽2。<br />- -1：未设置或服务不可用。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getDefaultVoiceSlotId((err: BusinessError, data: number) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(\): Promise\<number\>

获取默认语音业务的卡槽ID。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<number\> | 以Promise形式返回默认语音业务的卡槽ID。<br />- 0：卡槽1。<br />- 1：卡槽2。<br />- -1：未设置或服务不可用。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getDefaultVoiceSlotId().then((data: number) => {
    console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges\(slotId: number, callback: AsyncCallback\<boolean\>\): void

检查应用(调用者)是否已被授予运营商权限。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                     |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| slotId   | number                   | 是   | 卡槽ID。<br />- 0：卡槽1。<br />- 1：卡槽2。 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。 返回检查应用(调用者)是否已被授予运营商权限。                              |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.hasOperatorPrivileges(0, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges\(slotId: number\): Promise\<boolean\>

检查应用(调用者)是否已被授予运营商权限。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br />- 0：卡槽1。<br />- 1：卡槽2。 |

**返回值：**

| 类型               | 说明                                                        |
| :----------------- | :---------------------------------------------------------- |
| Promise\<boolean\> | 以Promise形式返回检查应用(调用者)是否已被授予运营商权限。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.hasOperatorPrivileges(0).then((data: boolean) => {
    console.log(`hasOperatorPrivileges success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`hasOperatorPrivileges failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽SIM卡的ISO国家码。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                     |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。   |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回国家码，例如：CN(中国)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getISOCountryCodeForSim(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的ISO国家码。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的ISO国家码。例如：CN(中国)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getISOCountryCodeForSim(0).then((data: string) => {
    console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getISOCountryCodeForSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSimSync<sup>10+</sup>

getISOCountryCodeForSimSync\(slotId: number\): string

获取指定卡槽SIM卡的ISO国家码。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| string | 返回获取指定卡槽SIM卡的ISO国家码。例如：CN(中国)。 |


**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let countryCode: string = sim.getISOCountryCodeForSimSync(0);
console.log(`the country ISO is:` + countryCode);
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽SIM卡的归属PLMN(Public Land Mobile Network)号。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回指定卡槽SIM卡的归属PLMN号。                          |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getSimOperatorNumeric(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的归属PLMN(Public Land Mobile Network)号。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                             |
| ----------------- | ------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的归属PLMN号。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getSimOperatorNumeric(0).then((data: string) => {
    console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimOperatorNumeric failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimOperatorNumericSync<sup>10+</sup>

getSimOperatorNumericSync\(slotId: number\): string

获取指定卡槽SIM卡的归属PLMN(Public Land Mobile Network)号。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                             |
| ----------------- | ------------------------------------------------ |
| string | 返回获取指定卡槽SIM卡的归属PLMN号。 |


**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let numeric: string = sim.getSimOperatorNumericSync(0);
console.log(`the sim operator numeric is:` + numeric);
```


## sim.getSimSpn

getSimSpn\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽SIM卡的服务提供商名称(Service Provider Name，SPN)。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回指定卡槽SIM卡的SPN。                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getSimSpn(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的服务提供商名称(Service Provider Name，SPN)。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                      |
| ----------------- | ----------------------------------------- |
| Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的SPN。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getSimSpn(0).then((data: string) => {
    console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimSpn failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimSpnSync<sup>10+</sup>

getSimSpnSync\(slotId: number\): string

获取指定卡槽SIM卡的服务提供商名称(Service Provider Name，SPN)。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                      |
| ----------------- | ----------------------------------------- |
| string | 返回获取指定卡槽SIM卡的SPN。 |


**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let spn: string = sim.getSimSpnSync(0);
console.log(`the sim card spn is:` + spn);
```


## sim.getSimState

getSimState\(slotId: number, callback: AsyncCallback\<SimState\>\): void

获取指定卡槽的SIM卡状态。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                   |
| -------- | -------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                 | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback\<[SimState](#simstate)\> | 是   | 回调函数。参考[SimState](#simstate)。  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimState(0, (err: BusinessError, data: sim.SimState) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimState

getSimState\(slotId: number\): Promise\<SimState\>

获取指定卡槽的SIM卡状态。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                             | 说明                                       |
| -------------------------------- | ------------------------------------------ |
| Promise\<[SimState](#simstate)\> | 以Promise形式返回获取指定卡槽的SIM卡状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getSimState(0).then((data: sim.SimState) => {
    console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimStateSync<sup>10+</sup>

getSimStateSync\(slotId: number\): SimState

获取指定卡槽的SIM卡状态。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                         | 说明                                       |
| ---------------------------- | ------------------------------------------ |
| [SimState](#simstate) | 返回获取指定卡槽的SIM卡状态。 |


**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let simState: sim.SimState = sim.getSimStateSync(0);
console.log(`The sim state is:` + simState);
```

## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number, callback: AsyncCallback\<CardType\>\): void

获取指定卡槽SIM卡的卡类型。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback\<[CardType](#cardtype7)\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getCardType(0, (err: BusinessError, data: sim.CardType) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number\): Promise\<CardType\>

获取指定卡槽SIM卡的卡类型。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<[CardType](#cardtype7)\> | 以Promise形式返回指定卡槽SIM卡的卡类型。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getCardType(0).then((data: sim.CardType) => {
    console.log(`getCardType success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getCardType failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getCardTypeSync<sup>10+</sup>

getCardTypeSync\(slotId: number\): CardType

获取指定卡槽SIM卡的卡类型。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| [CardType](#cardtype7) | 返回指定卡槽SIM卡的卡类型。 |


**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let cardType: sim.CardType = sim.getCardTypeSync(0);
console.log(`the card type is:` + cardType);
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number, callback: AsyncCallback\<boolean\>\): void

获取指定卡槽SIM卡是否插卡。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback&lt;boolean&gt; | 是  | 回调返回指定卡槽是否插卡，如果插卡返回true。                           |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.hasSimCard(0, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number\): Promise\<boolean\>

获取指定卡槽SIM卡是否插卡。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式返回指定卡槽是否插卡，如果插卡返回true。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.hasSimCard(0).then((data: boolean) => {
    console.log(`hasSimCard success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`hasSimCard failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasSimCardSync<sup>10+</sup>

hasSimCardSync\(slotId: number\): boolean

获取指定卡槽SIM卡是否插卡。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| boolean | 返回指定卡槽是否插卡，如果插卡返回true。 |

**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let hasSimCard: boolean = sim.hasSimCardSync(0);
console.log(`has sim card: ` + hasSimCard);
```

## sim.getSimAccountInfo<sup>10+</sup>

getSimAccountInfo\(slotId: number, callback: AsyncCallback\<IccAccountInfo\>\): void

获取SIM卡帐户信息。使用callback异步回调。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

> **说明：**
>
> 获取ICCID和号码信息时需要GET_TELEPHONY_STATE权限，ICCID和号码信息为敏感数据，不向三方应用开放。调用接口时，获取到的ICCID和号码信息为空。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                              | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback&lt;[IccAccountInfo](#iccaccountinfo10)&gt; | 是   | 回调函数。返回指定卡槽SIM卡的帐户信息。                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getSimAccountInfo(0, (err:BusinessError , data: sim.IccAccountInfo) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimAccountInfo<sup>10+</sup>

getSimAccountInfo\(slotId: number\): Promise\<IccAccountInfo\>

获取SIM卡帐户信息。使用Promise异步回调。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

> **说明：**
>
> 获取ICCID和号码信息时需要GET_TELEPHONY_STATE权限，ICCID和号码信息为敏感数据，不向三方应用开放。调用接口时，获取到的ICCID和号码信息为空。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                                         | 说明                                       |
| -------------------------------------------- | ------------------------------------------ |
| Promise&lt;[IccAccountInfo](#iccaccountinfo10)&gt; | 以Promise形式返回指定卡槽SIM卡的帐户信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getSimAccountInfo(0).then((data: sim.IccAccountInfo) => {
    console.log(`getSimAccountInfo success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimAccountInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getActiveSimAccountInfoList<sup>10+</sup>

getActiveSimAccountInfoList\(callback: AsyncCallback\<Array\<IccAccountInfo\>\>\): void

获取激活SIM卡帐户信息列表。使用callback异步回调。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

> **说明：**
>
> 获取ICCID和号码信息时需要GET_TELEPHONY_STATE权限，ICCID和号码信息为敏感数据，不向三方应用开放。调用接口时，获取到的ICCID和号码信息为空。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明       |
| -------- | ----------------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;Array&lt;[IccAccountInfo](#iccaccountinfo10)&gt;&gt; | 是   | 回调函数。返回激活SIM卡帐户信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getActiveSimAccountInfoList((err: BusinessError, data: Array<sim.IccAccountInfo>) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.getMaxSimCount<sup>7+</sup>

getMaxSimCount\(\): number

获取卡槽数量。

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| number | 卡槽数量。 |

**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

console.log("Result: "+ sim.getMaxSimCount());
```


## sim.getActiveSimAccountInfoList<sup>10+</sup>

getActiveSimAccountInfoList\(\): Promise\<Array\<IccAccountInfo\>\>

获取激活SIM卡帐户信息列表。使用Promise异步回调。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

> **说明：**
>
> 获取ICCID和号码信息时需要GET_TELEPHONY_STATE权限，ICCID和号码信息为敏感数据，不向三方应用开放。调用接口时，获取到的ICCID和号码信息为空。

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型                                                 | 说明                                           |
| ---------------------------------------------------- | ---------------------------------------------- |
| Promise&lt;Array&lt;[IccAccountInfo](#iccaccountinfo10)&gt;&gt; | 以Promise形式返回激活卡槽SIM卡的帐户信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300004  | No SIM card found.                           |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getActiveSimAccountInfoList().then((data: Array<sim.IccAccountInfo>) => {
    console.log(`getActiveSimAccountInfoList success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getActiveSimAccountInfoList failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getOpKey<sup>9+</sup>

getOpKey\(slotId: number, callback: AsyncCallback\<string\>): void

获取指定卡槽中SIM卡的opkey。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

try {
    sim.getOpKey(0, (err: BusinessError, data: string) => {
    if (err) {
      console.error("getOpKey failed, err: " + JSON.stringify(err));
    } else {
      console.log('getOpKey successfully, data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.error("getOpKey err: " + JSON.stringify(err));
}
```


## sim.getOpKey<sup>9+</sup>

getOpKey\(slotId: number\): Promise\<string\>

获取指定卡槽中SIM卡的opkey。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise<string\> | 以Promise形式返回指定卡槽中SIM卡的opkey。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getOpKey(0).then((data: string) => {
    console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getOpKey failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpKeySync<sup>10+</sup>

getOpKeySync\(slotId: number\): string

获取指定卡槽中SIM卡的opkey。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| string | 返回指定卡槽中SIM卡的opkey。 |


**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let data: string = sim.getOpKeySync(0);
console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);
```

## sim.getOpName<sup>9+</sup>

getOpName\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽中SIM卡的OpName。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                               |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

try {
    sim.getOpName(0, (err: BusinessError, data: string) => {
    if (err) {
      console.error("getOpName failed, err: " + JSON.stringify(err));
    } else {
      console.log('getOpName successfully, data: ' + JSON.stringify(data));
    }
  });
} catch (err) {
  console.error("getOpName err: " + JSON.stringify(err));
}
```


## sim.getOpName<sup>9+</sup>

getOpName\(slotId: number\): Promise\<string\>

获取指定卡槽中SIM卡的OpName。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型             | 说明                                       |
| ---------------- | ------------------------------------------ |
| Promise<string\> | 以Promise形式返回指定卡槽中SIM卡的OpName。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Service connection failed.                   |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error.                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

sim.getOpName(0).then((data: string) => {
    console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getOpName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpNameSync<sup>10+</sup>

getOpNameSync\(slotId: number\): string

获取指定卡槽中SIM卡的OpName。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型             | 说明                                       |
| ---------------- | ------------------------------------------ |
| string | 返回指定卡槽中SIM卡的OpName。 |


**示例：**

```ts
import { sim } from '@kit.TelephonyKit';

let data: string = sim.getOpNameSync(0);
console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);
```

## sim.getDefaultVoiceSimId<sup>10+</sup>

getDefaultVoiceSimId\(callback: AsyncCallback\<number\>\): void

获取默认语音业务的SIM卡ID。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明       |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。<br/>与SIM卡绑定，从1开始递增。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

sim.getDefaultVoiceSimId((err: BusinessError, data: number) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.getDefaultVoiceSimId<sup>10+</sup>

getDefaultVoiceSimId\(\): Promise\<number\>

获取默认语音业务的SIM卡ID。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<number\> | 以Promise形式返回默认语音业务的SIM卡ID。<br/>与SIM卡绑定，从1开始递增。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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

let promise = sim.getDefaultVoiceSimId();
promise.then((data: number) => {
    console.log(`getDefaultVoiceSimId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultVoiceSimId failed, promise: err->${JSON.stringify(err)}`);
});
```


## SimState

SIM卡状态。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称                  | 值   | 说明                                                       |
| --------------------- | ---- | ---------------------------------------------------------- |
| SIM_STATE_UNKNOWN     | 0    | SIM卡状态未知，即无法获取准确的状态。                      |
| SIM_STATE_NOT_PRESENT | 1    | 表示SIM卡处于not present状态，即卡槽中没有插入SIM卡。      |
| SIM_STATE_LOCKED      | 2    | 表示SIM卡处于locked状态，即SIM卡被PIN、PUK或网络锁锁定。   |
| SIM_STATE_NOT_READY   | 3    | 表示SIM卡处于not ready状态，即SIM卡在位但无法正常工作。    |
| SIM_STATE_READY       | 4    | 表示SIM卡处于ready状态，即SIM卡在位且工作正常。            |
| SIM_STATE_LOADED      | 5    | 表示SIM卡处于loaded状态，即SIM卡在位且所有卡文件加载完毕。 |

## CardType<sup>7+</sup>

卡类型。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|UNKNOWN_CARD | -1 | 未知类型。 |
|SINGLE_MODE_SIM_CARD | 10 | 单SIM卡。 |
|SINGLE_MODE_USIM_CARD | 20 | 单USIM卡。 |
|SINGLE_MODE_RUIM_CARD | 30 | 单RUIM卡。 |
|DUAL_MODE_CG_CARD | 40 | 双卡模式C+G。 |
|CT_NATIONAL_ROAMING_CARD | 41 | 中国电信内部漫游卡。 |
|CU_DUAL_MODE_CARD | 42 | 中国联通双模卡。 |
|DUAL_MODE_TELECOM_LTE_CARD | 43 | 双模式电信LTE卡。 |
|DUAL_MODE_UG_CARD | 50 | 双模式UG卡。 |
|SINGLE_MODE_ISIM_CARD<sup>8+</sup> | 60 | 单一ISIM卡类型。 |

## IccAccountInfo<sup>10+</sup>

Icc帐户信息。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称       | 类型    | 必填 | 说明             |
| ---------- | ------- | ---- | ---------------- |
| simId      | number  |  是  | SIM卡ID。          |
| slotIndex  | number  |  是  | 卡槽ID。           |
| isEsim     | boolean |  是  | 标记卡是否是eSim。 |
| isActive   | boolean |  是  | 卡是否被激活。     |
| iccId      | string  |  是  | ICCID号码。        |
| showName   | string  |  是  | SIM卡显示名称。    |
| showNumber | string  |  是  | SIM卡显示号码。    |