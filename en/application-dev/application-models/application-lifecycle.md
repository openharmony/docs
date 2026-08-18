# Application Lifecycle Overview

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wendel-->
<!--Designer: @wendel-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=11df7ff9976718ab2707dde1cf3ce5a5dccd5e46 translatedAt=2026-08-18T01:29:13.958Z pushedAt=2026-08-18T06:37:38.792Z -->

## Overview

When a user performs operations such as app startup, app foreground/background switching, and app exit, the overall application lifecycle state of the app changes accordingly. Understanding the app lifecycle helps developers perform operations such as resource application and release and service state management at the right time. This section mainly describes the application lifecycle state, the relationship between the application lifecycle and the application process and app components ([UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) and [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)), and how to listen for changes in the application lifecycle state.

## Application Lifecycle State

### Relationship Between App Lifecycle and App Process and App Components

- Relationship between app lifecycle and app process

    When the first process of an app is created, the app starts; when all processes of the app end, the app exits (see the following figure for details).


- Relationship between app process lifecycle and UIAbility component

    The lifecycle of an application process directly constrains and affects the lifecycle of a UIAbility component (see the following figure for details).


    The foreground/background callbacks of the [UIAbility component lifecycle](./uiability-lifecycle.md) are closely related to the foreground/background state of the process, but the two are not exactly the same:

    - The [onForeground()](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground) callback of a UIAbility indicates that the UIAbility instance switches to the foreground state.

    - The foreground/background state of the process indicates the foreground/background state of the entire process.

    - A process may contain multiple UIAbilities, and the `onForeground()` of one UIAbility does not necessarily mean that the process state changes (for example, the process may already be in the foreground state).

    The mapping between the UIAbility state and the process state is as follows (assuming that a process contains two UIAbility components):

    | UIAbility State | Window State in Process | Process State |
    | --------- | --------- | ------------------------------ |
    | Any UIAbility is in the foreground state | Visible state | Foreground state |
    | Any UIAbility is in the foreground state | Invisible state | Foreground state |
    | All UIAbilities are in the background state | Visible state | Foreground state |
    | All UIAbilities are in the background state | Invisible state | Background state |

- Relationship between the application process lifecycle and ExtensionAbility components

    When the first ExtensionAbility component is created, the corresponding application process is created first. When the application process is destroyed, all ExtensionAbility components in the process are also destroyed.

### Application Lifecycle State Changes

- App startup: An app can run in one or more processes, and a process can run one or more [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) component instances. An app developed by a third-party developer must contain at least one [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) component; otherwise, it has no UI to display to users. For details about the app startup mechanism, see [App Startup](./application-startup-options.md).

- App exit: When all app components in a process are destroyed, the process enters the destruction process. When all processes of the app are destroyed, the app exits. For details about the app exit mechanism, see [App Exit](./app-stop.md).

- App foreground/background switching: When at least one process of the app is in the foreground, the app is in the foreground state. If all processes of the app are in the background, the app is in the background state.

    - Timing for switching an application process to the foreground:

        - When the first UIAbility in the application process is started, the system switches the application process to the foreground state.

        - When the app is already in the background state, the user taps the task in the Recents screen to switch the app to the foreground state.

        - When the user returns from another app to an app that is already in the background state, the system switches the application process to the foreground state.

        - When the user unlocks the lock screen and returns to the app displayed before the screen was locked, the system switches the application process to the foreground state.

    - When the application process switches to the background:

        - When the user returns to the home screen from the app process, the system switches the app process to the background state.

        - When the user switches to another app, the system switches the app process to the background state.

        - When the screen is locked, the system switches the app process being displayed to the background state.

> **NOTE**
>
> The foreground/background switching timing of the app process described above does not apply to 2-in-1 apps. A 2-in-1 app is switched to the foreground state by the system only when it is started, and switched to the background state by the system when it exits.

## Listening to the App Lifecycle

