# @ohos.selectionInput.SelectionExtensionContext (SelectionExtensionContext) (System API)

**SelectionExtensionContext** is the context of [SelectionExtensionAbility](./js-apis-selectionInput-selectionExtensionAbility-sys.md), which is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

When a SelectionExtensionAbility component is instantiated, the system automatically creates the corresponding **SelectionExtensionContext**. You can use **SelectionExtensionContext** to start other abilities in the same application.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { SelectionExtensionContext } from '@kit.BasicServicesKit';
```

## SelectionExtensionContext

### startAbility

startAbility(want: Want): Promise\<void>

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.SelectionInput.Selection

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Want information of the ability to start, including the ability name and bundle name.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Ability Error Codes](../apis-ability-kit/errorcode-ability.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------- |
| 16000001 | The specified ability does not exist.                   |
| 16000002 | Incorrect ability type.                                 |
| 16000004 | Cannot start an invisible component.                    |
| 16000005 | The specified process does not have the permission.     |
| 16000006 | Cross-user operations are not allowed.                  |
| 16000008 | The crowdtesting application expires.                   |
| 16000009 | An ability cannot be started or stopped in Wukong mode. |
| 16000010 | The call with the continuation and prepare continuation flag is forbidden.       |
| 16000011 | The context does not exist.                             |
| 16000012 | The application is controlled.                          |
| 16000013 | The application is controlled by EDM.                   |
| 16000019 | No matching ability is found.                            |
| 16000050 | Internal error.                                         |
| 16000053 | The ability is not on the top of the UI.                |
| 16000055 | Installation-free timed out.                            |
| 16000061 | Operation not supported.                                |
| 16000069 | The extension cannot start the third party application. |
| 16000070 | The extension cannot start the service.                 |
| 16000083 | The ExtensionAbility cannot start the ability due to system control.                 |
| 16200001 | The caller has been released.                           |

**Example**

```ts
import { SelectionExtensionAbility, BusinessError } from '@kit.BasicServicesKit';
import { rpc } from '@kit.IPCKit';
import { Want } from '@kit.AbilityKit';

class SelectionAbilityStub extends rpc.RemoteObject {
  constructor(des: string) {
    super(des);
  }
  onRemoteMessageRequest(
    code: number,
    data: rpc.MessageSequence,
    reply: rpc.MessageSequence,
    options: rpc.MessageOption
  ): boolean | Promise<boolean> {
    console.info(`onRemoteMessageRequest code: ${code}`);
    return true;
  }
}

class SelectionExtAbility extends SelectionExtensionAbility {
  onConnect(want: Want): rpc.RemoteObject {
    try {
      let wantAbility: Want = {
        bundleName: "com.selection.selectionapplication",
        abilityName: "EntryAbility",
      };
      this.context.startAbility(wantAbility).then(() => {
        console.info(`startAbility success`);
      }).catch((err: BusinessError) => {
        let error = err as BusinessError;
        console.error(`startAbility error: ${error.code} ${error.message}`);
      })
    } catch (err) {
      let error = err as BusinessError;
      console.error(`startAbility error: ${error.code} ${error.message}`);
    }
    return new SelectionAbilityStub('remote');
  }
}
```
