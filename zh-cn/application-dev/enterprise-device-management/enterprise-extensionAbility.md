# EnterpriseAdminExtensionAbility

## EnterpriseAdminExtensionAbility简介

企业设备管理扩展能力，是MDM（Mobile Device Management）应用必备组件。当开发者为企业开发MDM应用时，需继承EnterpriseAdminExtensionAbility，在EnterpriseAdminExtensionAbility实例中实现MDM业务逻辑，EnterpriseAdminExtensionAbility实现了系统管理状态变化通知功能，并定义了管理应用激活、去激活、应用安装、卸载事件等回调接口。

## 约束与限制

  仅支持设备管理员应用使用。

## 场景：监听设备管理器激活、去激活、应用安装、卸载事件

### 概述

onAdminEnabled：由企业管理员或者员工部署MDM应用，激活设备管理器，系统通知MDM应用已激活DeviceAdmin权限。MDM应用可在onAdminEnabled回调函数中进行初始化策略设置。

onAdminDisabled：由系统或者员工去激活设备管理器，通知去激活DeviceAdmin权限，应用可以通知企业管理员设备已脱管。

onBundleAdded:  企业应用管理场景下，企业管理员订阅应用安装事件，端侧应用安装和卸载事件通知MDM应用，MDM应用可以在回调函数中进行事件上报，通知企业管理员。

onBundleRemoved: 企业应用管理场景下，企业管理员订阅应用卸载事件，端侧应用安装和卸载事件通知MDM应用，MDM应用可以在回调函数中进行事件上报，通知企业管理员。

### 接口说明

| 类名                            | 接口名称                                  | 描述                         |
| :------------------------------ | ----------------------------------------- | ---------------------------- |
| EnterpriseAdminExtensionAbility | onAdminEnabled(): void                    | 设备管理器应用激活回调方法   |
| EnterpriseAdminExtensionAbility | onAdminDisabled(): void                   | 设备管理器应用去激活回调方法 |
| EnterpriseAdminExtensionAbility | onBundleAdded(bundleName: string): void   | 应用安装回调方法             |
| EnterpriseAdminExtensionAbility | onBundleRemoved(bundleName: string): void | 应用卸载回调方法             |

### 开发步骤

1. 在工程Module对应的ets目录下，右键选择“New > Directory”，新建一个目录并命名为EnterpriseExtAbility。
2. 在EnterpriseExtAbility目录，右键选择“New > ArkTS File”，新建一个文件并命名为EnterpriseExtAbility.ets。
3. 打开EnterpriseExtAbility.ets文件，导入EnterpriseAdminExtensionAbility模块，自定义类继承EnterpriseAdminExtensionAbility并加上需要的应用通知回调方法，如onAdminEnabled()、onAdminDisabled()等回调方法。当设备管理员应用被激活或者去激活时，则可以在对应回调方法中接受系统发送通知。

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
    console.info("EnterpriseAdminAbility onBundleAdded bundleName:" + bundleName);
  }

  onBundleRemoved(bundleName: string) {
    console.info("EnterpriseAdminAbility onBundleRemoved bundleName" + bundleName);
  }
};
```

​	4.在工程Module对应的[module.json5](../quick-start/module-configuration-file.md)配置文件中注册ServiceExtensionAbility，type标签需要设置为“enterpriseAdmin”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

```json
"extensionAbilities": [
      {
        "name": "ohos.samples.enterprise_admin_ext_ability",
        "type": "enterpriseAdmin",
        "exported": true,
        "srcEntry": "./ets/enterpriseextability/EnterpriseAdminAbility.ets"
      }
    ]
```

## 使用示例

通过@ohos.enterprise.adminManager模块中的subscribeManagedEvent接口进行企业设备管理事件的订阅，订阅应用安装、卸载事件。当订阅成功后，端侧应用安装和卸载事件通知MDM应用，MDM应用可以在回调函数中进行事件上报，通知企业管理员。并可以通过unsubscribeManagedEvent接口进行企业设备管理事件的去订阅。

```ts
import adminManager from '@ohos.enterprise.adminManager';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

async function subscribeManagedEventCallback() {
  let admin: Want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
  }
  adminManager.subscribeManagedEvent(admin,
    [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED,
    adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED], (error) => {
      if (error) {
        console.error(`Failed to subscribe managed event. Code: ${error.code}, message: ${error.message}`);
      } else {
        console.log('Succeeded in subscribing managed event');
      }
    })
}

async function unsubscribeManagedEventPromise() {
  let admin: Want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
  }
  await adminManager.unsubscribeManagedEvent(admin,
    [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED,
    adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED]).then(() => {
    console.log('Succeeded in subscribing managed event');
  }).catch((error: BusinessError) => {
    console.error(`Failed to subscribe managed event. Code: ${error.code}, message: ${error.message}`);
  })
}
```

## 相关实例

针对EnterpriseAdminExtensionAbility开发，有以下相关示例可供参考：

- [企业设备管理扩展（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.1-Release/code/SystemFeature/ApplicationModels/EnterpriseAdminExtensionAbility)
