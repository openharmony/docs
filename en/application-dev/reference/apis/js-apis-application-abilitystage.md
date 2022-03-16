# AbilityStage

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Runtime class for HAP files. It provides methods to notify you when a HAP file starts loading. You can then initialize the HAP file, for example, pre-load resources and create threads.


## Modules to Import

  
```
import AbilityStage from '@ohos.application.AbilityStage';
```


## onCreate

onCreate(): void

Called when the application is created.

- Example
    
  ```
  class MyAbilityStage extends AbilityStage {
      onCreate() {
          console.log("MyAbilityStage.onCreate is called")
      }
  }
  ```


## onAcceptWant

onAcceptWant(want: Want): string;

Called when a specified ability is started.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want)| Yes| Information about the ability to start, such as the ability name and bundle name.| 

- Return value
    | Type| Description| 
  | -------- | -------- |
  | string | Returns an ability ID. If this ability has been started, no new instance is created and the ability is placed at the top of the stack. Otherwise, a new instance is created and started.| 

- Example
    
  ```
  class MyAbilityStage extends AbilityStage {
      onAcceptWant(want) {
          console.log("MyAbilityStage.onAcceptWant called");
          return "com.example.test";
      }
  }
  ```


## onConfigurationUpdated

onConfigurationUpdated(config: Configuration): void;

Called when the global configuration is updated.

- Parameters
    | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](js-apis-configuration.md) | Yes| Callback invoked when the global configuration is updated. The global configuration indicates the configuration of the environment where the application is running and includes the language and color mode.| 

- Example
    
  ```
  class MyAbilityStage extends AbilityStage {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, language:' + config.language);
      }
  }
  ```
