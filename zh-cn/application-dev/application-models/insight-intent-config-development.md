# 使用配置文件开发意图
## 使用场景
从API version 11及以上版本，支持通过配置文件开发意图。意图需要绑定到Ability组件，支持的组件类型、意图配置和意图执行器介绍如下。

| 组件类型 | 意图配置 | 意图执行器 |
| --- | --- | --- |
| UIAbility | 需要在`insight_intent.json`文件中配置"uiAbility"字段。 | 当"executeMode"字段为"foreground"时，实现`onExecuteInUIAbilityForegroundMode`，通过startAbility启动意图绑定的UIAbility组件。<br>当"executeMode"字段为"background"时，实现`onExecuteInUIAbilityBackgroundMode`，通过[Call调用](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#后台通信能力)启动意图绑定的UIAbility组件。 |
| UIExtensionAbility | 需要在`insight_intent.json`文件中配置"uiExtension"字段。 | 实现`onExecuteInUIExtensionAbility`。 |
|<!--DelRow--> ServiceExtensionAbility | 需要在`insight_intent.json`文件中配置"serviceExtension"字段。 | 实现 `onExecuteInServiceExtensionAbility`。 |
| 卡片(FormExtensionAbility) | 需要在`insight_intent.json`文件中配置"form"字段。 | 无需单独执行器。 |

## 接口说明
意图执行器实现需要继承[InsightIntentExecutor](../reference/apis-ability-kit/js-apis-app-ability-insightIntentExecutor.md#insightintentexecutor)，实现[onExecuteInUIAbilityForegroundMode](../reference/apis-ability-kit/js-apis-app-ability-insightIntentExecutor.md#onexecuteinuiabilityforegroundmode)等方法。开发者响应意图执行通过onExecuteInUIAbilityForegroundMode等接口实现，在不同的意图执行模式下，接口的触发时机也不同。针对不同意图执行模式的意图回调执行时机见各个回调的API说明。

## 开发步骤
### 意图绑定UIAbility组件

通过DevEco Studio工具可视化创建意图，操作及开发步骤如下。
1. 选中模块或模块下的文件，右键单击`New` > `Insight Intent`，进入意图框架配置界面。
2. 选择意图垂域、意图框架入口代码文件名以及意图配置。意图配置包含意图名称和绑定的Ability组件。
3. 点击`Finish`，完成意图框架创建。
    此时将在module目录 > src > main > resource > base > profile中，生成insight_intent.json文件，可在该文件查看当前意图框架配置的相关信息。

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

4. 在module目录 > src > main > ets > insightintents目录下生成入口代码文件。开发者在意图执行函数中实现意图的功能代码。

    ```ts
    // 本示例对应意图配置中的"srcEntry"字段对应的文件
    import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';

    export default class PlayMusicExecutor extends InsightIntentExecutor {
      // 由于意图配置中"executeMode"配置了"foreground"前台模式执行，故需要实现该接口
      async onExecuteInUIAbilityForegroundMode(intentName: string, params: Record<string, Object>,
        windowStage: window.WindowStage): Promise<insightIntent.ExecuteResult> {
        // 实现播放逻辑
        const result: insightIntent.ExecuteResult = {
          code: 0
        };
        return Promise.resolve(result);
      }

      // 由于意图配置中"executeMode"配置了"background"后台模式执行，故需要实现该接口
      async onExecuteInUIAbilityBackgroundMode(intentName: string,
        params: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
        // 后台控制逻辑
        const result: insightIntent.ExecuteResult = {
          code: 0
        };
        return Promise.resolve(result);
      }
    }
    ```

> **说明：**
>
> 配置文件范式仅提供基础执行能力，参数格式需开发者与系统入口协商。

开发者也可以选择按规范手动创建意图配置文件和意图执行器。需要关注如下注意点：
- 必须声明绑定的Ability组件和支持的意图执行模式。
- 配置文件必须命名为"insight_intent.json"。
- 配置文件存放路径为"resources/base/profile"。
- 配置文件关键字段遵循相应的约束。

### 意图绑定UIExtensionAbility组件

参考[意图绑定uiability组件](#意图绑定uiability组件)完成工程创建。

意图配置示例：

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

意图执行器实现：

```ts
import { InsightIntentExecutor, insightIntent, UIExtensionContentSession } from '@kit.AbilityKit';

export default class IntentExecutorImpl extends InsightIntentExecutor {
  // 由于意图配置了uiExtension，故需要实现该接口
  async onExecuteInUIExtensionAbility(name: string, param: Record<string, Object>,
    pageLoader: UIExtensionContentSession): Promise<insightIntent.ExecuteResult> {
    const result: insightIntent.ExecuteResult = {
      code: 0
    };
    return Promise.resolve(result);
  }
}
```

系统入口通过UIExtensionComponent组件执行该意图。

<!--Del-->
### 意图绑定ServiceExtensionAbility组件

参考[意图绑定uiability组件](#意图绑定uiability组件)完成工程创建。

意图配置示例：

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

意图执行器实现：

```ts
import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';

export default class IntentExecutorImpl extends InsightIntentExecutor {
  // 由于意图配置了serviceExtension，故需要实现该接口
  async onExecuteInServiceExtensionAbility(name: string,
    param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
    const result: insightIntent.ExecuteResult = {
      code: 0
    };
    return Promise.resolve(result);
  }
}
```

系统入口通过[startServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md#serviceextensioncontextstartserviceextensionability)方式执行该意图。
<!--DelEnd-->

### 意图绑定卡片

参考[意图绑定uiability组件](#意图绑定uiability组件)完成工程创建。

意图配置示例：

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

系统入口通过FormComponent组件展示卡片内容。
