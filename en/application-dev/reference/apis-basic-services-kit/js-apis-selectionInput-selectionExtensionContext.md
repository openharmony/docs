# @ohos.selectionInput.SelectionExtensionContext (Word Selection Extension Context)

<!--Kit: Basic Services Kit-->
<!--Subsystem: SelectionInput-->
<!--Owner: @no86-->
<!--Designer: @no86-->
<!--Tester: @dong-dongzhen-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=7bd9d64d06b09f010cde4ca5a86285027d09b51a translatedAt=2026-08-04T10:29:16.904Z pushedAt=2026-08-05T11:50:08.560Z -->

**SelectionExtensionContext** is the context of [SelectionExtensionAbility](./js-apis-selectionInput-selectionExtensionAbility.md), which is inherited from [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

When a **SelectionExtensionAbility** component is instantiated, the system automatically creates the corresponding **SelectionExtensionContext**. You can call the [startAbility](#startability) API in **SelectionExtensionContext** to start other abilities in the same app. This is applicable when you need to redirect to another ability in the same app in word selection extension, helping users quickly obtain the functions or information associated with the selected word.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 24. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This module is supported only on PCs/2-in-1 devices. You can use **canIUse('SystemCapability.SelectionInput.Selection')** to check whether the current device supports this function.

## Modules to Import

```ts
import { SelectionExtensionContext } from '@kit.BasicServicesKit';
```

## SelectionExtensionContext

**System capability**: SystemCapability.SelectionInput.Selection

**Model constraint**: This API can be used only in the stage model.

### startAbility

startAbility(want: Want): Promise\<void>

Starts the target ability in the same app. This method is applicable when you need to redirect to another ability in the app in word selection extension. The system matches and starts the target ability based on the values of **bundleName** and **abilityName** specified in the **Want** object. This API uses a promise to return the result. For details about the ability startup mechanism, see [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md).

**System capability**: SystemCapability.SelectionInput.Selection

**Model constraint**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | Mandatory   | Information about the target app to start. The main fields include **bundleName** (bundle name of the target app) and **abilityName** (name of the target ability). After this parameter is set, the system searches for and starts the corresponding ability based on the specified bundle name and ability name. Only abilities within the same app can be started. |

**Return value**

| Type          | Description                     |
| -------------- | ------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Ability Error Codes](../apis-ability-kit/errorcode-ability.md). For details about other common error codes, see [Universal Error Codes](../errorcode-universal.md).

| Error Code| Error Message                                               |
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
  constructor(descriptor: string) {
    super(descriptor);
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
      // Construct a Want object to specify the target ability to start.
      let wantAbility: Want = {
        bundleName: 'com.selection.selectionapplication',
        abilityName: 'EntryAbility',
      };
      // Start the target Ability. this.context is automatically provided by the SelectionExtensionAbility instance and does not need to be obtained separately.
      this.context.startAbility(wantAbility).then(() => {
        console.info(`startAbility success`);
      }).catch((err: BusinessError) => {
        console.error(`Failed to startAbility. Error code: ${err.code}, error message: ${err.message}`);
      });
    } catch (err) {
      console.error(`Failed to startAbility. Error code: ${err.code}, error message: ${err.message}`);
    }
    return new SelectionAbilityStub('remote');
  }
}
```