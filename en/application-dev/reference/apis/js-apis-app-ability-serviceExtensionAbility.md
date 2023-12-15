# @ohos.app.ability.ServiceExtensionAbility (ServiceExtensionAbility)

The **ServiceExtensionAbility** module provides lifecycle callbacks when a ServiceExtensionAbility (background service) is created, destroyed, connected, or disconnected.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs provided by this module are system APIs. 
> The APIs of this module can be used only in the stage model. 

## Modules to Import

```ts
import ServiceExtension from '@ohos.app.ability.ServiceExtensionAbility';
```

## Required Permissions

None.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [ServiceExtensionContext](js-apis-inner-application-serviceExtensionContext.md)  | Yes| No| ServiceExtensionContext, which is inherited from **ExtensionContext**.|


## ServiceExtensionAbility.onCreate

onCreate(want: Want): void;

Called to initialize the service logic when a ServiceExtensionAbility is being created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Example**

  ```ts
  class ServiceExt extends ServiceExtension {
    onCreate(want) {
      console.log('onCreate, want:' + want.abilityName);
    }
  }
  ```


## ServiceExtensionAbility.onDestroy

onDestroy(): void;

Called to clear resources when this ServiceExtensionAbility is being destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Example**

  ```ts
  class ServiceExt extends ServiceExtension {
    onDestroy() {
      console.log('onDestroy');
    }
  }
  ```


## ServiceExtensionAbility.onRequest

onRequest(want: Want, startId: number): void;

Called following **onCreate()** when a ServiceExtensionAbility is started by calling **startAbility()** or **startServiceExtensionAbility()**. The value of **startId** is incremented for each ServiceExtensionAbility that is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|
| startId | number | Yes| Number of ServiceExtensionAbility start times. The initial value is **1**, and the value is automatically incremented for each ServiceExtensionAbility started.|

**Example**

  ```ts
  class ServiceExt extends ServiceExtension {
    onRequest(want, startId) {
      console.log('onRequest, want:' + want.abilityName);
    }
  }
  ```


## ServiceExtensionAbility.onConnect

onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject>;

Called following **onCreate()** when a ServiceExtensionAbility is started by calling **connectAbility()**. A **RemoteObject** object is returned for communication with the client.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md)| Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| rpc.RemoteObject | A **RemoteObject** object used for communication with the client.|

**Example**

  ```ts
  import rpc from '@ohos.rpc';
  class StubTest extends rpc.RemoteObject{
      constructor(des) {
          super(des);
      }
      onConnect(code, data, reply, option) {
      }
  }
  class ServiceExt extends ServiceExtension {
    onConnect(want) {
      console.log('onConnect , want:' + want.abilityName);
      return new StubTest('test');
    }
  }
  ```


## ServiceExtensionAbility.onDisconnect

onDisconnect(want: Want): void | Promise\<void>;

Called when this ServiceExtensionAbility is disconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Example**

  ```ts
  class ServiceExt extends ServiceExtension {
    onDisconnect(want) {
      console.log('onDisconnect, want:' + want.abilityName);
    }
  }
  ```

## ServiceExtensionAbility.onReconnect

onReconnect(want: Want): void;

Called when this ServiceExtensionAbility is reconnected.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| Yes| Want information related to this ServiceExtensionAbility, including the ability name and bundle name.|

**Example**

  ```ts
  class ServiceExt extends ServiceExtension {
    onReconnect(want) {
      console.log('onReconnect, want:' + want.abilityName);
    }
  }
  ```

## ServiceExtensionAbility.onConfigurationUpdate

onConfigurationUpdate(newConfig: Configuration): void;

Called when the configuration of this ServiceExtensionAbility is updated.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| newConfig | [Configuration](js-apis-app-ability-configuration.md) | Yes| New configuration.|

**Example**
    
  ```ts
  class ServiceExt extends ServiceExtension {
      onConfigurationUpdate(config) {
          console.log('onConfigurationUpdate, config:' + JSON.stringify(config));
      }
  }
  ```

## ServiceExtensionAbility.onDump

onDump(params: Array\<string>): Array\<string>;

Dumps the client information.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API and cannot be called by third-party applications.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters in the form of a command.|

**Example**
    
  ```ts
  class ServiceExt extends ServiceExtension {
      onDump(params) {
          console.log('dump, params:' + JSON.stringify(params));
          return ['params'];
      }
  }
  ```
