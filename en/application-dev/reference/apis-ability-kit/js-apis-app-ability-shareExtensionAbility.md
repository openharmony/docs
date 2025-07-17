# @ohos.app.ability.ShareExtensionAbility (Share Details Page ExtensionAbility)

ShareExtensionAbility provides extended capabilities for building share details pages. It inherits from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md). For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## When to Use

The following uses text sharing as an example. A user selects a piece of text and starts the application to be shared. The application starts the sharing template based on the sharing information and displays the data based on the sharing template content.

## Modules to Import

```ts
import { ShareExtensionAbility } from '@kit.AbilityKit';
```

## ShareExtensionAbility

ShareExtensionAbility provides extended capabilities for building share details pages. It inherits from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md).

This module allows you to create share detail pages that can receive shared content, and it places the application entry in the recommended applications area on the system share panel.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core
