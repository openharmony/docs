# @ohos.app.ability.ActionExtensionAbility (ExtensionAbility for Custom Actions)

The ActionExtensionAbility module provides a custom action service template. It inherits from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md). For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## When to Use

The following uses text translation as an example. You must create a request initiator and then an ActionExtensionAbility. The request initiator sends the text to be translated to the ActionExtensionAbility. The ActionExtensionAbility translates the text and sends the translated text to the request initiator.

## Modules to Import

```ts
import { ActionExtensionAbility } from '@kit.AbilityKit';
```

## ActionExtensionAbility

The ActionExtensionAbility module provides a custom action service template. It inherits from [UIExtensionAbility](js-apis-app-ability-uiExtensionAbility.md).

ActionExtensionAbility is mainly designed to handle content viewing and interaction within the host application. For example, you can add a bookmark, translate the selected text into another language, or edit an image on the current page.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore
