# Implementing Nested Scrolling

There may be times when you want to implement nested scrolling for the **\<Web>** component. A typical use case is a page that contains multiple scrollable areas including the **\<Web>** component, whose scrolling is intrinsically linked with the scroll positions in other areas.
If you opt to embed a **\<Web>** component in a scroll container (such as [\<Scroll>](../reference/apis-arkui/arkui-ts/ts-container-scroll.md) and [\<List>](../reference/apis-arkui/arkui-ts/ts-container-list.md)) for nested scrolling, use the [NestedScrollMode](../reference/apis-arkweb/ts-basic-components-web.md#nestedscrollmode11) enum of the ArkUI framework. You can specify the default nested scrolling mode through [nestedScroll](../reference/apis-arkweb/ts-basic-components-web.md#nestedscroll11) during creation of the **\<Web>** component; this nested scrolling mode allows for dynamic changes.

**nestedScroll** is a [NestedScrollOptions](../reference/apis-arkweb/ts-basic-components-web.md#nestedscrolloptions11) object that has two attributes: **scrollForward** and **scrollBackward**, both of which are [NestedScrollMode](../reference/apis-arkweb/ts-basic-components-web.md#nestedscrollmode11) enum values.

When a **\<Web>** component is nested in multiple scrollable containers, the offset and speed values that are not consumed by the **\<Web>** component are passed to the parent container that is closest to the **\<Web>** component in the same direction so that the parent container can continue to scroll. A swipe gesture can initiate scrolling along either the x-axis or y-axis. If the finger moves between the x-axis and y-axis, the scrolling occurs along the axis where the offset or speed has a larger absolute value. If the absolute values of the offset or speed on the x-axis and y-axis are the same, the scrolling occurs in the direction of the scrollable component closest to the **\<Web>** component.

> **NOTE**
>
> - Containers that support nested scrolling: **\<Grid>**, **\<List>**, **\<Scroll>**, **\<Swiper>**, **\<Tabs>**, and **\<WaterFlow>**.
> - Input sources that support nested scrolling: gestures, mouse device, and touchpad.

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct NestedScroll {
  private scrollerForScroll: Scroller = new Scroller();
  controller: webview.WebviewController = new webview.WebviewController();
  controller2: webview.WebviewController = new webview.WebviewController();
  // With NestedScrollMode set to SELF_ONLY, the parent component does not scroll when the component scrolling reaches the boundary.
  @State NestedScrollMode0: NestedScrollMode = NestedScrollMode.SELF_ONLY;
  // With NestedScrollMode set to SELF_FIRST, the component scrolls first, and when it hits the boundary, the parent component scrolls.
  @State NestedScrollMode1: NestedScrollMode = NestedScrollMode.SELF_FIRST;
  // With NestedScrollMode set to PARENT_FIRST, the parent component scrolls first, and when it hits the boundary, the component scrolls.
  @State NestedScrollMode2: NestedScrollMode = NestedScrollMode.PARENT_FIRST;
  // With NestedScrollMode set to PARALLEL, the component and its parent component scroll at the same time.
  @State NestedScrollMode3: NestedScrollMode = NestedScrollMode.PARALLEL;
  @State NestedScrollModeF: NestedScrollMode = NestedScrollMode.SELF_FIRST;
  @State NestedScrollModeB: NestedScrollMode = NestedScrollMode.SELF_FIRST;
  // Vertical scrolling.
  @State ScrollDirection: ScrollDirection = ScrollDirection.Vertical;

  build() {
    Flex() {
      Scroll(this.scrollerForScroll) {
        Column({ space: 5 }) {
          Row({}) {
            Text('Scroll Forward').fontSize(5)
            Button('SELF_ONLY').onClick((event: ClickEvent) => {
              this.NestedScrollModeF = this.NestedScrollMode0
            }).fontSize(5)
            Button('SELF_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeF = this.NestedScrollMode1
            }).fontSize(5)
            Button('PARENT_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeF = this.NestedScrollMode2
            }).fontSize(5)
            Button('PARALLEL').onClick((event: ClickEvent) => {
              this.NestedScrollModeF = this.NestedScrollMode3
            }).fontSize(5)
          }

          Row({}) {
            Text('Scroll Backward').fontSize(5)
            Button('SELF_ONLY').onClick((event: ClickEvent) => {
              this.NestedScrollModeB = this.NestedScrollMode0
            }).fontSize(5)
            Button('SELF_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeB = this.NestedScrollMode1
            }).fontSize(5)
            Button('PARENT_FIRST').onClick((event: ClickEvent) => {
              this.NestedScrollModeB = this.NestedScrollMode2
            }).fontSize(5)
            Button('PARALLEL').onClick((event: ClickEvent) => {
              this.NestedScrollModeB = this.NestedScrollMode3
            }).fontSize(5)
          }

          Text('Default mode: scrollForward ---' + `${this.NestedScrollModeF}`).fontSize(10)
          Text('Default mode: scrollBackward ---' + `${this.NestedScrollModeB}`).fontSize(10)

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

          Web({ src: "www.example.com", controller: this.controller })
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

          Web({ src: "www.example.com", controller: this.controller2 })
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

        }.width("95%").border({ width: 5 })
      }
      .width("100%").height("120%").border({ width: 5 }).scrollable(this.ScrollDirection)
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding(20)
  }
}
```

![web-nested-scrolling](figures/web-nested-scrolling.gif)
