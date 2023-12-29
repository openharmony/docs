# @ohos.app.ability.InsightIntentExecutor (Base Class for InsightIntent Call Execution)

The **InsightIntentExecutor** module provides the base class for InsightIntent call execution. Through this base class, you can access the InsightIntent framework on the device side. You need to implement the service logic to respond to InsightIntent calls. To access the InsightIntent framework, you need to declare the InsightIntent name and InsightIntent access mode in the InsightIntent configuration file. The system calls the InsightIntent based on the user interaction and InsightIntent configuration file and triggers the corresponding InsightIntent call execution callback.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import InsightIntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
```

## Attributes

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [InsightIntentContext](js-apis-app-ability-insightIntentContext.md) | Yes| No| InsightIntent call execution context.|

## InsightIntentExecutor.onExecuteInUIAbilityForegroundMode

onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>, pageLoader: window.WindowStage):
  insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the InsightIntent call displays a UIAbility in the foreground. Both synchronous calls and asynchronous calls using Promise are supported.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| InsightIntent name.|
| param | Record<string, Object> | Yes| InsightIntent call parameter.|
| pageLoader | [window.WindowStage](js-apis-window.md#windowstage9) | Yes| Page loader.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | InsightIntent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the InsightIntent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import window from '@ohos.window';
  import hilog from '@ohos.hilog';

  export default class IntentExecutorImpl extends IntentExecutor {
    onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>, pageLoader: window.WindowStage): insightIntent.ExecuteResult {
      let result: insightIntent.ExecuteResult;
      if (name !== 'SupportedInsightIntentName') {
        hilog.warn(0x0000, 'testTag', 'Unsupported insight intent %{public}s', name);
        result = {
          // decided by developer
          code: 404,
          result: {
            message: 'Unsupported insight intent.',
          }
        };
        return result;
      }

      // if developer need load content
      pageLoader.loadContent('pages/Index', (err, data) => {
        if (err.code) {
          hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        } else {
          hilog.info(0x0000, 'testTag', '%{public}s', 'Succeeded in loading the content');
        }
      });

      result = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      return result;
    }
  }
  ```

The code snippet below shows the promise-based asynchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import window from '@ohos.window';
  import hilog from '@ohos.hilog';

  async function executeInsightIntent(param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
    return new Promise((resolve, reject) => {
      let result: insightIntent.ExecuteResult = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      resolve(result);
    })
  }

  export default class IntentExecutorImpl extends IntentExecutor {
    async onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>, pageLoader: window.WindowStage): Promise<insightIntent.ExecuteResult> {
      let result: insightIntent.ExecuteResult;
      if (name !== 'SupportedInsightIntentName') {
        hilog.warn(0x0000, 'testTag', 'Unsupported insight intent %{public}s', name);
        result = {
          // decided by developer
          code: 404,
          result: {
            message: 'Unsupported insight intent.',
          }
        };
        return result;
      }

      result = await executeInsightIntent(param);
      return result;
    }
  }
  ```

## InsightIntentExecutor.onExecuteInUIAbilityBackgroundMode

onExecuteInUIAbilityBackgroundMode(name: string, param: Record<string, Object>):
    insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the InsightIntent call displays a UIAbility in the background. Both synchronous calls and asynchronous calls using Promise are supported.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| InsightIntent name.|
| param | Record<string, Object> | Yes| InsightIntent call parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | InsightIntent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the InsightIntent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';

  export default class IntentExecutorImpl extends IntentExecutor {
    onExecuteInUIAbilityBackgroundMode(name: string, param: Record<string, Object>): insightIntent.ExecuteResult {
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

The code snippet below shows the promise-based asynchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';

  async function executeInsightIntent(param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
    return new Promise((resolve, reject) => {
      let result: insightIntent.ExecuteResult = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      resolve(result);
    })
  }

  export default class IntentExecutorImpl extends IntentExecutor {
    async onExecuteInUIAbilityBackgroundMode(name: string, param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
      let result: insightIntent.ExecuteResult = await executeInsightIntent(param);
      return result;
    }
  }
  ```

## InsightIntentExecutor.onExecuteInUIExtensionAbility

