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

Called when a bundle is added.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Name of the bundle added.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleRemoved

onBundleRemoved(bundleName: string): void

Called when a bundle is removed.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Name of the bundle removed.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleRemoved(bundleName: string) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStart

onAppStart(bundleName: string): void

Called when an application is started.

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

Called when an application is stopped.

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

Called to report a system update event.

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
