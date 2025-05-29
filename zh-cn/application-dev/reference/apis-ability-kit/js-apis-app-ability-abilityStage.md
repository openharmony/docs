# @ohos.app.ability.AbilityStage (AbilityStage)

AbilityStage是HAP的运行时类。

AbilityStage类提供在HAP加载的时候，通知开发者，可以在此进行该HAP的初始化（如资源预加载，线程创建等）能力。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { AbilityStage } from '@kit.AbilityKit';
```

## 属性

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| context  | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 否 | 否 | AbilityStage上下文。 |

## AbilityStage.onCreate

onCreate(): void

当应用创建时调用。同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**
    
```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onCreate() {
    console.log('MyAbilityStage.onCreate is called');
  }
}
```


## AbilityStage.onAcceptWant

onAcceptWant(want: Want): string

启动一个specified ability时触发的事件。同步接口，不支持异步回调。

> **说明：**
>
> 从API version 20开始，当[AbilityStage.onAcceptWantAsync](#abilitystageonacceptwantasync20)实现时，本回调函数将不执行。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | string | 返回一个ability标识，如果之前启动过标识的ability，不创建新的实例并拉回栈顶，否则创建新的实例并启动。 | 

**示例：**
    
```ts
import { AbilityStage, Want } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onAcceptWant(want: Want) {
    console.log('MyAbilityStage.onAcceptWant called');
    return 'com.example.test';
  }
}
```

## AbilityStage.onNewProcessRequest<sup>11+</sup>

onNewProcessRequest(want: Want): string

在指定进程中启动UIAbility时回调。同步接口，不支持异步回调。

> **说明：**
>
> 从API version 20开始，当[AbilityStage.onNewProcessRequestAsync](#abilitystageonnewprocessrequestasync20)实现时，本回调函数将不执行。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的ability的信息，如Ability名称，Bundle名称等。 |

**返回值：**

| 类型 | 说明 | 
| -------- | -------- |
| string | 返回一个由开发者自行决定的进程字符串标识，如果之前此标识对应的进程已被创建，就让ability在此进程中运行，否则创建新的进程。 | 

**示例：**
    
```ts
import { AbilityStage, Want } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onNewProcessRequest(want: Want) {
    console.log('MyAbilityStage.onNewProcessRequest called');
    return 'com.example.test';
  }
}
```


## AbilityStage.onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void

环境变化通知接口，发生全局配置变更时回调。同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | newConfig | [Configuration](js-apis-app-ability-configuration.md) | 是 | 发生全局配置变更时触发回调，当前全局配置包括系统语言、深浅色模式。 | 

**示例：**
    
```ts
import { AbilityStage, Configuration } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onConfigurationUpdate(config: Configuration) {
    console.log(`onConfigurationUpdate, language: ${config.language}`);
  }
}
```

## AbilityStage.onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void

该接口用于监听系统内存状态变化。当系统检测到内存资源紧张时，将主动触发该回调。开发者可通过实现此接口，在收到内存紧张事件时，及时释放非必要资源（如缓存数据、临时对象等），以避免应用进程被系统强制终止。

同步接口，不支持异步回调。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#memorylevel) | 是 | 回调返回内存微调级别，显示当前内存使用状态。<br>**说明：**<br>不同产品的触发条件可能存在差异。以12G内存的标准设备为例：<br>- 当可用内存下降至1700M~1800M时，会触发取值为0的onMemoryLevel回调。<br>- 当可用内存下降至1600M~1700M时，会触发取值为1的onMemoryLevel回调。<br>- 当可用内存下降至1600M以下时，会触发取值为2的onMemoryLevel回调。| 

**示例：**
    
```ts
import { AbilityStage, AbilityConstant } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onMemoryLevel(level: AbilityConstant.MemoryLevel) {
    console.log(`onMemoryLevel, level: ${JSON.stringify(level)}`);
  }
}
```

## AbilityStage.context

context: AbilityStageContext

指示AbilityStage的上下文。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 属性名      | 类型                        | 说明                                                         |
| ----------- | --------------------------- | ------------------------------------------------------------ |
| context  | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 在Ability启动阶段进行初始化时回调，获取到该Ability的context值。 |

**示例：**
    
```ts
import { AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    let abilityStageContext = this.context;
  }
}
```

## AbilityStage.onDestroy<sup>12+<sup>

onDestroy(): void

当应用销毁时调用，此方法将在正常的调度生命周期中调用，当应用程序异常退出或被终止时，将不会调用此方法。同步接口，不支持异步回调。

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  onDestroy() {
    console.log('MyAbilityStage.onDestroy is called');
  }
}
```

