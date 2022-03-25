# Service Ability Development

## Basic Concepts
A Service ability is used to run tasks in the background, such as playing music or downloading files. It does not provide a UI for user interaction. Service abilities can be started by other applications or abilities and can remain running in the background even after the user switches to another application.

## Creating a Service Ability<a name="section17436202895812"></a>

1. Create a child class of the **Ability** class and override the following Service ability-related lifecycle callbacks to implement your own logic for processing requests to interact with your Service ability:

   - onStart()

     This callback is invoked for initializing a Service ability when the Service ability is being created. This callback is invoked only once in the entire lifecycle of a Service ability. The **Want** object passed to this callback must be null.

   - onCommand()

     This callback is invoked every time a Service ability is created on a client. You can calculate calling statistics and perform initialization operations in this callback.

   - onConnect()

     This callback is invoked when another ability is connected to the Service ability. It returns an **IRemoteObject**. You can use this callback to generate a channel for the other ability to interact with the Service ability during inter-process communication (IPC). An ability can connect to the same Service ability for multiple times. When the first client is connected to a Service ability, the system calls **onConnect()** to generate an **IRemoteObject** for the Service ability, and the generated **IRemoteObject** will then be cached and used for all clients that are connected to this Service ability without having to call **onConnect()** again.

   - onDisconnect()

     This callback is invoked when another ability is disconnected from the Service ability.

   - onStop()

     This callback is invoked when a Service ability is being destroyed. You should override this callback for your Service ability to clear its resources, such as threads and registered listeners.

   The following code snippet shows how to create a Service ability:

   ```javascript
   export default {
       onStart(want) {
           console.log('ServiceAbility onStart');
       },
       onCommand(want, restart, startId) {
           console.log('ServiceAbility onCommand');
       },
       onConnect(want) {
           console.log('ServiceAbility OnConnect');
       },
       onDisconnect() {
           console.log('ServiceAbility OnDisConnect');
       },
       onStop() {
           console.log('ServiceAbility onStop');
       },
   }
   ```

2.  Register a Service ability.

    You must declare your Service ability in the **config.json** file by setting its **type** attribute to **service**.

    ```javascript
    {
        "module": {
            "abilities": [         
                {    
                    "name": ".ServiceAbility",
                    "type": "service",
                    "visible": true
                    ...
                }
            ]
            ...
        }
        ...
    }
    ```

    


## Starting the Service Ability<a name="section944219415599"></a>

The **Ability** class provides the **startAbility()** method for you to start another Service ability by passing a **Want** object.

To set information about the target Service ability, you can first construct a **Want** object with the **bundleName** and **abilityName** parameters specified. The meanings of the parameters are as follows:

- **bundleName** indicates the name of the bundle to which the target ability belongs.
- **abilityName** indicates the target ability name.

The following code snippet shows how to start a Service ability running on the local device:

```javascript
import featureAbility from '@ohos.ability.featureability';
var promise = await featureAbility.startAbility(
    {
        want:
        {
            bundleName: "com.jstest.serviceability",
            abilityName: "com.jstest.serviceability.MainAbility",
        },
    }
); 
```

- After the preceding code is executed, the **startAbility()** method is called to start the Service ability.
  - If the Service ability is not running, the system calls **onStart()** to initialize the Service ability, and then calls **onCommand()** on the Service ability.
  - If the Service ability is running, the system directly calls **onCommand()** on the Service ability.

- Stopping a Service ability

  Once created, the Service ability keeps running in the background. The system does not stop or destroy it unless memory resources must be reclaimed. You can call **terminateAbility()** on a Service ability to stop it or call **stopAbility()** on another ability to stop the specified Service ability.

  

## Connecting to a Local Service Ability<a name="section126857614018"></a>

If you need to connect a Service ability to a Page ability or to a Service ability in another application, you must first implement the **IAbilityConnection** API for the connection. A Service ability allows other abilities to connect to it through **connectAbility()**.

When calling **connectAbility()**, you should pass a **Want** object containing information about the target Service ability and an **IAbilityConnection** object to the method. **IAbilityConnection** provides the following callbacks that you should implement: **onConnect()**, **onDisconnect()**, and **onFailed()**. The **onConnect()** callback is invoked when a Service ability is connected, **onDisconnect()** is invoked when a Service ability is unexpectedly disconnected, and **onFailed()** is invoked when a connection to a Service ability fails.

The following code snippet shows how to implement the callbacks:

```javascript
var mRemote;
function onConnectCallback(element, remote){
    console.log('ConnectAbility onConnect Callback')
    mRemote = remote;
}

function onDisconnectCallback(element){
    console.log('ConnectAbility onDisconnect Callback')
}

function onFailedCallback(code){
    console.log('ConnectAbility onFailed Callback')
}
```

