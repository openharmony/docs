# DriverExtensionContext

The **DriverExtensionContext** module provides the context of **DriverExtensionAbility**. It inherits from **ExtensionContext**.

The **DriverExtensionContext** module provides the operations that need to be actively initiated in the **DriverExtensionAbility** implementation.

> **NOTE**
> 
>  - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## How to Use

Before using **DriverExtensionContext**, you need to obtain it through a **DriverExtensionAbility** child class instance.

```ts
  import { DriverExtensionAbility, DriverExtensionContext } from '@kit.DriverDevelopmentKit';

  let context : DriverExtensionContext | undefined;
  class EntryAbility extends DriverExtensionAbility {
    onInit() {
      context = this.context; // Obtain DriverExtensionContext.
    }
  }
```

## DriverExtensionContext.updateDriverState

updateDriverState(): void;

Updates the driver state. This interface is reserved and does not provide specific functionality currently.

**System capability**: SystemCapability.Driver.ExternalDevice

**Example**

  ```ts
  if (context != null) {
    context.updateDriverState();
  }
  ```
