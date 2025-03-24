# TriggerInfo (System API)

The TriggerInfo module defines the information required for triggering the WantAgent. The information is used as an input parameter of [trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> This topic describes only system APIs provided by the module. For details about its public APIs, see [TriggerInfo](js-apis-inner-wantAgent-triggerInfo.md).

## Modules to Import

```ts
import { wantAgent } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Type                | Mandatory| Description       |
| ---------- | --- |-------------------- | ----------- |
| startOptions<sup>12+<sup>|[StartOptions](js-apis-app-ability-startOptions.md)         | No | Start options in **wantAgent** used to start an ability.|
