# 折行能力


折行能力是指容器组件尺寸发生变化，当布局方向尺寸不足以显示完整内容时自动换行。它常用于横竖屏适配或默认设备向平板切换的场景。


折行能力通过使用 **Flex折行布局** （将warp属性设置为FlexWrap.Wrap）实现，当横向布局尺寸不足以完整显示内容元素时，通过折行的方式，将元素显示在下方。


可以访问[Flex组件](../../reference/arkui-ts/ts-container-flex.md)，了解Flex组件的详细用法。


## 示例：

父容器中的图片尺寸固定，当父容器尺寸发生变化，其中的内容做自适应换行。

![zh-cn_image_0000001292215677](figures/zh-cn_image_0000001292215677.gif)


```ts
@Entry
@Component
struct WrapCapabilitySample {
  @State rate: number = 0.7;
  const imageList: Resource [] = [
    $r('app.media.flexWrap1'),
    $r('app.media.flexWrap2'),
    $r('app.media.flexWrap3'),
    $r('app.media.flexWrap4'),
    $r('app.media.flexWrap5'),
    $r('app.media.flexWrap6')
  ];

  // 底部滑块，可以通过拖拽滑块改变容器尺寸
  @Builder slider() {
    Slider({ value: this.rate * 100, min: 50, max: 70, style: SliderStyle.OutSet })
      .blockColor(Color.White)
      .width('60%')
      .onChange((value: number) => {
        this.rate = value / 100;
      })
      .position({ x: '20%', y: '87%' })
  }

  build() {
    Flex({ justifyContent: FlexAlign.Center, direction: FlexDirection.Column }) {
      Column() {
        // 通过Flex组件warp参数实现自适应折行
        Flex({
          direction: FlexDirection.Row,
          alignItems: ItemAlign.Center,
          justifyContent: FlexAlign.Center,
          wrap: FlexWrap.Wrap
        }) {
          ForEach(this.imageList, (item) => {
            Image(item).width(183).height(138).padding(10)
          })
        }
        .backgroundColor('#FFFFFF')
        .padding(20)
        .width(this.rate * 100 + '%')
        .borderRadius(16)
      }
      .width('100%')

      this.slider()
    }.width('100%')
    .height('100%')
    .backgroundColor('#F1F3F5')
  }
}
```
