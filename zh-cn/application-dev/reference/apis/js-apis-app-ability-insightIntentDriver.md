# @ohos.app.ability.insightIntentDriver (执行意图调用)

本模块提供执行意图调用的能力，系统根据用户交互等信息执行意图调用。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import insightIntentDriver from '@ohos.app.ability.insightIntentDriver';
```

## ExecuteParam

执行意图调用的参数。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**: 此接口为系统接口，三方应用不支持调用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| bundleName | string | 是 | 意图调用Ability所属的应用名称。 |
| moduleName | string | 是 | 意图调用Ability所属的模块名称。 |
| abilityName | string | 是 | 意图调用Ability名称。 |
| insightIntentName | string | 是 | 意图调用名称。 |
| insightIntentParam | string | 是 | 意图调用参数。 |
| executeMode | [insightIntent.ExecuteMode](js-apis-app-ability-insightIntent.md#executemode) | 是 | 意图调用执行模式。 |

## insightIntentDriver.execute

execute(param: ExecuteParam, callback: AsyncCallback<insightIntent.ExecuteResult>): void

执行意图调用的接口。使用callback异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**: 此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.EXECUTE_INSIGHT_INTENT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](js-apis-app-ability-insightIntentDriver.md#executeparam) | 是 | 执行意图调用的参数。 |
  | callback | AsyncCallback<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | 是 | 回调函数，返回意图调用执行结果。 |

**错误码**：

| 错误码ID | 错误信息 |
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

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

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

执行意图调用的接口。使用Promise异步回调。

**模型约束**：此接口仅可在Stage模型下使用。

**系统接口**: 此接口为系统接口，三方应用不支持调用。

**需要权限**: ohos.permission.EXECUTE_INSIGHT_INTENT

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | param | [ExecuteParam](js-apis-app-ability-insightIntentDriver.md#executeparam) | 是 | 执行意图调用的参数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise<[insightIntent.ExecuteResult](js-apis-app-ability-insightIntent.md#executeresult)> | Promise对象，返回意图调用执行结果。 |

**错误码**：

| 错误码ID | 错误信息 |
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

以上错误码详细介绍请参考[errcode-ability](../errorcodes/errorcode-ability.md)。

**示例：**

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
