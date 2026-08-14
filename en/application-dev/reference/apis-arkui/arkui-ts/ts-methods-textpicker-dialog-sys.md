# Text Picker Dialog Box (TextPickerDialog) (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=fd4899920072ab190bbe2089f1efe02176565c30 translatedAt=2026-08-11T01:48:08.969Z pushedAt=2026-08-13T08:49:55.874Z -->

The **TextPickerDialog** component provides the text picker dialog box feature, which allows you to create selection items based on a specified range and display them in a dialog box. It is suitable for scenarios where users need to select text content from preset options, simplifying the selection process and improving user experience.

> **NOTE**
>
> - This component is supported since API version 8. New APIs in later versions are marked with a superscript to indicate their initial version.
>
> - This module depends on the UI execution context and cannot be used where the [UI context is ambiguous](../../../ui/arkts-global-interface.md#ambiguous-ui-context). See [UIContext](../arkts-apis-uicontext-uicontext.md) for details.
>
> - This page contains only the system APIs of this module. For other public APIs, see [Text Picker Dialog Box (TextPickerDialog)](ts-methods-textpicker-dialog.md).

## TextPickerDialogOptions

The parameters of the text picker dialog box are inherited from [TextPickerOptions](ts-basic-components-textpicker.md#textpickeroptions).

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- |  -------- |  -------- |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | No | Yes | Distortion animation mode of the dialog box under system materials. This parameter is passed in when a custom distortion animation effect is required for the dialog box.<br>**Default value:** **DistortionMode.DISTORTION_AUTO**<br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>**Note:** When the value is **DISTORTION_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for the effect to take effect, and the distortion effect is automatically enabled based on the device computing power level (enabled on high- and mid-range devices, disabled on low-end devices). Distortion animation increases rendering overhead, so it is recommended to use it with caution on low-end devices. For the meaning of each enum value, see [DistortionMode](./ts-appendix-enums-sys.md#distortionmode). |
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode) | No | Yes | Edge light animation mode of the dialog box under system materials. This parameter is passed in when a custom edge light animation effect is required for the dialog box.<br>**Default value:** **EdgeLightMode.EDGELIGHT_AUTO**<br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>**Note:** When the value is **EDGELIGHT_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for the effect to take effect, and the edge light effect is automatically enabled based on the device computing power level (enabled on high-end devices, disabled on mid-range and low-end devices). Edge light animation increases rendering overhead, so it is recommended to use it with caution on low-end devices. For the meaning of each enum value, see [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode). |