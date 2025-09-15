# @ohos.net.policy (Network Policy Management) (System API)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

The **policy** module provides APIs for managing network policies, through which you can control and manage the data volume used.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { policy } from '@kit.NetworkKit';
```

## policy.setBackgroundAllowed<sup>10+</sup>

setBackgroundAllowed(isAllowed: boolean, callback: AsyncCallback\<void>): void

Specifies whether background applications are allowed to access the network. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                | Mandatory| Description                                                        |
| --------- | -------------------- | ---- | ------------------------------------------------------------ |
| isAllowed | boolean              | Yes  | Whether background applications are allowed to use mobile data. The value **true** indicates that background applications are allowed to use mobile data, and the value **false** indicates the opposite.                                    |
| callback  | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setBackgroundAllowed(true, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setBackgroundAllowed<sup>10+</sup>

setBackgroundAllowed(isAllowed: boolean): Promise\<void>

Specifies whether background applications are allowed to access the network. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type   | Mandatory| Description                    |
| --------- | ------- | ---- | ------------------------ |
| isAllowed | boolean | Yes  | Whether background applications are allowed to use mobile data. The value **true** indicates that background applications are allowed to use mobile data, and the value **false** indicates the opposite.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Return value**

| Type          | Description                                                             |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setBackgroundAllowed(true).then(() => {
  console.info("setBackgroundAllowed success");
}).catch((error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.isBackgroundAllowed<sup>10+</sup>

isBackgroundAllowed(callback: AsyncCallback\<boolean>): void

Checks whether the current application is allowed to access the network when running at the background. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                            |
| -------- | ----------------------- | ---- | ---------------------------------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. If the operation is successful, the value **true** is returned, indicating that the application is allowed to access the network when running at the background. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.isBackgroundAllowed((error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
 console.info(JSON.stringify(data));
});
```

## policy.isBackgroundAllowed<sup>10+</sup>

isBackgroundAllowed(): Promise\<boolean>

Checks whether the current application is allowed to access the network when running at the background. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type             | Description                                                                                |
| ----------------- | ------------------------------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result. If the operation is successful, the value **true** is returned, indicating that the application is allowed to access the network when running at the background. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.setPolicyByUid<sup>10+</sup>

setPolicyByUid(uid: number, policy: NetUidPolicy, callback: AsyncCallback\<void>): void

