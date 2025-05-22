# @ohos.app.ability.FenceExtensionContext (FenceExtensionContext)

The **FenceExtensionContext** class defines the context for **FenceExtensionAbility** objects. Inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md), this class provides the configuration information of **FenceExtensionAbility** objects and the API for starting them.

> **NOTE**
>
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model. 

## Modules to Import

```ts
import { FenceExtensionContext } from '@kit.LocationKit';
```

## How to Use

Before using **FenceExtensionContext**, you must first obtain a **FenceExtensionAbility** instance.

```ts
import { FenceExtensionAbility, FenceExtensionContext } from '@kit.LocationKit';

class MyFenceExtensionAbility extends FenceExtensionAbility {
  onCreate() {
    let fenceExtensionContext: FenceExtensionContext = this.context;
  }
}
```
