# @ohos.enterprise.bundleManager (Bundle Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides package management capabilities, including installing and uninstalling application packages, and managing the installation trustlist, installation blocklist, uninstallation blocklist, and distribution types of installable applications. In enterprise device management scenarios, these capabilities enable fine-grained control over application installation and uninstallation, preventing unauthorized installations and uninstallations, thereby safeguarding enterprise device security and reducing security risks.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { bundleManager } from '@kit.MDMKit';
```

## bundleManager.addAllowedInstallBundlesSync

addAllowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Adds the applications that can be installed by the current or specified user. The reinstallation of system apps after uninstallation is not restricted by the API. However, the reinstallation of regular apps after uninstallation is restricted by the API.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| appIds    | Array&lt;string&gt;                                     | Yes  | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.|
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.addAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding allowed install bundles.');
} catch (err) {
  console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeAllowedInstallBundlesSync

removeAllowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Removes the applications that can be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.      |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing allowed install bundles.');
} catch (err) {
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getAllowedInstallBundlesSync

getAllowedInstallBundlesSync(admin: Want | null, accountId?: number): Array&lt;string&gt;

Obtains the applications that can be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policy set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policy that actually takes effect.|
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | List of bundles that are allowed to be installed by the current or specified user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<string> = bundleManager.getAllowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedInstallBundlesSync

addDisallowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Adds the applications that are not allowed to be installed by the current or specified user. The reinstallation of system apps after uninstallation is not restricted by the API. However, the reinstallation of regular apps after uninstallation is restricted by the API.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.|
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.addDisallowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding disallowed install bundles.');
} catch (err) {
  console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeDisallowedInstallBundlesSync

removeDisallowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Removes the applications that cannot be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeDisallowedInstallBundlesSync(wantTemp, appIds, 100)
  console.info('Succeeded in removing disallowed install bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedInstallBundlesSync

getDisallowedInstallBundlesSync(admin: Want | null, accountId?: number): Array&lt;string&gt;

Obtains the applications that cannot be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policy set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policy that actually takes effect.|
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | List of bundles that are not allowed to be installed by the current or specified user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let result: Array<string> = bundleManager.getDisallowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedUninstallBundlesSync

addDisallowedUninstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Adds the applications that are not allowed to be uninstalled by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | Application IDs.<br>Value range: The total number of entries in this list for a single user must not exceed 200. For example, if user 100 already has 50 entries and user 101 has none, user 100 can add up to 150 more entries, while user 101 can add up to 200 entries. You are advised to configure a maximum of 50 entries at a time to prevent potential performance problems.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.|
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  // Replace parameters with actual values.
  bundleManager.addDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeDisallowedUninstallBundlesSync

removeDisallowedUninstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Removes the applications that cannot be uninstalled by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | Application IDs.<br>Value range: You are advised to configure a maximum of 50 entries at a time to prevent potential performance problems.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.                  |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  // Replace parameters with actual values.
  bundleManager.removeDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedUninstallBundlesSync

getDisallowedUninstallBundlesSync(admin: Want | null, accountId?: number): Array&lt;string&gt;

Obtains the bundles that are not allowed to be uninstalled by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policy set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policy that actually takes effect.|
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | List of bundles that are not allowed to be uninstalled by the user.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let result: Array<string> = bundleManager.getDisallowedUninstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise&lt;void&gt;

Uninstalls a specified bundle of the current or specified user. The **isKeepData** parameter specifies whether to retain the bundle data. This API uses a promise to return the result. After the API is successfully called, the application is uninstalled, and the data is retained or deleted based on the **isKeepData** parameter.

> **NOTE**
>
> Error code **401** will be returned if this API is called to uninstall an application that is either a non-removable pre-installed application or one configured as non-uninstallable via the [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync) API.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleName | string                                                  | Yes  | Bundle name of an application.                                                      |
| userId     | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|
| isKeepData | boolean                                                 | No  | Whether to retain the bundle data. The value **true** means to retain the bundle data; the value **false** means the opposite.             |

**Return value**

| Type               | Description                                                 |
| ------------------- | ----------------------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object will be thrown if the application fails to be uninstalled.|

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
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace parameters with actual values.
bundleManager.uninstall(wantTemp, 'bundleName', 100, true).then(() => {
  console.info('Succeeded in uninstalling bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.install

install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>

Installs specified applications. This API uses a promise to return the result.<br>This API can be used to install only applications of the **enterprise_mdm** (MDM application) or **enterprise_normal** (common enterprise application) distribution type. You can call the [getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) API to query the [BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md) of an application, where **BundleInfo.appInfo.appDistributionType** indicates the distribution type. Since API version 26.0.0, you are advised to use [installForResult](#bundlemanagerinstallforresult) to obtain more detailed error code return values.
> **NOTE**
> 
> This API is time-consuming. Subsequent calls to other synchronous APIs in the application main thread must wait for the asynchronous return of this API.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.        |
| hapFilePaths | Array\<string>                                          | Yes  | Applications to install. The app bundle must be stored in the path that the app has the permission to access, such as the app sandbox path. For details about the mapping between the app sandbox path and the actual physical path, see [Mappings Between App Sandbox Paths and Physical Paths](../../file-management/app-sandbox-directory.md#mappings-between-application-sandbox-paths-and-physical-paths).|
| installParam | [InstallParam](#installparam)                           | No  | Application installation parameters.      |

**Return value**

| Type               | Description                                                   |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201002  | Failed to install the application.                           |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Install the application for the current user.
let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];

bundleManager.install(wantTemp, hapFilePaths).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Install the application for all users.
let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];
const params: Record<string, string> = {
  'ohos.bms.param.enterpriseForAllUser': 'true'
};
let installParam: bundleManager.InstallParam = {
  // Replace with actual values.
  userId: 100,
  installFlag: 0,
  parameters: params
};
bundleManager.install(wantTemp, hapFilePaths, installParam).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.installForResult

installForResult(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void\>

Installs the application bundle in the specified path and returns the installation result. This API uses a promise to return the result.<br>This API can be used to install only applications of the **enterprise_mdm** (MDM application) or **enterprise_normal** (common enterprise application) distribution type. You can call the [getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) API to query the [BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md) of an application, where **BundleInfo.appInfo.appDistributionType** indicates the distribution type.

> **NOTE**
> 
> This API is time-consuming. Subsequent calls to other synchronous APIs in the application main thread must wait for the asynchronous return of this API.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.        |
| hapFilePaths | Array\<string>                                          | Yes  | Applications to install. The app bundle must be stored in the path that the app has the permission to access, such as the app sandbox path. For details about the mapping between the app sandbox path and the actual physical path, see [Mappings Between App Sandbox Paths and Physical Paths](../../file-management/app-sandbox-directory.md#mappings-between-application-sandbox-paths-and-physical-paths).|
| installParam | [InstallParam](#installparam)                           | No  | Application installation parameters.      |

**Return value**

| Type               | Description                                                   |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201002  | Failed to install the application.                           |
| 9201022  | Failed to install the HAP because of insufficient system disk space. |
| 9201023  | Failed to install the HAP because enterprise device management disallows the installation. |
| 9201024  | Failed to install the HAP because the HAP fails to be parsed. |
| 9201025  | Failed to install the HAP because the HAP signature fails to be verified. |
| 9201026  | Failed to install the HAP because the HAP path is invalid or the HAP is too large. |
| 9201027  | Failed to install the HAPs because they have different configuration information. |
| 9201028  | Failed to install the HAP because the isolationMode configured is not supported. |
| 9201029  | Failed to install the HAP since the version of the HAP to install is too early. |
| 9201030  | Failed to install the HAP because the VersionCode to be updated is not greater than the current VersionCode. |
| 9201031  | Installation failed because the dependent module does not exist. |
| 9201032  | The specified user ID is not found. |
| 9201033  | Failed to install the HAP because the overlay check failed. |
| 9201034  | Failed to install the HSP due to missing required permissions. |
| 9201035  | Installation failed because the installation of cross-app shared libraries is not allowed. |
| 9201036  | Failed to install the HAP due to incorrect URI in the data proxy. |
| 9201037  | Failed to install the HAP due to incorrect permission configuration in the data proxy. |
| 9201038  | Failed to install the HAP due to code signature verification failure. |
| 9201039  | Failed to install the HAP due to enterprise device verification failure. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**
Example of not passing the **installParam** parameter:
```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Install the application for the current user.
let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Set bundleName based on the actual situation. For example, if bundleName is com.example.myapplication, the valid path is '/data/storage/el2/base/com.example.myapplication/haps/entry/testinstall/ExtensionTest.hap'.
// Ensure that the file in the corresponding path exists and the application has the permission to access the file.
let hapFilePaths: Array<string> = ['/data/storage/el2/base/bundleName/haps/entry/testinstall/ExtensionTest.hap'];

