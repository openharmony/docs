# @ohos.enterprise.EnterpriseAdminExtensionAbility（企业设备管理扩展能力）

本模块提供企业设备管理扩展能力。

企业管理员应用需要存在一个EnterpriseAdminExtensionAbility并重写相关接口，以此具备模块提供的各项能力，比如接收由系统发送的该应用被激活或者去激活的通知。

> **说明：**
> 
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 
> 
> 本模块接口仅可在Stage模型下使用。
> 

## 导入模块

```ts
import { EnterpriseAdminExtensionAbility } from '@kit.MDMKit'
```

## EnterpriseAdminExtensionAbility.onAdminEnabled

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

## EnterpriseAdminExtensionAbility.onAdminDisabled

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

## EnterpriseAdminExtensionAbility.onBundleAdded

onBundleAdded(bundleName: string): void

应用安装事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 安装应用Bundle名称。 |

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleAdded(bundleName: string) {
    console.info(`Succeeded in calling onBundleAdded callback, added bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onBundleRemoved

onBundleRemoved(bundleName: string): void

应用卸载事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 卸载应用Bundle名称。 |

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onBundleRemoved(bundleName: string) {
    console.info(`Succeeded in calling onBundleRemoved callback, removed bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStart

onAppStart(bundleName: string): void

应用启动事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 启动应用Bundle名称。 |

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStart(bundleName: string) {
    console.info(`Succeeded in calling onAppStart callback, started bundle name : ${bundleName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onAppStop

onAppStop(bundleName: string): void

应用停止事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| bundleName | string | 是    | 停止应用Bundle名称。 |

**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onAppStop(bundleName: string) {
    console.info(`Succeeded in calling onAppStop callback, stopped bundle name : ${bundleName}`);
  }
};
```
## EnterpriseAdminExtensionAbility.onSystemUpdate

onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo): void

系统更新事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名           | 类型                                                         | 必填 | 说明                 |
| ---------------- | ------------------------------------------------------------ | ---- | -------------------- |
| systemUpdateInfo | [systemManager.SystemUpdateInfo](js-apis-enterprise-systemManager.md#systemupdateinfo) | 是   | 系统更新的版本信息。 |

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onSystemUpdate(systemUpdateInfo: systemManager.SystemUpdateInfo) {
    console.info(`Succeeded in calling onSystemUpdate callback, version name  : ${systemUpdateInfo.versionName}`);
  }
};
```

## EnterpriseAdminExtensionAbility.onStart

onStart(): void

EnterpriseAdminExtensionAbility启动事件回调。

**系统能力**：SystemCapability.Customization.EnterpriseDeviceManager



**示例：**

```ts
export default class EnterpriseAdminAbility extends EnterpriseAdminExtensionAbility {
  onStart() {
    console.info(`Succeeded in calling onStart callback.`);
  }
};
```
