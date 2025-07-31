# @ohos.enterprise.adminManager (Administrator Permission Management)

The **adminManager** module provides administrator permission management capabilities for enterprise MDM applications, including enabling or disabling administrator permissions, subscribing to events, delegating applications, and granting permissions.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be called only by a device administrator application. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { adminManager } from '@kit.MDMKit';
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

Disables a device administrator application for the specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN (available only for system applications)

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
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
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.disableAdmin(wantTemp, 100).catch((err: BusinessError) => {
  console.error(`Failed to disable admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.subscribeManagedEventSync

subscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

Subscribes to system management events.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description                  |
| ------------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | Yes  | Array of events to subscribe to.        |

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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

Unsubscribes from system management events.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description                  |
| ------------- | ------------------------------------------------------- | ---- | ---------------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | Yes  | Array of events to unsubscribe from.    |

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
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
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
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
| bundleName | string                   | Yes  | Bundle name of the delegated application. The distribution type of the application can only be **enterprise_normal** or **enterprise_mdm**. For details about the **app-distribution-type** field, see [Profile](https://developer.huawei.com/consumer/en/doc/app/agc-help-add-releaseprofile-0000001914714796).|
| policies |  Array&lt;string&gt;                   | Yes  | [Delegation Policy List](#delegation-policy-list)|

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
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let policies: Array<string> = ["disabled_hdc"];

try {
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
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| bundleName | string                                                  | Yes  | Bundle name of the delegated application. The distribution type of the application can only be **enterprise_normal** or **enterprise_mdm**. For details about the **app-distribution-type** field, see [Profile](https://developer.huawei.com/consumer/en/doc/app/agc-help-add-releaseprofile-0000001914714796).|


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
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
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
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|
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
import { Want } from '@kit.AbilityKit';

let admin: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
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



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| type  | [AdminType](#admintype15)             | Yes   | Type of the activated device administrator application. Only the **ADMIN_TYPE_BYOD** type is supported. |
| context  | [common.Context](../apis-ability-kit/js-apis-app-ability-common.md) | Yes| Context information of the administrator application.|
| parameters  | Record\<string, string> | Yes| Custom parameters. The key value must contain **activateId**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

<!--code_no_check-->
```ts
import { common, Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let recordParameters: Record<string, string> = {
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

## AdminType<sup>15+</sup>

Enumerates the types of device administrator applications.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_BYOD  | 0x02 | BYOD device administrator application.|

## Appendix
### Delegation Policy List
| Policy Name| API                                                    | Description|
| --- | --- | --- |
|disallow_add_local_account| [accountManager.disallowOsAccountAddition](js-apis-enterprise-accountManager.md#accountmanagerdisallowosaccountaddition)<br>[accountManager.isOsAccountAdditionDisallowed](js-apis-enterprise-accountManager.md#accountmanagerisosaccountadditiondisallowed) | Prevents the device from creating a local user, without needing the **accountId** parameter.<br>Checks whether the device is prevented from creating a local user, without needing the **accountId** parameter.|
|disallow_add_os_account_by_user| [accountManager.disallowOsAccountAddition](js-apis-enterprise-accountManager.md#accountmanagerdisallowosaccountaddition)<br>[accountManager.isOsAccountAdditionDisallowed](js-apis-enterprise-accountManager.md#accountmanagerisosaccountadditiondisallowed) | Prevents the specified user from adding accounts, with the **accountId** parameter passed.<br>Checks whether the specified user is prevented from adding accounts, with the **accountId** parameter passed.|
|disallow_running_bundles|[applicationManager.addDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanageradddisallowedrunningbundlessync)<br>[applicationManager.removeDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanagerremovedisallowedrunningbundlessync)<br>[applicationManager.getDisallowedRunningBundlesSync](js-apis-enterprise-applicationManager.md#applicationmanagergetdisallowedrunningbundlessync)|Adds the applications that are not allowed to run by the current or specified user.<br>Removes applications that are not allowed to run.<br>Obtains applications that are not allowed to run by the current user or specified user.|
|manage_auto_start_apps|[applicationManager.addAutoStartApps](js-apis-enterprise-applicationManager.md#applicationmanageraddautostartapps)<br>[applicationManager.removeAutoStartApps](js-apis-enterprise-applicationManager.md#applicationmanagerremoveautostartapps)<br>[applicationManager.getAutoStartApps](js-apis-enterprise-applicationManager.md#applicationmanagergetautostartapps)|Adds the auto-start applications. Currently, this capability supports only 2-in-1 devices.<br>Removes the auto-start applications. Currently, this capability supports only 2-in-1 devices.<br>Obtains the auto-start applications. Currently, this capability supports only 2-in-1 devices.|
|allowed_bluetooth_devices|[bluetoothManager.addAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanageraddallowedbluetoothdevices)<br>[bluetoothManager.removeAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanagerremoveallowedbluetoothdevices)<br>[bluetoothManager.getAllowedBluetoothDevices](js-apis-enterprise-bluetoothManager.md#bluetoothmanagergetallowedbluetoothdevices)|Adds allowed Bluetooth devices.<br>Removes allowed Bluetooth devices.<br>Obtains allowed Bluetooth devices.|
|set_browser_policies|[browser.setPolicySync](js-apis-enterprise-browser.md#browsersetpolicysync)<br>[browser.getPoliciesSync](js-apis-enterprise-browser.md#browsergetpoliciessync)|Sets the sub-policy for a specified browser.<br>Obtains the policy of a specified browser.|
|allowed_install_bundles|[bundleManager.addAllowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanageraddallowedinstallbundlessync)<br>[bundleManager.removeAllowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagerremoveallowedinstallbundlessync)<br>[bundleManager.getAllowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagergetallowedinstallbundlessync)|Adds the applications that can be installed by the current or specified user.<br>Removes the applications that can be installed.<br>Obtains the applications that can be installed by the current or specified user.|
|disallowed_install_bundles|[bundleManager.addDisallowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanageradddisallowedinstallbundlessync)<br>[bundleManager.removeDisallowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagerremoveallowedinstallbundlessync)<br>[bundleManager.getDisallowedInstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagergetdisallowedinstallbundlessync)|Adds the applications that cannot be installed by the current or specified user.<br>Removes the applications that cannot be installed.<br>Obtains the applications that cannot be installed by the current or specified user.|
|disallowed_uninstall_bundles|[bundleManager.addDisallowedUninstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanageradddisalloweduninstallbundlessync)<br>[bundleManager.removeDisallowedUninstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagerremovedisalloweduninstallbundlessync)<br>[bundleManager.getDisallowedUninstallBundlesSync](js-apis-enterprise-bundleManager.md#bundlemanagergetdisalloweduninstallbundlessync)|Adds the applications that cannot be uninstalled by the current or specified user.<br>Removes the applications that cannot be uninstalled.<br>Obtains the applications that cannot be uninstalled by the current or specified user.|
|get_device_info|[deviceInfo.getDeviceInfo](js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)|Obtains device information.|
|location_policy|[locationManager.setLocationPolicy](js-apis-enterprise-locationManager.md#locationmanagersetlocationpolicy)<br>[locationManager.getLocationPolicy](js-apis-enterprise-locationManager.md#locationmanagergetlocationpolicy)|Sets the location service policy.<br>Obtains the location service policy.|
|disabled_network_interface|[networkManager.setNetworkInterfaceDisabledSync](js-apis-enterprise-networkManager.md#networkmanagersetnetworkinterfacedisabledsync)<br>[networkManager.isNetworkInterfaceDisabledSync](js-apis-enterprise-networkManager.md#networkmanagerisnetworkinterfacedisabledsync)|Disables a network interface.<br>Checks whether the network interface is disabled.|
|global_proxy|[networkManager.setGlobalProxySync](js-apis-enterprise-networkManager.md#networkmanagersetglobalproxysync)<br>[networkManager.getGlobalProxySync](js-apis-enterprise-networkManager.md#networkmanagergetglobalproxysync)|Sets the global network proxy.<br>Obtains the global network proxy.|
|disabled_bluetooth|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **bluetooth** as the parameter to disable or enable the Bluetooth capability.<br>Accepts **bluetooth** as the parameter to query whether the Bluetooth capability is disabled.|
|disallow_modify_datetime|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **modifyDateTime** as the parameter to disable or enable the system time setting capability.<br>Accepts **modifyDateTime** as the parameter to query whether the system time modification capability is disabled.|
|disabled_printer|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **printer** as the parameter to disable or enable the printing capability.<br>Accepts **printer** as the parameter to query whether the printing capability is disabled.|
|disabled_hdc|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **hdc** as the parameter to disable or enable the HDC capability.<br>Accepts **hdc** as the parameter to query whether the HDC capability is disabled.|
|disable_microphone|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **microphone** as the parameter to disable or enable the microphone capability.<br>Accepts **microphone** as the parameter to query whether the microphone is disabled.|
|fingerprint_auth|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)<br>[restrictions.setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount14)<br>[restrictions.getDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicyforaccount14)|Accepts **fingerprint** as the parameter to disable or enable fingerprint authentication.<br>Accepts **fingerprint** as the parameter to query whether fingerprint authentication is disabled.<br>Accepts **fingerprint** as the parameter to disable or enable fingerprint authentication for a specified user.<br>Accepts **fingerprint** as the parameter to query whether fingerprint authentication is disabled for a specified user.|
|disable_usb|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **usb** as the parameter to disable or enable the USB capability.<br>Accepts **usb** as the parameter to query whether the USB capability is disabled.|
|disable_wifi|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **wifi** as the parameter to disable or enable the Wi-Fi capability.<br>Accepts **wifi** as the parameter to query whether the Wi-Fi capability is disabled.|
|disallowed_tethering|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **tethering** as the parameter to disable or enable network sharing.<br>Accepts **tethering** as the parameter to query whether the network sharing capability is disabled.|
|inactive_user_freeze|[restrictions.setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)<br>[restrictions.getDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedpolicy)|Accepts **inactiveUserFreeze** as the parameter to freeze or unfreeze inactive users.<br>Accepts **inactiveUserFreeze** as the parameter to query whether inactive users are frozen.|
|snapshot_skip|[restrictions.addDisallowedListForAccount](js-apis-enterprise-restrictions.md#restrictionsadddisallowedlistforaccount14)<br>[restrictions.removeDisallowedListForAccount](js-apis-enterprise-restrictions.md#restrictionsremovedisallowedlistforaccount14)<br>[restrictions.getDisallowedListForAccount](js-apis-enterprise-restrictions.md#restrictionsgetdisallowedlistforaccount14)|Accepts **snapshotSkip** as the parameter to add applications with screen snapshot disabled.<br>Accepts **snapshotSkip** as the parameter to remove the applications with screen snapshot disabled.<br>Accepts **snapshotSkip** as the parameter to obtain the applications with screen snapshot disabled.|
|password_policy|[securityManager.setPasswordPolicy](js-apis-enterprise-securityManager.md#securitymanagersetpasswordpolicy)<br>[securityManager.getPasswordPolicy](js-apis-enterprise-securityManager.md#securitymanagergetpasswordpolicy)|Sets the device password policy.<br>Obtains the device password policy.|
|clipboard_policy|[securityManager.setAppClipboardPolicy](js-apis-enterprise-securityManager.md#securitymanagersetappclipboardpolicy)<br>[securityManager.getAppClipboardPolicy](js-apis-enterprise-securityManager.md#securitymanagergetappclipboardpolicy)|Sets the device clipboard policy.<br>Obtains the device clipboard policy.|
|watermark_image_policy|[securityManager.setWatermarkImage](js-apis-enterprise-securityManager.md#securitymanagersetwatermarkimage14)<br>[securityManager.cancelWatermarkImage](js-apis-enterprise-securityManager.md#securitymanagercancelwatermarkimage14)|Sets the watermark policy. Currently, this feature is available only for 2-in-1 devices.<br>Cancels the watermark policy. Currently, this feature is available only for 2-in-1 devices.|
|ntp_server|[systemManager.setNTPServer](js-apis-enterprise-systemManager.md#systemmanagersetntpserver)<br>[systemManager.getNTPServer](js-apis-enterprise-systemManager.md#systemmanagergetntpserver)|Sets the NTP server policy.<br>Obtains the NTP server information.|
|set_update_policy|[systemManager.setOtaUpdatePolicy](js-apis-enterprise-systemManager.md#systemmanagersetotaupdatepolicy)<br>[systemManager.getOtaUpdatePolicy](js-apis-enterprise-systemManager.md#systemmanagergetotaupdatepolicy)|Sets the update policy.<br>Obtains the update policy.|
|notify_upgrade_packages|[systemManager.notifyUpdatePackages](js-apis-enterprise-systemManager.md#systemmanagernotifyupdatepackages)<br>[systemManager.getUpdateResult](js-apis-enterprise-systemManager.md#systemmanagergetupdateresult)|Notifies the system of the update packages.<br>Obtains the system update result.|
|allowed_usb_devices|[usbManager.addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices)<br>[usbManager.removeAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagerremoveallowedusbdevices)<br>[usbManager.getAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagergetallowedusbdevices)|Adds allowed USB devices.<br>Removes allowed USB devices.<br>Obtains allowed USB devices.|
|usb_read_only|[usbManager.setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy)<br>[usbManager.getUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagergetusbstoragedeviceaccesspolicy)|Sets the USB storage device access policy.<br>Obtains the USB storage device access policy.|
|disallowed_usb_devices|[usbManager.addDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14)<br>[usbManager.removeDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagerremovedisallowedusbdevices14)<br>[usbManager.getDisallowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanagergetdisallowedusbdevices14)|Adds disallowed USB device types.<br>Removes disallowed USB device types.<br>Obtains disallowed USB device types.|
