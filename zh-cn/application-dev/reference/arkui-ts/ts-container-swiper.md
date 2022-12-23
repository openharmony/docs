# Swiper
滑动容器，提供切换子组件显示的能力。

> **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含子组件。


## 接口

Swiper(controller?: SwiperController)

**参数：** 

| 参数名        | 参数类型                           | 必填  | 参数描述                 |
| ---------- | ------------------------------------- | ---- | -------------------- |
| controller | [SwiperController](#swipercontroller) | 否   | 给组件绑定一个控制器，用来控制组件翻页。 |


## 属性

不支持[Menu控制](ts-universal-attributes-menu.md)。

| 名称                        | 参数类型                                                     | 描述                                                         |
| --------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| index                       | number                                                       | 设置当前在容器中显示的子组件的索引值。<br/>默认值：0         |
| autoPlay                    | boolean                                                      | 子组件是否自动播放，自动播放状态下，导航点不可操作。<br/>默认值：false |
| interval                    | number                                                       | 使用自动播放时播放的时间间隔，单位为毫秒。<br/>默认值：3000  |
| indicator                   | boolean                                                      | 是否启用导航点指示器。<br/>默认值：true                      |
| loop                        | boolean                                                      | 是否开启循环。<br> 设置为true时表示开启循环，在LazyForEach懒循环加载模式下，加载的组件数量建议大于5个。<br/>默认值：true |
| duration                    | number                                                       | 子组件切换的动画时长，单位为毫秒。<br/>默认值：400           |
| vertical                    | boolean                                                      | 是否为纵向滑动。<br/>默认值：false                           |
| itemSpace                   | number \| string                                             | 设置子组件与子组件之间间隙。<br/>默认值：0                   |
| displayMode                 | SwiperDisplayMode                                            | 设置子组件显示模式。<br/>默认值：SwiperDisplayMode.Stretch   |
| cachedCount<sup>8+</sup>    | number                                                       | 设置预加载子组件个数。<br/>默认值：1                         |
| disableSwipe<sup>8+</sup>   | boolean                                                      | 禁用组件滑动切换功能。<br/>默认值：false                     |
| displayCount<sup>8+</sup>   | number&nbsp;\|&nbsp;string                                   | 设置一页中显示子组件的个数，设置为“auto”时等同于SwiperDisplayMode.AutoLinear的显示效果。<br/>默认值：1 |
| effectMode<sup>8+</sup>     | [EdgeEffect](ts-appendix-enums.md#edgeeffect)                  | 设置滑动到边缘时的显示效果。<br/>默认值：EdgeEffect.Spring   |
| curve<sup>8+</sup>          | [Curve](ts-appendix-enums.md#curve) \| string                | 设置Swiper的动画曲线，默认为淡入淡出曲线，常用曲线参考[Curve枚举说明](ts-appendix-enums.md#curve)，也可以通过插值计算模块提供的接口创建自定义的Curves([插值曲线对象](ts-interpolation-calculation.md))。<br/>默认值：Curve.Ease |
| indicatorStyle<sup>8+</sup> | {<br/>left?:&nbsp;[Length](ts-types.md#length),<br/>top?:&nbsp;[Length](ts-types.md#length),<br/>right?:&nbsp;[Length](ts-types.md#length),<br/>bottom?:&nbsp;[Length](ts-types.md#length),<br/>size?:&nbsp;[Length](ts-types.md#length),<br/>mask?:&nbsp;boolean,<br/>color?:&nbsp;[ResourceColor](ts-types.md#resourcecolor8),<br/>selectedColor?:&nbsp;[ResourceColor](ts-types.md#resourcecolor8)<br/>} | 设置导航点样式：<br/>-&nbsp;left:&nbsp;设置导航点距离Swiper组件左边的距离。<br/>-&nbsp;top:&nbsp;设置导航点距离Swiper组件顶部的距离。<br/>-&nbsp;right:&nbsp;设置导航点距离Swiper组件右边的距离。<br/>-&nbsp;bottom:&nbsp;设置导航点距离Swiper组件底部的距离。<br/>-&nbsp;size:&nbsp;设置导航点的直径。<br/>-&nbsp;mask:&nbsp;设置是否显示导航点蒙层样式。<br/>-&nbsp;color:&nbsp;设置导航点的颜色。<br/>-&nbsp;selectedColor:&nbsp;设置选中的导航点的颜色。 |
## SwiperDisplayMode枚举说明

| 名称 | 描述 |
| ----------- | ------------------------------------------ |
| Stretch     | Swiper滑动一页的宽度为Swiper组件自身的宽度。|
| AutoLinear  | Swiper滑动一页的宽度为子组件宽度中的最大值。|

## EdgeEffect枚举说明

| 名称   | 描述                                                                      |
| ------ | ------------------------------------------------------------------------- |
| Spring | 弹性物理动效，滑动到边缘后可以通过触摸事件继续滑动一段距离，松手后回弹。    |
| Fade   | 滑动到边缘后，可以通过触摸事件继续滑动一段阴影，松手后阴影回弹。            |
| None   | 滑动到边缘后无效果。                                                      |

## SwiperController

Swiper容器组件的控制器，可以将此对象绑定至Swiper组件，然后通过它控制翻页。

### showNext

showNext(): void

翻至下一页。

### showPrevious

showPrevious(): void

翻至上一页。

### finishAnimation

finishAnimation(callback?: () => void): void

停止播放动画。

**参数：**

| 参数名    | 参数类型   | 必填项 | 参数描述 |
| --------- | ---------- | ------ | -------- |
| callback  | () => void | 是     | 动画结束的回调。 |

## 事件

### onChange

onChange(event:&nbsp;(index:&nbsp;number)&nbsp;=&gt;&nbsp;void)

当前显示的组件索引变化时触发该事件。

**参数：**

| 参数名    | 参数类型   | 必填项 | 参数描述 |
| --------- | ---------- | ------ | -------- |
| index     | number     | 是     | 当前显示元素的索引。 |


## 示例

```ts
// xxx.ets
class MyDataSource implements IDataSource {
  private list: number[] = []
  private listener: DataChangeListener

  constructor(list: number[]) {
    this.list = list
  }

  totalCount(): number {
    return this.list.length
  }

  getData(index: number): any {
    return this.list[index]
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    this.listener = listener
  }

  unregisterDataChangeListener() {
  }
}

@Entry
@Component
struct SwiperExample {
  private swiperController: SwiperController = new SwiperController()
  private data: MyDataSource = new MyDataSource([])

  aboutToAppear(): void {
    let list = []
    for (var i = 1; i <= 10; i++) {
      list.push(i.toString());
    }
    this.data = new MyDataSource(list)
  }

  build() {
    Column({ space: 5 }) {
      Swiper(this.swiperController) {
        LazyForEach(this.data, (item: string) => {
          Text(item).width('90%').height(160).backgroundColor(0xAFEEEE).textAlign(TextAlign.Center).fontSize(20)
        }, item => item)
      }
      .cachedCount(2)
      .index(1)
      .autoPlay(true)
      .interval(4000)
      .indicator(true) // 默认开启指示点
      .loop(false) // 默认开启循环播放
      .duration(1000)
      .vertical(false) // 默认横向切换
      .itemSpace(0)
      .curve(Curve.Linear) // 动画曲线
      .onChange((index: number) => {
        console.info(index.toString())
      })

      Flex({ justifyContent: FlexAlign.SpaceAround }) {
        Button('next')
          .onClick(() => {
            this.swiperController.showNext()
          })
        Button('preview')
          .onClick(() => {
            this.swiperController.showPrevious()
          })
      }
    }.margin({ top: 5 })
  }
}
```

![zh-cn_image_0000001224621917](figures/zh-cn_image_0000001224621917.gif)
