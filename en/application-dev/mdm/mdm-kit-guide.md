# MDM Kit Development

<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=c477ff8259b331985cb9b2d88570444e2af4a044 translatedAt=2026-08-15T01:54:49.764Z pushedAt=2026-08-15T08:44:45.792Z -->

## Introduction

MDM Kit provides device management capabilities for [MDM apps](./mdm-kit-term.md#mdm-app), including enterprise device management and event listening, app management, disable management, security management, device settings, device control, device information obtaining, hardware peripheral management, system management, and network communication management. For details about the specific APIs, see <!--RP7-->[@ohos.enterprise.accountManager (Account Management)](../reference/apis-mdm-kit/js-apis-enterprise-accountManager.md)<!--RP7End-->.

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

Before declaring the required permissions, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Then, declare the permissions required by the application under **requestPermissions** in the [module.json5](../quick-start/module-configuration-file.md) file of the module of the project. Example:

<!-- @[request_permissions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/EnterpriseAdminExtensionAbility/EnterpriseAdminExtensionAbility/entry/src/main/module.json5) -->

``` JSON5
"requestPermissions": [
// ···
  {
    "name": "ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS"
  },
// ···
],
```

> **NOTE**
>
> The required permissions vary with the API to call. For details, see [@ohos.enterprise.adminManager (Administrator Permission Management)](../reference/apis-mdm-kit/js-apis-enterprise-adminManager.md) and other related APIs.
>
> <!--RP4--><!--RP4End-->

### Developing MDM Functionalities

1. Import modules. MDM Kit provides a wide variety of APIs for application management, communication management, security management, feature restriction management, system management, device settings and query, device control, and more. Import related modules based on service requirements. In this example, **adminManager** and **restrictions** are imported.

   <!-- @[import_mdm_kit](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/EnterpriseAdminExtensionAbility/EnterpriseAdminExtensionAbility/entry/src/main/ets/enterpriseadminability/EnterpriseAdminAbility.ets) -->

   ``` TypeScript
   import { adminManager, restrictions } from '@kit.MDMKit';
   ```

2. Call APIs to implement related functionalities. For example, disable Wi-Fi for devices.

   <!-- @[set_disallowed_policy_wifi](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/EnterpriseAdminExtensionAbility/EnterpriseAdminExtensionAbility/entry/src/main/ets/enterpriseadminability/EnterpriseAdminAbility.ets) -->

   ``` TypeScript
   import { adminManager, restrictions } from '@kit.MDMKit';
   // ...
   import { Want } from '@kit.AbilityKit';
   // ...
     private wantTemp: Want = {
       bundleName: 'com.example.mdmsample',
       abilityName: 'EnterpriseAdminAbility',
     };
     // ...
       try {
         restrictions.setDisallowedPolicy(this.wantTemp, restrictions.FeatureForDevice.WIFI, isDisallow);
         console.info(isDisallow ? 'disable wifi success.' : 'enable wifi success.');
         // ...
       } catch (err) {
         console.error('setDisallowedPolicy fail.');
         // ...
       }
   ```

### Debugging

The MDM APIs can be called only after the **EnterpriseAdminExtensionAbility** is enabled. During the debugging process, you can use the following hdc commands to enable and disable an **EnterpriseAdminExtensionAbility**:

```bash
# Enable a super administrator application.
hdc shell edm enable-admin -n Bundle_name -a EnterpriseAdminExtensionAbility_class_name
# Enable a BYOD device administrator application.
hdc shell edm enable-admin -n Bundle_name -a EnterpriseAdminExtensionAbility_class_name -t byod
# Starting from API version 23, this command can enable an application as a regular device administrator application. This command applies to PCs/2-in-1 devices, and an error message will be displayed if it is used on other device types.
hdc shell edm enable-admin -n Bundle_name -a EnterpriseAdminExtensionAbility_class_name -t da
# Disable an EnterpriseAdminExtensionAbility.
hdc shell edm disable-admin -n Bundle_name
```

> **NOTE**
>
> An MDM application must be installed under the primary user (with account ID 100) to be enabled properly.
>
> Only one super device administrator application can be enabled on a device.
>
> BYOD, or Bring Your Own Device, allows enterprise employees to use their own mobile devices, such as laptops, tablets, and smartphones, on premises to obtain internal information and operate authorized enterprise applications.
>
> <!--RP5--><!--RP5End-->

<!--RP6--><!--RP6End-->