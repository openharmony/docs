# @ohos.app.ability.abilityLifecycleCallback (UIAbility Lifecycle Callback Listener)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wkljy; @xuzhihao666-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The lifecycle of a [UIAbility](js-apis-app-ability-uiAbility.md) dynamically changes from creation to destruction. The AbilityLifecycleCallback module provides the capability to listen for these lifecycle changes, which can be used for scenarios such as tracking the runtime duration of each UIAbility and performing data loading decoupled from the service logic of UIAbility.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module can listen for lifecycle changes of the UIAbility within the same process.

## How to Use

1. An application creates an AbilityLifecycleCallback object and calls [ApplicationContext.on('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextonabilitylifecycle) to register a listener to listen for UIAbility lifecycle changes.
2. When the UIAbility lifecycle changes, the application receives a notification indicating the UIAbility lifecycle change through the registered AbilityLifecycleCallback object.
3. When the application does not need to listen for the UIAbility lifecycle changes, the application can unregister the listener by calling [ApplicationContext.off('abilityLifecycle')](js-apis-inner-application-applicationContext.md#applicationcontextoffabilitylifecycle).

## Modules to Import

```ts
import { AbilityLifecycleCallback } from '@kit.AbilityKit';
```

## AbilityLifecycleCallback

### onAbilityCreate

onAbilityCreate(ability: UIAbility): void

Called after the [onCreate](js-apis-app-ability-uiAbility.md#oncreate) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageCreate

onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage): void

Called after the [onWindowStageCreate](js-apis-app-ability-uiAbility.md#onwindowstagecreate) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageActive

onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage): void

Called when the main window of the UIAbility gains focus.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageInactive

onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage): void

Called when the main window of the UIAbility loses focus.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageDestroy

onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage): void

Called after the [onWindowStageDestroy](js-apis-app-ability-uiAbility.md#onwindowstagedestroy) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityDestroy

onAbilityDestroy(ability: UIAbility): void

Called after the [onDestroy](js-apis-app-ability-uiAbility.md#ondestroy) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityForeground

onAbilityForeground(ability: UIAbility): void

Called after the [onForeground](js-apis-app-ability-uiAbility.md#onforeground) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityBackground

onAbilityBackground(ability: UIAbility): void

Called after the [onBackground](js-apis-app-ability-uiAbility.md#onbackground) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityContinue

onAbilityContinue(ability: UIAbility): void

Called after the [onContinue](js-apis-app-ability-uiAbility.md#oncontinue) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityWillCreate<sup>12+</sup>

onAbilityWillCreate?(ability: UIAbility): void

Called before the [onCreate](js-apis-app-ability-uiAbility.md#oncreate) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageWillCreate<sup>12+</sup>

onWindowStageWillCreate?(ability: UIAbility, windowStage: window.WindowStage): void

Called before the [onWindowStageCreate](js-apis-app-ability-uiAbility.md#onwindowstagecreate) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageWillDestroy<sup>12+</sup>

onWindowStageWillDestroy?(ability: UIAbility, windowStage: window.WindowStage): void

Called before the [onWindowStageDestroy](js-apis-app-ability-uiAbility.md#onwindowstagedestroy) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityWillForeground<sup>12+</sup>

onAbilityWillForeground?(ability: UIAbility): void

Called before the [onForeground](js-apis-app-ability-uiAbility.md#onforeground) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityWillDestroy<sup>12+</sup>

onAbilityWillDestroy?(ability: UIAbility): void

Called before the [onDestroy](js-apis-app-ability-uiAbility.md#ondestroy) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityWillBackground<sup>12+</sup>

onAbilityWillBackground?(ability: UIAbility): void

Called before the [onBackground](js-apis-app-ability-uiAbility.md#onbackground) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWillNewWant<sup>12+</sup>

onWillNewWant?(ability: UIAbility): void

Called before the [onNewWant](js-apis-app-ability-uiAbility.md#onnewwant) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onNewWant<sup>12+</sup>

onNewWant?(ability: UIAbility): void

Called after the [onNewWant](js-apis-app-ability-uiAbility.md#onnewwant) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityWillContinue<sup>12+</sup>

onAbilityWillContinue?(ability: UIAbility): void

Called before the [onContinue](js-apis-app-ability-uiAbility.md#oncontinue) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageWillRestore<sup>12+</sup>

onWindowStageWillRestore?(ability: UIAbility, windowStage: window.WindowStage): void

Called before the [onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onWindowStageRestore<sup>12+</sup>

onWindowStageRestore?(ability: UIAbility, windowStage: window.WindowStage): void

Called after the [onWindowStageRestore](js-apis-app-ability-uiAbility.md#onwindowstagerestore) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|
  | windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Main window manager of the UIAbility associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilityWillSaveState<sup>12+</sup>

onAbilityWillSaveState?(ability: UIAbility): void

Called before the [onSaveState](js-apis-app-ability-uiAbility.md#onsavestate) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### onAbilitySaveState<sup>12+</sup>

onAbilitySaveState?(ability: UIAbility): void

Called after the [onSaveState](js-apis-app-ability-uiAbility.md#onsavestate) callback of the UIAbility is triggered.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description|
  | ------ | ------ | ------ | ------ |
  | ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes| UIAbility object associated with the callback event.|

**Example**

For details, see [AbilityLifecycleCallback Usage Example](#abilitylifecyclecallback-usage-example).

### AbilityLifecycleCallback Usage Example

This example demonstrates some use cases of the lifecycle listener mechanism.
1. Register the listener when the [AbilityStage](../../application-models/abilitystage.md) is created.
2. Unregister the listener when the [AbilityStage](../../application-models/abilitystage.md) is destroyed.
3. Load resources when the corresponding UIAbility is created, and release resources when it is destroyed.
4. Log events and send notifications when the UIAbility is created, destroyed, or switched between the foreground and background.

```ts
// Use AbilityLifecycleCallback to listen for the lifecycle of the UIAbility in the MyStage.ets file.
import { AbilityLifecycleCallback, AbilityStage, application, UIAbility } from "@kit.AbilityKit";
import { hilog } from '@kit.PerformanceAnalysisKit';
import { JSON } from "@kit.ArkTS";
import { window } from "@kit.ArkUI";
import { BusinessError } from "@kit.BasicServicesKit";

const DOMAIN = 0x0000;
const TAG = 'testTag';

function loadContent() {
  // Load data.
}

function releaseContent() {
  // Release data.
}

function recordAbilityEvent(abilityName: string) {
  // Perform event tracking.
}

function publishEvent() {
  // Publish notifications externally.
}

let abilityLifecycleCallback: AbilityLifecycleCallback = {
  onAbilityCreate(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'onAbilityCreate: ' + ability.context.abilityInfo.name);
    // Log UIAbility events.
    recordAbilityEvent(ability.context.abilityInfo.name);
    // Load resources and publish notifications externally when the entry UIAbility is created.
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      loadContent();
      publishEvent();
    }
  },
  onWindowStageCreate(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageCreate.');
  },
  onWindowStageActive(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageActive.');
  },
  onWindowStageInactive(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageInactive.');
  },
  onWindowStageDestroy(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageDestroy.');
  },
  onAbilityDestroy(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'onAbilityDestroy: ' + ability.context.abilityInfo.name);
    recordAbilityEvent(ability.context.abilityInfo.name);
    // Release resources when the entry UIAbility is destroyed.
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      releaseContent();
      publishEvent();
    }
  },
  onAbilityForeground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityForeground.');
    recordAbilityEvent(ability.context.abilityInfo.name);
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      publishEvent();
    }
  },
  onAbilityBackground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityBackground.');
    recordAbilityEvent(ability.context.abilityInfo.name);
    if (ability.context.abilityInfo.name === 'EntryAbility') {
      publishEvent();
    }
  },
  onAbilityContinue(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityContinue.');
  },
  onNewWant(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onNewWant');
  },
  onWillNewWant(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWillNewWant');
  },
  onAbilityWillCreate(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillCreate');
  },
  onWindowStageWillCreate(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageWillCreate');
  },
  onWindowStageWillDestroy(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageWillDestroy');
  },
  onAbilityWillDestroy(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillDestroy');
  },
  onAbilityWillForeground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillForeground');
  },
  onAbilityWillBackground(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillBackground');
  },
  onAbilityWillContinue(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillContinue.');
  },
  onWindowStageWillRestore(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageWillRestore.');
  },
  onWindowStageRestore(ability: UIAbility, windowStage: window.WindowStage) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onWindowStageRestore.');
  },
  onAbilityWillSaveState(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilityWillSaveState.');
  },
  onAbilitySaveState(ability: UIAbility) {
    hilog.info(DOMAIN, TAG, 'AbilityLifecycleCallback onAbilitySaveState.');
  }
};

let lifecycleId = -1; // Save the listener ID.

export default class MyStage extends AbilityStage {
  onCreate(): void {
    hilog.info(DOMAIN, TAG, 'AbilityStage onCreate')

    // Register the UIAbility lifecycle listener during AbilityStage creation and save the listener ID.
    try {
      let applicationContext = application.getApplicationContext();
      lifecycleId = applicationContext.on('abilityLifecycle', abilityLifecycleCallback);
    } catch (e) {
      hilog.error(DOMAIN, TAG, `register abilityLifecycle failed: ${JSON.stringify(e)}`);
    }
  }

  onDestroy(): void {
    // Unregister the UIAbility lifecycle listener when the AbilityStage is destroyed.
    let applicationContext = application.getApplicationContext();
    applicationContext.off('abilityLifecycle', lifecycleId).catch((e: BusinessError) => {
      hilog.error(DOMAIN, TAG, `unregister abilityLifecycle failed: ${JSON.stringify(e)}`);
    });
  }
}
```

```ts
// Demonstrate the entry UIAbility in EntryAbility.ets.
import { AbilityConstant, ConfigurationConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const DOMAIN = 0x0000;
const TAG = 'testTag';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    this.context.getApplicationContext().setColorMode(ConfigurationConstant.ColorMode.COLOR_MODE_NOT_SET);
    hilog.info(DOMAIN, TAG, 'EntryAbility onCreate');
  }

  onDestroy(): void {
    hilog.info(DOMAIN, TAG, 'EntryAbility onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    // Create the main window.
    hilog.info(DOMAIN, TAG, 'EntryAbility onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err) => {
      if (err.code) {
        hilog.error(DOMAIN, TAG, 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        return;
      }
      hilog.info(DOMAIN, TAG, 'Succeeded in loading the content.');
    });
  }

  onWindowStageDestroy(): void {
    // Destroy the main window.
    hilog.info(DOMAIN, TAG, 'EntryAbility onWindowStageDestroy');
  }

  onForeground(): void {
    // Switch the UIAbility to the foreground.
    hilog.info(DOMAIN, TAG, 'EntryAbility onForeground');
  }

  onBackground(): void {
    // Switch the UIAbility to the background.
    hilog.info(DOMAIN, TAG, 'EntryAbility  onBackground');
  }
}
```
