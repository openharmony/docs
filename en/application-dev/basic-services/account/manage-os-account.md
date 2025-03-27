# Managing System Accounts (for System Applications Only)

The system provides APIs for managing system accounts. After applying for required permissions for your system application, you can use the APIs to create, activate, modify, and delete system accounts. For third-party applications, you can use the APIs to query basic information about system accounts to develop service logic related to system accounts.

## Basic Concepts

### Account Type

Currently, only the following types of system accounts can be created:
| Name  | Value| Description        |
| ------ | ------ | ----------- |
| ADMIN  | 0      | Administrator account.|
| NORMAL | 1      | Normal account.  |
| GUEST  | 2      | Guest account.  |
| PRIVATE<sup>12+</sup> | 1024  | Private account. |

### Account Information

For details about complete system account information, see [OsAccountInfo](../../reference/apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo).

## Before You Start

1. Request the ohos.permission.MANAGE_LOCAL_ACCOUNTS permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

2. Import the **osAccount** module.

   ```ts
   import { osAccount, BusinessError } from '@kit.BasicServicesKit';
   ```

3. Obtain an **AccountManager** instance.

   ```ts
   let accountManager = osAccount.getAccountManager();
   ```

## Creating a System Account

The default system account is created during the system initialization. The user cal also create multiple system accounts as required.

**Procedure**

Use [createOsAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#createosaccount) to create a system account with the specified name and type.

```ts
let name: string = 'Bob';
let type: osAccount.OsAccountType = osAccount.OsAccountType.NORMAL;

accountManager.createOsAccount(name, type, (err: BusinessError, osAccountInfo: osAccount.OsAccountInfo)=>{
  console.log('createOsAccount err:' + JSON.stringify(err));
  console.log('createOsAccount osAccountInfo:' + JSON.stringify(osAccountInfo));
});
```

## Obtaining All System Accounts

The account management page may need to display information about all the system accounts.

**Procedure**

Use [queryAllCreatedOsAccounts](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#queryallcreatedosaccounts) to obtain informatory about all system accounts. 

```ts
accountManager.queryAllCreatedOsAccounts((err: BusinessError, accountArr: osAccount.OsAccountInfo[])=>{
  console.log('queryAllCreatedOsAccounts err:' + JSON.stringify(err));
  console.log('queryAllCreatedOsAccounts accountArr:' + JSON.stringify(accountArr));
});
```

## Obtaining Information of a System Account

Detailed information about a system account can be obtained based on the account ID.

**Procedure**

Use [queryOsAccountById](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#queryosaccountbyid) to obtain detailed information about a system account.

```ts
let localId: number = 100;
accountManager.queryOsAccountById(localId, (err: BusinessError, accountInfo: osAccount.OsAccountInfo)=>{
  console.log('queryOsAccountById err:' + JSON.stringify(err));
  console.log('queryOsAccountById accountInfo:' + JSON.stringify(accountInfo));
});
```

## Changing the ProfilePhoto and Nickname of a System Account

Change the profile photo and nickname of a system account as required.

**Procedure**

1. Use [setOsAccountProfilePhoto](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#setosaccountprofilephoto) to change the profile picture of a system account.

   ```ts
   let localId: number = 100;
   let newPhoto: string = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+
   'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+
   'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+
   '+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='

   accountManager.setOsAccountProfilePhoto(localId, newPhoto, (err: BusinessError)=>{
     console.log('setOsAccountProfilePhoto err:' + JSON.stringify(err));
   });
   ```

2. Use [setOsAccountName](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#setosaccountname) to change the system account name.

   ```ts
   let localId: number = 100;
   let newName: string = 'Tom';
   accountManager.setOsAccountName(localId, newName, (err: BusinessError) => {
     if (err) {
       console.log('setOsAccountName failed, error: ' + JSON.stringify(err));
     } else {
       console.log('setOsAccountName successfully');
     }
   });
   ```

## Activating a System Account

System accounts are not activated by default. A system account can be used only after being activated. You can use [activateOsAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#activateosaccount) to activate a system account.

**Procedure**

Use [activateOsAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#activateosaccount) to activate a system account.

```ts
let localId: number = 101;
accountManager.activateOsAccount(localId, (err: BusinessError)=>{
  if (err) {
    console.error(`activateOsAccount failed, code is ${err.code}, message is ${err.message}`);
  } else {
    console.log('activateOsAccount successfully');
  }
});
```

## Removing a System Account

Remove the system account that is no longer used.

**Procedure**

Use [removeOsAccount](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#removeosaccount) to remove a system account.

```ts
let localId: number = 101;
accountManager.removeOsAccount(localId, (err: BusinessError)=>{
  if (err) {
      console.log('removeOsAccount failed, error: ' + JSON.stringify(err));
  } else {
      console.log('removeOsAccount successfully');
  }
});
```
