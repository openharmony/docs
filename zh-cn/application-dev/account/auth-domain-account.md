# 认证域帐号

当需要验证域帐号身份（比如屏幕解锁、登录会话失效等场景）时，可以使用系统提供的接口对域帐号进行身份认证。

## 开发准备

导入系统帐号模块。

```ts
import account_osAccount from '@ohos.account.osAccount';
```

## 使用密码认证域帐号

用户可以使用密码认证域帐号。开发者可以使用[auth](../reference/apis/js-apis-osAccount.md#auth10)接口完成此操作。此外使用该接口，应用还需要申请ohos.permission.ACCESS_USER_AUTH_INTERNAL权限。

具体开发实例如下：

1. 申请权限：ohos.permission.ACCESS_USER_AUTH_INTERNAL。申请流程请参考：[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级的应用申请权限)。

2. 获取用户输入，包括域帐号信息和域帐号密码。

   ```ts
     let domainAccountInfo: account_osAccount.DomainAccountInfo = {
       domain: 'CHINA',
       accountName: 'zhangsan'
     }
     let credential: Uint8Array = new Uint8Array([0]);
   ```

3. 定义认证结果回调。

   ```ts
   let callback: IUserAuthCallback = {
     onResult: (resultCode: number, authResult: account_osAccount.AuthResult) => {
       console.log('auth resultCode = ' + resultCode);
       console.log('auth authResult = ' + JSON.stringify(authResult));
     }
   }
   ```

4. 调用[auth](../reference/apis/js-apis-osAccount.md#auth10)接口进行密码认证。

   ```ts
   try {
     account_osAccount.DomainAccountManager.auth(domainAccountInfo, credential, callback);
   } catch (err) {
     console.log('auth exception = ' + JSON.stringify(err));
   }
   ```

## 弹窗认证域帐号

在无法获取用户密码的情况下，需要认证域帐号时，可以请求系统弹窗验证域帐号用户。开发者可以使用[authWithPopup](../reference/apis/js-apis-osAccount.md#authwithpopup10)完成此操作。

具体开发实例如下：

1. 定义认证结果回调对象。

   ```ts
   let callback: IUserCallback = {
     onResult: (resultCode: number, authResult: account_osAccount.AuthResult) => {
       console.log('authWithPopup resultCode = ' + resultCode);
       console.log('authWithPopup authResult = ' + JSON.stringify(authResult));
     }
   }
   ```

2. 调用[authWithPopup](../reference/apis/js-apis-osAccount.md#authwithpopup10)接口弹窗认证当前域帐号。

   ```ts
   try {
     account_osAccount.DomainAccountManager.authWithPopup(callback)
   } catch (err) {
     console.log('authWithPopup exception = ' + JSON.stringify(err));
   }
   ```
