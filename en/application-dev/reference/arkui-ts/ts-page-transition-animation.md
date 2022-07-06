# Page Transition


> **NOTE**<br>
> This animation is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


Customize the page transition animations by configuring the page entrance and exit components in the global **pageTransition** method.

## APIs

| Name | Parameter | Description |
| -------- | -------- | -------- |
| PageTransitionEnter | Object | Page entrance component, which is used to customize the entrance effect of the current page. For details, see animation parameters. |
| PageTransitionExit | Object | Page exit component, which is used to customize the exit effect of the current page. For details, see animation parameters. |


- Animation parameters
  | Name | Type | Default Value | Mandatory | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | type | RouteType | - | No | If this parameter is not set, the reverse playback effect as pop switches to push is used. |
  | duration | number | 1000 | No | Animation duration, in ms. |
  | curve | Curve \| Curves | Linear | No | Animation curve. For details about the valid values, see **Curve enums**. |
  | delay | number | 0 | No | Animation delay, in ms. Delayed animation is disabled by default. |


- RouteType enums
  | Name | Description |
  | -------- | -------- |
  | Pop | When page A jumps to page B, page A is Exit+Push, and page B is Enter+Push. |
  | Push | When page B returns to page A, page A is Enter+Pop, and page B is Exit+Pop. |


## Attributes

The **PageTransitionEnter** and **PageTransitionExit** components support the following attributes:

| Name | Type | Default Value | Mandatory | Description |
| -------- | -------- | -------- | -------- | -------- |
| slide | SlideEffect | SlideEffect.Right | No | Slide effect during page transition. For details about the valid values, see **SlideEffect enums**. |
| translate | {<br/>x? : number,<br/>y? : number,<br/>z? : number<br/>} | - | No | Translation effect during page transition, which is the value of the start point of entrance and the end point of exit. When this parameter is set together with **slide**, the latter takes effect by default. |
| scale | {<br/>x? : number,<br/>y? : number,<br/>z? : number,<br/>centerX? : number,<br/>centerY? : number<br/>} | - | No | Scaling effect during page transition, which is the value of the start point of entrance and the end point of exit. |
| opacity | number | 1 | No | Opacity, which is the opacity value of the start point of entrance or the end point of exit. |

- SlideEffect enums
  | Name | Description |
  | -------- | -------- |
  | Left | When set to Enter, slides in from the left. When set to Exit, slides out to the left. |
  | Right | When set to Enter, slides in from the right. When set to Exit, slides out to the right. |
  | Top | When set to Enter, slides in from the top. When set to Exit, slides out to the top. |
  | Bottom | When set to Enter, slides in from the bottom. When set to Exit, slides out to the bottom. |


## Events

The PageTransitionEnter and PageTransitionExit components support the following events:

| Event | Description |
| -------- | -------- |
| onEnter(type: RouteType, progress: number) =&gt; void | Callback invoked when page entrance occurs. The input parameter is the normalized progress of the current entrance animation. The value range is 0–1. |
| onExit(type: RouteType, progress: number) =&gt; void | Callback invoked when page exit occurs. The input parameter is the normalized progress of the current exit animation. The value range is 0–1. |


## Example

Customization method 1: The entrance animation of the current page is configured as fade-in, and the exit animation is configured as zoom-out.


```
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
// Customization method 1: Customize the transition process.
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // The onEnter callback is triggered frame by frame during the entrance process. The input parameter is the normalized progress of the animation (0% to 100%).
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // The onExit callback is triggered frame by frame during the exit process. The input parameter is the normalized progress of the animation (0% to 100%).
  }
}
```


```
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
// Customization method 1: Customize the transition process.
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale = 1
        this.opacity = progress
      }) // The onEnter callback is triggered frame by frame during the entrance process. The input parameter is the normalized progress of the animation (0% to 100%).
    PageTransitionExit({ duration: 1500, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale = 1 - progress
        this.opacity = 1
      }) // The onExit callback is triggered frame by frame during the exi process. The input parameter is the normalized progress of the animation (0% to 100%).
  }
}
```

![en-us_image_0000001256978335](figures/en-us_image_0000001256978335.gif)

Customization method 2: The entrance animation of the current page is configured to slide in from the left, and the exit animation is configured to zoom out with opacity change.


```
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

// Customization method 2: Use the default effects provided by the system, such as translation, scaling, and opacity.
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```


```
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

// Customization method 2: Use the default effects provided by the system, such as translation, scaling, and opacity.
  pageTransition() {
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    PageTransitionExit({ delay: 100 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

![en-us_image_0000001212058460](figures/en-us_image_0000001212058460.gif)
