#  	Application Account Management

> ![icon-note.gif](figures/icon-note.gif) **Note:**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import account_appAccount from '@ohos.account.appAccount';
```


## account_appAccount.createAppAccountManager

createAppAccountManager(): AppAccountManager;

Creates an **AppAccountManager** instance.

- Return value
  | Type| Description|
  | -------- | -------- |
  | AppAccountManager | **AppAccountManager** instance created.|

- Example
  ```
  var appAccountManager = account.createAppAccountManager();
  ```

## AppAccountManager

Provides methods to manage application accounts.

### addAccount

addAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;

Adds an application account to the account management service. This method uses an asynchronous callback to return the result.

Required permission: none.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------- | ---- | ------------------------------------------ |
  | name     | string              | Yes| Name of the application account to add.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the application account is added.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("WangWu", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount

addAccount(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void;

Adds an application account and its additional information to the account management service. This method uses an asynchronous callback to return the result.

Required permission: none.

- Parameters

  | Name| Type| Mandatory| Description|
  | --------- | ------------------- | ---- | ------------------------------------------------------------ |
  | name      | string              | Yes| Name of the application account to add.|
  | extraInfo | string              | Yes| Additional information (for example, token) of the application account to add. The additional information cannot contain sensitive information about the application account.|
  | callback  | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the application account and its additional information are added.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```



### addAccount

addAccount(name: string, extraInfo?: string): Promise&lt;void&gt;;

Adds an application account and its additional information to the account management service. This method uses a promise to return the result asynchronously.

Required permission: none.

- Parameters

  | Name| Type| Mandatory| Description|
  | --------- | ------ | ---- | ------------------------------------------------------------ |
  | name      | string | Yes| Name of the application account to add.|
  | extraInfo | string | Yes| Additional information of the application account to add. The additional information cannot contain sensitive information about the application account.|

- Return value

  | Type| Description|
  | ------------- | ---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101").then(()=> { 
      console.log('addAccount Success');
  }).catch((err) => {
      console.log("addAccount err: "  + JSON.stringify(err));
  });
  ```

### deleteAccount

deleteAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;

Deletes an application account from the account management service. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------- | ---- | ---------------------------------- |
  | name     | string              | Yes| Name of the application account to delete.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the application account is deleted.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu", (err) => { 
      console.log("deleteAccount err: " + JSON.stringify(err));
   });
  ```

### deleteAccount

deleteAccount(name: string): Promise&lt;void&gt;;

Deletes an application account from the account management service. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ------------------------ |
  | name   | string | Yes| Name of the application account to delete.|

