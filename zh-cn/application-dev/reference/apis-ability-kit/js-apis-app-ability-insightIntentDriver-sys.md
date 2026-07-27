# @ohos.app.ability.insightIntentDriver (执行意图调用)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

本模块提供执行意图调用的能力，系统根据用户交互等信息执行意图调用。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块为系统接口。
>
> 本模块从API version 20开始支持通过[@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)装饰器定义的意图来实现应用跳转。

## 导入模块

```ts
import { insightIntentDriver } from '@kit.AbilityKit';
```

## ExecuteParam

执行意图调用的参数。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | --- |----- | -------- |
| bundleName | string | 否 | 否 | 意图调用Ability所属的应用包名称。 |
| moduleName | string | 否 | 否 | 意图调用Ability所属的模块名称。 |
| abilityName | string | 否 | 否 | 意图调用Ability名称。 如果通过[@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)装饰器定义的意图来实现应用跳转，此字段传空字符串即可。 |
| insightIntentName | string | 否 | 否 | 意图调用名称。 |
| insightIntentParam | Record\<string, Object> | 否 | 否 | 意图调用参数。 |
| executeMode | [insightIntent.ExecuteMode](js-apis-app-ability-insightIntent.md#executemode) | 否 | 否 | 意图调用执行模式。 如果通过[@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)装饰器定义的意图来实现应用跳转，此字段需填写（可填ExecuteMode枚举类型中的任意值），但不会影响应用跳转的实际执行逻辑。 |
| displayId<sup>12+</sup> | number | 否 | 是 | 意图调用时指定的物理屏幕id，该参数应为整数，仅在executeMode为UI_ABILITY_FOREGROUND时生效。 |
| uris<sup>18+</sup> | Array&lt;string&gt; | 否 | 是 | 意图调用时，意图调用方给意图执行方授权的URI列表。 如果通过[@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)装饰器定义的意图来实现应用跳转，此字段必选，仅读取数组第一个元素作为[openLink](js-apis-inner-application-uiAbilityContext.md#openlink12)的URI。 |
| flags<sup>18+</sup> | number | 否 | 是 | 意图调用时，意图调用方给意图执行方授权的uris的[flags](js-apis-app-ability-wantConstant.md#flags)。 <br>**说明：**<br>该参数仅支持FLAG_AUTH_READ_URI_PERMISSION、FLAG_AUTH_WRITE_URI_PERMISSION、FLAG_AUTH_READ_URI_PERMISSION\|FLAG_AUTH_WRITE_URI_PERMISSION。|
| userId<sup>23+</sup> | number | 否 | 是 | 目标意图所属的用户ID。<br>**说明：**<br>如果调用方应用的用户ID与目标意图所属的用户ID不同，则需要申请权限`ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS`。    |
| deviceId | string | 否 | 是 | 连接的目标设备ID。<br>**说明：**<br>如果调用方应用的设备ID与目标意图所属的设备ID不同，则需要申请权限`ohos.permission.EXECUTE_DISTRIBUTED_INTENT`。<br>**起始版本：** 26.0.0    |

## InsightIntentInfoFilter<sup>23+</sup>

意图筛选器，描述目标意图的筛选条件，用于筛选设备上符合条件的意图。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称        | 类型   | 只读 | 可选 | 说明                                                         |
| ----------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| intentFlags | number | 否   | 否   | 意图信息（[InsightIntentInfo](#insightintentinfo20)）的标识，用于表示查询全量意图信息或者简要意图信息，取值可参考[GetInsightIntentFlag](#getinsightintentflag20)。 |
| bundleName  | string | 否   | 是   | 目标意图所属的应用包名称。                                                 |
| moduleName  | string | 否   | 是   | 目标意图所属的模块名称。                                                   |
| intentName  | string | 否   | 是   | 目标意图名称。                                                   |
| userId      | number | 否   | 是   | 目标意图所属的用户ID。<br/>**说明：**<br/>如果调用方应用的用户ID与目标意图所属的用户ID不同，则需要申请权限`ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS`。   |
## InsightIntentType<sup>20+</sup>

表示通过意图装饰器定义的意图类型，可通过[getAllInsightIntentInfo](#insightintentdrivergetallinsightintentinfo20)等方法返回的[LinkIntentInfo](#linkintentinfo20)获取。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| LINK | @InsightIntentLink | [@InsightIntentLink](./js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)类型装饰器。 |
| PAGE | @InsightIntentPage | [@InsightIntentPage](./js-apis-app-ability-InsightIntentDecorator.md#insightintentpage)类型装饰器。 |
| ENTRY | @InsightIntentEntry | [@InsightIntentEntry](./js-apis-app-ability-InsightIntentDecorator.md#insightintententry)类型装饰器。 |
| FUNCTION | @InsightIntentFunctionMethod | [@InsightIntentFunctionMethod](./js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod)类型装饰器。 |
| FORM | @InsightIntentForm | [@InsightIntentForm](./js-apis-app-ability-InsightIntentDecorator.md#insightintentform)类型装饰器。 |

## ExecuteModeForConfiguration<sup>23+</sup>

[使用配置文件开发的意图](../../application-models/insight-intent-config-development.md)支持的意图执行模式。例如，将[insight_intent.json配置文件](../../application-models/insight-intent-config-development.md#insight_intentjson配置文件说明)中的executeMode设置为"foreground"，表示支持与UIAbility组件绑定的意图在前台运行。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| FOREGROUND | 0 | 表示支持与UIAbility组件绑定的意图在前台运行。 |
| BACKGROUND | 1 | 表示支持与UIAbility组件绑定的意图在后台运行。 |

## LinkIntentInfo<sup>20+</sup>

LinkIntentInfo用于描述[@InsightIntentLink](./js-apis-app-ability-InsightIntentDecorator.md#insightintentlink)装饰器支持的参数，例如应用间跳转需要的uri信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| uri | string | 是 | 否 | 表示意图的uri信息。 |

## PageIntentInfo<sup>20+</sup>

PageIntentInfo用于描述[@InsightIntentPage](./js-apis-app-ability-InsightIntentDecorator.md#insightintentpage)装饰器支持的参数，例如目标页面的[navDestination](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10)名称。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| uiAbility | string | 是 | 否 | UIAbility组件名称。 |
| pagePath | string | 是 | 否 | 页面名称。 |
| navigationId | string | 是 | 否 |  表示与意图绑定[Navigation](../apis-arkui/arkui-ts/ts-basic-components-navigation.md)的id。 |
| navDestinationName | string | 是 | 否 | 表示与意图绑定[navDestination](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10)组件的名称。 |

## FunctionIntentInfo<sup>20+</sup>

[@InsightIntentFunctionMethod](./js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod)装饰器的参数类型，当前全部属性均继承自[IntentDecoratorInfo](./js-apis-app-ability-InsightIntentDecorator.md#intentdecoratorinfo)。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

## FormIntentInfo<sup>20+</sup>

FormIntentInfo用于描述[@InsightIntentForm](./js-apis-app-ability-InsightIntentDecorator.md#insightintentform)装饰器支持的参数，例如卡片名称。同时，该接口也可用于描述[使用配置文件开发的意图](../../application-models/insight-intent-config-development.md)所绑定的卡片信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| abilityName | string | 是 | 否 | Ability名称。 |
| formName | string | 是 | 否 | 表示[FormExtensionAbility](../apis-form-kit/js-apis-app-form-formExtensionAbility.md)绑定的卡片名称。 |

## EntryIntentInfo<sup>20+</sup>

EntryIntentInfo用于描述[@InsightIntentEntry](./js-apis-app-ability-InsightIntentDecorator.md#insightintententry)装饰器支持的参数，例如意图调用执行模式。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| abilityName | string | 是 | 否 | Ability名称。 |
| executeMode | [insightIntent.ExecuteMode](./js-apis-app-ability-insightIntent.md#executemode)[] | 是 | 否 | 意图调用执行模式。即拉起绑定的Ability时支持的执行模式。 |

## SubIntentInfoForConfiguration<sup>23+</sup>

用于描述[使用配置文件开发的意图](../../application-models/insight-intent-config-development.md)的特有信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| srcEntry | string | 是 | 否 | 表示意图执行文件的相对路径，取值为长度不超过127字节的字符串。 |
| inputParams | Array&lt;Record\<string, Object\>&gt; | 是 | 是 | 表示意图参数的数据格式声明，用于意图调用时定义入参的数据格式。 |
| outputParams | Array&lt;Record\<string, Object\>&gt; | 是 | 是 | 表示意图调用返回结果的数据格式声明，用于定义意图调用返回结果的数据格式。 |
| uiAbility | [UIAbilityIntentInfo](#uiabilityintentinfo23) | 是 | 是 | 表示意图绑定的UIAbility组件信息，包含"ability"字段和"executeMode"字段。 |
| uiExtension | [UIExtensionIntentInfo](#uiextensionintentinfo23) | 是 | 是 | 表示意图绑定的UIExtensionAbility组件信息。 |
| form | [FormIntentInfo](#formintentinfo20) | 是 | 是 | 表示意图绑定的卡片信息。 |
| serviceExtension | [ServiceExtensionIntentInfo](#serviceextensionintentinfo23) | 是 | 是 | 表示意图绑定的ServiceExtensionAbility组件信息。 |
| entities | Record\<string, Object\> | 是 | 是 | 表示意图包含的实体信息。 |

## UIAbilityIntentInfo<sup>23+</sup>

用于描述[使用配置文件开发的意图](../../application-models/insight-intent-config-development.md)所绑定的UIAbility组件信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| abilityName | string | 是 | 否 | 意图绑定的UIAbility组件名称。 |
| executeMode | [ExecuteModeForConfiguration](#executemodeforconfiguration23)[] | 是 | 否 | 意图调用执行模式。 |

## UIExtensionIntentInfo<sup>23+</sup>

用于描述[使用配置文件开发的意图](../../application-models/insight-intent-config-development.md)所绑定的UIExtensionAbility组件信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| abilityName | string | 是 | 否 | 意图绑定的UIExtensionAbility组件名称。 |

## ServiceExtensionIntentInfo<sup>23+</sup>

用于描述[使用配置文件开发的意图](../../application-models/insight-intent-config-development.md)所绑定的ServiceExtensionAbility组件信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| abilityName | string | 是 | 否 | 意图绑定的ServiceExtensionAbility组件名称。 |

## DevelopType<sup>23+</sup>

用于描述意图的开发方式。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CONFIGURATION  | 'configuration' | 使用配置文件开发的意图。 |
| DECORATOR | 'decorator' | 使用装饰器开发的意图。 |

## EntityInfo<sup>20+</sup>

EntityInfo继承自[IntentEntityDecoratorInfo](./js-apis-app-ability-InsightIntentDecorator.md#intententitydecoratorinfo)，用于描述[@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity)装饰器定义的意图实体的信息。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| className | string | 是 | 否 | 表示[@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity)装饰器修饰的类名。 |
| entityId | string | 是 | 否 | 表示意图实体的ID。 |
| entityCategory | string | 是 | 否 | 表示意图实体类别。 |
| parameters | Record\<string, Object> | 是 | 否 | 表示意图实体参数的数据格式声明，用于意图调用时定义实体参数的数据格式。 |
| parentClassName | string | 是 | 否 | 表示[@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity)装饰器修饰的类的父类名。 |
| isQueryable | boolean | 是 | 是 | 表示[@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity)装饰器修饰的意图实体类是否支持查询，只有继承自[insightIntent.AppIntentEntity](./js-apis-app-ability-insightIntent.md#appintententity)类的意图实体支持查询。<br/> - true：支持查询。<br/> - false：不支持查询。<br/>**起始版本**：26.0.0 |
| supportedQueryProperties | string[] | 是 | 是 | 表示[@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity)装饰器修饰的意图实体支持通过哪些属性进行查询。意图实体查询参数[parameters](./js-apis-app-ability-insightIntent.md#queryentityparam)的key值必须在该属性列表中。<br/>**起始版本**：26.0.0 |

## InsightIntentInfo<sup>20+</sup>

意图信息，表示设备中意图的具体参数配置。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- |-------- |
| bundleName | string | 是 | 否 | 表示应用包名称。 |
| moduleName | string | 是 | 否 | 表示模块名称。 |
| intentName | string | 是 | 否 | 表示意图名称。 |
| domain | string | 是 | 否 | 表示意图垂域，用于将意图按垂直领域分类（例如：视频、音乐、游戏），取值范围参见[各垂域的智慧分发特性列表](https://developer.huawei.com/consumer/cn/doc/service/intents-ai-distribution-characteristic-0000001901922213#section2656133582215)中的垂域字段。 |
| intentVersion | string | 是 | 否 | 意图版本号，当意图能力演进时，可通过版本号进行区分和管理。|
| displayName | string | 是 | 否 | 表示在意图框架中显示的意图名称。 |
| displayDescription | string | 是 | 否 | 表示在意图框架中显示的意图描述。 |
| schema | string | 是 | 否 | 标准意图名称，如果在标准意图列表中存在schema与intentVersion字段均匹配的意图，则按照标准意图处理。 |
| icon | string | 是 | 否 | 表示意图图标。 |
| llmDescription | string | 是 | 否 | 表示意图的功能，用于大型语言模型理解该意图。 |
| keywords | string[] | 是 | 否 | 表示意图的搜索关键字。 |
| intentType | [InsightIntentType](#insightintenttype20) | 是 | 否 | 表示通过意图装饰器定义的意图类型。<br/>**说明：**<br/>对于使用配置文件开发的意图，该字段返回值默认为[@InsightIntentEntry](./js-apis-app-ability-InsightIntentDecorator.md#insightintententry)类型装饰器。 |
| subIntentInfo | [LinkIntentInfo](#linkintentinfo20) \| [PageIntentInfo](#pageintentinfo20) \| [FunctionIntentInfo](#functionintentinfo20) \| [FormIntentInfo](#formintentinfo20) \| [EntryIntentInfo](#entryintentinfo20) | 是 | 否 | 表示特定意图装饰器的意图信息。 <br/>**说明：**<br/>对于使用配置文件开发的意图，该字段返回值默认为[EntryIntentInfo](#entryintentinfo20)。 |
| parameters | Record<string, Object> | 是 | 否 | 表示意图参数的数据格式声明，用于意图调用时定义入参的数据格式。 |
| result | Record<string, Object> | 是 | 否 | 表示意图调用返回的结果。 |
| entities | Array&lt;[EntityInfo](#entityinfo20)&gt; | 是 | 否 | 表示意图包含的实体信息。 |
| subIntentInfoForConfiguration<sup>23+</sup> | [SubIntentInfoForConfiguration](#subintentinfoforconfiguration23) | 是 | 是 | 表示使用配置文件开发的意图的特有信息。 |
| developType<sup>23+</sup> | [DevelopType](#developtype23) | 是 | 是 | 表示意图的开发方式。 |

## GetInsightIntentFlag<sup>20+</sup>

意图信息（[InsightIntentInfo](#insightintentinfo20)）的标识，用于[getAllInsightIntentInfo](#insightintentdrivergetallinsightintentinfo20)、[getInsightIntentInfoByBundleName](#insightintentdrivergetinsightintentinfobybundlename20)和[getInsightIntentInfoByIntentName](#insightintentdrivergetinsightintentinfobyintentname20)接口查询意图信息。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| GET_FULL_INSIGHT_INTENT | 0x00000001 | 查询[InsightIntentInfo](#insightintentinfo20)中的除entities以外的全量意图信息，详见下表。查询entities信息需要使用GET_ENTITY_INFO。 |
| GET_SUMMARY_INSIGHT_INTENT | 0x00000002 | 查询[InsightIntentInfo](#insightintentinfo20)中的简要意图信息，详见下表。 |
| GET_ENTITY_INFO | 0x00000004 | 查询[EntityInfo](#entityinfo20)的信息，不可单独使用，必须结合GET_FULL_INSIGHT_INTENT或者GET_SUMMARY_INSIGHT_INTENT使用。例如`GET_FULL_INSIGHT_INTENT \| GET_ENTITY_INFO`。 |

> **说明：**
>
>  - 对于使用配置文件开发的意图，通过上述接口查询的全量信息和简要信息完全一致。
>  - 对于使用装饰器开发的意图，通过上述接口查询的全量信息和简要信息存在差别，详见下表。

**表1** 全量意图信息与简要意图信息差别
   
| 属性 | 全量意图信息是否包含 | 简要意图信息是否包含 |
| -------- | -------- | -------- |
| bundleName | 是 | 是 | 
| moduleName | 是 | 是 |
| intentName | 是 | 是 |
| domain | 是 | 否 |
| intentVersion | 是 | 否 |
| displayName | 是 | 是 |
| displayDescription | 是 | 否 |
| schema | 是 | 否 |
| icon | 是 | 否 |
| llmDescription | 是 | 否 |
| keywords | 是 | 否 |
| intentType | 是 | 是 |
| subIntentInfo | 是 | 是 |
| parameters | 是 | 是 |
| entities | 否 | 否 |
| developType<sup>23+</sup> | 是 | 是 |
| subIntentInfoForConfiguration<sup>23+</sup> | 否 | 否 |

## QueryParam

意图实体查询参数，用于筛选设备上符合条件的意图实体。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| bundleName  | string | 否   | 否   | 目标意图实体所属的应用包名称。 |
| moduleName  | string | 否   | 否   | 目标意图实体所属的模块名称。 |
| intentName  | string | 否   | 否   | 目标意图实体所属的意图名称。 |
| className | string | 否 | 否 | 表示[@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity)修饰的目标意图实体的类名。 |
| queryEntityParam | [insightIntent.QueryEntityParam](./js-apis-app-ability-insightIntent.md#queryentityparam) | 否 | 否 | 意图实体查询参数，包含查询模式及查询条件，用于指定意图实体查询方式。 |
| userId      | number | 否   | 是   | 目标意图实体所属的用户ID。<br/>**说明：**<br/>如果调用方应用的用户ID与目标意图实体所属的用户ID不同，则需要申请权限`ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS`。   |

## insightIntentDriver.execute

execute(param: ExecuteParam, callback: AsyncCallback<insightIntent.ExecuteResult>): void

执行意图调用的接口。使用callback异步回调。

当调用方在后台时，需要申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。

当意图调用执行模式[ExecuteMode](js-apis-app-ability-insightIntent.md#executemode)取值为UI_ABILITY_BACKGROUND时，需要申请`ohos.permission.ABILITY_BACKGROUND_COMMUNICATION`权限。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.EXECUTE_INSIGHT_INTENT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](#executeparam) | 是 | 执行意图调用的参数。 |
  | callback | AsyncCallback<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | 是 | 回调函数，返回意图调用执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000137 | Cross-device execution failed due to a connection error. <br>适用版本：26.0.0+ |
| 16000138 | Device disconnected during cross-device intent execution. <br>适用版本：26.0.0+ |

**示例：**

```ts
  import { insightIntentDriver, insightIntent } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  function executeInsightIntentAsync() {
    let param: insightIntentDriver.ExecuteParam = {
      bundleName: 'com.ohos.intentexecutedemo',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      insightIntentName: 'PlayMusic',
      insightIntentParam: {
        songName: 'City Of Stars',
      },
      executeMode: insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND,
    };

    try {
      insightIntentDriver.execute(param, (error, data: insightIntent.ExecuteResult) => {
        if (error) {
          hilog.error(0x0000, 'testTag', 'execute insight intent failed with %{public}s', JSON.stringify(error));
        } else {
          hilog.info(0x0000, 'testTag', '%{public}s', 'execute insight intent succeed');
        }
        hilog.info(0x0000, 'testTag', 'execute insight intent return %{public}d', data.code);
        hilog.info(0x0000, 'testTag', 'execute insight intent result %{public}s', JSON.stringify(data.result));
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'execute insight intent error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.execute

execute(param: ExecuteParam): Promise<insightIntent.ExecuteResult>

执行意图调用的接口。使用Promise异步回调。

当调用方在后台时，需要申请`ohos.permission.START_ABILITIES_FROM_BACKGROUND`权限。

当意图调用执行模式[ExecuteMode](js-apis-app-ability-insightIntent.md#executemode)取值为UI_ABILITY_BACKGROUND时，需要申请`ohos.permission.ABILITY_BACKGROUND_COMMUNICATION`权限。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.EXECUTE_INSIGHT_INTENT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](#executeparam) | 是 | 执行意图调用的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise对象，返回意图调用执行结果。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Cannot start an invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000137 | Cross-device execution failed due to a connection error. <br>适用版本：26.0.0+ |
| 16000138 | Device disconnected during cross-device intent execution. <br>适用版本：26.0.0+ |

**示例：**

```ts
  import { insightIntentDriver, insightIntent } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  async function executeSearchMusicIntentPromise() {
    let param: insightIntentDriver.ExecuteParam = {
      bundleName: 'com.ohos.intentexecutedemo',
      moduleName: 'entry',
      abilityName: 'EntryAbility',
      insightIntentName: 'PlayMusic',
      insightIntentParam: {
        songName: 'City Of Stars',
      },
      executeMode: insightIntent.ExecuteMode.UI_ABILITY_FOREGROUND,
    };

    try {
      let resultData: insightIntent.ExecuteResult = await insightIntentDriver.execute(param);
      hilog.info(0x0000, 'testTag', 'execute insight intent return %{public}d', resultData.code);
      hilog.info(0x0000, 'testTag', 'execute insight intent result %{public}s', JSON.stringify(resultData.result));
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'execute insight intent error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.getAllInsightIntentInfo<sup>20+</sup>

getAllInsightIntentInfo(intentFlags: number): Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>>

查询当前设备上的所有意图信息。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | intentFlags | number | 是 | 意图信息（[InsightIntentInfo](#insightintentinfo20)）的标识，用于表示查询全量意图信息或者简要意图信息，参考[GetInsightIntentFlag](#getinsightintentflag20)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>> | Promise对象，返回意图信息对象数组。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service fails to communicate with the dependency module.  |

**示例：**

```ts
  import { insightIntentDriver } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  async function getInfos() {
    try {
      insightIntentDriver.getAllInsightIntentInfo(insightIntentDriver.GetInsightIntentFlag.GET_FULL_INSIGHT_INTENT | insightIntentDriver.GetInsightIntentFlag.GET_ENTITY_INFO).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllInsightIntentInfo return %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getAllInsightIntentInfo errCode: %{public}d', err.code);
        hilog.error(0x0000, 'testTag', 'getAllInsightIntentInfo errMessage: %{public}s', err.message);
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getAllInsightIntentInfo error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.getInsightIntentInfoByBundleName<sup>20+</sup>

getInsightIntentInfoByBundleName(bundleName: string, intentFlags: number): Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>>

根据包名查询当前设备上的意图信息。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名称。 <br/>**说明：**<br/> 若包名不存在，则返回空数组。 |
  | intentFlags | number | 是 | 意图信息（[InsightIntentInfo](#insightintentinfo20)）的标识，用于表示查询全量意图信息或者简要意图信息，参考[GetInsightIntentFlag](#getinsightintentflag20)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>> | Promise对象，返回意图信息对象数组。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service fails to communicate with the dependency module.  |

**示例：**

```ts
  import { insightIntentDriver } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  async function getInfosByBundleName() {
    try {
      let bundleName = "com.example.intent"; // 开发者需自行修改为实际包名
      insightIntentDriver.getInsightIntentInfoByBundleName(bundleName, insightIntentDriver.GetInsightIntentFlag.GET_FULL_INSIGHT_INTENT | insightIntentDriver.GetInsightIntentFlag.GET_ENTITY_INFO).then((data) => {
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByBundleName return %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByBundleName errCode: %{public}d', err.code);
        hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByBundleName errMessage: %{public}s', err.message);
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByBundleName error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.getInsightIntentInfoByIntentName<sup>20+</sup>

getInsightIntentInfoByIntentName(bundleName: string, moduleName: string, intentName: string, intentFlags: number): Promise<[InsightIntentInfo](#insightintentinfo20)>

根据包名、模块名和意图名查询当前设备上的意图信息。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | bundleName | string | 是 | 应用包名称。<br/>**说明：**<br/> 若包名不存在，则返回空对象。|
  | moduleName | string | 是 | 模块名称。<br/>**说明：**<br/> 若模块名不存在，则返回空对象。|
  | intentName | string | 是 | 意图名称。<br/>**说明：**<br/> 若意图名不存在，则返回空对象。|
  | intentFlags | number | 是 | 意图信息（[InsightIntentInfo](#insightintentinfo20)）的标识，用于表示查询全量意图信息或者简要意图信息，参考[GetInsightIntentFlag](#getinsightintentflag20)。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<[InsightIntentInfo](#insightintentinfo20)> | Promise对象，返回意图信息对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. Possible causes: 1. Failed to connect to the system service; 2. The system service fails to communicate with the dependency module.  |

**示例：**

```ts
  import { insightIntentDriver } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  function getInfoByIntentName() {
    try {
      let bundleName = "com.example.intent"; // 开发者需自行修改为实际包名
      let moduleName = "entry"; // 开发者需自行修改为实际模块名
      let intentName = "PlayMusic"; // 开发者需自行修改为实际意图名
      insightIntentDriver.getInsightIntentInfoByIntentName(
        bundleName, moduleName, intentName, insightIntentDriver.GetInsightIntentFlag.GET_FULL_INSIGHT_INTENT | insightIntentDriver.GetInsightIntentFlag.GET_ENTITY_INFO)
      .then((data) => {
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByIntentName return %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByIntentName errCode: %{public}d', err.code);
        hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByIntentName errMessage: %{public}s', err.message);
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByIntentName error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.getInsightIntentInfoByFilter<sup>23+</sup>

getInsightIntentInfoByFilter(filter: InsightIntentInfoFilter): Promise<Array\<InsightIntentInfo>>

根据[InsightIntentInfoFilter](#insightintentinfofilter23)查询当前设备上的意图信息。使用Promise异步回调。<br/>如果调用方应用的用户ID与目标用户ID不同，则需要申请权限`ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS`。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名                  | 类型                                                  | 必填 | 说明                     |
| ----------------------- | ----------------------------------------------------- | ---- | ------------------------ |
| filter | [InsightIntentInfoFilter](#insightintentinfofilter23) | 是   | 意图筛选器，描述目标意图的筛选条件，用于筛选设备上符合条件的意图。 |

**返回值：**

| 类型                                                       | 说明                                |
| ---------------------------------------------------------- | ----------------------------------- |
| Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>> | Promise对象，返回意图信息对象数组。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Not system application.                                      |
| 16000006 | Cross-user operations are not allowed.                       |
| 16000050 | Internal error. Possible causes: 1. Connect to system service failed; 2.Send restart message to system service failed; 3.System service failed to communicate with dependency module.|

**示例：**

```ts
import { insightIntentDriver } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

function getInfoByFilter() {
  let filter: insightIntentDriver.InsightIntentInfoFilter = {
    intentFlags: insightIntentDriver.GetInsightIntentFlag.GET_FULL_INSIGHT_INTENT | insightIntentDriver.GetInsightIntentFlag.GET_ENTITY_INFO,
    bundleName: 'com.example.intent', // 开发者需自行修改为实际包名
    moduleName: 'entry', // 开发者需自行修改为实际模块名
    intentName: 'PlayMusic', // 开发者需自行修改为实际意图名
    userId: 100, // 开发者需自行修改为实际userId
  };

  try {
    insightIntentDriver.getInsightIntentInfoByFilter(filter).then((data) => {
      hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByFilter return %{public}s', JSON.stringify(data));
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByFilter errCode: %{public}d', err.code);
      hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByFilter errMessage: %{public}s', err.message);
    });
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByFilter error caught %{public}s', JSON.stringify(error));
  }
}
```

## insightIntentDriver.queryEntityInfo

queryEntityInfo(param: QueryParam): Promise\<Array\<Record\<string, Object>>>

根据[QueryParam](#queryparam)查询应用的动态意图实体信息。使用Promise异步回调。<br/>如果调用方应用的用户ID与目标用户ID不同，则需要申请权限`ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS`。

**起始版本**：26.0.0

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.EXECUTE_INSIGHT_INTENT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| param | [QueryParam](#queryparam) | 是 | 意图实体参数，描述意图实体的查询条件，用于查询应用中符合条件的意图实体。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<Array\<Record\<string, Object>>> | Promise对象，返回应用返回的意图实体数组。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denied. |
| 202 | Not system application. |
| 16000006 | Cross-user operations are not allowed. |
| 16000050 | Internal error. Possible causes: 1. Connect to system service failed; 2.Send restart message to system service failed; 3.System service failed to communicate with dependency module. |

**示例：**

```ts
import { insightIntent, insightIntentDriver } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

function queryEntityInfoByPromise() {
  let queryParam: insightIntentDriver.QueryParam = {
    bundleName: 'com.example.intent', // 开发者需自行修改为实际包名
    moduleName: 'entry', // 开发者需自行修改为实际模块名
    intentName: 'PlayMusic', // 开发者需自行修改为实际意图名
    className: 'AppIntentEntityImpl', // 开发者需自行修改为实际的类名
    queryEntityParam: {
      queryType: insightIntent.QueryType.BY_PROPERTY,
      parameters: { // 开发者需自行修改为实际的查询参数
        'entityId': 'default'
      },
    },
    userId: 100,
  }

  try {
    insightIntentDriver.queryEntityInfo(queryParam)
      .then((data: Array<Record<string, Object>> | undefined) => {
        if (data) {
          hilog.info(0x0000, 'testTag', 'queryEntityInfo return %{public}s', JSON.stringify(data));
        } else {
          hilog.info(0x0000, 'testTag', 'queryEntityInfo return empty result');
        }
      })
      .catch((err: BusinessError) => {
        hilog.error(0x0000, 'testTag', 'queryEntityInfo errCode: %{public}d', err.code);
        hilog.error(0x0000, 'testTag', 'queryEntityInfo errMessage %{public}s', err.message);
      });
  } catch (error) {
    hilog.error(0x0000, 'testTag', 'queryEntityInfo error caught %{public}s', JSON.stringify(error));
  }
}
```
