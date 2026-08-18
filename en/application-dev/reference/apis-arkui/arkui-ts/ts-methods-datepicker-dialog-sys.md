# Date Picker Dialog Box (DatePickerDialog) (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=e7881c5c3a913498a72b348a639a6d6cf2ca6821 translatedAt=2026-08-11T01:47:55.914Z pushedAt=2026-08-13T08:42:59.363Z -->

The **DatePickerDialog** component provides a system-level date picker dialog box, supporting the configuration of the distortion animation mode and the edge light animation mode. It is suitable for scenarios where a system material-style date picker needs to be integrated into an app, delivering a consistent visual experience and smooth interactive animations to enhance user experience consistency.

> **NOTE**
>
> - This component is supported since API version 8. Updates to new APIs in later versions are marked with a superscript to indicate the API's since version.
>
> - The functionality of this module depends on the UI execution context and cannot be used in contexts where the [UI context is ambiguous](../../../ui/arkts-global-interface.md#ambiguous-ui-context). For details, see [UIContext](../arkts-apis-uicontext-uicontext.md).
>
> - This page covers only the system APIs of this module. For other public APIs, see [Date Picker Dialog Box (DatePickerDialog)](ts-methods-datepicker-dialog.md).

## DatePickerDialogOptions

Defines the options for the date picker dialog box. **DatePickerDialog** displays a date picker in a dialog box, providing system material animation effects.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | No | Yes | Distortion animation mode of the dialog box under the system material. This parameter is passed when a custom distortion animation effect for the dialog box is needed.<br>**Default value:** **DistortionMode.DISTORTION_AUTO**<br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>**Note:** When the value is **DISTORTION_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for it to take effect, and the distortion effect is automatically applied based on the device computing power tier (effective on high- and mid-tier devices, not effective on low-tier devices). Distortion animation increases rendering overhead, so use it with caution on low-end devices. For the meaning of each enum value, see [DistortionMode](./ts-appendix-enums-sys.md#distortionmode). |
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode) | No | Yes | Edge light animation mode of the dialog box under the system material. This parameter is passed when a custom edge light animation effect for the dialog box is needed.<br>**Default value:** **EdgeLightMode.EDGELIGHT_AUTO**<br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>**Note:** When the value is **EDGELIGHT_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for it to take effect, and the edge light effect is automatically applied based on the device computing power tier (effective on high-tier devices, not effective on mid- and low-tier devices). Edge light animation increases rendering overhead, so use it with caution on low-end devices. For the meaning of each enum value, see [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode). |