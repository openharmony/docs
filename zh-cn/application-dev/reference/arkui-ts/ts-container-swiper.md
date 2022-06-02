# Swiper

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


滑动容器，提供切换子组件显示的能力。


## 权限列表

无


## 子组件

可以包含子组件。


## 接口

Swiper(value:{controller?: SwiperController})

- 参数
  | 参数名        | 参数类型                                  | 必填   | 默认值  | 参数描述                 |
  | ---------- | ------------------------------------- | ---- | ---- | -------------------- |
  | controller | [SwiperController](#swipercontroller) | 否    | null | 给组件绑定一个控制器，用来控制组件翻页。 |


## 属性

| 名称                          | 参数类型                                     | 默认值        | 描述                                       |
| --------------------------- | ---------------------------------------- | ---------- | ---------------------------------------- |
| index                       | number                                   | 0          | 设置当前在容器中显示的子组件的索引值。                      |
| autoPlay                    | boolean                                  | false      | 子组件是否自动播放，自动播放状态下，导航点不可操作。               |
| interval                    | number                                   | 3000       | 使用自动播放时播放的时间间隔，单位为毫秒。                    |
| indicator                   | boolean                                  | true       | 是否启用导航点指示器。                              |
| loop                        | boolean                                  | true       | 是否开启循环。                                  |
| duration                    | number                                   | 400        | 子组件切换的动画时长，单位为毫秒。                        |
| vertical                    | boolean                                  | false      | 是否为纵向滑动。                                 |
| itemSpace                   | Length                                   | 0          | 设置子组件与子组件之间间隙。                           |
| cachedCount<sup>8+</sup>    | number                                   | 1          | 设置预加载子组件个数。                              |
| disableSwipe<sup>8+</sup>   | boolean                                  | false      | 禁用组件滑动切换功能。                              |
| curve<sup>8+</sup>          | [Curve](ts-animatorproperty.md#Curve枚举说明) \| Curves | Curve.Ease | 设置Swiper的动画曲线，默认为淡入淡出曲线，常用曲线参考[Curve枚举说明](ts-animatorproperty.md#Curve枚举说明)，也可以通过插值计算模块提供的接口创建自定义的Curves([插值曲线对象](ts-interpolation-calculation.md))。 |
| indicatorStyle<sup>8+</sup> | {<br/>left?:&nbsp;Length,<br/>top?:&nbsp;Length,<br/>right?:&nbsp;Length,<br/>bottom?:&nbsp;Length,<br/>size?:&nbsp;Length,<br/>color?:&nbsp;Color,<br/>selectedColor?:&nbsp;Color<br/>} | -          | 设置indicator样式：<br/>-&nbsp;left:&nbsp;设置导航点距离Swiper组件左边的距离。<br/>-&nbsp;top:&nbsp;设置导航点距离Swiper组件顶部的距离。<br/>-&nbsp;right:&nbsp;设置导航点距离Swiper组件右边的距离。<br/>-&nbsp;bottom:&nbsp;设置导航点距离Swiper组件底部的距离。<br/>-&nbsp;size:&nbsp;设置导航点的直径。<br/>-&nbsp;color:&nbsp;设置导航点的颜色。<br/>-&nbsp;selectedColor:&nbsp;设置选中的导航点的颜色。 |


### SwiperController

Swiper容器组件的控制器，可以将此对象绑定至Swiper组件，然后通过它控制翻页。

| 接口名称                | 功能描述   |
| ------------------- | ------ |
| showNext():void     | 翻至下一页。 |
| showPrevious():void | 翻至上一页。 |


## 事件

| 名称                                       | 功能描述               |
| ---------------------------------------- | ------------------ |
| onChange(&nbsp;index:&nbsp;number)&nbsp;=&gt;&nbsp;void | 当前显示的组件索引变化时触发该事件。 |


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

  private aboutToAppear(): void {
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
