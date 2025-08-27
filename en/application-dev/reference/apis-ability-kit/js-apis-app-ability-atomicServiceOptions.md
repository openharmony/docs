# @ohos.app.ability.AtomicServiceOptions (AtomicServiceOptions)
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1; @wendel; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

**AtomicServiceOptions** is used as an input parameter of [openAtomicService()](js-apis-inner-application-uiAbilityContext.md#openatomicservice12) to carry arguments. It inherits from [StartOptions](js-apis-app-ability-startOptions.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { AtomicServiceOptions } from '@kit.AbilityKit';
```

## AtomicServiceOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| [flags](js-apis-app-ability-wantConstant.md#flags) | number | No|  Yes| Mode in which the system processes the startup.<br>For example, **wantConstant.Flags.FLAG_INSTALL_ON_DEMAND** indicates that the installation-free capability is used.|
| parameters | Record\<string, Object> | No|  Yes| Additional parameters. For details, see the **parameters** field in [Want](js-apis-app-ability-want.md).|
| completionHandlerForAtomicService<sup>20+</sup> | [CompletionHandlerForAtomicService](./js-apis-app-ability-CompletionHandlerForAtomicService.md) | No|  Yes| Operation class for receiving the result of opening an atomic service.<br>**Atomic service API**: This API can be used in atomic services since API version 20.|

**Example**

```ts
import { UIAbility, AtomicServiceOptions, common, wantConstant, CompletionHandlerForAtomicService } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { FailureCode } from '@ohos.app.ability.CompletionHandlerForAtomicService';
import { hilog } from '@kit.PerformanceAnalysisKit';

export default class EntryAbility extends UIAbility {
  onForeground() {
    let completionHandler: CompletionHandlerForAtomicService = {
      onAtomicServiceRequestSuccess(appId: string) {
        hilog.info(0x0000, 'testTag', `appId:${appId}`);
      },
      onAtomicServiceRequestFailure(appId: string, failureCode: FailureCode, failureMessage: string) {
        hilog.info(0x0000, 'testTag', `appId:${appId}, failureCode:${failureCode}, failureMessage:${failureMessage}`);
      }
    };

    let options: AtomicServiceOptions = {
      flags: wantConstant.Flags.FLAG_INSTALL_ON_DEMAND,
      parameters: {
        'demo.result': 123456
      },
      completionHandlerForAtomicService: completionHandler
    };

    try {
      let appId: string = '6918661953712445909'; // Use the actual appId.
      this.context.openAtomicService(appId, options)
        .then((result: common.AbilityResult) => {
          // Carry out normal service processing.
          console.info('openAtomicService succeed');
        })
        .catch((err: BusinessError) => {
          // Process service logic errors.
          console.error(`openAtomicService failed, code is ${err.code}, message is ${err.message}`);
        });
    } catch (err) {
      // Process input parameter errors.
      let code = (err as BusinessError).code;
      let message = (err as BusinessError).message;
      console.error(`openAtomicService failed, code is ${code}, message is ${message}`);
    }
  }
}
```
