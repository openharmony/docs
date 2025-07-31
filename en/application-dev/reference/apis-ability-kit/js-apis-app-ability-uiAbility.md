# @ohos.app.ability.UIAbility (ExtensionAbilities with UI)

UIAbility is an application component that has the UI. It inherits from [Ability](js-apis-app-ability-ability.md) and provides [lifecycle](#uiability-lifecycle-states) callbacks such as component creation, destruction, and foreground/background switching. It also provides the [background communication capability](#background-communication-capability).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

For details about the inheritance relationship of each ability, see [Inheritance Relationship](./js-apis-app-ability-ability.md#ability-inheritance-relationship).

## UIAbility Lifecycle States

**Figure 1** UIAbility lifecycle states

![Ability lifecycle](../../application-models/figures/Ability-Life-Cycle.png)

- **Create**: A UIAbility instance has been created. The system triggers the [onCreate](#oncreate) callback in this state, where you can perform initialization operations.
- **Foreground**: The UIAbility has been brought to the foreground. The system triggers the [onForeground](#onforeground) callback in this state, where you can request resources required by the application.
- **Background**: The UIAbility has been moved to the background. The system triggers the [onBackground](#onbackground) callback in this state, where you can release some application resources.
- **Destroy**: The UIAbility instance is about to be destroyed. The system triggers the [onDestroy](#ondestroy) callback in this state, where you can save data.

## Background Communication Capability

**Call** invocations can be used for background communication with the target UIAbility. The following figure shows the Call invocation.


**Figure 2** Diagram of Call invocation

![call](../../application-models/figures/call.png)

- The Caller UIAbility uses [startAbilityByCall()](js-apis-inner-application-uiAbilityContext.md#startabilitybycall) to obtain a [Caller](#caller) object and then uses the [call](#call) API of the Caller object to send data to the Callee UIAbility.

- The Callee UIAbility holds a [Callee](#callee) object and uses the [on](#on) API of the Callee object to register a callback function for receiving data sent by the Caller object.

## Modules to Import

```ts
import { UIAbility } from '@kit.AbilityKit';
```

## UIAbility

Application component that has the UI. It provides lifecycle callbacks such as component creation, destruction, and foreground/background switching, and supports component collaboration.

### Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) | No| No| Context of the UIAbility.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| launchWant | [Want](js-apis-app-ability-want.md) | No| No| Want in the request used to cold start the UIAbility. The value is the Want received in [onCreate](#oncreate).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| lastRequestWant | [Want](js-apis-app-ability-want.md) | No| No| Want in the most recent request to launch the UIAbility.<br>- On the first launch of a UIAbility, it is the Want parameter received in [onCreate](#oncreate).<br>- On subsequent launches, it is the most recent Want received in [onNewWant](#onnewwant).<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| callee | [Callee](#callee) | No| No| Background communication object created by the system for the UIAbility, known as the Callee UIAbility (Callee), which is capable of receiving data sent from the Caller object.|


### onCreate

onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void

Called when a UIAbility instance is created. You can execute initialization logic (such as defining variables and loading resources) in this callback. This callback is invoked during a [cold start](../../application-models/uiability-intra-device-interaction.md#cold-starting-uiability) of the UIAbility.

This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Data passed by the caller when launching the UIAbility.|
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | Yes| Parameters for application launch, including the reason for application launch and the reason for the last application exit.|

**Example**


```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class MyUIAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    // Execute an asynchronous task.
    hilog.info(0x0000, 'testTag', `onCreate, want: ${want.abilityName}`);
    hilog.info(0x0000, 'testTag', `the launchReason is +  ${launchParam.launchReason} + , the lastExitReason is  + ${launchParam.lastExitReason}`);
  }
}
```


### onWindowStageCreate

onWindowStageCreate(windowStage: window.WindowStage): void

Called when a WindowStage instance is created. You can load a page through the WindowStage instance in this callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage instance.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

export default class MyUIAbility extends UIAbility {
  // The main window has been created. Set the main page for the UIAbility.
  onWindowStageCreate(windowStage: window.WindowStage): void {
    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', `Failed to load the content. Cause: ${JSON.stringify(err)}`);
        return;
      }
      hilog.info(0x0000, 'testTag', `Succeeded in loading the content. Data: ${JSON.stringify(data)}`);
    });
  }
}
```


### onWindowStageWillDestroy<sup>12+</sup>

onWindowStageWillDestroy(windowStage: window.WindowStage): void

Called when the WindowStage instance is about to be destroyed. You can cancel the listening of WindowStage events in this lifecycle.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage instance.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

export default class MyUIAbility extends UIAbility {
  onWindowStageWillDestroy(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', `onWindowStageWillDestroy`);
  }
}
```


### onWindowStageDestroy

onWindowStageDestroy(): void

Called when the WindowStage instance has been destroyed. It informs applications that the WindowStage instance is no longer available for use.

The callback is invoked only when the UIAbility exits gracefully. It is not invoked in cases of abnormal exits (for example, due to low memory conditions).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class MyUIAbility extends UIAbility {
  onWindowStageDestroy() {
    // The main window is destroyed. It is time to release UI resources.
    hilog.info(0x0000, 'testTag', `onWindowStageDestroy`);
  }
}
```


### onWindowStageRestore

onWindowStageRestore(windowStage: window.WindowStage): void

Called when the page stack is restored for the target UIAbility during cross-device migration.

> **NOTE**
>
> When an application is launched as a result of a migration, the **onWindowStageRestore()** lifecycle callback function, rather than **onWindowStageCreate()**, is triggered following [onCreate()](#oncreate) or [onNewWant()](#onnewwant). This sequence occurs for both cold and hot starts.


**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| WindowStage instance.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

export default class MyUIAbility extends UIAbility {
  onWindowStageRestore(windowStage: window.WindowStage) {
    hilog.info(0x0000, 'testTag', `onWindowStageRestore`);
  }
}
```


### onDestroy

onDestroy(): void | Promise&lt;void&gt;

Called when the UIAbility is destroyed (for example, when the UIAbility is terminated using the [terminateSelf](js-apis-inner-application-uiAbilityContext.md#terminateself) API). You can clear resources and save data during this lifecycle. This API returns the result synchronously or uses a promise to return the result.

After the **onDestroy()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDestroy()** may fail to be executed. Using a Promise for asynchronous callback is recommended to prevent such issues.

The callback is invoked only when the UIAbility exits gracefully. It is not invoked in cases of abnormal exits (for example, due to low memory conditions).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -------- | -------- |
| void&nbsp;\|&nbsp;Promise&lt;void&gt; | No return value or a Promise object that returns no result.|

**Example**

- A synchronous callback example is as follows:

  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class MyUIAbility extends UIAbility {
    onDestroy() {
      hilog.info(0x0000, 'testTag', `onDestroy`);
      // Call the synchronous function.
    }
  }
  ```

- A promise asynchronous callback example is as follows:

  ```ts
  import { UIAbility } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class MyUIAbility extends UIAbility {
    async onDestroy() {
      hilog.info(0x0000, 'testTag', `onDestroy`);
      // Call the asynchronous function.
    }
  }
  ```


### onWillForeground<sup>20+</sup>

onWillForeground(): void

Called just before the application transitions to the foreground. It is called before [onForeground](#onforeground). It can be used to capture the moment when the application starts to transition to the foreground. When paired with [onDidForeground](#ondidforeground20), it can also measure the duration from the application's initial foreground entry to its full transition into the foreground state.

This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  // ...

  onWillForeground(): void {
    // Start to log the event that the application starts moving to the foreground.
    let eventParams: Record<string, number> = { 'xxxx': 100 };
    let eventInfo: hiAppEvent.AppEventInfo = {
      // Define the event domain.
      domain: "lifecycle",
      // Define the event name.
      name: "onwillforeground",
      // Define the event type.
      eventType: hiAppEvent.EventType.BEHAVIOR,
      // Define the event parameters.
      params: eventParams,
    };
    hiAppEvent.write(eventInfo).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`);
    });
  }
  // ...

  onDidForeground(): void {
    // Start to log the event that the application fully transitions to the foreground.
    let eventParams: Record<string, number> = { 'xxxx': 100 };
    let eventInfo: hiAppEvent.AppEventInfo = {
      // Define the event domain.
      domain: "lifecycle",
      // Define the event name.
      name: "ondidforeground",
      // Define the event type.
      eventType: hiAppEvent.EventType.BEHAVIOR,
      // Define the event parameters.
      params: eventParams,
    };
    hiAppEvent.write(eventInfo).then(() => {
      hilog.info(0x0000, 'testTag', `HiAppEvent success to write event`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `HiAppEvent err.code: ${err.code}, err.message: ${err.message}`);
    });
  }
}
```


### onForeground

onForeground(): void

Called when the application is initially launched into the foreground or transitions from the background to the foreground. You can request necessary system resources, for example, requesting location services when the application transitions to the foreground, within this callback.

This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**


```ts
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class MyUIAbility extends UIAbility {
  onForeground() {
    // Execute an asynchronous task.
    hilog.info(0x0000, 'testTag', `onForeground`);
  }
}
```


### onDidForeground<sup>20+</sup>

onDidForeground(): void

Called after the application has transitioned to the foreground. It is called after [onForeground](#onforeground). It can be used to capture the moment when the application fully transitions to the foreground. When paired with [onWillForeground](#onwillforeground20), it can also measure the duration from the application's initial foreground entry to its full transition into the foreground state.

This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

For details, see [onWillForeground](#onwillforeground20).


### onWillBackground<sup>20+</sup>

onWillBackground(): void

Called just when the application transitions to the background. It is called before [onBackground](#onbackground). It can be used to log various types of data, such as faults, statistics, security information, and user behavior that occur during application running.

This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hiAppEvent, hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class MyUIAbility extends UIAbility {
  onWillBackground(): void {
    let eventParams: Record<string, number | string> = {
      "int_data": 100,
      "str_data": "strValue",
    };
    // Record the application fault information.
    hiAppEvent.write({
      domain: "test_domain",
      name: "test_event",
      eventType: hiAppEvent.EventType.FAULT,
      params: eventParams,
    }, (err: BusinessError) => {
      if (err) {
        hilog.error(0x0000, 'testTag', `hiAppEvent code: ${err.code}, message: ${err.message}`);
        return;
      }
      hilog.info(0x0000, 'testTag', `hiAppEvent success to write event`);
    });
  }
}
```


### onBackground

onBackground(): void

Called when the application transitions from the foreground to the background. You can release resources when the UI is no longer visible, for example, stopping location services, within this callback.

This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class MyUIAbility extends UIAbility {
  onBackground() {
    // The UIAbility transitions to the background.
    hilog.info(0x0000, 'testTag', `onBackground`);
  }
}
```


### onDidBackground<sup>20+</sup>

onDidBackground(): void

Called after the application has transitioned to the background. It is called after [onBackground](#onbackground). It can be used to release resources after the application has entered the background, for example, stopping audio playback.

This API returns the result synchronously and does not support asynchronous callback.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { audio } from '@kit.AudioKit';

export default class MyUIAbility extends UIAbility {
  static audioRenderer: audio.AudioRenderer;
  // ...
  onForeground(): void {
    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // Sampling rate.
      channels: audio.AudioChannel.CHANNEL_2, // Channel.
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // Sampling format.
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // Encoding format.
    };

    let audioRendererInfo: audio.AudioRendererInfo = {
      usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // Audio stream usage type: music. Set this parameter based on the service scenario.
      rendererFlags: 0 // AudioRenderer flag.
    };

    let audioRendererOptions: audio.AudioRendererOptions = {
      streamInfo: audioStreamInfo,
      rendererInfo: audioRendererInfo
    };

    // Request an AudioRenderer in the foreground to play Pulse Code Modulation (PCM) audio data.
    audio.createAudioRenderer(audioRendererOptions).then((data) => {
      MyUIAbility.audioRenderer = data;
      hilog.info(0x0000, 'testTag', `AudioRenderer Created : Success : Stream Type: SUCCESS.`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `AudioRenderer Created : F : ${JSON.stringify(err)}.`);
    });
  }

  onDidBackground() {
    // Release the AudioRenderer after transitioning to the background.
    MyUIAbility.audioRenderer.release((err: BusinessError) => {
      if (err) {
        hilog.error(0x0000, 'testTag', `AudioRenderer release failed, error: ${JSON.stringify(err)}.`);
      } else {
        hilog.info(0x0000, 'testTag',  `AudioRenderer released.`);
      }
    });
  }
}
```

### onContinue

onContinue(wantParam: Record&lt;string, Object&gt;): AbilityConstant.OnContinueResult | Promise&lt;AbilityConstant.OnContinueResult&gt;

Called to save data during the UIAbility migration preparation process.

> **NOTE**
>
> Since API version 12, **UIAbility.onContinue** supports the return value in the form of Promise\<[AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)\>.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Data to be migrated.|

**Return value**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)&nbsp;\|&nbsp;Promise&lt;[AbilityConstant.OnContinueResult](js-apis-app-ability-abilityConstant.md#oncontinueresult)&gt;  | Whether the migration is accepted. The options are as follows:<br>- **AGREE**: The migration is allowed.<br>- **REJECT**: The migration is rejected, for example, when an application is abnormal in **onContinue()**.<br>- **MISMATCH**: The application versions of the source and target devices do not match. The application on the source device can obtain the version of the target application from **onContinue**. If the ability continuation cannot be performed due to version mismatch, this result is returned.<br> This callback comes in pairs with **onWindowStageRestore**. In ability continuation scenarios, the source UIAbility triggers **onContinue** to save custom data, and the target UIAbility triggers **onWindowStageRestore** to restore the custom data.|

**Example**

- The following is an example of saving data using a synchronous API during application migration:

  ```ts
  import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

  export default class MyUIAbility extends UIAbility {
    onContinue(wantParams: Record<string, Object>) {
      console.info('onContinue');
      wantParams['myData'] = 'my1234567';
      return AbilityConstant.OnContinueResult.AGREE;
    }
  }
  ```

- The following is an example of saving data using an asynchronous API during application migration:

  ```ts
  import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

  export default class MyUIAbility extends UIAbility {
    async setWant(wantParams: Record<string, Object>) {
      console.info('setWant start');
      for (let time = 0; time < 1000; ++time) {
        wantParams[time] = time;
      }
      console.info('setWant end');
    }

    async onContinue(wantParams: Record<string, Object>) {
      console.info('onContinue');
      return this.setWant(wantParams).then(() => {
        return AbilityConstant.OnContinueResult.AGREE;
      });
    }
  }
  ```


### onNewWant

onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void

Called when a UIAbility instance, which has been in the foreground, is brought up again. If there are specific scenarios where you do not want this lifecycle callback to be triggered, you can use [setOnNewWantSkipScenarios](./js-apis-inner-application-uiAbilityContext.md#setonnewwantskipscenarios20) to set those [scenarios](./js-apis-app-ability-contextConstant.md#scenarios20).


**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Data passed by the caller when re-launching the UIAbility.|
| launchParam | [AbilityConstant.LaunchParam](js-apis-app-ability-abilityConstant.md#launchparam) | Yes| Reason for re-launching the UIAbility.|

**Example**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

export default class MyUIAbility extends UIAbility {
  onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info(`onNewWant, want: ${want.abilityName}`);
    console.info(`onNewWant, launchParam: ${JSON.stringify(launchParam)}`);
  }
}
```

### onDump

onDump(params: Array\<string>): Array\<string>

Called when UIAbility data is dumped by running the dump command during application debugging. You can return non-sensitive information to be dumped by the UIAbility in this callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters for the dump command.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array\<string> | Information returned by the dump operation.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyUIAbility extends UIAbility {
  onDump(params: Array<string>) {
    console.info(`dump, params: ${JSON.stringify(params)}`);
    return ['params'];
  }
}
```


### onSaveState

onSaveState(reason: AbilityConstant.StateType, wantParam: Record&lt;string, Object&gt;): AbilityConstant.OnSaveResult

Called when the framework automatically saves the UIAbility state in the case of an application fault. This API is used together with [appRecovery](js-apis-app-ability-appRecovery.md). When an application is faulty, the framework calls **onSaveState** to save the status of the UIAbility if auto-save is enabled.

When the application has enabled the fault recovery feature (with the **saveOccasion** parameter in [enableAppRecovery](js-apis-app-ability-appRecovery.md#apprecoveryenableapprecovery) set to **SAVE_WHEN_ERROR**), this callback is invoked to save the UIAbility data in the case of an application fault.

> **NOTE**
>
> Since API version 20, this callback is not executed when [UIAbility.onSaveStateAsync](#onsavestateasync20) is implemented.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reason | [AbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#statetype) | Yes| Reason for triggering the application to save its state. Currently, only **APP_RECOVERY** (fault recovery scenario) is supported.|
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Custom application state data, which is stored in **Want.parameters** in **onCreate** when the application restarts.|

**Return value**

| Type| Description|
| -------- | -------- |
| [AbilityConstant.OnSaveResult](js-apis-app-ability-abilityConstant.md#onsaveresult) | An object indicating the data-saving policy (for example, all denied, all allowed, or only allowed in fault recovery scenarios).|

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

export default class MyUIAbility extends UIAbility {
  onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {
    console.info('onSaveState');
    wantParam['myData'] = 'my1234567';
    return AbilityConstant.OnSaveResult.RECOVERY_AGREE;
  }
}
```

### onSaveStateAsync<sup>20+</sup>

onSaveStateAsync(stateType: AbilityConstant.StateType, wantParam: Record&lt;string, Object&gt;): Promise\<AbilityConstant.OnSaveResult>

When the application has enabled the fault recovery feature (with the **saveOccasion** parameter in [enableAppRecovery](js-apis-app-ability-appRecovery.md#apprecoveryenableapprecovery) set to **SAVE_WHEN_ERROR**), this callback is invoked to save the UIAbility data in the case of an application fault. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| stateType | [AbilityConstant.StateType](js-apis-app-ability-abilityConstant.md#statetype) | Yes| Reason for triggering the application to save its state. Currently, only **APP_RECOVERY** (fault recovery scenario) is supported.|
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Custom application state data, which is stored in **Want.parameters** when the application restarts.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<[AbilityConstant.OnSaveResult](js-apis-app-ability-abilityConstant.md#onsaveresult)> | Promise used to return the result. An object indicating the data-saving policy (for example, all denied, all allowed, or only allowed in fault recovery scenarios).|

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyUIAbility extends UIAbility {
  async onSaveStateAsync(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) : Promise<AbilityConstant.OnSaveResult> {
    await new Promise<string>((res, rej) => {
      setTimeout(res, 1000); // Execute the operation after 1 second.
    });
    return AbilityConstant.OnSaveResult.RECOVERY_AGREE;
  }
}
```

### onShare<sup>10+</sup>

onShare(wantParam: Record&lt;string, Object&gt;): void

Called when an atomic service is shared across devices. You can set the title, abstract, and URL of the atomic service to be shared in this callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes| Data to share.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class MyUIAbility extends UIAbility {
  onShare(wantParams: Record<string, Object>) {
    console.info('onShare');
    wantParams['ohos.extra.param.key.shareUrl'] = 'example.com';
  }
}
```

### onPrepareToTerminate<sup>10+</sup>

onPrepareToTerminate(): boolean

Triggered by the system just before the UIAbility is about to close, allowing you to perform additional operations before the UIAbility is officially shut down. You can return **true** to block the current closure attempt and then manually call [terminateSelf](js-apis-inner-application-uiAbilityContext.md#terminateself) at an appropriate time to close it. For example, you might ask the user to confirm whether they want to close the UIAbility and then proceed with the closure manually.


> **NOTE**
>
> - Prerequisites: This API takes effect only on 2-in-1 devices and requires the application to have the ohos.permission.PREPARE_APP_TERMINATE permission.
>
> - Trigger scenario: This API can be used when the user closes the application by clicking the close button in the top-right corner of the application window or by right-clicking to exit from the dock or system tray.
>
> - Since API version 15, this callback is not executed when[UIAbility.onPrepareToTerminateAsync](#onpreparetoterminateasync15) is implemented. When [AbilityStage.onPrepareTerminationAsync](js-apis-app-ability-abilityStage.md#onprepareterminationasync15) or [AbilityStage.onPrepareTermination](js-apis-app-ability-abilityStage.md#onpreparetermination15) is implemented, this callback is not executed if the user right-clicks the dock bar or system tray to close the UIAbility.
> - Additionally, if the application or a third-party framework registers a listener for [window.WindowStage.on('windowStageClose')](../apis-arkui/arkts-apis-window-WindowStage.md#onwindowstageclose14), this callback is not executed.

**Required permissions**: ohos.permission.PREPARE_APP_TERMINATE

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -- | -- |
| boolean | Whether to terminate the UIAbility. The value **true** means that the termination process is canceled. The value **false** means to continue terminating the UIAbility.|

**Example**

```ts
import { UIAbility, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends UIAbility {
  onPrepareToTerminate() {
    // Define a pre-termination operation,
    // for example, starting another UIAbility and performing asynchronous termination based on the startup result.
    let want: Want = {
      bundleName: "com.example.myapplication",
      moduleName: "entry",
      abilityName: "SecondAbility"
    }
    this.context.startAbilityForResult(want)
      .then((result)=>{
        // Obtain the startup result and terminate the current UIAbility when resultCode in the return value is 0.
        console.info('startAbilityForResult success, resultCode is ' + result.resultCode);
        if (result.resultCode === 0) {
          this.context.terminateSelf();
        }
      }).catch((err: BusinessError)=>{
      // Exception handling.
      console.error('startAbilityForResult failed, err:' + JSON.stringify(err));
      this.context.terminateSelf();
    })

    return true; // The pre-termination operation is defined. The value true means that the UIAbility termination process is canceled.
  }
}
```

### onPrepareToTerminateAsync<sup>15+</sup>

onPrepareToTerminateAsync(): Promise\<boolean>

Triggered by the system just before the UIAbility is about to close, allowing you to perform additional operations before the UIAbility is officially shut down.

You can return **true** to block the current closure attempt and then manually call [terminateSelf](js-apis-inner-application-uiAbilityContext.md#terminateself) at an appropriate time to close it. For example, you might ask the user to confirm whether they want to close the UIAbility and then proceed with the closure manually.


> **NOTE**
>
> - Prerequisites: This API takes effect only on 2-in-1 devices and requires the application to have the ohos.permission.PREPARE_APP_TERMINATE permission.
>
> - Trigger scenario: This API can be used when the user closes the application by clicking the close button in the top-right corner of the application window or by right-clicking to exit from the dock or system tray.
>
> - When [AbilityStage.onPrepareTerminationAsync](js-apis-app-ability-abilityStage.md#onprepareterminationasync15) or [AbilityStage.onPrepareTermination](js-apis-app-ability-abilityStage.md#onpreparetermination15) is implemented, this callback is not executed if the user right-clicks the dock bar or system tray to close the UIAbility.
> - Additionally, if the application or a third-party framework registers a listener for [window.WindowStage.on('windowStageClose')](../apis-arkui/arkts-apis-window-WindowStage.md#onwindowstageclose14), this callback is not executed.
>
> - If an asynchronous callback crashes, it will be handled as a timeout. If the UIAbility does not respond within 10 seconds, it will be terminated forcibly.

**Required permissions**: ohos.permission.PREPARE_APP_TERMINATE

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -- | -- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the termination process is canceled. The value **false** means to continue terminating the UIAbility.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  async onPrepareToTerminateAsync(): Promise<boolean> {
    await new Promise<boolean>((res, rej) => {
      setTimeout (res, 2000); // Execute the operation 2 seconds later.
    });
    return true; // The pre-termination operation is defined. The value true means that the UIAbility termination process is canceled.
  }
}
```

### onBackPressed<sup>10+</sup>

onBackPressed(): boolean

Called when an operation of going back to the previous page is triggered on this UIAbility. The return value determines whether to destroy the UIAbility instance.

- When the target SDK version is earlier than 12, the default return value is **false**, indicating that the UIAbility will be destroyed.
- When the target SDK version is 12 or later, the default return value is **true**, indicating that the UIAbility will be moved to the background and will not be destroyed.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Return value**

| Type| Description|
| -- | -- |
| boolean | The value **true** means that the UIAbility instance will be moved to the background and will not be destroyed, and **false** means that the UIAbility instance will be destroyed.|

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onBackPressed() {
    return true;
  }
}
```

### onCollaborate<sup>18+</sup>

onCollaborate(wantParam: Record&lt;string, Object&gt;): AbilityConstant.CollaborateResult

Callback invoked to return the collaboration result in multi-device collaboration scenarios.

 **NOTE**
- This callback does not support ability launch in specified mode.
- When you use methods such as **startAbility()** to start an application, you must include **FLAG_ABILITY_ON_COLLABORATE** in [Flags](js-apis-ability-wantConstant.md#flags) in the Want object.
- During a cold start, this callback must be invoked before [onForeground](#onforeground) or after [onBackground](#onbackground). During a hot start, this callback must be invoked before [onNewWant](#onnewwant).


**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name   | Type                             | Mandatory| Description                                                        |
| --------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| wantParam | Record&lt;string,&nbsp;Object&gt; | Yes  | Want parameter, which supports only the key **"ohos.extra.param.key.supportCollaborateIndex"**. The key can be used to obtain the data passed by the caller and perform corresponding processing.|

**Return value**

| Type    | Description  |
| -------- | ---- |
| [AbilityConstant.CollaborateResult](js-apis-app-ability-abilityConstant.md#collaborateresult18) | Whether the coordinator accepts the collaboration result.|

**Example**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbility extends UIAbility {
  onCollaborate(wantParam: Record<string, Object>) {
    return AbilityConstant.CollaborateResult.ACCEPT;
  }
}
```

## Caller

A Caller UIAbility (which must be a system application) can use [startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#startabilitybycall) to start a Callee UIAbility (which can be a third-party application). The Callee UIAbility will provide a Caller object to the Caller UIAbility. Once the Caller UIAbility receives this Caller object, it can use it to communicate with the Callee UIAbility and transmit data.

### call

call(method: string, data: rpc.Parcelable): Promise&lt;void&gt;

Used by a Caller UIAbility to send serialized data, as agreed upon by both parties, to the Callee UIAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Method name agreed upon by the Caller UIAbility and Callee UIAbility, used by the Callee UIAbility to identify the type of message.|
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Yes| Message content sent from the Caller UIAbility to the Callee UIAbility, which is in serialized form.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | The caller has been released. |
| 16200002 | The callee does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyMessageAble implements rpc.Parcelable { // Custom parcelable data structure.
  name: string
  str: string
  num: number = 1
  constructor(name: string, str: string) {
    this.name = name;
    this.str = str;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    messageSequence.writeInt(this.num);
    messageSequence.writeString(this.str);
    console.info(`MyMessageAble marshalling num[${this.num}] str[${this.str}]`);
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    this.num = messageSequence.readInt();
    this.str = messageSequence.readString();
    console.info(`MyMessageAble unmarshalling num[${this.num}] str[${this.str}]`);
    return true;
  }
};
let method = 'call_Function'; // Notification message string negotiated by the two UIAbilities.
let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      let msg = new MyMessageAble('msg', 'world'); // See the definition of Parcelable.
      caller.call(method, msg)
        .then(() => {
          console.info('Caller call() called');
        })
        .catch((callErr: BusinessError) => {
          console.error(`Caller.call catch error, error.code: ${callErr.code}, error.message: ${callErr.message}`);
        });
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```


### callWithResult

callWithResult(method: string, data: rpc.Parcelable): Promise&lt;rpc.MessageSequence&gt;

Used by a Caller UIAbility to send serialized data to a Callee UIAbility and return the result after the Callee UIAbility processes the message. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Method name agreed upon by the Caller UIAbility and Callee UIAbility, used by the Callee UIAbility to identify the type of message.|
| data | [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Yes| Message content sent from the Caller UIAbility to the Callee UIAbility, which is in serialized form.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9)&gt; | Promise used to return the response data from the Callee UIAbility.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | The caller has been released. |
| 16200002 | The callee does not exist. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { rpc } from '@kit.IPCKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyMessageAble implements rpc.Parcelable {
  name: string
  str: string
  num: number = 1

  constructor(name: string, str: string) {
    this.name = name;
    this.str = str;
  }

  marshalling(messageSequence: rpc.MessageSequence) {
    messageSequence.writeInt(this.num);
    messageSequence.writeString(this.str);
    console.info(`MyMessageAble marshalling num[${this.num}] str[${this.str}]`);
    return true;
  }

  unmarshalling(messageSequence: rpc.MessageSequence) {
    this.num = messageSequence.readInt();
    this.str = messageSequence.readString();
    console.info(`MyMessageAble unmarshalling num[${this.num}] str[${this.str}]`);
    return true;
  }
}
let method = 'call_Function';
let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      let msg = new MyMessageAble('msg', 'world');
      caller.callWithResult(method, msg)
        .then((data) => {
          console.info('Caller callWithResult() called');
          let retMsg = new MyMessageAble('msg', 'world');
          data.readParcelable(retMsg);
        })
        .catch((callErr: BusinessError) => {
          console.error(`Caller.callWithResult catch error, error.code: ${callErr.code}, error.message: ${callErr.message}`);
        });
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```


### release

release(): void

Used by a Caller UIAbility to proactively release the connection with the Callee UIAbility. After this API is called, the Caller UIAbility can no longer use **call** or **callWithResult** to send messages to the Callee UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Error codes**

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 16200001 | The caller has been released. |
| 16200002 | The callee does not exist. |

**Example**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      try {
        caller.release();
      } catch (releaseErr) {
        console.error(`Caller.release catch error, error.code: ${releaseErr.code}, error.message: ${releaseErr.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### onRelease

onRelease(callback: OnReleaseCallback): void

Called by the Caller UIAbility to register for notifications when the Callee UIAbility disconnects. The callback is used to monitor events where the Callee UIAbility disconnects either intentionally or due to an error.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      try {
        caller.onRelease((str) => {
          console.info(`Caller OnRelease CallBack is called ${str}`);
        });
      } catch (error) {
        console.error(`Caller.onRelease catch error, error.code: $error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### onRemoteStateChange<sup>10+</sup>

onRemoteStateChange(callback: OnRemoteStateChangeCallback): void

Called when the remote UIAbility state changes in the collaboration scenario. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | [OnRemoteStateChangeCallback](#onremotestatechangecallback10) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let caller: Caller;
let dstDeviceId: string;

export default class MainAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: dstDeviceId
    }).then((obj) => {
      caller = obj;
      try {
        caller.onRemoteStateChange((str) => {
          console.info('Remote state changed ' + str);
        });
      } catch (error) {
        console.error(`Caller.onRemoteStateChange catch error, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${JSON.stringify(err.code)}, error.message: ${JSON.stringify(err.message)}`);
    })
  }
}
```

### on('release')

on(type: 'release', callback: OnReleaseCallback): void

Called by the Caller UIAbility to register for notifications when the Callee UIAbility disconnects. The callback is used to monitor events where the Callee UIAbility disconnects either intentionally or due to an error.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200001 | The caller has been released. |

**Example**

```ts
import { UIAbility, Caller } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      try {
        caller.on('release', (str) => {
          console.info(`Caller OnRelease CallBack is called ${str}`);
        });
      } catch (error) {
        console.error(`Caller.on catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### off('release')

off(type: 'release', callback: OnReleaseCallback): void

Unregister the notification for disconnection from the Callee UIAbility. This is the reverse operation of [Caller.on('release')](#onrelease-1). It is currently not supported.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|
| callback | [OnReleaseCallback](#onreleasecallback) | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { UIAbility, Caller, OnReleaseCallback } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      try {
        let onReleaseCallBack: OnReleaseCallback = (str) => {
          console.info(`Caller OnRelease CallBack is called ${str}`);
        };
        caller.on('release', onReleaseCallBack);
        caller.off('release', onReleaseCallBack);
      } catch (error) {
        console.error(`Caller.on or Caller.off catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

### off('release')

off(type: 'release'): void

Unregister the notification for disconnection from the Callee UIAbility. This is the reverse operation of [Caller.on('release')](#onrelease-1). It is currently not supported.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is fixed at **'release'**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { UIAbility, Caller, OnReleaseCallback } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let caller: Caller;

export default class MainUIAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    this.context.startAbilityByCall({
      bundleName: 'com.example.myservice',
      abilityName: 'MainUIAbility',
      deviceId: ''
    }).then((obj) => {
      caller = obj;
      try {
        let onReleaseCallBack: OnReleaseCallback = (str) => {
          console.info(`Caller OnRelease CallBack is called ${str}`);
        };
        caller.on('release', onReleaseCallBack);
        caller.off('release');
      } catch (error) {
        console.error(`Caller.on or Caller.off catch error, error.code: ${error.code}, error.message: ${error.message}`);
      }
    }).catch((err: BusinessError) => {
      console.error(`Caller GetCaller error, error.code: ${err.code}, error.message: ${err.message}`);
    });
  }
}
```

## Callee

Implements callbacks for caller notification registration and deregistration.

### on

on(method: string, callback: CalleeCallback): void

Registers a caller notification callback, which is invoked when the target UIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Notification message string negotiated between the two UIAbilities.|
| callback | [CalleeCallback](#calleecallback) | Yes| JS notification synchronization callback of the [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) type. The callback must return at least one empty [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) object. Otherwise, the function execution fails.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200004 | The method has been registered. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

class MyMessageAble implements rpc.Parcelable {
  name: string
  str: string
  num: number = 1
  constructor(name: string, str: string) {
    this.name = name;
    this.str = str;
  }
  marshalling(messageSequence: rpc.MessageSequence) {
    messageSequence.writeInt(this.num);
    messageSequence.writeString(this.str);
    console.info(`MyMessageAble marshalling num[${this.num}] str[${this.str}]`);
    return true;
  }
  unmarshalling(messageSequence: rpc.MessageSequence) {
    this.num = messageSequence.readInt();
    this.str = messageSequence.readString();
    console.info(`MyMessageAble unmarshalling num[${this.num}] str[${this.str}]`);
    return true;
  }
};
let method = 'call_Function';

function funcCallBack(pdata: rpc.MessageSequence) {
  console.info(`Callee funcCallBack is called ${pdata}`);
  let msg = new MyMessageAble('test', '');
  pdata.readParcelable(msg);
  return new MyMessageAble('test1', 'Callee test');
}
export default class MainUIAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info('Callee onCreate is called');
    try {
      this.callee.on(method, funcCallBack);
    } catch (error) {
      console.error(`Callee.on catch error, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

### off

off(method: string): void

Unregisters a caller notification callback, which is invoked when the target UIAbility registers a function.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| method | string | Yes| Registered notification message string.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| ------- | -------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 16200005 | The method has not been registered. |
| 16000050 | Internal error. |

**Example**

```ts
import { UIAbility, AbilityConstant, Want } from '@kit.AbilityKit';

let method = 'call_Function';

export default class MainUIAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    console.info('Callee onCreate is called');
    try {
      this.callee.off(method);
    } catch (error) {
      console.error(`Callee.off catch error, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

## OnReleaseCallback

### (msg: string)

(msg: string): void

Defines the callback that is invoked when the stub on the target UIAbility is disconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| msg | string | Yes| Message used for disconnection.|

## OnRemoteStateChangeCallback<sup>10+</sup>

### (msg: string)

(msg: string): void

Defines the callback that is invoked when the remote UIAbility state changes in the collaboration scenario.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| msg | string | Yes| Message used for disconnection.|

## CalleeCallback

### (indata: rpc.MessageSequence)

(indata: rpc.MessageSequence): rpc.Parcelable

Defines the callback of the registration message notification of the UIAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| --- | ----- | --- | -------- |
| indata | [rpc.MessageSequence](../apis-ipc-kit/js-apis-rpc.md#messagesequence9) | Yes| Data to be transferred.|

**Return value**

| Type  | Description                                 |
| ------------ | ------------------------------------- |
| [rpc.Parcelable](../apis-ipc-kit/js-apis-rpc.md#parcelable9) | Returned data object.|
