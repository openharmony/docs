# @ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)

The **EnterpriseAdminExtensionAbility** module provides Extension abilities for enterprise administrators.

To have the capabilities provided by the module, for example, receiving the application activation or deactivation notification sent by the system, an enterprise administrator application must have an **EnterpriseAdminExtensionAbility** instance and override the APIs in it.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import EnterpriseAdminExtensionAbility from '@ohos.enterprise.EnterpriseAdminExtensionAbility'
```

## EnterpriseAdminExtensionAbility.onAdminEnabled

onAdminEnabled(): void

Called when an enterprise administrator is enabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
  }
};
```

## EnterpriseAdminExtensionAbility.onAdminDisabled

onAdminDisabled(): void

Called when an enterprise administrator is disabled.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

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

**System API**: This is a system API.

**Parameters**

| Parameter  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Name of the bundle added.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.log("added bundle name: " + bundleName);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleRemoved

onBundleRemoved(bundleName: string): void

Called when a bundle is removed.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Parameter  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Name of the bundle removed.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.log("removed bundle name: " + bundleName);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStart<sup>10+</sup>

onAppStart(bundleName: string): void

Called when an application is started.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Parameter  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application started.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStart(bundleName: string) {
    console.log("started bundle name: " + bundleName);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStop<sup>10+</sup>

onAppStop(bundleName: string): void

Called when an application is stopped.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Parameter  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | Yes   | Bundle name of the application stopped.|

**Example**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStop(bundleName: string) {
    console.log("stopped bundle name: " + bundleName);
  }
};
```
