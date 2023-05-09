# Page Transition Animation


During page redirection, one page disappears and the other page appears. In this case, you can configure the page transition parameters of each page to customize the page transition effect. [Page transition](../reference/arkui-ts/ts-page-transition-animation.md) effect is written in the **pageTransition** API. PageTransitionEnter and PageTransitionExit are used to specify the animation effect of page entry and exit.


PageTransitionEnter's interface is:



```ts
PageTransitionEnter({type?: RouteType,duration?: number,curve?: Curve | string,delay?: number})
```


The interface of PageTransitionExit is:



```ts
PageTransitionExit({type?: RouteType,duration?: number,curve?: Curve | string,delay?: number})
```


Defines the PageTransitionEnter and PageTransitionExit components. The slide, translate, scale, and opacity attributes can be used to define different page transition effects. For PageTransitionEnter, these effects indicate the start value during entry. For PageTransitionExit, these effects indicate the end value during exit. This method is similar to that for configuring component transition. In addition, PageTransitionEnter provides the onEnter interface to call back the entry animation of a customized page, and PageTransitionExit provides the onExit interface to call back the exit animation of a customized page.


The type parameter in the preceding interface indicates the type of the route that takes effect, which may be confused by developers. One of the two pages must exit and the other must enter. If you switch from page A to page B through the router.pushUrl operation, page A exits and the exit animation is displayed. Page B enters and the entry animation is displayed. If the router.back operation is performed to return from page B to page A, page B exits and the exit animation is displayed. Page A enters and the entry animation is displayed. That is, PageTransitionEnter of a page may be an entry animation of a new page caused by a new page (push, stack), or an entry animation of an old page in a page stack caused by a page return (back, pop, stack). To distinguish the two types of entry animations, the type parameter is provided so that developers can define all types of page transition effects.


## Set type to RouteType.None.

If the value of type is RouteType.None, the push and pop operations on the page stack are valid. The default value of type is RouteType.None.


```ts
// page A
pageTransition() {
  // Define the effect when the page is displayed. The page slides in from the left for 1200 ms. The effect takes effect no matter whether the push or pop operation is performed on the page stack.
  PageTransitionEnter({ type: RouteType.None, duration: 1200 })
    .slide(SlideEffect.Left)
  // Define the effect when the page exits. The page slides out to the left for 1000 ms. The effect takes effect no matter whether the push or pop operation is performed on the page stack.
  PageTransitionExit({ type: RouteType.None, duration: 1000 })
    .slide(SlideEffect.Left)
}
```



```ts
// page B
pageTransition() {
  // Define the effect when the page is displayed. The page slides in from the right for 1000 ms. The effect takes effect no matter whether the push or pop operation is performed on the page stack.
  PageTransitionEnter({ type: RouteType.None, duration: 1000 })
    .slide(SlideEffect.Right)
  // Define the effect when the page exits. The page slides out to the right for 1200 ms. The effect takes effect no matter whether the push or pop operation is performed on the page stack.
  PageTransitionExit({ type: RouteType.None, duration: 1200 })
    .slide(SlideEffect.Right)
}
```


Assume that the page stack is in the standard instance mode, that is, duplicate pages are allowed in the page stack. There may be four scenarios. The following table lists the page transition effects.


| Route operations                        | Transition effect of page A                           | Transition effect of page B                           |
| ---------------------------- | ---------------------------------- | ---------------------------------- |
| router.pushUrl. The new page B is displayed from page A.| Exit the page. The PageTransitionExit takes effect and slides to the left to display the screen. | The page is displayed. PageTransitionEnter takes effect and slides from the right to the screen.|
| router.back: Return from page B to page A.      | The page is displayed, PageTransitionEnter takes effect, and you can slide from the left to the screen.| Exit the page. The PageTransitionExit takes effect and slides out of the screen to the right. |
| router.pushUrl. The new page A is displayed from page B.| The page is displayed, PageTransitionEnter takes effect, and you can slide from the left to the screen.| Exit the page. The PageTransitionExit takes effect and slides out of the screen to the right. |
| router.back: Return from page A to page B.      | Exit the page. The PageTransitionExit takes effect and slides to the left to display the screen. | The page is displayed. PageTransitionEnter takes effect and slides from the right to the screen.|


