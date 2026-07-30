# @ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides the [enterprise device management extension ability](../../mdm/mdm-kit-term.md#enterpriseadminextensionability) and is the core component of the enterprise device administrator application.

**Main functions**:
- Provides lifecycle management capabilities for device administrator applications (enabling, disabling, startup, and so on).
- Provides application lifecycle event listening capabilities (installation, uninstallation, startup, stop, update).
- Provides system account management event listening capabilities (account addition, switch, removal).
- Provides system-level event callbacks for Kiosk mode, key events, log collection, and system updates.
- Provides policy change event listening capabilities.

**Use cases:** Enterprise device administrator application development, enterprise application lifecycle management, device security control, account management, and device O&M monitoring.

To have the capabilities provided by this module, for example, to receive a notification when a device administrator application is enabled or disabled, you need to create an **EnterpriseAdminExtensionAbility** instance for the device administrator application and overload related APIs.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the stage model.
> 

## Modules to Import

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';
```

## EnterpriseAdminExtensionAbility

**EnterpriseAdminExtensionAbility** is an essential component for device administrator applications. When developing an MDM device administrator application, you need to create an **EnterpriseAdminExtensionAbility** instance and implement MDM service logic in this instance. **EnterpriseAdminExtensionAbility** implements notifications of system management status changes and defines the callbacks to be invoked when a device administrator application is enabled or disabled or an application is installed or uninstalled.

### Properties

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context<sup>23+</sup> | [EnterpriseAdminExtensionContext](js-apis-application-EnterpriseAdminExtensionContext.md) | No| No| Context of **EnterpriseAdminExtensionAbility**. It inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### onAdminEnabled

onAdminEnabled(): void

Called when the device administrator application is enabled. After an enterprise administrator or employee deploys and enables the device administrator application, the system notifies the device administrator application that the admin permission has been granted. The device administrator application can initialize policies within this callback. No registration is required. This callback is triggered by default after the device administrator application is enabled.

**Differences from onDeviceAdminEnabled:**
- **onAdminEnabled**: Triggered when the device administrator application itself is enabled, and used for the device administrator application to initialize its own policies.
- **onDeviceAdminEnabled**: Triggered when a super device administrator application listens for the enabling of a normal device administrator application, and used for the super device administrator application to manage normal device administrator applications.

You should choose the appropriate method based on the application type and listening scenario: normal device administrator applications should use **onAdminEnabled**, while super device administrator applications listening for the enabling of other applications should use **onDeviceAdminEnabled**.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
    console.info(`Succeeded in calling onAdminEnabled callback.`);
  }
}
```

### onAdminDisabled

onAdminDisabled(): void

Called when the device administrator application is disabled. After an enterprise administrator or employee disables the device administrator application, the system notifies the application that the admin permission has been revoked. The device administrator application can use this callback to notify the enterprise administrator that the device is no longer under management. No registration is required. This callback is triggered by default after the device administrator application is disabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminDisabled() {
    console.info(`Succeeded in calling onAdminDisabled callback.`);
  }
}
```

### onBundleAdded

onBundleAdded(bundleName: string): void

Called when applications are installed. The application bundle name is included. You should register the **MANAGED_EVENT_BUNDLE_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application installation events. When an application is installed on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application installed.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}`);
  }
}
```

### onBundleAdded<sup>14+</sup>

onBundleAdded(bundleName: string, accountId: number): void

Called when applications are installed. The application bundle name and account ID are included. You should register the **MANAGED_EVENT_BUNDLE_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application installation events. When an application is installed on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application installed.|
| accountId | number | Yes   | Account ID of the application installed.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  // Since there is another callback method with the same name onBundleAdded(bundleName: string) that does not have the accountId parameter, accountId must be marked as optional in actual invocations. Please refer to the sample code for the proper syntax. Removing the question mark (?) following accountId will cause a compilation error.
  onBundleAdded(bundleName: string, accountId?: number) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}, accountId: ${accountId}`);
  }
}
```

### onBundleRemoved

onBundleRemoved(bundleName: string): void

Called when applications are uninstalled. The application bundle name is included. You should register the **MANAGED_EVENT_BUNDLE_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application uninstallation events. When an application is uninstalled from an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application uninstalled.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleRemoved(bundleName: string) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}`);
  }
}
```

### onBundleRemoved<sup>14+</sup>

onBundleRemoved(bundleName: string, accountId: number): void

Called when applications are uninstalled. The application bundle name and account ID are included. You should register the **MANAGED_EVENT_BUNDLE_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application uninstallation events. When an application is uninstalled from an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application uninstalled.|
| accountId | number | Yes   | Account ID of the application uninstalled.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  // Since there is another callback method with the same name onBundleRemoved(bundleName: string) that does not have the accountId parameter, accountId must be marked as optional in actual invocations. Please refer to the sample code for the proper syntax. Removing the question mark (?) following accountId will cause a compilation error.
  onBundleRemoved(bundleName: string, accountId?: number) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}, accountId: ${accountId}`);
  }
}
```

### onAppStart

onAppStart(bundleName: string): void

Called when an application is started. You should register the **MANAGED_EVENT_APP_START** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application start events. When an application is started on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application started.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_APP_START];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStart(bundleName: string) {
    console.info(`Succeeded in calling onAppStart callback, started bundle name : ${bundleName}`);
  }
}
```

