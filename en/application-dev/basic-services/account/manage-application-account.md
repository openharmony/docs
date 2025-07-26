# Managing Application Accounts

You can use the [application account SDK](../../reference/apis-basic-services-kit/js-apis-appAccount.md) to manage application accounts.

When an application is uninstalled, the account data of the application will be automatically deleted. When a local account is deleted, the account data of all applications of the local account will be automatically deleted.

## Before You Start

1. Import the **appAccount** module.

   ```ts
   import { appAccount, BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain an **AppAccountManager** instance.

   ```ts
   const appAccountManager = appAccount.createAppAccountManager();
   ```

## Creating an Application Account

Create an application account for an application user.

**Procedure**

1. Specify the account name and optional parameters.

   ```ts
   let name: string = "ZhangSan";
   let options: appAccount.CreateAccountOptions = {
     customData: {
       age: '10'
     }
   };
   ```

2. Use [createAccount](../../reference/apis-basic-services-kit/js-apis-appAccount.md#createaccount9) to create an application account based on the specified parameters.

   ```ts
   appAccountManager.createAccount(name, options).then(()=>{
    console.log('createAccount successfully');
  }).catch((err: BusinessError)=>{
    console.error('createAccount failed, error: ' + JSON.stringify(err));
  });
   ```

## Obtaining Application Account List

**Procedure**


Use [getAllAccounts](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getallaccounts9) to obtain the application account list.

   ```ts
   appAccountManager.getAllAccounts().then((data: appAccount.AppAccountInfo[]) => {
       console.log('getAllAccounts successfully, data: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.error('getAllAccounts failed, error: ' + JSON.stringify(err));
   });
   ```

## Accessing Account Credentials

**Procedure**

1. Specify the account name, credential type, and credential.

   ```ts
   let name: string = 'ZhangSan';
   let credentialType: string = 'PIN_SIX';
   let credential: string = 'xxxxxx';
   ```

2. Use [getCredential](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getcredential9) to obtain the account credential.

   ```ts
   appAccountManager.getCredential(name, credentialType).then((data: string) => {
       console.log('getCredential successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.error('getCredential failed, error: ' + JSON.stringify(err));
   });
   ```

3. Use [setCredential](../../reference/apis-basic-services-kit/js-apis-appAccount.md#setcredential9) to set the account credential.

   ```ts
   appAccountManager.setCredential(name, credentialType, credential).then(() => {
       console.log('setCredential successfully');
   }).catch((err: BusinessError) => {
       console.error('setCredential failed: ' + JSON.stringify(err));
   });
   ```

## Accessing Custom Account Data

**Procedure**

1. Specify the account name and custom data.

   ```ts
   let name: string = 'ZhangSan';
   let key: string = 'age';
   let value: string = '12';
   ```

2. Use [setCustomData](../../reference/apis-basic-services-kit/js-apis-appAccount.md#setcustomdata9) to customize account data.

   ```ts
   appAccountManager.setCustomData(name, key, value).then(() => {
       console.log('setCustomData successfully');
   }).catch((err: BusinessError) => {
       console.error('setCustomData failed: ' + JSON.stringify(err));
   });
   ```

3. Use [getCustomData](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getcustomdata9) to obtain the custom account data.

   ```ts
   appAccountManager.getCustomData(name, key).then((data: string) => {
       console.log('getCustomData successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.error('getCustomData failed, error: ' + JSON.stringify(err));
   });
   ```

## Accessing the Account Authentication Token

**Procedure**

1. Specify the account name, account owner, authorization type, and authentication token.

   ```ts
   let name: string = 'ZhangSan';
   let owner: string = 'com.example.accountjsdemo';
   let authType: string = 'getSocialData';
   let token: string = 'xxxxxx';
   ```

2. Use [setAuthToken](../../reference/apis-basic-services-kit/js-apis-appAccount.md#setauthtoken9) to set an authorization token for the specified authentication type.

   ```ts
   appAccountManager.setAuthToken(name, authType, token).then(() => {
       console.log('setAuthToken successfully');
   }).catch((err: BusinessError) => {
       console.error('setAuthToken failed: ' + JSON.stringify(err));
   });
   ```

3. Use [getAuthToken](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getauthtoken9) to obtain the authentication token of the specified authentication type.

   ```ts
   appAccountManager.getAuthToken(name, owner, authType).then((data: string) => {
       console.log('getAuthToken successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.error('getAuthToken failed, error: ' + JSON.stringify(err));
   });
   ```

## Removing an Application Account

Remove the application account after the user logs out of the system.

**Procedure**

Use [removeAccount](../../reference/apis-basic-services-kit/js-apis-appAccount.md#removeaccount9) to remove the application account.

   ```ts
   let name: string = 'Zhangsan';
   appAccountManager.removeAccount(name).then(() => {
       console.log('removeAccount successfully');
   }).catch((err: BusinessError) => {
       console.error('removeAccount failed, error: ' + JSON.stringify(err));
   });
   ```

<!--RP1-->
<!--RP1End-->
