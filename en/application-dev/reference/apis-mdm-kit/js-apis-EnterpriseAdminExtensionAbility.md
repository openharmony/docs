# @ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)

The **EnterpriseAdminExtensionAbility** module provides extended enterprise device management capabilities.

To have the capabilities provided by this module, for example, to receive a notification when a device administrator application is enabled or disabled, you need to create an **EnterpriseAdminExtensionAbility** instance for the enterprise administrator application and overload related APIs.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - The APIs of this module can be used only in the stage model.
> 

## Modules to Import

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit'
```

## EnterpriseAdminExtensionAbility.onAdminEnabled

onAdminEnabled(): void

Called when a device administrator application is enabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
  }
};
```

## EnterpriseAdminExtensionAbility.onAdminDisabled

onAdminDisabled(): void

Called when a device administrator application is disabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminDisabled() {
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleAdded

onBundleAdded(bundleName: string): void

Called when applications are installed. The application bundle name is included. You should register the **MANAGED_EVENT_BUNDLE_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application installed.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleAdded<sup>14+</sup>

onBundleAdded(bundleName: string, accountId: number): void

Called when applications are installed. The application bundle name and account ID are included. You should register the **MANAGED_EVENT_BUNDLE_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application installed.|
| accountId | number | Yes   | Account ID of the application installed.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string, accountId?: number) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}, accountId: ${accountId}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleRemoved

onBundleRemoved(bundleName: string): void

Called when applications are uninstalled. The application bundle name is included. You should register the **MANAGED_EVENT_BUNDLE_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application uninstalled.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleRemoved(bundleName: string) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleRemoved<sup>14+</sup>

onBundleRemoved(bundleName: string, accountId: number): void

Called when applications are uninstalled. The application bundle name and account ID are included. You should register the **MANAGED_EVENT_BUNDLE_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application uninstalled.|
| accountId | number | Yes   | Account ID of the application uninstalled.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleRemoved(bundleName: string, accountId?: number) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}, accountId: ${accountId}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStart

onAppStart(bundleName: string): void

Called when an application is started. You should register the **MANAGED_EVENT_APP_START** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application started.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStart(bundleName: string) {
    console.info(`Succeeded in calling onAppStart callback, started bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStop

onAppStop(bundleName: string): void

Called when an application is stopped. You should register the **MANAGED_EVENT_APP_STOP** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application stopped.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStop(bundleName: string) {
    console.info(`Succeeded in calling onAppStop callback, stopped bundle name : ${bundleName}`);
  }
};
```
## EnterpriseAdminExtensionAbility.onSystemUpdate

onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo): void

Called to report a system update event. You should register the **MANAGED_EVENT_SYSTEM_UPDATE** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name          | Type                                                        | Mandatory| Description                |
| ---------------- | ------------------------------------------------------------ | ---- | -------------------- |
| systemUpdateInfo | [systemManager.SystemUpdateInfo](js-apis-enterprise-systemManager.md#systemupdateinfo) | Yes  | Information about the version update.|

**Example**

```ts
import { systemManager } from '@kit.MDMKit';
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo) {
    console.info(`Succeeded in calling onSystemUpdate callback, version name  : ${systemUpdateInfo.versionName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onStart

onStart(): void

Called when EnterpriseAdminExtensionAbility starts.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onStart() {
    console.info(`Succeeded in calling onStart callback.`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAccountAdded<sup>18+</sup>

onAccountAdded(accountId: number): void

Called when a system account is added. You should register the **MANAGED_EVENT_ACCOUNT_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | Yes   | Account ID added.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountAdded(accountId: number) {
    console.info(`Succeeded in calling onAccountAdded callback, added accountId: ${accountId}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAccountSwitched<sup>18+</sup>

onAccountSwitched(accountId: number): void

Called when the system account is switched. You should register the **MANAGED_EVENT_ACCOUNT_SWITCHED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | Yes   | Account ID switched.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountSwitched(accountId: number) {
    console.info(`Succeeded in calling onAccountSwitched callback, switched accountId: ${accountId}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAccountRemoved<sup>18+</sup>

onAccountRemoved(accountId: number): void

Called when the system account is removed. You should register the **MANAGED_EVENT_ACCOUNT_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync).

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | Yes   | Account ID removed.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountRemoved(accountId: number) {
    console.info(`Succeeded in calling onAccountRemoved callback, removed accountId: ${accountId}`);
  }
};
```
