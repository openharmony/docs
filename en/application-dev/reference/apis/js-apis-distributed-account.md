# Distributed Account Management

The distributedAccount module provides basic functions for managing distributed accounts, including querying and updating account login status.

> **NOTE**<br>
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
  | [DistributedAccountAbility](#distributedaccountability) | **DistributedAccountAbility** instance obtained. This instance provides methods for querying and updating the login state of a distributed account.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  ```

## DistributedAccountAbility

Provides methods for querying and updating the login state of a distributed account. You must obtain a **DistributedAccountAbility** instance first.

### queryOsAccountDistributedInfo

queryOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

Obtains distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.DISTRIBUTED_DATASYNC

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | Yes| Callback invoked to return the distributed account information obtained.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo((err, data) => { 
      console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
      console.log('Query account info name: ' + data.name);
      console.log('Query account info id: ' + data.id);
  });
  ```

### queryOsAccountDistributedInfo

queryOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

Obtains distributed account information. This API uses a promise to return the result.

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

### updateOsAccountDistributedInfo

updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Updates distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the distributed account information is updated.|

**Example**
  ```js
  const accountAbility = account_distributedAccount.getDistributedAccountAbility();
  let accountInfo = {id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN'};
  accountAbility.updateOsAccountDistributedInfo(accountInfo, (err) => { 
      console.log("queryOsAccountDistributedInfo err: " + JSON.stringify(err));
  });
  ```

### updateOsAccountDistributedInfo

updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

Updates distributed account information. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

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
| name | string | Yes| Name of a distributed account. It must be a non-null string.|
| id | string | Yes| UID of a distributed account. It must be a non-null string.|
| event | string | Yes| Login state of a distributed account. The state can be login, logout, token invalid, or logoff, which correspond to the following strings respectively:<br>-&nbsp;Ohos.account.event.LOGIN<br>-&nbsp;Ohos.account.event.LOGOUT<br>-&nbsp;Ohos.account.event.TOKEN_INVALID<br>-&nbsp;Ohos.account.event.LOGOFF |
| scalableData | object | No| Extended information about a distributed account. Customized information is passed in key-value pairs.<br>Note: This parameter is reserved and not used in query and update methods.|
