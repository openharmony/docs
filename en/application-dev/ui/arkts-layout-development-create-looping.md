# Creating a Swiper (Swiper)


The \<[Swiper](../reference/arkui-ts/ts-container-swiper.md)> component is a container that is able to display child components in looping mode. It is typically used in scenarios such as display of recommended content on the home page.


## Layout and Constraints

The size of the **\<Swiper>** component follows its own size settings (if configured) or adapts based on the size of its child components.


## Loop Playback

The **loop** attribute sets whether to enable loop playback. Its default value is **true**.

When **loop** is set to **true**, the user can switch to the previous or next page when they are on the first or last page.  

  Example of setting **loop** to **true**:

```ts
...
private swiperController: SwiperController = new SwiperController()
...
Swiper(this.swiperController) {
  Text("0")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Gray)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("1")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Green)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("2")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Blue)
    .textAlign(TextAlign.Center)
    .fontSize(30)
}
.loop(true)
```

![loop_true](figures/loop_true.gif)

  Example of setting **loop** to **false**:

```ts
Swiper(this.swiperController) {
  Text("0")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Gray)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("1")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Green)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("2")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Blue)
    .textAlign(TextAlign.Center)
    .fontSize(30)
}
.loop(false)
```

![loop_false](figures/loop_false.gif)


## Automatic Playback

The **autoPlay** attribute sets whether to enable automatic playback for child component switching. Its default value is **false**.

When **autoPlay** is set to **true**, automatic playback is enabled for child component switching. The playback interval is specified by the **interval** attribute, which is **3000** by default, in milliseconds.

  Example of setting **autoPlay** to **true**:

```ts
Swiper(this.swiperController) {
  Text("0")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Gray)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("1")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Green)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("2")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Pink)
    .textAlign(TextAlign.Center)
    .fontSize(30)
}
.loop(true)
.autoPlay(true)
.interval(1000)
```

![autoPlay](figures/autoPlay.gif)


## Navigation Dots Indicator

The **\<Swiper>** component provides a navigation dots indicator, which is displayed in the bottom center of the component. You can customize the position and style of the navigation dots indicator through the **indicatorStyle **attribute.

With the **indicatorStyle** attribute, you can set the position of the navigation dots indicator relative to the edges of the **\<Swiper>** component, in addition to the size, color, and mask of each navigation dot as well as the color of the selected navigation dot.

  Example of using the navigation dots indicator in its default style:

```ts
Swiper(this.swiperController) {
  Text("0")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Gray)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("1")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Green)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("2")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Pink)
    .textAlign(TextAlign.Center)
    .fontSize(30)
}
```

![indicator](figures/indicator.PNG)

  Example of customizing the style of the navigation dots indicator, with the diameter of 30 vp, left margin of 0, and color of red:

```ts
Swiper(this.swiperController) {
  Text("0")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Gray)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("1")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Green)
    .textAlign(TextAlign.Center)
    .fontSize(30)

  Text("2")
    .width('90%')
    .height('100%')
    .backgroundColor(Color.Pink)
    .textAlign(TextAlign.Center)
    .fontSize(30)
}
.indicatorStyle({
  size: 30,
  left: 0,
  color: Color.Red
})
```

![ind](figures/ind.PNG)


## Page Switching Mode

The **\<Swiper>** component supports three page switching modes: using the swipe gesture, using the navigation dots indicator, and using the controller.

  Switch pages through the controller:

```ts
@Entry
@Component
struct SwiperDemo {
  private swiperController: SwiperController = new SwiperController();

  build() {
    Column({ space: 5 }) {
      Swiper(this.swiperController) {
        Text("0")
          .width(250)
          .height(250)
          .backgroundColor(Color.Gray)
          .textAlign(TextAlign.Center)
          .fontSize(30)
        Text("1")
          .width(250)
          .height(250)
          .backgroundColor(Color.Green)
          .textAlign(TextAlign.Center)
          .fontSize(30)
        Text("2")
          .width(250)
          .height(250)
          .backgroundColor(Color.Pink)
          .textAlign(TextAlign.Center)
          .fontSize(30)
      }
      .indicator(true)

      Row({ space: 12 }) {
        Button('showNext')
          .onClick(() => {
            this.swiperController.showNext(); // Switch to the next page through the controller.
          })
        Button('showPrevious')
          .onClick(() => {
            this.swiperController.showPrevious(); // Switch to the previous page through the controller.
          })
      }.margin(5)
    }.width('100%')
    .margin({ top: 5 })
  }
}
```

![controll](figures/controll.gif)


## Playback Direction

You can set the playback direction for the \<Swiper> component through its **vertical** attribute.

When **vertical** is set to **true**, vertical swiping is used. The default value of **vertical** is **false**.


  Example of using horizontal swiping:

```ts
Swiper(this.swiperController) {
  ...
}
.indicator(true)
.vertical(false)
```


![horizontal-swiping](figures/horizontal-swiping.PNG)


  Example of using vertical swiping:

```ts
Swiper(this.swiperController) {
  ...
}
.indicator(true)
.vertical(true)
```


![vertical-swiping](figures/vertical-swiping.PNG)


## Child Components Per Page

You can set the number of child components per page for the **\<Swiper>** component through its [displayCount](../reference/arkui-ts/ts-container-swiper.md#attributes) attribute.

  To display two child components per page:

```ts
Swiper(this.swiperController) {
  Text("0")
    .width(250)
    .height(250)
    .backgroundColor(Color.Gray)
    .textAlign(TextAlign.Center)
    .fontSize(30)
  Text("1")
    .width(250)
    .height(250)
    .backgroundColor(Color.Green)
    .textAlign(TextAlign.Center)
    .fontSize(30)
  Text("2")
    .width(250)
    .height(250)
    .backgroundColor(Color.Pink)
    .textAlign(TextAlign.Center)
    .fontSize(30)
  Text("3")
    .width(250)
    .height(250)
    .backgroundColor(Color.Blue)
    .textAlign(TextAlign.Center)
    .fontSize(30)
}
.indicator(true)
.displayCount(2)
```

![two](figures/two.PNG)
