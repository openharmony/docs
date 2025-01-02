# ViewData (System API)

ViewData defines the view data used for auto-fill.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs provided by this module are system APIs.
> The APIs of this module can be used only in the stage model.

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName    | string               | Yes  | Bundle name.                              |
| moduleName    | string              | Yes  | Module name.                              |
| abilityName    | string        | Yes  | Ability name.   |
| pageUrl    | string              | Yes  | URL of the page.                              |
| pageNodeInfos    | Array&lt;[PageNodeInfo](js-apis-inner-application-pageNodeInfo-sys.md)&gt;     | Yes  | Page node information.               |
| pageRect<sup>12+</sup>    | [AutoFillRect](js-apis-inner-application-autoFillRect-sys.md)     | Yes  | Coordinates, width, and height of the page.               |
| isUserSelected<sup>12+</sup> | boolean | Yes| Whether the content is selected by the user.|
| isOtherAccount<sup>12+</sup> | boolean | Yes| Whether to display other account information saved in the password box for the user to select.|
