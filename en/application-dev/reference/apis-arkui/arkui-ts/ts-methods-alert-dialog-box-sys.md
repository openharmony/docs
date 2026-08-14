# Alert Dialog Box (AlertDialog) (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @houguobiao-->
<!--Designer: @houguobiao-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=34139b640e7f5cff7ecd77a979f553b6821e37f2 translatedAt=2026-08-11T01:47:02.416Z pushedAt=2026-08-13T08:23:23.680Z -->

Displays an alert dialog box component with configurable text content and response callbacks.

> **NOTE**
>
> This feature is supported since API version 7. Newly added content in later versions will be marked with a superscript to indicate the initial version.
>
> This module depends on the UI execution context and cannot be used where the [UI context is ambiguous](../../../ui/arkts-global-interface.md#ambiguous-ui-context). See [UIContext](../arkts-apis-uicontext-uicontext.md) for details.
>
> This page covers only the system APIs of this module. For other public APIs, see [Alert Dialog Box (AlertDialog)](ts-methods-alert-dialog-box.md).

## AlertDialogParam

Defines the configuration parameters of the alert dialog box.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name                              | Type                                                         | Read-Only | Optional | Description                                                        |
| --------------------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | No | Yes | Distortion animation mode of the dialog box under system materials.<br/>**Default value:** **DistortionMode.DISTORTION_AUTO** <br/>**System API:** This is a system API.<br/>**Since:** 26.0.0<br/>**Model restriction:** This API can be used only in the stage model.|
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode) | No | Yes | Edge light animation mode of the dialog box under system materials.<br/>**Default value:** **EdgeLightMode.EDGELIGHT_AUTO** <br/>**System API:** This is a system API.<br/>**Since:** 26.0.0<br/>**Model restriction:** This API can be used only in the stage model. |