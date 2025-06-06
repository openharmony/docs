# @ohos.app.ability.InsightIntentDecorator (InsightIntent Decorator Definition)

The InsightIntentDecorator module provides various InsightIntent decorators that allow you to define application functionalities as InsightIntents and integrate them into AI-driven features like intelligent Q&A, search, and recommendations.

- [@InsightIntentLink](#insightintentlink): decorates a URI in your application as an InsightIntent, enabling AI systems to quickly jump to your application via this InsightIntent. For details on the parameters supported by this decorator, see [LinkIntentDecoratorInfo](#functionintentdecoratorinfo).
- [@InsightIntentPage](#insightintentpage): decorates a page in your application as an InsightIntent, enabling AI systems to swiftly navigate to that page. For details on the parameters supported by this decorator, see [PageIntentDecoratorInfo](#pageintentdecoratorinfo).
- [@InsightIntentFunction](#insightintentfunction) and [@InsightIntentFunctionMethod](#insightintentfunctionmethod): The two decorators must be used together. [@InsightIntentFunction](#insightintentfunction) is used to decorate a class, and [@InsightIntentFunctionMethod](#insightintentfunctionmethod) is used to decorate a static function in that class. This setup defines the static function as an InsightIntent, enabling AI systems to execute it rapidly.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { InsightIntentLink, InsightIntentPage, InsightIntentFunctionMethod, InsightIntentFunction } from '@kit.AbilityKit';
```

## Constraints
The InsightIntent decorators provided by this module can be used only in.ets files.

## InsightIntentLink

Decorates a URI in the application as an InsightIntent, enabling AI systems to quickly jump to the application via this InsightIntent. For details on the parameters supported by this decorator, see [LinkIntentDecoratorInfo](#functionintentdecoratorinfo).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Example**

Custom InsightIntent: The parameters of a custom InsightIntent must be passed in as a standard JSON schema data structure.

```ts
import { InsightIntentLink } from '@kit.AbilityKit';

@InsightIntentLink({
  intentName: 'PlayMusic',
  domain: 'MusicDomain',
  intentVersion: '1.0.1',
  displayName: 'Play Music',
  displayDescription: 'InsightIntent to play music',
  icon: $r("sys.float.window_shadow_config"),
  llmDescription: 'Supports passing song names to play music',
  keywords: ['music playback', 'play music', 'PlayMusic'],
  uri: 'https://www.example.com/music/',
  parameters: {
    "schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "title": "Song Schema",
    "description": "A schema for describing songs and their artists",
    "properties": {
      "songName": {
        "type": "string",
        "description": "The name of the song",
        "minLength": 1
      }
    },
    "required": ["songName"],
    "additionalProperties": false
  }
})
export class ClassForFunc {
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
  static Function1(playbackProgress:number, playback?: number): void {
    console.log('Function1'+ playbackProgress);
  }
}
```

## IntentDecoratorInfo

Common properties for InsightIntent decorators, used to define basic information about an InsightIntent (including the InsightIntent name and version number). It applies to all decorators provided by this module.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Properties**

| Name              | Type           | Read-Only        | Optional| Description                                                        |
| ------------------ | ----------------| ---------- | ---- | ------------------------------------------------------------ |
| intentName         | string          | No      | Yes  | InsightIntent name.                                              |
| domain             | string          | No      | Yes  | Vertical domain of the InsightIntent. It is used to categorize InsightIntents by vertical fields (for example, video, music, and games). For details about the value range, see the vertical domain fields in [smart distribution features in different vertical domains](https://developer.huawei.com/consumer/en/doc/service/intents-ai-distribution-characteristic-0000001901922213#section2656133582215).   |
| intentVersion      | string          | No      | Yes  | Version number of the InsightIntent. It is used to distinguish and manage InsightIntents when their capabilities evolve.                       |
| displayName        | string          | No      | Yes  | Name of the InsightIntent displayed in the InsightIntent framework.                                      |
| displayDescription | string         | No       | No  | Description of the InsightIntent displayed in the InsightIntent framework.                                      |
| schema             | string         | No       | No  | Standard InsightIntent name. If an InsightIntent in the standard InsightIntent list matches both the **schema** and **intentVersion** fields, it is processed as a standard InsightIntent.                 |
| icon               | ResourceStr | No  | No  | Icon of the InsightIntent.<br>- If the value is a string, the icon is read from a network resource.<br>- If the value is a [resource](../../reference/apis-localization-kit/js-apis-resource-manager.md), the icon is read from a local resource.|
| llmDescription     | string      | No          | No  | Function of an InsightIntent, which helps large language models understand the InsightIntent.                                |
| keywords           | string[]     | No         | No  | Search keywords for the InsightIntent.                                      |
| parameters         | Record<string, Object>| No| No  | Data format of InsightIntent parameters, which is used to define the input data format during InsightIntent calls.|

## LinkIntentDecoratorInfo

**LinkIntentDecoratorInfo** inherits from [IntentDecoratorInfo](#intentdecoratorinfo) and describes the parameters supported by the [@InsightIntentLink](#insightintentlink) decorator, such as the URI information required for application redirection.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Properties**

| Name       | Type             | Read-Only| Optional| Description                                                        |
| ----------- | -----------------| ------ | ---- | ------------------------------------------------------------ |
| uri                | string          | No         | Yes  | URI information associated with the InsightIntent.                                |
| paramsMapping      | [LinkIntentParamMapping](#linkintentparammapping)[] | No| No  | Mapping between InsightIntent parameters and URI information.   |

## LinkIntentParamMapping

**LinkIntentParamMapping** defines the mapping between InsightIntent parameters and URI information for the [@InsightIntentLink](#insightintentlink) decorator.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Properties**

| Name            | Type  | Read-Only| Optional| Description                                  |
| ---------------- | ------ | ----| ---- | -------------------------------------- |
| paramName        | string | No| Yes  | Name of the InsightIntent parameter.                      |
| paramMappingName | string | No| No  | Mapping name of the InsightIntent parameter.                    |
| paramCategory    | string | No| No  | Category of the InsightIntent parameter, which can be either **link** or **want**.<br>If the InsightIntent parameter is used in a URI, set this parameter to **link**. When processing an InsightIntent parameter of the link category, the system retrieves **paramMappingName** corresponding to **paramName** and appends it to the URI as a key-value pair (where **key** is the value of **paramMappingName**, and **value** is the InsightIntent parameter value).<br>If the InsightIntent parameter needs to be passed to the application, set this parameter to **want**. The system passes the InsightIntent parameter using the **parameters** field of a [want](./js-apis-app-ability-want.md) object.|

## InsightIntentPage

Decorates a page in the application as an InsightIntent, enabling AI systems to swiftly navigate to that page. For details on the parameters supported by this decorator, see [PageIntentDecoratorInfo](#pageintentdecoratorinfo).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Example**

```ts
import { InsightIntentPage } from '@kit.AbilityKit';

@Entry
@Component
@InsightIntentPage({
  intentName: 'SearchMusic',
  domain: 'MusicDomain',
  intentVersion: '1.0.1',
  displayName: 'Search Music',
  displayDescription: 'InsightIntent to Search Music',
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

**PageIntentDecoratorInfo** inherits from [IntentDecoratorInfo](#intentdecoratorinfo) and describes the parameters supported by the [@InsightIntentPage](#insightintentpage) decorator, such as the name of [NavDestination](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10) of the target page.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Properties**

| Name              | Type        | Read-Only      | Optional| Description                                                        |
| ------------------ | -------------| --------- | ---- | ------------------------------------------------------------ |
| uiAbility          | string       | No          | No  | Name of the UIAbility bound to the InsightIntent.                                 |
| pagePath           | string        | No         | No  | Path of the page bound to the InsightIntent.                                  |
| navigationId       | string        | No       | No  | ID of the [Navigation](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navigation) component bound to the InsightIntent.|
| navDestinationName | string         | No      | No  | Name of the [NavDestination](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10) component bound to the InsightIntent.|

## InsightIntentFunction

This decorator must be used together with the [@InsightIntentFunctionMethod](#insightintentfunctionmethod) decorator.

This decorate is used to decorate a class, and [@InsightIntentFunctionMethod](#insightintentfunctionmethod) is used to decorate a static function in that class. This setup defines the static function as an InsightIntent, enabling AI systems to execute it rapidly.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

## InsightIntentFunctionMethod

This decorator must be used together with the [@InsightIntentFunction](#insightintentfunction) decorator.

[@InsightIntentFunction](#insightintentfunction) is used to decorate a class, and this decorator is used to decorate a static function in that class. This setup defines the static function as an InsightIntent, enabling AI systems to execute it rapidly.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Example**

```ts
import {  InsightIntentFunction, InsightIntentFunctionMethod } from '@kit.AbilityKit';

@InsightIntentFunction()
export class ClassForFuncDemo {
  @InsightIntentFunctionMethod({
  intentName: 'GetWeather',
  domain: 'LifeDomain',
  intentVersion: '1.0.1',
  displayName: 'Query weather',
  displayDescription: 'Display weather information',
  icon: $r("sys.plural.selecttitlebar_accessibility_message_desc_new"),
  llmDescription: 'Get weather of an location',
  parameters: {
    "schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "title": "Weather Schema",
    "description": "A schema for get weather of an location",
    "properties": {
      "location": {
        "type": "string",
        "description": "The city and state, e.g. Hangzhou",
        "minLength": 1
      }
    },
    "required": ["location"],
    "additionalProperties": false
  }
})
  static getWeather(location: string): string {
    console.log('location' + location);
    return 'The current temperature in Hangzhou is 24℃';
  }
}
```

## FunctionIntentDecoratorInfo

Parameter type of the [@InsightIntentFunctionMethod](#insightintentfunctionmethod) decorator. All properties inherit from [IntentDecoratorInfo](#intentdecoratorinfo).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.
