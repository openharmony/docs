# Button

The **\<Button>** component can be used to create different types of buttons.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component can contain only one child component.


## APIs

**API 1:** Button(options?: {type?: ButtonType, stateEffect?: boolean})

**Parameters**

| Name        | Type      | Mandatory       | Description                             |
| ----------- | ---------- | ------| --------------------------------- |
| type        | ButtonType | No   | Button type.<br>Default value: **ButtonType.Capsule**                          |
| stateEffect | boolean    | No   |  Whether to enable the pressed effect on the click of the button. The value **false** means to disable the pressed effect.<br>Default value: **true**|


**API 2:** Button(label?: ResourceStr, options?: { type?: ButtonType, stateEffect?: boolean })

  Creates a button component based on text content. In this case, the component cannot contain child components.

**Parameters**

| Name    | Type                               | Mandatory  | Description         |
| ------- | ----------------------------------- | ---- | ------------- |
| label   | [ResourceStr](ts-types.md#resourcestr) | No   | Button text.      |
| options | { type?: ButtonType, stateEffect?: boolean }   | No   | See parameters of API 1.|


## Attributes

| Name         | Type          | Description                               |
| ----------- | ----------- | --------------------------------- |
| type        | ButtonType  |  Button type.<br>Default value: **ButtonType.Capsule**                      |
| stateEffect | boolean     |  Whether to enable the pressed effect on the click of the button. The value **false** means to disable the pressed effect.<br>Default value: **true**|

## ButtonType enums
| Name     | Description                |
| ------- | ------------------ |
| Capsule | Capsule-type button (the round corner is half of the height by default).|
| Circle  | Circle button.             |
| Normal  | Normal button (without rounded corners by default).     |

>  **NOTE**
>  - The rounded corner of a button is set by using [borderRadius](ts-universal-attributes-border.md), rather than by using the **border** API.
>  - For a button of the **Capsule** type, the **borderRadius** settings do not take effect, and its rounded corner is always half of the button height.
>  - For a button of the **Circle** type, its radius is the value of **borderRadius** (if set) or the width or height (whichever is smaller).
>  - The button text is set using the [text style attributes](ts-universal-attributes-text-style.md).


## Example

```ts
// xxx.ets
@Entry
@Component
struct ButtonExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Normal button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('OK', { type: ButtonType.Normal, stateEffect: true }).borderRadius(8).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Normal, stateEffect: true }) {
          Row() {
            LoadingProgress().width(20).height(20).margin({ left: 12 }).color(0xFFFFFF)
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center)
        }.borderRadius(8).backgroundColor(0x317aff).width(90).height(40)

        Button('Disable', { type: ButtonType.Normal, stateEffect: false }).opacity(0.4)
          .borderRadius(8).backgroundColor(0x317aff).width(90)
      }

      Text('Capsule button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
        Button('OK', { type: ButtonType.Capsule, stateEffect: true }).backgroundColor(0x317aff).width(90)
        Button({ type: ButtonType.Capsule, stateEffect: true }) {
          Row() {
            LoadingProgress().width(20).height(20).margin({ left: 12 }).color(0xFFFFFF)
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })
          }.alignItems(VerticalAlign.Center).width(90).height(40)
        }.backgroundColor(0x317aff)

        Button('Disable', { type: ButtonType.Capsule, stateEffect: false }).opacity(0.4)
          .backgroundColor(0x317aff).width(90)
      }

      Text('Circle button').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, wrap: FlexWrap.Wrap }) {
        Button({ type: ButtonType.Circle, stateEffect: true }) {
          LoadingProgress().width(20).height(20).color(0xFFFFFF)
        }.width(55).height(55).backgroundColor(0x317aff)

        Button({ type: ButtonType.Circle, stateEffect: true }) {
          LoadingProgress().width(20).height(20).color(0xFFFFFF)
        }.width(55).height(55).margin({ left: 20 }).backgroundColor(0xF55A42)
      }
    }.height(400).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![button](figures/button.gif)
