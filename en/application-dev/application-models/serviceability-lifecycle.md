# ServiceAbility Lifecycle


You can implement lifecycle callbacks (as described in the table below) in **service.js** or **service.ets**.  


**Table 1** ServiceAbility lifecycle callbacks

| API| Description| 
| -------- | -------- |
| onStart(): void | Called to initialize a ServiceAbility when the ServiceAbility is being created. This callback is invoked only once in the entire lifecycle of a ServiceAbility.| 
| onCommand(want: Want, startId: number): void | Called every time a ServiceAbility is started on the client. You can collect calling statistics and perform initialization operations in this callback.| 
| onConnect(want: Want): rpc.RemoteObject | Called when the ServiceAbility is connected.| 
| onDisconnect(want: Want): void | Called when the connection to the ServiceAbility is disconnected.| 
| onStop(): void | Called when the ServiceAbility is being destroyed. You should override this callback for your ServiceAbility to clear its resources, such as threads and registered listeners.| 
