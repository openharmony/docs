# WantAgentInfo

The **WantAgentInfo** module defines the information required for triggering a **WantAgent** object. The information can be used as an input parameter in [getWantAgent](js-apis-app-ability-wantAgent.md#wantagentgetwantagent) to obtain a specified **WantAgent** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name          | Type                           | Mandatory| Description                  |
| -------------- | ------------------------------- | ---- | ---------------------- |
| wants          | Array\<Want\>                   | Yes  | Array of all **Want** objects.    |
| operationType  | wantAgent.OperationType         | Yes  | Operation type.              |
| requestCode    | number                          | Yes  | Request code defined by the user.|
| wantAgentFlags | Array<[wantAgent.WantAgentFlags](js-apis-app-ability-wantAgent.md#wantagentflags)> | No  | Array of flags for using the **WantAgent** object.          |
| extraInfo      | {[key: string]: any}            | No  | Extra information.              |
