# @ohos.enterprise.securityManager (Security Management)

The **securityManager** module provides device security management capabilities, including obtaining the security patch status and file system encryption status.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { securityManager } from '@kit.MDMKit';
```

## securityManager.uninstallUserCertificate

uninstallUserCertificate(admin: Want, certUri: string): Promise&lt;void&gt;

Uninstalls a user certificate. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name | Type                                                   | Mandatory| Description                             |
| ------- | ------------------------------------------------------- | ---- | --------------------------------- |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                   |
| certUri | string                                                  | Yes  | Certificate URI, which is set and returned by the [installUserCertificate](#securitymanagerinstallusercertificate) API for installing a user certificate.|

**Return value**

| Type               | Description                                                        |
| ------------------- | ------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value. An error object will be thrown if the operation fails.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201001  | Failed to manage the certificate.                            |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let aliasStr = "certName"
securityManager.uninstallUserCertificate(wantTemp, aliasStr).then(() => {
  console.info(`Succeeded in uninstalling user certificate.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall user certificate. Code is ${err.code}, message is ${err.message}`);
});
```

## securityManager.installUserCertificate

installUserCertificate(admin: Want, certificate: CertBlob): Promise&lt;string&gt;

Installs a user certificate. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_CERTIFICATE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                                   | Mandatory| Description          |
| ----------- | ------------------------------------------------------- | ---- | -------------- |
| admin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| certificate | [CertBlob](#certblob)                                   | Yes  | Certificate information. The certificate file must be stored in a path that can be accessed by the application, such as the application sandbox path.    |

**Return value**

| Type                 | Description                                                |
| --------------------- | ---------------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the installed certificate. This URI can be used to uninstall the certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201001  | Failed to manage the certificate.                            |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let certFileArray: Uint8Array = new Uint8Array();
// Initialize the Context variable in the onCreate callback function of the MainAbility.
// Place the test file test.cer in the rawfile directory.
getContext().resourceManager.getRawFileContent("test.cer").then((value) => {
  certFileArray = value;
  securityManager.installUserCertificate(wantTemp, { inData: certFileArray, alias: "cert_alias_xts" })
    .then((result) => {
      console.info(`Succeeded in installing user certificate, result : ${JSON.stringify(result)}`);
    }).catch((err: BusinessError) => {
    console.error(`Failed to install user certificate. Code: ${err.code}, message: ${err.message}`);
  })
}).catch((err: BusinessError) => {
  console.error(`Failed to get row file content. message: ${err.message}`);
  return
});
```

## securityManager.getSecurityStatus

getSecurityStatus(admin: Want, item: string): string

Obtains security status.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SECURITY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| item   | string                                                  | Yes  | Type of the security status to obtain.<br>- **patch**: device security patch.<br>- **encryption**: device file system encryption.<!--RP1--><!--RP1End-->|

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| string | Security status obtained.|

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
  let result: string = securityManager.getSecurityStatus(wantTemp, 'patch');
  console.info(`Succeeded in getting security patch tag. tag: ${result}`);
} catch (err) {
  console.error(`Failed to get security patch tag. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setPasswordPolicy

setPasswordPolicy(admin: Want, policy: PasswordPolicy): void

Sets the device password policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SECURITY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility.                 |
| policy | [PasswordPolicy](#passwordpolicy) | Yes| Device password policy to set.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

let policy: securityManager.PasswordPolicy = {
  complexityRegex: '^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{8,}$',
  validityPeriod: 1,
  additionalDescription: 'The password must contain at least eight characters, including at least one uppercase letter, one lowercase letter, one digit, and one special character.',
}
try {
    securityManager.setPasswordPolicy(wantTemp, policy);
    console.info(`Succeeded in setting password policy.`);
} catch(err) {
    console.error(`Failed to set password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getPasswordPolicy

getPasswordPolicy(admin: Want): PasswordPolicy

Obtains the device password policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SECURITY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| [PasswordPolicy](#passwordpolicy) | Device password policy obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: securityManager.PasswordPolicy = securityManager.getPasswordPolicy(wantTemp);
    console.info(`Succeeded in getting password policy, result : ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get password policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.setAppClipboardPolicy

setAppClipboardPolicy(admin: Want, tokenId: number, policy: ClipboardPolicy): void

Sets the device clipboard policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SECURITY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility.                 |
| tokenId | number | Yes| Application token ID, which can be obtained using [bundleManager.getApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md). Currently, a maximum of 100 token IDs can be saved.|
| policy | [ClipboardPolicy](#clipboardpolicy) | Yes| Clipboard policy to set.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let tokenId: number = 586874394;
try {
    securityManager.setAppClipboardPolicy(wantTemp, tokenId, securityManager.ClipboardPolicy.IN_APP);
    console.info(`Succeeded in setting clipboard policy.`);
} catch(err) {
    console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## securityManager.getAppClipboardPolicy

getAppClipboardPolicy(admin: Want, tokenId?: number): string

Obtains the device clipboard policy.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SECURITY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility.     |
| tokenId | number | No| Application token ID, which can be obtained using [bundleManager.getApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md). Currently, a maximum of 100 token IDs can be saved.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| string | Device clipboard policy in JSON format.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let tokenId: number = 586874394;
try {
    let result: string = securityManager.getAppClipboardPolicy(wantTemp, tokenId);
    console.info(`Succeeded in getting password policy, result : ${result}`);
} catch(err) {
    console.error(`Failed to set clipboard policy. Code: ${err.code}, message: ${err.message}`);
}
```

## CertBlob

Represents the certificate information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name  | Type      | Mandatory| Description              |
| ------ | ---------- | ---- | ------------------ |
| inData | Uint8Array | Yes  | Binary content of the certificate.|
| alias  | string     | Yes  | Certificate alias.        |

## PasswordPolicy

Represents a device password policy.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Type    | Mandatory| Description                           |
| ----------- | --------| ---- | ------------------------------- |
| complexityRegex | string | No| Regular expression for password complexity.|
| validityPeriod | number | No| Password validity period, in ms.|
| additionalDescription | string | No| Description of the device password.|

## ClipboardPolicy

Represents a device clipboard policy.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Value| Description                           |
| ----------- | -------- | ------------------------------- |
| DEFAULT | 0  | Default policy.|
| IN_APP | 1  | Allow the clipboard to be used in the same application.|
| LOCAL_DEVICE | 2  | Allow the clipboard to be used on the same device.|
| CROSS_DEVICE | 3  | Allow the clipboard to be used across devices.|
