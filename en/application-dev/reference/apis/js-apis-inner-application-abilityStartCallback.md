# AbilityStartCallback

The **AbilityStartCallback** module defines the callback to be invoked when the UIExtensionAbility fails to start.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name       |  Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| onError<sup>11+</sup>  | function               | Yes  | Callback invoked when the UIExtensionAbility fails to start.                               |

**Example**

  ```ts
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext;
  let wantParam: Record<string, Object> = {
    'time':'2023-10-23 20:45',
  };
  let abilityStartCallback: common.AbilityStartCallback = {
    onError: (code, name, message) => {
      console.log(`code:` + code + `name:` + name + `message:` + message);
    }
  }
  context.startAbilityByType("photoEditor", wantParam, abilityStartCallback, (err) => {
    if (err) {
      console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`success`);
    }
  });
  ```
