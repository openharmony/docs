# @ohos.app.ability.InsightIntentEntryExecutor (Base Class for Intent Call Execution of @InsightIntentEntry)

The module provides the base class for executing intent calls decorated with [@InsightIntentEntry](js-apis-app-ability-InsightIntentDecorator.md#insightintententry). It must be used together with the @InsightIntentEntry decorator.

You are required to implement the [onExecute()](#onexecute) callback for intent execution in the child class that inherits from this base class and use the @InsightIntentEntry decorator to decorate the child class.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { InsightIntentEntryExecutor } from '@kit.AbilityKit';
```

## InsightIntentEntryExecutor\<T>

### Properties

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

| Name              | Type           | Read-Only        | Optional| Description                                                        |
| ------------------ | ----------------| ---------- | ---- | ------------------------------------------------------------ |
| executeMode        | [insightIntent.ExecuteMode](./js-apis-app-ability-insightIntent.md#executemode) | No      | No  | Execution mode of the intent call, that is, execution mode supported when the bound ability is started.|
| context            | [InsightIntentContext](./js-apis-app-ability-insightIntentContext.md)          | No      | No | Intent call execution context.|
| windowStage        | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md)       | No      | Yes  | Window manager that displays the intent. It is valid only when **executeMode** is set to **UI_ABILITY_FOREGROUND** (the UIAbility needs to be displayed in the foreground during the intent call).   |
| uiExtensionSession     | [UIExtensionContentSession](./js-apis-app-ability-uiExtensionContentSession.md)       | No      | Yes  | Instance created when the [UIExtensionAbility](./js-apis-app-ability-uiExtensionAbility.md) loads the UI content. It takes effect only when **executeMode** is set to **UI_EXTENSION_ABILITY** (the UIExtensionAbility needs to be started during the intent call).   |

### onExecute

onExecute(): Promise\<insightIntent.IntentResult\<T>>

When the AI entry triggers intent call, the system starts the ability bound to the entry and automatically triggers this callback. This API uses a promise to return the result. You can implement intent operations in this callback.

The following table describes the relationship between the callback and the intent execution mode.

| Intent Execution Mode| API Calling Timing and Sequence|
| ----------- | -----------------|
| [UI_ABILITY_FOREGROUND](./js-apis-app-ability-insightIntent.md#executemode)<br>Foreground mode of the UIAbility| - If the UIAbility is cold started, the UIAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onWindowStageCreate**, **onExecute**, and **onForeground**.<br>- If the UIAbility is hot started in the background, the UIAbility lifecycle callbacks are triggered in the following sequence: **onNewWant**, **onExecute**, and **onForeground**.<br>- If the UIAbility is hot started in the foreground, the UIAbility lifecycle callbacks are triggered in the following sequence: **onExecute**.|
| [UI_ABILITY_BACKGROUND](./js-apis-app-ability-insightIntent.md#executemode)<br>Background mode of the UIAbility| - If the UIAbility is cold started, the UIAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onExecute**, and **onBackground**.<br>- If the UIAbility is hot started, the UIAbility lifecycle callbacks are triggered in the following sequence: **onExecute**.|
| [UI_EXTENSION_ABILITY](./js-apis-app-ability-insightIntent.md#executemode)<br>UIExtension mode| When an intent is called, the UIExtensionAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onSessionCreate**, **onExecute**, and **onForeground**.|
|<!--DelRow-->[SERVICE_EXTENSION_ABILITY](./js-apis-app-ability-insightIntent-sys.md)<br>ServiceExtension mode| When an intent is called, the ServiceExtensionAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onRequest**, and **onExecute**.|

**Model restriction**: This API can be used only in the stage model.

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
