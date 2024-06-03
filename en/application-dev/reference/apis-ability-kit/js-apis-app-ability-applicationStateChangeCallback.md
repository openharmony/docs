# @ohos.app.ability.ApplicationStateChangeCallback (ApplicationStateChangeCallback)

The **ApplicationStateChangeCallback** module provides callbacks for the application context to listen for application foreground/background state changes.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';
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
import UIAbility from '@ohos.app.ability.UIAbility';
import ApplicationStateChangeCallback from '@ohos.app.ability.ApplicationStateChangeCallback';

let applicationStateChangeCallback: ApplicationStateChangeCallback = {
    onApplicationForeground() {
        console.info('applicationStateChangeCallback onApplicationForeground');
    },
    onApplicationBackground() {
        console.info('applicationStateChangeCallback onApplicationBackground');
    }
}

export default class MyAbility extends UIAbility {
    onCreate() {
        console.log('MyAbility onCreate');
        // 1. Obtain an applicationContext object.
        let applicationContext = this.context.getApplicationContext();
        // 2. Use applicationContext.on() to subscribe to the 'applicationStateChange' event.
        if (applicationContext != undefined) {
            applicationContext.on('applicationStateChange', applicationStateChangeCallback);
        }
        console.log('Resgiter applicationStateChangeCallback');
    }
    onDestroy() {
        let applicationContext = this.context.getApplicationContext();
        // 1. Use applicationContext.off() to unsubscribe from the 'applicationStateChange' event.
        if (applicationContext != undefined) {
            applicationContext.off('applicationStateChange', applicationStateChangeCallback);
        }
    }
}
```
