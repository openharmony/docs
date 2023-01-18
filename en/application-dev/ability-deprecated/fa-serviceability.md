# Service Ability Development

## When to Use
A Service ability is used to run tasks in the background, such as playing music or downloading files. It does not provide a UI for user interaction. Service abilities can be started by other applications or abilities and can keep running in the background even after the user switches to another application.

## Lifecycle APIs

**Table 1** Service ability lifecycle APIs
|API|Description|
|:------|:------|
|onStart?(): void|Called to initialize a Service ability when the Service ability is being created. This callback is invoked only once in the entire lifecycle of a Service ability.|
|onCommand?(want: Want, startId: number): void|Called every time a Service ability is created on the client. You can collect calling statistics and perform initialization operations in this callback.|
|onConnect?(want: Want): rpc.RemoteObject|Called when another ability is connected to the Service ability.|
|onDisconnect?(want: Want): void|Called when another ability is disconnected from the Service ability.|
|onStop?(): void|Called when the Service ability is being destroyed. You should override this callback for your Service ability to clear its resources, such as threads and registered listeners.|

The differences between **onCommand()** and **onConnect()** are as follows:
 - The **onCommand()** callback is triggered each time the client starts the Service ability by calling **startAbility** or **startAbilityForResult**.
 - The **onConnect()** callback is triggered each time the client establishes a new connection with the Service ability by calling **connectAbility**.

## How to Develop

### Creating and Registering a Service Ability

1. Override the Service ability-related lifecycle callbacks to implement your own logic for processing interaction requests.
   
    
   
   ```ts
    export default {
        onStart() {
            console.log('ServiceAbility onStart');
        },
        onCommand(want, startId) {
            console.log('ServiceAbility onCommand');
        },
        onConnect(want) {
            console.log('ServiceAbility OnConnect');
            // Below lists the implementation of ServiceAbilityStub.
            return new ServiceAbilityStub('test');
        },
        onDisconnect(want) {
            console.log('ServiceAbility OnDisConnect');
        },
        onStop() {
            console.log('ServiceAbility onStop');
        }
    }
   ```

2. Register a Service ability.

   Declare the Service ability in the **config.json** file by setting its **type** attribute to **service**.
   
   ```json
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

To set information about the target Service ability, you can first construct a **Want** object with the **bundleName** and **abilityName** parameters specified.  

- **bundleName** specifies the bundle name of the target application.
- **abilityName** specifies the target ability name.

The following code snippet shows how to start a Service ability running on the local device:

```ts
import featureAbility from '@ohos.ability.featureAbility'

featureAbility.startAbility(
    {
        want:
        {
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility"
        }
    }
).then((err) => {
    console.log("startService success");
}).catch (err => {
    console.log("startService FAILED");
});
```

In the preceding code, the **startAbility()** API is used to start the Service ability.
- If the Service ability is not running, the system initializes the Service ability, and calls **onStart()** and **onCommand()** on the Service ability in sequence.
- If the Service ability is running, the system directly calls **onCommand()** on the Service ability.

The following code snippet shows how to start a Service ability running on the remote device. For details, see [Connecting to a Remote Service Ability](#connecting-to-a-remote-service-ability).

```ts
import featureAbility from '@ohos.ability.featureAbility'

