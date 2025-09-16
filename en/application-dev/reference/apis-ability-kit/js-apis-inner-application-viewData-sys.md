# ViewData (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

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
| isUserSelected<sup>12+</sup> | boolean | No  | No  | Whether the content to be filled is selected by the user. **true** if the content is selected by the user, and **false** otherwise.|
| isOtherAccount<sup>12+</sup> | boolean | No  | No  | Whether to display other account information saved in the password box for the user to select. **true** to display, **false** otherwise.|
