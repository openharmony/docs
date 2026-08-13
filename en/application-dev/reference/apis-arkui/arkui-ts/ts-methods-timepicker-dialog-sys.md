# Time Picker Dialog Box (TimePickerDialog) (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=db8b06bfc93d665e3e19361e3a1c402554e8e3dd translatedAt=2026-08-11T01:47:59.005Z pushedAt=2026-08-13T09:20:04.979Z -->

Creates a time picker with a 24-hour time range and displays it in a dialog box. It is suitable for scenarios where precise time selection is required in a dialog box, providing a smooth user interaction experience and helping apps quickly implement time selection functionality while maintaining an aesthetically pleasing UI.

> **NOTE**
>
> - This component is supported since API version 8. Newly added APIs in later versions are marked with a superscript to indicate their initial version.
>
> - The functionality of this module depends on the UI execution context and cannot be used in scenarios where the [UI context is ambiguous](../../../ui/arkts-global-interface.md#ambiguous-ui-context). For details, see [UIContext](../arkts-apis-uicontext-uicontext.md).
>
> - This page contains only the system APIs of this module. For other public APIs, see [Time Picker Dialog Box (TimePickerDialog)](ts-methods-timepicker-dialog.md).

## TimePickerDialogOptions

Defines the options of the time picker dialog box.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | No | Yes | Distortion animation mode of the dialog box under system materials.<br>**Default value:** **DistortionMode.DISTORTION_AUTO**<br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>**Note:** When the value is **DISTORTION_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for the effect to take effect, and the distortion effect is automatically applied based on the device computing power tier (effective on high- and mid-tier computing power devices, ineffective on low-tier computing power devices). Distortion animation increases rendering overhead, so exercise caution when using it on low-end devices. For the meaning of each enum value, see [DistortionMode](./ts-appendix-enums-sys.md#distortionmode). |
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode) | No | Yes | Edge light animation mode of the dialog box under system materials.<br>**Default value:** **EdgeLightMode.EDGELIGHT_AUTO**<br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>**Note:** When the value is **EDGELIGHT_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for the effect to take effect, and the edge light effect is automatically applied based on the device computing power tier (effective on high-tier computing power devices, ineffective on mid- and low-tier computing power devices). Edge light animation increases rendering overhead, so exercise caution when using it on low-end devices. For the meaning of each enum value, see [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode). |