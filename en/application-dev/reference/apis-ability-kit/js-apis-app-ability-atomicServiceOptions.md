# @ohos.app.ability.AtomicServiceOptions (AtomicServiceOptions)

**AtomicServiceOptions** is used as an input parameter of [openAtomicService()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenatomicservice12) to carry arguments. It inherits from [StartOptions](js-apis-app-ability-startOptions.md).

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import AtomicServiceOptions from '@ohos.app.ability.AtomicServiceOptions';
```

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| [flags](js-apis-app-ability-wantConstant.md#wantconstantflags) | number | No| No| By default, a number is passed in.<br>For example, **wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION** indicates the action of granting the permission to read the URI.|
| parameters | Record\<string, Object> | No| No| Want parameters in the form of custom key-value (KV) pairs. By default, the following keys are carried:<br>- **ohos.aafwk.callerPid**: PID of the caller.<br>- **ohos.aafwk.param.callerBundleName**: bundle name of the caller.<br>- **ohos.aafwk.param.callerToken**: token of the caller.<br>- **ohos.aafwk.param.callerUid**: UID in [BundleInfo](js-apis-bundleManager-bundleInfo.md#bundleinfo-1), that is, the application UID in the bundle information.<br>- **component.startup.newRules**: enabled status of the new control rule.<br>- **moduleName**: module name of the caller. No matter what this field is set to, the correct module name will be sent to the peer.<br>- **ohos.dlp.params.sandbox**: available only for DLP files.<br>- **ability.params.backToOtherMissionStack**: support for redirection back across mission stacks.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import AtomicServiceOptions from '@ohos.app.ability.AtomicServiceOptions';
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
import wantConstant from '@ohos.app.ability.wantConstant';

export default class EntryAbility extends UIAbility {

  onForeground() {
    let appId: string = '6918661953712445909';
    let options: AtomicServiceOptions = {
      flags: wantConstant.Flags.FLAG_INSTALL_ON_DEMAND,
      parameters: { "demo.result": 123456 }
    };

    try {
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
