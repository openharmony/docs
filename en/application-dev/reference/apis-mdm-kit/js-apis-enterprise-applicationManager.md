# @ohos.enterprise.applicationManager (Application Management)

The **applicationManager** module provides application management capabilities, including adding, removing, and obtaining the applications that are forbidden to run.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md). The [applicationManager.isAppKioskAllowed](#applicationmanagerisappkioskallowed20) API is available to all applications.
>

## Modules to Import

```ts
import { applicationManager } from '@kit.MDMKit';
```

## applicationManager.addDisallowedRunningBundlesSync

addDisallowedRunningBundlesSync(admin: Want, appIds: Array\<string>, accountId?: number): void

Adds the applications that are not allowed to run by the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                  |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
  applicationManager.addDisallowedRunningBundlesSync(wantTemp, appIds);
  console.info('Succeeded in adding disallowed running bundles.');
} catch (err) {
  console.error(`Failed to add disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeDisallowedRunningBundlesSync

removeDisallowedRunningBundlesSync(admin: Want, appIds:  Array\<string>, accountId?: number): void

Removes the applications that are not allowed to run by the current user or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.                                  |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
  applicationManager.removeDisallowedRunningBundlesSync(wantTemp, appIds);
  console.info('Succeeded in removing disallowed running bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getDisallowedRunningBundlesSync

getDisallowedRunningBundlesSync(admin: Want, accountId?: number): Array&lt;string>

Obtains applications that are not allowed to run by the current user or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| accountId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the user ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | Applications that are not allowed to run by the current user or a specified user.|

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
  let result: Array<string> = applicationManager.getDisallowedRunningBundlesSync(wantTemp);
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addAutoStartApps

addAutoStartApps(admin: Want, autoStartApps: Array\<Want>): void

Adds the auto-start applications. Currently, this capability supports only 2-in-1 devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility.                        |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | Yes  | Auto-start applications to add. The maximum array length is 10.|

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
let autoStartApps: Array<Want> = [
  {
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility',
  }
];

try {
  applicationManager.addAutoStartApps(wantTemp, autoStartApps);
  console.info(`Succeeded in adding auto start applications.`);
} catch(err) {
  console.error(`Failed to add auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.removeAutoStartApps

removeAutoStartApps(admin: Want, autoStartApps: Array\<Want>): void

Removes the auto-start applications. Currently, this capability supports only 2-in-1 devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name       | Type                                                        | Mandatory| Description            |
| ------------- | ------------------------------------------------------------ | ---- | ---------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility.  |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | Yes  | Auto-start applications to remove.|

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
let autoStartApps: Array<Want> = [
  {
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility',
  }
];

try {
  applicationManager.removeAutoStartApps(wantTemp, autoStartApps);
  console.info(`Succeeded in removing auto start applications.`);
} catch(err) {
  console.error(`Failed to remove auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getAutoStartApps

getAutoStartApps(admin: Want): Array\<Want>

Queries the auto-start applications. Currently, this capability supports only 2-in-1 devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | List of the auto-start applications obtained.|

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
  let res: Array<Want> = applicationManager.getAutoStartApps(wantTemp);
  console.info(`Succeeded in adding auto start apps: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to auto start apps. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.addKeepAliveApps<sup>14+</sup>

addKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number): void

Adds applications to be kept alive. Currently, this feature is available only for 2-in-1 devices. If applications are disallowed to run by calling [addDisallowedRunningBundlesSync](#applicationmanageradddisallowedrunningbundlessync), they cannot be kept alive. Otherwise, a conflict occurs.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Application bundle name array, which specifies the applications to be kept alive. A maximum of five applications are supported.                                  |
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the user ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9201005  | Add keep alive applications failed. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.addKeepAliveApps(wantTemp, bundleNames, 100);
  console.info('Succeeded in adding keep alive apps.');
} catch (err) {
  console.error(`Failed to add keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeKeepAliveApps<sup>14+</sup>

removeKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number): void

Removes applications to be kept alive. Currently, this feature is available only for 2-in-1 devices.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Application bundle name array, which specifies the applications to be kept alive. A maximum of five applications are supported.                                  |
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the user ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.removeKeepAliveApps(wantTemp, bundleNames, 100);
  console.info('Succeeded in removing keep alive apps.');
} catch (err) {
  console.error(`Failed to remove keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getKeepAliveApps<sup>14+</sup>

getKeepAliveApps(admin: Want, accountId: number): Array&lt;string>

Application bundle name array, which specifies the applications to be kept alive. A maximum of five applications are supported.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| accountId | number                                                  | Yes  | User ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | Bundle name of the application kept alive for the specified user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: Array<string> = applicationManager.getKeepAliveApps(wantTemp, 100);
  console.info('Succeeded in getting keep alive apps.');
} catch (err) {
  console.error(`Failed to get keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.clearUpApplicationData<sup>20+</sup>

clearUpApplicationData(admin: Want, bundleName: string, appIndex: number, accountId: number): void

Clears all application data.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------  | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| bundleName | string                                                  | Yes  | Bundle name of the application whose data needs to be cleared.|
| appIndex | number                                                    | Yes  | Index of the application clone. The value is an integer greater than or equal to 0.<br> You can call [getAppCloneIdentity](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetappcloneidentity14) of @ohos.bundle.bundleManager to obtain the index.|
| accountId | number                                                   | Yes  | User ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { applicationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleName: string = 'com.example.exampleapplication';

try {
  applicationManager.clearUpApplicationData(wantTemp, bundleName, 0, 100);
  console.info('Succeeded in clear up application data.');
} catch (err) {
  console.error(`Failed to clear up application data. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.setAllowedKioskApps<sup>20+</sup>

setAllowedKioskApps(admin: Want, bundleNames: Array&lt;string&gt;): void

Sets applications allowed to run in kiosk mode.

Kiosk mode is a system-level runtime mode that restricts a device to a single application or a set of applications. It controls the lock screen, status bar, gestures, and key features to prevent users from launching other applications or performing other operations on the device.

**Required permissions**: ohos.permission.ENTERPRISE_SET_KIOSK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                              |
| bundleNames | Array&lt;string&gt;                                   | Yes  | Bundle names of applications allowed to run in kiosk mode. If the setting is repeated, the new arrays will replace the old ones, with a maximum of 200 arrays permitted.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { applicationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility',
};

try {
  let bundleNames: Array<string> = ['com.example.test'];
  applicationManager.setAllowedKioskApps(wantTemp, bundleNames);
  console.info('Succeeded in setting allowed kiosk apps.');
} catch (err) {
  console.error(`Failed to set allowed kiosk apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getAllowedKioskApps<sup>20+</sup>

getAllowedKioskApps(admin: Want): Array&lt;string&gt;

Obtains the applications allowed to run in kiosk mode.

**Required permissions**: ohos.permission.ENTERPRISE_SET_KIOSK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | Bundle names of applications allowed to run in kiosk mode.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { applicationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.edmtest',
  abilityName: 'com.example.edmtest.EnterpriseAdminAbility',
};

try {
  let bundleNames: Array<string> = applicationManager.getAllowedKioskApps(wantTemp);
  console.info(`Succeeded in getting allowed kiosk apps, bundleNames: ${JSON.stringify(bundleNames)}`);
} catch (err) {
  console.error(`Failed to get allowed kiosk apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.isAppKioskAllowed<sup>20+</sup>

isAppKioskAllowed(bundleName: string): boolean

Checks whether an application is allowed to run in kiosk mode.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName | string                                                 | Yes  | Bundle name of the application.                                      |

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| boolean    | The value **true** means the application can run in kiosk mode; the value **false** means the opposite.|

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';

try {
  let isAllowed: boolean = applicationManager.isAppKioskAllowed('com.example.test');
  console.info(`Succeeded in querying if the app is allowed kiosk, isAllowed: ${isAllowed}`);
} catch (err) {
  console.error(`Failed to query if the app is allowed kiosk. Code is ${err.code}, message is ${err.message}`);
}
```
