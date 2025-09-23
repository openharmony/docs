# @ohos.selectionInput.SelectionExtensionAbility (SelectionExtensionAbility) (System API)

This module provides ExtensionAbility for word selection, allowing users to search or translate text selected using a mouse or touchpad.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { SelectionExtensionAbility } from '@kit.BasicServicesKit';
```
## SelectionExtensionAbility

### Properties

**System capability**: SystemCapability.SelectionInput.Selection

| Name| Type| Read-Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| context | [SelectionExtensionContext](./js-apis-selectionInput-selectionExtensionContext-sys.md) | No| No| Context of the SelectionExtensionAbility. This context is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).|

### onConnect

onConnect(want: Want): rpc.RemoteObject

Called when the SelectionExtensionAbility instance is created. You can execute initialization logic (such as defining variables, loading resources, and listening for word selection events) within this callback.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name| Type         | Mandatory| Description                            |
| ------ | ----------- | ---- | ------------------------------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes| Want information of the SelectionExtensionAbility, including the ability name and bundle name.|

**Return value**
| Type  | Description                                                                |
| ------- | ------------------------------------------------------------------ |
| [rpc.RemoteObject](../apis-ipc-kit/js-apis-rpc.md#iremoteobject) | Remote object, which is used for communication between the client and server. |

**Example**

```ts
import { SelectionExtensionAbility } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[SelectionExtensionAbility]';

class StubTest extends rpc.RemoteObject {
  constructor(des: string) {
    super(des);
  }
  onConnect(code: number, data: rpc.MessageSequence, reply: rpc.MessageSequence, option: rpc.MessageOption) {
  }
}

class ServiceExtAbility extends SelectionExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
    hilog.info(0x0000, TAG, `onConnect, want: ${want.abilityName}`);
    return new StubTest('test');
  }
}
```

### onDisconnect

onDisconnect(): void

Called when the **SelectionExtensionAbility** instance is destroyed (for example, when the user disables the word selection function or switches the word selection application). You can clear resources and save data during this lifecycle. This API returns the result synchronously or uses a promise to return the result.

After the **onDisconnect()** lifecycle callback is executed, the application may exit. Consequently, the asynchronous function (for example, asynchronously writing data to the database) in **onDisconnect()** may fail to be executed. Using a Promise for asynchronous callback is recommended to prevent such issues.

The callback is invoked only when the SelectionExtensionAbility exits gracefully. It is not invoked in cases of abnormal exits (for example, due to low memory conditions).

**System capability**: SystemCapability.SelectionInput.Selection

**Example**

```ts
import { SelectionExtensionAbility } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = '[SelectionExtensionAbility]';

class ServiceExtAbility extends SelectionExtensionAbility {
  onDisconnect(): void {
    hilog.info(0x0000, TAG, `onDisconnect`);
  }
}
```
