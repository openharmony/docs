# @ohos.app.ability.contextConstant (ContextConstant)

The **ContextConstant** module defines context-related enums. Currently, it defines only the enum of encryption levels.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import contextConstant from '@ohos.app.ability.contextConstant';
```

## ContextConstant.AreaMode

You can obtain the value of this constant by calling the **ContextConstant.AreaMode** API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Value| Description|
| -------- | -------- | -------- |
| EL1 | 0 | Device-level encryption. Directories with this encryption level are accessible after the device is powered on. |
| EL2 | 1 | User-level encryption. Directories with this encryption level are accessible only after the device is powered on and the password is entered (for the first time). |
