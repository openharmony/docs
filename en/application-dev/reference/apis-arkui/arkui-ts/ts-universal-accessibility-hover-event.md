# Accessibility Hover Event

When accessibility mode is enabled, touch events are converted into accessibility hover events.

>  **NOTE**
>
>  - The initial APIs of this module are supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
>  - Currently, conversion into accessibility hover events can only be initiated by enabling accessibility mode.

## onAccessibilityHover

onAccessibilityHover(callback: AccessibilityCallback): T

Invoked in accessibility mode when a single finger touches the bound component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name       | Type                   | Mandatory | Description                         |
| ---------- | -------------------------- | ------- | ----------------------------- |
| callback      | [AccessibilityCallback](#accessibilitycallback) | Yes  |  Callback invoked in accessibility mode when a single finger touches the bound component.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Current component.|

## AccessibilityCallback

type AccessibilityCallback = (isHover: boolean, event: AccessibilityHoverEvent) => void

Represents the accessibility hover event callback, which is effective when accessibility mode is enabled.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name             | Type                               | Mandatory| Description                                                        |
| ------------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| isHover             | boolean                             | Yes  | Whether a finger is hovering over the component in accessibility mode. The accessibility hover event is converted from a touch event, with the value **true** when the finger enters the component and **false** when it exits.|
| event | [AccessibilityHoverEvent](#accessibilityhoverevent) | Yes  | **AccessibilityHoverEvent** object.                                  |

## AccessibilityHoverEvent

Inherits from [BaseEvent](ts-gesture-customize-judge.md#baseevent8).

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name             | Type      | Description     |
| --------------- | ---------- | ------- |
| type             | [AccessibilityHoverType](#accessibilityhovertype) | Accessibility hover type.               |
| x                      | number                         | X coordinate of the finger's position relative to the upper left corner of the component being touched.<br>Unit: vp<br>|
| y                      | number                         | Y coordinate of the finger's position relative to the upper left corner of the component being touched.<br>Unit: vp<br>|
| windowX                | number                         | X coordinate of the finger's position relative to the upper left corner of the application window.<br>Unit: vp<br>|
| windowY                | number                         | Y coordinate of the finger's position relative to the upper left corner of the application window.<br>Unit: vp<br>|
| displayX               | number                         | X coordinate of the finger's position relative to the upper left corner of the display.<br>Unit: vp<br>|
| displayY               | number                         | Y coordinate of the finger's position relative to the upper left corner of the display.<br>Unit: vp<br>|

## AccessibilityHoverType

Enumerates the accessibility hover types.

| Name   | Value  | Description                              |
| ------- | ---- | ---------------------------------- |
| HOVER_ENTER | 0    | A finger is pressed.|
| HOVER_MOVE  | 1    | The touch moves.|
| HOVER_EXIT  | 2    | The finger is lifted.|
| HOVER_CANCEL | 3    | The current event is canceled.|

## Example

This example demonstrates how to use the **onAccessibilityHover** event to customize a button in accessibility mode.

```ts
// xxx.ets
@Entry
@Component
struct OnAccessibilityHoverEventExample {
  @State hoverText: string = 'no hover';
  @State color: Color = Color.Blue;

  build() {
    Column({ space: 20 }) {
      Button(this.hoverText)
        .width(180).height(80)
        .backgroundColor(this.color)
        .onAccessibilityHover((isHover: boolean, event: AccessibilityHoverEvent) => {
          // Use the onAccessibilityHover event to dynamically change the text content and background color of a button when the finger is hovered on it.
          if (isHover) {
            this.hoverText = 'hover';
            this.color = Color.Pink;
          } else {
            this.hoverText = 'no hover';
            this.color = Color.Blue;
          }
        })
    }.padding({ top: 30 }).width('100%')
  }
}
```