### onAppStop

onAppStop(bundleName: string): void

Called when an application is stopped. You should register the **MANAGED_EVENT_APP_STOP** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application stop events. When an application is stopped on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application stopped.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_APP_STOP];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStop(bundleName: string) {
    console.info(`Succeeded in calling onAppStop callback, stopped bundle name : ${bundleName}`);
  }
}
```
### onSystemUpdate

onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo): void

Called to report a system update event. You should register the **MANAGED_EVENT_SYSTEM_UPDATE** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to application update events. When an application is updated on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name          | Type                                                        | Mandatory| Description                |
| ---------------- | ------------------------------------------------------------ | ---- | -------------------- |
| systemUpdateInfo | [systemManager.SystemUpdateInfo](js-apis-enterprise-systemManager.md#systemupdateinfo) | Yes  | System update information, which is used to notify the device administrator application of the system version update information.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager, systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_SYSTEM_UPDATE];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo) {
    console.info(`Succeeded in calling onSystemUpdate callback, version name  : ${systemUpdateInfo.versionName}`);
  }
}
```

### onStart

onStart(): void

Called when EnterpriseAdminExtensionAbility starts.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onStart() {
    console.info(`Succeeded in calling onStart callback.`);
  }
}
```

### onAccountAdded<sup>18+</sup>

onAccountAdded(accountId: number): void

Called when a system account is added. You should register the **MANAGED_EVENT_ACCOUNT_ADDED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to system account add events. When a system account is added to an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | Yes   | Account ID added.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_ACCOUNT_ADDED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountAdded(accountId: number) {
    console.info(`Succeeded in calling onAccountAdded callback, added accountId: ${accountId}`);
  }
}
```

### onAccountSwitched<sup>18+</sup>

onAccountSwitched(accountId: number): void

Called when the system account is switched. You should register the **MANAGED_EVENT_ACCOUNT_SWITCHED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to system account switch events. When a system account is switched, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | Yes   | Account ID switched.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_ACCOUNT_SWITCHED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountSwitched(accountId: number) {
    console.info(`Succeeded in calling onAccountSwitched callback, switched accountId: ${accountId}`);
  }
}
```

### onAccountRemoved<sup>18+</sup>

onAccountRemoved(accountId: number): void

Called when the system account is removed. You should register the **MANAGED_EVENT_ACCOUNT_REMOVED** event through [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). The enterprise administrator application can subscribe to system account removal events. When a system account is removed, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| accountId | number | Yes   | Account ID removed.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_ACCOUNT_REMOVED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAccountRemoved(accountId: number) {
    console.info(`Succeeded in calling onAccountRemoved callback, removed accountId: ${accountId}`);
  }
}
```

### onKioskModeEntering<sup>20+</sup>

onKioskModeEntering(bundleName: string, accountId: number): void

Called when an application enters the kiosk mode. This callback contains the application bundle name and account ID.

Kiosk mode is a system-level runtime mode that restricts a device to a single application or a set of applications. It controls the lock screen, status bar, gestures, and key features to prevent users from launching other applications or performing other operations on the device.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

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
}
```

### onKioskModeExiting<sup>20+</sup>

onKioskModeExiting(bundleName: string, accountId: number): void

Called when an application exits the kiosk mode. This callback contains the application bundle name and account ID.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

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
}
```

