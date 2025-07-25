# @ohos.app.ability.AbilityStage (AbilityStage Component Container)

AbilityStage is a component container at the [module](../../../application-dev/quick-start/application-package-overview.md#multi-module-design-mechanism) level. When the [HAP](../../../application-dev/quick-start/hap-package.md) or [HSP](../../../application-dev/quick-start/in-app-hsp.md) of an application is loaded for the first time, an AbilityStage instance is created. You can use the instance to perform initialization operations such as resource preloading and thread creation at the module level. An AbilityStage instance corresponds to a module.

An AbilityStage has the lifecycle callbacks [onCreate()](#oncreate) and [onDestroy()](#ondestroy12), and the event callbacks [onAcceptWant()](#onacceptwant), [onConfigurationUpdate()](#onconfigurationupdate), and [onMemoryLevel()](#onmemorylevel).

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { AbilityStage } from '@kit.AbilityKit';
```

## AbilityStage

### Properties

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context  | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | No| No| Context of an AbilityStage.|

### onCreate

onCreate(): void

Called when an AbilityStage instance is created. Such an instance is automatically created by the system before it loads the first Ability instance of the module.

You can initialize the module (for example, preload resources or create threads) in this callback. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```ts
import { AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onCreate() {
    console.log('MyAbilityStage.onCreate is called');
  }
}
```


### onAcceptWant

onAcceptWant(want: Want): string

Called when an [UIAbility with the launch mode set to specified](../../../application-dev/application-models/uiability-launch-type.md#specified) is launched. This API returns a string representing the unique ID of the UIAbility instance. This API returns the result synchronously and does not support asynchronous callbacks.

If a UIAbility instance with the same ID already exists in the system, that instance is reused. Otherwise, a new instance is created.

> **NOTE**
>
> Since API version 20, this callback is not executed when [AbilityStage.onAcceptWantAsync](#onacceptwantasync20) is implemented.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want type parameter that includes the launch parameters provided by the caller, such as the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | ID of the UIAbility. If a UIAbility with the same ID has been launched, that UIAbility is reused. Otherwise, a new instance is created and launched.|

**Example**


```ts
import { AbilityStage, Want } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onAcceptWant(want: Want) {
    console.log('MyAbilityStage.onAcceptWant called');
    return 'com.example.test';
  }
}
```

### onNewProcessRequest<sup>11+</sup>

onNewProcessRequest(want: Want): string

Called when a UIAbility or UIExtensionAbility is launched in a specified process. This API returns the result synchronously and does not support asynchronous callbacks.

To enable this API, the **isolationProcess** field for the corresponding UIAbility or UIExtensionAbility must be set to **true** in the [module.json5](../../quick-start/module-configuration-file.md) file.

> **NOTE**
>
> - In API version 19 and earlier, only a UIAbility can be launched in the specified process. From API version 20 onwards, a UIExtensionAbility can also be launched in the specified process.
> - Since API version 20, this callback is not executed when [AbilityStage.onNewProcessRequestAsync](#onnewprocessrequestasync20) is implemented.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want type parameter that includes the launch parameters provided by the caller, such as the UIAbility or UIExtensionAbility name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Custom process identifier. If the process with this identifier has been created, the ability runs in the process. Otherwise, a new process is created and the ability runs in it.|

**Example**

```ts
import { AbilityStage, Want } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onNewProcessRequest(want: Want) {
    console.log('MyAbilityStage.onNewProcessRequest called');
    return 'com.example.test';
  }
}
```


### onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void

Called when the system global configuration (such as the system language and dark/light color mode) changes. All the configuration items are defined in the [Configuration](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-configuration.md) class. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | newConfig | [Configuration](js-apis-app-ability-configuration.md) | Yes| Callback invoked when the global configuration is updated. The global configuration indicates the configuration of the environment where the application is running and includes the language and color mode.|

**Example**

```ts
import { AbilityStage, Configuration } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onConfigurationUpdate(config: Configuration) {
    console.log(`MyAbilityStage.onConfigurationUpdate, language: ${config.language}`);
  }
}
```

### onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void

Listens for changes in the system memory level status. When the system detects low memory resources, it will proactively invoke this callback. You can implement this callback to promptly release non-essential resources (such as cached data or temporary objects) upon receiving a memory shortage event, thereby preventing the application process from being forcibly terminated by the system.

This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-app-ability-abilityConstant.md#memorylevel) | Yes| Memory level that indicates the memory usage status. When the specified memory level is reached, a callback will be invoked and the system will start adjustment.<br>**NOTE**<br>The trigger conditions may differ across various devices. For example, on a standard device with 12 GB of memory:<br>- A callback with value 0 is triggered when available memory drops between 1700 MB and 1800 MB.<br>- A callback with value 1 is triggered when available memory drops between 1600 MB and 1700 MB.<br>- A callback with value 2 is triggered when available memory falls below 1600 MB.|

**Example**

```ts
import { AbilityStage, AbilityConstant } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onMemoryLevel(level: AbilityConstant.MemoryLevel) {
    console.log(`MyAbilityStage.onMemoryLevel, level: ${JSON.stringify(level)}`);
  }
}
```

### onDestroy<sup>12+<sup>

onDestroy(): void

Called when the last Ability instance of the corresponding module exits. This API is called during the normal lifecycle. If the application exits abnormally or is terminated, this API is not called. This API returns the result synchronously and does not support asynchronous callbacks.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

```ts
import { AbilityStage } from '@kit.AbilityKit';

