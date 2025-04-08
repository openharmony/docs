# Enable/Disable Control

You can enable or disable a component to control whether it responds to user interactions. When a component is enabled, it can respond to the following events:

- [Click event](ts-universal-events-click.md)
- [Touch event](ts-universal-events-touch.md)
- [Drag and drop event](ts-universal-events-drag-drop.md)
- [Key event](ts-universal-events-key.md)
- [Focus event](ts-universal-focus-event.md)
- [Mouse event](ts-universal-mouse-key.md)
- [Axis event](ts-universal-events-axis.md)
- [Hover event](ts-universal-events-hover.md)
- [Accessibility hover event](ts-universal-accessibility-hover-event.md)
- [Gesture event](ts-gesture-settings.md)
- [Focus axis event](ts-universal-events-focus_axis.md)
- [Crown event](ts-universal-events-crown.md)

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The **enabled** attribute takes effect only when the component is pressed. It does not work when the component is interacting with the user.

## enabled

enabled(value: boolean)

Sets whether the component responds to user interactions.

**Widget capability**: Since API version 9, this feature is supported in ArkTS widgets.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                                        |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | Yes  | Whether the component responds to user interactions, including clicks and touches. The value **true** means that the component responds to user interactions, and **false** means the opposite.<br>Default value: **true**.|


## Example

This example demonstrates how to use **enable** to set whether a button responds to user interactions.

```ts
// xxx.ets
@Entry
@Component
struct EnabledExample {
  
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // The component does not respond to clicks.
      Button('disable').enabled(false).backgroundColor(0x317aff).opacity(0.4)
      Button('enable').backgroundColor(0x317aff)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![en-us_image_0000001212218428](figures/en-us_image_0000001212218428.gif)
