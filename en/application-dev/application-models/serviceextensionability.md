# ServiceExtensionAbility

[ServiceExtensionAbility](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md) is an ExtensionAbility component of the service type that provides extension capabilities related to background services.


ServiceExtensionAbility can be started or connected by other application components to process transactions in the background based on the request of the caller. System applications can call the [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstartserviceextensionability) method to start background services or call the [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextconnectserviceextensionability) method to connect to background services. Third-party applications can call only **connectServiceExtensionAbility()** to connect to background services. The differences between starting and connecting to background services are as follows:


- In the case that AbilityA starts ServiceB, they are weakly associated. After AbilityA exits, ServiceB can still exist.

- In the case that AbilityA connects to ServiceB, they are strongly associated. After AbilityA exits, ServiceB also exits.


Each type of ExtensionAbility has its own context. ServiceExtensionAbility has [ServiceExtensionContext](../reference/apis/js-apis-inner-application-serviceExtensionContext.md). In this document, the started ServiceExtensionAbility component is called the server, and the component that starts ServiceExtensionAbility is called the client.


This topic describes how to use ServiceExtensionAbility in the following scenarios:


- [Implementing a Background Service](#implementing-a-background-service)

- [Starting a Background Service](#starting-a-background-service)

- [Connecting to a Background Service](#connecting-to-a-background-service)


> **NOTE**
> - OpenHarmony does not support third-party applications in implementing ServiceExtensionAbility. If you want to implement transaction processing in the background, use background tasks. For details, see [Background Task](../task-management/background-task-overview.md).
> 
> - UIAbility of a third-party application can connect to ServiceExtensionAbility provided by the system through the context.
> 
> - Third-party applications can connect to ServiceExtensionAbility provided by the system only when they gain focus in the foreground.


## Implementing a Background Service

This feature applies only to system applications. [ServiceExtensionAbility](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md) provides the callbacks **onCreate()**, **onRequest()**, **onConnect()**, **onDisconnect()**, and **onDestory()**. Override them as required. The following figure shows the lifecycle of ServiceExtensionAbility.

  **Figure 1** ServiceExtensionAbility lifecycle
![ServiceExtensionAbility-lifecycle](figures/ServiceExtensionAbility-lifecycle.png)

- **onCreate**
  

This callback is triggered when a service is created for the first time. You can perform initialization operations, for example, registering a common event listener.

  > **NOTE**
>
  > If a service has been created, starting it again does not trigger the **onCreate()** callback.

- **onRequest**
  

This callback is triggered when another component calls the **startServiceExtensionAbility()** method to start the service. After being started, the service runs in the background.

- **onConnect**
  

This callback is triggered when another component calls the **connectServiceExtensionAbility()** method to connect to the service. In this method, a remote proxy object (IRemoteObject) is returned, through which the client communicates with the server by means of RPC.

- **onDisconnect**
  

This callback is triggered when a component calls the **disconnectServiceExtensionAbility()** method to disconnect from the service.

- **onDestroy**
  
  This callback is triggered when the service is no longer used and the instance is ready for destruction. You can clear resources in this callback, for example, deregister the listener.


## How to Develop

To implement a background service, manually create a ServiceExtensionAbility component in DevEco Studio. The procedure is as follows:

1. In the **ets** directory of the **Module** project, right-click and choose **New > Directory** to create a directory named **serviceextability**.

2. In the **serviceextability** directory, right-click and choose **New > TypeScript File** to create a file named **ServiceExtAbility.ts**.

3. Open the **ServiceExtAbility.ts** file, import the [RPC module](../reference/apis/js-apis-rpc.md), and reload the **onRemoteMessageRequest()** method to receive messages from the client and return the processing result to the client. **REQUEST_VALUE** is used to verify the service request code sent by the client.
   
   ```ts
   import rpc from '@ohos.rpc';
   
   const REQUEST_CODE = 99;
   
   class StubTest extends rpc.RemoteObject {
     constructor(des) {
       super(des);
     }
     
     // Receive a message from the client and return the processing result to the client.
     onRemoteMessageRequest(code, data, reply, option) {
       if (code === REQUEST_CODE) {
         // Receive data from the client.
         // If the client calls data.writeInt() multiple times to write multiple pieces of data, the server can call data.readInt() multiple times to receive all the data.
         let optFir = data.readInt();
         let optSec = data.readInt();
         // The server returns the data processing result to the client.
         // In the example, the server receives two pieces of data and returns the sum of the two pieces of data to the client.
         reply.writeInt(optFir + optSec);
       }
       return true;
     }
   
     // Send messages to the client in synchronous or asynchronous mode.
     sendRequest(code, data, reply, options) {
       return null;
     }
   }
   ```

4. In the **ServiceExtAbility.ts** file, add the dependency package for importing ServiceExtensionAbility. Customize a class that inherits from ServiceExtensionAbility and add the required lifecycle callbacks.
   
   ```ts
   import ServiceExtensionAbility from '@ohos.app.ability.ServiceExtensionAbility';
   import rpc from '@ohos.rpc';
   
   const TAG: string = "[Example].[Entry].[ServiceExtAbility]";
   const REQUEST_CODE = 99;
   
   class StubTest extends rpc.RemoteObject {
     // ...
   }
   
   export default class ServiceExtAbility extends ServiceExtensionAbility {
     onCreate(want) {
       console.info(TAG, `onCreate, want: ${want.abilityName}`);
     }
   
     onRequest(want, startId) {
       console.info(TAG, `onRequest, want: ${want.abilityName}`);
     }
   
     onConnect(want) {
       console.info(TAG, `onConnect, want: ${want.abilityName}`);
       return new StubTest("test");
     }
   
     onDisconnect(want) {
       console.info(TAG, `onDisconnect, want: ${want.abilityName}`);
     }
   
     onDestroy() {
       console.info(TAG, `onDestroy`);
     }
   }
   ```

5. Register ServiceExtensionAbility in the [module.json5 file](../quick-start/module-configuration-file.md) corresponding to the **Module** project. Set **type** to **"service"** and **srcEntrance** to the code path of the ExtensionAbility component.
   
   ```json
   {
     "module": {
       // ...
       "extensionAbilities": [
         {
           "name": "ServiceExtAbility",
           "icon": "$media:icon",
           "description": "service",
           "type": "service",
           "visible": true,
           "srcEntrance": "./ets/serviceextability/ServiceExtAbility.ts"
         }
       ]
     }
   }
   ```


## Starting a Background Service

This feature applies only to system applications. A system application uses the [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstartserviceextensionability) method to start a background service. The [onRequest()](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md#serviceextensionabilityonrequest) callback is invoked, and the **Want** object passed by the caller is received through the callback. After the background service is started, its lifecycle is independent of that of the client. In other words, even if the client is destroyed, the background service can still run. Therefore, the background service must be stopped by calling [terminateSelf()](../reference/apis/js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself) when its work is complete. Alternatively, another component can call [stopServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstopserviceextensionability) to stop the background service.

> **NOTE**
>
> [startServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstartserviceextensionability), [stopServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstopserviceextensionability), and [terminateSelf()](../reference/apis/js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself) of ServiceExtensionContext are system APIs and cannot be called by third-party applications.

1. Start a new ServiceExtensionAbility in a system application. For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).
   
   ```ts
   let want = {
       "deviceId": "",
       "bundleName": "com.example.myapplication",
       "abilityName": "ServiceExtAbility"
   };
   this.context.startServiceExtensionAbility(want).then(() => {
       console.info('startServiceExtensionAbility success');
   }).catch((error) => {
       console.info('startServiceExtensionAbility failed');
   })
   ```

2. Stop ServiceExtensionAbility in the system application.
   
   ```ts
   let want = {
       "deviceId": "",
       "bundleName": "com.example.myapplication",
       "abilityName": "ServiceExtAbility"
   };
   this.context.stopServiceExtensionAbility(want).then(() => {
       console.info('stopServiceExtensionAbility success');
   }).catch((error) => {
       console.info('stopServiceExtensionAbility failed');
   })
   ```

3. ServiceExtensionAbility stops itself.
   
   ```ts
   // this is the current ServiceExtensionAbility component.
   this.context.terminateSelf().then(() => {
       console.info('terminateSelf success');
   }).catch((error) => {
       console.info('terminateSelf failed');
   })
   ```


> **NOTE**
>
> Background services can run in the background for a long time. To minimize resource usage, destroy it in time when a background service finishes the task of the requester. A background service can be stopped in either of the following ways:
>
> - The background service calls the [terminateSelf()](../reference/apis/js-apis-inner-application-serviceExtensionContext.md#serviceextensioncontextterminateself) method to automatically stop itself.
>
> - Another component calls the [stopServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextstopserviceextensionability) method to stop the background service.
>
> After either method is called, the system destroys the background service.


## Connecting to a Background Service

Either a system application or a third-party application can connect to a service (service specified in the **Want** object) through [connectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextconnectserviceextensionability). The [onConnect()](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md#serviceextensionabilityonconnect) callback is invoked, and the **Want** object passed by the caller is received through the callback. In this way, a persistent connection is established.

The ServiceExtensionAbility component returns an IRemoteObject in the **onConnect()** callback. Through this IRemoteObject, you can define communication interfaces for RPC interaction between the client and server. Multiple clients can connect to the same background service at the same time. After a client finishes the interaction, it must call [disconnectServiceExtensionAbility()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#abilitycontextdisconnectserviceextensionability) to disconnect from the service. If all clients connected to a background service are disconnected, the system destroys the service.

- Call **connectServiceExtensionAbility()** to establish a connection to a background service. For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).
  
  ```ts
  import rpc from '@ohos.rpc';
  
  const REQUEST_CODE = 99;
  let want = {
      "deviceId": "",
      "bundleName": "com.example.myapplication",
      "abilityName": "ServiceExtAbility"
  };
  let options = {
      onConnect(elementName, remote) {
          console.info('onConnect callback');
          if (remote === null) {
              console.info(`onConnect remote is null`);
              return;
          }
          let option = new rpc.MessageOption();
          let data = new rpc.MessageParcel();
          let reply = new rpc.MessageParcel();
          data.writeInt(100);
          data.writeInt(200);
  
          // @param code Indicates the service request code sent by the client.
          // @param data Indicates the {@link MessageParcel} object sent by the client.
          // @param reply Indicates the response message object sent by the remote service.
          // @param options Specifies whether the operation is synchronous or asynchronous.
          // 
          // @return Returns {@code true} if the operation is successful; returns {@code false} otherwise.
          remote.sendRequest(REQUEST_CODE, data, reply, option).then((ret) => {
              let msg = reply.readInt();
              console.info(`sendRequest ret:${ret} msg:${msg}`);
          }).catch((error) => {
              console.info('sendRequest failed');
          });
      },
      onDisconnect(elementName) {
          console.info('onDisconnect callback')
      },
      onFailed(code) {
          console.info('onFailed callback')
      }
  }
  // The ID returned after the connection is set up must be saved. The ID will be passed for service disconnection.
  let connectionId = this.context.connectServiceExtensionAbility(want, options);
  ```

- Use **disconnectServiceExtensionAbility()** to disconnect from the background service.
  
  ```ts
  let connectionId = 1 // ID returned when the service is connected through connectServiceExtensionAbility.
  this.context.disconnectServiceExtensionAbility(connectionId).then((data) => {
      console.info('disconnectServiceExtensionAbility success');
  }).catch((error) => {
      console.error('disconnectServiceExtensionAbility failed');
  })
  ```

