# EnterpriseAdminExtensionAbility

## Introduction to EnterpriseAdminExtensionAbility

EnterpriseAdminExtensionAbility is a mandatory component for Mobile Device Management (MDM) applications. When developing MDM applications for enterprises, you need to inherit EnterpriseAdminExtensionAbility and implement MDM service logic in the EnterpriseAdminExtensionAbility instance. EnterpriseAdminExtensionAbility implements notifications of system management status changes and defines the callbacks for when a device administrator application is enabled or disabled or an application is installed or uninstalled.

## Constraints

EnterpriseAdminExtensionAbility is applicable only to enterprise administrator applications.


## Observing Activation/Deactivation of a Device Administrator Application and Installation/Uninstallation of an Application

### Overview

**onAdminEnabled**: called when an enterprise administrator or employee deploys an MDM application and enables the DeviceAdmin permission for the application. The MDM application can set the initialization policy in the **onAdminEnabled** callback.

**onAdminDisabled**: called when the system or employee disables the DeviceAdmin permission to notify the enterprise administrator that the device is no longer managed.

**onBundleAdded**: The enterprise administrator can subscribe to application installation events. When an application is installed on an enterprise device, the MDM application reports the event in this callback to notify the enterprise administrator.

**onBundleRemoved**: The enterprise administrator can subscribe to application uninstallation events. When an application is uninstalled on an enterprise device, the MDM application reports the event in this callback to notify the enterprise administrator.

### Available APIs

| Class                           | API                                 | Description                        |
| ------------------------------ | ----------------------------------------- | ---------------------------- |
| EnterpriseAdminExtensionAbility | onAdminEnabled(): void                    | Called when the device administrator application is disabled.  |
| EnterpriseAdminExtensionAbility | onAdminDisabled(): void                   | Called when the device administrator application is enabled.|
| EnterpriseAdminExtensionAbility | onBundleAdded(bundleName: string): void   | Called when the MDM application is installed.            |
| EnterpriseAdminExtensionAbility | onBundleRemoved(bundleName: string): void | Called when the MDM application is uninstalled.            |

### How to Develop

1. In the **ets** directory of the target module, right-click and choose **New > Directory** to create a directory named **EnterpriseExtAbility**.
2. Right-click the **EnterpriseExtAbility** directory and choose **New > TypeScript File** to create a file named **EnterpriseExtAbility.ts**.
3. Open the **EnterpriseExtAbility.ts** file and import the **EnterpriseAdminExtensionAbility** module. Customize a class that inherits from **EnterpriseAdminExtensionAbility** and add the required callbacks, such as **onAdminEnabled()** and **onAdminDisabled()**, When the device administrator application is activated or deactivated, the device administrator can receive notifications.

```ts
import EnterpriseAdminExtensionAbility from '@ohos.enterprise.EnterpriseAdminExtensionAbility';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
    console.info("onAdminEnabled");
  }

  onAdminDisabled() {
    console.info("onAdminDisabled");
  }
  
  onBundleAdded(bundleName: string) {
    console.info("EnterpriseAdminAbility onBundleAdded bundleName:" + bundleName);
  }

  onBundleRemoved(bundleName: string) {
    console.info("EnterpriseAdminAbility onBundleRemoved bundleName" + bundleName);
  }
};
```

4. Register **ServiceExtensionAbility** in the [**module.json5**](../quick-start/module-configuration-file.md) file corresponding to the project module. Set **type** to **enterpriseAdmin** and **srcEntry** to the path of the ExtensionAbility code.

```json
"extensionAbilities": [
      {
        "name": "ohos.samples.enterprise_admin_ext_ability",
        "type": "enterpriseAdmin",
        "exported": true,
        "srcEntry": "./ets/enterpriseextability/EnterpriseAdminAbility.ts"
      }
    ]
```

## Example

Use **subscribeManagedEvent** in the **@ohos.enterprise.adminManager** module to subscribe to application installation and removal events. When an application is installed or removed, the MDM application is notified of the event. Then, the MDM application reports the event in the callback to notify the enterprise administrator. To unsubscribe from events, use **unsubscribeManagedEvent**.

```ts
import adminManager from '@ohos.enterprise.adminManager';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

async function subscribeManagedEventCallback() {
  let admin: Want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
  }
  adminManager.subscribeManagedEvent(admin,
    [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED,
    adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED], (error) => {
      if (error) {
        console.error(`Failed to subscribe managed event. Code: ${error.code}, message: ${error.message}`);
      } else {
        console.log('Succeeded in subscribing managed event');
      }
    })
}

async function unsubscribeManagedEventPromise() {
  let admin: Want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
  }
  await adminManager.unsubscribeManagedEvent(admin,
    [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED,
    adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED]).then(() => {
    console.log('Succeeded in subscribing managed event');
  }).catch((error: BusinessError) => {
    console.error(`Failed to subscribe managed event. Code: ${error.code}, message: ${error.message}`);
  })
}
```

