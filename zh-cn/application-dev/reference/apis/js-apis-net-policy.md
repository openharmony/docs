# @ohos.net.policy (网络策略管理)

网络策略管理通过对用户使用数据流量进行控制管理，采用防火墙技术实现网络策略的管理。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import policy from '@ohos.net.policy'
```

## policy.setBackgroundAllowed<sup>10+</sup>

setBackgroundAllowed(isAllowed: boolean, callback: AsyncCallback\<void>): void

设置是否允许后台应用访问网络，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| isAllowed | boolean | 是   | 是否允许应用后台使用数据 |
| callback | AsyncCallback\<void> | 是   | 回调函数，成功时，err为undefined，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.setBackgroundAllowed(true, (error) => {
  console.log(JSON.stringify(error))
})
;
```

## policy.setBackgroundAllowed<sup>10+</sup>

setBackgroundAllowed(isAllowed: boolean): Promise\<void>

设置是否允许后台应用访问网络，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| isAllowed | boolean | 是   | 是否允许应用后台使用数据 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果，失败返回错误码错误信息。 |

**示例：**

```js
policy.setBackgroundAllowed(true).then(function (error) {
  console.log(JSON.stringify(error))
})
```

## policy.isBackgroundAllowed<sup>10+</sup>

isBackgroundAllowed(callback: AsyncCallback\<boolean>): void

