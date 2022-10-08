# App Account Management

The **appAccount** module provides APIs for app account management. You can use the APIs to add, delete, query, modify, and authorize app accounts, write data to disks, and synchronize data.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import account_appAccount from '@ohos.account.appAccount';
```


## account_appAccount.createAppAccountManager

createAppAccountManager(): AppAccountManager

Creates an **AppAccountManager** instance.

**System capability**: SystemCapability.Account.AppAccount

**Return value**

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

Adds an app account to the **AppAccountManager** service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                  |
| -------- | ------------------------- | ---- | -------------------- |
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

Adds an app account name and additional information (information that can be converted into the string type, such as token) to the **AppAccountManager** service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| name      | string                    | Yes   | Name of the app account to add.                             |
| extraInfo | string                    | Yes   | Additional information to add. The additional information cannot contain sensitive information, such as the app account password.|
| callback  | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the app account name and additional information are added.            |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```



### addAccount

addAccount(name: string, extraInfo?: string): Promise&lt;void&gt;

Adds an app account name and additional information (information that can be converted into the string type, such as token) to the **AppAccountManager** service. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description                                      |
| --------- | ------ | ---- | ---------------------------------------- |
| name      | string | Yes   | Name of the app account to add.                             |
| extraInfo | string | No   | Additional information to add. The additional information cannot contain sensitive information, such as the app account password.|

**Return value**

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

