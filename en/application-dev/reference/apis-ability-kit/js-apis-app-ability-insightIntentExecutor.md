# @ohos.app.ability.InsightIntentExecutor (Base Class for Intent Call Execution)

The module provides the base class for intent call execution. Through this base class, you can access the InsightIntent framework on the device side. You need to implement the service logic to respond to intent calls. To access the InsightIntent framework, you need to declare the intent name and intent access mode in the intent configuration file. The system calls the intent based on the user interaction and intent configuration file and triggers the corresponding intent call execution callback.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { InsightIntentExecutor } from '@kit.AbilityKit';
```

## InsightIntentExecutor

Base class for intent call execution.

### Properties

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [InsightIntentContext](js-apis-app-ability-insightIntentContext.md) | No| No| Intent call execution context.|

### onExecuteInUIAbilityForegroundMode

onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>, pageLoader: window.WindowStage):
  insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the intent is to bring the UIAbility to the foreground. Both synchronous calls and asynchronous calls using Promise are supported.

- If the UIAbility is cold started, the UIAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onWindowStageCreate**, **onExecuteInUIAbilityForegroundMode**, and **onForeground**.
- If the UIAbility is hot started in the background, the UIAbility lifecycle callbacks are triggered in the following sequence: **onNewWant**, **onExecuteInUIAbilityForegroundMode**, and **onForeground**.
- If the UIAbility is hot started in the foreground, the UIAbility lifecycle callbacks are triggered in the following sequence: **onExecuteInUIAbilityForegroundMode**.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Intent name.|
| param | Record<string, Object> | Yes| Intent call parameter.|
| pageLoader | [window.WindowStage](../apis-arkui/arkts-apis-window-WindowStage.md) | Yes| Page loader.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | Intent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the intent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
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

The code snippet below shows the promise-based asynchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';

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

  export default class IntentExecutorImpl extends InsightIntentExecutor {
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

### onExecuteInUIAbilityBackgroundMode

onExecuteInUIAbilityBackgroundMode(name: string, param: Record<string, Object>):
    insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the intent is to bring the UIAbility to the background. Both synchronous calls and asynchronous calls using Promise are supported.

- If the UIAbility is cold started, the UIAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onExecuteInUIAbilityBackgroundMode**, and **onBackground**.
- If the UIAbility is hot started, the UIAbility lifecycle callbacks are triggered in the following sequence: **onExecuteInUIAbilityBackgroundMode**.

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Intent name.|
| param | Record<string, Object> | Yes| Intent call parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | Intent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the intent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
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

The code snippet below shows the promise-based asynchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';

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

  export default class IntentExecutorImpl extends InsightIntentExecutor {
    async onExecuteInUIAbilityBackgroundMode(name: string, param: Record<string, Object>): Promise<insightIntent.ExecuteResult> {
      let result: insightIntent.ExecuteResult = await executeInsightIntent(param);
      return result;
    }
  }
  ```

### onExecuteInUIExtensionAbility

onExecuteInUIExtensionAbility(name: string, param: Record<string, Object>, pageLoader: UIExtensionContentSession):
  insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the intent call starts a UIExtensionAbility. Both synchronous calls and asynchronous calls using Promise are supported.

When an intent is called, the UIExtensionAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onSessionCreate**, **onExecuteInUIExtensionAbility**, and **onForeground**.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Intent name.|
| param | Record<string, Object> | Yes| Intent call parameter.|
| pageLoader | [UIExtensionContentSession](js-apis-app-ability-uiExtensionContentSession.md) | Yes| Page loader.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | Intent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the intent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent, UIExtensionContentSession } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
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

The code snippet below shows the promise-based asynchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent, UIExtensionContentSession } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

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

  export default class IntentExecutorImpl extends InsightIntentExecutor {
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

### onExecuteInServiceExtensionAbility

onExecuteInServiceExtensionAbility(name: string, param: Record<string, Object>):
    insightIntent.ExecuteResult | Promise<insightIntent.ExecuteResult>

Called when the intent call starts a ServiceExtensionAbility. Both synchronous calls and asynchronous calls using Promise are supported.

When an intent is called, the ServiceExtensionAbility lifecycle callbacks are triggered in the following sequence: **onCreate**, **onRequest**, and **onExecuteInServiceExtensionAbility**.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Intent name.|
| param | Record<string, Object> | Yes| Intent call parameter.|

**Return value**

| Type| Description|
| -------- | -------- |
| [insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult) | Intent call execution result.|
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise used to return the intent call execution result.|

**Example**

The code snippet below shows the synchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
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

The code snippet below shows the promise-based asynchronous call that returns the intent call result:
  ```ts
  import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

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

  export default class IntentExecutorImpl extends InsightIntentExecutor {
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
