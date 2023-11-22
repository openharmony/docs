# AutoFillExtensionContext 

AutoFillExtensionContext模块是AutoFillExtensionAbility的上下文环境，继承自[ExtensionContext](js-apis-inner-application-extensionContext.md)。

> **说明：**
> 
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 使用说明

在使用AutoFillExtensionContext的功能前，需要通过AutoFillExtensionAbility子类实例获取。

```ts
import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onCreate() {
        let AutoFillExtensionContext = this.context;
    }
}
```
