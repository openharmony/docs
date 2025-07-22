# @ohos.app.ability.AbilityConstant (Ability-related Constants)

AbilityConstant provides enums related to abilities, including application launch reasons ([LaunchReason](#launchreason)), last exit reasons ([LastExitReason](#lastexitreason)), and migration results ([OnContinueResult](#oncontinueresult)).

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { AbilityConstant } from '@kit.AbilityKit';
```

## Constants

**System capability**: SystemCapability.Ability.AbilityBase

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name| Type| Value| Description|
| ---- | -----| ---- | ---------------------------------------------------------- |
| REASON_MESSAGE_DESKTOP_SHORTCUT<sup>20+</sup>  | string | "ReasonMessage_DesktopShortcut" | The UIAbility is launched via a home screen shortcut. If this string is obtained from the **launchReasonMessage** property in [LaunchParam](#launchparam), the UIAbility is initiated by touching a shortcut on the home screen.|

## LaunchParam

Defines the launch parameters. The parameter values are automatically passed in by the system when the ability is launched. You do not need to change the values.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| launchReason | [LaunchReason](#launchreason)| No| No| An enumerated value indicating the reason for application launch (for example, recovery from a fault, intent invocation, or atomic service sharing). For details, see [LaunchReason](#launchreason).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| launchReasonMessage<sup>18+</sup> | string | No| Yes| Detailed message that describes the reason for the application launch.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| lastExitReason | [LastExitReason](#lastexitreason) | No| No| An enumerated value indicating the reason for the last exit.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| lastExitMessage<sup>12+</sup> | string | No| No| Detailed message that describes the reason for the last exit.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| lastExitDetailInfo<sup>18+</sup> | [LastExitDetailInfo](#lastexitdetailinfo18) | No| Yes| Key runtime states for the last exit (including process ID, exit timestamp, and RSS memory value).<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## LaunchReason

Enumerates the launch reasons. You can use it together with the value of **launchParam.launchReason** in [onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#oncreate) of the UIAbility to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| START_ABILITY          | 1    | The ability is started by calling [startAbility](js-apis-inner-application-uiAbilityContext.md#startability).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CALL | 2    | The ability is started by calling [startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#startabilitybycall).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| CONTINUATION           | 3    | The ability is started by means of cross-device migration.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| APP_RECOVERY           | 4    | The ability is automatically started when the application is restored from a fault.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| SHARE<sup>10+</sup>           | 5    | The ability is started by means of atomic service sharing.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| AUTO_STARTUP<sup>11+</sup>           | 8    | The ability is automatically started upon system boot.|
| INSIGHT_INTENT<sup>11+</sup>           | 9    | The ability is started by the InsightIntent framework.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PREPARE_CONTINUATION<sup>12+</sup>           | 10    | The ability is started in advance during cross-device migration.<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

**Example**

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    if (launchParam.launchReason === AbilityConstant.LaunchReason.START_ABILITY) {
      console.log('The ability has been started by the way of startAbility.');
    }
  }
}
```

## LastExitReason

Enumerates the reasons for the last exit. You can use it together with the value of **launchParam.lastExitReason** in [onCreate()](js-apis-app-ability-uiAbility.md#oncreate) of the UIAbility to complete different operations.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | Unknown reason.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ABILITY_NOT_RESPONDING<sup>(deprecated)</sup> | 1    | The ability does not respond.<br>**NOTE**<br>This enum is supported since API version 9 and deprecated since API version 10. You are advised to use **APP_FREEZE**.|
| NORMAL | 2    | The ability exits normally because the user closes the application.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**NOTE**: If the application process is terminated using methods not provided by Ability Kit, such as calling [process.exit()](../apis-arkts/js-apis-process.md#processexitdeprecated) or using the **kill** command, the reason for the last exit is also reported as **NORMAL**.|
| CPP_CRASH<sup>10+</sup>  | 3    | The ability exits due to abnormal signals on the local host.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| JS_ERROR<sup>10+</sup>  | 4    | The ability exits due to a JS_ERROR fault triggered when an application has a JS syntax error that is not captured by developers.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| APP_FREEZE<sup>10+</sup>  | 5    | The ability exits because watchdog detects that the application is frozen.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| PERFORMANCE_CONTROL<sup>10+</sup>  | 6    | The ability exits due to system performance problems, for example, insufficient device memory.<br>**Atomic service API**: This API can be used in atomic services since API version 11.<br>**NOTE**: This API will be deprecated. You are advised to use **RESOURCE_CONTROL** instead.|
| RESOURCE_CONTROL<sup>10+</sup>  | 7    | The ability exits due to improper use of system resources. The specific error cause can be obtained through [LaunchParam.lastExitMessage](#launchparam). The possible causes are as follows:<br> - **CPU Highload**: The CPU load is high.<br> - **CPU_EXT Highload**: A fast CPU load detection is carried out.<br> - **IO Manage Control**: An I/O management and control operation is carried out.<br> - **App Memory Deterioration**: The application memory usage exceeds the threshold.<br> - **Temperature Control**: The temperature is too high or too low.<br> - **Memory Pressure**: The system is low on memory, triggering ability exiting in ascending order of priority.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| UPGRADE<sup>10+</sup>  | 8    | The ability exits due to an update.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| USER_REQUEST<sup>18+</sup>  | 9    | The ability exits because of an action in the multitasking center, for example, when users swipe up or hit the one-click clean button in the multitasking view.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| SIGNAL<sup>18+</sup>  | 10    | The ability exits because it receives a kill signal from the system.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

**Example**

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    if (launchParam.lastExitReason === AbilityConstant.LastExitReason.APP_FREEZE) {
      console.log('The ability has exit last because the ability was not responding.');
    }
    if (launchParam.lastExitReason === AbilityConstant.LastExitReason.RESOURCE_CONTROL) {
      console.log('The ability has exit last because the rss control, the lastExitReason is '+ launchParam.lastExitReason + ', the lastExitMessage is ' + launchParam.lastExitMessage);
    }
  }
}
```

## LastExitDetailInfo<sup>18+</sup>

Describes the detailed information about the last exit.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| pid | number | No| No| ID of the process where the ability last exited.|
| processName | string | No| No| Name of the process.|
| uid | number | No| No| UID of the application.|
| exitSubReason | number | No| No| Specific reason for the last exit of the ability.|
| exitMsg | string | No| No| Reason why the process was killed.|
| rss | number | No| No| RSS value of the process.|
| pss | number | No| No| PSS value of the process.|
| timestamp | number | No| No| Exact time when the ability last exited.|
| processState<sup>20+</sup> | [appManager.ProcessState](js-apis-app-ability-appManager.md#processstate10) | No| Yes| Process status of the ability when it last exited.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

**Example**

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    if (launchParam.lastExitDetailInfo) {
      console.log('pid: ' + launchParam.lastExitDetailInfo.pid +
        '\n processName: ' + launchParam.lastExitDetailInfo.processName +
        '\n uid: ' + launchParam.lastExitDetailInfo.uid +
        '\n exitSubReason: ' + launchParam.lastExitDetailInfo.exitSubReason +
        '\n exitMsg: ' + launchParam.lastExitDetailInfo.exitMsg +
        '\n rss: ' + launchParam.lastExitDetailInfo.rss +
        '\n pss: ' + launchParam.lastExitDetailInfo.pss +
        '\n timestamp: ' + launchParam.lastExitDetailInfo.timestamp +
        '\n processState: ' + launchParam.lastExitDetailInfo.processState
      );
    }
  }
}
```

## OnContinueResult 

Enumerates the ability continuation results. You can use it together with [onContinue()](js-apis-app-ability-uiAbility.md#oncontinue) of the UIAbility to complete different operations.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | The ability continuation is accepted.|
| REJECT           | 1    | The ability continuation is rejected. If the application is abnormal in [onContinue](js-apis-app-ability-uiAbility.md#oncontinue), which results in abnormal display during data restoration, this result is returned.|
| MISMATCH  | 2    | The version does not match. The application on the initiator can obtain the version of the target application from [onContinue](js-apis-app-ability-uiAbility.md#oncontinue). If the ability continuation cannot be performed due to version mismatch, this result is returned.|

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onContinue(wantParam: Record<string, Object>) {
    return AbilityConstant.OnContinueResult.AGREE;
  }
}
```

## MemoryLevel

Enumerates the memory levels. You can use it in [onMemoryLevel()](js-apis-app-ability-ability.md#abilityonmemorylevel) of the UIAbility to complete different operations.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                        | Value| Description               |
| ---                         | --- | ---           |
| MEMORY_LEVEL_MODERATE       | 0   | Moderate memory usage.|
| MEMORY_LEVEL_LOW            | 1   | Low memory usage.  |
| MEMORY_LEVEL_CRITICAL       | 2   | High memory usage.  |

> **NOTE**
> 
> The trigger conditions may differ across various devices. For example, on a standard device with 12 GB of memory:
> - A callback with value 0 is triggered when available memory drops between 1700 MB and 1800 MB.
> - A callback with value 1 is triggered when available memory drops between 1600 MB and 1700 MB.
> - A callback with value 2 is triggered when available memory falls below 1600 MB.

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onMemoryLevel(level: AbilityConstant.MemoryLevel) {
    if (level === AbilityConstant.MemoryLevel.MEMORY_LEVEL_CRITICAL) {
      console.log('The memory of device is critical, please release some memory.');
    }
  }
}
```

## WindowMode<sup>12+</sup>

Enumerates the window mode when the ability is started. It can be used together with [startAbility](js-apis-inner-application-uiAbilityContext.md#startability) to specify the window mode for starting the ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                       | Value| Description                |
| ---                         | --- | ---                  |
| WINDOW_MODE_FULLSCREEN      | 1   | Full screen mode. It takes effect only on 2-in-1 devices and tablets. |
| WINDOW_MODE_SPLIT_PRIMARY   | 100 | Primary screen (left screen in the case of horizontal orientation) in split-screen mode. It is valid only in intra-app redirection scenarios. It takes effect only on foldable devices and tablets.  |
| WINDOW_MODE_SPLIT_SECONDARY | 101 | Secondary screen (right screen in the case of horizontal orientation) in split-screen mode. It is valid only in intra-app redirection scenarios. It takes effect only on foldable devices and tablets.  |

**Example**

```ts
import { UIAbility, StartOptions, Want, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let option: StartOptions = {
  windowMode: AbilityConstant.WindowMode.WINDOW_MODE_SPLIT_PRIMARY
};

// Ensure that the context is obtained.
export default class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.startAbility(want, option).then(() => {
      console.log('Succeed to start ability.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to start ability with error: ${JSON.stringify(error)}`);
    });
  }
}
```

## OnSaveResult

Enumerates the result types for the operation of saving application data. You can use it in [onSaveState()](js-apis-app-ability-uiAbility.md#onsavestate) of the UIAbility to complete different operations.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALL_AGREE           | 0    | Always agreed to save the status.|
| CONTINUATION_REJECT           | 1    | Rejected to save the status in continuation.|
| CONTINUATION_MISMATCH  | 2    | Continuation mismatch.|
| RECOVERY_AGREE           | 3    | Agreed to restore the saved status.|
| RECOVERY_REJECT  | 4    | Rejected to restore the saved status.|
| ALL_REJECT  | 5    | Always rejected to save the status.|

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {
    return AbilityConstant.OnSaveResult.ALL_AGREE;
  }
}
```

## StateType

Enumerates the scenarios for saving application data. You can use it in [onSaveState()](js-apis-app-ability-uiAbility.md#onsavestate) of the UIAbility to complete different operations.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                         | Value  | Description                                                        |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| CONTINUATION           | 0    | Application migration scenario.|
| APP_RECOVERY           | 1    | Application recovery scenario.|

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {
    if (reason === AbilityConstant.StateType.CONTINUATION) {
      console.log('Save the ability data when the ability continuation.');
    }
    return AbilityConstant.OnSaveResult.ALL_AGREE;
  }
}
```

## ContinueState<sup>10+</sup>

Enumerates the mission continuation states of the application. It is used in the [setMissionContinueState](js-apis-inner-application-uiAbilityContext.md#setmissioncontinuestate10) API of [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Value      | Description                                                        |
| ------------- | --------- | ------------------------------------------------------------ |
| ACTIVE        | 0         | Mission continuation is activated for the current application.                             |
| INACTIVE      | 1         | Mission continuation is not activated for the current application.                           |

**Example**

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE, (result: BusinessError) => {
      console.info(`setMissionContinueState: ${JSON.stringify(result)}`);
    });
  }
}
```

## CollaborateResult<sup>18+</sup>

Enumerates the collaboration request results. This enum is used in multi-device collaboration scenarios to specify whether the target application accepts the collaboration request from the caller application. It is used in [onCollaborate()](js-apis-app-ability-uiAbility.md#oncollaborate18) of the UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name    | Value  | Description      |
| -------- | ---- | ---------- |
| ACCEPT   | 0    | Accepts the collaboration request.|
| REJECT   | 1    | Rejects the collaboration request.|

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onCollaborate(wantParam: Record<string, Object>) {
    return AbilityConstant.CollaborateResult.ACCEPT;
  }
}
```

## PrepareTermination<sup>15+</sup>

Enumerates the actions triggered when an application is closed by the user. It must be used together with [onPrepareTermination](js-apis-app-ability-abilityStage.md#onpreparetermination15) or [onPrepareTerminationAsync](js-apis-app-ability-abilityStage.md#onprepareterminationasync15) of [AbilityStage](js-apis-app-ability-abilityStage.md).

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| ------------- | --------- | ----------- |
| TERMINATE_IMMEDIATELY | 0 | Executes the termination action immediately. This is the default behavior.|
| CANCEL | 1 | Cancels the termination action.|

**Example**

```ts
import { AbilityConstant, AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onPrepareTermination(): AbilityConstant.PrepareTermination {
    console.info('MyAbilityStage.onPrepareTermination is called');
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```