### onMarketAppInstallResult<sup>22+</sup>

onMarketAppInstallResult(bundleName: string, result: common.InstallationResult): void

Called when an application is installed via the [bundleManager.installMarketApps](./js-apis-enterprise-bundleManager.md#bundlemanagerinstallmarketapps22) API. This callback contains the application bundle name and installation result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.
  
**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Application bundle name on AppGallery.|
| result | [common.InstallationResult](./js-apis-enterprise-common.md#installationresult) | Yes   | Installation status of an application on AppGallery, including the installation success or failure.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, common } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onMarketAppInstallResult(bundleName: string, result: common.InstallationResult): void {
    console.info(`Succeeded in calling onMarketAppInstallResult callback, bundleName:${bundleName}, result:${result}`);
  }
}
```

### onDeviceAdminEnabled<sup>23+</sup>

onDeviceAdminEnabled(bundleName: string): void

Called only for the super device administrator application when the device administrator application is enabled. After an enterprise administrator or employee deploys and enables the device administrator application, the system notifies the super device administrator application that the admin permission has been granted. The super device administrator application can initialize policies within this callback. No registration is required. This callback is triggered by default after the device administrator application is enabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type  | Mandatory| Description              |
| ---------- | ------ | ---- | ------------------ |
| bundleName | string | Yes  | Bundle name of the application enabled.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onDeviceAdminEnabled(bundleName: string) {
  }
}
```

### onDeviceAdminDisabled<sup>23+</sup>

onDeviceAdminDisabled(bundleName: string): void

