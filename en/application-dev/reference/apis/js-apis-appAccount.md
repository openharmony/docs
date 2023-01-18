# @ohos.account.appAccount

The **appAccount** module provides APIs for adding, deleting, modifying, and querying app account information, and supports inter-app authentication and distributed data synchronization.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import account_appAccount from '@ohos.account.appAccount';
```


## account_appAccount.createAppAccountManager

createAppAccountManager(): AppAccountManager

Creates an **AppAccountManager** object.

**System capability**: SystemCapability.Account.AppAccount

**Return value**

| Type               | Description          |
| ----------------- | ------------ |
| AppAccountManager | **AppAccountManager** object created.|

**Example**
  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  ```

## AppAccountManager

Implements app account management.

### createAccount<sup>9+</sup>

createAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;

Creates an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory | Description              |
| -------- | ------------------------- | ----- | -------------------- |
| name     | string                    | Yes   | Name of the app account to create.         |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name. |
| 12300004 | Account already exists. |
| 12300007 | The number of accounts reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.createAccount("WangWu", (err) => { 
        console.log("createAccount err: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("createAccount err: " + JSON.stringify(err));
  }
  ```

### createAccount<sup>9+</sup>

createAccount(name: string, options: CreateAccountOptions, callback: AsyncCallback&lt;void&gt;): void

Creates an app account with custom data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| name      | string                    | Yes   | Name of the app account to create.                             |
| options | [CreateAccountOptions](#createaccountoptions9) | Yes   | Options for creating the app account. You can customize data based on service requirements, but do not add sensitive data (such as passwords and tokens).|
| callback  | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.            |

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or options. |
| 12300004 | Account already exists. |
| 12300007 | The number of accounts reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let options = {
    customData: {
      "age": "10"
    }
  }
  try {
    appAccountManager.createAccount("LiSi", options, (err) => {
      if (err) {
        console.log("createAccount failed, error: " + JSON.stringify(err));
      } else {
        console.log("createAccount successfully");
      }
    });
  } catch(err) {
    console.log("createAccount exception: " + JSON.stringify(err));
  }
  ```

### createAccount<sup>9+</sup>

createAccount(name: string, options?: CreateAccountOptions): Promise&lt;void&gt;

Creates an app account with custom data. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description                                      |
| --------- | ------ | ---- | ---------------------------------------- |
| name      | string | Yes   | Name of the app account to create.                             |
| options | [CreateAccountOptions](#createaccountoptions9) | No   | Options for creating the app account. You can customize data based on service requirements, but do not add sensitive data (such as passwords and tokens). This parameter can be left empty.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or options. |
| 12300004 | Account already exists. |
| 12300007 | The number of accounts reaches the upper limit. |
| 12400003 | The number of custom data reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let options = {
    customData: {
      "age": "10"
    }
  }
  try {
    appAccountManager.createAccount("LiSi", options).then(() => {
      console.log("createAccount successfully");
    }).catch((err) => {
      console.log("createAccount failed, error: " + JSON.stringify(err));
    });
  } catch(err) {
    console.log("createAccount exception: " + JSON.stringify(err));
  }
  ```

### createAccountImplicitly<sup>9+</sup>

createAccountImplicitly(owner: string, callback: AuthCallback): void

Creates an app account implicitly based on the specified account owner. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type               | Mandatory  | Description                     |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app.         |
| callback | [AuthCallback](#authcallback9) | Yes   | Authenticator callback used to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid owner. |
| 12300007 | The number of accounts reaches the upper limit. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
    console.log("resultCode: "  + code);
    console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
    let abilityStartSetting = {want: request};
    featureAbility.startAbility(abilityStartSetting, (err) => {
      console.log("startAbility err: " + JSON.stringify(err));
    });
  }

  let appAccountManager = account_appAccount.createAppAccountManager();
  try {  
    appAccountManager.createAccountImplicitly("com.example.accountjsdemo", {
      onResult: onResultCallback,
      onRequestRedirected: onRequestRedirectedCallback
    });
  } catch (err) {
    console.log("createAccountImplicitly exception: " + JSON.stringify(err));
  }
  ```

### createAccountImplicitly<sup>9+</sup>

createAccountImplicitly(owner: string, options: CreateAccountImplicitlyOptions, callback: AuthCallback): void

Creates an app account implicitly based on the specified account owner and options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description                     |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app.         |
| options    | [CreateAccountImplicitlyOptions](#createaccountimplicitlyoptions9)   | Yes   | Options for implicitly creating the account.         |
| callback | [AuthCallback](#authcallback9) | Yes   | Authenticator callback used to return the result.        |

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or options. |
| 12300007 | The number of accounts reaches the upper limit. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, result) {
    console.log("resultCode: "  + code);
    console.log("result: "  + JSON.stringify(result));
  }

  function onRequestRedirectedCallback(request) {
    let abilityStartSetting = {want: request};
    featureAbility.startAbility(abilityStartSetting, (err) => {
      console.log("startAbility err: " + JSON.stringify(err));
    });
  }

  let appAccountManager = account_appAccount.createAppAccountManager();
  let options = {
    authType: "getSocialData",
    requiredLabels: [ "student" ]
  };
  try {
    appAccountManager.createAccountImplicitly("com.example.accountjsdemo", options, {
      onResult: onResultCallback,
      onRequestRedirected: onRequestRedirectedCallback
    });
  } catch (err) {
    console.log("createAccountImplicitly exception: " + JSON.stringify(err));
  }
  ```

### removeAccount<sup>9+</sup>

removeAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

Removes an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description              |
| -------- | ------------------------- | ---- | ---------------- |
| name     | string                    | Yes   | Name of the app account to remove.     |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.removeAccount("ZhaoLiu", (err) => {
      if (err) {
        console.log("removeAccount failed, error: " + JSON.stringify(err));
      } else {
        console.log("removeAccount successfully");
      }
   });
  } catch(err) {
    console.log("removeAccount exception: " + JSON.stringify(err));
  }
  ```

### removeAccount<sup>9+</sup>

removeAccount(name: string): Promise&lt;void&gt;

Removes an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| name | string | Yes   | Name of the app account to remove.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.removeAccount("Lisi").then(() => {
      console.log("removeAccount successfully");
    }).catch((err) => {
      console.log("removeAccount failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("removeAccount exception: " + JSON.stringify(err));
  }
  ```

### setAppAccess<sup>9+</sup>

setAppAccess(name: string, bundleName: string, isAccessible: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the access to the data of an account for an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                     | Mandatory  | Description                               |
| ------------ | ------------------------- | ---- | --------------------------------- |
| name         | string                    | Yes   | Name of the target app account.                          |
| bundleName   | string                    | Yes   | Bundle name of the app.                        |
| isAccessible | boolean                   | Yes   | Whether the access is allowed. The value **true** means to allow the access; the value **false** means the opposite.|
| callback     | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or bundleName. |
| 12300003 | Account not found. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setAppAccess("ZhangSan", "com.example.accountjsdemo", true, (err) => {
      if (err) {
        console.log("setAppAccess failed: " + JSON.stringify(err));
      } else {
        console.log("setAppAccess successfully");
      }
    });
  } catch (err) {
    console.log("setAppAccess exception: " + JSON.stringify(err));
  }
  ```

### setAppAccess<sup>9+</sup>

setAppAccess(name: string, bundleName: string, isAccessible: boolean): Promise&lt;void&gt;

Sets the access to the data of an account for an app. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| name       | string | Yes   | Name of the target app account.  |
| bundleName | string | Yes   | Bundle name of the app.|
| isAccessible | boolean | Yes   | Whether the access is allowed. The value **true** means to allow the access; the value **false** means the opposite.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or bundleName. |
| 12300003 | Account not found. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setAppAccess("ZhangSan", "com.example.accountjsdemo", true).then(() => {
      console.log("setAppAccess successfully");
    }).catch((err) => {
      console.log("setAppAccess failed: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("setAppAccess exception: " + JSON.stringify(err));
  }
  ```

### checkAppAccess<sup>9+</sup>

checkAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an app can access the data of an account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                               |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | Yes   | Name of the target app account.                          |
| bundleName | string                    | Yes   | Bundle name of the app.                        |
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. The value **true** means the app can access the account data; the value **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or bundleName. |
| 12300003 | Account not found. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.checkAppAccess("ZhangSan", "com.example.accountjsdemo", (err, isAccessible) => {
      if (err) {
        console.log("checkAppAccess failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkAppAccess successfully");
      }
    });
  } catch (err) {
    console.log("checkAppAccess exception: " + JSON.stringify(err));
  }
  ```

### checkAppAccess<sup>9+</sup>

checkAppAccess(name: string, bundleName: string): Promise&lt;boolean&gt;

Checks whether an app can access the data of an account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| name       | string | Yes   | Name of the target app account.  |
| bundleName | string | Yes   | Bundle name of the app.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the app can access the account data; the value **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or bundleName. |
| 12300003 | Account not found. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.checkAppAccess("ZhangSan", "com.example.accountjsdemo").then((isAccessible) => {
      console.log("checkAppAccess successfully, isAccessible: " + isAccessible);
    }).catch((err) => {
      console.log("checkAppAccess failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("checkAppAccess exception: " + JSON.stringify(err));
  }
  ```

### setDataSyncEnabled<sup>9+</sup>

setDataSyncEnabled(name: string, isEnabled: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets data synchronization for an app account. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                       |
| -------- | ------------------------- | ---- | ------------------------- |
| name     | string                    | Yes   | Name of the target app account.                  |
| isEnabled | boolean                   | Yes   | Whether to enable data synchronization.              |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setDataSyncEnabled("ZhangSan", true, (err) => { 
          console.log("setDataSyncEnabled err: " + JSON.stringify(err));
      });
  } catch (err) {
      console.log("setDataSyncEnabled err: " + JSON.stringify(err));
  }
  ```

### setDataSyncEnabled<sup>9+</sup>

setDataSyncEnabled(name: string, isEnabled: boolean): Promise&lt;void&gt;

Sets data synchronization for an app account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type     | Mandatory  | Description         |
| -------- | ------- | ---- | ----------- |
| name     | string  | Yes   | Name of the target app account.    |
| isEnabled | boolean | Yes   | Whether to enable data synchronization.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager .setDataSyncEnabled("ZhangSan", true).then(() => { 
          console.log('setDataSyncEnabled Success');
      }).catch((err) => {
          console.log("setDataSyncEnabled err: "  + JSON.stringify(err));
      });
  } catch (err) {
      console.log("setDataSyncEnabled err: "  + JSON.stringify(err));
  }
  ```

### checkDataSyncEnabled<sup>9+</sup>

checkDataSyncEnabled(name: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether data synchronization is enabled for an app account. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                          | Mandatory  | Description                   |
| -------- | ---------------------------- | ---- | --------------------- |
| name     | string                       | Yes   | Name of the target app account.              |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. The value **true** means data synchronization is enabled for the app account; the value **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.checkDataSyncEnabled("ZhangSan", (err, isEnabled) => {
      if (err) {
        console.log("checkDataSyncEnabled failed, err: " + JSON.stringify(err));
      } else {
        console.log('checkDataSyncEnabled successfully, isEnabled: ' + isEnabled);
      }
    });
  } catch (err) {
    console.log("checkDataSyncEnabled err: " + JSON.stringify(err));
  }
  ```

### checkDataSyncEnabled<sup>9+</sup>

checkDataSyncEnabled(name: string): Promise&lt;boolean&gt;

Checks whether data synchronization is enabled for an app account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| name | string | Yes   | Name of the target app account.|

**Return value**

| Type                    | Description                   |
| :--------------------- | :-------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means data synchronization is enabled for the app account; the value **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.checkDataSyncEnabled("ZhangSan").then((isEnabled) => {
        console.log("checkDataSyncEnabled successfully, isEnabled: " + isEnabled);
    }).catch((err) => {
      console.log("checkDataSyncEnabled failed, err: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("checkDataSyncEnabled err: " + JSON.stringify(err));
  }
  ```

### setCredential<sup>9+</sup>

setCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void

Sets a credential for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                       | Mandatory  | Description           |
| -------------- | ------------------------- | ---- | ------------- |
| name           | string                    | Yes   | Name of the target app account.    |
| credentialType | string                    | Yes   | Type of the credential to set.    |
| credential     | string                    | Yes   | Credential value.      |
| callback       | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the credential is set successfully, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or credentialType or credential. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setCredential("ZhangSan", "PIN_SIX", "xxxxxx", (err) => {
      if (err) {
        console.log("setCredential failed, error: " + JSON.stringify(err));
      } else {
        console.log("setCredential successfully");
      }
    });
  } catch (err) {
    console.log("setCredential exception: " + JSON.stringify(err));
  }
  ```

### setCredential<sup>9+</sup>

setCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;

Sets a credential for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | Name of the target app account.  |
| credentialType | string | Yes   | Type of the credential to set.|
| credential     | string | Yes   | Credential value.   |

**Return value**

| Type                | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or credentialType or credential. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setCredential("ZhangSan", "PIN_SIX", "xxxxxx").then(() => {
      console.log("setCredential successfully");
    }).catch((err) => {
      console.log("setCredential failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("setCredential exception: " + JSON.stringify(err));
  }
  ```

### getCredential<sup>9+</sup>

getCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the credential of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                         | Mandatory  | Description            |
| -------------- | --------------------------- | ---- | -------------- |
| name           | string                      | Yes   | Name of the target app account.       |
| credentialType | string                      | Yes   | Type of the credential to obtain.|
| callback       | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the credential obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or credentialType. |
| 12300003 | Account not found. |
| 12300102 | Credential not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.getCredential("ZhangSan", "PIN_SIX", (err, result) => { 
        if (err) {
          console.log("getCredential failed, error: " + JSON.stringify(err));
        } else {
          console.log('getCredential successfully, result: ' + result);
        }
      });
  } catch (err) {
      console.log("getCredential err: " + JSON.stringify(err));
  }
  ```

### getCredential<sup>9+</sup>

getCredential(name: string, credentialType: string): Promise&lt;string&gt;

Obtains the credential of an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name         | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | Name of the target app account.|
| credentialType | string | Yes   | Type of the credential to obtain.|

**Return value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise used to return the credential obtained.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or credentialType. |
| 12300003 | Account not found. |
| 12300102 | Credential not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getCredential("ZhangSan", "PIN_SIX").then((credential) => {
        console.log("getCredential successfully, credential: " + credential);
    }).catch((err) => {
        console.log("getCredential failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("getCredential exception: "  + JSON.stringify(err));
  }
  ```

### setCustomData<sup>9+</sup>

setCustomData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets custom data for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description               |
| -------- | ------------------------- | ---- | ----------------- |
| name     | string                    | Yes   | Name of the target app account.|
| key      | string                    | Yes   | Key of the custom data to set.|
| value    | string                    | Yes   | Value of the custom data to set.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or key or value. |
| 12300003 | Account not found. |
| 12400003 | The number of custom data reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setCustomData("ZhangSan", "age", "12", (err) => {
      if (err) {
        console.log("setCustomData failed, error: " + JSON.stringify(err));
      } else {
        console.log("setCustomData successfully");
      }
    });
  } catch (err) {
    console.log("setCustomData exception: " + JSON.stringify(err));
  }
  ```

### setCustomData<sup>9+</sup>

setCustomData(name: string, key: string, value: string): Promise&lt;void&gt;

Sets custom data for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type| Mandatory | Description             |
| ----- | ------ | ---- | ----------------- |
| name  | string | Yes   | Name of the target app account.  |
| key   | string | Yes   | Key of the custom data to set.|
| value | string | Yes   | Value of the custom data to set.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or key or value. |
| 12300003 | Account not found. |
| 12400003 | The number of custom data reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setCustomData("ZhangSan", "age", "12").then(() => {
      console.log("setCustomData successfully");
    }).catch((err) => {
      console.log("setCustomData failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("setCustomData exception: " + JSON.stringify(err));
  }
  ```

### getCustomData<sup>9+</sup>

getCustomData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the custom data of an app account based on the specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                       | Mandatory | Description                    |
| -------- | --------------------------- | ----- | ------------------------ |
| name     | string                      | Yes   | Name of the target app account.          |
| key      | string                      | Yes   | Key of the custom data to obtain.        |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the custom data value obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or key. |
| 12300003 | Account not found. |
| 12400002 | Custom data not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getCustomData("ZhangSan", "age", (err, data) => {
      if (err) {
        console.log('getCustomData failed, error: ' + err);
      } else {
        console.log("getCustomData successfully, data: " + data);
      }
    });
  } catch (err) {
    console.log("getCustomData exception: " + JSON.stringify(err));
  }
  ```

### getCustomData<sup>9+</sup>

getCustomData(name: string, key: string): Promise&lt;string&gt;

Obtains the custom data of an app account based on the specified key. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description       |
| ---- | ------ | ---- | --------- |
| name | string | Yes   | Name of the target app account.  |
| key  | string | Yes   | Key of the custom data to obtain.|

**Return value**

| Type                  | Description                   |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise used to return the custom data value obtained.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or key. |
| 12300003 | Account not found. |
| 12400002 | Custom data not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getCustomData("ZhangSan", "age").then((data) => {
      console.log("getCustomData successfully, data: " + data);
    }).catch((err) => {
      console.log("getCustomData failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("getCustomData exception: " + JSON.stringify(err));
  }
  ```

### getCustomDataSync<sup>9+</sup>

getCustomDataSync(name: string, key: string): string;

Obtains the custom data of an app account based on the specified key. The API returns the result synchronously.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description       |
| ---- | ------ | ---- | --------- |
| name | string | Yes   | Name of the target app account.  |
| key  | string | Yes   | Key of the custom data to obtain.|

**Return value**

| Type                   | Description                   |
| --------------------- | --------------------- |
| string | Value of the custom data obtained.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or key. |
| 12300003 | Account not found. |
| 12400002 | Custom data not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
      let value = appAccountManager.getCustomDataSync("ZhangSan", "age");
      console.info("getCustomDataSync successfully, vaue:" + value);
  } catch (err) {
    console.error("getCustomDataSync failed, error: " + JSON.stringify(err));
  }
  ```

### getAllAccounts<sup>9+</sup>

getAllAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Obtains information about all accessible app accounts. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of accessible app accounts. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAllAccounts((err, data) => {
      if (err) {
        console.debug("getAllAccounts failed, error:" + JSON.stringify(err));
      } else {
        console.debug("getAllAccounts successfully");
      }
    });
  } catch (err) {
      console.debug("getAllAccounts exception: " + JSON.stringify(err));
  }
  ```

### getAllAccounts<sup>9+</sup>

getAllAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Obtains information about all accessible app accounts. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS

**System capability**: SystemCapability.Account.AppAccount

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise used to return information about all accessible accounts.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAllAccounts().then((data) => {
      console.debug("getAllAccounts successfully");
    }).catch((err) => {
      console.debug("getAllAccounts failed, error:" + JSON.stringify(err));
    });
  } catch (err) {
    console.debug("getAllAccounts exception: " + JSON.stringify(err));
  }
  ```

### getAccountsByOwner<sup>9+</sup>

getAccountsByOwner(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Obtains the app accounts that can be accessed by the invoker based on the app account owner. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| owner    | string                                   | Yes   | Owner of the app account. The value is the bundle name of the app.   |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is null and **data** is the app account information obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid owner. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAccountsByOwner("com.example.accountjsdemo2", (err, data) => {
      if (err) {
        console.debug("getAccountsByOwner failed, error:" + JSON.stringify(err));
      } else {
        console.debug("getAccountsByOwner successfully, data:" + JSON.stringify(data));
      }
    });
  } catch (err) {
    console.debug("getAccountsByOwner exception:" + JSON.stringify(err));
  }
  ```

### getAccountsByOwner<sup>9+</sup>

getAccountsByOwner(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Obtains the app accounts that can be accessed by the invoker based on the app account owner. This API uses a promise to return the result.

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description    |
| ----- | ------ | ---- | ------ |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise used to return the app account information obtained.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid owner. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAccountsByOwner("com.example.accountjsdemo2").then((data) => {
      console.debug("getAccountsByOwner successfully, data:" + JSON.stringify(data));
    }).catch((err) => {
      console.debug("getAccountsByOwner failed, error:" + JSON.stringify(err));
    });
  } catch (err) {
    console.debug("getAccountsByOwner exception:" + JSON.stringify(err));
  }
  ```

### on('accountChange')<sup>9+</sup>

on(type: 'accountChange', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Subscribes to account information changes of apps.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | 'accountChange'                          | Yes   | Event type to subscribe to. The value is **'accountChange'**. An event will be reported when the account information of the target app changes.|
| owners   | Array&lt;string&gt;                      | Yes   | App bundle names of the account.                     |
| callback | Callback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return a list of app accounts whose information is changed.          |

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or owners. |
| 12300011 | Callback has been registered. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  function changeOnCallback(data){
  	console.log("receive change data:" + JSON.stringify(data));
  }
  try{
  	appAccountManager.on("accountChange", ["com.example.actsaccounttest"], changeOnCallback);
  } catch(err) {
  	console.error("on accountChange failed, error:" + JSON.stringify(err));
  }
  ```

### off('accountChange')<sup>9+</sup>

off(type: 'accountChange', callback?: Callback<Array\<AppAccountInfo>>): void

Unsubscribes from account information changes.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                              | Mandatory  | Description          |
| -------- | -------------------------------- | ---- | ------------ |
| type     | 'accountChange'                         | Yes   | Event type to unsubscribe from. The value is **'accountChange'**.   |
| callback | Callback<Array\<[AppAccountInfo](#appaccountinfo)>> | No   | Callback to unregister.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid type. |
| 12300012 | Callback has not been registered. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  function changeOnCallback(data){
  	console.log("receive change data:" + JSON.stringify(data));
  }
  try{
  	appAccountManager.on("accountChange", ["com.example.actsaccounttest"], changeOnCallback);
  } catch(err) {
  	console.error("on accountChange failed, error:" + JSON.stringify(err));
  }
  try{
  	appAccountManager.off('accountChange', changeOnCallback);
  }
  catch(err){
  	console.error("off accountChange failed, error:" + JSON.stringify(err));
  }
  ```

### auth<sup>9+</sup>

auth(name: string, owner: string, authType: string, callback: AuthCallback): void

Authenticates an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description             |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | Yes   | Name of the target app account.    |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string                | Yes   | Authentication type.          |
| callback | [AuthCallback](#authcallback9) | Yes   | Callback invoked to return the authentication result.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or authType. |
| 12300003 | Account not found. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, authResult) {
    console.log("resultCode: "  + code);
    console.log("authResult: "  + JSON.stringify(authResult));
  }

  function onRequestRedirectedCallback(request) {
    let abilityStartSetting = {want: request};
    featureAbility.startAbility(abilityStartSetting, (err) => {
        console.log("startAbility err: " + JSON.stringify(err));
    });
  }

  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.auth("LiSi", "com.example.accountjsdemo", "getSocialData", {
        onResult: onResultCallback,
        onRequestRedirected: onRequestRedirectedCallback
    });
  } catch (err) {
    console.log("auth exception: "  + JSON.stringify(err));
  }
  ```

### auth<sup>9+</sup>

auth(name: string, owner: string, authType: string, options: {[key: string]: Object}, callback: AuthCallback): void

Authenticates an app account with customized options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description             |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | Yes   | Name of the target app account.    |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string                | Yes   | Authentication type.          |
| options  | {[key: string]: Object}  | Yes   | Options for the authentication.      |
| callback | [AuthCallback](#authcallback9) | Yes   | Callback invoked to return the authentication result.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or authType. |
| 12300003 | Account not exist. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  function onResultCallback(code, authResult) {
    console.log("resultCode: "  + code);
    console.log("authResult: "  + JSON.stringify(authResult));
  }

  function onRequestRedirectedCallback(request) {
    let abilityStartSetting = {want: request};
    featureAbility.startAbility(abilityStartSetting, (err) => {
        console.log("startAbility err: " + JSON.stringify(err));
    });
  }

  let options = {
    "password": "xxxx",
  };
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.auth("LiSi", "com.example.accountjsdemo", "getSocialData", options, {
        onResult: onResultCallback,
        onRequestRedirected: onRequestRedirectedCallback
    });
  } catch (err) {
    console.log("auth exception: "  + JSON.stringify(err));
  }
  ```

### getAuthToken<sup>9+</sup>

getAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the authorization token of the specified authentication type for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description         |
| -------- | --------------------------- | ---- | ----------- |
| name     | string                      | Yes   | Name of the target app account.   |
| owner    | string                      | Yes   | Owner of the app account. The value is the bundle name of the app.|
| authType | string                      | Yes   | Authentication type.      |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the authorization token value obtained. Otherwise, **err** is an error object.   |

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name, owner or authType. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData", (err, token) => {
      if (err) {
        console.log("getAuthToken failed, error: " + JSON.stringify(err));
      } else {
        console.log("getAuthToken successfully, token: " + token);
      }
    });
  } catch (err) {
      console.log("getAuthToken exception: " + JSON.stringify(err));
  }
  ```

### getAuthToken<sup>9+</sup>

getAuthToken(name: string, owner: string, authType: string): Promise&lt;string&gt;

Obtains the authorization token of the specified authentication type for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description         |
| -------- | ------ | ---- | ----------- |
| name     | string | Yes   | Name of the target app account.   |
| owner    | string | Yes   | Owner of the app account. The value is the bundle name of the app.|
| authType | string | Yes   | Authentication type.      |

**Return value**

| Type                   | Description                |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise used to return the authorization token obtained.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or authType. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData").then((token) => {
      console.log("getAuthToken successfully, token: " + token);
    }).catch((err) => {
      console.log("getAuthToken failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
      console.log("getAuthToken exception: " + JSON.stringify(err));
  }
  ```

### setAuthToken<sup>9+</sup>

setAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Sets an authorization token of the specific authentication type for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description      |
| -------- | ------------------------- | ---- | -------- |
| name     | string                    | Yes   | Name of the target app account.|
| authType | string                    | Yes   | Authentication type.   |
| token    | string                    | Yes   | Token to set.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType or token. |
| 12300003 | Account not found. |
| 12400004 | The number of token reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setAuthToken("LiSi", "getSocialData", "xxxx", (err) => {
      if (err) {
        console.log("setAuthToken failed, error: " + JSON.stringify(err));
      } else {
        console.log("setAuthToken successfully");
      }
    });
  } catch (err) {
      console.log('setAuthToken exception: ' + JSON.stringify(err));
  }
  ```

### setAuthToken<sup>9+</sup>

setAuthToken(name: string, authType: string, token: string): Promise&lt;void&gt;

Sets an authorization token of the specific authentication type for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| name     | string | Yes   | Name of the target app account.|
| authType | string | Yes   | Authentication type.   |
| token    | string | Yes   | Token to set.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType or token. |
| 12300003 | Account not found. |
| 12400004 | The number of token reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setAuthToken("LiSi", "getSocialData", "xxxx").then(() => {
        console.log("setAuthToken successfully");
    }).catch((err) => {
        console.log("setAuthToken failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("setAuthToken exception: " + JSON.stringify(err));
  }
  ```

### deleteAuthToken<sup>9+</sup>

deleteAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the authorization token of the specified authentication type for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description          |
| -------- | ------------------------- | ---- | ------------ |
| name     | string                    | Yes   | Name of the target app account.    |
| owner    | string                    | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string                    | Yes   | Authentication type.       |
| token    | string                    | Yes   | Token to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.    |

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or authType or token. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.deleteAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData", "xxxxx", (err) => {
        if (err) {
          console.log('deleteAuthToken failed, error: ' + JSON.stringify(err));
        } else {
          console.log("deleteAuthToken successfully");
        }
      });
  } catch (err) {
      console.log('deleteAuthToken exception: ' + JSON.stringify(err));
  }
  ```

### deleteAuthToken<sup>9+</sup>

deleteAuthToken(name: string, owner: string, authType: string, token: string): Promise&lt;void&gt;

Deletes the authorization token of the specified authentication type for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description          |
| -------- | ------ | ---- | ------------ |
| name     | string | Yes   | Name of the target app account.    |
| owner    | string | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string | Yes   | Authentication type.       |
| token    | string | Yes   | Token to delete.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or authType or token. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.deleteAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData", "xxxxx").then(() => {
      console.log("deleteAuthToken successfully");
    }).catch((err) => {
      console.log('deleteAuthToken failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('deleteAuthToken exception: ' + JSON.stringify(err));
  }
  ```

### setAuthTokenVisibility<sup>9+</sup>

setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the visibility of an authorization token to an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                       |
| ---------- | ------------------------- | ---- | ------------------------- |
| name       | string                    | Yes   | Name of the target app account.                 |
| authType   | string                    | Yes   | Authentication type.                    |
| bundleName | string                    | Yes   | Bundle name of the app.             |
| isVisible  | boolean                   | Yes   | Whether the authorization token is visible to the app. The value **true** means the authorization token is visible to the app; the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType or bundleName. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |
| 12400001 | Application not found. |
| 12400005 | The size of authorization list reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.setAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo", true, (err) => {
        if (err) {
          console.log("setAuthTokenVisibility failed, error: " + JSON.stringify(err));
        } else {
          console.log("setAuthTokenVisibility successfully");
        }
      });
  } catch (err) {
      console.log("setAuthTokenVisibility exception: " + JSON.stringify(err));
  }
  ```

### setAuthTokenVisibility<sup>9+</sup>

setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise&lt;void&gt;

Sets the visibility of an authorization token to an app. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                       |
| ---------- | ------------------------- | ---- | ------------------------- |
| name       | string                    | Yes   | Name of the target app account.                 |
| authType   | string                    | Yes   | Authentication type.                    |
| bundleName | string                    | Yes   | Bundle name of the app.             |
| isVisible  | boolean                   | Yes   | Whether the authorization token is visible to the app. The value **true** means the authorization token is visible to the app; the value **false** means the opposite.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType or bundleName. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |
| 12400001 | Application not found. |
| 12400005 | The size of authorization list reaches the upper limit. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo", true).then(() => {
      console.log("setAuthTokenVisibility successfully");
    }).catch((err) => {
      console.log("setAuthTokenVisibility failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("setAuthTokenVisibility exception: " + JSON.stringify(err));
  }
  ```

### checkAuthTokenVisibility<sup>9+</sup>

checkAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks the visibility of an authorization token of the specified authentication type to an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                          | Mandatory  | Description         |
| ---------- | ---------------------------- | ---- | ----------- |
| name       | string                       | Yes   | Name of the target app account.   |
| authType   | string                       | Yes   | Authentication type.      |
| bundleName | string                       | Yes   | Bundle name of the app.|
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** can be **true** (the authorization token is visible to the app) or **false** (the authorization token is not visible to the app). If the operation fails, **err** is an error object.   |

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType or bundleName. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.checkAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo", (err, isVisible) => {
      if (err) {
        console.log("checkAuthTokenVisibility failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkAuthTokenVisibility successfully, isVisible: " + isVisible);
      }
    });
  } catch (err) {
    console.log("checkAuthTokenVisibility exception: " + JSON.stringify(err));
  }
  ```

### checkAuthTokenVisibility<sup>9+</sup>

checkAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise&lt;boolean&gt;

Checks the visibility of an authorization token of the specified authentication type to an app. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description           |
| ---------- | ------ | ---- | ------------- |
| name       | string | Yes   | Name of the target app account.     |
| authType   | string | Yes   | Authentication type.        |
| bundleName | string | Yes   | Bundle name of the app.|

**Return value**

| Type                    | Description                   |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the authorization token is visible to the app; the value **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType or bundleName. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |
| 12400001 | Application not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.checkAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo").then((isVisible) => {
      console.log("checkAuthTokenVisibility successfully, isVisible: " + isVisible);
    }).catch((err) => {
      console.log("checkAuthTokenVisibility failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("checkAuthTokenVisibility exception: " + JSON.stringify(err));
  }
  ```

### getAllAuthTokens<sup>9+</sup>

getAllAuthTokens(name: string, owner: string, callback: AsyncCallback&lt;Array&lt;AuthTokenInfo&gt;&gt;): void

Obtains all tokens visible to the invoker for an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | Yes   | Name of the target app account.   |
| owner    | string                                   | Yes   | Owner of the app account. The value is the bundle name of the app.|
| callback | AsyncCallback&lt;Array&lt;[AuthTokenInfo](#authtokeninfo9)&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of all tokens visible to the invoker. Otherwise, **err** is an error object.   |

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAllAuthTokens("LiSi", "com.example.accountjsdemo", (err, tokenArr) => {
      if (err) {
        console.log("getAllAuthTokens failed, error: "  + JSON.stringify(err));
      } else {
        console.log('getAllAuthTokens successfully, tokenArr: ' + tokenArr);
      }
    });
  } catch (err) {
    console.log("getAllAuthTokens exception: "  + JSON.stringify(err));
  }
  ```

### getAllAuthTokens<sup>9+</sup>

getAllAuthTokens(name: string, owner: string): Promise&lt;Array&lt;AuthTokenInfo&gt;&gt;

Obtains all tokens visible to the invoker for an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| name  | string | Yes   | Name of the target app account.   |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AuthTokenInfo](#authtokeninfo9)&gt;&gt; | Promise used to return the tokens obtained.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner. |
| 12300003 | Account not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAllAuthTokens("LiSi", "com.example.accountjsdemo").then((tokenArr) => {
        console.log('getAllAuthTokens successfully, tokenArr: ' + JSON.stringify(tokenArr));
    }).catch((err) => {
        console.log("getAllAuthTokens failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("getAllAuthTokens exception: "  + JSON.stringify(err));
  }
  ```

### getAuthList<sup>9+</sup>

getAuthList(name: string, authType: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the authorization list of the specified authentication type for an app account. The authorization list contains all authorized bundles. The token authorization list is set by [setAuthTokenVisibility](#setauthtokenvisibility9). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                     |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| name     | string                                   | Yes   | Name of the target app account.               |
| authType | string                                   | Yes   | Authentication type.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of authorized bundles obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAuthList("com.example.accountjsdemo", "getSocialData", (err, authList) => {
      if (err) {
        console.log("getAuthList failed, error: " + JSON.stringify(err));
      } else {
        console.log("getAuthList successfully, authList: " + authList);
      }
    });
  } catch (err) {
    console.log('getAuthList exception: ' + JSON.stringify(err));
  }
  ```

### getAuthList<sup>9+</sup>

getAuthList(name: string, authType: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains the authorization list of the specified authentication type for an app account. The authorization list contains all authorized bundles. The token authorization list is set by [setAuthTokenVisibility](#setauthtokenvisibility9). This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description                     |
| -------- | ------ | ---- | ------------------------------ |
| name     | string | Yes   | Name of the target app account.               |
| authType | string | Yes   | Authentication type.|

**Return value**

| Type                                | Description                   |
| ---------------------------------- | --------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return a list of authorized bundles.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or authType. |
| 12300003 | Account not found. |
| 12300107 | AuthType not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.getAuthList("com.example.accountjsdemo", "getSocialData").then((authList) => {
        console.log("getAuthList successfully, authList: " + authList);
    }).catch((err) => {
        console.log("getAuthList failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("getAuthList exception: "  + JSON.stringify(err));
  }
  ```

### getAuthCallback<sup>9+</sup>

getAuthCallback(sessionId: string, callback: AsyncCallback&lt;AuthCallback&gt;): void

Obtains the authenticator callback for the authentication session. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string                                   | Yes   | ID of the authentication session.|
| callback  | AsyncCallback&lt;[AuthCallback](#authcallback9)&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the authenticator callback object obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid sessionId. |
| 12300108 | Session not found. |

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  let appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant((err, want) => {
    var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
    try {
      appAccountManager.getAuthCallback(sessionId, (err, callback) => {
        if (err.code != account_appAccount.ResultCode.SUCCESS) {
            console.log("getAuthCallback err: "  + JSON.stringify(err));
            return;
        }
        var result = {
          accountInfo: {
            name: "Lisi",
            owner: "com.example.accountjsdemo",
          },
          tokenInfo: {
            token: "xxxxxx",
            authType: "getSocialData"
          }
        }; 
        callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
      });
    } catch (err) {
        console.log("getAuthCallback exception: "  + JSON.stringify(err));
    }
  });
  ```

### getAuthCallback<sup>9+</sup>

getAuthCallback(sessionId: string): Promise&lt;AuthCallback&gt;

Obtains the authenticator callback for the authentication session. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description      |
| --------- | ------ | ---- | -------- |
| sessionId | string | Yes   | ID of the authentication session.|

**Return value**

| Type                                  | Description                   |
| ------------------------------------ | --------------------- |
| Promise&lt;[AuthCallback](#authcallback9)&gt; | Promise used to return the authenticator callback obtained.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid sessionId. |
| 12300108 | Session not found. |

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  let appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant().then((want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      try {
        appAccountManager.getAuthCallback(sessionId).then((callback) => {
        var result = {
          accountInfo: {
            name: "Lisi",
            owner: "com.example.accountjsdemo",
          },
          tokenInfo: {
            token: "xxxxxx",
            authType: "getSocialData"
          }
        };
        callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
        }).catch((err) => {
            console.log("getAuthCallback err: "  + JSON.stringify(err));
        });
      } catch (err) {
        console.log("getAuthCallback exception: "  + JSON.stringify(err));
      }
  }).catch((err) => {
      console.log("getWant err: "  + JSON.stringify(err));
  });
  ```

### queryAuthenticatorInfo<sup>9+</sup>

queryAuthenticatorInfo(owner: string, callback: AsyncCallback&lt;AuthenticatorInfo&gt;): void

Obtains the authenticator information of an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                    | Mandatory  | Description         |
| -------- | -------------------------------------- | ---- | ----------- |
| owner    | string                                 | Yes   | Bundle name of the app.|
| callback | AsyncCallback&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the authenticator information obtained. Otherwise, **err** is an error object.   |

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid owner. |
| 12300113 | Authenticator service not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.queryAuthenticatorInfo("com.example.accountjsdemo", (err, info) => {
      if (err) {
        console.log("queryAuthenticatorInfo failed, error: "  + JSON.stringify(err));
      } else {
        console.log('queryAuthenticatorInfo successfully, info: ' + JSON.stringify(info));
      }
    });
  } catch (err) {
    console.log("queryAuthenticatorInfo exception: "  + JSON.stringify(err));
  }
  ```

### queryAuthenticatorInfo<sup>9+</sup>

queryAuthenticatorInfo(owner: string): Promise&lt;AuthenticatorInfo&gt;

Obtains the authenticator information of an app. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| owner | string | Yes   | Bundle name of the app.|

**Return value**

| Type                              | Description                   |
| -------------------------------- | --------------------- |
| Promise&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Promise used to return the authenticator information obtained.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid owner. |
| 12300113 | Authenticator service not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.queryAuthenticatorInfo("com.example.accountjsdemo").then((info) => { 
        console.log("queryAuthenticatorInfo successfully, info: " + JSON.stringify(info));
    }).catch((err) => {
        console.log("queryAuthenticatorInfo failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("queryAuthenticatorInfo exception: "  + JSON.stringify(err));
  }
  ```

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, owner: string, labels: Array&lt;string&gt;, callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether an app account has specific labels. This API uses an asynchronous callback to return the result. The labels are checked by the authenticator of the target app.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description            |
| -------------- | ------------------------- | ----- | --------------- |
| name           | string                    | Yes   | Name of the target app account. |
| owner          | string                    | Yes   | Owner of the app account. The value is the bundle name of the app.|
| labels         | Array&lt;string&gt;       | Yes   | Labels to check.      |
| callback       | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** can be **true** or **false**. The value **true** means the app account has the labels; the value **false** means the opposite. If the operation fails, **err** is an error object. |

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or labels. |
| 12300003 | Account not found. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let labels = ["student"];
  try {
    appAccountManager.checkAccountLabels("zhangsan", "com.example.accountjsdemo", labels, (err, hasAllLabels) => {
      if (err) {
        console.log("checkAccountLabels failed, error: "  + JSON.stringify(err));
      } else {
        console.log("checkAccountLabels successfully, hasAllLabels: " + hasAllLabels);
      }
    });
  } catch (err) {
    console.log("checkAccountLabels exception: "  + JSON.stringify(err));
  }
  ```

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, owner: string, labels: Array&lt;string&gt;): Promise&lt;boolean&gt;

Checks whether an app account has specific labels. This API uses a promise to return the result. The labels are checked by the authenticator of the target app.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description            |
| -------------- | ------------------------- | ----- | --------------- |
| name           | string                    | Yes   | Name of the target app account. |
| owner          | string                    | Yes   | Owner of the app account. The value is the bundle name of the app.|
| labels         | Array&lt;string&gt;       | Yes   | Labels to check.      |

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the app account has the labels; the value **false** means the opposite.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or labels. |
| 12300003 | Account not found. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let labels = ["student"];
  try {
    appAccountManager.checkAccountLabels("zhangsan", "com.example.accountjsdemo", labels).then((hasAllLabels) => {
      console.log('checkAccountLabels successfully: ' + hasAllLabels);
    }).catch((err) => {
      console.log("checkAccountLabels failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("checkAccountLabels exception: "  + JSON.stringify(err));
  }
  ```

### deleteCredential<sup>9+</sup>

deleteCredential(name: string, credentialType: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the credential of the specified type from an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description           |
| -------------- | ------------------------- | ----- | -------------- |
| name           | string                    | Yes   | Name of the target app account.|
| credentialType | string                    | Yes   | Type of the credential to delete.     |
| callback       | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or credentialType. |
| 12300003 | Account not found. |
| 12300102 | Credential not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.deleteCredential("zhangsan", "PIN_SIX", (err) => {
      if (err) {
        console.log("deleteCredential failed, error: "  + JSON.stringify(err));
      } else {
        console.log("deleteCredential successfully");
      }
    });
  } catch (err) {
    console.log("deleteCredential exception: "  + JSON.stringify(err));
  }
  ```

### deleteCredential<sup>9+</sup>

deleteCredential(name: string, credentialType: string): Promise&lt;void&gt;

Deletes the credential of the specified type from an app account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type  | Mandatory  | Description           |
| -------------- | ------ | ----- | --------------- |
| name           | string | Yes   | Name of the target app account.|
| credentialType | string | Yes   | Type of the credential to delete.      |

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid name or credentialType. |
| 12300003 | Account not found. |
| 12300102 | Credential not found. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.deleteCredential("zhangsan", "PIN_SIX").then(() => {
      console.log("deleteCredential successfully");
    }).catch((err) => {
      console.log("deleteCredential failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log("deleteCredential exception: "  + JSON.stringify(err));
  }
  ```

### selectAccountsByOptions<sup>9+</sup>

selectAccountsByOptions(options: SelectAccountsOptions, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Selects the accounts that can be accessed by the invoker based on the options. This API uses an asynchronous callback to return the result. If the options contain label constraints, the authenticator of the target app provides the capability of checking the labels.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                                | Mandatory | Description            |
| -------------- | ----------------------------------- | ----- | --------------- |
| options        | SelectAccountsOptions               | Yes   | Options for selecting accounts. |
| callback       | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of accounts selected. Otherwise, **err** is an error object. |

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid options. |
| 12300010 | Account service busy. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let options = {
    allowedOwners: [ "com.example.accountjsdemo" ],
    requiredLabels: [ "student" ]
  };
  try {
    appAccountManager.selectAccountsByOptions(options, (err, accountArr) => {
      if (err) {
        console.log("selectAccountsByOptions failed, error: "  + JSON.stringify(err));
      } else {
        console.log("selectAccountsByOptions successfully, accountArr: " + JSON.stringify(accountArr));
      }
    });
  } catch (err) {
    console.log("selectAccountsByOptions exception: "  + JSON.stringify(err));
  }
  ```

### selectAccountsByOptions<sup>9+</sup>

selectAccountsByOptions(options: SelectAccountsOptions): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Selects the accounts that can be accessed by the invoker based on the options. This API uses a promise to return the result. If the options contain label constraints, the authenticator of the target app provides the capability of checking the labels.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name        | Type                      | Mandatory | Description            |
| -------------- | ------------------------- | ----- | --------------- |
| options        | [SelectAccountsOptions](#selectaccountsoptions9)     | Yes   | Options for selecting accounts. |

**Return value**

| Type               | Description                             |
| ------------------- | -------------------------------- |
| Promise&lt;[AppAccountInfo](#appaccountinfo)&gt; | Promise used to return the accounts selected.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid options. |
| 12300010 | Account service busy. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let options = {
    allowedOwners: ["com.example.accountjsdemo"]
  };
  try {
    appAccountManager.selectAccountsByOptions(options).then((accountArr) => {
      console.log("selectAccountsByOptions successfully, accountArr: " + JSON.stringify(accountArr));
    }).catch((err) => {
      console.log("selectAccountsByOptions failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("selectAccountsByOptions exception: "  + JSON.stringify(err));
  }
  ```

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, owner: string, callback: AuthCallback): void;

Verifies the credential of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                 | Mandatory | Description                    |
| -------- | --------------------- | ----- | ----------------------- |
| name     | string                | Yes   | Name of the target app account.         |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app.       |
| callback | [AuthCallback](#authcallback9) | Yes   | Callback invoked to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner. |
| 12300003 | Account not found. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
      appAccountManager.verifyCredential("zhangsan", "com.example.accountjsdemo", {
          onResult: (resultCode, result) => {
              console.log("verifyCredential onResult, resultCode:" + JSON.stringify(resultCode));
              console.log("verifyCredential onResult, result:" + JSON.stringify(result));
          },
          onRequestRedirected: (request) => {
              console.log("verifyCredential onRequestRedirected, request:" + JSON.stringify(request));
          }
      });
  } catch (err) {
      console.log("verifyCredential err: "  + JSON.stringify(err));
  }
  ```

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, owner: string, options: VerifyCredentialOptions, callback: AuthCallback): void;

Verifies the user credential. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                   | Mandatory | Description                    |
| -------- | ----------------------- | ----- | ----------------------- |
| name     | string                  | Yes   | Name of the target app account.         |
| owner    | string                  | Yes   | Owner of the app account. The value is the bundle name of the app.       |
| options  | [VerifyCredentialOptions](#verifycredentialoptions9) | Yes   | Options for verifying the user credential.         |
| callback | [AuthCallback](#authcallback9)   | Yes   | Callback invoked to return the result.|

**Error codes**

| ID| Error Message|
| ------- | -------|
| 12300001 | System service exception. |
| 12300002 | Invalid name or owner or options. |
| 12300003 | Account not found. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let options = {
    credentialType: "pin",
    credential: "123456"
  };
  try {
    appAccountManager.verifyCredential("zhangsan", "com.example.accountjsdemo", options, {
      onResult: (resultCode, result) => {
        console.log("verifyCredential onResult, resultCode:" + JSON.stringify(resultCode));
        console.log("verifyCredential onResult, result:" + JSON.stringify(result));
      },
      onRequestRedirected: (request) => {
        console.log("verifyCredential onRequestRedirected, request:" + JSON.stringify(request));
      }
    });
  } catch (err) {
    console.log("verifyCredential err: "  + JSON.stringify(err));
  }
  ```

### setAuthenticatorProperties<sup>9+</sup>

setAuthenticatorProperties(owner: string, callback: AuthCallback): void;

Sets the authenticator attributes of an app. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                 | Mandatory | Description                    |
| -------- | --------------------- | ----- | ----------------------- |
| owner    | string                | Yes   | Owner of the authenticator.         |
| callback | [AuthCallback](#authcallback9) | Yes   | Callback invoked to return the result.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid owner. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  try {
    appAccountManager.setAuthenticatorProperties("com.example.accountjsdemo", {
      onResult: (resultCode, result) => {
        console.log("setAuthenticatorProperties onResult, resultCode:" + JSON.stringify(resultCode));
        console.log("setAuthenticatorProperties onResult, result:" + JSON.stringify(result));
      },
      onRequestRedirected: (request) => {
        console.log("setAuthenticatorProperties onRequestRedirected, request:" + JSON.stringify(request));
      }
    });
  } catch (err) {
    console.log("setAuthenticatorProperties err: "  + JSON.stringify(err));
  }
  ```

### setAuthenticatorProperties<sup>9+</sup>

setAuthenticatorProperties(owner: string, options: SetPropertiesOptions, callback: AuthCallback): void;

Set authenticator properties. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                 | Mandatory | Description                    |
| -------- | --------------------- | ----- | ----------------------- |
| owner    | string                | Yes   | Owner of the authenticator.         |
| options  | [SetPropertiesOptions](#setpropertiesoptions9)  | Yes   | Authenticator properties to set.         |
| callback | [AuthCallback](#authcallback9) | Yes   | Authenticator callback invoked to return the result.|

**Error codes**

| ID| Error Message|
| ------- | ------- |
| 12300001 | System service exception. |
| 12300002 | Invalid owner or options. |
| 12300010 | Account service busy. |
| 12300113 | Authenticator service not found. |
| 12300114 | Authenticator service exception. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  let options = {
    properties: {"prop1": "value1"}
  };
  try {
    appAccountManager.setAuthenticatorProperties("com.example.accountjsdemo", options, {
      onResult: (resultCode, result) => {
        console.log("setAuthenticatorProperties onResult, resultCode:" + JSON.stringify(resultCode));
        console.log("setAuthenticatorProperties onResult, result:" + JSON.stringify(result));
      },
      onRequestRedirected: (request) => {
        console.log("setAuthenticatorProperties onRequestRedirected, request:" + JSON.stringify(request));
      }
    });
  } catch (err) {
    console.log("setAuthenticatorProperties err: "  + JSON.stringify(err));
  } 

  ```

### addAccount<sup>(deprecated)</sup>

addAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

Adds an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
>This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createAccount](#createaccount9).


**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                  |
| -------- | ------------------------- | ---- | -------------------- |
| name     | string                    | Yes   | Name of the target app account.         |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("WangWu", (err) => { 
      console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount<sup>(deprecated)</sup>

addAccount(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

Adds an app account name and additional information. This API uses an asynchronous callback to return the result.

> **NOTE**
> 
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createAccount](#createaccount9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| name      | string                    | Yes   | Name of the target app account.                             |
| extraInfo | string                    | Yes   | Additional information (information that can be converted to the string type). It cannot contain sensitive information, such as the app account password and token.|
| callback  | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.            |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101", (err) => { 
    console.log("addAccount err: " + JSON.stringify(err));
  });
  ```

### addAccount<sup>(deprecated)</sup>

addAccount(name: string, extraInfo?: string): Promise&lt;void&gt;

Adds an app account name and additional information. This API uses an asynchronous callback to return the result. This API uses a promise to return the result.

> **NOTE**
>  
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [createAccount](#createaccount9-2).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description                                      |
| --------- | ------ | ---- | ---------------------------------------- |
| name      | string | Yes   | Name of the target app account.                           |
| extraInfo | string | No   | Additional information (information that can be converted to the string type). It cannot contain sensitive information, such as the app account password and token.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccount("LiSi", "token101").then(()=> { 
    console.log('addAccount Success');
  }).catch((err) => {
    console.log("addAccount err: "  + JSON.stringify(err));
  });
  ```

### addAccountImplicitly<sup>(deprecated)</sup>

addAccountImplicitly(owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Adds an app account implicitly based on the specified owner. This API uses an asynchronous callback to return the result.

> **NOTE** 
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [createAccountImplicitly](#createaccountimplicitly9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description                     |
| -------- | --------------------- | ---- | ----------------------- |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app.         |
| authType | string                | Yes   | Authentication type. The authentication type is customized. |
| options  | {[key: string]: any}  | Yes   | Authentication options, which can be set as required.|
| callback | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | Yes   | Authenticator callback invoked to return the result.        |

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

  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.addAccountImplicitly("com.example.accountjsdemo", "getSocialData", {}, {
    onResult: onResultCallback,
    onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### deleteAccount<sup>(deprecated)</sup>

deleteAccount(name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [removeAccount](#removeaccount9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description              |
| -------- | ------------------------- | ---- | ---------------- |
| name     | string                    | Yes   | Name of the target app account.     |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu", (err) => { 
      console.log("deleteAccount err: " + JSON.stringify(err));
   });
  ```

### deleteAccount<sup>(deprecated)</sup>

deleteAccount(name: string): Promise&lt;void&gt;

Deletes an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [removeAccount](#removeaccount9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description         |
| ---- | ------ | ---- | ----------- |
| name | string | Yes   | Name of the target app account.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteAccount("ZhaoLiu").then(() => { 
        console.log('deleteAccount Success');
   }).catch((err) => {
      console.log("deleteAccount err: "  + JSON.stringify(err));
  });
  ```
### disableAppAccess<sup>(deprecated)</sup>

disableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Disables an app account from accessing an app. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setAppAccess](#setappaccess9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                               |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | Yes   | Name of the target app account.                 |
| bundleName | string                    | Yes   | Bundle name of the app.                        |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.accountjsdemo", (err) => { 
      console.log("disableAppAccess err: " + JSON.stringify(err));
  });
  ```

### disableAppAccess<sup>(deprecated)</sup>

disableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

Disables an app account from accessing an app. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setAppAccess](#setappaccess9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description              |
| ---------- | ------ | ---- | ---------------- |
| name       | string | Yes   | Name of the target app account.|
| bundleName | string | Yes   | Bundle name of the app.       |

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.disableAppAccess("ZhangSan", "com.example.accountjsdemo").then(() => { 
      console.log('disableAppAccess Success');
  }).catch((err) => {
      console.log("disableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### enableAppAccess<sup>(deprecated)</sup>

enableAppAccess(name: string, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Enables an app account to access an app. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setAppAccess](#setappaccess9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                               |
| ---------- | ------------------------- | ---- | --------------------------------- |
| name       | string                    | Yes   | Name of the target app account.                          |
| bundleName | string                    | Yes   | Bundle name of the app.                        |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.accountjsdemo", (err) => { 
      console.log("enableAppAccess: " + JSON.stringify(err));
   });
  ```

### enableAppAccess<sup>(deprecated)</sup>

enableAppAccess(name: string, bundleName: string): Promise&lt;void&gt;

Enables an app account to access an app. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setAppAccess](#setappaccess9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| name       | string | Yes   | Name of the target app account.  |
| bundleName | string | Yes   | Bundle name of the app.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.enableAppAccess("ZhangSan", "com.example.accountjsdemo").then(() => { 
       console.log('enableAppAccess Success');
  }).catch((err) => {
      console.log("enableAppAccess err: "  + JSON.stringify(err));
  });
  ```

### checkAppAccountSyncEnable<sup>(deprecated)</sup>

checkAppAccountSyncEnable(name: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether data synchronization is enabled for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkDataSyncEnabled](#checkdatasyncenabled9).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                          | Mandatory  | Description                   |
| -------- | ---------------------------- | ---- | --------------------- |
| name     | string                       | Yes   | Name of the target app account.              |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. The value **true** means data synchronization is enabled for the app account; the value **false** means the opposite.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan", (err, result) => { 
      console.log("checkAppAccountSyncEnable err: " + JSON.stringify(err));
      console.log('checkAppAccountSyncEnable result: ' + result);
  });
  ```

### checkAppAccountSyncEnable<sup>(deprecated)</sup>

checkAppAccountSyncEnable(name: string): Promise&lt;boolean&gt;

Checks whether data synchronization is enabled for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkDataSyncEnabled](#checkdatasyncenabled9-1).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| name | string | Yes   | Name of the target app account.|

**Return value**

| Type                    | Description                   |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means data synchronization is enabled for the app account; the value **false** means the opposite.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkAppAccountSyncEnable("ZhangSan").then((data) => { 
      console.log('checkAppAccountSyncEnable, result: ' + data);
  }).catch((err) => {
      console.log("checkAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAccountCredential<sup>(deprecated)</sup>

setAccountCredential(name: string, credentialType: string, credential: string,callback: AsyncCallback&lt;void&gt;): void

Set credentials for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCredential](#setcredential9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                       | Mandatory  | Description           |
| -------------- | ------------------------- | ---- | ------------- |
| name           | string                    | Yes   | Name of the target app account.    |
| credentialType | string                    | Yes   | Type of the credential to set.    |
| credential     | string                    | Yes   | Credential value.     |
| callback       | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001", (err) => { 
      console.log("setAccountCredential err: " + JSON.stringify(err));
  });
  ```

### setAccountCredential<sup>(deprecated)</sup>

setAccountCredential(name: string, credentialType: string, credential: string): Promise&lt;void&gt;

Set credentials for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCredential](#setcredential9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | Name of the target app account.  |
| credentialType | string | Yes   | Type of the credential to set.|
| credential     | string | Yes   | Credential value.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountCredential("ZhangSan", "credentialType001", "credential001").then(() => { 
      console.log('setAccountCredential Success');
  }).catch((err) => {
      console.log("setAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo<sup>(deprecated)</sup>

setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback&lt;void&gt;): void

Sets additional information for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCustomData](#setcustomdata9).


**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                       | Mandatory  | Description             |
| --------- | ------------------------- | ---- | --------------- |
| name      | string                    | Yes   | Name of the target app account.        |
| extraInfo | string                    | Yes   | Additional information (information that can be converted to the string type). It cannot contain sensitive information, such as the app account password and token.      |
| callback  | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002", (err) => { 
      console.log("setAccountExtraInfo err: " + JSON.stringify(err));
  });
  ```

### setAccountExtraInfo<sup>(deprecated)</sup>

setAccountExtraInfo(name: string, extraInfo: string): Promise&lt;void&gt;

Sets additional information for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCustomData](#setcustomdata9-1).


**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description       |
| --------- | ------ | ---- | --------- |
| name      | string | Yes   | Name of the target app account.  |
| extraInfo | string | Yes   | Additional information (information that can be converted to the string type). It cannot contain sensitive information, such as the app account password and token.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAccountExtraInfo("ZhangSan", "Tk002").then(() => { 
      console.log('setAccountExtraInfo Success');
  }).catch((err) => {
      console.log("setAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable<sup>(deprecated)</sup>

setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets data synchronization for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setDataSyncEnabled](#setdatasyncenabled9).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description                       |
| -------- | ------------------------- | ---- | ------------------------- |
| name     | string                    | Yes   | Name of the target app account.                 |
| isEnable | boolean                   | Yes   | Whether to enable data synchronization.              |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAppAccountSyncEnable("ZhangSan", true, (err) => { 
      console.log("setAppAccountSyncEnable err: " + JSON.stringify(err));
  });
  ```

### setAppAccountSyncEnable<sup>(deprecated)</sup>

setAppAccountSyncEnable(name: string, isEnable: boolean): Promise&lt;void&gt;

Sets data synchronization for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setDataSyncEnabled](#setdatasyncenabled9-1).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type     | Mandatory  | Description         |
| -------- | ------- | ---- | ----------- |
| name     | string  | Yes   | Name of the target app account.    |
| isEnable | boolean | Yes   | Whether to enable data synchronization.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager .setAppAccountSyncEnable("ZhangSan", true).then(() => { 
      console.log('setAppAccountSyncEnable Success');
  }).catch((err) => {
      console.log("setAppAccountSyncEnable err: "  + JSON.stringify(err));
  });
  ```

### setAssociatedData<sup>(deprecated)</sup>

setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets data to be associated with an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCustomData](#setcustomdata9).


**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description               |
| -------- | ------------------------- | ---- | ----------------- |
| name     | string                    | Yes   | Name of the target app account.          |
| key      | string                    | Yes   | Key of the data to set.|
| value    | string                    | Yes   | Value of the data to set.        |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001", (err) => { 
      console.log("setAssociatedData err: " + JSON.stringify(err));
  });
  ```

### setAssociatedData<sup>(deprecated)</sup>

setAssociatedData(name: string, key: string, value: string): Promise&lt;void&gt;

Sets data to be associated with an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setCustomData](#setcustomdata9-1).


**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description               |
| ----- | ------ | ---- | ----------------- |
| name  | string | Yes   | Name of the target app account.          |
| key      | string | Yes   | Key of the data to set.|
| value    | string | Yes   | Value of the data to set.|

**Return value**

| Type                 | Description                   |
| :------------------ | :-------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setAssociatedData("ZhangSan", "k001", "v001").then(() => { 
      console.log('setAssociatedData Success');
  }).catch((err) => {
      console.log("setAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### getAllAccessibleAccounts<sup>(deprecated)</sup>

getAllAccessibleAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Obtains information about all accessible app accounts. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getAllAccounts](#getallaccounts9).

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of accessible app accounts. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts((err, data)=>{
  	console.debug("getAllAccessibleAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccessibleAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccessibleAccounts<sup>(deprecated)</sup>

getAllAccessibleAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Obtains information about all accessible app accounts. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getAllAccounts](#getallaccounts9-1).

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS

**System capability**: SystemCapability.Account.AppAccount

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise used to return the accessible app accounts.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllAccessibleAccounts().then((data) => { 
       console.log('getAllAccessibleAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccessibleAccounts err: "  + JSON.stringify(err));
  });
  ```

### getAllAccounts<sup>(deprecated)</sup>

getAllAccounts(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Obtains the app accounts that can be accessed by the invoker based on the app account owner. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getAccountsByOwner](#getaccountsbyowner9).

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description       |
| -------- | ---------------------------------------- | ---- | --------- |
| owner    | string                                   | Yes   | Owner of the app account. The value is the bundle name of the app.   |
| callback | AsyncCallback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return information about all accessible app accounts.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle, (err, data)=>{
  	console.debug("getAllAccounts err:" + JSON.stringify(err));
  	console.debug("getAllAccounts data:" + JSON.stringify(data));
  });
  ```

### getAllAccounts<sup>(deprecated)</sup>

getAllAccounts(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;

Obtains the app accounts that can be accessed by the invoker based on the app account owner. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getAccountsByOwner](#getaccountsbyowner9-1).

**Required permissions**: ohos.permission.GET_ALL_APP_ACCOUNTS (available only to system applications)

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description    |
| ----- | ------ | ---- | ------ |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Promise use to return the app accounts that can be accessed by the invoker.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  const selfBundle = "com.example.actsgetallaaccounts";
  appAccountManager.getAllAccounts(selfBundle).then((data) => { 
       console.log('getAllAccounts: ' + data);
  }).catch((err) => {
      console.log("getAllAccounts err: "  + JSON.stringify(err));
  });
  ```

### getAccountCredential<sup>(deprecated)</sup>

getAccountCredential(name: string, credentialType: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the credential of an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCredential](#getcredential9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type                         | Mandatory  | Description            |
| -------------- | --------------------------- | ---- | -------------- |
| name           | string                      | Yes   | Name of the target app account.       |
| credentialType | string                      | Yes   | Type of the credential to obtain.|
| callback       | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the credential obtained. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001", (err, result) => { 
      console.log("getAccountCredential err: " + JSON.stringify(err));
      console.log('getAccountCredential result: ' + result);
  });
  ```

### getAccountCredential<sup>(deprecated)</sup>

getAccountCredential(name: string, credentialType: string): Promise&lt;string&gt;

Obtains the credential of an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCredential](#getcredential9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name           | Type    | Mandatory  | Description        |
| -------------- | ------ | ---- | ---------- |
| name           | string | Yes   | Name of the target app account.   |
| credentialType | string | Yes   | Type of the credential to obtain.|

**Return value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise used to return the credential obtained.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountCredential("ZhangSan", "credentialType001").then((data) => { 
      console.log('getAccountCredential, result: ' + data);
  }).catch((err) => {
      console.log("getAccountCredential err: "  + JSON.stringify(err));
  });
  ```

### getAccountExtraInfo<sup>(deprecated)</sup>

getAccountExtraInfo(name: string, callback: AsyncCallback&lt;string&gt;): void

Obtains additional information of an app account. Additional information refers to other information that can be converted to the string type. It cannot contain sensitive information, such as the app account password and token. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCustomData](#getcustomdata9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description             |
| -------- | --------------------------- | ---- | --------------- |
| name     | string                      | Yes   | Name of the target app account.        |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the additional information obtained. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan", (err, result) => { 
      console.log("getAccountExtraInfo err: " + JSON.stringify(err));
      console.log('getAccountExtraInfo result: ' + result);
  });
  ```

### getAccountExtraInfo<sup>(deprecated)</sup>

getAccountExtraInfo(name: string): Promise&lt;string&gt;

Obtains additional information of an app account. Additional information refers to other information that can be converted to the string type. It cannot contain sensitive information, such as the app account password and token. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCustomData](#getcustomdata9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description     |
| ---- | ------ | ---- | ------- |
| name | string | Yes   | Name of the target app account.|

**Return value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise used to return the additional information obtained.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAccountExtraInfo("ZhangSan").then((data) => { 
      console.log('getAccountExtraInfo, result: ' + data);
  }).catch((err) => {
      console.log("getAccountExtraInfo err: "  + JSON.stringify(err));
  });
  ```

### getAssociatedData<sup>(deprecated)</sup>

getAssociatedData(name: string, key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains data associated with an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCustomData](#getcustomdata9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description               |
| -------- | --------------------------- | ---- | ----------------- |
| name     | string                      | Yes   | Name of the target app account.          |
| key      | string                      | Yes   | Key of the data to obtain.        |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the data obtained. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001", (err, result) => { 
      console.log("getAssociatedData err: " + JSON.stringify(err));
      console.log('getAssociatedData result: ' + result);
  });
  ```

### getAssociatedData<sup>(deprecated)</sup>

getAssociatedData(name: string, key: string): Promise&lt;string&gt;

Obtains data associated with an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCustomData](#getcustomdata9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name | Type    | Mandatory  | Description       |
| ---- | ------ | ---- | --------- |
| name | string | Yes   | Name of the target app account.  |
| key  | string | Yes   | Key of the data to obtain.|

**Return value**

| Type                   | Description                   |
| :-------------------- | :-------------------- |
| Promise&lt;string&gt; | Promise used to return the data obtained.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAssociatedData("ZhangSan", "k001").then((data) => { 
       console.log('getAssociatedData: ' + data);
  }).catch((err) => {
      console.log("getAssociatedData err: "  + JSON.stringify(err));
  });
  ```

### on('change')<sup>(deprecated)</sup>

on(type: 'change', owners: Array&lt;string&gt;, callback: Callback&lt;Array&lt;AppAccountInfo&gt;&gt;): void

Subscribes to account information changes of apps.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [on('accountChange')](#onaccountchange9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                            |
| -------- | ---------------------------------------- | ---- | ------------------------------ |
| type     | 'change'                                 | Yes   | Event type to subscribe to. The value is **'change'**. An event will be reported when the account information changes.|
| owners   | Array&lt;string&gt;                      | Yes   | App bundle names of the account.                     |
| callback | Callback&lt;Array&lt;[AppAccountInfo](#appaccountinfo)&gt;&gt; | Yes   | Callback invoked to return the account changes.          |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
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

### off('change')<sup>(deprecated)</sup>

off(type: 'change', callback?: Callback<Array\<AppAccountInfo>>): void

Unsubscribes from account information changes.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [off('accountChange')](#offaccountchange9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                              | Mandatory  | Description          |
| -------- | -------------------------------- | ---- | ------------ |
| type     | 'change'                         | Yes   | Event type to unsubscribe from. The value is **'change'**, which indicates the account change event.    |
| callback | Callback<Array\<[AppAccountInfo](#appaccountinfo)>> | No   | Callback to unregister.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
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

### authenticate<sup>(deprecated)</sup>

authenticate(name: string, owner: string, authType: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Authenticates an app account with customized options. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [auth](#auth9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                   | Mandatory  | Description             |
| -------- | --------------------- | ---- | --------------- |
| name     | string                | Yes   | Name of the target app account.    |
| owner    | string                | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string                | Yes   | Authentication type.          |
| options  | {[key: string]: any}  | Yes   | Options for the authentication.      |
| callback | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | Yes   | Callback invoked to return the result.|

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

  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.authenticate("LiSi", "com.example.accountjsdemo", "getSocialData", {}, {
    onResult: onResultCallback,
    onRequestRedirected: onRequestRedirectedCallback
  });
  ```

### getOAuthToken<sup>(deprecated)</sup>

getOAuthToken(name: string, owner: string, authType: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the authorization token of the specified authentication type for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthToken](#getauthtoken9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                         | Mandatory  | Description         |
| -------- | --------------------------- | ---- | ----------- |
| name     | string                      | Yes   | Name of the target app account.   |
| owner    | string                      | Yes   | Owner of the app account. The value is the bundle name of the app.|
| authType | string                      | Yes   | Authentication type.      |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the authorization token value obtained. Otherwise, **err** is an error object.  |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData", (err, data) => {
       console.log('getOAuthToken err: ' + JSON.stringify(err));
       console.log('getOAuthToken token: ' + data);
  });
  ```

### getOAuthToken<sup>(deprecated)</sup>

getOAuthToken(name: string, owner: string, authType: string): Promise&lt;string&gt;

Obtains the authorization token of the specified authentication type for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthToken](#getauthtoken9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description         |
| -------- | ------ | ---- | ----------- |
| name     | string | Yes   | Name of the target app account.   |
| owner    | string | Yes   | Owner of the app account. The value is the bundle name of the app.|
| authType | string | Yes   | Authentication type.      |

**Return value**

| Type                   | Description                   |
| --------------------- | --------------------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData").then((data) => {
       console.log('getOAuthToken token: ' + data);
  }).catch((err) => {
      console.log("getOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>(deprecated)</sup>

setOAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Sets an authorization token of the specific authentication type for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setAuthToken](#setauthtoken9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description      |
| -------- | ------------------------- | ---- | -------- |
| name     | string                    | Yes   | Name of the target app account.|
| authType | string                    | Yes   | Authentication type.   |
| token    | string                    | Yes   | Token to set.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "getSocialData", "xxxx", (err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### setOAuthToken<sup>(deprecated)</sup>

setOAuthToken(name: string, authType: string, token: string): Promise&lt;void&gt;

Sets an authorization token of the specific authentication type for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setAuthToken](#setauthtoken9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description      |
| -------- | ------ | ---- | -------- |
| name     | string | Yes   | Name of the target app account.|
| authType | string | Yes   | Authentication type.   |
| token    | string | Yes   | Authorization token to set.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthToken("LiSi", "getSocialData", "xxxx").then(() => {
      console.log('setOAuthToken successfully');
  }).catch((err) => {
      console.log('setOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>(deprecated)</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the authorization token of the specified authentication type for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteAuthToken](#deleteauthtoken9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                       | Mandatory  | Description          |
| -------- | ------------------------- | ---- | ------------ |
| name     | string                    | Yes   | Name of the target app account.    |
| owner    | string                    | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string                    | Yes   | Authentication type.       |
| token    | string                    | Yes   | Authorization token to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.    |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData", "xxxxx", (err) => {
       console.log('deleteOAuthToken err: ' + JSON.stringify(err));
  });
  ```

### deleteOAuthToken<sup>(deprecated)</sup>

deleteOAuthToken(name: string, owner: string, authType: string, token: string): Promise&lt;void&gt;

Deletes the authorization token of the specified authentication type for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [deleteAuthToken](#deleteauthtoken9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description          |
| -------- | ------ | ---- | ------------ |
| name     | string | Yes   | Name of the target app account.    |
| owner    | string | Yes   | Owner of the app account. The value is the bundle name of the app. |
| authType | string | Yes   | Authentication type.       |
| token    | string | Yes   | Authorization token to delete.|

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.deleteOAuthToken("LiSi", "com.example.accountjsdemo", "getSocialData", "xxxxx").then(() => {
       console.log('deleteOAuthToken successfully');
  }).catch((err) => {
      console.log("deleteOAuthToken err: "  + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>(deprecated)</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the visibility of an authorization token to an app. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setAuthTokenVisibility](#setauthtokenvisibility9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                       | Mandatory  | Description                       |
| ---------- | ------------------------- | ---- | ------------------------- |
| name       | string                    | Yes   | Name of the target app account.                 |
| authType   | string                    | Yes   | Authentication type.                    |
| bundleName | string                    | Yes   | Bundle name of the app.             |
| isVisible  | boolean                   | Yes   | Whether the authorization token is visible to the app. The value **true** means the authorization token is visible to the app; the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.                 |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo", true, (err) => {
       console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### setOAuthTokenVisibility<sup>(deprecated)</sup>

setOAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean): Promise&lt;void&gt;

Sets the visibility of an authorization token to an app. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [setAuthTokenVisibility](#setauthtokenvisibility9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type     | Mandatory  | Description          |
| ---------- | ------- | ---- | ------------ |
| name       | string  | Yes   | Name of the target app account.    |
| authType   | string  | Yes   | Authentication type.       |
| bundleName | string  | Yes   | Bundle name of the app.|
| isVisible  | boolean | Yes   | Whether the authorization token is visible to the app. The value **true** means the authorization token is visible to the app; the value **false** means the opposite.       |

**Return value**

| Type                 | Description                   |
| ------------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.setOAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo", true).then(() => {
      console.log('setOAuthTokenVisibility successfully');
  }).catch((err) => {
      console.log('setOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### checkOAuthTokenVisibility<sup>(deprecated)</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks the visibility of an authorization token of the specified authentication type to an app. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [checkAuthTokenVisibility](#checkauthtokenvisibility9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type                          | Mandatory  | Description         |
| ---------- | ---------------------------- | ---- | ----------- |
| name       | string                       | Yes   | Name of the target app account.   |
| authType   | string                       | Yes   | Authentication type.      |
| bundleName | string                       | Yes   | Bundle name of the app.|
| callback   | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** can be **true** (the authorization token is visible to the app) or **false** (the authorization token is not visible to the app). If the operation fails, **err** is an error object.   |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo", (err, data) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  });
  ```

### checkOAuthTokenVisibility<sup>(deprecated)</sup>

checkOAuthTokenVisibility(name: string, authType: string, bundleName: string): Promise&lt;boolean&gt;

Checks the visibility of an authorization token of the specified authentication type to an app. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [checkAuthTokenVisibility](#checkauthtokenvisibility9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name       | Type    | Mandatory  | Description           |
| ---------- | ------ | ---- | ------------- |
| name       | string | Yes   | Name of the target app account.     |
| authType   | string | Yes   | Authentication type.        |
| bundleName | string | Yes   | Bundle name of the app.|

**Return value**

| Type                    | Description                   |
| ---------------------- | --------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the authorization token is visible to the app; the value **false** means the opposite.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.checkOAuthTokenVisibility("LiSi", "getSocialData", "com.example.accountjsdemo").then((data) => {
      console.log('checkOAuthTokenVisibility isVisible: ' + data);
  }).catch((err) => {
      console.log('checkOAuthTokenVisibility err: ' + JSON.stringify(err));
  });
  ```

### getAllOAuthTokens<sup>(deprecated)</sup>

getAllOAuthTokens(name: string, owner: string, callback: AsyncCallback&lt;Array&lt;OAuthTokenInfo&gt;&gt;): void

Obtains all tokens visible to the invoker for an app account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAllAuthTokens](#getallauthtokens9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description         |
| -------- | ---------------------------------------- | ---- | ----------- |
| name     | string                                   | Yes   | Name of the target app account.   |
| owner    | string                                   | Yes   | Owner of the app account. The value is the bundle name of the app.|
| callback | AsyncCallback&lt;Array&lt;[OAuthTokenInfo](#oauthtokeninfodeprecated)&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of all tokens visible to the invoker. Otherwise, **err** is an error object.   |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.accountjsdemo", (err, data) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
      console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  });
  ```

### getAllOAuthTokens<sup>(deprecated)</sup>

getAllOAuthTokens(name: string, owner: string): Promise&lt;Array&lt;OAuthTokenInfo&gt;&gt;

Obtains all tokens visible to the invoker for an app account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAllAuthTokens](#getallauthtokens9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| name  | string | Yes   | Name of the target app account.   |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Return value**

| Type                                      | Description                   |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt; [OAuthTokenInfo](#oauthtokeninfodeprecated)&gt;&gt; | Promise used to return the tokens obtained.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAllOAuthTokens("LiSi", "com.example.accountjsdemo").then((data) => {
      console.log('getAllOAuthTokens data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getAllOAuthTokens err: "  + JSON.stringify(err));
  });
  ```

### getOAuthList<sup>(deprecated)</sup>

getOAuthList(name: string, authType: string, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the authorization list of the specified authentication type for an app account. The authorization list contains all authorized bundles. The token authorization list is set by setOAuthTokenVisibility(#setoauthtokenvisibilitydeprecated). This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthList](#getauthlist9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                      | Mandatory  | Description                     |
| -------- | ---------------------------------------- | ---- | ----------------------- |
| name     | string                                   | Yes   | Name of the target app account.               |
| authType | string                                   | Yes   | Authentication type.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of authorized bundles obtained. Otherwise, **err** is an error object.              |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.accountjsdemo", "getSocialData", (err, data) => {
    console.log('getOAuthList err: ' + JSON.stringify(err));
    console.log('getOAuthList data: ' + JSON.stringify(data));
  });
  ```

### getOAuthList<sup>(deprecated)</sup>

getOAuthList(name: string, authType: string): Promise&lt;Array&lt;string&gt;&gt;

Obtains the authorization list of the specified authentication type for an app account. The authorization list contains all authorized bundles. The token authorization list is set by setOAuthTokenVisibility(#setoauthtokenvisibilitydeprecated). This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthList](#getauthlist9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type    | Mandatory  | Description                     |
| -------- | ------ | ---- | ----------------------- |
| name     | string | Yes   | Name of the target app account.               |
| authType | string | Yes   | Authentication type.|

**Return value**

| Type                                | Description                   |
| ---------------------------------- | --------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return a list of authorized bundles.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getOAuthList("com.example.accountjsdemo", "getSocialData").then((data) => {
       console.log('getOAuthList data: ' + JSON.stringify(data));
  }).catch((err) => {
      console.log("getOAuthList err: "  + JSON.stringify(err));
  });
  ```

### getAuthenticatorCallback<sup>(deprecated)</sup>

getAuthenticatorCallback(sessionId: string, callback: AsyncCallback&lt;AuthenticatorCallback&gt;): void

Obtains the authenticator callback for an authentication session. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthCallback](#getauthcallback9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type                                      | Mandatory  | Description      |
| --------- | ---------------------------------------- | ---- | -------- |
| sessionId | string                                   | Yes   | ID of the authentication session.|
| callback  | AsyncCallback&lt;[AuthenticatorCallback](#authenticatorcallbackdeprecated)&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the authenticator callback obtained. Otherwise, **err** is an error object.|

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';
  let appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant((err, want) => {
    var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
    appAccountManager.getAuthenticatorCallback(sessionId, (err, callback) => {
        if (err.code != account_appAccount.ResultCode.SUCCESS) {
            console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
            return;
        }
        var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                      [account_appAccount.Constants.KEY_OWNER]: "com.example.accountjsdemo",
                      [account_appAccount.Constants.KEY_AUTH_TYPE]: "getSocialData",
                      [account_appAccount.Constants.KEY_TOKEN]: "xxxxxx"};
        callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
    });
  });
  ```

### getAuthenticatorCallback<sup>(deprecated)</sup>

getAuthenticatorCallback(sessionId: string): Promise&lt;AuthenticatorCallback&gt;

Obtains the authenticator callback for an authentication session. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getAuthCallback](#getauthcallback9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name      | Type    | Mandatory  | Description      |
| --------- | ------ | ---- | -------- |
| sessionId | string | Yes   | ID of the authentication session.|

**Return value**

| Type                                  | Description                   |
| ------------------------------------ | --------------------- |
| Promise&lt;[AuthenticatorCallback](#authenticatorcallbackdeprecated)&gt; | Promise used to return the authenticator callback obtained.|

**Example**

  ```js
  import featureAbility from '@ohos.ability.featureAbility';

  let appAccountManager = account_appAccount.createAppAccountManager();
  featureAbility.getWant().then((want) => {
      var sessionId = want.parameters[account_appAccount.Constants.KEY_SESSION_ID];
      appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
          var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                        [account_appAccount.Constants.KEY_OWNER]: "com.example.accountjsdemo",
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

### getAuthenticatorInfo<sup>(deprecated)</sup>

getAuthenticatorInfo(owner: string, callback: AsyncCallback&lt;AuthenticatorInfo&gt;): void

Obtains the authenticator information of an app. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [queryAuthenticatorInfo](#queryauthenticatorinfo9).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name     | Type                                    | Mandatory  | Description         |
| -------- | -------------------------------------- | ---- | ----------- |
| owner    | string                                 | Yes   | Owner of the app account. The value is the bundle name of the app.|
| callback | AsyncCallback&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the authenticator information obtained. Otherwise, **err** is an error object.   |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.accountjsdemo", (err, data) => {
      console.log("getAuthenticatorInfo err: "  + JSON.stringify(err));
      console.log('getAuthenticatorInfo data: ' + JSON.stringify(data));
  });
  ```

### getAuthenticatorInfo<sup>(deprecated)</sup>

getAuthenticatorInfo(owner: string): Promise&lt;AuthenticatorInfo&gt;

Obtains the authenticator information of an app. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [queryAuthenticatorInfo](#queryauthenticatorinfo9-1).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name  | Type    | Mandatory  | Description         |
| ----- | ------ | ---- | ----------- |
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|

**Return value**

| Type                              | Description                   |
| -------------------------------- | --------------------- |
| Promise&lt;[AuthenticatorInfo](#authenticatorinfo8)&gt; | Promise used to return the authenticator information obtained.|

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  appAccountManager.getAuthenticatorInfo("com.example.accountjsdemo").then((data) => { 
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
| owner | string | Yes   | Owner of the app account. The value is the bundle name of the app.|
| name  | string | Yes   | Name of the target app account.   |

## AuthTokenInfo<sup>9+</sup>

Defines authorization token information.

**System capability**: SystemCapability.Account.AppAccount

| Name              | Type           | Mandatory | Description             |
| -------------------- | -------------- | ----- | ---------------- |
| authType<sup>9+</sup>             | string         | Yes   | Authentication type.  |
| token<sup>9+</sup>                | string         | Yes   | Value of the authorization token.      |
| account<sup>9+</sup> | [AppAccountInfo](#appaccountinfo) | No   | Account information of the authorization token.|

## OAuthTokenInfo<sup>(deprecated)</sup>

Defines authorization token information.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AuthTokenInfo](#authtokeninfo9).

**System capability**: SystemCapability.Account.AppAccount

| Name              | Type           | Mandatory | Description             |
| -------------------- | -------------- | ----- | ---------------- |
| authType             | string         | Yes   | Authentication type.  |
| token                | string         | Yes   | Value of the authorization token.      |
| account<sup>9+</sup> | [AppAccountInfo](#appaccountinfo) | No   | Account information of the authorization token.|

## AuthenticatorInfo<sup>8+</sup>

Defines OAuth authenticator information.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type    | Mandatory  | Description        |
| ------- | ------ | ---- | ---------- |
| owner   | string | Yes   | Owner of the authenticator. The value is the bundle name of the app.|
| iconId  | number | Yes   | ID of the authenticator icon. |
| labelId | number | Yes   | ID of the authenticator label. |

## AuthResult<sup>9+</sup>

Defines the authentication result.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type    | Mandatory  | Description        |
| ------- | ------ | ---- | ---------- |
| account   | [AppAccountInfo](#appaccountinfo) | No   | Account information of the authorization token.|
| tokenInfo  | [AuthTokenInfo](#authtokeninfo9) | No   | Token information. |

## CreateAccountOptions<sup>9+</sup>

Defines the options for creating an app account.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type    | Mandatory  | Description        |
| ------- | ------ | ---- | ---------- |
| customData   | {[key: string]: string} | No   | Custom data.|

## CreateAccountImplicitlyOptions<sup>9+</sup>

Defines the options for implicitly creating an app account.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type    | Mandatory  | Description        |
| ------- | ------ | ---- | ---------- |
| requiredLabels   | Array&lt;string&gt; | No   | Labels required.|
| authType   | string | No   | Authentication type.|
| parameters   | {[key: string]: Object} | No   | Customized parameters.|
## SelectAccountsOptions<sup>9+</sup>

Defines the options for selecting accounts.

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
| parameters     | {[key: string]: Object} | No   | Customized parameters.|


## SetPropertiesOptions<sup>9+</sup>

Represents the options for setting authenticator properties.

**System capability**: SystemCapability.Account.AppAccount

| Name    | Type                   | Mandatory | Description          |
| ---------- | ---------------------- | ----- | -------------- |
| properties | {[key: string]: Object} | No   | Authenticator properties.     |
| parameters | {[key: string]: Object} | No   | Customized parameters.|

## Constants<sup>8+</sup>

Enumerates the constants.

**System capability**: SystemCapability.Account.AppAccount

| Name                           | Value                   | Description                  |
| -------------------------------- | ---------------------- | ----------------------- |
| ACTION_ADD_ACCOUNT_IMPLICITLY<sup>(deprecated)</sup>    | "addAccountImplicitly" | Operation of adding an account implicitly. |
| ACTION_AUTHENTICATE<sup>(deprecated)</sup>              | "authenticate"         | Authentication operation.        |
| ACTION_CREATE_ACCOUNT_IMPLICITLY<sup>9+</sup>    | "createAccountImplicitly" | Operation of creating an account implicitly. |
| ACTION_AUTH<sup>9+</sup>              | "auth"         | Authentication operation.        |
| ACTION_VERIFY_CREDENTIAL<sup>9+</sup>    | "verifyCredential" | Operation of verifying credentials. |
| ACTION_SET_AUTHENTICATOR_PROPERTIES<sup>9+</sup> | "setAuthenticatorProperties" | Operation of setting authenticator properties.     |
| KEY_NAME                         | "name"                 | Name of the app account. |
| KEY_OWNER                        | "owner"                | Owner of the app account.|
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

| Name                                 | Value  | Description          |
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
| ERROR_OAUTH_TOKEN_NOT_EXIST         | 10014 | The authorization token does not exist.|
| ERROR_OAUTH_TOKEN_TOO_MANY          | 10015 | The number of OAuth tokens reaches the limit. |
| ERROR_OAUTH_UNSUPPORT_ACTION        | 10016 | The authentication operation is not supported. |
| ERROR_OAUTH_UNSUPPORT_AUTH_TYPE     | 10017 | The authentication type is not supported. |
| ERROR_PERMISSION_DENIED             | 10018 | The required permission is missing.     |

## AuthCallback<sup>9+</sup>

Implements authenticator callbacks.

### onResult<sup>9+</sup>

onResult: (code: number, result?: AuthResult) =&gt; void

Called to return the result of an authentication request.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name   | Type                  | Mandatory  | Description    |
| ------ | -------------------- | ---- | ------ |
| code   | number               | Yes   | Authentication result code.|
| result | [AuthResult](#authresult9) | No   | Authentication result. |

**Example**

  ```js
  let appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthCallback(sessionId).then((callback) => {
      var result = {
          accountInfo: {
            name: "Lisi",
            owner: "com.example.accountjsdemo",
          },
          tokenInfo: {
            token: "xxxxxx",
            authType: "getSocialData"
          }
      };
      callback.onResult(account_appAccount.ResultCode.SUCCESS, result);
  }).catch((err) => {
      console.log("getAuthCallback err: "  + JSON.stringify(err));
  });
  ```

### onRequestRedirected<sup>9+</sup>

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
      createAccountImplicitly(options, callback) {
          callback.onRequestRedirected({
              bundleName: "com.example.accountjsdemo",
              abilityName: "com.example.accountjsdemo.LoginAbility",
          });
      }

      auth(name, authType, options, callback) {
          var result = {
            accountInfo: {
              name: "Lisi",
              owner: "com.example.accountjsdemo",
            },
            tokenInfo: {
              token: "xxxxxx",
              authType: "getSocialData"
            }
          };
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
  let appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthCallback(sessionId).then((callback) => {
      callback.onRequestContinued();
  }).catch((err) => {
      console.log("getAuthCallback err: "  + JSON.stringify(err));
  });
  ```

## AuthenticatorCallback<sup>(deprecated)</sup>

Provides OAuth authenticator callbacks.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [AuthCallback](#authcallback9).

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
  let appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
      var result = {[account_appAccount.Constants.KEY_NAME]: "LiSi",
                    [account_appAccount.Constants.KEY_OWNER]: "com.example.accountjsdemo",
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
              bundleName: "com.example.accountjsdemo",
              abilityName: "com.example.accountjsdemo.LoginAbility",
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
  let appAccountManager = account_appAccount.createAppAccountManager();
  var sessionId = "1234";
  appAccountManager.getAuthenticatorCallback(sessionId).then((callback) => {
      callback.onRequestContinued();
  }).catch((err) => {
      console.log("getAuthenticatorCallback err: "  + JSON.stringify(err));
  });
  ```

## Authenticator<sup>8+</sup>

Provides APIs to operate the authenticator.

### createAccountImplicitly<sup>9+</sup>

createAccountImplicitly(options: CreateAccountImplicitlyOptions, callback: AuthCallback): void

Creates an app account implicitly based on the specified account owner. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| options          | [CreateAccountImplicitlyOptions](#createaccountimplicitlyoptions9)  | Yes   | Options for implicitly creating the account.     |
| callback         | [AuthCallback](#authcallback9) | Yes   | Authenticator callback invoked to return the result.|

### addAccountImplicitly<sup>deprecated</sup>

addAccountImplicitly(authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Adds an app account implicitly based on the specified authentication type and options. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [createAccountImplicitly](#createaccountimplicitly9-2).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| authType         | string                | Yes   | Authentication type.     |
| callerBundleName | string                | Yes   | Bundle name of the authentication requester.      |
| options          | {[key: string]: any}  | Yes   | Options for the authentication.     |
| callback         | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | Yes   | Authenticator callback invoked to return the authentication result.|

### auth<sup>9+</sup>

auth(name: string, authType: string, options: {[key:string]: Object}, callback: AuthCallback): void

Authenticates an app account to obtain the authorization token. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name             | string                | Yes   | Name of the target app account.       |
| authType         | string                | Yes   | Authentication type.     |
| callerBundleName | string                | Yes   | Authentication type.      |
| options          | {[key: string]: Object}  | Yes   | Options for the authentication.     |
| callback         | [AuthCallback](#authcallback9) | Yes   | Callback invoked to return the result.|

### authenticate<sup>deprecated</sup>

authenticate(name: string, authType: string, callerBundleName: string, options: {[key: string]: any}, callback: AuthenticatorCallback): void

Authenticates an app account to obtain the authorization token. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [auth](#auth9-2).

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name             | string                | Yes   | Name of the target app account.       |
| authType         | string                | Yes   | Authentication type.     |
| callerBundleName | string                | Yes   | Bundle name of the authentication requester.      |
| options          | {[key: string]: any}  | Yes   | Options for the authentication.     |
| callback         | [AuthenticatorCallback](#authenticatorcallbackdeprecated) | Yes   | Authenticator callback invoked to return the authentication result.|

### verifyCredential<sup>9+</sup>

verifyCredential(name: string, options: VerifyCredentialOptions, callback: AuthCallback): void;

Verifies the credential of an app account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                   | Yes   | Name of the target app account.             |
| options   | [VerifyCredentialOptions](#verifycredentialoptions9)  | Yes   | Options for credential verification.           |
| callback  | [AuthCallback](#authcallback9)    | Yes   | Authenticator callback invoked to return the verification result.|

### setProperties<sup>9+</sup>

setProperties(options: SetPropertiesOptions, callback: AuthCallback): void;

Sets the authenticator properties. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| options   | [SetPropertiesOptions](#setpropertiesoptions9)  | Yes   | Authenticator properties to set.           |
| callback  | [AuthCallback](#authcallback9) | Yes   | Authenticator callback invoked to return the result.|

### checkAccountLabels<sup>9+</sup>

checkAccountLabels(name: string, labels: Array&lt;string&gt;, callback: AuthCallback): void;

Checks the account labels. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                | Yes   | Name of the target app account.             |
| labels    | Array&lt;string&gt;          | Yes   | Labels to check.                  |
| callback  | [AuthCallback](#authcallback9) | Yes   | Authenticator callback invoked to return the check result.|

### isAccountRemovable<sup>9+</sup>

isAccountRemovable(name: string, callback: AuthCallback): void;

Checks whether an app account can be deleted. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.AppAccount

**Parameters**

| Name             | Type                   | Mandatory  | Description             |
| ---------------- | --------------------- | ---- | --------------- |
| name      | string                | Yes   | Name of the target app account.             |
| callback  | [AuthCallback](#authcallback9) | Yes   | Authenticator callback invoked to return the result.|

### getRemoteObject<sup>9+</sup>

getRemoteObject(): rpc.RemoteObject;

Obtains the remote object of an authenticator. This API cannot be overloaded.

**System capability**: SystemCapability.Account.AppAccount

**Example**

  ```js
  class MyAuthenticator extends account_appAccount.Authenticator {
    addAccountImplicitly(authType, callerBundleName, options, callback) {
      callback.onRequestRedirected({
        bundleName: "com.example.accountjsdemo",
        abilityName: "com.example.accountjsdemo.LoginAbility",
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
        bundleName: "com.example.accountjsdemo",
        abilityName: "com.example.accountjsdemo.VerifyAbility",
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
