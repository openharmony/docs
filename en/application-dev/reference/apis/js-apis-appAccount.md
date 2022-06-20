#  	App Account Management

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import account_appAccount from '@ohos.account.appAccount';
```


## account_appAccount.createAppAccountManager

createAppAccountManager(): AppAccountManager

Creates an **AppAccountManager** instance.

**System capability**: SystemCapability.Account.AppAccount

**Return Value**
| Type               | Description          |
| ----------------- | ------------ |
| AppAccountManager | **AppAccountManager** instance created.|

**Example**
  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  ```

## AppAccountManager

Provides methods to manage app accounts.

### addAccount

addAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

Adds an app account to the account management service. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                   |
| -------- | ------------------------- | ---- | --------------------- |
| name     | string                    | Yes   | Name of the app account to add.         |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the app account is added.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("WangWu", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount

addAccount(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

Adds an app account and its additional information to the account management service. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| name      | string                    | Yes   | Name of the app account to add.                            |
| extraInfo | string                    | Yes   | Additional information (for example, token) of the app account to add. The additional information cannot contain sensitive information about the app account.|
| callback  | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the app account and its additional information are added.           |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```



### addAccount

addAccount(name: string, extraInfo?: string): Promise&lt;void&gt;

Adds an app account and its additional information to the account management service. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description                              |
| --------- | ------ | ---- | -------------------------------- |
| name      | string | Yes   | Name of the app account to add.                    |
| extraInfo | string | Yes   | Additional information of the app account to add. The additional information cannot contain sensitive information about the app account.|

**Return Value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101").then(()=> { 
      console.log('addAccount Success');
  }).catch((err) => {
      console.log("addAccount err: "  + JSON.stringify(err));
  });
  ```

### addAccountImplicitly<sup>8+</sup>

addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Implicitly adds an app account based on the specified account owner, authentication type, and options. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description             |
| -------- | --------------------- | ---- | --------------- |
| owner    | string                | Yes   | Bundle name of the app account to add.|
| authType | string                | Yes   | Authentication type of the app account to add. |
| options  | {[key: string]: any}  | Yes   | Options for the authentication.     |
| callback | AuthenticatorCallback | Yes   | Authenticator callback invoked to return the authentication result.|

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccountImplicitly("LiSi", "readAge", {}, {
      onResult: onResultCallback,
      onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### deleteAccount

deleteAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an app account from the account management service. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description               |
| -------- | ------------------------- | ---- | ----------------- |
| name     | string                    | Yes   | Name of the app account to delete.     |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the app account is deleted.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu", (err) => { 
      console.log("deleteAccount err: " + JSON.stringify(err));
   });
  ```

### deleteAccount

deleteAccount(name: string): Promise&lt;void&gt;

Deletes an app account from the account management service. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description          |
| ---- | ------ | ---- | ------------ |
| name | string | Yes   | Name of the app account to delete.|

**Return Value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu").then(() => { 
        console.log('deleteAccount Success');
   }).catch((err) => {
      console.log("deleteAccount err: "  + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Disables an app account from accessing an application with the given bundle name. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                             |
| ---------- | ------------------------- | ---- | ------------------------------- |
| name       | string                    | Yes   | App account name.              |
| bundleName | string                    | Yes   | Bundle name of an app.                      |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the app account is disabled from accessing the application with the given bundle name.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("disableAppAccess err: " + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

Disables an app account from accessing an application with the given bundle name. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description               |
| ---------- | ------ | ---- | ----------------- |
| name       | string | Yes   | App account name.|
| bundleName | string | Yes   | Bundle name of an app.        |

**Return Value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
      console.log('disableAppAccess Success');
  }).catch((err) => {
      console.log("disableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Enables an app account to access an application with the given bundle name. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                             |
| ---------- | ------------------------- | ---- | ------------------------------- |
| name       | string                    | Yes   | App account name.                        |
| bundleName | string                    | Yes   | Bundle name of an app.                      |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the app account is enabled to access the application with the given bundle name.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("enableAppAccess: " + JSON.stringify(err));
   });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

Enables an app account to access an application with the given bundle name. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| name       | string | Yes   | App account name.  |
| bundleName | string | Yes   | Bundle name of an app.|

**Return Value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  app_account_instance.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
       console.log('enableAppAccess Success');
  }).catch((err) => {
      console.log("enableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an app account allows application data synchronization. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                          | Mandatory  | Description                    |
| -------- | ---------------------------- | ---- | ---------------------- |
| name     | string                       | Yes   | App account name.               |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return whether the app account allows application data synchronization.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan", (err, result) => { 
      console.log("checkAppAccountSyncEnable err: " + JSON.stringify(err));
      console.log('checkAppAccountSyncEnable result: ' + result);
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string): Promise&lt;boolean&gt;

Checks whether an app account allows application data synchronization. This method uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| name | string | Yes   | App account name.|

**Return Value**

| Type                    | Description                   |
| :--------------------- | :-------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan").then((data) => { 
      console.log('checkAppAccountSyncEnable, result: ' + data);
  }).catch((err) => {
      console.log("checkAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void

Sets a credential for an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                       | Mandatory  | Description            |
| -------------- | ------------------------- | ---- | -------------- |
| name           | string                    | Yes   | App account name.    |
| credentialType | string                    | Yes   | Type of the credential to set.    |
| credential     | string                    | Yes   | Credential to set.       |
| callback       | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when a credential is set for the specified app account.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
      console.log("setAccountCredential err: " + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;

Sets a credential for an app account. This method uses a promise to return the result asynchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | App account name.  |
| credentialType | string | Yes   | Type of the credential to set.|
| credential     | string | Yes   | Credential to set.   |

**Return Value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001").then(() => { 
      console.log('setAccountCredential Success');
  }).catch((err) => {
      console.log("setAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

Sets additional information for an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                       | Mandatory  | Description              |
| --------- | ------------------------- | ---- | ---------------- |
| name      | string                    | Yes   | App account name.        |
| extraInfo | string                    | Yes   | Additional information to set.       |
| callback  | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when additional information is set for the specified app account.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002", (err) => { 
      console.log("setAccountExtraInfo err: " + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string): Promise&lt;void&gt;

Sets additional information for an app account. This method uses a promise to return the result asynchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description       |
| --------- | ------ | ---- | --------- |
| name      | string | Yes   | App account name. |
| extraInfo | string | Yes   | Additional information to set.|

**Return Value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002").then(() => { 
      console.log('setAccountExtraInfo Success');
  }).catch((err) => {
      console.log("setAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets whether to enable application data synchronization for an app account. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                       |
| -------- | ------------------------- | ---- | ------------------------- |
| name     | string                    | Yes   | App account name.                 |
| isEnable | boolean                   | Yes   | Whether to enable app data synchronization.              |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when application data synchronization is enabled or disabled for the app account.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAppAccountSyncEnable("ZhangSan", true, (err) => { 
      console.log("setAppAccountSyncEnable err: " + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable application data synchronization for an app account. This method uses a promise to return the result asynchronously.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type     | Mandatory  | Description         |
| -------- | ------- | ---- | ----------- |
| name     | string  | Yes   | App account name.   |
| isEnable | boolean | Yes   | Whether to enable app data synchronization.|

**Return Value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager .setAppAccountSyncEnable("ZhangSan", true).then(() => { 
      console.log('setAppAccountSyncEnable Success');
  }).catch((err) => {
      console.log("setAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAssociatedData

setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets data to be associated with an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description               |
| -------- | ------------------------- | ---- | ----------------- |
| name     | string                    | Yes   | App account name.         |
| key      | string                    | Yes   | Key of the data to set. The private key can be customized.|
| value    | string                    | Yes   | Value of the data to be set.        |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the data associated with the specified app account is set.|

**Example**

  ```js
  app_account_instance.setAssociatedData("ZhangSan", "k001", "v001", (err) => { 
      console.log("setAssociatedData err: " + JSON.stringify(err));
  });
  ```

### setAssociatedData

setAssociatedData(name: string, key: string, value: string): Promise&lt;void&gt;

Sets data to be associated with an app account. This method uses a promise to return the result asynchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description               |
| ----- | ------ | ---- | ----------------- |
| name  | string | Yes   | App account name.         |
| key   | string | Yes   | Key of the data to set. The private key can be customized.|
| value | string | Yes   | Value of the data to be set.        |

**Return Value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001").then(() => { 
      console.log('setAssociatedData Success');
  }).catch((err) => {
      console.log("setAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the credential of an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                         | Mandatory  | Description            |
| -------------- | --------------------------- | ---- | -------------- |
| name           | string                      | Yes   | App account name.       |
| credentialType | string                      | Yes   | Type of the credential to obtain.    |
| callback       | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the credential of the specified app account.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001", (err, result) => { 
      console.log("getAccountCredential err: " + JSON.stringify(err));
      console.log('getAccountCredential result: ' + result);
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string): Promise&lt;string&gt;

Obtains the credential of an app account. This method uses a promise to return the result asynchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | App account name.   |
| credentialType | string | Yes   | Type of the credential to obtain.|

**Return Value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001").then((data) => { 
      console.log('getAccountCredential, result: ' + data);
  }).catch((err) => {
      console.log("getAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### getAccountExtraInfo

getAccountExtraInfo(name: string, callback: AsyncCallback&lt;string&gt;): void

Obtains additional information of an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description              |
| -------- | --------------------------- | ---- | ---------------- |
| name     | string                      | Yes   | App account name.         |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the additional information of the specified app account.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan", (err, result) => { 
      console.log("getAccountExtraInfo err: " + JSON.stringify(err));
      console.log('getAccountExtraInfo result: ' + result);
  });
  ```

### getAccountExtraInfo

getAccountExtraInfo(name: string): Promise&lt;string&gt;

Obtains additional information of an app account. This method uses a promise to return the result asynchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| name | string | Yes   | App account name.|

**Return Value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan").then((data) => { 
      console.log('getAccountExtraInfo, result: ' + data);
  }).catch((err) => {
      console.log("getAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### getAssociatedData

getAssociatedData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains data associated with an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description               |
| -------- | --------------------------- | ---- | ----------------- |
| name     | string                      | Yes   | App account name.          |
| key      | string                      | Yes   | Key of the data to obtain.      |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the data associated with the specified app account.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001", (err, result) => { 
      console.log("getAssociatedData err: " + JSON.stringify(err));
      console.log('getAssociatedData result: ' + result);
  });
  ```

### getAssociatedData

getAssociatedData(name: string, key: string): Promise&lt;string&gt;

Obtains data associated with an app account. This method uses a promise to return the result asynchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| name | string | Yes   | App account name.    |
| key  | string | Yes   | Key of the data to obtain.|

**Return Value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001").then((data) => { 
       console.log('getAssociatedData: ' + data);
  }).catch((err) => {
      console.log("getAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Obtains information about all accessible app accounts. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description      |
| -------- | ---------------------------------------- | ---- | -------- |
| callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | Yes   | Callback invoked to return information about all accessible app accounts.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts((err, data)=>{
  	console.debug("getAllAccessibleAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccessibleAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Obtains information about all accessible app accounts. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts().then((data) => { 
       console.log('getAllAccessibleAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccessibleAccounts err: "  + JSON.stringify(err));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Obtains information about all app accounts of the specified app. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description      |
| -------- | ---------------------------------------- | ---- | -------- |
| owner    | string                                   | Yes   | Bundle name of the app.   |
| callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | Yes   | Callback invoked to return information about all accessible app accounts.|

**Example**

  ```js
  const appAccountManager = account.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle, (err, data)=>{
  	console.debug("getAllAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Obtains information about all app accounts of the specified app. This method uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description   |
| ----- | ------ | ---- | ----- |
| owner | string | Yes   | Bundle name of the app.|

**Parameters**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle).then((data) => { 
       console.log('getAllAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccounts err: "  + JSON.stringify(err));
  });
  ```

### on('change')

on(type: 'change', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Subscribes to the account change event of the specified account owners. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | 'change'                                 | Yes   | Type of the event to subscribe to. The subscriber will receive a notification when the account owners update their accounts.|
| owners   | Array&lt;string&gt;                      | Yes   | Owners of the accounts.                     |
| callback | Callback&lt;Array&lt;AppAccountInfo&gt;&gt; | Yes   | Callback invoked to return the account change.          |

**Example**

  ```js
  const appAccountManager = account.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  }
  try{
  	appAccountManager.on('change', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

### off('change')

off(type: 'change', callback?: Callback<Array\<AppAccountInfo>>): void

Unsubscribes from the account change event. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                              | Mandatory  | Description          |
| -------- | -------------------------------- | ---- | ------------ |
| type     | 'change'                         | Yes   | Account change event to unsubscribe from.   |
| callback | Callback<Array\<AppAccountInfo>> | No   | Callback used to report the account change.|

**Example**

  ```js
  const appAccountManager = account.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  	appAccountManager.off('change', function(){
  		console.debug("off finish");
  	})
  }
  try{
  	appAccountManager.on('change', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

### authenticate<sup>8+</sup>

authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Authenticates an app account to obtain the Open Authorization (OAuth) access token. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description             |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | Yes   | Name of the app account to authenticate.   |
| owner    | string                | Yes   | Bundle name of the app.|
| authType | string                | Yes   | Authentication type.          |
| options  | {[key: string]: any}  | Yes   | Options for the authentication.      |
| callback | AuthenticatorCallback | Yes   | Authenticator callback invoked to return the authentication result.|

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
      console.log("resultCode: "  + code);
      console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
      let abilityStartSetting = {want: request};
      featureAbility.startAbility(abilityStartSetting, (err)=>{
          console.log("startAbility err: " + JSON.stringify(err));
      });
  }

  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.authenticate("LiSi", "com.example.ohos.accountjsdemo", "readAge", {}, {
    onResult: onResultCallback,
    onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### getOAuthToken<sup>8+</sup>

getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the OAuth access token of an app account based on the specified authentication type. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description         |
| -------- | --------------------------- | ---- | ----------- |
| name     | string                      | Yes   | App account name.   |
| owner    | string                      | Yes   | Bundle name of the app.|
| authType | string                      | Yes   | Authentication type.      |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result.   |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge", (err, data) => {
       console.log('getOAuthToken err: ' + JSON.stringify(err));
       console.log('getOAuthToken token: ' + data);
  });
  ```

### getOAuthToken<sup>8+</sup>

getOAuthToken(name: string, owner: string, authType: string): Promise&lt;string&gt;

Obtains the OAuth access token of an app account based on the specified authentication type. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description         |
| -------- | ------ | ---- | ----------- |
| name     | string | Yes   | App account name.   |
| owner    | string | Yes   | Bundle name of the app.|
| authType | string | Yes   | Authentication type.      |

**Parameters**

| Type                   | Description                   |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge").then((data) => {
       console.log('getOAuthToken token: ' + data);
  }).catch((err) => {
      console.log("getOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>8+</sup>

setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Sets an OAuth access token for an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description      |
| -------- | ------------------------- | ---- | -------- |
| name     | string                    | Yes   | App account name.|
| authType | string                    | Yes   | Authentication type.   |
| token    | string                    | Yes   | OAuth access token to set.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "readAge", "xxxx", (err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>8+</sup>

setOAuthToken(name: string, authType: string, token: string): Promise&lt;void&gt;

Sets an OAuth access token for an app account. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| name     | string | Yes   | App account name.|
| authType | string | Yes   | Authentication type.   |
| token    | string | Yes   | OAuth access token to set.|

**Parameters**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "readAge", "xxxx").then(() => {
      console.log('setOAuthToken successfully');
  }).catch((err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>8+</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the specified OAuth access token for an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description          |
| -------- | ------------------------- | ---- | ------------ |
| name     | string                    | Yes   | App account name.    |
| owner    | string                    | Yes   | Bundle name of the app. |
| authType | string                    | Yes   | Authentication type.       |
| token    | string                    | Yes   | OAuth access token to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.    |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge", "xxxxx", (err) => {
       console.log('deleteOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>8+</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise&lt;void&gt;

Deletes the specified OAuth access token for an app account. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description          |
| -------- | ------ | ---- | ------------ |
| name     | string | Yes   | App account name.    |
| owner    | string | Yes   | Bundle name of the app. |
| authType | string | Yes   | Authentication type.       |
| token    | string | Yes   | OAuth access token to delete.|

**Parameters**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "readAge", "xxxxx").then(() => {
       console.log('deleteOAuthToken successfully');
  }).catch((err) => {
      console.log("deleteOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>8+</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the visibility of an OAuth access token to the specified app. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description          |
| ---------- | ------------------------- | ---- | ------------ |
| name       | string                    | Yes   | App account name.    |
| authType   | string                    | Yes   | Authentication type.       |
| bundleName | string                    | Yes   | Bundle name of the app.|
| isVisible  | boolean                   | Yes   | Whether the OAuth access token is visible to the app.       |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.    |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true, (err) => {
       console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>8+</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise&lt;void&gt;

Sets the visibility of an OAuth access token to the specified app. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type     | Mandatory  | Description          |
| ---------- | ------- | ---- | ------------ |
| name       | string  | Yes   | App account name.    |
| authType   | string  | Yes   | Authentication type.       |
| bundleName | string  | Yes   | Bundle name of the app.|
| isVisible  | boolean | Yes   | Whether the OAuth access token is visible to the app.       |

**Parameters**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true).then(() => {
      console.log('setOAuthTokenVisibility successfully');
  }).catch((err) => {
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### checkOAuthTokenVisibility<sup>8+</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OAuth token is visible to the specified app. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                          | Mandatory  | Description           |
| ---------- | ---------------------------- | ---- | ------------- |
| name       | string                       | Yes   | App account name.     |
| authType   | string                       | Yes   | Authentication type.        |
| bundleName | string                       | Yes   | Bundle name of the app.|
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result.     |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true, (err, data) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  });
  ```

### checkOAuthTokenVisibility<sup>8+</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise&lt;boolean&gt;

Checks whether an OAuth token is visible to the specified app. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description           |
| ---------- | ------ | ---- | ------------- |
| name       | string | Yes   | App account name.     |
| authType   | string | Yes   | Authentication type.        |
| bundleName | string | Yes   | Bundle name of the app.|

**Parameters**

| Type                    | Description                   |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "readAge", "com.example.ohos.accountjsdemo", true).then((data) => {
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  }).catch((err) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### getAllOAuthTokens<sup>8+</sup>

getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback&lt;Array&lt;OAuthTokenInfo&gt;&gt;): void

Obtains information about all OAuth access tokens of an app account visible to the specified app. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | Yes   | App account name.   |
| owner    | string                                   | Yes   | Bundle name of the app.|
| callback | AsyncCallback&lt;Array&lt;OAuthTokenInfo&gt;&gt; | Yes   | Callback invoked to return the result.   |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.ohos.accountjsdemo", (err, data) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
      console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  });
  ```

### getAllOAuthTokens<sup>8+</sup>

getAllOAuthTokens(name: string, owner: string): Promise&lt;Array&lt;OAuthTokenInfo&gt;&gt;

Obtains information about all OAuth access tokens of an app account visible to the specified app. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| name  | string | Yes   | App account name.   |
| owner | string | Yes   | Bundle name of the app.|

**Parameters**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;OAuthTokenInfo&gt;&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.ohos.accountjsdemo").then((data) => {
       console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
  });
  ```

### getOAuthList<sup>8+</sup>

getOAuthList(name: string, authType: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the authorization list of OAuth access tokens of an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | Yes   | App account name.   |
| owner    | string                                   | Yes   | Bundle name of the app.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback invoked to return the result.   |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "readAge", (err, data) => {
       console.log('getOAuthList err: ' + JSON.stringify(err));
       console.log('getOAuthList data: ' + JSON.stringify(data));
  });
  ```

### getOAuthList<sup>8+</sup>

getOAuthList(name: string, authType: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains the authorization list of OAuth access tokens of an app account. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| name  | string | Yes   | App account name.   |
| owner | string | Yes   | Bundle name of the app.|

**Parameters**

| Type                                | Description                   |
| ---------------------------------- | --------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "readAge").then((data) => {
       console.log('getOAuthList data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getOAuthList err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorCallback<sup>8+</sup>

getAuthenticatorCallback(sessionId: string, callback: AsyncCallback&lt;AuthenticatorCallback&gt;): void

Obtains the authenticator callback for a session. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string                                   | Yes   | ID of the session to authenticate.|
| callback  | AsyncCallback&lt;AuthenticatorCallback&gt; | Yes   | Callback invoked to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant((err, want) => {
    var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
    appAccountManager.getAuthenticatorCallback(sessionId, (err, callback) => {
        if (err.code != account_appAccount.ResultCode.SUCCESS) {
            console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
            return;
        }
        var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                      [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                      [account_appAccount.Constants.KEY_AUTH_TYPE]: "readAge",
                      [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
        callback.OnResult(account_appAccount.ResultCode.SUCCESS, result);
    });
  });
  ```

### getAuthenticatorCallback<sup>8+</sup>

getAuthenticatorCallback(sessionId: string): Promise&lt;AuthenticatorCallback&gt;

Obtains the authenticator callback for a session. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description      |
| --------- | ------ | ---- | -------- |
| sessionId | string | Yes   | ID of the session to authenticate.|

**Parameters**

| Type                                  | Description                   |
| ------------------------------------ | --------------------- |
| Promise&lt;AuthenticatorCallback&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant().then((want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
          var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                        [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: "readAge",
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.OnResult(account_appAccount.ResultCode.SUCCESS, result);
      }).catch((err) => {
          console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
      });
  }).catch((err) => {
      console.log("getWant err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorInfo<sup>8+</sup>

getAuthenticatorInfo(owner: string, callback: AsyncCallback&lt;AuthenticatorInfo&gt;): void

Obtains authenticator information of an app account. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                    | Mandatory  | Description         |
| -------- | -------------------------------------- | ---- | ----------- |
| owner    | string                                 | Yes   | Bundle name of the app.|
| callback | AsyncCallback&lt;AuthenticatorInfo&gt; | Yes   | Callback invoked to return the result.   |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.ohos.accountjsdemo", (err, data) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
      console.log('getAuthenticatorInfo data: ' + JSON.stringify(data));
  });
  ```

### getAuthenticatorInfo<sup>8+</sup>

getAuthenticatorInfo(owner: string): Promise&lt;AuthenticatorInfo&gt;

Obtains authenticator information of an app account. This method uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| owner | string | Yes   | Bundle name of the app.|

**Parameters**

| Type                              | Description                   |
| -------------------------------- | --------------------- |
| Promise&lt;AuthenticatorInfo&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.ohos.accountjsdemo").then((data) => { 
       console.log('getAuthenticatorInfo: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
  });
  ```

## AppAccountInfo

Defines app account information.

**System capability**: SystemCapability.Account.AppAccount

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| owner | string | Yes   | Bundle name of the app.|
| name  | string | Yes   | App account name.   |

## OAuthTokenInfo<sup>8+</sup>

Defines OAuth access token information.

**System capability**: SystemCapability.Account.AppAccount

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| authType | string | Yes   | Authentication type.|
| token    | string | Yes   | Value of the access token.  |

## AuthenticatorInfo<sup>8+</sup>

Defines OAuth authenticator information.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type    | Mandatory  | Description        |
| ------- | ------ | ---- | ---------- |
| owner   | string | Yes   | Bundle name of the authenticator owner.|
| iconId  | string | Yes   | ID of the authenticator icon. |
| labelId | string | Yes   | ID of the authenticator label. |

## Constants<sup>8+</sup>

Enumerates the constants.

**System capability**: SystemCapability.Account.AppAccount

| Name                           | Default Value                   | Description           |
| ----------------------------- | ---------------------- | ------------- |
| ACTION_ADD_ACCOUNT_IMPLICITLY | "addAccountImplicitly" | Operation for implicitly adding an account. |
| ACTION_AUTHENTICATE           | "authenticate"         | Authentication operation.     |
| KEY_NAME                      | "name"                 | App account name. |
| KEY_OWNER                     | "owner"                | App account owner.|
| KEY_TOKEN                     | "token"                | OAuth access token.     |
| KEY_ACTION                    | "action"               | Action.     |
| KEY_AUTH_TYPE                 | "authType"             | Authentication type.   |
| KEY_SESSION_ID                | "sessionId"            | Session ID.   |
| KEY_CALLER_PID                | "callerPid"            | Caller process ID (PID). |
| KEY_CALLER_UID                | "callerUid"            | Caller user ID (UID). |
| KEY_CALLER_BUNDLE_NAME        | "callerBundleName"     | Caller bundle name.  |

## ResultCode<sup>8+</sup>

Enumerates the result codes.

**System capability**: SystemCapability.Account.AppAccount

| Name                                 | Default Value  | Description          |
| ----------------------------------- | ----- | ------------ |
| SUCCESS                             | 0     | The operation is successful.     |
| ERROR_ACCOUNT_NOT_EXIST             | 10001 | The app account does not exist.  |
| ERROR_APP_ACCOUNT_SERVICE_EXCEPTION | 10002 | The app account service is abnormal. |
| ERROR_INVALID_PASSWORD              | 10003 | The password is invalid.     |
| ERROR_INVALID_REQUEST               | 10004 | The request is invalid.     |
| ERROR_INVALID_RESPONSE              | 10005 | The response is invalid.     |
| ERROR_NETWORK_EXCEPTION             | 10006 | The network is abnormal.     |
| ERROR_OAUTH_AUTHENTICATOR_NOT_EXIST | 10007 | The authenticator does not exist.   |
| ERROR_OAUTH_CANCELED                | 10008 | The authentication is canceled.     |
| ERROR_OAUTH_LIST_TOO_LARGE          | 10009 | The size of the OAuth list exceeds the limit. |
| ERROR_OAUTH_SERVICE_BUSY            | 10010 | The OAuth service is busy. |
| ERROR_OAUTH_SERVICE_EXCEPTION       | 10011 | The OAuth service is abnormal. |
| ERROR_OAUTH_SESSION_NOT_EXIST       | 10012 | The session to be authenticated does not exist.  |
| ERROR_OAUTH_TIMEOUT                 | 10013 | The authentication timed out.     |
| ERROR_OAUTH_TOKEN_NOT_EXIST         | 10014 | The OAuth access token does not exist.|
| ERROR_OAUTH_TOKEN_TOO_MANY          | 10015 | The number of OAuth access tokens reaches the limit. |
| ERROR_OAUTH_UNSUPPORT_ACTION        | 10016 | The authentication operation is not supported. |
| ERROR_OAUTH_UNSUPPORT_AUTH_TYPE     | 10017 | The authentication type is not supported. |
| ERROR_PERMISSION_DENIED             | 10018 | The required permission is missing.     |

## AuthenticatorCallback<sup>8+</sup>

Provides methods for managing the OAuth authenticator callback.

### onResult<sup>8+</sup>

onResult: (code: number, result: {[key: string]: any}) =&gt; void

Called back to send the authentication result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**
| Name   | Type                  | Mandatory  | Description    |
| ------ | -------------------- | ---- | ------ |
| code   | number               | Yes   | Authentication result code.|
| result | {[key: string]: any} | Yes   | Authentication result. |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
      var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                    [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                    [account_appAccount.Constants.KEY_AUTH_TYPE]: "readAge",
                    [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
      callback.OnResult(account_appAccount.ResultCode.SUCCESS, result);
  }).catch((err) => {
      console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
  });
  ```

### onRequestRedirected<sup>8+</sup>

onRequestRedirected: (request: Want) =&gt; void

Called back to redirect an authentication request.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**
| Name    | Type  | Mandatory  | Description        |
| ------- | ---- | ---- | ---------- |
| request | Want | Yes   | Request to be redirected.|

**Example**

  ```js
  class MyAuthenticator extends account_appAccount.Authenticator {
      addAccountImplicitly(authType, callerBundleName, options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.ohos.accountjsdemo",
              abilityName: "com.example.ohos.accountjsdemo.LoginAbility",
          });
      }

      authenticate(name, authType, callerBundleName, options, callback) {
          var result = {[account_appAccount.Constants.KEY_NAME]: name,
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: authType,
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
  }
  ```

## Authenticator<sup>8+</sup>

Defines the OAuth authenticator base class.

### addAccountImplicitly<sup>8+</sup>

addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Implicitly adds an app account based on the specified authentication type and options. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**
| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| authType         | string                | Yes   | Authentication type.     |
| callerBundleName | string                | Yes   | Bundle name of the authentication requester.      |
| options          | {[key: string]: any}  | Yes   | Options for the authentication.     |
| callback         | AuthenticatorCallback | Yes   | Authenticator callback invoked to return the authentication result.|

### authenticate<sup>8+</sup>

authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Authenticates an app account to obtain the OAuth access token. This method uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**
| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name             | string                | Yes   | App account name.       |
| authType         | string                | Yes   | Authentication type.     |
| callerBundleName | string                | Yes   | Bundle name of the authentication requester.      |
| options          | {[key: string]: any}  | Yes   | Options for the authentication.     |
| callback         | AuthenticatorCallback | Yes   | Authenticator callback invoked to return the authentication result.|

**Example**

  ```js
  class MyAuthenticator extends account_appAccount.Authenticator {
      addAccountImplicitly(authType, callerBundleName, options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.ohos.accountjsdemo",
              abilityName: "com.example.ohos.accountjsdemo.LoginAbility",
          });
      }

      authenticate(name, authType, callerBundleName, options, callback) {
          var result = {[account_appAccount.Constants.KEY_NAME]: name,
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: authType,
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
  }

  export default {
      onConnect(want) {
          return new MyAuthenticator();
      }
  }
  ```
