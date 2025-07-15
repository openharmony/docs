# @ohos.enterprise.bundleManager (Bundle Management)

The **bundleManager** module provides APIs for bundle management, including adding, obtaining, and removing a list of bundles that are allowed to install.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { bundleManager } from '@kit.MDMKit';
```

## bundleManager.addAllowedInstallBundlesSync

addAllowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Adds the applications that can be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
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


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing allowed install bundles.');
} catch (err) {
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getAllowedInstallBundlesSync

getAllowedInstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

Obtains the applications that can be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | Applications that can be installed.|

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
  let result: Array<string> = bundleManager.getAllowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedInstallBundlesSync

addDisallowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Adds the applications that cannot be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
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

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeDisallowedInstallBundlesSync(wantTemp, appIds, 100)
  console.info('Succeeded in removing disallowed install bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedInstallBundlesSync

getDisallowedInstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

Obtains the applications that cannot be installed by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | Applications that cannot be installed.|

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
  let result: Array<string> = bundleManager.getDisallowedInstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.addDisallowedUninstallBundlesSync

addDisallowedUninstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Adds the applications that cannot be uninstalled by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
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


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  bundleManager.removeDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedUninstallBundlesSync

getDisallowedUninstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

Obtains the applications that cannot be uninstalled by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of **@ohos.account.osAccount** to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | Applications that cannot be uninstalled by the user.|

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
  let result: Array<String> = bundleManager.getDisallowedUninstallBundlesSync(wantTemp, 100);
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.uninstall

uninstall(admin: Want, bundleName: string, userId?: number, isKeepData?: boolean): Promise&lt;void&gt;

Uninstalls an application of the current or specified user. The **isKeepData** parameter specifies whether to retain the bundle data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| bundleName | string                                                  | Yes  | Name of the bundle to uninstall.                                                      |
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

bundleManager.uninstall(wantTemp, 'bundleName', 100, true).then(() => {
  console.info('Succeeded in uninstalling bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.install

install(admin: Want, hapFilePaths: Array\<string>, installParam?: InstallParam): Promise\<void>

Installs specified applications. This API uses a promise to return the result.<br>The distribution type of the application can only be **enterprise_mdm** or **enterprise_normal**.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.        |
| hapFilePaths | Array\<string>                                          | Yes  | Applications to install.|
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
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Install the application for the current user.
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];

bundleManager.install(wantTemp, hapFilePaths).then(() => {
  console.info('Succeeded in installing bundles.');
}).catch((err: BusinessError) => {
  console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Install the application for all users.
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];
const params: Record<string, string> = {
  'ohos.bms.param.enterpriseForAllUser': 'true'
};
let installParam: bundleManager.InstallParam = {
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

## bundleManager.getInstalledBundleList<sup>20+</sup>

getInstalledBundleList(admin: Want, accountId: number): Promise\<Array\<BundleInfo>>

Obtains the applications installed by a specified user on a device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_ALL_BUNDLE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.        |
| accountId    | number                                                  | Yes  | User ID. The value is a positive integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the user ID.|

**Return value**

| Type               | Description                                                   |
| ------------------- | ------------------------------------------------------- |
| Promise&lt;Array&lt;[BundleInfo](#bundleinfo20)&gt;&gt; | Promise used to return the bundle information of the installed application.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                          |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let accountId: number = 100;
bundleManager.getInstalledBundleList(wantTemp, accountId).then((result) => {
  console.info('Succeeded in getting installed bundle list.');
}).catch((err: BusinessError) => {
  console.error(`Failed to get installed bundle list. Code is ${err.code}, message is ${err.message}`);
});
```

## InstallParam

Defines the parameters for application installation.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name                    | Type                  | Read-Only| Optional| Description                                                        |
| ------------------------ | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| userId                   | number                 | No  | Yes| User ID, which must be greater than or equal to 0. The default value is the user ID of the caller.   |
| installFlag              | number                 | No  | Yes|Installation flag.<br> - **0**: initial installation.<br>- **1**: overwrite installation.<br>- **2**: installation-free.<br>Default value: **0**|
| parameters<sup>19+</sup> | Record&lt;string, string&gt; | No  | Yes| Extended parameters. The default value is null. The key value can be **ohos.bms.param.enterpriseForAllUser**. If the value is **true**, the application is installed for all users.|

## bundleManager.addInstallationAllowedAppDistributionTypes<sup>20+</sup>

addInstallationAllowedAppDistributionTypes(admin: Want, appDistributionTypes: Array&lt;AppDistributionType&gt;): void

