# 管理应用账号

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @zhaimengchao-->
<!--Adviser: @zengyawen-->

应用开发者可以使用[应用账号SDK](../../reference/apis-basic-services-kit/js-apis-appAccount.md)管理本应用的账号数据。

能力限制：应用卸载场景下，被卸载应用的账号数据会被删除；本地账号删除场景下，被删除本地账号下的所有应用的账号数据会被删除。

## 开发准备

1. 导入应用账号模块。

   ```ts
   import { appAccount, BusinessError } from '@kit.BasicServicesKit';
   ```

2. 获取应用账号的实例对象。

   ```ts
   const appAccountManager = appAccount.createAppAccountManager();
   ```

## 创建应用账号

用户在应用中登录后，开发者可以在系统中创建一个关联的应用账号，后续可以基于此账号进行数据管理。

具体开发实例如下：

1. 参数准备，指定账号名和可选配置。

   ```ts
   let name: string = "ZhangSan";
   let options: appAccount.CreateAccountOptions = {
     customData: {
       age: '10'
     }
   };
   ```

2. 调用[createAccount](../../reference/apis-basic-services-kit/js-apis-appAccount.md#createaccount9)接口，根据名称和选项创建应用账号。

   ```ts
   appAccountManager.createAccount(name, options).then(()=>{
       console.info('createAccount successfully');
   }).catch((err: BusinessError)=>{
       console.error(`createAccount failed, error: code is ${err.code}, message is ${err.message}`);
   });
   ```

## 查询应用账号列表

具体开发实例如下：


调用[getAllAccounts](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getallaccounts9)接口查询账号列表。

   ```ts
   appAccountManager.getAllAccounts().then((data: appAccount.AppAccountInfo[]) => {
       console.log('getAllAccounts successfully, data: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.error('getAllAccounts failed, error: ' + JSON.stringify(err));
   });
   ```

## 存取账号的凭据

具体开发实例如下：

1. 准备参数，指定账号名、凭据类型和凭据。

   ```ts
   let name: string = 'ZhangSan';
   let credentialType: string = 'PIN_SIX';
   let credential: string = 'xxxxxx';
   ```

2. 调用[getCredential](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getcredential9)接口，获取账号的凭据。

   ```ts
   appAccountManager.getCredential(name, credentialType).then((data: string) => {
       console.log('getCredential successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.error('getCredential failed, error: ' + JSON.stringify(err));
   });
   ```

3. 调用[setCredential](../../reference/apis-basic-services-kit/js-apis-appAccount.md#setcredential9)接口，设置账号的凭据。

   ```ts
   appAccountManager.setCredential(name, credentialType, credential).then(() => {
       console.log('setCredential successfully');
   }).catch((err: BusinessError) => {
       console.error('setCredential failed: ' + JSON.stringify(err));
   });
   ```

## 存取账号的自定义数据

具体开发实例如下：

1. 准备参数，指定账号名和自定义键值。

   ```ts
   let name: string = 'ZhangSan';
   let key: string = 'age';
   let value: string = '12';
   ```

2. 调用[setCustomData](../../reference/apis-basic-services-kit/js-apis-appAccount.md#setcustomdata9)接口，设置账号的自定义数据。

   ```ts
   appAccountManager.setCustomData(name, key, value).then(() => {
       console.log('setCustomData successfully');
   }).catch((err: BusinessError) => {
       console.error('setCustomData failed: ' + JSON.stringify(err));
   });
   ```

3. 调用[getCustomData](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getcustomdata9)接口，获取账号的自定义数据。

   ```ts
   appAccountManager.getCustomData(name, key).then((data: string) => {
       console.log('getCustomData successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.error('getCustomData failed, error: ' + JSON.stringify(err));
   });
   ```

## 存取账号的授权令牌

具体开发实例如下：

1. 准备参数，指定账号名、账号所有者、授权类型和授权令牌。

   ```ts
   let name: string = 'ZhangSan';
   let owner: string = 'com.example.accountjsdemo';
   let authType: string = 'getSocialData';
   let token: string = 'xxxxxx';
   ```

2. 调用[setAuthToken](../../reference/apis-basic-services-kit/js-apis-appAccount.md#setauthtoken9)接口，设置指定授权类型的授权令牌。

   ```ts
   appAccountManager.setAuthToken(name, authType, token).then(() => {
       console.log('setAuthToken successfully');
   }).catch((err: BusinessError) => {
       console.error('setAuthToken failed: ' + JSON.stringify(err));
   });
   ```

3. 调用[getAuthToken](../../reference/apis-basic-services-kit/js-apis-appAccount.md#getauthtoken9)接口，获取指定授权类型的授权令牌。

   ```ts
   appAccountManager.getAuthToken(name, owner, authType).then((data: string) => {
       console.log('getAuthToken successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.error('getAuthToken failed, error: ' + JSON.stringify(err));
   });
   ```

## 删除应用账号

用户退出登录后，应用需及时将相应的应用账号从系统中删除。

具体开发实例如下：

指定要删除的账号名称，调用[removeAccount](../../reference/apis-basic-services-kit/js-apis-appAccount.md#removeaccount9)接口删除账号。

   ```ts
   let name: string = 'ZhangSan';
   appAccountManager.removeAccount(name).then(() => {
       console.log('removeAccount successfully');
   }).catch((err: BusinessError) => {
       console.error('removeAccount failed, error: ' + JSON.stringify(err));
   });
   ```

<!--RP1-->
<!--RP1End-->