# ExtensionContext

The **ExtensionContext** module, inherited from **Context**, implements the context for Extension abilities.

This module provides APIs for accessing resources of a specific Extension ability. An Extension ability can use the context directly provided by **ExtensionContext** or that extended from **ExtensionContext**.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| currentHapModuleInfo | [HapModuleInfo](js-apis-bundleManager-hapModuleInfo.md) | Yes| No| Information about the HAP file.<br>(See **api\bundle\hapModuleInfo.d.ts** in the **SDK** directory.) |
| config   | [Configuration](js-apis-app-ability-configuration.md) | Yes| No| Module configuration information.<br>(See **api\@ohos.app.ability.Configuration.d.ts** in the **SDK** directory.)|
| extensionAbilityInfo | [ExtensionAbilityInfo](js-apis-bundleManager-extensionAbilityInfo.md) | Yes| No| Extension ability information.<br>(See **api\bundle\extensionAbilityInfo.d.ts** in the **SDK** directory.)|

## When to Use
**ExtensionContext** provides information about an Extension ability, module, and HAP file. You can use the information based on service requirements.

**Example**

```ts
// Singleton object GlobalContext.ts
export class GlobalContext {
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

  private constructor() {
  }

  public static getContext(): GlobalContext {
    if (!GlobalContext.instance) {
      GlobalContext.instance = new GlobalContext();
    }
    return GlobalContext.instance;
  }

  getObject(value: string): Object | undefined {
    return this._objects.get(value);
  }

  setObject(key: string, objectClass: Object): void {
    this._objects.set(key, objectClass);
  }
}
```

```ts
import { FormExtensionAbility, formBindingData } from '@kit.FormKit';
import { Want } from '@kit.AbilityKit';
import { GlobalContext } from '../GlobalContext';

export default class MyFormExtensionAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    console.log(`FormExtensionAbility onAddForm, want: ${want.abilityName}`);
    let dataObj1: Record<string, string> = {
      'temperature': '11c',
      'time': '11:00'
    };
    GlobalContext.getContext().setObject("ExtensionContext", this.context);
    let obj1: formBindingData.FormBindingData = formBindingData.createFormBindingData(dataObj1);
    return obj1;
  }
};
```
