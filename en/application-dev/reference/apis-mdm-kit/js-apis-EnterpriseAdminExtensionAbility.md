# @ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)

The **EnterpriseAdminExtensionAbility** module provides extended enterprise device management capabilities.

To have the capabilities provided by this module, for example, to receive a notification when a device administrator application is enabled or disabled, you need to create an **EnterpriseAdminExtensionAbility** instance for the device administrator application and overload related APIs.

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

Called when the device administrator application is enabled by the enterprise administrator or employee. Upon receiving the event notification from the system, the device administrator application can set initialization policies in this callback.

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

Called when the device administrator application is disabled by the enterprise administrator or employee. Upon receiving the event notification from the system, the device administrator application can use this callback to notify the enterprise administrator that the device is no longer under management.

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

Called when applications are installed. The application bundle name is included. You should register the **MANAGED_EVENT_BUNDLE_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application installation events. When an application is installed on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

Called when applications are installed. The application bundle name and account ID are included. You should register the **MANAGED_EVENT_BUNDLE_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application installation events. When an application is installed on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application installed.|
| accountId | number | Yes   | Account ID of the application installed.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string, accountId: number) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}, accountId: ${accountId}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleRemoved

onBundleRemoved(bundleName: string): void

Called when applications are uninstalled. The application bundle name is included. You should register the **MANAGED_EVENT_BUNDLE_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application uninstallation events. When an application is uninstalled from an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

Called when applications are uninstalled. The application bundle name and account ID are included. You should register the **MANAGED_EVENT_BUNDLE_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application uninstallation events. When an application is uninstalled from an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application uninstalled.|
| accountId | number | Yes   | Account ID of the application uninstalled.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleRemoved(bundleName: string, accountId: number) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}, accountId: ${accountId}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStart

onAppStart(bundleName: string): void

Called when an application is started. You should register the **MANAGED_EVENT_APP_START** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application start events. When an application is started on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

Called when an application is stopped. You should register the **MANAGED_EVENT_APP_STOP** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application stop events. When an application is stopped on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

Called to report a system update event. You should register the **MANAGED_EVENT_SYSTEM_UPDATE** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application update events. When an application is updated on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

Called when a system account is added. You should register the **MANAGED_EVENT_ACCOUNT_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to system account addition events. When a system account is added on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

Called when the system account is switched. You should register the **MANAGED_EVENT_ACCOUNT_SWITCHED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to system account switch events. When a system account is switched on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

Called when the system account is removed. You should register the **MANAGED_EVENT_ACCOUNT_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to system account remove events. When a system account is removed from an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

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

## EnterpriseAdminExtensionAbility.onKioskModeEntering<sup>20+</sup>

onKioskModeEntering(bundleName: string, accountId: number): void

Called when an application enters the kiosk mode. This callback contains the application bundle name and account ID.

Kiosk mode is a system-level runtime mode that restricts a device to a single application or a set of applications. It controls the lock screen, status bar, gestures, and key features to prevent users from launching other applications or performing other operations on the device.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application that enters the kiosk mode.|
| accountId | number | Yes   | Account ID of the application that enters the kiosk mode.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onKioskModeEntering(bundleName: string, accountId: number): void {
    console.info(`Succeeded in calling onKioskModeEntering callback, bundleName:${bundleName}, accountId:${accountId}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onKioskModeExiting<sup>20+</sup>

onKioskModeExiting(bundleName: string, accountId: number): void

Called when an application exits the kiosk mode. This callback contains the application bundle name and account ID.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application that exits the kiosk mode.|
| accountId | number | Yes   | Account ID of the application that exits the kiosk mode.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onKioskModeExiting(bundleName: string, accountId: number): void {
    console.info(`Succeeded in calling onKioskModeExiting callback, bundleName:${bundleName}, accountId:${accountId}`);
  }
};
```
