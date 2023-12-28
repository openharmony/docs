# 使用约束管控系统帐号

帐号管理模块提供了基于角色的访问控制机制，用户可以为系统帐号设置约束，以限制目标帐号的行为。

## 约束列表

预定义的帐号约束条件，可以参考 ：[系统帐号约束列表](../reference/apis/js-apis-osAccount.md#系统帐号约束列表)

## 开发准备

1. 申请权限：ohos.permission.MANAGE_LOCAL_ACCOUNTS。申请流程请参考：[申请应用权限](../security/AccessToken/determine-application-mode.md#system_basic等级的应用申请权限)。

2. 导入系统帐号模块。

   ```ts
   import account_osAccount from '@ohos.account.osAccount';
   ```

3. 获取系统帐号的单实例对象。

   ```ts
   let accountManager = account_osAccount.getAccountManager();
   ```

## 设置指定系统帐号的约束列表

设备所有者可以给指定系统帐号设置约束，以限制该帐号的行为。例如在家长模式下，家长可能禁止儿童打开WIFI、安装应用等。

具体开发实例如下：

1. 指定系统帐号标识和待使能的约束集合。

   ```ts
   let localId: number = 101;
   let constraint: string[] = [ 'constraint.wifi.set' ];
   ```

2. 调用setOsAccountConstraints接口，使能系统帐号100的约束。

   ```ts
   try {
     let accountManager.setOsAccountConstraints(localId, [constraint], true);
     console.log('setOsAccountConstraints successfully');
   } catch (err) {
     console.log('setOsAccountConstraints failed, error: ' + JSON.stringify(err));
   }
   ```

## 判断目标系统帐号的指定约束是否使能

业务应用需要判断目标系统帐号的指定约束是否使能，以此来决策是否对目标系统帐号的行为做管控。
开发者可以使用[checkOsAccountConstraintEnabled](../reference/apis/js-apis-osAccount.md#checkosaccountconstraintenabled9)接口完成此操作。

具体开发实例如下：

1. 指定系统帐号标识和约束名称。

   ```ts
   let localId: number = 100;
   let constraint: string = 'constraint.wifi';
   ```

2. 调用[checkOsAccountConstraintEnabled](../reference/apis/js-apis-osAccount.md#checkosaccountconstraintenabled9)接口，判断指定约束是否使能。

   ```ts
   let isEnabled: boolean = accountManager.checkOsAccountConstraintEnabled(localId, constraint);
   if (isEnabled) {
     // your business logic
   }
   ```
