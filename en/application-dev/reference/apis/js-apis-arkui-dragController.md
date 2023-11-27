# @ohos.arkui.dragController (DragController)

The **dragController** module provides APIs for initiating drag actions. When receiving a gesture event, such as a click or long-press event, an application can initiate a drag action and carry drag information therein.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.


## Modules to Import

```ts
import dragController from "@ohos.arkui.dragController";
```

## dragController.executeDrag

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo, callback: AsyncCallback&lt;{event: DragEvent, extraParams: string}&gt;): void

Initiates a drag action, with the object to be dragged and the drag information passed in. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                            |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo) | Yes  | Object to be dragged.|
| dragInfo | [DragInfo](#draginfo)                                        | Yes  | Drag information.                      |
| callback | [AsyncCallback](./js-apis-base.md#asynccallback)&lt;{event: [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent), extraParams: string}&gt; | Yes  | Callback used to return the result.<br>- **event**: drag event information that includes only the drag result.<br>- **extraParams**: extra information about the drag event.         |

**Example**

```ts
import dragController from "@ohos.arkui.dragController"
import UDC from '@ohos.data.unifiedDataChannel';

@Entry
@Component
struct DragControllerPage {
  @Builder DraggingBuilder() {
    Column() {
      Text("DraggingBuilder")
    }
    .width(100)
    .height(100)
    .backgroundColor(Color.Blue)
  }

  build() {
    Column() {
      Button('touch to execute drag')
        .onTouch((event?:TouchEvent) => {
          if(event){
            if (event.type == TouchType.Down) {
              let text = new UDC.Text()
              let unifiedData = new UDC.UnifiedData(text)

              let dragInfo: dragController.DragInfo = {
                pointerId: 0,
                data: unifiedData,
                extraParams: ''
              }
              class tmp{
                event:DragEvent|undefined = undefined
                extraParams:string = ''
              }
              let eve:tmp = new tmp()
              dragController.executeDrag(()=>{this.DraggingBuilder()}, dragInfo, (err, eve) => {
                if(eve.event){
                  if (eve.event.getResult() == DragResult.DRAG_SUCCESSFUL) {
                  // ...
                  } else if (eve.event.getResult() == DragResult.DRAG_FAILED) {
                  // ...
                  }
                }
              })
            }
          }
        })
    }
  }
}
```

## dragController.executeDrag

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo): Promise&lt;{event: DragEvent, extraParams: string}&gt;

Initiates a drag action, with the object to be dragged and the drag information passed in. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                            |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo) | Yes  | Object to be dragged.|
| dragInfo | [DragInfo](#draginfo)                                        | Yes  | Drag information.                      |

**Return value**

| Type                                                  | Description              |
| ------------------------------------------------------ | ------------------ |
| Promise&lt;{event: [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent), extraParams: string}&gt; | Promise used to return the result.<br>- **event**: drag event information that includes only the drag result.<br>- **extraParams**: extra information about the drag event.|

**Example**

```ts
import dragController from "@ohos.arkui.dragController"
import componentSnapshot from '@ohos.arkui.componentSnapshot';
import image from '@ohos.multimedia.image';
import UDC from '@ohos.data.unifiedDataChannel';

@Entry
@Component
struct DragControllerPage {
  @State pixmap: image.PixelMap|null = null

  @Builder DraggingBuilder() {
    Column() {
      Text("DraggingBuilder")
    }
    .width(100)
    .height(100)
    .backgroundColor(Color.Blue)
  }

  @Builder PixmapBuilder() {
    Column() {
      Text("PixmapBuilder")
    }
    .width(100)
    .height(100)
    .backgroundColor(Color.Blue)
  }

  build() {
    Column() {
      Button('touch to execute drag')
        .onTouch((event?:TouchEvent) => {
          if(event){
            if (event.type == TouchType.Down) {
              let text = new UDC.Text()
              let unifiedData = new UDC.UnifiedData(text)

              let dragInfo: dragController.DragInfo = {
                pointerId: 0,
                data: unifiedData,
                extraParams: ''
              }
              let pb:CustomBuilder =()=>{():void=>{this.PixmapBuilder()}}
              componentSnapshot.createFromBuilder(pb).then((pix: image.PixelMap) => {
                this.pixmap = pix;
                let dragItemInfo: DragItemInfo = {
                  pixelMap: this.pixmap,
                  builder: ()=>{this.DraggingBuilder()},
                  extraInfo: "DragItemInfoTest"
                }

                class tmp{
                  event:DragResult|undefined = undefined
                  extraParams:string = ''
                }
                let eve:tmp = new tmp()
                dragController.executeDrag(dragItemInfo, dragInfo)
                  .then((eve) => {
                    if (eve.event.getResult() == DragResult.DRAG_SUCCESSFUL) {
                      // ...
                    } else if (eve.event.getResult() == DragResult.DRAG_FAILED) {
                      // ...
                    }
                  })
                  .catch((err:Error) => {
                  })
              })
            }
          }
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

## DragInfo

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Defines the attributes required for initiating a drag action and information carried in the dragging process.

| Name       | Type                                                  | Mandatory| Description                                    |
| ----------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| pointerId   | number                                                 | Yes  | ID of the touch point on the screen when dragging is started.        |
| data        | [unifiedDataChannel.UnifiedData](js-apis-data-unifiedDataChannel.md#unifieddata) | No  | Data carried in the dragging process.              |
| extraParams | string                                                 | No  | Additional information about the drag action. Not supported currently.|
