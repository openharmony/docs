# 管理应用帐号

应用开发者可以使用[应用帐号SDK](../reference/apis/js-apis-appAccount.md)管理本应用的帐号数据。

## 开发准备

1. 导入应用帐号模块。

   ```ts
   import account_appAccount from '@ohos.account.appAccount';
   ```

2. 获取应用帐号的实例对象。

   ```ts
   const appAccountManager = account_appAccount.createAppAccountManager();
   ```

## 创建应用帐号

用户在应用中登录后，开发者可以在系统中创建一个关联的应用帐号，后续可以基于此帐号进行数据管理。

具体开发实例如下：

1. 参数准备，指定帐号名和可选配置。

   ```ts
   let name: string = "ZhangSan";
   let options: account_appAccount.CreateAccountOptions = {
     customData: {
       age: 10
     }
   };
   ```

2. 调用[createAccount](../reference/apis/js-apis-appAccount.md#createaccount9)接口，根据名称和选项创建应用帐号。

   ```ts
   try {
     await appAccountManager.createAccount(name, options);
     console.log('createAccount successfully');
   } catch (err: BusinessError) {
     console.log('createAccount failed, error: ' + JSON.stringify(err));
   }
   ```

## 查询应用帐号列表

具体开发实例如下：

1. 准备参数，指定帐号所有者。

   ```ts
   let owner: string = 'com.example.accountjsdemo2';
   ```

2. 调用[getAllAccounts](../reference/apis/js-apis-appAccount.md#getallaccounts9)接口查询帐号列表。

   ```ts
   appAccountManager.getAllAccounts().then((data: account_appAccount.AppAccountInfo[]) => {
       console.debug('getAllAccounts successfully, data: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.debug('getAllAccounts failed, error: ' + JSON.stringify(err));
   });
   ```

## 存取帐号的凭据

具体开发实例如下：

1. 准备参数，指定帐号名、凭据类型和凭据。

   ```ts
   let name: string = 'ZhangSan';
   let credentialType: string = 'PIN_SIX';
   let credential: string = 'xxxxxx';
   ```

2. 调用[getCredential](../reference/apis/js-apis-appAccount.md#getcredential9)接口，获取帐号的凭据。

   ```ts
   appAccountManager.getCredential(name, credentialType).then((data: string) => {
       console.log('getCredential successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.log('getCredential failed, error: ' + JSON.stringify(err));
   });
   ```

3. 调用[setCredential](../reference/apis/js-apis-appAccount.md#setcredential9)接口，设置帐号的凭据。

   ```ts
   appAccountManager.setCredential(name, credentialType, credential).then(() => {
       console.log('setCredential successfully');
   }).catch((err: BusinessError) => {
       console.log('setCredential failed: ' + JSON.stringify(err));
   });
   ```

## 存取帐号的自定义数据

具体开发实例如下：

1. 准备参数，指定帐号名和自定义键值。

   ```ts
   let name: string = 'ZhangSan';
   let key: string = 'age';
   let value: string = '12';
   ```

2. 调用[setCustomData](../reference/apis/js-apis-appAccount.md#setcustomdata9)接口，设置帐号的自定义数据。

   ```ts
   appAccountManager.setCustomData(name, key, value).then(() => {
       console.log('setCustomData successfully');
   }).catch((err: BusinessError) => {
       console.log('setCustomData failed: ' + JSON.stringify(err));
   });
   ```

3. 调用[getCustomData](../reference/apis/js-apis-appAccount.md#getcustomdata9)接口，获取帐号的自定义数据。

   ```ts
   appAccountManager.getCustomData(name, key).then((data: string) => {
       console.log('getCustomData successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.log('getCustomData failed, error: ' + JSON.stringify(err));
   });
   ```

## 存取帐号的授权令牌

具体开发实例如下：

1. 准备参数，指定帐号名、帐号所有者、授权类型和授权令牌。

   ```ts
   let name: string = 'ZhangSan';
   let owner: string = 'com.example.accountjsdemo';
   let authType: string = 'getSocialData';
   let token: string = 'xxxxxx';
   ```

2. 调用[setAuthToken](../reference/apis/js-apis-appAccount.md#setauthtoken9)接口，设置指定授权类型的授权令牌。

   ```ts
   appAccountManager.setAuthToken(name, authType, token).then(() => {
       console.log('setAuthToken successfully');
   }).catch((err: BusinessError) => {
       console.log('setAuthToken failed: ' + JSON.stringify(err));
   });
   ```

3. 调用[getAuthToken](../reference/apis/js-apis-appAccount.md#getauthtoken9)接口，获取指定授权类型的授权令牌。

   ```ts
   appAccountManager.getAuthToken(name, owner, authType).then((data: string) => {
       console.log('getAuthToken successfully, data: ' + data);
   }).catch((err: BusinessError) => {
       console.log('getAuthToken failed, error: ' + JSON.stringify(err));
   });
   ```

## 删除应用帐号

用户退出登录后，应用需及时将相应的应用帐号从系统中删除。

具体开发实例如下：

1. 指定要删除的帐号名称，调用[removeAccount](../reference/apis/js-apis-appAccount.md#removeaccount9)接口删除帐号。

   ```ts
   let name: string = 'Zhangsan';
   appAccountManager.removeAccount(name).then(() => {
       console.log('removeAccount successfully');
   }).catch((err: BusinessError) => {
       console.log('removeAccount failed, error: ' + JSON.stringify(err));
   });
   ```
