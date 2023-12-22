# AutoFillExtensionContext 

The **AutoFillExtensionContext** module, inherited from [ExtensionContext](js-apis-inner-application-extensionContext.md), provides the context environment for the AutoFillExtensionAbility.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Usage

Before using the **AutoFillExtensionContext** module, you must define a child class that inherits from **AutoFillExtensionAbility**.

```ts
import AutoFillExtensionAbility from '@ohos.app.ability.AutoFillExtensionAbility';

class MyAutoFillExtensionAbility extends AutoFillExtensionAbility {
    onCreate() {
        let AutoFillExtensionContext = this.context;
    }
}
```
