# @ohos.app.ability.AppServiceExtensionAbility (ExtensionAbility for Application Background Services)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The AppServiceExtensionAbility module provides extended capabilities for background services, including lifecycle callbacks for creating, destroying, connecting, and disconnecting background services.

> **NOTE**
>
> The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Constraints

- Currently, only 2-in-1 devices are supported.
- To integrate an AppServiceExtensionAbility, applications must request the ACL permission (ohos.permission.SUPPORT_APP_SERVICE_EXTENSION). This ACL permission is available only for enterprise applications.

## Lifecycle

The AppServiceExtensionAbility provides the following lifecycle callbacks: [onCreate()](#oncreate), [onRequest()](#onrequest), [onConnect()](#onconnect), [onDisconnect()](#ondisconnect), and [onDestroy()](#ondestroy). You can override the callback methods as required. The following figure shows the AppServiceExtensionAbility lifecycle.

![AppServiceExtensionAbility-lifecycle](figures/AppServiceExtensionAbility-lifecycle.png)

- **onCreate**
  Called when an AppServiceExtensionAbility instance is created.

- **onDestroy**
  Called when an AppServiceExtensionAbility instance is destroyed.

- **onRequest**
  Called when an AppServiceExtensionAbility instance is started by calling [startAppServiceExtensionAbility()](js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20).

- **onConnect**
  Called when an AppServiceExtensionAbility instance is connected by calling [connectAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20).

- **onDisconnect**
  Called when all connections to an AppServiceExtensionAbility instance are interrupted.

## Modules to Import

```ts
import { AppServiceExtensionAbility } from '@kit.AbilityKit';
```

## AppServiceExtensionAbility

AppServiceExtensionAbility provides extended capabilities for background services, including lifecycle callbacks for creating, destroying, connecting, and disconnecting background services.

### Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [AppServiceExtensionContext](js-apis-inner-application-appServiceExtensionContext.md)  | No| No| Context environment for an AppServiceExtensionAbility. This context inherits from [ExtensionContext](js-apis-inner-application-extensionContext.md).|


### onCreate

onCreate(want: Want): void

Called when an AppServiceExtensionAbility instance is created. Applications can perform initialization operations, such as registering common event listeners, in this callback.

> **NOTE**
>
> If an AppServiceExtensionAbility instance has already been created, the **onCreate()** callback is not invoked again when the instance is started or connected.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes| Want information about the target AppServiceExtensionAbility instance, including the ability name and bundle name.|

**Example**

  ```ts
  import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = '[AppServiceExtAbility]';

  class AppServiceExtAbility extends AppServiceExtensionAbility {
    onCreate(want: Want) {
      hilog.info(0x0000, TAG, `onCreate, want: ${want.abilityName}`);
    }
  }
  ```

### onDestroy

onDestroy(): void

Called when an AppServiceExtensionAbility instance is destroyed. Applications can perform resource cleanup operations, such as unregistering listeners, in this callback.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Example**

  ```ts
  import { AppServiceExtensionAbility } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = '[AppServiceExtAbility]';

  class AppServiceExtAbility extends AppServiceExtensionAbility {
    onDestroy() {
      hilog.info(0x0000, TAG, `onDestroy`);
    }
  }
  ```

### onRequest

onRequest(want: Want, startId: number): void

Called when an AppServiceExtensionAbility instance is started by calling [startAppServiceExtensionAbility()](js-apis-inner-application-uiAbilityContext.md#startappserviceextensionability20).

- If the instance has already been created, this callback is invoked directly.
- If the instance has not been created before, the system first creates the instance and triggers the [onCreate()](#oncreate) callback, followed by this callback.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes| Want information about the target AppServiceExtensionAbility instance, including the ability name and bundle name.|
| startId | number | Yes| Number of times the instance has been started. The initial value is **1** for the first start, and it increments automatically for subsequent starts.|

**Example**

  ```ts
  import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = '[AppServiceExtAbility]';

  class AppServiceExtAbility extends AppServiceExtensionAbility {
    onRequest(want: Want, startId: number) {
      hilog.info(0x0000, TAG, `onRequest, want: ${want.abilityName}, startId: ${startId}`);
    }
  }
  ```

### onConnect

onConnect(want: Want): rpc.RemoteObject

Called when an AppServiceExtensionAbility instance is connected by calling [connectAppServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#connectappserviceextensionability20).

- If the instance has already been created, this callback is invoked directly.
- If the instance has not been created before, the system first creates the instance and triggers the [onCreate()](#oncreate) callback, followed by this callback.

Applications need to return a RemoteObject in this callback for communication between the client and the server. When an AppServiceExtensionAbility instance is in a connected state, if the caller initiates a new connection, the system returns the cached RemoteObject instead of calling **onConnect()** again.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md)| Yes| Want information about the target AppServiceExtensionAbility instance, including the ability name and bundle name.|

**Return value**

| Type| Description|
| -------- | -------- |
| [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | A RemoteObject used for communication between the server and client.|

**Example**

  ```ts
  import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = '[AppServiceExtAbility]';

  class StubTest extends rpc.RemoteObject {
    constructor(des: string) {
      super(des);
    }

    onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {
    }
  }

  class AppServiceExtAbility extends AppServiceExtensionAbility {
    onConnect(want: Want) {
      hilog.info(0x0000, TAG, `onConnect, want: ${want.abilityName}`);
      return new StubTest('test');
    }
  }
  ```

### onDisconnect

onDisconnect(want: Want): void

Called when all connections to an AppServiceExtensionAbility instance are interrupted.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| Yes| Want information passed by the caller when the AppServiceExtensionAbility instance was most recently started or connected. This includes information such as the ability name and bundle name.|

**Example**

  ```ts
  import { AppServiceExtensionAbility, Want } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = '[AppServiceExtAbility]';

  class AppServiceExtAbility extends AppServiceExtensionAbility {
    onDisconnect(want: Want) {
      hilog.info(0x0000, TAG, `onDisconnect, want: ${want.abilityName}`);
    }
  }
  ```
