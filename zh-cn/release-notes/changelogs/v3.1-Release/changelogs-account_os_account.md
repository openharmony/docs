# 帐号子系统changeLog

## cl.account_os_account.1 系统帐号OsAccountInfo.type取值类型变更

变更前，OsAccountInfo.type取值的实际类型为Object，与d.ts中声明的OsAccountType枚举类型不一致；变更后，OsAccountInfo.type取值的实际类型为OsAccountType枚举。

**变更影响**

基于此前版本开发的应用，需变更OsAccountInfo.type值的读取方式，否则影响原因业务逻辑。

**关键接口/组件变更**

涉及的接口：
- AccountManager
  - queryAllCreatedOsAccounts(callback: AsyncCallback&lt;Array&lt;OsAccountInfo&gt;&gt;): void;
  - queryAllCreatedOsAccounts(): Promise&lt;Array&lt;OsAccountInfo&gt;&gt;;
  - createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
  - createOsAccount(localName: string, type: OsAccountType): Promise&lt;OsAccountInfo&gt;;
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;;
  - queryCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
  - queryCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;;
  - getCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
  - getCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;;
  - queryOsAccountById(localId: number, callback: AsyncCallback&lt;OsAccountInfo&gt;): void;
  - queryOsAccountById(localId: number): Promise&lt;OsAccountInfo&gt;;

  - getOsAccountTypeFromProcess(callback: AsyncCallback&lt;OsAccountType&gt;): void;
  - getOsAccountTypeFromProcess(): Promise&lt;OsAccountType&gt;;
  - getOsAccountType(callback: AsyncCallback&lt;OsAccountType&gt;): void;
  - getOsAccountType(): Promise&lt;OsAccountType&gt;;

**适配指导**
```ts
import account_osAccount from "@ohos.account.osAccount"

let accountMgr = account_osAccount.getAccountManager();
accountMgr.createOsAccount("account_test", account_osAccount.OsAccountType.GUEST).then((accountInfo) => {
  if (accountInfo.type == account_osAccount.OsAccountType.GUEST) {
    console.log("createOsAccount successfully");
  }
  accountMgr.activateOsAccount(accountInfo.localId).then(() => {
    console.log("activateOsAccount successfully");
    accountMgr.getOsAccountTypeFromProcess().then((accountType) => {
      if (accountType == account_osAccount.OsAccountType.GUEST) {
        console.log("getOsAccountTypeFromProcess successfully");
      }
    }).catch((err) => {
      console.log("activateOsAccount err: " + JSON.stringify(err));
    });
  }).catch((err) => {
    console.log("activateOsAccount err: " + JSON.stringify(err));
  });
}).catch((err) => {
  console.log("createOsAccount err: " + JSON.stringify(err));
});
```
