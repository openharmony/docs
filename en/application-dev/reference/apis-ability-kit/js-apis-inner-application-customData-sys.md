# CustomData (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

When starting a modal page, you can transfer custom data to the autofill service through [reloadInModal](js-apis-inner-application-autoFillExtensionContext-sys.md#reloadinmodal13) and obtain the data through [onFillRequest](js-apis-app-ability-autoFillExtensionAbility-sys.md#onfillrequest) of the service.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 13. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the stage model. 
> The APIs provided by this module are system APIs.

##  Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.AbilityCore

| Name| Type                  | Read-Only| Optional| Description                                                |
| ---- | ---------------------- | ---- | ---- | ---------------------------------------------------- |
| data | Record<string, Object> | No  | No  | Custom data transferred for starting the modal page. The data is of the Record type.|
