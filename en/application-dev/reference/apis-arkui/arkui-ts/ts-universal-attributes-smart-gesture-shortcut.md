# Smart Gesture Response

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=438fa85da87f5e46f9b1e09fbfaa37fb46362b8b translatedAt=2026-08-11T01:48:31.485Z pushedAt=2026-08-13T10:38:48.416Z -->

The smart gesture response is used to configure whether a component responds to smart gestures, whether to show and retain the selected state, and the response priority. It applies to scenarios where control over whether a component can be selected or prioritized in smart gesture operations is needed, improving the controllability of target component responses in smart gesture interactions.

**Since:** 26.0.0

## smartGestureShortcut

smartGestureShortcut(options?: SmartGestureShortcutOptions): T

Sets the smart gesture response behavior of the component. This attribute is only used to declare whether the component responds to smart gestures, and does not directly trigger actions such as tap, scroll, page turning, or back.

**Since:** 26.0.0

**Model restriction:** This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type | Mandatory | Description |
| ------ | ---- | ---- | ---- |
| options | [SmartGestureShortcutOptions](#smartgestureshortcutoptions) | No | Configuration for the smart gesture response of the component.<br>In **SmartGestureShortcutOptions**, **enabled** is used to configure whether the component responds to smart gestures.<br>**selectable** is used to set whether to show and retain the selected state after the component is selected by a smart gesture operation.<br>**action** is used to set the smart gesture response priority. Currently, only **GestureShortcut.PRIMARY** is supported, which makes the component the preferred response target in operations supported by smart gestures, such as swipe and tap.<br>It is recommended to pass this parameter explicitly to avoid unexpected behavior due to default configuration. For default configuration handling, see [SmartGestureShortcutOptions](#smartgestureshortcutoptions). |

**Return value**

| Type | Description |
| ---- | ---- |
| T | Current component, used for chaining attribute methods. |

**Example**

Refer to the smart gesture controller [Example 1: Enabling Smart Gestures and Customizing Action Handling](../arkts-apis-uicontext-smartgesturecontroller.md#example-1-enabling-smart-gestures-and-customizing-action-handling).

## SmartGestureShortcutOptions

Defines the configuration object for smart Gesture response behavior.

**Since:** 26.0.0

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability:** SystemCapability.ArkUI.ArkUI.Full

**Model restriction:** This API can be used only in the stage model.

| Name | Type | Read-Only | Optional | Description |
| ---- | ---- | ---- | ---- | ---- |
| action | [GestureShortcut](ts-appendix-enums.md#gestureshortcut) | No | Yes | Smart gesture response priority. Currently, only **GestureShortcut.PRIMARY** is supported, which indicates that the component serves as the preferred response target in smart gesture operations such as swiping and tapping.<br>Default value: **GestureShortcut.PRIMARY**. |
| enabled | boolean | No | Yes | Whether the current component responds to smart gestures.<br>The value **true** indicates that the component responds to smart gestures, and **false** indicates that the component does not respond to smart gestures.<br>Default value: **false**. |
| selectable | boolean | No | Yes | Whether to show and retain the selected state after the component is selected by a smart gesture operation.<br>The value **true** indicates that the selection box is displayed, and **false** indicates that the selection box is not displayed.<br>When **enabled** is **true**, the default value is **true**; when **enabled** is **false**, the default value is **false**. |