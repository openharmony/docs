# ViewData

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=0dd5abdb86dc8faf6072b7e90ffea179b52ea3b4 translatedAt=2026-08-13T13:22:36.052Z pushedAt=2026-08-17T07:23:27.146Z -->

View data information for autofill.

**Since**: 26.0.0

## ViewData

**Since**: 26.0.0

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.Ability.AbilityRuntime.AbilityCore

**Model restriction:** This API can be used only in the stage model.

| Name          | Type   | Read-Only | Optional | Description       |
| ------------- | ------ | ---- | ---- | --------- |
| bundleName    | string | No   | No   | App name. |
| pageUrl       | string | No   | No   | URL of the page. |
| pageNodeInfos | Array\<[PageNodeInfo](js-apis-inner-application-pageNodeInfo.md)> | No   | No   | Information about the page nodes. |
| pageRect      | [AutoFillRect](js-apis-inner-application-autoFillRect.md)         | No   | No   | Position coordinates and width and height information of the page. On PC/2-in-1 devices, Password Vault is displayed as a dialog box. To ensure that the dialog box position follows the input box, set both left and top to 0. |