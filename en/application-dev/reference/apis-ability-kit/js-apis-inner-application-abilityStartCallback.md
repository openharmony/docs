# AbilityStartCallback

The AbilityStartCallback module describes the callback invoked to return the UIExtensionAbility startup result.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> The APIs of this module can be used only in the stage model.
> 
> Since API version 11, the APIs of this module are supported in atomic services.

## Modules to Import

```ts
import { common } from '@kit.AbilityKit';
```

## onError

onError(code: number, name: string, message: string): void

Called when the UIExtensionAbility fails to start.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| code | number | Yes   | Result code returned when the UIExtensionAbility fails to start. |
| name | string | Yes   | Name returned when the UIExtensionAbility fails to start. |
| message | string | Yes   | Error information returned when the UIExtensionAbility fails to start. |

**Example**

```ts
import { UIAbility, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## onResult<sup>12+<sup>

onResult?(parameter: AbilityResult): void

Called when the UIExtensionAbility is terminated.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| parameter | [AbilityResult](js-apis-inner-ability-abilityResult.md) | Yes   | Result returned when [terminateSelfWithResult](js-apis-inner-application-uiExtensionContext.md#uiextensioncontextterminateselfwithresult12) is called to terminate the UIExtensionAbility. |

**Example**

```ts
import { UIAbility, common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
