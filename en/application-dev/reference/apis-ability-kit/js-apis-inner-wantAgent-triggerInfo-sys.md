# TriggerInfo

The **TriggerInfo** module defines the information required for triggering the WantAgent. The information is used as an input parameter of [trigger](js-apis-app-ability-wantAgent.md#wantagenttrigger).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name      | Type                | Mandatory| Description       |
| ---------- | --- |-------------------- | ----------- |
| startOptions<sup>12+<sup>|[StartOptions](js-apis-app-ability-startOptions.md)         | No | Start options when the wantAgent of the ability is triggered.|
