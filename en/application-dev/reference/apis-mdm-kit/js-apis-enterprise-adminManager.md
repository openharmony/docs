# @ohos.enterprise.adminManager (Administrator Permission Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **adminManager** module provides administrator permission management capabilities for enterprise MDM applications, including enabling or disabling administrator permissions, subscribing to events, delegating applications, and granting permissions.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be called only by a device administrator application. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { adminManager } from '@kit.MDMKit';
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

Disables a device administrator application for the specified user. This API uses a promise to return the result. After this API is called successfully, the specified device administrator application will be deactivated and no longer have the device management capability.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN (available only for system applications), ohos.permission.START_PROVISIONING_MESSAGE, or ohos.permission.ENTERPRISE_DEACTIVATE_DEVICE_ADMIN
<br>- Since API version 23, the ohos.permission.ENTERPRISE_DEACTIVATE_DEVICE_ADMIN permission can be requested. This permission can be requested only after a [SDA](../../mdm/mdm-kit-term.md#super-device-admin-sda) or [DA](../../mdm/mdm-kit-term.md#device-admin-da) application administrator application deactivates itself.<br>- **ohos.permission.START_PROVISIONING_MESSAGE** is supported since API version 20. This permission can be requested only when the [BYOD](../../mdm/mdm-kit-term.md#byod) device management app is deactivated.<br>- **ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN** is required for API version 19 and earlier. (This permission can be requested only by system applications.)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application. When deactivating the BYOD device administrator application, you can pass only the **EnterpriseAdminExtensionAbility** component of the current application.   |
| userId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200005  | Failed to deactivate the administrator application of the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

adminManager.disableAdmin(wantTemp, 100).catch((err: BusinessError) => {
  console.error(`Failed to disable admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.isByodAdmin<sup>20+</sup>

isByodAdmin(admin: Want): boolean

Checks whether the current application is activated as a BYOD device administrator application based on the **EnterpriseAdminExtensionAbility** component.

**Required permission**: ohos.permission.START_PROVISIONING_MESSAGE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application. Only the **EnterpriseAdminExtensionAbility** component of the current application can be passed.|

**Return value**

| Type        | Description                |
| ----------------- | ------------------- |
| boolean | The value **true** indicates the application is activated as a BYOD device administrator application, and the value **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 9200012      | Parameter verification failed.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { adminManager } from '@kit.MDMKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  let result: boolean = adminManager.isByodAdmin(wantTemp);
  console.info(`Succeeded in querying admin is byod admin or not : ${result}`);
} catch (error) {
  console.error(`Failed to query admin is byod admin or not. Code is ${error.code}, message is ${error.message}`);
}
```

## adminManager.subscribeManagedEventSync

subscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

Subscribes to system management events. After the call is successful, the device administrator application will receive a notification when a subscribed system management event occurs.

Since API version 26.0.0, error code 9200002 is returned when a non-super device administrator application calls this API to subscribe to the [MANAGED_EVENT_POLICIES_CHANGED](#managedevent) event.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description                  |
| ------------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | Yes  | Array of system management events to be subscribed to. Each element in the array is a value from the [ManagedEvent](#managedevent) enumeration. Multiple event types can be subscribed to, such as application installation/uninstallation/start/stop events, system update events, and more.        |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. <br>Applicable version: 26.0.0+|
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.unsubscribeManagedEventSync

unsubscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

Unsubscribes from system management events. After the API is successfully called, no notifications for the unsubscribed system management events will be received.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description                  |
| ------------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | Yes  | Array of system management events to be unsubscribed from. Each element in the array is a value from the [ManagedEvent](#managedevent) enumeration. The input event types must be the same as those passed during subscription.    |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.unsubscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in unsubscribing managed event.');
} catch (err) {
  console.error(`Failed to unsubscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.setDelegatedPolicies<sup>14+</sup>

setDelegatedPolicies(admin: Want, bundleName: string, policies: Array&lt;string&gt;): void

Delegates other applications to set device management policies. The applications must request the permissions required.

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_DELEGATED_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description              |
| ------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| bundleName | string                   | Yes  | Bundle name of the delegated application. The distribution type of the delegated application must be **enterprise_normal** or **enterprise_mdm**. You can call the [getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) API to query the [BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md) of the application, where **BundleInfo.appInfo.appDistributionType** indicates the distribution type.|
| policies |  Array&lt;string&gt;                   | Yes  | [Delegable policy list](../../mdm/mdm-kit-appendix.md#delegable-policy-list).|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device.                       |
| 9200009  | Failed to grant the permission to the application.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
// Replace with actual values.
let policies: Array<string> = ["disabled_hdc"];

try {
  // Replace parameters with actual values.
  adminManager.setDelegatedPolicies(admin, "com.example.enterprise.xxx", policies);
  console.info('Succeeded in setting delegated policies.');
} catch (err) {
  console.error(`Failed to set delegated policies. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.getDelegatedPolicies<sup>14+</sup>

getDelegatedPolicies(admin: Want, bundleName: string): Array&lt;string&gt;

Queries the list of policies that can be accessed by the delegated application.

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_DELEGATED_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type                                                   | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| bundleName | string                                                  | Yes  | Bundle name of the delegated application. The distribution type of the delegated application must be **enterprise_normal** or **enterprise_mdm**. You can call the [getBundleInfoForSelf](../apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) API to query the [BundleInfo](../apis-ability-kit/js-apis-bundleManager-bundleInfo.md) of the application, where **BundleInfo.appInfo.appDistributionType** indicates the distribution type.|


**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Array&lt;string&gt; | Delegation policy list.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let policies: Array<string> = adminManager.getDelegatedPolicies(admin, "com.example.enterprise.xxx");
  console.info(`Succeeded in getting delegated policies.${JSON.stringify(policies)}`);
} catch (err) {
  console.error(`Failed to get delegated policies. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.getDelegatedBundleNames<sup>14+</sup>

getDelegatedBundleNames(admin: Want, policy: string): Array&lt;string&gt;

Queries the delegated applications that can access a delegation policy and output the list of delegated applications.

**Required permission**: ohos.permission.ENTERPRISE_MANAGE_DELEGATED_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description              |
| ------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| policy | string                   | Yes  | Delegation policy.|


**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Array&lt;string&gt; | List of delegated applications.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let bundleNames: Array<string> = adminManager.getDelegatedBundleNames(admin, "disabled_hdc");
  console.info(`Succeeded in getting delegated bundles.${JSON.stringify(bundleNames)}`);
} catch (err) {
  console.error(`Failed to get delegated bundles. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.startAdminProvision<sup>15+</sup>

startAdminProvision(admin: Want, type: AdminType, context: common.Context, parameters: Record\<string, string>): void

Enables the device administrator application to open a page for the BYOD administrator to perform activation.

**Required permission**: ohos.permission.START_PROVISIONING_MESSAGE

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on phones and tablets but does not take effect on other devices.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| type  | [AdminType](#admintype15)             | Yes   | Type of the activated device administrator application. Only the **ADMIN_TYPE_BYOD** type is supported. |
| context  | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context) | Yes| Context information of the administrator application.|
| parameters  | Record\<string, string> | Yes| Custom parameters. The key value must contain **activateId** and may optionally include **customizedInfo** and **localDeactivationPolicy**.<br>- **activateId**: project activation ID.<br>- **customizedInfo**: enterprise-defined information.<br>- **localDeactivationPolicy**: local deactivation delay (unit: hour). This parameter is supported since API version 22<!--RP1--><!--RP1End-->.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

<!--code_no_check-->
```ts
import { adminManager } from '@kit.MDMKit';
import { common, Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};
let recordParameters: Record<string, string> = {
  // Replace with actual values.
  "activateId": "activateId testValue",
  "customizedInfo": "customizedInfo testValue"
};
// Obtain the context from the component and ensure that the return value of this.getUIContext().getHostContext() is UIAbilityContext.
const context = this.getUIContext().getHostContext() as common.UIAbilityContext;
try {
  console.info('context:' + JSON.stringify(context));
  adminManager.startAdminProvision(wantTemp, adminManager.AdminType.ADMIN_TYPE_BYOD, context, recordParameters);
  console.info('startAdminProvision::success');
} catch (error) {
  console.error('startAdminProvision::errorCode: ' + error.code + ' errorMessage: ' + error.message);
}
```

## adminManager.enableDeviceAdmin<sup>23+</sup>

enableDeviceAdmin(admin: Want): Promise&lt;void&gt;

Enables a [DA](../../mdm/mdm-kit-term.md#device-admin-da) application by a [SDA](../../mdm/mdm-kit-term.md#super-device-admin-sda) application. This API uses a promise to return the result. After the API is successfully called, the specified DA application is enabled and granted device management capabilities. This API can be called only by super device administrator applications.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200003  | The administrator ability component is invalid.              |
| 9200004  | Failed to activate the administrator application of the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { adminManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

adminManager.enableDeviceAdmin(wantTemp).catch((err: BusinessError) => {
  console.error(`Failed to enable device admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.disableDeviceAdmin<sup>23+</sup>

disableDeviceAdmin(admin: Want): Promise&lt;void&gt;

Disables a [DA](../../mdm/mdm-kit-term.md#device-admin-da) application by a [SDA](../../mdm/mdm-kit-term.md#super-device-admin-sda) application. This API uses a promise to return the result. After this API is called successfully, the specified device administrator application is disabled and no longer has the device management capability. This API can be called only by super device administrator applications.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200005  | Failed to deactivate the administrator application of the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { adminManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

adminManager.disableDeviceAdmin(wantTemp).catch((err: BusinessError) => {
  console.error(`Failed to disable device admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.enableSelfDeviceAdmin

enableSelfDeviceAdmin(admin: Want, credential: string): void

Allows an MDM application to enable itself in scenarios where it is not pre-enabled on the enterprise device. This API supports enablement of the MDM application itself only, and cannot be used to enable other MDM applications. The supported enablement types include super device administrator application and normal device administrator application.

<!--RP1--><!--RP1End-->

**Since:** 26.0.0

**Required permissions:** ohos.permission.ENTERPRISE_ACTIVATE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                  |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|
| credential | string                   | Yes  | Enablement credential.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200003  | The administrator ability component is invalid.              |
| 9200004  | Failed to activate the administrator application of the device. |
| 9200012  | Parameter verification failed. |
| 9200017  | The self-activation credential of the enterprise device administrator is invalid. |
| 9200018  | This device is not an enterprise device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { adminManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace with actual values.
let credential: string = '{"enterpriseId": "123456", "appIdentifier": "123456", "type": "SDA", "sign": "", "certs": []}';

try {
  adminManager.enableSelfDeviceAdmin(wantTemp, credential);
  console.info(`succeed in enable self device admin.`);
} catch (err) {
  console.error(`Failed to enable self device admin. Code: ${err.code}, message: ${err.message}`);
}
```

## ManagedEvent

Enumerates the system management events that can be subscribed to.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name                                        | Value  | Description          |
| -------------------------------------------- | ---- | -------------- |
| MANAGED_EVENT_BUNDLE_ADDED                   | 0    | An application is installed.|
| MANAGED_EVENT_BUNDLE_REMOVED                 | 1    | An application is uninstalled.|
| MANAGED_EVENT_APP_START                      | 2    | An application is started.|
| MANAGED_EVENT_APP_STOP                       | 3    | An application is stopped.|
| MANAGED_EVENT_SYSTEM_UPDATE                  | 4    | The system is updated.|
| MANAGED_EVENT_ACCOUNT_ADDED<sup>18+</sup>    | 5    | An account is created.|
| MANAGED_EVENT_ACCOUNT_SWITCHED<sup>18+</sup> | 6    | An account is switched.|
| MANAGED_EVENT_ACCOUNT_REMOVED<sup>18+</sup>  | 7    | An account is removed.|
| MANAGED_EVENT_STARTUP_GUIDE_COMPLETED<sup>24+</sup> | 8    | The startup wizard is complete.<br>**Model restriction**: This API can be used only in the stage model.|
| MANAGED_EVENT_BOOT_COMPLETED<sup>24+</sup>  | 9    | Device startup is complete.<br>**Model restriction**: This API can be used only in the stage model.|
| MANAGED_EVENT_BUNDLE_UPDATED                | 10    | Application update event.<br>**Since:** 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|
| MANAGED_EVENT_POLICIES_CHANGED                | 11    | Policy change event. Only super device administrator applications can subscribe to this event. If other types of device administrator applications attempt to subscribe, error code 9200002 is returned.<br>**Since:** 26.0.0<br>**Model restriction**: This API can be used only in the stage model.|

## AdminType<sup>15+</sup>

Enumerates the types of device administrator applications.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_BYOD  | 0x02 | BYOD device administrator application.|

## Policy<sup>20+</sup>

Defines the policy type for the trustlist or blocklist.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| BLOCK_LIST  | 0 | Blocklist.|
| TRUST_LIST  | 1 | Trustlist.|
<!--no_check-->