Called only for the super device administrator application when the device administrator application is disabled. After an enterprise administrator or employee disables the device administrator application, the system notifies the super device administrator application that the admin permission has been revoked. The super device administrator application can use this callback to notify the enterprise administrator that the device is no longer under management. No registration is required. This callback is triggered by default after the device administrator application is disabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type  | Mandatory| Description                  |
| ---------- | ------ | ---- | ---------------------- |
| bundleName | string | Yes  | Bundle name of the application disabled.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onDeviceAdminDisabled(bundleName: string) {
  }
}
```

### onKeyEvent<sup>23+</sup>

onKeyEvent(keyEvent: systemManager.KeyEvent): void

Defines the [key event](./js-apis-enterprise-systemManager.md#keyevent23) callback. The MDM application needs to deliver key event handling policies via the [systemManager.addKeyEventPolicies](./js-apis-enterprise-systemManager.md#systemmanageraddkeyeventpolicies23) API. When a system key event is triggered, if the event matches the delivered policy, this callback will be invoked. The callback parameter [keyEvent](./js-apis-enterprise-systemManager.md#keyevent23) contains information about currently triggered key events, which are introduced below.

Single-key event. When a single key on the device is triggered, the [onKeyEvent](#onkeyevent23) callback will be invoked twice (once on key press and once on key release). You can determine whether the key is pressed or released based on the **keyAction** property in [keyEvent](./js-apis-enterprise-systemManager.md#keyevent23). The **keyItems** property in [keyEvent](./js-apis-enterprise-systemManager.md#keyevent23) can be ignored for single-key events.

Combined-key event. Only the power button, volume up button, and volume down button can be combined. When a user presses a key combination, the callback for the subsequently pressed key will carry information about all currently pressed keys via the **keyItems** property in [keyEvent](./js-apis-enterprise-systemManager.md#keyevent23). All other response logic is consistent with that of single-key events.

Long-press event. When a single key or key combination is pressed for an extended period, the [onKeyEvent](#onkeyevent23) callback will be triggered continuously at an interval of 50 ms (the actual interval may be slightly longer depending on system status and performance). For each callback event, the **actionTime** property in [keyEvent](./js-apis-enterprise-systemManager.md#keyevent23) remains the same as the **actionTime** property in the [keyEvent](./js-apis-enterprise-systemManager.md#keyevent23) of the initial key press callback. All other response logic is consistent with that of single-key and combined key events.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| keyEvent | [systemManager.KeyEvent](./js-apis-enterprise-systemManager.md#keyevent23) | Yes   | Information about the current key event, including the key code (**keyCode**), key action (**keyAction**, such as press or release), trigger time (**actionTime**), and list of pressed keys (**keyItems**). This information is used to identify and process key operations performed by the user.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';
import { systemManager } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {

 /* This callback triggers when key press matches the listening policy delivered by the MDM app, and carries the matched key information.
  * 
  * For example:
  * 1. Callback triggered by the user's short press of the power key.
  * 1.1 Deliver the key event listening policy.
  * For details, please refer to systemManager.addKeyEventPolicies.
  * Set keyCode to 0 and keyPolicy to 1.
  * 1.2 The user short-presses the power key.
  * 1.3 The callback is triggered.
  * Result (press): onKeyEvent event:{"actionTime": 1895101259, "keyCode": 0, "keyAction": 0,
  *          "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 1895101259}]}
  *       Result (release): onKeyEvent event:{"actionTime": 1895478977, "keyCode": 0, "keyAction": 1,
  *         "keyItems": [{"pressed": false, "keyCode": 0, "downTime": 1895101259}]}
  *
  * 2. Callback triggered by the user's long press of the power key.
  * 2.1 Deliver the key event listening policy.
  * For details, please refer to systemManager.addKeyEventPolicies.
  * Set keyCode to 0 and keyPolicy to 1.
  * 2.2 The user long-presses the power key.
  * 2.3 The callback is triggered.
  * Result (press): onKeyEvent event:{"actionTime": 14468236859, "keyCode": 0, "keyAction": 0,
  *         "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 14468236859}]}
  *      Result (long-press): onKeyEvent event:{"actionTime": 14468236859, "keyCode": 0, "keyAction": 0,
  *         "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 14468236859}]}
  *          ......
  *       Result (release): onKeyEvent event:{"actionTime": 14471425448, "keyCode": 0, "keyAction": 1,
  *         "keyItems": [{"pressed": false, "keyCode": 0, "downTime": 14468236859}]}
  * 
  * Key combinations can be classified into the following scenarios based on the delivery policy:
  * 3. Callback 1 triggered by the user's pressing of the key combination (power key and volume up key).
  * 3.1 Deliver the key event listening policy.
  * For details, please refer to systemManager.addKeyEventPolicies.
  * Set keyCode to 0 and keyPolicy to 1; keyCode to 1 and keyPolicy to 1.
  * 3.2 The user presses the power key and volume up key at the same time.
  * 3.3 The callback is triggered.
  * Result: The power key and volume up key are pressed at the same time (power key first).
  *      onKeyEvent event:{"actionTime": 20991450446, "keyCode": 1, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 20991432293},
  *   {"pressed": true, "keyCode": 1, "downTime": 20991450446}]}
  *      Release the two keys at the same time (volume up key first).
  *      onKeyEvent event:{"actionTime": 20590590293, "keyCode": 1, "keyAction": 1,
  *   "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 28588682984},
  *   {"pressed": false, "keyCode": 1, "downTime": 21588900860}]}
  * 
  * 4. Callback 2 triggered by the user's pressing of the key combination (power key and volume up key).
  * 4.1 Deliver the key event listening policy.
  * For details, please refer to systemManager.addKeyEventPolicies.
  * Set keyCode to 0 and keyPolicy to 1; keyCode to 1 and keyPolicy to 0.
  * 4.2 The user presses the power key and volume up key at the same time.
  * 4.3 The callback is triggered.
  * Result: The two keys are pressed at the same time (volume up key first).
  *      onKeyEvent event:{"actionTime": 28991115400, "keyCode": 0, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 1, "downTime": 28990731985},
  *   {"pressed": true, "keyCode": 0, "downTime": 20991115400}]}
  *      Release the two keys at the same time (volume up key first).
  *      onKeyEvent event:{"actionTime": 28992721560, "keyCode": 0, "keyAction": 1,
  *   "keyItems": [{"pressed": false, "keyCode": 0, "downTime": 28991115400}]}
  * 
  * 5. Callback 3 triggered by the user's pressing of the key combination (power key and volume up key).
  * 5.1 Deliver the key event listening policy.
  * For details, please refer to systemManager.addKeyEventPolicies.
  * Set keyCode to 0 and keyPolicy to 1.
  * 5.2 The user presses the power key and volume up key at the same time.
  * 5.3 The callback is triggered.
  * Result: The two keys are pressed at the same time (volume up key first).
  *      onKeyEvent event:{"actionTime": 29979014190, "keyCode": 0, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 1, "downTime": 29978420634},
  *   {"pressed": true, "keyCode": 0, "downTime": 29979014190}]}
  *      Release the two keys at the same time (power key first).
  *      onKeyEvent event:{"actionTime": 29982420773, "keyCode": 0, "keyAction": 1,
  *   "keyItems": [{"pressed": true, "keyCode": 1, "downTime": 29978420634},
  *   {"pressed": false, "keyCode": 0, "downTime": 29979014190}]}
  * 
  * 6. Callback 4 triggered by the user's pressing of the key combination (power key and navigation key - recently opened).
  * 6.1 Deliver the key event listening policy.
  * For details, please refer to systemManager.addKeyEventPolicies.
  * Set keyCode to 0 and keyPolicy to 1; keyCode to 5 and keyPolicy to 1.
  * 6.2 The user presses the power key and navigation key - recently opened at the same time.
  * 6.3 The callback is triggered.
  * Result: The two keys are pressed at the same time (each callback is executed independently).
  *      onKeyEvent event:{"actionTime": 34073626894, "keyCode": 0, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 0, "downTime": 34073626894}]}
  *      onKeyEvent event:{"actionTime": 34075144844, "keyCode": 5, "keyAction": 0,
  *   "keyItems": [{"pressed": true, "keyCode": 5, "downTime": 0}]}
  */
  onKeyEvent(keyEvent: systemManager.KeyEvent): void {
    console.info(`Succeeded in calling onKeyEvent callback, key event:${JSON.stringify(keyEvent)}`);
  }
}
```

