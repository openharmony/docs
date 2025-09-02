# Implementing Unified Drag and Drop
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

Unified drag and drop refers to a data transfer interaction triggered by a mouse device or gesture. Users can drag data from one component (the drag source) and drop it into another (the drop target) to initiate a response. In this interaction, the drag source provides the data, while the drop target receives and processes it, thereby enabling users to easily move, copy, or delete data.

## Basic Concepts

* Drag operation: an operation that begins when a user selects a draggable component, continues when the user drags the component on the screen, and ends when the user releases the component on a droppable component.
* Drag preview (background): a visual representation of the data being dragged. You can set it by using [CustomerBuilder](../reference/apis-arkui/arkui-ts/ts-types.md#custombuilder8) or [DragItemInfo](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo) of [onDragStart](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart), or by using the universal attribute [dragPreview](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#dragpreview11).
* Drag data: data being dragged, encapsulated using the UDMF API [UnifiedData](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) to ensure data consistency and security.
* Drag source: component that initiates the drag operation and provides data, typically with characteristics for responding to dragging.
* Drop target: component that can receive and process drag data, and is able to perform corresponding actions based on the data being dropped.
* Drag point: point of contact between the mouse device or finger and the screen. It is used to determine whether data enters a drop target. The determination is based on whether the contact point is within the bounds of the component.

## Drag Process

The drag process encompasses both gesture-based dragging and mouse-based dragging. This distinction helps clarify the timing of callback event triggers.

### ​​Gesture-based Drag Process

​If a drag operation is triggered by a long press gesture, ArkUI checks whether the current component is draggable before initiating the drag. For components that are draggable by default ([Search](../reference/apis-arkui/arkui-ts/ts-basic-components-search.md), [TextInput](../reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md), [TextArea](../reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md), [RichEditor](../reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md), [Text](../reference/apis-arkui/arkui-ts/ts-basic-components-text.md), [Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md), [Hyperlink](../reference/apis-arkui/arkui-ts/ts-container-hyperlink.md)), ArkUI checks whether their [draggable](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#draggable) attribute is set to **true** (the system predefines the default value of this attribute for these components through [system resources](../quick-start/resource-categories-and-access.md#system-resources)); for other components, ArkUI also checks whether the **onDragStart** callback is set. If the attribute or callback is set as required, ArkUI starts dragging once the user has long pressed the component for 500 ms or longer, and displays a drag preview once the user has long pressed the component for 800 ms. When the drag operation is used together with a menu controlled by the **isShow** attribute for visibility, avoid delaying the display of the menu by 800 ms after the user's action. Otherwise, unexpected behavior may occur.

Below you can see the drag process initiated by a gesture (finger or stylus).

![en-us_image_0000001562820825](figures/en-us_image_0000001562820825.png)

### ​Mouse-based Drag Process

When a mouse device is used as the pointer, ArkUI starts dragging once the draggable component has been moved with the left mouse button by more than 1 vp.

A drag and drop can occur in a single application, or start in one application and end in another. The following callback events are provided for you to detect the dragging status and intervene in the default dragging behavior of the system.

| Callback Event| Description|
| ---------------- | ------------------------|
| [onDragStart](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragstart) | Triggered when a draggable component is dragged.<br>You can use this callback to detect the initiation of dragging behavior. You can also set the drag data and drag preview in this callback. To avoid extra performance overhead, it is recommended that the drag preview be returned in the form of a pixel map, instead of using **customBuilder**.|
| [onDragEnter](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragenter) | Triggered when the drag point enters the bounds of the component. This callback is called only when the component listens for the [onDrop](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop) event.|
| [onDragMove](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragmove) | Triggered when the drag point moves within the bounds of the component, but only if the component listens for the **onDrop** event.<br>During the movement, the **setResult** API in[DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent7) can be used to affect the system appearance in some scenarios.<br>1. Set **DragResult.DROP\_ENABLED**.<br>2. Set **DragResult.DROP\_DISABLED**.|
| [onDragLeave](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave) | Triggered when the drag point leaves the bounds of the component. This callback is called only when the component listens for the **onDrop** event.<br>By default, the **onDragLeave** callback is not called in the following cases:<br>1. An item in a parent component is dragged to one of its child components.<br>2. The layout of the drop target component overlaps that of the drag source component.<br>Since API version 12, the [setDragEventStrictReportingEnabled](../reference/apis-arkui/arkts-apis-uicontext-dragcontroller.md#setdrageventstrictreportingenabled12) API in [UIContext](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) can be used to trigger the **onDragLeave** event in a strict fashion.|
| [onDrop](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondrop) | Triggered when the dragged item is dropped on the component. The drag result must be set in this callback through the **setResult** API in **DragEvent**. Otherwise, the **getResult** API in the **onDragEnd** method of the drag source only returns the default result **DragResult.DRAG\_FAILED**.<br>This callback is where you can intervene in the default drop processing behavior. The system preferentially executes the **onDrop** callback and processes the drag data based on the **setResult** API in the callback function.<br>1. If **DragResult.DRAG\_SUCCESSFUL** is set, you need to process the data on your own; the system does not process the data.<br>2. If **DragResult.DRAG\_FAILED** is set, the system does not process the data.<br>3. If **DragResult.DRAG\_CANCELED** is set, the system does not process the data.<br>4. Setting **DragResult.DROP\_ENABLED** or **DragResult.DROP\_DISABLED** will be ignored, producing the same effect as **DragResult.DRAG\_SUCCESSFUL**.|
| [onDragEnd](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragend10) | Triggered when dragging of the component ends.|
| [onPreDrag](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#onpredrag12) | Triggered when the component enters a state prior to a drop and drop operation.<br>You can use this callback to listen for the value of [PreDragStatus](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#predragstatus12) to prepare corresponding data.<br>1. **ACTION\_DETECTING\_STATUS**: A drag gesture is being detected. Triggered when the component is long pressed for 50 ms.<br>2. **READY\_TO\_TRIGGER\_DRAG\_ACTION**: The component is ready to be dragged. Triggered when the component is long pressed for 500 ms.<br>3. **PREVIEW\_LIFT\_STARTED**: A lift animation is started. Triggered when the component is long pressed for 800 ms.<br>4. **PREVIEW\_LIFT\_FINISHED**: A lift animation is finished. Triggered at the completion of the lift animation.<br>5. **PREVIEW\_LANDING\_STARTED**: A drop animation is started. Triggered when the drop animation starts.<br>6. **PREVIEW\_LANDING\_FINISHED**: A drop animation is finished. Triggered when the drop animation ends.<br>7. **ACTION\_CANCELED\_BEFORE\_DRAG**: A drop animation is terminated. Triggered when the finger is lifted off the screen after the component enters the **READY_TO_TRIGGER_DRAG_ACTION** state.|

[DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent7) provides getters to obtain information about the drag operation. The table below lists whether the getters can return valid data in the corresponding drag callbacks.
| Callback Event| onDragStart | onDragEnter | onDragMove | onDragLeave | onDrop | onDragEnd |
| - | - | - | - | - | - | - |
| getData         |—|—|—|—| Supported|—|
| getSummary      |—| Supported| Supported| Supported| Supported|—|
| getResult       |—|—|—|—|—| Supported|
| getPreviewRect  |—|—|—|—| Supported|—|
| getVelocity/X/Y |—| Supported| Supported| Supported| Supported|—|
| getWindowX/Y    | Supported| Supported| Supported| Supported| Supported|—|
| getDisplayX/Y   | Supported| Supported| Supported| Supported| Supported|—|
| getX/Y          | Supported| Supported| Supported| Supported| Supported|—|
| behavior        |—|—|—|—|—| Supported|

[DragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent7) also provides setters to transfer information to the system, which may affect how the system handles UI or data. The table below lists the stages in the callbacks where the setters should be executed for the information to be accepted and processed by the system.
| Callback Event| onDragStart | onDragEnter | onDragMove | onDragLeave | onDrop |
| - | - | - | - | - | - |
| useCustomDropAnimation |—|—|—|—| Supported|
| setData                | Supported|—|—|—|—|
| setResult              | Supported; can be used to prevent dragging initiation by setting failed or cancel| Supported; not passed as the final result to **onDragEnd**| Supported; not passed as the final result to **onDragEnd**| Supported; not passed as the final result to **onDragEnd** | Supported; passed as the final result to **onDragEnd**|
| behavior               |—| Supported| Supported| Supported| Supported|

## Drag Preview

The drag preview is an image displayed during the drag and drop operation. It is a visual representation of the drag data, not the component itself. You can set it to any supported image that you want to display to users. The **customBuilder** or **pixelMap** object returned by the **onDragStart** callback can be used to set the drag preview displayed during dragging and moving, with a snapshot of the component being used as the default drag preview during a lift animation. The **customBuilder** or **pixelMap** object set by the **dragPreview** attribute can be used to set the drag preview during a lift animation and dragging. If no custom drag preview is set, the system uses a snapshot of the component by default.

You can set the opacity, rounded corners, shadow, and blur for the drag preview. For details, see [Drag and Drop Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md).

![pixelMap](figures/pixelMap.png)

**Constraints**:

* For a container component, if the internal content exceeds the bounds of the component due to **position**, **offset**, or other settings, the component snapshot does not capture the excess content. To show the excess content, you can expand the container scope or customize the container.
* Regardless of whether you use a custom builder or rely on the default snapshot mechanism, the snapshot process does not support transformation APIs, including [scale](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#scale) and [rotate](../reference/apis-arkui/arkui-ts/ts-universal-attributes-transformation.md#rotate).

## Drag and Drop Capability

### General Drag and Drop Adaptation

The following uses the [Image](../reference/apis-arkui/arkui-ts/ts-basic-components-image.md) component as an example to describe the basic procedure for drag and drop development and the precautions to be taken during development.

1. Make the component draggable.

   Set the **draggable** attribute to **true** and set the **onDragStart** callback function. In the callback function, you can use UDMF to set the drag data and return the custom drag preview.

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

   The gesture-based drag operation is initiated by a long press gesture bound at the underlying layer. If a long press gesture is also bound to the dragged component, gesture conflict will occur, resulting in dragging to fail. To address this issue, you can use parallel gestures.

    ```ts
    .parallelGesture(LongPressGesture().onAction(() => {
       this.getUIContext().getPromptAction().showToast({ duration: 100, message: 'Long press gesture trigger' });
    }))
    ```

2. Customize the drag preview.
   
   Prepare a pixel map for the custom drag preview within the callback triggered by [onPreDrag](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#onpredrag12) after a long press of 50 ms.
   
    ```ts
    .onPreDrag((status: PreDragStatus) => {
        if (preDragStatus == PreDragStatus.ACTION_DETECTING_STATUS) {
            this.getComponentSnapshot();
        }
    })
    ```
   
   To generate a pixel map, you can use [this.getUIContext().getComponentSnapshot().createFromBuilder()](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#createfrombuilder12).

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
        this.getUIContext().getComponentSnapshot().createFromBuilder(()=>{this.pixelMapBuilder()},
        (error: Error, pixmap: image.PixelMap) => {
            if(error){
              console.error("error: " + JSON.stringify(error))
              return;
            }
            this.pixmap = pixmap;
        })
      }
      ```

3. To make sure the [onDragLeave](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#ondragleave) event is triggered as expected, use the [setDragEventStrictReportingEnabled](../reference/apis-arkui/arkts-apis-uicontext-dragcontroller.md#setdrageventstrictreportingenabled12) API.

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

   You can set [allowDrop](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#allowdrop) to define the allowed data types for dropping, which affects the badge display. The **COPY** badge is displayed when the drag data matches the allowed data types, the **FORBIDDEN** badge is displayed when it does not, and the **MOVE** badge is displayed if **allowDrop** is not set. The following example allows only data of HYPERLINK and PLAIN\_TEXT types defined in UnifiedData.

    ```ts
    .allowDrop([uniformTypeDescriptor.UniformDataType.HYPERLINK, uniformTypeDescriptor.UniformDataType.PLAIN_TEXT])
    ```

   If the **onDrop** callback is implemented, you can control the badge display by setting [DragResult](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragresult10) to **DROP_ENABLED** in **onDragMove** and setting [DragBehavior](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragbehavior10) to **COPY** or **MOVE**. The following code forces the badge to display **MOVE** during a drag operation:

    ```ts
    .onDragMove((event) => {
        event.setResult(DragResult.DROP_ENABLED);
        event.dragBehavior = DragBehavior.MOVE;
    })
    ```

5. Receive drag data.

   Set the **onDrop** callback to handle the drag data and determine the drag result.

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

   Data transfer is managed by UDMF, which may experience latency when dealing with large data volumes. Therefore, you are advised to implement a retry mechanism with a 1500 ms delay after the initial data acquisition fails.

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
         console.error("getData failed, code: " + (e as BusinessError).code + ", message: " + (e as BusinessError).message);
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
        this.getUIContext().getPromptAction().showToast({ duration: 100, message: 'Drag Success' });
      } else if (event.getResult() === DragResult.DRAG_FAILED) {
        this.getUIContext().getPromptAction().showToast({ duration: 100, message: 'Drag failed' });
      }
    })
    ```

**Sample Code**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
import { promptAction } from '@kit.ArkUI';
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
      console.error("getData failed, code: " + (e as BusinessError).code + ", message: " + (e as BusinessError).message);
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
    this.getUIContext().getComponentSnapshot().createFromBuilder(()=>{this.pixelMapBuilder()},
      (error: Error, pixmap: image.PixelMap) => {
        if(error){
          console.error("error: " + JSON.stringify(error))
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
              this.getUIContext().getPromptAction().showToast({ duration: 100, message: 'Long press gesture trigger' });
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
                this.getUIContext().getPromptAction().showToast({ duration: 100, message: 'Drag Success' });
              } else if (event.getResult() === DragResult.DRAG_FAILED) {
                this.getUIContext().getPromptAction().showToast({ duration: 100, message: 'Drag failed' });
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
![commonDrag](figures/commonDrag.gif)

### Multi-Select Drag and Drop Adaptation

Since API version 12, the **GridItem** and **ListItem** components, which are child components of [Grid](../reference/apis-arkui/arkui-ts/ts-container-grid.md) and [List](../reference/apis-arkui/arkui-ts/ts-container-list.md), respectively, support multi-select drag and drop, which can be initiated through the **onDragStart** API.

The following uses **Grid** as an example to describe the basic procedure for multi-select drag and drop development and key considerations during development.

1. Enable multi-select drag and drop.

   Create **GridItem** child components and bind the **onDragStart** callback to them. In addition, set the **GridItem** components to be selectable.

    ```ts
    Grid() {
      ForEach(this.numbers, (idx: number) => {
        GridItem() {
          Column()
            .backgroundColor(Color.Blue)
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

   Multi-select drag and drop is disabled by default. To enable it, set **isMultiSelectionEnabled** to **true** in the **DragInteractionOptions** parameter of the [dragPreviewOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#dragpreviewoptions11) API. **DragInteractionOptions** also has the **defaultAnimationBeforeLifting** parameter, which, when set to **true**, applies a default scaling down animation as the lift animation for the component.

    ```ts
    .dragPreviewOptions({isMultiSelectionEnabled:true,defaultAnimationBeforeLifting:true})
    ```

   To maintain the selected state, set the **selected** attribute of the **GridItem** components to **true**. For example, you can use [onClick](../reference/apis-arkui/arkui-ts/ts-universal-events-click.md#onclick) to set a specific component to the selected state.

    ```ts
    .selected(this.isSelectedGrid[idx])
    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
    })
    ```

2. Optimize the multi-select drag and drop performance.

   In multi-select drag and drop scenarios, there is a clustering animation effect when multiple items are selected. This effect captures a snapshot of the selected components currently displayed on the screen, which can incur high performance costs if there are too many selected components. To save on performance, multi-select drag and drop allows for the use of a snapshot from **dragPreview** as the basis for the clustering animation.

    ```ts
    .dragPreview({
        pixelMap:this.pixmap
    })
    ```

   To obtain a snapshot of a component, you can call the [this.getUIContext().getComponentSnapshot().get()](../reference/apis-arkui/arkts-apis-uicontext-componentsnapshot.md#get12) API when the component is selected. The following shows how to use the component ID to obtain the snapshot.

    ```ts
    @State previewData: DragItemInfo[] = []
    @State isSelectedGrid: boolean[] = []
    .onClick(()=>{
        this.isSelectedGrid[idx] = !this.isSelectedGrid[idx]
        if (this.isSelectedGrid[idx]) {
            let gridItemName = 'grid' + idx
            this.getUIContext().getComponentSnapshot().get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap
                this.previewData[idx] = {
                    pixelMap:this.pixmap
                }
            })
        }
    })
    ```

3. Set the multi-select display effects.

    Use [stateStyles](../reference/apis-arkui/arkui-ts/ts-universal-attributes-polymorphic-style.md#statestyles) to set display effects for selected and unselected states for easy distinction.

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

**Sample Code**

```ts
import { image } from '@kit.ImageKit';

@Entry
@Component
struct GridEts {
  @State pixmap: image.PixelMap|undefined = undefined
  @State numbers: number[] = []
  @State isSelectedGrid: boolean[] = []
  @State previewData: DragItemInfo[] = []
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
      .backgroundColor(Color.Blue)
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
              .backgroundColor(Color.Blue)
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
              this.getUIContext().getComponentSnapshot().get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap
                this.previewData[idx] = {
                  pixelMap:this.pixmap
                }
              })
            } else {
              this.numberBadge--;
            }
          })
          // Enable multi-select and set the number badge.
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
![multiDrag](figures/multiDrag.gif)

### Custom Drop Animation Adaptation

When you need to create custom drop animations, you can disable the default system animations. Since API version 18, ArkUI provides the [executeDropAnimation](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#executedropanimation18) API, which allows you to define your own drop animations. The following provides step-by-step instructions using the **Image** component as an example, along with key points to keep in mind during development.

1. Configure drag and drop settings for the component.
   Set **draggable** to **true** and configure callbacks such as **onDragStart** and **onDragEnd**.
    ```ts
    Image($r('app.media.app_icon'))
      .width(100)
      .height(100)
      .draggable(true)
      .margin({ left: 15 ,top: 40})
      .visibility(this.imgState)
      .onDragStart((event) => {})
      .onDragEnd((event) => {})
    ```
2. Define your custom animation.

   Use the [animateTo](../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#animateto) API to create a custom animation. For example, you can change the size of the component.

    ```ts
      customDropAnimation = () => {
        this.getUIContext().animateTo({ duration: 1000, curve: Curve.EaseOut, playMode: PlayMode.Normal }, () => {
          this.imageWidth = 200;
          this.imageHeight = 200;
          this.imgState = Visibility.None;
        })
      }
    ```

3. Trigger the custom drop animation.

   Configure the **onDrop** callback to receive the drag data. Execute your custom drop animation using the [executeDropAnimation](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#executedropanimation18) API. Set [useCustomDropAnimation](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent7) to **true** to disable the default system animation.

    ```ts
      Column() {
        Image(this.targetImage)
          .width(this.imageWidth)
          .height(this.imageHeight)
      }
      .draggable(true)
      .margin({ left: 15 })
      .border({ color: Color.Black, width: 1 })
      .allowDrop([udmfType.UniformDataType.IMAGE])
      .onDrop((dragEvent: DragEvent) => {
        let records: Array<unifiedDataChannel.UnifiedRecord> = dragEvent.getData().getRecords();
        let rect: Rectangle = dragEvent.getPreviewRect();
        this.imageWidth = Number(rect.width);
        this.imageHeight = Number(rect.height);
        this.targetImage = (records[0] as udmf.Image).imageUri;
        dragEvent.useCustomDropAnimation = true;
        dragEvent.executeDropAnimation(this.customDropAnimation)
      })
    ```

**Sample Code**

```ts
import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
import { promptAction } from '@kit.ArkUI';


@Entry
@Component
struct DropAnimationExample {
  @State targetImage: string = '';
  @State imageWidth: number = 100;
  @State imageHeight: number = 100;
  @State imgState: Visibility = Visibility.Visible;

  customDropAnimation =
    () => {
      this.getUIContext().animateTo({ duration: 1000, curve: Curve.EaseOut, playMode: PlayMode.Normal }, () => {
        this.imageWidth = 200;
        this.imageHeight = 200;
        this.imgState = Visibility.None;
      })
    }

  build() {
    Row() {
      Column() {
        Image($r('app.media.app_icon'))
          .width(100)
          .height(100)
          .draggable(true)
          .margin({ left: 15 ,top: 40})
          .visibility(this.imgState)
          .onDragStart((event) => {
          })
          .onDragEnd((event) => {
            if (event.getResult() === DragResult.DRAG_SUCCESSFUL) {
              console.info('Drag Success');
            } else if (event.getResult() === DragResult.DRAG_FAILED) {
              console.info('Drag failed');
            }
          })
      }.width('45%')
      .height('100%')
      Column() {
        Text('Drag Target Area')
          .fontSize(20)
          .width(180)
          .height(40)
          .textAlign(TextAlign.Center)
          .margin(10)
          .backgroundColor('rgb(240,250,255)')
        Column() {
          Image(this.targetImage)
            .width(this.imageWidth)
            .height(this.imageHeight)
        }
        .draggable(true)
        .margin({ left: 15 })
        .border({ color: Color.Black, width: 1 })
        .allowDrop([uniformTypeDescriptor.UniformDataType.IMAGE])
        .onDrop((dragEvent: DragEvent) => {
          let records: Array<unifiedDataChannel.UnifiedRecord> = dragEvent.getData().getRecords();
          let rect: Rectangle = dragEvent.getPreviewRect();
          this.imageWidth = Number(rect.width);
          this.imageHeight = Number(rect.height);
          this.targetImage = (records[0] as unifiedDataChannel.Image).imageUri;
          dragEvent.useCustomDropAnimation = true;
          dragEvent.executeDropAnimation(this.customDropAnimation)
        })
        .width(this.imageWidth)
        .height(this.imageHeight)
      }.width('45%')
      .height('100%')
      .margin({ left: '5%' })
    }
    .height('100%')
  }
}
```
![executeDropAnimation](figures/executeDropAnimation.gif)

### Handling Large Volumes of Data

When dealing with a large number of items or large data volumes during drag and drop operations, processing all the data at once can negatively impact the user experience. The following uses the **Grid** component as an example to provide recommended practices for handling large data volumes during drag and drop operations, along with key points to keep in mind during development.

1. Enable multi-select drag and drop.

   Create **GridItem** child components and set their state to be selectable. Enable multi-select drag and drop by setting **isMultiSelectionEnabled** to **true**. Use the selected state to distinguish whether an item is selected.

    ```ts
    Grid() {
      ForEach(this.numbers, (idx: number) => {
        GridItem() {
          Column()
            .backgroundColor(Color.Blue)
            .width(50)
            .height(50)
            .opacity(1.0)
            .id('grid'+idx)
        }
        .dragPreview(this.previewData[idx])
        .dragPreviewOptions({numberBadge: this.numberBadge},{isMultiSelectionEnabled:true,defaultAnimationBeforeLifting:true})
        .selectable(true)
        .selected(this.isSelectedGrid[idx])
        .stateStyles({
          normal : this.normalStyles,
          selected: this.selectStyles
        })
        .onClick(() => {
          this.isSelectedGrid[idx] = !this.isSelectedGrid[idx];
        })
      }, (idx: string) => idx)
    }
    ```

   To maintain performance, limit the maximum number of items for multi-select drag and drop to 500.

    ```ts
    onPageShow(): void {
      let i: number = 0
      for(i=0;i<500;i++){
        this.numbers.push(i)
        this.isSelectedGrid.push(false)
        this.previewData.push({})
      }
    }
    ```
2. Add data incrementally when items are selected.

   When dealing with large data volumes, you are advised to add data records incrementally using [addRecord](../reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#addrecord) as items are selected. This avoids significant performance overhead from processing all data at once during the drag operation.

    ```ts
    .onClick(()=>{
      this.isSelectedGrid[idx] = !this.isSelectedGrid[idx];
      if (this.isSelectedGrid[idx]) {
        let data: UDC.Image = new UDC.Image();
        data.uri = '/resource/image.jpeg';
        if (!this.unifiedData) {
          this.unifiedData = new UDC.UnifiedData(data);
        }
        this.unifiedData.addRecord(data);
        this.numberBadge++;
        let gridItemName = 'grid' + idx;
        // Call the get API in componentSnapshot to obtain the component snapshot pixel map on selection.
        this.getUIContext().getComponentSnapshot().get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
          this.pixmap = pixmap;
          this.previewData[idx] = {
            pixelMap:this.pixmap
          }
        })
      } else {
        this.numberBadge--;
        for (let i=0; i<this.isSelectedGrid.length; i++) {
          if (this.isSelectedGrid[i] === true) {
            let data: UDC.Image = new UDC.Image();
            data.uri = '/resource/image.jpeg';
            if (!this.unifiedData) {
              this.unifiedData = new UDC.UnifiedData(data);
            }
            this.unifiedData.addRecord(data);
          }
        }
      }
    })
    ```

3. Prepare data in advance.

   Use the **onPreDrag** callback to receive a signal that a drag operation is about to start. If the data volume is large, prepare the data in advance.

    ```ts
    .onPreDrag((status: PreDragStatus) => {
      if (status == PreDragStatus.PREPARING_FOR_DRAG_DETECTION) {
        this.loadData()
      }
    })
    ```

4. Block the drag operation if data preparation is not complete.

   When initiating a drag operation, check whether the data is ready. If the data is not yet ready, send a [WAITING](../reference/apis-arkui/js-apis-arkui-dragController.md#dragstartrequeststatus18) signal to the system to block the drag operation. In this case, if the user performs a drag gesture, the drag preview will remain stationary until the application sends a READY signal or the maximum blocking time limit (5 seconds) is exceeded. If the data is ready, you can directly set it to [dragEvent](../reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#dragevent7). Note that when using the blocking feature, you need to save the current **dragEvent** and set the data when preparation is complete. In non-blocking scenarios, saving the current **dragEvent** is not recommended.

    ```ts
    .onDragStart((event: DragEvent) => {
      this.dragEvent = event;
      if (this.finished == false) {
        this.getUIContext().getDragController().notifyDragStartRequest(dragController.DragStartRequestStatus.WAITING);
      } else {
        event.setData(this.unifiedData);
      }
    })
    ```

**Sample Code**

```ts
import { image } from '@kit.ImageKit';
import { unifiedDataChannel as UDC } from '@kit.ArkData';
import { dragController } from '@kit.ArkUI';

@Entry
@Component
struct GridEts {
  @State pixmap: image.PixelMap|undefined = undefined
  @State numbers: number[] = []
  @State isSelectedGrid: boolean[] = []
  @State previewData: DragItemInfo[] = []
  @State numberBadge: number = 0;
  unifiedData: UnifiedData|undefined = undefined;
  timeout: number = 1
  finished: boolean = false;
  dragEvent: DragEvent|undefined;

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
    for(i=0;i<500;i++){
      this.numbers.push(i)
      this.isSelectedGrid.push(false)
      this.previewData.push({})
    }
  }

  loadData() {
    this.timeout = setTimeout(() => {
      // State after data preparation is complete.
      if (this.dragEvent) {
        this.dragEvent.setData(this.unifiedData);
      }
      this.getUIContext().getDragController().notifyDragStartRequest(dragController.DragStartRequestStatus.READY);
      this.finished = true;
    }, 4000);
  }

  @Builder
  RandomBuilder(idx: number) {
    Column()
      .backgroundColor(Color.Blue)
      .width(50)
      .height(50)
      .opacity(1.0)
  }

  build() {
    Column({ space: 5 }) {
      Button('Select All')
        .onClick(() => {
          for (let i=0;i<this.isSelectedGrid.length;i++) {
            if (this.isSelectedGrid[i] === false) {
              this.numberBadge++;
              this.isSelectedGrid[i] = true;
              let data: UDC.Image = new UDC.Image();
              data.uri = '/resource/image.jpeg';
              if (!this.unifiedData) {
                this.unifiedData = new UDC.UnifiedData(data);
              }
              this.unifiedData.addRecord(data);
              let gridItemName = 'grid' + i;
              // Call the get API in componentSnapshot to obtain the component snapshot pixel map on selection.
              this.getUIContext().getComponentSnapshot().get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap
                this.previewData[i] = {
                  pixelMap:this.pixmap
                }
              })
            }
          }
        })
      Grid() {
        ForEach(this.numbers, (idx: number) => {
          GridItem() {
            Column()
              .backgroundColor(Color.Blue)
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
            this.isSelectedGrid[idx] = !this.isSelectedGrid[idx];
            if (this.isSelectedGrid[idx]) {
              let data: UDC.Image = new UDC.Image();
              data.uri = '/resource/image.jpeg';
              if (!this.unifiedData) {
                this.unifiedData = new UDC.UnifiedData(data);
              }
              this.unifiedData.addRecord(data);
              this.numberBadge++;
              let gridItemName = 'grid' + idx;
              // Call the get API in componentSnapshot to obtain the component snapshot pixel map on selection.
              this.getUIContext().getComponentSnapshot().get(gridItemName, (error: Error, pixmap: image.PixelMap)=>{
                this.pixmap = pixmap;
                this.previewData[idx] = {
                  pixelMap:this.pixmap
                }
              })
            } else {
              this.numberBadge--;
              for (let i=0; i<this.isSelectedGrid.length; i++) {
                if (this.isSelectedGrid[i] === true) {
                  let data: UDC.Image = new UDC.Image();
                  data.uri = '/resource/image.jpeg';
                  if (!this.unifiedData) {
                    this.unifiedData = new UDC.UnifiedData(data);
                  }
                  this.unifiedData.addRecord(data);
                }
              }
            }
          })
          .onPreDrag((status: PreDragStatus) => {
            // 1. Long press notification. Callback upon 350 ms.
            if (status == PreDragStatus.PREPARING_FOR_DRAG_DETECTION) {
              // 2. The user presses and holds for a period of time without releasing, which may lead to dragging: Prepare data at this time.
              this.loadData()
            } else if (status == PreDragStatus.ACTION_CANCELED_BEFORE_DRAG) {
              // 3. The user stops the drag operation: Cancel data preparation (simulation method: cancel the timer).
              clearTimeout(this.timeout);
            }
          })
          // Triggered when the component is pressed for 500 ms or longer and moved more than 10 vp.
          .onDragStart((event: DragEvent) => {
            this.dragEvent = event;
            if (this.finished == false) {
              this.getUIContext().getDragController().notifyDragStartRequest(dragController.DragStartRequestStatus.WAITING);
            } else {
              event.setData(this.unifiedData);
            }
          })
          .onDragEnd(() => {
            this.finished = false;
          })
          .dragPreviewOptions({numberBadge: this.numberBadge},{isMultiSelectionEnabled:true,defaultAnimationBeforeLifting:true})
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



## Spring Loading (Hover Detection) Support
Spring loading, also known as drag hover detection or spring-loaded navigation, is an enhanced drag and drop capability that allows users to automatically trigger view transitions by hovering over targets during drag operations. This feature significantly improves operational efficiency and is recommended for implementation in all page transition scenarios.

> This feature is supported since API version 20.

This feature is particularly useful in the following scenarios:

- File management: Dragging a file over a folder automatically expands the folder.
- Home screen launcher: Hovering a file over an application icon automatically launches the application.

Beyond view transitions, spring loading can also activate specific UI elements. For example, when a user drags text and hovers it over a button, a text boxcan be activated. The user can then move the dragged text into this text box and release it to display search results, enabling efficient one-handed operation.

![drag spring loading example](figures/drag_springloading-01.png)

### Implementation Principle

To implement this feature, register the **onDragSpringLoading** API on a component and pass a callback to handle hover trigger notifications. Once registered, the component acts as a drop target (similar to components using the **onDrop** API) and follows the same hit detection rules: Only the topmost component under the hover position receives the drag event response.

The spring loading process follows three distinct phases: hover detection -> callback notification -> completion. If the user continues dragging before completion, spring loading is automatically canceled, triggering a cancellation notification to the application. However, if dragging is resumed during the hover detection phase before the spring loading state is entered, no cancellation notification is sent.

![drag spring loading pharse](figures/drag_springloading-02.png)

Applications receive state updates through callbacks, enabling dynamic UI adjustments.

| State  | Description                                                                                             | Recommended Action                                                                              |
| :----- | :------------------------------------------------------------------------------------------------ | :----------------------------------------------------------------------------------------- |
| BEGIN  | The user has hovered over the component long enough to start entering the spring loading state.                         | Change the background color or adjust the component size to provide visual feedback.                                  |
| UPDATE | The user holds the pointer device stationary, and the system sends periodic refresh notifications (default: 3 times).                                                | Use the notification sequence parity to determine whether to reset UI display, creating pulsating visual effects.|
| END    | The user has hovered long enough to complete the entire spring loading process.                             | Execute page transitions or view changes.                                                                  |
| CANCEL | The user continues dragging or hover detection is interrupted in BEGIN state, preventing completion of hover detection.| Reset the UI state and cancel view transition-related states and logic.                                          |

>**NOTE**
>
>1. Keeping the pointer device stationary within the same component triggers only one complete spring loading cycle. The cycle will not repeat until the pointer device leaves and re-enters the component.
>2. A component can support both spring loading and other drag events (for example, **onDrop** and **onDragEnter**).


### Triggering Customization

You can customize spring loading detection parameters to dynamically determine whether to continue triggering.

1. Trigger parameter customization

  The **onDragSpringLoading** API includes an optional **configuration** parameter, which allows you to customize settings such as detection duration, trigger intervals, and number of triggers. This enables personalized definition of spring loading trigger conditions. In most cases, however, the system's default configuration is sufficient, and no modifications are required.
  
  The **configuration** parameter must be set before detection begins. Once the system initiates the spring loading detection process, it will no longer read updates from this parameter. Yet, you can still dynamically adjust configurations during detection using the **updateConfiguration** API in the **context** object provided using the callback. These dynamic updates apply only to the current trigger and do not affect the base configurations set through the **configuration** parameter.
  
  It is recommended that you use either the default configuration or fixed parameters through the **configuration** parameter in **onDragSpringLoading**. In most cases, dynamically modifying detection parameters during spring loading is unnecessary. However, this functionality can be useful if you need to provide different user feedback based on the type of dragged data.

  >**NOTE**
  >
  >Avoid setting excessively long time intervals or overly frequent trigger counts, as these typically fail to provide meaningful user feedback.

2. Dynamic termination

  When the system detects sufficient hover duration and invokes the **onDragSpringLoading** callback, you can decide whether to allow the pending spring loading notification to proceed. This is particularly useful when you need to check the type of dragged data and align it with your service logic.

  The following pseudocode demonstrates this dynamic termination functionality:
  ```typescript
    .onDragSpringLoading((context: DragSpringLoadingContext)=>{
      // Check the current state.
      if (context.state == DragSpringLoadingState.BEGIN) {
        // Verify whether the dragged data type can be processed.
        boolean isICanHandle = false;
        let dataSummary = context?.dragInfos?.dataSummary;
        if (dataSummary != undefined) {
          for (const [type, size] of dataSummary) {
            if (type === "general.plain-text") { // Only plain text can be processed.
              isICanHandle = true;
              break;
            }
          }
        }
        // Terminate spring loading if data cannot be processed.
        if (!isICanHandle) {
          context.abort();
          return;
        }
      }
    })
  ```

3. Disabling spring loading

  If you no longer need a component to respond to spring loading, you can explicitly disable the feature by passing **null** to **onDragSpringLoading**:

  ```typescript
    .onDragSpringLoading(null)
  ```

### Example

The following example demonstrates how to implement the device search functionality using **onDragSpringLoading**, including visual feedback and view switching triggered by drag hover interactions.

1. Prepare components.

  To simplify the example, create two core components: a draggable text component and a button control. The button responds to spring loading to activate a view implemented using **bindSheet**, containing a text box for receiving dragged text and a text component for displaying search results.

  ```typescript
    build() {
      Column() {
        Column() {
          Text('Double-click to select and drag text: \n     DeviceName')
            .fontSize(30)
            .copyOption(CopyOptions.InApp) // Enable text selection and dragging when copyOption is enabled.
        }.padding({bottom:30})
  
        Button('Search Devices').width('80%').height('80vp').fontSize(30)
          .bindSheet($$this.isShowSheet, this.SheetBuilder(), {
            detents: [SheetSize.MEDIUM, SheetSize.LARGE, 600],
            preferType: SheetType.BOTTOM,
            title: { title: 'Search Devices' },
          })
      }.width('100%').height('100%')
      .justifyContent(FlexAlign.Center)
    }
  ```
2. Implement **SheetBuilder**.

  Implements the UI for the sheet.

  ```typescript
    @Builder
    SheetBuilder() {
      Column() {
        // Text box
        TextInput({placeholder: 'Drag text here'})
          .width('80%').borderWidth(1).borderColor(Color.Black)
          .onChange((value: string)=>{
            if (value.length == 0) {
              this.isSearchDone = false;
              return;
            }
            // Simplified handling: display fixed search results.
            this.isSearchDone = true;
        })
        if (this.isSearchDone) {
          Text(this.searchResult).fontSize(30)
        }
      }.width('100%').height('100%')
    }
  ```

3. Add the enter and leave response to the button.

  To provide visual feedback, add **onDragEnter** and **onDragLeave** handlers to the target component. When text is dragged over the component, the background color changes to prompt the user.

  ```typescript
    .onDragEnter(()=>{
      // Change the button color when dragged text enters the area.
      this.buttonBackgroundColor = this.reminderColor
    })
    .onDragLeave(()=>{
      // Restore the original color when text leaves the area.
      this.buttonBackgroundColor = this.normalColor
    })
  ```

4. Implement spring loading response.

  Implement a spring loading handler to process all states.

  ```typescript
  handleSpringLoading(context: dragController.SpringLoadingContext) {
      // Check the drag data type during the BEGIN state.
      if (context.state == dragController.DragSpringLoadingState.BEGIN) {
        // Add necessary checks to decide whether to terminate the process.
        return;
      }
      if (context.state == dragController.DragSpringLoadingState.UPDATE) {
        // Provide periodic visual reminders during hovering.
        return;
      }
      // Handle completion: Trigger view transition.
      if (context.state == dragController.DragSpringLoadingState.END) {
        // Activate or switch views.
        return;
      }
      // Handle cancellation: Restore the UI.
      if (context.state == dragController.DragSpringLoadingState.CANCEL) {
        // Restore the state and UI.
        return;
      }
    }
  ```

**Complete Code**

  ```typescript
  import { dragController } from '@kit.ArkUI';
  import { unifiedDataChannel, uniformTypeDescriptor } from '@kit.ArkData';
  
  @Entry
  @ComponentV2
  struct Index {
    @Local isShowSheet: boolean = false;
    private searchResult: string = 'Search results:\n  Device 1\n  Device 2\n  Device 3\n  ... ...';
    @Local isSearchDone: boolean = false;
    private  reminderColor: Color = Color.Green;
    private normalColor: Color = Color.Blue;
    @Local buttonBackgroundColor: Color = this.normalColor;
  
    @Builder
    SheetBuilder() {
      Column() {
        // Text box
        TextInput({placeholder: 'Drag text here'})
          .width('80%').borderWidth(1).borderColor(Color.Black).padding({bottom: 5})
          .onChange((value: string)=>{
            if (value.length == 0) {
              this.isSearchDone = false;
              return;
            }
            // Simplified handling: display fixed search results.
            this.isSearchDone = true;
          })
        if (this.isSearchDone) {
          Text(this.searchResult).fontSize(20).textAlign(TextAlign.Start).width('80%')
        }
      }.width('100%').height('100%')
    }
  
    // Check whether the dragged data contains plain text.
    checkDataType(dataSummary: unifiedDataChannel.Summary | undefined): boolean {
      let summary = dataSummary?.summary;
      if (summary == undefined) {
        return false;
      }
  
      let dataSummaryObjStr: string = JSON.stringify(summary);
      let dataSummaryArray: Array<Array<string>> = JSON.parse(dataSummaryObjStr);
      let isDataTypeMatched: boolean = false;
      dataSummaryArray.forEach((record: Array<string>) => {
        if (record[0] == 'general.plain-text') {
          isDataTypeMatched = true;
        }
      });
      return isDataTypeMatched;
    }
  
    // Handle the BEGIN state.
    handleBeginState(context: SpringLoadingContext): boolean {
      // Verify whether the dragged data type can be processed.
      if (this.checkDataType(context?.dragInfos?.dataSummary)) {
        return true;
      }
      // Terminate spring loading if data cannot be processed.
      context.abort();
      return false;
    }
  
    // Spring Loading handler.
    handleSpringLoading(context: SpringLoadingContext) {
      // Check the drag data type during the BEGIN state.
      if (context.state == dragController.DragSpringLoadingState.BEGIN) {
        if (this.handleBeginState(context)) {
          // The visual feedback is already provided in onDragEnter. When the spring loading state is entered, restore the UI to prompt the user to remain stationary.
          this.buttonBackgroundColor = this.normalColor;
        }
        return;
      }
      if (context.state == dragController.DragSpringLoadingState.UPDATE) {
        // Alternate the UI reminder color based on the notification sequence parity.
        if (context.currentNotifySequence % 2 != 0) {
          this.buttonBackgroundColor = this.reminderColor;
        } else {
          this.buttonBackgroundColor = this.normalColor;
        }
        return;
      }
      // Handle completion: Trigger view transition.
      if (context.state == dragController.DragSpringLoadingState.END) {
        this.isShowSheet = true;
        return;
      }
      // Handle cancellation: Restore the UI.
      if (context.state == dragController.DragSpringLoadingState.CANCEL) {
        this.buttonBackgroundColor = this.normalColor;
        return;
      }
    }
  
    build() {
      Column() {
        Column() {
          Text('Double-click to select and drag text: \n     DeviceName')
            .fontSize(30)
            .copyOption(CopyOptions.InApp) // Enable text selection and dragging when copyOption is enabled.
        }.padding({bottom:30})
  
        Button('Search Devices').width('80%').height('80vp').fontSize(30)
          .bindSheet($$this.isShowSheet, this.SheetBuilder(), {
            detents: [SheetSize.MEDIUM, SheetSize.LARGE, 600],
            preferType: SheetType.BOTTOM,
            title: { title: 'Search Devices' },
          })
          .allowDrop([uniformTypeDescriptor.UniformDataType.PLAIN_TEXT])
          .backgroundColor(this.buttonBackgroundColor)
          .onDragEnter(()=>{
            // Change the button color when dragged text enters the area.
            this.buttonBackgroundColor = this.reminderColor
          })
          .onDragLeave(()=>{
            // Restore the original color when text leaves the area.
            this.buttonBackgroundColor = this.normalColor
          })
          .onDragSpringLoading((context: SpringLoadingContext)=>{
            this.handleSpringLoading(context);
          })
      }.width('100%').height('100%')
      .justifyContent(FlexAlign.Center)
    }
  }
```


<!--RP1--><!--RP1End-->
<!--no_check-->