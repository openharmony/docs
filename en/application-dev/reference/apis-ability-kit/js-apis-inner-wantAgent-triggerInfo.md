# TriggerInfo

The module defines the information required for triggering the WantAgent. The information is used as an input parameter of [trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { wantAgent } from '@kit.AbilityKit';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Type                | Read-Only| Optional| Description       |
| ---------- | ------------------- | ---- | ---- | ----------- |
| code       | number               | No| No| Custom result code provided for the target WantAgent.|
| want       | Want                 | No| Yes| Carrier for information transfer between objects (application components).   |
| permission | string               | No| Yes| Permission.   |
| extraInfo  | { [key: string]: any } | No| Yes| Extra information.   |
| extraInfos<sup>11+<sup>  | Record\<string, Object> | No| Yes| Extra information. You are advised to use this property to replace **extraInfo**. When this property is set, **extraInfo** does not take effect.   |
