# EnterpriseAdminExtensionAbility Development

## Introduction

**EnterpriseAdminExtensionAbility** is essential to a mobile device management (MDM) application. When developing an MDM application for an enterprise, you must inherit the **EnterpriseAdminExtensionAbility** class and have the MDM service logic implemented in an **EnterpriseAdminExtensionAbility** instance. The **EnterpriseAdminExtensionAbility** class provides callbacks for the enable, disable, install, and uninstall events of a device administrator application, implementing notification of system administrator status changes.

## Constraints

- ***Function constraints***

  The APIs provided can be used only by device administrator applications.
  

## Scenarios: Listening for the Enable, Disable, Install, and Uninstall Events of a Device Administrator Application

### Overview

**onAdminEnabled**: called when the enterprise administrator or employee deploys an MDM application and enables the DeviceAdmin permission for the application. The MDM application can set the initialization policy in the **onAdminEnabled** callback.

**onAdminDisabled**: called when the system or employee disables the DeviceAdmin permission to notify the enterprise administrator that the device is no longer managed.

**onBundleAdded**: called to notify the enterprise administrator that the specified MDM application is installed on the device. In enterprise application administration settings, after the enterprise administrator subscribes to application installation and uninstallation events, the MDM application reports the events through the callbacks.

**onBundleRemoved**: called to notify the enterprise administrator that the specified MDM application is uninstalled on the device.

### Available APIs

| Class                           | API                                 | Description                        |
| :------------------------------ | ----------------------------------------- | ---------------------------- |
| EnterpriseAdminExtensionAbility | onAdminDisabled(): void                   | Called when the device administrator application is enabled.|
| EnterpriseAdminExtensionAbility | onBundleAdded(bundleName: string): void   | Called when the MDM application is installed.            |
| EnterpriseAdminExtensionAbility | onAdminEnabled(): void                    | Called when the device administrator application is disabled.  |
| EnterpriseAdminExtensionAbility | onBundleRemoved(bundleName: string): void | Called when the MDM application is uninstalled.            |

### How to Develop

To implement **EnterpriseAdminExtensionAbility**, enable the device administrator application and create an **ExtensionAbility** instance from the code directory of the device administrator application. The procedure is as follows:

1. In the **ets** directory of the target module, right-click and choose **New > Directory** to create a directory named **EnterpriseExtAbility**.
2. Right-click the **EnterpriseExtAbility** directory and choose **New > TypeScript File** to create a file named **EnterpriseExtAbility.ts**.
3. Open the **EnterpriseExtAbility.ts** file and import the **EnterpriseAdminExtensionAbility** module. Customize a class that inherits from **EnterpriseAdminExtensionAbility** and add the required callbacks, such as **onAdminEnabled()** and **onAdminDisabled()**, through which the enterprise administrator can receive notification when the device administrator application is enabled or disabled.

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

4. Register **ServiceExtensionAbility** in the [module.json5](../quick-start/module-configuration-file.md) file of the target module. Among the parameters, set **type** to **enterpriseAdmin** and **srcEntrance** to the code path of the current ExtensionAbility.

   ```ts
   "extensionAbilities": [
         {
           "name": "ohos.samples.enterprise_admin_ext_ability",
           "type": "enterpriseAdmin",
           "visible": true,
           "srcEntrance": "./ets/enterpriseextability/EnterpriseAdminAbility.ts"
         }
       ]
   ```

## Example

Use the **subscribeManagedEvent** and **unsubscribeManagedEvent** APIs in the **@ohos.enterprise.adminManager** module to subscribe to and unsubscribe from the application installation and uninstallation event, respectively. After the subscription is successful, the MDM application notifies the enterprise administrator when it is installed or uninstalled on the device.

```ts
  @State managedEvents: Array<adminManager.ManagedEvent> = [0,1]
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


