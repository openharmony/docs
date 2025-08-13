# WantAgentInfo

The module defines the information required for triggering a WantAgent.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> 
> This topic describes only system APIs provided by the module. For details about its public APIs, see [WantAgentInfo](js-apis-inner-wantAgent-wantAgentInfo.md).

## Modules to Import

```ts
import { wantAgent as abilityWantAgent } from '@kit.AbilityKit';
```

## LocalWantAgentInfo<sup>20+</sup>

Defines the information required for triggering a local WantAgent object. The information can be used as an input parameter in [createLocalWantAgent](js-apis-app-ability-wantAgent-sys.md#wantagentcreatelocalwantagent20) to obtain a local WantAgent object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

| Name          | Type                           | Read-Only | Optional | Description                  |
| -------------- | ------------------------------- | --- | ---- | ---------------------- |
| wants          | Array\<[Want](js-apis-app-ability-want.md)\>                          | No  | No  | Array of all Want objects. Currently, only one Want object is supported. If multiple values are passed in, only the first member in the array is used.   |
| operationType  | [wantAgent.OperationType](js-apis-wantAgent.md#operationtype)         | No  | Yes  | Type of the operation to execute.     |
| requestCode    | number                          | No  | No  | Custom request code, which is used to identify the operation to execute.|