### Listening for App Startup and Exit

An app must first apply for the [ohos.permission.RUNNING_STATE_OBSERVER](../security/AccessToken/permissions-for-enterprise-apps.md#ohospermissionrunning_state_observer) permission. Then, the [on('applicationState')](../reference/apis-ability-kit/js-apis-app-ability-appManager.md#appmanageronapplicationstate14) method can be used to listen for the state of all apps, and the [on('applicationState')](../reference/apis-ability-kit/js-apis-app-ability-appManager.md#appmanageronapplicationstate14-1) method can be used to listen for the state of a specified app. By implementing the [onAppStarted()](../reference/apis-ability-kit/js-apis-inner-application-applicationStateObserver.md#applicationstateobserveronappstarted) method in the `ApplicationStateObserver` interface, you can listen for app startup. By implementing the [onAppStopped()](../reference/apis-ability-kit/js-apis-inner-application-applicationStateObserver.md#applicationstateobserveronappstopped) method in the `ApplicationStateObserver` interface, you can listen for app exit.

### Listening for App Foreground/Background Changes

An app can use the [on('applicationStateChange')](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextonapplicationstatechange10) method of `ApplicationContext` to listen for changes in the app's foreground/background state. When the app switches between the foreground and background, the corresponding callback is invoked, so that you can execute methods that depend on the foreground/background state or collect statistics such as the frequency of foreground/background switching.

The following uses [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md) as an example.

<!-- @[lifecycle_ability_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ApplicationContextDemo/entry/src/main/ets/lifecycleability/LifecycleAbility.ets) -->

> **NOTE**
>
> The callback events described above are all asynchronous callbacks and have no strict timing relationship.

``` TypeScript
import { UIAbility, ApplicationStateChangeCallback } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG = '[LifecycleAbility]';
const DOMAIN = 0xF811;

export default class LifecycleAbility extends UIAbility {
  onCreate() {
    let applicationStateChangeCallback: ApplicationStateChangeCallback = {
      onApplicationForeground() {
        hilog.info(DOMAIN, TAG, 'applicationStateChangeCallback onApplicationForeground');
      },
      onApplicationBackground() {
        hilog.info(DOMAIN, TAG, 'applicationStateChangeCallback onApplicationBackground');
      }
    }

    // Obtain the applicationContext.
    let applicationContext = this.context.getApplicationContext();
    try {
      // 2. Register the application foreground/background state listener through applicationContext.
      applicationContext.on('applicationStateChange', applicationStateChangeCallback);
    } catch (paramError) {
      hilog.error(DOMAIN, TAG, `error: ${(paramError as BusinessError).code}, ${(paramError as BusinessError).message}`);
    }
    hilog.info(DOMAIN, TAG, 'Register applicationStateChangeCallback');
  }
}
```

## Application Model Features of PC/2-in-1 Devices

For an app whose [deviceTypes](../quick-start/module-configuration-file.md#devicetypes-tag) in the module.json5 file declares support only for PC/2-in-1 devices, the triggering mechanism of its UIAbility lifecycle callbacks differs from that on other devices.

  1. When a user starts a UIAbility, the system sequentially triggers the onCreate(), onWindowStageCreate(), and onForeground() lifecycle callbacks to complete processes such as component creation and lifecycle driving.

  2. When the user switches between apps, the UIAbility remains in the foreground state, and the system does not trigger the onBackground() lifecycle callback.

  3. Only when the user actively exits the UIAbility or the app actively exits the UIAbility does the system trigger the onBackground() and onDestroy() lifecycle callbacks to complete component exit and destruction.

The process lifecycle is closely related to the UIAbility component lifecycle. Since the UIAbility remains in the foreground state for a long time in the running state, the process also remains in the foreground state for a long time, and only briefly enters the background state during normal process exit. Correspondingly, the app also remains in the foreground state for a long time, and only briefly enters the background state during normal app exit.