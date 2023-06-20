# WantAgentInfo

The **WantAgentInfo** module defines the information required for triggering a **WantAgent** object. The information can be used as an input parameter in [getWantAgent](js-apis-app-ability-wantAgent.md#wantagentgetwantagent) to obtain a specified **WantAgent** object.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import wantAgent from '@ohos.app.ability.wantAgent';
```

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Type                           | Mandatory| Description                  |
| -------------- | ------------------------------- | ---- | ---------------------- |
| wants          | Array\<[Want](js-apis-inner-ability-want.md)\>                   | Yes  | Array of all **Want** objects.    |
| operationType  | [wantAgent.OperationType](js-apis-app-ability-wantAgent.md#operationtype)         | Yes  | Operation type.              |
| requestCode    | number                          | Yes  | Request code defined by the user.|
| wantAgentFlags | Array<[wantAgent.WantAgentFlags](js-apis-app-ability-wantAgent.md#wantagentflags)> | No  | Array of flags for using the **WantAgent** object.          |
| extraInfo      | {[key: string]: any}            | No  | Extra information.              |
