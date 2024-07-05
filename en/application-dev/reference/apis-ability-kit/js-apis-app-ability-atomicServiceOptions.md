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

## Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read Only| Mandatory| Description|
| -------- | -------- | -------- | -------- | -------- |
| [flags](js-apis-app-ability-wantConstant.md#wantconstantflags) | number | No|  No| Mode in which the system processes the startup.<br>For example, **wantConstant.Flags.FLAG_INSTALL_ON_DEMAND** indicates that the installation-free capability is used.|
| parameters | Record\<string, Object> | No|  No| Additional parameters. For details, see the **parameters** field in [Want](js-apis-app-ability-want.md).|

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
