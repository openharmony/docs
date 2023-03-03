# Account Subsystem Changelog

## cl.account_os_account.1 createOsAccountForDomain Error Code Change

Changed the error code returned when the domain account created by **createOsAccountForDomain()** already exists from **12300001** to **12300004**.
Changed the error information from "common system error" to "The account already exists".

**Change Impact**

The application developed based on earlier versions needs to adapt the new error code. Otherwise, the original service logic will be affected.

**Key API/Component Changes**
- AccountManager
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;);
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;;

**Adaptation Guide**

The sample code is as follows:

```ts
import account_osAccount from "@ohos.account.osAccount"

let accountMgr = account_osAccount.getAccountManager();
let domainInfo = {
  accountName: "zhangsan",
  domain: "china.example.com"
};
try {
  await accountMgr.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo);
  await accountMgr.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo);
} catch (err) {
  console.log("activateOsAccount err: " + JSON.stringify(err)); // error.code = 12300004;
}
```

## cl.account_os_account.2 Application Account getAllAccounts() Permission Change 

Removed the **ohos.permission.GET_ALL_APP_ACCOUNTS** permission that is originally required for an application to call **getAllAccounts()** to obtain accessible accounts.

**Change Impact**

From this version, applications do not need the **ohos.permission.GET_ALL_APP_ACCOUNTS** permission when calling **getAllAccounts()**.

**Key API/Component Changes**
- AccountManager
  - getAllAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;
  - getAllAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

**Adaptation Guide**

The following is the sample code for an application to obtain the accessible accounts without the **ohos.permission.GET_ALL_APP_ACCOUNTS** permission:

```ts
import account_appAccount from "@ohos.account.appAccount"

let accountMgr = account_appAccount.createAppAccountManager();
try {
  await accountMgr.addAccount("accessibleAccount_promise_nopermission");
  var data = await accountMgr.getAllAccounts();
  if (data[0].name == "accessibleAccount_promise_nopermission") {
    console.log("getAllAccounts successfully");
  }
} catch (err) {
  console.log("getAllAccounts err: " + JSON.stringify(err));
}
``` 

## cl.account_os_account.3 Application Account getAccountsByOwner() Permission Change

Removed the **ohos.permission.GET_ALL_APP_ACCOUNTS** permission that is originally required for an application to call **getAccountsByOwner()** to obtain the accessible accounts based on the account owner .

**Change Impact**

From this version, applications do not need the **ohos.permission.GET_ALL_APP_ACCOUNTS** permission when calling **getAccountsByOwner()**.

**Key API/Component Changes**
- AccountManager
  - getAccountsByOwner(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;
  - getAccountsByOwner(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

**Adaptation Guide**

The following is the sample code for an application to obtain the accessible accounts based on the account owner without the **ohos.permission.GET_ALL_APP_ACCOUNTS** permission:

```ts
import account_appAccount from "@ohos.account.appAccount"

let accountMgr = account_appAccount.createAppAccountManager();
try {
  var ownerName = "com.example.owner";
  var data = await accountMgr.getAllAccounts(ownerName);
} catch (err) {
  console.log("getAllAccounts err: " + JSON.stringify(err));
}
``` 
