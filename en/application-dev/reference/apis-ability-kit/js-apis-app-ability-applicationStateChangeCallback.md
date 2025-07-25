# @ohos.app.ability.ApplicationStateChangeCallback (Application Foreground/Background State Change Listener)

The ApplicationStateChangeCallback module provides callbacks for the application context to listen for application foreground/background state changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { ApplicationStateChangeCallback } from '@kit.AbilityKit';
```

## ApplicationStateChangeCallback.onApplicationForeground

onApplicationForeground(): void

Called when the application is switched from the background to the foreground.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

For details, see [onApplicationBackground](#applicationstatechangecallbackonapplicationbackground).

## ApplicationStateChangeCallback.onApplicationBackground

onApplicationBackground(): void

Called when the application is switched from the foreground to the background.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIAbility, ApplicationStateChangeCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let applicationStateChangeCallback: ApplicationStateChangeCallback = {
  onApplicationForeground() {
    console.info('applicationStateChangeCallback onApplicationForeground');
  },
  onApplicationBackground() {
    console.info('applicationStateChangeCallback onApplicationBackground');
  }
};

export default class MyAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    // 1. Obtain an applicationContext object.
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2. Use applicationContext.on() to subscribe to the 'applicationStateChange' event.
      if (applicationContext != undefined) {
        applicationContext.on('applicationStateChange', applicationStateChangeCallback);
      }
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    console.log('Register applicationStateChangeCallback');
  }
  onDestroy() {
    let applicationContext = this.context.getApplicationContext();
    try {
      // 1. Use applicationContext.off() to unsubscribe from the 'applicationStateChange' event.
      if (applicationContext != undefined) {
        applicationContext.off('applicationStateChange', applicationStateChangeCallback);
      } 
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```
