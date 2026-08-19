# App Exit

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @ccllee1-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=19050225e664e6cdf992c6f93572590dc5afb573 translatedAt=2026-08-18T01:29:10.203Z pushedAt=2026-08-18T03:58:13.968Z -->

## Overview

During app development, destroying a component (such as UIAbility) only destroys that specific instance, while its host process remains resident in the background. Only when all components in the process are destroyed does the process trigger the destruction flow. The app is not considered truly exited until all processes belonging to the app are completely destroyed by the operating system and all memory and threads are reclaimed.

## App Exit Mechanism

An app may contain multiple processes, and each process can run multiple UIAbility components. Therefore, when the last UIAbility component in a process exits, the process exits accordingly; when the last process of the app exits, the entire app completes its exit. Based on the triggering cause and how the system handles it, the UIAbility exit mechanism is mainly classified into two types: normal exit and abnormal exit.

- **Normal Exit**: Triggered by user interaction or developer code. It includes the developer explicitly calling an exit API (such as terminateSelf()), the user tapping the back key, clearing a card in the recent tasks screen, and closing via right-click on the Dock bar. In such scenarios, the system strictly follows the lifecycle specifications and sequentially triggers the standard destruction callbacks, allowing the app to save data and release resources.

- **Abnormal Exit**: An unexpected interruption caused by uncontrollable factors or system intervention. It includes uncaught severe crashes within the app, memory leaks, or forced termination due to violation of system control policies. In the case of abnormal exit, the system directly and forcibly terminates the app process, and the complete execution of lifecycle callbacks often cannot be guaranteed.

The following table lists the lifecycle execution of UIAbility in different exit scenarios:

| Exit Type    | Triggering Scenario       | Whether [onDestroy](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#ondestroy) Is Triggered  |
| ------------| ---------------- | ----------------------- |
| User-Initiated Exit (Normal Exit)  | The user swipes back or presses the Back key to exit; the user swipes up to clear a single card in the recent tasks screen, or taps the "Clear All" button. |   Yes   |
| Application-Initiated Exit (Normal Exit) | The developer explicitly calls terminateSelf() to terminate the current app process. Common scenarios include: the app detects a fatal error and proactively terminates the process to avoid data corruption; after completing core tasks such as one-tap cache clearing within the app, it proactively ends its lifecycle. |  Yes |
| System-Forced Termination (Abnormal Exit) | The app process crashes or is forcibly terminated by the system (for example, jscrash or pointer exceptions); the system automatically clears the UIAbility for reasons such as resource reclamation (for example, system memory pressure, power optimization, or permission changes). |  No |

## User-Initiated Exit

### Exiting by Pressing the Back Key

**Scenario**: On phone-type devices, when the user presses the back key, the system calls the [onBackPressed()](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onbackpressed10) callback of the UIAbility. This callback returns **true** by default, and the system moves the UIAbility to the background instead of destroying it.

**Implementation**: Developers can override the [onBackPressed()](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onbackpressed10) method to return **true** to change the default behavior of the back key. For example, call terminateSelf() in onBackPressed() to directly exit the UIAbility when the back key is pressed.

**How to Develop**:

By default, pressing the back key moves the UIAbility to the background. To directly exit the UIAbility when the back key is pressed, override the onBackPressed() method to exit the app.

Override the onBackPressed() method in UIAbility.

<!-- @[appStop_backPressed](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/GuideForAppExit/onBackPressed/src/main/ets/onbackpressedability/OnBackPressedAbility.ets) -->

``` TypeScript
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

export default class OnBackPressedAbility extends UIAbility {
  // ...

  onBackPressed() {
    // Call terminateSelf to exit the UIAbility.
    this.context.terminateSelf().then(() => {
      console.info('Succeeded in terminating self.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to terminate self. Code is ${err.code}, message is ${err.message}`);
    });

    // Return true to indicate that the event is consumed and no default processing is performed.
    return true;
  }
}
```

### Cleaning Up UIAbility by the User

Users can proactively exit a UIAbility in various ways:

- **Single-task cleanup**: Swipe up to clear a single task card. The corresponding UIAbility instance exits and invokes the onDestroy lifecycle callback.

- **One-tap cleanup**: Tap the "Clear All" button to clear all task cards in batches. All UIAbility instances exit and invoke the onDestroy lifecycle callback.

- **Exit from the Dock**: On PC/2-in-1 or tablet devices, when the user exits through the Dock, the onDestroy callback of the UIAbility is not guaranteed.

## Application-Initiated Exit

When an app exits on its own initiative, the UIAbility components it contains also exit normally. A normal UIAbility exit refers to the exit process that occurs when the component meets business expectations. In this scenario, the system triggers the onDestroy() lifecycle callback, allowing the app to release the system resources it holds.

**Example scenario**: The user taps a custom "Exit" button in the app, or the countdown of an ad page hosted by a UIAbility ends and the page needs to be closed automatically.

**Implementation**: After the business logic is complete, developers can call [terminateSelf()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#terminateself-1) to proactively exit the current UIAbility.

**How to Develop**:

1. Obtain the UIAbilityContext instance in the UIAbility.

2. Call terminateSelf() to exit the UIAbility.

<!-- @[appStop_terminateSelf](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/GuideForAppExit/terminateSelf/src/main/ets/terminateselfability/TerminateSelfAbility.ets) -->

``` TypeScript
import { AbilityConstant, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;

export default class EntryAbility extends UIAbility {
  // ...

  onForeground(): void {
    // Ability has brought to foreground
    hilog.info(DOMAIN, 'testTag', '%{public}s', 'Ability onForeground');

    // Obtain the UIAbilityContext.
    let context = this.context;

    setTimeout(() => {
      context.terminateSelf().then(() => {
        console.info('Succeeded in terminating self.');
      }).catch((err: BusinessError) => {
        console.error(`Failed to terminate self. Code is ${err.code}, message is ${err.message}`);
      });
    }, 2000);
  }

  // ...
}
```

## System-Forced Termination

### App Exception

When an app encounters an exception, such as a JavaScript crash or a null pointer exception, the app crashes and exits directly. In this case, the onDestroy lifecycle callback is not executed.

### System Cleanup

In certain scenarios, the system forcibly cleans up the app process without executing the onDestroy lifecycle callback:

For example, when the system temperature is too high, the available memory of the device is insufficient, or the app is being upgraded.