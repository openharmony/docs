# Slider

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


滑动条组件，用来快速调节设置值，如音量、亮度等。


## 权限列表

无


## 子组件

无


## 接口

Slider(value:{value?: number, min?: number, max?: number, step?: number, style?: SliderStyle, direction?: Axis})

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | 否 | 0 | 当前进度值。 |
  | min | number | 否 | 0 | 设置最小值。 |
  | max | number | 否 | 100 | 设置最大值。 |
  | step | number | 否 | 1 | 设置Slider滑动跳动值，当设置相应的step时，Slider为间歇滑动。 |
  | style | SliderStyle | 否 | SliderStyle.OutSet | 设置Slider的滑块样式。 |
  | direction<sup>8+</sup> | [Axis](ts-appendix-enums.md#axis枚举说明) | 否 | Axis.Horizontal | 设置滑动条滑动方向为水平或竖直方向。 |
  | reverse<sup>8+</sup> | boolean | 否 | false | 设置滑动条取值范围是否反向。 |

- SliderStyle枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | OutSet | 滑块在滑轨上。 | 
  | InSet | 滑块在滑轨内。 | 


## 属性

不支持触摸热区设置。

| 名称 | 参数类型 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| blockColor | Color | - | 设置滑块的颜色。 | 
| trackColor | Color | - | 设置滑轨的背景颜色。 | 
| selectedColor | Color | - | 设置滑轨的已滑动颜色。 | 
| showSteps | boolean | false | 设置当前是否显示步长刻度值。 | 
| showTips | boolean | false | 设置滑动时是否显示气泡提示百分比。 | 


## 事件

通用事件仅支持：OnAppear，OnDisAppear。

| 名称 | 功能描述 | 
| -------- | -------- |
| onChange(callback:&nbsp;(value:&nbsp;number,&nbsp;mode:&nbsp;SliderChangeMode)&nbsp;=&gt;&nbsp;void） | Slider滑动时触发事件回调。<br/>value：当前进度值。<br/>mode：拖动状态。 | 

- SliderChangeMode枚举说明
  | 名称 | 描述 | 
  | -------- | -------- |
  | Begin | 用户开始拖动滑块。 | 
  | Moving | 用户拖动滑块中。 | 
  | End | 用户结束拖动滑块。 | 


## 示例

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

![zh-cn_image_0000001179613854](figures/zh-cn_image_0000001179613854.gif)
