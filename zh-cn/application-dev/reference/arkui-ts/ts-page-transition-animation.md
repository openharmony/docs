# 页面间转场

当路由进行切换时，可以通过 在pageTransition函数中自定义页面入场和页面退场的转场动效。

> **说明：**
>
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>


| 名称                | 参数                                                         | 必填 | 参数描述                                                     |
| ------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| PageTransitionEnter | {<br/>type?: RouteType,<br/>duration?: number,<br/>curve?: [Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;string,<br>delay?: number<br/>} | 否   | 设置当前页面的自定义入场动效。<br/>-&nbsp;type：页面转场效果生效的路由类型。<br/>默认值：RouteType.None。<br/>-&nbsp;duration：动画的时长。<br/>单位：毫秒<br/>默认值：1000<br/>-&nbsp;curve：动画曲线。string类型的取值支持"ease"、"ease-in"、"ease-out"、"ease-in-out"、"extreme-deceleration"、"fast-out-linear-in"、"fast-out-slow-in"、"friction"、"linear"、"linear-out-slow-in"、"rhythm"、"sharp"、"smooth"。<br/>默认值：Curve.Linear<br/>-&nbsp;delay：动画延迟时长。<br/>单位：毫秒<br/>默认值：0<br/>**说明：** <br/>没有匹配时使用系统默认的页面转场效果(根据设备可能会有差异)，如需禁用系统默认页面转场效果，可以指定duration为0。 |
| PageTransitionExit  | {<br/>type?: RouteType,<br/>duration?: number,<br/>curve?: [Curve](ts-appendix-enums.md#curve)&nbsp;\|&nbsp;string,<br/>delay?: number<br/>} | 否   | 设置当前页面的自定义退场动效。<br/>-&nbsp;type：页面转场效果生效的路由类型。<br/>默认值：RouteType.None。<br/>-&nbsp;duration：动画的时长。<br/>单位：毫秒<br/>默认值：1000<br/>-&nbsp;curve：动画曲线，string类型取值与PageTransitionEnter相同。<br/>&nbsp;默认值：Curve.Linear<br/>-&nbsp;delay：动画延迟时长。<br/>单位：毫秒<br/>默认值：0<br/>**说明：** <br/>没有匹配时使用系统默认的页面转场效果(根据设备可能会有差异)，如需禁用系统默认页面转场效果，可以指定duration为0。 |

## RouteType枚举说明

| 名称 | 描述                                                         |
| ---- | ------------------------------------------------------------ |
| Pop  | 重定向指定页面。从PageB回退到之前的页面PageA。对于PageB，指定RouteType为None或者Pop的PageTransitionExit组件样式生效，对于PageA，指定RouteType为None或者Pop的PageTransitionEnter组件样式生效。 |
| Push | 跳转到下一页面。PageA跳转到下一个新的界面PageB。对于PageA，指定RouteType为None或者Push的PageTransitionExit组件样式生效，对于PageB，指定RouteType为None或者Push的PageTransitionEnter组件样式生效。 |
| None | 页面未重定向。如Push和Pop描述中RouteType为None的情形，即页面进场时PageTransitionEnter的转场效果生效；退场时PageTransitionExit的转场效果生效。 |


## 属性

| 参数名称  | 参数类型                                                     | 必填 | 参数描述                                                     |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slide     | [SlideEffect](#slideeffect枚举说明)                          | 否   | 设置页面转场时的滑入滑出效果。 |
| translate | {<br/>x?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>y?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>z?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 否   | 设置页面转场时的平移效果，为入场时起点和退场时终点的值，和slide同时设置时默认生效slide。<br/>-&nbsp;x：横向的平移距离。<br/>-&nbsp;y：纵向的平移距离。<br/>-&nbsp;z：竖向的平移距离。 |
| scale     | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number,<br/>centerX?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string,<br/>centerY?&nbsp;:&nbsp;number&nbsp;\|&nbsp;string<br/>} | 否   | 设置页面转场时的缩放效果，为入场时起点和退场时终点的值。<br/>-&nbsp;x：横向放大倍数（或缩小比例）。<br/>-&nbsp;y：纵向放大倍数（或缩小比例）。<br/>-&nbsp;z：竖向放大倍数（或缩小比例）。<br/>-&nbsp;centerX、centerY缩放中心点。centerX和centerY默认值是"50%"，即默认以页面的中心点为旋转中心点。<br/>-&nbsp;中心点为(0, 0)代表页面的左上角。<br/> |
| opacity   | number                                                       | 否   | 设置入场的起点透明度值或者退场的终点透明度值。 |

## SlideEffect枚举说明

| 名称     | 描述                        |
| ------ | ------------------------- |
| Left   | 设置到入场时表示从左边滑入，出场时表示滑出到左边。 |
| Right  | 设置到入场时表示从右边滑入，出场时表示滑出到右边。 |
| Top    | 设置到入场时表示从上边滑入，出场时表示滑出到上边。 |
| Bottom | 设置到入场时表示从下边滑入，出场时表示滑出到下边。 |


## 事件

| 事件                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onEnter(event: (type?:&nbsp;RouteType,&nbsp;progress?:&nbsp;number)&nbsp;=&gt;&nbsp;void) | 回调入参为当前入场动画的归一化进度[0&nbsp;-&nbsp;1]。<br/>-&nbsp;type：跳转方法。<br/>-&nbsp;progress：当前进度。<br/>触发该事件的条件：<br/>逐帧回调，直到入场动画结束，progress从0变化到1。 |
| onExit(event: (type?:&nbsp;RouteType,&nbsp;progress?:&nbsp;number)&nbsp;=&gt;&nbsp;void) | 回调入参为当前退场动画的归一化进度[0&nbsp;-&nbsp;1]。<br/>-&nbsp;type：跳转方法。<br/>-&nbsp;progress：当前进度。<br/>触发该事件的条件：<br/>逐帧回调，直到退场动画结束，progress从0变化到1。 |


## 示例

自定义方式1：配置了当前页面的入场动画为淡入，退场动画为缩小。

```ts
// index.ets
@Entry
@Component
struct PageTransitionExample1 {
  @State scale1: number = 1
  @State opacity1: number = 1

  build() {
    Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width('100%').height('100%')    // 图片存放在media文件夹下
      }
    }.scale({ x: this.scale1 }).opacity(this.opacity1)
  }
  // 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale1 = 1
        this.opacity1 = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1200, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale1 = 1 - progress
        this.opacity1 = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

```ts
// page1.ets
@Entry
@Component
struct AExample {
  @State scale2: number = 1
  @State opacity2: number = 1

  build() {
    Column() {
      Navigator({ target: 'pages/index', type: NavigationType.Push }) {
        Image($r('app.media.bg2')).width('100%').height('100%')   // 图片存放在media文件夹下
      }
    }.width('100%').height('100%').scale({ x: this.scale2 }).opacity(this.opacity2)
  }
  // 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale2 = 1
        this.opacity2 = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1200, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale2 = 1 - progress
        this.opacity2 = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

![pageTransition1](figures/pageTransition1.gif)

自定义方式2：配置了当前页面的入场动画为从左侧滑入，退场为平移加透明度变化。

```ts
// index.ets 
@Entry
@Component
struct PageTransitionExample {
  build() {
    Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width('100%').height('100%')   // 图片存放在media文件夹下
      }
    }
  }

  // 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    // 该页面进入动画时长为1200ms，尽量与另一页面的退出动画时长匹配
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    // 该页面退出动画时长为1000ms，尽量与另一页面的进入动画时长匹配
    PageTransitionExit({ duration: 1000 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

```ts
// page1.ets
@Entry
@Component
struct PageTransitionExample1 {
  build() {
    Column() {
      Navigator({ target: 'pages/index', type: NavigationType.Push }) {
        Image($r('app.media.bg2')).width('100%').height('100%')    // 图片存放在media文件夹下
      }
    }
  }

  // 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    // 该页面进入动画时长为1000ms，尽量与另一页面的退出动画时长匹配
    PageTransitionEnter({ duration: 1000 })
      .slide(SlideEffect.Left)
    // 该页面退出动画时长为1200ms，尽量与另一页面的进入动画时长匹配
    PageTransitionExit({ duration: 1200 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

![pageTransition2](figures/pageTransition2.gif)
