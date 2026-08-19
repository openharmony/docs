# AutoFillType

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=dea48deb47f1cd9cbdd53d7140c1e6495638a26c translatedAt=2026-08-13T13:21:50.042Z pushedAt=2026-08-17T07:09:41.257Z -->

Enumerates the auto-fill types.

**Since**: 26.0.0

## Modules to Import

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## AutoFillType

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction**: This API can be used only in the stage model.

| Name         | Value | Description           |
| ------------ | ----- | --------------------- |
| UNSPECIFIED  | 0     | Unspecified type. |
| PASSWORD     | 1     | Password type. |
| USER_NAME    | 2     | User name type. |
| NEW_PASSWORD | 3     | New password type. |