# ViewData

ViewData defines the view data used for auto-fill.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name       | Type                | Mandatory| Description                                                        |
| ----------- | -------------------- | ---- | ------------------------------------------------------------ |
| bundleName    | string               | Yes  | Bundle name.                              |
| moduleName    | string              | Yes  | Module name.                              |
| abilityName    | string        | Yes  | Ability name.   |
| pageUrl    | string              | Yes  | URL of the page.                              |
| pageNodeInfos    | Array&lt;[PageNodeInfo](js-apis-inner-application-pageNodeInfo.md)&gt;     | Yes  | Page node information.               |
