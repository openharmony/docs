# Enterprise Device Management Overview (for System Applications Only)

## Overview
Enterprise Device Management APIs provide support for enterprise APIs. You can use these APIs to implement system-level management and configuration of employee devices. For example, the IT personnel can install enterprise applications, set security policies, set enterprise email addresses, access enterprise networks, and remotely restore factory settings (to clear lost or stolen device data) for employee devices.

## Developing Enterprise Management Applications

### Basic Concepts
- Device administrator application: a system application that has the [EnterpriseAdminExtensionAbility](../../application-models/enterprise-extensionAbility.md).

### Constraints
- Only the stage model is supported.

### Environment Setup
- DevEco Studio: Download DevEco Studio from its official website and perform related configuration.
- ohos-sdk-full: Obtain ohos-sdk-full. For details, see [Replacing Full SDK](../../faqs/full-sdk-switch-guide.md).

### How to Develop

1. Use DevEco Studio to create a project and replace the full SDK.

2. In the HarmonyAppProvision file, set the **app-feature** field to **hos_system_app**, which indicates an [system_basic or system_core](../../security/AccessToken/app-permission-mgmt-overview.md#application-apl) application.

3. Create [EnterpriseAdminExtensionAbility](../../application-models/enterprise-extensionAbility.md).

4. Declare the permissions required. Before requesting permissions, ensure that the [basic principles for using permissions](../../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Then, declare the required permission in the [ACL](../../security/AccessToken/declare-permissions-in-acl.md).

### API References

> **NOTE**
>
> - For details about the APIs, see:
- [@ohos.enterprise.accountManager (Account Management) (System API)](js-apis-enterprise-accountManager-sys.md)
- [@ohos.enterprise.adminManager (Enterprise Device Management) (System API)](js-apis-enterprise-adminManager-sys.md)
- [@ohos.enterprise.applicationManager (Application Management) (System API)](js-apis-enterprise-applicationManager-sys.md)
- [@ohos.enterprise.browser (Browser Management) (System API)](js-apis-enterprise-browser-sys.md)
- [@ohos.enterprise.bundleManager (Bundle Management) (System API)](js-apis-enterprise-bundleManager-sys.md)
- [@ohos.enterprise.dateTimeManager (System Time Management) (System API)](js-apis-enterprise-dateTimeManager-sys.md)
- [@ohos.enterprise.deviceControl (Device Control) (System API)](js-apis-enterprise-deviceControl-sys.md)
- [@ohos.enterprise.deviceInfo (Device Information Management) (System API)](js-apis-enterprise-deviceInfo-sys.md)
- [@ohos.enterprise.deviceSettings (Device Settings) (System API)](js-apis-enterprise-deviceSettings-sys.md)
- [@ohos.enterprise.EnterpriseAdminExtensionAbility (Enterprise Device Management ExtensionAbility) (System API)](js-apis-EnterpriseAdminExtensionAbility-sys.md)
- [@ohos.enterprise.networkManager (Network Management) (System API)](js-apis-enterprise-networkManager-sys.md)
- [@ohos.enterprise.restrictions (Restrictions) (System API)](js-apis-enterprise-restrictions-sys.md)
- [@ohos.enterprise.usbManager (USB Management) (System API)](js-apis-enterprise-usbManager-sys.md)
- [@ohos.enterprise.wifiManager (Wi-Fi Management) (System API)](js-apis-enterprise-wifiManager-sys.md)
