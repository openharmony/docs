# AbilityStage

> **NOTE**<br/>
> The initial APIs of this module are supported since API 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Runtime class for HAP files. It provides APIs to notify you when a HAP file starts loading. You can then initialize the HAP file, for example, pre-load resources and create threads.


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
## AbilityStage.context

context: AbilityStageContext;

Describes the configuration information about the context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name     | Type                       | Description                                                        |
| ----------- | --------------------------- | ------------------------------------------------------------ |
| context  | [AbilityStageContext](js-apis-featureAbility.md) | Called when initialization is performed during ability startup.|
