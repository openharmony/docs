# Distributed Account Management

The **distributedAccount** module provides APIs for managing distributed accounts, including querying and updating account login status.

> **NOTE**<br>
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import account_distributedAccount from '@ohos.account.distributedAccount';
```

## account_distributedAccount.getDistributedAccountAbility

getDistributedAccountAbility(): DistributedAccountAbility

Obtains a **DistributedAccountAbility** instance.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [DistributedAccountAbility](#distributedaccountability) | **DistributedAccountAbility** instance obtained. This instance provides APIs for querying and updating the login state of a distributed account.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  ```

## DistributedAccountAbility

Provides APIs for querying and updating the login state of a distributed account. You must obtain a **DistributedAccountAbility** instance first.

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

Obtains distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS, ohos.permission.GET_DISTRIBUTED_ACCOUNTS, or ohos.permission.DISTRIBUTED_DATASYNC

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **undefined** and data is the distributed account information obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo((err, data) => {
      console.log("getOsAccountDistributedInfo err: " + JSON.stringify(err));
      console.log('Query account info name: ' + data.name);
      console.log('Query account info id: ' + data.id);
    });
  } catch (e) {
    console.log("getOsAccountDistributedInfo exception: " + JSON.stringify(e));
  }
  ```

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

Obtains distributed account information. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS, ohos.permission.GET_DISTRIBUTED_ACCOUNTS, or ohos.permission.DISTRIBUTED_DATASYNC

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise used to return the distributed account information obtained.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo().then((data) => {
        console.log('Query account info name: ' + data.name);
        console.log('Query account info id: ' + data.id);
    }).catch((err) => {
        console.log("getOsAccountDistributedInfo err: "  + JSON.stringify(err));
    });
  } catch (e) {
    console.log("getOsAccountDistributedInfo exception: " + JSON.stringify(e));
  }
  ```
### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

Obtains distributed account information. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountDistributedInfo](#getosaccountdistributedinfo9).

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.DISTRIBUTED_DATASYNC

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **undefined** and data is the distributed account information obtained. Otherwise, **err** is an error object.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo((err, data) => {
      console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
      console.log('Query account info name: ' + data.name);
      console.log('Query account info id: ' + data.id);
  });
  ```

### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

Obtains distributed account information. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountDistributedInfo](#getosaccountdistributedinfo9-1).

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.DISTRIBUTED_DATASYNC

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise used to return the distributed account information obtained.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo().then((data) => {
      console.log('Query account info name: ' + data.name);
      console.log('Query account info id: ' + data.id);
  }).catch((err) => {
      console.log("queryOsAccountDistributedInfoerr: "  + JSON.stringify(err));
  });
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Sets the distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| New distributed account information.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the distributed account information is set successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid accountInfo. |
| 12300003 | Account not found. |

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo, (err) => {
        console.log("setOsAccountDistributedInfo err: " + JSON.stringify(err));
    });
  } catch (e) {
    console.log("setOsAccountDistributedInfo exception: " + JSON.stringify(e));
  }
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

Sets the distributed account information. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| New distributed account information.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | invalid accountInfo. |

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo).then(() => {
        console.log('setOsAccountDistributedInfo Success');
    }).catch((err) => {
        console.log("setOsAccountDistributedInfo err: "  + JSON.stringify(err));
    });
  } catch (e) {
    console.log("setOsAccountDistributedInfo exception: " + JSON.stringify(e));
  }
  ```
### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Updates distributed account information. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setOsAccountDistributedInfo](#setosaccountdistributedinfo9).

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| New distributed account information.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the distributed account information is set successfully, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo, (err) => {
      console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
  });
  ```

### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

Updates the distributed account information. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setOsAccountDistributedInfo](#setosaccountdistributedinfo9-1).
**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| New distributed account information.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {
      console.log('updateOsAccountDistributedInfo Success');
   }).catch((err) => {
      console.log("updateOsAccountDistributedInfo err: "  + JSON.stringify(err));
  });
  ```
## DistributedInfo

Defines distributed OS account information.

**System capability**: SystemCapability.Account.OsAccount

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Name of the distributed account. It must be a non-null string.|
| id | string | Yes| UID of the distributed account. It must be a non-null string.|
| event | string | Yes| Login state of a distributed account. The state can be login, logout, token invalid, or logoff, which correspond to the following strings respectively:<br>-&nbsp;Ohos.account.event.LOGIN<br>-&nbsp;Ohos.account.event.LOGOUT<br>-&nbsp;Ohos.account.event.TOKEN_INVALID<br>-&nbsp;Ohos.account.event.LOGOFF |
| nickname<sup>9+</sup> | string | No| Nickname of the distributed account. It must be a non-null string.|
| avatar<sup>9+</sup> | string | No| Avatar of the distributed account. It must be a non-null string.|
| scalableData | object | No| Extended information about the distributed account, passed in key-value (KV) pairs.<br>**NOTE**<br>This parameter is reserved and not used in query and update methods.|
