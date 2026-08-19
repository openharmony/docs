# Types

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @yihao-lin-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @Brilliantry_Rui-->

This file describes the types related to ArkUI UIContext, including types for custom component building, UIObserver event listener callbacks, node identifier, pointer style, and context.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CustomBuilderWithId<sup>18+</sup>

type CustomBuilderWithId = (id: number)&nbsp;=&gt;&nbsp;void

Defines a type that can be used for component attributes and method parameters to customize the UI description and generate custom components with a specific component ID.

**Atomic service API**: This API can be used in atomic services since API version 18.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | number | Yes| Component ID.|

## ClickEventListenerCallback

type ClickEventListenerCallback = (event: ClickEvent, node?: FrameNode) => void

Defines the callback type for listening for click events in **UIObserver**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| event | [ClickEvent](../apis-arkui/arkui-ts/ts-universal-events-click.md#clickevent) | Yes| Information about the click event that triggers the callback.|
| node | [FrameNode](js-apis-arkui-frameNode.md) | No| Component bound to the click event. If this parameter is not passed, **undefined** is used by default.|

## PanListenerCallback<sup>19+</sup>

type PanListenerCallback = (event: GestureEvent, current: GestureRecognizer, node?: FrameNode) => void

Pan gesture event listener callback type. It can be used in scenarios where you need to listen for pan gesture interactions such as dragging and translating components.

**Atomic service API**: This API can be used in atomic services since API version 19.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type             | Mandatory| Description                               |
| ------- | ----------------- | ---- | --------------------------------- |
| event   | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-common.md#gestureevent)      | Yes  | Information about the gesture event that triggers the callback.  |
| current | [GestureRecognizer](arkui-ts/ts-gesture-common.md#gesturerecognizer12) | Yes  | Information about the gesture recognizer that detects the event. |
| node | [FrameNode](js-apis-arkui-frameNode.md) | No| Component bound to the gesture event. If this parameter is not passed, **undefined** is used by default.|

## GestureEventListenerCallback

type GestureEventListenerCallback = (event: GestureEvent, node?: FrameNode) => void

Defines the callback type for gesture event listeners in **UIObserver**.

**Atomic service API**: This API can be used in atomic services since API version 12.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| event | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-common.md#gestureevent) | Yes| Information about the gesture event that triggers the callback.|
| node | [FrameNode](js-apis-arkui-frameNode.md) | No| Component bound to the gesture event.|

## NodeIdentity<sup>20+</sup>

type NodeIdentity = string \| number

Defines the component ID.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type             | Description                               |
| ----------------- | --------------------------------- |
| string      | Component ID, which is set using the universal attribute [id](./arkui-ts/ts-universal-attributes-component-id.md#id).  |
| number | System-assigned unique node ID, obtainable via [getUniqueId](js-apis-arkui-frameNode.md#getuniqueid12). |

## NodeRenderStateChangeCallback<sup>20+</sup>

type NodeRenderStateChangeCallback = (state: NodeRenderState, node?: FrameNode) => void

Defines the callback type for listening for the rendering state of a specific node in **UIObserver**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type             | Mandatory| Description                               |
| ------- | ----------------- | ---- | --------------------------------- |
| state | [NodeRenderState](arkts-apis-uicontext-e.md#noderenderstate20) | Yes| Current rendering status of the node, which indicates whether the monitored node is in the renderable state.|
| node | [FrameNode](js-apis-arkui-frameNode.md) | No| Component that triggers the rendering status change listener. When you need to obtain the component node information for which the rendering state has changed, you can retrieve it via this parameter. If the component has been released, null is returned. If this parameter is not passed, **undefined** is used by default.|

## GestureListenerCallback<sup>20+</sup>

type GestureListenerCallback = (info: GestureTriggerInfo) => void

Defines the callback type for listening for specific gesture trigger information in **UIObserver**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type             | Mandatory| Description                               |
| ------- | ----------------- | ---- | --------------------------------- |
| info   | [GestureTriggerInfo](arkts-apis-uicontext-i.md#gesturetriggerinfo20)     | Yes  |  Details of the gesture triggered by the interaction.|

## PointerStyle

type PointerStyle = pointer.PointerStyle

Defines the pointer style.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

|Type|Description|
| -- | -- |
|[pointer.PointerStyle](../apis-input-kit/js-apis-pointer.md#pointerstyle) |Pointer style.|

## Context

type Context = common.Context

Defines the context of the ability (application component) where the current component is located.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type|Description  |
| ------ | ------------------- |
| [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context) |Context object associated with the current ability.|

## OnOverlayBackPressCallback

type OnOverlayBackPressCallback = () => boolean

Defines the callback type for intercepting overlay side-swipe back events.

**Since:** 26.0.0

**Model restriction**: This API can be used only in the stage model.

**Atomic service API:** This API can be used in atomic services since API version 26.0.0.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Returns:**

| Type| Description|
| -------- | -------- |
| boolean | Whether to intercept the back event.<br>The value **true** indicates that the back event is intercepted and will not be passed to the lower-layer component. The value **false** indicates that the back event is not intercepted and will be transparently passed to the lower-layer component.|
