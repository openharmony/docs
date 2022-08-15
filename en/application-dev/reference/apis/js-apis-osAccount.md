#    OS Account Management

The osAccount module provides basic capabilities for managing operating system (OS) accounts, including adding, deleting, querying, setting, subscribing to, and enabling an OS account, and storing OS account data to disks.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import account_osAccount from '@ohos.account.osAccount';
```

## account_osAccount.getAccountManager

getAccountManager(): AccountManager

Obtains an **AccountManager** instance.

**System capability**: SystemCapability.Account.OsAccount

**Return value**
| Type                             | Description                    |
| --------------------------------- | ------------------------ |
| [AccountManager](#accountmanager) | Obtains an **AccountManager** instance.|

**Example**
  ```js
  const accountManager = account_osAccount.getAccountManager();
  ```

## OsAccountType

Enumerates OS account types.

**System capability**: SystemCapability.Account.OsAccount

| Name  | Default Value| Description        |
| ------ | ------ | ------------ |
| ADMIN  | 0      | Administrator account|
| NORMAL | 1      | Normal account  |
| GUEST  | 2      | Guest account  |

## AccountManager

Provides methods to manage OS accounts.

### activateOsAccount

activateOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

Activates an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| localId  | number                    | Yes  | ID of the OS account to activate.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Example**: Activate OS account 100.
  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.activateOsAccount(localId, (err)=>{
    console.log("activateOsAccount err:" + JSON.stringify(err));
  });
  ```

### activateOsAccount

activateOsAccount(localId: number): Promise&lt;void&gt;

Activates an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                |
| ------- | ------ | ---- | -------------------- |
| localId | number | Yes  | ID of the OS account to activate.|

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**: Activate OS account 100.
  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.activateOsAccount(localId).then(() => {
    console.log("activateOsAccount success");
  }).catch((err) => {
    console.log("activateOsAccount err:" + JSON.stringify(err));
  });
  ```

### isMultiOsAccountEnable

isMultiOsAccountEnable(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether multiple OS accounts are supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                               |
| -------- | ---------------------------- | ---- | --------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If multiple OS accounts are supported, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable((err, isEnabled) => {
    console.log("isMultiOsAccountEnable err: " + JSON.stringify(err));
    console.log('isMultiOsAccountEnable isEnabled: ' + isEnabled);
  });
  ```

### isMultiOsAccountEnable

isMultiOsAccountEnable(): Promise&lt;boolean&gt;

Checks whether multiple OS accounts are supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                        |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If multiple OS accounts are supported, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable().then((isEnabled) => {
    console.log('isMultiOsAccountEnable, isEnabled: ' + isEnabled);
  }).catch((err) => {
    console.log("isMultiOsAccountEnable err: "  + JSON.stringify(err));
  });
  ```

### isOsAccountActived

isOsAccountActived(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OS account is activated. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                             |
| -------- | ---------------------------- | ---- | ------------------------------------------------- |
| localId  | number                       | Yes  | ID of the target OS account.                                     |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the OS account is activated, **true** will be returned. Otherwise, **false** will be returned.|

**Example**: Check whether OS account 100 is activated.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var osLocalId = 100;
  accountManager.isOsAccountActived(osLocalId, (err, isActive)=>{
    console.log("isOsAccountActived err:" + JSON.stringify(err));
    console.log("isOsAccountActived isActive:" + isActive);
  });
  ```

### isOsAccountActived

isOsAccountActived(localId: number): Promise&lt;boolean&gt;

Checks whether an OS account is activated. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                  | Description                                                        |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the OS account is activated, **true** will be returned. Otherwise, **false** will be returned.|

**Example**: Check whether OS account 100 is activated.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var osLocalId = 100;
  accountManager.isOsAccountActived(osLocalId).then((isActive) => {
    console.log('isOsAccountActived, isActive: ' + isActive);
  }).catch((err) => {
    console.log("isOsAccountActived err: "  + JSON.stringify(err));
  });
  ```

### isOsAccountConstraintEnable

isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the specified constraint is enabled for an OS account. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                        | Mandatory| Description                                             |
| ---------- | ---------------------------- | ---- | ------------------------------------------------- |
| localId    | number                       | Yes  | ID of the target OS account.                               |
| constraint | string                       | Yes  | [Constraint](#constraints) specified.            |
| callback   | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the constraint is enabled for the OS account, **true** will be returned. Otherwise, **false** will be returned.|

**Example**: Check whether OS account 100 is forbidden to use Wi-Fi.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.isOsAccountConstraintEnable(localId, "constraint.wifi", (err, isConstraintEnabled)=>{
    console.log("isOsAccountConstraintEnable err:" + JSON.stringify(err));
    console.log("isOsAccountConstraintEnable isConstraintEnabled:" + isConstraintEnabled);
  });
  ```

### isOsAccountConstraintEnable

isOsAccountConstraintEnable(localId: number, constraint: string): Promise&lt;boolean&gt;

Checks whether the specified constraint is enabled for an OS account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type  | Mandatory| Description                                 |
| ---------- | ------ | ---- | ------------------------------------- |
| localId    | number | Yes  | ID of the target OS account.                   |
| constraint | string | Yes  | [Constraint](#constraints) specified.|

**Return value**

| Type                  | Description                                                        |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the constraint is enabled for the OS account, **true** will be returned. Otherwise, **false** will be returned.|

**Example**: Check whether OS account 100 is forbidden to use Wi-Fi.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.isOsAccountConstraintEnable(localId, "constraint.wifi").then((isConstraintEnabled) => {
    console.log('isOsAccountConstraintEnable, isConstraintEnabled: ' + isConstraintEnabled);
  }).catch((err) => {
    console.log("isOsAccountConstraintEnable err: "  + JSON.stringify(err));
  });
  ```

### isTestOsAccount

isTestOsAccount(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this OS account is a test account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                           |
| -------- | ---------------------------- | ---- | ----------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the account is a test account, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount((err, isTest) => {
    console.log("isTestOsAccount err: " + JSON.stringify(err));
    console.log('isTestOsAccount isTest: ' + isTest);
  });
  ```

### isTestOsAccount

isTestOsAccount(): Promise&lt;boolean&gt;

Checks whether this OS account is a test account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                        |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the account is a test account, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount().then((isTest) => {
    console.log('isTestOsAccount, isTest: ' + isTest);
  }).catch((err) => {
    console.log("isTestOsAccount err: "  + JSON.stringify(err));
  });
  ```

### isOsAccountVerified

isOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this OS account has been verified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                       |
| -------- | ---------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the OS account has been verified, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err, isVerified) => {
    console.log("isOsAccountVerified err: " + JSON.stringify(err));
    console.log('isOsAccountVerified isVerified: ' + isVerified);
  });
  ```

### isOsAccountVerified

isOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OS account has been verified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                       |
| -------- | ---------------------------- | ---- | ------------------------------------------- |
| localId  | number                       | No  | ID of the target OS account.                         |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. If the OS account has been verified, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err, isVerified) => {
    console.log("isOsAccountVerified err: " + JSON.stringify(err));
    console.log('isOsAccountVerified isVerified: ' + isVerified);
  });
  ```

### isOsAccountVerified

isOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

Checks whether an OS account has been verified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description              |
| ------- | ------ | ---- | ------------------ |
| localId | number | No  | ID of the target OS account.|

**Return value**

| Type                  | Description                                                        |
| :--------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the OS account has been verified, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified().then((isVerified) => {
    console.log('isOsAccountVerified, isVerified: ' + isVerified);
  }).catch((err) => {
    console.log("isOsAccountVerified err: "  + JSON.stringify(err));
  });
  ```

### removeOsAccount

removeOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

Removes an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| localId  | number                    | Yes  | ID of the OS account to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.          |

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var createIocalId;
  osAccountManager.createOsAccount("testAccountName", osaccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
    createIocalId = osAccountInfo.localId;
  });
  accountManager.removeOsAccount(createIocalId, (err)=>{
    console.log("removeOsAccount err:" + JSON.stringify(err));
  });
  ```

### removeOsAccount

removeOsAccount(localId: number): Promise&lt;void&gt;

Removes an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                |
| ------- | ------ | ---- | -------------------- |
| localId | number | Yes  | ID of the OS account to remove.|

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var createIocalId;
  osAccountManager.createOsAccount("testAccountName", osaccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
    createIocalId = osAccountInfo.localId;
  });
  createIocalId = osAccount.localId;
  accountManager.removeOsAccount(createIocalId).then(() => {
    console.log('removeOsAccount Success');
  }).catch(() => {
    console.log("removeOsAccount err: "  + JSON.stringify(err));
  });
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean,callback: AsyncCallback&lt;void&gt;): void

Sets or removes constraints for an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type                     | Mandatory| Description                                        |
| ----------- | ------------------------- | ---- | -------------------------------------------- |
| localId     | number                    | Yes  | ID of the target OS account.                                |
| constraints | Array&lt;string&gt;       | Yes  | List of [constraints](#constraints) to set or remove.|
| enable      | boolean                   | Yes  | Set or remove constraints. The value **true** means to set constraints, and **false** means to remove constraints.                      |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                  |

**Example**: Disable Wi-Fi for OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.setOsAccountConstraints(localId, ["constraint.wifi"], true, (err)=>{
    console.log("setOsAccountConstraints err:" + JSON.stringify(err));
  });
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean): Promise&lt;void&gt;

Sets or removes constraints for an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type               | Mandatory| Description                                        |
| ----------- | ------------------- | ---- | -------------------------------------------- |
| localId     | number              | Yes  | ID of the target OS account.                                |
| constraints | Array&lt;string&gt; | Yes  | List of [constraints](#constraints) to set or remove.|
| enable      | boolean             | Yes  | Set or remove constraints. The value **true** means to set constraints, and **false** means to remove constraints.                    |

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**: Remote the constraint on the use of Wi-Fi for OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.setOsAccountConstraints(localId, ["constraint.location.set"], false).then(() => {
    console.log('setOsAccountConstraints Success');
  }).catch((err) => {
    console.log("setOsAccountConstraints err: "  + JSON.stringify(err));
  });
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string, callback: AsyncCallback&lt;void&gt;): void

Sets a name for an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type                     | Mandatory| Description        |
| :-------- | ------------------------- | ---- | ------------ |
| localId   | number                    | Yes  | ID of the target OS account.|
| localName | string                    | Yes  | Account name to set.    |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.  |

**Example**: Set the name of OS account 100 to **demoName**.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var newName = "demoName";
  accountManager.setOsAccountName(localId, newName, (err)=>{
    console.debug("setOsAccountName err:" + JSON.stringify(err));
  });
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string): Promise&lt;void&gt;

Sets a name for an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| localId   | number | Yes  | ID of the target OS account.|
| localName | string | Yes  | Account name to set.    |

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**: Set the name of OS account 100 to **demoName**.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var nameLimit = "demoName";
  accountManager.setOsAccountName(localId, nameLimit).then(() => {
    console.log('setOsAccountName Success');
  }).catch((err) => {
    console.log("setOsAccountName err: "  + JSON.stringify(err));
  });
  ```

