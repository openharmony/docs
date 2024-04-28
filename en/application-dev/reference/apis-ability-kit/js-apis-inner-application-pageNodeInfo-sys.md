# PageNodeInfo (System API)

PageNodeInfo defines the page node information used for auto-fill.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.
> The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| id    | number               | Yes  | ID of the page node.                              |
| depth    | number              | Yes  | Depth of the page node.                              |
| autoFillType    | [AutoFillType](js-apis-inner-application-autoFillType-sys.md)        | Yes  | Type of the element to be automatically filled in.   |
| tag    | string              | Yes  | Tag of the page node.                              |
| value    | string              | Yes  | Value of the page node.                              |
| placeholder    | string              | No  | Placeholder of the page node.                              |
| passwordRules    | string              | No  | Rules for generating passwords.                              |
| enableAutoFill    | boolean              | Yes  | Status of the auto-fill feature.                              |
| rect<sup>12+</sup>    | [AutoFillRect](js-apis-inner-application-autoFillRect-sys.md) | Yes  | Coordinates, width, and height of the page node. |
| isFocus<sup>12+</sup>    | boolean              | Yes  | Whether the page node has focus.                              |