bundleManager.installForResult(wantTemp, hapFilePaths).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  // After obtaining the error code, rectify the fault based on the error cause in the API comment.
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

Example of passing the **installParam** parameter:
```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Install the application for all users.
let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Set bundleName based on the actual situation. For example, if bundleName is com.example.myapplication, the valid path is '/data/storage/el2/base/com.example.myapplication/haps/entry/testinstall/ExtensionTest.hap'.
// Ensure that the file in the corresponding path exists and the application has the permission to access the file.
let hapFilePaths: Array<string> = ['/data/storage/el2/base/bundleName/haps/entry/testinstall/ExtensionTest.hap'];
const params: Record<string, string> = {
  'ohos.bms.param.enterpriseForAllUser': 'true'
};
let installParam: bundleManager.InstallParam = {
  // Replace with actual values.
  userId: 100,
  installFlag: 0,
  parameters: params
};
bundleManager.installForResult(wantTemp, hapFilePaths, installParam).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  // After obtaining the error code, rectify the fault based on the error cause in the API comment.
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getInstalledBundleList<sup>20+</sup>

getInstalledBundleList(admin: Want, accountId: number): Promise\<Array\<BundleInfo>>

Obtains the applications installed by a specified user on a device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| accountId    | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.|

**Return value**

| Type               | Description                                                   |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleInfo](#bundleinfo20)&gt;&gt; | Promise used to return the bundle information of the installed application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let accountId: number = 100;
bundleManager.getInstalledBundleList(wantTemp, accountId).then((result) => {
  console.info('Succeeded in getting installed bundle list.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle list. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getInstalledBundleList<sup>23+</sup>

getInstalledBundleList(admin: Want, accountId: number, bundleInfoGetFlag: number): Promise\<Array\<BundleInfo>>

Obtains the list of applications installed by a specified user based on the specified **bundleInfoGetFlag**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.        |
| accountId    | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.|
| [bundleInfoGetFlag](js-apis-enterprise-bundleManager.md#bundleinfogetflag23)    | number              | Yes  | Type of the bundle information to obtain.|

**Return value**

| Type               | Description                                                   |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleInfo](#bundleinfo20)&gt;&gt; | Promise used to return the bundle information of the installed application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let accountId: number = 100;
let bundleInfoGetFlag: number = bundleManager.BundleInfoGetFlag.WITH_APPLICATION_INFO
  | bundleManager.BundleInfoGetFlag.WITH_SIGNATURE_INFO;
bundleManager.getInstalledBundleList(wantTemp, accountId, bundleInfoGetFlag).then((result) => {
  console.info('Succeeded in getting installed bundle list.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle list. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.addInstallationAllowedAppDistributionTypes<sup>20+</sup>

addInstallationAllowedAppDistributionTypes(admin: Want, appDistributionTypes: Array&lt;AppDistributionType&gt;): void

Adds the distribution type of the application that can be installed. Only applications of the distribution type that is added to [AppDistributionType](#appdistributiontype20) can be installed on the current device.<br>
For details about the distribution type of the application signing certificate, refer to the **appDistributionType** attribute in [ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1).

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | Yes  | Distribution types of the application signing certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let appDistributionTypes: Array<bundleManager.AppDistributionType> = [bundleManager.AppDistributionType.APP_GALLERY];
  bundleManager.addInstallationAllowedAppDistributionTypes(wantTemp, appDistributionTypes);
  console.info('Succeeded in adding allowed appDistributionTypes.');
} catch (err) {
  console.error(`Failed to add allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.removeInstallationAllowedAppDistributionTypes<sup>20+</sup>

