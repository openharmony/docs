# @ohos.enterprise.accountManager (Account Management)

The **accountManager** module provides APIs for account management of enterprise devices.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import accountManager from '@ohos.enterprise.accountManager';
```

## accountManager.disallowAddLocalAccount

disallowAddLocalAccount(admin: Want, disallow: boolean, callback: AsyncCallback&lt;void&gt;): void

Disallows a device administrator application to create local user accounts. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| disallow    | boolean     | Yes   | Whether to forbid the creation of local user accounts. The value **true** means to disallow the creation of local user accounts, and the value **false** means the opposite.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

accountManager.disallowAddLocalAccount(wantTemp, true, (err) => {
  if (err) {
    console.error(`Failed to disallow add local account. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in disallowing add local account');
});
```

## accountManager.disallowAddLocalAccount

disallowAddLocalAccount(admin: Want, disallow: boolean): Promise&lt;void&gt;

Disallows a device administrator application to create local user accounts. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| disallow    | boolean     | Yes   | Whether to forbid the creation of local user accounts. The value **true** means to disallow the creation of local user accounts, and the value **false** means the opposite.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

accountManager.disallowAddLocalAccount(wantTemp, true).then(() => {
  console.info('Succeeded in disallowing add local account');
}).catch((err: BusinessError) => {
  console.error(`Failed to disallow add local account. Code: ${err.code}, message: ${err.message}`);
});
```

## accountManager.disallowAddOsAccountByUser<sup>11+</sup>

disallowAddOsAccountByUser(admin: Want, userId: number, disallow: boolean): void

Disallows a user to add OS accounts through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                               | Mandatory| Description                                                       |
| -------- | ----------------------------------- | ---- | ----------------------------------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | Yes  | Device administrator application.                                             |
| userId   | number                              | Yes  | User ID, which must be greater than or equal to 0.                |
| disallow | boolean                             | Yes  | Whether to disallow the user to add OS accounts. The value **true** means to disallow the user to add OS accounts; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.      |
| 9200002  | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  accountManager.disallowAddOsAccountByUser(wantTemp, 100, true);
  console.info(`Succeeded in disallowing user add os account`);
} catch (err) {
  console.error(`Failed to disallow user add os account. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.isAddOsAccountByUserDisallowed<sup>11+</sup>

isAddOsAccountByUserDisallowed(admin: Want, userId: number): boolean

Checks whether a user is not allowed to add OS accounts through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name| Type                               | Mandatory| Description                                       |
| ------ | ----------------------------------- | ---- | ------------------------------------------- |
| admin  | [Want](js-apis-app-ability-want.md) | Yes  | Device administrator application.                             |
| userId | number                              | Yes  | User ID, which must be greater than or equal to 0.|

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the user is not allowed to add OS accounts; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.      |
| 9200002  | The administrator application does not have permission to manage the device.|

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let isDisallowed: boolean = accountManager.isAddOsAccountByUserDisallowed(wantTemp, 100);
  console.info(`Succeeded in querying the user can add os account or not: ${isDisallowed}`);
} catch (err) {
  console.error(`Failed to query the user can add os account or not. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.addOsAccount<sup>11+</sup>

addOsAccount(admin: Want, name: string, type: osAccount.OsAccountType): osAccount.OsAccountInfo

Adds an OS account in the background through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](js-apis-app-ability-want.md)                          | Yes  | Device administrator application.                                              |
| name   | string                                                       | Yes  | User ID, which must be greater than or equal to 0.                 |
| type   | [osAccount.OsAccountType](js-apis-osAccount.md#osaccounttype) | Yes  | Type of the account to add.<br>The value can be any of the following:<br>· **ADMIN**: administrator account.<br>· **NORMAL**: normal account.<br>· **GUEST**: guest account.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| [osAccount.OsAccountInfo](js-apis-osAccount.md#osaccountinfo) | Information about the account added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.      |
| 9200002  | The administrator application does not have permission to manage the device.|
| 9201003  | failed to add an OS account.                                 |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import osAccount from '@ohos.account.osAccount';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let info: osAccount.OsAccountInfo = accountManager.addOsAccount(wantTemp, "TestAccountName", osAccount.OsAccountType.NORMAL);
  console.info(`Succeeded in creating os account: ${JSON.stringify(info)}`);
} catch (err) {
  console.error(`Failed to creating os account. Code: ${err.code}, message: ${err.message}`);
}
```
