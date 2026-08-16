# Action Sheet (ActionSheet) (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1773e7196cb84820c1653799f71f51fa355bf610 translatedAt=2026-08-11T01:46:52.719Z pushedAt=2026-08-13T08:30:45.539Z -->

Creates an action sheet.

> **NOTE**
>
> This API is supported since API version 8. Newly added content in later versions will be marked with a superscript to indicate the initial version.
>
> This module depends on the UI execution context and cannot be used in the [ambiguous UI context](../../../ui/arkts-global-interface.md#ambiguous-ui-context). For details, see [UIContext](../arkts-apis-uicontext-uicontext.md).
>
> This page covers only the system APIs of this module. For public APIs, see [Action Sheet (ActionSheet)](ts-methods-action-sheet.md).

## ActionSheetOptions

Defines the style of the action sheet.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| ---------- | -------------------------- | ------- | ----------------------------- | ----------------------------- |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | No | Yes | Distortion animation mode of the dialog box under system materials.<br/>**Default value:** **DistortionMode.DISTORTION_AUTO**<br/>**System API:** This is a system API.<br/>**Since:** 26.0.0<br/>**Model restriction:** This API can be used only in the stage model. |
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode) | No | Yes | Edge light animation mode of the dialog box under system materials.<br/>**Default value:** **EdgeLightMode.EDGELIGHT_AUTO**<br/>**System API:** This is a system API.<br/>**Since:** 26.0.0<br/>**Model restriction:** This API can be used only in the stage model. |