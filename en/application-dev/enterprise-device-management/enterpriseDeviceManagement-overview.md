# Enterprise Device Management Overview

## Introduction
MDM Kit provides APIs to implement system-level management and configuration of enterprise employee devices. For example, the IT personnel can install enterprise applications, set security policies, set enterprise email addresses, access enterprise networks, and remotely restore factory settings (to clear lost or stolen device data) for employee devices.

## Developing Enterprise Management Applications

### Basic Concepts
- Device administrator application: <!--RP1-->a system application with the [EnterpriseAdminExtensionAbility](enterprise-extensionAbility.md)<!--RP1End-->.

### Constraints
- Only the stage model is supported.

### Environment Setup
- DevEco Studio: Download DevEco Studio from its official website and perform related configuration.<!--Del-->
- To call system interfaces, you need to use ohos-sdk-full. For details, see [Switching to Full SDK](../faqs/full-sdk-switch-guide.md).<!--DelEnd-->

### How to Develop

1. Use DevEco Studio to create a project.<!--Del-->

2. Replace public SDK with full SDK if system APIs need to be called. In addition, set the **app-feature** field to **hos_system_app** in the [application signature file](../security/AccessToken/determine-application-mode.md#requesting-permissions-for-system_basic-applications).<!--DelEnd-->

3. Create an EnterpriseAdminExtensionAbility. For details, see <!--RP1-->[EnterpriseAdminExtensionAbility Development](enterprise-extensionAbility.md)<!--RP1End-->.

4. Declare the permissions required. Before declaring the required permissions, ensure that the [basic principles for using permissions](../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. Then, declare the required permissions in the [ACL](../security/AccessToken/declare-permissions-in-acl.md).

### API Reference

> **NOTE**
>
> - For details about the APIs, see:
- [@ohos.enterprise.accountManager (Account Management)](../reference/apis-mdm-kit/js-apis-enterprise-accountManager.md)
- [@ohos.enterprise.adminManager (Enterprise Device Management)](../reference/apis-mdm-kit/js-apis-enterprise-adminManager.md)
- [@ohos.enterprise.applicationManager (Application Management)](../reference/apis-mdm-kit/js-apis-enterprise-applicationManager.md)
- [@ohos.enterprise.bluetoothManager (Bluetooth Management)](../reference/apis-mdm-kit/js-apis-enterprise-bluetoothManager.md)
- [@ohos.enterprise.browser (Browser Management)](../reference/apis-mdm-kit/js-apis-enterprise-browser.md)
- [@ohos.enterprise.bundleManager (Bundle Management)](../reference/apis-mdm-kit/js-apis-enterprise-bundleManager.md)
- [@ohos.enterprise.deviceControl (Device Control Management)](../reference/apis-mdm-kit/js-apis-enterprise-deviceControl.md)
- [@ohos.enterprise.deviceInfo (Device Information Management)](../reference/apis-mdm-kit/js-apis-enterprise-deviceInfo.md)
- [@ohos.enterprise.deviceSettings (Device Settings Management)](../reference/apis-mdm-kit/js-apis-enterprise-deviceSettings.md)
- [@ohos.enterprise.locationManager (Location Service Management)](../reference/apis-mdm-kit/js-apis-enterprise-locationManager.md)
- [@ohos.enterprise.networkManager (Network Management)](../reference/apis-mdm-kit/js-apis-enterprise-networkManager.md)
- [@ohos.enterprise.restrictions (Restrictions)](../reference/apis-mdm-kit/js-apis-enterprise-restrictions.md)
- [@ohos.enterprise.securityManager (Security Management)](../reference/apis-mdm-kit/js-apis-enterprise-securityManager.md)
- [@ohos.enterprise.systemManager (System Management)](../reference/apis-mdm-kit/js-apis-enterprise-systemManager.md)
- [@ohos.enterprise.usbManager (USB Management)](../reference/apis-mdm-kit/js-apis-enterprise-usbManager.md)
- [@ohos.enterprise.wifiManager (Wi-Fi Management)](../reference/apis-mdm-kit/js-apis-enterprise-wifiManager.md)
- [@ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)](../reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md)<!--Del-->
- [@ohos.enterprise.accountManager (Account Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-accountManager-sys.md)
- [@ohos.enterprise.adminManager (Enterprise Device Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-adminManager-sys.md)
- [@ohos.enterprise.applicationManager (Application Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-applicationManager-sys.md)
- [@ohos.enterprise.bluetoothManager (Bluetooth Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-bluetoothManager-sys.md)
- [@ohos.enterprise.browser (Browser Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-browser-sys.md)
- [@ohos.enterprise.bundleManager (Bundle Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-bundleManager-sys.md)
- [@ohos.enterprise.dateTimeManager (System Time Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md)
- [@ohos.enterprise.deviceControl (Device Control) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-deviceControl-sys.md)
- [@ohos.enterprise.deviceInfo (Device Information Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-deviceInfo-sys.md)
- [@ohos.enterprise.deviceSettings (Device Settings) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-deviceSettings-sys.md)
- [@ohos.enterprise.networkManager (Network Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-networkManager-sys.md)
- [@ohos.enterprise.restrictions (Restrictions) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-restrictions-sys.md)
- [@ohos.enterprise.securityManager (Security Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-securityManager-sys.md)
- [@ohos.enterprise.usbManager (USB Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-usbManager-sys.md)
- [@ohos.enterprise.wifiManager (Wi-Fi Management) (System API)](../reference/apis-mdm-kit/js-apis-enterprise-wifiManager-sys.md)<!--DelEnd-->
