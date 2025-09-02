# @ohos.app.ability.abilityManager (Ability信息管理)

AbilityManager模块提供获取Ability相关信息和运行状态信息的能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```ts
import { abilityManager } from '@kit.AbilityKit';
```

## AbilityState<sup>14+</sup>

Ability的状态，该类型为枚举，可配合[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)返回Ability的状态。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 | 
| -------- | -------- | -------- |
| INITIAL | 0 | 表示ability为初始化状态。| 
| FOCUS | 2 | 表示ability为获焦状态。 |
| FOREGROUND | 9 | 表示ability为前台状态。  | 
| BACKGROUND | 10 | 表示ability为后台状态。  | 
| FOREGROUNDING | 11 | 表示ability为前台调度中状态。  | 
| BACKGROUNDING | 12 | 表示ability为后台调度中状态。  | 


## abilityManager.getAbilityRunningInfos<sup>14+</sup>

getAbilityRunningInfos(): Promise\<Array\<AbilityRunningInfo>>

获取UIAbility运行相关信息（Promise形式）。

**需要权限**：ohos.permission.GET_RUNNING_INFO

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| Promise\<Array\<[AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md)>> | 以Promise方式返回接口运行结果及运行中的ability信息，可进行错误处理或其他自定义处理。 |

**错误码**：

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000050 | Internal error. |

**示例**：

```ts
import { abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  abilityManager.getAbilityRunningInfos()
    .then((data: abilityManager.AbilityRunningInfo[]) => {
      console.log(`getAbilityRunningInfos success, data: ${JSON.stringify(data)}`);
    })
    .catch((error: BusinessError) => {
      console.error(`getAbilityRunningInfos fail, error code: ${JSON.stringify(error.code)}, error msg: ${JSON.stringify(error.message)}`);
    })
} catch (e) {
  let code = (e as BusinessError).code;
  let msg = (e as BusinessError).message;
  console.error(`getAbilityRunningInfos fail, error code: ${JSON.stringify(code)}, error msg: ${JSON.stringify(msg)}`);
}
```

## abilityManager.restartSelfAtomicService<sup>20+</sup>

restartSelfAtomicService(context: Context): void

重启当前原子化服务。

> **说明：**
>
> - 当前仅支持以独立窗口方式拉起原子化服务。
>
> - 该接口的两次调用时间间隔不能低于3秒。

**模型约束**：此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**参数**：

| 参数名        | 类型                                       | 必填   | 说明             |
| --------- | ---------------------------------------- | ---- | -------------- |
| context    | [Context](./js-apis-inner-application-context.md)   | 是    | 当前Ability的上下文。<br>**说明**：当前仅支持[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)。</br> |

**错误码**：

以下错误码详细介绍请参考[元能力子系统错误码](errorcode-ability.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 16000050 | Internal error. Possible causes: 1. Connect to system service failed; 2.Send restart message to system service failed; 3.System service failed to communicate with dependency module.|
| 16000053 | The ability is not on the top of the UI. |
| 16000064 | Restart too frequently. Try again at least 3s later. |
| 16000086 | The context is not UIAbilityContext. |
| 16000090 | The caller is not an atomic service. |

**示例**：

```ts
import { AbilityConstant, EmbeddableUIAbility, Want, abilityManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

export default class EntryAbility extends EmbeddableUIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    try {
      abilityManager.restartSelfAtomicService(this.context);
    } catch (e) {
      console.error(`restartSelfAtomicService error: ${JSON.stringify(e as BusinessError)}`);
    }
  }
}
```

## AbilityRunningInfo<sup>14+</sup>

type AbilityRunningInfo = _AbilityRunningInfo

AbilityRunningInfo二级模块。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityRunningInfo](js-apis-inner-application-abilityRunningInfo.md) | AbilityRunningInfo二级模块，提供对Ability运行的相关信息和状态的定义。 |

## AbilityStateData<sup>14+</sup>

type AbilityStateData = _AbilityStateData.default

AbilityStateData二级模块。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 类型 | 说明 |
| --- | --- |
| [_AbilityStateData.default](js-apis-inner-application-abilityStateData.md) | AbilityStateData二级模块，提供Ability状态信息。 |
