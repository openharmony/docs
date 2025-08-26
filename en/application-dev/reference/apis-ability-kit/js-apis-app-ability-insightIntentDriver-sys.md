# @ohos.app.ability.insightIntentDriver (Intent Call Execution) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @li-weifeng2-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module provides APIs for executing intent calls. The system executes intent calls based on user interaction and more.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.
>
> Starting from API version 20, this module supports application navigation using intents defined by the [@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink) decorator.

## Modules to Import

```ts
import { insightIntentDriver } from '@kit.AbilityKit';
```

## ExecuteParam

Defines the parameter used to execute an intent call.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | --- |----- | -------- |
| bundleName | string | No| No| Name of the bundle to which the ability to be called belongs.|
| moduleName | string | No| No| Name of the module to which the ability belongs.|
| abilityName | string | No| No| Name of the ability to be called. If an intent defined by the [@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink) decorator is used to implement application redirection, this parameter can be left empty.|
| insightIntentName | string | No| No| Intent name.|
| insightIntentParam | Record\<string, Object> | No| No| Intent call parameter.|
| executeMode | [insightIntent.ExecuteMode](js-apis-app-ability-insightIntent.md#executemode) | No| No| Intent call execution mode. If an intent defined by the [@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink) decorator is used to implement application redirection, this parameter must be filled (with any value that conforms to the definition), although it will not actually take effect.|
| displayId<sup>12+</sup> | number | No| Yes| Physical screen ID specified during intent call. The value must be an integer. This parameter is valid only when **executeMode** is set to **UI_ABILITY_FOREGROUND**.|
| uris<sup>18+</sup> | Array&lt;string&gt; | No| Yes| List of URIs authorized by the intent caller to the intent executor during the call. If an intent defined by the [@InsightIntentLink](js-apis-app-ability-InsightIntentDecorator.md#insightintentlink) decorator is used to implement application redirection, this field is mandatory. Only the first element in the array is read as the URI of [openLink](js-apis-inner-application-uiAbilityContext.md#openlink12).|
| flags<sup>18+</sup> | number | No| Yes| [Flags](js-apis-app-ability-wantConstant.md#flags) of the URIs authorized by the intent caller to the intent executor during the call.<br>**NOTE**<br>This parameter supports only **FLAG_AUTH_READ_URI_PERMISSION**, **FLAG_AUTH_WRITE_URI_PERMISSION**, and FLAG_AUTH_READ_URI_PERMISSION\||FLAG_AUTH_WRITE_URI_PERMISSION.|

## InsightIntentType<sup>20+<sup>

Enumerates the intent types defined by the intent decorator. You can obtain the intent type from [LinkIntentInfo](#linkintentinfo20) returned by calling APIs such as [getAllInsightIntentInfo](#insightintentdrivergetallinsightintentinfo20).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| LINK | @InsightIntentLink | A decorator of the [@InsightIntentLink](./js-apis-app-ability-InsightIntentDecorator.md#insightintentlink) type.|
| PAGE | @InsightIntentPage | A decorator of the [@InsightIntentPage](./js-apis-app-ability-InsightIntentDecorator.md#insightintentpage) type.|
| ENTRY | @InsightIntentEntry | A decorator of the [@InsightIntentEntry](./js-apis-app-ability-InsightIntentDecorator.md#insightintententry) type.|
| FUNCTION | @InsightIntentFunctionMethod | A decorator of the [@InsightIntentFunctionMethod](./js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod) type.|
| FORM | @InsightIntentForm | A decorator of the [@InsightIntentForm](./js-apis-app-ability-InsightIntentDecorator.md#insightintentform) type.|

## LinkIntentInfo<sup>20+<sup>

LinkIntentInfo inherits from [IntentDecoratorInfo](./js-apis-app-ability-InsightIntentDecorator.md#intentdecoratorinfo). It is used to describe parameters supported by the [@InsightIntentLink](./js-apis-app-ability-InsightIntentDecorator.md#insightintentlink) decorator, such as the URI required for application redirection.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- |-------- |
| uri | string | Yes| No| URI of an intent.|

## PageIntentInfo<sup>20+<sup>

PageIntentInfo inherits from [IntentDecoratorInfo](./js-apis-app-ability-InsightIntentDecorator.md#intentdecoratorinfo). It is used to describe parameters supported by the [@InsightIntentPage](./js-apis-app-ability-InsightIntentDecorator.md#insightintentpage) decorator, such as the name of [NavDestination](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10) of the target page.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- |-------- |
| uiAbility | string | Yes| No| Ability name.|
| pageRouterName | string | Yes| No| Page name.|
| navigationId | string | Yes| No|  ID of the [Navigation](../apis-arkui/arkui-ts/ts-basic-components-navigation.md) component bound to the intent.|
| navDestination | string | Yes| No| Name of the [NavDestination](../apis-arkui/arkui-ts/ts-basic-components-navigation.md#navdestination10) component bound to the intent.|

## FunctionIntentInfo<sup>20+<sup>

Defines the parameter type of the [@InsightIntentFunctionMethod](./js-apis-app-ability-InsightIntentDecorator.md#insightintentfunctionmethod) decorator. All parameters inherit from [IntentDecoratorInfo](./js-apis-app-ability-InsightIntentDecorator.md#intentdecoratorinfo).

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

## EntityInfo<sup>20+<sup>

EntityInfo inherits from [IntentEntityDecoratorInfo](./js-apis-app-ability-InsightIntentDecorator.md#intententitydecoratorinfo) and is used to describe the information about the intent entity defined by the [@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity) decorator.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- |-------- |
| className | string | Yes| No| Class name decorated by [@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity).|
| entityId | string | Yes| No| ID of the intent entity.|
| entityCategory | string | Yes| No| Category of the intent entity.|
| parameters | string | Yes| No| Data format of intent entity parameters.|
| parentClassName | string | Yes| No| Parent class name decorated by [@InsightIntentEntity](./js-apis-app-ability-InsightIntentDecorator.md#insightintententity).|

## InsightIntentInfo<sup>20+<sup>

Defines the intent information, which is the specific parameter configuration of the intent in the device.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- |-------- |
| bundleName | string | Yes| No| Bundle name of the application.|
| moduleName | string | Yes| No| Module name.|
| intentName | string | Yes| No| Intent name.|
| domain | string | Yes| No| Vertical domain of the intent. It is used to categorize intents by vertical fields (for example, video, music, and games). For details about the value range, see the vertical domain fields in [smart distribution features in different vertical domains](https://developer.huawei.com/consumer/en/doc/service/intents-ai-distribution-characteristic-0000001901922213#section2656133582215).|
| intentVersion | string | Yes| No| Version number of the intent. It is used to distinguish and manage intents when their capabilities evolve.|
| displayName | string | Yes| No| Name of the intent displayed in the InsightIntent framework.|
| displayDescription | string | Yes| No| Description of the intent displayed in the InsightIntent framework.|
| schema | string | Yes| No| Standard intent name. If an intent in the standard intent list matches both the **schema** and **intentVersion** fields, it is processed as a standard intent.|
| icon | string | Yes| No| Icon of the intent.|
| llmDescription | string | Yes| No| Function of an intent, which helps large language models understand the intent.|
| keywords | Array&lt;string&gt; | Yes| No| Search keywords for the intent.|
| intentType | [InsightIntentType](#insightintenttype20) | Yes| No| Type of intent defined by the intent decorator.|
| subIntentInfo | [LinkIntentInfo](#linkintentinfo20) \| [PageIntentInfo](#pageintentinfo20) \| [FunctionIntentInfo](#functionintentinfo20) | Yes| No| Intent information for specific intent decorators.|
| parameters | Record<string, Object> | Yes| No| Data format of intent parameters, which is used to define the input data format during intent calls.|
| entities | Array&lt;[EntityInfo](#entityinfo20)&gt; | Yes| No| Entity information contained in the intent.|

## GetInsightIntentFlag<sup>20+<sup>

Enumerates the flags of intent information ([InsightIntentInfo](#insightintentinfo20)). It is used in [getAllInsightIntentInfo](#insightintentdrivergetinsightintentinfobybundlename20), [getInsightIntentInfoByBundleName](#insightintentdrivergetinsightintentinfobybundlename20), and [getInsightIntentInfoByIntentName](#insightintentdrivergetinsightintentinfobyintentname20).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| GET_FULL_INSIGHT_INTENT | 0x00000001 | Used to query all intent information (except entities) in [InsightIntentInfo](#insightintentinfo20). To query entities information, use **GET_ENTITY_INFO**.|
| GET_SUMMARY_INSIGHT_INTENT | 0x00000002 | Used to query brief intent information in [InsightIntentInfo](#insightintentinfo20).|
| GET_ENTITY_INFO | 0x00000004 | Used to query [EntityInfo](#entityinfo20). It must be used together with **GET_FULL_INSIGHT_INTENT** or **GET_SUMMARY_INSIGHT_INTENT**. Example usage: `GET_FULL_INSIGHT_INTENT \| GET_ENTITY_INFO`.|

Table 1 Differences between full intent information and brief intent information
   
| Name| Included in Full Intent Information| Included in Brief Intent Information|
| -------- | -------- | -------- |
| bundleName | Yes| Yes| 
| moduleName | Yes| Yes|
| intentName | Yes| Yes|
| domain | Yes| No|
| intentVersion | Yes| No|
| displayName | Yes| Yes|
| displayDescription | Yes| No|
| schema | Yes| No|
| icon | Yes| No|
| llmDescription | Yes| No|
| keywords | Yes| No|
| intentType | Yes| Yes|
| subIntentInfo | Yes| Yes|
| parameters | Yes| Yes|
| entities | No| No|

## insightIntentDriver.execute

execute(param: ExecuteParam, callback: AsyncCallback<insightIntent.ExecuteResult>): void

Executes a call to an intent. This API uses an asynchronous callback to return the result.

When the caller is in the background, the ohos.permission.START_ABILITIES_FROM_BACKGROUND permission is required.

When [ExecuteMode](js-apis-app-ability-insightIntent.md#executemode) of the intent call is set to **UI_ABILITY_BACKGROUND**, the ohos.permission.ABILITY_BACKGROUND_COMMUNICATION permission is required.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.EXECUTE_INSIGHT_INTENT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](#executeparam) | Yes| Parameter used to execute the intent call.|
  | callback | AsyncCallback<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Yes| Callback used to return the intent call execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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

**Example**

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
      })
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'execute insight intent error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.execute

execute(param: ExecuteParam): Promise<insightIntent.ExecuteResult>

Executes a call to an intent. This API uses a promise to return the result.

When the caller is in the background, the ohos.permission.START_ABILITIES_FROM_BACKGROUND permission is required.

When [ExecuteMode](js-apis-app-ability-insightIntent.md#executemode) of the intent call is set to **UI_ABILITY_BACKGROUND**, the ohos.permission.ABILITY_BACKGROUND_COMMUNICATION permission is required.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.EXECUTE_INSIGHT_INTENT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](#executeparam) | Yes| Parameter used to execute the intent call.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the intent call execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
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

**Example**

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

## insightIntentDriver.getAllInsightIntentInfo<sup>20+<sup>

getAllInsightIntentInfo(intentFlags: number): Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>>

Obtains the information about all intents on the current device. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | intentFlags | number | Yes| Flag of the intent information ([InsightIntentInfo](#insightintentinfo20)). It is used to query full or brief intent information. For details, see [GetInsightIntentFlag](#getinsightintentflag20).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>> | Promise used to return an array holding InsightIntentInfo objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. |

**Example**

```ts
  import { insightIntentDriver } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  async function getInfos() {
    try {
      insightIntentDriver.getAllInsightIntentInfo(insightIntentDriver.GetInsightIntentFlag.GET_FULL_INSIGHT_INTENT | insightIntentDriver.GetInsightIntentFlag.GET_ENTITY_INFO).then((data) => {
        hilog.info(0x0000, 'testTag', 'getAllInsightIntentInfo return %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.info(0x0000, 'testTag', 'getAllInsightIntentInfo errCode: %{public}d', err.code);
        hilog.info(0x0000, 'testTag', 'getAllInsightIntentInfo errMessage: %{public}s', err.message);
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getAllInsightIntentInfo error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.getInsightIntentInfoByBundleName<sup>20+<sup>

getInsightIntentInfoByBundleName(bundleName: string, intentFlags: number): Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>>

Obtains the intent information on the current device based on the given bundle name. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | bundleName | string | Yes| Bundle name of the application.<br>**NOTE**<br> If the bundle name does not exist, an empty array is returned.|
  | intentFlags | number | Yes| Flag of the intent information ([InsightIntentInfo](#insightintentinfo20)). It is used to query full or brief intent information. For details, see [GetInsightIntentFlag](#getinsightintentflag20).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise<Array\<[InsightIntentInfo](#insightintentinfo20)>> | Promise used to return an array holding InsightIntentInfo objects.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. |

**Example**

```ts
  import { insightIntentDriver } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  async function getInfosByBundleName() {
    try {
      let bundleName = "com.example.intent"; // Use the actual bundle name.
      insightIntentDriver.getInsightIntentInfoByBundleName(bundleName, insightIntentDriver.GetInsightIntentFlag.GET_FULL_INSIGHT_INTENT | insightIntentDriver.GetInsightIntentFlag.GET_ENTITY_INFO).then((data) => {
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByBundleName return %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByBundleName errCode: %{public}d', err.code);
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByBundleName errMessage: %{public}s', err.message);
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByBundleName error caught %{public}s', JSON.stringify(error));
    }
  }
```

## insightIntentDriver.getInsightIntentInfoByIntentName<sup>20+<sup>

getInsightIntentInfoByIntentName(bundleName: string, moduleName: string, intentName: string, intentFlags: number): Promise<[InsightIntentInfo](#insightintentinfo20)>

Obtains the intent information on the current device based on the bundle name, module name, and intent name. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_BUNDLE_INFO_PRIVILEGED

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | bundleName | string | Yes| Bundle name of the application.<br>**NOTE**<br> If the bundle name does not exist, an empty object is returned.|
  | moduleName | string | Yes| Module name<br>**NOTE**<br> If the module name does not exist, an empty object is returned.|
  | intentName | string | Yes| Intent name.<br>**NOTE**<br> If the intent name does not exist, an empty object is returned.|
  | intentFlags | number | Yes| Flag of the intent information ([InsightIntentInfo](#insightintentinfo20)). It is used to query full or brief intent information. For details, see [GetInsightIntentFlag](#getinsightintentflag20).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise<[InsightIntentInfo](#insightintentinfo20)> | Promise used to return the InsightIntentInfo object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | -------- |
| 201      | Permission denied. |
| 202      | Not system application. |
| 16000050 | Internal error. |

**Example**

```ts
  import { insightIntentDriver } from '@kit.AbilityKit';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  function getInfoByIntentName() {
    try {
      let bundleName = "com.example.intent"; // Use the actual bundle name.
      let moduleName = "entry"; // Use the actual module name.
      let intentName = "play"; // Use the actual intent name.
      insightIntentDriver.getInsightIntentInfoByIntentName(
        bundleName, moduleName, intentName, insightIntentDriver.GetInsightIntentFlag.GET_FULL_INSIGHT_INTENT | insightIntentDriver.GetInsightIntentFlag.GET_ENTITY_INFO)
      .then((data) => {
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByIntentName return %{public}s', JSON.stringify(data));
      }).catch((err: BusinessError) => {
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByIntentName errCode: %{public}d', err.code);
        hilog.info(0x0000, 'testTag', 'getInsightIntentInfoByIntentName errMessage: %{public}s', err.message);
      });
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getInsightIntentInfoByIntentName error caught %{public}s', JSON.stringify(error));
    }
  }
```
