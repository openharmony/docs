# @ohos.account.distributedAccount (Distributed Account Management) (System API)

The **distributedAccount** module provides APIs for managing distributed accounts, including querying and updating account login states.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.account.distributedAccount (Distributed Account Management)](js-apis-distributed-account.md).

## Modules to Import

```ts
import { distributedAccount } from '@kit.BasicServicesKit';
```

## DistributedAccountAbility

Provides APIs for querying and updating the login state of a distributed account. You must obtain a **DistributedAccountAbility** instance first.

### getOsAccountDistributedInfoByLocalId<sup>10+</sup>

getOsAccountDistributedInfoByLocalId(localId: number, callback: AsyncCallback&lt;DistributedInfo&gt;): void

Obtains distributed information about a system account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | localId | number | Yes| ID of the target system account.|
  | callback | AsyncCallback&lt;[DistributedInfo](js-apis-distributed-account.md#distributedinfo)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the distributed account information obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID | Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300003 | Account not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
try {
  accountAbility.getOsAccountDistributedInfoByLocalId(100,
    (err: BusinessError, data: distributedAccount.DistributedInfo) => {
      if (err) {
        console.log('getOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));
      } else {
        console.log('distributed information: ' + JSON.stringify(data));
      }
    });
} catch (err) {
  console.log('getOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));
}
```

### getOsAccountDistributedInfoByLocalId<sup>10+</sup>

getOsAccountDistributedInfoByLocalId(localId: number): Promise&lt;DistributedInfo&gt;

Obtains distributed information about a system account. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**Return value**

  | Type | Description |
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](js-apis-distributed-account.md#distributedinfo)&gt; | Promise used to return the distributed account information obtained. |

**Error codes**

| ID | Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300003 | Account not found. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
try {
  accountAbility.getOsAccountDistributedInfoByLocalId(100).then((
    data: distributedAccount.DistributedInfo) => {
    console.log('distributed information: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.log('getOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
  });
} catch (err) {
  console.log('getOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));
}
```

### setOsAccountDistributedInfoByLocalId<sup>10+</sup>

setOsAccountDistributedInfoByLocalId(localId: number, distributedInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Sets the distributed information for a system account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | localId | number | Yes| ID of the target system account.|
  | accountInfo | [DistributedInfo](js-apis-distributed-account.md#distributedinfo) | Yes| Distributed account information to set.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the distributed information is set successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID | Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid distributedInfo. |
| 12300003 | Account identified by localId or by distributedInfo not found. |
| 12300008 | Restricted OS account. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
let accountInfo: distributedAccount.DistributedInfo =
  {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
try {
  accountAbility.setOsAccountDistributedInfoByLocalId(100, accountInfo, (err: BusinessError) => {
    if (err) {
      console.log('setOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));
    } else {
      console.log('setOsAccountDistributedInfoByLocalId successfully');
    }
  });
} catch (err) {
    console.log('setOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));
}
```

### setOsAccountDistributedInfoByLocalId<sup>10+</sup>

setOsAccountDistributedInfoByLocalId(localId: number, distributedInfo: DistributedInfo): Promise&lt;void&gt;

Sets the distributed information for a system account. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS

**Parameters**

  | Name | Type | Mandatory | Description |
  | -------- | -------- | -------- | -------- |
  | localId | number | Yes| ID of the target system account.|
  | distributedInfo | [DistributedInfo](js-apis-distributed-account.md#distributedinfo) | Yes| Distributed account information to set.|

**Return value**

  | Type | Description |
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

| ID | Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 202 | Not system application.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid distributedInfo. |
| 12300003 | Account identified by localId or by distributedInfo not found. |
| 12300008 | Restricted OS account. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
let accountInfo: distributedAccount.DistributedInfo =
  {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
try {
  accountAbility.setOsAccountDistributedInfoByLocalId(100, accountInfo).then(() => {
      console.log('setOsAccountDistributedInfoByLocalId successfully');
  }).catch((err: BusinessError) => {
      console.log('setOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
  });
} catch (err) {
    console.log('setOsAccountDistributedInfoByLocalId exception: ' + JSON.stringify(err));
}
```