onExecuteInUIExtensionAbility(name: string, param: Record<string, Object>, pageLoader: UIExtensionContentSession):
  insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the InsightIntent call starts a UIExtensionAbility. Both synchronous calls and asynchronous calls using Promise are supported.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| InsightIntent name.|
| param | Record<string, Object> | Yes| InsightIntent call parameter.|
| pageLoader | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| Page loader.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | InsightIntent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the InsightIntent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import hilog from '@ohos.hilog';

  export default class IntentExecutorImpl extends IntentExecutor {
    onExecuteInUIExtensionAbility(name: string, param: Record<string, Object>, pageLoader: UIExtensionContentSession): insightIntent.ExecuteResult {
      let result: insightIntent.ExecuteResult;
      if (name !== 'SupportedInsightIntentName') {
        hilog.warn(0x0000, 'testTag', 'Unsupported insight intent %{public}s', name);
        result = {
          // decided by developer
          code: 404,
          result: {
            message: 'Unsupported insight intent.',
          }
        };
        return result;
      }

      // if developer need load content
      pageLoader.loadContent('pages/Index');

      result = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      return result;
    }
  }
  ```

The code snippet below shows the promise-based asynchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import UIExtensionContentSession from '@ohos.app.ability.UIExtensionContentSession';
  import hilog from '@ohos.hilog';

  async function executeInsightIntent(param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
    return new Promise((resolve, reject) => {
      let result: insightIntent.ExecuteResult = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      resolve(result);
    })
  }

  export default class IntentExecutorImpl extends IntentExecutor {
    async onExecuteInUIExtensionAbility(name: string, param: Record<string, Object>, pageLoader: UIExtensionContentSession): Promise<insightIntent.ExecuteResult> {
      let result: insightIntent.ExecuteResult;
      if (name !== 'SupportedInsightIntentName') {
        hilog.warn(0x0000, 'testTag', 'Unsupported insight intent %{public}s', name);
        result = {
          // decided by developer
          code: 404,
          result: {
            message: 'Unsupported insight intent.',
          }
        };
        return result;
      }

      result = await executeInsightIntent(param);
      return result;
    }
  }
  ```

## InsightIntentExecutor.onExecuteInServiceExtensionAbility

onExecuteInServiceExtensionAbility(name: string, param: Record<string, Object>):
    insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the InsightIntent call starts a ServiceExtensionAbility. Both synchronous calls and asynchronous calls using Promise are supported.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| InsightIntent name.|
| param | Record<string, Object> | Yes| InsightIntent call parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | InsightIntent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the InsightIntent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';

  export default class IntentExecutorImpl extends IntentExecutor {
    onExecuteInServiceExtensionAbility(name: string, param: Record<string, Object>): insightIntent.ExecuteResult {
      let result: insightIntent.ExecuteResult;
      if (name !== 'SupportedInsightIntentName') {
        hilog.warn(0x0000, 'testTag', 'Unsupported insight intent %{public}s', name);
        result = {
          // decided by developer
          code: 404,
          result: {
            message: 'Unsupported insight intent.',
          }
        };
        return result;
      }

      result = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      return result;
    }
  }
  ```

The code snippet below shows the promise-based asynchronous call that returns the InsightIntent call result:
  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import insightIntent from '@ohos.app.ability.insightIntent';

  async function executeInsightIntent(param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
    return new Promise((resolve, reject) => {
      let result: insightIntent.ExecuteResult = {
        code: 0,
        result: {
          message: 'Execute insight intent succeed.',
        }
      };
      resolve(result);
    });
  }

  export default class IntentExecutorImpl extends IntentExecutor {
    async onExecuteInServiceExtensionAbility(name: string, param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
      let result: insightIntent.ExecuteResult;
      if (name !== 'SupportedInsightIntentName') {
        hilog.warn(0x0000, 'testTag', 'Unsupported insight intent %{public}s', name);
        result = {
          // decided by developer
          code: 404,
          result: {
            message: 'Unsupported insight intent.',
          }
        };
        return result;
      }

      result = await executeInsightIntent(param);
      return result;
    }
  }
  ```
