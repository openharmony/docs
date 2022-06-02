# 页面间转场

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


页面转场通过在全局pageTransition方法内配置页面入场组件和页面退场组件来自定义页面转场动效。


| 名称                  | 参数     | 参数描述                            |
| ------------------- | ------ | ------------------------------- |
| PageTransitionEnter | Object | 页面入场组件，用于自定义当前页面的入场效果，详见动效参数说明。 |
| PageTransitionExit  | Object | 页面退场组件，用于自定义当前页面的退场效果，详见动效参数说明。 |


- 动效参数说明
  | 参数名称     | 参数类型                      | 默认值    | 必填   | 参数描述                                     |
  | -------- | ------------------------- | ------ | ---- | ---------------------------------------- |
  | type     | RouteType                 | -      | 否    | 不配置时表明pop为push时效果的逆播。                    |
  | duration | number                    | 1000   | 否    | 动画时长，单位为毫秒。                              |
  | curve    | Curve&nbsp;\|&nbsp;Curves | Linear | 否    | 动画曲线，有效值参见[Curve](ts-animatorproperty.md)&nbsp;说明。 |
  | delay    | number                    | 0      | 否    | 动画延迟时长，单位为毫秒，默认不延时播放。                    |


- RouteType枚举说明
  | 名称   | 描述                                       |
  | ---- | ---------------------------------------- |
  | Pop  | PageA跳转到PageB时，PageA为Exit+Push，PageB为Enter+Push。 |
  | Push | PageB返回至PageA时，PageA为Enter+Pop，PageB为Exit+Pop。 |


## 属性

PageTransitionEnter和PageTransitionExit组件支持的属性：

| 参数名称      | 参数类型                                     | 默认值               | 必填   | 参数描述                                     |
| --------- | ---------------------------------------- | ----------------- | ---- | ---------------------------------------- |
| slide     | SlideEffect                              | SlideEffect.Right | 否    | 设置转场的滑入效果，有效值参见SlideEffect枚举说明。          |
| translate | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number<br/>} | -                 | 否    | 设置页面转场时的平移效果，为入场时起点和退场时终点的值，和slide同时设置时默认生效slide。 |
| scale     | {<br/>x?&nbsp;:&nbsp;number,<br/>y?&nbsp;:&nbsp;number,<br/>z?&nbsp;:&nbsp;number,<br/>centerX?&nbsp;:&nbsp;number,<br/>centerY?&nbsp;:&nbsp;number<br/>} | -                 | 否    | 设置页面转场时的缩放效果，为入场时起点和退场时终点的值。             |
| opacity   | number                                   | 1                 | 否    | 设置入场的起点透明度值或者退场的终点透明度值。                  |

- SlideEffect枚举说明
  | 名称     | 描述                        |
  | ------ | ------------------------- |
  | Left   | 设置到入场时表示从左边滑入，出场时表示滑出到左边。 |
  | Right  | 设置到入场时表示从右边滑入，出场时表示滑出到右边。 |
  | Top    | 设置到入场时表示从上边滑入，出场时表示滑出到上边。 |
  | Bottom | 设置到入场时表示从下边滑入，出场时表示滑出到下边。 |


## 事件

PageTransitionEnter和PageTransitionExit组件支持的事件：

| 事件                                       | 功能描述                                |
| ---------------------------------------- | ----------------------------------- |
| onEnter(type:&nbsp;RouteType,&nbsp;progress:&nbsp;number)&nbsp;=&gt;&nbsp;void | 回调入参为当前入场动画的归一化进度[0&nbsp;-&nbsp;1]。 |
| onExit(type:&nbsp;RouteType,&nbsp;progress:&nbsp;number)&nbsp;=&gt;&nbsp;void | 回调入参为当前退场动画的归一化进度[0&nbsp;-&nbsp;1]。 |


## 示例

自定义方式1：配置了当前页面的入场动画为淡入，退场动画为缩小。

```ts
// index.ets
@Entry
@Component
struct PageTransitionExample1 {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false
  build() {
  Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }
// 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

```ts
// page1.ets
@Entry
@Component
struct AExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false
  build() {
    Column() {
      Navigator({ target: 'pages/index' ,type: NavigationType.Push}) {
        Image($r('app.media.bg2')).width("100%").height("100%")
      }
    }.height("100%").width("100%").scale({ x: this.scale }).opacity(this.opacity)
  }
// 自定义方式1：完全自定义转场过程的效果
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // 进场过程中会逐帧触发onEnter回调，入参为动效的归一化进度(0% -- 100%)
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // 退场过程中会逐帧触发onExit回调，入参为动效的归一化进度(0% -- 100%)
  }
}
```

![zh-cn_image_0000001174422902](figures/zh-cn_image_0000001174422902.gif)

自定义方式2：配置了当前页面的入场动画为从左侧滑入，退场为缩小加透明度变化。

```ts
// index.ets 
@Entry
@Component
struct PageTransitionExample {
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }

// 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
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
  @State scale: number = 1
  @State opacity: number = 1
  @State active: boolean = false

  build() {
    Column() {
      Navigator({ target: 'pages/index', type: NavigationType.Push }) {
        Image($r('app.media.bg2')).width  ("100%").height("100%")
      }
      .onClick(() => {
        this.active = true
      })
    }.scale({ x: this.scale }).opacity(this.opacity)
  }

// 自定义方式2：使用系统提供的多种默认效果(平移、缩放、透明度等)
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

![zh-cn_image_0000001219864139](figures/zh-cn_image_0000001219864139.gif)
