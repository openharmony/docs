# MDM Kit Development

## Introduction

MDM Kit provides capabilities for the device administrator application, including enterprise device management and event listening, application management, feature restriction management, security management, device settings, device control, device information acquisition, hardware peripheral management, system management, and network management. For details about the APIs, see [API Reference](../reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md).

A device administrator application is an application with the [EnterpriseAdminExtensionAbility](./mdm-kit-admin.md).

## How to Develop

To develop a device administrator application, perform the following steps:

<!--RP1-->

1. Create an **EnterpriseAdminExtensionAbility** instance.

2. Declare the permissions required.

3. Develop and debug MDM functionalities.

<!--RP1End-->


<!--RP2--><!--RP2End-->

### Creating an **EnterpriseAdminExtensionAbility** Instance

For details, see [EnterpriseAdminExtensionAbility Development](mdm-kit-admin.md).

### Declaring Required Permissions

Before declaring the required permissions, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Then, declare the permissions required by the application under **requestPermissions** in the [module.json5](../quick-start/module-configuration-file.md) file of the module of the project.

Example:

```ts
"requestPermissions": [
  {
    "name": "ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN"
  },
]
```

> **NOTE**
> 
> The required permissions vary with the API to call. For details, see [Enterprise Device Management](../reference/apis-mdm-kit/js-apis-enterprise-adminManager.md) and other related APIs.
>
> <!--RP4--><!--RP4End-->

### Developing MDM Functionalities

1. Import modules. MDM Kit provides a wide variety of APIs for application management, communication management, security management, feature restriction management, intra-system management, device settings and query, device control, and more. Import related modules based on service requirements. In this example, **adminManager** and **restrictions** are imported.

   ```ts
   import { adminManager, restrictions } from '@kit.MDMKit';
   ```

2. Call APIs to implement related functionalities. For example, disable Wi-Fi for devices.

   ```ts
   import { Want } from '@kit.AbilityKit';

   let wantTemp: Want = {
     bundleName: 'com.example.xxx',
     abilityName: 'EnterpriseAdminAbility',
   };
   try {
     restrictions.setDisallowedPolicy(wantTemp, "wifi", true);
     console.info("disable wifi success.");
   } catch (error) {
     console.info("disable wifi fail.");
   }
   ```

### Debugging

The MDM APIs can be called only after the **EnterpriseAdminExtensionAbility** is enabled. During the debugging process, you can use the following hdc commands to enable and disable an **EnterpriseAdminExtensionAbility**:

```bash
# Enable a super administrator application.
hdc shell edm enable-admin -n Bundle_name -a EnterpriseAdminExtensionAbility class name
# Enable a BYOD device administrator application.
hdc shell edm enable-admin -n Bundle_name -a EnterpriseAdminExtensionAbility class name -t byod
# Disable an EnterpriseAdminExtensionAbility.
hdc shell edm disable-admin -n Bundle_name
```

> **NOTE**
>
> Only one super device administrator application can be enabled on a device.
>
> BYOD, or Bring Your Own Device, allows enterprise employees to use their own mobile devices, such as laptops, tablets, and smartphones, on premises to obtain internal information and operate authorized enterprise applications.
>
> <!--RP5--><!--RP5End-->

<!--RP6--><!--RP6End-->
