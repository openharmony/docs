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

| Name                         | Type                              | Default Value                         | Description                                      |
| --------------------------- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
| index                       | number                                   | 0                   | Index of the child component currently displayed in the container.                    |
| autoPlay                    | boolean                                  | false | Whether to enable automatic playback for child component switching. If this attribute is **true**, the navigation dots indicator does not take effect.   |
| interval                    | number                                   | 3000               | Interval for automatic playback, in ms.                   |
| indicator                   | boolean                                  | true                         | Whether to enable the navigation dots indicator.                             |
| loop                        | boolean                                  | true | Whether to enable loop playback.<br>The value **true** means to enable loop playback. When LazyForEach is used, it is recommended that the number of the components to load exceed 5. |
| duration                    | number                                   | 400                    | Duration of the animation for switching child components, in ms.                       |
| vertical                    | boolean                                  | false                           | Whether vertical swiping is used.                                |
| itemSpace                   | number \| string                                   | 0                         | Space between child components.                          |
| displayMode                 | SwiperDisplayMode                        | SwiperDisplayMode.Stretch | Mode in which elements are displayed along the main axis. This attribute takes effect only when **displayCount** is not set. |
| cachedCount<sup>8+</sup>    | number                                   | 1                            | Number of child components to be cached.                             |
| disableSwipe<sup>8+</sup>   | boolean                                  | false                        | Whether to disable the swipe feature.                             |
| displayCount<sup>8+</sup>   | number \| string | 1 | Number of elements to display. |
| effectMode<sup>8+</sup>     | EdgeEffect | EdgeEffect.Spring | Swipe effect. For details, see **EdgeEffect**. |
| curve<sup>8+</sup>          | [Curve](ts-appendix-enums.md#curve) \| string | Curve.Ease | Animation curve. The ease-in/ease-out curve is used by default. For details about common curves, see [Curve](ts-appendix-enums.md#curve). You can also create custom curves ([interpolation curve objects](ts-interpolation-calculation.md)) by using the API provided by the interpolation calculation module. |
| indicatorStyle<sup>8+</sup> | {<br/>left?: [Length](ts-types.md#length),<br/>top?: [Length](ts-types.md#length),<br/>right?: [Length](ts-types.md#length),<br/>bottom?: [Length](ts-types.md#length),<br/>size?: [Length](ts-types.md#length),<br/>mask?: boolean,<br/>color?: [ResourceColor](ts-types.md#resourcecolor8),<br/>selectedColor?: [ResourceColor](ts-types.md#resourcecolor8)<br/>} | - | Style of the navigation dots indicator.<br>- **left**: distance between the navigation dots indicator and the left edge of the **\<Swiper>** component.<br>- **top**: distance between the navigation dots indicator and the top edge of the **\<Swiper>** component.<br>- **right**: distance between the navigation dots indicator and the right edge of the **\<Swiper>** component.<br>- **bottom**: distance between the navigation dots indicator and the bottom edge of the **\<Swiper>** component.<br>- **size**: diameter of the navigation dots indicator.<br>- **color**: color of the navigation dots indicator.<br>- **selectedColor**: color of the selected navigation dot.|

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

onChange( index: number) =&gt; void

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