### onLogCollected<sup>23+</sup>

onLogCollected(result: common.Result): void

Callback triggered upon completion of log collection, after a log collection task is successfully created via the [systemManager.startCollectLog](./js-apis-enterprise-systemManager.md#systemmanagerstartcollectlog23) API. It contains the log collection result.

> **NOTE**
> 
> When log collection succeeds, the app must access the sandbox directory (**/data/edm/log**) in its **EnterpriseAdminExtensionAbility** to retrieve the logs. For details about how to obtain logs, see the following sample code. After the app obtains the logs, you are advised to call [systemManager.finishLogCollected](./js-apis-enterprise-systemManager.md#systemmanagerfinishlogcollected23) to remove the collected logs.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| result | [common.Result](./js-apis-enterprise-common.md#result) | Yes   | Log collection result, used to indicate whether log collection was successful. Common values are **SUCCESS** or **FAIL**. You can use this result to determine whether to proceed with subsequent log retrieval operations.|

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { EnterpriseAdminExtensionAbility, common, systemManager } from '@kit.MDMKit';
import { fileIo as fs } from '@kit.CoreFileKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  /**
   * This callback is triggered after the MDM app invokes the systemManager.startCollectLog API to initiate a log collection task, and it carries the log collection result.
   * If result is common.Result.SUCCESS, the log collection is successful. You can obtain the logs and invoke the systemManager.finishLogCollected API to delete the collected logs.
   * If result is common.Result.FAIL, the log collection fails.
   */
  onLogCollected(result: common.Result): void {
    console.info(`Succeeded in calling onLogCollected callback, result:${result}`);
    if (result === common.Result.SUCCESS) {
      let filesDir = '/data/edm/log';
      // Replace the app sandbox path with the actual one.
      let targetPath = this.context.tempDir;
      try {
        let files: string[] = fs.listFileSync(filesDir);
        // Obtain logs from the /data/edm/log sandbox directory.
        files.forEach(value => {
          fs.copyFileSync(filesDir + '/' + value, targetPath + '/' + value);
        });
        let wantTemp: Want = {
          // Replace with actual values.
          bundleName: 'com.example.myapplication',
          abilityName: 'EnterpriseAdminAbility'
        };
        systemManager.finishLogCollected(wantTemp);
      } catch (error) {
        console.info("onLogCollected", "error: " + JSON.stringify(error))
      }
    }
    if (result === common.Result.FAIL) {
      console.error("onLogCollected", "Failed to collect log.")
    }
  }
}
```

### onStartupGuideCompleted<sup>24+</sup>

onStartupGuideCompleted(scene: common.StartupScene): void

Callback for the startup wizard completion event. You can receive this callback only after you register the **MANAGED_EVENT_STARTUP_GUIDE_COMPLETED** event through the [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync) API. The device administrator application can subscribe to startup wizard completion events. When the initial switch to a sub-user (only on PCs), OTA upgrade, and first-time startup wizard are complete on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type  | Mandatory| Description                  |
| ---------- | ------ | ---- | ---------------------- |
| scene | [common.StartupScene](./js-apis-enterprise-common.md#startupscene24) | Yes  | Specific scenario type that triggers the callback in the device setup wizard completion scenario, such as user setup completion (**USER_SETUP**), OTA upgrade completion (**OTA**), or device provisioning completion (**DEVICE_PROVISION**). You can execute corresponding service logic based on different scenarios.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_STARTUP_GUIDE_COMPLETED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onStartupGuideCompleted(scene: common.StartupScene) {
    if (scene === common.StartupScene.USER_SETUP) {
      console.info('onStartupGuideCompleted scene is USER_SETUP');
    } else if (scene === common.StartupScene.OTA) {
      console.info('onStartupGuideCompleted scene is OTA');
    } else if (scene === common.StartupScene.DEVICE_PROVISION) {
      console.info('onStartupGuideCompleted scene is DEVICE_PROVISION');
    }
  }
}
```

### onDeviceBootCompleted<sup>24+</sup>

onDeviceBootCompleted(): void

Callback for the device startup completion event. You can receive this callback only after you register the **MANAGED_EVENT_BOOT_COMPLETED** event through the [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync) API. The enterprise administrator application can subscribe to device startup completion events. When an enterprise device has finished starting up, the device administrator application reports the event in this callback to notify the enterprise administrator.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BOOT_COMPLETED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onDeviceBootCompleted() {
    console.info("EnterpriseAdminExtensionAbility onDeviceBootCompleted");
  }
}
```

### onBundleUpdated

onBundleUpdated(bundleName: string, accountId: number): void

Callback for application update events. The callback contains the application package name and user ID. You can receive this callback only after you register the **MANAGED_EVENT_BUNDLE_UPDATED** event through the [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync) API. In enterprise device management scenarios, the device administrator application can subscribe to application update events of all users. When an application update event is triggered, the device administrator application of the current user is notified. Then the device administrator application can report the event in this callback function to notify the enterprise administrator under the main user.

**Since**: 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Package name of the updated application belongs.|
| accountId | number | Yes   | ID of the user to which the updated application belongs.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_UPDATED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleUpdated(bundleName: string, accountId: number) {
    console.info(`Succeeded in calling onBundleUpdated callback, update bundle name : ${bundleName}, accountId: ${accountId}`);
  }
}
```

