# 均分能力


均分能力是指容器组件尺寸发生变化时，增加或减小的空间均匀分配给容器组件内所有空白区域。它常用于内容数量固定、均分显示的场景，比如工具栏、底部菜单栏等。


均分能力通常通过使用 **Flex均分布局**（[Flex组件](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/arkui-ts/ts-container-flex.md)的justifyContent属性设置为FlexAlign.SpaceEvenly）实现，即子元素在Flex主轴方向等间距布局，相邻元素之间的间距、第一个元素与行首的间距、最后一个元素到行尾的间距都完全一样。


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 均分能力是特殊场景下拉伸能力的简单实现。也可以借助其它方式实现均分能力，如在每个组件间添加Blank组件等。


## 示例：

父容器尺寸变化过程中，图标及文字的尺寸不变，图标间的间距及图标离左右边缘的距离同时均等改变。

![zh-cn_image_0000001291935425](figures/zh-cn_image_0000001291935425.gif)


```ts
@Entry
@Component
struct EquipartitionCapabilitySample {
  const list: number [] = [0, 1, 2, 3];
  @State rate: number = 0.6;

  // 底部滑块，可以通过拖拽滑块改变容器尺寸
  @Builder slider() {
    Slider({ value: this.rate * 100, min: 30, max: 60, style: SliderStyle.OutSet })
      .blockColor(Color.White)
      .width('60%')
      .onChange((value: number) => {
        this.rate = value / 100;
      })
      .position({ x: '20%', y: '80%' })
  }

  build() {
    Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Column() {
        // 均匀分配父容器主轴方向的剩余空间
        Flex({ justifyContent: FlexAlign.SpaceEvenly }) {
          ForEach(this.list, (item) => {
            Column() {
              Image($r("app.media.icon")).width(48).height(48).margin({ top: 8 })
              Text('App name')
                .width(64)
                .height(30)
                .lineHeight(15)
                .fontSize(12)
                .textAlign(TextAlign.Center)
                .margin({ top: 8 })
                .padding({ bottom: 15 })
            }.width(80).height(102)
          })
        }
        // 均匀分配父容器主轴方向的剩余空间
        Flex({ justifyContent: FlexAlign.SpaceEvenly }) {
          ForEach(this.list, (item) => {
            Column() {
              Image($r("app.media.icon")).width(48).height(48).margin({ top: 8 })
              Text('App name')
                .width(64)
                .height(30)
                .lineHeight(15)
                .fontSize(12)
                .textAlign(TextAlign.Center)
                .margin({ top: 8 })
                .padding({ bottom: 15 })
            }.width(80).height(102)
          })
        }
      }
      .width(this.rate * 100 + '%')
      .height(222)
      .padding({ top: 16 })
      .backgroundColor('#FFFFFF')
      .borderRadius(16)

      this.slider()
    }
    .width('100%')
    .height('100%')
    .backgroundColor('#F1F3F5')
  }
}
```