Adds the distribution type of the application that can be installed. Only applications of the distribution type that is added to [AppDistributionType](#appdistributiontype20) can be installed on the current device.<br>
For details about the distribution type of the application signing certificate, refer to the **appDistributionType** attribute in [ApplicationInfo](../apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1).

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | Yes  | EnterpriseAdminExtensionAbility.                                      |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | Yes  | Distribution types of the application signing certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                     |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | Yes  | EnterpriseAdminExtensionAbility.                                      |
| appDistributionTypes  | Array&lt;[AppDistributionType](#appdistributiontype20)&gt;  | Yes| Distribution types of the application signing certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                     |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

getInstallationAllowedAppDistributionTypes(admin: Want): Array&lt;AppDistributionType&gt;

Obtains the distribution type of the signing certificate used by applications that can be installed.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name      | Type                                                      | Mandatory| Description                                                        |
| ------------ | -------------------------------------------------------    | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md)    | Yes  | EnterpriseAdminExtensionAbility.                                      |

**Return value**

| Type                              | Description                     |
| ---------------------------------- | ------------------------- |
| Array&lt;[AppDistributionType](#appdistributiontype20)&gt; | Distribution types of the application signing certificate.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |                     |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { bundleManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility'
};
try {
  let result: Array<bundleManager.AppDistributionType> = bundleManager.getInstallationAllowedAppDistributionTypes(wantTemp);
  console.info(`Succeeded in getting allowed appDistributionTypes. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed appDistributionTypes. Code: ${err.code}, message: ${err.message}`);
}
```

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
| appInfo                           | [ApplicationInfo](#applicationinfo20)                        | Yes  | No  | Application information, including the application name and installation directory.|
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
| appId     | string         | Yes  | No  | Application ID.                |
|fingerprint| string         | Yes  | No  | Fingerprint information of the bundle. This field changes when the used signing certificate changes.         |
|appIdentifier| string         | Yes  | No  | Unique ID of the application. It is the [app ID](https://developer.huawei.com/consumer/en/doc/app/agc-help-createharmonyapp-0000001945392297), which is a random string, allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers.         |
|certificate| string         | Yes  | Yes  | Public key of the application certificate.          |


## ApplicationInfo<sup>20+</sup>

Defines the application information.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name                      | Type                                                        | Read-Only| Optional| Description                                                        |
| -------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| name                       | string                                                       | Yes  | No  | Bundle name of the application.                                                |
| description                | string                                                       | Yes  | No  | Application description, for example, `"description": $string: mainability_description"`. For details, see the description of the **descriptionResource** field below.|
| descriptionId              | number                                                       | Yes  | No  | ID of the application description.|
| enabled                    | boolean                                                      | Yes  | No  | Whether the application is enabled. The value **true** means that the application is enabled, and **false** means the opposite.|
| label                      | string                                                       | Yes  | No  | Application label, for example, `"label": "$string: mainability_description"`. For details, see the description of the **labelResource** field below.|
| labelId                    | number                                                       | Yes  | No  | ID of the application label.|
| icon                       | string                                                       | Yes  | No  | Application icon, for example, `"icon": "$media:icon"`. For details, see the description of the **iconResource** field below.|
| iconId                     | number                                                       | Yes  | No  | ID of the application icon.|
| process                    | string                                                       | Yes  | No  | Process name.|
| codePath                   | string                                                       | Yes  | No  | Installation directory of the application.|
| removable                  | boolean                                                      | Yes  | No  | Whether the application is removable. The value **true** means that the application is removable, and **false** means the opposite.|
| accessTokenId             | number                                                       | Yes  | No  | Access token ID of the application.|
| uid                       | number                                                       | Yes  | No  | UID of the application.|
| iconResource              | [Resource](#resource20) | Yes| No| Resource information of the application icon, including the bundle name, module name, and ID of the resource.|
| labelResource             | [Resource](#resource20) | Yes| No| Resource information of the application label, including the bundle name, module name, and ID of the resource.|
| descriptionResource       | [Resource](#resource20) | Yes| No| Resource information of the application description, including the bundle name, module name, and ID of the resource.|
| appDistributionType       | string                                                       | Yes  | No  | Distribution type of the application signing certificate. The options are:<br> - **app_gallery**: application distributed by AppGallery.<br> - **enterprise**: enterprise application that can be installed on personal devices.<br> - **enterprise_mdm**: enterprise MDM application, which can be installed only on enterprise devices. The applications of this type must have device management privileges, such as remote locking devices and installing common enterprise applications on devices.<br> - **enterprise_normal**: common enterprise application, which can be installed on enterprise devices only through an enterprise MDM application. The applications of this type do not require device management privileges.<br> - **os_integration**: preset application in the system.<br> - **crowdtesting**: Crowdtesting application.<br> - **internaltesting**: application under internal testing of AppGallery.<br> - **none**: others.|
| appProvisionType          | string                                                       | Yes  | No  | Type of the application signing certificate file. The options are:<br> - **debug**: debug type.<br> - **release**: release type.|
| systemApp          | boolean                                                       | Yes  | No  | Whether the application is a system application. The value **true** means that the application is a system application, and **false** means the opposite.|
| debug       | boolean                                | Yes  | No  | Whether the application is running in debug mode. The value **true** means that the application is running in debug mode, and **false** means the opposite.|
| dataUnclearable       | boolean                      | Yes  | No  | Whether the application data is unclearable. The value **true** means that the application data is unclearable, and **false** means the opposite.|
| nativeLibraryPath | string                                                                     | Yes  | No  | Local library file path of the application.                                                 |
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