If you want the page accessed by pushUrl to always slide in from the right and the page exited by back to always slide out from the right, the third and fourth cases in the preceding table do not meet the requirements. In this case, you need to define the transition effects of the four pages.


## Set type to RouteType.Push or RouteType.Pop.

If type is set to RouteType.Push, this parameter is valid only for the push operation of the page stack. If type is set to RouteType.Pop, this parameter is valid only for the pop operation of the page stack.


```ts
// page A
pageTransition() {
  // Define the effect when the page is entered. The page slides in from the right for 1200 ms. The effect takes effect only when the push operation is performed on the page stack.
  PageTransitionEnter({ type: RouteType.Push, duration: 1200 })
    .slide(SlideEffect.Right)
  // Define the effect when the page is entered. The page slides in from the left for 1200 ms. The effect takes effect only when the pop operation is performed on the page stack.
  PageTransitionEnter({ type: RouteType.Pop, duration: 1200 })
    .slide(SlideEffect.Left)
  // Define the effect when the page exits. The page slides out to the left for 1000 ms. The effect takes effect only when the push operation is performed on the page stack.
  PageTransitionExit({ type: RouteType.Push, duration: 1000 })
    .slide(SlideEffect.Left)
  // Define the effect when the page exits. The page slides out to the right for 1000 ms. The effect takes effect only when the pop operation is performed on the page stack.
  PageTransitionExit({ type: RouteType.Pop, duration: 1000 })
    .slide(SlideEffect.Right)
}
```



```ts
// page B
pageTransition() {
  // Define the effect when the page is entered. The page slides in from the right for 1000 ms. The effect takes effect only when the push operation is performed on the page stack.
  PageTransitionEnter({ type: RouteType.Push, duration: 1000 })
    .slide(SlideEffect.Right)
  //Define the effect when the page is entered. The page slides in from the left for 1000 ms. The effect takes effect only when the pop operation is performed on the page stack.
  PageTransitionEnter({ type: RouteType.Pop, duration: 1000 })
    .slide(SlideEffect.Left)
  // Define the effect when the page exits. The page slides out to the left for 1200 ms. The effect takes effect only when the push operation is performed on the page stack.
  PageTransitionExit({ type: RouteType.Push, duration: 1200 })
    .slide(SlideEffect.Left)
  // Define the effect when the page exits. The page slides out to the right for 1200 ms. The effect takes effect only when the pop operation is performed on the page stack.
  PageTransitionExit({ type: RouteType.Pop, duration: 1200 })
    .slide(SlideEffect.Right)
}
```


The preceding code completely defines all possible page transition styles. Assume that the page stack is in the standard instance mode, that is, duplicate pages are allowed in the page stack. There may be four scenarios. The following table lists the page transition effects.


| Route operations                        | Transition effect of page A                                 | Transition effect of page B                                 |
| ---------------------------- | ---------------------------------------- | ---------------------------------------- |
| router.pushUrl. The new page B is displayed from page A.| The page exits. The transition style of PageTransitionExit whose type is RouteType.Push takes effect. The screen slides out to the left.| The page is displayed. The transition style of PageTransitionEnter whose type is RouteType.Push takes effect. The page slides from the right to the screen.|
| router.back: Return from page B to page A.      | The page is displayed. The transition style of PageTransitionEnter whose type is RouteType.Pop takes effect. Slide from the left to the screen.| The page exits. The transition style of PageTransitionExit whose type is RouteType.Pop takes effect. The screen slides out to the right.|
| router.pushUrl. The new page A is displayed from page B.| The page is displayed. The transition style of PageTransitionEnter whose type is RouteType.Push takes effect. The page slides from the right to the screen.| The page exits. The transition style of PageTransitionExit whose type is RouteType.Push takes effect. The screen slides out to the left.|
| router.back: Return from page A to page B.      | The page exits. The transition style of PageTransitionExit whose type is RouteType.Pop takes effect. The screen slides out to the right.| The page is displayed. The transition style of PageTransitionEnter whose type is RouteType.Pop takes effect. Slide from the left to the screen.|


