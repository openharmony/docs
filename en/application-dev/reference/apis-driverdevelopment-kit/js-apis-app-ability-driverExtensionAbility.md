# @ohos.app.ability.DriverExtensionAbility (Driver Extension Ability)
<!--Kit: Driver Development Kit-->
<!--Subsystem: Driver-->
<!--Owner: @lixinsheng2-->
<!--Designer: @w00373942-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @w_Machine_cc-->

The **DriverExtensionAbility** module provides the ExtensionAbility related to drivers. It provides lifecycle callbacks to be invoked when a driver is created, destroyed, connected, or disconnected.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version. 

## Modules to Import

```ts
import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
```


## DriverExtensionAbility

### Attributes

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice


| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [DriverExtensionContext](js-apis-inner-application-driverExtensionContext.md)  | No| No| Context of the **DriverExtension**. This context is inherited from **ExtensionContext**.|

### onInit

onInit(want: Want): void

Called when a DriverExtensionAbility is created to initialize the service logic.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want information related to this DriverExtensionAbility, including the ability name and bundle name.|

**Example**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    onInit(want : Want) {
      console.info('onInit, want: ${want.abilityName}');
    }
  }
  ```

### onRelease

onRelease(): void

Called when this DriverExtensionAbility is destroyed to clear resources.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Example**

  ```ts
  class DriverExt extends DriverExtensionAbility {
    onRelease() {
      console.info('onRelease');
    }
  }
  ```

### onConnect

onConnect(want: Want): rpc.RemoteObject | Promise<rpc.RemoteObject>

Called following **onCreate()** when a DriverExtensionAbility is started by calling **connectAbility()**. A **RemoteObject** object is returned for communication between the server and client.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](../apis-ability-kit/js-apis-app-ability-want.md)| Yes| Want information related to this DriverExtensionAbility, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| rpc.RemoteObject \| Promise<rpc.RemoteObject> | **RemoteObject** object used for communication between the server and client, or promise used to return the value.|

**Example**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { rpc } from '@kit.IPCKit';
  import { Want } from '@kit.AbilityKit';

  class StubTest extends rpc.RemoteObject{
      constructor(des : string) {
          super(des);
      }
      onRemoteMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption) {
        // This interface must be overridden.
        return true;
      }
  }
  class DriverExt extends DriverExtensionAbility {
    onConnect(want : Want) {
      console.info('onConnect , want: ${want.abilityName}');
      return new StubTest('test');
    }
  }
  ```

If the returned **RemoteObject** object depends on an asynchronous API, you can use the asynchronous lifecycle.

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { rpc } from '@kit.IPCKit';
  import { Want } from '@kit.AbilityKit';
  
  class StubTest extends rpc.RemoteObject{
      constructor(des : string) {
          super(des);
      }
      onRemoteMessageRequest(code : number, data : rpc.MessageSequence, reply : rpc.MessageSequence, option : rpc.MessageOption) {
        // This interface must be overridden.
        return true;
      }
  }
  async function getDescriptor() {
      // Call the asynchronous function.
      return "asyncTest";
  }
  class DriverExt extends DriverExtensionAbility {
    async onConnect(want : Want) {
      console.info(`onConnect , want: ${want.abilityName}`);
      let descriptor = await getDescriptor();
      return new StubTest(descriptor);
    }
  }
  ```

### onDisconnect

onDisconnect(want: Want): void | Promise\<void>

Called when a client is disconnected from this DriverExtensionAbility.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](../apis-ability-kit/js-apis-app-ability-want.md)| Yes| Want information related to this DriverExtensionAbility, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| void \| Promise\<void> | Empty value, or promise used to return the value.|

**Example**

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    onDisconnect(want : Want) {
      console.info('onDisconnect, want: ${want.abilityName}');
    }
  }
  ```

After the **onDisconnect** lifecycle callback is executed, the application may exit. As a result, the asynchronous function in **onDisconnect** may fail to be executed correctly, for example, asynchronously writing data to the database. The asynchronous lifecycle can be used to ensure that the subsequent lifecycle continues after the asynchronous **onDisconnect** is complete.

  ```ts
  import { DriverExtensionAbility } from '@kit.DriverDevelopmentKit';
  import { Want } from '@kit.AbilityKit';

  class DriverExt extends DriverExtensionAbility {
    async onDisconnect(want : Want) {
      console.info('onDisconnect, want: ${want.abilityName}');
      // Call the asynchronous function.
    }
  }
  ```


### onDump

onDump(params: Array\<string>): Array\<string>

Dumps client information.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Driver.ExternalDevice

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| params | Array\<string> | Yes| Parameters in the form of a command.|

**Return value**

| Type| Description|
| -------- | -------- |
| Array\<string> | String array used to dump client information.|

**Example**
    
  ```ts
  class DriverExt extends DriverExtensionAbility {
      onDump(params : Array<string>) {
          console.info(`dump, params: ${JSON.stringify(params)}`);
          return ['params'];
      }
  }
  ```

## DriverExtensionContext

type DriverExtensionContext = _DriverExtensionContext;

**DriverExtensionAbility** context.

**System capability**: SystemCapability.Driver.ExternalDevice


| Type| Description|
| -------- | -------- | 
| _DriverExtensionContext | **DriverExtensionAbility** context, which is inherited from **ExtensionContext**. For details about how to use the context, see [DriverExtensionContext](js-apis-inner-application-driverExtensionContext.md).|
