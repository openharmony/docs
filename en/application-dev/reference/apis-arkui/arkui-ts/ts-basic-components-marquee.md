# Marquee

The **Marquee** component is used to display a scrolling piece of text. The text is scrolled only when its width exceeds the width of the **Marquee** component.


>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
>  To ensure that scrolling frame rates are not affected, it is recommended that the number of **Marquee** components in a scroll container does not exceed four, or alternatively, use the [Text](ts-basic-components-text.md) component's [TextOverflow.MARQUEE](ts-appendix-enums.md#textoverflow) as a substitute.

## Child Components

Not supported


## APIs

Marquee(value: { start: boolean, step?: number, loop?: number, fromStart?: boolean, src: string })

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | { start: boolean, step?: number, loop?: number, fromStart?: boolean, src: string } | Yes| Parameters of the marquee.<br>**start**: whether to start scrolling.<br>**NOTE**<br>This parameter cannot be used to restart scrolling that has been completed.<br>- **step**: scrolling step. If the step is greater than the text width, the default value is taken.<br>Default value: **6**, in vp<br>- **loop**: number of times the marquee will scroll. If the value is less than or equal to **0**, the marquee will scroll continuously.<br>Default value: **-1**<br>**NOTE**<br>Regardless of the value, the marquee scrolls only once on an ArkTS widget.<br>- **fromStart**: whether the text scrolls from the start.<br>Default value: **true**<br>- **src**: text to scroll.|

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

### fontColor

fontColor(value: ResourceColor)

Sets the font color.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                      | Mandatory| Description      |
| ------ | ------------------------------------------ | ---- | ---------- |
| value  | [ResourceColor](ts-types.md#resourcecolor) | Yes  | Font color.|

### fontSize

fontSize(value: number | string | Resource)

Sets the text size.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [Resource](ts-types.md#resource) \| number \| string | Yes  | Font size. If **fontSize** is of the number type, the unit fp is used. The default font size is 16 fp. This parameter cannot be set in percentage.|

### fontWeight

fontWeight(value: number | FontWeight | string)

Sets the font weight. If the value is too large, the text may be clipped depending on the font.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | Yes  | Font weight. For the number type, the value range is [100, 900], at an interval of 100. The default value is **400**. A larger value indicates a heavier font weight. For the string type, only strings that represent a number, for example, **"400"**, and the following enumerated values of **FontWeight** are supported: **"bold"**, **"bolder"**, **"lighter"**, **"regular"**, and **"medium"**.<br>Default value: **FontWeight.Normal**|

### fontFamily

fontFamily(value: string | Resource)

Sets the font family.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                | Mandatory| Description                                                        |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [Resource](ts-types.md#resource) \| string | Yes  | Font family. Default font: **'HarmonyOS Sans'**<br>The 'HarmonyOS Sans' font and [registered custom fonts](../js-apis-font.md) are supported for applications.<br>Only the 'HarmonyOS Sans' font is supported for widgets.|

### allowScale

allowScale(value: boolean)

Sets whether to allow text to scale.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                |
| ------ | ------- | ---- | ------------------------------------ |
| value  | boolean | Yes  | Whether to allow text to scale.<br>Default value: **false**<br>**NOTE**<br>This parameter is effective only when **fontSize** is in fp units.|

### marqueeUpdateStrategy<sup>12+</sup>

marqueeUpdateStrategy(value: MarqueeUpdateStrategy)

Sets the scrolling strategy for the marquee after its attributes are updated. (This attribute takes effect when the marquee is in the playing state and the text content width exceeds the width of the marquee component.)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                |
| ------ | ------- | ---- | ------------------------------------ |
| value |[MarqueeUpdateStrategy](ts-appendix-enums.md#marqueeupdatestrategy12)| Yes| Scrolling strategy of the marquee after its attributes are updated.<br>Default value: **MarqueeUpdateStrategy.DEFAULT**|

## Events

### onStart

onStart(event: () =&gt; void)

Called when the marquee text changes or starts scrolling.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onBounce

onBounce(event: () =&gt; void)

Triggered when the marquee has reached the end. This event will be triggered for multiple times if the **loop** attribute is not set to **1**.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### onFinish

onFinish(event: () =&gt; void)

Triggered when the marquee has finished the number of scrolling times set by the **loop** attribute.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Example


```ts
// xxx.ets
@Entry
@Component
struct MarqueeExample {
  @State start: boolean = false
  @State src: string = ''
  @State marqueeText: string = 'Running Marquee'
  private fromStart: boolean = true
  private step: number = 10
  private loop: number = Number.POSITIVE_INFINITY
  controller: TextClockController = new TextClockController()
  convert2time(value: number): string{
    let date = new Date(Number(value+'000'));
    let hours = date.getHours().toString().padStart(2, '0');
    let minutes = date.getMinutes().toString().padStart(2, '0');
    let seconds = date.getSeconds().toString().padStart(2, '0');
    return hours+ ":" + minutes + ":" + seconds;
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Marquee({
        start: this.start,
        step: this.step,
        loop: this.loop,
        fromStart: this.fromStart,
        src: this.marqueeText + this.src
      })
        .marqueeUpdateStrategy(MarqueeUpdateStrategy.PRESERVE_POSITION)
        .width(300)
        .height(80)
        .fontColor('#FFFFFF')
        .fontSize(48)
        .fontWeight(700)
        .backgroundColor('#182431')
        .margin({ bottom: 40 })
        .onStart(() => {
          console.info('Marquee animation complete onStart')
        })
        .onBounce(() => {
          console.info('Marquee animation complete onBounce')
        })
        .onFinish(() => {
          console.info('Marquee animation complete onFinish')
        })
      Button('Start')
        .onClick(() => {
          this.start = true
          // Start the text clock.
          this.controller.start()
        })
        .width(120)
        .height(40)
        .fontSize(16)
        .fontWeight(500)
        .backgroundColor('#007DFF')
      TextClock({ timeZoneOffset: -8, controller: this.controller })
        .format('hms')
        .onDateChange((value: number) => {
          this.src = this.convert2time(value);
        })
        .margin(20)
        .fontSize(30)
    }
    .width('100%')
    .height('100%')
  }
}
```

![marquee](figures/marquee.gif)
