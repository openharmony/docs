# 帐号子系统ChangeLog

## cl.account_os_account.1 域插件查询帐号信息接口变更

域插件查询帐号信息接口getAccountInfo变更，为提高接参数的可扩展性，将原来的方法中的指定类型入参，替换为可扩展类型（GetDomainAccountInfoPluginOptions）入参。

**变更影响**

开发者需要适配新的入参类型，否则将导致编译失败。适配方式请参考下文示例代码。

**关键接口/组件变更**

变更前：

```js
  interface DomainPlugin {
    ...
    getAccountInfo(domain: string, accountName: string, callback: AsyncCallback<DomainAccountInfo>): void;
    ...
  }
```

变更后：
```js
  interface DomainPlugin {
    ...
    getAccountInfo(options: GetDomainAccountInfoPluginOptions, callback: AsyncCallback<DomainAccountInfo>): void;
    ...
  }
```

**适配指导**

接口入参修改为指定GetDomainAccountInfoPluginOptions类型，示例代码如下。

```js
  let plugin: account_osAccount.DomainPlugin = {
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,
        callback: account_osAccount.IUserAuthCallback) => {},
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,
                  callback: account_osAccount.IUserAuthCallback) => {},
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,
                  callback: account_osAccount.IUserAuthCallback) => {},
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions, // 接口入参变更
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {
    // mock getting account information
    // notify result
    let code: BusinessError = {
      code: 0,
      name: "",
      message: ""
    };
    let accountInfo: account_osAccount.DomainAccountInfo = {
      domain: options.domain, // 入参读取方式
      accountName: options.accountName, // 入参读取方式
      accountId: 'xxxx'
    };
    callback(code, accountInfo);
  },
  getAuthStatusInfo: (domainAccountInfo: account_osAccount.DomainAccountInfo,
                      callback: AsyncCallback<account_osAccount.AuthStatusInfo>) => {},
  bindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, localId: number,
                callback: AsyncCallback<void>) => {},
  unbindAccount: (domainAccountInfo: account_osAccount.DomainAccountInfo, callback: AsyncCallback<void>) => {},
  isAccountTokenValid: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,
                        callback: AsyncCallback<boolean>) => {},
  getAccessToken: (options: account_osAccount.GetDomainAccessTokenOptions, callback: AsyncCallback<Uint8Array>) => {}
}
  account_osAccount.DomainAccountManager.registerPlugin(plugin)
```
