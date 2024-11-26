# @ohos.InputMethodExtensionAbility (InputMethodExtensionAbility)

The **InputMethodExtensionAbility** module provides APIs for developing input methods and managing their lifecycles.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { InputMethodExtensionAbility } from '@kit.IMEKit';
```

## Attributes

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [InputMethodExtensionContext](js-apis-inputmethod-extension-context.md) | No| No| Context of the **InputMethodExtension**, which is inherited from **ExtensionContext**.|

## InputMethodExtensionAbility.onCreate

onCreate(want: Want): void

Called when the **InputMethodExtension** ability is started to implement initialization.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type         | Mandatory| Description                            |
| ------ | ----------- | ---- | ------------------------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Information related to the **InputMethodExtension** ability, including the ability name and bundle name.|

**Example**

```ts
import { InputMethodExtensionAbility } from '@kit.IMEKit';
import { Want } from '@kit.AbilityKit';
class InputMethodExt extends InputMethodExtensionAbility {
  onCreate(want: Want): void {
    console.log('onCreate, want:' + want.abilityName);
  }
}
```

## InputMethodExtensionAbility.onDestroy

onDestroy(): void

Called when this **InputMethodExtension** ability is destroyed to clear resources.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Example**

```ts
import { InputMethodExtensionAbility } from '@kit.IMEKit';
class InputMethodExt extends InputMethodExtensionAbility {
  onDestroy(): void {
    console.log('onDestroy');
  }
}
```
