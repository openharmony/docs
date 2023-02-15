# Account Subsystem ChangeLog

## cl.account_os_account.1 OsAccountInfo.type Value Type Change

Changed the value type of **OsAccountInfo.type** from **Object** to **OsAccountType** enumeration.

**Change Impacts**

The mode for reading the **OsAccountInfo.type** value needs to be changed for the application developed based on earlier versions. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

The following APIs are involved:
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

**Adaptation Guide**
```ts
import account_osAccount from "@ohos.account.osAccount"
import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect } from '@ohos/hypium'

let accountMgr = account_osAccount.getAccountManager();
accountMgr.createOsAccount('account_test', account_osAccount.OsAccountType.GUEST).then((accountInfo) => {
  expect(accountInfo.type).assertEqual(account_osAccount.OsAccountType.GUEST);
  accountMgr.activateOsAccount(accountInfo.localId).then(() => {
    console.log('activateOsAccount successfully');
    accountMgr.getOsAccountTypeFromProcess().then((accountType) => {
      expect(accountType).assertEqual(account_osAccount.OsAccountType.GUEST);
    }).catch((err) => {
      console.log('activateOsAccount err: ' + JSON.stringify(err));
      expect().assertFail();
    });
  }).catch((err) => {
    console.log('activateOsAccount err: ' + JSON.stringify(err));
    expect().assertFail();
  });
}).catch((err) => {
  console.log('createOsAccount err: ' + JSON.stringify(err));
  expect().assertFail();
});
```
