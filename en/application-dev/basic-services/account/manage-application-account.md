# Managing App Accounts

You can use the [application account SDK](../../reference/apis-basic-services-kit/js-apis-appAccount.md) to manage app accounts.

When an app is uninstalled, the account data of the app will be automatically deleted. When a local account is deleted, the account data of all apps of the local account will be automatically deleted.

## Before You Start

1. Import the **appAccount** module.

   ```ts
   import { appAccount, BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain an **AppAccountManager** instance.

   ```ts
   const appAccountManager = appAccount.createAppAccountManager();
   ```

## Creating an App Account

Create an app account for an application user.

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

2. Use [createAccount](../../reference/apis-basic-services-kit/js-apis-appAccount.md#createaccount9) to create an app account based on the specified parameters.

   ```ts
   try {
     await appAccountManager.createAccount(name, options);
     console.log('createAccount successfully');
   } catch (err) {
     console.log('createAccount failed, error: ' + JSON.stringify(err));
   }
   ```

## Obtaining App Account List

**Procedure**

1. Specify the account owner.

   ```ts
   let owner: string = 'com.example.accountjsdemo2';
   ```

2. Use [getAllAccounts](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getallaccounts9) to obtain the app account list.

   ```ts
   appAccountManager.getAllAccounts().then((data: appAccount.AppAccountInfo[]) => {
       console.debug('getAllAccounts successfully, data: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.debug('getAllAccounts failed, error: ' + JSON.stringify(err));
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
       console.log('getCredential failed, error: ' + JSON.stringify(err));
   });
   ```

3. Use [setCredential](../../reference/apis-basic-services-kit/js-apis-appAccount.md#setcredential9) to set the account credential.

   ```ts
   appAccountManager.setCredential(name, credentialType, credential).then(() => {
       console.log('setCredential successfully');
   }).catch((err: BusinessError) => {
       console.log('setCredential failed: ' + JSON.stringify(err));
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
       console.log('setCustomData failed: ' + JSON.stringify(err));
   });
   ```

3. Use [getCustomData](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getcustomdata9) to obtain the custom account data.

   ```ts
   appAccountManager.getCustomData(name, key).then((data: string) => {
       console.log('getCustomData successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.log('getCustomData failed, error: ' + JSON.stringify(err));
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
       console.log('setAuthToken failed: ' + JSON.stringify(err));
   });
   ```

3. Use [getAuthToken](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getauthtoken9) to obtain the authentication token of the specified authentication type.

   ```ts
   appAccountManager.getAuthToken(name, owner, authType).then((data: string) => {
       console.log('getAuthToken successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.log('getAuthToken failed, error: ' + JSON.stringify(err));
   });
   ```

## Removing an App Account

Remove the app account after the user logs out of the system.

**Procedure**

1. Use [removeAccount](../../reference/apis-basic-services-kit/js-apis-appAccount.md#removeaccount9) to remove the app account.

   ```ts
   let name: string = 'Zhangsan';
   appAccountManager.removeAccount(name).then(() => {
       console.log('removeAccount successfully');
   }).catch((err: BusinessError) => {
       console.log('removeAccount failed, error: ' + JSON.stringify(err));
   });
   ```
