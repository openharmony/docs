# @ohos.ability.errorCode (ErrorCode)

The **ErrorCode** module defines the error codes that may be returned when an ability is started.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { ErrorCode } from '@kit.AbilityKit';
```

## ErrorCode

Enumerates the error codes that may be returned when an ability is started.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                            | Value   | Description                                      |
| ------------------------------ | ---- | ---------------------------------------- |
| NO_ERROR         | 0    | No error.  |
| INVALID_PARAMETER | -1   | Invalid parameter.|
| ABILITY_NOT_FOUND | -2   | The ability is not found.|
| PERMISSION_DENY   | -3   | Permission denied.  |
