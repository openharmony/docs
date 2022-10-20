# Service Ability Development

## When to Use
A Service ability is used to run tasks in the background, such as playing music or downloading files. It does not provide a UI for user interaction. Service abilities can be started by other applications or abilities and can remain running in the background even after the user switches to another application.

## Available APIs

**Table 1** Service ability lifecycle APIs
|API|Description|
|:------|:------|
|onStart?(): void|Called to initialize a Service ability being created. This callback is invoked only once in the entire lifecycle of a Service ability. The **Want** object passed to this callback must be null.|
|onCommand?(want: Want, startId: number): void|Called every time a Service ability is created on a client. You can collect calling statistics and perform initialization operations in this callback.|
|onConnect?(want: Want): rpc.RemoteObject|Called when another ability is connected to the Service ability.|
|onDisconnect?(want: Want): void|Called when another ability is disconnected from the Service ability.|
|onStop?(): void|Called when the Service ability is being destroyed. You should override this callback for your Service ability to clear its resources, such as threads and registered listeners.|

## How to Develop

### Creating and Registering a Service Ability

1. Override the Service ability-related lifecycle callbacks to implement your own logic for processing interaction requests.
   
   ```javascript
   export default {
       onStart() {
           console.log('ServiceAbility onStart');
       },
       onCommand(want, startId) {
           console.log('ServiceAbility onCommand');
       },
       onConnect(want) {
           console.log('ServiceAbility OnConnect');
           return new FirstServiceAbilityStub('test');
       },
       onDisconnect(want) {
           console.log('ServiceAbility OnDisConnect');
       },
       onStop() {
           console.log('ServiceAbility onStop');
       },
   }
   ```
   
2. Register a Service ability.

   Declare the Service ability in the **config.json** file by setting its **type** attribute to **service**.
   
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



### Starting a Service Ability

The **Ability** class provides the **startAbility()** API for you to start another Service ability by passing a **Want** object.

To set information about the target Service ability, you can first construct a **Want** object with the **bundleName** and **abilityName** parameters specified. The meanings of the parameters are as follows:

- **bundleName** indicates the name of the bundle to which the target ability belongs.
- **abilityName** indicates the target ability name.

The following code snippet shows how to start a Service ability running on the local device:

```javascript
import featureAbility from '@ohos.ability.featureAbility';
let promise = featureAbility.startAbility(
    {
        want:
        {
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility",
        },
    }
); 
```

After the preceding code is executed, the **startAbility()** API is called to start the Service ability.
- If the Service ability is not running, the system calls **onStart()** to initialize the Service ability, and then calls **onCommand()** on the Service ability.
- If the Service ability is running, the system directly calls **onCommand()** on the Service ability.

