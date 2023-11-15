# @ohos.app.ability.insightIntentDriver (Executing InsightIntent Calls)

The **insightIntentDriver** module provides APIs for executing InsightIntent calls. The system executes InsightIntent calls based on user interaction and more.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import insightIntentDriver from '@ohos.app.ability.insightIntentDriver';
```

## ExecuteParam

Defines the parameter used to execute an InsightIntent call.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| bundleName | string | Yes| Name of the bundle to which the ability to be called belongs.|
| moduleName | string | Yes| Name of the module to which the ability belongs.|
| abilityName | string | Yes| Name of the ability to be called.|
| insightIntentName | string | Yes| InsightIntent name.|
| insightIntentParam | string | Yes| InsightIntent call parameter.|
| executeMode | [insightIntent.ExecuteMode](js-apis-app-ability-insightIntent.md#executemode) | Yes| InsightIntent call execution mode.|

## insightIntentDriver.execute

execute(param: ExecuteParam, callback: AsyncCallback<insightIntent.ExecuteResult>): void

Executes a call to an InsightIntent. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.EXECUTE_INSIGHT_INTENT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](js-apis-app-ability-insightIntentDriver.md#executeparam) | Yes| Parameter used to execute the InsightIntent call.|
  | callback | AsyncCallback<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Yes| Callback used to return the InsightIntent call execution result.|

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
  import insightIntentDriver from '@ohos.app.ability.insightIntentDriver';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import hilog from '@ohos.hilog';

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

Executes a call to an InsightIntent. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API and cannot be called by third-party applications.

**Required permissions**: ohos.permission.EXECUTE_INSIGHT_INTENT

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](js-apis-app-ability-insightIntentDriver.md#executeparam) | Yes| Parameter used to execute the InsightIntent call.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the InsightIntent call execution result.|

**Error codes**

| ID| Error Message|
| -------- | -------- |
| 16000001 | The specified ability does not exist. |
| 16000002 | Incorrect ability type. |
| 16000004 | Can not start invisible component. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation flag is forbidden. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |

For details about the error codes, see [Ability Error Codes](../errorcodes/errorcode-ability.md).

**Example**

```ts
  import insightIntentDriver from '@ohos.app.ability.insightIntentDriver';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import hilog from '@ohos.hilog';

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
