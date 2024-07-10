# EnterpriseAdminExtensionAbility Development

## Introduction

**EnterpriseAdminExtensionAbility** is an essential component for device administrator applications. When developing a Mobile Device Management (MDM) application, you need to create an **EnterpriseAdminExtensionAbility** instance and implement MDM service logic in this instance. The **EnterpriseAdminExtensionAbility** instance implements notifications of system management status changes and defines the related callbacks to be invoked when a device administrator application is enabled or disabled or when an application is installed or uninstalled.

### Available APIs

| Class                           | API                                 | Description                        |
| ------------------------------- | ----------------------------------------- | ---------------------------- |
| EnterpriseAdminExtensionAbility | onAdminEnabled(): void                    | Called when a device administrator application is disabled.  |
| EnterpriseAdminExtensionAbility | onAdminDisabled(): void                   | Called when a device administrator application is disabled. |
| EnterpriseAdminExtensionAbility | onBundleAdded(bundleName: string): void   | Called when an MDM application is installed.            |
| EnterpriseAdminExtensionAbility | onBundleRemoved(bundleName: string): void | Called when an MDM application is uninstalled.            |

**onAdminEnabled**: This callback is invoked when an enterprise administrator or employee deploys an MDM application and activates the device administrator. The system notifies the device administrator application that the DeviceAdmin permission has been activated. The device administrator application can set initialization policies in the **onAdminEnabled** callback.

**onAdminDisabled**: This callback is invoked when the system or an employee deactivates the device administrator. It notifies the application that the DeviceAdmin permission is revoked. The application can inform the enterprise administrator that the device is not under management.

**onBundleAdded**: The enterprise administrator can subscribe to application installation events. When an application is installed on an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

**onBundleRemoved**: The enterprise administrator can subscribe to application uninstallation events. When an application is uninstalled from an enterprise device, the device administrator application reports the event in this callback to notify the enterprise administrator.

## How to Develop

1. Create a project. 

   The project structure is as follows:

   ![guide_struct_init.png](./figures/guide_struct_init.png)

2. Create an **ExtensionAbility** of the **EnterpriseAdmin** type, that is, an **EnterpriseAdminExtensionAbility** instance.

   ![guide_struct_done.png](./figures/guide_struct_done.png)

3. Open the **EnterpriseAdminAbility.ets** file, import the **EnterpriseAdminExtensionAbility** module, enable it to inherit from the **EnterpriseAdminExtensionAbility** module, and define callbacks such as **onAdminEnabled()** and **onAdminDisabled()**. When the device administrator application is enabled or disabled, the callback will be invoked to receive notifications.

   ```ts
   import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';
   
   export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
     // Callback to be invoked when the device administrator application is enabled. Initialization policy can be set in this callback.
     onAdminEnabled() {
       console.info("onAdminEnabled");
     }
   
     // Callback to be invoked when the device administrator application is disabled. This callback can be used to notify the enterprise administrator application that the device is no longer under management.
     onAdminDisabled() {
       console.info("onAdminDisabled");
     }
     
     // Callback to be invoked when an application is installed. This callback can be used to report events.
     onBundleAdded(bundleName: string) {
       console.info("EnterpriseAdminAbility onBundleAdded bundleName:" + bundleName);
     }
   
     // Callback to be invoked when an application is uninstalled. This callback can be used to report events.
     onBundleRemoved(bundleName: string) {
       console.info("EnterpriseAdminAbility onBundleRemoved bundleName" + bundleName);
     }
   };
   ```

4. In the [module.json5](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V2/module-configuration-file-0000001427744540-V2) file of the project module, register **EnterpriseAdminAbility** as **ExtensionAbility**, and set type to **enterpriseAdmin** and **srcEntry** to the code path of the **ExtensionAbility** component.

```ts
"extensionAbilities": [
  {
	"name": "EnterpriseAdminAbility",
	"type": "enterpriseAdmin",
	"exported": true,
	"srcEntry": "./ets/enterpriseadminability/EnterpriseAdminAbility.ets"
  }
]
```