removeInstallationAllowedAppDistributionTypes(admin: Want, appDistributionTypes: Array&lt;AppDistributionType&gt;): void

Removes the distribution type of an application. If only some distribution types in the array are removed, the current device can install applications of the remaining distribution types in the array, but cannot install applications of the distribution types not included in [AppDistributionType](#appdistributiontype20).<br>
For details about the distribution type of the application signing certificate, refer to the **appDistributionType** attribute in [ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1).

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | Yes| Distribution types of the application signing certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let appDistributionTypes: Array<bundleManager.AppDistributionType> = [bundleManager.AppDistributionType.APP_GALLERY];
  bundleManager.removeInstallationAllowedAppDistributionTypes(wantTemp, appDistributionTypes);
  console.info('Succeeded in removing allowed appDistributionTypes.');
} catch (err) {
  console.error(`Failed to remove allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.getInstallationAllowedAppDistributionTypes<sup>20+</sup>

getInstallationAllowedAppDistributionTypes(admin: Want | null): Array&lt;AppDistributionType&gt;

Obtains the distribution type of the signing certificate used by applications that can be installed.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policy set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policy that actually takes effect.|

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| Array&lt;[AppDistributionType](#appdistributiontype20)&gt; | Distribution types of the application signing certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.edmtest',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let result: Array<bundleManager.AppDistributionType> = bundleManager.getInstallationAllowedAppDistributionTypes(wantTemp);
  console.info(`Succeeded in getting allowed appDistributionTypes. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.installMarketApps<sup>22+</sup>

installMarketApps(admin: Want, bundleNames: Array\<string>): void

Downloads and installs an application from AppGallery.
> **NOTE**
>
> After this API is successfully called, an application download task is generated on the home screen. The task is the same as that created during download from AppGallery. Upon completion of the download and installation, the installation result is returned through the [EnterpriseAdminExtensionAbility.onMarketAppInstallResult](./js-apis-EnterpriseAdminExtensionAbility.md#onmarketappinstallresult22) callback.<!--RP1--><!--RP1End-->

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.        |
| bundleNames    | Array&lt;string&gt;                                                  | Yes  | Application bundle name list. A maximum of 10 bundle names can be passed at a time. The bundle name must be the same as that on AppGallery. Otherwise, the download task cannot be created, and error code 9201002 will be reported.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201002  | Failed to install the application. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let bundleNames: Array<string> = [ 'com.huaweicloud.m' ];
try {
  bundleManager.installMarketApps(wantTemp, bundleNames);
  console.info(`Succeeded in installing market apps.`);
} catch(err) {
  console.error(`Failed to install market apps. Code: ${err.code}, message: ${err.message}`);
}
```

## bundleManager.getInstalledBundleStorageStats

getInstalledBundleStorageStats(admin: Want, bundleNames: Array\<string>, accountId: number): Promise\<Array\<BundleStorageStats>>

Obtains the storage usage of installed applications of a specified user on a device. This API uses a promise to return the result.

> **NOTE**
> 
> 1. Only the storage usage of installed applications can be obtained.
>
> 2. If **bundleNames** is empty or all bundle names passed are of uninstalled applications, error code 9200012 will be returned.
>
> 3. If some of the applications specified in the **bundleNames** parameter are installed and some are not, the API returns normally. For installed applications, their actual storage usage information is returned. For uninstalled applications, **0** is returned as their storage usage.
>
> 4. This API supports cross-user queries. For example, user 100 can query the storage usage of some applications of user 101.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.        |
| bundleNames  | Array&lt;string&gt;                                     | Yes  | Application bundle name list. The list must contain no more than 200 bundle names.|
| accountId    | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.|

**Return value**

| Type               | Description                                                   |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleStorageStats](#bundlestoragestats)&gt;&gt; | Promise used to return the storage usage information of the installed applications.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                               |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let bundleNames: Array<string> = ['com.example.app1', 'com.example.app2'];
let accountId: number = 100;
bundleManager.getInstalledBundleStorageStats(wantTemp, bundleNames, accountId).then((result) => {
  console.info('Succeeded in getting installed bundle storage stats.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle storage stats. Code is ${err.code}, message is ${err.message}`);
});
```
<!--code_no_check-->
```ts
// Return value example.
[
  {
    "bundleName": "com.example.edmtest",
    "appSize": 38185408,
    "dataSize": 1216566
  },
  // ...
]
```


## InstallParam

Defines the parameters for application installation.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name                    | Type                  | Read-Only| Optional| Description                                                        |
| ------------------------ | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| userId                   | number                 | No  | Yes| User ID, which must be greater than or equal to 0. The default value is the user ID of the caller.   |
| installFlag              | number                 | No  | Yes|Installation flag.<br> **0** (default value) indicates fresh installation of the application, **1** indicates overlay installation of the application, and **2** indicates installation-free.|
| parameters<sup>19+</sup> | Record&lt;string, string&gt; | No  | Yes| Extended parameters. The default value is null. The key can be **ohos.bms.param.enterpriseForAllUser**. If the corresponding value is set **true**, the application is installed for all users.|

## AppDistributionType<sup>20+</sup>

Defines the distribution type of the application signing certificate. For details, please refer to the **appDistributionType** attribute of [ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Value| Description                           |
| ----------- | -------- | ------------------------------- |
| APP_GALLERY | 1  | Application installed from AppGallery.|
| ENTERPRISE | 2  | Enterprise application.|
| ENTERPRISE_NORMAL | 3  | Common enterprise application.|
| ENTERPRISE_MDM | 4  | Enterprise MDM application.|
| INTERNALTESTING | 5  | Application under internal testing of AppGallery.|
| CROWDTESTING | 6  | Crowdtesting application.|

## BundleInfo<sup>20+</sup>

Describes the application bundle information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name                             | Type                                                        | Read-Only| Optional| Description                                                        |
| --------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                              | string                                                       | Yes  | No  | Name of the application bundle. It corresponds to the **bundleName** field in the [app.json5](../../quick-start/app-configuration-file.md) file.|
| vendor                            | string                                                       | Yes  | No  | Vendor of the application bundle. It corresponds to the **vendor** field in the [app.json5](../../quick-start/app-configuration-file.md) file.|
| versionCode                       | number                                                       | Yes  | No  | Version code of the application bundle. It corresponds to the **versionCode** field in the [app.json5](../../quick-start/app-configuration-file.md) file.|
| versionName                       | string                                                       | Yes  | No  | Version description of the application bundle. It corresponds to the **versionName** field in the [app.json5](../../quick-start/app-configuration-file.md) file.|
| minCompatibleVersionCode          | number                                                       | Yes  | No  | Minimum compatible version of the application bundle in the distributed scenario. It corresponds to the **minCompatibleVersionCode** field in the [app.json5](../../quick-start/app-configuration-file.md) file.|
| targetVersion                     | number                                                       | Yes  | No  | Target version of the application. It corresponds to the **targetAPIVersion** field in the [app.json5](../../quick-start/app-configuration-file.md) file.|
| appInfo                           | [ApplicationInfo](#applicationinfo20)                        | Yes  | No  | Application information.|
| signatureInfo                     | [SignatureInfo](#signatureinfo20)                            | Yes  | No  | Signature information of the bundle.|
| installTime                       | number                                                       | Yes  | No  | Timestamp for the installation of the application bundle. It measures the milliseconds elapsed since the Unix epoch (January 1, 1970, 08:00:00 UTC+8).|
| updateTime                        | number                                                       | Yes  | No  | Timestamp for the last update of the application bundle. It measures the milliseconds elapsed since the Unix epoch (January 1, 1970, 08:00:00 UTC+8).|
| appIndex                          | number                                                       | Yes  | No  | Index of an application clone. It takes effect only for application clones.|
| firstInstallTime                  | number                                                       | Yes  | Yes  | Timestamp for the initial installation of the application bundle. It measures the milliseconds elapsed since the Unix epoch (January 1, 1970, 08:00:00 UTC+8). For preinstalled applications, the initial installation timestamp is 1533657660000.|


## SignatureInfo<sup>20+</sup>

Describes the signature information of the bundle.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| appId     | string         | Yes  | No  | App ID, which uniquely identifies an app.                |
|fingerprint| string         | Yes  | No  | Fingerprint information of the application package. It is generated by calculating the hash value of the signing certificate using the SHA-256 algorithm. This field changes when the used signing certificate changes.         |
|appIdentifier| string         | Yes  | No  | Unique ID of the application.           |
|certificate| string         | Yes  | Yes  | Public key of the application certificate.          |


## ApplicationInfo<sup>20+</sup>

Defines the application information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name                      | Type                                                        | Read-Only| Optional| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Name of the application bundle. It corresponds to the **bundleName** field in the [app.json5](../../quick-start/app-configuration-file.md) file.                                                |
| description                | string                                                       | Yes  | No  | Description of the application. It corresponds to the **description** field in [app.json5](../../quick-start/app-configuration-file.md). For details about **description**, see the **descriptionResource** field in this table.|
| descriptionId              | number                                                       | Yes  | No  | Resource ID of the application description. It is automatically generated during compilation and build based on the description configured for the application.|
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. **true** if enabled, **false** otherwise.|
| label                      | string                                                       | Yes  | No  | Application label.|
| labelId                    | number                                                       | Yes  | No  | Resource ID of the application label. It is automatically generated during compilation and build based on the label configured for the application.|
| icon                       | string                                                       | Yes  | No  | Application icon. It corresponds to the **icon** field in the [app.json5](../../quick-start/app-configuration-file.md) file. For details about **icon**, see the **iconResource** field in this table.|
| iconData<sup>23+</sup>     | string                                                       | Yes  | No  | Application icon, which is in Base64 encoding format.|
| iconId                     | number                                                       | Yes  | No  | Resource ID of the application icon. It is automatically generated during compilation and build based on the icon configured for the application.|
| process                    | string                                                       | Yes  | No  | Process name.|
| codePath                   | string                                                       | Yes  | No  | Installation directory of the application.|
| removable                  | boolean                                                      | Yes  | No  | Whether the application is removable. **true** if removable, **false** otherwise.|
| accessTokenId             | number                                                       | Yes  | No  | Access token ID of the application, which is used in the [checkAccessToken](../apis-ability-kit/js-apis-abilityAccessCtrl.md#checkaccesstoken9).|
| uid                       | number                                                       | Yes  | No  | UID of the application.|
| iconResource              | [Resource](#resource20) | Yes| No| Resource information of the application icon, including the bundle name, module name, and ID of the resource.|
| labelResource             | [Resource](#resource20) | Yes| No| Resource information of the application label, including the bundle name, module name, and ID of the resource.|
| descriptionResource       | [Resource](#resource20) | Yes| No| Resource information of the application description, including the bundle name, module name, and ID of the resource.|
| appDistributionType       | string                                                       | Yes  | No  | Distribution type of the application signing certificate. For details, see the **appProvisionType** field in [ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1).|
| appProvisionType          | string                                                       | Yes  | No  | Type of the application signing certificate file. The options are **debug** and **release**.|
| systemApp          | boolean                                                       | Yes  | No  | Whether the application is a system application. **true** if it is a system application, **false** otherwise.|
| debug       | boolean                                | Yes  | No  | Whether the application is running in debug mode. **true** if in debug mode, **false** otherwise.|
| dataUnclearable       | boolean                      | Yes  | No  | Whether the application data is unclearable. The value **true** means that the application data is unclearable, and **false** means the opposite.|
| nativeLibraryPath | string                                                                     | Yes  | No  | Local library file path of the application.|
| appIndex    | number    | Yes  | No  | Index of an application clone. It takes effect only for application clones.|
| installSource    | string    | Yes  | No  | Installation source of the application. The options are as follows:<br> - **pre-installed**: The application is a preset application installed at initial device startup.<br> - **ota**: The application is a preset application added during system upgrade.<br> - **recovery**: The preset application is uninstalled and then restored.<br> - **bundleName**: The application corresponding to the bundle name is installed.<br> - **unknown**: The installation source is unknown.|
| releaseType      | string    | Yes  | No  | Release type of the SDK used for application packing. Currently, the SDK release types include Canary, Beta, and Release. Each of the Canary and Beta releases can be distinguished by a sequential number, such as Canary1, Canary2, Beta1, and Beta2. You can compare the SDK release type on which application packaging depends and the OS release type (specified by [deviceInfo.distributionOSReleaseType](../apis-basic-services-kit/js-apis-device-info.md)) to determine the compatibility.|


## Resource<sup>20+</sup>

Describes application resource information, including the bundle name, module name, and resource ID.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name        | Type    | Read-Only  | Optional |Description         |
| ---------- | ------ | ----- | ----  | ---------------|
| bundleName | string | No   | No| Bundle name of the application.|
| moduleName | string | No   | No| Module name of the application.|
| id         | number | No   | No| Resource ID.     |

## BundleInfoGetFlag<sup>23+</sup>

Enumerates the bundle flags, which indicate the type of bundle information to obtain.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name                          | Value       | Description                                                        |
| --------------------------    | ---------- | ------------------------------------------------------------ |
| DEFAULT                       | 0 | Obtains the default bundle information, excluding **applicationInfo** and **signatureInfo**.|
| WITH_APPLICATION_INFO         | 1 << 0 | Obtains the default bundle information and **applicationInfo** (excluding **iconData**).|
| WITH_SIGNATURE_INFO           | 1 << 1 | Obtains the default bundle information and **signatureInfo**.|
| WITH_APPLICATION_ICON_INFO    | 1 << 2 | Obtains the default bundle information and **applicationInfo** (including **iconData**).|

## BundleStorageStats

Storage usage information of the application.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name     | Type          | Read-Only| Optional| Description                       |
| --------- | -------------- | ---- | ---- | --------------------------- |
| bundleName| string         | No  | No  | Bundle name of the application.                |
| appSize   | number         | No  | No  | Size of the application installation files, in bytes.<br>Application installation file directory:<br>/data/storage/el1/bundle         |
| dataSize  | number         | No  | No  | Size of the local data, distributed data, and database data of the application, in bytes.<br>Local file directory (parent directory of the cache file directory):<br>/data/storage/\${el1-el5}/base<br>Distributed file directory:<br>/data/storage/el2/distributedfiles<br>Database file directory:<br>/data/storage/\${el1-el5}/database<br> **Note**: **\${el1-el5}** refers to the directories [el1, el2, el3, el4, el5](../../../application-dev/file-management/app-sandbox-directory.md#application-file-directory-and-application-file-path)|
