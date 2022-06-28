# Service Extension Ability Development

## When to Use
**ExtensionAbility** is the base class of the new Extension component in the stage model. It is used to process missions without UIs. The lifecycle of an Extension ability is simple and does not involve foreground or background. **ServiceExtensionAbility** is extended from **ExtensionAbility**.

You can customize a class that inherits from **ServiceExtensionAbility** and override the lifecycle callbacks in the base class to perform service logic operations during the initialization, connection, and disconnection processes.

## Available APIs

**Table 1** ServiceExtensionAbility lifecycle callbacks
|API|Description|
|:------|:------|
|onCreate|Called for the initialization when **startAbility** or **connectAbility** is invoked for a given ability for the first time.|
|onRequest|Called each time **startAbility** is invoked for a given ability. The initial value of **startId** is 1, and the value is incremented by one each time **startAbility** is invoked for that ability.|
|onConnect|Called when **connectAbility** is invoked for a given ability. This callback is not invoked for repeated calling of **connectAbility** for a specific ability. However, it will be invoked when **disconnectAbility** is called to disconnect an ability and then **connectAbility** is called to connect the ability again. The returned result is a **RemoteObject**.|
|onDisconnect|Called when **disconnectAbility** is called for a given ability. If the Extension ability is started by **connectAbility** and is not bound by other applications, the **onDestroy** callback will also be triggered to destroy the Extension ability.|
|onDestroy|Called when **terminateSelf** is invoked to terminate the ability.|


## Constraints

- Currently, OpenHarmony does not support creation of a Service Extension ability for third-party applications.


## How to Develop

1. Create a Service Extension ability.

Customize a class that inherits from **ServiceExtensionAbility** in the .ts file and override the lifecycle callbacks of the base class. The code sample is as follows:

  ```js
  import rpc from '@ohos.rpc'
  class StubTest extends rpc.RemoteObject {
    constructor(des) {
          super(des);
    }
    onRemoteRequest(code, data, reply, option) {
    }
  }

  class ServiceExt extends ServiceExtensionAbility {
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


2. Register the Service Extension ability.

Declare the Service Extension ability in the **module.json** file by setting its **type** attribute to **service**.

**module.json configuration example**

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

## Development Example

The following sample is provided to help you better understand how to develop a Service Extension ability:

- [`ServiceExtAbility`: Stage Extension Ability Creation and Usage (eTS, API version 9)](https://gitee.com/openharmony/app_samples/tree/master/ability/ServiceExtAbility)

