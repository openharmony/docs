# Swiper

 The **\<Swiper>** component is able to display child components in looping mode.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

This component can contain child components.

>  **NOTE**
>
>  Built-in components and custom components are allowed, with support for ([if/else](../../quick-start/arkts-rendering-control-ifelse.md), [ForEach](../../quick-start/arkts-rendering-control-foreach.md), and [LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md)) rendering control.
>
>  When the **\<Swiper>** component's **displayMode** attribute is set to **SwiperDisplayMode.AutoLinear** or its **displayCount** attribute is set to **'auto'**, the child component whose **visibility** attribute is set to **None** does not take up space in the viewport, but this does not affect the number of navigation dots.
>
>  If the **visibility** attribute of a child component is set to **None** or **Hidden**, it takes up space in the viewport, but is not displayed.


## APIs

Swiper(controller?: SwiperController)

**Parameters**

| Name       | Type                          | Mandatory | Description                |
| ---------- | ------------------------------------- | ---- | -------------------- |
| controller | [SwiperController](#swipercontroller) | No  | Controller bound to the component to control the page switching.|


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported. [Menu control](ts-universal-attributes-menu.md) is not supported.

| Name                         | Type                              | Description                                      |
| --------------------------- | ---------------------------------------- | ---------------------------------------- |
| index                       | number                                   | Index of the child component currently displayed in the container.<br>Default value: **0**<br>**NOTE**<br>If the value is less than 0 or greater than or equal to the number of child components, the default value **0** is used.|
| autoPlay                    | boolean                                  | Whether to enable automatic playback for child component switching.<br>Default value: **false**<br>**NOTE**<br>If **loop** is set to **false**, the playback stops when the last page is displayed. The playback continues when the page is not the last page after a swipe gesture.|
| interval                    | number                                   | Interval for automatic playback, in ms.<br>Default value: **3000**                   |
| indicator                   | boolean                                  | Whether to enable the navigation dots indicator.<br>Default value: **true**                             |
| loop                        | boolean                                  | Whether to enable loop playback.<br>The value **true** means to enable loop playback. When LazyForEach is used, it is recommended that the number of the components to load exceed 5.<br>Default value: **true**|
| duration                    | number                                   | Duration of the animation for switching child components, in ms.<br>Default value: **400**                       |
| vertical                    | boolean                                  | Whether vertical swiping is used.<br>Default value: **false**                                |
| itemSpace                   | number \| string          | Space between child components.<br>Default value: **0**<br>**NOTE**<br>This parameter cannot be set in percentage.|
| displayMode                 | SwiperDisplayMode                        | Mode in which elements are displayed along the main axis. This attribute takes effect only when **displayCount** is not set.<br>Default value: **SwiperDisplayMode.Stretch**|
| cachedCount<sup>8+</sup>              | number                                   | Number of child components to be cached.<br>Default value: **1**<br>**NOTE**<br>This attribute applies only when the **\<Swiper>** component uses [LazyForEach](../../quick-start/arkts-rendering-control-lazyforeach.md).|
| disableSwipe<sup>8+</sup>   | boolean                                  | Whether to disable the swipe feature.<br>Default value: **false**                             |
| curve<sup>8+</sup>          | [Curve](ts-appendix-enums.md#curve)  \| string | Animation curve. The ease-in/ease-out curve is used by default. For details about common curves, see [Curve](ts-appendix-enums.md#curve). You can also create custom curves (interpolation curve objects) by using the API provided by the [interpolation calculation](../apis/js-apis-curve.md) module.<br>Default value: **Curve.Linear**|
| indicatorStyle<sup>8+</sup> | {<br>left?: [Length](ts-types.md#length),<br>top?: [Length](ts-types.md#length),<br>right?: [Length](ts-types.md#length),<br>bottom?: [Length](ts-types.md#length),<br>size?: [Length](ts-types.md#length),<br>mask?: boolean,<br>color?: [ResourceColor](ts-types.md),<br>selectedColor?: [ResourceColor](ts-types.md)<br>} | Style of the navigation point indicator.<br>\- **left**: distance between the navigation point indicator and the left edge of the **\<Swiper>** component.<br>\- **top**: distance between the navigation point indicator and the top edge of the **\<Swiper>** component.<br>\- **right**: distance between the navigation point indicator and the right edge of the **\<Swiper>** component.<br>\- **bottom**: distance between the navigation point indicator and the bottom edge of the **\<Swiper>** component.<br>\- **size**: diameter of the navigation point indicator. The value cannot be in percentage. Default value: **6vp**<br>\- **mask**: whether to enable the mask for the navigation point indicator.<br>\- **color**: color of the navigation point indicator.<br>\- **selectedColor**: color of the selected navigation dot.|
| displayCount<sup>8+</sup>   | number \| string | Number of elements to display per page.<br>Default value: **1**<br>**NOTE**<br>If the value is of the string type, it can only be **'auto'**, whose display effect is the same as that of **SwiperDisplayMode.AutoLinear**.<br>If the value is set to a number less than or equal to 0, the default value **1** is used.<br>If the value is of the number type, child components stretch (shrink) on the main axis after the swiper width [deducting the result of itemSpace x (displayCount - 1)] is evenly distributed among them on the main axis.|
| effectMode<sup>8+</sup>     | [EdgeEffect](ts-appendix-enums.md#edgeeffect)  | Swipe effect. For details, see **EdgeEffect**.<br>Default value: **EdgeEffect.Spring**<br>**NOTE**<br>The spring effect does not take effect when the controller API is called.|

## SwiperDisplayMode

| Name| Description|
| ----------- | ------------------------------------------ |
| Stretch     | The slide width of the **\<Swiper>** component is equal to the width of the component.|
| AutoLinear  | The slide width of the **\<Swiper>** component is equal to that of the child component with the maximum width.|

## SwiperController

Controller of the **\<Swiper>** component. You can bind this object to the **\<Swiper>** component and use it to control page switching.

### showNext

showNext(): void

Turns to the next page. Page turning occurs with the animation, whose duration is specified by **duration**.

### showPrevious

showPrevious(): void

Turns to the previous page. Page turning occurs with the animation, whose duration is specified by **duration**.

### finishAnimation

finishAnimation(callback?: () => void): void

Stops an animation.

**Parameters**

| Name   | Type  | Mandatory.| Description|
| --------- | ---------- | ------ | -------- |
| callback  | () => void | No    | Callback invoked when the animation stops.|


## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

| Name                                                        | Description                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onChange(event: (index: number) => void)                     | Triggered when the index of the currently displayed child component changes.<br>- **index**: index of the currently displayed element.<br>**NOTE**<br>When the **\<Swiper>** component is used together with **LazyForEach**, the subpage UI update cannot be triggered in the **onChange** event.|
| onAnimationStart<sup>9+</sup>(event: (index: number) => void) | Triggered when the switching animation starts.<br>- **index**: index of the currently displayed element.<br>**NOTE**<br>The **index** parameter indicates the index before the animation starts (not the one after). When the **\<Swiper>** component contains multiple columns, the index is of the leftmost element.|
| onAnimationEnd<sup>9+</sup>(event: (index: number) => void)  | Triggered when the switching animation ends.<br>- **index**: index of the currently displayed element.<br>**NOTE**<br>This event is triggered when the animation ends regardless of whether it is due to a user gesture or invocation of **finishAnimation** through **SwiperController**. The **index** parameter indicates the index after the animation ends. When the **\<Swiper>** component contains multiple columns, the index is of the leftmost element.|

## Example

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
          Text(item).width('90%').height(160).backgroundColor(0xAFEEEE).textAlign(TextAlign.Center).fontSize(30)
        }, item => item)
      }
      .cachedCount(2)
      .index(1)
      .autoPlay(true)
      .interval(4000)
      .indicator(true)
      .loop(true)
      .duration(1000)
      .itemSpace(0)
      .curve(Curve.Linear)
      .onChange((index: number) => {
        console.info(index.toString())
      })

      Row({ space: 12 }) {
        Button('showNext')
          .onClick(() => {
            this.swiperController.showNext()
          })
        Button('showPrevious')
          .onClick(() => {
            this.swiperController.showPrevious()
          })
      }.margin(5)
    }.width('100%')
    .margin({ top: 5 })
  }
}
```

![swiper](figures/swiper.gif)
