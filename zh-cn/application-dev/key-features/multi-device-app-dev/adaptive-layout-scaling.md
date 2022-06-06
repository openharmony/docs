# 缩放能力


缩放能力是指子组件的宽高按照预设的比例，随容器组件发生变化，且变化过程中子组件的宽高比不变。


缩放能力通过使用百分比布局配合**固定宽高比**（aspectRatio属性）实现当容器尺寸发生变化时，内容自适应调整。


可以访问[布局约束](../../reference/arkui-ts/ts-universal-attributes-layout-constraints.md)，了解aspectRatio属性的详细信息。


## 示例：

为方便查看效果，示例中特意给Column组件加了边框。可以看到Column组件随着其Flex父组件尺寸变化而缩放的过程中，始终保持预设的宽高比，其中的图片也始终正常显示。

![zh-cn_image_0000001245614634](figures/zh-cn_image_0000001245614634.gif)


```ts
@Entry
@Component
struct ScaleCapabilitySample {
  @State width: number = 400;
  @State height: number = 400;

  // 底部滑块，可以通过拖拽滑块改变容器尺寸
  @Builder slider() {
    Slider({ value: this.width, min: 100, max: 400, style: SliderStyle.OutSet })
      .blockColor(Color.White)
      .width('60%')
      .height(50)
      .onChange((value: number) => {
        this.width = value;
      })
      .position({ x: '20%', y: '80%' })
    Slider({ value: this.height, min: 100, max: 400, style: SliderStyle.OutSet })
      .blockColor(Color.White)
      .width('60%')
      .height(50)
      .onChange((value: number) => {
        this.height = value;
      })
      .position({ x: '20%', y: '87%' })
  }

  build() {
    Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
        Column() {
          Image($r("app.media.illustrator")).width('100%').height('100%')
        }
        .aspectRatio(1)                           // 固定宽高比
        .border({ width: 2, color: "#66F1CCB8"})  // 边框，仅用于展示效果
      }
      .backgroundColor("#FFFFFF")
      .height(this.width)
      .width(this.height)

      this.slider()
    }.width('100%')
    .height('100%')
    .backgroundColor("#F1F3F5")
  }
}
```
