# 使用装饰器开发意图

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @zhangyafei-echo-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## 使用场景
从 API version 20开始，支持通过装饰器开发意图，支持将现有功能通过装饰器快速集成至系统入口。典型场景介绍如下。

| 意图调用场景 | 常见意图举例 | 意图开发方式 |
| --- | --- | --- |
| 拉起应用 | - 播放音乐。<br>- 打开购物软件直达商品详情页。 |  - 通过[@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry)创建新的意图逻辑，绑定UIAbility组件或UIExtensionAbility组件。<br>- 通过[@InsightIntentLink](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)将uri链接转换为意图。<br>- 通过[@InsightIntentPage](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentpage) 将页面路由转换为意图。 |
| 查询或更新信息 | - 查询天气。<br>- 修改应用配置或更新。 | - 通过[@InsightIntentFunctionMethod](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod) 将函数调用转换为系统意图。<br>- 通过[@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry)创建新的意图逻辑，绑定UIAbility组件的后台执行模式或ServiceExtensionAbility组件。 |
| 添加服务卡片 | - 添加天气卡片。 | - 通过[@InsightIntentForm](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentform)开发意图。 |

## 运行机制

| 功能 | 意图开发 | 意图执行|
| --- | --- | --- |
| 使用[@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry)开发意图 | 1. 开发者新增意图执行文件，若该执行文件未被其他文件导入，需要通过`insight_intent.json`文件的"insightIntentsSrcEntry"字段配置意图执行文件路径，使其参与编译。<br> 2. 通过装饰器定义意图需要绑定Ability组件、定义意图执行模式。 | 系统入口匹配意图，根据意图执行模式触发Ability组件的启动和意图执行。 |
| 使用[@InsightIntentLink](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)开发意图 | 开发者定义Link跳转意图，支持已有的uri链接和新增uri链接。 | 系统入口匹配意图，传递uri链接，通过[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#openlink12)触发意图执行，意图执行时的入参处理见[LinkIntentParamMapping](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#linkintentparammapping)的paramCategory说明。 |
| 使用[@InsightIntentPage](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentpage)开发意图 | 开发者定义页面跳转意图，配置意图对应的UIAbility组件、[页面路由](../ui/arkts-routing.md)的路径和[Navigation](../ui/arkts-navigation-navigation.md)路径。 | 1. 系统入口通过startAbility启动意图绑定的UIAbility组件。若意图未绑定UIAbility组件，则启动意图所在module的[mainElement](../quick-start/module-configuration-file.md#配置文件标签)对应的UIAbility组件。<br>2. 意图执行时，若应用未启动，在UIAbility的首页加载后跳转到意图对应的页面；若应用已启动，由当前页面跳转到意图对应的页面。<br>3. 意图执行时，参数会被传递给目标页面。<br>4. "navigationId"字段或"navDestinationName"字段匹配失败时，退化为"pagePath"字段对应的页面跳转。 |
| 使用[@InsightIntentFunctionMethod](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod)开发意图 | 开发者为静态方法定义意图，静态方法可以是已有方法或新增方法。 | 系统入口通过[Call调用](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#后台通信能力)启动意图所在module的[mainElement](../quick-start/module-configuration-file.md#配置文件标签)对应的UIAbility组件。|
| 使用[@InsightIntentForm](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintentform)开发意图 | 开发者定义卡片意图，卡片可以是已有卡片或新增卡片。| 系统入口通过FormComponent组件创建意图卡片。 |

## 开发步骤

本章节以通过@InsightIntentEntry开发标准意图和自定义意图举例，其他装饰器开发标准意图和自定义意图与@InsightIntentEntry相似，可以结合API参考开发其他类型的意图。

### 通过意图装饰器开发标准意图

以通过@InsightIntentEntry装饰器开发[查看快递](./insight-intent-access-specifications.md#查看快递)标准意图举例。

1. 在insight_intent.json配置文件中的"insightIntentsSrcEntry"字段声明意图执行文件。
    ```json
    {
      "insightIntentsSrcEntry": [
        {
          "srcEntry": "./ets/insightintents/ViewLogisticsImpl.ets"
        }
      ]
    }
    ```

2. 实现意图执行器。
    开发标准意图无需开发者自行定义意图的大语言模型描述、意图参数定义和意图执行结果定义，根据"schema"字段和"intentVersion"字段匹配[附录：标准意图接入规范](insight-intent-access-specifications.md)中的标准意图。意图执行器需要从InsightIntentEntryExector\<T>类继承，实现onExecute()方法。
    ```ts
    import { InsightIntentEntryExecutor, insightIntent, InsightIntentEntry } from '@kit.AbilityKit';

    class ViewLogisticsResultDef {
      msg?: string = '';
    }

    @InsightIntentEntry({
      intentName: 'ViewLogistics',
      domain: 'LocalDomain',
      intentVersion: '1.0.1',
      displayName: '查询快递',
      displayDescription: '根据快递单号查询快递信息',
      schema: 'ViewLogistics',
      icon: $r('app.media.viewLogistics'), // $r表示本地图标，需要在资源目录中定义
      abilityName: 'EntryAbility',
      executeMode: [insightIntent.ExecuteMode.UI_ABILITY_BACKGROUND],
    })
    export default class ViewLogisticsImpl extends InsightIntentEntryExecutor<ViewLogisticsResultDef> {
      trackingNo?: string = '';
      entityId?: string = '';

      onExecute(): Promise<insightIntent.IntentResult<ViewLogisticsResultDef>> {
        // 执行查询快递逻辑
        let result: insightIntent.IntentResult<ViewLogisticsResultDef> = {
          code: 0,
          result: {
            msg: 'the logistics is being delivered'
          }
        }
        return Promise.resolve(result);
      }
    }
    ```

意图执行过程：
1. 系统入口响应用户“查询单号为12345的快递”的请求，匹配到该应用的"ViewLogistics"意图，通过意图框架触发该应用的"ViewLogistics"意图执行。
2. 由于意图绑定了"EntryAbility"组件、配置了`insightIntent.ExecuteMode.UI_ABILITY_BACKGROUND`执行模式，在意图执行过程中，"ViewLogistics"意图绑定的"EntryAbility"组件会通过[Call调用](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#后台通信能力)启动，意图执行过程中，ViewLogisticsImpl类的属性"trackingNo"会被赋值，进而执行onExecute()方法，将意图执行结果通过意图框架返回给系统入口。
3. 系统入口将意图执行结果转换为自然语言呈现给用户。

### 通过意图装饰器开发自定义意图

以开发“播放音乐”自定义意图举例，需要定义意图的大语言模型描述、意图搜索关键字、意图参数定义和意图执行结果定义。

1. 在insight_intent.json配置文件中的"insightIntentsSrcEntry"字段声明意图执行文件。

    ```json
    {
      "insightIntentsSrcEntry": [
        {
          "srcEntry": "./ets/insightintents/PlayMusicImpl.ets"
        }
      ]
    }
    ```

2. 实现意图执行器。
    开发自定义意图需要开发者定义意图的大语言模型描述、意图搜索关键字、意图参数定义和意图执行结果定义。意图执行器需要从InsightIntentEntryExector\<T>类继承，实现onExecute()方法。

    ```ts
    // `insight_intent.json`文件的"insightIntentsSrcEntry"字段的实现
    import { InsightIntentEntryExecutor, insightIntent, InsightIntentEntity, InsightIntentEntry } from '@kit.AbilityKit';

    // 意图执行返回值数据格式定义
    class PlayMusicResultDef {
      msg?: string = '';
    }

    // 意图定义
    @InsightIntentEntry({
      intentName: 'PlayMusic',
      domain: 'MusicDomain',
      intentVersion: '1.0.1',
      displayName: '播放歌曲',
      displayDescription: '播放音乐意图',
      icon: $r('app.media.playMusic'), // $r表示本地图标，需要在资源目录中定义
      llmDescription: '支持传递歌曲名称，播放音乐',
      keywords: ['音乐播放', '播放歌曲', 'PlayMusic'],
      abilityName: 'EntryAbility',
      executeMode: [insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND],
      parameters: {
        "type": "object",
        "description": "A schema for describing songs and their artists",
        "properties": {
          "songName": {
            "type": "string",
            "description": "The name of the song",
            "minLength": 1
          },
          "singer": {
            "type": "string",
            "description": "The name of the singer",
            "minLength": 1
          }
        },
        "required": ["songName"]
      }
    })
    export class PlayMusicImpl extends InsightIntentEntryExecutor<PlayMusicResultDef> {
      songName: string = '';
      singer?: string = '';

      onExecute(): Promise<insightIntent.IntentResult<PlayMusicResultDef>> {
        // 执行音乐播放逻辑
        let result: insightIntent.IntentResult<PlayMusicResultDef> = {
          code: 123,
          result: {
            msg: 'play music succeed'
          }
        }
        return Promise.resolve(result);
      }
    }
    ```

意图执行过程：
1. 系统入口响应用户“播放歌手A的歌曲B”的请求，匹配到该应用的"PlayMusic"意图，通过意图框架触发该应用的"PlayMusic"意图执行。
2. 意图绑定了"EntryAbility"组件、配置了`insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND`执行模式，在意图执行过程中，"PlayMusic"意图绑定的"EntryAbility"组件会通过startAbility启动，PlayMusicImpl类的属性"songName"和"singer"会被赋值，进而执行onExecute()方法，将意图执行结果通过意图框架返回给系统入口。
3. 系统入口将意图执行结果转换为自然语言呈现给用户。

### （可选）通过开发意图实体传递复杂参数

由系统入口传递给应用的数据默认为基础类型。如果需要复杂数据（例如，播放音乐时需要传入的歌手信息包括歌手姓名、国籍等多个字段），需要采用对象类型，并使用[@InsightIntentEntity](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententity)装饰器装饰。被装饰的对象称为意图实体。

以播放音乐为例，用户告诉小艺希望播放的音乐名称与歌手信息，小艺根据音乐名称和歌手信息拉起对应音乐界面，播放该音乐。

为了实现该场景，开发者可以将歌手信息定义为意图实体，并开发意图实体。具体步骤如下：

1. 定义意图实体。

    开发者将歌手信息（包括名称、国家、城市）定义为类，并使用@InsightIntentEntity装饰器将该类定义为意图实体。装饰器的parameters属性列出了类的数据成员、数据格式及每个成员的必选性。

    ```ts
    import { insightIntent, InsightIntentEntity } from '@kit.AbilityKit';

    @InsightIntentEntity({
      entityCategory: 'artist entity category',
      parameters: {
        '$id': '/schemas/ArtistClassDef',
        'type': 'object',
        'description': 'Information about the artist',
        'properties': {
          'country': {
            'type': 'string',
            'description': 'The artist\'s country of origin',
            'default': 'zh'
          },
          'city': {
            'type': 'string',
            'description': 'The artist\'s city of origin'
          },
          'name': {
            'type': 'string',
            'description': 'The name of the artist',
            'minLength': 1
          }
        },
        // name为必选参数
        'required': ['name']
      }
    })
    export class ArtistClassDef implements insightIntent.IntentEntity {
      entityId: string = '0x11';
      country?: string = '';
      city?: string = '';
      name: string = '';
    }
    ```

2. 使用意图实体。添加[@InsightIntentEntry](../reference/apis-ability-kit/js-apis-app-ability-InsightIntentDecorator.md#insightintententry)装饰器的意图使用音乐名称和歌手信息（ArtistClassDef意图实体）作为播放音乐的入参。

    ```ts
    import { insightIntent, InsightIntentEntry, InsightIntentEntryExecutor, InsightIntentEntity } from '@kit.AbilityKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';

    const LOG_TAG: string = 'testTag-EntryIntent';

    @InsightIntentEntity({
      entityCategory: 'artist entity category',
      // @InsightIntentEntry装饰器中parameters中已描述ArtistClassDef意图实体信息，此处parameters可不写
    })
    export class ArtistClassDef implements insightIntent.IntentEntity {
      entityId: string = '0x11';
      country?: string = '';
      city?: string = '';
      name: string = '';
    }

    // 使用@InsightIntentEntry装饰器定义意图
    @InsightIntentEntry({
      intentName: 'PlayMusic',
      domain: 'MusicDomain',
      intentVersion: '1.0.1',
      displayName: '播放歌曲',
      displayDescription: '播放音乐意图',
      icon: $r('app.media.app_icon'), // $r表示本地图标，需要在资源目录中定义
      llmDescription: '支持传递歌曲名称，播放音乐',
      keywords: ['音乐播放', '播放歌曲', 'PlayMusic'],
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
          },
          'artist': {
            'type': 'object',
            'description': 'Information about the artist',
            'properties': {
              'country': {
                'type': 'string',
                'description': 'The artist\'s country of origin',
                'default': 'zh'
              },
              'city': {
                'type': 'string',
                'description': 'The artist\'s city of origin'
              },
              'name': {
                'type': 'string',
                'description': 'The name of the artist',
                'minLength': 1
              }
            },
            'required': ['name']
          }
        },
        'required': ['songName']
      }
    })
    export default class PlayMusicDemo extends InsightIntentEntryExecutor<string> {
      songName: string = '';
      // 使用意图实体
      artist?: ArtistClassDef;

      onExecute(): Promise<insightIntent.IntentResult<string>> {
        hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo executeMode %{public}s', JSON.stringify(this.executeMode));
        hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo artist %{public}s', JSON.stringify(this.artist));
        let storage = new LocalStorage();
        storage.setOrCreate('songName', this.songName);
        storage.setOrCreate('artist', this.artist);
        // 根据 `executeMode` 参数的不同情况，提供不同的方式拉起 `PlayMusicPage` 页面。
        if (this.executeMode == insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND) {
          this.windowStage?.loadContent('pages/PlayMusicPage', storage);
        } else if (this.executeMode == insightIntent.ExecuteMode.UI_EXTENSION_ABILITY) {
          this.uiExtensionSession?.loadContent('pages/PlayMusicPage', storage);
        }
        // 定义意图的执行结果
        let result: insightIntent.IntentResult<string> = {
          code: 123,
          result: 'execute success'
        }
        hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo return %{public}s', JSON.stringify(result));
        return Promise.resolve(result);
      }
    }
    ```
