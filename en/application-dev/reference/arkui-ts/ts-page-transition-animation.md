# Page Transition

You can customize the page entrance and exit animations in the **pageTransition** API for transition between pages.

> **NOTE**
>
> This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>


| Name               | Parameter                                                        | Mandatory| Description                                                    |
| ------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| PageTransitionEnter | {<br>type?: RouteType,<br>duration?: number,<br>curve?: [Curve](ts-appendix-enums.md#curve) \| string,<br>delay?: number<br>} | No  | Page entrance animation.<br>- **type**: route type for the page transition effect to take effect.<br>Default value: **RouteType.None**<br>- **duration**: animation duration.<br>Unit: ms<br>Default value: **1000**<br>- **curve**: animation curve. The value of the string type can be any of the following: "ease", "ease-in", "ease-out", "ease-in-out", "extreme-deceleration", "fast-out-linear-in", "fast-out-slow-in", "friction", "linear", "linear-out-slow-in", "rhythm", "sharp", "smooth".<br>Default value: **Curve.Linear**<br>- **delay**: animation delay.<br>Unit: ms<br>Default value: **0**<br>**NOTE**<br>If no match is found, the default page transition effect is used (which may vary according to the device). To disable the default page transition effect, set **duration** to **0**.|
| PageTransitionExit  | {<br>type?: RouteType,<br>duration?: number,<br>curve?: [Curve](ts-appendix-enums.md#curve) \| string,<br>delay?: number<br>} | No  | Page exit animation.<br>- **type**: route type for the page transition effect to take effect.<br>Default value: **RouteType.None**<br>- **duration**: animation duration.<br>Unit: ms<br>Default value: **1000**<br>- **curve**: animation curve. The value range of the string type is the same as that of **PageTransitionEnter**.<br>Default value: **Curve.Linear**<br>- **delay**: animation delay.<br>Unit: ms<br>Default value: **0**<br>**NOTE**<br>If no match is found, the default page transition effect is used (which may vary according to the device). To disable the default page transition effect, set **duration** to **0**.|

## RouteType

| Name| Description                                                        |
| ---- | ------------------------------------------------------------ |
| Pop  | Redirects to a specified page. To redirect the user from page B back to page A, set **RouteType** of **PageTransitionExit** to **None** or **Pop** for page B and set **RouteType** of **PageTransitionEnter** to **None** or **Pop** for page A.|
| Push | Redirects to the next page. To redirect the user from page A to page B, set **RouteType** of **PageTransitionExit** to **None** or **Push** for page A and set **RouteType** of **PageTransitionEnter** to **None** or **Push** for page B.|
| None | The page is not redirected. The animation specified by **PageTransitionEnter** takes effect for page entrance, and the animation specified by **PageTransitionExit** takes effect for page exit.|


## Attributes

| Name | Type                                                    | Mandatory| Description                                                    |
| --------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| slide     | [SlideEffect](#slideeffect)                          | No  | Slide effect during page transition.|
| translate | {<br>x? : number \| string,<br>y? : number \| string,<br>z? : number \| string<br>} | No  | Translation effect during page transition, which is the value of the start point of entrance and the end point of exit. When this parameter is set together with **slide**, the latter takes effect by default.<br>- **x**: translation distance along the x-axis.<br>- **y**: translation distance along the y-axis.<br>- **z**: translation distance along the y-axis.|
| scale     | {<br>x? : number,<br>y? : number,<br>z? : number,<br>centerX? : number \| string,<br>centerY? : number \| string<br>} | No  | Scaling effect during page transition, which is the value of the start point of entrance and the end point of exit.<br>- **x**: scale ratio along the x-axis.<br>- **y**: scale ratio along the y-axis.<br>- **z**: scale ratio along the z-axis.<br>- **centerX** and **centerY**: scale center point. The default values are both **"50%"**, indicating that the center point of the page.<br>- If the center point is (0, 0), it refers to the upper left corner of the component.<br>|
| opacity   | number                                                       | No  | Opacity, which is the opacity value of the start point of entrance or the end point of exit.|

## SlideEffect

| Name    | Description                       |
| ------ | ------------------------- |
| Left   | When set to Enter, slides in from the left. When set to Exit, slides out to the left.|
| Right  | When set to Enter, slides in from the right. When set to Exit, slides out to the right.|
| Top    | When set to Enter, slides in from the top. When set to Exit, slides out to the top.|
| Bottom | When set to Enter, slides in from the bottom. When set to Exit, slides out to the bottom.|


## Events

| Name                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onEnter(event: (type?: RouteType, progress?: number) =&gt; void) | Invoked once every animation frame until the entrance animation ends, when the value of **progress** changes from 0 to 1. The input parameter is the normalized progress of the current entrance animation. The value range is 0–1.<br>- **type**: route type.<br>- **progress**: current progress.<br> <br> |
| onExit(event: (type?: RouteType, progress?: number) =&gt; void) | Invoked once every animation frame until the exit animation ends, when the value of **progress** changes from 0 to 1. The input parameter is the normalized progress of the current exit animation. The value range is 0–1.<br>- **type**: route type.<br>- **progress**: current progress.<br> <br> |


## Example

Example 1: Apply the entrance animation of fade-in and the exit animation of zoom-out.

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
        Image($r('app.media.bg1')).width('100%').height('100%')    // Store the image in the media folder.
      }
    }.scale({ x: this.scale1 }).opacity(this.opacity1)
  }
  // Customize the transition process.
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale1 = 1
        this.opacity1 = progress
      }) // The onEnter callback is triggered frame by frame during the entrance process. The input parameter is the normalized progress of the animation (0% to 100%).
    PageTransitionExit({ duration: 1200, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale1 = 1 - progress
        this.opacity1 = 1
      }) // The onExit callback is triggered frame by frame during the exit process. The input parameter is the normalized progress of the animation (0% to 100%).
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
        Image($r('app.media.bg2')).width('100%').height('100%')   // Store the image in the media folder.
      }
    }.width('100%').height('100%').scale({ x: this.scale2 }).opacity(this.opacity2)
  }
  // Customize the transition process.
  pageTransition() {
    PageTransitionEnter({ duration: 1200, curve: Curve.Linear })
      .onEnter((type: RouteType, progress: number) => {
        this.scale2 = 1
        this.opacity2 = progress
      }) // The onEnter callback is triggered frame by frame during the entrance process. The input parameter is the normalized progress of the animation (0% to 100%).
    PageTransitionExit({ duration: 1200, curve: Curve.Ease })
      .onExit((type: RouteType, progress: number) => {
        this.scale2 = 1 - progress
        this.opacity2 = 1
      }) // The onExit callback is triggered frame by frame during the exit process. The input parameter is the normalized progress of the animation (0% to 100%).
  }
}
```

![pageTransition1](figures/pageTransition1.gif)

Example 2: Apply the entrance animation of sliding in from the left and the exit animation of translating with opacity change.

```ts
// index.ets 
@Entry
@Component
struct PageTransitionExample {
  build() {
    Column() {
      Navigator({ target: 'pages/page1', type: NavigationType.Push }) {
        Image($r('app.media.bg1')).width('100%').height('100%')   // Store the image in the media folder.
      }
    }
  }

  // Use the default effects provided by the system, such as translation, scaling, and opacity.
  pageTransition() {
    // Set the duration of the entrance animation to 1200 ms, in the purpose of matching the duration of the exit animation of the other page.
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    // Set the duration of the exit animation to 1000 ms, in the purpose of matching the duration of the entrance animation of the other page.
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
        Image($r('app.media.bg2')).width('100%').height('100%')    // Store the image in the media folder.
      }
    }
  }

  // Use the default effects provided by the system, such as translation, scaling, and opacity.
  pageTransition() {
    // Set the duration of the entrance animation to 1000 ms, in the purpose of matching the duration of the exit animation of the other page.
    PageTransitionEnter({ duration: 1000 })
      .slide(SlideEffect.Left)
    // Set the duration of the exit animation to 1200 ms, in the purpose of matching the duration of the entrance animation of the other page.
    PageTransitionExit({ duration: 1200 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```

![pageTransition2](figures/pageTransition2.gif)
