# 管理系统帐号（仅对系统应用开放）

系统提供了用于管理系统帐号的接口。
系统应用开发者在申请对应的权限后，可以创建、激活、修改和删除系统帐号，实现对系统帐号的生命周期管理；三方应用开发者可以查询系统帐号的基本信息，以完成与系统帐号相关的业务逻辑开发。

## 基本概念

### 帐号类型

当前，系统仅允许创建以下三种预定义类型的系统帐号：
| 名称   | 值 | 说明         |
| ------ | ------ | ----------- |
| ADMIN  | 0      | 管理员帐号。 |
| NORMAL | 1      | 普通帐号。   |
| GUEST  | 2      | 访客帐号。   |

### 帐号完整信息

系统帐号的完整信息请参考[OsAccountInfo](../reference/apis/js-apis-osAccount.md#osaccountinfo)定义。

## 开发准备

1. 申请权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS。申请流程请参考：[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级的应用申请权限)。

2. 导入系统帐号模块。

   ```ts
   import account_osAccount from '@ohos.account.osAccount';
   ```

3. 获取帐号管理单实例对象。

   ```ts
   let accountManager = account_osAccount.getAccountManager();
   ```

## 创建系统帐号

系统初始化阶段，会创建默认系统帐号。此外，可以创建多个系统帐号，以满足用户不同诉求。

具体开发实例如下：

调用[createOsAccount](../reference/apis/js-apis-osAccount.md#createosaccount)接口，指定昵称和类型信息来创建系统帐号。

```ts
let name: string = 'Bob';
let type: account_osAccount.OsAccountType = account_osAccount.OsAccount.NORMAL;

accountManager.createOsAccount(name, type, (err: BusinessError, osAccountInfo: account_osAccount.OsAccountInfo)=>{
  console.log('createOsAccount err:' + JSON.stringify(err));
  console.log('createOsAccount osAccountInfo:' + JSON.stringify(osAccountInfo));
});
```

## 查询所有已创建的系统帐号

帐号管理界面通常需要获取所有帐号信息时，以方便用户操作不同帐号。

具体开发实例如下：

调用[queryAllCreatedOsAccounts](../reference/apis/js-apis-osAccount.md#queryallcreatedosaccounts)接口查询全量帐号。  

```ts
accountManager.queryAllCreatedOsAccounts((err: BusinessError, accountArr: account_osAccount.OsAccountInfo[])=>{
  console.log('queryAllCreatedOsAccounts err:' + JSON.stringify(err));
  console.log('queryAllCreatedOsAccounts accountArr:' + JSON.stringify(accountArr));
});
```

## 查询指定系统帐号信息

除了查询所有帐号信息，还可以根据帐号标识查询指定系统帐号的详细信息。

具体开发实例如下：

调用[queryOsAccountById](../reference/apis/js-apis-osAccount.md#queryosaccountbyid)接口查询指定帐号的详细信息。

```ts
let localId: number = 100;
accountManager.queryOsAccountById(localId, (err: BusinessError, accountInfo: account_osAccount.OsAccountInfo)=>{
  console.log('queryOsAccountById err:' + JSON.stringify(err));
  console.log('queryOsAccountById accountInfo:' + JSON.stringify(accountInfo));
});
```

## 修改系统帐号头像和昵称

可以修改系统帐号的头像、昵称，以满足用户的个性化需求。

具体开发实例如下：

1. 调用[setOsAccountProfilePhoto](../reference/apis/js-apis-osAccount.md#setosaccountprofilephoto)接口修改系统帐号头像。

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

2. 调用[setOsAccountName](../reference/apis/js-apis-osAccount.md#setosaccountname)接口修改系统帐号名称。

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

## 激活系统帐号

系统帐号默认处于未激活状态，需要激活后才能使用。开发者可以使用[activateOsAccount](../reference/apis/js-apis-osAccount.md#activateosaccount)接口完成此操作。

具体开发实例如下：

调用[activateOsAccount](../reference/apis/js-apis-osAccount.md#activateosaccount)接口激活指定系统帐号。

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

## 删除系统帐号

不再使用某个系统帐号时，可以将该系统帐号删除。

具体开发实例如下：

调用[removeOsAccount](../reference/apis/js-apis-osAccount.md#removeosaccount)接口删除指定的帐号。

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
