# FormExtensionContext

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=01c11bd0ed8d410f6879cbb6403794eb83930561 translatedAt=2026-07-31T08:26:09.772Z pushedAt=2026-07-31T09:14:33.416Z -->

The FormExtensionContext module provides APIs and capabilities of FormExtensionAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## FormExtensionContext

The FormExtensionContext module is the context of [FormExtensionAbility](js-apis-app-form-formExtensionAbility.md). It inherits from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md) and is used to obtain context information related to widgets. It is applicable to widget development scenarios.

**System capability**: SystemCapability.Ability.Form

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

## How to Use

FormExtensionContext is mainly used to query information about the associated FormExtensionAbility, module configuration information, and HAP information. You can use the corresponding information based on the service requirements.

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
    console.info("current language is:", this.context.config.language);
    return formBindingData.createFormBindingData(formData);
  }
};
```