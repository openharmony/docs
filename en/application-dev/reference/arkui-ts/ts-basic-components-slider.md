# Slider

The **\<Slider>** component is used to quickly adjust settings, such as the volume and brightness.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Slider(options?:{value?: number, min?: number, max?: number, step?: number, style?: SliderStyle, direction?: Axis, reverse?: boolean})

**Parameters**

| Name                | Type                         | Mandatory| Description                                                    |
| ---------------------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| value                  | number                            | No  | Current progress.<br>Default value: **0**                                  |
| min                    | number                            | No  | Minimum value.<br>Default value: **0**                                  |
| max                    | number                            | No  | Maximum value.<br>Default value: **100**                                |
| step                   | number                            | No  | Step of the slider.<br>Default value: **1**                          |
| style                  | SliderStyle                       | No  | Style of the slider.<br>Default value: **SliderStyle.OutSet**       |
| direction<sup>8+</sup> | [Axis](ts-appendix-enums.md#axis) | No  | Whether the slider moves horizontally or vertically.<br>Default value: **Axis.Horizontal**|
| reverse<sup>8+</sup>   | boolean                           | No  | Whether the slider values are reversed.<br>**NOTE**<br>The value **false** indicates that the values increase from left to right for a horizontal slider and from top to bottom for a vertical slider. The value **true** indicates that the values increase from right to left for a horizontal slider and from bottom to top for a vertical slider.<br>Default value: **false**|

## SliderStyle

| Name    | Description     |
| ------ | ------- |
| OutSet | The slider is on the slider rail.|
| InSet  | The slider is in the slider rail.|

## Attributes

Touch target configuration is not supported.

| Name           | Type   | Description               |
| ------------- | ------- | ----------------- |
| blockColor    | [ResourceColor](ts-types.md#resourcecolor8) | Color of the slider.         |
| trackColor    | [ResourceColor](ts-types.md#resourcecolor8) | Background color of the slider.       |
| selectedColor | [ResourceColor](ts-types.md#resourcecolor8) | Color of the slider rail that has been slid.      |
| showSteps     | boolean | Whether to display the current step.<br>Default value: **false**|
| showTips      | boolean | Whether to display a bubble to indicate the percentage when sliding.<br>Default value: **false**|
| trackThickness      | [Length](ts-types.md#length) | Track thickness of the slider.|
| maxLabel | string | Maximum label.|
| minLabel | string | Minimum label.|


## Events

In addition to the **OnAppear** and **OnDisAppear** universal events, the following events are supported.

| Name                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onChange(callback: (value: number, mode: SliderChangeMode) =&gt; void) | Invoked when the slider slides.<br>**value**: current progress. If the return value contains decimals, you can use **Math.toFixed()** to process the data to the required precision.<br>**mode**: dragging state.|

## SliderChangeMode

| Name    | Value   | Description       |
| ------ | ---- | --------- |
| Begin  | 0    | The user starts to drag the slider.|
| Moving | 1    | The user is dragging the slider. |
| End    | 2    | The user stops dragging the slider.|
| Click    | 3    | The user moves the slider by touching the slider rail.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct SliderExample {
  @State outSetValue: number = 40
  @State inSetValue: number = 40
  @State outVerticalSetValue: number = 40
  @State inVerticalSetValue: number = 40

  build() {
    Column({ space: 5 }) {
      Text('slider out set').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row() {
        Slider({
          value: this.outSetValue,
          min: 0,
          max: 100,
          step: 1,
          style: SliderStyle.OutSet
        })
        .blockColor(Color.Blue)
        .trackColor(Color.Gray)
        .selectedColor(Color.Blue)
        .showSteps(true)
        .showTips(true)
        .onChange((value: number, mode: SliderChangeMode) => {
          this.outSetValue = value
          console.info('value:' + value + 'mode:' + mode.toString())
        })
        Text(this.outSetValue.toFixed(0)).fontSize(16)
      }
      .padding({ top: 50 })
      .width('80%')

      Text('slider in set').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row() {
        Slider({
          value: this.inSetValue,
          min: 0,
          max: 100,
          step: 1,
          style: SliderStyle.InSet
        })
        .blockColor(0xCCCCCC)
        .trackColor(Color.Black)
        .selectedColor(0xCCCCCC)
        .showSteps(false)
        .showTips(false)
        .onChange((value: number, mode: SliderChangeMode) => {
          this.inSetValue = value
          console.info('value:' + value + 'mode:' + mode.toString())
        })
        Text(this.inSetValue.toFixed(0)).fontSize(16)
      }
      .width('80%')

      Row() {
        Column() {
          Text('slider out direction set').fontSize(9).fontColor(0xCCCCCC).width('50%')
          Slider({
            value: this.outVerticalSetValue,
            min: 0,
            max: 100,
            step: 1,
            style: SliderStyle.OutSet,
            direction: Axis.Vertical
          })
          .blockColor(Color.Blue)
          .trackColor(Color.Gray)
          .selectedColor(Color.Blue)
          .showSteps(true)
          .showTips(true)
          .onChange((value: number, mode: SliderChangeMode) => {
            this.outVerticalSetValue = value
            console.info('value:' + value + 'mode:' + mode.toString())
          })
          Text(this.outVerticalSetValue.toFixed(0)).fontSize(16)
        }.width('50%').height(300)

        Column() {
          Text('slider in direction set').fontSize(9).fontColor(0xCCCCCC).width('50%')
          Slider({
            value: this.inVerticalSetValue,
            min: 0,
            max: 100,
            step: 1,
            style: SliderStyle.InSet,
            direction: Axis.Vertical
          })
          .blockColor(0xCCCCCC)
          .trackColor(Color.Black)
          .selectedColor(0xCCCCCC)
          .showSteps(false)
          .showTips(false)
          .onChange((value: number, mode: SliderChangeMode) => {
            this.inVerticalSetValue = value
            console.info('value:' + value + 'mode:' + mode.toString())
          })
          Text(this.inVerticalSetValue.toFixed(0)).fontSize(16)
        }.width('50%').height(300)
      }

    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001211898492](figures/en-us_image_0000001211898492.gif)