>**NOTE**
>
>    1. The transition style of each page can be independently configured by developers. However, the transition involves two pages. Developers need to consider the transition effect of the two pages, for example, the transition duration.
>
>    2. If no matching page transition style is defined, the page uses the default page transition style.


## Disable the transition of a page.


```ts
pageTransition() {
  PageTransitionEnter({ type: RouteType.None, duration: 0 })
  PageTransitionExit({ type: RouteType.None, duration: 0 })
}
```


You can set the page transition duration to 0 so that no page transition animation is displayed on the page.


## Example Scenario

The following describes an example of a page transition animation that defines all four page transition styles.



```ts
// page A
import router from '@ohos.router';
@Entry
@Component
struct PageTransitionSrc1 {
  build() {
    Column() {
      Image($r('app.media.mountain'))
        .width('90%')
        .height('80%')
        .objectFit(ImageFit.Fill)
        .syncLoad(true) //Load the image synchronously so that the image has been loaded when the page is displayed.
        .margin(30)

      Row({ space: 10 }) {
        Button("pushUrl")
          .onClick(() => {
            //Route to the next page and perform the push operation.
            router.pushUrl({ url: 'pages/myTest/pageTransitionDst1' });
          })
        Button("back")
          .onClick(() => {
            //Return to the previous page, which is equivalent to the pop operation.
            router.back();
          })
      }.justifyContent(FlexAlign.Center)
    }
    .width("100%").height("100%")
    .alignItems(HorizontalAlign.Center)
  }

  pageTransition() {
    //Define the effect when the page is entered. The page slides in from the right for 1000 ms. The effect takes effect only when the push operation is performed on the page stack.
    PageTransitionEnter({ type: RouteType.Push, duration: 1000 })
      .slide(SlideEffect.Right)
    //Define the effect when the page is entered. The page slides in from the left for 1000 ms. The effect takes effect only when the pop operation is performed on the page stack.
    PageTransitionEnter({ type: RouteType.Pop, duration: 1000 })
      .slide(SlideEffect.Left)
    //Define the effect when the page exits. The page slides out to the left for 1000 ms. The effect takes effect only when the push operation is performed on the page stack.
    PageTransitionExit({ type: RouteType.Push, duration: 1000 })
      .slide(SlideEffect.Left)
    //Define the effect when the page exits. The page slides out to the right for 1000 ms. The effect takes effect only when the pop operation is performed on the page stack.
    PageTransitionExit({ type: RouteType.Pop, duration: 1000 })
      .slide(SlideEffect.Right)
  }
}
```




```ts
// page B
import router from '@ohos.router';
@Entry
@Component
struct PageTransitionDst1 {
  build() {
    Column() {
      Image($r('app.media.forest'))
        .width('90%')
        .height('80%')
        .objectFit(ImageFit.Fill)
        .syncLoad(true) //Load the image synchronously so that the image has been loaded when the page is displayed.
        .margin(30)

      Row({ space: 10 }) {
        Button("pushUrl")
          .onClick(() => {
            //Route to the next page and perform the push operation.
            router.pushUrl({ url: 'pages/myTest/pageTransitionSrc1' });
          })
        Button("back")
          .onClick(() => {
            //Return to the previous page, which is equivalent to the pop operation.
            router.back();
          })
      }.justifyContent(FlexAlign.Center)
    }
    .width("100%").height("100%")
    .alignItems(HorizontalAlign.Center)
  }

  pageTransition() {
    //Define the effect when the page is entered. The page slides in from the right for 1000 ms. The effect takes effect only when the push operation is performed on the page stack.
    PageTransitionEnter({ type: RouteType.Push, duration: 1000 })
      .slide(SlideEffect.Right)
    //Define the effect when the page is entered. The page slides in from the left for 1000 ms. The effect takes effect only when the pop operation is performed on the page stack.
    PageTransitionEnter({ type: RouteType.Pop, duration: 1000 })
      .slide(SlideEffect.Left)
    //Define the effect when the page exits. The page slides out to the left for 1000 ms. The effect takes effect only when the push operation is performed on the page stack.
    PageTransitionExit({ type: RouteType.Push, duration: 1000 })
      .slide(SlideEffect.Left)
    //Define the effect when the page exits. The page slides out to the right for 1000 ms. The effect takes effect only when the pop operation is performed on the page stack.
    PageTransitionExit({ type: RouteType.Pop, duration: 1000 })
      .slide(SlideEffect.Right)
  }
}
```



