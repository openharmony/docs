# 使用配置文件开发意图
## 简介
从API version 11及以上版本，支持通过配置文件开发意图。主要包含两个环节：

1. 通过[insight_intent.json配置文件](#insight_intentjson配置文件说明)定义意图，声明意图执行器的代码路径、绑定的Ability组件等意图信息。

2. 通过[InsightIntentExecutor](../reference/apis-ability-kit/js-apis-app-ability-insightIntentExecutor.md#insightintentexecutor)实现意图执行逻辑。

不同Ability组件类型需要配置的字段与需要实现的意图执行器，如下所示：

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

## insight_intent.json配置文件说明
意图配置文件insight_intent.json位于工程的"resources/base/profile"目录，用于声明意图配置信息。其中，"insightIntents"数组包含通过配置文件开发的所有意图配置信息，数组中的属性如下：

| 属性名称 | 含义 | 数据类型 | 是否可缺省 |
| --- | --- | --- | --- |
| intentName | 表示意图名称，是意图的唯一标识。取值为首字母大写、包含字母和数字的字符串。 | 字符串 | 否 |
| domain | 表示意图垂域名称，用于将意图按具体领域分类（例如：视频、音乐、游戏）。<!--RP1--><!--RP1End--> | 字符串 | 否 |
| intentVersion | 表示意图版本号。当意图能力演进时，可通过版本号进行区分和管理。支持用点分隔开的三段数据序列，例如"1.0.1"。 | 字符串 | 否 |
| srcEntry | 表示意图执行文件相对路径。取值为长度不超过127字节的字符串。 | 字符串 | 否 |
| uiAbility | 表示意图绑定的UIAbility组件信息。包含"ability"字段和"executeMode"字段。<br>- ability：必选字段，表示UIAbility组件名称，取值与module.json5配置文件[abilities标签](../quick-start/module-configuration-file.md#abilities标签)的"name"字段保持一致。<br>-  executeMode：必选字段，表示执行模式，取值范围是"foreground"和"background"。<br> &nbsp; &nbsp; - 取值为"foreground"，表示支持在UIAbility组件前台启动时执行意图逻辑。<br>&nbsp; &nbsp; -  取值为"background"，表示支持在UIAbility组件后台启动时执行意图逻辑。  | 对象 | 是 |
| <!--DelRow--> serviceExtension | 表示意图绑定的ServiceExtensionAbility组件信息。仅包含"ability"必选字段，表示ServiceExtensionAbility组件名称，取值与module.json5配置文件[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)的"name"字段保持一致。 | 对象 | 是 |
| uiExtension | 表示意图绑定的UIExtensionAbility组件信息。仅包含"ability"必选字段，表示UIExtensionAbility组件名称，取值与module.json5配置文件[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)的"name"字段保持一致。 | 对象 | 是 |
| form | 表示意图绑定的卡片信息。包含"ability"字段和"formName"字段。<br>- ability：必选字段，表示FormExtensionAbility组件名称，取值与module.json5配置文件[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签) 的"name"字段保持一致。<br>- formName：必选字段，表示卡片名称，取值与[卡片配置](../form/arkts-ui-widget-configuration.md#卡片配置)的"name"字段保持一致。 | 对象 | 是 |
| displayName | 表示意图显示名称。 | 字符串 | 是 |
| displayDescription | 表示意图显示描述。 | 字符串 | 是 |
| icon | 表示意图图标。支持网络资源和本地资源。 | 字符串 | 是 |
| keywords | 表示意图的搜索关键字。 | 字符串数组 | 是 |
| inputParams | 表示意图参数的数据格式声明，用于意图调用时定义入参的数据格式。 | 对象 | 是 |
| outputParams | 表示意图调用返回结果的数据格式声明，用于定义意图调用返回结果的数据格式。 | 对象 | 是 |
| entities | 表示意图实体定义，用于数据传递。 | 对象 | 是 |
