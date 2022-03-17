# Swiper


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Swiper&gt;** component provides a container that allows users to switch among child components by swiping operations.


## Required Permissions

None


## Child Components

This component can contain child components.


## APIs

Swiper(value:{controller?: SwiperController})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | controller | [SwiperController](#swipercontroller) | No | null | Controller&nbsp;bound&nbsp;to&nbsp;the&nbsp;component&nbsp;to&nbsp;control&nbsp;the&nbsp;page&nbsp;switching. | 


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| index | number | 0 | Index&nbsp;of&nbsp;the&nbsp;child&nbsp;component&nbsp;currently&nbsp;displayed&nbsp;in&nbsp;the&nbsp;container. |
| autoPlay | boolean | false | Whether&nbsp;to&nbsp;enable&nbsp;automatic&nbsp;playback&nbsp;for&nbsp;child&nbsp;component&nbsp;switching.&nbsp;If&nbsp;this&nbsp;attribute&nbsp;is&nbsp;**true**,&nbsp;the&nbsp;indicator&nbsp;dots&nbsp;do&nbsp;not&nbsp;take&nbsp;effect. |
| interval | number | 3000 | Interval&nbsp;for&nbsp;automatic&nbsp;playback,&nbsp;in&nbsp;ms. |
| indicator | boolean | true | Whether&nbsp;to&nbsp;enable&nbsp;the&nbsp;navigation&nbsp;dots. |
| loop | boolean | true | Whether&nbsp;to&nbsp;enable&nbsp;loop&nbsp;playback. |
| duration | number | 400 | Duration&nbsp;of&nbsp;the&nbsp;animation&nbsp;for&nbsp;switching&nbsp;child&nbsp;components,&nbsp;in&nbsp;ms. |
| vertical | boolean | false | Whether&nbsp;vertical&nbsp;swiping&nbsp;is&nbsp;used. |
| itemSpace | Length | 0 | Space&nbsp;between&nbsp;child&nbsp;components. |
| cachedCount<sup>8+</sup> | number | 1 | Number&nbsp;of&nbsp;child&nbsp;components&nbsp;to&nbsp;be&nbsp;cached. |
| disableSwipe<sup>8+</sup> | boolean | false | Whether&nbsp;to&nbsp;disable&nbsp;the&nbsp;swipe&nbsp;feature. |
| curve<sup>8+</sup> | [Curve](ts-animatorproperty.md)&nbsp;\|&nbsp;Curves | Curve.Ease | Animation&nbsp;curve.&nbsp;The&nbsp;ease-in/ease-out&nbsp;curve&nbsp;is&nbsp;used&nbsp;by&nbsp;default.&nbsp;For&nbsp;details&nbsp;about&nbsp;common&nbsp;curves,&nbsp;see&nbsp;[Curve&nbsp;enums](ts-animatorproperty.md).&nbsp;You&nbsp;can&nbsp;also&nbsp;create&nbsp;custom&nbsp;curves&nbsp;([interpolation&nbsp;curve&nbsp;objects](ts-interpolation-calculation.md))&nbsp;by&nbsp;using&nbsp;the&nbsp;API&nbsp;provided&nbsp;by&nbsp;the&nbsp;interpolation&nbsp;calculation&nbsp;module. |


### SwiperController

Controller of the **&lt;Swiper&gt;** component. You can bind this object to the **&lt;Swiper&gt;** component and use it to control page switching.

  | Name | Description | 
| -------- | -------- |
| showNext():void | Turns&nbsp;to&nbsp;the&nbsp;next&nbsp;page. | 
| showPrevious():void | Turns&nbsp;to&nbsp;the&nbsp;previous&nbsp;page. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onChange(&nbsp;index:&nbsp;number)&nbsp;=&gt;&nbsp;void | Triggered&nbsp;when&nbsp;the&nbsp;index&nbsp;of&nbsp;the&nbsp;currently&nbsp;displayed&nbsp;component&nbsp;changes. | 


## Example


```
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
      .indicator(true) // Navigation dots are enabled by default.
      .loop(false) // Loop playback is enabled by default.
      .duration(1000)
      .vertical(false) // Horizontal swiping is enabled by default.
      .itemSpace(0)
      .curve(Curve.Linear) // Animation curve
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
