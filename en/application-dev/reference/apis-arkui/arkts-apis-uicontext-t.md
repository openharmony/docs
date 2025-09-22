# Types

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## CustomBuilderWithId<sup>18+</sup>

type CustomBuilderWithId = (id: number) =&gt; void

Defines a type that can be used for component attributes and method parameters to customize the UI description and generate custom components with a specific component ID.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| id | number | Yes| Component ID.|

## ClickEventListenerCallback<sup>12+</sup>

type ClickEventListenerCallback = (event: ClickEvent, node?: FrameNode) => void

Defines a callback for click events in ArkTS.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| event | [ClickEvent](../apis-arkui/arkui-ts/ts-universal-events-click.md#clickevent)| Yes| Information about the click event that triggers the callback.|
| node | [FrameNode](js-apis-arkui-frameNode.md) | No| Component bound to the click event.|

## PanListenerCallback<sup>19+</sup>

type PanListenerCallback = (event: GestureEvent, current: GestureRecognizer, node?: FrameNode) => void

Defines a callback for pan gesture events.

**Atomic service API**: This API can be used in atomic services since API version 19.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type             | Mandatory| Description                               |
| ------- | ----------------- | ---- | --------------------------------- |
| event   | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-settings.md#gestureevent)     | Yes  | Information about the gesture event that triggers the callback.  |
| current | [GestureRecognizer](arkui-ts/ts-gesture-blocking-enhancement.md#gesturerecognizer) | Yes  | Information about the gesture recognizer that detects the event. |
| node    | [FrameNode](js-apis-arkui-frameNode.md)         | No  | Component bound to the gesture event.|

## GestureEventListenerCallback<sup>12+</sup>

type GestureEventListenerCallback = (event: GestureEvent, node?: FrameNode) => void

Defines a callback for gesture events in ArkTS.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory| Description                         |
| ------- | ------ | ---- | --------------------------- |
| event | [GestureEvent](../apis-arkui/arkui-ts/ts-gesture-settings.md#gestureevent)| Yes| Information about the gesture event that triggers the callback.|
| node | [FrameNode](js-apis-arkui-frameNode.md) | No| Component bound to the gesture event.|

## NodeIdentity<sup>20+</sup>

type NodeIdentity = string | number

Defines the component ID.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Type             | Description                               |
| ----------------- | --------------------------------- |
| string      | ID of the target component, set using the universal attributes [id](./arkui-ts/ts-universal-attributes-component-id.md#id).  |
| number | System-assigned unique node ID, obtainable via [getUniqueId](js-apis-arkui-frameNode.md#getuniqueid12). |

## NodeRenderStateChangeCallback<sup>20+</sup>

type NodeRenderStateChangeCallback = (state: NodeRenderState, node?: FrameNode) => void

Defines the callback type for listening for the rendering state of a specific node in **UIObserver**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type             | Mandatory| Description                               |
| ------- | ----------------- | ---- | --------------------------------- |
| state   | [NodeRenderState](arkts-apis-uicontext-e.md#noderenderstate20)     | Yes  | Information about the gesture event that triggers the callback.  |
| node    | [FrameNode](js-apis-arkui-frameNode.md)         | No  | Component bound to the gesture event that triggers the listener; returns **null** if the component has been released.|

## GestureListenerCallback<sup>20+</sup>

type GestureListenerCallback = (info: GestureTriggerInfo) => void

Defines the callback type for listening for specific gesture trigger information in **UIObserver**.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type             | Mandatory| Description                               |
| ------- | ----------------- | ---- | --------------------------------- |
| info   | [GestureTriggerInfo](arkts-apis-uicontext-i.md#gesturetriggerinfo20)     | Yes  |  Details of the gesture triggered by the interaction.|

## PointerStyle<sup>12+</sup>

type PointerStyle = pointer.PointerStyle

Defines the pointer style.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.MultimodalInput.Input.Pointer

|Type|Description|
| -- | -- |
|[pointer.PointerStyle](../apis-input-kit/js-apis-pointer.md#pointerstyle) |Defines the pointer style.|

## Context<sup>12+</sup>

type Context = common.Context

Defines the context of the current ability.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Model restriction**: This API can be used only in the stage model.

| Type|Description  |
| ------ | ------------------- |
| [common.Context](../apis-ability-kit/js-apis-app-ability-common.md#context) |Context object associated with the current ability.|
