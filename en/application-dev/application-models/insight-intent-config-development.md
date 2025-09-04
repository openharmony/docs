# Developing Intents Using Configuration Files

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @zhangyafei-echo-->
<!--Designer: @zhangyafei-echo-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## Overview
Starting from API version 11, you can develop intents using configuration files. This mainly involves two steps:

1. Define intents in the [insight_intent.json file](#description-of-the-insight_intentjson-file), and declare the code path of the intent executor and the bound ability component.

2. Implement the intent execution logic using [InsightIntentExecutor](../reference/apis-ability-kit/js-apis-app-ability-insightIntentExecutor.md#insightintentexecutor).

The fields to be configured and the intention executors to be implemented vary depending on the type of ability component, as described in the table below.

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
      // If executeMode in intent configuration is set to foreground, this API should be implemented.
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

## Description of the insight_intent.json File
The intention configuration file **insight_intent.json** is located in the **resources/base/profile** directory of the project. It is used to declare intent configuration information. In this file, the **insightIntents** array contains all intention configurations developed through the configuration file. It contains the following properties.

| Property| Description| Data Type| Optional|
| --- | --- | --- | --- |
| intentName | Intent name, which is the unique identifier of an intent. The value is a string starting with an uppercase letter and containing letters and digits.| String| No|
| domain | Domain name of the intent. It is used to categorize intents by domain (for example, video, music, and game).<!--RP1--><!--RP1End--> | String| No|
| intentVersion | Version number of the intent. It is used to distinguish and manage intents when their capabilities evolve. The value is a three-part data sequence separated by dots, for example, 1.0.1.| String| No|
| srcEntry | Relative path of the intent execution file. The value is a string with a maximum of 127 bytes.| String| No|
| uiAbility | Information about the UIAbility bound to the intent. It contains the **ability** and **executeMode** fields.<br>- **ability**: mandatory; name of the UIAbility. The value must be the same as that of **name** in the [abilities tag](../quick-start/module-configuration-file.md#abilities) of the **module.json5** file.<br>- **executeMode**: mandatory; execution mode. The value can be **foreground** or **background**.<br> &nbsp; &nbsp; - **foreground**: The intent logic can be executed when the UIAbility is launched in the foreground.<br>&nbsp; &nbsp; - **background**: The intent logic can be executed when the UIAbility is launched in the background. | Object| Yes|
| <!--DelRow--> serviceExtension | Information about the ServiceExtensionAbility bound to the intent. It contains only the **ability** field, which is mandatory and specifies the name of the ServiceExtensionAbility. The value must be the same as that of **name** in the [extensionAbilities tag](../quick-start/module-configuration-file.md#extensionabilities) of the **module.json5** file.| Object| Yes|
| uiExtension | Information about the UIExtensionAbility bound to the intent. It contains only the **ability** field, which is mandatory and specifies the name of the UIExtensionAbility. The value must be the same as that of **name** in the [extensionAbilities tag](../quick-start/module-configuration-file.md#extensionabilities) of the **module.json5** file.| Object| Yes|
| form | Information about the widget bound to the intent. It contains the **ability** and **formName** fields.<br>- **ability**: mandatory; name of the FormExtensionAbility. The value must be the same as that of **name** in the [extensionAbilities tag](../quick-start/module-configuration-file.md#extensionabilities) of the **module.json5** file.<br>- **formName**: mandatory; widget name. The value must be the same as that of **name** in [Widget Configuration](../form/arkts-ui-widget-configuration.md#widget-configuration).| Object| Yes|
| displayName | Display name of the intent.| String| Yes|
| displayDescription | Display description of the intent.| String| Yes|
| icon | Icon of the intent. It supports both network and local resources.| String| Yes|
| keywords | Search keywords for the intent.| String array| Yes|
| inputParams | Data format of intent parameters. It is used to define the input data format during intent calls.| Object| Yes|
| outputParams | Data format for the results returned by intent calls. It defines how the data should be structured.| Object| Yes|
| entities | Intent entities for data transfer.| Object| Yes|