## AbilityStage.onPrepareTermination<sup>15+<sup>

onPrepareTermination(): AbilityConstant.PrepareTermination

当应用被用户关闭时调用，可用于询问用户选择立即执行操作还是取消操作。同步接口，不支持异步回调。

当前仅在2in1设备上生效。

> **说明：**
>
> - 仅当应用正常退出时会调用该接口。如果应用被强制关闭，则不会调用该接口。
> 
> - 当[AbilityStage.onPrepareTerminationAsync](#abilitystageonprepareterminationasync15)实现时，本回调函数将不执行。 

**需要权限**：ohos.permission.PREPARE_APP_TERMINATE

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 | 
| -------- | -------- |
| [AbilityConstant.PrepareTermination](js-apis-app-ability-abilityConstant.md#preparetermination15) | 用于返回用户的选择结果。 | 

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

## AbilityStage.onPrepareTerminationAsync<sup>15+<sup>

onPrepareTerminationAsync(): Promise\<AbilityConstant.PrepareTermination>

当应用被用户关闭时调用，可用于询问用户选择立即执行操作还是取消操作。使用Promise异步回调。当前仅在2in1设备上生效。

> **说明：**
>
> - 仅当应用正常退出时会调用该接口。如果应用被强制关闭，则不会调用该接口。
>
> - 若异步回调内发生crash，按超时处理，执行等待超过10秒未响应，应用将被强制关闭。

**需要权限**：ohos.permission.PREPARE_APP_TERMINATE

**原子化服务API**：从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 | 
| -------- | -------- |
| Promise\<[AbilityConstant.PrepareTermination](js-apis-app-ability-abilityConstant.md#preparetermination15)> | Promise对象，返回用户的选择结果。 | 

**示例：**

```ts
import { AbilityConstant, AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onPrepareTerminationAsync(): Promise<AbilityConstant.PrepareTermination> {
    await new Promise<AbilityConstant.PrepareTermination>((res, rej) => {
      setTimeout(res, 3000); // 延时3秒后执行
    });
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```

## AbilityStage.onAcceptWantAsync<sup>20+</sup>

onAcceptWantAsync(want: Want): Promise\<string\>

当启动模式配置为specified的UIAbility被拉起时，会触发该回调，并返回一个string作为待启动的UIAbility实例的唯一标志。使用Promise异步回调。

如果系统中已经有相同标记的UIAbility实例存在，则复用已有实例，否则创建新的实例。详见：[specified启动模式](../../application-models/uiability-launch-type.md#specified启动模式)。

**原子化服务API**：从API version 20开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的UIAbility的信息，如UIAbility名称、Bundle名称等。 |

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | Promise\<string\> | Promise对象，返回一个string作为待启动的UIAbility实例的唯一标志。如果系统中已经有该标志的UIAbility实例存在，则复用已有实例，否则创建新的实例。 |

**示例：**
    
```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onAcceptWantAsync(): Promise<string> {
    await new Promise<string>((res, rej) => {
      setTimeout(res, 1000); // 延时1秒后执行
    });
    return 'default';
  }
}
```

## AbilityStage.onNewProcessRequestAsync<sup>20+</sup>

onNewProcessRequestAsync(want: Want): Promise\<string\>

如果UIAbility配置了在独立进程中运行（即[module.json5配置文件](../../quick-start/module-configuration-file.md)中UIAbility的isolationProcess字段取值为true），当该UIAbility被拉起时，会触发该回调，并返回一个string作为进程唯一标志。使用Promise异步回调。

如果该应用已有相同标志的进程存在，则待启动的UIAbility运行在此进程中，否则创建新的进程。

该接口仅在2in1和tablet设备上生效。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的UIAbility的信息，如UIAbility名称、Bundle名称等。 |

**返回值：**

| 类型 | 说明 | 
| -------- | -------- |
| Promise\<string\> | Promise对象，返回一个由开发者自定义的进程字符串标识。如果该应用已有相同标志的进程存在，则UIAbility在此进程中运行，否则创建新的进程。 |

**示例：**
    
```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onNewProcessRequestAsync(): Promise<string> {
    await new Promise<string>((res, rej) => {
      setTimeout(res, 1000); // 延时1秒后执行
    });
    return '';
  }
}
```
