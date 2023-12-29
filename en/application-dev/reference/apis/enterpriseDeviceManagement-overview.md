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

2. In the [HarmonyAppProvision file](../../security/accesstoken-overview.md#application-apls), set the **app-feature** field to **hos_system_app**.

3. Create [EnterpriseAdminExtensionAbility](../../application-models/enterprise-extensionAbility.md).

4. Declare the permissions required. Before requesting permissions, ensure that the [basic principles for permission management](../../security/accesstoken-overview.md#basic-principles-for-permission-management) are met. Then, [declare the permissions](../../security/accesstoken-guidelines.md#acl).

### API Reference

> **NOTE**
>
> - For details about the APIs, see:
- [@ohos.enterprise.accountManager (Account Management)](js-apis-enterprise-accountManager.md)
- [@ohos.enterprise.adminManager (Enterprise Device Management)](js-apis-enterprise-adminManager.md)
- [@ohos.enterprise.applicationManager (Application Management)](js-apis-enterprise-applicationManager.md)
- [@ohos.enterprise.browser (Browser Management)](js-apis-enterprise-browser.md)
- [@ohos.enterprise.bundleManager (Bundle Management)](js-apis-enterprise-bundleManager.md)
- [@ohos.enterprise.dateTimeManager (System Time Management)](js-apis-enterprise-dateTimeManager.md)
- [@ohos.enterprise.deviceControl (Device Control Management)](js-apis-enterprise-deviceControl.md)
- [@ohos.enterprise.deviceInfo (Device Information Management)](js-apis-enterprise-deviceInfo.md)
- [@ohos.enterprise.deviceSettings (Device Settings Management](js-apis-enterprise-deviceSettings.md)
- [@ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)](js-apis-EnterpriseAdminExtensionAbility.md)
- [@ohos.enterprise.networkManager (Network Management)](js-apis-enterprise-networkManager.md)
- [@ohos.enterprise.restrictions (Restrictions)](js-apis-enterprise-restrictions.md)
- [@ohos.enterprise.usbManager (USB Management)](js-apis-enterprise-usbManager.md)
- [@ohos.enterprise.wifiManager (Wi-Fi Management)](js-apis-enterprise-wifiManager.md)
