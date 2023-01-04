# Want概述


## Want的定义与用途

[Want](../reference/apis/js-apis-app-ability-want.md)是对象间信息传递的载体，可以用于应用组件间的信息传递。其使用场景之一是作为startAbility()的参数，包含了指定的启动目标以及启动时需携带的相关数据，如bundleName和abilityName字段分别指明目标Ability所在应用的Bundle名称以及对应包内的Ability名称。当UIAbilityA启动UIAbilityB并需要传入一些数据给UIAbilityB时，Want可以作为一个载体将数据传给UIAbilityB。

  **图1** Want用法示意  
<img src="figures/usage-of-want.png" alt="usage-of-want" style="zoom:80%;" />


## Want的类型

- **显式Want**：在启动Ability时指定了abilityName和bundleName的Want称为显式Want。
    当有明确处理请求的对象时，通过提供目标Ability所在应用的Bundle名称信息（bundleName），并在Want内指定abilityName便可启动目标Ability。显式Want通常用于在当前应用开发中启动某个已知的Ability。
    
  ```ts
  let wantInfo = {
      deviceId: '', // deviceId为空表示本设备
      bundleName: 'com.example.myapplication',
      abilityName: 'FuncAbility',
  }
  ```

- **隐式Want**：在启动Ability时未指定abilityName的Want称为隐式Want。
  当请求处理的对象不明确时，希望在当前应用中使用其他应用提供的某个能力（通过[skills标签](../quick-start/module-configuration-file.md#skills标签)定义），而不关心提供该能力的具体应用，可以使用隐式Want。例如使用隐式Want描述需要打开一个链接的请求，而不关心通过具体哪个应用打开，系统将匹配声明支持该请求的所有应用。

  
  ```ts
  let wantInfo = {
      // uncomment line below if wish to implicitly query only in the specific bundle.
      // bundleName: 'com.example.myapplication',
      action: 'ohos.want.action.search',
      // entities can be omitted
      entities: [ 'entity.system.browsable' ],
      uri: 'https://www.test.com:8080/query/student',
      type: 'text/plain',
  };
  ```

  > **说明：**
  > - 根据系统中待匹配Ability的匹配情况不同，使用隐式Want启动Ability时会出现以下三种情况。
  >   - 未匹配到满足条件的Ability：启动失败。
  >   - 匹配到一个满足条件的Ability：直接启动该Ability。
  >   - 匹配到多个满足条件的Ability（UIAbility）：弹出选择框让用户选择。
  > 
  > - 调用方传入的want参数中不带有abilityName和bundleName，则不允许通过隐式Want启动所有应用的ServiceExtensionAbility。
  > 
  > - 调用方传入的want参数中带有bundleName，则允许使用startServiceExtensionAbility()方法隐式Want启动ServiceExtensionAbility，默认返回优先级最高的ServiceExtensionAbility，如果优先级相同，返回第一个。
