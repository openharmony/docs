# ServiceAbility Switching


The ServiceAbility component in the FA model corresponds to the ServiceExtensionAbility component in the stage model. The ServiceExtensionAbility class provides system APIs. Only system applications can create ServiceExtensionAbility instances. Therefore, ServiceAbility switching adopts different policies for system applications and third-party applications.  


## Switching a ServiceAbility for a System Application

The procedure for switching a ServiceAbility for a system application is similar to the procedure of PageAbility switching.

1. [Create a ServiceExtensionAbility](serviceextensionability.md) in the stage model.

2. Migrate the ServiceAbility code to the ServiceExtensionAbility.
   

The table below describes the lifecycle comparison of the ServiceAbility and ServiceExtensionAbility.

| ServiceAbility| ServiceExtensionAbility| Comparison Description|
| -------- | -------- | -------- |
| onStart(): void | onCreate(want: Want): void | The two methods have the same invoking time. In the stage model, the **want** parameter is added so that you can obtain parameters during creation.|
| onCommand(want: Want, startId: number): void | onRequest(want: Want, startId: number): void | The two methods have the same meaning, invoking time, and parameters.|
| onConnect(want: Want): rpc.RemoteObject | onConnect(want: Want): rpc.RemoteObject | The two methods have the same meaning, invoking time, and parameters.|
| onDisconnect(want: Want): void | onDisconnect(want: Want): void | The two methods have the same meaning, invoking time, and parameters.|
| onReconnect(want: Want): void| onReconnect(want: Want): void| The two methods have the same meaning, invoking time, and parameters.|
| onStop(): void | onDestroy(): void | The two methods have the same meaning, invoking time, and parameters.|


## Switching a ServiceAbility for a Third-Party Application

In the stage model, third-party applications cannot provide services for other third-party applications. You can select a switching solution based on your service requirements.

| Service Type| Switching Solution|
| -------- | -------- |
| Providing services for other third-party applications| Match a scenario-specific [ExtensionAbility](extensionability-overview.md).|
| In-application: providing public use when it is running in the foreground| Extract the component code as a common module for other components to use.|
| In-application: continuing running when it switches to the background| Switch the service to a [background service](serviceextensionability.md).|
