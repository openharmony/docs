# @ohos.app.ability.InsightIntentContext (InsightIntent Call Execution Context)

The **InsightIntentContext** module provides the InsightIntent call execution context, which is a property of the base class for InsightIntent call execution and provides basic capabilities for the base class.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { InsightIntentContext } from '@kit.AbilityKit';
```

## InsightIntentContext.startAbility

startAbility(want: Want, callback: AsyncCallback\<void\>): void

Starts an ability. The ability can be started only when it has the same bundle name as the base class for InsightIntent call execution. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result. If the ability is started, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000061 | Operation not supported. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import { InsightIntentExecutor, insightIntent, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
    onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>, pageLoader: window.WindowStage): insightIntent.ExecuteResult {
      let want: Want = {
        bundleName: 'com.ohos.intentexecutedemo',
        moduleName: 'entry',
        abilityName: 'AnotherAbility',
      };

      try {
        this.context.startAbility(want, (error) => {
          if (error) {
            hilog.error(0x0000, 'testTag', 'Start ability failed with %{public}s', JSON.stringify(error));
          } else {
            hilog.info(0x0000, 'testTag', '%{public}s', 'Start ability succeed');
          }
        })
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'Start ability error caught %{public}s', JSON.stringify(error));
      }

      let result: insightIntent.ExecuteResult = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      return result;
    }
  }
  ```

## InsightIntentContext.startAbility

startAbility(want: Want): Promise\<void\>

Starts an ability. The ability can be started only when it has the same bundle name as the base class for InsightIntent call execution. This API uses a promise to return the result.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Ability Error Codes](errorcode-ability.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Failed to start the invisible ability. |
| 16000005 | The specified process does not have the permission. |
| 16000006 | Cross-user operations are not allowed. |
| 16000008 | The crowdtesting application expires. |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000011 | The context does not exist.        |
| 16000012 | The application is controlled.        |
| 16000013 | The application is controlled by EDM.       |
| 16000050 | Internal error. |
| 16000053 | The ability is not on the top of the UI. |
| 16000055 | Installation-free timed out. |
| 16000061 | Operation not supported. |
| 16200001 | The caller has been released. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

  ```ts
  import { InsightIntentExecutor, insightIntent, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
    async onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>, pageLoader: window.WindowStage): Promise<insightIntent.ExecuteResult> {
      let want: Want = {
        bundleName: 'com.ohos.intentexecutedemo',
        moduleName: 'entry',
        abilityName: 'AnotherAbility',
      };

      try {
        await this.context.startAbility(want);
        hilog.info(0x0000, 'testTag', '%{public}s', 'Start ability finished');
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'Start ability error caught %{public}s', JSON.stringify(error));
      }

      let result: insightIntent.ExecuteResult = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      return result;
    }
  }
  ```
