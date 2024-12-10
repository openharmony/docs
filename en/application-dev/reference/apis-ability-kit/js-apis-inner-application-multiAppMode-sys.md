# MultiAppMode (System API)

The MultiAppMode module defines whether an application supports the multi-app mode.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module are system APIs.

## Properties

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Value| Description| 
| -------- | -------- |
| NOT_SUPPORTED | The application does not support the multi-app mode.|
| MULTI_INSTANCE<sup>14+</sup>  | The application supports the multi-instance mode.<br>**NOTE**: This property is valid only for 2-in-1 devices. |
| APP_CLONE | The application supports the app-clone mode.|
