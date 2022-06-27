# SIM卡管理

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

获取指定卡槽SIM卡是否激活，使用callback方式作为异步方法。

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

获取指定卡槽SIM卡是否激活，使用Promise方式作为异步方法。

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
    console.log(`isSimActive fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getDefaultVoiceSlotId<sup>7+</sup>

getDefaultVoiceSlotId\(callback: AsyncCallback<number\>\): void

获取默认语音业务的卡槽ID，使用callback方式作为异步方法。

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

获取默认语音业务的卡槽ID，使用Promise方式作为异步方法。

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
    console.log(`getDefaultVoiceSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.hasOperatorPrivileges<sup>7+</sup>

hasOperatorPrivileges(slotId: number, callback: AsyncCallback\<boolean\>): void

检查应用（调用者）是否已被授予运营商权限，使用callback方式作为异步方法。

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

检查应用（调用者）是否已被授予运营商权限，使用Promise方式作为异步方法。

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
    console.log(`hasOperatorPrivileges fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getISOCountryCodeForSim

getISOCountryCodeForSim\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的ISO国家码，使用callback方式作为异步方法。

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

获取指定卡槽SIM卡的ISO国家码，使用Promise方式作为异步方法。

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
    console.log(`getISOCountryCodeForSim fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimOperatorNumeric

getSimOperatorNumeric\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号，使用callback方式作为异步方法。

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

获取指定卡槽SIM卡的归属PLMN（Public Land Mobile Network）号，使用Promise方式作为异步方法。

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
    console.log(`getSimOperatorNumeric fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimSpn

getSimSpn\(slotId: number, callback: AsyncCallback<string\>\): void

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN），使用callback方式作为异步方法。

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

获取指定卡槽SIM卡的服务提供商名称（Service Provider Name，SPN），使用Promise方式作为异步方法。

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
    console.log(`getSimSpn fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.getSimState

getSimState\(slotId: number, callback: AsyncCallback<SimState\>\): void

获取指定卡槽的SIM卡状态，使用callback方式作为异步方法。

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

获取指定卡槽的SIM卡状态，使用Promise方式作为异步方法。

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
    console.log(`getSimState fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getCardType<sup>7+</sup>

getCardType\(slotId: number, callback: AsyncCallback<CardType\>\): void

获取指定卡槽SIM卡的卡类型，使用callback方式作为异步方法。

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

获取指定卡槽SIM卡的卡类型，使用Promise方式作为异步方法。

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
    console.log(`getCardType fail, promise: err->${JSON.stringify(err)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number, callback: AsyncCallback<boolean\>\): void

获取指定卡槽SIM卡是否插卡，使用callback方式作为异步方法。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                   |
| -------- | --------------------------- | ---- | -------------------------------------- |
| slotId   | number                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。                             |

**示例：**

```jsjs
sim.hasSimCard(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.hasSimCard<sup>7+</sup>

hasSimCard\(slotId: number\): Promise<boolean\>

获取指定卡槽SIM卡是否插卡，使用Promise方式作为异步方法。

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
    console.log(`hasSimCard fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getSimAccountInfo<sup>7+</sup>

getSimAccountInfo(slotId: number, callback: AsyncCallback<IccAccountInfo\>): void

获取SIM卡账户信息，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                   |
| -------- | --------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                              | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[IccAccountInfo](#IccAccountInfo7)\> | 是   | 回调函数。参考[IccAccountInfo](#IccAccountInfo7)。 |

**示例：**

```js
sim.getSimAccountInfo(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getSimAccountInfo<sup>7+</sup>

getSimAccountInfo(slotId: number): Promise<IccAccountInfo\>

获取SIM卡账户信息，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                                         | 说明                                       |
| -------------------------------------------- | ------------------------------------------ |
| Promise<[IccAccountInfo](#IccAccountInfo7)\> | 以Promise形式返回指定卡槽SIM卡的账户信息。 |

**示例：**

```js
let promise = sim.getSimAccountInfo(0);
promise.then(data => {
    console.log(`getSimAccountInfo success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getSimAccountInfo fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getActiveSimAccountInfoList<sup>8+</sup>

getActiveSimAccountInfoList(callback: AsyncCallback<Array<IccAccountInfo\>>): void

获取活跃SIM卡账户信息列表，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明       |
| -------- | ----------------------------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array<[IccAccountInfo](#IccAccountInfo7)\>\> | 是   | 回调函数。 |

**示例：**

```js
sim.getActiveSimAccountInfoList(0, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getActiveSimAccountInfoList<sup>8+</sup>

getActiveSimAccountInfoList(): Promise<Array<IccAccountInfo\>>;

获取活跃SIM卡账户信息列表，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.GET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**返回值：**

| 类型                                                 | 说明                                           |
| ---------------------------------------------------- | ---------------------------------------------- |
| Promise<Array<[IccAccountInfo](#IccAccountInfo7)\>\> | 以Promise形式返回活跃卡槽SIM卡的账户信息列表。 |

**示例：**

```js
let promise = sim.getActiveSimAccountInfoList();
promise.then(data => {
    console.log(`getActiveSimAccountInfoList success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getActiveSimAccountInfoList fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId(slotId: number, callback: AsyncCallback<void\>): void

设置默认语音业务的卡槽ID，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                    | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                                                   |

**示例：**

```js
sim.setDefaultVoiceSlotId(0,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setDefaultVoiceSlotId<sup>7+</sup>

setDefaultVoiceSlotId(slotId: number): Promise\<void\>

设置默认语音业务的卡槽ID，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| slotId | number | 是   | SIM卡槽ID：<br/>- 0：卡槽1<br/>- 1：卡槽2<br/>- -1：清除默认配置 |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void\> | 无返回结果的Promise对象。        |

**示例：**

```js
let promise = sim.setDefaultVoiceSlotId(0);
promise.then(data => {
    console.log(`setDefaultVoiceSlotId success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setDefaultVoiceSlotId fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**setShowName**<sup>8+</sup>

setShowName\(slotId: number, name: string,callback: AsyncCallback<void\>\): void

设置指定卡槽SIM卡显示的名称，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| name     | string                    | 是   | SIM卡名称                              |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
const name='中国移动';
sim.setShowName(0, name,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```

## sim.**setShowName**<sup>8+</sup>

setShowName\(slotId: number, name: string\): Promise\<void\>

设置指定卡槽SIM卡显示的名称，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| name   | string | 是   | SIM卡名称                              |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void\> | 无返回结果的Promise对象。        |

**示例：**

```js
const name='中国移动';
let promise = sim.setShowName(0,name);
promise.then(data => {
    console.log(`setShowName success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setShowName fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**getShowName**<sup>8+</sup>

getShowName(slotId: number, callback: AsyncCallback<string\>): void

获取指定卡槽SIM卡的名称，使用callback方式作为异步方法。

该接口为系统接口。

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

获取指定卡槽SIM卡的名称，使用Promise方式作为异步方法。

该接口为系统接口。

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
    console.log(`getShowName fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**setShowNumber**<sup>8+</sup>

setShowNumber\(slotId: number, number: string,callback: AsyncCallback<void\>\): void

设置指定卡槽SIM卡的号码，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                   |
| -------- | ------------------------- | ---- | -------------------------------------- |
| slotId   | number                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| number   | string                    | 是   | SIM卡号码                              |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。                             |

**示例：**

```js
let number='+861xxxxxxxxxx';
sim.setShowNumber(0, number,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**setShowNumber**<sup>8+</sup>

setShowNumber\(slotId: number,number: string\): Promise\<void\>

设置指定卡槽SIM卡的号码，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| number | string | 是   | SIM卡号码                              |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void\> | 无返回结果的Promise对象。        |

**示例：**

```js
let number='+861xxxxxxxxxx';
let promise = sim.setShowNumber(0,number);
promise.then(data => {
    console.log(`setShowNumber success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setShowNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**getShowNumber**<sup>8+</sup>

getShowNumber(slotId: number,callback: AsyncCallback<string\>): void

获取指定卡槽SIM卡的号码，使用callback方式作为异步方法。

该接口为系统接口。

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

获取指定卡槽SIM卡的号码，使用Promise方式作为异步方法。

该接口为系统接口。

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
    console.log(`getShowNumber fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**activateSim**<sup>8+</sup>

activateSim(slotId: number, callback: AsyncCallback<void\>): void

激活指定卡槽SIM卡，使用callback方式作为异步方法。

该接口为系统接口。

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

激活指定卡槽SIM卡，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void\> | 无返回结果的Promise对象。        |

**示例：**

```js
let promise = sim.activateSim(0);
promise.then(data => {
    console.log(`activateSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`activateSim fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**deactivateSim**<sup>8+</sup>

deactivateSim(slotId: number, callback: AsyncCallback<void\>): void

禁用指定卡槽SIM卡，使用callback方式作为异步方法。

该接口为系统接口。

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

禁用指定卡槽SIM卡，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型           | 说明                            |
| -------------- | ------------------------------- |
| Promise\<void\> | 无返回结果的Promise对象。        |

**示例：**

```js
let promise = sim.deactivateSim(0);
promise.then(data => {
    console.log(`deactivateSim success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`deactivateSim fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.setLockState<sup>7+</sup>

setLockState(slotId: number, options: LockInfo, callback: AsyncCallback<LockStatusResponse\>): void

设置指定卡槽SIM卡的锁状态，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| callback | AsyncCallback\<[LockStatusResponse](#LockStatusResponse7)\> | 是   | 回调函数。                                                   |
| options  | [LockInfo](#LockInfo8)                                      | 是   | 锁信息。<br/>lockType: [LockType](#LockType8)<br/>password: string<br/>state: [LockState](#LockState8) |

**示例：**

```js
LockInfo.lockType = 1;
LockInfo.password = "1234";
LockInfo.state = 0;
sim.setLockState(0, LockInfo, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.setLockState<sup>7+</sup>

setLockState(slotId: number, options: LockInfo): Promise<LockStatusResponse\>

设置指定卡槽SIM卡的锁状态，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型                   | 必填 | 说明                                                         |
| ------- | ---------------------- | ---- | ------------------------------------------------------------ |
| slotId  | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2                       |
| options | [LockInfo](#LockInfo8) | 是   | 锁信息。<br/>lockType: [LockType](#LockType8)<br/>password: string<br/>state: [LockState](#LockState8) |

**返回值：**

| 类型                                                 | 说明                                         |
| ---------------------------------------------------- | -------------------------------------------- |
| Promise<[LockStatusResponse](#LockStatusResponse7)\> | 以Promise形式返回获取指定卡槽SIM卡的锁状态。 |

**示例：**

```js
LockInfo.lockType = 1;
LockInfo.password = "1234";
LockInfo.state = 0;
let promise = sim.setLockState(0, LockInfo);
promise.then(data => {
    console.log(`setLockState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`setLockState fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.getLockState<sup>8+</sup>

getLockState(slotId: number, lockType: LockType, callback: AsyncCallback<LockState\>): void

获取指定卡槽SIM卡的锁状态，使用callback方式作为异步方法。

该接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                    |
| -------- | ----------------------------------------- | ---- | --------------------------------------- |
| slotId   | number                                    | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |
| callback | AsyncCallback\<[LockState](#LockState8)\> | 是   | 回调函数。                              |
| options  | [LockType](#LockType8)                    | 是   | 锁类型。<br/>- 1: PIN锁<br/>- 2: PIN2锁 |

**示例：**

```js
sim.getLockState(0, 1, (err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.getLockState<sup>8+</sup>

getLockState(slotId: number, lockType: LockType): Promise<LockState\>

获取指定卡槽SIM卡的锁状态，使用callback方式作为异步方法。

该接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型                   | 必填 | 说明                                    |
| ------- | ---------------------- | ---- | --------------------------------------- |
| slotId  | number                 | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2  |
| options | [LockType](#LockType8) | 是   | 锁类型。<br/>- 1: PIN锁<br/>- 2: PIN2锁 |

**返回值：**

| 类型                               | 说明                                         |
| ---------------------------------- | -------------------------------------------- |
| Promise<[LockState](#LockState8)\> | 以Promise形式返回获取指定卡槽SIM卡的锁状态。 |

**示例：**

```js
let promise = sim.getLockState(0, 1);
promise.then(data => {
    console.log(`getLockState success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`getLockState fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin<sup>7+</sup>

alterPin(slotId: number, newPin: string, oldPin: string, callback: AsyncCallback<LockStatusResponse\>): void

更改Pin密码，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                   |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[LockStatusResponse](#LockStatusResponse7)\> | 是   | 回调函数。                             |
| newPin   | string                                                      | 是   | 新密码。                               |
| oldPin   | string                                                      | 是   | 旧密码。                               |

**示例：**

```js
sim.alterPin(0, "1234", "0000"(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.alterPin<sup>7+</sup>

alterPin(slotId: number, newPin: string, oldPin: string): Promise<LockStatusResponse\>;

更改Pin密码，使用callback方式作为异步方法。

该接口为系统接口。

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
| Promise<[LockStatusResponse](#LockStatusResponse7)\> | 以Promise形式返回指定卡槽SIM卡的Pin是否成功。 |

**示例：**

```js
let promise = sim.alterPin(0, "1234", "0000");
promise.then(data => {
    console.log(`alterPin success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`alterPin fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.alterPin2<sup>8+</sup>

alterPin2(slotId: number, newPin2: string, oldPin2: string, callback: AsyncCallback<LockStatusResponse\>): void

更改Pin2密码，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                   |
| -------- | ----------------------------------------------------------- | ---- | -------------------------------------- |
| slotId   | number                                                      | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| callback | AsyncCallback\<[LockStatusResponse](#LockStatusResponse7)\> | 是   | 回调函数。                             |
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

更改Pin2密码，使用callback方式作为异步方法。

该接口为系统接口。

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
| Promise<[LockStatusResponse](#LockStatusResponse7)\> | 以Promise形式返回指定卡槽SIM卡的Pin是否成功。 |

**示例：**

```js
let promise = sim.alterPin2(0, "1234","0000");
promise.then(data => {
    console.log(`alterPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`alterPin2 fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPin**<sup>7+</sup>

unlockPin(slotId: number,pin: string ,callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin      | string                                                       | 是   | SIM卡的密码                            |
| callback | AsyncCallback&lt;[LockStatusResponse](#LockStatusResponse7)> | 是   | 回调函数。                             |

**示例：**

```js
let pin='1234';
sim.unlockPin(0, pin,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPin**<sup>7+</sup>

unlockPin(slotId: number,pin: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin    | string | 是   | SIM卡的密码                            |

**返回值：**

| 类型                                                 | 说明                                               |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#LockStatusResponse)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**示例：**

```js
let pin='1234';
let promise = sim.unlockPin(0,pin);
promise.then(data => {
    console.log(`unlockPin success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPin fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPuk**<sup>7+</sup>

unlockPuk(slotId: number,newPin: string,puk: string ,callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码的解锁密码，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin   | string                                                       | 是   | 重置SIM卡的密码                        |
| puk      | string                                                       | 是   | SIM卡密码的解锁密码                    |
| callback | AsyncCallback&lt;[LockStatusResponse](#LockStatusResponse7)&gt; | 是   | 回调函数。                             |

**示例：**

```js
let puk='1xxxxxxx';
let newPin='1235';
sim.unlockPuk(0, newPin,puk,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPuk**<sup>7+</sup>

unlockPuk(slotId: number,newPin: string,puk: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码的解锁密码，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin | string | 是   | 重置SIM卡的密码                        |
| puk    | string | 是   | SIM卡密码的解锁密码                    |

**返回值：**

| 类型                                                 | 说明                                               |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#LockStatusResponse)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**示例：**

```js
let puk='1xxxxxxx';
let newPin='1235';
let promise = sim.unlockPuk(0,newPin,puk);
promise.then(data => {
    console.log(`unlockPuk success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPuk fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPin**2<sup>8+</sup>

****unlockPin2****(slotId: number,pin2: string ,callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin2     | string                                                       | 是   | SIM卡的密码                            |
| callback | AsyncCallback&lt;[LockStatusResponse](#LockStatusResponse7)&gt; | 是   | 回调函数。                             |

**示例：**

```js
let pin2='1234';
sim.unlockPin2(0, pin2,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPin**2<sup>8+</sup>

unlockPin2(slotId: number,pin2: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| pin2   | string | 是   | SIM卡的密码                            |

**返回值：**

| 类型                                                  | 说明                                               |
| ----------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#LockStatusResponse7)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**示例：**

```js
let pin2='1234';
let promise = sim.unlockPin2(0,pin2);
promise.then(data => {
    console.log(`unlockPin2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPin2 fail, promise: err->${JSON.stringify(err)}`);
});
```

## sim.**unlockPuk**2<sup>8+</sup>

unlockPuk2(slotId: number,newPin2: string,puk2: string ,callback: AsyncCallback<LockStatusResponse\>): void

解锁指定卡槽SIM卡密码的解锁密码，使用callback方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| slotId   | number                                                       | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin2  | string                                                       | 是   | 重置SIM卡的密码                        |
| puk2     | string                                                       | 是   | SIM卡密码的解锁密码                    |
| callback | AsyncCallback&lt;[LockStatusResponse](#LockStatusResponse7)&gt; | 是   | 回调函数。                             |

**示例：**

```js
let puk2='1xxxxxxx';
let newPin2='1235';
sim.unlockPuk2(0, newPin2,puk2,(err, data) => {
    console.log(`callback: err->${JSON.stringify(err)}, data->${JSON.stringify(data)}`);
});
```


## sim.**unlockPuk2**<sup>8+</sup>

unlockPuk2slotId: number,newPin2: string,puk2: string): Promise&lt;LockStatusResponse\>

解锁指定卡槽SIM卡密码的解锁密码，使用Promise方式作为异步方法。

该接口为系统接口。

**需要权限**：ohos.permission.SET_TELEPHONY_STATE

**系统能力**：SystemCapability.Telephony.CoreService

**参数：**

| 参数名  | 类型   | 必填 | 说明                                   |
| ------- | ------ | ---- | -------------------------------------- |
| slotId  | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |
| newPin2 | string | 是   | 重置SIM卡的密码                        |
| puk2    | string | 是   | SIM卡密码的解锁密码                    |

**返回值：**

| 类型                                                 | 说明                                               |
| ---------------------------------------------------- | -------------------------------------------------- |
| Promise\<[LockStatusResponse](#LockStatusResponse)\> | 以Promise形式返回获取指定卡槽的SIM卡锁状态的响应。 |

**示例：**

```js
let puk2='1xxxxxxx';
let newPin2='1235';
let promise = sim.unlockPuk2(0,newPin2,puk2);
promise.then(data => {
    console.log(`unlockPuk2 success, promise: data->${JSON.stringify(data)}`);
}).catch(err => {
    console.log(`unlockPuk2 fail, promise: err->${JSON.stringify(err)}`);
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
|UNKNOWN_CARD | -1 | 未知类型 |
|SINGLE_MODE_SIM_CARD | 10 | 单SIM卡 |
|SINGLE_MODE_USIM_CARD | 20 | 单USIM卡 |
|SINGLE_MODE_RUIM_CARD | 30 | 单RUIM卡 |
|DUAL_MODE_CG_CARD | 40 | 双卡模式C+G |
|CT_NATIONAL_ROAMING_CARD | 41 | 中国电信内部漫游卡 |
|CU_DUAL_MODE_CARD | 42 | 中国联通双模卡 |
|DUAL_MODE_TELECOM_LTE_CARD | 43 | 双模式电信LTE卡 |
|DUAL_MODE_UG_CARD | 50 | 双模式UG卡 |
|SINGLE_MODE_ISIM_CARD<sup>8+</sup> | 60 | 单一ISIM卡类型 |

## LockType<sup>8+</sup>

锁类型。

该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     | 值   | 说明        |
| -------- | ---- | ----------- |
| PIN_LOCK | 1    | SIM卡密码锁 |
| FDN_LOCK | 2    | 固定拨号锁  |

## LockState<sup>8+</sup>

锁状态。

该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     | 值   | 说明       |
| -------- | ---- | ---------- |
| LOCK_OFF | 0    | 锁关闭状态 |
| LOCK_ON  | 1    | 锁开启状态 |

## **PersoLockType**<sup>8+</sup>

定制锁类型。

该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称         | 值   | 说明                                            |
| ------------ | ---- | ----------------------------------------------- |
| PN_PIN_LOCK  | 0    | 定制网络PIN锁*(参照 3GPP TS 22.022 [33])*       |
| PN_PUK_LOCK  | 1    | 定制网络PUk锁                                   |
| PU_PIN_LOCK  | 2    | 定制网络子集PIN锁*(参照 3GPP TS 22.022 [33])*   |
| PU_PUK_LOCK  | 3    | 定制网络子集PUK锁                               |
| PP_PIN_LOCK  | 4    | 定制服务提供者PIN锁*(参照 3GPP TS 22.022 [33])* |
| PP_PUK_LOCK  | 5    | 定制服务提供者PUK锁                             |
| PC_PIN_LOCK  | 6    | 定制企业PIN锁*(参照 3GPP TS 22.022 [33])*       |
| PC_PUK_LOCK  | 7    | 定制企业Puk锁                                   |
| SIM_PIN_LOCK | 8    | 定制SIM的PIN锁*(参照 3GPP TS 22.022 [33])*      |
| SIM_PUK_LOCK | 9    | 定制SIM的PUK锁                                  |

## **LockStatusResponse**<sup>7+</sup>

锁状态响应。

该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称            | 类型   | 说明               |
| --------------- | ------ | ------------------ |
| result          | number | 当前操作的结果     |
| remain?: number | number | 剩余次数(可以为空) |

## **LockInfo**<sup>8+</sup>

锁状态响应。

该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     | 类型      | 说明   |
| -------- | --------- | ------ |
| lockType | LockType  | 锁类型 |
| password | string    | 密码   |
| state    | LockState | 锁状态 |

## **PersoLockInfo**<sup>8+</sup>

锁状态响应。

该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称     | 类型          | 说明         |
| -------- | ------------- | ------------ |
| lockType | PersoLockType | 定制锁的类型 |
| password | string        | 密码         |

## **IccAccountInfo**<sup>7+</sup>

Icc账户信息。

该接口为系统接口。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Telephony.CoreService。

| 名称       | 类型    | 说明             |
| ---------- | ------- | ---------------- |
| simId      | number  | SIM卡ID          |
| slotIndex  | number  | 卡槽ID           |
| isEsim     | boolean | 标记卡是否是eSim |
| isActive   | boolean | 卡是否被激活     |
| iccId      | string  | ICCID号码        |
| showName   | string  | SIM卡显示名称    |
| showNumber | string  | SIM卡显示号码    |