featureAbility.startAbility(
    {
        want:
        {
            deviceId: remoteDeviceId,    // Remote device ID.
            bundleName: "com.jstest.service",
            abilityName: "com.jstest.service.ServiceAbility"
        }
    }
).then((err) => {
    console.log("startService success");
}).catch (err => {
    console.log("startService FAILED");
});
```


### Stopping a Service Ability

  In normal cases, a Service ability can be stopped by itself or by the system.
   - The Service ability can call **particleAbility.terminateSelf()** to stop itself.
   - If the application process where the Service ability is located exits, the Service ability is reclaimed along with the process.
   - If the Service ability is only accessed through **connectAbility()** (the **onCommand()** callback has never been triggered), the system stops the Service ability when the last connection to the Service ability is disconnected.

### Connecting to a Local Service Ability

If a Service ability wants to interact with a Page ability or a Service ability in another application, you must first create a connection. A Service ability allows other abilities to connect to it through **connectAbility()**.


You can use either of the following methods to connect to a Service ability:

1. Using the IDL to automatically generate code

    Use OpenHarmony Interface Definition Language (IDL) to automatically generate the corresponding client, server, and **IRemoteObject** code. For details, see [Development Using TS](../IDL/idl-guidelines.md#development-using-ts).

2. Writing code in the corresponding file

    When using **connectAbility()**, pass the **Want** and **ConnectOptions** objects of the target Service ability, where **ConnectOptions** encapsulates the following three callbacks that need to be implemented.
     - **onConnect()**: callback used for processing when the Service ability is connected.
     - **onDisconnect()**: callback used for processing when the Service ability is disconnected.
     - **onFailed()**: callback used for processing when the connection to the Service ability fails.

    The following code snippet shows how to implement the callbacks:

    ```ts
    import prompt from '@system.prompt'

    var option = {
        onConnect: function onConnectCallback(element, proxy) {
            console.log(`onConnectLocalService onConnectDone`);
            if (proxy === null) {
                prompt.showToast({
                    message: "Connect service failed"
                });
                return;
            }
            // After obtaining the proxy of the Service ability, the calling ability can communicate with the Service ability.
            let data = rpc.MessageParcel.create();
            let reply = rpc.MessageParcel.create();
            let option = new rpc.MessageOption();
            data.writeString("InuptString");
            proxy.sendRequest(0, data, reply, option);
            prompt.showToast({
                message: "Connect service success"
            });
        },
        onDisconnect: function onDisconnectCallback(element) {
            console.log(`onConnectLocalService onDisconnectDone element:${element}`);
            prompt.showToast({
                message: "Disconnect service success"
            });
        },
        onFailed: function onFailedCallback(code) {
            console.log(`onConnectLocalService onFailed errCode:${code}`);
            prompt.showToast({
                message: "Connect local service onFailed"
            });
        }
    };
    ```

    The following code snippet shows how to connect to a local Service ability:

    ```ts
    import featureAbility from '@ohos.ability.featureAbility'

    let want = {
        bundleName: "com.jstest.service",
        abilityName: "com.jstest.service.ServiceAbility"
    };
    let connectId = featureAbility.connectAbility(want, option);
    ```

    When a Service ability is connected, the **onConnect()** callback is invoked and returns an **IRemoteObject** defining the proxy used for communicating with the Service ability.  OpenHarmony provides the default implementation of **IRemoteObject**. You can inherit **rpc.RemoteObject** to create a custom implementation class for interaction with the Service ability. For details, see the [RPC API Reference](..\reference\apis\js-apis-rpc.md).

    The following code snippet shows how the Service ability returns itself to the calling ability:

    ```ts
    import rpc from "@ohos.rpc"

    class ServiceAbilityStub extends rpc.RemoteObject {
        constructor(des: any) {
            if (typeof des === 'string') {
                super(des);
            } else {
                console.log("Error, the input param is not string");
                return;
            }
        }

        onRemoteRequest(code: number, data: any, reply: any, option: any) {
            console.log("onRemoteRequest called");
            // Execute the service logic.
            if (code === 1) {
                // Sort the input strings.
                let string = data.readString();
                console.log(`Input string = ${string}`);
                let result = Array.from(string).sort().join('');
                console.log(`Output result = ${result}`);
                reply.writeString(result);
            } else {
                console.log(`Unknown request code`);
            }
            return true;
        }
    }

    export default {
        onStart() {
            console.log('ServiceAbility onStart');
        },
        onCommand(want, startId) {
            console.log('ServiceAbility onCommand');
        },
        onConnect(want) {
            console.log('ServiceAbility OnConnect');
            return new ServiceAbilityStub('ServiceAbilityRemoteObject');
        },
        onDisconnect(want) {
            console.log('ServiceAbility OnDisConnect');
        },
        onStop() {
            console.log('ServiceAbility onStop');
        }
    }
    ```

### Connecting to a Remote Service Ability

This feature applies only to system applications. The method of creating a **ConnectOptions** object for connecting to a remote Service ability is similar to that for connecting to a local Service ability. The differences are as follows:
 - The application must apply for the data synchronization permission from the user.
 - **Want** of the target Service ability must contain the remote device ID.

> **NOTE**
>
> The **getTrustedDeviceList** API of **DeviceManager** is open only to system applications. Currently, only system applications can connect to a remote Service ability.
>
> For details about the API definition, see [Device Management](..\reference\apis\js-apis-device-manager.md).

The data synchronization permission is required in the cross-device scenario. Configure the permission in the **config.json** file.

```json
{
  ...
  "module": {
    ...
    "reqPermissions": [{
      "name": "ohos.permission.DISTRIBUTED_DATASYNC"
    }]
  }
}
```

The **DISTRIBUTED_DATASYNC** permission is user granted. Therefore, your application, when being started, must display a dialog box to request the permission. The sample code is as follows:

```ts
import abilityAccessCtrl from "@ohos.abilityAccessCtrl"
import bundle from '@ohos.bundle'

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
        if (result != abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
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

To obtain the device ID, import the **@ohos.distributedHardware.deviceManager** module, which provides **getTrustedDeviceList** to obtain the remote device ID. For details about how to use the API, see [Device Management](..\reference\apis\js-apis-device-manager.md).

To connect to a remote Service ability, you only need to define **deviceId** in **Want**. The sample code is as follows:

```ts
import featureAbility from '@ohos.ability.featureAbility'

let want = {
    deviceId: remoteDeviceId,
    bundleName: "com.jstest.service",
    abilityName: "com.jstest.service.ServiceAbility"
};
let connectId = featureAbility.connectAbility(want, option);
```

The other implementations are the same as those for the connection to a local Service ability. For details, see the sample code provided under [Connecting to a Local Service Ability](#connecting-to-a-local-service-ability).