### getCreatedOsAccountsCount

getCreatedOsAccountsCount(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of OS accounts created. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                      |
| -------- | --------------------------- | ---- | ------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the number of OS accounts created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount((err, accountCnt)=>{
    console.log("obtains the number of all os accounts created err:" + JSON.stringify(err));
    console.log("obtains the number of all os accounts created accountCnt:" + accountCnt);
  });
  ```

### getCreatedOsAccountsCount

getCreatedOsAccountsCount(): Promise&lt;number&gt;

Obtains the number of OS accounts created. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of OS accounts created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount().then((accountCnt) => {
    console.log('getCreatedOsAccountsCount, accountCnt: ' + accountCnt);
  }).catch((err) => {
    console.log("getCreatedOsAccountsCount err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromProcess

getOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the OS account to which the current process belongs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                              |
| -------- | --------------------------- | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the account ID obtained.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess((err, accountID) => {
    console.log("getOsAccountLocalIdFromProcess err: " + JSON.stringify(err));
    console.log('getOsAccountLocalIdFromProcess accountID: ' + accountID);
  });
  ```

### getOsAccountLocalIdFromProcess

getOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

Obtains the ID of the OS account to which the current process belongs. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the account ID obtained.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess().then((accountID) => {
    console.log('getOsAccountLocalIdFromProcess, accountID: ' + accountID);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromProcess err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromUid

getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the process UID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                         |
| -------- | --------------------------- | ---- | --------------------------------------------- |
| uid      | number                      | Yes  | Process UID.                                    |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the OS account ID obtained.|

**Example**: Obtain the ID of the OS account whose process UID is **12345678**.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid, (err, accountID) => {
    console.log("getOsAccountLocalIdFromUid err: " + JSON.stringify(err));
    console.log('getOsAccountLocalIdFromUid: ' + accountID);
  });
  ```

### getOsAccountLocalIdFromUid

getOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

Obtains the OS account ID based on the process UID. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name| Type  | Mandatory| Description     |
| ------ | ------ | ---- | --------- |
| uid    | number | Yes  | Process UID.|

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Example**: Obtain the ID of the OS account whose process UID is **12345678**.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid).then((accountID) => {
    console.log('getOsAccountLocalIdFromUid: ' + accountID);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromUid err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromDomain<sup>8+</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on domain account information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                                        |
| ---------- | --------------------------------------- | ---- | -------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.                                |
| callback   | AsyncCallback&lt;number&gt;             | Yes  | Callback used to return the ID of the OS account associated with the domain account.|

**Example**

  ```js
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromDomain(domainInfo, (err, accountID) => {
    console.log("getOsAccountLocalIdFromDomain: " + JSON.stringify(err));
    console.log('getOsAccountLocalIdFromDomain: ' + accountID);
  });
  ```

### getOsAccountLocalIdFromDomain<sup>8+</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

Obtains the OS account ID based on domain account information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description        |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.|

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the ID of the OS account associated with the domain account.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  accountManager.getOsAccountLocalIdFromDomain(domainInfo).then((accountID) => {
    console.log('getOsAccountLocalIdFromDomain: ' + accountID);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromDomain err: "  + JSON.stringify(err));
  });
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum number of OS accounts that can be created. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                            |
| -------- | --------------------------- | ---- | ------------------------------------------------ |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the maximum number of OS accounts that can be created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryMaxOsAccountNumber((err, maxCnt)=>{
    console.log("queryMaxOsAccountNumber err:" + JSON.stringify(err));
    console.log("queryMaxOsAccountNumber maxCnt:" + maxCnt);
  });
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(): Promise&lt;number&gt;

Obtains the maximum number of OS accounts that can be created. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum number of OS accounts that can be created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryMaxOsAccountNumber().then((maxCnt) => {
    console.log('queryMaxOsAccountNumber, maxCnt: ' + maxCnt);
  }).catch((err) => {
    console.log("queryMaxOsAccountNumber err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountAllConstraints

getOsAccountAllConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains all constraints enabled for an OS account. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                        |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| localId  | number                                   | Yes  | ID of the target OS account.                                                |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes  | Callback used to return all [constraints](#constraints) obtained.|

**Example**: Obtain all constraints of OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountAllConstraints(localId, (err, constraints)=>{
    console.log("getOsAccountAllConstraints err:" + JSON.stringify(err));
    console.log("getOsAccountAllConstraints:" + JSON.stringify(constraints));
  });
  ```

### getOsAccountAllConstraints

getOsAccountAllConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains all constraints enabled for an OS account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                              | Description                                                        |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the [constraints](#constraints) obtained.|

**Example**: Obtain all constraints of OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountAllConstraints(localId).then((constraints) => {
    console.log("getOsAccountAllConstraints, constraints: " + constraints);
  }).catch((err) => {
    console.log("getOsAccountAllConstraints err: "  + JSON.stringify(err));
  });
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(callback: AsyncCallback&lt;Array&lt;OsAccountInfo&gt;&gt;): void

Obtains information about all the OS accounts created. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                              |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | Yes  | Callback used to return information about OS accounts created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryAllCreatedOsAccounts((err, accountArr)=>{
    console.log("queryAllCreatedOsAccounts err:" + JSON.stringify(err));
    console.log("queryAllCreatedOsAccounts accountArr:" + JSON.stringify(accountArr));
  });
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(): Promise&lt;Array&lt;OsAccountInfo&gt;&gt;

Obtains information about all the OS accounts created. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Return value**

| Type                                                       | Description                                                        |
| :---------------------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | Promise used to return information about OS accounts created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryAllCreatedOsAccounts().then((accountArr) => {
    console.log('queryAllCreatedOsAccounts, accountArr: ' + JSON.stringify(accountArr));
  }).catch((err) => {
    console.log("queryAllCreatedOsAccounts err: "  + JSON.stringify(err));
  });
  ```

### queryActivatedOsAccountIds<sup>8+</sup>

queryActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains information about all activated OS accounts. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return information about activated OS accounts.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds((err, idArray)=>{
    console.log("queryActivatedOsAccountIds err:" + JSON.stringify(err));
    console.log("queryActivatedOsAccountIds idArray length:" + idArray.length);
    for(var i=0;i<idArray.length;i++) {
      console.info("activated os account id: " + idArray[i]);
    }
  });
  ```

### queryActivatedOsAccountIds<sup>8+</sup>

queryActivatedOsAccountIds(): Promise&lt;Array&lt;number&gt;&gt;

Obtains information about all activated OS accounts. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                              | Description                                                        |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return information about activated OS accounts.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds().then((idArray) => {
    console.log('queryActivatedOsAccountIds, idArray: ' + idArray);
  }).catch((err) => {
    console.log("queryActivatedOsAccountIds err: "  + JSON.stringify(err));
  });
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Creates an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type                                                | Mandatory| Description                                      |
| :-------- | ---------------------------------------------------- | ---- | ------------------------------------------ |
| localName | string                                               | Yes  | Name of the OS account to create.                    |
| type      | [OsAccountType](#osaccounttype)                      | Yes  | Type of the OS account to create.                    |
| callback  | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback used to return the OS account created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.createOsAccount("testName", osaccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
    console.log("createOsAccount err:" + JSON.stringify(err));
    console.log("createOsAccount osAccountInfo:" + JSON.stringify(osAccountInfo));
  });
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType): Promise&lt;OsAccountInfo&gt;

Creates an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type                           | Mandatory| Description                  |
| --------- | ------------------------------- | ---- | ---------------------- |
| localName | string                          | Yes  | Name of the OS account to create.|
| type      | [OsAccountType](#osaccounttype) | Yes  | Type of the OS account to create.|

**Return value**

| Type                                          | Description                                                        |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the OS account created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.createOsAccount("testAccountName", osaccount.OsAccountType.NORMAL).then((accountInfo) => {
    console.log("createOsAccount, accountInfo: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("createOsAccount err: "  + JSON.stringify(err));
  });
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Creates an OS account and associates it with the specified domain account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                                | Mandatory| Description                                      |
| :--------- | ---------------------------------------------------- | ---- | ------------------------------------------ |
| type       | [OsAccountType](#osaccounttype)                      | Yes  | Type of the OS account to create.                    |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8)              | Yes  | Domain account information.                              |
| callback   | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback used to return the OS account created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  accountManager.createOsAccountForDomain(osaccount.OsAccountType.NORMAL, domainInfo, (err, osAccountInfo)=>{
    console.log("createOsAccountForDomain err:" + JSON.stringify(err));
    console.log("createOsAccountForDomain osAccountInfo:" + JSON.stringify(osAccountInfo));
  });
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;

Creates an OS account and associates it with the specified domain account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                  |
| ---------- | --------------------------------------- | ---- | ---------------------- |
| type       | [OsAccountType](#osaccounttype)         | Yes  | Type of the OS account to create.|
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.          |

**Return value**

| Type                                          | Description                                                        |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the OS account created.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var domainInfo = {domain: "testDomain", accountName: "testAccountName"};
  accountManager.createOsAccountForDomain(osaccount.OsAccountType.NORMAL, domainInfo).then((accountInfo) => {
    console.log("createOsAccountForDomain, account info: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("createOsAccountForDomain err: "  + JSON.stringify(err));
  });
  ```

### queryCurrentOsAccount

queryCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Obtains information about the OS account to which the current process belongs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback used to return information about the OS account obtained.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount((err, curAccountInfo)=>{
    console.log("queryCurrentOsAccount err:" + JSON.stringify(err));
    console.log("queryCurrentOsAccount curAccountInfo:" + JSON.stringify(curAccountInfo));
  });
  ```

### queryCurrentOsAccount

queryCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

Obtains information about the OS account to which the current process belongs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                                        |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return information about the OS account obtained.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount().then((accountInfo) => {
    console.log("queryCurrentOsAccount, accountInfo: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("queryCurrentOsAccount err: "  + JSON.stringify(err));
  });
  ```

### queryOsAccountById

queryOsAccountById(localId: number, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Obtains information about an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                    |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------- |
| localId  | number                                               | Yes  | ID of the target OS account.                    |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback used to return the OS account information obtained.|

**Example**: Query information about OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.queryOsAccountById(localId, (err, accountInfo)=>{
    console.log("queryOsAccountById err:" + JSON.stringify(err));
    console.log("queryOsAccountById accountInfo:" + JSON.stringify(accountInfo));
  });
  ```

### queryOsAccountById

queryOsAccountById(localId: number): Promise&lt;OsAccountInfo&gt;

Obtains information about an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                |
| ------- | ------ | ---- | -------------------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                                          | Description                                                        |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the OS account information obtained.|

**Example**: Query information about OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.queryOsAccountById(localId).then((accountInfo) => {
    console.log("queryOsAccountById, accountInfo: " + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log("queryOsAccountById err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountTypeFromProcess

getOsAccountTypeFromProcess(callback: AsyncCallback&lt;OsAccountType&gt;): void

Obtains the type of the OS account to which the current process belongs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | Yes  | Callback used to return the OS account type.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess((err, accountType) => {
    console.log("getOsAccountTypeFromProcess err: " + JSON.stringify(err));
    console.log('getOsAccountTypeFromProcess accountType: ' + accountType);
  });
  ```

### getOsAccountTypeFromProcess

getOsAccountTypeFromProcess(): Promise&lt;OsAccountType&gt;

Obtains the type of the OS account to which the current process belongs. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                                        |
| :--------------------------------------------- | :----------------------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise used to return the OS account type.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess().then((accountType) => {
    console.log('getOsAccountTypeFromProcess, accountType: ' + accountType);
  }).catch((err) => {
    console.log("getOsAccountTypeFromProcess err: "  + JSON.stringify(err));
  });
  ```

### getDistributedVirtualDeviceId

getDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

Obtains the ID of this distributed virtual device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                |
| -------- | --------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the device ID obtained.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId((err, virtualID) => {
    console.log("getDistributedVirtualDeviceId err: " + JSON.stringify(err));
    console.log('getDistributedVirtualDeviceId virtualID: ' + virtualID);
  });
  ```

### getDistributedVirtualDeviceId

getDistributedVirtualDeviceId(): Promise&lt;string&gt;

Obtains the ID of this distributed virtual device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the device ID obtained.|

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId().then((virtualID) => {
    console.log('getDistributedVirtualDeviceId, virtualID: ' + virtualID);
  }).catch((err) => {
    console.log("getDistributedVirtualDeviceId err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the profile photo of an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                    |
| -------- | --------------------------- | ---- | ---------------------------------------- |
| localId  | number                      | Yes  | ID of the target OS account.                            |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the profile photo obtained.|

**Example**: Obtain the profile photo of OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountProfilePhoto(localId, (err, photo)=>{
    console.log("getOsAccountProfilePhoto err:" + JSON.stringify(err));
    console.log("get photo:" + photo + " by localId: " + localId);
  });
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number): Promise&lt;string&gt;

Obtains the profile photo of an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the profile photo obtained.|

**Example**: Obtain the profile photo of OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getOsAccountProfilePhoto(localId).then((photo) => {
    console.log("getOsAccountProfilePhoto: " + photo);
  }).catch((err) => {
    console.log("getOsAccountProfilePhoto err: "  + JSON.stringify(err));
  });
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback&lt;void&gt;): void

Sets a profile photo for an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                     | Mandatory| Description        |
| -------- | ------------------------- | ---- | ------------ |
| localId  | number                    | Yes  | ID of the target OS account.|
| photo    | string                    | Yes  | Profile photo information.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.  |

**Example**: Set a profile photo for OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var photo = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA"+
  "Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y"+
  "q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo"+
  "+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=="
  osAccountManager.setOsAccountProfilePhoto(localId, photo, (err)=>{
    console.log("setOsAccountProfilePhoto err:" + JSON.stringify(err));
  });
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string): Promise&lt;void&gt;

Sets a profile photo for an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|
| photo   | string | Yes  | Profile photo information.  |

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**: Set a profile photo for OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  var photo = "data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA"+
  "Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y"+
  "q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo"+
  "+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=="
  accountManager.setOsAccountProfilePhoto(localId, photo).then(() => {
    console.log("setOsAccountProfilePhoto success");
  }).catch((err) => {
    console.log("setOsAccountProfilePhoto err: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>8+</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the SN. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type                       | Mandatory| Description                                            |
| ------------ | --------------------------- | ---- | ------------------------------------------------ |
| serialNumber | number                      | Yes  | Account SN.                                      |
| callback     | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the OS account ID obtained.|

**Example**: Obtain the ID of the OS account whose SN is **12345**.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber, (err, localId)=>{
    console.log("ger localId err:" + JSON.stringify(err));
    console.log("get localId:" + localId + " by serialNumber: " + serialNumber);
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>8+</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

Obtains the OS account ID based on the SN. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type  | Mandatory| Description      |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | Yes  | Account SN.|

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Example**: Obtain the ID of the OS account whose SN is **12345**.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber).then((localId) => {
    console.log("getOsAccountLocalIdBySerialNumber localId: " + localId);
  }).catch((err) => {
    console.log("getOsAccountLocalIdBySerialNumber err: "  + JSON.stringify(err));
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>8+</sup>

getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the SN of an OS account based on the account ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                      |
| -------- | --------------------------- | ---- | ------------------------------------------ |
| localId  | number                      | Yes  | ID of the target OS account.                              |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the account SN obtained.|

**Example**: Obtain the SN of OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId, (err, serialNumber)=>{
    console.log("ger serialNumber err:" + JSON.stringify(err));
    console.log("get serialNumber:" + serialNumber + " by localId: " + localId);
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>8+</sup>

getSerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

Obtains the SN of an OS account based on the account ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the account SN obtained.|

**Example**: Obtain the SN of OS account 100.

  ```js
  const accountManager = account_osAccount.getAccountManager();
  var localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId).then((serialNumber) => {
    console.log("getSerialNumberByOsAccountLocalId serialNumber: " + serialNumber);
  }).catch((err) => {
    console.log("getSerialNumberByOsAccountLocalId err: "  + JSON.stringify(err));
  });
  ```

### on

on(type: 'activate' | 'activating', name: string, callback: Callback&lt;number&gt;): void

Subscribes to OS account changes. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | Yes  | Type of the event to subscribe to. The value **activate** means an event indicating that an OS account is activated, and **activating** means an event indicating that an OS account is being activated.|
| name     | string                     | Yes  | Subscription name, which can be customized. The value cannot be empty or exceed 1024 bytes.          |
| callback | Callback&lt;number&gt;     | Yes  | Callback used to return the OS account ID and status changes.  |

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  function onCallback(receiveLocalId){
    console.log("receive localId:" + receiveLocalId);
  }
  accountManager.on("activating", "osAccountOnOffNameA", onCallback);
  ```

### off

off(type: 'activate' | 'activating', name: string, callback?: Callback&lt;number&gt;): void

Unsubscribes from the OS account changes. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | Yes  | Type of the event to unsubscribe from. The value **activate** means an event indicating that an OS account is activated, and **activating** means an event indicating that an OS account is being activated.|
| name     | string                     | Yes  | Subscription name, which can be customized. The value cannot be empty or exceed 1024 bytes, and must be the same as the value passed by **on()**.|
| callback | Callback&lt;number&gt;     | No  | Callback used to return the OS account changes. By default, **0** is returned.                     |

**Example**

  ```js
  const accountManager = account_osAccount.getAccountManager();
  function offCallback(){
    console.log("off enter")
  }
  accountManager.off("activating", "osAccountOnOffNameA", offCallback);
  ```

### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void;

Obtains the bundle ID based on the UID. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| uid     | number | Yes  |  Process UID.|
| callback | AsyncCallback&lt;number&gt;     | Yes  | Callback invoked to return the bundle ID obtained.                     |

**Example**

  ```js
  var testUid = 1000000;
  osAccountManager.getBundleIdFromUid(testUid,(err,bundleId)=>{
    console.info("getBundleIdFromUid errInfo:" + JSON.stringify(err));
    console.info("getBundleIdFromUid bundleId:" + JSON.stringify(bundleId));
  });
  ```
### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number): Promise&lt;number&gt;;

Obtains the bundle ID based on the UID. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| uid     | number | Yes  |  Process UID.|

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the bundle ID obtained.|

**Example**

  ```js
  var testUid = 1000000;
  var bundleIdInfo = await osAccountManager.getBundleIdFromUid(testUid).catch((err)=>{
    console.info("getBundleIdFromUid errInfo:" + JSON.stringify(err));})
  console.info("getBundleIdFromUid bundleId:" + JSON.stringify(bundleIdInfo));
  ```

### isMainOsAccount<sup>9+</sup>

isMainOsAccount(callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether the current process belongs to the main OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt;     | Yes  | Callback used to return the result. If the current process belongs to the main OS account, **true** will be returned. Otherwise, **false** will be returned.                     |

**Example**

  ```js
  osAccountManager.isMainOsAccount((err,result)=>{
    console.info("isMainOsAccount errInfo:" + JSON.stringify(err));
    console.info("isMainOsAccount result:" + JSON.stringify(result));
  });
  ```
### isMainOsAccount<sup>9+</sup>

isMainOsAccount(): Promise&lt;boolean&gt;;

Checks whether the current process belongs to the main OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the current process belongs to the main OS account, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

  ```js
  var result = await osAccountManager.isMainOsAccount().catch((err)=>{
    console.info("isMainOsAccount errInfo:" + JSON.stringify(err));
  });
  console.info("isMainOsAccount result:" + JSON.stringify(result));
  ```
### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;): void;

Obtains the constraint source information of an OS account. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| localId     | number | Yes  |  ID of the target OS account.|
| constraint     | string | Yes  |  Name of the [constraint](#constraints) to query.|
| callback | AsyncCallback&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt;     | Yes  | Callback invoked to return the source information about the specified [constraint](#constraints).                     |

**Example**

  ```js
  osAccountManager.queryOsAccountConstraintSourceTypes(100, "constraint.wifi",(err,sourceTypeInfos)=>{
    console.info("queryOsAccountConstraintSourceType errInfo:" + JSON.stringify(err));
    console.info("queryOsAccountConstraintSourceType sourceTypeInfos:" + JSON.stringify(sourceTypeInfos));
  });
  ```

### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;;

Obtains the constraint source information of an OS account. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId     | number | Yes  |  ID of the target OS account.|
| constraint     | string | Yes  |  Name of the [constraint](#constraints) to query.|

**Return value**

| Type                 | Description                                                        |
| :-------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt; | Promise used to return the source information about the specified [constraint](#constraints).|

**Example**

  ```js
  var sourceTypeInfos = await osAccountManager.queryOsAccountConstraintSourceTypes(100, "constraint.wifi").catch((err)=>{
    console.info("queryOsAccountConstraintSourceType errInfo:" + JSON.stringify(err));})
  console.info("queryOsAccountConstraintSourceType sourceTypeInfos:" + JSON.stringify(sourceTypeInfos));
  ```

## UserAuth<sup>8+</sup>

Provides APIs for user authentication.

### constructor<sup>8+</sup>

constructor()

A constructor used to create an instance for user authentication.

**System capability**: SystemCapability.Account.OsAccount

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  console.info('====>test for examples constructor success');
  ```


### getVersion<sup>8+</sup>

getVersion(): number;

Obtains version information.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type  | Description        |
| :----- | :----------- |
| number | Version information obtained.|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  console.info('====>test for examples constructor success');
  var version = userAuth.getVersion();
  console.info('====>test for examples version is : ' + JSON.stringify(version));
  ```

### getAvailableStatus<sup>8+</sup>

getAvailableStatus(authType: AuthType, authTrustLevel: AuthTrustLevel): number;

Checks whether the identity authentication function is available.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name          | Type                                          | Mandatory| Description                      |
| --------------- | -----------------------------------------------| ---- | ------------------------- |
| authType        | [AuthType](#AuthType<sup>8+</sup>)             | Yes  | Authentication credential type.    |
| authTrustLevel  | [AuthTrustLevel](#AuthTrustLevel<sup>8+</sup>) | Yes  | Trust level of the authentication result.|

**Return value**

| Type  | Description                                      |
| :----- | :---------------------------------------- |
| number | Result code(#ResultCode<sup>8+</sup>).| 

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let authTrustLevel = osAccount.AuthTrustLevel.ATL1;
  console.info('====>test for examples constructor success');
  let availableStatus = userAuth.getAvailableStatus(authType, authTrustLevel);
  console.info('====>test for examples AvailabeStatus is : ' + JSON.stringify(availableStatus));
  ```

### getProperty<sup>8+</sup>

getProperty(request: GetPropertyRequest, callback: AsyncCallback&lt;ExecutorProperty&gt;): void;

Obtains the executor property based on the request. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                                                   | Mandatory| Description                               |
| -------- | ----------------------------------------------------------------------- | ---- | ---------------------------------- |
| request  | [GetPropertyRequest](#GetPropertyRequest<sup>8+</sup>)                  | Yes  | Request information, including the authentication credential type and property list.|
| callback | AsyncCallback&lt;[ExecutorProperty](#ExecutorProperty<sup>8+</sup>)&gt; | Yes  | Callback invoked to return the executor property obtained.       |

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let keys = new Array();
  keys[0] = osAccount.GetPropertyType.AUTH_SUB_TYPE;
  keys[1] = osAccount.GetPropertyType.REMAIN_TIMES;
  keys[2] = osAccount.GetPropertyType.FREEZING_TIME;
  let getPropertyRequest = {authType, keys};
  userAuth.getProperty(getPropertyRequest,function (propReq) {
      console.log("====>test for examples getallAuthInfo AsyncCallback = " + JSON.stringify(propReq));
  })
  ```

### getProperty<sup>8+</sup>

getProperty(request: GetPropertyRequest): Promise<ExecutorProperty>;

Obtains the executor property based on the request. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                                  | Mandatory| Description                               |
| -------- | ------------------------------------------------------ | ---- | ---------------------------------- |
| request  | [GetPropertyRequest](#GetPropertyRequest<sup>8+</sup>) | Yes  | Request information, including the authentication credential type and property list.|

**Return value**

| Type                                                             | Description                                                |
| :---------------------------------------------------------------- | :-------------------------------------------------- |
| Promise&lt;[ExecutorProperty](#ExecutorProperty<sup>8+</sup>)&gt; | Promise used to return the executor property obtained.|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let keys = new Array();
  keys[0] = osAccount.GetPropertyType.AUTH_SUB_TYPE;
  keys[1] = osAccount.GetPropertyType.REMAIN_TIMES;
  keys[2] = osAccount.GetPropertyType.FREEZING_TIME;
  let getPropertyRequest = {authType, keys};
  userAuth.getProperty(getPropertyRequest).then((propReq) => {
      console.log("====>test for examples getallAuthInfo AsyncCallback = " + JSON.stringify(propReq));
  });
  ```

### setProperty<sup>8+</sup>

setProperty(request: SetPropertyRequest, callback: AsyncCallback<number>): void;

Sets the property for the initialization algorithm. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                                 | Mandatory| Description                                                                   |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------------------------- |
| request  | [SetPropertyRequest](#SetPropertyRequest<sup>8+</sup>)| Yes  | Request information, including the authentication credential type and key value to set.                                  |
| callback | AsyncCallback&lt;number&gt;                           | Yes  | Callback invoked to return the [result code](#ResultCode<sup>8+</sup>).|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let key = osAccount.SetPropertyType.INIT_ALGORITHM;
  let setInfo = new Uint8Array();
  let setPropertyRequest = {authType, key, setInfo};
  userAuth.setProperty(setPropertyRequest,function (setProp) {
      console.log("====>test for examples setProperty AsyncCallback = " + JSON.stringify(setProp));
  });
  ```

### setProperty<sup>8+</sup>

setProperty(request: SetPropertyRequest): Promise<number>;

Sets the property for the initialization algorithm. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                                  | Mandatory| Description                                     |
| -------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| request  | [SetPropertyRequest](#SetPropertyRequest<sup>8+</sup>) | Yes  | Request information, including the authentication credential type and the key value to set.|

**Return value**

| Type                 | Description                                                                                          |
| :-------------------- | :-------------------------------------------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the [result code](#ResultCode<sup>8+</sup>).|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let key = osAccount.SetPropertyType.INIT_ALGORITHM;
  let setInfo = new Uint8Array();
  let setPropertyRequest = {authType, key, setInfo};
  userAuth.setProperty(setPropertyRequest).then((setProp) => {
      console.log("====>test for examples setProperty AsyncCallback = " + JSON.stringify(setProp));
  });
  ```

### auth<sup>8+</sup>

auth(challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;

Performs authentication. This API uses a callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name          | Type                                                | Mandatory| Description                               |
| --------------- | ---------------------------------------------------- | --- | ------------------------------------ |
| challenge       | Uint8Array                                           | Yes | Challenge value, which is a random number used to improve security.|
| authType        | [AuthType](#AuthType<sup>8+</sup>)                   | Yes | Authentication credential type.                       |
| authTrustLevel  | [AuthTrustLevel](#AuthTrustLevel<sup>8+</sup>)       | Yes | Trust level of the authentication result.              |
| callback        | [IUserAuthCallback](#IUserAuthCallback<sup>8+</sup>) | Yes | Callback invoked to return the authentication result and obtained information. |


**Return value**

| Type       | Description              |
| :--------- | :----------------- |
| Uint8Array | ID of the context for canceling the authentication.|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let challenge = 1;
  let authTrustLevel = osAccount.AuthTrustLevel.ATL1;
  let onresult = {
      authresult: null,
      authextr: null,
  }
  userAuth.auth(challenge, authType,authTrustLevel,{
      onResult: function(result,extraInfo){
          console.log("====>test for examples auth result = " + result);
          onresult.authresult = result;
          console.log("====>test for examples auth extraInfo = " + JSON.stringify(extraInfo));
          onresult.authextr = extraInfo;
          console.info('====>test for examples auth onResult = ' + JSON.stringify(onresult));
      }
  });
  ```

### authUser<sup>8+</sup>

authUser(userId: number, challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;

Perform user authentication. This API uses a callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name          | Type                                                | Mandatory| Description                               |
| --------------- | ---------------------------------------------------- | --- | ------------------------------------ |
| userId          | number                                               | Yes | User ID.                       |
| challenge       | Uint8Array                                           | Yes | Challenge value, which is a random number used to improve security.                         |
| authType        | [AuthType](#AuthType<sup>8+</sup>)                   | Yes | Authentication credential type.                       |
| authTrustLevel  | [AuthTrustLevel](#AuthTrustLevel<sup>8+</sup>)       | Yes | Trust level of the authentication result.              |
| callback        | [IUserAuthCallback](#IUserAuthCallback<sup>8+</sup>) | Yes | Callback invoked to return the authentication result and obtained information. |


**Return value**

| Type       | Description              |
| :--------- | :----------------- |
| Uint8Array | ID of the context for canceling the authentication.|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let challenge = 1;
  let authTrustLevel = osAccount.AuthTrustLevel.ATL1;
  let userID = 100;
  let onresult = {
      authresult: null,
      authextr: null,
  }
  userAuth.authUser(userID, challenge, authType, authTrustLevel, {
      onResult: function(result,extraInfo){
          console.log("====>test for examples authUser result = " + result);
          onresult.authresult = result;
          console.log("====>test for examples authUser extraInfo = " + JSON.stringify(extraInfo));
          onresult.authextr = extraInfo;
          console.info('====>test for examples authUser onResult = ' + JSON.stringify(onresult));
      }
  });
  ```

### cancelAuth<sup>8+</sup>

cancelAuth(contextID: Uint8Array): number;

Cancels authentication.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type      | Mandatory | Description                                       |
| ----------| ---------- | ---- | ------------------------------------------ |
| contextID | Uint8Array | Yes  | ID of the authentication context. The context ID is dynamically generated.|

**Return value**

| Type  | Description                                                      |
| :----- | :-------------------------------------------------------- |
| number | [Result code](#ResultCode<sup>8+</sup>).|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let contextID = null;
  let cancelAuthresult = null;
  cancelAuthresult = userAuth.cancelAuth(contextID);
  console.log("====>test for examples cancelAuthresult result = " + JSON.stringify(cancelAuthresult));
  ```

## PINAuth<sup>8+</sup>

Provides methods for PIN authentication.

### constructor<sup>8+</sup>

constructor()

A constructor used to create an instance for PIN authentication.

**System capability**: SystemCapability.Account.OsAccount

**Example**
  ```js
  var pinAuth = new osAccount.PINAuth();
  console.info('====>test for examples constructor success');
  ```

### registerInputer

registerInputer(inputer: IInputer): boolean;

Registers an inputer.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_PIN_AUTH

**Parameters**

| Name   | Type                                | Mandatory| Description              |
| ----------| ----------------------------------- | --- | ------------------ |
| inputer   | [IInputer](#IInputer<sup>8+</sup>)  | Yes | Callback invoked to obtain the PIN.|

**Return value**

| Type   | Description                                          |
| :------ | :-------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**
  ```js
  var pinAuth = new osAccount.PINAuth();
  var GetAuthSubType = 0;
  var AuthSubType = osAccount.AuthSubType.PIN_SIX;
  var Inputerdata = [0,1,3];
  var registerresult = pinAuth.registerInputer({
      onGetData: (GetAuthSubType, IInputData) => {
          if (GetAuthSubType == 0) {
              IInputData.onSetData(AuthSubType, Inputerdata)
          } else {
              IInputData.onSetData(GetAuthSubType, Inputerdata);
          }
      }
  })
  console.log("====>test for examples RegisterInputer result is: " + registerresult);
  ```

### unregisterInputer

unregisterInputer(): void;

Unregisters the inputer.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_PIN_AUTH

**Example**
  ```js
  var pinAuth = new osAccount.PinAuth();
  pinAuth.unregisterInputer();
  ```

## UserIdentityManager<sup>8+</sup>

Provides methods for user identity management.

### constructor<sup>8+</sup>

constructor()

A constructor used to create an instance for user authentication.

**System capability**: SystemCapability.Account.OsAccount

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  console.info('====>test for examples constructor success');
  ```

### openSession<sup>8+</sup>

openSession(callback: AsyncCallback&lt;Uint8Array&gt;): void;

Opens a session to start identity management (IDM) so that a challenge value can be obtained. This API uses an asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type                            | Mandatory| Description                             |
| -------- | -------------------------------- | ---- | -------------------------------- |
| callback | AsyncCallback&lt;Uint8Array&gt;  | Yes  | Callback invoked to return the result. If **0** is returned, the operation failed. If the operation is successful, the challenge value (a non-zero value) will be returned.|

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  var challenge;
  userIDM.openSession(function(err, data){
      try{
          console.log("====>test for examples before get challenge");
          console.log("====>test for examples + " + data);
          challenge = data;
          console.log("====>test for examples end ");
          console.log("====>test for examples after get challenge");
      }
      catch(e) {
          console.info('====>test for examples openSession error = ' + JSON.stringify(e));
      }
  });
  ```

### openSession<sup>8+</sup>

openSession(): Promise&lt;Uint8Array&gt;;

Opens a session to start IDM so that a challenge value can be obtained. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Return value**

| Type                     | Description                                                     |
| :------------------------ | :------------------------------------------------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the result. If **0** is returned, the operation failed. If the operation is successful, the challenge value (a non-zero value) will be returned.|

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  var challenge;
  userIDM.openSession().then((data) => {
      try{
          console.log("====>test for examples before get challenge");
          console.log("====>test for examples + " + data);
          challenge = data;
          console.log("====>test for examples end ");
          console.log("====>test for examples after get challenge");
      }
      catch(err) {
          console.info('====>test for examples faceDemo openSession error1 = ' + JSON.stringify(err));
      }
  })
  .catch((err) => {
      console.info('====>test for examples faceDemo openSession error2 = ' + JSON.stringify(err));
  })
  ```

### addCredential<sup>8+</sup>

addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;

Adds credential information, which includes the authentication credential type, subtype, and token (if a non-PIN credential is added). This API uses a callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name          | Type                                            | Mandatory| Description                           |
| --------------- | ------------------------------------------------ | --- | -------------------------------- |
| credentialInfo  | [CredentialInfo](#CredentialInfo<sup>8+</sup>)   | Yes | Credential information to add.                     |
| callback        | [IIdmCallback](#IIdmCallback<sup>8+</sup>)       | Yes | Callback invoked to return the result and obtained information. |

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  let CredentialInfo = null;
  let onresult = {
      addCredresult: null,
      credentialId: null,
  }
  userIDM.addCredential(CredentialInfo, {
      onResult: function(result,extraInfo){
          console.info('====>test for examples aaaaaaaaaaaaa');
          console.info("====>test for examples addCredential result = " + result);
          console.info("====>test for examples addCredential extraInfo = " + JSON.stringify(extraInfo));
          console.log(result)
          onresult.addCredresult= result;
          if(extraInfo != undefined) {
              onresult.credentialId = extraInfo.credentialId
          } else {
              onresult.credentialId = null;
          }
      }
  })
  ```

### updateCredential<sup>8+</sup>

updateCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;

Updates credential information. This API uses a callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name          | Type                                             | Mandatory| Description                           |
| --------------- | ------------------------------------------------- | --- | -------------------------------- |
| credentialInfo  | [CredentialInfo](#CredentialInfo<sup>8+</sup>)    | Yes | New credential information.                   |
| callback        | [IIdmCallback](#IIdmCallback<sup>8+</sup>)        | Yes | Callback invoked to return the result and obtained information. |

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  let CredentialInfo = null;
  let onresult = {
      addCredresult: null,
      credentialId: null,
  }
  userIDM.updateCredential(CredentialInfo, {
      onResult: function(result,extraInfo){
          console.log("====>test for examples faceDemo updateCredential result = " + result)
          onresult.updateCredresult = result
          console.log("====>test for examples faceDemo updateCredential credentialId = " + extraInfo.credentialId)
          if(extraInfo != undefined) {
              onresult.CredentialId = extraInfo.credentialId
          } else {
              onresult.CredentialId = null;
          }
          console.info('====>test for examples publicupdateCred updateCredential  onResult = ' + JSON.stringify(onresult));
      }
  })
  ```

### closeSession<sup>8+</sup>

closeSession(): void;

Closes this session to terminate IDM.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  userIDM.closeSession();
  ```

### cancel<sup>8+</sup>

cancel(challenge: Uint8Array): number;

Cancels an entry based on the challenge value.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type       | Mandatory| Description  |
| -------- | ----------- | ---- | ----- |
| challenge | Uint8Array | Yes  | Challenge value.|

**Return value**

| Type  | Description                                                      |
| :----- | :-------------------------------------------------------- |
| number | [Result code](#ResultCode<sup>8+</sup>).|

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  let challenge = 1;
  let cancelresult = userIDM.cancel(challenge);
  ```

### delUser<sup>8+</sup>

delUser(token: Uint8Array, callback: IIdmCallback): void;

Deletes a user based on the authentication token. The API uses a callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type                                      | Mandatory| Description                     |
| -------- | ------------------------------------------ | --- | ------------------------- |
| token    | Uint8Array                                 | Yes | Authentication token.            |
| callback | [IIdmCallback](#IIdmCallback<sup>8+</sup>) | Yes | Callback invoked to return the result.|

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  let onresult = {
      delUserresult: null,
      CredentialId: null,
  }
  let token = null;
  userIDM.delUser(token, {
      onResult: function(result,extraInfo){
          console.log("====>test for examples  delUser result = " + result)
          onresult.delUserresult = result
          if(extraInfo != undefined) {
              onresult.CredentialId = extraInfo.credentialId
          } else {
              onresult.CredentialId = null;
          }
          console.info('====>test for examples publicdelUser delUser = ' + JSON.stringify(onresult));
      }
  })
  ```

### delCred<sup>8+</sup>

delCred(credentialId: Uint8Array, token: Uint8Array, callback: IIdmCallback): void;

Deletes user credential information. The API uses a callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name          | Type                                           | Mandatory| Description                     |
| --------------- | ----------------------------------------------- | --- | ---------------------------|
| credentialId    | Uint8Array                                      | Yes | Credential ID.                 |
| token           | Uint8Array                                      | Yes | Authentication token.             |
| callback        | [IIdmCallback](#IIdmCallback<sup>8+</sup>)      | Yes | Callback invoked to return the result.|

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  let onresult = {
      delUserresult: null,
      CredentialId: null,
  }
  let credentialId = 1;
  let token = null;
  userIDM.delCred(credentialId, token,{
      onResult: function(result,extraInfo){
          console.log("====>test for examples delCred result = " + result)
          onresult.delCredresult = result
          console.log("====>test for examples delCred extraInfo = " + extraInfo)
          if(extraInfo != undefined) {
              onresult.CredentialId = extraInfo.credentialId
          } else {
              onresult.CredentialId = null;
          }
          console.log("====>test for examples delCred onresult = " + JSON.stringify(onresult));
      }
  })
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;, authType?: AuthType): void;

Obtains authentication information. This API uses asynchronous callback to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type                                              | Mandatory| Description                                               |
| -------- | -------------------------------------------------- | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[EnrolledCredInfo](#EnrolledCredInfo<sup>8+</sup>)&gt;&gt; | Yes  | Callback invoked to return information about all enrolled credentials of the specified type of the user.|
| authType | [AuthType](#AuthType<sup>8+</sup>) | No  | Authentication credential type.                                         |

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  var authType = osAccount.AuthType.PIN;
  userIDM.getAuthInfo(authType, function (authInfo) {
      console.log("====>test for examples getAuthInfo AsyncCallback = " + JSON.stringify(authInfo))
  })
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(authType?: AuthType): Promise&lt;Array&lt;EnrolledCredInfo&gt;&gt;;

Obtains authentication information. This API uses a promise to return the result.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type                               | Mandatory| Description     |
| -------- | ----------------------------------- | ---- | -------- |
| authType | [AuthType](#AuthType<sup>8+</sup>)  | No  | Authentication credential type.|

**Return value**

| Type                                        | Description                                                                      |
| :------------------------------------------- | :------------------------------------------------------------------------ |
| Promise&lt;Array&lt;[EnrolledCredInfo](#EnrolledCredInfo<sup>8+</sup>)&gt;&gt; | Promise used to return information about all enrolled credentials of the specified type of the user.|

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  var authType = osAccount.AuthType.PIN;
  userIDM.getAuthInfo(authType).then((authInfo) => {
      console.log("====>test for examples getAuthInfo AsyncCallback = " + JSON.stringify(authInfo))
  })
  ```

## IInputData<sup>8+</sup>

Provides callbacks for PIN operations.

### onSetData<sup>8+</sup>

onSetData: (pinSubType: AuthSubType, data: Uint8Array) => void;

Called to set data.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type                                    | Mandatory| Description                                           |
| ---------- | ---------------------------------------- | ---- | ----------------------------------------------- |
| pinSubType | [AuthSubType](#AuthSubType<sup>8+</sup>) | Yes  | Credential subtype.                           |
| data       | Uint8Array                               | Yes  | Data (credential) to set. The data is used for authentication and operations for adding and modifying credentials.|

**Example**
  ```js
  console.log("====>test for examples onCreate start ");
  var pinAuth = new osAccount.PINAuth();
  var GetAuthSubType = 0;
  var AuthSubType = osAccount.AuthSubType.PIN_SIX;
  console.log("====>test for examples GetAuthSubType " + GetAuthSubType);
  console.log("====>test for examples AuthSubType " + AuthSubType);
  var Inputerdata = [0,1,3];
  var registerresult = pinAuth.registerInputer({
      onGetData: (GetAuthSubType, IInputData) => {
          console.log("====>test for examples by GetAuthSubType " +GetAuthSubType );
          if (GetAuthSubType == 0) {
              console.log("====>test for examples GetAuthSubType == 0 ");
              IInputData.onSetData(AuthSubType, Inputerdata)
          } else {
              console.log("====>test for examples GetAuthSubType == 1 ");
              IInputData.onSetData(GetAuthSubType, Inputerdata);
          }
      }
  })
  console.log("====>test for examples RegisterInputer result is: " + registerresult);
  ```

## IInputer<sup>8+</sup>

Provides callbacks for the PIN input box.

### onGetData<sup>8+</sup>

onGetData: (callback: IInputData) => void;

Called to obtain data.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type                                   | Mandatory| Description            |
| ---------- | --------------------------------------- | ---- | --------------- |
| callback   | [IInputData](#IInputData<sup>8+</sup>)  | Yes  | Called to input the PIN.|

**Example**
  ```js
  console.log("====>test for examples onCreate start ");
  var pinAuth = new osAccount.PINAuth();
  var GetAuthSubType = 0;
  var AuthSubType = osAccount.AuthSubType.PIN_SIX;
  console.log("====>test for examples GetAuthSubType " + GetAuthSubType);
  console.log("====>test for examples AuthSubType " + AuthSubType);
  var Inputerdata = [0,1,3];
  var registerresult = pinAuth.registerInputer({
      onGetData: (GetAuthSubType, IInputData) => {
          console.log("====>test for examples by GetAuthSubType " +GetAuthSubType );
          if (GetAuthSubType == 0) {
              console.log("====>test for examples GetAuthSubType == 0 ");
              IInputData.onSetData(AuthSubType, Inputerdata)
          } else {
              console.log("====>test for examples GetAuthSubType == 1 ");
              IInputData.onSetData(GetAuthSubType, Inputerdata);
          }
      }
  })
  console.log("====>test for examples RegisterInputer result is: " + registerresult);
  ```

## IUserAuthCallback<sup>8+</sup>

Provides callbacks for user authentication.

### onResult<sup>8+</sup>

onResult: (result: number, extraInfo: AuthResult) => void;

Called to return the authentication result code.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                |
| --------- | --------------------------------------- | ---- | ------------------- |
| result    | number                                   | Yes  | Authentication result code.|
| extraInfo | [AuthResult](#AuthResult<sup>8+</sup>)  | Yes  | Specific authentication result information. If the authentication is successful, the authentication token is returned in **extrainfo**. If the authentication fails, the remaining authentication time is returned. If the authentication executor is locked, the freezing time is returned.|

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let challenge = 1;
  let authTrustLevel = osAccount.AuthTrustLevel.ATL1;
  let onresult = {
      authresult: null,
      authextr: null,
  }
  userAuth.auth(challenge, authType,authTrustLevel,{
      onResult: function(result,extraInfo){
          console.log("====>test for examples auth result = " + result);
          onresult.authresult = result;
          console.log("====>test for examples auth extraInfo = " + JSON.stringify(extraInfo));
          onresult.authextr = extraInfo;
          console.info('====>test for examples auth onResult = ' + JSON.stringify(onresult));
      }
  });
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;

Called to return the **TipsCode** during the authentication process.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type    | Mandatory| Description                          |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | Yes  | Type of authentication executor.  |
| acquire   | number  | Yes  | Tip code of the authentication executor.|
| extraInfo | any     | Yes  | Reserved.                    |

**Example**
  ```js
  let userAuth = new osAccount.UserAuth();
  let authType = osAccount.AuthType.PIN;
  let challenge = 1;
  let authTrustLevel = osAccount.AuthTrustLevel.ATL1;
  let onresult = {
      authresult: null,
      authextr: null,
  }
  let onacquireinfo = {
      authmodule : null,
      authacquire : null,
      authextr : null
  }
  userAuth.auth(challenge, authType,authTrustLevel,{
      onResult: function(result,extraInfo){
          console.log("====>test for examples auth result = " + result)
          onresult.authresult = result
          console.log("====>test for examples auth extraInfo = " + JSON.stringify(extraInfo));
          onresult.authextr = extraInfo;
          console.info('====>test for examples auth onResult = ' + JSON.stringify(onresult));
      },
      onAcquireInfo:function (modulea,acquire,extr){
          console.info('====>test for examples publicauth auth onAcquireInfo in');
          onacquireinfo.authmodule = modulea;
          onacquireinfo.authacquire = acquire;
          onacquireinfo.authextr = extr;
          console.log("====>test for examples auth module = " + JSON.stringify(modulea));
          console.info('====>test for examples publicauth auth onAcquireInfo = ' + JSON.stringify(onacquireinfo));
      }
  });
  ```

## IIdmCallback<sup>8+</sup>

Provides callbacks for IDM.

### onResult<sup>8+</sup>

onResult: (result: number, extraInfo: AuthResult) => void;

Called to return the authentication result code.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                    |
| --------- | --------------------------------------- | ---- | ----------------------- |
| result    | number                                  | Yes  | Authentication result code.   |
| extraInfo | [AuthResult](#AuthResult<sup>8+</sup>)  | Yes  | Specific information to be transferred.|

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  let CredentialInfo = null;
  let onresult = {
      addCredresult: null,
      credentialId: null,
  }
  userIDM.updateCredential(CredentialInfo, {
      onResult: function(result,extraInfo){
          console.log("====>test for examples updateCredential result = " + result)
          onresult.updateCredresult = result
          console.log("====>test for examples updateCredential credentialId = " + extraInfo.credentialId)
          if(extraInfo != undefined) {
              onresult.CredentialId = extraInfo.credentialId
          } else {
              onresult.CredentialId = null;
          }
          console.info('====>test for examples publicupdateCred updateCredential  onResult = ' + JSON.stringify(onresult));
      }
  })
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;

Called to return the **TipsCode** during the authentication process.

This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type    | Mandatory| Description                          |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | Yes  | Type of authentication executor.  |
| acquire   | number  | Yes  | Tip code of the authentication executor.|
| extraInfo | any     | Yes  | Reserved.                    |

**Example**
  ```js
  var userIDM = new osAccount.UserIdentityManager();
  let CredentialInfo = null;
  let onresult = {
      addCredresult: null,
      credentialId: null,
  }
  let onacquireinfo = {
      updateCredmodule : null,
      updateCredacquire : null,
      updateCredextr : null
  }
  userIDM.updateCredential(CredentialInfo, {
      onResult: function(result,extraInfo){
          console.log("====>test for examples updateCredential result = " + result)
          onresult.updateCredresult = result
          console.log("====>test for examples updateCredential credentialId = " + extraInfo.credentialId)
          if(extraInfo != undefined) {
              onresult.CredentialId = extraInfo.credentialId
          } else {
              onresult.CredentialId = null;
          }
          console.info('====>test for examples publicupdateCred updateCredential  onResult = ' + JSON.stringify(onresult));
      },
      onAcquireInfo:function (modulea,acquire,extr){
          console.info('====>test for examples publicupdateCred updateCredential  onAcquireInfo in ');
          onacquireinfo.updateCredmodule = modulea
          onacquireinfo.updateCredacquire = acquire
          onacquireinfo.updateCredextr = extr
          console.info('====>test for examples updateCredential onacquireinfo = ' + JSON.stringify(onacquireinfo));
          console.log("====>test for examples updateCredential module = " + modulea)
      }
  })
  ```

## GetPropertyRequest<sup>8+</sup>

Defines the request for obtaining property information.

**System capability**: SystemCapability.Account.OsAccount

| Name   | Type                                                         | Mandatory  | Description                  |
| -------- | ------------------------------------------------------------- | ----- | ----------------------- |
| authType | [AuthType](#AuthType<sup>8+</sup>)                            | Yes   | Authentication credential type.       |
| keys     | Array&lt;[GetPropertyType](#GetPropertyType<sup>8+</sup>)&gt; | Yes   | An array of the types of the properties to obtain.|

## SetPropertyRequest<sup>8+</sup>

Defines the request for setting property information.

**System capability**: SystemCapability.Account.OsAccount

| Name   | Type                                            | Mandatory  | Description                |
| -------- | ------------------------------------------------ | ----- | -------------------- |
| authType | [AuthType](#AuthType<sup>8+</sup>)               | Yes   | Authentication credential type.    |
| keys     | [SetPropertyType](#SetPropertyType<sup>8+</sup>) | Yes   | Type of the property to be set.|
| setInfo  | Uint8Array                                       | Yes   | Information to set.    |

## ExecutorProperty<sup>8+</sup>

Defines the executor property.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ----- | ----------------- |
| result       | number                                   | Yes   | Result.        |
| authSubType  | [AuthSubType](#AuthSubType<sup>8+</sup>) | Yes   | Authentication credential subtype.|
| remainTimes  | number                                   | No   | Remaining time.    |
| freezingTime | number                                   | No   | Freezing time.    |

## AuthResult<sup>8+</sup>

Defines the authentication result information.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type       | Mandatory  | Description             |
| ------------ | ----------- | ----- | ----------------- |
| token        | Uint8Array  | No   | Authentication token.    |
| remainTimes  | number      | No   | Remaining time.    |
| freezingTime | number      | No   | Freezing time.    |

## CredentialInfo<sup>8+</sup>

Defines the credential information.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ----- | ----------------- |
| credType     | [AuthType](#AuthType<sup>8+</sup>)       | Yes   | Authentication credential type.    |
| credSubType  | [AuthSubType](#AuthSubType<sup>8+</sup>) | Yes   | Credential subtype.  |
| token        | Uint8Array                               | Yes   | Authentication token.    |

## RequestResult<sup>8+</sup>

Defines the request result information.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type       | Mandatory  | Description             |
| ------------ | ----------- | ----- | ----------------- |
| credentialId | Uint8Array  | No   | Credential ID.    |

## EnrolledCredInfo<sup>8+</sup>

Defines enrolled credential information.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ----- | ------------------- |
| credentialId | Uint8Array                               | Yes   | Credential ID.      |
| authType     | [AuthType](#AuthType<sup>8+</sup>)       | Yes   | Authentication credential type.  |
| authSubType  | [AuthSubType](#AuthSubType<sup>8+</sup>) | Yes   | Credential subtype.|
| templateId   | Uint8Array                               | Yes   | Credential template ID.    |

## GetPropertyType<sup>8+</sup>

Enumerates the types of the properties to obtain.

**System capability**: SystemCapability.Account.OsAccount

| Name          | Default Value| Description     |
| ------------- | ------ | --------- |
| AUTH_SUB_TYPE | 1      | Authentication subtype.|
| REMAIN_TIMES  | 2      | Remaining time.  |
| FREEZING_TIME | 3      | Freezing time.  |

## SetPropertyType<sup>8+</sup>

Enumerates the types of the properties to set.

**System capability**: SystemCapability.Account.OsAccount

| Name          | Default Value| Description       |
| -------------- | ----- | ----------- |
| INIT_ALGORITHM | 1     | Initialization algorithm.|

## AuthType<sup>8+</sup>

Enumerates the credential types.

**System capability**: SystemCapability.Account.OsAccount

| Name | Default Value| Description            |
| ----- | ----- | ---------------- |
| PIN   | 1     | PIN authentication.|
| FACE  | 2     | Facial authentication.|

## AuthSubType<sup>8+</sup>

Enumerates the credential subtypes.

**System capability**: SystemCapability.Account.OsAccount

| Name      | Default Value| Description              |
| ---------- | ----- | ------------------ |
| PIN_SIX    | 10000 | Six-digit PIN.      |
| PIN_NUMBER | 10001 | Custom PIN.|
| PIN_MIXED  | 10002 | Custom mixed credential.|
| FACE_2D    | 20000 | 2D face credential.  |
| FACE_3D    | 20001 | 3D face credential.  |

## AuthTrustLevel<sup>8+</sup>

Enumerates the trust levels of the authentication result.

**System capability**: SystemCapability.Account.OsAccount

| Name | Default Value| Description       |
| ---- | ------ | ----------- |
| ATL1 | 10000  | Trust level 1.|
| ATL2 | 20000  | Trust level 2.|
| ATL3 | 30000  | Trust level 3.|
| ATL4 | 40000  | Trust level 4.|

## Module<sup>8+</sup>

Enumerates the modules from which information is obtained.

**System capability**: SystemCapability.Account.OsAccount

| Name      | Default Value| Description                    |
| --------- | ------ | ------------------------ |
| FACE_AUTH | 1      | Information obtained from the face authentication module.|

## ResultCode<sup>8+</sup>

Enumerates the authentication result codes.

**System capability**: SystemCapability.Account.OsAccount

| Name                   | Default Value| Description                                    |
| ----------------------- | ----- | ---------------------------------------- |
| SUCCESS                 | 0     | The authentication is successful or the authentication function is supported.            |
| FAIL                    | 1     | The authentication executor failed to identify the user.                  |
| GENERAL_ERROR           | 2     | Other errors.                           |
| CANCELED                | 3     | The authentication is canceled.                      |
| TIMEOUT                 | 4     | The authentication timed out.                      |
| TYPE_NOT_SUPPORT        | 5     | The authentication credential type is not supported.                |
| TRUST_LEVEL_NOT_SUPPORT | 6     | The authentication trust level is not supported.              |
| BUSY                    | 7     | The authentication task is not available. Try again after a few seconds.|
| INVALID_PARAMETERS      | 8     | Incorrect parameters are detected.                         |
| LOCKED                  | 9     | The authentication executor is locked.                    |
| NOT_ENROLLED            | 10    | The authentication executor is not enrolled.                  |

## FaceTipsCode<sup>8+</sup>

Enumerates the tip codes for facial authentication.

**System capability**: SystemCapability.Account.OsAccount

| Name                         | Default Value| Description                                    |
| ----------------------------- | ----- | ---------------------------------------- |
| FACE_AUTH_TIP_TOO_BRIGHT      | 1     | The obtained face image is too bright.        |
| FACE_AUTH_TIP_TOO_DARK        | 2     | The obtained face image is too dark.      |
| FACE_AUTH_TIP_TOO_CLOSE       | 3     | The face is too close to the device.                      |
| FACE_AUTH_TIP_TOO_FAR         | 4     | The face is too far away from the device.                      |
| FACE_AUTH_TIP_TOO_HIGH        | 5     | Only the upper part of the face is captured because the device is angled too high.             |
| FACE_AUTH_TIP_TOO_LOW         | 6     | Only the lower part of the face is captured because the device is angled too low.             |
| FACE_AUTH_TIP_TOO_RIGHT       | 7     | Only the right part of the face is captured because the device is angled too much to the right.|
| FACE_AUTH_TIP_TOO_LEFT        | 8     | Only the left part of the face is captured because the device is angled too much to the left.|
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9     | The face moves too fast during facial information collection.        |
| FACE_AUTH_TIP_POOR_GAZE       | 10    | The face is not facing the device.                        |
| FACE_AUTH_TIP_NOT_DETECTED    | 11    | No face is detected.                        |

## ingerprintTips<sup>8+</sup>

Enumerates the tip codes for fingerprint authentication.

**System capability**: SystemCapability.Account.OsAccount

| Name                         | Default Value| Description                                           |
| ----------------------------- | ----- | ----------------------------------------------- |
| FINGERPRINT_TIP_GOOD          | 0     | The captured image is clear.                             |
| FINGERPRINT_TIP_IMAGER_DIRTY  | 1     | The fingerprint image has big noise due to dirt on the sensor.|
| FINGERPRINT_TIP_INSUFFICIENT  | 2     | Failed to process the fingerprint image due to big noise.  |
| FINGERPRINT_TIP_PARTIAL       | 3     | Only part of the fingerprint image is detected.                        |
| FINGERPRINT_TIP_TOO_FAST      | 4     | The fingerprint image is incomplete due to quick motion.                 |
| FINGERPRINT_TIP_TOO_SLOW      | 5     | Failed to read the fingerprint image due to lack of motion.               |

## OsAccountInfo

Defines information about an OS account.

**System capability**: SystemCapability.Account.OsAccount

| Name                        | Type                                                        | Mandatory| Description                             |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------- |
| localId                        | number                                                       | Yes  | ID of the target OS account.                     |
| localName                      | string                                                       | Yes  | OS account name.                   |
| type                           | [OsAccountType](#osaccounttype)                              | Yes  | OS account type.                     |
| constraints                    | Array&lt;string&gt;                                          | No  | [Constraints](#constraints) on the OS account.|
| isVerified<sup>8+</sup>        | boolean                                                      | Yes  | Whether the OS account is verified.                     |
| photo<sup>8+</sup>             | string                                                       | No  | Profile photo of the OS account.                     |
| createTime<sup>8+</sup>        | number                                                       | Yes  | Time when the OS account was created.                 |
| lastLoginTime<sup>8+</sup>     | number                                                       | No  | Last login time of the OS account.         |
| serialNumber<sup>8+</sup>      | number                                                       | Yes  | SN of the OS account.                     |
| isActived<sup>8+</sup>         | boolean                                                      | Yes  | Whether the OS account is activated.                 |
| isCreateCompleted<sup>8+</sup> | boolean                                                      | Yes  | Whether the OS account information is complete.             |
| distributedInfo                | [distributedAccount.DistributedInfo](js-apis-distributed-account.md) | No  | Distributed account information.                   |
| domainInfo<sup>8+</sup>        | [DomainAccountInfo](#domainaccountinfo8)                      | No  | Domain account information.                       |

## DomainAccountInfo<sup>8+</sup>

Domain account information.

**System capability**: SystemCapability.Account.OsAccount

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| domain      | string | Yes  | Domain name.    |
| accountName | string | Yes  | Domain account name.|

## Constraints

| Constraint                                 | Description                          |
| ------------------------------------- | ------------------------------ |
| constraint.wifi                       | A user is not allowed to use Wi-Fi.                  |
| constraint.wifi.set                   | A user is not allowed to change Wi-Fi settings.                  |
| constraint.locale.set                 | A user is not allowed to change the device language.              |
| constraint.app.accounts               | A user is not allowed to add or delete app accounts.        |
| constraint.apps.install               | A user is not allowed to install apps.                  |
| constraint.apps.uninstall             | A user is not allowed to uninstall apps.                  |
| constraint.location.shared            | A user is not allowed to enable location sharing.              |
| constraint.unknown.sources.install    | A user is not allowed to install apps from unknown sources.        |
| constraint.global.unknown.app.install | All users are not allowed to install apps from unknown sources.|
| constraint.bluetooth.set              | A user is not allowed to configure Bluetooth.                  |
| constraint.bluetooth | The use of Bluetooth is prohibited on the device.|
| constraint.bluetooth.share | Bluetooth sharing is prohibited.|
| constraint.usb.file.transfer | A user is not allowed to transfer files over USB.|
| constraint.credentials.set | A user is not allowed to configure user credentials.|
| constraint.os.account.remove | An admin user is not allowed to remove users or a non-admin user is not allowed to remove itself.|
| constraint.managed.profile.remove | The managed profiles of this user cannot be removed.|
| constraint.debug.features.use | A user is not allowed to enable or access debugging features.|
| constraint.vpn.set | A user is not allowed to configure a VPN.|
| constraint.date.time.set | A user is not allowed to set date, time, or time zone.|
| constraint.tethering.config | A user is not allowed to configure Tethering.|
| constraint.network.reset | A user is not allowed to reset network settings.|
| constraint.factory.reset | A user is not allowed to reset factory settings.|
| constraint.os.account.create | A user is not allowed to create users.|
| constraint.add.managed.profile | A user is not allowed to add managed profiles.|
| constraint.apps.verify.disable | A user is not allowed to disable app verification.|
| constraint.cell.broadcasts.set | A user is not allowed to configure cell broadcasts.|
| constraint.mobile.networks.set | A user is not allowed to configure radio networks.|
| constraint.control.apps | A user is not allowed to modify apps in **Settings** or the boot module.|
| constraint.physical.media | A user is not allowed to mount external physical media.|
| constraint.microphone | A user is not allowed to use microphones.|
| constraint.microphone.unmute | A user is not allowed to unmute the microphone.|
| constraint.volume.adjust | A user is not allowed to adjust the volume.|
| constraint.calls.outgoing | A user is not allowed to make outgoing calls.|
| constraint.sms.use | A user is not allowed to send or receive SMS messages.|
| constraint.fun | A user is not allowed to have entertainment.|
| constraint.windows.create | Windows other than app windows cannot be created.|
| constraint.system.error.dialogs | Error dialogs for crashed or unresponsive apps are prohibited.|
| constraint.cross.profile.copy.paste | Pasting clipboard content to other users or profiles is prohibited.|
| constraint.beam.outgoing | A user is not allowed to use Near Field Communications (NFC) to transfer data from apps.|
| constraint.wallpaper | A user is not allowed to manage wallpapers.|
| constraint.safe.boot | A user is not allowed to reboot the device in safe boot mode.|
| constraint.parent.profile.app.linking | The apps in the parent profile are allowed to handle web links from the managed profile.|
| constraint.audio.record | Audio recording is prohibited.|
| constraint.camera.use | The use of cameras is prohibited.|
| constraint.os.account.background.run | Running in the background is prohibited.|
| constraint.data.roam | A user is not allowed to use cellular data when roaming.|
| constraint.os.account.set.icon | A user is not allowed to change their icon.|
| constraint.wallpaper.set | A user is not allowed to set a wallpaper.|
| constraint.oem.unlock | A user is not allowed to enable OEM unlock.|
| constraint.device.unmute | A user is not allowed to unmute the device.|
| constraint.password.unified | The managed profile is not allowed to have unified lock screen challenge with the primary user.|
| constraint.autofill | A user is not allowed to use the autofill service.|
| constraint.content.capture | Capturing the content of a user's screen is prohibited.|
| constraint.content.suggestions | A user is not allowed to receive content suggestions.|
| constraint.os.account.start | User switching is blocked.|
| constraint.location.set | A user is not allowed to configure the location service.|
| constraint.airplane.mode.set | The airplane mode is prohibited on the device.|
| constraint.brightness.set | A user is not allowed to configure brightness.|
| constraint.share.into.profile | A user is not allowed to share files, images, or data from the primary user to the managed profile.|
| constraint.ambient.display | Ambient display is prohibited for the user.|
| constraint.screen.timeout.set | A user is not allowed to configure the screen off timeout.|
| constraint.print | A user is not allowed to print.|
| constraint.private.dns.set | A user is not allowed to configure a private domain name server (DNS).|

## ConstraintSourceTypeInfo<sup>9+</sup>

Defines information about the source of a constraint.

This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| localId      | number | Yes  | ID of the OS account.    |
| type | [ConstraintSourceType](#constraintsourcetype) | Yes  | Type of the constrain source.|

## ConstraintSourceType<sup>9+</sup>

Enumerates the constraint sources.

This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name  | Default Value| Description        |
| ------ | ------ | ------------ |
| CONSTRAINT_NOT_EXIST  | 0      | The constraint does not exist.|
| CONSTRAINT_TYPE_BASE | 1      | Constraint from system settings.  |
| CONSTRAINT_TYPE_DEVICE_OWNER  | 2   | Constraint from the device owners' settings.  |
| CONSTRAINT_TYPE_PROFILE_OWNER  | 3  | Constraint from the profile owners' settings.  |
