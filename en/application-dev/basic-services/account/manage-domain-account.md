# Managing Domain Accounts (for System Applications Only)

The user can add a domain account to a device so that the domain account user can log in to the system and use the device.

## Before You Start

1. Request the following permissions. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).
   - ohos.permission.MANAGE_LOCAL_ACCOUNTS
   - ohos.permission.GET_DOMAIN_ACCOUNTS

2. Import the **osAccount** module.

   ```ts
   import { osAccount, BusinessError } from '@kit.BasicServicesKit';
   ```

3. Obtain an **AccountManager** instance for system accounts.

   ```ts
   let osAccountMgr = osAccount.getAccountManager();
   ```

## Checking for a Domain Account

Before adding a domain account, the user may need to check whether the domain account exists. You can use [hasAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#hasaccount10) to check whether a domain account exists.

**Procedure**

1. Define the domain account to check.

   ```ts
   let domainAccountInfo: osAccount.DomainAccountInfo = {
     accountName: 'testAccountName',
     domain: 'testDomain'
   }
   ```

2. Use [hasAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#hasaccount10) to check whether the domain account exists.

   ```ts
   osAccount.DomainAccountManager.hasAccount(domainAccountInfo).then((isAccountExisted: boolean)=>{
     console.log('execute hasAccount successfully, isAccountExisted:' + JSON.stringify(isAccountExisted));
   }).catch((err: BusinessError)=>{
     console.error('execute hasAccount err:' + JSON.stringify(err));
   });
   ```

## Adding a Domain Account

The user can add a domain account in **Settings** to allow the domain account user to log in to and use the device. You can use [createOsAccountForDomain](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#createosaccountfordomain8) to implement this operation.

**Procedure**

1. Define domain account information, including the domain name, account name, and account ID (optional).

   ```ts
   let domainInfo: osAccount.DomainAccountInfo = {
     domain: 'testDomain',
     accountName: 'testAccountName'
   };
   ```

2. Use [createOsAccountForDomain](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#createosaccountfordomain8) to create a domain account on the device.

   ```ts
   try {
     osAccountMgr.createOsAccountForDomain(osAccount.OsAccountType.NORMAL, domainInfo,
     (err: BusinessError, osAccountInfo: osAccount.OsAccountInfo)=>{
       if (err) {
        console.error('createOsAccountForDomain exception:' + JSON.stringify(err));
      } else {
        console.log('createOsAccountForDomain osAccountInfo:' + JSON.stringify(osAccountInfo));
      }
   });
   } catch (e) {
   console.error('createOsAccountForDomain exception: ' + JSON.stringify(e));
   }
   ```

## Removing a Domain Account

The user can remove the domain account that is not required. Since a domain account is in one-to-one relationship with a system account, you can use [removeOsAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#removeosaccount) to delete the system account. The domain account is deleted as well.

**Procedure**

1. Use [getOsAccountLocalIdForDomain](../../reference/apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalidfordomain9) to obtain the system account ID based on the domain account information.

   ```ts
   let domainInfo: osAccount.DomainAccountInfo = {
       domain: 'testDomain',
       accountName: 'testAccountName'
   };
   let localId: number = 0;

   try {
     localId = await osAccountMgr.getOsAccountLocalIdForDomain(domainInfo);
   } catch (err) {
     console.error('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));
   }
   ```

2. Use [removeOsAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#removeosaccount) to remove the system account.

   ```ts
   try {
     osAccountMgr.removeOsAccount(localId, (err: BusinessError)=>{
       if (err) {
           console.error('removeOsAccount failed, error: ' + JSON.stringify(err));
       } else {
           console.log('removeOsAccount successfully');
       }
     });
   } catch (err) {
     console.error('removeOsAccount exception: ' + JSON.stringify(err));
   }
   ```

## Obtaining Domain Account Information

After passing the authentication, the user can query their own or others' domain account information. You can use [getAccountInfo](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#getaccountinfo10) to implement this operation.

**Procedure**

1. Specify the query options, including the domain name and account name. The option type is [GetDomainAccountInfoOptions](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#getdomainaccountinfooptions10).

   ```ts
   let options: osAccount.GetDomainAccountInfoOptions = {
       domain: 'testDomain',
       accountName: 'testAccountName'
   }
   ```

2. Use [getAccountInfo](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#getaccountinfo10) to obtain domain account information.

   ```ts
   try {
     osAccount.DomainAccountManager.getAccountInfo(options,
       (err: BusinessError, result: osAccount.DomainAccountInfo) => {
       if (err) {
           console.error('call getAccountInfo failed, error: ' + JSON.stringify(err));
       } else {
           console.log('getAccountInfo result: ' + result);
       }
     });
   } catch (err) {
       console.error('getAccountInfo exception = ' + JSON.stringify(err));
   }
   ```
