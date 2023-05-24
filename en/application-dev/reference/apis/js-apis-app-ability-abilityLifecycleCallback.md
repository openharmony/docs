# @ohos.app.ability.abilityLifecycleCallback (AbilityLifecycleCallback)

The **AbilityLifecycleCallback** module defines the callbacks to receive lifecycle changes of [ApplicationContext](js-apis-inner-application-applicationContext.md). The callbacks include [onAbilityCreate](#abilitylifecyclecallbackonabilitycreate), [onWindowStageCreate](#abilitylifecyclecallbackonwindowstagecreate), [onWindowStageActive](#abilitylifecyclecallbackonwindowstageactive), [onWindowStageInactive](#abilitylifecyclecallbackonwindowstageinactive), [onWindowStageDestroy](#abilitylifecyclecallbackonwindowstagedestroy), [onAbilityDestroy](#abilitylifecyclecallbackonabilitydestroy), [onAbilityForeground](#abilitylifecyclecallbackonabilityforeground), [onAbilityBackground](#abilitylifecyclecallbackonabilitybackground), and [onAbilityContinue](#abilitylifecyclecallbackonabilitycontinue).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';
```

## AbilityLifecycleCallback.onAbilityCreate

onAbilityCreate(ability: UIAbility): void;

Called when an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.| 

**Example**
```ts
let abilityLifecycleCallback =  {
    onAbilityCreate(ability){
        console.log('AbilityLifecycleCallback onAbilityCreate.');  
    }
};
```

## AbilityLifecycleCallback.onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|    

**Example**
```ts
let abilityLifecycleCallback =  {
    onWindowStageCreate(ability, windowStage){
        console.log('AbilityLifecycleCallback onWindowStageCreate.');
    }
};
```

## AbilityLifecycleCallback.onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability gains focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|    

**Example**
```ts
let abilityLifecycleCallback =  {
    onWindowStageActive(ability, windowStage){
        console.log('AbilityLifecycleCallback onWindowStageActive.');
    }
};
```

## AbilityLifecycleCallback.onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability loses focus.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|  

**Example**
```ts
let abilityLifecycleCallback =  {
    onWindowStageInactive(ability, windowStage){
        console.log('AbilityLifecycleCallback onWindowStageInactive.');
    }
};
```

## AbilityLifecycleCallback.onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void;

Called when the window stage of an ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.|  
  | windowStage | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| **WindowStage** object.|  

**Example**
```ts
let abilityLifecycleCallback =  {
    onWindowStageDestroy(ability, windowStage){
        console.log('AbilityLifecycleCallback onWindowStageDestroy.');
    }
};
```

## AbilityLifecycleCallback.onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void;

Called when an ability is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.| 

**Example**
```ts
let abilityLifecycleCallback =  {
    onAbilityDestroy(ability){
        console.log('AbilityLifecycleCallback onAbilityDestroy.');
    }
};
```

## AbilityLifecycleCallback.onAbilityForeground

onAbilityForeground(ability: UIAbility): void;

Called when an ability is switched from the background to the foreground.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.| 

**Example**
```ts
let abilityLifecycleCallback =  {
    onAbilityForeground(ability){
        console.log('AbilityLifecycleCallback onAbilityForeground.');
    }
};
```

## AbilityLifecycleCallback.onAbilityBackground

onAbilityBackground(ability: UIAbility): void;

Called when an ability is switched from the foreground to the background.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.| 

**Example**
```ts
let abilityLifecycleCallback =  {
    onAbilityBackground(ability){
        console.log('AbilityLifecycleCallback onAbilityBackground.');
    }
};
```

## AbilityLifecycleCallback.onAbilityContinue

onAbilityContinue(ability: UIAbility): void;

Called when an ability is continued on another device.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| **Ability** object.| 

**Example**
```ts
let abilityLifecycleCallback =  {
    onAbilityContinue(ability){
        console.log('AbilityLifecycleCallback onAbilityContinue.');
    }
};
```

## Usage of AbilityLifecycleCallback

**Example**

MyFirstAbility.ts
```ts
import AbilityLifecycleCallback from '@ohos.app.ability.AbilityLifecycleCallback';
import AbilityStage from '@ohos.app.ability.AbilityStage';
import UIAbility from '@ohos.app.ability.UIAbility';

// Declare the ability lifecycle callbacks. A listener can be registered in applicationContext only after all the callbacks are configured.
let abilityLifecycleCallback = {
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
    }
};

export default class MyFirstAbility extends UIAbility {
    onCreate() {
        console.log('MyAbilityStage onCreate');
        // 1. Obtain applicationContext through the context attribute.
        let applicationContext = this.context.getApplicationContext();
        // 2. Register the listener for the ability lifecycle changes through the applicationContext object.
        try {
            globalThis.lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
            console.log('registerAbilityLifecycleCallback lifecycleId: ${globalThis.lifecycleId}');
        } catch (paramError) {
            console.log('error: ' + paramError.code + ' ,' + paramError.message);
        }
    }
}
```

MySecondAbility.ts
```ts
import UIAbility from '@ohos.app.ability.UIAbility';

export default class MySecondAbility extends UIAbility {
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        // 3. Deregister the listener for the ability lifecycle changes through the applicationContext object.
        applicationContext.off('abilityLifecycle', globalThis.lifecycleId, (error) => {
            if (error.code != 0) {
                console.log('unregisterAbilityLifecycleCallback failed, error: ' + JSON.stringify(error));
            } else {
                console.log('unregisterAbilityLifecycleCallback success.');
            }
        });
    }
}
```
