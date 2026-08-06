# EnterpriseAdminExtensionAbility Development

<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=841ab55668f7b398f360ae4d9b2f28b8041d2ae5 translatedAt=2026-08-04T13:31:03.927Z pushedAt=2026-08-05T08:42:23.682Z -->

## Introduction

**EnterpriseAdminExtensionAbility** is an essential component for device administrator applications. When developing an MDM device administrator application, you need to create an **EnterpriseAdminExtensionAbility** instance and implement MDM service logic in this instance. **EnterpriseAdminExtensionAbility** implements notifications of system management status changes and defines the callbacks to be invoked when a device administrator application is enabled or disabled or an application is installed or uninstalled.

## Available APIs

The following are the APIs used in this development example. For more APIs and usage, see [EnterpriseAdminExtensionAbility](../../application-dev/reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md).

| API                                 | Description                        |
| ----------------------------------------- | ---------------------------- |
| [onAdminEnabled(): void](../../application-dev/reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md#onadminenabled)                    | Called when a device administrator application is enabled.  |
| [onAdminDisabled(): void](../../application-dev/reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md#onadmindisabled)                   | Called when a device administrator application is disabled.|
| [onBundleAdded(bundleName: string): void](../../application-dev/reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md#onbundleadded)   | Called when an application is installed.            |
| [onBundleRemoved(bundleName: string): void](../../application-dev/reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md#onbundleremoved) | Called when an application is uninstalled.            |
| [onDeviceAdminEnabled(bundleName: string): void](../../application-dev/reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md#ondeviceadminenabled23) | Called when a common device administrator application is enabled.|
| [onDeviceAdminDisabled(bundleName: string): void](../../application-dev/reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md#ondeviceadmindisabled23) | Called when a common device administrator application is disabled.|

## How to Develop

Create a project. The project structure is as follows.

![guide_struct_init.png](./figures/guide_struct_init.png)

Create an **ExtensionAbility** of the **EnterpriseAdmin** type, that is, an **EnterpriseAdminExtensionAbility** instance.

![guide_struct_done.png](./figures/guide_struct_done.png)

Open the **EnterpriseAdminAbility.ets** file, import the **EnterpriseAdminExtensionAbility** module, enable it to inherit from the **EnterpriseAdminExtensionAbility** module, and define callbacks, such as **onAdminEnabled()** and **onAdminDisabled()**. When the device administrator application is enabled or disabled, the callback will be invoked to receive notifications.

<!-- @[enterprise_admin_extension_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/EnterpriseAdminExtensionAbility/EnterpriseAdminExtensionAbility/entry/src/main/ets/enterpriseadminability/EnterpriseAdminAbility.ets) -->     

``` TypeScript
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';
// ...

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  // ...

  // Callback to be invoked when the device administrator application is enabled. Initialization policy can be set in this callback.
  onAdminEnabled() {
    console.info('onAdminEnabled');
    // ...
  }

  // Callback to be invoked when the device administrator application is disabled. This callback can be used to notify the enterprise administrator application that the device is no longer under management.
  onAdminDisabled() {
    console.info('onAdminDisabled');
    // ...
  }

  // Callback to be invoked when an application is installed. This callback can be used to report events.
  onBundleAdded(bundleName: string) {
    console.info('EnterpriseAdminAbility onBundleAdded bundleName:' + bundleName);
  }

  // Callback to be invoked when an application is uninstalled. This callback can be used to report events.
  onBundleRemoved(bundleName: string) {
    console.info('EnterpriseAdminAbility onBundleRemoved bundleName' + bundleName);
  }

  // Callback for standard device management app activation. You can set initialization policies in this callback.
  onDeviceAdminEnabled(bundleName: string) {
    console.info('EnterpriseAdminAbility onDeviceAdminEnabled bundleName:' + bundleName);
  }

  // Callback for standard device management app deactivation. You can notify the enterprise administrator that the device is unmanaged in this callback.
  onDeviceAdminDisabled(bundleName: string) {
    console.info('EnterpriseAdminAbility onDeviceAdminDisabled bundleName' + bundleName);
  }
};
```

In the [module.json5](../quick-start/module-configuration-file.md) file of the project module, register **EnterpriseAdminAbility** as **ExtensionAbility**, and set **type** to **enterpriseAdmin** and **srcEntry** to the code path of the **ExtensionAbility** component.

<!-- @[extension_abilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/EnterpriseAdminExtensionAbility/EnterpriseAdminExtensionAbility/entry/src/main/module.json5) -->

``` JSON5
"extensionAbilities": [
  {
    "name": "EnterpriseAdminAbility",
    "type": "enterpriseAdmin",
    "exported": true,
    "srcEntry": "./ets/enterpriseadminability/EnterpriseAdminAbility.ets"
  }
],
```

## Samples

The following sample is available for EnterpriseAdminExtensionAbility development:

- [EnterpriseAdminExtensionAbility (ArkTS)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/EnterpriseAdminExtensionAbility/EnterpriseAdminExtensionAbility)