# 企业设备管理概述

## 概述
通过企业设备管理（Enterprise Device Management）API支持企业应用，该API提供了系统级别的管理功能，用于实现企业对员工设备的管理和配置。如在企业场景下，IT人员需要员工设备进行管理和控制，安装企业应用、设置安全策略、设置企业邮箱、企业网络接入以及远程清除（即恢复出厂默认设置）丢失或者被盗设备上的数据。

## 开发企业管理应用

### 基本概念
- 设备管理应用：<!--RP1-->具备[企业设备管理扩展能力](enterprise-extensionAbility.md)的系统应用<!--RP1End-->。

### 约束与限制
- 仅支持Stage模型

### 环境准备
- DevEco Studio可参考其官网介绍进行下载，并进行相关的配置动作。<!--Del-->
- 调用系统接口需使用ohos-sdk-full，具体请参考[如何替换full-sdk](../faqs/full-sdk-switch-guide.md)。<!--DelEnd-->

### 开发步骤

1. 使用DevEco Studio新建工程。<!--Del-->

2. 如需调用系统接口，需替换为替换full-sdk。且需在[应用签名文件](../security/AccessToken/determine-application-mode.md#system_basic等级应用申请权限的方式)中设置应用为系统应用，即app-feature字段为hos_system_app。<!--DelEnd-->

3. 创建EnterpriseAdminExtensionAbility，创建过程详情请见<!--RP1-->[EnterpriseAdminExtensionAbility开发指南](enterprise-extensionAbility.md)<!--RP1End-->。

4. 声明接口所需权限。在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。然后参考[声明ACL权限](../security/AccessToken/declare-permissions-in-acl.md)声明对应权限。

### API参考

> **说明：**
>
> - 若想进行网络管理，WiFi管理等开发，请参考以下内容。
- [@ohos.enterprise.accountManager（帐户管理）](../reference/apis-mdm-kit/js-apis-enterprise-accountManager.md)
- [@ohos.enterprise.adminManager (企业设备管理)](../reference/apis-mdm-kit/js-apis-enterprise-adminManager.md)
- [@ohos.enterprise.applicationManager（应用管理）](../reference/apis-mdm-kit/js-apis-enterprise-applicationManager.md)
- [@ohos.enterprise.bluetoothManager（蓝牙管理）](../reference/apis-mdm-kit/js-apis-enterprise-bluetoothManager.md)
- [@ohos.enterprise.browser（浏览器管理）](../reference/apis-mdm-kit/js-apis-enterprise-browser.md)
- [@ohos.enterprise.bundleManager（包管理）](../reference/apis-mdm-kit/js-apis-enterprise-bundleManager.md)
- [@ohos.enterprise.deviceControl（设备控制管理）](../reference/apis-mdm-kit/js-apis-enterprise-deviceControl.md)
- [@ohos.enterprise.deviceInfo（设备信息管理）](../reference/apis-mdm-kit/js-apis-enterprise-deviceInfo.md)
- [@ohos.enterprise.deviceSettings （设备设置管理）](../reference/apis-mdm-kit/js-apis-enterprise-deviceSettings.md)
- [@ohos.enterprise.locationManager（位置服务管理）](../reference/apis-mdm-kit/js-apis-enterprise-locationManager.md)
- [@ohos.enterprise.networkManager（网络管理）](../reference/apis-mdm-kit/js-apis-enterprise-networkManager.md)
- [@ohos.enterprise.restrictions （限制类策略）](../reference/apis-mdm-kit/js-apis-enterprise-restrictions.md)
- [@ohos.enterprise.securityManager（安全管理）](../reference/apis-mdm-kit/js-apis-enterprise-securityManager.md)
- [@ohos.enterprise.systemManager （系统管理）](../reference/apis-mdm-kit/js-apis-enterprise-systemManager.md)
- [@ohos.enterprise.usbManager（USB管理）](../reference/apis-mdm-kit/js-apis-enterprise-usbManager.md)
- [@ohos.enterprise.wifiManager（WiFi管理）](../reference/apis-mdm-kit/js-apis-enterprise-wifiManager.md)
- [@ohos.enterprise.EnterpriseAdminExtensionAbility（企业设备管理扩展能力）](../reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md)<!--Del-->
- [@ohos.enterprise.accountManager（帐户管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-accountManager-sys.md)
- [@ohos.enterprise.adminManager (企业设备管理)(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-adminManager-sys.md)
- [@ohos.enterprise.applicationManager（应用管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-applicationManager-sys.md)
- [@ohos.enterprise.bluetoothManager（蓝牙管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-bluetoothManager-sys.md)
- [@ohos.enterprise.browser（浏览器管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-browser-sys.md)
- [@ohos.enterprise.bundleManager（包管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-bundleManager-sys.md)
- [@ohos.enterprise.dateTimeManager （系统时间管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-dateTimeManager-sys.md)
- [@ohos.enterprise.deviceControl（设备控制管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-deviceControl-sys.md)
- [@ohos.enterprise.deviceInfo（设备信息管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-deviceInfo-sys.md)
- [@ohos.enterprise.deviceSettings （设备设置管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-deviceSettings-sys.md)
- [@ohos.enterprise.networkManager（网络管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-networkManager-sys.md)
- [@ohos.enterprise.restrictions （限制类策略）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-restrictions-sys.md)
- [@ohos.enterprise.securityManager（安全管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-securityManager-sys.md)
- [@ohos.enterprise.usbManager（USB管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-usbManager-sys.md)
- [@ohos.enterprise.wifiManager（WiFi管理）(系统接口)](../reference/apis-mdm-kit/js-apis-enterprise-wifiManager-sys.md)<!--DelEnd-->