Sets the metered network access policy for the application specified by a given UID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                           | Mandatory| Description                                          |
| -------- | ------------------------------- | ---- | ---------------------------------------------- |
| uid      | number                          | Yes  | The app unique identifier, which is a positive integer within the range of int32_t.                               |
| policy   | [NetUidPolicy](#netuidpolicy10) | Yes  | Network access policy for the application.                                |
| callback | AsyncCallback\<void>            | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setPolicyByUid(11111, policy.NetUidPolicy.NET_POLICY_NONE, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setPolicyByUid<sup>10+</sup>

setPolicyByUid(uid: number, policy: NetUidPolicy): Promise\<void>

Sets the metered network access policy for the application specified by a given UID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type                           | Mandatory| Description          |
| ------ | ------------------------------- | ---- | -------------- |
| uid    | number                          | Yes  | The unique identifier of the app, which is a positive integer within the range of int32_t.|
| policy | [NetUidPolicy](#netuidpolicy10) | Yes  | Network access policy for the application.|

**Return value**

| Type          | Description                                                             |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.getPolicyByUid<sup>10+</sup>

getPolicyByUid(uid: number, callback: AsyncCallback\<NetUidPolicy>): void

Obtains the network access policy for the application specified by a given UID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                    |
| -------- | ----------------------------------------------- | ---- | -------------------------------------------------------- |
| uid      | number                                          | Yes  | Unique app ID. The value is a positive integer within the int32_t range.                                          |
| callback | AsyncCallback\<[NetUidPolicy](#netuidpolicy10)> | Yes  | Callback used to return the result. If the operation is successful, the policy result is returned. If the operation fails, an error code is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getPolicyByUid(11111, (error: BusinessError, data: policy.NetUidPolicy) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getPolicyByUid<sup>10+</sup>

getPolicyByUid(uid: number): Promise\<NetUidPolicy>

Obtains the network access policy for the application specified by a given UID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| uid    | number | Yes  | The app unique identifier, which is a positive integer within the int32_t range.|

**Return value**

| Type                                     | Description                                                     |
| ----------------------------------------- | --------------------------------------------------------- |
| Promise\<[NetUidPolicy](#netuidpolicy10)> | Promise used to return the result. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.getUidsByPolicy<sup>10+</sup>

getUidsByPolicy(policy: NetUidPolicy, callback: AsyncCallback\<Array\<number>>): void

Obtains all UIDs that match the specified network policy. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                           | Mandatory| Description                                                       |
| -------- | ------------------------------- | ---- | ----------------------------------------------------------- |
| policy   | [NetUidPolicy](#netuidpolicy10) | Yes  | Network policy for the application.                                 |
| callback | AsyncCallback\<Array\<number>>  | Yes  | Callback used to return the result. If the operation is successful, the UID array of the application is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getUidsByPolicy(11111, (error: BusinessError, data: number[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getUidsByPolicy<sup>10+</sup>

getUidsByPolicy(policy: NetUidPolicy): Promise\<Array\<number>>

Obtains all UIDs that match the specified network policy. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type                           | Mandatory| Description                      |
| ------ | ------------------------------- | ---- | -------------------------- |
| policy | [NetUidPolicy](#netuidpolicy10) | Yes  | Network policy for the application.|

**Return value**

| Type                    | Description                                                        |
| ------------------------ | ------------------------------------------------------------ |
| Promise\<Array\<number>> | Promise used to return the result. If the operation is successful, the operation result is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.getNetQuotaPolicies<sup>10+</sup>

getNetQuotaPolicies(callback: AsyncCallback\<Array\<NetQuotaPolicy>>): void

Obtains the network quota policies. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                       | Mandatory| Description                    |
| -------- | ----------------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | Yes  | Callback used to return the result.  .|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getNetQuotaPolicies((error: BusinessError, data: policy.NetQuotaPolicy[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getNetQuotaPolicies<sup>10+</sup>

getNetQuotaPolicies(): Promise\<Array\<NetQuotaPolicy>>

Obtains the network quota policies. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                                                 | Description                         |
| ----------------------------------------------------- | ----------------------------- |
| Promise\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.setNetQuotaPolicies<sup>10+</sup>

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>, callback: AsyncCallback\<void>): void

Sets network quota policies. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name       | Type                                       | Mandatory| Description                                          |
| ------------- | ------------------------------------------- | ---- | ---------------------------------------------- |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy10)> | Yes  | Defines the quota policy for the specified network.                                  |
| callback      | AsyncCallback\<void>                        | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netQuotaPolicyList: Array<policy.NetQuotaPolicy> = [];
let netquotapolicy: policy.NetQuotaPolicy = {
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
netQuotaPolicyList.push(netquotapolicy);

policy.setNetQuotaPolicies(netQuotaPolicyList, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setNetQuotaPolicies<sup>10+</sup>

setNetQuotaPolicies(quotaPolicies: Array\<NetQuotaPolicy>): Promise\<void>

Sets network quota policies. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name       | Type                                       | Mandatory| Description        |
| ------------- | ------------------------------------------- | ---- | ------------ |
| quotaPolicies | Array\<[NetQuotaPolicy](#netquotapolicy10)> | Yes  | Defines the quota policy for the specified network.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Return value**

| Type          | Description                                                             |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Example**

```ts
import { connection } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

let netQuotaPolicyList: Array<policy.NetQuotaPolicy> = [];
let netquotapolicy: policy.NetQuotaPolicy = {
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
netQuotaPolicyList.push(netquotapolicy);

policy
  .setNetQuotaPolicies(netQuotaPolicyList)
  .then(() => {
    console.info('setNetQuotaPolicies success');
  })
  .catch((error: BusinessError) => {
    console.error(JSON.stringify(error));
  });
```

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, isMetered: boolean, callback: AsyncCallback\<boolean>): void

Checks whether the application specified by a given UID is allowed to access a metered network. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                   | Mandatory| Description                                                     |
| --------- | ----------------------- | ---- | --------------------------------------------------------- |
| uid       | number                  | Yes  | The app unique identifier, which is a positive integer within the range of int32_t.                                          |
| isMetered | boolean                 | Yes  | Whether the network is a metered network. The value **true** indicates that the network is a metered network, and the value **false** indicates the opposite.                                           |
| callback  | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the application is allowed to access metered networks, and the value **false** means the opposite.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.isUidNetAllowed(11111, true, (error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, isMetered: boolean): Promise\<boolean>

Checks whether the application specified by a given UID is allowed to access a metered network. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type   | Mandatory| Description          |
| --------- | ------- | ---- | -------------- |
| uid       | number  | Yes  | The app unique identifier, which is a positive integer within the range of int32_t.|
| isMetered | boolean | Yes  | Whether the network is a metered network. The value **true** indicates that the network is a metered network, and the value **false** indicates the opposite.|

**Return value**

| Type             | Description                         |
| ----------------- | ----------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, iface: string, callback: AsyncCallback\<boolean>): void

Checks whether an application is allowed to access the specified network. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| uid      | number                  | Yes  | The app unique identifier, which is a positive integer within the range of int32_t.                                              |
| iface    | string                  | Yes  | Name of the target network.                                             |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that the application is allowed to access the specified network, and the value **false** means the opposite.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.isUidNetAllowed(11111, 'wlan0', (error: BusinessError, data: boolean) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.isUidNetAllowed<sup>10+</sup>

isUidNetAllowed(uid: number, iface: string): Promise\<boolean>

Checks whether an application is allowed to access the specified network. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| uid    | number | Yes  | The app unique identifier, which is a positive integer within the range of int32_t.|
| iface  | string | Yes  | Name of the target network.|

**Return value**

| Type             | Description                                                   |
| ----------------- | ------------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. |

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.setDeviceIdleTrustlist<sup>10+</sup>

setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void

Adds applications specified by given UIDs to the device idle allowlist. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                          | Mandatory| Description                                          |
| --------- | ------------------------------ | ---- | ---------------------------------------------- |
| uids      | Array\<number>                 | Yes  | Unique ID of the application.                                |
| isAllowed | boolean                        | Yes  | Whether to add the application to the allowlist. The value **true** means to add the application to the allowlist, and the value **false** means the opposite.                                |
| callback  | callback: AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setDeviceIdleTrustlist([11111, 22222], true, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setDeviceIdleTrustlist<sup>10+</sup>

setDeviceIdleTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>

Adds applications specified by given UIDs to the device idle allowlist. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type          | Mandatory| Description          |
| --------- | -------------- | ---- | -------------- |
| uids      | Array\<number> | Yes  | Unique ID of the application.|
| isAllowed | boolean        | Yes  | Whether to add the application to the allowlist. The value **true** means to add the application to the allowlist, and the value **false** means the opposite.|

**Return value**

| Type          | Description                                                             |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.getDeviceIdleTrustlist<sup>10+</sup>

getDeviceIdleTrustlist(callback: AsyncCallback\<Array\<number>>): void

Obtains the UIDs of applications that are on the device idle allowlist. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                          | Mandatory| Description                    |
| -------- | ------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<Array\<number>> | Yes  | Callback used to return the result.  .|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getDeviceIdleTrustlist((error: BusinessError, data: number[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getDeviceIdleTrustlist<sup>10+</sup>

getDeviceIdleTrustlist(): Promise\<Array\<number>>

Obtains the UIDs of applications that are on the device idle allowlist. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                    | Description                         |
| ------------------------ | ----------------------------- |
| Promise\<Array\<number>> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.getBackgroundPolicyByUid<sup>10+</sup>

getBackgroundPolicyByUid(uid: number, callback: AsyncCallback\<NetBackgroundPolicy>): void

Obtains the background network policy for the application specified by a given UID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                         | Mandatory| Description                    |
| -------- | ------------------------------------------------------------- | ---- | ------------------------ |
| uid      | number                                                        | Yes  | Unique app identifier, which is a positive integer within the int32_t range.          |
| callback | AsyncCallback\<[NetBackgroundPolicy](#netbackgroundpolicy10)> | Yes  | Callback used to return the result.  .|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getBackgroundPolicyByUid(11111, (error: BusinessError, data: policy.NetBackgroundPolicy) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getBackgroundPolicyByUid<sup>10+</sup>

getBackgroundPolicyByUid(uid: number): Promise\<NetBackgroundPolicy>

Obtains the background network policies configured for the specified application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| uid    | number | Yes  | The app unique identifier, which is a positive integer within the int32_t range.|

**Return value**

| Type                                                   | Description                         |
| ------------------------------------------------------- | ----------------------------- |
| Promise\<[NetBackgroundPolicy](#netbackgroundpolicy10)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.resetPolicies<sup>10+</sup>

resetPolicies(simId: string, callback: AsyncCallback\<void>): void

Restores all the policies (cellular network, background network, firewall, and application-specific network policies) for the specified SIM card. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                          |
| -------- | -------------------- | ---- | ---------------------------------------------- |
| simId    | string               | Yes  | SIM card ID.                                     |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.resetPolicies('1', (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.resetPolicies<sup>10+</sup>

resetPolicies(simId: string): Promise\<void>

Restores all the policies (cellular network, background network, firewall, and application-specific network policies) for the specified SIM card. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description     |
| ------ | ------ | ---- | --------- |
| simId  | string | Yes  | SIM card ID.|

**Return value**

| Type          | Description                                                             |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.updateRemindPolicy<sup>10+</sup>

updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType, callback: AsyncCallback\<void>): void

Updates a reminder policy. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name    | Type                                                | Mandatory| Description                                          |
| ---------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| netType    | [NetBearType](js-apis-net-connection.md#netbeartype) | Yes  | Network type.                                      |
| simId      | string                                               | Yes  | SIM card ID.                                     |
| remindType | [RemindType](#remindtype10)                          | Yes  | Enumerates the reminder types.                                      |
| callback   | AsyncCallback\<void>                                 | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.updateRemindPolicy<sup>10+</sup>

updateRemindPolicy(netType: NetBearType, simId: string, remindType: RemindType): Promise\<void>

Updates a reminder policy. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name    | Type                                                | Mandatory| Description     |
| ---------- | ---------------------------------------------------- | ---- | --------- |
| netType    | [NetBearType](js-apis-net-connection.md#netbeartype) | Yes  | Network type. |
| simId      | string                                               | Yes  | SIM card ID.|
| remindType | [RemindType](#remindtype10)                          | Yes  | Enumerates the reminder types. |

**Return value**

| Type          | Description                                                             |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.setPowerSaveTrustlist<sup>10+</sup>

setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean, callback: AsyncCallback\<void>): void

Sets whether to add the application specified by a given UID to the power-saving allowlist. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                          | Mandatory| Description                                          |
| --------- | ------------------------------ | ---- | ---------------------------------------------- |
| uids      | Array\<number>                 | Yes  | Unique ID of the application.                               |
| isAllowed | boolean                        | Yes  | Whether to add the application to the allowlist. The value **true** means to add the application to the allowlist, and the value **false** means the opposite.                                |
| callback  | callback: AsyncCallback\<void> | Yes  | Callback used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.setPowerSaveTrustlist([11111, 22222], true, (error: BusinessError) => {
  console.error(JSON.stringify(error));
});
```

## policy.setPowerSaveTrustlist<sup>10+</sup>

setPowerSaveTrustlist(uids: Array\<number>, isAllowed: boolean): Promise\<void>

Sets whether to add the application specified by a given UID to the power-saving allowlist. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type          | Mandatory| Description          |
| --------- | -------------- | ---- | -------------- |
| uids      | Array\<number> | Yes  | Unique ID of the application.|
| isAllowed | boolean        | Yes  | Whether to add the application to the allowlist. The value **true** means to add the application to the allowlist, and the value **false** means the opposite.|

**Return value**

| Type          | Description                                                             |
| -------------- | ----------------------------------------------------------------- |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## policy.getPowerSaveTrustlist<sup>10+</sup>

getPowerSaveTrustlist(callback: AsyncCallback\<Array\<number>>): void

Obtains the UID array of applications that are on the power-saving allowlist. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                          | Mandatory| Description                    |
| -------- | ------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback\<Array\<number>> | Yes  | Callback used to return the result.  .|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

policy.getPowerSaveTrustlist((error: BusinessError, data: number[]) => {
  console.error(JSON.stringify(error));
  console.info(JSON.stringify(data));
});
```

## policy.getPowerSaveTrustlist<sup>10+</sup>

getPowerSaveTrustlist(): Promise\<Array\<number>>

Obtains the UID array of applications that are on the device idle allowlist. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                    | Description                         |
| ------------------------ | ----------------------------- |
| Promise\<Array\<number>> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

Specifies whether an application with the specified UID can access the network. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name        | Type                                          | Mandatory| Description                                                                         |
| ------------- | ---------------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| uid           | number                                         | Yes  | The unique identifier of the app, which is a positive integer within the range of int32_t.                                                               |
| policy        | [NetworkAccessPolicy](#networkaccesspolicy12)  | Yes  | Network policy.                                                                     |
| isReconfirmed | boolean                                        | No  | Whether reconfirmation is required. The value **true** indicates that reconfirmation is not required and no dialog box is displayed. The value **false** indicates that reconfirmation is required and a dialog box is displayed when the application accesses the network. The default value is **false**. |

**Return value**

| Type          | Description                                                         |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise used to return the result. If the operation is successful, no value is returned. If the operation fails, an error message is returned.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

Checks whether an application with the specified UID can access the network. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| uid    | number | Yes  | The app unique identifier, which is a positive integer within the range of int32_t.|

**Return value**

| Type                                                   | Description                         |
| ------------------------------------------------------- | ----------------------------- |
| Promise\<[NetworkAccessPolicy](#networkaccesspolicy12)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

Checks whether all applications of the current user can access the network. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**

| Type                                                         | Description                       |
| ------------------------------------------------------------- | --------------------------- |
| Promise\<[UidNetworkAccessPolicy](#uidnetworkaccesspolicy12)> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

Represents the handle to a network policy.

### on('netUidPolicyChange')<sup>10+</sup>

on(type: "netUidPolicyChange", callback: Callback\<NetUidPolicyInfo\>): void

Subscribes to policy changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                               | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                              | Yes  | Event type.<br/> The value **netUidPolicyChange** indicates a policy change event.                 |
| callback | Callback\<[NetUidPolicyInfo](#netuidpolicyinfo11)> | Yes  | Callback used to return the result. It is called when the network policy changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### off('netUidPolicyChange')<sup>10+</sup>

off(type: "netUidPolicyChange", callback?: Callback\<NetUidPolicyInfo\>): void

Unsubscribes from policy changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                               | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                              | Yes  | Event type. The value **netUidPolicyChange** indicates a policy change event.              |
| callback | Callback\<[NetUidPolicyInfo](#netuidpolicyinfo11)> | No  | Callback used to return the result. It is called when the network policy changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### on('netUidRuleChange')<sup>10+</sup>

on(type: "netUidRuleChange", callback: Callback\<NetUidRuleInfo\>): void

Subscribes to rule changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                         | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                        | Yes  | Event type.<br/> The value **netUidRuleChange** indicates a rule change event.                   |
| callback | Callback\<[NetUidRuleInfo](#netuidruleinfo11)> | Yes  | Callback used to return the result. It is called when the rule changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### off('netUidRuleChange')<sup>10+</sup>

off(type: "netUidRuleChange", callback?: Callback\<NetUidRuleInfo\>): void

Unsubscribes from rule changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                         | Mandatory| Description                                  |
| -------- | ------------------------------------------------------------- | ---- | -------------------------------------- |
| type     | string                                                        | Yes  | Event type. The value **netUidRuleChange** indicates a rule change event.                   |
| callback | Callback\<[NetUidRuleInfo](#netuidruleinfo11)> | No  | Callback used to return the result. It is called when the rule changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### on('netMeteredIfacesChange')<sup>10+</sup>

on(type: "netMeteredIfacesChange", callback: Callback\<Array\<string>>): void

Subscribes to metered **iface** changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| type     | string                    | Yes  | Event type.<br/> The value **netMeteredIfacesChange** indicates a metered **iface** change event.                |
| callback | Callback\<Array\<string>> | Yes  | Callback used to return the result. It is called when the registered metered **iface** changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### off('netMeteredIfacesChange')<sup>10+</sup>

off(type: "netMeteredIfacesChange", callback?: Callback\<Array\<string>>): void

Unsubscribes from metered **iface** changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                     |
| -------- | ------------------------- | ---- | ----------------------------------------- |
| type     | string                    | Yes  | Event type. The value **netMeteredIfacesChange** indicates a metered **iface** change event.                |
| callback | Callback\<Array\<string>> | No  | Callback used to return the result. It is called when the registered metered **iface** changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### on('netQuotaPolicyChange')<sup>10+</sup>

on(type: "netQuotaPolicyChange", callback: Callback\<Array\<NetQuotaPolicy>>): void

Subscribes to network quota policy changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                  | Mandatory| Description                                      |
| -------- | ------------------------------------------------------ | ---- | ------------------------------------------ |
| type     | string                                                 | Yes  | Event type.<br/> The value **netQuotaPolicyChange** indicates a network quota policy change event.                |
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | Yes  | Callback used to return the result. It is called when the registered network quota policy changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### off('netQuotaPolicyChange')<sup>10+</sup>

off(type: "netQuotaPolicyChange", callback?: Callback\<Array\<NetQuotaPolicy>>): void

Unsubscribes from network quota policy changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                                  | Mandatory| Description                                      |
| -------- | ------------------------------------------------------ | ---- | ------------------------------------------ |
| type     | string                                                 | Yes  | Event type. The value **netQuotaPolicyChange** indicates a network quota policy change event.                |
| callback | Callback\<Array\<[NetQuotaPolicy](#netquotapolicy10)>> | No  | Callback used to return the result. It is called when the registered network quota policy changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### on('netBackgroundPolicyChange')<sup>10+</sup>

on(type: "netBackgroundPolicyChange", callback: Callback\<boolean>): void

Subscribes to background network policy changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type              | Mandatory| Description                                      |
| -------- | ------------------ | ---- | ------------------------------------------ |
| type     | string             | Yes  | Event type.<br/> The value **netBackgroundPolicyChange** indicates a background network policy change event.                |
| callback | Callback\<boolean> | Yes  | Callback used to return the result. It is called when the registered background network policy changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

### off('netBackgroundPolicyChange')<sup>10+</sup>

off(type: "netBackgroundPolicyChange", callback?: Callback\<boolean>): void

Unsubscribes from background network policy changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.MANAGE_NET_STRATEGY

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type              | Mandatory| Description                                      |
| -------- | ------------------ | ---- | ------------------------------------------ |
| type     | string             | Yes  | Event type. The value **netBackgroundPolicyChange** indicates a background network policy change event.                |
| callback | Callback\<boolean> | No  | Callback used to return the result. It is called when the registered background network policy changes.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

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

## NetBackgroundPolicy<sup>10+</sup>

Enumerates the background network policies.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                           | Value | Description                                      |
| ------------------------------- | --- | ------------------------------------------ |
| NET_BACKGROUND_POLICY_NONE      | 0   | No background network policy is specified. This is the default value.                                  |
| NET_BACKGROUND_POLICY_ENABLE    | 1   | Background applications are allowed to access a metered network.              |
| NET_BACKGROUND_POLICY_DISABLE   | 2   | Applications running in the background are not allowed to access a metered network.            |
| NET_BACKGROUND_POLICY_TRUSTLIST | 3   | Only applications on the allowlist are allowed to access metered networks when they are running in the background.|

## NetQuotaPolicy<sup>10+</sup>

Defines the quota policy for the specified network.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name            | Type                                   | Mandatory| Description                            |
| ---------------- | --------------------------------------- | ---- | -------------------------------- |
| networkMatchRule | [NetworkMatchRule](#networkmatchrule10) | Yes  | Network for which the quota policy is set.|
| quotaPolicy      | [QuotaPolicy](#quotapolicy10)           | Yes  | Network quota policy.              |

## NetworkMatchRule<sup>10+</sup>

Defines the network for which the quota policy is set.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name    | Type                                                | Mandatory| Description                                                                        |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------------------------------- |
| netType  | [NetBearType](js-apis-net-connection.md#netbeartype) | Yes  | Network type.                                                                  |
| simId    | string                                               | Yes  | Identifier of the SIM card on the metered cellular network. It is not used for Wi-Fi networks.                    |
| identity | string                                               | Yes  | ID of the SIM card on the metered cellular network. It is used for Wi-Fi networks. It is used together with **iccid**.|

## QuotaPolicy<sup>10+</sup>

Defines the network quota policy.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name             | Type                           | Mandatory| Description                                                 |
| ----------------- |-------------------------------| ---- |-----------------------------------------------------|
| periodDuration    | string                        | Yes  | Metering period for the quota limit. **D1**, **M1**, and **Y1** indicate one day, one month, and one year, respectively. If the specified metering period is exceeded, the quota is not limited.|
| warningBytes      | number                        | Yes  | Data volume threshold for generating an alarm.                                         |
| limitBytes        | number                        | Yes  | Data volume quota.                                           |
| metered           | boolean                       | Yes  | Whether the network is a metered network. The value **true** indicates that the network is a metered network, and the value **false** indicates the opposite.                                           |
| limitAction       | [LimitAction](#limitaction10) | Yes  | Action to take when the data volume quota is reached.                                        |
| lastWarningRemind | number                        | No  | Last time when an alarm was generated. Default value: **-1**                                 |
| lastLimitRemind   | number                        | No  | Last time when the quota was exhausted. Default value: **-1**                                       |

## LimitAction<sup>10+</sup>

Enumerates the actions that can be taken when the data volume quota is reached.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                        | Value | Description                              |
| ---------------------------- | --- | ---------------------------------- |
| LIMIT_ACTION_NONE            | -1  | No action is taken. This is the default value.                          |
| LIMIT_ACTION_ACCESS_DISABLED | 0   | Internet access is disabled.|
| LIMIT_ACTION_ALERT_ONLY      | 1   | An alarm is generated when the quota limit is reached.|

## NetUidRule<sup>10+</sup>

Enumerates the metered network rules.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                             | Value    | Description                |
| --------------------------------- | ------ | -------------------- |
| NET_RULE_NONE                     | 0      | Default rule.            |
| NET_RULE_ALLOW_METERED_FOREGROUND | 1 << 0 | Applications running in the foreground are allowed to access a metered network.|
| NET_RULE_ALLOW_METERED            | 1 << 1 | Applications are allowed to access a metered network.    |
| NET_RULE_REJECT_METERED           | 1 << 2 | Applications are not allowed to access a metered network.    |
| NET_RULE_ALLOW_ALL                | 1 << 5 | Applications are allowed to access all networks (metered or non-metered).   |
| NET_RULE_REJECT_ALL               | 1 << 6 | Applications are not allowed to access any networks (metered or non-metered).    |

## NetUidRuleInfo<sup>11+</sup>

Defines a unique network ID.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name             | Type                          | Mandatory| Description                                     |
| ----------------- | ----------------------------- | ---- | ----------------------------------------- |
| uid               | number                        | Yes  | Traffic alarm threshold. The default value is **DATA_USAGE_UNKNOWN**.|
| rule              | [NetUidRule](#netuidrule10)   | Yes  | Rule that specifies whether the application specified by a given UID is allowed to access a metered or non-metered network.    |

## NetUidPolicyInfo<sup>11+</sup>

Defines the network policy information for an application.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name             | Type                           | Mandatory| Description                                   |
| ----------------- | ------------------------------- | ---- | -------------------------------------- |
| uid               | number                          | Yes  | Traffic alarm threshold. The default value is **DATA_USAGE_UNKNOWN**.|
| policy            | [NetUidPolicy](#netuidpolicy10) | Yes  | Policy that specifies whether the application specified by a given UID is allowed to access the network when running in the background.   |

## RemindType<sup>10+</sup>

Enumerates the reminder types.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name               | Value | Description    |
| ------------------- | --- | -------- |
| REMIND_TYPE_WARNING | 1   | Warning.|
| REMIND_TYPE_LIMIT   | 2   | Limit.|

## NetUidPolicy<sup>10+</sup>

Enumerates network access policies for the application.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name                                | Value    | Description                      |
| ------------------------------------ | ------ | -------------------------- |
| NET_POLICY_NONE                      | 0      | Default network policy.              |
| NET_POLICY_ALLOW_METERED_BACKGROUND  | 1 << 0 | Background applications are allowed to access a metered network.|
| NET_POLICY_REJECT_METERED_BACKGROUND | 1 << 1 | Applications running in the background are not allowed to access a metered network.|

## NetworkAccessPolicy<sup>12+</sup>

Network access policy.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name             | Type      | Mandatory| Description                         |
| ----------------- | --------- | ---- | ----------------------------- |
| allowWiFi         | boolean   | Yes  | Whether to allow access to the Wi-Fi network. The value **true** means to allow access to the Wi-Fi network, and the value **false** means the opposite.|
| allowCellular     | boolean   | Yes  | Whether to allow access to the cellular network. The value **true** means to allow access to the cellular network, and the value **false** means the opposite.|

## UidNetworkAccessPolicy<sup>12+</sup>

Defines the network policy for an application with the specified UID.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name      | Type                                                        | Mandatory| Description                |
| --------- | -----------------------------------------------------------  | ---- | ------------------- |
| undefined | [uid: string]: [NetworkAccessPolicy](#networkaccesspolicy12) | No  | Network policy. The data type is key-value pair.     |
