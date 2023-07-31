# Enterprise Device Management Overview (for System Applications Only)

## Overview
OpenHarmony provides Enterprise Device Management APIs to support enterprise APIs. You can use the APIs to implement system-level management and configuration of employee devices. For example, the IT personnel need to install enterprise applications, set security policies, set enterprise email addresses, access enterprise networks, and remotely restore factory settings (to clear lost or stolen device data).

## Developing Enterprise Management Applications

### Basic Concepts
- Device administrator application: a system application that has the [EnterpriseAdminExtensionAbility](../../application-models/enterprise-extensionAbility.md).

### Constraints
- Only the stage model is supported.

### Environment Setup
- [Download DevEco Studio](https://developer.harmonyos.com/en/develop/deveco-studio#download) and set it up as instructed on the official website.
- [Download ohos-sdk-full](../../../release-notes/OpenHarmony-v3.2-beta2.md#acquiring-source-code-from-mirrors).

### How to Develop

1. Use DevEco Studio to create a project and [switch to full-sdk](../../faqs/full-sdk-switch-guide.md).

2. In the [HarmonyAppProvision file](../../security/accesstoken-overview.md#application-apls), set the **app-feature** field to **hos_system_app**.

3. Create [EnterpriseAdminExtensionAbility](../../application-models/enterprise-extensionAbility.md).

4. Declare the permissions required. Before requesting permissions, ensure that the [basic principles for permission management](../../security/accesstoken-overview.md#basic-principles-for-permission-management) are met. Then, [declare the permissions](../../security/accesstoken-guidelines.md#acl).

### API Reference

To implement network management and Wi-Fi management, see:

- [@ohos.enterprise.accountManager (Account Management)](js-apis-enterprise-accountManager.md)
- [@ohos.enterprise.adminManager (Enterprise Device Management)](js-apis-enterprise-adminManager.md)
- [@ohos.enterprise.applicationManager (Application Management)](js-apis-enterprise-applicationManager.md)
- [@ohos.enterprise.bundleManager (Bundle Management)](js-apis-enterprise-bundleManager.md)
- [@ohos.enterprise.dateTimeManager (System Time Management)](js-apis-enterprise-dateTimeManager.md)
- [@ohos.enterprise.deviceControl (Device Control Management)](js-apis-enterprise-deviceControl.md)
- [@ohos.enterprise.deviceInfo (Device Information Management)](js-apis-enterprise-deviceInfo.md)
- [@ohos.enterprise.deviceSettings (Device Settings Management](js-apis-enterprise-deviceSettings.md)
- [@ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)](js-apis-EnterpriseAdminExtensionAbility.md)
- [@ohos.enterprise.networkManager (Network Management)](js-apis-enterprise-networkManager.md)
- [@ohos.enterprise.restrictions (Restrictions)](js-apis-enterprise-restrictions.md)
- [@ohos.enterprise.wifiManager (Wi-Fi Management)](js-apis-enterprise-wifiManager.md)
