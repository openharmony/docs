# VpnExtensionContext

VpnExtensionContext是VpnExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。

VpnExtensionContext可直接作为VpnExtension的上下文环境，提供允许访问特定于VpnExtensionAbility的资源的能力。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 使用说明

通过VpnExtensionAbility子类实例来获取。

```ts
import VpnExtensionAbility from '@ohos.app.ability.VpnExtensionAbility';

let context = getContext(this) as common.VpnExtensionContext;
```


## VpnExtensionAbility

三方VPN拓展能力。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

| 名称   | 类型                                                         | 必填 | 说明           |
|------| ------------------------------------------------------------ | ---- | -------------- |
| context | [VpnExtensionContext](js-apis-inner-application-VpnExtensionContext.md) | 是   | 指定 context。 |


### onCreate

onCreate(want: Want): void

拓展VPN启动初始化的时候进行回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                | 必填 | 说明             |
| ------ | ----------------------------------- | ---- | ---------------- |
| want   | [Want](js-apis-app-ability-want.md) | 是   | 指示要启动的信息 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| <void> | 无返回值。 |


### onDestroy

onDestroy(): void

拓展VPN销毁之前进行回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**模型约束**：此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                | 必填 | 说明             |
| ------ | ----------------------------------- | ---- | ---------------- |
| want   | [Want](js-apis-app-ability-want.md) | 是   | 指示要启动的信息 |

**返回值：**

| 类型           | 说明                    |
| -------------- | ----------------------- |
| <void> | 无返回值。 |


