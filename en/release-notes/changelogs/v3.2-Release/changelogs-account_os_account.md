# Account Subsystem Changelog

## cl.account_os_account.1 Allowing Spaces in App Account Names

Before the change, when an account name containing a space is passed in, an error will be returned. Now, the account names can contain spaces.

**Change Impact**

Applications developed based on earlier versions are not affected.
From this version, the account names in app account APIs are no longer checked for spaces.

**Key API/Component Changes**

The following APIs are involved:
- AppAccountManager
  - createAccount(name: string, callback: AsyncCallback&lt;void&gt;): void;
  - auth(name: string, owner: string, authType: string, callback: AuthCallback): void;
  - setAppAccess(name: string, bundleName: string, isAccessible: boolean, callback: AsyncCallback&lt;void&gt;): void;
  - setCredential(name: string, credentialType: string, credential: string, callback: AsyncCallback&lt;void&gt;): void;
  - setCustomData(name: string, key: string, value: string, callback: AsyncCallback&lt;void&gt;): void;
  - setAuthToken(name: string, authType: string, token: string, callback: AsyncCallback&lt;void&gt;): void;
  - setAuthTokenVisibility(name: string, authType: string, bundleName: string, isVisible: boolean, callback: AsyncCallback&lt;void&gt;): void;
