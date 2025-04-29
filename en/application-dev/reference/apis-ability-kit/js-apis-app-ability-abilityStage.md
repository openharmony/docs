# @ohos.app.ability.AbilityStage (AbilityStage)

**AbilityStage** is a runtime class for HAP files.

**AbilityStage** notifies you of when you can perform HAP initialization such as resource pre-loading and thread creation during the HAP loading.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { AbilityStage } from '@kit.AbilityKit';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context  | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | No| No| Context of an AbilityStage.|

## AbilityStage.onCreate

onCreate(): void

Called when the application is created. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**
    
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

Called when a specified ability is started. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability, such as the ability name and bundle name.|

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | string | Ability ID. If the ability with this ID has been started, no new instance is created and the ability is placed at the top of the stack. Otherwise, a new instance is created and started.| 

**Example**
    
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

Called when the UIAbility is started in the specified process. This API returns the result synchronously and does not support asynchronous callbacks.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target ability, such as the ability name and bundle name.|

**Return value**

| Type| Description| 
| -------- | -------- |
| string | Custom process identifier. If the process with this identifier has been created, the ability runs in the process. Otherwise, a new process is created and the ability runs in it.| 

**Example**
    
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

Called when the global configuration is updated. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | newConfig | [Configuration](js-apis-app-ability-configuration.md) | Yes| Callback invoked when the global configuration is updated. The global configuration indicates the configuration of the environment where the application is running and includes the language and color mode.| 

**Example**
    
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

Called when the system has decided to adjust the memory level. For example, this API can be used when there is not enough memory to run as many background processes as possible. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#memorylevel) | Yes| Memory level that indicates the memory usage status. When the specified memory level is reached, a callback will be invoked and the system will start adjustment.| 

**Example**
    
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

Defines the context of **AbilityStage**.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Type                       | Description                                                        |
| ----------- | --------------------------- | ------------------------------------------------------------ |
| context  | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | The context is obtained in the callback invoked when initialization is performed during ability startup.|

**Example**
    
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

Called when the application is destroyed. This API is called during the normal lifecycle. If the application exits abnormally or is terminated, this API is not called. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

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

Called when the application is closed by the user, allowing the user to choose between immediate termination or cancellation. This API returns the result synchronously and does not support asynchronous callbacks.

Currently, this API takes effect only on 2-in-1 devices.

> **NOTE**
>
> - This API is called only when the application exits normally. It is not called if the application is forcibly closed.
> 
> - This API is not executed when [AbilityStage.onPrepareTerminationAsync](#abilitystageonprepareterminationasync15) is implemented.

**Required permissions**: ohos.permission.PREPARE_APP_TERMINATE

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description| 
| -------- | -------- |
| [AbilityConstant.PrepareTermination](js-apis-app-ability-abilityConstant.md#preparetermination15) | The user's choice.| 

**Example**

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

Called when the application is closed by the user, allowing the user to choose between immediate termination or cancellation. This API uses a promise to return the result. Currently, this API takes effect only on 2-in-1 devices.

> **NOTE**
>
> - This API is called only when the application exits normally. It is not called if the application is forcibly closed.
>
> - If an asynchronous callback crashes, it will be handled as a timeout. If the application does not respond within 10 seconds, it will be terminated forcibly.

**Required permissions**: ohos.permission.PREPARE_APP_TERMINATE

**Atomic service API**: This API can be used in atomic services since API version 15.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description| 
| -------- | -------- |
| Promise\<[AbilityConstant.PrepareTermination](js-apis-app-ability-abilityConstant.md#preparetermination15)> | Promise used to return the user's choice.| 

**Example**

```ts
import { AbilityConstant, AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onPrepareTerminationAsync(): Promise<AbilityConstant.PrepareTermination> {
    await new Promise<AbilityConstant.PrepareTermination>((res, rej) => {
      setTimeout(res, 3000); // Execute the operation after 3 seconds.
    });
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```
