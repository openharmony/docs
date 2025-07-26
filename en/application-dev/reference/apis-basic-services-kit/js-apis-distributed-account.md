# @ohos.account.distributedAccount (Distributed Account Management)

The **distributedAccount** module provides APIs for managing distributed accounts, including querying and updating account login states.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { distributedAccount } from '@kit.BasicServicesKit';
```

## distributedAccount.getDistributedAccountAbility

getDistributedAccountAbility(): DistributedAccountAbility

Obtains a **DistributedAccountAbility** instance.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type| Description|
| -------- | -------- |
| [DistributedAccountAbility](#distributedaccountability) | **DistributedAccountAbility** instance obtained. This instance provides APIs for querying and updating the login state of a distributed account.||

**Example**
  ```ts
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  ```

## DistributedAccountAbility

Provides APIs for querying and updating the login state of a distributed account. You must obtain a **DistributedAccountAbility** instance first.

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

Obtains distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (for system applications only), ohos.permission.GET_DISTRIBUTED_ACCOUNTS (for system applications only), or ohos.permission.DISTRIBUTED_DATASYNC

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the distributed account information obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo(
      (err: BusinessError, data: distributedAccount.DistributedInfo) => {
        if (err) {
          console.error('getOsAccountDistributedInfo exception: ' + JSON.stringify(err));
        } else {
          console.log('distributed information: ' + JSON.stringify(data));
        }
      });
  } catch (err) {
    console.error('getOsAccountDistributedInfo exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

Obtains distributed account information. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (for system applications only), ohos.permission.GET_DISTRIBUTED_ACCOUNTS (for system applications only), or ohos.permission.DISTRIBUTED_DATASYNC

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise used to return the distributed account information obtained.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | System service exception. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo().then((data: distributedAccount.DistributedInfo) => {
        console.log('distributed information: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
        console.error('getOsAccountDistributedInfo exception: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.error('getOsAccountDistributedInfo exception: ' + JSON.stringify(err));
  }
  ```

### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

Queries distributed account information. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountDistributedInfo](#getosaccountdistributedinfo9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only) or ohos.permission.DISTRIBUTED_DATASYNC

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | Yes| Callback used to return the result. If the operation is successful, **err** is **undefined** and **data** is the distributed account information obtained. Otherwise, **err** is an error object.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo(
    (err: BusinessError, data: distributedAccount.DistributedInfo) => {
      if (err) {
        console.error('queryOsAccountDistributedInfo exception: ' + JSON.stringify(err));
      } else {
        console.log('distributed information: ' + JSON.stringify(data));
      }
    });
  ```

### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

Queries distributed account information. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountDistributedInfo](#getosaccountdistributedinfo9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only) or ohos.permission.DISTRIBUTED_DATASYNC

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise used to return the distributed account information obtained.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo().then((data: distributedAccount.DistributedInfo) => {
      console.log('distributed information: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
      console.error('queryOsAccountDistributedInfo exception: '  + JSON.stringify(err));
  });
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Sets the distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (available only for system applications)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the distributed account information is set successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid accountInfo. |
| 12300003 | Account not found. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {
      if (err) {
        console.error('setOsAccountDistributedInfo exception: ' + JSON.stringify(err));
      } else {
        console.log('setOsAccountDistributedInfo successfully');
      }
    });
  } catch (err) {
      console.error('setOsAccountDistributedInfo exception: ' + JSON.stringify(err));
  }
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

Sets the distributed account information. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (available only for system applications)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid accountInfo. |
| 12300003 | Account not found. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo).then(() => {
        console.log('setOsAccountDistributedInfo successfully');
    }).catch((err: BusinessError) => {
        console.error('setOsAccountDistributedInfo exception: '  + JSON.stringify(err));
    });
  } catch (err) {
      console.error('setOsAccountDistributedInfo exception: ' + JSON.stringify(err));
  }
  ```

### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Updates the distributed account information. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [setOsAccountDistributedInfo](#setosaccountdistributedinfo9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to update. |
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the distributed account information is updated successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {
    if (err) {
      console.error('queryOsAccountDistributedInfo exception: ' + JSON.stringify(err));
    } else {
      console.log('queryOsAccountDistributedInfo successfully');
    }
  });
  ```

### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

Updates the distributed account information. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [setOsAccountDistributedInfo](#setosaccountdistributedinfo9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to update. |

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  let accountInfo: distributedAccount.DistributedInfo =
    {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {
      console.log('updateOsAccountDistributedInfo successfully');
   }).catch((err: BusinessError) => {
      console.error('updateOsAccountDistributedInfo exception: '  + JSON.stringify(err));
  });
  ```

## DistributedInfo

Represents the distributed information about a system account.

**System capability**: SystemCapability.Account.OsAccount

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string |Yes| Name of the distributed account. It must be a non-null string.|
| id | string |Yes| UID of the distributed account. It must be a non-null string.|
| event | string |Yes| Login state of the distributed account. The state can be login, logout, token invalid, or logoff, which correspond to the following strings respectively:<br>-&nbsp;Ohos.account.event.LOGIN<br>-&nbsp;Ohos.account.event.LOGOUT<br>-&nbsp;Ohos.account.event.TOKEN_INVALID<br>-&nbsp;Ohos.account.event.LOGOFF |
| nickname<sup>9+</sup> | string |No| Nickname of the distributed account. By default, no value is passed in.|
| avatar<sup>9+</sup> | string |No| Avatar of the distributed account. By default, no value is passed in.|
| status<sup>10+</sup> | [DistributedAccountStatus](#distributedaccountstatus10) |No| Status of the distributed account. The value is of the enumerated type. The default status is unlogged.|
| scalableData<sup>8+</sup> | object |No| Additional information about the distributed account, in the form of KV pairs. This parameter is left empty by default.|

## DistributedAccountStatus<sup>10+</sup>

Enumerates the statuses of a distributed account.

**System capability**: SystemCapability.Account.OsAccount

| Name | Value| Description       |
| ---- | ------ | ----------- |
| NOT_LOGGED_IN   | 0  | The account has not logged in.|
| LOGGED_IN  | 1  | The account has logged in.|
