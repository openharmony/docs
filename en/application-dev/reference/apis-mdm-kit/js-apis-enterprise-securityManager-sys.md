# @ohos.enterprise.securityManager (Security Management) (System API)

The **securityManager** module provides device security management capabilities, including obtaining the security patch status and file system encryption status.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is [enabled](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2).
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.securityManager](js-apis-enterprise-securityManager.md).

## Modules to Import

```ts
import { securityManager } from '@kit.MDMKit';
```

## securityManager.getSecurityPatchTag

getSecurityPatchTag(admin: Want): string

Queries the security patch tag of a device.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SECURITY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| string | Patch tag obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let res: string = securityManager.getSecurityPatchTag(wantTemp);
    console.info(`Succeeded in getting security patch tag. tag: ${res}`);
} catch(err) {
    console.error(`Failed to get security patch tag. Code: ${err.code}, message: ${err.message}`);
}
```
## securityManager.getDeviceEncryptionStatus

getDeviceEncryptionStatus(admin: Want): DeviceEncryptionStatus

Queries the encryption status of the device file system.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SECURITY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility.           |

**Return value**

| Type                                             | Description                                                  |
| ------------------------------------------------- | ------------------------------------------------------ |
| [DeviceEncryptionStatus](#deviceencryptionstatus) | File system encryption status. Currently, only a boolean value indicating whether the file system is encrypted is returned.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: securityManager.DeviceEncryptionStatus = securityManager.getDeviceEncryptionStatus(wantTemp);
    console.info(`Succeeded in getting device encryption status. isEncrypted: ${result.isEncrypted}`);
} catch(err) {
    console.error(`Failed to get device encryption status. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getPasswordPolicy<sup>12+</sup>

getPasswordPolicy(): PasswordPolicy

Obtains the password policy of this device.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| [PasswordPolicy](./js-apis-enterprise-securityManager.md#passwordpolicy) | Device password policy obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

```ts
try {
    let result: securityManager.PasswordPolicy = securityManager.getPasswordPolicy();
    console.info(`Succeeded in getting password policy, result : ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## DeviceEncryptionStatus

Represents the file system encryption status.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name        | Type    | Read-Only| Optional|  Description                           |
| ----------- | --------| ---- | ----| ---------------------------- |
| isEncrypted | boolean | No  | No| Whether the file system of the device is encrypted. <br>The value **true** means the file system of the device is encrypted; the value **false** means the opposite.|
