# Account Subsystem ChangeLog

## cl.account_os_account.1 createOsAccountForDomain Error Code Change

Changed the error code returned when the **createOsAccountForDomain** API is used to create a domain account that already exists from **12300001** to **12300004**.
The error information is changed from a common system error to an error indicating that the account already exists.

**Change Impacts**

The application developed based on earlier versions needs to adapt the new error code. Otherwise, the original service logic will be affected.

**Key API/Component Changes**
- AccountManager
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;);
  - createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;;

**Adaptation Guide**

The sample code for returning an error when a domain account is repeatedly created is as follows:

```ts
import account_osAccount from "@ohos.account.osAccount"
import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect } from '@ohos/hypium'

let accountMgr = account_osAccount.getAccountManager();
let domainInfo = {
  accountName: "zhangsan",
  domain: "china.example.com"
};
try {
  await accountMgr.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo);
  await accountMgr.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo);
} catch (err) {
  expect(err.code).assertEqual(12300004);
}
```
