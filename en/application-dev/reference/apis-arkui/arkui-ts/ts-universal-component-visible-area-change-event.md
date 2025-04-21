# Visible Area Change Event

The visible area change event of a component refers to the change in the visual portion of the component on the screen. It can be used to determine whether the component is completely or partially displayed on the screen. It is usually applicable to scenarios such as advertisement exposure tracing.

> **NOTE**
>
>  The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.

## onVisibleAreaChange

onVisibleAreaChange(ratios: Array&lt;number&gt;, event: VisibleAreaChangeCallback): T

Called when the visible area of the component changes.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                               | Mandatory| Description                                                        |
| ------ | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| ratios | Array&lt;number&gt;                                 | Yes  | Threshold array. Each threshold represents a ratio of the component's visible area (that is, the area of the component that is visible on screen; only the area within the parent component is counted) to the component's total area. This callback is invoked when the ratio of the component's visible area to its total area is greater than or less than the threshold. The value range of the threshold is [0.0, 1.0]. If the threshold set exceeds this range, the value **0.0** or **1.0** will be used.<br>**NOTE**<br>When the value is close to the boundary 0 or 1, it is rounded off with a round-off error not greater than 0.001. For example, 0.9997 is rounded off to 1.|
| event  | [VisibleAreaChangeCallback](ts-types.md#visibleareachangecallback12) | Yes  | Callback for visible area changes of the component.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Current component.|

> **NOTE**
>
>
>- This API only takes into account the relative clipped area ratio of the component with respect to all ancestor nodes (up to the window boundary) and its own area.
> 
>- It does not support calculations for obstructions caused by sibling components or by sibling components of any ancestors, such as those managed by [Stack](ts-container-stack.md) or [z-order control](ts-universal-attributes-z-order.md).
>
>- It does not support visibility change calculations for nodes that are not in the component tree. For example, preloaded nodes or custom nodes mounted using the [overlay](ts-universal-attributes-overlay.md#overlay) capability.

## onVisibleAreaApproximateChange<sup>18+</sup>

onVisibleAreaApproximateChange(options: VisibleAreaEventOptions, event: VisibleAreaChangeCallback | undefined): void

Called to set the callback parameters for the [onVisibleAreaChange](./ts-universal-component-visible-area-change-event.md#onvisibleareachange) event and restrict its execution interval.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description                      |
| ------ | ------ | ---- | -------------------------- |
| options  | [VisibleAreaEventOptions](./ts-types.md#visibleareaeventoptions12) | Yes  | Options of visible area changes.|
| event  | [VisibleAreaChangeCallback](./ts-types.md#visibleareachangecallback12)   \| undefined | Yes  | Callback for the **onVisibleAreaChange** event. This callback is triggered when the ratio of the component's visible area to its total area approaches the threshold set in **options**.|

>**NOTE**
>
> This callback is not a real-time callback. The actual callback interval may differ from the expected interval.
>
> The interval between two visible area change callbacks will not be less than the expected update interval. If the provided expected interval is too short, the actual callback interval will be determined by the system load.
>
> By default, the interval threshold of the visible area change callback includes 0. This means that, if the provided threshold is [0.5], the effective threshold will be [0.0, 0.5].

## Example

### Example 1: Using onVisibleAreaChange to Listen for Visible Area Changes

This example demonstrates how to set an **onVisibleAreaChange** event for a component, which triggers the callback when the component is fully displayed or completely hidden.

```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller()
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State testTextStr: string = 'test'
  @State testRowStr: string = 'test'

  build() {
    Column() {
      Column() {
        Text(this.testTextStr)
          .fontSize(20)

        Text(this.testRowStr)
          .fontSize(20)
      }
      .height(100)
      .backgroundColor(Color.Gray)
      .opacity(0.3)

      Scroll(this.scroller) {
        Column() {
          Text("Test Text Visible Change")
            .fontSize(20)
            .height(200)
            .margin({ top: 50, bottom: 20 })
            .backgroundColor(Color.Green)
              // Set ratios to [0.0, 1.0] to invoke the callback when the component is fully visible or invisible on screen.
            .onVisibleAreaChange([0.0, 1.0], (isExpanding: boolean, currentRatio: number) => {
              console.info('Test Text isExpanding: ' + isExpanding + ', currentRatio:' + currentRatio)
              if (isExpanding && currentRatio >= 1.0) {
                console.info('Test Text is fully visible. currentRatio:' + currentRatio)
                this.testTextStr = 'Test Text is fully visible'
              }

              if (!isExpanding && currentRatio <= 0.0) {
                console.info('Test Text is completely invisible.')
                this.testTextStr = 'Test Text is completely invisible'
              }
            })

          Row() {
            Text('Test Row Visible  Change')
              .fontSize(20)
              .margin({ bottom: 20 })

          }
          .height(200)
          .backgroundColor(Color.Yellow)
          .onVisibleAreaChange([0.0, 1.0], (isExpanding: boolean, currentRatio: number) => {
            console.info('Test Row isExpanding:' + isExpanding + ', currentRatio:' + currentRatio)
            if (isExpanding && currentRatio >= 1.0) {
              console.info('Test Row is fully visible.')
              this.testRowStr = 'Test Row is fully visible'
            }

            if (!isExpanding && currentRatio <= 0.0) {
              console.info('Test Row is completely invisible.')
              this.testRowStr = 'Test Row is completely invisible'
            }
          })

          ForEach(this.arr, (item:number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item:number) => (item.toString()))

        }.width('100%')
      }
      .backgroundColor(0x317aff)
      .scrollable(ScrollDirection.Vertical)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Gray)
      .scrollBarWidth(10)
      .onWillScroll((xOffset: number, yOffset: number, scrollState: ScrollState) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
      .onScrollStop(() => {
        console.info('Scroll Stop')
      })

    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

### Example 2: Using onVisibleAreaApproximateChange to Listen for Visible Area Changes

This example demonstrates how to set an **onVisibleAreaApproximateChange** event for a component, which triggers the callback when the component is fully displayed or completely hidden.

```ts
// xxx.ets
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller()
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State testTextStr: string = 'test'
  @State testRowStr: string = 'test'

  build() {
    Column() {
      Column() {
        Text(this.testTextStr)
          .fontSize(20)

        Text(this.testRowStr)
          .fontSize(20)
      }
      .height(100)
      .backgroundColor(Color.Gray)
      .opacity(0.3)

      Scroll(this.scroller) {
        Column() {
          Text("Test Text Visible Change")
            .fontSize(20)
            .height(200)
            .margin({ top: 50, bottom: 20 })
            .backgroundColor(Color.Green)
              // Set ratios to [0.0, 1.0] to invoke the callback when the component is fully visible or invisible on screen.
            .onVisibleAreaApproximateChange({ratios: [0.0, 1.0], expectedUpdateInterval: 1000}, (isExpanding: boolean, currentRatio: number) => {
              console.info('Test Text isExpanding: ' + isExpanding + ', currentRatio:' + currentRatio)
              if (isExpanding && currentRatio >= 1.0) {
                console.info('Test Text is fully visible. currentRatio:' + currentRatio)
                this.testTextStr = 'Test Text is fully visible'
              }

              if (!isExpanding && currentRatio <= 0.0) {
                console.info('Test Text is completely invisible.')
                this.testTextStr = 'Test Text is completely invisible'
              }
            })

          Row() {
            Text('Test Row Visible Change')
              .fontSize(20)
              .margin({ bottom: 20 })

          }
          .height(200)
          .backgroundColor(Color.Yellow)
          .onVisibleAreaChange([0.0, 1.0], (isExpanding: boolean, currentRatio: number) => {
            console.info('Test Row isExpanding:' + isExpanding + ', currentRatio:' + currentRatio)
            if (isExpanding && currentRatio >= 1.0) {
              console.info('Test Row is fully visible.')
              this.testRowStr = 'Test Row is fully visible'
            }

            if (!isExpanding && currentRatio <= 0.0) {
              console.info('Test Row is completely invisible.')
              this.testRowStr = 'Test Row is completely invisible'
            }
          })

          ForEach(this.arr, (item:number) => {
            Text(item.toString())
              .width('90%')
              .height(150)
              .backgroundColor(0xFFFFFF)
              .borderRadius(15)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, (item:number) => (item.toString()))

        }.width('100%')
      }
      .backgroundColor(0x317aff)
      .scrollable(ScrollDirection.Vertical)
      .scrollBar(BarState.On)
      .scrollBarColor(Color.Gray)
      .scrollBarWidth(10)
      .onWillScroll((xOffset: number, yOffset: number, scrollState: ScrollState) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
      .onScrollStop(() => {
        console.info('Scroll Stop')
      })

    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```
![en-us_visible_area_change.gif](figures/en-us_visible_area_change.gif)
