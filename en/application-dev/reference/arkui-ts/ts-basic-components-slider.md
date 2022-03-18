# Slider


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Slider&gt;** component is used to quickly adjust settings, such as the volume and brightness.


## Required Permissions

None


## Child Components

None


## APIs

Slider(value:{value?: number, min?: number, max?: number, step?: number, style?: SliderStyle, direction?: Axis})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | No | 0 | Current&nbsp;progress. |
  | min | number | No | 0 | Minimum&nbsp;value. |
  | max | number | No | 100 | Maximum&nbsp;value. |
  | step | number | No | 1 | Step&nbsp;of&nbsp;the&nbsp;slider.&nbsp;When&nbsp;the&nbsp;corresponding&nbsp;step&nbsp;is&nbsp;set,&nbsp;the&nbsp;slider&nbsp;slides&nbsp;intermittently. |
  | style | SliderStyle | No | SliderStyle.OutSet | Style&nbsp;of&nbsp;the&nbsp;slider. |
  | direction<sup>8+</sup> | [Axis](ts-appendix-enums.md) | No | Axis.Horizontal | Whether&nbsp;the&nbsp;slider&nbsp;moves&nbsp;horizontally&nbsp;or&nbsp;vertically. |
  | reverse<sup>8+</sup> | boolean | No | false | Whether&nbsp;the&nbsp;slider&nbsp;values&nbsp;are&nbsp;reversed. |

- SliderStyle enums
    | Name | Description | 
  | -------- | -------- |
  | OutSet | The&nbsp;slider&nbsp;is&nbsp;on&nbsp;the&nbsp;slider&nbsp;rail. | 
  | InSet | The&nbsp;slider&nbsp;is&nbsp;in&nbsp;the&nbsp;slider&nbsp;rail. | 


## Attributes

Touch target configuration is not supported.

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| blockColor | Color | - | Color&nbsp;of&nbsp;the&nbsp;slider. | 
| trackColor | Color | - | Background&nbsp;color&nbsp;of&nbsp;the&nbsp;slider. | 
| selectedColor | Color | - | Color&nbsp;of&nbsp;the&nbsp;slider&nbsp;rail&nbsp;that&nbsp;has&nbsp;been&nbsp;slid. | 
| showSteps | boolean | false | Whether&nbsp;to&nbsp;display&nbsp;the&nbsp;current&nbsp;step. | 
| showTips | boolean | false | Whether&nbsp;to&nbsp;display&nbsp;a&nbsp;bubble&nbsp;to&nbsp;indicate&nbsp;the&nbsp;percentage&nbsp;when&nbsp;sliding. | 


## Events

Among all the universal events, only **OnAppear** and **OnDisAppear** are supported.

| Name | Description |
| -------- | -------- |
| onChange(callback:&nbsp;(value:&nbsp;number,&nbsp;mode: SliderChangeMode)&nbsp;=&gt;&nbsp;void) | Callback&nbsp;invoked&nbsp;when&nbsp;the&nbsp;slider&nbsp;slides.<br/>**value**:&nbsp;current&nbsp;progress.<br/>**mode**:&nbsp;dragging&nbsp;state. |

- SliderChangeMode enums
    | Name | Description | 
  | -------- | -------- |
  | Begin | The&nbsp;user&nbsp;starts&nbsp;to&nbsp;drag&nbsp;the&nbsp;slider. | 
  | Moving | The&nbsp;user&nbsp;is&nbsp;dragging&nbsp;the&nbsp;slider. | 
  | End | The&nbsp;user&nbsp;stops&nbsp;dragging&nbsp;the&nbsp;slider. | 


## Example


```
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
