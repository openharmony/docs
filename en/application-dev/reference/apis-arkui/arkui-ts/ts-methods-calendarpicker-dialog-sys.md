# Calendar Picker Dialog Box (CalendarPickerDialog) (System API)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @luoying_ace_admin-->
<!--Designer: @weixin_52725220-->
<!--Tester: @xiong0104-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=10b2ec492471417f959c9192926575fb5bccbfca translatedAt=2026-08-11T01:47:12.937Z pushedAt=2026-08-13T08:29:25.890Z -->

The calendar picker dialog box provides date selection functionality, allowing users to select a date in the dialog box. It is suitable for scenarios that require date input, such as appointment management and task scheduling.

> **NOTE**
>
> - This component is supported since API version 10. Updates to new APIs in later versions are marked with a superscript to indicate the API's since version.
>
> - The functionality of this module depends on the UI execution context and cannot be used where the [UI context is ambiguous](../../../ui/arkts-global-interface.md#ambiguous-ui-context). See [UIContext](../arkts-apis-uicontext-uicontext.md) for details.
>
> - This page covers only the system APIs of this module. For other public APIs, see [Calendar Picker Dialog Box (CalendarPickerDialog)](ts-methods-calendarpicker-dialog.md).

## CalendarDialogOptions

Defines the options for the calendar picker dialog box.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name       | Type                                            | Read-Only | Optional | Description                                                        |
| ---------- | ----------------------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| distortionMode | [DistortionMode](./ts-appendix-enums-sys.md#distortionmode) | No | Yes | Distortion animation mode of the dialog box under system materials. This parameter is passed when a custom distortion animation effect is needed for the dialog box.<br>**Default value:** **DistortionMode.DISTORTION_AUTO** <br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>Note: When the value is **DISTORTION_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for the effect to take effect, and the distortion effect is automatically applied based on the device performance tier (effective on high- and mid-tier devices, not effective on low-tier devices). Distortion animation increases rendering overhead, so use it with caution on low-end devices. For the meaning of each enum value, see [DistortionMode](./ts-appendix-enums-sys.md#distortionmode).|
| edgeLightMode | [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode) | No | Yes | Edge light animation mode of the dialog box under system materials. This parameter is passed when a custom edge light animation effect is needed for the dialog box.<br>**Default value:** **EdgeLightMode.EDGELIGHT_AUTO** <br>**Since:** 26.0.0<br>**System API:** This is a system API.<br>**Model restriction:** This API can be used only in the stage model.<br>**Atomic service API:** This API can be used in atomic services since API version 26.0.0.<br>Note: When the value is **EDGELIGHT_AUTO**, the [IMMERSIVE](../arkts-apis-uimaterial.md#immersivematerial) material type must be set for the effect to take effect, and the edge light effect is automatically applied based on the device performance tier (effective on high-tier devices, not effective on mid- and low-tier devices). Edge light animation increases rendering overhead, so use it with caution on low-end devices. For the meaning of each enum value, see [EdgeLightMode](./ts-appendix-enums-sys.md#edgelightmode). |