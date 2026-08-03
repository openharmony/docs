# @ohos.enterprise.bundleManager (Bundle Management) (System API)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **bundleManager** module provides APIs for bundle management, including adding, obtaining, and removing a list of bundles that are allowed to install.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module are available only to [MDM applications](../../mdm/mdm-kit-term.md#mdm-application-device-administrator-application), and can be called only after the device administrator application is activated via [enableAdmin](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2).
> 
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.bundleManager](js-apis-enterprise-bundleManager.md).

## Modules to Import

```ts
import { bundleManager } from '@kit.MDMKit';
```

## bundleManager.addAllowedInstallBundles<sup>(deprecated)</sup>

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that can be installed by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageraddallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed. |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.addAllowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding allowed install bundles');
});
```

## bundleManager.addAllowedInstallBundles<sup>(deprecated)</sup>

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that can be installed by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageraddallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.   |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding allowed install bundles');
});
```

## bundleManager.addAllowedInstallBundles<sup>(deprecated)</sup>

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Adds the applications that can be installed by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageraddallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.       |
| userId     | number                             | No   |User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in adding allowed install bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to add allowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.removeAllowedInstallBundles<sup>(deprecated)</sup>

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that can be installed by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremoveallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.    |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing allowed install bundles');
});
```

## bundleManager.removeAllowedInstallBundles<sup>(deprecated)</sup>

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that can be installed by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremoveallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.     |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing allowed install bundles');
});
```

## bundleManager.removeAllowedInstallBundles<sup>(deprecated)</sup>

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Removes the applications that can be installed by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremoveallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;         | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.                 |
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in removing allowed install bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to remove allowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getAllowedInstallBundles<sup>(deprecated)</sup>

getAllowedInstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that can be installed by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.getAllowedInstallBundles(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getAllowedInstallBundles<sup>(deprecated)</sup>

getAllowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that can be installed by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.getAllowedInstallBundles(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getAllowedInstallBundles<sup>(deprecated)</sup>

getAllowedInstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of applications that are allowed to be installed by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getAllowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the applications that can be installed by the current or specified user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.getAllowedInstallBundles(wantTemp, 100).then((result) => {
  console.info(`Succeeded in getting allowed install bundles, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get allowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.addDisallowedInstallBundles<sup>(deprecated)</sup>

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that cannot be installed by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.   |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed install bundles');
});
```

## bundleManager.addDisallowedInstallBundles<sup>(deprecated)</sup>

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that cannot be installed by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.     |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed install bundles');
});
```

## bundleManager.addDisallowedInstallBundles<sup>(deprecated)</sup>

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Adds the applications that are not allowed to be installed by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.                 |
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in adding disallowed install bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to add disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.removeDisallowedInstallBundles<sup>(deprecated)</sup>

removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that cannot be installed by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremovedisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.        |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed install bundles');
});
```

## bundleManager.removeDisallowedInstallBundles<sup>(deprecated)</sup>

removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that cannot be installed by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremovedisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed install bundles');
});
```

## bundleManager.removeDisallowedInstallBundles<sup>(deprecated)</sup>

removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Removes the applications that cannot be installed by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremovedisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;        | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.       |
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in removing disallowed install bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to remove disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getDisallowedInstallBundles<sup>(deprecated)</sup>

getDisallowedInstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that cannot be installed by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetdisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.getDisallowedInstallBundles(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedInstallBundles<sup>(deprecated)</sup>

getDisallowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that cannot be installed by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetdisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.getDisallowedInstallBundles(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedInstallBundles<sup>(deprecated)</sup>

getDisallowedInstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of applications that are not allowed to be installed by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDisallowedInstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetdisallowedinstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the applications that cannot be installed by the current or specified user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.getDisallowedInstallBundles(wantTemp, 100).then((result) => {
  console.info(`Succeeded in getting disallowed install bundles, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get disallowed install bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.addDisallowedUninstallBundles<sup>(deprecated)</sup>

addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that cannot be uninstalled by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed uninstall bundles');
});
```

## bundleManager.addDisallowedUninstallBundles<sup>(deprecated)</sup>

addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that cannot be uninstalled by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed uninstall bundles');
});
```

## bundleManager.addDisallowedUninstallBundles<sup>(deprecated)</sup>

addDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Adds the applications that cannot be uninstalled by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: From API version 21 onwards, the **appId** and **appIdentifier** of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.          |
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

bundleManager.addDisallowedUninstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in adding disallowed uninstall bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to add disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.removeDisallowedUninstallBundles<sup>(deprecated)</sup>

removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that cannot be uninstalled by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremovedisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.        |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed uninstall bundles');
});
```

## bundleManager.removeDisallowedUninstallBundles<sup>(deprecated)</sup>

removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that cannot be uninstalled by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremovedisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.           |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed uninstall bundles');
});
```

## bundleManager.removeDisallowedUninstallBundles<sup>(deprecated)</sup>

removeDisallowedUninstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Removes the applications that cannot be uninstalled by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [removeDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagerremovedisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| appIds    | Array&lt;string&gt;        | Yes   | Application IDs.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.                 |
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
// Replace with actual values.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

bundleManager.removeDisallowedUninstallBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in removing disallowed uninstall bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to remove disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.getDisallowedUninstallBundles<sup>(deprecated)</sup>

getDisallowedUninstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that cannot be uninstalled by the current user. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetdisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.getDisallowedUninstallBundles(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedUninstallBundles<sup>(deprecated)</sup>

getDisallowedUninstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that cannot be uninstalled by the user specified by **userId**. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetdisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.getDisallowedUninstallBundles(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
});
```

## bundleManager.getDisallowedUninstallBundles<sup>(deprecated)</sup>

getDisallowedUninstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of applications that are not allowed to be uninstalled by the current or specified user. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanagergetdisalloweduninstallbundlessync)

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the applications that cannot be uninstalled by the current or specified user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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

bundleManager.getDisallowedUninstallBundles(wantTemp, 100).then((result) => {
  console.info(`Succeeded in getting disallowed uninstall bundles, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get disallowed uninstall bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## bundleManager.uninstall<sup>(deprecated)</sup>

uninstall(admin: Want, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Uninstalls an application of the current user without retaining the bundle data. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [uninstall](./js-apis-enterprise-bundleManager.md#bundlemanageruninstall)

> **NOTE**
>
> Error code **401** will be returned if this API is called to uninstall an application that is either a non-removable pre-installed application or one configured as non-uninstallable via the [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync) API.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| bundleName     | string                             | Yes   | Name of the bundle to uninstall.|
| callback | AsyncCallback&lt;void&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.uninstall(wantTemp, 'bundleName', (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.uninstall<sup>(deprecated)</sup>

uninstall(admin: Want, bundleName: string, userId: number, callback: AsyncCallback&lt;void&gt;): void

Uninstalls an application of the specified user without retaining the bundle data This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [uninstall](./js-apis-enterprise-bundleManager.md#bundlemanageruninstall)

> **NOTE**
>
> Error code **401** will be returned if this API is called to uninstall an application that is either a non-removable pre-installed application or one configured as non-uninstallable via the [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync) API.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| bundleName     | string                             | Yes   | Name of the bundle to uninstall.|
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.uninstall(wantTemp, 'bundleName', 100, (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.uninstall<sup>(deprecated)</sup>

uninstall(admin: Want, bundleName: string, isKeepData: boolean, callback: AsyncCallback&lt;void&gt;): void

Uninstalls an application of the current user. The **isKeepData** parameter specifies whether to retain the bundle data. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [uninstall](./js-apis-enterprise-bundleManager.md#bundlemanageruninstall)

> **NOTE**
>
> Error code **401** will be returned if this API is called to uninstall an application that is either a non-removable pre-installed application or one configured as non-uninstallable via the [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync) API.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| bundleName     | string                             | Yes   | Name of the bundle to uninstall.|
| isKeepData     | boolean                             | Yes   | Whether to retain the bundle data. The value **true** means to retain the bundle data; the value **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.uninstall(wantTemp, 'bundleName', true, (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.uninstall<sup>(deprecated)</sup>

uninstall(admin: Want, bundleName: string, userId: number, isKeepData: boolean, callback: AsyncCallback&lt;void&gt;): void

Uninstalls an application of the specified user. The **isKeepData** parameter specifies whether to retain the bundle data. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [uninstall](./js-apis-enterprise-bundleManager.md#bundlemanageruninstall)

> **NOTE**
>
> Error code **401** will be returned if this API is called to uninstall an application that is either a non-removable pre-installed application or one configured as non-uninstallable via the [addDisallowedUninstallBundlesSync](./js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync) API.

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| bundleName     | string                             | Yes   | Name of the bundle to uninstall.|
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| isKeepData     | boolean                             | Yes   | Whether to retain the bundle data. The value **true** means to retain the bundle data; the value **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { bundleManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

bundleManager.uninstall(wantTemp, 'bundleName', 100, true, (err) => {
  if (err) {
    console.error(`Failed to uninstall bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in uninstalling bundles');
});
```

## bundleManager.install<sup>(deprecated)</sup>

install(admin: Want, hapFilePaths: Array\<string>, callback: AsyncCallback\<void>): void

Installs specified applications. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [install](./js-apis-enterprise-bundleManager.md#bundlemanagerinstall)

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| hapFilePaths     | Array\<string>                           | Yes   | Applications to install.|
| callback | AsyncCallback&lt;void&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                |
| 9201002 | Failed to install the application. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];

bundleManager.install(wantTemp, hapFilePaths, (err) => {
  if (err) {
    console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in installing bundles');
});
```

## bundleManager.install<sup>(deprecated)</sup>

install(admin: Want, hapFilePaths: Array\<string>, installParam: InstallParam, callback: AsyncCallback\<void>): void

Installs applications with specified parameters. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [install](./js-apis-enterprise-bundleManager.md#bundlemanagerinstall)

**Required permissions**: ohos.permission.ENTERPRISE_INSTALL_BUNDLE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| hapFilePaths     | Array\<string>                       | Yes   | Applications to install.|
| installParam     | [InstallParam](js-apis-enterprise-bundleManager.md#installparam) | Yes   | Application installation parameters.|
| callback | AsyncCallback&lt;void&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                  |
| 9200002 | The administrator application does not have permission to manage the device.                                |
| 9201002 | Failed to install the application. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

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
let hapFilePaths: Array<string> = ['/data/storage/el2/base/haps/entry/testinstall/ExtensionTest.hap'];
let installParam: bundleManager.InstallParam = {
  userId: 100,
  installFlag: 1,
};

bundleManager.install(wantTemp, hapFilePaths, installParam, (err) => {
  if (err) {
    console.error(`Failed to install bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in installing bundles');
});
```
