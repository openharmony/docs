# Service Extension Ability Development

## When to Use
`ExtensionAbility` is the base class of the new Extension component in the stage model. It is used to process missions without UIs. The lifecycle of an Extension ability is simple and does not involve foreground or background states. `ServiceExtensionAbility` is extended from `ExtensionAbility`.

You can customize a class that inherits from `ServiceExtensionAbility` and override the lifecycle callbacks in the base class to perform service logic operations during the initialization, connection, and disconnection processes.

## Available APIs

**Table 1** ServiceExtensionAbility lifecycle APIs
|API|Description|
|:------|:------|
|onCreate(want: Want): void|Called for the initialization when `startAbility` or `connectAbility` is invoked for a given ability for the first time.|
|onRequest(want: Want, startId: number): void|Called each time `startAbility` is invoked for a given ability. The initial value of `startId` is `1`, and the value is incremented by one each time `startAbility` is invoked for that ability.|
|onConnect(want: Want): rpc.RemoteObject|Called when `connectAbility` is invoked for a given ability. This callback is not invoked for repeated calling of `connectAbility` for a specific ability. However, it will be invoked unless `connectAbility` is called after the ability has been disconnected using `disconnectAbility`. The returned result is a `RemoteObject`.|
|onDisconnect(want: Want): void|Called when `disconnectAbility` is called for a given ability. If the Extension ability is started by `connectAbility` and is not bound to other applications, the `onDestroy` callback will also be triggered to destroy the Extension ability.|
|onDestroy(): void|Called when `terminateSelf` is invoked to terminate the ability.|


## Constraints

OpenHarmony does not support creation of a Service Extension ability for third-party applications.


## How to Develop

1. Declare the Service Extension ability in the `module.json5` file by setting its `type` attribute to `service`. The following is a configuration example of the `module.json5` file:


   ```json
    "extensionAbilities":[{
        "name": "ServiceExtAbility",
        "icon": "$media:icon",
        "description": "service",
        "type": "service",
        "visible": true,
        "srcEntrance": "./ets/ServiceExtAbility/ServiceExtAbility.ts"
    }]
   ```


2. Customize a class that inherits from `ServiceExtensionAbility` in the .ts file in the directory where the Service Extension ability is defined (`entry\src\main\ets\ServiceExtAbility\ServiceExtAbility.ts` by default) and override the lifecycle callbacks of the base class. The code sample is as follows:

    ```js
    import ServiceExtensionAbility from '@ohos.application.ServiceExtensionAbility'
    import rpc from '@ohos.rpc'

    class StubTest extends rpc.RemoteObject {
        constructor(des) {
            super(des);
        }
        onRemoteRequest(code, data, reply, option) {
        }
    }

    class ServiceExtAbility extends ServiceExtensionAbility {
        onCreate(want) {
            console.log('onCreate, want:' + want.abilityName);
        }
        onRequest(want, startId) {
            console.log('onRequest, want:' + want.abilityName);
        }
        onConnect(want) {
            console.log('onConnect , want:' + want.abilityName);
            return new StubTest("test");
        }
        onDisconnect(want) {
            console.log('onDisconnect, want:' + want.abilityName);
        }
        onDestroy() {
            console.log('onDestroy');
        }
    }
    ```

