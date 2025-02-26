#  ArcButton

The **ArcButton** component represents an arc button specifically designed for circular screens on wearable devices. It offers various button styles, such as emphasized, normal, and warning, tailored for watch UIs.

> **NOTE**
>
> This component is supported since API version 16. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import {
  ArcButton,
  ArcButtonOptions,
  ArcButtonStatus,
  ArcButtonStyleMode,
  ArcButtonPosition,
}  from '@kit.ArkUI';
```

## Child Components

Not supported

## Attributes
The [universal attributes](ts-universal-attributes-size.md) are not supported.

## Events
Among the universal events, the [click event](ts-universal-events-click.md) and [touch event](ts-universal-events-touch.md) are supported.

## ArcButton

ArcButton({options:ArcButtonOptions})

Creates an instance of **ArcButton** with configuration parameters.

**Decorator**: @ComponentV2

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name   | Type            | Mandatory| Decorator | Description                     |
| ------- | ---------------- | ---- | ----------- | ------------------------- |
| options | [ArcButtonOptions](#arcbuttonoptions) | Yes  | @ObservedV2 | Text, background color, shadow, and other parameters of the **ArcButton** component.|



## ArcButtonOptions

Defines the default or custom style parameters for the **ArcButton** component.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name            | Type                                                        | Mandatory| Description                                                        |
| ---------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| position         | [ArcButtonPosition](#arcbuttonposition)                      | No  | Type of the arc button.<br>Default value: lower arc button                |
| styleMode        | [ArcButtonStyleMode](#arcbuttonstylemode)                    | No  | Style mode for the arc button.<br>Default value: **ArcButtonStyleMode.EMPHASIZED_LIGHT**|
| status           | [ArcButtonStatus](#arcbuttonstatus)                          | No  | Status of the arc button.<br>Default value: **ArcButtonStatus.NORMAL**         |
| label     | [ResourceStr](ts-types.md#resourcestr)                       | No  | Text displayed on the arc button.                                          |
| backgroundBlurStyle | [BlurStyle](ts-universal-attributes-background.md#blurstyle9) | No  | Background blur style of the arc button.<br>Default value: **BlurStyle.NONE**|
| backgroundColor  | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)  | No  | Background color of the arc button.<br>Default value: **Color.Black**                |
| shadowColor      | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)  | No  | Shadow color of the arc button.<br>Default value: **Color.Black**                |
| shadowEnabled    | boolean                                                      | No  | Whether to enable the shadow for the arc button.<br>Default value: **false**                      |
| fontSize | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | No  | Font size of the arc button.<br>Default value: **19fp**                       |
| fontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)  | No  | Font color of the arc button.<br>Default value: **Color.White**                |
| pressedFontColor | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12)  | No  | Font color of the arc button when pressed.<br>Default value: **Color.White**            |
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle)                  | No  | Font style of the arc button.<br>Default value: **FontStyle.Normal**           |
| fontFamily | string \| [Resource](ts-types.md#resource)                   | No  | Font family of the arc button text.                                            |
| fontMargin | [LocalizedMargin](ts-types.md#localizedmargin12)             | No  | Margin of the arc button text.<br>Default value: **{ start: 24vp, top: 10vp,end: 24vp, bottom:16vp }**|
|onTouch | (event: [TouchEvent](ts-universal-events-touch.md#touchevent)) => void | No  | Callback triggered by touch actions on the arc button.|
|onClick | (event: [ClickEvent](ts-universal-events-click.md#clickevent)) => void | No  | Callback triggered by click actions on the arc button.|


## ArcButtonPosition

Enumerates the types of arc buttons that can be set for **ArcButton**.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name       | Value  | Description                            |
| ----------- | ---- | -------------------------------- |
| TOP_EDGE    | 0    | Upper arc button located at the top of the circular screen.    |
| BOTTOM_EDGE | 1    | Lower arc button located at the bottom of the circular screen.|


## ArcButtonStyleMode

Enumerates the style modes that can be set for **ArcButton**.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name            | Value  | Description            |
| ---------------- | ---- | ---------------- |
| EMPHASIZED_LIGHT | 0    | Emphasized, light color.|
| EMPHASIZED_DARK  | 1    | Emphasized, dark color.|
| NORMAL_LIGHT     | 2    | Normal, light color.|
| NORMAL_DARK      | 3    | Normal, dark color.|


## ArcButtonStatus

Enumerates the states that can be set for **ArcButton**.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Circle

| Name    | Value  | Description      |
| -------- | ---- | ---------- |
| NORMAL   | 0    | Normal state.|
| PRESSED  | 1    | Pressed state.|
| DISABLED | 2    | Disabled state.|



## Example

This example shows the usage of **ArcButton**.

**topOptions** defines an upper arc button with the button text "ButtonTop," a font size of 15 fp, and shadow enabled, in the normal state with a light-color emphasized style.

**bottomOptions** defines a bottom arc button with the button text "ButtonBottom," a font size of 15 fp, shadow enabled, in a light-color emphasized style, with a click event set for the button.

```ts
// xxx.ets
import {
  ColorMetrics,
  LengthMetrics,
  LengthUnit,
  ArcButton,
  ArcButtonOptions,
  ArcButtonStatus,
  ArcButtonStyleMode,
  ArcButtonTypeMode,
}  from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  @Local topOptions: ArcButtonOptions = new ArcButtonOptions({})
  @Local bottomOptions: ArcButtonOptions = new ArcButtonOptions({})

  aboutToAppear() {
    this.topOptions = new ArcButtonOptions({
      label: 'ButtonTop',
      status: ArcButtonStatus.NORMAL,
      position: ArcButtonPosition.TOP_EDGE,
      styleMode: ArcButtonStyleMode.EMPHASIZED_LIGHT,
      fontSize: new LengthMetrics(15, LengthUnit.FP),
      shadowEnabled: true
    })

    this.bottomOptions = new ArcButtonOptions({
      label: 'ButtonBottom',
      styleMode: ArcButtonStyleMode.EMPHASIZED_LIGHT,
      fontSize: new LengthMetrics(15, LengthUnit.FP),
      shadowEnabled: true,
      onClick: () => {
        console.info('click from ArcButton.')
      }
    })
  }

  build() {
    Stack() {
      Stack() {
        Circle({ width: 233, height: 233 })
          .strokeWidth(0.1)
          .fill(Color.White)

        Column() {
          ArcButton({ options: this.topOptions })
          Blank()
          ArcButton({ options: this.bottomOptions })

        }.width('100%')
        .height('100%')
      }.width(233)
      .height(233)
    }.width('100%')
    .height('100%')
    .alignContent(Alignment.Center)
    .backgroundColor(Color.Gray)
  }
}

```

![](figures/advanced_arcButton.jpg)