The following code snippet shows how to connect to a local Service ability:

```javascript
import featureAbility from '@ohos.ability.featureability';
var connId = featureAbility.connectAbility(
    {
        bundleName: "com.jstest.serviceability",
        abilityName: "com.jstest.serviceability.MainAbility",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

When a Service ability is connected, the **onConnect()** callback is invoked and returns an **IRemoteObject** defining the proxy used for communicating with the Service ability. OpenHarmony provides a default implementation of the **IRemoteObject** interface. You can inherit **rpc.RemoteObject** to implement your own class of **IRemoteObject**.

The following code snippet shows how the Service ability instance returns itself to the calling ability:

```javascript
import rpc from "@ohos.rpc";

var mMyStub;
export default {
    onStart(want) {
        class MyStub extends rpc.RemoteObject{
            constructor(des) {
                if (typeof des === 'string') {
                    super(des);
                }
                return null;
            }
            onRemoteRequest(code, message, reply, option) {
            }
        }
        mMyStub = new MyStub("ServiceAbility-test");
    },
    onCommand(want, restart, startId) {
        console.log('ServiceAbility onCommand');
    },
    onConnect(want) {
        console.log('ServiceAbility OnConnect');
        return mMyStub;
    },
    onDisconnect() {
        console.log('ServiceAbility OnDisConnect');
    },
    onStop() {
        console.log('ServiceAbility onStop');
    },
}
```

## Connecting to a Remote Service Ability<a name="section126857614019"></a>

If you need to connect a Service ability to a Page ability on another device or to a Service ability in another application on another device, you must first implement the **IAbilityConnection** interface for the connection. A Service ability allows other abilities on another device to connect to it through **connectAbility()**.

When calling **connectAbility()**, you should pass a **Want** object containing information about the target Service ability and an **IAbilityConnection** object to the method. **IAbilityConnection** provides the following callbacks that you should implement: **onConnect()**, **onDisconnect()**, and **onFailed()**. The **onConnect()** callback is invoked when a Service ability is connected, **onDisconnect()** is invoked when a Service ability is unexpectedly disconnected, and **onFailed()** is invoked when a connection to a Service ability fails.

The following code snippet shows how to implement the callbacks:

```javascript
var mRemote;
function onConnectCallback(element, remote){
    console.log('ConnectRemoteAbility onConnect Callback')
    mRemote = remote;
}

function onDisconnectCallback(element){
    console.log('ConnectRemoteAbility onDisconnect Callback')
}

function onFailedCallback(code){
    console.log('ConnectRemoteAbility onFailed Callback')
}
```

The **Want** of the target Service ability must contain the remote **deviceId**, which can be obtained through **deviceManager**.

The following code snippet shows how to connect to a remote Service ability:

```javascript
import featureAbility from '@ohos.ability.featureability';
var connId = featureAbility.connectAbility(
    {
        deviceId: deviceId,
        bundleName: "com.jstest.serviceability",
        abilityName: "com.jstest.serviceability.MainAbility",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```

When a Service ability is connected, the **onConnect()** callback is invoked and returns an **IRemoteObject** defining the proxy used for communicating with the Service ability. OpenHarmony provides a default implementation of the **IRemoteObject** interface. You can inherit **rpc.RemoteObject** to implement your own class of **IRemoteObject**.

The following code snippet shows how the Service ability instance returns itself to the calling ability:

```javascript
import rpc from "@ohos.rpc";

var mMyStub;
export default {
    onStart(want) {
        class MyStub extends rpc.RemoteObject{
            constructor(des) {
                if (typeof des === 'string') {
                    super(des);
                }
                return null;
            }
            onRemoteRequest(code, message, reply, option) {
            }
        }
        mMyStub = new MyStub("ServiceAbility-test");
    },
    onCommand(want, restart, startId) {
        console.log('ServiceAbility onCommand');
    },
    onConnect(want) {
        console.log('ServiceAbility OnConnect');
        return mMyStub;
    },
    onDisconnect() {
        console.log('ServiceAbility OnDisConnect');
    },
    onStop() {
        console.log('ServiceAbility onStop');
    },
}
```

## Development Example

The following sample is provided to help you better understand how to develop a Service ability:

- [eTSServiceAbility](https://gitee.com/openharmony/app_samples/tree/master/ability/eTSServiceAbility)

This **eTSServiceAbility** sample shows how to:

Create a local Service ability in the **service.ts** file in the **ServiceAbility** directory.

Encapsulate the process of starting and connecting to the local Service ability in the **MainAbility** directory.
