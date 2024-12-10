# PageNodeInfo (System API)

PageNodeInfo defines the page node information used for auto-fill.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.
> The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Read-Only| Optional| Description                                                        |
| ----------- | -------------------- | ----| ---- | ------------------------------------------------------------ |
| id    | number               | No  | No  | ID of the page node.                              |
| depth    | number              | No  | No  | Depth of the page node.                              |
| autoFillType    | [AutoFillType](js-apis-inner-application-autoFillType-sys.md)        | No  | No  | Type of the element to be automatically filled in.   |
| tag    | string              | No  | No  | Tag of the page node.                              |
| value    | string              | No  | No  | Value of the page node.                              |
| placeholder    | string              | No  | Yes  | Placeholder of the page node.                              |
| passwordRules    | string              | No  | Yes  | Rules for generating passwords.                              |
| enableAutoFill    | boolean              | No  | No  | Status of the auto-fill feature.                              |
| rect<sup>12+</sup>    | [AutoFillRect](js-apis-inner-application-autoFillRect-sys.md) | No  | No  | Coordinates, width, and height of the page node. |
| isFocus<sup>12+</sup>    | boolean              | No  | No  | Whether the page node has focus.                              |
| metadata<sup>12+</sup>    | string              | No  | Yes  | Metadata of the page node.                              |
