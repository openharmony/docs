# WantAgentInfo

The **WantAgentInfo** module defines the information required for triggering a **WantAgent** object. The information can be used as an input parameter in [getWantAgent](js-apis-app-ability-wantAgent.md#wantagentgetwantagent) to obtain a specified **WantAgent** object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Type                           | Mandatory| Description                  |
| -------------- | ------------------------------- | ---- | ---------------------- |
| wants          | Array\<[Want](js-apis-app-ability-want.md)\>                   | Yes  | Array of all **Want** objects. Currently, only one Want is supported. The array is reserved for future capability expansion. If multiple values are passed in, only the first member in the array is used.   |
| operationType<sup>(deprecated)</sup>  | [wantAgent.OperationType](js-apis-wantAgent.md#operationtype)         | No  | Operation type.<br>This attribute is supported since API version 7 and deprecated since API version 11. You are advised to use **[actionType]** instead.              |
| actionType<sup>11+</sup> | [abilityWantAgent.OperationType](js-apis-app-ability-wantAgent.md#operationtype)         | No  | Operation type.              |
| requestCode    | number                          | Yes  | Request code defined by the user.|
| wantAgentFlags | Array<[wantAgent.WantAgentFlags](js-apis-app-ability-wantAgent.md#wantagentflags)> | No  | Array of flags for using the **WantAgent** object.          |
| extraInfo      | {[key: string]: any}            | No  | Extra information.              |
