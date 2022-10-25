# 网络策略管理

网络策略管理通过对用户使用数据流量进行控制管理，采用防火墙技术实现网络策略的管理。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import policy from '@ohos.net.policy'
```

## policy.setBackgroundPolicy

setBackgroundPolicy(isAllowed: boolean, callback: AsyncCallback\<void>): void

设置后台网络策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| isAllowed | boolean | 是   | 是否允许应用后台使用数据 |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回设定结果。 |

**示例：**

```js
policy.setBackgroundPolicy(Boolean(Number.parseInt(this.isBoolean))), (err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
});
```

## policy.setBackgroundPolicy

setBackgroundPolicy(isAllowed: boolean): Promise\<void>

设置后台网络策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| isAllowed | boolean | 是   | 是否允许应用后台使用数据 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
policy.setBackgroundPolicy(Boolean(Number.parseInt(this.isBoolean))).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.getBackgroundPolicy

getBackgroundPolicy(callback: AsyncCallback\<boolean>): void;

获取后台网络策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true代表后台策略为允许。 |

**示例：**

```js
policy.getBackgroundPolicy((err, data) => {
    this.callBack(err, data);
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
});
```

## policy.getBackgroundPolicy

getBackgroundPolicy(): Promise\<boolean>;

获取后台网络策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise形式返回设定结果。 |

**示例：**

```js
policy.getBackgroundPolicy().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.setPolicyByUid

setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void;

