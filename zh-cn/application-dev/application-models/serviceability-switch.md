# ServiceAbility切换


FA模型中的ServiceAbility对应Stage模型中的ServiceExtensionAbility。Stage模型下的ServiceExtensionAbility为系统API，只有系统应用才可以创建。因此，FA模型的ServiceAbility的切换，对于系统应用和三方应用策略有所不同。下面分别介绍这两种场景。


## 系统应用ServiceAbility切换

目前系统提供了ServiceExtensionAbility供系统应用使用。切换步骤和PageAbility基本一致。

1. 在Stage应用中[创建ServiceExtensionAbility](serviceextensionability.md)。

2. 将FA应用中ServiceAbility的业务代码迁移到新创建的ServiceExtensionAbility中。
   ServiceAbility和ServiceExtensionAbility生命周期对比见下表。

     | FA的ServiceAbility | Stage的ServiceExtensionAbility | 对比描述 | 
   | -------- | -------- | -------- |
   | onStart():&nbsp;void | onCreate(want:&nbsp;Want):&nbsp;void | 两者调用时机一致，Stage模型下增加了入参want以便开发者在创建时获取参数。 | 
   | onCommand(want:&nbsp;Want,&nbsp;startId:&nbsp;number):&nbsp;void | onRequest(want:&nbsp;Want,&nbsp;startId:&nbsp;number):&nbsp;void | 两者意义和调用时机一致，参数也一致。 | 
   | onConnect(want:&nbsp;Want):&nbsp;rpc.RemoteObject | onConnect(want:&nbsp;Want):&nbsp;rpc.RemoteObject | 两者意义和调用时机一致，参数也一致。 | 
   | onDisconnect(want:&nbsp;Want):&nbsp;void | onDisconnect(want:&nbsp;Want):&nbsp;void | 两者意义和调用时机一致，参数也一致。 | 
   | onReconnect(want:&nbsp;Want):&nbsp;void | onReconnect(want:&nbsp;Want):&nbsp;void | 两者意义和调用时机一致，参数也一致。 | 
   | onStop():&nbsp;void | onDestroy():&nbsp;void | 两者意义和调用时机一致，参数也一致。 | 


## 三方应用ServiceAbility切换

Stage模型下三方应用不能对其他三方提供服务，应用可以根据具体业务选择切换方案。

  | 业务类型 | 切换策略 | 
| -------- | -------- |
| 对其他三方应用提供服务 | 需根据业务场景匹配到系统对应的场景化[ExtensionAbility](extensionability-overview.md)。 | 
| 应用内：前台运行时公共使用 | 可以将该组件代码抽取成公共模块供其他组件使用。 | 
| 应用内：进入后台时继续运行 | 可以将此服务切换为[后台任务](serviceextensionability.md)。 | 
