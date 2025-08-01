# ViewData (System API)

The module defines the view data used for auto-fill.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs provided by this module are system APIs.
> The APIs of this module can be used only in the stage model.

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Read-Only| Optional| Description                                                        |
| ----------- | ------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName    | string            | No  | No  | Bundle name.                              |
| moduleName    | string            | No  | No  | Module name.                              |
| abilityName   | string            | No  | No  | Ability name.   |
| pageUrl       | string            | No  | No  | URL of the page.                              |
| pageNodeInfos | Array&lt;[PageNodeInfo](js-apis-inner-application-pageNodeInfo-sys.md)&gt;    | No  | No  | Page node information.               |
| pageRect<sup>12+</sup>    | [AutoFillRect](js-apis-inner-application-autoFillRect-sys.md)     | No  | No  | Coordinates, width, and height of the page.               |
| isUserSelected<sup>12+</sup> | boolean | No  | No  | Whether the content is selected by the user. The value **true** means that the content is selected by the user, and **false** means the opposite.|
| isOtherAccount<sup>12+</sup> | boolean | No  | No  | Whether to display other account information saved in the password box for the user to select. The value **true** means to display other account information saved in the password box for the user to select, and **false** means the opposite.|