export default class MyAbilityStage extends AbilityStage {
  onDestroy() {
    console.log('MyAbilityStage.onDestroy is called');
  }
}
```

### onPrepareTermination<sup>15+<sup>

onPrepareTermination(): AbilityConstant.PrepareTermination

Called when the application is closed by the user, allowing the user to choose between immediate termination or cancellation. This API returns the result synchronously and does not support asynchronous callbacks.

> **NOTE**
>
> - Currently, this API takes effect only on 2-in-1 devices.
>
> - The API is called only when the application exits under normal circumstances (for example, when the application is closed through the doc bar or tray, or when the application shuts down along with the device). It will not be called if the application is terminated forcibly.
>
> - This API is not executed when [AbilityStage.onPrepareTerminationAsync](#onprepareterminationasync15) is implemented.

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

export default class MyAbilityStage extends AbilityStage {
  onPrepareTermination(): AbilityConstant.PrepareTermination {
    console.info('MyAbilityStage.onPrepareTermination is called');
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```

### onPrepareTerminationAsync<sup>15+<sup>

onPrepareTerminationAsync(): Promise\<AbilityConstant.PrepareTermination>

Called when the application is closed by the user, allowing the user to choose between immediate termination or cancellation. This API uses a promise to return the result.

> **NOTE**
>
> - Currently, this API takes effect only on 2-in-1 devices.
>
> - The API is called only when the application exits under normal circumstances (for example, when the application is closed through the doc bar or tray, or when the application shuts down along with the device). It will not be called if the application is terminated forcibly.
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

export default class MyAbilityStage extends AbilityStage {
  async onPrepareTerminationAsync(): Promise<AbilityConstant.PrepareTermination> {
    await new Promise<AbilityConstant.PrepareTermination>((res, rej) => {
      setTimeout(res, 3000); // Execute the operation after 3 seconds.
    });
    return AbilityConstant.PrepareTermination.CANCEL;
  }
}
```

### onAcceptWantAsync<sup>20+</sup>

onAcceptWantAsync(want: Want): Promise\<string\>

Called when a UIAbility with the launch mode set to **specified** is launched. This API returns a string that uniquely identifies the UIAbility instance. This API uses a promise to return the result.

If a UIAbility instance with the same ID already exists in the system, that instance is reused. Otherwise, a new instance is created. For details, see [specified](../../application-models/uiability-launch-type.md#specified).

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want information about the target UIAbility, such as the UIAbility name and bundle name.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise\<string\> | Promise used to return a string that uniquely identifies the UIAbility instance launched. If a UIAbility instance with the same ID already exists in the system, that instance is reused. Otherwise, a new instance is created.|

**Example**

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onAcceptWantAsync(): Promise<string> {
    await new Promise<string>((res, rej) => {
      setTimeout(res, 1000); // Execute the operation after 1 second.
    });
    return 'default';
  }
}
```

### onNewProcessRequestAsync<sup>20+</sup>

onNewProcessRequestAsync(want: Want): Promise\<string\>

Called when a UIAbility or UIExtensionAbility, which is configured to run in an independent process (with **isolationProcess** set to **true** in the [module.json5](../../quick-start/module-configuration-file.md) file), is launched. This API returns a string representing the unique process ID. This API uses a promise to return the result.

If the application already has a process with the same ID, the UIAbility or UIExtensionAbility runs in that process. Otherwise, a new process is created.

This API takes effect only on 2-in-1 devices and tablets.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-app-ability-want.md) | Yes| Want type parameter that includes the launch parameters provided by the caller, such as the UIAbility or UIExtensionAbility name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<string\> | Promise used to return a string representing the process ID. If the application already has a process with the same ID, the UIAbility or UIExtensionAbility runs in that process. Otherwise, a new process is created.|

**Example**

```ts
import { AbilityStage } from '@kit.AbilityKit';

class MyAbilityStage extends AbilityStage {
  async onNewProcessRequestAsync(): Promise<string> {
    await new Promise<string>((res, rej) => {
      setTimeout(res, 1000); // Execute the operation after 1 second.
    });
    return '';
  }
}
```
