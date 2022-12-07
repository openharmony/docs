# SIM卡管理

SIM卡管理模块提供了SIM卡管理的基础能力，包括获取指定卡槽SIM卡的名称、号码、ISO国家码、归属PLMN号、服务提供商名称、SIM卡状态、卡类型、是否插卡、是否激活、锁状态，设置指定卡槽SIM卡显示的名称、号码、锁状态，激活、禁用指定卡槽SIM卡，更改Pin密码，以及解锁指定卡槽SIM卡密码、SIM卡密码的解锁密码等。

>**说明：** 
>
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```js
import sim from '@ohos.telephony.sim';
```

## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number, callback: AsyncCallback<boolean\>\): void

获取指定卡槽SIM卡是否激活。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。                             |

**示例：**

```js
sim.isSimActive(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.isSimActive<sup>7+</sup>

isSimActive\(slotId: number\): Promise<boolean\>

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

```js
let promise = sim.isSimActive(0);
promise.then(data => {
    console.log(`isSimActive success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`isSimActive failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(callback: AsyncCallback<number\>\): void

获取默认语音业务的卡槽ID。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明       |
| -------- | --------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调函数。 |

**示例：**

```js
sim.getDefaultVoiceSlotId((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(\): Promise<number\>

获取默认语音业务的卡槽ID。使用Promise异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型              | 说明                                    |
| ----------------- | --------------------------------------- |
| Promise\<number\> | 以Promise形式返回默认语音业务的卡槽ID。 |

**示例：**

```js
let promise = sim.getDefaultVoiceSlotId();
promise.then(data => {
    console.log(`getDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges(slotId: number, callback: AsyncCallback\<boolean\>): void

检查应用（调用者）是否已被授予运营商权限。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                     |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| slotId   | number                   | 是   | 卡槽ID。<br />- 0：卡槽1<br />- 1：卡槽2 |
| callback | AsyncCallback\<boolean\> | 是   | 回调函数。                               |

**示例：**

```js
sim.hasOperatorPrivileges(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges(slotId: number): Promise<boolean\>

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

**示例：**

```js
let promise = sim.hasOperatorPrivileges(0);
promise.then(data => {
    console.log(`hasOperatorPrivileges success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`hasOperatorPrivileges failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的ISO国家码。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                     |
| -------- | ----------------------- | ---- | ---------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2   |
| callback | AsyncCallback\<string\> | 是   | 回调函数。返回国家码，例如：CN（中国）。 |

**示例：**

```js
sim.getISOCountryCodeForSim(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number\): Promise<string\>

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

**示例：**

```js
let promise = sim.getISOCountryCodeForSim(0);
promise.then(data => {
    console.log(`getISOCountryCodeForSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getISOCountryCodeForSim failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getSimOperatorNumeric(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number\): Promise<string\>

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

**示例：**

```js
let promise = sim.getSimOperatorNumeric(0);
promise.then(data => {
    console.log(`getSimOperatorNumeric success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimOperatorNumeric failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN）。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getSimSpn(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number\): Promise<string\>

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

**示例：**

```js
let promise = sim.getSimSpn(0);
promise.then(data => {
    console.log(`getSimSpn success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimSpn failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimState

getSimState\(slotId: number, callback: AsyncCallback<SimState\>\): void

获取指定卡槽的SIM卡状态。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                   |
| -------- | -------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[SimState](#simstate)\> | 是   | 回调函数。参考[SimState](#simstate)。  |

**示例：**

```js
sim.getSimState(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimState

getSimState\(slotId: number\): Promise<SimState\>

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

**示例：**

```js
let promise = sim.getSimState(0);
promise.then(data => {
    console.log(`getSimState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number, callback: AsyncCallback<CardType\>\): void

获取指定卡槽SIM卡的卡类型。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[CardType](#cardtype7)\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getCardType(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number\): Promise<CardType\>

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

**示例：**

```js
let promise = sim.getCardType(0);
promise.then(data => {
    console.log(`getCardType success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getCardType failed, promise: err->${JSON.stringify(err)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number, callback: AsyncCallback<boolean\>\): void

获取指定卡槽SIM卡是否插卡。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。                             |

**示例：**

```js
sim.hasSimCard(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number\): Promise<boolean\>

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

**示例：**

```js
let promise = sim.hasSimCard(0);
promise.then(data => {
    console.log(`hasSimCard success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`hasSimCard failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimAccountInfo<sup>7+</sup>

getSimAccountInfo(slotId: number, callback: AsyncCallback<IccAccountInfo\>): void

获取SIM卡账户信息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                              | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[IccAccountInfo](#iccaccountinfo7)\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getSimAccountInfo(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimAccountInfo<sup>7+</sup>

getSimAccountInfo(slotId: number): Promise<IccAccountInfo\>

获取SIM卡账户信息。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                         | 说明                                       |
| -------------------------------------------- | ------------------------------------------ |
| Promise<[IccAccountInfo](#iccaccountinfo7)\> | 以Promise形式返回指定卡槽SIM卡的账户信息。 |

**示例：**

```js
let promise = sim.getSimAccountInfo(0);
promise.then(data => {
    console.log(`getSimAccountInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimAccountInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getActiveSimAccountInfoList<sup>8+</sup>

getActiveSimAccountInfoList(callback: AsyncCallback<Array<IccAccountInfo\>>): void

获取活跃SIM卡账户信息列表。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明       |
| -------- | ----------------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array<[IccAccountInfo](#iccaccountinfo7)\>\> | 是   | 回调函数。 |

**示例：**

```js
sim.getActiveSimAccountInfoList((err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getActiveSimAccountInfoList<sup>8+</sup>

getActiveSimAccountInfoList(): Promise<Array<IccAccountInfo\>>;

获取活跃SIM卡账户信息列表。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型                                                 | 说明                                           |
| ---------------------------------------------------- | ---------------------------------------------- |
| Promise<Array<[IccAccountInfo](#iccaccountinfo7)\>\> | 以Promise形式返回活跃卡槽SIM卡的账户信息列表。 |

**示例：**

```js
let promise = sim.getActiveSimAccountInfoList();
promise.then(data => {
    console.log(`getActiveSimAccountInfoList success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getActiveSimAccountInfoList failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId(slotId: number, callback: AsyncCallback<void\>): void

设置默认语音业务的卡槽ID。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
sim.setDefaultVoiceSlotId(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId(slotId: number): Promise\<void\>

设置默认语音业务的卡槽ID。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.setDefaultVoiceSlotId(0);
promise.then(data => {
    console.log(`setDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setDefaultVoiceSlotId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**setShowName**<sup>8+</sup>

setShowName\(slotId: number, name: string, callback: AsyncCallback<void\>\): void

设置指定卡槽SIM卡显示的名称。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| name     | string                    | 是   | SIM卡名称。                              |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
let name = "ShowName";
sim.setShowName(0, name, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.**setShowName**<sup>8+</sup>

setShowName\(slotId: number, name: string\): Promise\<void\>

设置指定卡槽SIM卡显示的名称。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let name = "ShowName";
let promise = sim.setShowName(0, name);
promise.then(data => {
    console.log(`setShowName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**getShowName**<sup>8+</sup>

getShowName(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽SIM卡的名称。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。                             |

**示例：**

```js
sim.getShowName(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**getShowName**<sup>8+</sup>

getShowName(slotId: number): Promise<string\>

获取指定卡槽SIM卡的名称。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getShowName(0);
promise.then(data => {
    console.log(`getShowName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getShowName failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**setShowNumber**<sup>8+</sup>

setShowNumber\(slotId: number, number: string, callback: AsyncCallback<void\>\): void

设置指定卡槽SIM卡的号码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| number   | string                    | 是   | SIM卡号码。                              |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
let number = '+861xxxxxxxxxx';
sim.setShowNumber(0, number, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**setShowNumber**<sup>8+</sup>

setShowNumber\(slotId: number, number: string\): Promise\<void\>

设置指定卡槽SIM卡的号码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let number = '+861xxxxxxxxxx';
let promise = sim.setShowNumber(0, number);
promise.then(data => {
    console.log(`setShowNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**getShowNumber**<sup>8+</sup>

getShowNumber(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽SIM卡的号码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数。                             |

**示例：**

```js
sim.getShowNumber(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**getShowNumber**<sup>8+</sup>

getShowNumber(slotId: number): Promise<string\>

获取指定卡槽SIM卡的号码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getShowNumber(0);
promise.then(data => {
    console.log(`getShowNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getShowNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**activateSim**<sup>8+</sup>

activateSim(slotId: number, callback: AsyncCallback<void\>): void

激活指定卡槽SIM卡。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
sim.activateSim(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**activateSim**<sup>8+</sup>

activateSim(slotId: number): Promise\<void\>

激活指定卡槽SIM卡。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.activateSim(0);
promise.then(data => {
    console.log(`activateSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`activateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**deactivateSim**<sup>8+</sup>

deactivateSim(slotId: number, callback: AsyncCallback<void\>): void

禁用指定卡槽SIM卡。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
sim.deactivateSim(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**deactivateSim**<sup>8+</sup>

deactivateSim(slotId: number): Promise\<void\>

禁用指定卡槽SIM卡。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.deactivateSim(0);
promise.then(data => {
    console.log(`deactivateSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`deactivateSim failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setLockState<sup>7+</sup>

setLockState(slotId: number, options: LockInfo, callback: AsyncCallback<LockStatusResponse\>): void

设置指定卡槽SIM卡的锁状态。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                                                   |
| options  | [LockInfo](#lockinfo8)                                      | 是   | 锁信息。<br/>- lockType: [LockType](#locktype8)<br/>- password: string<br/>- state: [LockState](#lockstate8) |

**示例：**

```js
let lockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
sim.setLockState(0, lockInfo, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setLockState<sup>7+</sup>

setLockState(slotId: number, options: LockInfo): Promise<LockStatusResponse\>

设置指定卡槽SIM卡的锁状态。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let lockInfo = {
    lockType: sim.LockType.PIN_LOCK,
    password: "1234",
    state: sim.LockState.LOCK_OFF
};
let promise = sim.setLockState(0, lockInfo);
promise.then(data => {
    console.log(`setLockState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getLockState<sup>8+</sup>

getLockState(slotId: number, lockType: LockType, callback: AsyncCallback<LockState\>): void

获取指定卡槽SIM卡的锁状态。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                    |
| -------- | ----------------------------------------- | ---- | --------------------------------------- |
| slotId   | number                                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |
| callback | AsyncCallback\<[LockState](#lockstate8)\> | 是   | 回调函数。                              |
| options  | [LockType](#locktype8)                    | 是   | 锁类型。<br/>- 1: PIN锁<br/>- 2: PIN2锁 |

**示例：**

```js
sim.getLockState(0, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getLockState<sup>8+</sup>

getLockState(slotId: number, lockType: LockType): Promise<LockState\>

获取指定卡槽SIM卡的锁状态。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getLockState(0, 1);
promise.then(data => {
    console.log(`getLockState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getLockState failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin<sup>7+</sup>

alterPin(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback<LockStatusResponse\>): void

更改Pin密码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                   |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                             |
| newPin   | string                                                      | 是   | 新密码。                               |
| oldPin   | string                                                      | 是   | 旧密码。                               |

**示例：**

```js
sim.alterPin(0, "1234", "0000", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin<sup>7+</sup>

alterPin(slotId: number, newPin: string, oldPin: string): Promise<LockStatusResponse\>;

更改Pin密码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.alterPin(0, "1234", "0000");
promise.then(data => {
    console.log(`alterPin success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`alterPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin2<sup>8+</sup>

alterPin2(slotId: number, newPin2: string, oldPin2: string, callback: AsyncCallback<LockStatusResponse\>): void

更改Pin2密码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                   |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                             |
| newPin2  | string                                                      | 是   | 新密码。                               |
| oldPin2  | string                                                      | 是   | 旧密码。                               |

**示例：**

```js
sim.alterPin2(0, "1234", "0000", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin2<sup>8+</sup>

alterPin2(slotId: number, newPin2: string, oldPin2: string): Promise<LockStatusResponse\>

更改Pin2密码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.alterPin2(0, "1234", "0000");
promise.then(data => {
    console.log(`alterPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`alterPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPin**<sup>7+</sup>

unlockPin(slotId: number, pin: string, callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin      | string                                                       | 是   | SIM卡的密码。                            |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)> | 是   | 回调函数。                             |

**示例：**

```js
let pin = '1234';
sim.unlockPin(0, pin, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPin**<sup>7+</sup>

unlockPin(slotId: number, pin: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let pin = '1234';
let promise = sim.unlockPin(0, pin);
promise.then(data => {
    console.log(`unlockPin success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPin failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPuk**<sup>7+</sup>

unlockPuk(slotId: number, newPin: string, puk: string, callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码的解锁密码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin   | string                                                       | 是   | 重置SIM卡的密码。                        |
| puk      | string                                                       | 是   | SIM卡密码的解锁密码。                    |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | 是   | 回调函数。                             |

**示例：**

```js
let puk = '1xxxxxxx';
let newPin = '1235';
sim.unlockPuk(0, newPin, puk, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPuk**<sup>7+</sup>

unlockPuk(slotId: number, newPin: string, puk: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码的解锁密码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let puk = '1xxxxxxx';
let newPin = '1235';
let promise = sim.unlockPuk(0, newPin, puk);
promise.then(data => {
    console.log(`unlockPuk success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPuk failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPin**2<sup>8+</sup>

unlockPin2(slotId: number, pin2: string, callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin2     | string                                                       | 是   | SIM卡的密码。                            |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | 是   | 回调函数。                             |

**示例：**

```js
let pin2 = '1234';
sim.unlockPin2(0, pin2, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPin**2<sup>8+</sup>

unlockPin2(slotId: number, pin2: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let pin2='1234';
let promise = sim.unlockPin2(0, pin2);
promise.then(data => {
    console.log(`unlockPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPin2 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPuk**2<sup>8+</sup>

unlockPuk2(slotId: number, newPin2: string, puk2: string, callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码的解锁密码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin2  | string                                                       | 是   | 重置SIM卡的密码。                        |
| puk2     | string                                                       | 是   | SIM卡密码的解锁密码。                    |
| callback | AsyncCallback&lt;[LockStatusResponse](#lockstatusresponse7)&gt; | 是   | 回调函数。                             |

**示例：**

```js
let puk2 = '1xxxxxxx';
let newPin2 = '1235';
sim.unlockPuk2(0, newPin2, puk2, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPuk2**<sup>8+</sup>

unlockPuk2(slotId: number, newPin2: string, puk2: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码的解锁密码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let puk2 = '1xxxxxxx';
let newPin2 = '1235';
let promise = sim.unlockPuk2(0, newPin2, puk2);
promise.then(data => {
    console.log(`unlockPuk2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPuk2 failed, promise: err->${JSON.stringify(err)}`);
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

```js
console.log("Result: "+ sim.getMaxSimCount())
```

## sim.getSimIccId<sup>7+</sup>

getSimIccId(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽SIM卡的ICCID。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getSimIccId(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimIccId<sup>7+</sup>

getSimIccId(slotId: number): Promise<string\>

获取指定卡槽SIM卡的ICCID。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getSimIccId(0);
promise.then(data => {
    console.log(`getSimIccId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimIccId failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽中SIM卡语音信箱的alpha标识符。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getVoiceMailIdentifier(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailIdentifier<sup>8+</sup>

getVoiceMailIdentifier(slotId: number): Promise<string\>

获取指定卡槽中SIM卡语音信箱的alpha标识符。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getVoiceMailIdentifier(0);
promise.then(data => {
    console.log(`getVoiceMailIdentifier success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getVoiceMailIdentifier failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽中SIM卡的语音信箱号。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getVoiceMailNumber(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getVoiceMailNumber<sup>8+</sup>

getVoiceMailNumber(slotId: number): Promise<string\>

获取指定卡槽中SIM卡的语音信箱号。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getVoiceMailNumber(0);
promise.then(data => {
    console.log(`getVoiceMailNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getVoiceMailNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string, callback: AsyncCallback<void\>): void

设置语音邮件信息。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名     | 类型                 | 必填 | 说明                                   |
| ---------- | -------------------- | ---- | -------------------------------------- |
| slotId     | number               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| mailName   | string               | 是   | 邮件名字                               |
| mailNumber | string               | 是   | 邮件号码                               |
| callback   | AsyncCallback<void\> | 是   | 回调函数。                             |

**示例：**

```js
sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setVoiceMailInfo<sup>8+</sup>

setVoiceMailInfo(slotId: number, mailName: string, mailNumber: string): Promise<void\>

设置语音邮件信息。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.setVoiceMailInfo(0, "mail", "xxx@xxx.com");
promise.then(data => {
    console.log(`setVoiceMailInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setVoiceMailInfo failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽中SIM卡的MSISDN。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getSimTelephoneNumber(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimTelephoneNumber<sup>8+</sup>

getSimTelephoneNumber(slotId: number): Promise<string\>

获取指定卡槽中SIM卡的MSISDN。使用Promise异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型             | 说明                                         |
| ---------------- | -------------------------------------------- |
| Promise<string\> | 以Promise形式返回获取指定卡槽SIM卡的MSISDN。 |

**示例：**

```js
let promise = sim.getSimTelephoneNumber(0);
promise.then(data => {
    console.log(`getSimTelephoneNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimTelephoneNumber failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimGid1<sup>7+</sup>

getSimGid1(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽中SIM卡的组标识符级别1（GID1）。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getSimGid1(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimGid1<sup>7+</sup>

getSimGid1(slotId: number): Promise<string\>

获取指定卡槽中SIM卡的组标识符级别1（GID1）。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getSimGid1(0);
promise.then(data => {
    console.log(`getSimGid1 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimGid1 failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getIMSI

getIMSI(slotId: number, callback: AsyncCallback<string\>): void

获取国际移动用户识别码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| slotId   | number                  | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getIMSI(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getIMSI

getIMSI(slotId: number): Promise<string\>

获取国际移动用户识别码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getIMSI(0);
promise.then(data => {
    console.log(`getIMSI success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getIMSI failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs(slotId: number, callback: AsyncCallback<Array<OperatorConfig\>>): void

获取运营商配置。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                      | 必填 | 说明                                   |
| -------- | --------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<Array<[OperatorConfig](#operatorconfig8)\>> | 是   | 回调函数。                             |

**示例：**

```js
sim.getOperatorConfigs(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOperatorConfigs<sup>8+</sup>

getOperatorConfigs(slotId: number): Promise<Array<OperatorConfig\>>

获取运营商配置。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.getOperatorConfigs(0);
promise.then(data => {
    console.log(`getOperatorConfigs success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOperatorConfigs failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers(slotId: number, type: ContactType, callback: AsyncCallback<Array<DiallingNumbersInfo\>>): void

查询SIM卡联系人号码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.READ_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                       |
| -------- | ------------------------------------------------------------ | ---- | ---------------------------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type     | [ContactType](#contacttype8)                                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| callback | AsyncCallback<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> | 是   | 回调函数。                                          |

**示例：**

```js
sim.queryIccDiallingNumbers(0, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.queryIccDiallingNumbers<sup>8+</sup>

queryIccDiallingNumbers(slotId: number, type: ContactType): Promise<Array<DiallingNumbersInfo\>>

查询SIM卡联系人号码。使用Promise异步回调。

此接口为系统接口。

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
| Promise<Array<[DiallingNumbersInfo](#diallingnumbersinfo8)\>> | 以Promise形式返回Icc拨号号码。 |

**示例：**

```js
let promise = sim.queryIccDiallingNumbers(0, 1);
promise.then(data => {
    console.log(`queryIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`queryIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback<void\>): void

添加SIM卡联系人号码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |
| callback        | AsyncCallback<void\>                         | 是   | 回调函数。                                                   |

**示例：**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    pin2: "1234"
};
sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.addIccDiallingNumbers<sup>8+</sup>

addIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise<void\>

添加SIM卡联系人号码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
let promise = sim.addIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof);
promise.then(data => {
    console.log(`addIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`addIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback<void\>): void

删除SIM卡联系人号码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |
| callback        | AsyncCallback<void\>                         | 是   | 回调函数。                                                   |

**示例：**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123,
    pin2: "1234"
};
sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.delIccDiallingNumbers<sup>8+</sup>

delIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise<void\>

删除SIM卡联系人号码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx"
};
let promise = sim.delIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof);
promise.then(data => {
    console.log(`delIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`delIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo, callback: AsyncCallback<void\>): void

更新SIM卡联系人号码。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.WRITE_CONTACTS

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名          | 类型                                         | 必填 | 说明                                                       |
| --------------- | -------------------------------------------- | ---- | ---------------------------------------------------------- |
| slotId          | number                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                     |
| type            | [ContactType](#contacttype8)                 | 是   | 联系人类型。<br/>- 1 : GENERAL_CONTACT<br/>- 2 : FIXED_DIALING |
| diallingNumbers | [DiallingNumbersInfo](#diallingnumbersinfo8) | 是   | 拨号号码信息。                                               |
| callback        | AsyncCallback<void\>                         | 是   | 回调函数。                                                   |

**示例：**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123,
    pin2: "1234"
};
sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.updateIccDiallingNumbers<sup>8+</sup>

updateIccDiallingNumbers(slotId: number, type: ContactType, diallingNumbers: DiallingNumbersInfo): Promise<void\>

更新SIM卡联系人号码。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let diallingNumbersInof = {
    alphaTag: "alpha",
    number: "138xxxxxxxx",
    recordNumber: 123
};
let promise = sim.updateIccDiallingNumbers(0, sim.ContactType.GENERAL_CONTACT, diallingNumbersInof);
promise.then(data => {
    console.log(`updateIccDiallingNumbers success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`updateIccDiallingNumbers failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd(slotId: number, cmd: string, callback: AsyncCallback<void\>): void

发送信封命令。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                   |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| cmd      | string               | 是   | 命令。                                   |
| callback | AsyncCallback<void\> | 是   | 回调函数。                                     |

**示例：**

```js
sim.sendEnvelopeCmd(0, "ls", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.sendEnvelopeCmd<sup>8+</sup>

sendEnvelopeCmd(slotId: number, cmd: string): Promise<void\>

发送信封命令。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.sendEnvelopeCmd(0, "ls");
promise.then(data => {
    console.log(`sendEnvelopeCmd success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`sendEnvelopeCmd failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd(slotId: number, cmd: string, callback: AsyncCallback<void\>): void

发送终端响应命令。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                   |
| -------- | -------------------- | ---- | -------------------------------------- |
| slotId   | number               | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| cmd      | string               | 是   | 命令。                                   |
| callback | AsyncCallback<void\> | 是   | 回调函数。                             |

**示例：**

```js
sim.sendTerminalResponseCmd(0, "ls", (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.sendTerminalResponseCmd<sup>8+</sup>

sendTerminalResponseCmd(slotId: number, cmd: string): Promise<void\>

发送终端响应命令。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let promise = sim.sendTerminalResponseCmd(0, "ls");
promise.then(data => {
    console.log(`sendTerminalResponseCmd success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`sendTerminalResponseCmd failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.unlockSimLock<sup>8+</sup>

unlockSimLock(slotId: number, lockInfo: PersoLockInfo, callback: AsyncCallback<LockStatusResponse\>): void

解锁SIM卡锁。使用callback异步回调。

此接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                       | 必填 | 说明                                   |
| -------- | ---------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                     | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| lockInfo | [PersoLockInfo](#persolockinfo8)                           | 是   | 定制锁类型信息。                         |
| callback | AsyncCallback<[LockStatusResponse](#lockstatusresponse7)\> | 是   | 回调函数。                               |

**示例：**

```js
let persoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
sim.unlockSimLock(0, persoLockInfo, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.unlockSimLock<sup>8+</sup>

unlockSimLock(slotId: number, lockInfo: PersoLockInfo): Promise<LockStatusResponse\>

解锁SIM卡锁。使用Promise异步回调。

此接口为系统接口。

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

**示例：**

```js
let persoLockInfo = {
    lockType: sim.PersoLockType.PN_PIN_LOCK,
    password: "1234"
};
let promise = sim.unlockSimLock(0, persoLockInfo);
promise.then(data => {
    console.log(`unlockSimLock success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockSimLock failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpKey<sup>9+</sup>

getOpKey(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽中SIM卡的opkey。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                             |

**示例：**

```js
sim.getOpKey(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOpKey<sup>9+</sup>

getOpKey(slotId: number): Promise<string\>

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

**示例：**

```js
let promise = sim.getOpKey(0);
promise.then(data => {
    console.log(`getOpKey success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOpKey failed, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getOpName<sup>9+</sup>

getOpName(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽中SIM卡的OpName。使用callback异步回调。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                   |
| -------- | ---------------------- | ---- | -------------------------------------- |
| slotId   | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback<string\> | 是   | 回调函数。                               |

**示例：**

```js
sim.getOpName(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getOpName<sup>9+</sup>

getOpName(slotId: number): Promise<string\>

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

**示例：**

```js
let promise = sim.getOpName(0);
promise.then(data => {
    console.log(`getOpName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getOpName failed, promise: err->${JSON.stringify(err)}`);
});
```

## SimState

SIM卡状态。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

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

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

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

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     | 值   | 说明        |
| -------- | ---- | ----------- |
| PIN_LOCK | 1    | SIM卡密码锁。 |
| FDN_LOCK | 2    | 固定拨号锁。  |

## LockState<sup>8+</sup>

锁状态。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     | 值   | 说明       |
| -------- | ---- | ---------- |
| LOCK_OFF | 0    | 锁关闭状态 |
| LOCK_ON  | 1    | 锁开启状态 |

## PersoLockType<sup>8+</sup>

定制锁类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称         | 值   | 说明                                            |
| ------------ | ---- | ----------------------------------------------- |
| PN_PIN_LOCK  | 0    | 定制网络PIN锁*(参照 3GPP TS 22.022 [33])*。       |
| PN_PUK_LOCK  | 1    | 定制网络PUk锁。                                   |
| PU_PIN_LOCK  | 2    | 定制网络子集PIN锁*(参照 3GPP TS 22.022 [33])*。   |
| PU_PUK_LOCK  | 3    | 定制网络子集PUK锁。                               |
| PP_PIN_LOCK  | 4    | 定制服务提供者PIN锁*(参照 3GPP TS 22.022 [33])*。 |
| PP_PUK_LOCK  | 5    | 定制服务提供者PUK锁。                             |
| PC_PIN_LOCK  | 6    | 定制企业PIN锁*(参照 3GPP TS 22.022 [33])*。       |
| PC_PUK_LOCK  | 7    | 定制企业Puk锁。                                   |
| SIM_PIN_LOCK | 8    | 定制SIM的PIN锁*(参照 3GPP TS 22.022 [33])*。      |
| SIM_PUK_LOCK | 9    | 定制SIM的PUK锁。                                  |

## LockStatusResponse<sup>7+</sup>

锁状态响应。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称            | 类型   | 必填 | 说明                  |
| --------------- | ------ | ---- | --------------------- |
| result          | number |  是  | 当前操作的结果。      |
| remain?: number | number |  否  | 剩余次数（可以为空）。|

## LockInfo<sup>8+</sup>

锁状态响应。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     |           类型           | 必填 |   说明   |
| -------- | ------------------------ | ---- | -------- |
| lockType | [LockType](#locktype8)   |  是  | 锁类型。 |
| password | string                   |  是  | 密码。   |
| state    | [LockState](#lockstate8) |  是  | 锁状态。 |

## PersoLockInfo<sup>8+</sup>

锁状态响应。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     |               类型               | 必填 |      说明     |
| -------- | -------------------------------- | ---- | ------------- |
| lockType | [PersoLockType](#persolocktype8) |  是  | 定制锁的类型。|
| password | string                           |  是  | 密码。        |

## IccAccountInfo<sup>7+</sup>

Icc账户信息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

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

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称  | 类型   | 必填 | 说明 |
| ----- | ------ | ---- | ---- |
| field | string |  是  | 字段 |
| value | string |  是  | 值   |

## DiallingNumbersInfo<sup>8+</sup>

拨号号码信息。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称         | 类型   | 必填 |    说明    |
| ------------ | ------ | ---- | ---------- |
| alphaTag     | string |  是  | 标签。     |
| number       | string |  是  | 号码。     |
| recordNumber | number |  是  | 记录编号。 |
| pin2         | string |  是  | pin2密码。 |

## ContactType<sup>8+</sup>

联系人类型。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称            | 值   | 说明       |
| --------------- | ---- | ---------- |
| GENERAL_CONTACT | 1    | 通用联系人。 |
| FIXED_DIALING   | 2    | 固定拨号。   |

## OperatorConfigKey<sup>9+</sup>

运营商配置键。

此接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

|                             名称                        |                             值                       |         说明         |
| ------------------------------------------------------- | ---------------------------------------------------- | -------------------- |
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
| KEY_IMS_CALL_DISCONNECT_REASONINFO_MAPPING_STRING_ARRAY | "ims_call_disconnect_reasoninfo_mapping_string_array"  | IMS呼叫结束原因列表。|
| KEY_FORCE_VOLTE_SWITCH_ON_BOOL                          | "force_volte_switch_on_bool"                           | 强制VOLTE开关。      |
| KEY_ENABLE_OPERATOR_NAME_CUST_BOOL                      | "enable_operator_name_cust_bool"                       | 是否显示运营商名称。 |
| KEY_OPERATOR_NAME_CUST_STRING                           | "operator_name_cust_string"                            | 运营商名称。         |
| KEY_SPN_DISPLAY_CONDITION_CUST_INT                      | "spn_display_condition_cust_int"                       | SPN显示规则。        |
| KEY_PNN_CUST_STRING_ARRAY                               | "pnn_cust_string_array"                                | PLMN名称。           |
| KEY_OPL_CUST_STRING_ARRAY                               | "opl_cust_string_array"                                | 运营商PLMN信息。     |
| KEY_EMERGENCY_CALL_STRING_ARRAY                         | "emergency_call_string_array"                          | 紧急呼叫列表。       |