设置对应uid应用的访问计量网络的策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | 应用的唯一标识符 |
| policy | [NetUidPolicy](#netuidpolicy) | 是 | 应用对应的策略 |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回设定结果。 |

**示例：**

```js
let param = {
    uid: Number.parseInt(this.firstParam), policy: Number.parseInt(this.currentNetUidPolicy)
}
policy.setPolicyByUid(Number.parseInt(this.firstParam), Number.parseInt(this.currentNetUidPolicy), (err, data) => {
    this.callBack(err, data);
});
```

## policy.setPolicyByUid

setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>;

设置对应uid应用的访问计量网络的策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | 应用的唯一标识符 |
| policy | [NetUidPolicy](#netuidpolicy) | 是 | 应用对应的策略 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
let param = {
    uid: Number.parseInt(this.firstParam), policy: Number.parseInt(this.currentNetUidPolicy)
}
policy.setPolicyByUid(Number.parseInt(this.firstParam), Number.parseInt(this.currentNetUidPolicy)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getPolicyByUid

getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void;

通过应用uid获取策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| callback | AsyncCallback\<[NetUidPolicy](#netuidpolicy)> | 是   | 回调函数，返回获取结果。 |

**示例：**

```js
policy.getPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
    this.callBack(err, data);
});
```

## policy.getPolicyByUid

getPolicyByUid(uid: number): Promise\<NetUidPolicy>;

通过应用uid获取策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetUidPolicy](#netuidpolicy)> | 以Promise形式返回设定结果。 |

**示例：**

```js
policy.getPolicyByUid(Number.parseInt(this.firstParam)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getUidsByPolicy

getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void;

通过策略获取设置这一策略的应用uid数组，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| policy | [NetUidPolicy](#netuidpolicy) | 是 | 应用对应的计量网络下的策略 |
| callback | AsyncCallback\<Array\<number>> | 是   | 回调函数，返回获取结果。 |

**示例：**

```js
policy.getUidsByPolicy(Number.parseInt(this.currentNetUidPolicy), (err, data) => {
    this.callBack(err, data);
});
```

## policy.getUidsByPolicy

function getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>;

通过策略获取设置这一策略的应用uid数组，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| policy | [NetUidPolicy](#netuidpolicy) | 是 | app对应的计量网络下的策略 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<number>> | 以Promise形式返回设定结果。 |

**示例：**

```js
policy.getUidsByPolicy(Number.parseInt(this.firstParam)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getNetQuotaPolicies

getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void;

获取计量网络策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | 是   | 回调函数，返回获取结果。 |

**示例：**

```js
policy.getNetQuotaPolicies((err, data) => {
    this.callBack(err, data);
});
```

## policy.getNetQuotaPolicies

getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>;

获取计量网络策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | 以Promise形式返回设定结果。 |

**示例：**

```js
policy.getNetQuotaPolicies().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.setNetQuotaPolicies

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void;

设置计量网络策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy)> | 是 | 计量网络策略 |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回设定结果。 |

**示例：**

```js
let param = {netType:Number.parseInt(this.netType), iccid:this.iccid, ident:this.ident, periodDuration:this.periodDuration, warningBytes:Number.parseInt(this.warningBytes),
    limitBytes:Number.parseInt(this.limitBytes), lastWarningRemind:this.lastWarningRemind, lastLimitRemind:this.lastLimitRemind, metered:Boolean(Number.parseInt(this.metered)), limitAction:this.limitAction};
this.netQuotaPolicyList.push(param);

policy.setNetQuotaPolicies(this.netQuotaPolicyList, (err, data) => {
    this.callBack(err, data);
});
```

## policy.setNetQuotaPolicies

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>;

设置计量网络策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy)> | 是 | 计量网络策略 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
let param = {netType:Number.parseInt(this.netType), iccid:this.iccid, ident:this.ident, periodDuration:this.periodDuration, warningBytes:Number.parseInt(this.warningBytes),
    limitBytes:Number.parseInt(this.limitBytes), lastWarningRemind:this.lastWarningRemind, lastLimitRemind:this.lastLimitRemind, metered:Boolean(Number.parseInt(this.metered)), limitAction:this.limitAction};
this.netQuotaPolicyList.push(param);

policy.setNetQuotaPolicies(this.netQuotaPolicyList).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.restoreAllPolicies

restoreAllPolicies(iccid: string, callback: AsyncCallback\<void>): void;

重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | 是 | SIM卡ID|
| callback | AsyncCallback\<void> | 是   | 回调函数，返回重置结果。 |

**示例：**

```js
this.firstParam = iccid;
policy.restoreAllPolicies(this.firstParam, (err, data) => {
    this.callBack(err, data);
});
```

## policy.restoreAllPolicies

restoreAllPolicies(iccid: string): Promise\<void>;

重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | 是 | SIM卡ID|

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
this.firstParam = iccid;
policy.restoreAllPolicies(this.firstParam).then((err, data){
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void;

获取对应uid能否访问计量或非计量网络，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| isMetered | boolean | 是 | 是否为计量网络 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true表示这个uid可以访问对应的计量网络。 |

**示例：**

```js

let param = {
    uid: Number.parseInt(this.firstParam), isMetered: Boolean(Number.parseInt(this.isBoolean))
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
    this.callBack(err, data);
});
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>;

获取对应uid能否访问计量或非计量网络，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| isMetered | boolean | 是 | 是否为计量网络 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise形式返回设定结果。 |

**示例：**

```js

let param = {
    uid: Number.parseInt(this.firstParam), isMetered: Boolean(Number.parseInt(this.isBoolean))
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean))).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void;

获取对应uid能否访问指定的iface的网络，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| iface | string | 是 | 网络对应的名称 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true表示这个uid可以访问对应iface的网络。 |

**示例：**

```js

let param = {
    uid: Number.parseInt(this.firstParam), iface: this.secondParam
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), this.secondParam, (err, data) => {
    this.callBack(err, data);
});
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, iface: string): Promise\<boolean>;

获取对应uid能否访问指定的iface的网络，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| iface | string | 是 | 网络对应的名称 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise形式返回设定结果。 |

**示例：**

```js
let param = {
    uid: Number.parseInt(this.firstParam), iface: this.secondParam
}
policy.isUidNetAllowed(Number.parseInt(this.firstParam), this.secondParam).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.setDeviceIdleAllowlist

setDeviceIdleAllowList(uid: number, isAllowed: boolean, callback: AsyncCallback\<void>): void;

设置指定uid能应用是否在休眠防火墙的白名单，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| isAllowed | boolean | 是 | 是否加入白名单 |
| callback | callback: AsyncCallback\<void> | 是   | 回调函数，返回设定结果。 |

**示例：**

```js
let param = {
    uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
}
policy.setDeviceIdleAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean)), (err, data) => {
    this.callBack(err, data);
});
```

## policy.setDeviceIdleAllowlist

setDeviceIdleAllowList(uid: number, isAllowed: boolean): Promise\<void>;

设置指定uid能应用是否在休眠防火墙的白名单，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| isAllowed | boolean | 是 | 是否加入白名单 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
let param = {
    uid: Number.parseInt(this.firstParam), isAllowed: Boolean(Number.parseInt(this.isBoolean))
}
policy.setDeviceIdleAllowList(Number.parseInt(this.firstParam), Boolean(Number.parseInt(this.isBoolean))).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.getDeviceIdleAllowlist

getDeviceIdleAllowList(callback: AsyncCallback\<Array\<number>>): void;

获取休眠模式白名单所包含的uid数组，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array\<number>> | 是   | 回调函数，返回获取结果。 |

**示例：**

```js
policy.getDeviceIdleAllowList((err, data) => {
    this.callBack(err, data);
});
```

## policy.getDeviceIdleAllowlist

getDeviceIdleAllowList(): Promise\<Array\<number>>;

获取休眠模式白名单所包含的uid数组，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<number>> | 以Promise形式返回设定结果。 |

**示例：**

```js
policy.getDeviceIdleAllowList().then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.getBackgroundPolicyByUid

getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void;

获取指定uid能否访问后台网络，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| callback | AsyncCallback\<[NetBackgroundPolicy](#netbackgroundpolicy)> | 是   | 回调函数，返回获取结果。 |

**示例：**

```js
this.firstParam = uid
policy.getBackgroundPolicyByUid(Number.parseInt(this.firstParam), (err, data) => {
    this.callBack(err, data);
});
```

## policy.getBackgroundPolicyByUid

getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>;

获取指定uid能否访问后台网络，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetBackgroundPolicy](#netbackgroundpolicy)> | 以Promise形式返回设定结果。 |

**示例：**

```js
this.firstParam = uid
policy.getBackgroundPolicyByUid(Number.parseInt(this.firstParam)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})
```

## policy.resetPolicies

resetPolicies(iccid: string, callback: AsyncCallback\<void>): void;

重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | 是 | SIM卡ID|
| callback | AsyncCallback\<void> | 是   | 回调函数，返回重置结果。 |

**示例：**

```js
this.firstParam = iccid
policy.resetPolicies(this.firstParam, (err, data) => {
    this.callBack(err, data);
});
```

## policy.resetPolicies

resetPolicies(iccid: string): Promise\<void>;

重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| iccid | string | 是 | SIM卡ID|

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
policy.getUidsByPolicy(Number.parseInt(this.firstParam)).then((err, data) {

})
this.firstParam = iccid
policy.resetPolicies(this.firstParam).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.updateRemindPolicy

updateRemindPolicy(netType: NetBearType, iccid: string, remindType: RemindType, callback: AsyncCallback\<void>): void;

更新提醒策略，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| netType | [NetBearType](js-apis-net-connection.md#netbeartype) | 是 | 网络类型 |
| iccid | string | 是 | SIM卡ID|
| remindType | [RemindType](#remindtype) | 是 | 提醒类型 |
| callback | AsyncCallback\<void> | 是   | 回调函数，返回更新结果。 |

**示例：**

```js
let param = {
    netType: Number.parseInt(this.netType), iccid: this.firstParam, remindType: this.currentRemindType
}
policy.updateRemindPolicy(Number.parseInt(this.netType), this.firstParam, Number.parseInt(this.currentRemindType), (err, data) => {
    this.callBack(err, data);
});
```


## policy.updateRemindPolicy

updateRemindPolicy(netType: NetBearType, iccid: string, remindType: RemindType): Promise\<void>;

更新提醒策略，使用Promise方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| netType | [NetBearType](js-apis-net-connection.md#netbeartype) | 是 | 网络类型 |
| iccid | string | 是 | SIM卡ID|
| remindType | [RemindType](#remindtype) | 是 | 提醒类型 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
let param = {
    netType: Number.parseInt(this.netType), iccid: this.firstParam, remindType: this.currentRemindType
}
policy.updateRemindPolicy(Number.parseInt(this.netType), this.firstParam, Number.parseInt(this.currentRemindType)).then((err, data) {
    console.log(JSON.stringify(err))
    console.log(JSON.stringify(data))
})

```

## policy.on

网络策略的句柄。

### on('netUidPolicyChange')

on(type: "netUidPolicyChange", callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void;

注册policy发生改变时的回调，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netUidPolicyChange | 是 | policy发生改变的类型 |
| callback | Callback\<{ uid: number, policy: [NetUidPolicy](#netuidpolicy) }> | 是   | 回调函数。 |

**示例：**

```js
policy.on('netUidPolicyChange', (data) => {
    this.log('on netUidPolicyChange：' + JSON.stringify(data));
})
```

### on('netUidRuleChange')

on(type: "netUidRuleChange", callback: Callback\<{ uid: number, rule: NetUidRule }>): void;

注册rule发生改变时的回调，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netUidRuleChange | 是 | rule发生改变的类型 |
| callback | Callback\<{ uid: number, rule: [NetUidRule](#netuidrule) }> | 是   | 回调函数。 |

**示例：**

```js
policy.on('netUidRuleChange', (data) => {
    this.log('on netUidRuleChange：' + JSON.stringify(data));
})
```

### on('netMeteredIfacesChange')

on(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void;

注册计量iface发生改变时的回调，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netMeteredIfacesChange | 是 | 计量iface发生改变的类型 |
| callback | Callback\<Array\<string>> | 是   | 回调函数。 |

**示例：**

```js
policy.on('netMeteredIfacesChange', (data) => {
    this.log('on netMeteredIfacesChange：' + JSON.stringify(data));
})
```

### on('netQuotaPolicyChange')

on(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void;

注册计量网络策略发生改变时的回调，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netQuotaPolicyChange | 是 | 计量网络策略发生改变的类型 |
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | 是   | 回调函数。 |

**示例：**

```js
policy.on('netQuotaPolicyChange', (data) => {
    this.log('on netQuotaPolicyChange：' + JSON.stringify(data));
})
```

### on('netBackgroundPolicyChange')

on(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void;

注册后台网络策略发生改变时的回调，使用callback方式作为异步方法。

**需要权限**：ohos.permission.CONNECTIVITY_INTERNAL

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | netBackgroundPolicyChange | 是 | 后台网络策略发生改变的类型 |
| callback | Callback\<boolean> | 是   | 回调函数。 |

**示例：**

```js
policy.on('netBackgroundPolicyChange', (data) => {
    this.log('on netBackgroundPolicyChange：' + JSON.stringify(data));
})
```

## NetBackgroundPolicy

后台网络策略。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| NET_BACKGROUND_POLICY_NONE       | 0 | 默认值。 |
| NET_BACKGROUND_POLICY_ENABLE     | 1 | 应用在后台可以使用计量网路。 |
| NET_BACKGROUND_POLICY_DISABLE    | 2 | 应用在后台不可以使用计量网路。 |
| NET_BACKGROUND_POLICY_ALLOW_LIST | 3 | 只有应用指定的列表在后台可以使用计量网络。 |

## NetQuotaPolicy

计量网络策略。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 类型                                | 说明                                                         |
| ----------------------- | ----------------------------------- | ------------------------------------------------------------ |
| netType           | [NetBearType](js-apis-net-connection.md#netbeartype) | 网络类型。 |
| iccid             | string                      | 计量蜂窝网络的SIM卡的标识值。以太网，wifi网络不会用到 |
| ident             | string                      | 计量蜂窝网络中配合iccid联合使用。以太网，wifi网络单独使用。用于标记类型。 |
| periodDuration    | string                      | 计量开始时间。 |
| warningBytes      | number                      | 发出警告的流量阈值。 |
| limitBytes        | number                      | 流量设置的配额。 |
| lastWarningRemind | string                      | 最新一次发出警告的时间。 |
| lastLimitRemind   | string                      | 最新一次配额耗尽的时间。 |
| metered           | string                      | 是否为计量网络。 |
| limitAction       | [LimitAction](#limitaction) | 到达流量限制后的动作。 |

## LimitAction

限制动作。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 值 | 说明   |
| ---------------------- | ----- | ------------ |
| LIMIT_ACTION_NONE     | -1 | 默认值。 |
| LIMIT_ACTION_DISABLE  | 0  | 当配额策略达到限制时，访问被禁用。 |
| LIMIT_ACTION_AUTO_BILL| 1  | 当配额策略达到限制时，用户将自动计费。 |

## NetUidRule

计量网络规则。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 值 | 说明   |
| ---------------------- | ----- | ------------ |
| NET_RULE_NONE                     | 0 | 默认规则 |
| NET_RULE_ALLOW_METERED_FOREGROUND | 1 | 允许前台访问计量网络 |
| NET_RULE_ALLOW_METERED            | 2 | 允许访问计量网络 |
| NET_RULE_REJECT_METERED           | 4 | 拒绝访问计量网络 |
| NET_RULE_ALLOW_ALL                | 32 | 允许访问所有网络 |
| NET_RULE_REJECT_ALL               | 64 | 拒绝访问所有网络 |

## RemindType

提醒类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 值 | 说明   |
| ---------------------- | - | ------- |
| REMIND_TYPE_WARNING    | 1 | 警告提醒 |
| REMIND_TYPE_LIMIT      | 2 | 限制提醒 |

## NetUidPolicy

应用对应的网络策略。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Communication.NetManager.Core。

| 参数名                  | 值 | 说明   |
| ---------------------- | ----- | ------------ |
| NET_POLICY_NONE                       | 0 | 默认网络策略 |
| NET_POLICY_ALLOW_METERED_BACKGROUND   | 1 | 允许应用在后台访问计量网络 |
| NET_POLICY_REJECT_METERED_BACKGROUND  | 2 | 拒绝应用在后台访问计量网络 |
