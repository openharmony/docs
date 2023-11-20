# @ohos.telephony.sim (SIM卡管理)

SIM卡管理模块提供了SIM卡管理的基础能力，包括获取指定卡槽SIM卡的名称、号码、ISO国家码、归属PLMN号、服务提供商名称、SIM卡状态、卡类型、是否插卡、是否激活、锁状态，设置指定卡槽SIM卡显示的名称、号码、锁状态，激活、禁用指定卡槽SIM卡，更改Pin密码，以及解锁指定卡槽SIM卡密码、SIM卡密码的解锁密码等。

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```ts
import sim from '@ohos.telephony.sim';
```

## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number, callback: AsyncCallback\<boolean\>\): void

获取指定卡槽SIM卡是否激活。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。返回指定卡槽是否激活，如果激活返回true。                             |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式返回指定卡槽是否激活，如果激活返回true。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| boolean | 返回指定卡槽是否激活，如果激活返回true。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。<br />- 0：卡槽1<br />- 1：卡槽2<br />- -1：未设置或服务不可用 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| Promise\<number\> | 以Promise形式返回默认语音业务的卡槽ID。<br />- 0：卡槽1<br />- 1：卡槽2<br />- -1：未设置或服务不可用 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getDefaultVoiceSlotId().then((data: number) => {
    console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges\(slotId: number, callback: AsyncCallback\<boolean\>\): void

检查应用（调用者）是否已被授予运营商权限。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                     |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| slotId   | number                   | 是   | 卡槽ID。<br />- 0：卡槽1<br />- 1：卡槽2 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。 返回检查应用（调用者）是否已被授予运营商权限。                              |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.hasOperatorPrivileges(0, (err: BusinessError, data: boolean) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges\(slotId: number\): Promise\<boolean\>

检查应用（调用者）是否已被授予运营商权限。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br />- 0：卡槽1<br />- 1：卡槽2 |

**返回值：**

| 类型               | 说明                                                        |
| :----------------- | :---------------------------------------------------------- |
| Promise\<boolean\> | 以Promise形式返回检查应用（调用者）是否已被授予运营商权限。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2   |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回国家码，例如：CN（中国）。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的ISO国家码，例如：CN（中国）。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| string | 返回获取指定卡槽SIM卡的ISO国家码，例如：CN（中国）。 |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

let countryCode: string = sim.getISOCountryCodeForSimSync(0);
console.log(`the country ISO is:` + countryCode);
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回指定卡槽SIM卡的归属PLMN号。                          |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getSimOperatorNumeric(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                             |
| ----------------- | ------------------------------------------------ |
| Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的归属PLMN号。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getSimOperatorNumeric(0).then((data: string) => {
    console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimOperatorNumeric failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimOperatorNumericSync<sup>10+</sup>

getSimOperatorNumericSync\(slotId: number\): string

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                             |
| ----------------- | ------------------------------------------------ |
| string | 返回获取指定卡槽SIM卡的归属PLMN号。 |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

let numeric: string = sim.getSimOperatorNumericSync(0);
console.log(`the sim operator numeric is:` + numeric);
```


## sim.getSimSpn

getSimSpn\(slotId: number, callback: AsyncCallback\<string\>\): void

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN）。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回指定卡槽SIM卡的SPN。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getSimSpn(0, (err: BusinessError, data: string) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number\): Promise\<string\>

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN）。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                      |
| ----------------- | ----------------------------------------- |
| Promise\<string\> | 以Promise形式返回获取指定卡槽SIM卡的SPN。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getSimSpn(0).then((data: string) => {
    console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimSpn failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimSpnSync<sup>10+</sup>

getSimSpnSync\(slotId: number\): string

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN）。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                      |
| ----------------- | ----------------------------------------- |
| string | 返回获取指定卡槽SIM卡的SPN。 |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId   | number                                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[SimState](#simstate)\> | 是   | 回调函数。参考[SimState](#simstate)。  |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                             | 说明                                       |
| -------------------------------- | ------------------------------------------ |
| Promise\<[SimState](#simstate)\> | 以Promise形式返回获取指定卡槽的SIM卡状态。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                         | 说明                                       |
| ---------------------------- | ------------------------------------------ |
| [SimState](#simstate) | 返回获取指定卡槽的SIM卡状态。 |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[CardType](#cardtype7)\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<[CardType](#cardtype7)\> | 以Promise形式返回指定卡槽SIM卡的卡类型。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| [CardType](#cardtype7) | 返回指定卡槽SIM卡的卡类型。 |


**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;boolean&gt; | 是  | 回调返回指定卡槽是否插卡，如果插卡返回true。                           |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise&lt;boolean&gt; | 以Promise形式返回指定卡槽是否插卡，如果插卡返回true。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| boolean | 返回指定卡槽是否插卡，如果插卡返回true。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

let hasSimCard: boolean = sim.hasSimCardSync(0);
console.log(`has sim card: ` + hasSimCard);
```

## sim.getSimAccountInfo<sup>10+</sup>

getSimAccountInfo\(slotId: number, callback: AsyncCallback\<IccAccountInfo\>\): void

获取SIM卡帐户信息。使用callback异步回调。

>**说明：**
>
>如果没有GET_TELEPHONY_STATE权限，获取到的ICCID和号码信息为空。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                              | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[IccAccountInfo](#iccaccountinfo10)\> | 是   | 回调函数。返回指定卡槽SIM卡的帐户信息。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getSimAccountInfo(0, (err:BusinessError , data: sim.IccAccountInfo) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimAccountInfo<sup>10+</sup>

getSimAccountInfo\(slotId: number\): Promise\<IccAccountInfo\>

获取SIM卡帐户信息。使用Promise异步回调。

>**说明：**
>
>如果没有GET_TELEPHONY_STATE权限，获取到的ICCID和号码信息为空。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                         | 说明                                       |
| -------------------------------------------- | ------------------------------------------ |
| Promise<[IccAccountInfo](#iccaccountinfo10)\> | 以Promise形式返回指定卡槽SIM卡的帐户信息。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getSimAccountInfo(0).then((data: sim.IccAccountInfo) => {
    console.log(`getSimAccountInfo success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getSimAccountInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getActiveSimAccountInfoList<sup>10+</sup>

getActiveSimAccountInfoList\(callback: AsyncCallback\<Array\<IccAccountInfo\>\>\): void

获取激活SIM卡帐户信息列表。使用callback异步回调。

>**说明：**
>
>如果没有GET_TELEPHONY_STATE权限，获取到的ICCID和号码信息为空。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明       |
| -------- | ----------------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array<[IccAccountInfo](#iccaccountinfo10)\>\> | 是   | 回调函数。返回激活SIM卡帐户信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getActiveSimAccountInfoList((err: BusinessError, data: Array<sim.IccAccountInfo>) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getActiveSimAccountInfoList<sup>10+</sup>

getActiveSimAccountInfoList\(\): Promise\<Array\<IccAccountInfo\>\>

获取激活SIM卡帐户信息列表。使用Promise异步回调。

>**说明：**
>
>如果没有GET_TELEPHONY_STATE权限，获取到的ICCID和号码信息为空。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型                                                 | 说明                                           |
| ---------------------------------------------------- | ---------------------------------------------- |
| Promise<Array<[IccAccountInfo](#iccaccountinfo10)\>\> | 以Promise形式返回激活卡槽SIM卡的帐户信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

sim.getActiveSimAccountInfoList().then((data: Array<sim.IccAccountInfo>) => {
    console.log(`getActiveSimAccountInfoList success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getActiveSimAccountInfoList failed, promise: err->${JSON.stringify(err)}`);
});
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
| slotId   | number                    | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

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
import sim from '@ohos.telephony.sim';

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
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

let puk2: string = '1xxxxxxx';
let newPin2: string = '1235';
sim.unlockPuk2(0, newPin2, puk2).then((data: sim.LockStatusResponse) => {
    console.log(`unlockPuk2 success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`unlockPuk2 failed, promise: err->${JSON.stringify(err)}`);
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
import sim from '@ohos.telephony.sim';

console.log("Result: "+ sim.getMaxSimCount());
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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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
import sim from '@ohos.telephony.sim';

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

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
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
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| 8301002  | SIM card operation error.                    |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

## sim.getOpKey<sup>9+</sup>

getOpKey\(slotId: number, callback: AsyncCallback\<string\>): void

获取指定卡槽中SIM卡的opkey。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise<string\> | 以Promise形式返回指定卡槽中SIM卡的opkey。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

try {
    let data: Promise<string> = sim.getOpKey(0);
    console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);
} catch (error) {
    console.error(`getOpKey failed, promise: err->${JSON.stringify(error)}`);
}
```

## sim.getOpKeySync<sup>10+</sup>

getOpKeySync\(slotId: number\): string

获取指定卡槽中SIM卡的opkey。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| string | 返回指定卡槽中SIM卡的opkey。 |


**示例：**

```ts
import sim from '@ohos.telephony.sim';

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
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                               |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                       |
| ---------------- | ------------------------------------------ |
| Promise<string\> | 以Promise形式返回指定卡槽中SIM卡的OpName。 |

**错误码：**

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 401      | Parameter error.                             |
| 801      | Capability not supported.                    |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

try {
    let data: Promise<string> = sim.getOpName(0);
    console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);
} catch (error) {
    console.error(`getOpName failed, promise: err->${JSON.stringify(error)}`);
}
```

## sim.getOpNameSync<sup>10+</sup>

getOpNameSync\(slotId: number\): string

获取指定卡槽中SIM卡的OpName。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                       |
| ---------------- | ------------------------------------------ |
| string | 返回指定卡槽中SIM卡的OpName。 |


**示例：**

```ts
import sim from '@ohos.telephony.sim';

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

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
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
import sim from '@ohos.telephony.sim';

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

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 8300001  | Invalid parameter value.                     |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300004  | Do not have sim card.                        |
| 8300999  | Unknown error code.                          |
| 8301001  | SIM card is not activated.                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

let promise = sim.getDefaultVoiceSimId();
promise.then((data: number) => {
    console.log(`getDefaultVoiceSimId success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultVoiceSimId failed, promise: err->${JSON.stringify(err)}`);
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

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

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

以下错误码的详细介绍请参见[ohos.telephony(电话子系统)错误码](../../reference/errorcodes/errorcode-telephony.md)。

| 错误码ID |                 错误信息                     |
| -------- | -------------------------------------------- |
| 201      | Permission denied.                           |
| 202      | Non-system applications use system APIs.     |
| 401      | Parameter error.                             |
| 8300002  | Operation failed. Cannot connect to service. |
| 8300003  | System internal error.                       |
| 8300999  | Unknown error code.                          |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import sim from '@ohos.telephony.sim';

let promise = sim.getDsdsMode();
promise.then((data: sim.DsdsMode) => {
    console.log(`getDsdsMode success, promise: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDsdsMode failed, promise: err->${JSON.stringify(err)}`);
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
| LOCK_OFF | 0    | 锁关闭状态 |
| LOCK_ON  | 1    | 锁开启状态 |

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

## OperatorConfig<sup>8+</sup>

运营商配置。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称  | 类型   | 必填 | 说明 |
| ----- | ------ | ---- | ---- |
| field | string |  是  | 字段 |
| value | string |  是  | 值   |

## DiallingNumbersInfo<sup>8+</sup>

拨号号码信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

| 名称         | 类型   | 必填 |    说明    |
| ------------ | ------ | ---- | ---------- |
| alphaTag     | string |  是  | 标签。     |
| number       | string |  是  | 号码。     |
| recordNumber | number |  否  | 记录编号。 |
| pin2         | string |  是  | pin2密码。 |

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
