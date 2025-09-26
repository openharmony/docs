# Detecting Component Visibility
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

## Overview
Component visibility refers to the display state of a component on the screen. By detecting visibility, applications can implement the following typical scenarios:
- Component exposure tracking and analysis (for example, calculating how long an advertisement component is displayed on the screen)
- On-demand resource loading and releasing (for example, releasing images, videos, and other resources used by a component when it becomes invisible)
- Detecting complex view switching (for example, in nested multi-level views, handling related logic based on the component display state)

For the above scenarios, the following strategies are recommended:

|Scenario|Recommendation API|Description|
|----- |---- |--- |
|[Component exposure tracking and analysis](#component-exposure-tracking-and-analysis)| onVisibleAreaApproximateChange |Ideal for a large number of components; uses low-frequency calculation to reduce overhead.|
|[On-demand resource loading and releasing](#on-demand-resource-loading-and-releasing)| onVisibleAreaChange |Ideal for a small number of components; uses per-frame detection for timely updates.|
|[Detection of complex view switching](#detection-of-complex-view-switching)| nodeRenderState listener| Suitable for visibility changes caused by page or view switching.|

Applications can also traverse and calculate component visibility manually, but due to the complex hierarchy of components, such calculations involve heavy computation and are generally not recommended.

## Component Exposure Tracking and Analysis

Use [onVisibleAreaApproximateChange](../reference/apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareaapproximatechange17) to listen for the exposure duration of key components (such as ads or product cards) for user behavior analysis and operations statistics.

This API is more efficient than **onVisibleAreaChange**. It supports setting a calculation interval to reduce detection frequency, making it suitable for scenarios with many components and deep hierarchies, significantly reducing performance overhead.

> **NOTE**
> 
> This feature is supported since API version 17.

```typescript
class ListDataSource implements IDataSource {
  private list: number[] = [];
  private listeners: DataChangeListener[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    });
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  public deleteItem(index: number): void {
    this.list.splice(index, 1);
    this.notifyDataDelete(index);
  }

  public insertItem(index: number, data: number): void {
    this.list.splice(index, 0, data);
    this.notifyDataAdd(index);
  }
}

class ExposureTrackingData {
  // Use a map to track currently displayed ad slots and their start timestamps, to calculate the onscreen duration when they become invisible.
  private visibleAdvertisingInfos = new Map<string, number>();
  // Use a map to record the total display duration for each ad slot.
  private exposureData = new Map<string, number>();

  constructor() {
  }

  notifyAdvertisingSlotIsAppearing(slot: string): void {
    // The ad slot starts to be displayed. Record the start timestamp.
    let startTimestamp = Date.now()
    this.visibleAdvertisingInfos.set(slot, startTimestamp)
  }

  notifyAdvertisingSlotIsDisappearing(slot: string): void {
    // The ad slot starts to disappear. Calculate this display duration and add it to the total.
    let endTimestamp: number = Date.now()
    let advertisingInfo = this.visibleAdvertisingInfos.get(slot)
    let duration: number = 0
    if (advertisingInfo) {
      duration = endTimestamp - advertisingInfo.valueOf()
    }
    // Update the total display duration.
    this.updateExposureData(slot, duration)
    // Remove this ad slot information from the map of currently displayed slots.
    this.visibleAdvertisingInfos.delete(slot)
  }

  notifyPageHiding(): void {
    // The page is exiting. Report the statistics.
    this.reportData()
  }

  updateExposureData(slot: string, duration: number) {
    if (duration <= 0) {
      return
    }
    let oldDuration = 0
    let dataItem = this.exposureData.get(slot)
    if (dataItem) {
      oldDuration = dataItem.valueOf()
    }
    this.exposureData.set(slot, oldDuration + duration)
  }

  consumeAllCurrentVisibleSlots(): void {
    this.visibleAdvertisingInfos.forEach((value: number, key: string) => {
      this.notifyAdvertisingSlotIsDisappearing(key)
    });
    this.visibleAdvertisingInfos.clear()
  }

  reportData(): void {
    // Before reporting the statistics, process all currently displayed ad slots for their total duration.
    this.consumeAllCurrentVisibleSlots()
    // Send data to the analytics platform.
    console.info(`Exposure data report: ` + Array.from(this.exposureData))
    // Clear data after reporting.
    this.exposureData.clear()
  }
}

@Entry
@ComponentV2
struct ExposureTrackingPage {
  private data: ListDataSource =
    new ListDataSource([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]);
  private exposureData = new ExposureTrackingData()

  onPageHide(): void {
    // Report statistics to the analytics platform when the page exits.
    this.exposureData.notifyPageHiding()
  }

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        LazyForEach(this.data, (item: number) => {
          ListItem() {
            Text(this.getAdvertisingSlotInfo(item))
              .width('100%')
              .height(100)
              .fontSize(20)
              .fontColor(Color.White)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(this.calculateItemBackgroundColor(item))
          }
          // Add a visibility listener callback for each list item. The threshold is set to 0.5, meaning if more than half of the ad slot is displayed on screen, it is considered exposed.
          // Although only one line of code is written here, a callback is bound for each displayed list item. Therefore, the callback that supports configurable calculation frequency is used.
          .onVisibleAreaApproximateChange({ ratios: [0.5], expectedUpdateInterval: 500 },
            (isExpanding: boolean, currentRatio: number) => {
              this.handleExposureTracking(item, isExpanding, currentRatio)
            })
        }, (item: number) => item.toString())
      }
      .listDirection(Axis.Vertical)
      .scrollBar(BarState.Off)
      .edgeEffect(EdgeEffect.Spring)
      .width('90%')
      .margin(5)
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }

  private isAdvertisingSlot(index: number): boolean {
    // Assume every 5th component is an ad slot.
    return (index % 5 == 0)
  }

  private calculateAdvertisingSlot(index: number): number | null {
    if (this.isAdvertisingSlot(index)) {
      return (index / 5)
    }
    return null
  }

  private calculateItemBackgroundColor(index: number): Color {
    if (this.isAdvertisingSlot(index)) {
      return Color.Green
    }

    return Color.Gray
  }

  private getAdvertisingSlotInfo(index: number): string {
    let advertisingSlot = this.calculateAdvertisingSlot(index)
    if (advertisingSlot) {
      return advertisingSlot + " Ad Slot"
    }
    return 'Normal Content ' + index
  }

  private handleExposureTracking(index: number, isExpanding: boolean, currentRatio: number): void {
    if (!this.isAdvertisingSlot(index)) {
      // Do not handle non-ad slots.
      return
    }
    let slot = this.getAdvertisingSlotInfo(index)
    if (isExpanding) {
      // The visible ratio is increasing, meaning the component is appearing.
      this.exposureData.notifyAdvertisingSlotIsAppearing(slot)
      return
    }
    // The visible ratio is decreasing, meaning the component is disappearing.
    this.exposureData.notifyAdvertisingSlotIsDisappearing(slot)
  }
}
```

## On-demand Resource Loading and Releasing

Use [onVisibleAreaChange](../reference/apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareachange) to listen for fine-grained changes in the visible ratio of a component. When the visible ratio approaches the preset threshold, a callback is triggered to load or release resources based on these changes.

> **NOTE**
> 
> This feature is supported since API version 9.
> - The visible area is limited by the boundaries of the parent component; the part beyond the parent will not be counted in the visible ratio calculation.
> - Because of floating-point comparisons, the system will trigger callbacks when the result approaches the set threshold.
> - To ensure timely visibility change notifications, the system detects ratio changes per frame. To reduce system load, minimize the use of this API.

```typescript
import { image } from '@kit.ImageKit';

class ListDataSource implements IDataSource {
  private list: number[] = [];
  private listeners: DataChangeListener[] = [];

  constructor(list: number[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): number {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
    if (this.listeners.indexOf(listener) < 0) {
      this.listeners.push(listener);
    }
  }

  unregisterDataChangeListener(listener: DataChangeListener): void {
    const pos = this.listeners.indexOf(listener);
    if (pos >= 0) {
      this.listeners.splice(pos, 1);
    }
  }

  notifyDataDelete(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataDelete(index);
    });
  }

  notifyDataAdd(index: number): void {
    this.listeners.forEach(listener => {
      listener.onDataAdd(index);
    });
  }

  public deleteItem(index: number): void {
    this.list.splice(index, 1);
    this.notifyDataDelete(index);
  }

  public insertItem(index: number, data: number): void {
    this.list.splice(index, 0, data);
    this.notifyDataAdd(index);
  }
}

@Entry
@ComponentV2
struct Index {
  @Local headerImage: PixelMap | null = null
  private data: ListDataSource =
    new ListDataSource([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]);

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ListItem() {
          Image(this.headerImage)
            .width('100%')
            .height(300)
            // This is the only component on the entire page that requires visibility listening, and it needs to detect state changes in a timely manner to load resources immediately.
            .onVisibleAreaChange([0.1], (isExpanding: boolean, currentRatio: number) => {
              this.loadOrReleaseHeaderImage(isExpanding)
            })
        }

        LazyForEach(this.data, (item: number) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(50)
              .fontSize(20)
              .fontColor(Color.White)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(Color.Grey)
          }
        }, (item: number) => item.toString())
      }
      .listDirection(Axis.Vertical)
      .scrollBar(BarState.Off)
      .edgeEffect(EdgeEffect.Spring)
      .width('90%')
      .margin(5)
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }

  private loadOrReleaseHeaderImage(isExpanding: boolean): void {
    if (!isExpanding) {
      // Release the image as it becomes invisible.
      this.headerImage = null
      console.info('Image released successfully')
      return
    }

    try {
      this.getUIContext().getHostContext()!.resourceManager.getMediaContent($r('app.media.startIcon').id,
        (error, value: ArrayBuffer) => {
          let opts: image.InitializationOptions = {
            editable: true,
            pixelFormat: 3,
            size: { height: 4, width: 6 }
          };
          let uint8Array: Uint8Array = new Uint8Array(value);
          let buffer: ArrayBuffer = uint8Array.buffer.slice(0);

          image.createPixelMap(buffer, opts).then((pixelMap) => {
            this.headerImage = pixelMap
            console.info('Image loaded successfully')
          })
        });
    } catch (error) {
      console.error(`callback getMediaContent failed, error code: ${error.code}, message: ${error.message}.`)
    }
  }
}
```

## Detection of Complex View Switching

Use the [on('nodeRenderState')](../reference/apis-arkui/arkts-apis-uicontext-uiobserver.md#onnoderenderstate20) API provided by **UIObserver** to listen for the rendering state of a specified component. This API requires a component ID to specify the component to observe, so it is not suitable for scenarios where components are frequently created and destroyed. It is suitable for detecting visibility changes caused by page transitions, such as page navigation or when the component's page is pushed onto the stack, for example, when the currently displayed page of a **Swiper** or **Tabs** component is no longer active.

There are two rendering states:
- **ABOUT_TO_RENDER_IN**: The component has been mounted to the render tree and will be rendered in the next frame.
- **ABOUT_TO_RENDER_OUT**: The component has been removed from the render tree and will not be rendered in the next frame.

> **NOTE**
> 
> This feature is supported since API version 20.

Note that **ABOUT_TO_RENDER_IN** only indicates that the component has entered the rendering process and will be displayed in the next frame, but it may still not be visible if covered by other components. Therefore, rendering state is not completely equivalent to visibility.

The following example nests an observed **Column** component within a hierarchy of **Tabs**, **Navigation**, and **Swiper** containers. Across operations like switching tabs, navigating pages, or swiping through the **Swiper**, the component's visibility on the screen is accurately detected.

> **NOTE**
> Given the characteristics of the **on('nodeRenderState')** API, it is not recommended for list item scenarios where nodes are recycled and removed from the tree when scrolled out of screen.


```typescript
// Index.ets
import { NodeRenderState } from '@kit.ArkUI';

@Entry
@ComponentV2
struct Index {
  private childNavStack: NavPathStack = new NavPathStack();
  private tabController: TabsController = new TabsController();

  build() {
    Tabs({ barPosition: BarPosition.End, controller: this.tabController }) {
      TabContent() {
        Navigation() {
          Stack({ alignContent: Alignment.Center }) {
            Swiper() {
              // The first page of the Swiper is a child Navigation.
              Navigation(this.childNavStack) {
                Column() {
                  Text('Monitored Component')
                    .width('100%')
                    .height('100%')
                    .fontSize(26)
                    .fontColor(Color.White)
                    .textAlign(TextAlign.Center)
                }
                .width('90%')
                .height(300)
                .backgroundColor(Color.Blue)
                .id('component_to_be_monitor')
                .onAttach(() => {
                  // Register the listener callback after 10 ms to ensure that the mounting process is fully complete.
                  setTimeout(()=>{
                    // Enable rendering state monitoring when the observed component is mounted.
                    this.getUIContext()
                      .getUIObserver()
                      .on('nodeRenderState', 'component_to_be_monitor', (state: NodeRenderState, node?: FrameNode) => {
                        if (state == NodeRenderState.ABOUT_TO_RENDER_IN) {
                          console.info('Component will appear')
                        } else {
                          console.info('Component will disappear')
                        }
                      })
                  }, 10)
                })
                .onDetach(() => {
                  // Cancel monitoring when the observed component is removed from the component tree.
                  this.getUIContext().getUIObserver().off('nodeRenderState', 'component_to_be_monitor')
                })

                Button('Navigate to Next Page', { stateEffect: true, type: ButtonType.Capsule })
                  .width('80%')
                  .height(40)
                  .margin(20)
                  .onClick(() => {
                    let parentStack = this.childNavStack.getParent();
                    parentStack?.pushPath({ name: "pageTwo" });
                  })
              }
              .clip(true)
              .backgroundColor(Color.Orange)
              .width('90%')
              .height('90%')
              .title('ChildNavigation')

              // Second page of the Swiper
              Text('Swiper Page 2')
                .width('90%')
                .height('90%')
                .fontSize(20)
                .fontColor(Color.Black)
                .backgroundColor(Color.Orange)
                .textAlign(TextAlign.Center)
              // Third page of the Swiper
              Text('Swiper Page 3')
                .width('90%')
                .height('90%')
                .fontSize(20)
                .fontColor(Color.Black)
                .backgroundColor(Color.Orange)
                .textAlign(TextAlign.Center)
            }
            .itemSpace(10)
          }
          .width('100%')
          .height('100%')
        }
        .backgroundColor(Color.Green)
        .width('100%')
        .height('100%')
        .title('ParentNavigation')
      }.tabBar('Home')

      TabContent() {
        Text('Recommended')
          .width('100%')
          .height('100%')
          .fontSize(20)
          .fontColor(Color.Black)
          .backgroundColor(Color.Pink)
          .textAlign(TextAlign.Center)
      }.tabBar('Recommended')

      TabContent() {
        Text('Me')
          .width('100%')
          .height('100%')
          .fontSize(20)
          .fontColor(Color.Black)
          .backgroundColor(Color.Yellow)
          .textAlign(TextAlign.Center)
      }.tabBar('Me')
    }
    .backgroundColor(Color.Gray)
  }
}
```

```typescript
// PageTwo.ets
@Builder
export function PageTwoBuilder(name: string) {
  NavDestination() {
    Text("this is " + name)
      .width('100%')
      .height('100%')
      .textAlign(TextAlign.Center)
      .fontSize(20)
      .fontColor(Color.White)
      .backgroundColor(Color.Red)
  }
  .title(name)
}
```

Create the **route_map.json** file in **resources/base/profile**, and add the following information to the file:

```json
{
  "routerMap": [
    {
      "name": "pageTwo",
      "pageSourceFile": "src/main/ets/pages/PageTwo.ets",
      "buildFunction": "PageTwoBuilder",
      "data": {
        "description": "this is pageTwo"
      }
    }
  ]
}
```

Define the **routerMap** field under **module** in the **module.json5** file to point to the defined route table configuration file **route_map.json**.

```json
"routerMap": "$profile:route_map"
```

## FAQs

### Visibility Calculation Does Not Match Visual Perception

**Symptom**

The component has entered the screen but the callback is not triggered, or the visible ratio does not match visual perception.

**Solution**
- Check whether the parent component has the **clip** attribute set; clipping may cause deviations in visible area calculation.
- Consider the impact of component opacity: Even with opacity of 0, the area is still counted in the visible ratio.
- Use **nodeRenderState** listening for cross-validation.

### Performance Degradation Due to High-frequency Callbacks

**Symptom**

The UI stutters during scrolling, and logs show that visibility callbacks are being executed frequently.

**Solution**
- Switch to **onVisibleAreaApproximateChange** and set **expectedUpdateInterval** to a larger value.
- Reduce the number of components that have visibility callbacks registered.

### RenderState Listener Limit Exceeded
**Symptom**

**nodeRenderState** listening fails, and logs indicate that the maximum number of listeners has been exceeded.

**Solution**
- Replace the **nodeRenderState** listener with the more efficient **onVisibleAreaApproximateChange** API.
- Apply the listener to a parent container that stays on screen longer.
- Remove listeners that are no longer needed by using the **off** API.
