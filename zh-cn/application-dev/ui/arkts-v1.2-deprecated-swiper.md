# Swiper

以下接口在ArkTS1.1中已标记为废弃，并在ArkTS1.2中不再支持。

## SwiperAttribute

### indicatorStyle
ArkTS1.1接口声明：[indicatorStyle(value?: IndicatorStyle): SwiperAttribute](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated)

替代的ArkTS1.2接口声明：[indicator(value: DotIndicator | DigitIndicator | boolean): SwiperAttribute](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicator)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle()
```

ArkTS1.2

<!--code_no_check-->
```ts
 Swiper().indicator(true)
```

## IndicatorStyle

### IndicatorStyle
ArkTS1.1接口声明：[declare interface IndicatorStyle](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[declare class DotIndicator extends Indicator<DotIndicator>](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
let a: IndicatorStyle = {color: "#FFFF00FF"}
```

ArkTS1.2

<!--code_no_check-->
```ts
let a: DotIndicator = new DotIndicator().color("#FFFF00FF")
```


### color
ArkTS1.1接口声明：[IndicatorStyle.color?: ResourceColor](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[color(value: ResourceColor): DotIndicator](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({color: "#FFFF00FF"})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().color("#FFFF00FF"))
```


### right
ArkTS1.1接口声明：[IndicatorStyle.right?: Length](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[right(value: Length): T](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({right: 0})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().right(0))
```


### left
ArkTS1.1接口声明：[IndicatorStyle.left?: Length](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[left(value: Length): T](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({left: 0})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().left(0))
```


### top
ArkTS1.1接口声明：[IndicatorStyle.top?: Length](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[top(value: Length): T](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({top: 0})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().top(0))
```


### bottom
ArkTS1.1接口声明：[IndicatorStyle.bottom?: Length](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[bottom(value: Length): T](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({bottom: 0})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().bottom(0))
```


### selectedColor
ArkTS1.1接口声明：[IndicatorStyle.selectedColor?: ResourceColor](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[selectedColor(value: ResourceColor): DotIndicator](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({selectedColor: "#FFFF00FF"})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().selectedColor("#FFFF00FF"))
```


### mask
ArkTS1.1接口声明：[IndicatorStyle.mask?: boolean](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[mask(value: boolean): DotIndicator](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({mask: true})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().mask(true))
```


### size
ArkTS1.1接口声明：[IndicatorStyle.size?: Length](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#indicatorstyledeprecated对象说明)

替代的ArkTS1.2接口声明：[itemWidth(value: Length): DotIndicator](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#dotindicator10)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().indicatorStyle({size: 100})
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().indicator(new DotIndicator().itemWidth(100).itemHeight(100).selectedItemWidth(100).selectedItemHeight(100))
```


## SwiperDisplayMode

### Stretch
ArkTS1.1接口声明：[SwiperDisplayMode.Stretch](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#swiperdisplaymode枚举说明)

替代的ArkTS1.2接口声明：[SwiperDisplayMode.STRETCH](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#swiperdisplaymode枚举说明)

适配方法如下：

ArkTS1.1

<!--code_no_check-->
```ts
Swiper().displayMode(SwiperDisplayMode.Stretch)
```

ArkTS1.2

<!--code_no_check-->
```ts
Swiper().displayMode(SwiperDisplayMode.STRETCH)
```


### AutoLinear
ArkTS1.1接口声明：[SwiperDisplayMode.AutoLinear](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#swiperdisplaymode枚举说明)

替代的ArkTS1.2接口声明：[scrollTo(options: ScrollOptions)](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scrollto)


适配方案详见[示例1](###示例1)。


### AUTO_LINEAR
ArkTS1.1接口声明：[SwiperDisplayMode.AUTO_LINEAR](../reference/apis-arkui/arkui-ts/ts-container-swiper.md#swiperdisplaymode枚举说明)

替代的ArkTS1.2接口声明：[scrollTo(options: ScrollOptions)](../reference/apis-arkui/arkui-ts/ts-container-scroll.md#scrollto)

适配方案详见[示例1](###示例1)。


## 示例

### 示例1

ArkTS1.1

<!--code_no_check-->
```ts
@Entry
@Component
struct SwiperExample {
  private data: number[] = [1, 2, 3, 4, 5, 6, 7, 8]
  private swiperController: SwiperController = new SwiperController()

  build() {
    Column() {
      Swiper(this.swiperController) {
        ForEach(this.data, (item: number) => {
          Column() {
            Text(item.toString())
              .width('100%')
              .height('100%')
              .textAlign(TextAlign.Center)
          }
          .width(90)
          .height(160)
          .backgroundColor(0xAFEEEE)
        })
      }
      .displayMode(SwiperDisplayMode.AUTO_LINEAR)
      //.displayMode(SwiperDisplayMode.AutoLinear)
      .itemSpace(20)
      .curve(Curve.Linear)
      .duration(1000)
      .loop(false)
      .indicator(false)
      .onChange((index: number) => {
        console.info(index.toString())
      })
      Row({ space: 12 }) {
        Button('showNext')
          .onClick(() => {
            this.swiperController.showNext();
          })
        Button('showPrevious')
          .onClick(() => {
            this.swiperController.showPrevious();
          })
      }.margin(5)
    }.width('100%')
  }
}
```

ArkTS1.2

<!--code_no_check-->
```ts
@Entry
@Component
struct ScrollExample {
  private data: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8];
  private scroller: Scroller = new Scroller();

  build() {
    Column() {
      Scroll(this.scroller) {
        Row() {
          ForEach(this.data, (item: number) => {
            Column() {
              Text(item.toString())
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
            }
            .width(90)
            .height(160)
            .backgroundColor(0xAFEEEE)
            .margin({ right: item === this.data[this.data.length - 1] ? 0 : 20 })
          })
        }.height(160)
      }
      .scrollable(ScrollDirection.Horizontal)
      .scrollBar(BarState.Off)
      .edgeEffect(EdgeEffect.Spring)
      Row({ space: 12 }) {
        Button('showNext')
          .onClick(() => {
            const xOffset: number = this.scroller.currentOffset().xOffset;
            this.scroller.scrollTo({ xOffset: xOffset + 90 + 20, yOffset: 0, animation: { duration: 1000, curve: Curve.Linear } });
          })
        Button('showPrevious')
          .onClick(() => {
            const xOffset: number = this.scroller.currentOffset().xOffset;
            this.scroller.scrollTo({ xOffset: xOffset - 90 - 20, yOffset: 0, animation: { duration: 1000, curve: Curve.Linear } });
          })
      }.margin(5)
    }.width('100%')
  }
}
```