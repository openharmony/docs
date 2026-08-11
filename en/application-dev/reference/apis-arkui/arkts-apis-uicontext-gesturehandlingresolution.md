# Class (GestureHandlingResolution)

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1679aa2b39603a323ce91f1907155d8cbd2b330b translatedAt=2026-08-11T01:52:53.352Z pushedAt=2026-08-11T06:04:53.417Z -->

Declares the smart gesture handling result.

**Since**: 26.0.0

## constructor

constructor(isConsumed: boolean)

Constructor for the smart gesture handling result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- |
| isConsumed | boolean | Yes | Whether to consume the current smart gesture.<br>The value **true** means to consume the current smart gesture. In this case, if [selectedProposal](#properties) is not set, the system default action handling is used; if [selectedProposal](#properties) is set, custom action handling is used.<br>The value **false** means not to consume, and the system treats this smart gesture as unhandled. |

## Properties

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API**: This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| isConsumed | boolean | No | No | Whether to consume the current smart gesture.<br>The value **true** means to consume the current smart gesture. In this case, if **selectedProposal** is not set, the system default action handling is used; if **selectedProposal** is set, custom action handling is used.<br>The value **false** means not to consume, and the system treats this smart gesture as unhandled. |
| selectedProposal | [BaseGestureHandlingProposal](./arkts-apis-uicontext-basegesturehandlingproposal.md) | No | Yes | Smart gesture handling behavior specified by the user.<br>When **isConsumed** is **true**, if **selectedProposal** is not set, the system default action handling is used; if **selectedProposal** is set, custom action handling is used.<br>When **isConsumed** is **false**, the setting of **selectedProposal** does not take effect. |