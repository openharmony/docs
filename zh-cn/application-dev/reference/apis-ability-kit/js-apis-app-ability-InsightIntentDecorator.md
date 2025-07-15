# @ohos.app.ability.InsightIntentDecorator (意图装饰器定义)

InsightIntentDecorator模块提供了几类意图装饰器。通过装饰类或方法可以将应用的功能定义为意图，并集成到智能问答、智能搜索、智能推荐等AI入口。

- [@InsightIntentLink](#insightintentlink)装饰器：使用该装饰器装饰当前应用的uri链接，可以将该uri链接定义为意图，便于AI入口通过意图快速跳转到当前应用。该装饰器支持的参数参见[LinkIntentDecoratorInfo](#linkintentdecoratorinfo)。
- [@InsightIntentPage](#insightintentpage)装饰器：使用该装饰器装饰当前应用的Page页面，可以将该Page页面定义为意图，便于AI入口通过意图快速跳转到当前Page页面。该装饰器支持的参数参见[PageIntentDecoratorInfo](#pageintentdecoratorinfo)。
- [@InsightIntentFunction](#insightintentfunction)装饰器与[@InsightIntentFunctionMethod](#insightintentfunctionmethod)装饰器：两者必须组合使用。使用[@InsightIntentFunction](#insightintentfunction)装饰器来装饰类，同时使用[@InsightIntentFunctionMethod](#insightintentfunctionmethod)装饰器来装饰类中的静态函数，可以将对应的静态函数定义为意图，便于AI入口能够快速执行此函数。
- [@InsightIntentEntry](#insightintententry)装饰器：使用该装饰器装饰一个继承自[InsightIntentEntryExecutor](./js-apis-app-ability-InsightIntentEntryExecutor.md)的类，并配置拉起Ability时支持的执行模式，便于AI入口拉起绑定的Ability组件时，执行对应的意图操作。该装饰器支持的参数参见[EntryIntentDecoratorInfo](#entryintentdecoratorinfo)。
- [@InsightIntentForm](#insightintentform)装饰器：使用该装饰器装饰[FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md)并配置FormExtensionAbility绑定的卡片名称，通过意图调用可以将对应的卡片添加到AI入口。该装饰器支持的参数参见[FormIntentDecoratorInfo](#formintentdecoratorinfo)。
- [@InsightIntentEntity](#insightintententity)装饰器：使用该装饰器装饰一个继承自[IntentEntity](./js-apis-app-ability-insightIntent.md#intententity20)的类，可将该类定义为意图实体，用于传递意图调用时所需的参数。该装饰器支持的参数参见[IntentEntityDecoratorInfo](#intententitydecoratorinfo)。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 基本概念

意图可以分为标准意图和自定义意图。

系统会根据[IntentDecoratorInfo](#intentdecoratorinfo)中的schema与intentVersion字段，在标准意图列表查询是否存在匹配的意图。

- 如果存在匹配的意图，则对应的意图为标准意图。
- 如果不存在匹配的意图，则对应的意图为自定义意图。

## 导入模块

```ts
import { InsightIntentLink, InsightIntentPage, InsightIntentFunctionMethod, InsightIntentFunction, InsightIntentEntry } from '@kit.AbilityKit';
```

## 约束限制

该模块提供的意图装饰器仅支持在HAP或HSP的.ets文件中使用。

## @InsightIntentLink

使用该装饰器装饰当前应用的uri链接，可以将该uri链接定义为意图，便于AI入口通过定义的意图快速跳转到当前应用。该装饰器支持的参数参见[LinkIntentDecoratorInfo](#linkintentdecoratorinfo)。

> **说明**
>
> uri链接格式需要符合[应用链接说明](../../application-models/app-uri-config.md)说明中的要求。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**示例：**

以自定义意图为例：自定义意图的parameters需要传入标准的JSON Schema数据结构。

```ts
import { InsightIntentLink, LinkParamCategory } from '@kit.AbilityKit';

@InsightIntentLink({
  intentName: 'PlayMusic',
  domain: 'MusicDomain',
  intentVersion: '1.0.1',
  displayName: '播放歌曲',
  displayDescription: '播放音乐意图',
  icon: $r('sys.float.window_shadow_config'),
  llmDescription: '支持传递歌曲名称，播放音乐',
  keywords: ['音乐播放', '播放歌曲', 'PlayMusic'],
  uri: 'https://www.example.com/music/',
  paramMappings: [{
    paramName: 'songName',
    paramMappingName: 'music',
    paramCategory: LinkParamCategory.LINK
  }],
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
    'required': ['songName'],
    'additionalProperties': false
  },
  result: {
    'type': 'object',
    'propertyNames': {
      'enum': [
        'code',
        'result'
      ]
    },
    'required': [
      'code',
      'result'
    ],
    'properties': {
      'code': {
        'description': '执行结果码',
        'type': 'number'
      },
      'result': {}
    }
  }
})
export class ClassForLink {
  private _playback: string = 'intention_test';

  public set playback(value: string) {
    this._playback = value;
  }

  public get playback(): string {
    return this._playback;
  }

  constructor(playback: string) {
    this._playback = playback;
  }

  static Function1(playbackProgress: number, playback?: number): void {
    console.log('Function1' + playbackProgress);
  }
}
```

## IntentDecoratorInfo

意图装饰器的通用属性，用于定义意图的基本信息（包括意图名称、意图版本号）。适用于本模块的所有装饰器。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

> **说明：**
>
> 如果根据schema与intentVersion字段，在标准意图列表存在匹配的标准意图，系统会将intentName、llmDescription、keywords、parameters、result字段均设置为标准意图的相应字段值。

| 名称               | 类型            | 只读         | 可选 | 说明                                                         |
| ------------------ | ----------------| ---------- | ---- | ------------------------------------------------------------ |
| intentName         | string          | 否       | 否   | 表示意图名称。在标准意图的情况下，其取值会使用该字段在标准意图中定义的值。                   |
| domain             | string          | 否       | 否   | 表示意图垂域，用于将意图按垂直领域分类（例如：视频、音乐、游戏），取值范围参见[各垂域的智慧分发特性列表](https://developer.huawei.com/consumer/cn/doc/service/intents-ai-distribution-characteristic-0000001901922213#section2656133582215)中的垂域字段。    |
| intentVersion      | string          | 否       | 否   | 当意图能力演进时，可通过版本号进行区分和管理。                        |
| displayName        | string          | 否       | 否   | 表示在意图框架中显示的意图名称。                                       |
| displayDescription | string         | 否        | 是   | 表示在意图框架中显示的意图描述。                                       |
| schema             | string         | 否        | 是   | 表示标准意图的名称。                  |
| icon               | ResourceStr | 否   | 是   | 表示意图图标。<br/>- 当取值为字符串类型时，表示图标读取网络资源。<br/>- 当取值为[Resource](../../reference/apis-localization-kit/js-apis-resource-manager.md)时，表示图标读取本地资源。 |
| llmDescription     | string      | 否           | 是   | 表示意图的功能，用于大型语言模型理解该意图。                  |
| keywords           | string[]     | 否          | 是   | 表示意图的搜索关键字。                                       |
| parameters         | Record<string, Object>| 否 | 是   | 表示意图参数的数据格式声明，用于意图调用时定义入参的数据格式。取值参见[各垂域意图Schema](https://developer.huawei.com/consumer/cn/doc/service/intents-schema-0000001901962713) |
| result           | Record<string, Object>     | 否          | 是   | 表示意图调用返回结果的数据格式声明，用于定义意图调用返回结果的数据格式。                                       |

## LinkIntentDecoratorInfo

LinkIntentDecoratorInfo继承自[IntentDecoratorInfo](#intentdecoratorinfo)，用于描述[@InsightIntentLink](#insightintentlink)装饰器支持的参数，例如应用间跳转需要的uri信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

| 名称        | 类型              | 只读 | 可选 | 说明                                                         |
| ----------- | -----------------| ------ | ---- | ------------------------------------------------------------ |
| uri                | string          | 否          | 否   | 表示意图的uri信息。                                 |
| paramMappings      | [LinkIntentParamMapping](#linkintentparammapping)[] | 否 | 是   | 意图参数和uri信息的映射。    |

## LinkIntentParamMapping

LinkIntentParamMapping是[@InsightIntentLink](#insightintentlink)装饰器的意图参数和uri信息的映射。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

| 名称             | 类型   | 只读 | 可选 | 说明                                   |
| ---------------- | ------ | ----| ---- | -------------------------------------- |
| paramName        | string | 否 | 否   | 表示意图参数的名称。                       |
| paramMappingName | string | 否 | 是   | 表示意图参数映射名称。                     |
| paramCategory    | [LinkParamCategory](#linkparamcategory) | 否 | 是   | 表示意图参数类别。<br/>若意图参数类别取值为[LINK](#linkparamcategory)，系统获取paramName字段对应的意图参数映射名称，并将该意图参数映射名称拼接到uri链接的末尾(以键值对的形式key=value，key为意图参数映射名称，value为意图参数值)。<br/>若意图参数类别为[WANT](#linkparamcategory)，系统获取paramName字段对应的意图参数映射名称，并将该意图参数映射名称及取值通过[Want](./js-apis-app-ability-want.md)的parameters字段进行传递。  |

## LinkParamCategory

[@InsightIntentLink](#insightintentlink)装饰器的意图参数类别，用于定义意图参数的传递形式。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| LINK  | 'link' | 表示意图参数类别为'link'。意图参数将被拼接到uri链接的末尾，以uri链接的形式传给应用。 |
| WANT  | 'want' | 表示意图参数类别为'want'。意图参数将通过[Want](./js-apis-app-ability-want.md)的parameters字段传给应用。 |

## @InsightIntentPage

使用该装饰器装饰当前应用的页面，可以将页面定义为意图，便于AI入口通过意图快速跳转到指定页面。该装饰器支持的参数参见[PageIntentDecoratorInfo](#pageintentdecoratorinfo)。

> **说明**
>
> 该装饰器仅支持装饰struct页面。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**示例：**

```ts
import { InsightIntentPage } from '@kit.AbilityKit';

@Entry
@Component
@InsightIntentPage({
  intentName: 'SearchMusic',
  domain: 'MusicDomain',
  intentVersion: '1.0.1',
  displayName: '搜索歌曲',
  displayDescription: '搜索歌曲意图',
  schema: 'SearchMusic',
  uiAbility: 'Entry',
  pagePath: './ets/pages/Index',
  navigationId: '1',
  navDestinationName: 'PageOne',
})
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

## PageIntentDecoratorInfo

PageIntentDecoratorInfo继承自[IntentDecoratorInfo](#intentdecoratorinfo)，用于描述[@InsightIntentPage](#insightintentpage)装饰器支持的参数，例如目标页面的[NavDestination](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10)名称。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

| 名称               | 类型         | 只读       | 可选 | 说明                                                         |
| ------------------ | -------------| --------- | ---- | ------------------------------------------------------------ |
| uiAbility          | string       | 否           | 是   | 表示与意图绑定的UIAbility名称。                                  |
| pagePath           | string        | 否          | 否   | 表示与意图绑定的页面路径，该页面需要是一个实际存在的文件。 |
| navigationId       | string        | 否        | 是   | 表示与意图绑定的[Navigation组件](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#属性)的id属性。 |
| navDestinationName | string         | 否       | 是   | 表示与意图绑定[NavDestination组件](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10)的名称。 |

## @InsightIntentFunction

该装饰器与[@InsightIntentFunctionMethod](#insightintentfunctionmethod)装饰器必须组合使用。

使用该装饰器来装饰类，同时使用[@InsightIntentFunctionMethod](#insightintentfunctionmethod)装饰器来装饰类中的静态函数，可以将对应的静态函数定义为意图，便于AI入口能够快速执行此函数。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

## InsightIntentFunctionMethod

该装饰器与[@InsightIntentFunction](#insightintentfunction)装饰器必须组合使用。

使用该装饰器来装饰类中的静态函数，同时使用[@InsightIntentFunction](#insightintentfunction)装饰器来装饰静态函数所属的类，可以将对应的静态函数定义为意图，便于AI入口能够快速执行此函数。

> **说明**
>
> 静态方法所在的类需要通过export导出。
>
> 函数的参数名称、参数类型需要与意图定义的参数名称、参数类型保持一致。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**示例：**

```ts
import { InsightIntentFunction, InsightIntentFunctionMethod } from '@kit.AbilityKit';

@InsightIntentFunction()
export class ClassForFuncDemo {
  @InsightIntentFunctionMethod({
  intentName: 'GetWeather',
  domain: 'LifeDomain',
  intentVersion: '1.0.1',
  displayName: '查询天气',
  displayDescription: '显示天气信息',
  icon: $r('sys.plural.selecttitlebar_accessibility_message_desc_new'),
  llmDescription: 'Get weather of an location',
  parameters: {
    'schema': 'http://json-schema.org/draft-07/schema#',
    'type': 'object',
    'title': 'Weather Schema',
    'description': 'A schema for get weather of an location',
    'properties': {
      'location': {
        'type': 'string',
        'description': 'The city and state, e.g. Hangzhou',
        'minLength': 1
      }
    },
    'required': ['location'],
    'additionalProperties': false
  }
})
  static getWeather(location: string): string {
    console.log('location' + location);
    return 'The current temperature in Hangzhou is 24℃';
  }
}
```

## FunctionIntentDecoratorInfo

[@InsightIntentFunctionMethod](#insightintentfunctionmethod)装饰器的参数类型，当前全部属性均继承自[IntentDecoratorInfo](#intentdecoratorinfo)。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

## @InsightIntentEntry

使用该装饰器装饰一个继承自[InsightIntentEntryExecutor](./js-apis-app-ability-InsightIntentEntryExecutor.md)的类，并配置拉起Ability时支持的执行模式，便于AI入口拉起绑定的Ability组件时，执行对应的意图操作。该装饰器支持的参数参见[EntryIntentDecoratorInfo](#entryintentdecoratorinfo)。

> **说明**
>
> - 如果使用该装饰器接入标注意图，必须实现标准意图Json Schema中定义的所有必选参数且类型匹配。
> - 如果创建自定义意图，必须实现parameters字段中定义的所有必选参数且类型匹配。
> - 被装饰的类需要使用export default导出。类的属性仅支持基础类型或意图实体，返回值仅支持意图实体。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**示例：**

```ts
import { insightIntent, InsightIntentEntry, InsightIntentEntryExecutor } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const LOG_TAG: string = 'testTag-EntryIntent';

// 使用@InsightIntentEntry装饰器定义意图
@InsightIntentEntry({
  intentName: 'PlayMusic',
  domain: 'MusicDomain',
  intentVersion: '1.0.1',
  displayName: '播放歌曲',
  displayDescription: '播放音乐意图',
  icon: $r('app.media.app_icon'),
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
    // 根据executeMode参数的不同情况，提供不同拉起PlayMusicPage页面的方式。
    if (this.executeMode == insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND) {
      this.windowStage?.loadContent('pages/PlayMusicPage', storage);
    } else if (this.executeMode == insightIntent.ExecuteMode.UI_EXTENSION_ABILITY) {
      this.uiExtensionSession?.loadContent('pages/PlayMusicPage', storage);
    }
    // 定义意图的执行结果
    let result: insightIntent.IntentResult<string> = {
      code: 123,
      result: 'result'
    }
    hilog.info(0x0000, LOG_TAG, 'PlayMusicDemo return %{public}s', JSON.stringify(result));
    // 以Promise的方式返回意图执行结果
    return Promise.reject(result);
  }
}
```

## EntryIntentDecoratorInfo

EntryIntentDecoratorInfo继承自[IntentDecoratorInfo](#intentdecoratorinfo)，用于描述[@InsightIntentEntry](#insightintententry)装饰器支持的参数。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

| 名称               | 类型         | 只读       | 可选 | 说明                                                         |
| ------------------ | -------------| --------- | ---- | ------------------------------------------------------------ |
| abilityName        | string       | 否        | 否   | 表示与意图绑定的Ability名称。                                  |
| executeMode        | [insightIntent.ExecuteMode](./js-apis-app-ability-insightIntent.md#executemode)[]| 否        | 否   | 表示意图调用执行模式。即拉起绑定的Ability时支持的执行模式。 |

## @InsightIntentForm

使用该装饰器装饰[FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md)并配置FormExtensionAbility绑定的卡片名称，通过意图调用可以将对应的卡片添加到AI入口。该装饰器支持的参数参见[FormIntentDecoratorInfo](#formintentdecoratorinfo)。

> **说明**
>
> 卡片名称定义的要求参见[卡片配置](../../form/arkts-ui-widget-configuration.md#卡片配置)。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**示例：**

```ts
import { formBindingData, FormExtensionAbility, formInfo } from '@kit.FormKit';
import { insightIntent, Want, InsightIntentForm } from '@kit.AbilityKit';

// 使用@InsightIntentForm装饰器将该FormExtensionAbility名为widget的卡片定义为意图
@InsightIntentForm({
  intentName: 'PlayMusic78',
  domain: 'MusicDomain',
  intentVersion: '1.0.1',
  displayName: '播放歌曲',
  displayDescription: '播放音乐意图',
  icon: $r('app.media.app_icon'),
  llmDescription: '支持传递歌曲名称，播放音乐',
  keywords: ['音乐播放', '播放歌曲', 'PlayMusic'],
  parameters: {
    '$schema': 'http://json-schema.org/draft-07/schema#',
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
            'type': 'object',
            'description': 'The artist\' city of origin'
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
  },
  formName: 'widget'
})
export default class EntryFormAbility extends FormExtensionAbility {
  songName: string = '';

  onAddForm(want: Want) {
    // 该方法被调用时，将返回FormBindingData对象
    let formData = '';
    return formBindingData.createFormBindingData(formData);
  }
}
```

## FormIntentDecoratorInfo

FormIntentDecoratorInfo继承自[IntentDecoratorInfo](#intentdecoratorinfo)，用于描述[@InsightIntentForm](#insightintentform)装饰器支持的参数。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

| 名称               | 类型         | 只读       | 可选 | 说明                                                         |
| ------------------ | -------------| --------- | ---- | ------------------------------------------------------------ |
| formName        | string       | 否        | 否   | 表示FormExtensionAbility绑定的卡片名称。                                  |

## @InsightIntentEntity

使用该装饰器装饰一个继承自[IntentEntity](./js-apis-app-ability-insightIntent.md#intententity20)的类，可将该类定义为意图实体，用于传递意图调用时所需的参数。该装饰器支持的参数参见[IntentEntityDecoratorInfo](#intententitydecoratorinfo)。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**示例：**

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
    'required': ['name']
  }
})
export class ArtistClassDef implements insightIntent.IntentEntity {
  entityId: string = 'id';
  name: string = '';
}
```

## IntentEntityDecoratorInfo

用于描述[@InsightIntentEntity](#insightintententity)装饰器支持的参数。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**属性：**

| 名称               | 类型         | 只读       | 可选 | 说明                                                         |
| ------------------ | -------------| --------- | ---- | ------------------------------------------------------------ |
| entityCategory        | string       | 否        | 否   | 表示意图实体类别。可以基于意图实体类别对意图实体进行归类                   |
| parameters        | Record<string, Object> | 否        | 是   | 表示意图实体的数据格式声明。用于定义意图实体的数据格式。 |
