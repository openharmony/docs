# Interfaces (Others)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92; @liyi0903; @mayaolll-->
<!--Designer: @piggyguy; @liyi0903; @jiangdayuan-->
<!--Tester: @fredyuan912-->
<!--Adviser: @HelloCrease-->

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## TargetInfo<sup>18+</sup>

Specifies the target node for component binding.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| id | string \| number | No| No| Target node for binding popups or menus.<br>**NOTE**<br>1. When **id** is a number, it corresponds to the component's **UniqueID**, whose uniqueness is guaranteed by the system.<br>2. When **id** is a string, it corresponds to the component specified by the universal attribute [id](arkui-ts/ts-universal-attributes-component-id.md#id). You must ensure the uniqueness of this ID, although there may be multiple instances.|
| componentId | number | No| Yes| Unique ID of the custom component where the target node is located. When the above **id** is specified as a string, this property can be used to narrow down the scope, helping you ensure the uniqueness of **id: string** within a certain range.|

## PageInfo<sup>12+</sup>

Represents the page information of the router or navigation destination. If there is no related page information, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- |-------- | -------- |
| routerPageInfo | observer.[RouterPageInfo](js-apis-arkui-observer.md#routerpageinfo) | No|Yes| Router information.|
| navDestinationInfo | observer.[NavDestinationInfo](js-apis-arkui-observer.md#navdestinationinfo) | No|Yes| Navigation destination information.|

## OverlayManagerOptions<sup>15+</sup>

Provides the parameters used for initializing [OverlayManager](arkts-apis-uicontext-overlaymanager.md).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name            | Type               | Read Only| Optional  | Description                    |
| --------------- | ---------------------- | ------------ | --------------------- | --------------------- |
| renderRootOverlay   | boolean | No| Yes| Whether to render the overlay root node. The value **true** means to render the overlay root node, and **false** means the opposite. The default value is **true**.<br>**Atomic service API**: This API can be used in atomic services since API version 15.|
| enableBackPressedEvent<sup>19+</sup>   | boolean | No| Yes| Whether to enable the swipe-to-dismiss gesture for **ComponentContent** under **OverlayManager**. The value **true** means to enable the swipe-to-dismiss gesture, and **false** means the opposite. Default value: **false**.<br>**Atomic service API**: This API can be used in atomic services since API version 19.|

## GestureTriggerInfo<sup>20+</sup>

Defines the information provided when a specific gesture callback is triggered.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  | Mandatory      |Description      |
| ------ | ---- | ---------- |---------- |
| event | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-settings.md#gestureevent)  |Yes      |Gesture event object.|
| current | [GestureRecognizer](arkui-ts/ts-gesture-blocking-enhancement.md#gesturerecognizer)    |Yes     |Gesture recognizer object. Detailed gesture information can be obtained from this object. However, avoid retaining this object locally as it may become invalid after the node is released.|
| currentPhase  | [GestureActionPhase](arkts-apis-uicontext-e.md#gestureactionphase20) |Yes     | Phase of the gesture action callback.|
| node  | [FrameNode](js-apis-arkui-frameNode.md) |No     |Node that triggers the gesture. The default value is **null**, indicating that no specific node triggers the gesture.|

## GestureObserverConfigs<sup>20+</sup>

Specifies the gesture callback phases to listen for (passing an empty array will be ineffective). Notifications are sent only when the gesture triggers the specified phases.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type  | Mandatory      |Description      |
| ------ | ---- | ---------- |---------- |
|  actionPhases | Array\<[GestureActionPhase](arkts-apis-uicontext-e.md#gestureactionphase20)\>    |Yes      |Gesture event object.|
