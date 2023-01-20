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