- Return value

  | Type| Description|
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu").then(() => { 
        console.log('deleteAccount Success');
   }).catch((err) => {
      console.log("deleteAccount err: "  + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

Disables the specified third-party application account from accessing the third-party application with the given bundle name. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------------------- | ---- | ------------------------------------------------------------ |
  | name       | string              | Yes| Name of the third-party application account.|
  | bundleName | string              | Yes| Bundle name of the third-party application.|
  | callback   | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the third-party application account is disabled from accessing the third-party application with the given bundle name.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("disableAppAccess err: " + JSON.stringify(err));
  });
  ```

### disableAppAccess

disableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;;

Disables the specified third-party application account from accessing the third-party application with the given bundle name. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------ | ---- | ---------------------------------- |
  | name       | string | Yes| Name of the third-party application account.|
  | bundleName | string | Yes| Bundle name of a third-party application.|

- Return value

  | Type| Description|
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
      console.log('disableAppAccess Success');
  }).catch((err) => {
      console.log("disableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void;

Enables the specified third-party application account to access the third-party application with the given bundle name. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------------------- | ---- | ------------------------------------------------------------ |
  | name       | string              | Yes| Application account name.|
  | bundleName | string              | Yes| Bundle name of the third-party application.|
  | callback   | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the third-party application account is enabled to access the third-party application with the given bundle name.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo", (err) => { 
      console.log("enableAppAccess: " + JSON.stringify(err));
   });
  ```

### enableAppAccess

enableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;;

Enables the specified third-party application account to access the third-party application with the given bundle name. This method uses a promise to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | ---------- | ------ | ---- | ------------------ |
  | name       | string | Yes| Application account name.|
  | bundleName | string | Yes| Bundle name of the third-party application.|

- Return value

  | Type| Description|
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  app_account_instance.enableAppAccess("ZhangSan", "com.example.ohos.accountjsdemo").then(() => { 
       console.log('enableAppAccess Success');
  }).catch((err) => {
      console.log("enableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string, callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether the specified application account allows application data synchronization. This method uses an asynchronous callback to return the result.

The **ohos.permission.DISTRIBUTED_DATASYNC** permission is required. This permission is intended for system applications only.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ---------------------- | ---- | -------------------------------------------- |
  | name     | string                 | Yes| Application account name.|
  | callback | AsyncCallback&lt;boolean&gt; | Yes| Callback invoked to specify whether the application account allows application data synchronization.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan", (err, result) => { 
      console.log("checkAppAccountSyncEnable err: " + JSON.stringify(err));
      console.log('checkAppAccountSyncEnable result: ' + result);
  });
  ```

### checkAppAccountSyncEnable

checkAppAccountSyncEnable(name: string): Promise&lt;boolean&gt;;

Checks whether the specified application account allows application data synchronization. This method uses a promise to return the result asynchronously.

The **ohos.permission.DISTRIBUTED_DATASYNC** permission is required. This permission is intended for system applications only.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------- |
  | name   | string | Yes| Application account name.|

- Return value

  | Type| Description|
  | :--------------- | :---------------------------------- |
  | Promise&lt;boolean&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan").then((data) => { 
      console.log('checkAppAccountSyncEnable, result: ' + data);
  }).catch((err) => {
      console.log("checkAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void;

Sets a credential for an application account. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------------- | ------------------- | ---- | ---------------------------- |
  | name           | string              | Yes| Application account name.|
  | credentialType | string              | Yes| Type of the credential to set.|
  | credential     | string              | Yes| Credential to set.|
  | callback       | AsyncCallback&lt;void&gt; | Yes| Callback invoked when a credential is set for the specified application account.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
      console.log("setAccountCredential err: " + JSON.stringify(err));
  });
  ```

### setAccountCredential

setAccountCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;;

Sets a credential for an application account. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------------- | ------ | ---- | -------------------- |
  | name           | string | Yes| Application account name.|
  | credentialType | string | Yes| Type of the credential to set.|
  | credential     | string | Yes| Credential to set.|

- Return value

  | Type| Description|
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001").then(() => { 
      console.log('setAccountCredential Success');
  }).catch((err) => {
      console.log("setAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void;

Sets additional information for an application account. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | --------- | ------------------- | ---- | -------------------------------- |
  | name      | string              | Yes| Application account name.|
  | extraInfo | string              | Yes| Additional information to set.|
  | callback  | AsyncCallback&lt;void&gt; | Yes| Callback invoked when additional information is set for the specified application account.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002", (err) => { 
      console.log("setAccountExtraInfo err: " + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo

setAccountExtraInfo(name: string, extraInfo: string): Promise&lt;void&gt;;

Sets additional information for an application account. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | --------- | ------ | ---- | ------------------ |
  | name      | string | Yes| Application account name.|
  | extraInfo | string | Yes| Additional information to set.|

- Return value

  | Type| Description|
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002").then(() => { 
      console.log('setAccountExtraInfo Success');
  }).catch((err) => {
      console.log("setAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void;

Sets whether to enable application data synchronization for an application account. This method uses an asynchronous callback to return the result.

The **ohos.permission.DISTRIBUTED_DATASYNC** permission is required. This permission is intended for system applications only.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------- | ---- | -------------------------------------------------- |
  | name     | string              | Yes| Application account name.|
  | isEnable | boolean             | Yes| Specifies whether to enable application data synchronization.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked when application data synchronization is enabled or disabled for the application account.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAppAccountSyncEnable("ZhangSan", true, (err) => { 
      console.log("setAppAccountSyncEnable err: " + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable

setAppAccountSyncEnable(name: string, isEnable: boolean): Promise&lt;void&gt;;

Sets whether to enable application data synchronization for an application account. This method uses a promise to return the result asynchronously.

The **ohos.permission.DISTRIBUTED_DATASYNC** permission is required. This permission is intended for system applications only.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------- | ---- | ---------------------- |
  | name     | string  | Yes| Application account name.|
  | isEnable | boolean | Yes| Specifies whether to enable application data synchronization.|

- Return value

  | Type| Description|
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager .setAppAccountSyncEnable("ZhangSan", true).then(() => { 
      console.log('setAppAccountSyncEnable Success');
  }).catch((err) => {
      console.log("setAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAssociatedData

setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void;

Sets data to be associated with an application account. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------- | ---- | ---------------------------------- |
  | name     | string              | Yes| Application account name.|
  | key      | string              | Yes| Key of the data to set. The private key can be customized.|
  | value    | string              | Yes| Value of the data to be set.|
  | callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked when the data associated with the specified application account is set.|

- Example

  ```
  app_account_instance.setAssociatedData("ZhangSan", "k001", "v001", (err) => { 
      console.log("setAssociatedData err: " + JSON.stringify(err));
  });
  ```

### setAssociatedData

setAssociatedData(name: string, key: string, value: string): Promise&lt;void&gt;;

Sets data to be associated with an application account. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ---------------------------------- |
  | name   | string | Yes| Application account name.|
  | key    | string | Yes| Key of the data to set. The private key can be customized.|
  | value  | string | Yes| Value of the data to be set.|

- Return value

  | Type| Description|
  | :------------ | :---------------------------------- |
  | Promise&lt;void&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001").then(() => { 
      console.log('setAssociatedData Success');
  }).catch((err) => {
      console.log("setAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void;

Obtains the credential of an application account. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------------- | --------------------- | ---- | ---------------------------- |
  | name           | string                | Yes| Application account name.|
  | credentialType | string                | Yes| Type of the credential to obtain.|
  | callback       | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the credential of the specified application account.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001", (err, result) => { 
      console.log("getAccountCredential err: " + JSON.stringify(err));
      console.log('getAccountCredential result: ' + result);
  });
  ```

### getAccountCredential

getAccountCredential(name: string, credentialType: string): Promise&lt;string&gt;;

Obtains the credential of an application account. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------------- | ------ | ---- | -------------------- |
  | name           | string | Yes| Application account name.|
  | credentialType | string | Yes| Type of the credential to obtain.|

- Return value

  | Type| Description|
  | :-------------- | :---------------------------------- |
  | Promise&lt;string&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001").then((data) => { 
      console.log('getAccountCredential, result: ' + data);
  }).catch((err) => {
      console.log("getAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### getAccountExtraInfo

getAccountExtraInfo(name: string, callback: AsyncCallback&lt;string&gt;): void;

Obtains additional information of an application account. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | --------------------- | ---- | -------------------------------- |
  | name     | string                | Yes| Application account name.|
  | callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the additional information of the specified application account.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan", (err, result) => { 
      console.log("getAccountExtraInfo err: " + JSON.stringify(err));
      console.log('getAccountExtraInfo result: ' + result);
  });
  ```

### getAccountExtraInfo

getAccountExtraInfo(name: string): Promise&lt;string&gt;;

Obtains additional information of an application account. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | -------------- |
  | name   | string | Yes| Application account name.|

- Return value

  | Type| Description|
  | :-------------- | :---------------------------------- |
  | Promise&lt;string&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan").then((data) => { 
      console.log('getAccountExtraInfo, result: ' + data);
  }).catch((err) => {
      console.log("getAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### getAssociatedData

getAssociatedData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void;

Obtains data associated with an application account. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | --------------------- | ---- | ---------------------------------- |
  | name     | string                | Yes| Application account name.|
  | key      | string                | Yes| Key of the data to be obtained.|
  | callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the data associated with the specified application account.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001", (err, result) => { 
      console.log("getAssociatedData err: " + JSON.stringify(err));
      console.log('getAssociatedData result: ' + result);
  });
  ```

### getAssociatedData

getAssociatedData(name: string, key: string): Promise&lt;string&gt;;

Obtains data associated with an application account. This method uses a promise to return the result asynchronously.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ------------------- |
  | name   | string | Yes| Application account name.|
  | key    | string | Yes| Key of the data to obtain.|

- Return value

  | Type| Description|
  | :-------------- | :---------------------------------- |
  | Promise&lt;string&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001").then((data) => { 
       console.log('getAssociatedData: ' + data);
  }).catch((err) => {
      console.log("getAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;

Obtains information about all accessible accounts. This method uses an asynchronous callback to return the result.

The **ohos.permission.GET_ACCOUNTS_PRIVILEGED** permission is required. This permission is intended for system applications only.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------ | ---- | ---------------- |
  | callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | Yes| Callback invoked to return information about all accessible accounts.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts((err, data)=>{
  	console.debug("getAllAccessibleAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccessibleAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccessibleAccounts

getAllAccessibleAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

Obtains information about all accessible accounts. This method uses a promise to return the result.

The **ohos.permission.GET_ACCOUNTS_PRIVILEGED** permission is required. This permission is intended for system applications only.

- Parameters

  | Type| Description|
  | ------------------------------ | ----------------------------------- |
  | Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts().then((data) => { 
       console.log('getAllAccessibleAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccessibleAccounts err: "  + JSON.stringify(err));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;

Obtains information about all accounts of the specified account owner. This method uses an asynchronous callback to return the result.

The **ohos.permission.GET_ACCOUNTS_PRIVILEGED** permission is required. This permission is intended for system applications only.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------------ | ---- | ---------------- |
  | owner    | string                               | Yes| Owner of a system application account or third-party application account.|
  | callback | AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt; | Yes| Callback invoked to return information about all accounts of the specified account owner.|

- Example

  ```
  const appAccountManager = account.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle, (err, data)=>{
  	console.debug("getAllAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccounts

getAllAccounts(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

Obtains information about all accounts of the specified account owner. This method uses a promise to return the result.

The **ohos.permission.GET_ACCOUNTS_PRIVILEGED** permission is required. This permission is intended for system applications only.

- Parameters

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ---- | ---------- |
  | owner  | string | Yes| Owner of a system application account or third-party application account.|

- Parameters

  | Type| Description|
  | ------------------------------ | ----------------------------------- |
  | Promise&lt;Array&lt;AppAccountInfo&gt;&gt; | Promise used to return the result.|

- Example

  ```
  const appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle).then((data) => { 
       console.log('getAllAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccounts err: "  + JSON.stringify(err));
  });
  ```

### on('change')

on(type: 'change', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;

Subscribes to the account change event of the specified account owners. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | ------------------------------- | ---- | ------------------------------------------------------------ |
  | type     | 'change'                        | Yes| Type of the event to subscribe to. The subscriber will receive a notification when the account owner updates the account.|
  | owners   | Array&lt;string&gt;                   | Yes| Owners of the account.|
  | callback | Callback&lt;Array&lt;AppAccountInfo&gt;&gt; | Yes| Callback invoked to return the account change.|

- Example

  ```
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

off(type: 'change', callback?: Callback&lt;void&gt;): void;

Unsubscribes from the account change event. This method uses an asynchronous callback to return the result.

- Parameters

  | Name| Type| Mandatory| Description|
  | -------- | -------------------- | ---- | ------------------------ |
  | type     | 'change'             | Yes| Account change event.|
  | callback | Callback&lt;void&gt; | No| Callback used to report the account change.|

- Example

  ```
  const appAccountManager = account.createAppAccountManager();
  function changeOnCallback(data){
  	console.debug("receive change data:" + JSON.stringify(data));
  	appAccountManager.off('change', function(){
  		console.debug("off finish");
  	}
  }
  try{
  	appAccountManager.on('change', ["com.example.actsaccounttest"], changeOnCallback);
  }
  catch(err){
  	console.error("on accountOnOffDemo err:" + JSON.stringify(err));
  }
  ```

## AppAccountInfo



| Name| Type| Mandatory| Description|
| ------ | ------ | ---- | ------------------ |
| owner  | string | Yes| Owner of an application account.|
| name   | string | Yes| Name of an application account.|
