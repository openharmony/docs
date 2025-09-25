# FormExtensionContext

The FormExtensionContext module, inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md), provides the context environment for the [FormExtensionAbility](js-apis-app-form-formExtensionAbility.md).

You can use the APIs of this module to start a FormExtensionAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { FormExtensionAbility } from '@kit.FormKit';
```

## FormExtensionContext

**FormExtensionContext** is the context of [FormExtensionAbility](js-apis-app-form-formExtensionAbility.md).

**System capability**: SystemCapability.Ability.Form

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

## When to Use
FormExtensionContext provides information about a FormExtensionAbility, module, and HAP. You can use the information based on service requirements.
```ts
import { FormExtensionAbility, formBindingData } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    console.info(`FormExtensionAbility onAddForm, want: ${want.abilityName}`);
    let formData: Record<string, string> = {
      'temperature': '11c',
      'time': '11:00'
    };
    console.info("current language is: ", this.context.config.language);
    return formBindingData.createFormBindingData(formData);
  }
};
```
