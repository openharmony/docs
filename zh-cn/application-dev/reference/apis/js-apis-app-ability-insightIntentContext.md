# @ohos.app.ability.InsightIntentContext (意图调用执行上下文)

本模块提供意图调用执行上下文，意图调用执行上下文是意图调用执行基类的属性，为意图调用执行基类提供基础能力。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import InsightIntentContext from '@ohos.app.ability.InsightIntentContext';
```

## InsightIntentContext.startAbility

startAbility(want: Want, callback: AsyncCallback<void>): void

启动Ability，仅当Ability与意图调用执行基类具有相同包名才能被拉起。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当启动Ability成功，err为undefined，否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
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
| 16000061 | Can not start component belongs to other bundle. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import IntentContext from '@ohos.app.ability.InsightIntentContext';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import window from '@ohos.window';
  import Want from '@ohos.app.ability.Want';
  import hilog from '@ohos.hilog';

  export default class IntentExecutorImpl extends IntentExecutor {
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

startAbility(want: Want): Promise<void>

启动Ability，仅当Ability与意图调用执行基类具有相同包名才能被拉起。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | 启动Ability的want信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息 |
| -------- | -------- |
| 16000001 | The specified ability does not exist. |
| 16000004 | Can not start invisible component. |
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
| 16000061 | Can not start component belongs to other bundle. |
| 16200001 | The caller has been released. |

以上错误码详细介绍请参考[元能力子系统错误码](../errorcodes/errorcode-ability.md)。

**示例：**

  ```ts
  import IntentExecutor from '@ohos.app.ability.InsightIntentExecutor';
  import IntentContext from '@ohos.app.ability.InsightIntentContext';
  import insightIntent from '@ohos.app.ability.insightIntent';
  import window from '@ohos.window';
  import Want from '@ohos.app.ability.Want';
  import hilog from '@ohos.hilog';

  export default class IntentExecutorImpl extends IntentExecutor {
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
