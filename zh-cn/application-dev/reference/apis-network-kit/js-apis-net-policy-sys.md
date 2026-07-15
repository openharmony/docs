# @ohos.net.policy (网络策略管理)（系统接口）

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

网络策略管理通过对用户使用数据流量进行控制管理，采用防火墙技术实现网络策略的管理。

> **说明：**
>
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。

## 导入模块

```ts
import { policy } from '@kit.NetworkKit';
```

## policy.setBackgroundAllowed

setBackgroundAllowed(isAllowed: boolean, callback: AsyncCallback\<void>): void

设置是否允许后台应用访问网络，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                 | 必填 | 说明                                                         |
| --------- | -------------------- | ---- | ------------------------------------------------------------ |
| isAllowed | boolean              | 是   | 是否允许应用后台使用数据。true：允许应用后台使用数据；false：不允许应用后台使用数据。                                     |
| callback  | AsyncCallback\<void> | 是   | 回调函数，成功时，err 为 undefined，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setBackgroundAllowed(true, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setBackgroundAllowed

setBackgroundAllowed(isAllowed: boolean): Promise\<void>

设置是否允许后台应用访问网络，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型    | 必填 | 说明                     |
| --------- | ------- | ---- | ------------------------ |
| isAllowed | boolean | 是   | 是否允许应用后台使用数据。true：允许应用后台使用数据；false：不允许应用后台使用数据。 |

**返回值：**

| 类型           | 说明                                                              |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setBackgroundAllowed(true).then(() => {
  console.info("setBackgroundAllowed success");
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.isBackgroundAllowed

isBackgroundAllowed(callback: AsyncCallback\<boolean>): void

获取当前应用是否允许后台访问网络，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                             |
| -------- | ----------------------- | ---- | ---------------------------------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回 true 代表后台策略为允许，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.isBackgroundAllowed((error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
 console.info(JSON.stringify(data));
});
```

## policy.isBackgroundAllowed

isBackgroundAllowed(): Promise\<boolean>

获取当前应用是否允许后台访问网络，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型              | 说明                                                                                 |
| ----------------- | ------------------------------------------------------------------------------------ |
| Promise\<boolean> |  Promise 对象。 返回 true 表示后台策略为允许，返回false表示后台策略不允许。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .isBackgroundAllowed()
  .then((data: boolean) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.setPolicyByUid

setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void

设置对应 uid 应用是否能够访问计量网络的策略，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                           |
| -------- | ------------------------------- | ---- | ---------------------------------------------- |
| uid      | number                          | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。                                |
| policy   | [NetUidPolicy](#netuidpolicy) | 是   | 应用对应的策略。                                 |
| callback | AsyncCallback\<void>            | 是   | 回调函数，成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setPolicyByUid(11111, policy.NetUidPolicy.NET_POLICY_NONE, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setPolicyByUid

setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>

设置对应 uid 应用是否能够访问计量网络的策略，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明           |
| ------ | ------------------------------- | ---- | -------------- |
| uid    | number                          | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。 |
| policy | [NetUidPolicy](#netuidpolicy) | 是   | 应用对应的策略。 |

**返回值：**

| 类型           | 说明                                                              |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .setPolicyByUid(11111, policy.NetUidPolicy.NET_POLICY_NONE)
  .then(() => {
    console.info('setPolicyByUid success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getPolicyByUid

getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void

通过应用 uid 获取对应访问网络策略，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                     |
| -------- | ----------------------------------------------- | ---- | -------------------------------------------------------- |
| uid      | number                                          | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。                                           |
| callback | AsyncCallback\<[NetUidPolicy](#netuidpolicy)> | 是   | 回调函数。成功返回获取策略结果，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getPolicyByUid(11111, (error: BusinessError, data: policy.NetUidPolicy) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getPolicyByUid

getPolicyByUid(uid: number): Promise\<NetUidPolicy>

通过应用 uid 获取对应访问网络策略，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| uid    | number | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。 |

**返回值：**

| 类型                                      | 说明                                                      |
| ----------------------------------------- | --------------------------------------------------------- |
| Promise\<[NetUidPolicy](#netuidpolicy)> | 以 Promise 形式返回获取策略结果。失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getPolicyByUid(11111)
  .then((data: policy.NetUidPolicy) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getUidsByPolicy

getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void

通过策略获取跟策略匹配的所有 uid，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                            | 必填 | 说明                                                        |
| -------- | ------------------------------- | ---- | ----------------------------------------------------------- |
| policy   | [NetUidPolicy](#netuidpolicy) | 是   | 应用对应的计量网络下的策略。                                  |
| callback | AsyncCallback\<Array\<number>>  | 是   | 回调函数。成功返回应用的 uid 数组，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getUidsByPolicy(11111, (error: BusinessError, data: number[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getUidsByPolicy

getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>

通过策略获取跟策略匹配的所有 uid，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明                       |
| ------ | ------------------------------- | ---- | -------------------------- |
| policy | [NetUidPolicy](#netuidpolicy) | 是   | app 对应的计量网络下的策略。 |

**返回值：**

| 类型                     | 说明                                                         |
| ------------------------ | ------------------------------------------------------------ |
| Promise\<Array\<number>> | 以 Promise 形式返回应用的 uid 数组，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getUidsByPolicy(11111)
  .then((data: object) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getNetQuotaPolicies

getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void

获取计量网络策略，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                     |
| -------- | ----------------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | 是   | 回调函数。返回获取结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getNetQuotaPolicies((error: BusinessError, data: policy.NetQuotaPolicy[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getNetQuotaPolicies

getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>

获取计量网络策略，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                                                  | 说明                          |
| ----------------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | 以 Promise 形式返回设定结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getNetQuotaPolicies()
  .then((data: policy.NetQuotaPolicy[]) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.setNetQuotaPolicies

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void

设置计量网络策略，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名        | 类型                                        | 必填 | 说明                                           |
| ------------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy)> | 是   | 计量网络策略。                                   |
| callback      | AsyncCallback\<void>                        | 是   | 回调函数。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netQuotaPolicyList: Array<policy.NetQuotaPolicy> = [];
let netQuotaPolicy: policy.NetQuotaPolicy = {
  networkMatchRule: {
    netType: connection.NetBearType.BEARER_CELLULAR,
    identity: '',
    simId: '1'
  },
  quotaPolicy: {
    periodDuration: 'M1',
    warningBytes: 40000,
    limitBytes: 50000,
    metered: true,
    limitAction: policy.LimitAction.LIMIT_ACTION_NONE
  }
}
netQuotaPolicyList.push(netQuotaPolicy);

policy.setNetQuotaPolicies(netQuotaPolicyList, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setNetQuotaPolicies

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>

设置计量网络策略，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名        | 类型                                        | 必填 | 说明         |
| ------------- | ------------------------------------------- | ---- | ------------ |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy)> | 是   | 计量网络策略。 |

**返回值：**

| 类型           | 说明                                                              |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netQuotaPolicyList: Array<policy.NetQuotaPolicy> = [];
let netQuotaPolicy: policy.NetQuotaPolicy = {
  networkMatchRule: {
    netType: connection.NetBearType.BEARER_CELLULAR,
    identity: '',
    simId: '1'
  },
  quotaPolicy: {
    periodDuration: 'M1',
    warningBytes: 40000,
    limitBytes: 50000,
    metered: true,
    limitAction: policy.LimitAction.LIMIT_ACTION_NONE
  }
}
netQuotaPolicyList.push(netQuotaPolicy);

policy
  .setNetQuotaPolicies(netQuotaPolicyList)
  .then(() => {
    console.info('setNetQuotaPolicies success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void

判断对应 uid 能否访问计量或非计量网络，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                      |
| --------- | ----------------------- | ---- | --------------------------------------------------------- |
| uid       | number                  | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。                                           |
| isMetered | boolean                 | 是   | 是否为计量网络。true：是计量网络；false：不是计量网络。                                            |
| callback  | AsyncCallback\<boolean> | 是   | 回调函数。返回 true 表示这个 uid 可以访问对应的计量网络。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.isUidNetAllowed(11111, true, (error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>

判断对应 uid 能否访问计量或非计量网络，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型    | 必填 | 说明           |
| --------- | ------- | ---- | -------------- |
| uid       | number  | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。 |
| isMetered | boolean | 是   | 是否为计量网络。true：是计量网络；false：不是计量网络。 |

**返回值：**

| 类型              | 说明                          |
| ----------------- | ----------------------------- |
| Promise\<boolean> | Promise 对象。 返回 true 表示这个uid可以访问计量或非计量网络，返回false表示这个uid不可以访问计量或非计量网络。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .isUidNetAllowed(11111, true)
  .then((data: boolean) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void

获取对应 uid 能否访问指定的 iface 的网络，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                  | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。                                               |
| iface    | string                  | 是   | 网络对应的名称。                                              |
| callback | AsyncCallback\<boolean> | 是   | 回调函数。返回 true 表示这个 uid 可以访问对应 iface 的网络。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.isUidNetAllowed(11111, 'wlan0', (error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.isUidNetAllowed

isUidNetAllowed(uid: number, iface: string): Promise\<boolean>

获取对应 uid 能否访问指定的 iface 的网络，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| uid    | number | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。 |
| iface  | string | 是   | 网络对应的名称。 |

**返回值：**

| 类型              | 说明                                                    |
| ----------------- | ------------------------------------------------------- |
| Promise\<boolean> | Promise 对象。 返回 true 表示对应 uid 能访问指定的 iface 的网络，返回false则表示不能访问。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .isUidNetAllowed(11111, 'wlan0')
  .then((data: boolean) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.setDeviceIdleTrustlist

setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void

设置多个 uid 是否在休眠防火墙的白名单，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                           | 必填 | 说明                                           |
| --------- | ------------------------------ | ---- | ---------------------------------------------- |
| uids      | Array\<number>                 | 是   | app 唯一标识符。                                 |
| isAllowed | boolean                        | 是   | 是否加入白名单。true：加入白名单；false：没有加入白名单。                                 |
| callback  | AsyncCallback\<void> | 是   | 回调函数。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setDeviceIdleTrustlist([11111, 22222], true, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setDeviceIdleTrustlist

setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>

设置多个 uid 是否在休眠防火墙的白名单，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型           | 必填 | 说明           |
| --------- | -------------- | ---- | -------------- |
| uids      | Array\<number> | 是   | app 唯一标识符。 |
| isAllowed | boolean        | 是   | 是否加入白名单。true：加入白名单；false：没有加入白名单。 |

**返回值：**

| 类型           | 说明                                                              |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .setDeviceIdleTrustlist([11111, 22222], true)
  .then(() => {
    console.info('setDeviceIdleTrustlist success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getDeviceIdleTrustlist

getDeviceIdleTrustlist(callback: AsyncCallback\<Array\<number>>): void

获取休眠模式白名单所包含的 uid，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                           | 必填 | 说明                     |
| -------- | ------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<Array\<number>> | 是   | 回调函数。返回获取结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getDeviceIdleTrustlist((error: BusinessError, data: number[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getDeviceIdleTrustlist

getDeviceIdleTrustlist(): Promise\<Array\<number>>

获取休眠模式白名单所包含的 uid，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                     | 说明                          |
| ------------------------ | ----------------------------- |
| Promise\<Array\<number>> | 以 Promise 形式返回设定结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getDeviceIdleTrustlist()
  .then((data: number[]) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getBackgroundPolicyByUid

getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void

获取指定 uid 是否能访问后台网络，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                          | 必填 | 说明                     |
| -------- | ------------------------------------------------------------- | ---- | ------------------------ |
| uid      | number                                                        | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。           |
| callback | AsyncCallback\<[NetBackgroundPolicy](#netbackgroundpolicy)> | 是   | 回调函数。返回获取结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getBackgroundPolicyByUid(11111, (error: BusinessError, data: policy.NetBackgroundPolicy) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getBackgroundPolicyByUid

getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>

获取指定 uid 能否访问后台网络，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| uid    | number | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。 |

**返回值：**

| 类型                                                    | 说明                          |
| ------------------------------------------------------- | ----------------------------- |
| Promise\<[NetBackgroundPolicy](#netbackgroundpolicy)> | 以 Promise 形式返回设定结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getBackgroundPolicyByUid(11111)
  .then((data: policy.NetBackgroundPolicy) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.resetPolicies

resetPolicies(simId: string, callback: AsyncCallback\<void>): void

重置对应 sim 卡 id 的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | ---------------------------------------------- |
| simId    | string               | 是   | SIM 卡 ID。                                      |
| callback | AsyncCallback\<void> | 是   | 回调函数。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.resetPolicies('1', (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.resetPolicies

resetPolicies(simId: string): Promise\<void>

重置对应 sim 卡 id 的蜂窝网络、后台网络策略、防火墙策略、应用对应的策略，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| simId  | string | 是   | SIM 卡 ID。 |

**返回值：**

| 类型           | 说明                                                              |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .resetPolicies('1')
  .then(() => {
    console.info('resetPolicies success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.updateRemindPolicy

updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType, callback: AsyncCallback\<void>): void

更新提醒策略，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明                                           |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| netType    | [NetBearType](js-apis-net-connection.md#netbeartype) | 是   | 网络类型。                                       |
| simId      | string                                               | 是   | SIM 卡 ID。                                      |
| remindType | [RemindType](#remindtype)                          | 是   | 提醒类型。                                       |
| callback   | AsyncCallback\<void>                                 | 是   | 回调函数。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

policy.updateRemindPolicy(
  connection.NetBearType.BEARER_CELLULAR,
  '1',
  policy.RemindType.REMIND_TYPE_WARNING,
  (error: BusinessError) => {
    console.error(JSON.stringify(error));
  }
);
```

## policy.updateRemindPolicy

updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType): Promise\<void>

更新提醒策略，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名     | 类型                                                 | 必填 | 说明      |
| ---------- | ---------------------------------------------------- | ---- | --------- |
| netType    | [NetBearType](js-apis-net-connection.md#netbeartype) | 是   | 网络类型。  |
| simId      | string                                               | 是   | SIM 卡 ID。 |
| remindType | [RemindType](#remindtype)                          | 是   | 提醒类型。  |

**返回值：**

| 类型           | 说明                                                              |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .updateRemindPolicy(
    connection.NetBearType.BEARER_CELLULAR,
    '1',
    policy.RemindType.REMIND_TYPE_WARNING
  )
  .then(() => {
    console.info('updateRemindPolicy success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.setPowerSaveTrustlist

setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void

设置指定 uid 应用是否在省电防火墙的白名单，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                           | 必填 | 说明                                           |
| --------- | ------------------------------ | ---- | ---------------------------------------------- |
| uids      | Array\<number>                 | 是   | app 唯一标识符。                                |
| isAllowed | boolean                        | 是   | 是否加入白名单。true：加入白名单；false：没有加入白名单。                                 |
| callback  | AsyncCallback\<void> | 是   | 回调函数。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setPowerSaveTrustlist([11111, 22222], true, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setPowerSaveTrustlist

setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>

设置指定 uid 应用是否在省电防火墙的白名单，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型           | 必填 | 说明           |
| --------- | -------------- | ---- | -------------- |
| uids      | Array\<number> | 是   | app 唯一标识符。 |
| isAllowed | boolean        | 是   | 是否加入白名单。true：加入白名单；false：没有加入白名单。 |

**返回值：**

| 类型           | 说明                                                              |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .setPowerSaveTrustlist([11111, 22222], true)
  .then(() => {
    console.info('setPowerSaveTrustlist success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getPowerSaveTrustlist

getPowerSaveTrustlist(callback: AsyncCallback\<Array\<number>>): void

获取省电模式白名单所包含的 uid 数组，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                           | 必填 | 说明                     |
| -------- | ------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<Array\<number>> | 是   | 回调函数。返回获取结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getPowerSaveTrustlist((error: BusinessError, data: number[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getPowerSaveTrustlist

getPowerSaveTrustlist(): Promise\<Array\<number>>

获取休眠模式白名单所包含的 uid 数组，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                     | 说明                          |
| ------------------------ | ----------------------------- |
| Promise\<Array\<number>> | 以 Promise 形式返回设定结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getPowerSaveTrustlist()
  .then((data: number[]) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.setNetworkAccessPolicy<sup>12+</sup>

setNetworkAccessPolicy(uid: number, policy: NetworkAccessPolicy, isReconfirmed?: boolean): Promise\<void>

设置指定uid应用能否访问网络的策略，使用Promise异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名         | 类型                                           | 必填 | 说明                                                                          |
| ------------- | ---------------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| uid           | number                                         | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。                                                                |
| policy        | [NetworkAccessPolicy](#networkaccesspolicy12)  | 是   | 网络策略。                                                                      |
| isReconfirmed | boolean                                        | 否   | 默认false；false 表示需要重确认，应用访问网络会弹框; true 表示不需要重确认，无弹框。 |

**返回值：**

| 类型           | 说明                                                          |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | 以 Promise 形式返回设定结果。成功返回空，失败返回错误码错误信息。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let accessPolicy: policy.NetworkAccessPolicy = {
  allowWiFi: false,
  allowCellular: true,
}
policy
  .setNetworkAccessPolicy(11111, accessPolicy)
  .then(() => {
    console.info('setNetworkAccessPolicy success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getNetworkAccessPolicy<sup>12+</sup>

getNetworkAccessPolicy(uid: number): Promise\<NetworkAccessPolicy>

获取指定 uid 能否访问网络策略，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| uid    | number | 是   | app 唯一标识符，取值范围为int32_t范围内的正整数。 |

**返回值：**

| 类型                                                    | 说明                          |
| ------------------------------------------------------- | ----------------------------- |
| Promise\<[NetworkAccessPolicy](#networkaccesspolicy12)> | 以 Promise 形式返回设定结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getNetworkAccessPolicy(11111)
  .then((data: policy.NetworkAccessPolicy) => {
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.getNetworkAccessPolicy<sup>12+</sup>

getNetworkAccessPolicy(): Promise\<UidNetworkAccessPolicy>

获取当前用户下所有应用 app 能否访问网络策略信息，使用 Promise 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**

| 类型                                                          | 说明                        |
| ------------------------------------------------------------- | --------------------------- |
| Promise\<[UidNetworkAccessPolicy](#uidnetworkaccesspolicy12)> | 以 Promise 形式返回设定结果。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy
  .getNetworkAccessPolicy()
  .then((data: policy.UidNetworkAccessPolicy) => {
    let keyMap: Map<string, object> = new Map<string, object>(Object.entries(data));
    let uid:number = 0;
    let allowWiFi: string = "";
    let allowCellular: string = "";

    keyMap.forEach((value:object, key:string) => {
      let valueMap: Map<string, string> = new Map<string, string>(Object.entries(value));
      uid = Number.parseInt(key);
      valueMap.forEach((value:string, key:string)=>{
        if (key == "allowWiFi") {
          allowWiFi = value;
        }
        if (key == "allowCellular") {
          allowCellular = value;
        }
      })
    })
    console.info(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.on

网络策略的句柄。

### on('netUidPolicyChange')

on(type: "netUidPolicyChange", callback: Callback\<NetUidPolicyInfo\>): void

注册 policy 发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                                | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                              | 是   | 订阅的事件类型。'netUidPolicyChange'：注册policy发生改变事件。                  |
| callback | Callback\<[NetUidPolicyInfo](#netuidpolicyinfo11)> | 是   | 回调函数。注册 policy 发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

interface Data {
  uid: number,
  policy: policy.NetUidPolicy
}

try {
  policy.on('netUidPolicyChange', (data: Data) => {
    console.info('on netUidPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netUidPolicyChange error: ' + JSON.stringify(err));
}
```

### off('netUidPolicyChange')

off(type: "netUidPolicyChange", callback?: Callback\<NetUidPolicyInfo\>): void

注销 policy 发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                                | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                              | 是   | 注销的事件类型。'netUidPolicyChange'：注销policy发生改变事件。               |
| callback | Callback\<[NetUidPolicyInfo](#netuidpolicyinfo11)> | 否   | 回调函数。注销 policy 发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

interface Data {
  uid: number,
  policy: policy.NetUidPolicy
}

try {
  policy.on('netUidPolicyChange', (data: Data) => {
    console.info('on netUidPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netUidPolicyChange error: ' + JSON.stringify(err));
}

try {
  policy.off('netUidPolicyChange', (data: Data) => {
    console.info('off netUidPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('off netUidPolicyChange error: ' + JSON.stringify(err));
}
```

### on('netUidRuleChange')

on(type: "netUidRuleChange", callback: Callback\<NetUidRuleInfo\>): void

注册 rule 发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                          | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                        | 是   | 订阅的事件类型。'netUidRuleChange'：注册rule发生改变事件。                    |
| callback | Callback\<[NetUidRuleInfo](#netuidruleinfo11)> | 是   | 回调函数。注册 rule 发生改变时的调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

interface Data {
  uid: number,
  rule: policy.NetUidRule
}

try {
  policy.on('netUidRuleChange', (data: Data) => {
    console.info('on netUidRuleChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netUidRuleChange error: ' + JSON.stringify(err));
}
```

### off('netUidRuleChange')

off(type: "netUidRuleChange", callback?: Callback\<NetUidRuleInfo\>): void

注销 rule 发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                          | 必填 | 说明                                   |
| -------- | ------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                        | 是   | 注销的事件类型。'netUidRuleChange'：注销rule发生改变事件。                    |
| callback | Callback\<[NetUidRuleInfo](#netuidruleinfo11)> | 否   | 回调函数。注销 rule 发生改变时的调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

interface Data {
  uid: number,
  rule: policy.NetUidRule
}

try {
  policy.on('netUidRuleChange', (data: Data) => {
    console.info('on netUidRuleChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netUidRuleChange error: ' + JSON.stringify(err));
}

try {
  policy.off('netUidRuleChange', (data: Data) => {
    console.info('off netUidRuleChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('off netUidRuleChange error: ' + JSON.stringify(err));
}
```

### on('netMeteredIfacesChange')

on(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void

注册计量 iface 发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                      |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| type     | string                    | 是   | 订阅的事件类型。'netMeteredIfacesChange'：注册计量iface发生改变事件。                 |
| callback | Callback\<Array\<string>> | 是   | 回调函数。注册计量 iface 发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

try {
  policy.on('netMeteredIfacesChange', (data: string[]) => {
    console.info('on netMeteredIfacesChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netMeteredIfacesChange error: ' + JSON.stringify(err));
}
```

### off('netMeteredIfacesChange')

off(type: "netMeteredIfacesChange", callback?: Callback\<Array\<string>>): void

注销计量 iface 发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                      |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| type     | string                    | 是   | 注销的事件类型。'netMeteredIfacesChange'：注销计量iface发生改变事件。                 |
| callback | Callback\<Array\<string>> | 否   | 回调函数。注册计量 iface 发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

try {
  policy.on('netMeteredIfacesChange', (data: string[]) => {
    console.info('on netMeteredIfacesChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netMeteredIfacesChange error: ' + JSON.stringify(err));
}

try {
  policy.off('netMeteredIfacesChange', (data: string[]) => {
    console.info('off netMeteredIfacesChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('off netMeteredIfacesChange error: ' + JSON.stringify(err));
}
```

### on('netQuotaPolicyChange')

on(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void

注册计量网络策略发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                                       |
| -------- | ------------------------------------------------------ | ---- | ------------------------------------------ |
| type     | string                                                 | 是   | 订阅的事件类型。'netQuotaPolicyChange'：注册计量网络策略发生改变事件。                 |
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | 是   | 回调函数。注册计量网络策略发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

interface Data {
  uid: number,
  policy: policy.NetUidPolicy
}

try {
  policy.on('netQuotaPolicyChange', (data: policy.NetQuotaPolicy[]) => {
    console.info('on netQuotaPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netQuotaPolicyChange error: ' + JSON.stringify(err));
}
```

### off('netQuotaPolicyChange')

off(type: "netQuotaPolicyChange", callback?: Callback\<Array\<NetQuotaPolicy>>): void

注销计量网络策略发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                                   | 必填 | 说明                                       |
| -------- | ------------------------------------------------------ | ---- | ------------------------------------------ |
| type     | string                                                 | 是   | 注销的事件类型。'netQuotaPolicyChange'：注销计量网络策略发生改变事件。                 |
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy)>> | 否   | 回调函数。注册计量网络策略发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

try {
  policy.on('netQuotaPolicyChange', (data: Array<policy.NetQuotaPolicy>) => {
    console.info('on netQuotaPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netQuotaPolicyChange error: ' + JSON.stringify(err));
}

try {
  policy.off('netQuotaPolicyChange', (data: Array<policy.NetQuotaPolicy>) => {
    console.info('off netQuotaPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('off netQuotaPolicyChange error: ' + JSON.stringify(err));
}
```

### on('netBackgroundPolicyChange')

on(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void

注册后台网络策略发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型               | 必填 | 说明                                       |
| -------- | ------------------ | ---- | ------------------------------------------ |
| type     | string             | 是   | 订阅的事件类型。'netBackgroundPolicyChange'：注册后台网络策略发生改变事件。                 |
| callback | Callback\<boolean> | 是   | 回调函数。注册后台网络策略发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

try {
  policy.on('netBackgroundPolicyChange', (data: boolean) => {
    console.info('on netBackgroundPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netBackgroundPolicyChange error: ' + JSON.stringify(err));
}
```

### off('netBackgroundPolicyChange')

off(type: "netBackgroundPolicyChange", callback?: Callback\<boolean>): void

注销后台网络策略发生改变时的回调，使用 callback 异步回调。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.MANAGE_NET_STRATEGY

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型               | 必填 | 说明                                       |
| -------- | ------------------ | ---- | ------------------------------------------ |
| type     | string             | 是   | 注销的事件类型。'netBackgroundPolicyChange'：注销后台网络策略发生改变事件。                 |
| callback | Callback\<boolean> | 否   | 回调函数。注册后台网络策略发生改变时调用。 |

**错误码：**

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```ts
import { policy } from '@kit.NetworkKit';

try {
  policy.on('netBackgroundPolicyChange', (data: boolean) => {
    console.info('on netBackgroundPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('on netBackgroundPolicyChange error: ' + JSON.stringify(err));
}

try {
  policy.off('netBackgroundPolicyChange', (data: boolean) => {
    console.info('off netBackgroundPolicyChange data: ' + JSON.stringify(data));
  });
} catch(err) {
  console.error('off netBackgroundPolicyChange error: ' + JSON.stringify(err));
}
```

## NetBackgroundPolicy

后台网络策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                            | 值  | 说明                                       |
| ------------------------------- | --- | ------------------------------------------ |
| NET_BACKGROUND_POLICY_NONE      | 0   | 默认值。                                   |
| NET_BACKGROUND_POLICY_ENABLE    | 1   | 应用在后台可以使用计量网络。               |
| NET_BACKGROUND_POLICY_DISABLE   | 2   | 应用在后台不可以使用计量网络。             |
| NET_BACKGROUND_POLICY_TRUSTLIST | 3   | 只有应用指定的列表在后台可以使用计量网络。 |

## NetQuotaPolicy

计量网络策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称             | 类型                                    | 只读 |可选| 说明                             |
| ---------------- | --------------------------------------- | ---- | ----|---------------------------- |
| networkMatchRule | [NetworkMatchRule](#networkmatchrule) | 否   |否 |网络标识，用来确定设置哪一个网络。 |
| quotaPolicy      | [QuotaPolicy](#quotapolicy)           | 否  | 否|具体的计量网络策略。               |

## NetworkMatchRule

网络标识，用来确定设置哪一个网络

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称     | 类型                                                 | 只读 |可选| 说明                                                                         |
| -------- | ---------------------------------------------------- | ---- | ------|---------------------------------------------------------------------- |
| netType  | [NetBearType](js-apis-net-connection.md#netbeartype) | 否   |否 |网络类型。                                                                   |
| simId    | string                                               | 否    |否 |计量蜂窝网络的SIM卡的标识值。<br>以太网和wifi网络不会用到。                     |
| identity | string                                               | 否   |否 |计量蜂窝网络中配合simId联合使用。<br>以太网和wifi网络单独使用。<br>用于标记类型。 |

## QuotaPolicy

计量网络策略

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称              | 类型                            | 只读 |可选| 说明                                                  |
| ----------------- |-------------------------------| ---- |----|-------------------------------------------------|
| periodDuration    | string                        | 否   |否 |流量限制计量周期。D1、M1、Y1分别代表1天、1个月、1年内流量限制，超出时间则不受限制。 |
| warningBytes      | number                        | 否   |否 |发出警告的流量阈值。                                          |
| limitBytes        | number                        | 否   |否 |流量设置的配额。                                            |
| metered           | boolean                       | 否   |否 |是否为计量网络。true表示是，false表示不是。                                         |
| limitAction       | [LimitAction](#limitaction) | 否   | 否|到达流量限制后的动作。                                         |
| lastWarningRemind | number                        | 否   |是 |最新一次发出警告的时间。如果值大于0，值为时间戳（单位：s），否则表示警告从未发出。默认值：-1。                                  |
| lastLimitRemind   | number                        | 否   |是 |最新一次配额耗尽的时间。如果值大于0，值为时间戳（单位：s），否则表示警告从未耗尽。默认值：-1。                                      |

## LimitAction

限制动作。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                         | 值  | 说明                               |
| ---------------------------- | --- | ---------------------------------- |
| LIMIT_ACTION_NONE            | -1  | 默认值。                           |
| LIMIT_ACTION_ACCESS_DISABLED | 0   | 当配额策略达到限制时，访问被禁用。 |
| LIMIT_ACTION_ALERT_ONLY      | 1   | 当配额策略达到限制时，将警告用户。 |

## NetUidRule

计量网络规则。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                              | 值     | 说明                 |
| --------------------------------- | ------ | -------------------- |
| NET_RULE_NONE                     | 0      | 默认规则。             |
| NET_RULE_ALLOW_METERED_FOREGROUND | 1 << 0 | 允许前台访问计量网络。 |
| NET_RULE_ALLOW_METERED            | 1 << 1 | 允许访问计量网络。     |
| NET_RULE_REJECT_METERED           | 1 << 2 | 拒绝访问计量网络。     |
| NET_RULE_ALLOW_ALL                | 1 << 5 | 允许访问所有网络。    |
| NET_RULE_REJECT_ALL               | 1 << 6 | 拒绝访问所有网络。     |

## NetUidRuleInfo<sup>11+</sup>

生成网络唯一标识。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称              | 类型                           | 只读 |可选| 说明                                      |
| ----------------- | ----------------------------- | ---- | ------|----------------------------------- |
| uid               | number                        | 否   |否 |流量警告的阈值，默认：DATA_USAGE_UNKNOWN。 |
| rule              | [NetUidRule](#netuidrule)   | 否  |否 |规定一个UID访问计量网络还是非计量网络。     |

## NetUidPolicyInfo<sup>11+</sup>

注册网络UID策略变化的回调函数。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称              | 类型                            | 只读 |可选| 说明                                    |
| ----------------- | ------------------------------- | ---- | ----|---------------------------------- |
| uid               | number                          | 否   |否 |流量警告的阈值，默认：DATA_USAGE_UNKNOWN。 |
| policy            | [NetUidPolicy](#netuidpolicy) | 否   | 否|UID指定了在后台模式下网络访问的策略。    |

## RemindType

提醒类型。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                | 值  | 说明     |
| ------------------- | --- | -------- |
| REMIND_TYPE_WARNING | 1   | 警告提醒。 |
| REMIND_TYPE_LIMIT   | 2   | 限制提醒。 |

## NetUidPolicy

应用对应的网络策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称                                 | 值     | 说明                       |
| ------------------------------------ | ------ | -------------------------- |
| NET_POLICY_NONE                      | 0      | 默认网络策略。               |
| NET_POLICY_ALLOW_METERED_BACKGROUND  | 1 << 0 | 允许应用在后台访问计量网络。 |
| NET_POLICY_REJECT_METERED_BACKGROUND | 1 << 1 | 拒绝应用在后台访问计量网络。 |

## NetworkAccessPolicy<sup>12+</sup>

应用对应的连接网络的策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称              | 类型       | 只读 | 可选|说明                          |
| ----------------- | --------- | ---- | ------|----------------------- |
| allowWiFi         | boolean   | 否   |是 |是否允许应用访问wifi网络。true表示允许，false表示不允许。 |
| allowCellular     | boolean   | 否  |是 |是否允许应用访问蜂窝网络。true表示允许，false表示不允许。 |
| alwaysAllowWiFi<sup>18+</sup>    | boolean   | 否  |是 |是否允许应用一直访问wifi网络。true表示允许，false表示不允许。 |
| alwaysAllowCellular<sup>18+</sup>  | boolean   | 否  |是 |是否允许应用一直访问蜂窝网络。true表示允许，false表示不允许。 |

## UidNetworkAccessPolicy<sup>12+</sup>

应用标识以及对应应用连接网络的策略。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称       | 类型                                                         | 只读 |可选|说明                 |
| --------- | -----------------------------------------------------------  | ---- | ---|---------------- |
| [uid: string] | [NetworkAccessPolicy](#networkaccesspolicy12) | 否   |否 |数据类型为键值对。      |