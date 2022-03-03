# ServiceExtension

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides APIs related to **ServiceExtension**.


## Modules to Import

```
import ServiceExtension from '@ohos.application.ServiceExtension';
```


## Required Permissions

None


## Attributes

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| context | [ServiceExtensionContext](js-apis-service-extension-context.md)  | Yes| No| Service extension context, which is inherited from **ExtensionContext**.| 


## onCreate

onCreate(want: Want): void;

Called when an extension is created to initialize the service logic.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-featureAbility.md#Want)| Yes| Information related to this extension, including the ability name and bundle name.| 

- Example
  ```
  class ServiceExt extends ServiceExtension {
    onCreate(want) {
      console.log('onCreate, want:' + want.abilityName);
    }
  }
  ```


## onDestroy

onDestroy(): void;

Called when this extension is destroyed to clear resources.

- Example
  ```
  class ServiceExt extends ServiceExtension {
    onDestroy() {
      console.log('onDestroy');
    }
  }
  ```


## onRequest

onRequest(want: Want, startId: number): void;

Called after **onCreate** is invoked when an ability is started by calling **startAbility**. The value of **startId** is incremented for each ability that is started.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-featureAbility.md#Want)| Yes| Information related to this extension, including the ability name and bundle name.| 
  | startId | number | Yes| Number of ability start times. The initial value is **1**, and the value is automatically incremented for each ability started.| 

- Example
  ```
  class ServiceExt extends ServiceExtension {
    onRequest(want, startId) {
      console.log('onRequest, want:' + want.abilityName);
    }
  }
  ```


## onConnect

onConnect(want: Want): rpc.RemoteObject;

Called after **onCreate** is invoked when an ability is started by calling **connectAbility**. A **RemoteObject** object is returned for communication with the client.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want |  [Want](js-apis-featureAbility.md#Want)| Yes| Information related to this extension, including the ability name and bundle name.| 

- Return value
  | Type| Description| 
  | -------- | -------- |
  | rpc.RemoteObject | A **RemoteObject** object used for communication with the client.| 

- Example
  ```
  import rpc from '@ohos.rpc'
  class StubTest extends rpc.RemoteObject{
      constructor(des) {
          super(des);
      }
      onRemoteRequest(code, data, reply, option) {
      }
  }
  class ServiceExt extends ServiceExtension {
    onConnect(want) {
      console.log('onConnect , want:' + want.abilityName);
      return new StubTest("test");
    }
  }
  ```


## onDisconnect

onDisconnect(want: Want): void;

Called when the ability is disconnected.

- Parameters
  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want |[Want](js-apis-featureAbility.md#Want)| Yes| Information related to this extension, including the ability name and bundle name.| 

- Example
  ```
  class ServiceExt extends ServiceExtension {
    onDisconnect(want) {
      console.log('onDisconnect, want:' + want.abilityName);
    }
  }
  ```
