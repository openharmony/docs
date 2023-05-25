# TriggerInfo

The **TriggerInfo** module defines the information required for triggering the WantAgent. The information is used as an input parameter of [trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Type                | Mandatory| Description       |
| ---------- | --- |-------------------- | ----------- |
| code       | number               | Yes  | Result code.|
| want       | Want                 | No  | Want.       |
| permission | string               | No  | Permission.   |
| extraInfo  | {[key: string]: any} | No  | Extra information.   |