### onAdminPolicyChanged

onAdminPolicyChanged(event: common.PolicyChangedEvent): void

Defines the policy change event. The super device administrator application can receive this callback after registering the MANAGED_EVENT_POLICIES_CHANGED event via [adminManager.subscribeManagedEventSync](js-apis-enterprise-adminManager.md#adminmanagersubscribemanagedeventsync). In the enterprise device management scenario, when any MDM application calls an API in [Policy Change Reporting List](../../mdm/mdm-kit-appendix.md#policy-change-reporting-list), the system notifies the super device administrator application of the current user.

**Since**: 26.0.0

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| event | [common.PolicyChangedEvent](./js-apis-enterprise-common.md#policychangedevent) | Yes   | Policy change event, which contains detailed information about the policy change, such as the changed bundle name (**bundleName**), changed function name (**functionName**), changed parameters (**parameters**), and change time (**time**). The super device administrator application can perform policy audit or synchronization based on this information.|

**Example**

```ts
import { EnterpriseAdminExtensionAbility, adminManager, common } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_POLICIES_CHANGED];
try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribing managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminPolicyChanged(event: common.PolicyChangedEvent) {
    //For example, when the MDM application calls the setPasswordPolicy API to set a password policy, the output is as follows: Policy changed, bundleName : com.example.test, functionName: setPasswordPolicy, parameters: {"policy":{"complexityRegex":"^(?=.*[a-zA-Z])(?=.*\\d).{8},$","validityPeriod":1808309786000,"additionalDescription":"Must contain at least 8 characters, including digits and letters."}}, time: 1776773305379.
    console.info(`Policy changed, bundleName : ${event.bundleName}, functionName: ${event.functionName}, parameters: ${event.parameters}, time: ${event.time}.`);
  }
}
```
