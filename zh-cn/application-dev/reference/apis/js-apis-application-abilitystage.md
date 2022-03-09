# AbilityStage

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


AbilityStage是HAP包的运行时类。在HAP加载的时候，通知开发者，开发者可以在此进行该HAP的初始化（如资源预加载，线程创建等）。


## 导入模块

  
```
import AbilityStage from '@ohos.application.AbilityStage';
```


## onCreate

onCreate(): void

当应用创建时调用。

- 示例
    
  ```
  class MyAbilityStage extends AbilityStage {
      onCreate() {
          console.log("MyAbilityStage.onCreate is called")
      }
  }
  ```


## onAcceptWant

onAcceptWant(want: Want): string;

启动一个specified ability时触发的事件。

- 参数：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | want | [Want](js-apis-featureAbility.md#Want类型说明) | 是 | Want类型参数，传入需要启动的ability的信息，如ability名称，包名等。 | 

- 返回值：
    | 类型 | 说明 | 
  | -------- | -------- |
  | string | 用户返回一个ability标识，如果之前启动过次标识的ability，不创建新的实例并拉回栈顶，否则创建新的实例并启动。 | 

- 示例
    
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

环境变化通知接口，发生全局配置变更时回调。

- 参数：
    | 参数名 | 类型 | 必填 | 说明 | 
  | -------- | -------- | -------- | -------- |
  | config | [Configuration](js-apis-configuration.md) | 是 | 发生全局配置变更时触发回调，当前全局配置包括系统语言、深浅色模式。 | 

- 示例：
    
  ```
  class MyAbilityStage extends AbilityStage {
      onConfigurationUpdated(config) {
          console.log('onConfigurationUpdated, language:' + config.language);
      }
  }
  ```

