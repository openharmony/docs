# 管理分布式帐号（仅对系统应用开放）

OEM厂商可以通过[分布式帐号SDK](../reference/apis/js-apis-distributed-account.md#)将自有帐号与本地系统帐号建立关联关系。

## 开发准备

1. 申请权限：ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS。申请流程请参考：[访问控制授权申请指导](../security/accesstoken-guidelines.md)。

2. 导入分布式帐号模块。

   ```ts
   import account_distributedAccount from '@ohos.account.distributedAccount';
   ```

3. 获取分布式帐号的单实例对象。

   ```ts
   const distributedAccountAbility = account_distributedAccount.getDistributedAccountAbility();
   ```

## 在当前系统帐号上登录绑定分布式帐号

具体开发实例如下：

1. 定义待登录的分布式帐号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGIN"。

   ```ts
   let distributedInfo: account_distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGIN',
   };
   ```

2. 调用[setOsAccountDistributedInfo](../reference/apis/js-apis-distributed-account.md#setosaccountdistributedinfo9)接口，将当前系统帐号与指定分布式帐号绑定到一起。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfo(distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfo successfully');
   }).catch((err: BusinessError) => {
       console.log('setOsAccountDistributedInfo exception: '  + JSON.stringify(err));
   });
   ```

3. 在帐号绑定之后，可以调用[getOsAccountDistributedInfo](../reference/apis/js-apis-distributed-account.md#getosaccountdistributedinfo9)接口查看分布式帐号的登录信息。

   ```ts
   distributedAccountAbility.getOsAccountDistributedInfo().then((data: account_distributedAccount.DistributedInfo) => {
       console.log('distributed information: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.log('getOsAccountDistributedInfo exception: '  + JSON.stringify(err));
   });
   ```

## 在指定的系统帐号上登录绑定分布式帐号

具体开发实例如下：

1. 确定目标系统帐号，并定义待登录的分布式帐号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGIN"。

   ```ts
   let localId: number = 100;
   let distributedInfo: account_distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGIN',
   };
   ```

2. 调用setOsAccountDistributedInfoByLocalId接口，将指定分布式帐号与当前系统帐号绑定。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfoByLocalId(localId, distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfoByLocalId successfully');
   }).catch((err: BusinessError) => {
       console.log('setOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
   });
   ```

3. 在帐号绑定之后，可以调用[getOsAccountDistributedInfo](../reference/apis/js-apis-distributed-account.md#setosaccountdistributedinfobylocalid10)接口查看分布式帐号的登录信息。

   ```ts
   distributedAccountAbility.getOsAccountDistributedInfoByLocalId(localId).then((data: account_distributedAccount.DistributedInfo) => {
       console.log('distributed information: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.log('getOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
   });
   ```

## 在当前系统帐号上登出解绑分布式帐号

具体开发实例如下：

1. 定义待登出的分布式帐号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGOUT"。

   ```ts
   let distributedInfo: account_distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGOUT',
   };
   ```

2. 调用[setOsAccountDistributedInfo](../reference/apis/js-apis-distributed-account.md#setosaccountdistributedinfo9)接口，将指定的分布式帐号与当前系统帐号解绑。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfo(distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfo successfully');
   }).catch((err: BusinessError) => {
       console.log('setOsAccountDistributedInfo exception: '  + JSON.stringify(err));
   });
   ```

## 在指定系统帐号上登出解绑分布式帐号

具体开发实例如下：

1. 确定目标系统帐号，并定义待登出的分布式帐号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGOUT"。

   ```ts
   let localId: number = 100;
   let distributedInfo: account_distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGOUT',
   };
   ```

2. 调用[setOsAccountDistributedInfoByLocalId](../reference/apis/js-apis-distributed-account.md#setosaccountdistributedinfobylocalid10)接口，将指定的分布式帐号与目标系统帐号解绑。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfoByLocalId(localId, distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfoByLocalId successfully');
   }).catch((err: BusinessError) => {
       console.log('setOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
   });
   ```
