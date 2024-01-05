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