Implicitly adds an app account based on the specified account owner, authentication type, and options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description                     |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | Yes   | Owner of the app account to add. The value is the bundle name of the app.         |
| authType | string                | Yes   | Authentication type of the app account to add. The authentication type is customized. |
| options  | {[key: string]: any}  | Yes   | Authentication options, which can be set as required.|
| callback | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the authentication result.        |

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
  appAccountManager.addAccountImplicitly("com.example.ohos.accountjsdemo", "getSocialData", {}, {
      onResult: onResultCallback,
      onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### deleteAccount

deleteAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an app account from the **AppAccountManager** service. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description              |
| -------- | ------------------------- | ---- | ---------------- |
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

Deletes an app account from the **AppAccountManager** service. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| name | string | Yes   | Name of the app account to delete.|

**Return value**

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

Disables an app account from accessing an app with the given bundle name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                               |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | Yes   | Name of the target app account.                 |
| bundleName | string                    | Yes   | Bundle name of the app.                        |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("disableAppAccess err: " + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

Disables an app account from accessing an app with the given bundle name. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description              |
| ---------- | ------ | ---- | ---------------- |
| name       | string | Yes   | Name of the target app account.|
| bundleName | string | Yes   | Bundle name of the app.       |

**Return value**

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

Enables an app account to access an app with the given bundle name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                               |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | Yes   | Name of the target app account.                          |
| bundleName | string                    | Yes   | Bundle name of the app.                        |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("enableAppAccess: " + JSON.stringify(err));
   });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

Enables an app account to access an app with the given bundle name. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| name       | string | Yes   | Name of the target app account.  |
| bundleName | string | Yes   | Bundle name of the app.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
       console.log('enableAppAccess Success');
  }).catch((err) => {
      console.log("enableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an app account allows app data synchronization. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                          | Mandatory  | Description                   |
| -------- | ---------------------------- | ---- | --------------------- |
| name     | string                       | Yes   | Name of the target app account.              |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result.|

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

Checks whether an app account allows app data synchronization. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| name | string | Yes   | Name of the target app account.|

**Return value**

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

Sets a credential for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                       | Mandatory  | Description           |
| -------------- | ------------------------- | ---- | ------------- |
| name           | string                    | Yes   | Name of the target app account.    |
| credentialType | string                    | Yes   | Type of the credential to set.    |
| credential     | string                    | Yes   | Credential to set.      |
| callback       | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
      console.log("setAccountCredential err: " + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;

Sets a credential for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | Name of the target app account.  |
| credentialType | string | Yes   | Type of the credential to set.|
| credential     | string | Yes   | Credential to set.   |

**Return value**

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

Sets additional information for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                       | Mandatory  | Description             |
| --------- | ------------------------- | ---- | --------------- |
| name      | string                    | Yes   | Name of the target app account.        |
| extraInfo | string                    | Yes   | Additional information to set.      |
| callback  | AsyncCallback&lt;void&gt; | Yes   | Callback used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002", (err) => { 
      console.log("setAccountExtraInfo err: " + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string): Promise&lt;void&gt;

Sets additional information for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description       |
| --------- | ------ | ---- | --------- |
| name      | string | Yes   | Name of the target app account.  |
| extraInfo | string | Yes   | Additional information to set.|

**Return value**

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

Sets whether to enable app data synchronization for an app account. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                       |
| -------- | ------------------------- | ---- | ------------------------- |
| name     | string                    | Yes   | Name of the target app account.                  |
| isEnable | boolean                   | Yes   | Whether to enable app data synchronization.              |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when app data synchronization is enabled or disabled for the app account.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAppAccountSyncEnable("ZhangSan", true, (err) => { 
      console.log("setAppAccountSyncEnable err: " + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean): Promise&lt;void&gt;

Sets whether to enable app data synchronization for an app account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type     | Mandatory  | Description         |
| -------- | ------- | ---- | ----------- |
| name     | string  | Yes   | Name of the target app account.    |
| isEnable | boolean | Yes   | Whether to enable app data synchronization.|

**Return value**

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

Sets data to be associated with an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description               |
| -------- | ------------------------- | ---- | ----------------- |
| name     | string                    | Yes   | Name of the target app account.          |
| key      | string                    | Yes   | Key of the data to set. The private key can be customized.|
| value    | string                    | Yes   | Value of the data to be set.        |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked when the data associated with the specified app account is set.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001", (err) => { 
      console.log("setAssociatedData err: " + JSON.stringify(err));
  });
  ```

### setAssociatedData

setAssociatedData(name: string, key: string, value: string): Promise&lt;void&gt;

Sets data to be associated with an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description               |
| ----- | ------ | ---- | ----------------- |
| name  | string | Yes   | Name of the target app account.          |
| key   | string | Yes   | Key of the data to set. The private key can be customized.|
| value | string | Yes   | Value of the data to be set.        |

**Return value**

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

Obtains the credentials (such as the digital password, face image, and PIN) of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                         | Mandatory  | Description            |
| -------------- | --------------------------- | ---- | -------------- |
| name           | string                      | Yes   | Name of the target app account.       |
| credentialType | string                      | Yes   | Type of the credential to obtain.|
| callback       | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the credential obtained.|

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

Obtains the credential of an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | Name of the target app account.   |
| credentialType | string | Yes   | Type of the credential to obtain.|

**Return value**

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

Obtains additional information (information that can be converted into the string type) about an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| name     | string                      | Yes   | Name of the target app account.        |
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

Obtains additional information of an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| name | string | Yes   | Name of the target app account.|

**Return value**

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

Obtains data associated with an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description               |
| -------- | --------------------------- | ---- | ----------------- |
| name     | string                      | Yes   | Name of the target app account.          |
| key      | string                      | Yes   | Key of the data to obtain.        |
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

Obtains data associated with an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description       |
| ---- | ------ | ---- | --------- |
| name | string | Yes   | Name of the target app account.  |
| key  | string | Yes   | Key of the data to obtain.|

**Return value**

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

### getAssociatedDataSync<sup>9+</sup>

getAssociatedDataSync(name: string, key: string): string;

Obtains the data associated with this app account. This API returns the result synchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description       |
| ---- | ------ | ---- | --------- |
| name | string | Yes   | Name of the target app account.  |
| key  | string | Yes   | Key of the data to obtain.|

**Return value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| string | Data obtained.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var backData = appAccountManager.getAssociatedDataSync("ZhangSan", "k001");
  console.info("getAssociatedDataSync backData:" + JSON.stringify(backData));
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Obtains information about all accessible app accounts. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return information about all accessible app accounts.|

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

Obtains information about all accessible app accounts. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise used to return the result.|

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

Obtains information about all app accounts of the specified app. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| owner    | string                                   | Yes   | Owner of the app account. The value is the bundle name of the app.   |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return information about all accessible app accounts.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle, (err, data)=>{
  	console.debug("getAllAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Obtains information about all app accounts of the specified app. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description    |
| ----- | ------ | ---- | ------ |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Parameters**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise used to return the result.|

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

Subscribes to the account change events of the specified account owners. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | 'change'                                 | Yes   | Account change events to subscribe to. The subscriber will receive a notification when the account owners update their accounts.|
| owners   | Array&lt;string&gt;                      | Yes   | Account owners.                     |
| callback | Callback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return the account changes.          |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
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

Unsubscribes from the account change events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                              | Mandatory  | Description          |
| -------- | -------------------------------- | ---- | ------------ |
| type     | 'change'                         | Yes   | Account change events to unsubscribe from.   |
| callback | Callback<Array\<[AppAccountInfo](#appaccountinfo)>> | No   | Callback used to report the account changes.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
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

Authenticates an app account to obtain an Open Authorization (OAuth) token. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description             |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | Yes   | Name of the target app account.    |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string                | Yes   | Authentication type.          |
| options  | {[key: string]: any}  | Yes   | Options for the authentication.      |
| callback | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the authentication result.|

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
  appAccountManager.authenticate("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", {}, {
    onResult: onResultCallback,
    onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### getOAuthToken<sup>8+</sup>

getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the OAuth token of an app account based on the specified authentication type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description         |
| -------- | --------------------------- | ---- | ----------- |
| name     | string                      | Yes   | Name of the target app account.   |
| owner    | string                      | Yes   | Owner of the app account. The value is the bundle name of the app.|
| authType | string                      | Yes   | Authentication type.      |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result.   |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", (err, data) => {
       console.log('getOAuthToken err: ' + JSON.stringify(err));
       console.log('getOAuthToken token: ' + data);
  });
  ```

### getOAuthToken<sup>8+</sup>

getOAuthToken(name: string, owner: string, authType: string): Promise&lt;string&gt;

Obtains the OAuth token of an app account based on the specified authentication type. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description         |
| -------- | ------ | ---- | ----------- |
| name     | string | Yes   | Name of the target app account.   |
| owner    | string | Yes   | Owner of the app account. The value is the bundle name of the app.|
| authType | string | Yes   | Authentication type.      |

**Parameters**

| Type                   | Description                   |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData").then((data) => {
       console.log('getOAuthToken token: ' + data);
  }).catch((err) => {
      console.log("getOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>8+</sup>

setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Sets an OAuth token for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description      |
| -------- | ------------------------- | ---- | -------- |
| name     | string                    | Yes   | Name of the target app account.|
| authType | string                    | Yes   | Authentication type.   |
| token    | string                    | Yes   | OAuth token to set.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "getSocialData", "xxxx", (err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>8+</sup>

setOAuthToken(name: string, authType: string, token: string): Promise&lt;void&gt;

Sets an OAuth token for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| name     | string | Yes   | Name of the target app account.|
| authType | string | Yes   | Authentication type.   |
| token    | string | Yes   | OAuth token to set.|

**Parameters**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "getSocialData", "xxxx").then(() => {
      console.log('setOAuthToken successfully');
  }).catch((err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>8+</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the specified OAuth token for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description          |
| -------- | ------------------------- | ---- | ------------ |
| name     | string                    | Yes   | Name of the target app account.    |
| owner    | string                    | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string                    | Yes   | Authentication type.       |
| token    | string                    | Yes   | OAuth token to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.    |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", "xxxxx", (err) => {
       console.log('deleteOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>8+</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise&lt;void&gt;

Deletes the specified OAuth token for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description          |
| -------- | ------ | ---- | ------------ |
| name     | string | Yes   | Name of the target app account.    |
| owner    | string | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string | Yes   | Authentication type.       |
| token    | string | Yes   | OAuth token to delete.|

**Parameters**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.ohos.accountjsdemo", "getSocialData", "xxxxx").then(() => {
       console.log('deleteOAuthToken successfully');
  }).catch((err) => {
      console.log("deleteOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>8+</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the visibility of an OAuth token to an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                       |
| ---------- | ------------------------- | ---- | ------------------------- |
| name       | string                    | Yes   | Name of the target app account.                 |
| authType   | string                    | Yes   | Authentication type.                    |
| bundleName | string                    | Yes   | Bundle name of the app.             |
| isVisible  | boolean                   | Yes   | Whether the OAuth token is visible to the app. The value **true** means visible, and the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.                 |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", true, (err) => {
       console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>8+</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise&lt;void&gt;

Sets the visibility of an OAuth token to an app. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type     | Mandatory  | Description          |
| ---------- | ------- | ---- | ------------ |
| name       | string  | Yes   | Name of the target app account.    |
| authType   | string  | Yes   | Authentication type.       |
| bundleName | string  | Yes   | Bundle name of the app.|
| isVisible  | boolean | Yes   | Whether the OAuth token is visible to the app.       |

**Parameters**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", true).then(() => {
      console.log('setOAuthTokenVisibility successfully');
  }).catch((err) => {
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### checkOAuthTokenVisibility<sup>8+</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OAuth token is visible to an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                          | Mandatory  | Description         |
| ---------- | ---------------------------- | ---- | ----------- |
| name       | string                       | Yes   | Name of the target app account.   |
| authType   | string                       | Yes   | Authentication type.      |
| bundleName | string                       | Yes   | Bundle name of the app.|
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result.   |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo", (err, data) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  });
  ```

### checkOAuthTokenVisibility<sup>8+</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise&lt;boolean&gt;

Checks whether an OAuth token is visible to an app. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description           |
| ---------- | ------ | ---- | ------------- |
| name       | string | Yes   | Name of the target app account.     |
| authType   | string | Yes   | Authentication type.        |
| bundleName | string | Yes   | Bundle name of the app.|

**Parameters**

| Type                    | Description                   |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "getSocialData", "com.example.ohos.accountjsdemo").then((data) => {
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  }).catch((err) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### getAllOAuthTokens<sup>8+</sup>

getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback&lt;Array&lt;OAuthTokenInfo&gt;&gt;): void

Obtains all OAuth tokens visible to the caller for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | Yes   | Name of the target app account.   |
| owner    | string                                   | Yes   | Owner of the app account. The value is the bundle name of the app.|
| callback | AsyncCallback&lt;Array&lt; [OAuthTokenInfo](#oauthtokeninfo8)&gt;&gt; | Yes   | Callback invoked to return the result.   |

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

Obtains all OAuth tokens visible to the caller for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| name  | string | Yes   | Name of the target app account.   |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Parameters**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt; [OAuthTokenInfo](#oauthtokeninfo8)&gt;&gt; | Promise used to return the result.|

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

Obtains a list of authorized OAuth tokens of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                     |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| name     | string                                   | Yes   | Name of the target app account.               |
| authType | string                                   | Yes   | Authorization type.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback invoked to return the result.               |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "getSocialData", (err, data) => {
       console.log('getOAuthList err: ' + JSON.stringify(err));
       console.log('getOAuthList data: ' + JSON.stringify(data));
  });
  ```

### getOAuthList<sup>8+</sup>

getOAuthList(name: string, authType: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains a list of authorized OAuth tokens of an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description                     |
| -------- | ------ | ---- | ----------------------- |
| name     | string | Yes   | Name of the target app account.               |
| authType | string | Yes   | Authorization type.|

**Parameters**

| Type                                | Description                   |
| ---------------------------------- | --------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.ohos.accountjsdemo", "getSocialData").then((data) => {
       console.log('getOAuthList data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getOAuthList err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorCallback<sup>8+</sup>

getAuthenticatorCallback(sessionId: string, callback: AsyncCallback&lt;AuthenticatorCallback&gt;): void

Obtains the authenticator callback for an authentication session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string                                   | Yes   | ID of the authentication session.|
| callback  | AsyncCallback&lt;[AuthenticatorCallback](#authenticatorcallback8)&gt; | Yes   | Callback invoked to return the result.|

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
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
                      [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                      [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
        callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
    });
  });
  ```

### getAuthenticatorCallback<sup>8+</sup>

getAuthenticatorCallback(sessionId: string): Promise&lt;AuthenticatorCallback&gt;

Obtains the authenticator callback for an authentication session. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description      |
| --------- | ------ | ---- | -------- |
| sessionId | string | Yes   | ID of the authentication session.|

**Parameters**

| Type                                  | Description                   |
| ------------------------------------ | --------------------- |
| Promise&lt;[AuthenticatorCallback](#authenticatorcallback8)&gt; | Promise used to return the result.|

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  const appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant().then((want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
          var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                        [account_appAccount.Constants.KEY_OWNER]: "com.example.ohos.accountjsdemo",
                        [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                        [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }).catch((err) => {
          console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
      });
  }).catch((err) => {
      console.log("getWant err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorInfo<sup>8+</sup>

getAuthenticatorInfo(owner: string, callback: AsyncCallback&lt;AuthenticatorInfo&gt;): void

Obtains authenticator information of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                    | Mandatory  | Description         |
| -------- | -------------------------------------- | ---- | ----------- |
| owner    | string                                 | Yes   | Owner of the app account. The value is the bundle name of the app.|
| callback | AsyncCallback&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Yes   | Callback invoked to return the result.   |

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

Obtains authenticator information of an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Parameters**

| Type                              | Description                   |
| -------------------------------- | --------------------- |
| Promise&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.ohos.accountjsdemo").then((data) => { 
       console.log('getAuthenticatorInfo: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccess<sup>9+</sup>

checkAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an app account is authorized to access an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                        | Mandatory | Description            |
| ---------- | ---------------------------- | ----- | ---------------- |
| name       | string                       | Yes   | Name of the target app account.  |
| bundleName | string                       | Yes   | Bundle name of the app to access. |
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result.  |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccess("zhangsan", "com.example.ohos.accountjsdemo", (err, data) => {
      console.log('checkAppAccess: ' + JSON.stringify(data));
      console.log("checkAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccess<sup>9+</sup>

checkAppAccess(name: string, bundleName: string): Promise&lt;boolean&gt;

Checks whether an app account is authorized to access an app. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type  | Mandatory  | Description            |
| ---------- | ------ | ----- | ---------------- |
| name       | string | Yes   | Name of the target app account.  |
| bundleName | string | Yes   | Bundle name of the app to access. |

**Parameters**

| Type                  | Description                             |
| ---------------------- | --------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccess("zhangsan", "com.example.ohos.accountjsdemo").then((data) => {
       console.log('checkAppAccess: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("checkAppAccess err: "  + JSON.stringify(err));
  });
  ```

### deleteAccountCredential<sup>9+</sup>

deleteAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the credential of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description           |
| -------------- | ------------------------- | ----- | -------------- |
| name           | string                    | Yes   | Name of the target app account.|
| credentialType | string                    | Yes   | Type of the credential to delete.     |
| callback       | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccountCredential("zhangsan", "pin", (err, data) => {
      console.log('deleteAccountCredential: ' + JSON.stringify(data));
      console.log("deleteAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### deleteAccountCredential<sup>9+</sup>

deleteAccountCredential(name: string, credentialType: string): Promise&lt;void&gt;

Deletes the credential of an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type  | Mandatory  | Description           |
| -------------- | ------ | ----- | --------------- |
| name           | string | Yes   | Name of the target app account.|
| credentialType | string | Yes   | Type of the credential to delete.      |

**Parameters**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccountCredential("zhangsan", "pin").then((data) => {
       console.log('deleteAccountCredential: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("deleteAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, owner: string, labels: Array&lt;string&gt;, callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether an app account has specific labels. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description            |
| -------------- | ------------------------- | ----- | --------------- |
| name           | string                    | Yes   | Name of the target app account. |
| owner          | string                    | Yes   | Owner of the app account. The value is the bundle name of the app.|
| labels         | Array&lt;string&gt;       | Yes   | Labels to check.      |
| callback       | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var labels = ["student"];
  appAccountManager.checkAccountLabels("zhangsan", "com.example.ohos.accountjsdemo", labels, (err, data) => {
      console.log('checkAccountLabels: ' + JSON.stringify(data));
      console.log("checkAccountLabels err: "  + JSON.stringify(err));
  });
  ```

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, owner: string, labels: Array&lt;string&gt;): Promise&lt;boolean&gt;

Checks whether an app account has specific labels. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description            |
| -------------- | ------------------------- | ----- | --------------- |
| name           | string                    | Yes   | Name of the target app account. |
| owner          | string                    | Yes   | Owner of the app account. The value is the bundle name of the app.|
| labels         | Array&lt;string&gt;       | Yes   | Labels to check.      |

**Parameters**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var labels = ["student"];
  appAccountManager.checkAccountLabels("zhangsan", "com.example.ohos.accountjsdemo", labels).then((data) => {
       console.log('checkAccountLabels: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("checkAccountLabels err: "  + JSON.stringify(err));
  });
  ```

### selectAccountsByOptions<sup>9+</sup>

selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;);

Selects the accounts accessible to the requester based on the options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                                | Mandatory | Description            |
| -------------- | ----------------------------------- | ----- | --------------- |
| options        | SelectAccountsOptions               | Yes   | Options for selecting accounts.  |
| callback       | AsyncCallback&lt;[AppAccountInfo](#appaccountinfo)&gt; | Yes   | Callback invoked to return the result. |

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    allowedOwners: ["com.example.ohos.accountjsdemo"]
  };
  appAccountManager.selectAccountsByOptions(options, (err, data) => {
      console.log('selectAccountsByOptions: ' + JSON.stringify(data));
      console.log("selectAccountsByOptions err: "  + JSON.stringify(err));
  });
  ```

### selectAccountsByOptions<sup>9+</sup>

selectAccountsByOptions(options: SelectAccountsOptions): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Selects the accounts accessible to the requester based on the options. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description            |
| -------------- | ------------------------- | ----- | --------------- |
| options        | [SelectAccountsOptions](#selectaccountsoptions9)     | Yes   | Options for selecting accounts.  |

**Parameters**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;[AppAccountInfo](#appaccountinfo)&gt; | Promise used to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    allowedOwners: ["com.example.ohos.accountjsdemo"]
  };
  appAccountManager.selectAccountsByOptions(options).then((data) => {
       console.log('selectAccountsByOptions: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("selectAccountsByOptions err: "  + JSON.stringify(err));
  });
  ```

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, owner: string, callback: AuthenticatorCallback): void;

Verifies the user credential. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                 | Mandatory | Description                    |
| -------- | --------------------- | ----- | ----------------------- |
| name     | string                | Yes   | Name of the target app account.         |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app.       |
| callback | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the verification result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.verifyCredential("zhangsan", "com.example.ohos.accountjsdemo", {
    onResult: (resultCode, result) => {
      console.log("verifyCredential onResult, resultCode:" + JSON.stringify(resultCode));
      console.log("verifyCredential onResult, result:" + JSON.stringify(result));
    },
    onRequestRedirected: (request) => {
      console.log("verifyCredential onRequestRedirected, request:" + JSON.stringify(request));
    }
  });
  ```

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void;

Verifies the user credential. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                   | Mandatory | Description                    |
| -------- | ----------------------- | ----- | ----------------------- |
| name     | string                  | Yes   | Name of the target app account.         |
| owner    | string                  | Yes   | Owner of the app account. The value is the bundle name of the app.       |
| options  | [VerifyCredentialOptions](#verifycredentialoptions9) | Yes   | Options for verifying the user credential.         |
| callback | [AuthenticatorCallback](#authenticatorcallback8)   | Yes   | Authenticator callback invoked to return the verification result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    credentialType: "pin",
    credential: "123456"
  };
  appAccountManager.verifyCredential("zhangsan", "com.example.ohos.accountjsdemo", options, {
    onResult: (resultCode, result) => {
      console.log("verifyCredential onResult, resultCode:" + JSON.stringify(resultCode));
      console.log("verifyCredential onResult, result:" + JSON.stringify(result));
    },
    onRequestRedirected: (request) => {
      console.log("verifyCredential onRequestRedirected, request:" + JSON.stringify(request));
    }
  });
  ```

### setAuthenticatorProperties<sup>9+</sup>

setAuthenticatorProperties(owner: string, callback: AuthenticatorCallback): void;

Sets authenticator properties. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                 | Mandatory | Description                    |
| -------- | --------------------- | ----- | ----------------------- |
| owner    | string                | Yes   | Owner of the authenticator.         |
| options  | [SetPropertiesOptions](#setpropertiesoptions9)  | Yes   | Authenticator properties to set.         |
| callback | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAuthenticatorProperties("com.example.ohos.accountjsdemo", {
    onResult: (resultCode, result) => {
      console.log("setAuthenticatorProperties onResult, resultCode:" + JSON.stringify(resultCode));
      console.log("setAuthenticatorProperties onResult, result:" + JSON.stringify(result));
    },
    onRequestRedirected: (request) => {
      console.log("setAuthenticatorProperties onRequestRedirected, request:" + JSON.stringify(request));
    }
  });
  ```

### setAuthenticatorProperties<sup>9+</sup>

setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthenticatorCallback): void;

Sets authenticator properties. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                 | Mandatory | Description                    |
| -------- | --------------------- | ----- | ----------------------- |
| owner    | string                | Yes   | Owner of the authenticator.         |
| options  | [SetPropertiesOptions](#setpropertiesoptions9)  | Yes   | Authenticator properties to set.         |
| callback | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the result.|

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var options = {
    properties: {"prop1": "value1"}
  };
  appAccountManager.setAuthenticatorProperties("com.example.ohos.accountjsdemo", options, {
    onResult: (resultCode, result) => {
      console.log("setAuthenticatorProperties onResult, resultCode:" + JSON.stringify(resultCode));
      console.log("setAuthenticatorProperties onResult, result:" + JSON.stringify(result));
    },
    onRequestRedirected: (request) => {
      console.log("setAuthenticatorProperties onRequestRedirected, request:" + JSON.stringify(request));
    }
  });
  ```

## AppAccountInfo

Defines app account information.

**System capability**: SystemCapability.Account.AppAccount

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|
| name  | string | Yes   | Name of the app account. |

## OAuthTokenInfo<sup>8+</sup>

Defines OAuth token information.

**System capability**: SystemCapability.Account.AppAccount

| Name              | Type           | Mandatory | Description             |
| -------------------- | -------------- | ----- | ---------------- |
| authType             | string         | Yes   | Authentication type.  |
| token                | string         | Yes   | Value of the token.      |
| account<sup>9+</sup> | AppAccountInfo | No   | Account information of the token.|

## AuthenticatorInfo<sup>8+</sup>

Defines OAuth authenticator information.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type    | Mandatory  | Description        |
| ------- | ------ | ---- | ---------- |
| owner   | string | Yes   | Owner of the authenticator. The value is the bundle name of the app.|
| iconId  | number | Yes   | ID of the authenticator icon. |
| labelId | number | Yes   | ID of the authenticator label. |

## SelectAccountsOptions<sup>9+</sup>

Represents the options for selecting accounts.

**System capability**: SystemCapability.Account.AppAccount

| Name         | Type                        | Mandatory | Description               |
| --------------- | --------------------------- | ----- | ------------------- |
| allowedAccounts | Array&lt;[AppAccountInfo](#appaccountinfo)&gt; | No   | Allowed accounts.     |
| allowedOwners   | Array&lt;string&gt;         | No   | Allowed account owners.|
| requiredLabels  | Array&lt;string&gt;         | No   | Labels required for the authenticator.   |

## VerifyCredentialOptions<sup>9+</sup>

Represents the options for verifying the user credential.

**System capability**: SystemCapability.Account.AppAccount

| Name         | Type                  | Mandatory | Description          |
| -------------- | ---------------------- | ----- | -------------- |
| credentialType | string                 | No   | Type of the credential to verify.     |
| credential     | string                 | No   | Credential value.     |
| parameters     | {[key:string]: Object} | No   | Customized parameters.|


## SetPropertiesOptions<sup>9+</sup>

Represents the options for setting authenticator properties.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type                   | Mandatory | Description          |
| ---------- | ---------------------- | ----- | -------------- |
| properties | {[key:string]: Object} | No   | Authenticator properties.     |
| parameters | {[key:string]: Object} | No   | Customized parameters.|

## Constants<sup>8+</sup>

Enumerates the constants.

**System capability**: SystemCapability.Account.AppAccount

| Name                           | Default Value                   | Description                  |
| -------------------------------- | ---------------------- | ----------------------- |
| ACTION_ADD_ACCOUNT_IMPLICITLY    | "addAccountImplicitly" | Operation of adding an account implicitly. |
| ACTION_AUTHENTICATE              | "authenticate"         | Authentication operation.        |
| KEY_NAME                         | "name"                 | App account name. |
| KEY_OWNER                        | "owner"                | Owner of an app account.|
| KEY_TOKEN                        | "token"                | Token.        |
| KEY_ACTION                       | "action"               | Operation.        |
| KEY_AUTH_TYPE                    | "authType"             | Authentication type.    |
| KEY_SESSION_ID                   | "sessionId"            | Session ID.    |
| KEY_CALLER_PID                   | "callerPid"            | PID of the caller.   |
| KEY_CALLER_UID                   | "callerUid"            | UID of the caller.   |
| KEY_CALLER_BUNDLE_NAME           | "callerBundleName"     | Bundle name of the caller.   |
| KEY_REQUIRED_LABELS<sup>9+</sup> | "requiredLabels"       | Required labels.   |
| KEY_BOOLEAN_RESULT<sup>9+</sup>  | "booleanResult"        | Return value of the Boolean type.   |

## ResultCode<sup>8+</sup>

Enumerates the result codes.

**System capability**: SystemCapability.Account.AppAccount

| Name                                 | Default Value  | Description          |
| ----------------------------------- | ----- | ------------ |
| SUCCESS                             | 0     | The operation is successful.     |
| ERROR_ACCOUNT_NOT_EXIST             | 10001 | The app account does not exist.  |
| ERROR_APP_ACCOUNT_SERVICE_EXCEPTION | 10002 | The **AppAccountManager** service is abnormal. |
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
| ERROR_OAUTH_TOKEN_NOT_EXIST         | 10014 | The OAuth token does not exist.|
| ERROR_OAUTH_TOKEN_TOO_MANY          | 10015 | The number of OAuth tokens reaches the limit. |
| ERROR_OAUTH_UNSUPPORT_ACTION        | 10016 | The authentication operation is not supported. |
| ERROR_OAUTH_UNSUPPORT_AUTH_TYPE     | 10017 | The authentication type is not supported. |
| ERROR_PERMISSION_DENIED             | 10018 | The required permission is missing.     |

## AuthenticatorCallback<sup>8+</sup>

Provides OAuth authenticator callbacks.

### onResult<sup>8+</sup>

onResult: (code: number, result: {[key: string]: any}) =&gt; void

Called to return the result of an authentication request.

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
                    [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                    [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
      callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
  }).catch((err) => {
      console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
  });
  ```

### onRequestRedirected<sup>8+</sup>

onRequestRedirected: (request: Want) =&gt; void

Called to redirect a request.

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

### onRequestContinued<sup>9+</sup>

onRequestContinued?: () =&gt; void

Called to continue to process the request.

**System capability**: SystemCapability.Account.AppAccount

**Example**

  ```js
  const appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
      callback.onRequestContinued();
  }).catch((err) => {
      console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
  });
  ```

## Authenticator<sup>8+</sup>

Provides APIs to operate the authenticator.

### addAccountImplicitly<sup>8+</sup>

addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Implicitly adds an app account based on the specified authentication type and options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| authType         | string                | Yes   | Authentication type.     |
| callerBundleName | string                | Yes   | Bundle name of the authentication requester.      |
| options          | {[key: string]: any}  | Yes   | Options for the authentication.     |
| callback         | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the authentication result.|

### authenticate<sup>8+</sup>

authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Authenticates an app account to obtain the OAuth token. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name             | string                | Yes   | Name of the target app account.       |
| authType         | string                | Yes   | Authentication type.     |
| callerBundleName | string                | Yes   | Bundle name of the authentication requester.      |
| options          | {[key: string]: any}  | Yes   | Options for the authentication.     |
| callback         | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the authentication result.|

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthenticatorCallback): void;

Verifies the credential of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                   | Yes   | Name of the target app account.             |
| options   | [VerifyCredentialOptions](#verifycredentialoptions9)  | Yes   | Options for credential verification.           |
| callback  | [AuthenticatorCallback](#authenticatorcallback8)    | Yes   | Authenticator callback invoked to return the verification result.|

### setProperties<sup>9+</sup>

setProperties(options: SetPropertiesOptions, callback: AuthenticatorCallback): void;

Sets authenticator properties. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| options   | [SetPropertiesOptions](#setpropertiesoptions9)  | Yes   | Authenticator properties to set.           |
| callback  | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the result.|

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, labels: Array&lt;string&gt;, callback: AuthenticatorCallback): void;

Checks the account labels. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                | Yes   | Name of the target app account.             |
| labels    | Array&lt;string&gt;          | Yes   | Labels to check.                  |
| callback  | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the check result.|

### isAccountRemovable<sup>9+</sup>

isAccountRemovable(name: string, callback: AuthenticatorCallback): void;

Checks whether an app account can be deleted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                | Yes   | Name of the target app account.             |
| callback  | [AuthenticatorCallback](#authenticatorcallback8) | Yes   | Authenticator callback invoked to return the result.|

### getRemoteObject<sup>9+</sup>

getRemoteObject(): rpc.RemoteObject;

Obtains the remote object of an authenticator. This API cannot be overloaded.

**System capability**: SystemCapability.Account.AppAccount

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

      verifyCredential(name, options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.ohos.accountjsdemo",
              abilityName: "com.example.ohos.accountjsdemo.VerifyAbility",
              parameters: {
                name: name
              }
          });
      }

      setProperties(options, callback) {
          callback.onResult(account_appAccount.ResultCode.SUCCESS, {});
      }

      checkAccountLabels(name, labels, callback) {
          var result = {[account_appAccount.Constants.KEY_BOOLEAN_RESULT]: false};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
    
      isAccountRemovable(name, callback) {
          var result = {[account_appAccount.Constants.KEY_BOOLEAN_RESULT]: true};
          callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      }
  }
  var authenticator = null;
  export default {
      onConnect(want) {
          authenticator = new MyAuthenticator();
          return authenticator.getRemoteObject();
      }
  }
  ```
