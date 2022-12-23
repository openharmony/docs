# @ohos.app.ability.AbilityStage (AbilityStage)

AbilityStage是HAP包的运行时类。

AbilityStage类提供在HAP加载的时候，通知开发者，可以在此进行该HAP的初始化（如资源预加载，线程创建等）能力。

> **说明：**
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import AbilityStage from '@ohos.app.ability.AbilityStage';
```

## AbilityStage.onCreate

onCreate(): void

当应用创建时调用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**示例：**
    
```ts
class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage.onCreate is called");
    }
}
```


## AbilityStage.onAcceptWant

onAcceptWant(want: [Want](js-apis-app-ability-want.md)): string;

启动一个specified ability时触发的事件。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-app-ability-want.md) | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 

**返回值：**

  | 类型 | 说明 | 
  | -------- | -------- |
  | string | 用户返回一个ability标识，如果之前启动过标识的ability，不创建新的实例并拉回栈顶，否则创建新的实例并启动。 | 

**示例：**
    
```ts
class MyAbilityStage extends AbilityStage {
    onAcceptWant(want) {
        console.log("MyAbilityStage.onAcceptWant called");
        return "com.example.test";
    }
}
```


## AbilityStage.onConfigurationUpdate

onConfigurationUpdate(newConfig: [Configuration](js-apis-app-ability-configuration.md)): void;

环境变化通知接口，发生全局配置变更时回调。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | newConfig | [Configuration](js-apis-app-ability-configuration.md) | 是 | 发生全局配置变更时触发回调，当前全局配置包括系统语言、深浅色模式。 | 

**示例：**
    
```ts
class MyAbilityStage extends AbilityStage {
    onConfigurationUpdate(config) {
        console.log('onConfigurationUpdate, language:' + config.language);
    }
}
```

## AbilityStage.onMemoryLevel

onMemoryLevel(level: [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#abilityconstantmemorylevel)): void;

当系统已决定调整内存时调用。例如，当该功能在后台运行时，没有足够的内存来运行尽可能多的后台进程时可以使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#abilityconstantmemorylevel) | 是 | 回调返回内存微调级别，显示当前内存使用状态。| 

**示例：**
    
```ts
class MyAbilityStage extends AbilityStage {
    onMemoryLevel(level) {
        console.log('onMemoryLevel, level:' + JSON.stringify(level));
    } 
}
```

## AbilityStage.context

context: [AbilityStageContext](js-apis-inner-application-abilityStageContext.md);

指示AbilityStage的上下文。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 属性名      | 类型                        | 说明                                                         |
| ----------- | --------------------------- | ------------------------------------------------------------ |
| context  | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 在Ability启动阶段进行初始化时回调，获取到该Ability的context值。 |
