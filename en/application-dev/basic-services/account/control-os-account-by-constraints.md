# Applying Constraints for System Accounts

The **account** module provides a role-based access control mechanism. You can set constraints for system accounts to restrict their behaviors.

## Constraints

For details about the predefined account constraints, see [Constraints](../../reference/apis-basic-services-kit/js-apis-osAccount.md#constraints).

## Before You Start

1. Request the ohos.permission.MANAGE_LOCAL_ACCOUNTS permission. For details, see [Requesting Permissions for system_basic Applications](../../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).

2. Import the **osAccount** module.

   ```ts
   import { osAccount } from '@kit.BasicServicesKit';
   ```

3. Obtain an **AccountManager** instance.

   ```ts
   let accountManager = osAccount.getAccountManager();
   ```

## Setting Constraints for a System Account

The user can set constraints to restrict the system account behaviors. For example, the user can enable mobile guardian for children to prevent the kids to use Wi-Fi or install applications.

**Procedure**

1. Specify the system account ID and the constraints.

   ```ts
   let localId: number = 100;
   let constraint: string[] = [ 'constraint.wifi.set' ];
   ```

2. Use [setOsAccountConstraints](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#setosaccountconstraints) to enable the constraints for the system account.

   ```ts
   try {
     accountManager.setOsAccountConstraints(localId, constraint, true);
     console.log('setOsAccountConstraints successfully');
   } catch (err) {
     console.log('setOsAccountConstraints failed, error: ' + JSON.stringify(err));
   }
   ```

## Checking Whether a Constraint Can be Enabled for a System Account

Before a constraint is enabled for a system account, the application needs to check whether the constraint can be enabled. You can use [isOsAccountConstraintEnabled](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#isosaccountconstraintenabled11) to implement this operation.

**Procedure**

1. Set the system account ID and constraint.

   ```ts
   let localId: number = 100;
   let constraint: string = 'constraint.wifi.set';
   ```

2. Use [isOsAccountConstraintEnabled](../../reference/apis-basic-services-kit/js-apis-osAccount-sys.md#isosaccountconstraintenabled11) to check whether the constraint can be enabled for the system account.

   ```ts
   let isEnabled: boolean = await accountManager.isOsAccountConstraintEnabled(localId, constraint);
   if (isEnabled) {
     // Your business logic
   }
   ```
