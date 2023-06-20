# EnterpriseAdminExtensionAbility Development

## Introduction to EnterpriseAdminExtensionAbility

EnterpriseAdminExtensionAbility is a mandatory component for Mobile Device Management (MDM) applications. When developing MDM applications for enterprises, you need to inherit EnterpriseAdminExtensionAbility and implement MDM service logic in the EnterpriseAdminExtensionAbility instance. EnterpriseAdminExtensionAbility implements notifications of system management status changes and defines the callbacks for when a device administrator application is enabled or disabled or an application is installed or uninstalled.

## Constraints

EnterpriseAdminExtensionAbility is applicable only to enterprise administrator applications.

## Observing Activation/Deactivation of a Device Administrator Application and Installation/Removal of an Application

### Overview

**onAdminEnabled**: When an enterprise administrator or employee deploys an MDM application and activates the device administrator application, this callback is invoked to notify the MDM application that the DeviceAdmin permission is activated. The initialization policy of the MDM application can set in **onAdminEnabled**.

**onAdminDisabled**: When the device administrator application is deactivated, the callback is invoked to notify the MDM application that the DeviceAdmin permission is deactivated.

**onBundleAdded**: The enterprise administrator can subscribe to application installation and uninstallation events. When an application is installed on an enterprise device, the MDM application reports the event in this callback to notify the enterprise administrator.

**onBundleRemoved**: When an application is removed from an enterprise device, the MDM application reports the event in this callback to notify the enterprise administrator.

### Available APIs

| Class                           | API                                 | Description                        |
| ------------------------------ | ----------------------------------------- | ---------------------------- |
| EnterpriseAdminExtensionAbility | onAdminEnabled(): void                    | Called when a device administrator application is activated.  |
| EnterpriseAdminExtensionAbility | onAdminDisabled(): void                   | Called when a device administrator application is deactivated.|
| EnterpriseAdminExtensionAbility | onBundleAdded(bundleName: string): void   | Called when an application is installed on a device.            |
| EnterpriseAdminExtensionAbility | onBundleRemoved(bundleName: string): void | Called when an application is removed from a device.            |

### How to Develop

To implement EnterpriseAdminExtensionAbility, you need to activate the device administrator application and create **ExtensionAbility** in the code directory of the device administrator application. The procedure is as follows:

1. In the **ets** directory of the target module, right-click and choose **New > Directory** to create a directory named **EnterpriseExtAbility**.
2. Right-click the **EnterpriseExtAbility** directory, and choose **New > TypeScript File** to create a file named **EnterpriseExtAbility.ts**.
3. Open the **EnterpriseExtAbility.ts** file and import the **EnterpriseAdminExtensionAbility** module. Inherit the **EnterpriseAdminExtensionAbility** module to the custom class and add application notification callbacks, such as **onAdminEnabled()** and **onAdminDisabled()**. When the device administrator application is activated or deactivated, the device administrator can receive notifications.

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
           console.info("EnterpriseAdminAbility onBundleAdded bundleName:" + bundleName)
       }

       onBundleRemoved(bundleName: string) {
           console.info("EnterpriseAdminAbility onBundleRemoved bundleName" + bundleName)
       }
   };
   ```

4. Register **ServiceExtensionAbility** in the [**module.json5**](../quick-start/module-configuration-file.md) file corresponding to the project module. Set **type** to **enterpriseAdmin** and **srcEntry** to the path of the ExtensionAbility code.

   ```ts
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
  @State subscribeManagedEventMsg: string = ""
  @State unsubscribeManagedEventMsg: string = ""

  async subscribeManagedEventCallback() {
    await adminManager.subscribeManagedEvent(this.admin,
      [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED,
      adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED], (error) => {
        if (error) {
          this.subscribeManagedEventMsg = 'subscribeManagedEvent Callback::errorCode: ' + error.code + ' errorMessage: ' + error.message
        } else {
          this.subscribeManagedEventMsg = 'subscribeManagedEvent Callback::success'
        }
      })
  }

  async unsubscribeManagedEventPromise() {
    await adminManager.unsubscribeManagedEvent(this.admin,
      [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED,
      adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED]).then(() => {
      this.unsubscribeManagedEventMsg = 'unsubscribeManagedEvent Promise::success'
    }).catch((error) => {
      this.unsubscribeManagedEventMsg = 'unsubscribeManagedEvent Promise::errorCode: ' + error.code + ' errorMessage: ' + error.message
    })
  }
```