![pageTransition_PushPop](figures/pageTransition_PushPop.gif)


The following describes an example of the page transition animation whose type is None.



```ts
// page A
import router from '@ohos.router';
@Entry
@Component
struct PageTransitionSrc2 {
  build() {
    Column() {
      Image($r('app.media.mountain'))
        .width('90%')
        .height('80%')
        .objectFit(ImageFit.Fill)
        .syncLoad(true) //Load the image synchronously so that the image has been loaded when the page is displayed.
        .margin(30)

      Row({ space: 10 }) {
        Button("pushUrl")
          .onClick(() => {
            //Route to the next page and perform the push operation.
            router.pushUrl({ url: 'pages/myTest/pageTransitionDst2' });
          })
        Button("back")
          .onClick(() => {
            //Return to the previous page, which is equivalent to the pop operation.
            router.back();
          })
      }.justifyContent(FlexAlign.Center)
    }
    .width("100%").height("100%")
    .alignItems(HorizontalAlign.Center)
  }

  pageTransition() {
    //Define the effect when the page is displayed. The page slides in from the left for 1000 ms. The effect takes effect no matter whether the push or pop operation is performed on the page stack.
    PageTransitionEnter({ duration: 1000 })
      .slide(SlideEffect.Left)
    //Define the effect when the page exits. Compared with the normal page position, the page position is shifted by 100 vp in the x direction and 100 vp in the y direction. The transparency changes to 0. The duration is 1200 ms. The effect takes effect regardless of whether the push or pop operation is performed on the page stack.
    PageTransitionExit({ duration: 1200 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```



```ts
// page B
import router from '@ohos.router';
@Entry
@Component
struct PageTransitionDst2 {
  build() {
    Column() {
      Image($r('app.media.forest'))
        .width('90%')
        .height('80%')
        .objectFit(ImageFit.Fill)
        .syncLoad(true) //Load the image synchronously so that the image has been loaded when the page is displayed.
        .margin(30)

      Row({ space: 10 }) {
        Button("pushUrl")
          .onClick(() => {
            //Route to the next page and perform the push operation.
            router.pushUrl({ url: 'pages/myTest/pageTransitionSrc2' });
          })
        Button("back")
          .onClick(() => {
            //Return to the previous page, which is equivalent to the pop operation.
            router.back();
          })
      }.justifyContent(FlexAlign.Center)
    }
    .width("100%").height("100%")
    .alignItems(HorizontalAlign.Center)
  }

  pageTransition() {
    //Define the effect when the page is displayed. The page slides in from the left for 1200 ms. The effect takes effect no matter whether the push or pop operation is performed on the page stack.
    PageTransitionEnter({ duration: 1200 })
      .slide(SlideEffect.Left)
    //Define the effect when the page exits. Compared with the normal page position, the page position is shifted by 100 vp in the x direction and 100 vp in the y direction. The transparency changes to 0. The duration is 1000 ms. The effect takes effect regardless of whether the push or pop operation is performed on the page stack.
    PageTransitionExit({ duration: 1000 })
      .translate({ x: 100.0, y: 100.0 })
      .opacity(0)
  }
}
```



![pageTransition_None](figures/pageTransition_None.gif)
