# @ohos.app.ability.ApplicationStateChangeCallback (Application Process State Change Listener)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module is used to listen for state changes of the current application process. For ease of description, the term "application process" will be referred to as "process" in the following sections.

You can call [ApplicationContext.on('applicationStateChange')](js-apis-inner-application-applicationContext.md#applicationcontextonapplicationstatechange10) and pass in a custom ApplicationStateChangeCallback to listen for foreground/background state changes of the current process. This allows you to perform certain actions based on the process state changes, for example, tracking the duration of the process in the foreground and background, or clearing memory caches when the process moves to the background.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Constraints

This module allows you to listen for foreground/background state changes of the current process. If you need to listen for foreground/background state changes of the entire application, use [ApplicationStateObserver.onForegroundApplicationChanged](js-apis-inner-application-applicationStateObserver.md#applicationstateobserveronforegroundapplicationchanged).

>**NOTE**
>
> The foreground/background state of a process is different from that of an application, as follows:
>- Foreground/Background state of a process: If any UIAbility or UIExtensionAbility in the process is in the foreground or has a visible window, the process is considered to be in the foreground; otherwise, it is in the background.
>- Foreground/Background state of an application: If any process under the application is in the foreground, the application is considered to be in the foreground; otherwise, it is in the background.

## Modules to Import

```ts
import { ApplicationStateChangeCallback } from '@kit.AbilityKit';
```

## ApplicationStateChangeCallback.onApplicationForeground

onApplicationForeground(): void

Called when the current process switches from the background to the foreground. When this callback is triggered, it does not mean that the process is already fully in the foreground state, but rather that it is about to enter the foreground state. At this point, operations that depend on the foreground state (such as launching another UIAbility) cannot be performed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

For details, see [onApplicationBackground](#applicationstatechangecallbackonapplicationbackground).

## ApplicationStateChangeCallback.onApplicationBackground

onApplicationBackground(): void

Called when the current process switches from the foreground to the background. When this callback is triggered, the process is fully in the background state, and you can perform operations suitable for the background state (for example, clearing memory caches).

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
      // 2. Register a listener for the current process state changes through applicationContext.
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
      // 1. Unregister the listener for the current process state changes through applicationContext.
      if (applicationContext != undefined) {
        applicationContext.off('applicationStateChange', applicationStateChangeCallback);
      } 
    } catch (paramError) {
      console.error(`error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
  }
}
```
