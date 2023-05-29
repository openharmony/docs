# Want概述


## Want的定义与用途

[Want](../reference/apis/js-apis-app-ability-want.md)是一种对象，用于在应用组件之间传递信息。

其中，一种常见的使用场景是作为[`startAbility()`](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)方法的参数。例如，当UIAbilityA需要启动UIAbilityB并向UIAbilityB传递一些数据时，可以使用Want作为一个载体，将数据传递给UIAbilityB。

**图1** Want用法示意  
![usage-of-want](figures/usage-of-want.png)  


## Want的类型

- **显式Want**：在启动目标应用组件时，调用方传入的want参数中指定了abilityName和bundleName，称为显式Want。
  
    显式Want通常用于在当前应用中启动已知的目标应用组件，通过提供目标应用组件所在应用的Bundle名称信息（bundleName）并在Want对象内指定abilityName来启动目标应用组件。当有明确处理请求的对象时，显式Want是一种简单有效的启动目标应用组件的方式。
  
  ```ts
  let wantInfo = {
    deviceId: '', // deviceId为空表示本设备
    bundleName: 'com.example.myapplication',
    abilityName: 'FuncAbility',
  }
  ```
  
- **隐式Want**：在启动目标应用组件时，调用方传入的want参数中未指定abilityName，称为隐式Want。
  
  当需要处理的对象不明确时，可以使用隐式Want，在当前应用中使用其他应用提供的某个能力，而不关心提供该能力的具体应用。隐式Want使用[skills标签](../quick-start/module-configuration-file.md#skills标签)来定义需要使用的能力，并由系统匹配声明支持该请求的所有应用来处理请求。例如，需要打开一个链接的请求，系统将匹配所有声明支持该请求的应用，然后让用户选择使用哪个应用打开链接。
  
  
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
  > - 根据系统中待匹配应用组件的匹配情况不同，使用隐式Want启动应用组件时会出现以下三种情况。
  >   - 未匹配到满足条件的应用组件：启动失败。
  >   - 匹配到一个满足条件的应用组件：直接启动该应用组件。
  >   - 匹配到多个满足条件的应用组件（UIAbility）：弹出选择框让用户选择。
  > 
  > - 调用方传入的want参数中不带有abilityName和bundleName，则不允许通过隐式Want启动所有应用的ServiceExtensionAbility。
  > 
  > - 调用方传入的want参数中带有bundleName，则允许使用startServiceExtensionAbility()方法隐式Want启动ServiceExtensionAbility，默认返回优先级最高的ServiceExtensionAbility，如果优先级相同，返回第一个。
