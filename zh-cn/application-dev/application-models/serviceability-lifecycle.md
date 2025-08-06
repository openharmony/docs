# ServiceAbility的生命周期
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @xialiangwei-->
<!--SE: @jsjzju-->
<!--TSE: @lixueqing513-->


开发者可以根据业务场景实现service.js/service.ets中的生命周期相关接口。ServiceAbility生命周期接口说明见下表。


  **表1** ServiceAbility生命周期接口说明

| 接口名 | 描述 | 
| -------- | -------- |
| onStart():&nbsp;void | 该方法在创建ServiceAbility的时候调用，用于Service的初始化，在ServiceAbility的整个生命周期只会调用一次。 | 
| onCommand(want:&nbsp;Want,&nbsp;startId:&nbsp;number):&nbsp;void | 在Service创建完成之后调用，该方法在客户端每次启动该Service时都会调用，开发者可以在该方法中做一些调用统计、初始化类的操作。 | 
| onConnect(want:&nbsp;Want):&nbsp;rpc.RemoteObject | 在连接ServiceAbility时调用。 | 
| onDisconnect(want:&nbsp;Want):&nbsp;void | 在与已连接的ServiceAbility断开连接时调用。 | 
| onStop():&nbsp;void | 在ServiceAbility销毁时调用。开发者应通过实现此方法来清理资源，如关闭线程、注册的侦听器等。 | 
