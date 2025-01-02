# @ohos.enterprise.accountManager (Account Management)

The **accountManager** module provides APIs for account management of enterprise devices.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { accountManager } from '@kit.MDMKit';
```

## accountManager.disallowOsAccountAddition

disallowOsAccountAddition(admin: Want, disallow: boolean, accountId?: number): void

Disallows a user to add system accounts through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                       |
| --------- | ------------------------------------------------------- | ---- | ----------------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                             |
| disallow  | boolean                                                 | Yes  | Whether to forbid the addition of local user accounts. The value **true** means the addition of local user accounts is forbidden, and the value **false** means the opposite. |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.                |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  accountManager.disallowOsAccountAddition(wantTemp, true, 100);
  console.info('Succeeded in disallowing os account addition.');
} catch (err) {
  console.error(`Failed to disallow os account addition. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.isOsAccountAdditionDisallowed

isOsAccountAdditionDisallowed(admin: Want, accountId?: number): boolean

Checks whether a user is not allowed to add system accounts through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                       |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                             |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the user is not allowed to add system accounts;<br>returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let isDisallowed: boolean = accountManager.isOsAccountAdditionDisallowed(wantTemp, 100);
  console.info(`Succeeded in querying the os account addition or not: ${isDisallowed}`);
} catch (err) {
  console.error(`Failed to query the os account addition or not. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.addOsAccountAsync

addOsAccountAsync(admin: Want, name: string, type: osAccount.OsAccountType): Promise&lt;osAccount.OsAccountInfo&gt;

Adds a system account in the background through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | Device administrator application.                                              |
| name   | string                                                       | Yes  | User ID, which must be greater than or equal to 0.                 |
| type   | [osAccount.OsAccountType](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype) | Yes  | Type of the account to add.<br>The value can be any of the following:<br>· **ADMIN**: administrator account.<br>· **NORMAL**: normal account.<br>· **GUEST**: guest account.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| [osAccount.OsAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype) | Information about the account added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201003  | Failed to add an OS account.                                 |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

accountManager.addOsAccountAsync(wantTemp, "TestAccountName", osAccount.OsAccountType.NORMAL).then((info) => {
  console.info(`Succeeded in creating os account: ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to creating os account. Code: ${err.code}, message: ${err.message}`);
});
```
