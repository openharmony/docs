# InputMethodExtensionAbility

The **InputMethodExtensionAbility** module provides APIs for developing input methods and managing their lifecycles.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import InputMethodExtensionAbility from '@ohos.inputmethodextensionability';
```

## Attributes

**System capability**: SystemCapability.MiscServices.InputMethodFramework

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [InputMethodExtensionContext](js-apis-inputmethod-extension-context.md) | Yes| No| Context of the **InputMethodExtension**, which is inherited from **ExtensionContext**.|

## InputMethodExtensionAbility.onCreate

onCreate(want: Want): void

Called when the **InputMethodExtension** ability is started to implement initialization.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Parameters**

| Name| Type         | Mandatory| Description                            |
| ------ | ----------- | ---- | ------------------------------- |
| want   | [Want](js-apis-app-ability-want.md) | Yes  | Information related to the **InputMethodExtension** ability, including the ability name and bundle name.|

**Example**

```js
class InputMethodExt extends InputMethodExtensionAbility {
    onCreate(want) {
        console.log('onCreate, want:' + want.abilityName);
    }
}
```

## InputMethodExtensionAbility.onDestroy

onDestroy(): void

Called when this **InputMethodExtension** ability is destroyed to clear resources.

**System capability**: SystemCapability.MiscServices.InputMethodFramework

**Example**

```js
class InputMethodExt extends InputMethodExtensionAbility {
    onDestroy() {
        console.log('onDestroy');
    }
}
```
