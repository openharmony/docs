# @ohos.ability.wantConstant (wantConstant) (System API)

The wantConstant module provides the actions, entities, and flags used in Want objects.

> **NOTE**
> 
> The APIs of this module are supported since API version 6 and deprecated since API version 9. You are advised to use [@ohos.app.ability.wantConstant](js-apis-app-ability-wantConstant.md) instead. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.ability.wantConstant (wantConstant)](js-apis-ability-wantConstant.md).

## Modules to Import

```ts
import wantConstant from '@ohos.ability.wantConstant';
```

## Flags

 Enumerates the flags that specify how the Want will be handled.

**System capability**: SystemCapability.Ability.AbilityBase

**System API**: This is a system API.

| Name                                | Value      | Description                                                        |
| ------------------------------------ | ---------- | ------------------------------------------------------------ |
| FLAG_AUTH_PERSISTABLE_URI_PERMISSION | 0x00000040 | Grants the permission to make the URI persistent. |
| FLAG_AUTH_PREFIX_URI_PERMISSION      | 0x00000080 | Grants the permission to verify URIs by prefix matching.|
| FLAG_ABILITY_CONTINUATION_REVERSIBLE | 0x00000400 | Indicates that ability continuation is reversible.    |
