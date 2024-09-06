# Drag Event

## Overview

The drag event, bolstered by the drag and drop framework, represents a mode of data transfer using a mouse device or gesture: Users can drag data from one component to another. The component from which data is dragged is the drag source; and the component to which data is dropped is the drop target. This drag and drop operation enables users to easily move, copy, or delete data. The following are some key concepts involved:

* Drag operation: an operation that begins when a user selects a draggable component, continues when the user drags the component on the screen, and ends when the user releases the component on a droppable component.
* Drag preview (background): a visual representation of the data being dragged. You can set it by using [CustomerBuilder](../reference/apis-arkui/arkui-ts/ts-types.md#custombuilder8) or [DragItemInfo](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo) of [onDragStart](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart), or by using the universal attribute [dragPreview](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#dragpreview11).
* Drag data: data being dragged; encapsulated using the UDMF API [UnifiedData](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata).
* Drag source: component that initiates the drag operation and provides data.
* Drop target: component that can receive and process drag data.
* Drag point: position where the mouse device or finger has in contact with the screen. It is used to determine whether data enters a drop target.

## Drag Process

### ​Gesture-based Drag Operation

​If a drag operation is initiated by a gesture, the framework checks whether the current component is draggable. For draggable components ([Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md), [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md), [TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md), [RichEditor](../reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md), [Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md), [Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md), <!--Del-->[FormComponent](../reference/apis-arkui/arkui-ts/ts-basic-components-formcomponent-sys.md), <!--DelEnd-->[Hyperlink](../reference/apis-arkui/arkui-ts/ts-container-hyperlink.md)), the framework checks whether their [draggable](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#draggable) attribute is set to **true** (this attribute is true by default if layered parameters are used); for other components, the framework checks whether the **onDragStart** callback is set. If the attribute or callback is set as required, the framework starts dragging once a user has long pressed the component for 500 ms or longer, and displays a drag preview once the user has long pressed the component for 800 ms.

Below you can see the drag process initiated by a gesture (finger or stylus).

![en-us_image_0000001562820825](figures/en-us_image_0000001562820825.png)

### ​Mouse-based Drag Operation

When a mouse device is used as the pointer, the framework starts dragging once the draggable component has been moved with the left mouse button by more than 1 vp.

A drag and drop can occur in a single application, or start in one application and end in another. The following callback events are provided for you to detect the dragging status and intervene in the default dragging behavior of the system.

| Callback Event| Description|
| ---------------- | ------------------------|
| onDragStart | Triggered when a draggable component is dragged.<br>You can use this callback to detect the initiation of dragging behavior. You can also set the drag data and drag preview in this callback. To avoid extra performance overhead, it is recommended that the drag preview be returned in the mode of **pixelmap**, instead of **customBuilder**.|
| onDragEnter | Triggered when a dragged item enters the boundaries of the component. This callback is called only when the component listens for the [onDrop](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop) event.|
| onDragMove| Triggered when the dragged item moves in the boundaries of the component. This callback is called only when the component listens for the **onDrop** event.<br>During the movement, the **setResult** API in [DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent) can be used to affect the system appearance in some scenarios.<br>1. Set **DragResult.DROP\_ENABLED**.<br>2. Set **DragResult.DROP\_DISABLED**.|
| onDragLeave | Triggered when the dragged item leaves the boundaries of the component. This callback is called only when the component listens for the **onDrop** event.<br>By default, the **onDragLeave** callback is not called in the following cases:<br>1. An item in a parent component is dragged to one of its child components.<br>2. The layout of the drop target component overlaps that of the drag source component.<br>Since API version 12, the [setDragEventStrictReportingEnabled](../reference/apis-arkui/js-apis-arkui-UIContext.md#setdrageventstrictreportingenabled12) API in [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md) can be used to trigger the **onDragLeave** event in a strict fashion.|
| onDrop | Triggered when the dragged item is dropped on the component. The dragging result must be set in this callback through the **setResult** API in **DragEvent**. Otherwise, the **getResult** API in the **onDragEnd** method of the drag source component only returns the default result **DragResult.DRAG\_FAILED**.<br>This callback is where you can intervene in the default drop processing behavior. The system preferentially executes the **onDrop** callback and processes the drag data based on the **setResult** method in the callback function.<br>1. If **DragResult.DRAG\_SUCCESSFUL** is set, you need to process the data on your own; the system does not process the data.<br>2. If **DragResult.DRAG\_FAILED** is set, the system does not process the data.<br>3. If **DragResult.DRAG\_CANCELED** is set, the system does not process the data.<br>4. Setting **DragResult.DROP\_ENABLED** or **DragResult.DROP\_DISABLED** will be ignored, producing the same effect as **DragResult.DRAG\_FAILED**.|
| onDragEnd | Triggered when dragging of the component ends.|
| onPreDrag | Triggered when the component enters a state prior to a drop and drop operation.<br>You can use this callback to listen for the value of [PreDragStatus](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#predragstatus12) to prepare corresponding data.<br>1. **ACTION\_DETECTING\_STATUS**: A drag gesture is being detected. (Triggered when the component is long pressed for 50 ms.)<br>2. **READY\_TO\_TRIGGER\_DRAG\_ACTION**: The component is ready to be dragged. (Triggered when the component is long pressed for 500 ms.)<br>3. **PREVIEW\_LIFT\_STARTED**: A lift animation is started. (Triggered when the component is long pressed for 800 ms.)<br>4. **PREVIEW\_LIFT\_FINISHED**: A lift animation is finished. (Triggered at the completion of the lift animation.)<br>5. **PREVIEW\_LANDING\_STARTED**: A drop animation is started. (Triggered when the drop animation starts.)<br>6. **PREVIEW\_LANDING\_FINISHED**: A drop animation is finished. (Triggered when the drop animation ends.)<br>7. **ACTION\_CANCELED\_BEFORE\_DRAG**: A drop animation is terminated. (Triggered when the finger is lifted off the screen after the component enters the **READY\_TO\_TRIGGER\_DRAG\_ACTION** state.)|

For more usage, see [Drag Event](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md)

## Drag Preview

The drag preview is an image displayed during the drag and drop operation. It is a visual representation of the drag data, not the component itself. You can set it to any supported image that you want to display to users. The **customBuilder** or **pixelmap** object returned by the **onDragStart** callback can be used to set the drag preview – snapshot of the component by default – displayed during dragging and moving. The **customBuilder** or **pixelmap** object set by the **dragpreview** attribute can be used to set the drag preview – snapshot of the component by default – during a lift animation and dragging.

You can set the opacity, rounded corners, shadow, and blur for the drag preview. For details, see [Drag and Drop Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md).

**Constraints**:

* For a container component, if the internal content exceeds the range of the container component due to **position**, **offset**, and other settings, the component snapshot does not capture the content beyond the range. To show the out-of-range content, you can expand the container scope or customize the container.
* Regardless of how the component snapshot is captured, using a custom builder or the default mode, the snapshot does not support the transform APIs, such as [scale](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale) and [rotate](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#rotate).

## How to Develop

### General Drag and Drop Adaptation

The following uses the [Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md) component as an example to describe the basic procedure for drag and drop development and the precautions to be taken during development.

1. Make the component draggable.

* Set the **draggable** attribute to **true** and set the **onDragStart** callback function. In the callback function, you can use UDMF to set the drag data and return the custom drag preview.

    ```ts
    import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';

    Image($r('app.media.app_icon'))
        .width(100)
        .height(100)
        .draggable(true)
        .onDragStart((event) => {
            let data: unifiedDataChannel.Image = new unifiedDataChannel.Image();
            data.imageUri = 'common/pic/img.png';
            let unifiedData = new unifiedDataChannel.UnifiedData(data);
            event.setData(unifiedData);

            let dragItemInfo: DragItemInfo = {
            pixelMap: this.pixmap,
            extraInfo: "this is extraInfo",
            };
            // The custom drag preview is returned in onDragStart.
            return dragItemInfo;
        })
    ```

* The gesture-based drag operation is initiated by a long press gesture bound at the underlying layer. If a long press gesture is also bound to the dragged component, gesture conflict will occur, resulting in dragging to fail. To avoid such an issue, you can use parallel gestures.

    ```ts
    .parallelGesture(LongPressGesture().onAction(() => {
       promptAction.showToast({ duration: 100, message: 'Long press gesture trigger' });
    }))
    ```

2. Customize the drag preview.
   
  * Prepare the pixel map for the custom drag preview within the callback triggered by [onPreDrag](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#onpredrag12) after a long press of 50 ms.
   
    ```ts
    .onPreDrag((status: PreDragStatus) => {
        if (preDragStatus == PreDragStatus.ACTION_DETECTING_STATUS) {
            this.getComponentSnapshot();
        }
    })
    ```
   
   * Generate the specific pixel map by calling [componentSnapshot.createFromBuilder](../reference/apis-arkui/js-apis-arkui-componentSnapshot.md#componentsnapshotcreatefrombuilder).

      ```ts
      @Builder
      pixelMapBuilder() {
          Column() {
            Image($r('app.media.startIcon'))
              .width(120)
              .height(120)
              .backgroundColor(Color.Yellow)
          }
        }
        private getComponentSnapshot(): void {
        componentSnapshot.createFromBuilder(()=>{this.pixelMapBuilder()},
        (error: Error, pixmap: image.PixelMap) => {
            if(error){
              console.log("error: " + JSON.stringify(error))
              return;
            }
            this.pixmap = pixmap;
        })
      }
      ```

3. To strictly execute the [onDragLeave](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave) event, use the [setDragEventStrictReportingEnabled](../reference/apis-arkui/js-apis-arkui-UIContext.md#setdrageventstrictreportingenabled12) API.

    ```ts
    import { UIAbility } from '@kit.AbilityKit';
    import { window, UIContext } from '@kit.ArkUI';

    export default class EntryAbility extends UIAbility {
      onWindowStageCreate(windowStage: window.WindowStage): void {
        windowStage.loadContent('pages/Index', (err, data) => {
          if (err.code) {
            return;
          }
          windowStage.getMainWindow((err, data) => {
            if (err.code) {
              return;
            }
            let windowClass: window.Window = data;
            let uiContext: UIContext = windowClass.getUIContext();
            uiContext.getDragController().setDragEventStrictReportingEnabled(true);
          });
        });
      }
    }
    ```

4. Set the badge displayed during dragging.

* You can set [allowDrop](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#allowdrop) to define the allowed data types for dropping to affect the badge display. The COPY badge is displayed when the drag data matches the allowed data types, the FORBIDDEN badge when it does not, and the MOVE badge if **allowDrop** is not set. The following example allows only data of HYPERLINK and PLAIN_TEXT types defined in UnifiedData.

    ```ts
    .allowDrop([uniformTypeDescriptor.UniformDataType.HYPERLINK, uniformTypeDescriptor.UniformDataType.PLAIN_TEXT])
    ```

* If the **onDrop** callback is implemented, you can control the badge display by setting [DragResult](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragresult10) to **DROP\_ENABLED** in **onDragMove** and setting [DragBehavior](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragbehavior10) to **COPY** or **MOVE**. The following code forces the badge to display **MOVE** during a drag operation:

    ```ts
    .onDragMove((event) => {
        event.setResult(DragResult.DROP_ENABLED);
        event.dragBehavior = DragBehavior.MOVE;
    })
    ```

5. Receive drag data.

* Set the **onDrop** callback to handle the drag data and determine the drag result.

    ```ts
    .onDrop((dragEvent?: DragEvent) => {
        // Obtain the drag data.
        this.getDataFromUdmf((dragEvent as DragEvent), (event: DragEvent) => {
        let records: Array<unifiedDataChannel.UnifiedRecord> = event.getData().getRecords();
        let rect: Rectangle = event.getPreviewRect();
        this.imageWidth = Number(rect.width);
        this.imageHeight = Number(rect.height);
        this.targetImage = (records[0] as unifiedDataChannel.Image).imageUri;
        this.imgState = Visibility.None;
        // Explicitly set the result to successful, and then pass this value to onDragEnd of the drag source.
        event.setResult(DragResult.DRAG_SUCCESSFUL);
    })
    ```

* Data transfer is managed by UDMF, which may experience latency with large data volumes. Therefore, you are advised to implement a retry mechanism with a 1500 ms delay after the initial data acquisition fails.

    ```ts
    getDataFromUdmfRetry(event: DragEvent, callback: (data: DragEvent) => void) {
       try {
         let data: UnifiedData = event.getData();
         if (!data) {
           return false;
         }
         let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
         if (!records || records.length <= 0) {
           return false;
         }
         callback(event);
         return true;
       } catch (e) {
         console.log("getData failed, code: " + (e as BusinessError).code + ", message: " + (e as BusinessError).message);
         return false;
       }
    }

    getDataFromUdmf(event: DragEvent, callback: (data: DragEvent) => void) {
      if (this.getDataFromUdmfRetry(event, callback)) {
        return;
      }
      setTimeout(() => {
        this.getDataFromUdmfRetry(event, callback);
      }, 1500);
    }
    ```

6. The drag initiator can detect the result of the drag operation by setting the **onDragEnd** callback.

    ```ts
    import { promptAction } from '@kit.ArkUI';

    .onDragEnd((event) => {
        // The result value obtained from onDragEnd is set in onDrop of the drop target.
      if (event.getResult() === DragResult.DRAG_SUCCESSFUL) {
        promptAction.showToast({ duration: 100, message: 'Drag Success' });
      } else if (event.getResult() === DragResult.DRAG_FAILED) {
        promptAction.showToast({ duration: 100, message: 'Drag failed' });
      }
    })
    ```

### Multi-Select Drag and Drop Adaptation

Since API version 12, the [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md) and [List](../reference/apis-arkui/arkui-ts/ts-container-list.md) components, specifically the **GridItem** and **ListItem** components within them, support multi-select drag and drop, currently only accessible through the **onDragStart** API. The following uses **Grid** as an example to describe the basic procedure for multi-select drag and drop development and key considrations during development.

1. Enable multi-select drag and drop.

* Create **GridItem** child components and bind the **onDragStart** callback to them. In addition, set the **GridItem** components to be selectable.

    ```ts
    Grid() {
      ForEach(this.numbers, (idx: number) => {
        GridItem() {
          Column()
            .backgroundColor(this.colors[idx % 9])
            .width(50)
            .height(50)
            .opacity(1.0)
            .id('grid'+idx)
        }
        .onDragStart(()=>{})
        .selectable(true)
      }, (idx: string) => idx)
    }
    ```

* Multi-select drag and drop is disabled by default. To enable it, set **isMultiSelectionEnabled** to **true** in the **DragInteractionOptions** parameter of the [dragPreviewOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#dragpreviewoptions11) API. **DragInteractionOptions** also has the **defaultAnimationBeforeLifting** parameter, which, when set to **true**, applies a default scaling down animation as the lift animation for the component.

    ```ts
    .dragPreviewOptions({isMultiSelectionEnabled:true,defaultAnimationBeforeLifting:true})
    ```

* To maintain the selected state, set the **selected** attribute of the **GridItem** child component to **true**. For example, use [onClick](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md#onclick) to set a specific component to the selected state.

    ```ts
    .selected(this.isSelectedGrid[idx])
    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
    })
    ```

2. Optimize the multi-select drag and drop performance.

* In multi-select drag and drop scenarios, there is a clustering animation effect when multiple items are selected. This effect captures a snapshot of the selected components currently displayed on the screen, which can lead to high performance costs if there are too many selected components. To save on performance, multi-select drag and drop supports obtaining a snapshot from **dragPreview** to use as the basis for the clustering animation.

    ```ts
    .dragPreview({
        pixelMap:this.pixmap
    })
    ```

* You can obtain snapshots of a component by calling the **get** method of **componentSnapshot** when the component is selected. The following shows how to use the component ID to obtain the snapshot.

    ```ts
    @State previewData: DragItemInfo[] = []
    @State isSelectedGrid: boolean[] = []
    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
        if (this.isSelectedGrid[idx]) {
            let gridItemName = 'grid' + idx
            componentSnapshot.get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap
                this.previewData[idx] = {
                    pixelMap:this.pixmap
                }
            })
        }
    })
    ```

3. Set the multi-select display effects.

    Use **stateStyles** to set display effects for selected and unselected states for easy distinction.

    ```ts
    @Styles
    normalStyles(): void{
      .opacity(1.0)
    }

    @Styles
    selectStyles(): void{
      .opacity(0.4)
    }

    .stateStyles({
      normal : this.normalStyles,
      selected: this.selectStyles
    })
    ```

4. Adapt the number badge.

    Configure the number badge for multi-select drag and drop using the **numberBadge** parameter in **dragPreviewOptions**, adjusting it based on the number of selected items.

    ```ts
    @State numberBadge: number = 0;

    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
        if (this.isSelectedGrid[idx]) {
          this.numberBadge++;
        } else {
          this.numberBadge--;
      }
    })
    // Set the numberBadge parameter in dragPreviewOptions for the number badge in multi-select scenarios.
    .dragPreviewOptions({numberBadge: this.numberBadge})
    ```

## Example

### General Drag and Drop Adaptation Case

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
import { promptAction, componentSnapshot } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

@Entry
@Component
struct Index {
  @State targetImage: string = '';
  @State imageWidth: number = 100;
  @State imageHeight: number = 100;
  @State imgState: Visibility = Visibility.Visible;
  @State pixmap: image.PixelMap|undefined = undefined

  @Builder
  pixelMapBuilder() {
    Column() {
      Image($r('app.media.startIcon'))
        .width(120)
        .height(120)
        .backgroundColor(Color.Yellow)
    }
  }

  getDataFromUdmfRetry(event: DragEvent, callback: (data: DragEvent) => void) {
    try {
      let data: UnifiedData = event.getData();
      if (!data) {
        return false;
      }
      let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
      if (!records || records.length <= 0) {
        return false;
      }
      callback(event);
      return true;
    } catch (e) {
      console.log("getData failed, code: " + (e as BusinessError).code + ", message: " + (e as BusinessError).message);
      return false;
    }
  }
  // Obtain UDMF data with a retry mechanism of 1500 ms if the initial attempt fails.
  getDataFromUdmf(event: DragEvent, callback: (data: DragEvent) => void) {
    if (this.getDataFromUdmfRetry(event, callback)) {
      return;
    }
    setTimeout(() => {
      this.getDataFromUdmfRetry(event, callback);
    }, 1500);
  }
  // Use the createFromBuilder API of componentSnapshot to capture a snapshot of a custom builder.
  private getComponentSnapshot(): void {
    componentSnapshot.createFromBuilder(()=>{this.pixelMapBuilder()},
      (error: Error, pixmap: image.PixelMap) => {
        if(error){
          console.log("error: " + JSON.stringify(error))
          return;
        }
        this.pixmap = pixmap;
      })
  }
  // Prepare a custom screenshot pixel map after a 50 ms long press is detected.
  private PreDragChange(preDragStatus: PreDragStatus): void {
    if (preDragStatus == PreDragStatus.ACTION_DETECTING_STATUS) {
      this.getComponentSnapshot();
    }
  }

  build() {
    Row() {
      Column() {
        Text('start Drag')
          .fontSize(18)
          .width('100%')
          .height(40)
          .margin(10)
          .backgroundColor('#008888')
        Row() {
          Image($r('app.media.app_icon'))
            .width(100)
            .height(100)
            .draggable(true)
            .margin({ left: 15 })
            .visibility(this.imgState)
            // Bind a parallel gesture to trigger a custom long press gesture.
            .parallelGesture(LongPressGesture().onAction(() => {
              promptAction.showToast({ duration: 100, message: 'Long press gesture trigger' });
            }))
            .onDragStart((event) => {
              let data: unifiedDataChannel.Image = new unifiedDataChannel.Image();
              data.imageUri = 'common/pic/img.png';
              let unifiedData = new unifiedDataChannel.UnifiedData(data);
              event.setData(unifiedData);

              let dragItemInfo: DragItemInfo = {
                pixelMap: this.pixmap,
                extraInfo: "this is extraInfo",
              };
              return dragItemInfo;
            })
              // Prepare a custom drag preview in advance.
            .onPreDrag((status: PreDragStatus) => {
              this.PreDragChange(status);
            })
            .onDragEnd((event) => {
              // The result value obtained from onDragEnd is set in onDrop of the drop target.
              if (event.getResult() === DragResult.DRAG_SUCCESSFUL) {
                promptAction.showToast({ duration: 100, message: 'Drag Success' });
              } else if (event.getResult() === DragResult.DRAG_FAILED) {
                promptAction.showToast({ duration: 100, message: 'Drag failed' });
              }
            })
        }

        Text('Drag Target Area')
          .fontSize(20)
          .width('100%')
          .height(40)
          .margin(10)
          .backgroundColor('#008888')
        Row() {
          Image(this.targetImage)
            .width(this.imageWidth)
            .height(this.imageHeight)
            .draggable(true)
            .margin({ left: 15 })
            .border({ color: Color.Black, width: 1 })
            // Set the drag behavior to MOVE, which means no badge is displayed.
            .onDragMove((event) => {
              event.setResult(DragResult.DROP_ENABLED)
              event.dragBehavior = DragBehavior.MOVE
            })
            .allowDrop([uniformTypeDescriptor.UniformDataType.IMAGE])
            .onDrop((dragEvent?: DragEvent) => {
              // Obtain the drag data.
              this.getDataFromUdmf((dragEvent as DragEvent), (event: DragEvent) => {
                let records: Array<unifiedDataChannel.UnifiedRecord> = event.getData().getRecords();
                let rect: Rectangle = event.getPreviewRect();
                this.imageWidth = Number(rect.width);
                this.imageHeight = Number(rect.height);
                this.targetImage = (records[0] as unifiedDataChannel.Image).imageUri;
                this.imgState = Visibility.None;
                // Explicitly set the result to successful, and then pass this value to onDragEnd of the drag source.
                event.setResult(DragResult.DRAG_SUCCESSFUL);
              })
            })
        }
      }
      .width('100%')
      .height('100%')
    }
    .height('100%')
  }
}

```

### Multi-Select Drag and Drop Adaptation Case

```ts
import { componentSnapshot } from '@kit.ArkUI';
import { image } from '@kit.ImageKit';

@Entry
@Component
struct GridEts {
  @State pixmap: image.PixelMap|undefined = undefined
  @State numbers: number[] = []
  @State isSelectedGrid: boolean[] = []
  @State previewData: DragItemInfo[] = []
  @State colors: Color[] = [Color.Red, Color.Blue, Color.Brown, Color.Gray, Color.Green, Color.Grey, Color.Orange,Color.Pink ,Color.Yellow]
  @State numberBadge: number = 0;

  @Styles
  normalStyles(): void{
    .opacity(1.0)
  }

  @Styles
  selectStyles(): void{
    .opacity(0.4)
  }

  onPageShow(): void {
    let i: number = 0
    for(i=0;i<100;i++){
      this.numbers.push(i)
      this.isSelectedGrid.push(false)
      this.previewData.push({})
    }
  }

  @Builder
  RandomBuilder(idx: number) {
    Column()
      .backgroundColor(this.colors[idx % 9])
      .width(50)
      .height(50)
      .opacity(1.0)
  }

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.numbers, (idx: number) => {
          GridItem() {
            Column()
              .backgroundColor(this.colors[idx % 9])
              .width(50)
              .height(50)
              .opacity(1.0)
              .id('grid'+idx)
          }
          .dragPreview(this.previewData[idx])
          .selectable(true)
          .selected(this.isSelectedGrid[idx])
          // Set the multi-select display effects.
          .stateStyles({
            normal : this.normalStyles,
            selected: this.selectStyles
          })
          .onClick(()=>{
            this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
            if (this.isSelectedGrid[idx]) {
              this.numberBadge++;
              let gridItemName = 'grid' + idx
              // Call the get API in componentSnapshot to obtain the component snapshot pixel map on selection.
              componentSnapshot.get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap
                this.previewData[idx] = {
                  pixelMap:this.pixmap
                }
              })
            } else {
              this.numberBadge--;
            }
          })
          // Enable multiselect and set the number badge.
          .dragPreviewOptions({numberBadge: this.numberBadge},{isMultiSelectionEnabled:true,defaultAnimationBeforeLifting:true})
          .onDragStart(()=>{
          })
        }, (idx: string) => idx)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(5)
      .rowsGap(10)
      .backgroundColor(0xFAEEE0)
    }.width('100%').margin({ top: 5 })
  }
}
```
