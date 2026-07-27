# @ohos.app.ability.InsightIntentContext (意图执行上下文)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @linjunjie6-->
<!--Designer: @li-weifeng2024-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->

本模块提供意图执行上下文，是[意图执行基类](./js-apis-app-ability-insightIntentExecutor.md)和[@InsightIntentEntry的意图执行基类](./js-apis-app-ability-InsightIntentEntryExecutor.md)的属性，为意图执行提供基础能力，例如启动本应用内的[UIAbility](./js-apis-app-ability-uiAbility.md#uiability)组件。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { InsightIntentContext } from '@kit.AbilityKit';
```

## 属性

**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| instanceId<sup>23+</sup> | number | 否 | 否 | 意图实例唯一ID。用于通过[insightIntentProvider.sendExecuteResult接口](./js-apis-app-ability-insightIntentProvider.md#insightintentprovidersendexecuteresult)和[insightIntentProvider.sendIntentResult接口](./js-apis-app-ability-insightIntentProvider.md#insightintentprovidersendintentresult)返回指定意图的执行结果。|

**示例：**

  ```ts
  import { InsightIntentExecutor, insightIntent, insightIntentProvider } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class InsightIntentExecutorUI extends InsightIntentExecutor {
    onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>,
      pageLoader: window.WindowStage): insightIntent.ExecuteResult {
      hilog.info(0x0000, 'testTag', 'onExecuteInUIAbilityForegroundMode %{public}s', name);
      let result: insightIntent.ExecuteResult;
      result = {
        code: 0,
        result: {
          message: 'Unsupported insight intent.',
        },
      };
      try {
        // 通过意图实例唯一ID返回意图执行结果
        insightIntentProvider.sendExecuteResult(this.context.instanceId, result)
          .then(() => {
            console.info('testTag setExecuteResult success');
          })
          .catch((error: BusinessError) => {
            console.error(`Failed to setExecuteResult. Code: ${error.code}, message: ${error.message}`);
          });
      } catch (e) {
        let code = (e as BusinessError).code;
        let msg = (e as BusinessError).message;
        console.error(`testTag setExecuteResult fail2, error code: ${code}, error msg: ${msg}`);
      }
      return result;
    }
  }
  ```

## InsightIntentContext.startAbility

startAbility(want: Want, callback: AsyncCallback\<void\>): void

启动UIAbility组件，仅支持启动本应用内的UIAbility组件。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动UIAbility组件的want信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当接口调用成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
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

**示例：**

  ```ts
  import { InsightIntentExecutor, insightIntent, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
    onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>,
      pageLoader: window.WindowStage): insightIntent.ExecuteResult {
      let want: Want = {
        bundleName: 'com.ohos.intentExecuteDemo', // 此处仅为示例，开发者在实际使用中需替换为真实包名
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
        const err: BusinessError = error as BusinessError;
        console.error(`Failed to start ability. Code: ${err.code}, message: ${err.message}`);
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

启动UIAbility组件，仅支持启动本应用内的UIAbility组件。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动UIAbility组件的want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 16000001 | The specified ability does not exist. |
| 16000004 | Cannot start an invisible component. |
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

**示例：**

  ```ts
  import { InsightIntentExecutor, insightIntent, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  export default class IntentExecutorImpl extends InsightIntentExecutor {
    async onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>,
      pageLoader: window.WindowStage): Promise<insightIntent.ExecuteResult> {
      let want: Want = {
        bundleName: 'com.ohos.intentExecuteDemo', // 此处仅为示例，开发者在实际使用中需替换为真实包名
        moduleName: 'entry',
        abilityName: 'AnotherAbility',
      };

      try {
        await this.context.startAbility(want);
        hilog.info(0x0000, 'testTag', '%{public}s', 'Start ability finished');
      } catch (error) {
        const err: BusinessError = error as BusinessError;
        console.error(`Failed to start ability. Code: ${err.code}, message: ${err.message}`);
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

## InsightIntentContext.setReturnModeForUIAbilityForeground<sup>23+</sup>

setReturnModeForUIAbilityForeground(returnMode: insightIntent.ReturnMode): void

设置意图执行结果的返回形式，适用于执行模式为[UI_ABILITY_FOREGROUND](./js-apis-app-ability-insightIntent.md#executemode)的意图。

**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| returnMode | [insightIntent.ReturnMode](./js-apis-app-ability-insightIntent.md#returnmode23) | 是 | 意图执行结果的返回形式。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16000011      | The context does not exist. Possible causes: 1.The context is not insightIntentContext; 2.The context is not for UIAbility foreground insight intent execute mode. |

**示例：**

  ```ts
  import { InsightIntentExecutor, insightIntent } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class InsightIntentExecutorUI extends InsightIntentExecutor {
    onExecuteInUIAbilityForegroundMode(name: string, param: Record<string, Object>,
      pageLoader: window.WindowStage): insightIntent.ExecuteResult {
      hilog.info(0x0000, 'testTag', 'onExecuteInUIAbilityForegroundMode %{public}s', name);
      let result: insightIntent.ExecuteResult;
      result = {
        code: 0,
        result: {
          message: 'Unsupported insight intent.',
        },
      };

      try {
        this.context.setReturnModeForUIAbilityForeground(insightIntent.ReturnMode.FUNCTION);
      } catch (error) {
        const err: BusinessError = error as BusinessError;
        console.error(`Failed to setReturnModeForUIAbilityForeground. Code: ${err.code}, message: ${err.message}`);
      }

      let localStorageData: Record<string, number> = {
        'insightId': this.context.instanceId,
      };
      let storage: LocalStorage = new LocalStorage(localStorageData);
      pageLoader.loadContent('pages/UIAbilityIndex', storage, (err, data) => {
        if (err.code) {
          hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err));
        } else {
          hilog.info(0x0000, 'testTag', '%{public}s', 'Succeeded in loading the content');
        }
      });
      return result;
    }
  }
  ```

## InsightIntentContext.setReturnModeForUIExtensionAbility<sup>23+</sup>

setReturnModeForUIExtensionAbility(returnMode: insightIntent.ReturnMode): void

设置意图执行结果的返回形式，适用于执行模式为[UI_EXTENSION_ABILITY](./js-apis-app-ability-insightIntent.md#executemode)的意图。

**模型约束**：此接口仅可在Stage模型下使用。

**原子化服务API**：从API version 23开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| returnMode | [insightIntent.ReturnMode](./js-apis-app-ability-insightIntent.md#returnmode23) | 是 | 意图执行结果的返回形式。 |

**错误码：**

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16000011      | The context does not exist. Possible causes: 1.The context is not insightIntentContext; 2.The context is not for UIExtensionAbility insight intent execute mode. |

**示例：**

  ```ts
  import { InsightIntentExecutor, insightIntent, UIExtensionContentSession } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  export default class InsightIntentExecutorUI extends InsightIntentExecutor {
    onExecuteInUIExtensionAbility(name: string, param: Record<string, Object>,
      pageLoader: UIExtensionContentSession): insightIntent.ExecuteResult {
      hilog.info(0x0000, 'testTag', 'onExecuteInUIExtensionAbility %{public}s', name);
      let result: insightIntent.ExecuteResult;
      result = {
        code: 0,
        result: {
          message: 'Unsupported insight intent.',
        },
      };
      try {
        this.context.setReturnModeForUIExtensionAbility(insightIntent.ReturnMode.FUNCTION)
      } catch (error) {
        let code = (error as BusinessError).code;
        let msg = (error as BusinessError).message;
        console.error(`testTag setReturnModeForUIExtensionAbility fail, error code: ${code}, error msg: ${msg}.`);
      }

      try {
        let localStorageData: Record<string, number> = {
          'insightId': this.context.instanceId,
        };
        let storage: LocalStorage = new LocalStorage(localStorageData);
        storage.setOrCreate('session', pageLoader);
        pageLoader.loadContent('pages/UIExtensionPage', storage);
      } catch (err) {
        const err: BusinessError = err as BusinessError;
        console.error(`Failed to loadContent. Code: ${err.code}, message: ${err.message}`);
      }
      return result;
    }
  }
  ```