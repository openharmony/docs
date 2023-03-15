# 帐号子系统changeLog

## cl.account_os_account.1 createOsAccountForDomain错误码变更

使用createOsAccountForDomain重复创建域帐号时，变更前返回的错误码为12300001，变更后返回的错误码为12300004。
错误信息由通用系统报错细化为帐号已存在报错。

**变更影响**

基于此前版本开发的应用，需适配变更后的错误码，否则会影响原有业务逻辑。

**关键接口/组件变更**
- AccountManager
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;);
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;;

**适配指导**

重复创建域帐号的示例代码如下：

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

## cl.account_os_account.2 应用帐号getAllAccounts接口权限场景变更

应用使用getAllAccounts接口查询自己可访问的帐号列表时，不需要申请权限ohos.permission.GET_ALL_APP_ACCOUNTS。

**变更影响**

基于此后版本开发的应用，查询自己可访问的帐号列表时，无需申请权限。

**关键接口/组件变更**
- AccountManager
  - getAllAccounts(callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;
  - getAllAccounts(): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

**适配指导**

应用未申请ohos.permission.GET_ALL_APP_ACCOUNTS，查询自己可访问的帐号列表示例代码如下：

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

## cl.account_os_account.3 应用帐号getAccountsByOwner接口权限场景变更

应用使用getAccountsByOwner接口查询可访问的指定应用的帐号列表时，不需要申请权限ohos.permission.GET_ALL_APP_ACCOUNTS。

**变更影响**

基于此后版本开发的应用，查询指定应用可访问的帐号列表时，无需申请权限。

**关键接口/组件变更**
- AccountManager
  - getAccountsByOwner(owner: string, callback: AsyncCallback&lt;Array&lt;AppAccountInfo&gt;&gt;): void;
  - getAccountsByOwner(owner: string): Promise&lt;Array&lt;AppAccountInfo&gt;&gt;;

**适配指导**

应用未申请ohos.permission.GET_ALL_APP_ACCOUNTS，查询指定应用可访问的帐号列表示例代码如下：

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