# Account Subsystem Changelog

## cl.account_os_account.1 Change of getAccountInfo()

Changed the parameters in **getAccountInfo()** from the specified type to the extensible type (**GetDomainAccountInfoPluginOptions**) to improve parameter scalability.

**Change Impact**

New parameters must be used. Otherwise, the compilation fails. For details about the adaptation, see the following sample code.

**Key API/Component Changes**

Before change:

```js
  interface DomainPlugin {
    ...
    getAccountInfo(domain: string, accountName: string, callback: AsyncCallback<DomainAccountInfo>): void;
    ...
  }
```

After change:
```js
  interface DomainPlugin {
    ...
    getAccountInfo(options: GetDomainAccountInfoPluginOptions, callback: AsyncCallback<DomainAccountInfo>): void;
    ...
  }
```

**Adaptation Guide**

Change **domain** and **accountName** to **GetDomainAccountInfoPluginOptions**. The sample code is as follows:

```js
  let plugin: account_osAccount.DomainPlugin = {
  auth: (domainAccountInfo: account_osAccount.DomainAccountInfo, credential: Uint8Array,
        callback: account_osAccount.IUserAuthCallback) => {},
  authWithPopup: (domainAccountInfo: account_osAccount.DomainAccountInfo,
                  callback: account_osAccount.IUserAuthCallback) => {},
  authWithToken: (domainAccountInfo: account_osAccount.DomainAccountInfo, token: Uint8Array,
                  callback: account_osAccount.IUserAuthCallback) => {},
  getAccountInfo: (options: account_osAccount.GetDomainAccountInfoPluginOptions, // Change the input parameters.
                  callback: AsyncCallback<account_osAccount.DomainAccountInfo>) => {
    // mock getting account information
    // notify result
    let code: BusinessError = {
      code: 0,
      name: "",
      message: ""
    };
    let accountInfo: account_osAccount.DomainAccountInfo = {
      domain: options.domain, // Obtain the input parameter.
      accountName: options.accountName, // Obtain the input parameter.
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
