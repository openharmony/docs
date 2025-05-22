# 管理分布式账号（仅对系统应用开放）

OEM厂商可以通过[分布式账号SDK](../../reference/apis-basic-services-kit/js-apis-distributed-account.md)将自有账号与本地系统账号建立关联关系。

## 开发准备

1. 申请权限：ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS。申请流程请参考：[申请应用权限](../../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)。

2. 导入分布式账号模块。

   ```ts
   import { distributedAccount, BusinessError } from '@kit.BasicServicesKit';
   ```

3. 获取分布式账号的单实例对象。

   ```ts
   const distributedAccountAbility = distributedAccount.getDistributedAccountAbility();
   ```

## 在当前系统账号上登录绑定分布式账号

具体开发实例如下：

1. 定义待登录的分布式账号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGIN"。

   ```ts
   let distributedInfo: distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGIN',
   };
   ```

2. 调用[setOsAccountDistributedInfo](../../reference/apis-basic-services-kit/js-apis-distributed-account.md#setosaccountdistributedinfo9)接口，将当前系统账号与指定分布式账号绑定到一起。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfo(distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfo successfully');
   }).catch((err: BusinessError) => {
       console.error('setOsAccountDistributedInfo exception: '  + JSON.stringify(err));
   });
   ```

3. 在账号绑定之后，可以调用[getOsAccountDistributedInfo](../../reference/apis-basic-services-kit/js-apis-distributed-account.md#getosaccountdistributedinfo9)接口查看分布式账号的登录信息。

   ```ts
   distributedAccountAbility.getOsAccountDistributedInfo().then((data: distributedAccount.DistributedInfo) => {
       console.log('distributed information: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.error('getOsAccountDistributedInfo exception: '  + JSON.stringify(err));
   });
   ```

## 在当前系统账号上登出解绑分布式账号

具体开发实例如下：

1. 定义待登出的分布式账号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGOUT"。

   ```ts
   let distributedInfo: distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGOUT',
   };
   ```

2. 调用[setOsAccountDistributedInfo](../../reference/apis-basic-services-kit/js-apis-distributed-account.md#setosaccountdistributedinfo9)接口，将指定的分布式账号与当前系统账号解绑。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfo(distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfo successfully');
   }).catch((err: BusinessError) => {
       console.error('setOsAccountDistributedInfo exception: '  + JSON.stringify(err));
   });
   ```

## 在指定的系统账号上登录绑定分布式账号

具体开发实例如下：

1. 确定目标系统账号，并定义待登录的分布式账号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGIN"。

   ```ts
   let localId: number = 100;
   let distributedInfo: distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGIN',
   };
   ```

2. 调用[setOsAccountDistributedInfoByLocalId](../../reference/apis-basic-services-kit/js-apis-distributed-account-sys.md#setosaccountdistributedinfobylocalid10)接口，将指定分布式账号与当前系统账号绑定。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfoByLocalId(localId, distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfoByLocalId successfully');
   }).catch((err: BusinessError) => {
       console.error('setOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
   });
   ```

3. 在账号绑定之后，可以调用[getOsAccountDistributedInfoByLocalId](../../reference/apis-basic-services-kit/js-apis-distributed-account-sys.md#getosaccountdistributedinfobylocalid10)接口查看分布式账号的登录信息。

   ```ts
   distributedAccountAbility.getOsAccountDistributedInfoByLocalId(localId).then((data: distributedAccount.DistributedInfo) => {
       console.log('distributed information: ' + JSON.stringify(data));
   }).catch((err: BusinessError) => {
       console.error('getOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
   });
   ```

## 在指定系统账号上登出解绑分布式账号

具体开发实例如下：

1. 确定目标系统账号，并定义待登出的分布式账号信息。其中，登录场景下需将event指定为"Ohos.account.event.LOGOUT"。

   ```ts
   let localId: number = 100;
   let distributedInfo: distributedAccount.DistributedInfo = {
       name: 'ZhangSan',
       id: '12345',
       event: 'Ohos.account.event.LOGOUT',
   };
   ```

2. 调用[setOsAccountDistributedInfoByLocalId](../../reference/apis-basic-services-kit/js-apis-distributed-account-sys.md#setosaccountdistributedinfobylocalid10)接口，将指定的分布式账号与目标系统账号解绑。

   ```ts
   distributedAccountAbility.setOsAccountDistributedInfoByLocalId(localId, distributedInfo).then(() => {
       console.log('setOsAccountDistributedInfoByLocalId successfully');
   }).catch((err: BusinessError) => {
       console.error('setOsAccountDistributedInfoByLocalId exception: '  + JSON.stringify(err));
   });
   ```