The following code snippet shows how to start a Service ability running on the remote device. For details about **getRemoteDeviceId()**, see [Connecting to a Remote Service Ability](#connecting-to-a-remote-service-ability).

```javascript
import featureAbility from '@ohos.ability.featureAbility';
let promise = featureAbility.startAbility(
    {
        want:
        {
            deviceId: getRemoteDeviceId(),    // Remote device ID
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility",
        },
    }
); 
```


### Stopping a Service Ability

Once created, the Service ability keeps running in the background. The system does not stop or destroy it unless memory resources must be reclaimed.

### Connecting to a Local Service Ability

If you need to connect a Service ability to a Page ability or to a Service ability in another application, you must first implement the **IAbilityConnection** API for the connection. A Service ability allows other abilities to connect to it through **connectAbility()**.


You can use either of the following methods to connect to a Service ability:

1. Using the IDL to automatically generate code

    Use OpenHarmony Interface Definition Language (IDL) to automatically generate the corresponding client, server, and **IRemoteObject** code. For details, see “Development Using TS" in [OpenHarmony IDL Specifications and User Guide](../IDL/idl-guidelines.md).

2. Writing code in the corresponding file

    When calling **connectAbility()**, you should pass a **Want** object containing information about the target Service ability and an **IAbilityConnection** object to the API. **IAbilityConnection** provides the following callbacks that you should implement: **onConnect()**, **onDisconnect()**, and **onFailed()**. The **onConnect()** callback is invoked when a Service ability is connected, **onDisconnect()** is invoked when a Service ability is unexpectedly disconnected, and **onFailed()** is invoked when a connection to a Service ability fails.

    The following code snippet shows how to implement the callbacks:

    ```javascript
    import prompt from '@system.prompt'

    var option = {
        onConnect: function onConnectCallback(element, proxy) {
            console.log(`onConnectLocalService onConnectDone`)
            if (proxy === null) {
                prompt.showToast({
                    message: "Connect service failed"
                })
                return
            }
            let data = rpc.MessageParcel.create()
            let reply = rpc.MessageParcel.create()
            let option = new rpc.MessageOption()
            data.writeInterfaceToken("connect.test.token")
            proxy.sendRequest(0, data, reply, option)
            prompt.showToast({
                message: "Connect service success"
            })
        },
        onDisconnect: function onDisconnectCallback(element) {
            console.log(`onConnectLocalService onDisconnectDone element:${element}`)
            prompt.showToast({
                message: "Disconnect service success"
            })
        },
        onFailed: function onFailedCallback(code) {
            console.log(`onConnectLocalService onFailed errCode:${code}`)
            prompt.showToast({
                message: "Connect local service onFailed"
            })
        }
    }
    ```

    The following code snippet shows how to connect to a local Service ability:

    ```javascript
    import featureAbility from '@ohos.ability.featureAbility';
    let connId = featureAbility.connectAbility(
        {
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility",
        },
        {
            onConnect: onConnectCallback,
            onDisconnect: onDisconnectCallback,
            onFailed: onFailedCallback,
        },
    );
    ```

    When a Service ability is connected, the **onConnect()** callback is invoked and returns an **IRemoteObject** defining the proxy used for communicating with the Service ability. OpenHarmony provides a default implementation of **IRemoteObject**. You can extend **rpc.RemoteObject** to implement your own class of **IRemoteObject**.

    The following code snippet shows how the Service ability instance returns itself to the calling ability:

    ```javascript
    import rpc from "@ohos.rpc";

    class FirstServiceAbilityStub extends rpc.RemoteObject {
    constructor(des: any) {
        if (typeof des === 'string') {
            super(des)
        } else {
            return
        }
    }

    onRemoteRequest(code: number, data: any, reply: any, option: any) {
        console.log(printLog + ` onRemoteRequest called`)
        if (code === 1) {
            let string = data.readString()
            console.log(printLog + ` string=${string}`)
            let result = Array.from(string).sort().join('')
            console.log(printLog + ` result=${result}`)
            reply.writeString(result)
        } else {
            console.log(printLog + ` unknown request code`)
        }
        return true;
    }
    ```

### Connecting to a Remote Service Ability

>**NOTE**
>
>This feature applies only to system applications, since the **getTrustedDeviceListSync** API of the **DeviceManager** class is open only to system applications.

If you need to connect a Service ability to a Page ability or another Service ability on a remote device, you must first implement the **IAbilityConnection** interface for the connection. A Service ability allows abilities on another device to connect to it through **connectAbility()**.

When calling **connectAbility()**, you should pass a **Want** object containing information about the target Service ability and an **IAbilityConnection** object to the API. **IAbilityConnection** provides the following callbacks that you should implement: **onConnect()**, **onDisconnect()**, and **onFailed()**. The **onConnect()** callback is invoked when a Service ability is connected, **onDisconnect()** is invoked when a Service ability is unexpectedly disconnected, and **onFailed()** is invoked when a connection to a Service ability fails.

The following code snippet shows how to implement the callbacks:

```ts
import prompt from '@system.prompt'

var option = {
    onConnect: function onConnectCallback(element, proxy) {
        console.log(`onConnectRemoteService onConnectDone`)
        if (proxy === null) {
            prompt.showToast({
                message: "Connect service failed"
            })
            return
        }
        let data = rpc.MessageParcel.create()
        let reply = rpc.MessageParcel.create()
        let option = new rpc.MessageOption()
        data.writeInterfaceToken("connect.test.token")
        proxy.sendRequest(0, data, reply, option)
        prompt.showToast({
            message: "Connect service success"
        })
    },
    onDisconnect: function onDisconnectCallback(element) {
        console.log(`onConnectRemoteService onDisconnectDone element:${element}`)
        prompt.showToast({
            message: "Disconnect service success"
        })
    },
    onFailed: function onFailedCallback(code) {
        console.log(`onConnectRemoteService onFailed errCode:${code}`)
        prompt.showToast({
            message: "Connect local service onFailed"
        })
    }
}
```

The **Want** of the target Service ability must contain the remote **deviceId**, which can be obtained from **DeviceManager**. The sample code is as follows:

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';

// For details about the implementation of dmClass, see the implementation in Distributed Demo in Samples.
let dmClass;

function getRemoteDeviceId() {
    if (typeof dmClass === 'object' && dmClass != null) {
        let list = dmClass.getTrustedDeviceListSync();
        if (typeof (list) == 'undefined' || typeof (list.length) == 'undefined') {
            console.log("MainAbility onButtonClick getRemoteDeviceId err: list is null");
            return;
        }
        console.log("MainAbility onButtonClick getRemoteDeviceId success:" + list[0].deviceId);
        return list[0].deviceId;
    } else {
        console.log("MainAbility onButtonClick getRemoteDeviceId err: dmClass is null");
    }
}
```

The following code snippet shows how to connect to a remote Service ability:

```ts
import featureAbility from '@ohos.ability.featureAbility';
let connId = featureAbility.connectAbility(
    {
        deviceId: getRemoteDeviceId(),
        bundleName: "ohos.samples.etsDemo",
        abilityName: "ohos.samples.etsDemo.ServiceAbility",
    },
    {
        onConnect: onConnectCallback,
        onDisconnect: onDisconnectCallback,
        onFailed: onFailedCallback,
    },
);
```
In the cross-device scenario, the application must also apply for the data synchronization permission from end users. The sample code is as follows:

```ts
import abilityAccessCtrl from "@ohos.abilityAccessCtrl";
import bundle from '@ohos.bundle';
async function RequestPermission() {
  console.info('RequestPermission begin');
  let array: Array<string> = ["ohos.permission.DISTRIBUTED_DATASYNC"];
  let bundleFlag = 0;
  let tokenID = undefined;
  let userID = 100;
  let appInfo = await bundle.getApplicationInfo('ohos.samples.etsDemo', bundleFlag, userID);
  tokenID = appInfo.accessTokenId;
  let atManager = abilityAccessCtrl.createAtManager();
  let requestPermissions: Array<string> = [];
  for (let i = 0;i < array.length; i++) {
    let result = await atManager.verifyAccessToken(tokenID, array[i]);
    console.info("verifyAccessToken result:" + JSON.stringify(result));
    if (result == abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
    } else {
      requestPermissions.push(array[i]);
    }
  }
  console.info("requestPermissions:" + JSON.stringify(requestPermissions));
  if (requestPermissions.length == 0 || requestPermissions == []) {
    return;
  }
  let context = featureAbility.getContext();
  context.requestPermissionsFromUser(requestPermissions, 1, (data)=>{
    console.info("data:" + JSON.stringify(data));
  });
  console.info('RequestPermission end');
}
```

When a Service ability is connected, the **onConnect()** callback is invoked and returns an **IRemoteObject** defining the proxy used for communicating with the Service ability. OpenHarmony provides a default implementation of **IRemoteObject**. You can extend **rpc.RemoteObject** to implement your own class of **IRemoteObject**.

The following code snippet shows how the Service ability instance returns itself to the calling ability:

```ts
import rpc from "@ohos.rpc";

class FirstServiceAbilityStub extends rpc.RemoteObject {
    constructor(des: any) {
        if (typeof des === 'string') {
            super(des)
        } else {
            return
        }
    }

    onRemoteRequest(code: number, data: any, reply: any, option: any) {
        console.log(printLog + ` onRemoteRequest called`)
        if (code === 1) {
            let string = data.readString()
            console.log(printLog + ` string=${string}`)
            let result = Array.from(string).sort().join('')
            console.log(printLog + ` result=${result}`)
            reply.writeString(result)
        } else {
            console.log(printLog + ` unknown request code`)
        }
        return true;
    }
}

export default {
    onStart() {
        console.info('ServiceAbility onStart');
    },
    onStop() {
        console.info('ServiceAbility onStop');
    },
    onConnect(want) {
        console.log("ServiceAbility onConnect");
        try {
            let value = JSON.stringify(want);
            console.log("ServiceAbility want:" + value);
        } catch(error) {
            console.log("ServiceAbility error:" + error);
        }
        return new FirstServiceAbilityStub("first ts service stub");
    },
    onDisconnect(want) {
        console.log("ServiceAbility onDisconnect");
        let value = JSON.stringify(want);
        console.log("ServiceAbility want:" + value);
    },
    onCommand(want, startId) {
        console.info('ServiceAbility onCommand');
        let value = JSON.stringify(want);
        console.log("ServiceAbility want:" + value);
        console.log("ServiceAbility startId:" + startId);
    }
};
```
