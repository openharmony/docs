# EnterpriseAdminExtentionAbility

EnterpriseAdminExtentionAbility模块提供企业管理员应用扩展相关接口。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口仅可在Stage模型下使用。
## 导入模块

```ts
import EnterpriseAdminExtentionAbility from '@ohos.EnterpriseAdminExtentionAbility'
```

## EnterpriseAdminExtentionAbility.onAdminEnabled

onAdminEnabled(): void

设备管理员被激活事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**示例：**

  ```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
    onAdminEnabled() {
    }
};
  ```

## EnterpriseAdminExtentionAbility.onAdminDisabled

onAdminDisabled(): void

设备管理员被去激活事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager

**示例：**
    

  ```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
    onAdminDisabled() {
    }
};
  ```