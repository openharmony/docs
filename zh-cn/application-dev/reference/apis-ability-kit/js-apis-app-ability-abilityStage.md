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

## AbilityStage.onCreate

onCreate(): void

当应用创建时调用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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

启动一个specified ability时触发的事件。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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

在指定进程中启动UIAbility时回调。

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

环境变化通知接口，发生全局配置变更时回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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

当系统已决定调整内存时调用。例如，当该功能在后台运行时，没有足够的内存来运行尽可能多的后台进程时可以使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#memorylevel) | 是 | 回调返回内存微调级别，显示当前内存使用状态。| 

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

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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

当应用销毁时调用, 此方法将在正常的调度生命周期中调用, 当应用程序异常退出或被终止时，将不会调用此方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

## AbilityStage.onPrepareTermination<sup>16+<sup>

onPrepareTermination(): AbilityConstant.PrepareTermination

当应用将被强制结束时调用，可用于询问用户选择立即执行操作还是取消操作。当前仅在2in1设备上生效。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型 | 说明 | 
| -------- | -------- |
| [AbilityConstant.PrepareTermination](js-apis-app-ability-abilityConstant.md#preparetermination16) | 用于返回用户的选择结果。 | 

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
