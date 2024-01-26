# Web组件嵌套滚动

Web组件嵌套滚动的典型应用场景为，在一个页面中，有多个独立的区域需要进行滚动，当用户滚动Web区域内容时，可带动其他滚动区域进行滚动，以达到上下滑动页面的用户体验。
内嵌在可滚动容器（Scroll、List...）中的Web组件，接收到滑动手势事件，需要对接ArkUI框架的[NestedScrollMode](../reference/arkui-ts/ts-basic-components-web.md#nestedscrollmode11枚举说明)枚举类型，使得Web组件可以嵌套ArkUI可滚动容器，进行嵌套滚动。开发者可以在Web组件创建时，使用[nestedScroll](../reference/arkui-ts/ts-basic-components-web.md#nestedscroll11)属性接口指定默认的嵌套滚动模式，也允许在过程中动态改变嵌套滚动的模式。

nestedScroll入参为一个[NestedScrollOptions](../reference/arkui-ts/ts-basic-components-web.md#nestedscrolloptions11对象说明)对象，该对象具有两个属性，分别为scrollForward和scrollBackward，每一个属性都为一个[NestedScrollMode](../reference/arkui-ts/ts-basic-components-web.md#nestedscrollmode11枚举说明)枚举类型。

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct NestedScroll {
  private scrollerForScroll: Scroller = new Scroller()
  controller: web_webview.WebviewController = new web_webview.WebviewController();
  controller2: web_webview.WebviewController = new web_webview.WebviewController();
  // NestedScrollMode设置成SELF_ONLY时，Web网页滚动到页面边缘后，不与父组件联动，父组件仍无法滚动。
  @State NestedScrollMode0:NestedScrollMode=NestedScrollMode.SELF_ONLY
  // NestedScrollMode设置成SELF_FIRST时，Web网页滚动到页面边缘后，父组件继续滚动。
  @State NestedScrollMode1:NestedScrollMode=NestedScrollMode.SELF_FIRST
  // NestedScrollMode设置为PARENT_FIRST时，父组件先滚动，滚动至边缘后通知Web继续滚动。
  @State NestedScrollMode2:NestedScrollMode=NestedScrollMode.PARENT_FIRST
  // NestedScrollMode设置为PARALLEL时，父组件与Web同时滚动。
  @State NestedScrollMode3:NestedScrollMode=NestedScrollMode.PARALLEL
  @State NestedScrollModeF:NestedScrollMode=NestedScrollMode.SELF_FIRST
  @State NestedScrollModeB:NestedScrollMode=NestedScrollMode.SELF_FIRST
  // scroll竖向的滚动
  @State ScrollDirection:ScrollDirection=ScrollDirection.Vertical

  build() {
    Flex() {
      Scroll(this.scrollerForScroll) {
        Column({space:5}) {
          Row({}){
            Text('切换前滚动模式').fontSize(5)
            Button('SELF_ONLY').onClick((event: ClickEvent) => {
              this.NestedScrollModeF=this.NestedScrollMode0
            }).fontSize(5)
            Button('SELF_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeF=this.NestedScrollMode1
            }).fontSize(5)
            Button('PARENT_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeF=this.NestedScrollMode2
            }).fontSize(5)
            Button('PARALLEL').onClick((event: ClickEvent) => {
              this.NestedScrollModeF=this.NestedScrollMode3
            }).fontSize(5)
          }
          Row({}){
            Text('切换后滚动模式').fontSize(5)
            Button('SELF_ONLY').onClick((event: ClickEvent) => {
              this.NestedScrollModeB=this.NestedScrollMode0
            }).fontSize(5)
            Button('SELF_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeB=this.NestedScrollMode1
            }).fontSize(5)
            Button('PARENT_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeB=this.NestedScrollMode2
            }).fontSize(5)
            Button('PARALLEL').onClick((event: ClickEvent) => {
              this.NestedScrollModeB=this.NestedScrollMode3
            }).fontSize(5)
          }
          Text('当前内嵌前滚动模式 scrollForward ---'+`${this.NestedScrollModeF}`).fontSize(10)
          Text('当前内嵌后滚动模式  scrollBackward ---'+`${this.NestedScrollModeB}`).fontSize(10)

          Text("Scroll Area")
            .width("100%")
            .height("10%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)
          Text("Scroll Area")
            .width("100%")
            .height("10%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)
          Text("Scroll Area")
            .width("100%")
            .height("10%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)

          Web({ src: "www.example.com", controller: this.controller})
              .nestedScroll({
                scrollForward: this.NestedScrollModeF,
                scrollBackward: this.NestedScrollModeB,
              })
              .height("40%")
              .width("100%")

          Text("Scroll Area")
            .width("100%")
            .height("20%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)

          Text("Scroll Area")
            .width("100%")
            .height("20%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)

          Web({ src: "www.example.com", controller: this.controller2})
            .nestedScroll({
              scrollForward: this.NestedScrollModeF,
              scrollBackward: this.NestedScrollModeB,
            })
            .height("40%")
            .width("90%")

          Text("Scroll Area")
            .width("100%")
            .height("20%")
            .backgroundColor(0X330000FF)
            .fontSize(16)
            .textAlign(TextAlign.Center)

        }.width("95%").border({width:5})
      }
      .width("100%").height("120%").border({width:5}).scrollable(this.ScrollDirection)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding(20)
  }
}
```

![web-nested-scrolling](figures/web-nested-scrolling.gif)
