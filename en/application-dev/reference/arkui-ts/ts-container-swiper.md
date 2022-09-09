# Swiper


The **\<Swiper>** component provides a container that allows users to switch among child components using swipe gestures.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Swiper(value:{controller?: SwiperController})

**Parameters**

| Name       | Type                          | Mandatory | Description                |
| ---------- | ------------------------------------- | ---- | -------------------- |
| controller | [SwiperController](#swipercontroller) | No  | Controller bound to the component to control the page switching.<br>Default value: **null** |


## Attributes

[Menu control](ts-universal-attributes-menu.md) is not supported.

| Name                         | Type                              | Description                                      |
| --------------------------- | ---------------------------------------- | ---------------------------------------- |
| index                       | number                                   | Index of the child component currently displayed in the container.<br>Default value: **0**                    |
| autoPlay                    | boolean                                  | Whether to enable automatic playback for child component switching. If this attribute is **true**, the navigation dots indicator does not take effect.<br>Default value: **false**   |
| interval                    | number                                   | Interval for automatic playback, in ms.<br>Default value: **3000**                   |
| indicator                   | boolean                                  | Whether to enable the navigation dots indicator.<br>Default value: **true**                             |
| loop                        | boolean                                  | Whether to enable loop playback.<br>The value **true** means to enable loop playback. When LazyForEach is used, it is recommended that the number of the components to load exceed 5.<br>Default value: **true**|
| duration                    | number                                   | Duration of the animation for switching child components, in ms.<br>Default value: **400**                       |
| vertical                    | boolean                                  | Whether vertical swiping is used.<br>Default value: **false**                                |
| itemSpace                   | Length                                   | Space between child components.<br>Default value: **0**                          |
| displayMode                 | SwiperDisplayMode                        | Mode in which elements are displayed along the main axis. This attribute takes effect only when **displayCount** is not set.<br>Default value: **SwiperDisplayMode.Stretch**|
| cachedCount<sup>8+</sup>    | number                                   | Number of child components to be cached.<br>Default value: **1**                             |
| disableSwipe<sup>8+</sup>   | boolean                                  | Whether to disable the swipe feature.<br>Default value: **false**                             |
| curve<sup>8+</sup>          | [Curve](ts-appendix-enums.md#curve) \| string | Animation curve. The ease-in/ease-out curve is used by default. For details about common curves, see [Curve](ts-appendix-enums.md#curve). You can also create custom curves ([interpolation curve objects](ts-interpolation-calculation.md)) by using the API provided by the interpolation calculation module.<br>Default value: **Curve.Ease** |
| indicatorStyle<sup>8+</sup> | {<br/>left?:&nbsp;Length,<br/>top?:&nbsp;Length,<br/>right?:&nbsp;Length,<br/>bottom?:&nbsp;Length,<br/>size?:&nbsp;Length,<br/>mask?:&nbsp;boolean,<br/>color?:&nbsp;[ResourceColor](../../ui/ts-types.md),<br/>selectedColor?:&nbsp;[ResourceColor](../../ui/ts-types.md)<br/>} | Style of the navigation dots indicator.<br>- **left**: distance between the navigation dots indicator and the left edge of the **\<Swiper>** component.<br>- **top**: distance between the navigation dots indicator and the top edge of the **\<Swiper>** component.<br>- **right**: distance between the navigation dots indicator and the right edge of the **\<Swiper>** component.<br>- **bottom**: distance between the navigation dots indicator and the bottom edge of the **\<Swiper>** component.<br>- **size**: diameter of the navigation dots indicator.<br>- **color**: color of the navigation dots indicator.<br>- **selectedColor**: color of the selected navigation dot.|
| displayCount<sup>8+</sup>   | number\|string                                               | Number of elements to display.<br>Default value: **1**                                          |
| effectMode<sup>8+</sup>     | [EdgeEffect](ts-appendix-enums.md#edgeeffect)                               | Swipe effect. For details, see **EdgeEffect**.<br>Default value: **EdgeEffect.Spring**|

## SwiperDisplayMode

| Name| Description|
| ----------- | ------------------------------------------ |
| Stretch     | The slide width of the **\<Swiper>** component is equal to the width of the component.|
| AutoLinear  | The slide width of the **\<Swiper>** component is equal to the maximum width of the child components.|

## EdgeEffect

| Name  | Description                                                                     |
| ------ | ------------------------------------------------------------------------- |
| Spring | Spring effect. When at one of the edges, the component can move beyond the bounds through touches, and produce a bounce effect when the user releases their finger.   |
| Fade   | Fade effect. When at one of the edges, the component can move beyond the bounds through touches, and produce a fade effect along the way; when the user releases their finger, the fade changes.           |
| None   | No effect. When at one of the edges, the component cannot move beyond the bounds.                                                     |

## SwiperController

Controller of the **\<Swiper>** component. You can bind this object to the **<Swiper>** component and use it to control page switching.

### showNext

showNext(): void

Turns to the next page.

### showPrevious

showPrevious(): void

Turns to the previous page.

### finishAnimation

finishAnimation(callback?: () => void): void

Stops this animation.

**Parameters**

| Name   | Type  | Mandatory.| Description|
| --------- | ---------- | ------ | -------- |
| callback  | () => void | Yes    | Callback invoked when the animation stops.|

## Events

### onChange

onChange(event: (index: number) => void)

Triggered when the index of the currently displayed component changes.

**Parameters**

| Name   | Type  | Mandatory.| Description|
| --------- | ---------- | ------ | -------- |
| index     | number     | Yes    | Index of the currently displayed element.|


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
          Text(item).width('90%').height(160).backgroundColor(0xAFEEEE).textAlign(TextAlign.Center).fontSize(20)
        }, item => item)
      }
      .cachedCount(2)
      .index(1)
      .autoPlay(true)
      .interval(4000)
      .indicator(true) // Navigation dots are enabled by default.
      .loop(false) // Loop playback is enabled by default.
      .duration(1000)
      .vertical(false) // Horizontal swiping is enabled by default.
      .itemSpace(0)
      .curve(Curve.Linear) // Animation curve.
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

![en-us_image_0000001211898474](figures/en-us_image_0000001211898474.gif)
