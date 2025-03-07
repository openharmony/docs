# @ohos.app.ability.AbilityConstant (AbilityConstant)

AbilityConstant提供UIAbility相关的枚举，包括设置初次启动原因、上次退出原因、迁移结果、窗口类型等。

> **说明：**
> 
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { AbilityConstant } from '@kit.AbilityKit';
```

## LaunchParam

启动参数。Ability启动时由系统自动传入，开发者无需修改。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| launchReason | [LaunchReason](#launchreason)| 否 | 否 | 枚举类型，表示启动原因。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| launchReasonMessage<sup>16+</sup> | string | 否 | 是 | 表示启动的详细原因。<br>**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。 |
| lastExitReason | [LastExitReason](#lastexitreason) | 否 | 否 | 枚举类型，表示最后退出原因。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| lastExitMessage<sup>12+</sup> | string | 否 | 否 | 表示最后退出详细原因。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。 |
| lastExitDetailInfo<sup>16+</sup> | [LastExitDetailInfo](#lastexitdetailinfo16) | 否 | 是 | 表示最后退出时的进程状态和详细原因。<br>**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。 |

## LaunchReason

Ability初次启动原因，该类型为枚举，可配合UIAbility的[onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate)方法根据launchParam.launchReason的不同类型执行相应操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知原因。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| START_ABILITY          | 1    | 通过[startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口启动Ability。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| CALL | 2    | 通过[startAbilityByCall](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybycall)接口启动Ability。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| CONTINUATION           | 3    | 跨端迁移启动Ability。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| APP_RECOVERY           | 4    | 设置应用恢复后，应用故障时自动恢复启动Ability。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| SHARE<sup>10+</sup>           | 5    | 通过原子化服务分享启动Ability。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| AUTO_STARTUP<sup>11+</sup>           | 8    | 通过设置开机自启动来启动Ability。 |
| INSIGHT_INTENT<sup>11+</sup>           | 9    | 通过洞察意图来启动Ability。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| PREPARE_CONTINUATION<sup>12+</sup>           | 10    | 跨端迁移提前启动Ability。<br>**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。|

**示例：**

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    if (launchParam.launchReason === AbilityConstant.LaunchReason.START_ABILITY) {
      console.log('The ability has been started by the way of startAbility.');
    }
  }
}
```

## LastExitReason

Ability上次退出原因，该类型为枚举，可配合UIAbility的[onCreate(want, launchParam)](js-apis-app-ability-uiAbility.md#uiabilityoncreate)方法根据launchParam.lastExitReason的不同类型执行相应操作。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| UNKNOWN          | 0    | 未知原因。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| ABILITY_NOT_RESPONDING<sup>(deprecated)</sup> | 1    | ability未响应。<br>**说明:** 从API version 9开始支持，从API version 10开始废弃，请使用APP_FREEZE替代。|
| NORMAL | 2    | 用户主动关闭，应用程序正常退出。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| CPP_CRASH<sup>10+</sup>  | 3    | 本机异常信号，导致应用程序退出。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| JS_ERROR<sup>10+</sup>  | 4    | 当应用存在JS语法错误并未被开发者捕获时，触发JS_ERROR故障，导致应用程序退出。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| APP_FREEZE<sup>10+</sup>  | 5    | 由于watchdog检测出应用Freeze故障，导致应用程序退出。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| PERFORMANCE_CONTROL<sup>10+</sup>  | 6    | 由于系统性能问题（如设备内存不足），导致应用程序退出。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。<br>**说明**：该接口即将废弃，建议使用RESOURCE_CONTROL替代。 |
| RESOURCE_CONTROL<sup>10+</sup>  | 7    | 系统资源使用不当，导致应用程序退出。具体错误原因可以通过[LaunchParam.lastExitMessage](#launchparam)获取，可能原因如下: <br> - CPU Highload，CPU高负载。<br> - CPU_EXT Highload，快速CPU负载检测。<br> - IO Manage Control，I/O管控。<br> - App Memory Deterioration，应用内存超限劣化。<br> - Temperature Control，温度管控。<br> - Memory Pressure，整机低内存触发按优先级由低到高查杀。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。|
| UPGRADE<sup>10+</sup>  | 8    | 应用程序因升级而退出。<br>**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| USER_REQUEST<sup>16+</sup>  | 9    | 应用程序因多任务中心请求而退出，例如用户在多任务管理界面执行上划、一键清理等操作。<br>**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。 |
| SIGNAL<sup>16+</sup>  | 10    | 应用程序因收到系统kill指令信号而退出。<br>**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。 |

**示例：**

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    if (launchParam.lastExitReason === AbilityConstant.LastExitReason.APP_FREEZE) {
      console.log('The ability has exit last because the ability was not responding.');
    }
    if (launchParam.lastExitReason === AbilityConstant.LastExitReason.RESOURCE_CONTROL) {
      console.log('The ability has exit last because the rss control，the lastExitReason is '+  launchParam.lastExitReason + ', the lastExitMessage is ' + launchParam.lastExitMessage);
    }
  }
}
```

## LastExitDetailInfo<sup>16+</sup>

记录Ability所在进程上次退出的详细信息。<br>**原子化服务API**：从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 否 | 否 | Ability上次退出所在进程的进程号。 |
| processName | string | 否 | 否 | Ability上次退出所在进程的名称。 |
| uid | number | 否 | 否 | Ability上次退出所在应用的UID。 |
| exitSubReason | number | 否 | 否 | Ability上次退出的子原因。 |
| exitMsg | string | 否 | 否 | Ability上次退出时所在进程被kill的描述信息。 |
| rss | number | 否 | 否 | Ability上次退出时所在进程的rss值。 |
| pss | number | 否 | 否 | Ability上次退出时所在进程的pss值。 |
| timestamp | number | 否 | 否 | Ability上次退出时的时间戳。 |

**示例**:

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    if (launchParam.lastExitDetailInfo) {
      console.log('pid: ' + launchParam.lastExitDetailInfo.pid +
        '\n processName: ' + launchParam.lastExitDetailInfo.processName +
        '\n uid: ' + launchParam.lastExitDetailInfo.uid +
        '\n exitSubReason: ' + launchParam.lastExitDetailInfo.exitSubReason +
        '\n exitMsg: ' + launchParam.lastExitDetailInfo.exitMsg +
        '\n rss: ' + launchParam.lastExitDetailInfo.rss +
        '\n pss: ' + launchParam.lastExitDetailInfo.pss +
        '\n timestamp: ' + launchParam.lastExitDetailInfo.timestamp
      );
    }
  }
}
```

