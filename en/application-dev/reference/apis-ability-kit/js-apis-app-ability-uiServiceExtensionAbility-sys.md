# @ohos.app.ability.UIServiceExtensionAbility (UIServiceExtensionAbility) (System API)

UIServiceExtensionAbility provides extended capabilities related to the floating window component. It inherits from [ExtensionAbility](js-apis-app-ability-extensionAbility.md). It is mainly used to provide services with UIs for third-party applications.


> **NOTE**
>
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module must be used in the main thread, but not in child threads such as Worker and TaskPool.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
```

## UIServiceExtensionAbility

### Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [UIServiceExtensionContext](js-apis-inner-application-uiserviceExtensionContext-sys.md) | No| No| Context environment for a [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md). This context inherits from [ExtensionContext](js-apis-inner-application-extensionContext.md).|


### onCreate

onCreate(want: Want): void

Called to initialize the service logic.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- |  -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes | No| [Want](js-apis-app-ability-want.md) information about the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md), including the ability name and bundle name.|

**Example**

```ts
import { UIServiceExtensionAbility, Want } from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  // Create a UIServiceExtensionAbility.
  onCreate(want: Want) {
    console.info(`onCreate, want: ${want.abilityName}`);
  }
}
```


### onRequest

onRequest(want: Want, startId: number): void

Called to request to start a [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md). If the UIServiceExtensionAbility is started by calling [startAbility](js-apis-inner-application-uiAbilityContext.md#startability) or [startUIServiceExtensionAbility](js-apis-inner-application-uiAbilityContext.md#startuiserviceextensionability14), this callback will be invoked after [onCreate](#oncreate). The value of **startId** is incremented for each UIServiceExtensionAbility that is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md) | Yes| No|  [Want](js-apis-app-ability-want.md) information about the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md), including the ability name and bundle name.|
| startId | number | Yes| Number of times the instance has been started. The initial value is **1** for the first start, and it increments automatically for subsequent starts.|

**Example**

```ts
import { UIServiceExtensionAbility, Want} from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  onRequest(want: Want, startId: number) {
    console.info('onRequest, want:' + want.abilityName + ', startId:' + startId);
  }
}
```


### onConnect

onConnect(want: Want, proxy: UIServiceHostProxy): void

Called when the connection to a [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md) is established. If the UIServiceExtensionAbility is started by calling [connectUIServiceExtensionAbility()](js-apis-inner-application-uiExtensionContext.md#connectuiserviceextensionability14), this callback will be invoked after [onCreate()](#oncreate). This callback receives a [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) object for communication between the client and server.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| want |  [Want](js-apis-app-ability-want.md)| Yes| No| [Want](js-apis-app-ability-want.md) information about the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md), including the ability name and bundle name.|
| proxy | [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) | Yes| No| [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) object, used for communication between the client and server.|


**Example**

```ts
import { UIServiceExtensionAbility, Want, common} from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  onConnect(want: Want, proxy: common.UIServiceHostProxy){
    console.info('onConnect, want:' + want.abilityName + '');
  }
}
```


### onDisconnect

onDisconnect(want: Want, proxy: UIServiceHostProxy): void

Called when the connection to a [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md) is interrupted.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| want |[Want](js-apis-app-ability-want.md)| Yes| No| [Want](js-apis-app-ability-want.md) information about the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md), including the ability name and bundle name.|
| proxy |[UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md)| Yes| No| Proxy that sends data to the sender.|

**Example**

```ts
import { UIServiceExtensionAbility, Want, common } from '@kit.AbilityKit';

class UIServiceExt extends UIServiceExtensionAbility {
  onDisconnect(want: Want, proxy: common.UIServiceHostProxy) {
    console.info('onDisconnect, want: ${want.abilityName}');
  }
}
```


### onWindowWillCreate

onWindowWillCreate(config: window.ExtensionWindowConfig): void

Called when a window will be created for the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md). Through **window.ExtensionWindowConfig** in the callback, the foreground application sends the parameters for creating the window to the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md).

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| config |[window.ExtensionWindowConfig](../apis-arkui/js-apis-window-sys.md#extensionwindowconfig14)| Yes| No| Window configuration information.|

**Example**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class UIServiceExt extends UIServiceExtensionAbility {
  onWindowWillCreate(config : window.ExtensionWindowConfig){
    console.info('onWindowWillCreate');
  }
}
```

### onWindowDidCreate

onWindowDidCreate(window: window.Window): void

Called when a window is created for the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md). Through this callback, the [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md) passes the created window object to the foreground application.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- |  -------- |
| window | [window.Window](../apis-arkui/js-apis-window-sys.md#window) | Yes| No| Window object created.|

**Example**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class ServiceExt extends UIServiceExtensionAbility {
  onWindowDidCreate(window : window.Window){
    console.info('onWindowDidCreate');
  }
}
```

### onData

onData(proxy: UIServiceHostProxy, data: Record&lt;string, Object&gt;): void

Callback invoked when data is received.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- |  -------- |
| proxy | [UIServiceHostProxy](js-apis-inner-application-uiservicehostproxy-sys.md) | Yes| No| Proxy that sends data to the client.|
| data | Record&lt;string, Object&gt; | Yes| No| Data received.|

**Example**

```ts
import { UIServiceExtensionAbility, common} from '@kit.AbilityKit';

class ServiceExt extends UIServiceExtensionAbility {
  onData(proxy : common.UIServiceHostProxy, data : Record<string, Object> ){
    console.info('onData');
  }
}
```

### onDestroy

onDestroy(): void

Called to clear resources when this [UIServiceExtensionAbility](js-apis-app-ability-uiServiceExtensionAbility-sys.md) is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Example**

```ts
import { UIServiceExtensionAbility } from '@kit.AbilityKit';

class ServiceExt extends UIServiceExtensionAbility {
  onDestroy() {
    console.info('onDestroy');
  }
}
```
