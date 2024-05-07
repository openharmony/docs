# AbilityStartCallback

The AbilityStartCallback module describes the callback invoked to return the UIExtensionAbility startup result.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name       |  Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| onError  | function               | Yes  | Callback invoked when the UIExtensionAbility fails to start. **Atomic service API**: This API can be used in atomic services since API version 11.                               |
| onResult<sup>12+</sup> | function               | No  |  Callback invoked when the UIExtensionAbility, after being started, calls **terminateSelfWithResult**. **Atomic service API**: This API can be used in atomic services since API version 12.                       |

**Example**

  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import common from '@ohos.app.ability.common';
  import { BusinessError } from '@ohos.base';

  export default class EntryAbility extends UIAbility {
    onForeground() {
      let wantParam: Record<string, Object> = {
        'time': '2023-10-23 20:45',
      };
      let abilityStartCallback: common.AbilityStartCallback = {
        onError: (code: number, name: string, message: string) => {
          console.log(`code:` + code + `name:` + name + `message:` + message);
        },
        onResult: (abilityResult: common.AbilityResult) => {
          console.log(`resultCode:` + abilityResult.resultCode + `bundleName:` + abilityResult.want?.bundleName);
        }
      };

      this.context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err: BusinessError) => {
        if (err) {
          console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
        } else {
          console.log(`success`);
        }
      });
    }
  }
  ```
