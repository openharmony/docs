# @ohos.enterprise.EnterpriseAdminExtensionAbility (EnterpriseAdminExtensionAbility)

本模块提供企业管理员应用拓展能力。

企业管理员应用需要存在一个EnterpriseAdminExtensionAbility并重写相关接口，以此具备模块提供的各项能力，比如接收由系统发送的该应用被激活或者去激活的通知。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> 
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import EnterpriseAdminExtensionAbility from '@ohos.enterprise.EnterpriseAdminExtensionAbility'
```

## EnterpriseAdminExtensionAbility.onAdminEnabled

onAdminEnabled(): void

设备管理员被激活事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminEnabled() {
  }
};
```

## EnterpriseAdminExtensionAbility.onAdminDisabled

onAdminDisabled(): void

设备管理员被去激活事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAdminDisabled() {
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleAdded

onBundleAdded(bundleName: string): void

应用安装事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 安装应用Bundle名称。 |

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.log("added bundle name: " + bundleName);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleRemoved

onBundleRemoved(bundleName: string): void

应用卸载事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 卸载应用Bundle名称。 |

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.log("removed bundle name: " + bundleName);
  }
};
```
