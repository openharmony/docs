# Developing Intents Using Configuration Files
## When to Use
Starting from API version 11, you can develop intents using configuration files. Intents must be bound to application components. The table below describes the supported component types, their intent configurations, and corresponding intent executors.

| Component Type| Intent Configuration| Intent Executor|
| --- | --- | --- |
| UIAbility | Configure the **uiAbility** field in the **insight_intent.json** file.| When **executeMode** is set to **foreground**, implement **onExecuteInUIAbilityForegroundMode** to start the bound UIAbility via **startAbility**.<br>When **executeMode** is set to **background**, implement **onExecuteInUIAbilityBackgroundMode** to start the bound UIAbility via [Call](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#background-communication-capability).|
| UIExtensionAbility | Configure the **uiExtension** field in the **insight_intent.json** file.| Implement **onExecuteInUIExtensionAbility**.|
|<!--DelRow--> ServiceExtensionAbility | Configure the **serviceExtension** field in the **insight_intent.json** file.| Implement **onExecuteInServiceExtensionAbility**.|
| Widget (FormExtensionAbility)| Configure the **form** field in the **insight_intent.json** file.| No separate executor required.|

## Available APIs
To implement an intent executor, inherit from [InsightIntentExecutor](../reference/apis-ability-kit/js-apis-app-ability-insightIntentExecutor.md#insightintentexecutor) and implement APIs such as [onExecuteInUIAbilityForegroundMode](../reference/apis-ability-kit/js-apis-app-ability-insightIntentExecutor.md#onexecuteinuiabilityforegroundmode). To respond to intent execution, implementing these APIs. The triggering timing varies based on the intent execution mode. For details about the execution timing under different modes, see the API documentation of each callback.

## How to Develop
### Binding an Intent to a UIAbility

You can create intents in a visualized manner using DevEco Studio. The procedure is as follows:
1. Right-click a module or a file in a module and choose **New** > **Insight Intent** to enter the InsightIntent framework configuration page.
2. Choose the intent vertical domain, the file name for the InsightIntent framework entry code, and the intent configuration, which includes the intent name and the bound application component.
3. When you have finished, click **Finish**.

    An **insight_intent.json** file is generated in **module > src > main > resource > base > profile**. You can view the current InsightIntent framework configuration details in this file.

    ```json
    {
      "insightIntents": [
        {
          "domain": "MusicDomain",
          "intentName": "PlayMusic",
          "intentVersion": "1.0.1",
          "srcEntry": "./ets/insightintents/PlayMusicExecutor.ets",
          "uiAbility": {
            "ability": "MusicPlayerAbility",
            "executeMode": [
              "foreground",
              "background"
            ]
          }
        }
      ]
    }
    ```

4. An entry code file is generated in **module > src > main > ets > insightintents**. Implement the functional code for the intent in the intent execution function.

    ```ts
    // This file is the entry point corresponding to the srcEntry field in intent configuration.
    import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';

    export default class PlayMusicExecutor extends InsightIntentExecutor {
      // The executeMode field in intent configuration is set to foreground. Therefore, this API should be implemented.
      async onExecuteInUIAbilityForegroundMode(intentName: string, params: Record<string, Object>,
        windowStage: window.WindowStage): Promise<insightIntent.ExecuteResult> {
        // Implement the playback logic.
        const result: insightIntent.ExecuteResult = {
          code: 0
        };
        return Promise.resolve(result);
      }

      // If executeMode in intent configuration is set to background, this API should be implemented.
      async onExecuteInUIAbilityBackgroundMode(intentName: string,
        params: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
        // Background control logic.
        const result: insightIntent.ExecuteResult = {
          code: 0
        };
        return Promise.resolve(result);
      }
    }
    ```

> **NOTE**
>
> The configuration file approach only provides basic execution capabilities. The parameter format must be negotiated between the developer and the system entry point.

You can also manually create the intent configuration file and intent executor according to the specifications. Pay attention to the following points:
- You must declare the bound application component and supported intent execution mode.
- The configuration file must be named **insight_intent.json**.
- The configuration file must be stored in **resources/base/profile**.
- Key fields in the configuration file must comply with the corresponding constraints.

### Binding an Intent to a UIExtensionAbility

Create a project by referring to the procedures provided in [Binding an Intent to a UIAbility](#binding-an-intent-to-a-uiability).

Example intent configuration:

```json
{
  "insightIntents": [
    {
      "domain": "MusicDomain",
      "intentName": "PlayMusic",
      "intentVersion": "1.0.1",
      "srcEntry": "./ets/insightintents/ExtensionExecutor.ets",
      "uiExtension": {
        "ability": "MusicExtensionAbility"
      }
    }
  ]
}
```

Implementation of the intent executor:

```ts
import { InsightIntentExecutor, insightIntent, UIExtensionContentSession } from '@kit.AbilityKit';

export default class IntentExecutorImpl extends InsightIntentExecutor {
  // The uiExtension is configured for the intent. Therefore, this API should be implemented.
  async onExecuteInUIExtensionAbility(name: string, param: Record<string, Object>,
    pageLoader: UIExtensionContentSession): Promise<insightIntent.ExecuteResult> {
    const result: insightIntent.ExecuteResult = {
      code: 0
    };
    return Promise.resolve(result);
  }
}
```

The system entry point executes the intent via the UIExtensionComponent.

<!--Del-->
### Binding an Intent to a ServiceExtensionAbility

Create a project by referring to the procedures provided in [Binding an Intent to a UIAbility](#binding-an-intent-to-a-uiability).

Example intent configuration:

```json
{
  "insightIntents": [
    {
      "domain": "MusicDomain",
      "intentName": "PlayMusic",
      "intentVersion": "1.0.1",
      "srcEntry": "./ets/insightintents/DownloadExecutor.ets",
      "serviceExtension": {
        "ability": "DownloadService"
      }
    }
  ]
}
```

Implementation of the intent executor:

```ts
import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';

export default class IntentExecutorImpl extends InsightIntentExecutor {
  // The serviceExtension is configured for the intent. Therefore, this API should be implemented.
  async onExecuteInServiceExtensionAbility(name: string,
    param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
    const result: insightIntent.ExecuteResult = {
      code: 0
    };
    return Promise.resolve(result);
  }
}
```

The system entry point executes this intent via [startServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md#serviceextensioncontextstartserviceextensionability).
<!--DelEnd-->

### Binding an Intent to a Widget

Create a project by referring to the procedures provided in [Binding an Intent to a UIAbility](#binding-an-intent-to-a-uiability).

Example intent configuration:

```json
{
  "insightIntents": [
    {
      "domain": "MusicDomain",
      "intentName": "PlayMusic",
      "intentVersion": "1.0.1",
      "srcEntry": "./ets/insightintents/WidgetExecutor.ets",
      "form": {
        "ability": "PlayerWidgetAbility",
        "formName": "mini_player"
      }
    }
  ]
}
```

The system entry point displays the widget content through the FormComponent.
