# @ohos.selectionInput.SelectionExtensionAbility (SelectionExtensionAbility)

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @no86-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=1210a92867c5c546bcdf34b618914a517e85d135 translatedAt=2026-08-04T10:36:04.260Z pushedAt=2026-08-05T11:50:08.567Z -->

This module provides APIs for word selection extension, which can implement extended interactions such as searching and translating text using a mouse or touchpad. Word selection extension services can be customized by inheriting SelectionExtensionAbility. You need to declare this ExtensionAbility in the project configuration. For details, see [Developing a Word Selection Extension Ability](../../basic-services/selectionInput/selection-services-application-guide.md). This module provides the following capabilities:

- Lifecycle management: Use the [onConnect](#onconnect) and [onDisconnect](#ondisconnect) callbacks to process the connection and disconnection logic.

- **context**: You can use **context** to call [startAbility](js-apis-selectionInput-selectionExtensionContext.md#startability) to start the target ability in the same app, or use **context** as an input parameter of [createPanel](js-apis-selectionInput-selectionManager.md#createpanel) to create a word selection panel.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module is supported only on PCs/2-in-1 devices. You can use **canIUse('SystemCapability.SelectionInput.Selection')** to check whether the current device supports the capability.

## Modules to Import

```ts
import { SelectionExtensionAbility } from '@kit.BasicServicesKit';
```

## SelectionExtensionAbility

**System capability**: SystemCapability.SelectionInput.Selection

**Model restriction**: This API can be used only in the stage model.

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [SelectionExtensionContext](./js-apis-selectionInput-selectionExtensionContext.md) | No | No | Context of the **SelectionExtensionAbility**. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md). You can use **context** to call [startAbility](js-apis-selectionInput-selectionExtensionContext.md#startability) to start the target ability in the same app, or use **context** as an input parameter of [createPanel](js-apis-selectionInput-selectionManager.md#createpanel) to create a word selection panel. |

### onConnect

onConnect(want: Want): rpc.RemoteObject

Defines a callback triggered when the client connects to the **SelectionExtensionAbility**. You can return an RPC object in this callback to establish an IPC connection between the client and the server. You need to return a communication stub object that inherits **rpc.RemoteObject**. The system passes the stub object to the client, which then uses the stub object to communicate with the **SelectionExtensionAbility** through IPC.

**System capability**: SystemCapability.SelectionInput.Selection

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type         | Mandatory| Description                            |
| ------ | ----------- | ---- | ------------------------------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | Yes | **Want** object passed by the system when the **SelectionExtensionAbility** is connected. The object contains the description information such as the ability name and bundle name. It is used to obtain the ability connection configuration in the **onConnect** callback so that the corresponding initialization logic can be executed. |

**Return value**

| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | **RemoteObject** communication stub object. You need to implement the remote message processing method (for example, **onRemoteMessageRequest**) of this object. The system passes this object to the client for IPC.  |

**Example**

```ts
import { SelectionExtensionAbility } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[SelectionExtensionAbility]';

// Define the RPC stub class for IPC between the client and server.
class StubTest extends rpc.RemoteObject {
  constructor(descriptor: string) {
    super(descriptor);
  }
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption
  ): boolean | Promise<boolean> {
    return true;
  }
}

class ServiceExtAbility extends SelectionExtensionAbility {
  // Implement the onConnect lifecycle callback to return the RPC object when the client connects to the SelectionExtensionAbility.
  onConnect(want: Want): rpc.RemoteObject {
    hilog.info(0x0000, TAG, `onConnect, want: ${want.abilityName}`);
    // Return the RPC stub object for establishing IPC between the client and server.
    return new StubTest('test');
  }
}
```

### onDisconnect

onDisconnect(): void

Defines a callback triggered when the client disconnects from the **SelectionExtensionAbility** (for example, when the user disables the word selection function or switches the word selection app). You can perform cleanup operations for the **onConnect** callback in this callback. For example, you can  call [destroyPanel](js-apis-selectionInput-selectionManager.md#destroypanel) to destroy the created panel, or call [off('selectionCompleted')](js-apis-selectionInput-selectionManager.md#selectionmanageroffselectioncompleted) to unsubscribe from the word selection completion event.

The callback is triggered only when the **SelectionExtensionAbility** is disconnected normally. It is not triggered in cases of abnormal disconnection (for example, process termination due to low memory conditions).

**System capability**: SystemCapability.SelectionInput.Selection

**Model restriction**: This API can be used only in the stage model.

**Example**

```ts
import { SelectionExtensionAbility } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[SelectionExtensionAbility]';

class ServiceExtAbility extends SelectionExtensionAbility {
  // Implement the onDisconnect lifecycle callback to perform cleanup operations when the client disconnects from the SelectionExtensionAbility.
  onDisconnect(): void {
    hilog.info(0x0000, TAG, `onDisconnect`);
  }
}
```