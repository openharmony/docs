# @ohos.enterprise.bundleManager (Bundle Management)

The **bundleManager** module provides APIs for bundle management, including adding, obtaining, and removing a list of bundles that are allowed to install.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is enabled.

## Modules to Import

```ts
import { bundleManager } from '@kit.MDMKit';
```

## bundleManager.addAllowedInstallBundlesSync

addAllowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Adds the applications that can be installed by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

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
let appIds: Array<string> = ['com.example.myapplication'];

try {
  bundleManager.addAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding allowed install bundles.');
} catch (err) {
  console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeAllowedInstallBundlesSync

removeAllowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Removes the applications that can be installed by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to remove.                                                |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

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
let appIds: Array<string> = ['com.example.myapplication'];

try {
  bundleManager.removeAllowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing allowed install bundles.');
} catch (err) {
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getAllowedInstallBundlesSync

getAllowedInstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

Obtains the applications that can be installed by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | Applications that can be installed by the user.|

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

Adds the applications that cannot be installed by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

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
let appIds: Array<string> = ['com.example.myapplication'];

try {
  bundleManager.addDisallowedInstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in adding disallowed install bundles.');
} catch (err) {
  console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.removeDisallowedInstallBundlesSync

removeDisallowedInstallBundlesSync(admin: Want, appIds: Array&lt;string&gt;, accountId?: number): void

Removes the applications that cannot be installed by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to remove.                                                |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

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
let appIds: Array<string> = ['com.example.myapplication'];

try {
  bundleManager.removeDisallowedInstallBundlesSync(wantTemp, appIds, 100)
  console.info('Succeeded in removing disallowed install bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedInstallBundlesSync

getDisallowedInstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

Obtains the applications that cannot be installed by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                          |
| ------------------- | ------------------------------ |
| Array&lt;string&gt; | Applications that cannot be installed by the user.|

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

Adds the applications that cannot be uninstalled by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                                |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

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
let appIds: Array<string> = ['com.example.myapplication'];

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
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to remove.                                                |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

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
let appIds: Array<string> = ['com.example.myapplication'];

try {
  bundleManager.removeDisallowedUninstallBundlesSync(wantTemp, appIds, 100);
  console.info('Succeeded in removing disallowed uninstall bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## bundleManager.getDisallowedUninstallBundlesSync

getDisallowedUninstallBundlesSync(admin: Want, accountId?: number): Array&lt;string&gt;

Obtains the applications that cannot be uninstalled by the current or specified user through the specified device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **accountId** is passed in, this API applies to the specified user.<br>- If **accountId** is not passed in, this API applies to the current user.|

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

Uninstalls an application of the current or specified user through the specified device administrator application. The **isKeepData** parameter specifies whether to retain the bundle data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.                                              |
| bundleName | string                                                  | Yes  | Name of the bundle to uninstall.                                                      |
| userId     | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **userId** is passed in, this API applies to the specified user.<br>- If **userId** is not passed in, this API applies to the current user.|
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

Installs applications through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.        |
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

## InstallParam

Defines the parameters for application installation.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| userId      | number | No  | User ID, which must be greater than or equal to 0. The default value is the user ID of the caller.   |
| installFlag | number | No  | Installation flag.<br>- **0**: initial installation.<br>- **1**: overwrite installation.<br>- **2**: installation-free.<br>Default value: **0**|
