# @ohos.enterprise.applicationManager (Application Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides application management capabilities, including managing the application running blocklist, application running trustlist, auto-startup application list, keep-alive application list, non-stoppable application list, background freeze-exempt application list, notification trustlist, and cross-device application trustlist. It is suitable for enterprise device management scenarios, enabling control over application running permissions, auto-startup management, keep-alive application management, and more, thereby enhancing enterprise device security and compliance.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md). The [applicationManager.isAppKioskAllowed](#applicationmanagerisappkioskallowed20) API is available to all applications.
>

## Modules to Import

```ts
import { applicationManager } from '@kit.MDMKit';
```

## applicationManager.addDisallowedRunningBundlesSync

addDisallowedRunningBundlesSync(admin: Want, appIds: Array\<string>, accountId?: number): void

Adds applications to the application running blocklist. Applications added to the blocklist are not allowed to run under the current or specified user. Since API version 21, if the application running trustlist [addAllowedRunningBundles](#applicationmanageraddallowedrunningbundles21) is not empty, the application running blocklist cannot be added via this API. Otherwise, the error code 9200010 is reported.

> **NOTE**
>
> If a specified application is running, the system will immediately terminate the application process once it is added to the blocklist.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.<br>**Note**: From API version 21 onwards, the [appId](../../quick-start/common-problem-of-application.md#what-is-appid) and [appIdentifier](../../quick-start/common-problem-of-application.md#what-is-appidentifier) of the app can be passed. **appIdentifier** is recommended. In API version 20 and earlier versions, only **appId** can be passed.<br>Value range:<br> The total number of entries in this list for a single user must not exceed 200. For example, if 50 entries have been set for user 100 and none for user 101, user 100 can add 150 more entries, while user 101 can add up to 200 entries.|
| accountId | number                                                  | No  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. <br>Applicable versions: 21+|
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
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

Removes applications from the application running blocklist of the current or specified user. After an application is removed, it is allowed to run under the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIds    | Array&lt;string&gt;                                     | Yes  | IDs of the applications to add.<br>Note: Since API version 21, elements in the array can use **appId** and **appIdentifier**. Only the input **appId** or **appIdentifier** is removed. **appIdentifier** or **appId** of the same app will not be removed. In API version 20 and earlier versions, only **appId** can be transferred.|
| accountId | number                                                  | No  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let appIds: Array<string> = ['com.example.******_******/******5t5CoBM='];

try {
  applicationManager.removeDisallowedRunningBundlesSync(wantTemp, appIds);
  console.info('Succeeded in removing disallowed running bundles.');
} catch (err) {
  console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getDisallowedRunningBundlesSync

getDisallowedRunningBundlesSync(admin: Want | null, accountId?: number): Array&lt;string>

Obtains the application running blocklist of the current user or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|
| accountId | number                                                  | No  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.<br> - If **accountId** is passed in, this API applies to the specified user.<br> - If **accountId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | Application running blocklist of the current user or specified user.<br>Note: For API version 20 and earlier versions, the return value is the **appId** list. In API version 21 and later versions, the return value is the **appId** or **appIdentifier** list.|

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<string> = applicationManager.getDisallowedRunningBundlesSync(wantTemp);
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addAllowedRunningBundles<sup>21+</sup>

addAllowedRunningBundles(admin: Want, appIdentifiers: Array\<string>, accountId: number): void

Adds applications to the application running trustlist. Only applications in the trustlist are allowed to run under the specified user.

> **NOTE**
>
> 1. Most APIs provided by MDM Kit are available only to MDM applications. When using this API, add the MDM application to the application running trustlist. Otherwise, the MDM application will be prohibited from running, blocking the API call. For details about whether the API is open only to MDM applications, see the module description.
>
> 2. If the application running blocklist is not empty, this API cannot be used to add applications to the running trustlist. Otherwise, the error code 9200010 is reported. APIs related to the application running blocklist include [addDisallowedRunningBundlesSync](#applicationmanageradddisallowedrunningbundlessync)<!--Del-->, [addDisallowedRunningBundles](./js-apis-enterprise-applicationManager-sys.md#applicationmanageradddisallowedrunningbundlesdeprecated), [addDisallowedRunningBundles](./js-apis-enterprise-applicationManager-sys.md#applicationmanageradddisallowedrunningbundlesdeprecated-1), and [addDisallowedRunningBundles](./js-apis-enterprise-applicationManager-sys.md#applicationmanageradddisallowedrunningbundlesdeprecated-2)<!--DelEnd-->.
>
> 3. This API only takes effect for third-party applications. System applications are not subject to this list and are allowed to run by default.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIdentifiers    | Array&lt;string&gt;                             | Yes  | Array of application [unique identifiers](../../quick-start/common-problem-of-application.md#what-is-appidentifier). You can obtain **bundleInfo.signatureInfo.appIdentifier** through the [bundleManager.getInstalledBundleList](./js-apis-enterprise-bundleManager.md#bundlemanagergetinstalledbundlelist20) API.<br>Value range:<br> - The total number of entries in this list for a single user must not exceed 200. For example, if 50 entries have been set for user 100 and none for user 101, user 100 can add 150 more entries, while user 101 can add up to 200 entries.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let appIdentifiers: Array<string> = ['0123456789123456789'];

try {
  applicationManager.addAllowedRunningBundles(wantTemp, appIdentifiers, 100);
  console.info('Succeeded in adding allowed running bundles.');
} catch (err) {
  console.error(`Failed to add allowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeAllowedRunningBundles<sup>21+</sup>

removeAllowedRunningBundles(admin: Want, appIdentifiers: Array\<string>, accountId: number): void

Removes applications from the application running trustlist of the specified user. After an application is removed, it is not allowed to run under the current or specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIdentifiers    | Array&lt;string&gt;                             | Yes  | Array of unique identifiers of an app. You can obtain **bundleInfo.signatureInfo.appIdentifier** through the [bundleManager.getInstalledBundleList](./js-apis-enterprise-bundleManager.md#bundlemanagergetinstalledbundlelist20) API. Value range: The array length cannot exceed 200.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let appIdentifiers: Array<string> = ['0123456789123456789'];

try {
  applicationManager.removeAllowedRunningBundles(wantTemp, appIdentifiers, 100);
  console.info('Succeeded in removing allowed running bundles.');
} catch (err) {
  console.error(`Failed to remove allowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getAllowedRunningBundles<sup>21+</sup>

getAllowedRunningBundles(admin: Want | null, accountId: number): Array&lt;string>

Obtains the application running trustlist of a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | List of applications allowed to run by a specified user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<string> = applicationManager.getAllowedRunningBundles(wantTemp, 100);
  console.info(`Succeeded in getting allowed running bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed running bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addAutoStartApps

addAutoStartApps(admin: Want, autoStartApps: Array\<Want>): void

Adds the auto-start applications for the current user. Applications added to the auto-start list via this API cannot be manually disabled for auto-start by users on the device<!--RP4--><!--RP4End-->. However, they can be removed from the auto-start list using the [removeAutoStartApps](#applicationmanagerremoveautostartapps) API.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: For API version 20 and earlier versions, this API can be properly called on PCs/2-in-1 devices and does not work on other devices. This API can be used on phones, tablets, PCs/2-in-1 devices since API version 21. Since API version 24, this API allows you to configure whether to hide the UI when applications automatically start upon device startup. This capability is available only on PCs/2-in-1 devices and tablets in PC mode.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                        |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | Yes  | Array of auto-start applications. The maximum array length is 10. For example, if there are already 5 applications in the list, a maximum of 5 more can be added via this API. **Want** must contain **bundleName** and **abilityName**. The ability can be UIAbility or ServiceExtensionAbility. If the value of **exported** in the [abilities](../../quick-start/module-configuration-file.md#abilities) tag is **false**, the ability cannot be started. Since API version 24, you can specify whether to hide the UI when applications automatically start upon device startup by setting **isHiddenStart** in the **parameters** attribute of Want. The value **true** indicates that yes, and the value **false** indicates no. The default value is **false**. If the **true** value is used, the applications must be <!--RP8-->integrated with the status bar<!--RP8End-->. Otherwise, the auto-start setting fails. (If only one application is set to hide the UI upon auto-start but the application is not integrated with the status bar, error 401 is reported. This API returns success as long as one application is successfully set.) After the setting is successful, the applications do not display the UI but their UI processes exist. The capability of hiding the UI is available only on PCs/2-in-1 devices and tablets in PC mode.|

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let autoStartApps: Array<Want> = [
  {
    // Replace it as required.
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility',
    // The following parameters are optional.
    parameters: {
      // Since API version 24, you can configure whether to hide the UI when applications automatically start upon device startup. The value true indicates yes. If this parameter is set to true, the applications must be integrated with the status bar. Otherwise, the automatic startup setting fails and error 401 is reported.
      isHiddenStart: true 
    }
  }
];

try {
  applicationManager.addAutoStartApps(wantTemp, autoStartApps);
  console.info('Succeeded in adding auto start applications.');
} catch(err) {
  console.error(`Failed to add auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.removeAutoStartApps

removeAutoStartApps(admin: Want, autoStartApps: Array\<Want>): void

Removes the auto-start applications for the current user. After the deletion, the applications will no longer automatically start upon system boot.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: For API version 20 and earlier versions, this API can be properly called on PCs/2-in-1 devices and does not work on other devices. This API can be used on phones, tablets, PCs/2-in-1 devices since API version 21.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description            |
| ------------- | ------------------------------------------------------------ | ---- | ---------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.  |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | Yes  | Array of auto-start applications. **Want** must contain **bundleName** and **abilityName**. The ability can be UIAbility or ServiceExtensionAbility. If the value of **exported** in the [abilities](../../quick-start/module-configuration-file.md#abilities) tag is **false**, the ability cannot be started.|

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let autoStartApps: Array<Want> = [
  {
    // Replace it as required.
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility'
  }
];

try {
  applicationManager.removeAutoStartApps(wantTemp, autoStartApps);
  console.info('Succeeded in removing auto start applications.');
} catch(err) {
  console.error(`Failed to remove auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```
## applicationManager.removeAutoStartApps<sup>20+</sup>

removeAutoStartApps(admin: Want, autoStartApps: Array\<Want>, accountId: number): void

Removes the specified application from the auto-start application list of a specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: For API version 20 and earlier versions, this API can be properly called on PCs/2-in-1 devices and does not work on other devices. This API can be used on phones, tablets, PCs/2-in-1 devices since API version 21.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description            |
| ------------- | ------------------------------------------------------------ | ---- | ---------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.  |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | Yes  | Array of auto-start applications. **Want** must contain **bundleName** and **abilityName**.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
 
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let autoStartApps: Array<Want> = [
  // Replace it as required.
  {
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility'
  }
];

try {
  applicationManager.removeAutoStartApps(wantTemp, autoStartApps, 100);
  console.info('Succeeded in removing auto start applications.');
} catch(err) {
  console.error(`Failed to remove auto start applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getAutoStartApps

getAutoStartApps(admin: Want | null): Array\<Want>

Checks the auto-start applications for the current user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: For API version 20 and earlier versions, this API can be properly called on PCs/2-in-1 devices and does not work on other devices. This API can be used on phones, tablets, PCs/2-in-1 devices since API version 21.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | List of the auto-start applications obtained. Since API version 24, the setting of whether the UI is hidden can be returned.|

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let res: Array<Want> = applicationManager.getAutoStartApps(wantTemp);
  console.info(`Succeeded in adding auto start apps: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to auto start apps. Code: ${err.code}, message: ${err.message}`);
}
```
<!--code_no_check-->
```ts
// Return value example.
[
  {
    "bundleName": "com.example.edmtest",
    "abilityName": "EntryAbility",
    // Supported since API version 24.
    "parameters": {
      "isHiddenStart": false
    }
  },
  // ...
]
```

## applicationManager.addAutoStartApps<sup>20+</sup>

addAutoStartApps(admin: Want, autoStartApps: Array\<Want>, accountId: number, disallowModify: boolean): void

Adds a list of applications that automatically start upon device startup for a specified user, and sets whether to prohibit the user from manually canceling application auto-start<!--RP4--><!--RP4End-->.<br>Applications can be added to the auto-start list via this API and the [addAutoStartApps](#applicationmanageraddautostartapps) API. Settings from both APIs can take effect simultaneously. For a single user, the auto-start list supports a maximum of 10 applications. For example, if there are already 3 applications in the current list, a maximum of 7 more can be added for the user via this API.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: For API version 20 and earlier versions, this API can be properly called on PCs/2-in-1 devices and does not work on other devices. This API can be used on phones, tablets, PCs/2-in-1 devices since API version 21. Since API version 24, this API allows you to configure whether to hide the UI when applications automatically start upon device startup. This capability is available only on PCs/2-in-1 devices and tablets in PC mode.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                        |
| autoStartApps | Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | Yes  | Array of auto-start applications. The array can contain a maximum of 10 applications. **Want** must contain **bundleName** and **abilityName**. The ability can be UIAbility or ServiceExtensionAbility. If the value of **exported** in the [abilities](../../quick-start/module-configuration-file.md#abilities) tag is **false**, the ability cannot be started. Since API version 24, you can specify whether to hide the UI when applications automatically start upon device startup by setting **isHiddenStart** in the **parameters** attribute of Want. The value **true** indicates that yes, and the value **false** indicates no. The default value is **false**. If the **true** value is used, the applications must be <!--RP8-->integrated with the status bar<!--RP8End-->. Otherwise, the auto-start setting fails. (If only one application is set to hide the UI upon auto-start but the application is not integrated with the status bar, error 401 is reported. This API returns success as long as one application is successfully set.) After the setting is successful, the applications do not display the UI but their UI processes exist. The capability of hiding the UI is available only on PCs/2-in-1 devices and tablets in PC mode.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| disallowModify | boolean | Yes  | Whether to prohibit the user from manually disabling application auto-start. The value **true** indicates yes and the value **false** indicates no.<!--RP1--><!--RP1End-->|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let autoStartApps: Array<Want> = [
  // Replace it as required.
  {
    bundleName: 'com.example.autoStartApplication',
    abilityName: 'EntryAbility',
    // The following parameters are optional.
    parameters: {
      // Since API version 24, you can configure whether to hide the UI when applications automatically start upon device startup. The value true indicates yes. If this parameter is set to true, the applications must be integrated with the status bar. Otherwise, the automatic startup setting fails and error 401 is reported.
      isHiddenStart: true 
    }
  }
];

try {
  applicationManager.addAutoStartApps(wantTemp, autoStartApps, 100, true);
  console.info('Succeeded in adding auto start applications and set disallowModify.');
} catch(err) {
  console.error(`Failed to add auto start applications and set disallowModify. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getAutoStartApps<sup>20+</sup>

getAutoStartApps(admin: Want | null, accountId: number): Array\<Want>

Checks the auto-start applications for the specified user.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: For API version 20 and earlier versions, this API can be properly called on PCs/2-in-1 devices and does not work on other devices. This API can be used on phones, tablets, PCs/2-in-1 devices since API version 21.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | List of the auto-start applications obtained. Since API version 24, the setting of whether the UI is hidden can be returned.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let res: Array<Want> = applicationManager.getAutoStartApps(wantTemp, 100);
  console.info(`Succeeded in getting auto start apps: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to get auto start apps. Code: ${err.code}, message: ${err.message}`);
}
```
<!--code_no_check-->
```ts
// Return value example.
[
  {
    "bundleName": "com.example.edmtest",
    "abilityName": "EntryAbility",
    // Supported since API version 24.
    "parameters": {
      "isHiddenStart": false
    }
  },
  // ...
]
```

## applicationManager.isModifyAutoStartAppsDisallowed<sup>20+</sup>

isModifyAutoStartAppsDisallowed(admin: Want, autoStartApp: Want, accountId: number): boolean

Checks whether a specified user is prohibited from canceling application auto-start.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: For API version 20 and earlier versions, this API can be properly called on PCs/2-in-1 devices and does not work on other devices. This API can be used on phones, tablets, PCs/2-in-1 devices since API version 21.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| autoStartApp | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Auto-start applications to add. **Want** must contain **bundleName** and **abilityName**.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| boolean | Whether the user is prohibited from canceling application auto-startup. The value **true** indicates yes and the value **false** indicates no.<!--RP1--><!--RP1End-->|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let autoStartApp: Want = {
  // Replace it as required.
  bundleName: 'com.example.autoStartApplication',
  abilityName: 'EntryAbility'
};

try {
  let res: boolean = applicationManager.isModifyAutoStartAppsDisallowed(wantTemp, autoStartApp, 100);
  console.info(`Succeeded in getting disallow modify auto start app: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to get disallow modify auto start app. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.addKeepAliveApps<sup>14+</sup>

addKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number): void

Adds applications to the keep-alive list; once added, the application processes will be kept alive automatically. After the device is powered on or the application is killed, the system will proactively restart these application processes.<!--RP7--><!--RP7End--><br>For applications added to the keep-alive list via this API, users cannot manually revoke their keep-alive status on the device <!--RP6--><!--RP6End-->. However, you can call the [removeKeepAliveApps](#applicationmanagerremovekeepaliveapps14) API to remove them from the keep-alive list.<br>If applications are disallowed to run by calling [addDisallowedRunningBundlesSync](#applicationmanageradddisallowedrunningbundlessync), they cannot be kept alive. Otherwise, error code 9200010 will be reported.<br>To use similar functions on phones or tablets, call [addUserNonStopApps](#applicationmanageraddusernonstopapps22) or [addFreezeExemptedApps](#applicationmanageraddfreezeexemptedapps22). For details, see the relevant documents.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Array of application bundle names, which specifies the applications to be kept alive. A maximum of 5 applications are supported.<!--RP5--><!--RP5End-->                                    |
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

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
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.addKeepAliveApps(wantTemp, bundleNames, 100);
  console.info('Succeeded in adding keep alive apps.');
} catch (err) {
  console.error(`Failed to add keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addKeepAliveApps<sup>20+</sup>

addKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number, disallowModify: boolean): void

Adds applications to the keep-alive list; once added, the application processes will be kept alive automatically. You can also set whether to disable manual keep-alive cancellation. After the device is powered on or the application is killed, the system will proactively restart these application processes.<br>Applications can be added to the keep-alive list via this API and the [addKeepAliveApps](#applicationmanageraddkeepaliveapps14) API. Settings from both APIs can take effect simultaneously. For a single user, the keep-alive list supports a maximum of 5 applications. For example, if there are already 3 applications in the current list, a maximum of 2 more can be added for the user via this API.<br>If applications are disallowed to run by calling [addDisallowedRunningBundlesSync](#applicationmanageradddisallowedrunningbundlessync), they cannot be kept alive. Otherwise, error code 9200010 will be reported.<br>To use similar functions on phones or tablets, call [addUserNonStopApps](#applicationmanageraddusernonstopapps22) or [addFreezeExemptedApps](#applicationmanageraddfreezeexemptedapps22). For details, see the relevant documents.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Array of application bundle names, which specifies the applications to be kept alive. A maximum of 5 applications are supported.<br>Applications must be installed under user 1 (a user who supports single-instance running of third-party applications) and have integrated [background services](../../application-models/app-service-extension-ability.md#implementing-a-background-service)<!--RP3--><!--RP3End-->. Otherwise, the error code 9201005 will be reported. |
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| disallowModify | boolean | Yes  | Whether to restrict users from manually canceling the keep-alive status. The value **true** indicates that users are not allowed to manually cancel the keep-alive status, and the value **false** indicates the opposite.<!--RP2--><!--RP2End--> |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9201005  | Add keep alive applications failed. |
| 201  | Permission verification failed.The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace it as required.
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.addKeepAliveApps(wantTemp, bundleNames, 100, true);
  console.info('Succeeded in adding keep alive apps and set disallowModify.');
} catch (err) {
  console.error(`Failed to add keep alive apps and set disallowModify. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeKeepAliveApps<sup>14+</sup>

removeKeepAliveApps(admin: Want, bundleNames: Array\<string>, accountId: number): void

Removes a specified application from the keep-alive list.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API takes effect only on PCs/2-in-1 devices and does not work on other devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Application bundle name array, which specifies the applications to be kept alive. A maximum of five applications are supported.                                  |
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let bundleNames: Array<string> = ['com.example.myapplication'];

try {
  applicationManager.removeKeepAliveApps(wantTemp, bundleNames, 100);
  console.info('Succeeded in removing keep alive apps.');
} catch (err) {
  console.error(`Failed to remove keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getKeepAliveApps<sup>14+</sup>

getKeepAliveApps(admin: Want | null, accountId: number): Array&lt;string>

Obtains the bundle name of the keep-alive application.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API takes effect only on PCs/2-in-1 devices and does not work on other devices.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

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
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<string> = applicationManager.getKeepAliveApps(wantTemp, 100);
  console.info('Succeeded in getting keep alive apps.');
} catch (err) {
  console.error(`Failed to get keep alive apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.isModifyKeepAliveAppsDisallowed<sup>20+</sup>

isModifyKeepAliveAppsDisallowed(admin: Want, accountId: number, bundleName: string): boolean

Checks whether the application is forbidden to cancel the keep-alive status.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API takes effect only on PCs/2-in-1 devices and does not work on other devices.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description          |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| bundleName | string | Yes| Bundle name.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| boolean | Whether to restrict users from manually canceling the keep-alive status. The value **true** indicates that users are not allowed to manually cancel the keep-alive status, and the value **false** indicates the opposite.<!--RP2--><!--RP2End-->|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace it as required.
let keepAliveApp: string = 'com.example.keepAliveApplication';

try {
  let res: boolean = applicationManager.isModifyKeepAliveAppsDisallowed(wantTemp, 100, keepAliveApp);
  console.info(`Succeeded in getting disallow modify keep alive app: ${JSON.stringify(res)}`);
} catch(err) {
  console.error(`Failed to get disallow modify keep alive app. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.clearUpApplicationData<sup>20+</sup>

clearUpApplicationData(admin: Want, bundleName: string, appIndex: number, accountId: number): void

Clears all application data.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------  | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleName | string                                                  | Yes  | Bundle name of the application whose data needs to be cleared.|
| appIndex | number                                                    | Yes  | Index of the application clone. The value is an integer greater than or equal to 0.<br> You can call [getAppCloneIdentity](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetappcloneidentity14) of @ohos.bundle.bundleManager to obtain the index.|
| accountId | number                                                   | Yes  | Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

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
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let bundleName: string = 'com.example.exampleapplication';

try {
  // Replace it as required.
  applicationManager.clearUpApplicationData(wantTemp, bundleName, 0, 100);
  console.info('Succeeded in clearing up application data.');
} catch (err) {
  console.error(`Failed to clear up application data. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.setAllowedKioskApps<sup>20+</sup>

setAllowedKioskApps(admin: Want, appIdentifiers: Array&lt;string&gt;): void

Sets applications allowed to run in kiosk mode.

Kiosk mode is a system-level runtime mode that restricts a device to a single application or a set of applications. It controls the lock screen, status bar, gestures, and key features to prevent users from launching other applications or performing other operations on the device.

**Required permissions**: ohos.permission.ENTERPRISE_SET_KIOSK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIdentifiers | Array&lt;string&gt;                                   | Yes  | Array of [unique identifiers](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application. You can call the [bundleManager.getBundleInfo](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfo14-2) API to obtain the **bundleInfo.signatureInfo.appIdentifier**. In case of repeated configuration, the newly configured array will overwrite the old one, with a maximum limit of 200 entries.|

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
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace it as required.
  let appIdentifiers: Array<string> = ['6917****3569'];
  applicationManager.setAllowedKioskApps(wantTemp, appIdentifiers);
  console.info('Succeeded in setting allowed kiosk apps.');
} catch (err) {
  console.error(`Failed to set allowed kiosk apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getAllowedKioskApps<sup>20+</sup>

getAllowedKioskApps(admin: Want | null): Array&lt;string&gt;

Obtains the applications allowed to run in kiosk mode.

**Required permissions**: ohos.permission.ENTERPRISE_SET_KIOSK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | List of [unique identifiers](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application that can run in kiosk mode.|

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
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let appIdentifiers: Array<string> = applicationManager.getAllowedKioskApps(wantTemp);
  console.info(`Succeeded in getting allowed kiosk apps, appIdentifiers: ${JSON.stringify(appIdentifiers)}`);
} catch (err) {
  console.error(`Failed to get allowed kiosk apps. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.isAppKioskAllowed<sup>20+</sup>

isAppKioskAllowed(appIdentifier: string): boolean

Checks whether an application is allowed to run in kiosk mode.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| appIdentifier | string                                                 | Yes  | [Unique identifiers](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application. You can call the [bundleManager.getBundleInfo](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfo14-2) API to obtain the **bundleInfo.signatureInfo.appIdentifier**.                                      |

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| boolean    | The value **true** means the application can run in kiosk mode; the value **false** means the opposite.|

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';

try {
  // Replace it as required.
  let isAllowed: boolean = applicationManager.isAppKioskAllowed('6917****3569');
  console.info(`Succeeded in querying if the app is allowed kiosk, isAllowed: ${isAllowed}`);
} catch (err) {
  console.error(`Failed to query if the app is allowed kiosk. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.setKioskFeatures<sup>20+</sup>

setKioskFeatures(admin: Want, features: Array\<KioskFeature>): void

Sets the features of the kiosk mode. You can use this API to control whether the notification center and control panel can be accessed in kiosk mode.

Since API version 24, you can set whether to allow users to swipe up from the bottom to access the recent taskbar and swipe left or right to display the side dock.

In non-kiosk mode, this API can be called normally but does not take effect. The settings will take effect after kiosk mode is enabled.

**Required permissions**: ohos.permission.ENTERPRISE_SET_KIOSK

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Device behavior differences**: This API has no effect on PCs/2-in-1 devices, but can be properly called on phones and tablets.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                  |
| ------------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.        |
| features | Array&lt;[KioskFeature](#kioskfeature20)&gt;           | Yes  | Feature set of the Kiosk mode. (Since API version 24, swiping up from the bottom to access the recent taskbar and swiping left or right to display the side dock are supported.)<br> If an empty array is passed, the system will clear all previously delivered features and restore the kiosk mode to its default state. To be specific, abilities such as the notification center, control panel, recent task bar, and side dock are disabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. | 
| 9200012  | Parameter verification failed.                          |
| 201      | Permission verification failed.The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { applicationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let kioskFeatures: Array<applicationManager.KioskFeature> = [];
kioskFeatures.push(applicationManager.KioskFeature.ALLOW_NOTIFICATION_CENTER);
kioskFeatures.push(applicationManager.KioskFeature.ALLOW_CONTROL_CENTER);
kioskFeatures.push(applicationManager.KioskFeature.ALLOW_GESTURE_CONTROL);
kioskFeatures.push(applicationManager.KioskFeature.ALLOW_SIDE_DOCK);
try {
  applicationManager.setKioskFeatures(wantTemp, kioskFeatures);
  console.info('Succeeded in setting kiosk feature.');
} catch (err) {
  console.error(`Failed to set kiosk feature. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addUserNonStopApps<sup>22+</sup>

addUserNonStopApps(admin: Want, applicationInstances: Array&lt;common.ApplicationInstance&gt;): void

Adds applications to the non-stoppable application list for a specified user. This policy only applies to installed applications. If the parameter list contains uninstalled applications, error code 9200012 will be returned. If an application in the list is uninstalled after the policy is set, the uninstalled application will be removed from the list. Adding an application that already exists in the list will return success, but the application will not be added repeatedly to the policy list.

On phones and tablets, non-stoppable applications cannot be closed by swiping up in the task center. After a user taps the application name in **Settings** > **Apps & services** to go to the details page, the forcible stop button is unavailable, and the disable button does not take effect.

On PCs/2-in-1 devices, after a user taps the application name in **Settings** > **Apps & services** to go to the details page, the forcible stop button is unavailable, and the disable button does not take effect.

Since API version 26.0.0, if you call [setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount) to disable [SUPER_HUB](./js-apis-enterprise-restrictions.md#featureforaccount) and then call this API to add SuperHub to the non-stoppable application list, a policy conflict occurs and error code 9200010 is reported.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be called on phones and tablets but has no effect on other devices. Since API version 24, this API can be properly called on PCs/2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                        |
| applicationInstances | Array&lt;[common.ApplicationInstance](./js-apis-enterprise-common.md#applicationinstance)&gt; | Yes  | Array of non-stoppable applications. A maximum of 10 applications can be added to the non-stoppable application list. This limit is not divided among users. Specifically, the total number of such applications added by all users cannot exceed 10. For example, if there are already 3 applications in the current list, a maximum of 7 more can be added for a specified user via this API.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. <br>Applicable version: 26.0.0+|
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let applicationInstances: Array<common.ApplicationInstance> = [
  // Replace it as required.
  {
    appIdentifier: '0123456789123456789',
    accountId: 100,
    appIndex: 0
  }
];

try {
  applicationManager.addUserNonStopApps(wantTemp, applicationInstances);
  console.info('Succeeded in adding UserNonStop applications.');
} catch(err) {
  console.error(`Failed to add UserNonStop applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.removeUserNonStopApps<sup>22+</sup>

removeUserNonStopApps(admin: Want, applicationInstances: Array&lt;common.ApplicationInstance&gt;): void

Removes the non-stoppable application list for a specified user. After the removal, the user can stop the applications on the device. If the parameter list includes uninstalled applications, the removal will still succeed. Installed applications will be removed from the list, while uninstalled ones will not impact the removal process.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be called on phones and tablets but has no effect on other devices. Since API version 24, this API can be properly called on PCs/2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                        |
| applicationInstances | Array&lt;[common.ApplicationInstance](./js-apis-enterprise-common.md#applicationinstance)&gt; | Yes  | Array of non-stoppable applications.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let applicationInstances: Array<common.ApplicationInstance> = [
  // Replace it as required.
  {
    appIdentifier: '0123456789123456789',
    accountId: 100,
    appIndex: 0
  }
];

try {
  applicationManager.removeUserNonStopApps(wantTemp, applicationInstances);
  console.info('Succeeded in removing UserNonStop applications.');
} catch(err) {
  console.error(`Failed to remove UserNonStop applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getUserNonStopApps<sup>22+</sup>

getUserNonStopApps(admin: Want | null): Array&lt;common.ApplicationInstance&gt;

Obtains the non-stoppable application list of all users on the current device.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be called on phones and tablets but has no effect on other devices. Since API version 24, this API can be properly called on PCs/2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array&lt;[common.ApplicationInstance](./js-apis-enterprise-common.md#applicationinstance)&gt; | Array of non-stoppable applications.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<common.ApplicationInstance> = applicationManager.getUserNonStopApps(wantTemp);
  console.info(`Succeeded in getting UserNonStop applications, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get UserNonStop applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.addFreezeExemptedApps<sup>22+</sup>

addFreezeExemptedApps(admin: Want, applicationInstances: Array&lt;common.ApplicationInstance&gt;): void

Adds applications to the background freeze-exempt application list for a specified user. This policy applies only to installed applications. If the parameter list contains uninstalled applications, error code 9200012 will be returned. If an application in the list is uninstalled after the policy is set, the uninstalled application will be removed from the list. Adding an application that already exists in the list will return success, but the application will not be added repeatedly to the policy list.

Freezing operations include suspending the target application, and managing software resource agents, hardware resource agents, and high-power consumption.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: Before API version 26.0.0, this API is supported on phones and tablets but does not take effect on other devices. Since API version 26.0.0, this API is supported on phones, tablets, PCs/2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                        |
| applicationInstances | Array&lt;[common.ApplicationInstance](./js-apis-enterprise-common.md#applicationinstance)&gt; | Yes  | Array of the background freeze-exempt application list. A maximum of 10 applications can be added to the list. This limit is not divided among users. Specifically, the total number of such applications added by all users cannot exceed 10. For example, if there are already 3 applications in the current list, a maximum of 7 more can be added for a specified user via this API.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let applicationInstances: Array<common.ApplicationInstance> = [
  // Replace it as required.
  {
    appIdentifier: '0123456789123456789',
    accountId: 100,
    appIndex: 0
  }
];

try {
  applicationManager.addFreezeExemptedApps(wantTemp, applicationInstances);
  console.info('Succeeded in adding FreezeExempted applications.');
} catch(err) {
  console.error(`Failed to add FreezeExempted applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.removeFreezeExemptedApps<sup>22+</sup>

removeFreezeExemptedApps(admin: Want, applicationInstances: Array&lt;common.ApplicationInstance&gt;): void

Removes the background freeze-exempt application list for a specified user. After the removal, the applications can be frozen by the system. If the parameter list includes uninstalled applications, the removal will still succeed. Installed applications will be removed from the list, while uninstalled ones will not impact the removal process.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: Before API version 26.0.0, this API is supported on phones and tablets but does not take effect on other devices. Since API version 26.0.0, this API is supported on phones, tablets, PCs/2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                        |
| applicationInstances | Array&lt;[common.ApplicationInstance](./js-apis-enterprise-common.md#applicationinstance)&gt; | Yes  | Array of the background freeze-exempt application list.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let applicationInstances: Array<common.ApplicationInstance> = [
  // Replace it as required.
  {
    appIdentifier: '0123456789123456789',
    accountId: 100,
    appIndex: 0
  }
];

try {
  applicationManager.removeFreezeExemptedApps(wantTemp, applicationInstances);
  console.info('Succeeded in removing FreezeExempted applications.');
} catch(err) {
  console.error(`Failed to remove FreezeExempted applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getFreezeExemptedApps<sup>22+</sup>

getFreezeExemptedApps(admin: Want | null): Array&lt;common.ApplicationInstance&gt;

Obtains the background freeze-exempt application list of all users on the current device.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: Before API version 26.0.0, this API is supported on phones and tablets but does not take effect on other devices. Since API version 26.0.0, this API is supported on phones, tablets, PCs/2-in-1 devices.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array&lt;[common.ApplicationInstance](./js-apis-enterprise-common.md#applicationinstance)&gt; | Array of the background freeze-exempt application list.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<common.ApplicationInstance> = applicationManager.getFreezeExemptedApps(wantTemp);
  console.info(`Succeeded in getting FreezeExempted applications, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get FreezeExempted applications. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.setAbilityDisabled<sup>23+</sup>

setAbilityDisabled(admin: Want, bundleName: string, accountId: number, abilityName: string, isDisabled: boolean): void

Sets whether to disable the Ability component of a specified application (system application or third-party application). Currently, only the UIAbility type is supported. After the UIAbility type is disabled, the UI of the Ability component cannot be started.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                        |
| bundleName  | string     | Yes  | App bundle name.|
| accountId  | number      | Yes  | Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| abilityName  | string      | Yes  | Name of the ability to be disabled or enabled. Currently, only UIAbility is supported.|
| isDisabled  | boolean      | Yes  | Whether to disable the ability. **true**: Disable the ability. **false**: Enable the ability.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace it as required.
  let bundleName: string = "com.example.exampleapplication";
  let accountId: number = 100;
  let abilityName: string = "EntryAbility";
  applicationManager.setAbilityDisabled(wantTemp, bundleName, accountId, abilityName, true);
  console.info('Succeeded in setting ability disabled');
} catch(err) {
  console.error(`Failed to set ability disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.isAbilityDisabled<sup>23+</sup>

isAbilityDisabled(admin: Want | null, bundleName: string, accountId: number, abilityName: string): boolean

Checks whether the Ability component of a specified application (system application or third-party application) is disabled.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                        | Mandatory| Description                                  |
| ------------- | ------------------------------------------------------------ | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.|
| bundleName  | string     | Yes  | App bundle name.|
| accountId  | number      | Yes  | Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| abilityName  | string      | Yes  | Name of the ability to be disabled or enabled. Currently, only UIAbility is supported.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| boolean | Whether the ability is disabled. **true**: The ability is disabled. **false**: The ability is not disabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace it as required.
  let bundleName: string = "com.example.exampleapplication";
  let accountId: number = 100;
  let abilityName: string = "EntryAbility";
  let isDisabled: boolean = applicationManager.isAbilityDisabled(wantTemp, bundleName, accountId, abilityName);
  console.info(`Succeeded in querying whether the ability is disabled, isDisabled: ${isDisabled}`);
} catch(err) {
  console.error(`Failed to query whether the ability is disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.addDockApp<sup>24+</sup>

addDockApp(admin: Want, bundleName: string, abilityName: string, index?: number): void

Adds an application to the bottom shortcut bar of a PC/2-in-1 device based on the location index. Then users can tap the application icon in the shortcut bar to directly launch the application. The application icon is the default icon displayed on the home screen.

> **NOTE**
>
> 1. If location 0 or 1 is already occupied by the application center or task center, adding an application to that location returns error code 9201019. If that location is occupied by another app, the addition succeeds.
>
> 2. The following applications cannot be added to the shortcut bar using this API: Application Center, Task Center, Files, and Recycle Bin.
>
> 3. Only applications with an entry (that is, an icon) can be added.
>
> 4. Only the shortcut bar of the current user can be configured. Each user's shortcut bar can contain a maximum of 100 applications.
>
> 5. When a new application is inserted into an occupied location, the new application will directly take that location, and the original application along with all subsequent applications will shift back by one location.
>
> 6. If the **index** parameter is not passed or the passed value is greater than the number of applications in the shortcut bar, the new application is added to the end of the shortcut bar by default.
>
> 7. After an application is added to the shortcut bar using this API, users can manually remove the application or adjust its position.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Device behavior differences**: This API takes effect only on PCs/2-in-1 devices. If it is called on other devices, error code 801 is returned.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleName   | string                                                  | Yes  | Bundle name of the application.|
| abilityName  | string                                                  | Yes  | Ability name of the application. Only the application entry ability is supported.|
| index        | number                                                  | No  | Location index of the application in the shortcut bar. The value range is [0, 100). The default value is 99.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9200015  | The ability does not exist. |
| 9201013  | The number of applications in the Dock has reached the maximum. |
| 9201014  | The application is already in the Dock. |
| 9201015  | The application is not installed. |
| 9201018  | The application is inoperable. |
| 9201019  | The location is inoperable. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace it as required.
  let bundleName: string = 'com.example.exampleapplication';
  let abilityName: string = 'EntryAbility';
  applicationManager.addDockApp(wantTemp, bundleName, abilityName, 3);
  console.info('Succeeded in adding dock app.');
} catch(err) {
  console.error(`Failed to add dock app. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.removeDockApp<sup>24+</sup>

removeDockApp(admin: Want, bundleName: string, abilityName: string): void

Removes an application from the shortcut bar.

> **NOTE**
>
> The following applications cannot be removed from the shortcut bar using this API: Application Center, Task Center, Files, and Recycle Bin. Otherwise, error code 9201018 will be reported.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Device behavior differences**: This API takes effect only on PCs/2-in-1 devices. If it is called on other devices, error code 801 is returned.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleName   | string                                                  | Yes  | Bundle name of the application.|
| abilityName  | string                                                  | Yes  | Ability name of the application. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201016  | The application has not been added to the Dock. |
| 9201018  | The application is inoperable. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace it as required.
  let bundleName: string = 'com.example.exampleapplication';
  let abilityName: string = 'EntryAbility';
  applicationManager.removeDockApp(wantTemp, bundleName, abilityName);
  console.info('Succeeded in removing dock app.');
} catch(err) {
  console.error(`Failed to remove dock app. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getDockApps<sup>24+</sup>

getDockApps(admin: Want): Array\<DockInfo>

Obtains the list of applications in the shortcut bar currently.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Device behavior differences**: This API takes effect only on PCs/2-in-1 devices. If it is called on other devices, error code 801 is returned.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array&lt;[DockInfo](#dockinfo24)&gt; | Array of application information in the shortcut bar.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<applicationManager.DockInfo> = applicationManager.getDockApps(wantTemp);
  console.info(`Succeeded in getting dock apps, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get dock apps. Code: ${err.code}, message: ${err.message}`);
}
```
<!--code_no_check-->
```ts
// Return value example.
[
  {
    "bundleName": "com.example.edmtest",
    "abilityName": "EntryAbility",
    "index": 5
  },
  // ...
]
```



## applicationManager.addAllowedNotificationBundles

addAllowedNotificationBundles(admin: Want, bundleNames: Array\<string\>, accountId: number): void

Adds applications to the notification trustlist. After the notification trustlist is set, applications not in the trustlist cannot send notifications.
> **NOTE**
>
> 1. If both the Kiosk mode and the notification trustlist policy are set, applications in the Kiosk mode and those in the notification trustlist can send notifications.<br>
> 2. If the device notification capability has been disabled via [setDisallowedPolicy](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicydeprecated), calling this API to set the notification trustlist will trigger error code 9200010.<br>
> 3. The notification trustlist does not apply to system services, which can always send notifications. System applications are controlled by the notification trustlist.<br>
> 4. Cross-user settings are supported. The settings take effect immediately.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Application bundle name array, which specifies the applications that are allowed to send notifications. A maximum of 200 applications are supported.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let bundleNames: Array<string> = ['com.example.notificationapp'];

try {
  applicationManager.addAllowedNotificationBundles(wantTemp, bundleNames, 100);
  console.info('Succeeded in adding allowed notification bundles.');
} catch (err) {
  console.error(`Failed to add allowed notification bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeAllowedNotificationBundles

removeAllowedNotificationBundles(admin: Want, bundleNames: Array\<string\>, accountId: number): void

Removes applications from the notification trustlist.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Application bundle name array, which specifies the applications to be removed.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let bundleNames: Array<string> = ['com.example.notificationapp'];

try {
  applicationManager.removeAllowedNotificationBundles(wantTemp, bundleNames, 100);
  console.info('Succeeded in removing allowed notification bundles.');
} catch (err) {
  console.error(`Failed to remove allowed notification bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getAllowedNotificationBundles

getAllowedNotificationBundles(admin: Want \| null, accountId: number): Array\<string\>

Obtains the list of applications that are allowed to send notifications.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| accountId | number                                                  | Yes  | Account ID, which must be greater than or equal to 0.<br>You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | Array of bundle names of applications that are allowed to send notifications.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: Array<string> = applicationManager.getAllowedNotificationBundles(wantTemp, 100);
  console.info(`Succeeded in getting allowed notification bundles, result : ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed notification bundles. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.addAllowedDistributeAbilityConnBundles

addAllowedDistributeAbilityConnBundles(admin: Want, appIdentifiers: Array&lt;string&gt;, serviceType: ServiceType, accountId: number): void

Adds the cross-device application trustlist for a specific distributed service for a specified user. Applications in the trustlist can use the specific distributed service to transfer data across devices without being subject to the restrictions imposed by [setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated).

Currently, the following distributed service type is supported: [collaboration service](#servicetype).
> **NOTE**
>
> 1. Before calling this API to set the application list allowed to use a specific distributed service, you must have already disabled one-way data transmission between devices (which is used for transferring data to other devices) via [setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated). Otherwise, error code 9201043 is thrown.<br>
> 2. When one-way data transmission between devices is re-enabled, the application list allowed to use the specific distributed service that was set via this API is automatically cleared.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIdentifiers | Array&lt;string&gt;                                   | Yes  | Array of [unique identifiers](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application. You can call the [bundleManager.getBundleInfo](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfo14-2) API to obtain the **bundleInfo.signatureInfo.appIdentifier**. The total number of applications in the array cannot exceed 200.|
| serviceType | [ServiceType](#servicetype) | Yes  | Distributed service type.|
| accountId  | number      | Yes  | Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 9201043  | Prerequisites for the API call have not been satisfied. For example, distributed outgoing transmission is not disallowed before adding the distributed bidirectional collaboration trustlist. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager, restrictions } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

// If you want to disable data transmission to other devices for all applications except specified ones on the device under user 100, perform the following two steps:
let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let accountId: number = 100;

// Step 1. Disable one-way data transmission between devices for user 100. (If this capability has been disabled before, you do not need to disable it again.)
try {
  restrictions.setDisallowedPolicyForAccount(wantTemp, restrictions.FeatureForAccount.DISTRIBUTED_TRANSMISSION_OUTGOING, true, accountId);
  console.info('Succeeded in setting distributedTransmissionOutgoing disabled');
} catch (err) {
  console.error(`Failed to set distributedTransmissionOutgoing disabled. Code is ${err.code}, message is ${err.message}`);
}

// Step 2: Set the list of applications that are allowed to use a specific distributed service (for example, the collaboration service) under user 100.
try {
  // Replace it as required.
  let appIdentifiers: Array<string> = ['6917****3569'];
  applicationManager.addAllowedDistributeAbilityConnBundles(wantTemp, appIdentifiers, applicationManager.ServiceType.COLLABORATION_SERVICE, accountId);
  console.info('Succeeded in adding allowed distribute ability conn bundles.');
} catch(err) {
  console.error(`Failed to add allowed distribute ability conn bundles. Code: ${err.code}, message: ${err.message}`);
}
// After the preceding two steps are performed, under user 100, only the application 6917****3569 can transmit data to other devices through the collaboration service. Other applications cannot transmit data to other devices.
// Note: After disabling one-way data transmission between devices for a specific user, whether to add an application list allowed to use collaboration services depends on actual business requirements.
```

## applicationManager.removeAllowedDistributeAbilityConnBundles

removeAllowedDistributeAbilityConnBundles(admin: Want, appIdentifiers: Array&lt;string&gt;, serviceType: ServiceType, accountId: number): void

Removes the cross-device application trustlist for a specific distributed service for a specified user. After the trustlist is removed, if there are still remaining applications in the list, only those applications can use the specific distributed service to transmit data across devices without being subject to the restrictions imposed by [setDisallowedPolicyForAccount](./js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccountdeprecated). If the list has been removed and there are no remaining applications, no applications under the specified user are allowed to use the specific distributed service for cross-device data transmission.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| appIdentifiers | Array&lt;string&gt;                                   | Yes  | Array of [unique identifiers](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) of an application. You can call the [bundleManager.getBundleInfo](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfo14-2) API to obtain the **bundleInfo.signatureInfo.appIdentifier**. The total number of applications in the array cannot exceed 200.|
| serviceType | [ServiceType](#servicetype) | Yes  | Distributed service type.|
| accountId  | number      | Yes  | Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace it as required.
  let appIdentifiers: Array<string> = ['6917****3569'];
  let accountId: number = 100;
  applicationManager.removeAllowedDistributeAbilityConnBundles(wantTemp, appIdentifiers, applicationManager.ServiceType.COLLABORATION_SERVICE, accountId);
  console.info('Succeeded in removing allowed distribute ability conn bundles.');
  // Note: After removing the application list allowed to use collaboration services for a user, whether to lift the disablement of one-way data transmission between devices for that user should be determined based on actual business requirements.
} catch(err) {
  console.error(`Failed to remove allowed distribute ability conn bundles. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.getAllowedDistributeAbilityConnBundles

getAllowedDistributeAbilityConnBundles(admin: Want | null, serviceType: ServiceType, accountId: number): Array&lt;string&gt;

Obtains the cross-device application trustlist for a specific distributed service under a specified user.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| serviceType | [ServiceType](#servicetype) | Yes  | Distributed service type.|
| accountId  | number | Yes| Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array&lt;string&gt; | Array of [unique identifiers](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md#signatureinfo) for applications allowed to use a specific distributed service under the specified user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace it as required.
  let accountId: number = 100;
  let result: Array<string> = applicationManager.getAllowedDistributeAbilityConnBundles(wantTemp, applicationManager.ServiceType.COLLABORATION_SERVICE, accountId);
  console.info(`Succeeded in getting allowed distribute ability conn bundles: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get allowed distribute ability conn bundles. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.queryTrafficStats

queryTrafficStats(admin: Want, bundleName: string, appIndex: number, accountId: number, networkInfo: statistics.NetworkInfo): Promise&lt;statistics.NetStatsInfo&gt;

Queries the data usage of a specified application within a specified period for the current user. This API uses a promise to return the result.

> **NOTE**
>
> The input network type (**networkInfo.type**) can only be **connection.NetBearType.BEARER_CELLULAR** or **connection.NetBearType.BEARER_WIFI**. If any other value is passed, the API returns error code 9200012.
>
> The input start time (**networkInfo.startTime**) and end time (**networkInfo.endTime**) are second-level timestamps. If the input start time and end time are negative numbers or the start time is later than the end time, the API returns error code 9200012.
>
> If the input user ID (**accountId**) is not the ID of the current user, the API returns error code 9200012.
>
> It is advised that the query interval (end time – start time) be 1 to 30 days. If the interval is too short, the query result may be inaccurate. If the interval is too long, the query will take a long time.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleName   | string                                                  | Yes  | Bundle name of the application.|
| appIndex | number                                                    | Yes  | Index of the application clone. The value is an integer greater than or equal to 0.<br> You can call [getAppCloneIdentity](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetappcloneidentity14) of @ohos.bundle.bundleManager to obtain the index.|
| accountId | number                                                   | Yes  | Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|
| networkInfo | [statistics.NetworkInfo](../apis-network-kit/js-apis-net-statistics.md#networkinfo22)                                                    | Yes  | Network information.|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise&lt;[statistics.NetStatsInfo](../apis-network-kit/js-apis-net-statistics.md#netstatsinfo22)&gt; | Promise used to return the historical traffic information object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**
```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { connection, statistics } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { sim } from '@kit.TelephonyKit';

async function queryTrafficStats() {
  let wantTemp: Want = {
    // Replace it as required.
    bundleName: 'com.example.myapplication',
    abilityName: 'EnterpriseAdminAbility'
  };
  // Replace it as required.
  let bundleName: string = 'com.example.test';
  let appIndex: number = 0;
  let accountId: number = 100;
  // In the sample code, sim.getSimAccountInfo is used to obtain the SIM ID.
  let slotId: number = 0;
  let simId: number = 0;
  await sim.getSimAccountInfo(slotId).then((data: sim.IccAccountInfo) => {
    simId = data.simId;
  }).catch((err: BusinessError) => {
    console.error(`getSimAccountInfo failed, promise: err->${JSON.stringify(err)}`);
  });
  let networkInfo: statistics.NetworkInfo = {
    // Replace it as required.
    type: connection.NetBearType.BEARER_CELLULAR,
    // Query data from 2026/4/15 00:00:00.000 to 2026/4/16 00:00:00.000. (The month starts from 0.)
    startTime: Math.floor(new Date(2026, 3, 15, 0, 0, 0, 0).getTime() / 1000),
    endTime: Math.floor(new Date(2026, 3, 16, 0, 0, 0, 0).getTime() / 1000),
    // If the network type is BEARER_CELLULAR, simId needs to be passed. If the network type is BEARER_WIFI, simId does not need to be passed.
    simId: simId
  }
  await applicationManager.queryTrafficStats(wantTemp, bundleName, appIndex, accountId, networkInfo)
    .then(result => {
      console.info('Succeeded in querying traffic stats.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to query traffic stats. Code is ${error.code}, message is ${error.message}`);
    })
}
```

## applicationManager.getApplicationWindowStates

getApplicationWindowStates(admin: Want, bundleName: string, appIndex: number): Array\<WindowStateInfo\>

Queries the window state information list of the specified application. It can retrieve information such as whether the application is in the bottom dock and whether the application window is currently displayed in the foreground.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name      | Type                                                   | Mandatory| Description                                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleName   | string                                                  | Yes  | Bundle name of the application.|
| appIndex | number                                                    | Yes  | Index of the application clone. The value is an integer greater than or equal to 0.<br> You can call [getAppCloneIdentity](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetappcloneidentity14) of @ohos.bundle.bundleManager to obtain the index.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array&lt;[WindowStateInfo](#windowstateinfo)&gt; | Array of the application window state information.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**
```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Bundle name of the application to be queried. Replace it as required.
let bundleName: string = 'com.example.myapplication';
// Clone index of the queried application. Replace it as required.
let appIndex: number = 0;
try {
  let result: Array<applicationManager.WindowStateInfo> = applicationManager.getApplicationWindowStates(wantTemp, bundleName, appIndex);
  console.info(`Succeeded in getting application window states, result: ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to get application window states. Code: ${err.code}, message: ${err.message}`);
}
```

## KioskFeature<sup>20+</sup>

Defines the features of the kiosk mode.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name                       | Value | Description   |
| ----------------------------| ----| ------------------------------- |
| ALLOW_NOTIFICATION_CENTER   | 1   | Allow access to the notification center (by swiping down from the upper left corner with one finger).|
| ALLOW_CONTROL_CENTER        | 2   | Allow access to the control panel (by swiping down from the upper right corner with one finger).|
| ALLOW_GESTURE_CONTROL<sup>24+</sup>    | 3   | Allow access to the recent task bar (by swiping up from the bottom with one finger and holding).|
| ALLOW_SIDE_DOCK<sup>24+</sup>    | 4   | Allow access to the side dock (by swiping inward from the edge with one finger and holding).|


## DockInfo<sup>24+</sup>

Describes information about an application in the shortcut bar.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name        | Type  | Read-Only | Optional |Description         |
| ----------- | ------ |------ |------| ---------------|
| bundleName  | string | No   | No  | Bundle name of the application.|
| abilityName | string | No   | No  | Ability name of the application. |
| index       | number | No   | No  | Location index of the application in the shortcut bar.|

## BundleStatsInfo

Application bundle statistics.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name                   | Type  | Read-Only | Optional |Description         |
| ----------------------- | ------ |------ |------| ---------------|
| bundleName              | string | No   | No  | Bundle name of the application.|
| appIndex                | number | No   | No  | Index of the application clone. The value is an integer greater than or equal to 0.<br> You can call [getAppCloneIdentity](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetappcloneidentity14) of @ohos.bundle.bundleManager to obtain the index.|
| abilityInFgTotalTime    | number | No   | No  | Total duration that the ability runs in the foreground, in milliseconds.|

## WindowStateInfo

Defines the application window state information.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name        | Type    | Read-Only| Optional| Description                           |
| ----------- | --------| ----- | ---- | ------------------------------- |
| windowId | number | No| No| Application window ID.|
| state | [WindowState](#windowstate) | No| No| Application window state.|
| isOnDock | boolean | No| No| Whether the application window is displayed on the bottom dock. For application on the bottom dock on tablets in PC mode and PCs/2-in-1 devices. For other devices, **false** is returned.|
| name | string | No| No| Application window name.|

## ServiceType

Distributed service type.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name        | Value  | Description |
| ----------- | ------ |------ |
| COLLABORATION_SERVICE  | 0 | Collaboration service. Applications allowed to use the collaboration service can launch pages of other applications across devices and transmit data to them by using the APIs in [UIAbilityContext](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) or [UIExtensionContext](../apis-ability-kit/js-apis-inner-application-uiExtensionContext.md), or by using the method in [Cross-Device UIAbility Connection Development](../../distributedservice/abilityconnectmanager-guidelines.md).|

## WindowState

Enumerates application window states.

**Since:** 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name| Value| Description|
| -------- | -------- | -------- |
| DISCONNECT | 0 | The window has been created but is currently unavailable.|
| CONNECT | 1 | The window has been created and is available for use.|
| FOREGROUND | 2 | Foreground state, indicating that the window has entered the foreground display. This is a transitional state.|
| ACTIVE | 3 | Foreground active state, indicating that the window is currently displayed in the foreground.|
| INACTIVE | 4 | Foreground inactive state, indicating that the window is about to enter the background. This is a transitional state.|
| BACKGROUND | 5 | Background state, indicating that the window has been moved to the background and is not visible.|

## applicationManager.queryBundleStatsInfos

queryBundleStatsInfos(admin: Want, startTime: number, endTime: number, accountId: number): Array\<BundleStatsInfo\>

Queries the accumulated foreground runtime statistics of applications under a specified user account within a given time period. The minimum query granularity is one day. The API requires the start time (**startTime**), end time (**endTime**), and target user account ID (**accountId**) to be passed in. **startTime** and **endTime** are millisecond-level timestamps. The caller can pass custom values. The default value of **startTime** is 00:00:00.000 of the current day, and the default of **endTime** is 24:00:00.000 of the current day (that is, 00:00:00 of the following day). The API returns an array of **BundleStatsInfo**, where each element contains the bundle name of an application, its clone index, and the foreground usage duration (in milliseconds) within the specified time period. If **startTime** is set to **0**, the query starts from the device's first boot time. If **startTime** is later than **endTime**, the API returns error code 9200012.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| startTime | number                                                  | Yes  | Query start time, in milliseconds (timestamp).<br>Value range: [0, +∞).|
| endTime   | number                                                  | Yes  | Query end time, in milliseconds (timestamp).<br>Value range: [0, +∞).|
| accountId | number                                                  | Yes  | Account ID. The value is an integer greater than or equal to 0.<br> You can call [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1) of @ohos.account.osAccount to obtain the ID.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Array&lt;[BundleStatsInfo](#bundlestatsinfo)&gt; | Array of application bundle statistics.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**
```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Query data from 2026/4/15 00:00:00.000 to 2026/4/16 23:59:59.999. (The month starts from 0.)
  let startTime: number = new Date(2026, 3, 15, 0, 0, 0, 0).getTime();
  let endTime: number = new Date(2026, 3, 16, 23, 59, 59, 999).getTime();
  let accountId: number = 100;
  let result: Array<applicationManager.BundleStatsInfo> = applicationManager.queryBundleStatsInfos(wantTemp, startTime, endTime, accountId);
  console.info(`Succeeded in querying bundle stats infos, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to query bundle stats infos. Code: ${err.code}, message: ${err.message}`);
}
```

```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Query data of the last month.
  // Obtain the current date.
  let currentDate: Date = new Date();
  // Calculate the first day of the last month. (The month starts from 0. Therefore, subtract 1 from the current month.)
  let lastMonthFirstDay: Date = new Date(currentDate.getFullYear(), currentDate.getMonth() - 1, 1, 0, 0, 0, 0);
  // Calculate the last day of the last month. (The 0th day of the next month is the last day of the current month.)
  let lastMonthLastDay: Date = new Date(currentDate.getFullYear(), currentDate.getMonth(), 0, 23, 59, 59, 999);
  
  let startTime: number = lastMonthFirstDay.getTime();
  let endTime: number = lastMonthLastDay.getTime();
  let accountId: number = 100;
  let result: Array<applicationManager.BundleStatsInfo> = applicationManager.queryBundleStatsInfos(wantTemp, startTime, endTime, accountId);
  console.info(`Succeeded in querying bundle stats infos, result : ${JSON.stringify(result)}`);
} catch(err) {
  console.error(`Failed to query bundle stats infos. Code: ${err.code}, message: ${err.message}`);
}
```

## applicationManager.addHideLauncherIcon

addHideLauncherIcon(admin: Want, bundleNames: Array\<string\>): void

Adds applications to the home screen icon hide list.

> **NOTE**
>
> 1. This API can only hide home screen icons for applications of the current user. Hiding application widgets are not supported.
>
> 2. If a hidden application has clones, the clones are hidden synchronously.
>
> 3. Not all applications on the home screen can be added to the hidden list. Otherwise, all applications will still be displayed on the home screen.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Device behavior differences**: This API is supported on phones and tablets. On other device types, it returns error code 801.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Application bundle name array, which specifies the applications to be hidden. A maximum of 500 applications are supported.                                |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**
```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let bundleNames: Array<string> = ['com.example.test'];
try {
  applicationManager.addHideLauncherIcon(wantTemp, bundleNames);
  console.info('Succeeded in adding hide launcher icon.');
} catch (err) {
  console.error(`Failed to add hide launcher icon. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.removeHideLauncherIcon

removeHideLauncherIcon(admin: Want, bundleNames: Array\<string\>): void

Removes applications from the home screen icon hide list.

> **NOTE**
>
> After unhiding, applications will be placed in the first available slot starting from the second screen of the home screen. If no empty slot is found on screens 2 to 18, it will search for an empty slot on the first screen. If no empty slot is available on the first screen, a small folder will be created at the position of the first application on the second screen to contain the applications.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Device behavior differences**: This API is supported on phones and tablets. On other device types, it returns error code 801.

**Conflict rule**: [Policy merging](../../mdm/mdm-kit-multi-mdm.md#rule-4-policy-merging).

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                              |
| bundleNames    | Array&lt;string&gt;                                     | Yes  | Application bundle name array, which specifies the applications to be unhidden. A maximum of 500 applications are supported.                                |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**
```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace it as required.
let bundleNames: Array<string> = ['com.example.test'];
try {
  applicationManager.removeHideLauncherIcon(wantTemp, bundleNames);
  console.info('Succeeded in removing hide launcher icon.');
} catch (err) {
  console.error(`Failed to remove hide launcher icon. Code is ${err.code}, message is ${err.message}`);
}
```

## applicationManager.getHideLauncherIcon

getHideLauncherIcon(admin: Want \| null): Array\<string\>

Queries the list of applications whose home screen icons are hidden for the current user.

**Since:** 26.0.0

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_APPLICATION

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Device behavior differences**: This API is supported on phones and tablets. On other device types, it returns error code 801.

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>If the device has multiple MDM applications, you can pass **admin** to query the corresponding policies. If **null** is passed, the policies that actually take effect on the device are returned.                                              |

**Return value**

| Type               | Description                            |
| ------------------- | -------------------------------- |
| Array&lt;string&gt; | List of applications whose home screen icons are hidden for the current user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**
```ts
import { applicationManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace it as required.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
try {
  let bundleNames: Array<string> = applicationManager.getHideLauncherIcon(wantTemp);
  console.info('Succeeded in getting hide launcher icon.');
} catch (err) {
  console.error(`Failed to get hide launcher icon. Code is ${err.code}, message is ${err.message}`);
}
```
