# @ohos.app.ability.abilityLifecycleCallback (UIAbility Lifecycle Callback Listener)

The AbilityLifecycleCallback module defines the callbacks to receive lifecycle changes of [ApplicationContext](js-apis-inner-application-applicationContext.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { AbilityLifecycleCallback } from '@kit.AbilityKit';
```

## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: UIAbility): void

Called when an ability is created.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void

Called when the window stage of an ability is created.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void

Called when the window stage of an ability gains focus.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void

Called when the window stage of an ability loses focus.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void

Called when the window stage of an ability is destroyed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void

Called when an ability is destroyed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: UIAbility): void

Called when an ability is switched from the background to the foreground.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: UIAbility): void

Called when an ability is switched from the foreground to the background.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: UIAbility): void

Called when an ability is continued on another device.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityWillCreate<sup>12+</sup>

onAbilityWillCreate?(ability: UIAbility): void

Called before the [onCreate](js-apis-app-ability-uiAbility.md#oncreate) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageWillCreate<sup>12+</sup>

onWindowStageWillCreate?(ability: UIAbility, windowStage: window.WindowStage): void

Called before the [onWindowStageCreate](js-apis-app-ability-uiAbility.md#onwindowstagecreate) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageWillDestroy<sup>12+</sup>

onWindowStageWillDestroy?(ability: UIAbility, windowStage: window.WindowStage): void

Called before the [onWindowStageDestroy](js-apis-app-ability-uiAbility.md#onwindowstagedestroy) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityWillForeground<sup>12+</sup>

onAbilityWillForeground?(ability: UIAbility): void

Called before the [onForeground](js-apis-app-ability-uiAbility.md#onforeground) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityWillDestroy<sup>12+</sup>

onAbilityWillDestroy?(ability: UIAbility): void

Called before the [onDestroy](js-apis-app-ability-uiAbility.md#ondestroy) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityWillBackground<sup>12+</sup>

onAbilityWillBackground?(ability: UIAbility): void

Called before the [onBackground](js-apis-app-ability-uiAbility.md#onbackground) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWillNewWant<sup>12+</sup>

onWillNewWant?(ability: UIAbility): void

Called before the [onNewWant](js-apis-app-ability-uiAbility.md#onnewwant) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onNewWant<sup>12+</sup>

onNewWant?(ability: UIAbility): void

Called after the [onNewWant](js-apis-app-ability-uiAbility.md#onnewwant) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityWillContinue<sup>12+</sup>

onAbilityWillContinue?(ability: UIAbility): void

Called before the [onContinue](js-apis-app-ability-uiAbility.md#oncontinue) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageWillRestore<sup>12+</sup>

onWindowStageWillRestore?(ability: UIAbility, windowStage: window.WindowStage): void

Called before the [onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onWindowStageRestore<sup>12+</sup>

onWindowStageRestore?(ability: UIAbility, windowStage: window.WindowStage): void

Called after the [onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilityWillSaveState<sup>12+</sup>

onAbilityWillSaveState?(ability: UIAbility): void

Called before the [onSaveState](js-apis-app-ability-uiAbility.md#onsavestate) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## AbilityLifecycleCallback.onAbilitySaveState<sup>12+</sup>

onAbilitySaveState?(ability: UIAbility): void

Called after the [onSaveState](js-apis-app-ability-uiAbility.md#onsavestate) callback of a UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| Ability object.|

**Example**

See [Usage of AbilityLifecycleCallback](#usage-of-abilitylifecyclecallback).

## Usage of AbilityLifecycleCallback

**Example**
GlobalContext.ts
Global context
```ts
// Construct a singleton object.
export class GlobalContext {
  private constructor() {}
  private static instance: GlobalContext;
  private _objects = new Map<string, Object>();

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

MyFirstAbility.ts
First ability of the application
```ts
import { AbilityLifecycleCallback, UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

// Import GlobalContext. Use the actual path declared.
import { GlobalContext } from '../GlobalContext';

// Declare the ability lifecycle callbacks. A listener can be registered in applicationContext only after all the callbacks are configured.
let abilityLifecycleCallback: AbilityLifecycleCallback = {
  onAbilityCreate(ability){
    console.log('AbilityLifecycleCallback onAbilityCreate.');
  },
  onWindowStageCreate(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageCreate.');
  },
  onWindowStageActive(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageActive.');
  },
  onWindowStageInactive(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageInactive.');
  },
  onWindowStageDestroy(ability, windowStage){
    console.log('AbilityLifecycleCallback onWindowStageDestroy.');
  },
  onAbilityDestroy(ability){
    console.log('AbilityLifecycleCallback onAbilityDestroy.');
  },
  onAbilityForeground(ability){
    console.log('AbilityLifecycleCallback onAbilityForeground.');
  },
  onAbilityBackground(ability){
    console.log('AbilityLifecycleCallback onAbilityBackground.');
  },
  onAbilityContinue(ability){
    console.log('AbilityLifecycleCallback onAbilityContinue.');
  },
  onNewWant(ability) {
    console.log('AbilityLifecycleCallback onNewWant');
  },
  onWillNewWant(ability) {
    console.log('AbilityLifecycleCallback onWillNewWant');
  },
  onAbilityWillCreate(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillCreate');
  },
  onWindowStageWillCreate(ability, windowStage) {
    console.log('AbilityLifecycleCallback onWindowStageWillCreate');
  },
  onWindowStageWillDestroy(ability, windowStage) {
    console.log('AbilityLifecycleCallback onWindowStageWillDestroy');
  },
  onAbilityWillDestroy(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillDestroy');
  },
  onAbilityWillForeground(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillForeground');
  },
  onAbilityWillBackground(ability) {
    console.log('AbilityLifecycleCallback onAbilityWillBackground');
  },
  onAbilityWillContinue(ability: UIAbility) {
    console.log('AbilityLifecycleCallback onAbilityWillContinue.');
  },
  onWindowStageWillRestore(ability: UIAbility, windowStage: window.WindowStage) {
    console.log('AbilityLifecycleCallback onWindowStageWillRestore.');
  },
  onWindowStageRestore(ability: UIAbility, windowStage: window.WindowStage) {
    console.log('AbilityLifecycleCallback onWindowStageRestore.');
  },
  onAbilityWillSaveState(ability: UIAbility) {
    console.log('AbilityLifecycleCallback onAbilityWillSaveState.');
  },
  onAbilitySaveState(ability: UIAbility) {
    console.log('AbilityLifecycleCallback onAbilitySaveState.');
  }
};

export default class MyFirstAbility extends UIAbility {
  onCreate() {
    console.log('MyAbilityStage onCreate');
    // 1. Obtain applicationContext through the context property.
    let applicationContext = this.context.getApplicationContext();
    // 2. Register the listener for the ability lifecycle changes through the applicationContext object.
    try {
      let lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
      GlobalContext.getContext().setObject("lifecycleId", lifecycleId);
      console.log(`registerAbilityLifecycleCallback lifecycleId: ${GlobalContext.getContext().getObject('lifecycleId')}`);
    } catch (paramError) {
      console.error(`error: ${paramError.code}, ${paramError.message}`);
    }
  }
}
```

MySecondAbility.ts
Second ability of the application
```ts
import { UIAbility } from '@kit.AbilityKit';

// Import GlobalContext. Use the actual path declared.
import { GlobalContext } from '../GlobalContext';
import { BusinessError } from '@ohos.base';

export default class MySecondAbility extends UIAbility {
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    let lifecycleId = GlobalContext.getContext().getObject("lifecycleId") as number;
    try {
    // 3. Deregister the listener for the ability lifecycle changes through the applicationContext object.
      applicationContext.off('abilityLifecycle', lifecycleId, (error) => {
        if (error && error.code !== 0) {
          console.error(`unregisterAbilityLifecycleCallback fail, error: ${JSON.stringify(error)}`);
        } else {
          console.log('unregisterAbilityLifecycleCallback success.');
        }
      });
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```
