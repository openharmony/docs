# Zoom Animation


If the same element (for example, the same image) is used on different pages, you can use the Shared Element Transition (../reference/arkui-ts/ts-transition-animation-shared-elements.md) animation to connect the elements. To highlight the association of the same elements between different pages, you can add shared element transition animations for them. If the sizes of the same element on different pages are obviously different, the view can be zoomed in or out.


The interface for shared element transition is as follows:



```ts
sharedTransition(id: string, options?: sharedTransitionOptions)
```


Based on the type parameter in sharedTransitionOptions, shared element transitions are classified into Exchange shared element transitions and Static shared element transitions.


## Transition of Shared Elements of the Exchange Type

The transition of shared elements of the exchange type requires that components with the same ID configured through the sharedTransition function exist on two pages. These components are called shared elements. This type of shared element transition is applicable to the connection of the same element between two pages, and transits from the position and size of the shared element on the start page to the position and size of the shared element on the target page. If type is not specified, the shared element transition of the Exchange type is used by default, which is the most common shared element transition mode. When the shared element transition of the Exchange type is used, the animation parameters of the shared element transition are determined by the animation parameters in options on the target page.


## Transition of Shared Elements of the Static Type

Static shared element transition is usually used in the scenario where the title gradually appears or is hidden during page switching. Static shared elements only need to exist on one page. Static shared elements with the same ID cannot exist on two pages. When the page (target page) is displayed, the transparency of the sharedTransition component of the Static type is changed from 0 to the transparency set by the component, and the position remains unchanged. When the page (that is, the start page) disappears, an animation in which the transparency gradually changes to 0 is performed, and the position remains unchanged.

The animation parameters of the shared element transition are determined by the animation parameters in the sharedTransition attribute of the component.


## Example Scenario

The following describes an example of using a shared element transition to zoom in or zoom out an image.


```ts
// src page
import router from '@ohos.router';

@Entry
@Component
struct SharedTransitionSrc {
  build() {
    Column() {
      //Configure the transition of the shared element of the Exchange type. The ID of the shared element is sharedImage1.
      Image($r('app.media.mountain')).width(50).height(50)
        .sharedTransition('sharedImage1', { duration: 1000, curve: Curve.Linear })
        .onClick(() => {
          //When a small image is clicked, the route jumps to the next page.
          router.pushUrl({ url: 'pages/myTest/sharedTransitionDst' });
        })
    }
    .padding(10)
    .width("100%")
    .alignItems(HorizontalAlign.Start)
  }
}
```




```ts
// dest page
import router from '@ohos.router';
@Entry
@Component
struct SharedTransitionDest {
  build() {
    Column() {
      //Configure the transition of shared elements of the Static type.
      Text("SharedTransition dest page")
        .fontSize(16)
        .sharedTransition('text', { duration: 500, curve: Curve.Linear, type: SharedTransitionEffectType.Static })
        .margin({ top: 10 })

      //Configure the transition of the shared element of the Exchange type. The ID of the shared element is sharedImage1.
      Image($r('app.media.mountain'))
        .width(150)
        .height(150)
        .sharedTransition('sharedImage1', { duration: 500, curve: Curve.Linear })
        .onClick(() => {
          // Return to the previous page when a user clicks an image.
          router.back();
        })
    }
    .width("100%")
    .alignItems(HorizontalAlign.Center)
  }
}
```


In the preceding example, the shared element transition whose ID is sharedImage1 is configured on both the first page (src page) and the second page (dest page) so that the two pages can match the group of shared elements. When you jump from the first page to the second page, the first page is the start page, and the second page is the target page. Configure the component whose ID is sharedImage1 to perform shared element transition based on the duration of 500 ms on the target page to zoom in the view. Configure the component whose ID is text to perform shared element transition based on the duration of 500 ms in the sharedTransition parameter of the Static type, the headline gradually appears. When you return from the second page to the first page, the second page is the start page, and the first page is the target page. Configure the component whose ID is sharedImage1 to perform shared element transition based on the duration of 1000 ms on the target page and zoom out to the original view. Configure the component whose ID is text to perform shared element transition based on the duration of 500 ms in the sharedTransition parameter of the Static type, the title is gradually hidden.



![sharedTransition](figures/sharedTransition.gif)
