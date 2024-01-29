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

Enumerates the data encryption levels. You can obtain the value of this constant by calling the **ContextConstant.AreaMode** API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name | Value| Description                                                                                                                  |
|-----| -------- |----------------------------------------------------------------------------------------------------------------------|
| EL1 | 0 | Device-level encryption. Directories with this encryption level are accessible after the device is powered on.                                                                                                |
| EL2 | 1 | User-level encryption. Directories with this encryption level are accessible only after the device is powered on and the password is entered (for the first time).                                                                                       |
| EL3<sup>11+<sup> | 2 | User-level encryption. The file permissions vary according to their scenarios.<br>- An open file is always readable and writable regardless of whether the screen is locked.<br>- When the screen is locked, a closed file cannot be opened, read, or written. When the screen is unlocked, such a file can be opened, read, and written.<br>- When the screen is locked, a file can be created and then opened and written but not read. When the screen is unlocked, a file can be created and then opened, read, and written.|
| EL4<sup>11+<sup> | 3 | User-level encryption. The file permissions vary according to their scenarios.<br>- When the screen is locked, an open file is readable and writable in FEB2.0, but not in FEB3.0. When the screen is unlocked, such a file is always readable and writable.<br>- When the screen is locked, a closed file cannot be opened, read, or written. When the screen is unlocked, such a file can be opened, read, and written.<br>- When the screen is locked, a file cannot be created. When the screen is unlocked, a file can be created and then opened, read, and written.       |