## OnContinueResult 

Ability迁移结果，该类型为枚举，可配合UIAbility的[onContinue(wantParam)](js-apis-app-ability-uiAbility.md#uiabilityoncontinue)方法进完成相应的返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| AGREE           | 0    | 表示同意。 |
| REJECT           | 1    | 表示拒绝：如应用在[onContinue](js-apis-app-ability-uiAbility.md#uiabilityoncontinue)中异常会导致迁移以后数据恢复时显示异常，则可以建议REJECT。 |
| MISMATCH  | 2    | 表示版本不匹配：迁移发起端应用可以在[onContinue](js-apis-app-ability-uiAbility.md#uiabilityoncontinue)中获取到迁移目标端应用的版本号，进行协商后，如果版本不匹配导致无法迁移，可以返回该错误。|

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onContinue(wantParam: Record<string, Object>) {
    return AbilityConstant.OnContinueResult.AGREE;
  }
}
```

## MemoryLevel

内存级别，该类型为枚举，可配合UIAbility的[onMemoryLevel(level)](js-apis-app-ability-ability.md#abilityonmemorylevel)方法根据level执行不同内存级别的相应操作。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                         | 值 | 说明                |
| ---                         | --- | ---           |
| MEMORY_LEVEL_MODERATE       | 0   | 内存占用适中。 |
| MEMORY_LEVEL_LOW            | 1   | 内存占用低。   |
| MEMORY_LEVEL_CRITICAL       | 2   | 内存占用高。   |

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onMemoryLevel(level: AbilityConstant.MemoryLevel) {
    if (level === AbilityConstant.MemoryLevel.MEMORY_LEVEL_CRITICAL) {
      console.log('The memory of device is critical, please release some memory.');
    }
  }
}
```

## WindowMode<sup>12+</sup>

启动Ability时的窗口模式，类型为枚举。可配合[startAbility](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)使用，指定启动Ability的窗口模式。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                        | 值 | 说明                 |
| ---                         | --- | ---                  |
| WINDOW_MODE_FULLSCREEN      | 1   | 全屏模式。仅在2in1和tablet设备上生效。  |
| WINDOW_MODE_SPLIT_PRIMARY   | 100 | 支持应用内拉起Ability时设置为分屏，左侧分屏。仅在折叠屏和tablet设备上生效。   |
| WINDOW_MODE_SPLIT_SECONDARY | 101 | 支持应用内拉起Ability时设置为分屏，右侧分屏。仅在折叠屏和tablet设备上生效。   |

**示例：**

```ts
import { UIAbility, StartOptions, Want, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let want: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
let option: StartOptions = {
  windowMode: AbilityConstant.WindowMode.WINDOW_MODE_SPLIT_PRIMARY
};

// 确保从上下文获取到context
class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.startAbility(want, option).then(() => {
      console.log('Succeed to start ability.');
    }).catch((error: BusinessError) => {
      console.error(`Failed to start ability with error: ${JSON.stringify(error)}`);
    });
  }
}
```

## OnSaveResult

保存应用数据的结果，该类型为枚举，可配合UIAbility的[onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate)方法完成相应的返回。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| ALL_AGREE           | 0    | 总是同意保存状态。 |
| CONTINUATION_REJECT           | 1    | 拒绝迁移保存状态。 |
| CONTINUATION_MISMATCH  | 2    | 迁移不匹配。|
| RECOVERY_AGREE           | 3    | 同意恢复保存状态。 |
| RECOVERY_REJECT  | 4    | 拒绝恢复保存状态。|
| ALL_REJECT  | 5    | 总是拒绝保存状态。|

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {
    return AbilityConstant.OnSaveResult.ALL_AGREE;
  }
}
```

## StateType

保存应用数据场景原因，该类型为枚举，可配合UIAbility的[onSaveState(reason, wantParam)](js-apis-app-ability-uiAbility.md#uiabilityonsavestate)方法根据reason的不同类型执行相应操作。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称                          | 值   | 说明                                                         |
| ----------------------------- | ---- | ------------------------------------------------------------ |
| CONTINUATION           | 0    | 迁移保存状态。 |
| APP_RECOVERY           | 1    | 应用恢复保存状态。 |

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onSaveState(reason: AbilityConstant.StateType, wantParam: Record<string, Object>) {
    if (reason === AbilityConstant.StateType.CONTINUATION) {
      console.log('Save the ability data when the ability continuation.');
    }
    return AbilityConstant.OnSaveResult.ALL_AGREE;
  }
}
```

## ContinueState<sup>10+</sup>

流转状态枚举值。用于表示当前应用任务流转的状态。可配合[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)的[setMissionContinueState](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissioncontinuestate10)方法进行设置。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称           | 值       | 说明                                                         |
| ------------- | --------- | ------------------------------------------------------------ |
| ACTIVE        | 0         | 指示当前应用任务流转处于激活状态。                              |
| INACTIVE      | 1         | 指示当前应用任务流转处于未激活状态。                            |

**示例：**

```ts
import { UIAbility, Want, AbilityConstant } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

class MyAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    this.context.setMissionContinueState(AbilityConstant.ContinueState.INACTIVE, (result: BusinessError) => {
      console.info(`setMissionContinueState: ${JSON.stringify(result)}`);
    });
  }
}
```

## CollaborateResult<sup>16+</sup>

协同状态枚举值，用于表示多设备场景下，调用方应用拉起协同方应用时，协同方应用是否接受协同。配合UIAbility的[onCollaborate(wantParam)](js-apis-app-ability-uiAbility.md#uiabilityoncollaborate16)方法进行设置。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称     | 值   | 说明       |
| -------- | ---- | ---------- |
| ACCEPT   | 0    | 接受协同。 |
| REJECT   | 1    | 拒绝协同。 |

**示例：**

```ts
import { UIAbility, AbilityConstant } from '@kit.AbilityKit';

class MyAbility extends UIAbility {
  onCollaborate(wantParam: Record<string, Object>) {
    return AbilityConstant.CollaborateResult.ACCEPT;
  }
}
```

## PrepareTermination<sup>15+</sup>

应用被用户关闭时的动作枚举值，需要配合[AbilityStage](js-apis-app-ability-abilityStage.md)的[onPrepareTermination](js-apis-app-ability-abilityStage.md#abilitystageonpreparetermination15)或者[onPrepareTerminationAsync](js-apis-app-ability-abilityStage.md#abilitystageonprepareterminationasync15)方法使用。

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 值 | 说明 |
| ------------- | --------- | ----------- |
| TERMINATE_IMMEDIATELY | 0 | 表示立即执行结束动作，默认值。|
| CANCEL | 1 | 表示取消结束动作。|

**示例：**

```ts
import { AbilityConstant, AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onPrepareTermination(): AbilityConstant.PrepareTermination {
    console.info('MyAbilityStage.onPrepareTermination is called');
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```
