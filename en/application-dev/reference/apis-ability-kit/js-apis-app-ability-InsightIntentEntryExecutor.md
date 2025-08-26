# @ohos.app.ability.InsightIntentEntryExecutor (Base Class for Intent Execution of @InsightIntentEntry)

The module provides the base class for implementing the execution of intents decorated with [@InsightIntentEntry](js-apis-app-ability-InsightIntentDecorator.md#insightintententry). It must be used together with the @InsightIntentEntry decorator.

You are required to implement the [onExecute()](#onexecute) callback for intent execution in the child class that inherits from this base class and use the @InsightIntentEntry decorator to decorate the child class.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { InsightIntentEntryExecutor } from '@kit.AbilityKit';
```

## InsightIntentEntryExecutor\<T>

### Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| executeMode | [insightIntent.ExecuteMode](./js-apis-app-ability-insightIntent.md#executemode) | No| No| Intent execution mode, that is, execution mode supported when the bound ability is started.|
| context | [InsightIntentContext](./js-apis-app-ability-insightIntentContext.md) | No| No| Context for intent execution.|
| windowStage | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | No| Yes| WindowStage instance, which is the same as the WindowStage instance in the [onWindowStageCreate](./js-apis-app-ability-uiAbility.md#onwindowstagecreate) API and can be used to load the page for intent execution. It is valid only when **executeMode** is set to **UI_ABILITY_FOREGROUND** (the UIAbility needs to be displayed in the foreground during intent execution).|
| uiExtensionSession | [UIExtensionContentSession](./js-apis-app-ability-uiExtensionContentSession.md) | No| Yes| UIExtensionContentSession instance, which is the same as the UIExtensionContentSession instance in the [onSessionCreate](./js-apis-app-ability-uiExtensionAbility.md#onsessioncreate) API and can be used to load the page for intent execution. It takes effect only when **executeMode** is set to **UI_EXTENSION_ABILITY** (the UIExtensionAbility needs to be started during intent execution).|

### onExecute

onExecute(): Promise\<insightIntent.IntentResult\<T>>

 When the AI entry triggers intent execution, the system starts the ability bound to this class and triggers this callback. You can implement the required intent operations in this callback. This API uses a promise to return the result.

The following table describes the relationship between the callback and the intent execution mode.

| Intent Execution Mode| API Calling Timing and Sequence|
| ----------- | -----------------|
| [UI_ABILITY_FOREGROUND](./js-apis-app-ability-insightIntent.md#executemode)<br>Foreground mode of the UIAbility| - If the UIAbility is cold started, the UIAbility lifecycle callbacks are triggered in the following sequence during intent execution: [onCreate](./js-apis-app-ability-uiAbility.md#oncreate), [onWindowStageCreate](./js-apis-app-ability-uiAbility.md#onwindowstagecreate), onExecute, and [onForeground](./js-apis-app-ability-uiAbility.md#onforeground).<br>- If the UIAbility is hot started in the background, the UIAbility lifecycle callbacks are triggered in the following sequence during intent execution: [onNewWant](./js-apis-app-ability-uiAbility.md#onnewwant), onExecute, and [onForeground](./js-apis-app-ability-uiAbility.md#onforeground).<br>- If the UIAbility is hot started in the foreground, the UIAbility lifecycle callbacks are triggered in the following sequence during intent execution: onExecute.|
| [UI_ABILITY_BACKGROUND](./js-apis-app-ability-insightIntent.md#executemode)<br>Background mode of the UIAbility| - If the UIAbility is cold started, the UIAbility lifecycle callbacks are triggered in the following sequence during intent execution: [onCreate](./js-apis-app-ability-uiAbility.md#oncreate), onExecute, and [onBackground](./js-apis-app-ability-uiAbility.md#onbackground).<br>- If the UIAbility is hot started, the UIAbility lifecycle callbacks are triggered in the following sequence during intent execution: onExecute.|
| [UI_EXTENSION_ABILITY](./js-apis-app-ability-insightIntent.md#executemode)<br>UIExtension mode| The UIExtensionAbility lifecycle callbacks are triggered in the following sequence during intent execution: [onCreate](./js-apis-app-ability-uiExtensionAbility.md#oncreate), [onSessionCreate](./js-apis-app-ability-uiExtensionAbility.md#onsessioncreate), onExecute, and [onForeground](./js-apis-app-ability-uiExtensionAbility.md#onforeground).|
|<!--DelRow-->[SERVICE_EXTENSION_ABILITY](./js-apis-app-ability-insightIntent-sys.md)<br>ServiceExtension mode| The ServiceExtensionAbility lifecycle callbacks are triggered in the following sequence during intent execution: [onCreate](./js-apis-app-ability-serviceExtensionAbility-sys.md#oncreate), [onRequest](./js-apis-app-ability-serviceExtensionAbility-sys.md#onrequest), and onExecute.|

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Atomic service API**: This API can be used in atomic services since API version 20.

**Return value**

| Type| Description|
|------|-----|
| Promise\<insightIntent.IntentResult\<T>>| Promise used to return an [insightIntent.IntentResult\<T>](js-apis-app-ability-insightIntent.md#intentresultt20) object, indicating the intent execution result.|

**Example**

```ts
import { insightIntent, InsightIntentEntry, InsightIntentEntryExecutor } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const LOG_TAG: string = 'testTag-EntryIntent';

// Use the @InsightIntentEntry decorator to define an intent.
@InsightIntentEntry({
  intentName: 'PlayMusic',
  domain: 'MusicDomain',
  intentVersion: '1.0.1',
  displayName: 'Play Music',
  displayDescription: 'Intent to play music',
  icon: $r('app.media.app_icon'),
  llmDescription: 'Supports passing song names to play music',
  keywords: ['music playback', 'play music', 'PlayMusic'],
  abilityName: 'EntryAbility',
  executeMode: [insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND],
  parameters: {
    'schema': 'http://json-schema.org/draft-07/schema#',
    'type': 'object',
    'title': 'Song Schema',
    'description': 'A schema for describing songs and their artists',
    'properties': {
      'songName': {
        'type': 'string',
        'description': 'The name of the song',
        'minLength': 1
      }
    },
    'required': ['songName']
  }
})
export default class PlayMusicDemo extends InsightIntentEntryExecutor<string> {
  songName: string = '';

  onExecute(): Promise<insightIntent.IntentResult<string>> {
    hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo executeMode %{public}s', JSON.stringify(this.executeMode));
    hilog.info(0x0000, LOG_TAG, '%{public}s', JSON.stringify(this));
    let storage = new LocalStorage();
    storage.setOrCreate('songName', this.songName);
    // Start the PlayMusicPage page based on the executeMode parameter.
    if (this.executeMode == insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND) {
      this.windowStage?.loadContent('pages/PlayMusicPage', storage);
    } else if (this.executeMode == insightIntent.ExecuteMode.UI_EXTENSION_ABILITY) {
      this.uiExtensionSession?.loadContent('pages/PlayMusicPage', storage);
    }
    // Define the intent execution result.
    let result: insightIntent.IntentResult<string> = {
      code: 123,
      result: 'result'
    }
    hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo return %{public}s', JSON.stringify(result));
    // Return the intent execution result in Promise mode.
    return Promise.reject(result);
  }
}
```
