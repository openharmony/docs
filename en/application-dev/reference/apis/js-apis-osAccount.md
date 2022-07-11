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
| domainInfo | [DomainAccountInfo](#domainaccountinfo) | Yes  | Domain account information.                                |
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
| domainInfo | [DomainAccountInfo](#domainaccountinfo) | Yes  | Domain account information.|

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
| domainInfo | [DomainAccountInfo](#domainaccountinfo)              | Yes  | Domain account information.                              |
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
| domainInfo | [DomainAccountInfo](#domainaccountinfo) | Yes  | Domain account information.          |

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
| domainInfo<sup>8+</sup>        | [DomainAccountInfo](#domainaccountinfo)                      | No  | Domain account information.                       |

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
