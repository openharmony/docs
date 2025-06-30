# @ohos.app.ability.ServiceExtensionAbility (ServiceExtensionAbility) (System API)

The **ServiceExtensionAbility** module provides lifecycle callbacks when a ServiceExtensionAbility (background service) is created, destroyed, connected, or disconnected.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { ServiceExtensionAbility } from '@kit.AbilityKit';
```

## Required Permissions

None.

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext-sys.md)  | Yes| No| ServiceExtensionContext, which is inherited from **ExtensionContext**.|


## ServiceExtensionAbility.onCreate

onCreate(want: Want): void;

Called to initialize the service logic when a ServiceExtensionAbility is being created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Example**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onCreate(want: Want) {
    console.log(`onCreate, want: ${want.abilityName}`);
  }
}
```


## ServiceExtensionAbility.onDestroy

onDestroy(): void;

Called to clear resources when this ServiceExtensionAbility is being destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Example**

```ts
import { ServiceExtensionAbility } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onDestroy() {
    console.log('onDestroy');
  }
}
```


## ServiceExtensionAbility.onRequest

onRequest(want: Want, startId: number): void;

Called following **onCreate()** when a ServiceExtensionAbility is started by calling **startAbility()** or **startServiceExtensionAbility()**. The value of **startId** is incremented for each ServiceExtensionAbility that is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|
| startId | number | Yes| Number of ServiceExtensionAbility start times. The initial value is **1**, and the value is automatically incremented for each ServiceExtensionAbility started.|

**Example**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.log('onRequest, want: ${want.abilityName}');
  }
}
```


## ServiceExtensionAbility.onConnect

onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject>;

Called following **onCreate()** when a ServiceExtensionAbility is started by calling **connectAbility()**. A **RemoteObject** object is returned for communication between the server and client.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md)| Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject) \| Promise\<[rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#remoteobject)> | **RemoteObject** object or Promise used to return a **RemoteObject** object, which is used for communication between the client and server.|

**Example**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

class StubTest extends rpc.RemoteObject{
  constructor(des: string) {
    super(des);
  }
  onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {
  }
}
class ServiceExt extends ServiceExtensionAbility {
  onConnect(want: Want) {
    console.log('onConnect , want: ${want.abilityName}');
    return new StubTest('test');
  }
}
```

If the returned **RemoteObject** object depends on an asynchronous API, you can use the asynchronous lifecycle.

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';
import { rpc } from '@kit.IPCKit';

class StubTest extends rpc.RemoteObject{
  constructor(des: string) {
    super(des);
  }
  onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {
  }
}
async function getDescriptor() {
  // Call the asynchronous function.
  return "asyncTest"
}
class ServiceExt extends ServiceExtensionAbility {
  async onConnect(want: Want) {
    console.log(`onConnect , want: ${want.abilityName}`);
    let descriptor = await getDescriptor();
    return new StubTest(descriptor);
  }
}
```

## ServiceExtensionAbility.onDisconnect

onDisconnect(want: Want): void | Promise\<void>;

Called when a client is disconnected from this ServiceExtensionAbility.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise that returns no value.|

**Example**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onDisconnect(want: Want) {
    console.log('onDisconnect, want: ${want.abilityName}');
  }
}
```

After the **onDisconnect()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDisconnect()** may fail to be executed. The asynchronous lifecycle can be used to ensure that the subsequent lifecycle continues after the asynchronous **onDisconnect()** is complete.

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  async onDisconnect(want: Want) {
    console.log('onDisconnect, want: ${want.abilityName}');
    // Call the asynchronous function.
  }
}
```

## ServiceExtensionAbility.onReconnect

onReconnect(want: Want): void;

Called when a new client attempts to connect to this ServiceExtensionAbility after all previous clients are disconnected. This capability is reserved.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Example**

```ts
import { ServiceExtensionAbility, Want } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onReconnect(want: Want) {
    console.log('onReconnect, want: ${want.abilityName}');
  }
}
```

## ServiceExtensionAbility.onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void;

Called when the configuration of this ServiceExtensionAbility is updated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](js-apis-app-ability-configuration.md) | Yes| New configuration.|

**Example**
    
```ts
import { ServiceExtensionAbility, Configuration } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onConfigurationUpdate(newConfig: Configuration) {
    console.log(`onConfigurationUpdate, config: ${JSON.stringify(newConfig)}`);
  }
}
```

## ServiceExtensionAbility.onDump

onDump(params: Array\<string>): Array\<string>;

Dumps the client information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters in the form of a command.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array\<string> | Array of client information.|

**Example**
    
```ts
import { ServiceExtensionAbility } from '@kit.AbilityKit';

class ServiceExt extends ServiceExtensionAbility {
  onDump(params: Array<string>) {
    console.log(`dump, params: ${JSON.stringify(params)}`);
    return ['params'];
  }
}
```
