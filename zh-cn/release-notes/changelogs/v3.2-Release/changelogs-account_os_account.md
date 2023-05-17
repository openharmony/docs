# 帐号子系统changeLog

## cl.account_os_account.1 应用帐号取消帐号名中空格字符限制

变更前，应用帐号接口传入包含空格字符的帐号名时，返回无效参数错误；变更后，不报错。

**变更影响**

基于此前版本开发的应用不受变更影响；
基于此后版本开发的应用，调用API 9以及之后版本的应用帐号相关接口，帐号名不再做空格字符限制。

**关键接口/组件变更**

涉及的接口：
- AppAccountManager
  - createAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;
  - auth(name: string, owner: string, authType: string, callback: AuthCallback): void;
  - setAppAccess(name: string, bundleName: string, isAccessible: boolean, callback: AsyncCallback&lt;void&gt;): void;
  - setCredential(name: string, credentialType: string, credential: string, callback: AsyncCallback&lt;void&gt;): void;
  - setCustomData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void;
  - setAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void;
  - setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void;
