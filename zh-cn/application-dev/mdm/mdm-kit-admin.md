# EnterpriseAdminExtensionAbility开发指南

## 概述

企业设备管理扩展能力，是设备管理应用必备组件。当开发者为企业开发设备管理应用时，需继承EnterpriseAdminExtensionAbility，在EnterpriseAdminExtensionAbility实例中实现MDM业务逻辑，EnterpriseAdminExtensionAbility实现了系统管理状态变化通知功能，并定义了管理应用激活、去激活、应用安装、卸载事件等回调接口。

### 接口说明

| 类名                            | 接口名称                                  | 描述                         |
| ------------------------------- | ----------------------------------------- | ---------------------------- |
| EnterpriseAdminExtensionAbility | onAdminEnabled(): void                    | 设备管理器应用激活回调方法   |
| EnterpriseAdminExtensionAbility | onAdminDisabled(): void                   | 设备管理器应用去激活回调方法 |
| EnterpriseAdminExtensionAbility | onBundleAdded(bundleName: string): void   | 应用安装回调方法             |
| EnterpriseAdminExtensionAbility | onBundleRemoved(bundleName: string): void | 应用卸载回调方法             |

onAdminEnabled：由企业管理员或者员工部署设备管理应用，激活设备管理器，系统通知设备管理应用设备管理应用已激活DeviceAdmin权限。设备管理应用可在onAdminEnabled回调函数中进行初始化策略设置。

onAdminDisabled：由系统或者员工去激活设备管理器，通知去激活DeviceAdmin权限，应用可以通知企业管理员设备已脱管。

onBundleAdded: 企业应用管理场景下，企业管理员订阅应用安装事件，端侧应用安装和卸载事件通知设备管理应用，设备管理应用可以在回调函数中进行事件上报，通知企业管理员。

onBundleRemoved: 企业应用管理场景下，企业管理员订阅应用卸载事件，端侧应用安装和卸载事件通知设备管理应用，设备管理应用可以在回调函数中进行事件上报，通知企业管理员。

## 开发步骤

新建一个工程后，结构如下：

![guide_struct_init.png](./figures/guide_struct_init.png)

首先，创建一个EnterpriseAdmin类型的ExtensionAbility（也就是EnterpriseAdminExtensionAbility）。

![guide_struct_done.png](./figures/guide_struct_done.png)

其次，打开新建的EnterpriseAdminAbility文件，导入EnterpriseAdminExtensionAbility模块，使其继承EnterpriseAdminExtensionAbility并加上需要的应用通知回调方法，如onAdminEnabled()、onAdminDisabled()等回调方法。当设备管理员应用被激活或者去激活时，则可以在对应回调方法中接受系统发送通知。

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit';

export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  // 设备管理器应用激活回调方法，应用可在此回调函数中进行初始化策略设置。
  onAdminEnabled() {
    console.info("onAdminEnabled");
  }

  // 设备管理器应用去激活回调方法，应用可在此回调函数中通知企业管理员设备已脱管。
  onAdminDisabled() {
    console.info("onAdminDisabled");
  }
  
  // 应用安装回调方法，应用可在此回调函数中进行事件上报，通知企业管理员。
  onBundleAdded(bundleName: string) {
    console.info("EnterpriseAdminAbility onBundleAdded bundleName:" + bundleName);
  }

  // 应用卸载回调方法，应用可在此回调函数中进行事件上报，通知企业管理员。
  onBundleRemoved(bundleName: string) {
    console.info("EnterpriseAdminAbility onBundleRemoved bundleName" + bundleName);
  }
};
```

最后，在工程Module对应的[module.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V2/module-configuration-file-0000001427744540-V2)配置文件中将EnterpriseAdminAbility注册为ExtensionAbility，type标签需要设置为“enterpriseAdmin”，srcEntry标签表示当前ExtensionAbility组件所对应的代码路径。

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

## 相关实例

针对EnterpriseAdminExtensionAbility开发，有以下相关示例可供参考：

- [企业设备管理扩展（ArkTS）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-5.0.0-Release/code/SystemFeature/ApplicationModels/EnterpriseAdminExtensionAbility)