获取当前应用是否允许后台访问网络，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true代表后台策略为允许。失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.isBackgroundAllowed((error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.isBackgroundAllowed<sup>10+</sup>

isBackgroundAllowed(): Promise\<boolean>;

获取当前应用是否允许后台访问网络，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise形式返回设定结果。 返回true代表后台策略为允许。失败返回错误码错误信息。|

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.isBackgroundAllowed().then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.setPolicyByUid<sup>10+</sup>

setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void

设置对应uid应用是否能够访问计量网络的策略，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | app唯一标识符 |
| policy | [NetUidPolicy](#netuidpolicy10) | 是 | 应用对应的策略 |netuidpolicy
| callback | AsyncCallback\<void> | 是   | 回调函数，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uid: Number.parseInt(11111), policy: Number.parseInt(policy.NetUidPolicy.NET_POLICY_NONE)
}
policy.setPolicyByUid(param, (error) => {
   console.log(JSON.stringify(error))
});
```

## policy.setPolicyByUid<sup>10+</sup>

setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>;

设置对应uid应用是否能够访问计量网络的策略，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是   | app唯一标识符 |
| policy | [NetUidPolicy](#netuidpolicy10) | 是 | 应用对应的策略 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uid: Number.parseInt(11111), policy: Number.parseInt(policy.NetUidPolicy.NET_POLICY_NONE)
}
policy.setPolicyByUid(param).then(function (error) {
  console.log(JSON.stringify(error))
})
```

## policy.getPolicyByUid<sup>10+</sup>

getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void

通过应用uid获取对应访问网络策略，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| callback | AsyncCallback\<[NetUidPolicy](#netuidpolicy10)> | 是   | 回调函数，成功返回获取策略结果，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getPolicyByUid(Number.parseInt(11111), (error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.getPolicyByUid<sup>10+</sup>

getPolicyByUid(uid: number): Promise\<NetUidPolicy>;

通过应用uid获取对应访问网络策略，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetUidPolicy](#netuidpolicy10)> | 以Promise形式返回获取策略结果。失败返回错误码错误信息。|

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |                |

**示例：**

```js
policy.getPolicyByUid(Number.parseInt(11111)).then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.getUidsByPolicy<sup>10+</sup>

getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void

通过策略获取跟策略匹配的所有uid，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| policy | [NetUidPolicy](#netuidpolicy10) | 是 | 应用对应的计量网络下的策略 |
| callback | AsyncCallback\<Array\<number>> | 是   | 回调函数，成功返回应用的uid数组，失败返回错误码错误信息。|

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getUidsByPolicy(Number.parseInt(11111), (error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.getUidsByPolicy<sup>10+</sup>

getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>;

通过策略获取跟策略匹配的所有uid，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| policy | [NetUidPolicy](#netuidpolicy10) | 是 | app对应的计量网络下的策略 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<number>> | 以Promise形式返回应用的uid数组，失败返回错误码错误信息。|

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getUidsByPolicy(Number.parseInt(11111)).then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.getNetQuotaPolicies<sup>10+</sup>

getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void

获取计量网络策略，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | 是   | 回调函数，返回获取结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getNetQuotaPolicies((error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.getNetQuotaPolicies<sup>10+</sup>

getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>;

获取计量网络策略，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getNetQuotaPolicies().then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})

```

## policy.setNetQuotaPolicies<sup>10+</sup>

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void

设置计量网络策略，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy10)> | 是 | 计量网络策略 |
| callback | AsyncCallback\<void> | 是   | 回调函数，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
import connection from '@ohos.net.connection';

let netQuotaPolicyList = []

let param = {
  netType: Number.parseInt(connection.NetBearType.BEARER_CELLULAR),
  simId: 1,
  identity: "",
  periodDuration: "M1",
  warningBytes: Number.parseInt(40000),
  limitBytes: Number.parseInt(50000),
  metered: Boolean(Number.parseInt(true)),
  limitAction: policy.LimitAction.LIMIT_ACTION_NONE
};
netQuotaPolicyList.push(param);

policy.setNetQuotaPolicies(netQuotaPolicyList, (error) => {
  console.log(JSON.stringify(error))
});
```

## policy.setNetQuotaPolicies<sup>10+</sup>

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>;

设置计量网络策略，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy10)> | 是 | 计量网络策略 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**示例：**

```js
import connection from '@ohos.net.connection';

let netQuotaPolicyList = []

let param = {
  netType: Number.parseInt(connection.NetBearType.BEARER_CELLULAR),
  simId: 1,
  identity: "",
  periodDuration: "M1",
  warningBytes: Number.parseInt(40000),
  limitBytes: Number.parseInt(50000),
  metered: Boolean(Number.parseInt(true)),
  limitAction: policy.LimitAction.LIMIT_ACTION_NONE
};
netQuotaPolicyList.push(param);

policy.setNetQuotaPolicies(netQuotaPolicyList).then(function (error) {
  console.log(JSON.stringify(error))
})
```

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void

判断对应uid能否访问计量或非计量网络，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| isMetered | boolean | 是 | 是否为计量网络 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true表示这个uid可以访问对应的计量网络。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uid: Number.parseInt(11111), isMetered: true
}
policy.isUidNetAllowed(param, (error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>;

判断对应uid能否访问计量或非计量网络，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

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

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uid: Number.parseInt(11111), isMetered: true
}
policy.isUidNetAllowed(param).then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void

获取对应uid能否访问指定的iface的网络，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| iface | string | 是 | 网络对应的名称 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，返回true表示这个uid可以访问对应iface的网络。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uid: Number.parseInt(11111), iface: 'wlan0'
}
policy.isUidNetAllowed(param, (error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, iface: string): Promise\<boolean>;

获取对应uid能否访问指定的iface的网络，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| iface | string | 是 | 网络对应的名称 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<boolean> | 以Promise形式返回当前uid能否访问对应iface的网络。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uid: Number.parseInt(11111), iface: 'wlan0'
}
policy.isUidNetAllowed(param).then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.setDeviceIdleTrustlist<sup>10+</sup>

setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void

设置多个uid是否在休眠防火墙的白名单，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uids | Array\<number> | 是 | app唯一标识符 |
| isAllowed | boolean | 是 | 是否加入白名单 |
| callback | callback: AsyncCallback\<void> | 是   | 回调函数，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uids: [11111,22222], isAllowed: true
}
policy.setDeviceIdleTrustlist(param, (error) => {
  console.log(JSON.stringify(error))
});
```

## policy.setDeviceIdleTrustlist<sup>10+</sup>

setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>;

设置多个uid是否在休眠防火墙的白名单，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uids | Array\<number> | 是 | app唯一标识符 |
| isAllowed | boolean | 是 | 是否加入白名单 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uids: [11111,22222], isAllowed: true
}
policy.setDeviceIdleTrustlist(param).then(function (error) {
  console.log(JSON.stringify(error))
})
```

## policy.getDeviceIdleTrustlist<sup>10+</sup>

getDeviceIdleTrustlist(callback: AsyncCallback\<Array\<number>>): void

获取休眠模式白名单所包含的uid，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array\<number>> | 是   | 回调函数，返回获取结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getDeviceIdleTrustlist((error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.getDeviceIdleTrustlist<sup>10+</sup>

getDeviceIdleTrustlist(): Promise\<Array\<number>>;

获取休眠模式白名单所包含的uid，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<number>> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |
**示例：**

```js
policy.getDeviceIdleTrustlist().then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.getBackgroundPolicyByUid<sup>10+</sup>

getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void

获取指定uid是否能访问后台网络，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |
| callback | AsyncCallback\<[NetBackgroundPolicy](#netbackgroundpolicy10)> | 是   | 回调函数，返回获取结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getBackgroundPolicyByUid(Number.parseInt(11111), (error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.getBackgroundPolicyByUid<sup>10+</sup>

getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>;

获取指定uid能否访问后台网络，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uid | number | 是 | app唯一标识符 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<[NetBackgroundPolicy](#netbackgroundpolicy10)> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getBackgroundPolicyByUid(Number.parseInt(11111)).then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.resetPolicies<sup>10+</sup>

resetPolicies(simId: string, callback: AsyncCallback\<void>): void

重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| simId | string | 是 | SIM卡ID|
| callback | AsyncCallback\<void> | 是   | 回调函数，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.resetPolicies(1, (error) => {
  console.log(JSON.stringify(error))
});
```

## policy.resetPolicies<sup>10+</sup>

resetPolicies(simId: string): Promise\<void>;

重置对应sim卡id的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| simId | string | 是 | SIM卡ID|

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.resetPolicies(1).then(function (error) {
  console.log(JSON.stringify(error))
})
```

## policy.updateRemindPolicy<sup>10+</sup>

updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType, callback: AsyncCallback\<void>): void

更新提醒策略，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| netType | [NetBearType](js-apis-net-connection.md#netbeartype) | 是 | 网络类型 |
| simId | string | 是 | SIM卡ID|
| remindType | [RemindType](#remindtype10) | 是 | 提醒类型 |
| callback | AsyncCallback\<void> | 是   | 回调函数，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
import connection from '@ohos.net.connection';

let param = {
  netType: Number.parseInt(connection.NetBearType.BEARER_CELLULAR), simId: 1, remindType: policy.NetUidPolicy.NET_POLICY_NONE
}
policy.updateRemindPolicy(param, (error) => {
  console.log(JSON.stringify(error))
});
```

## policy.updateRemindPolicy<sup>10+</sup>

updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType): Promise\<void>;

更新提醒策略，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| netType | [NetBearType](js-apis-net-connection.md#netbeartype) | 是 | 网络类型 |
| simId | string | 是 | SIM卡ID|
| remindType | [RemindType](#remindtype10) | 是 | 提醒类型 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
import connection from '@ohos.net.connection';

let param = {
  netType: Number.parseInt(connection.NetBearType.BEARER_CELLULAR), simId: 1, remindType: policy.NetUidPolicy.NET_POLICY_NONE
}
policy.updateRemindPolicy(param).then(function (error) {
  console.log(JSON.stringify(error))
})
```

## policy.setPowerSaveTrustlist<sup>10+</sup>

setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void

设置指定uid应用是否在省电防火墙的白名单，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uids | Array\<number> | 是 | app唯一标识符 |
| isAllowed | boolean | 是 | 是否加入白名单 |
| callback | callback: AsyncCallback\<void> | 是   | 回调函数，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uids: [11111,22222], isAllowed: true
}
policy.setDeviceIdleTrustlist(param, (error) => {
  console.log(JSON.stringify(error))
});
```

## policy.setPowerSaveTrustlist<sup>10+</sup>

setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>;

设置指定uid应用是否在省电防火墙的白名单，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| uids | Array\<number> | 是 | app唯一标识符 |
| isAllowed | boolean | 是 | 是否加入白名单 |

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<void> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
let param = {
  uids: [11111,22222], isAllowed: true
}
policy.setDeviceIdleTrustlist(param).then(function (error) {
  console.log(JSON.stringify(error))
})
```

## policy.getPowerSaveTrustlist<sup>10+</sup>

getPowerSaveTrustlist(callback: AsyncCallback\<Array\<number>>): void

获取省电模式白名单所包含的uid数组，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                    | 必填 | 说明       |
| -------- | --------------------------------------- | ---- | ---------- |
| callback | AsyncCallback\<Array\<number>> | 是   | 回调函数，返回获取结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getPowerSaveTrustlist((error, data) => {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
});
```

## policy.getPowerSaveTrustlist<sup>10+</sup>

getPowerSaveTrustlist(): Promise\<Array\<number>>;

获取休眠模式白名单所包含的uid数组，使用Promise方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                              | 说明                                  |
| --------------------------------- | ------------------------------------- |
| Promise\<Array\<number>> | 以Promise形式返回设定结果。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.                  |

**示例：**

```js
policy.getPowerSaveTrustlist().then(function (error, data) {
  console.log(JSON.stringify(error))
  console.log(JSON.stringify(data))
})
```

## policy.on

网络策略的句柄。

### on('netUidPolicyChange')<sup>10+</sup>

on(type: "netUidPolicyChange", callback: Callback\<{ uid: number, policy: NetUidPolicy }>): void

注册policy发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | policy发生改变的类型 |
| callback | Callback\<{ uid: number, policy: [NetUidPolicy](#netuidpolicy10) }> | 是   | 回调函数。注册policy发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.on('netUidPolicyChange', (data) => {
  console.log('on netUidPolicyChange: ' + JSON.stringify(data));
})
```

### off('netUidPolicyChange')<sup>10+</sup>

off(type: "netUidPolicyChange", callback?: Callback<{ uid: number, policy: NetUidPolicy }>): void

注销policy发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | policy发生改变的类型 |
| callback | Callback\<{ uid: number, policy: [NetUidPolicy](#netuidpolicy10) }> | 否   | 回调函数。注册policy发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.off('netUidPolicyChange', (data) => {
  console.log('off netUidPolicyChange: ' + JSON.stringify(data));
})
```

### on('netUidRuleChange')<sup>10+</sup>

on(type: "netUidRuleChange", callback: Callback\<{ uid: number, rule: NetUidRule }>): void

注册rule发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | rule发生改变的类型 |
| callback | Callback\<{ uid: number, rule: [NetUidRule](#netuidrule10) }> | 是   | 回调函数。注册rule发生改变时的调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.on('netUidRuleChange', (data) => {
  console.log('on netUidRuleChange: ' + JSON.stringify(data));
})
```

### off('netUidRuleChange')<sup>10+</sup>

off(type: "netUidRuleChange", callback?: Callback<{ uid: number, rule: NetUidRule }>): void

注销rule发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | rule发生改变的类型 |
| callback | Callback\<{ uid: number, rule: [NetUidRule](#netuidrule10) }> | 否   | 回调函数。注册rule发生改变时的调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.off('netUidRuleChange', (data) => {
  console.log('off netUidRuleChange: ' + JSON.stringify(data));
})
```

### on('netMeteredIfacesChange')<sup>10+</sup>

on(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void

注册计量iface发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | 计量iface发生改变的类型 |
| callback | Callback\<Array\<string>> | 是   | 回调函数。注册计量iface发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.on('netMeteredIfacesChange', (data) => {
  console.log('on netMeteredIfacesChange: ' + JSON.stringify(data));
})
```

### off('netMeteredIfacesChange')<sup>10+</sup>

off(type: "netMeteredIfacesChange", callback?: Callback\<Array\<string>>): void

注销计量iface发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | 计量iface发生改变的类型 |
| callback | Callback\<Array\<string>> | 否   | 回调函数。注册计量iface发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.off('netMeteredIfacesChange', (data) => {
  console.log('off netMeteredIfacesChange: ' + JSON.stringify(data));
})
```

### on('netQuotaPolicyChange')<sup>10+</sup>

on(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void

注册计量网络策略发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | 计量网络策略发生改变的类型 |
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | 是   | 回调函数。注册计量网络策略发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.on('netQuotaPolicyChange', (data) => {
  console.log('on netQuotaPolicyChange: ' + JSON.stringify(data));
})
```

### off('netQuotaPolicyChange')<sup>10+</sup>

off(type: "netQuotaPolicyChange", callback?: Callback\<Array\<NetQuotaPolicy>>): void

注销计量网络策略发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | 计量网络策略发生改变的类型 |
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | 否   | 回调函数。注册计量网络策略发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.off('netQuotaPolicyChange', (data) => {
  console.log('off netQuotaPolicyChange: ' + JSON.stringify(data));
})
```

### on('netBackgroundPolicyChange')<sup>10+</sup>

on(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void

注册后台网络策略发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | 后台网络策略发生改变的类型 |
| callback | Callback\<boolean> | 是   | 回调函数。注册后台网络策略发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.on('netBackgroundPolicyChange', (data) => {
  console.log('on netBackgroundPolicyChange: ' + JSON.stringify(data));
})
```

### off('netBackgroundPolicyChange')<sup>10+</sup>

off(type: "netBackgroundPolicyChange", callback?: Callback\<boolean>): void

注销后台网络策略发生改变时的回调，使用callback方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                               | 必填 | 说明                                                         |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| type | string | 是 | 后台网络策略发生改变的类型 |
| callback | Callback\<boolean> | 否   | 回调函数。注册后台网络策略发生改变时调用。 |

**错误码：**

| 错误码ID | 错误信息                                      |
| ------- | -------------------------------------------- |
| 201     | Permission denied.                           |
| 202     | Non-system applications use system APIs.     |
| 401     | Parameter error.                             |
| 2100001 | Invalid parameter value.                     |
| 2100002 | Operation failed. Cannot connect to service.|
| 2100003 | System internal error.        

**示例：**

```js
policy.off('netBackgroundPolicyChange', (data) => {
  console.log('off netBackgroundPolicyChange: ' + JSON.stringify(data));
})
```

## NetBackgroundPolicy<sup>10+</sup>

后台网络策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 值   | 说明                   |
| ------------------------ | ---- | ---------------------- |
| NET_BACKGROUND_POLICY_NONE       | 0 | 默认值。 |
| NET_BACKGROUND_POLICY_ENABLE     | 1 | 应用在后台可以使用计量网路。 |
| NET_BACKGROUND_POLICY_DISABLE    | 2 | 应用在后台不可以使用计量网路。 |
| NET_BACKGROUND_POLICY_TRUSTLIST | 3 | 只有应用指定的列表在后台可以使用计量网络。 |

## NetQuotaPolicy<sup>10+</sup>

计量网络策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 类型                                |必填| 说明                                                         |
| ----------------------- | ----------------------------------- |------| -------------------------------------------------------  |
| networkMatchRule             | [NetworkMatchRule](#networkmatchrule10)               |是| 网络标识，用来确定设置哪一个网络
| quotaPolicy             | [QuotaPolicy](#quotapolicy10)                      |是| 具体的计量网络策略

## NetworkMatchRule<sup>10+</sup>

网络标识，用来确定设置哪一个网络

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 类型                                |必填| 说明                                                         |
| ----------------------- | ----------------------------------- |-----| ------------------------------------------------------------ |
| netType           | [NetBearType](js-apis-net-connection.md#netbeartype) |是| 网络类型。 |
| simId             | string                      |是| 计量蜂窝网络的SIM卡的标识值。以太网，wifi网络不会用到 |
| identity             | string                      |是| 计量蜂窝网络中配合simId联合使用。以太网，wifi网络单独使用。用于标记类型。 |

## QuotaPolicy<sup>10+</sup>

计量网络策略

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 类型                                |必填| 说明                                                         |
| ----------------------- | ----------------------------------- |----| ------------------------------------------------------------ |
| periodDuration    | string                      |是| 计量开始时间。 |
| warningBytes      | number                      |是| 发出警告的流量阈值。 |
| limitBytes        | number                      |是| 流量设置的配额。 |
| metered           | string                      |是| 是否为计量网络。 |
| limitAction       | [LimitAction](#limitaction10) |是| 到达流量限制后的动作。 |
| lastWarningRemind | string                      |否| 最新一次发出警告的时间。 |
| lastLimitRemind   | string                      |否| 最新一次配额耗尽的时间。 |

## LimitAction<sup>10+</sup>

限制动作。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 值 | 说明   |
| ---------------------- | ----- | ------------ |
| LIMIT_ACTION_NONE     | -1 | 默认值。 |
| LIMIT_ACTION_ACCESS_DISABLED  | 0  | 当配额策略达到限制时，访问被禁用。 |
| LIMIT_ACTION_ALERT_ONLY| 1  | 当配额策略达到限制时，将警告用户。 |

## NetUidRule<sup>10+</sup>

计量网络规则。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                 | 值 | 说明   |
| ---------------------- | ----- | ------------ |
| NET_RULE_NONE                     | 0 | 默认规则 |
| NET_RULE_ALLOW_METERED_FOREGROUND | 1 << 0 | 允许前台访问计量网络 |
| NET_RULE_ALLOW_METERED            | 1 << 1 | 允许访问计量网络 |
| NET_RULE_REJECT_METERED           | 1 << 2 | 拒绝访问计量网络 |
| NET_RULE_ALLOW_ALL                | 1 << 5 | 允许访问所有网络 |
| NET_RULE_REJECT_ALL               | 1 << 6 | 拒绝访问所有网络 |

## RemindType<sup>10+</sup>

提醒类型。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称 | 值 | 说明 |
| ---------------------- | - | ------- |
| REMIND_TYPE_WARNING | 1 | 警告提醒 |
| REMIND_TYPE_LIMIT   | 2 | 限制提醒 |

## NetUidPolicy<sup>10+</sup>

应用对应的网络策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                  | 值 | 说明   |
| ---------------------- | ----- | ------------ |
| NET_POLICY_NONE                       | 0 | 默认网络策略 |
| NET_POLICY_ALLOW_METERED_BACKGROUND   | 1 << 0 | 允许应用在后台访问计量网络 |
| NET_POLICY_REJECT_METERED_BACKGROUND  | 1 << 1 | 拒绝应用在后台访问计量网络 |
