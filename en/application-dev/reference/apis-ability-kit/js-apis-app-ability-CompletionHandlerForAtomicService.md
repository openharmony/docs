# @ohos.app.ability.CompletionHandlerForAtomicService (Atomic Service Launch Result Handler)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1; @wendel; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

**CompletionHandlerForAtomicService** is an optional parameter of [AtomicServiceOptions](js-apis-app-ability-atomicServiceOptions.md) and is used to handle the result of an atomic service launch request.


> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { CompletionHandlerForAtomicService } from '@kit.AbilityKit';
```

## FailureCode

Enumerates the errors codes available for failures in launching an atomic service.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                                    | Value  | Description                                      |
| ---------------------------------------- | ---- | ---------------------------------------- |
| FAILURE_CODE_SYSTEM_MALFUNCTION     | 0    | The atomic service cannot be launched due to a system error (for example, a crash in the transition dialog box).|
| FAILURE_CODE_USER_CANCEL            | 1    | The user canceled the operation.|
| FAILURE_CODE_USER_REFUSE            | 2    | The user refused the operation.|

## CompletionHandlerForAtomicService

CompletionHandlerForAtomicService provides two callback functions, [onAtomicServiceRequestSuccess](#onatomicservicerequestsuccess) and [onAtomicServiceRequestFailure](#onatomicservicerequestfailure), to handle the results of successful and failed atomic service launch requests, respectively.

### onAtomicServiceRequestSuccess

onAtomicServiceRequestSuccess(appId: string): void

Called when the atomic service is successfully launched.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appId | string | Yes| appId of the target atomic service.|

**Example**

For details, see [CompletionHandlerForAtomicService Usage Example](#completionhandlerforatomicservice-usage-example).

### onAtomicServiceRequestFailure

onAtomicServiceRequestFailure(appId: string, failureCode: FailureCode, failureMessage: string): void

Called when the atomic service fails to be launched.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appId | string | Yes| appId of the target atomic service.|
| failureCode | [FailureCode](#failurecode) | Yes| Error code of the failure cause.|
| failureMessage | string | Yes| Description of the failure cause.|

**Example**

For details, see [CompletionHandlerForAtomicService Usage Example](#completionhandlerforatomicservice-usage-example).

### CompletionHandlerForAtomicService Usage Example

```ts
import { AbilityConstant, AtomicServiceOptions, common, UIAbility, Want, CompletionHandlerForAtomicService } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { FailureCode } from '@ohos.app.ability.CompletionHandlerForAtomicService';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    let completionHandler: CompletionHandlerForAtomicService = {
      onAtomicServiceRequestSuccess(appId: string) {
        hilog.info(0x0000, 'testTag', `appId:${appId}`);
      },
      onAtomicServiceRequestFailure(appId: string, failureCode: FailureCode, failureMessage: string) {
        hilog.info(0x0000, 'testTag', `appId:${appId}, failureCode:${failureCode}, failureMessage:${failureMessage}`);
      }
    };
    let options: AtomicServiceOptions = {
      completionHandlerForAtomicService: completionHandler
    };
    let appId: string = '5765880207853275489'; // Use the actual appId.
    this.context.openAtomicService(appId, options).then((result: common.AbilityResult) => {
      hilog.info(0x0000, 'testTag', `openAtomicService succeed:${JSON.stringify(result)}`);
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', `openAtomicService failed:${JSON.stringify(err)}`);
    });
  }
}

```
