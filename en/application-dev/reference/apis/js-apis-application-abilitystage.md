# AbilityStage

**AbilityStage** is a runtime class for HAP files.

The **AbilityStage** module notifies you of when you can perform HAP initialization such as resource pre-loading and thread creation during the HAP loading.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```js
import AbilityStage from '@ohos.application.AbilityStage';
```

## AbilityStage.onCreate

onCreate(): void

Called when the application is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**
    
  ```js
  class MyAbilityStage extends AbilityStage {
      onCreate() {
          console.log("MyAbilityStage.onCreate is called")
      }
  }
  ```


## AbilityStage.onAcceptWant

onAcceptWant(want: Want): string;

Called when a specified ability is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-application-Want.md) | Yes| Information about the ability to start, such as the ability name and bundle name.| 

**Return value**

  | Type| Description| 
  | -------- | -------- |
  | string | Returns an ability ID. If this ability has been started, no new instance is created and the ability is placed at the top of the stack. Otherwise, a new instance is created and started.| 

**Example**
    
  ```js
  class MyAbilityStage extends AbilityStage {
      onAcceptWant(want) {
          console.log("MyAbilityStage.onAcceptWant called");
          return "com.example.test";
      }
  }
  ```


## AbilityStage.onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

Called when the global configuration is updated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](js-apis-configuration.md) | Yes| Callback invoked when the global configuration is updated. The global configuration indicates the configuration of the environment where the application is running and includes the language and color mode.| 

**Example**
    
  ```js
  class MyAbilityStage extends AbilityStage {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, language:' + config.language);
      }
  }
  ```

## AbilityStage.onMemoryLevel

onMemoryLevel(level: AbilityConstant.MemoryLevel): void;

Called when the system has decided to adjust the memory level. For example, this API can be used when there is not enough memory to run as many background processes as possible.

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | level | [AbilityConstant.MemoryLevel](js-apis-application-abilityConstant.md#abilityconstantmemorylevel) | Yes| Memory level that indicates the memory usage status. When the specified memory level is reached, a callback will be invoked and the system will start adjustment.| 

**Example**
    
  ```js
  class MyAbilityStage extends AbilityStage {
    onMemoryLevel(level) {
        console.log('onMemoryLevel, level:' + JSON.stringify(level));
    } 
  }
  ```

## AbilityStage.context

context: AbilityStageContext;

Describes the configuration information about the context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Type                       | Description                                                        |
| ----------- | --------------------------- | ------------------------------------------------------------ |
| context  | [AbilityStageContext](js-apis-abilitystagecontext.md) | Called when initialization is performed during ability startup.|
