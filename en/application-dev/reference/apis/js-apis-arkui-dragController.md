# @ohos.arkui.dragController (DragController)

The **dragController** module provides APIs for initiating drag actions. When receiving a gesture event, such as a touch or long-press event, an application can initiate a drag action and carry drag information therein.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](./js-apis-arkui-UIContext.md#uicontext).
> Since API version 10, you can use the [getDragController](./js-apis-arkui-UIContext.md#getdragcontroller11) API in **UIContext** to obtain the **DragController** object associated with the current UI context.
> You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.

## Modules to Import

```ts
import dragController from "@ohos.arkui.dragController";
```

## dragController.executeDrag

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo, callback: AsyncCallback&lt; {event: DragEvent, extraParams: string}&gt;): void

Initiates a drag action, with the object to be dragged and the drag information passed in. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                            |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo) | Yes  | Object to be dragged.<br>**NOTE**<br>The global builder is not supported.|
| dragInfo | [DragInfo](#draginfo)                                        | Yes  | Drag information.                      |
| callback | [AsyncCallback](./js-apis-base.md#asynccallback)&lt;{event: [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent), extraParams: string}&gt; | Yes  | Callback used to return the result.<br>- **event**: drag event information that includes only the drag result.<br>- **extraParams**: extra information about the drag event.         |

**Error codes**

| ID| Error Message     |
| -------- | ------------- |
| 401      | if the parameters checking failed. |
| 100001   | if some internal handling failed. |

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

**Error codes**

| ID| Error Message     |
| -------- | ------------- |
| 401      | if the parameters checking failed. |
| 100001   | if some internal handling failed. |

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
              let pb:CustomBuilder = ():void=>{this.PixmapBuilder()}
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
| touchPoint<sup>11+</sup>    | [TouchPoint](../arkui-ts/ts-types.md#touchpoint11)  | No  | Coordinates of the touch point. If this parameter is not set, the touch point is centered.     |
| previewOptions<sup>11+</sup>| [DragPreviewOptions](../arkui-ts/ts-universal-attributes-drag-drop.md#dragpreviewoptions11)                                | No  | Custom configuration of the drag preview.|

## DragStatus<sup>11+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Describes the dragging start and end states.

| Name         | Value                                                  | Description                                    |
| -----------   | ------------------------------------------------------| ---------------------------------------- |
| STARTED       | 0                                                  | Dragging is started.        |
| ENDED        | 1                                                  | Dragging ends.              |

## DragAndDropInfo<sup>11+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Provides the data reported when the state changes during dragging.

| Name         | Type                                                  | Mandatory| Description                                    |
| -----------   | ------------------------------------------------------ | ---- | ---------------------------------------- |
| status       | DragStatus                                                 | Yes  | Current dragging state (started or ended).        |
| event        | [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent) | No  | Drag event corresponding to the current state.              |
| extraParams| string                                                 | No  | Additional information about the drag action. Not supported currently.|

## DragAction<sup>11+</sup>

Implements a **DragAction** object to subscribe to drag state changes and start the drag service.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### startDrag<sup>11+</sup>

startDrag(): Promise&lt;void&gt;

Starts the drag service. This API uses a promise to return the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Error codes**

| ID| Error Message     |
| -------- | ------------- |
| 100001   | if some internal handling failed. |

**Example**
```ts
dragAction.startDrag().then(()=>{}).catch((err:Error)=>{
  console.log("start drag Error:" + err.message);
})
```

### on('statusChange')<sup>11+</sup>

on(type: 'statusChange', callback: Callback&lt;[DragAndDropInfo](#draganddropinfo11)&gt;): void

Subscribes to drag state changes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name    | Type | Mandatory   | Description            |
| ------ | ------ | ------- | ---------------- |
|  type  | string | Yes     | Event type. The value is fixed at **'statusChange'**, which indicates the drag state change event.|
|  callback  | Callback&lt;[DragAndDropInfo](#draganddropinfo11)&gt; | Yes     | Callback used to return a [DragAndDropInfo](#draganddropinfo11) instance.|

**Example**
```ts
dragAction.on('statusChange', (dragAndDropInfo)=>{
  console.info("Register to listen on drag status", JSON.stringify(dragAndDropInfo);
})
```

### off('statusChange')<sup>11+</sup>

 off(type: 'statusChange', callback?: Callback&lt;[DragAndDropInfo](#draganddropinfo11)&gt;): void

Unsubscribes from drag state changes.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name    | Type | Mandatory   | Description            |
| ------ | ------ | ------- | ---------------- |
|  type  | string | Yes     | Event type. The value is fixed at **'statusChange'**, which indicates the drag state change event.|
|  callback  | Callback&lt;[DragAndDropInfo](#draganddropinfo11)&gt; | No     | Callback used to return a [DragAndDropInfo](#draganddropinfo11) instance. If this parameter is not set, this API unsubscribes from all callbacks corresponding to **type**.|

**Example**
```ts
dragAction.off('statusChange', (dragAndDropInfo)=>{
  console.info("Cancel listening on drag status", JSON.stringify(dragAndDropInfo)
})
```

## dragController.createDragAction<sup>11+</sup>

createDragAction(customArray: Array&lt;CustomBuilder \| DragItemInfo&gt;, dragInfo: DragInfo): DragAction

Creates a **DragAction** object, by explicitly specifying one or more drag previews, drag data, and information about the dragged object. If the drag initiated by a **DragAction** object is not complete, no new **DragAction** object can be created, and calling this API will throw an exception.

**NOTE**<br>You are advised to control the number of drag previews. If too many previews are passed in, the drag efficiency may be affected.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                                                        | Mandatory| Description                            |
| --------      | ------------------------------------------------------------ | ---- | -------------------------------- |
| customArray  | Array&lt;[CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo)&gt; | Yes  | Object to be dragged.|
| dragInfo | [DragInfo](#draginfo)                                        | Yes  | Drag information.                      |

**Return value**

| Type                                                  | Description              |
| ------------------------------------------------------ | ------------------ |
| [DragAction](#dragaction11)| **DragAction** object, which is used to subscribe to drag state changes and start the drag service.|

**Error codes**

| ID| Error Message     |
| -------- | ------------- |
| 401      | Invalid input parameter |
| 100001   | If some internal handling failed |

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
  private dragAction: dragController.DragAction|null = null;
  customBuilders:Array<CustomBuilder | DragItemInfo> = new Array<CustomBuilder | DragItemInfo>();
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

      Column() {
        Text ("Test")
      }
      .width(100)
      .height(100)
      .backgroundColor(Color.Red)

      Button('Drag Multiple Objects').onTouch((event?:TouchEvent) => {
        if(event){
          if (event.type == TouchType.Down) {
            console.log("muti drag Down by listener");
            this.customBuilders.splice(0, this.customBuilders.length);
            this.customBuilders.push(()=>{this.DraggingBuilder()});
            this.customBuilders.push(()=>{this.DraggingBuilder()});
            this.customBuilders.push(()=>{this.DraggingBuilder()});
            let text = new UDC.Text()
            let unifiedData = new UDC.UnifiedData(text)
            let dragInfo: dragController.DragInfo = {
              pointerId: 0,
              data: unifiedData,
              extraParams: ''
            }
            try{
              this.dragAction = dragController.createDragAction(this.customBuilders, dragInfo)
            if(!this.dragAction){
              console.log("listener dragAction is null");
              return
            }
            this.dragAction.on('statusChange', (dragAndDropInfo)=>{
              if (dragAndDropInfo.status == dragController.DragStatus.STARTED) {
                console.log("drag has start");
              } else if (dragAndDropInfo.status == dragController.DragStatus.ENDED){
                console.log("drag has end");
                if (!this.dragAction) {
                  return
                }
                this.dragAction.off('statusChange')
              }
            })
            this.dragAction.startDrag().then(()=>{}).catch((err:Error)=>{
              console.log("start drag Error:" + err.message);
            })
            } catch(err) {
              console.log("create dragAction Error:" + err.message);
            }
          }
        }
      }).margin({top:20})
    }
  }
}
```
## AnimationOptions<sup>11+</sup>

**System capability**: SystemCapability.ArkUI.ArkUI.Full

Defines the attributes required for initiating a drag action and information carried in the dragging process.

| Name       | Type                                                  | Mandatory| Description                                    |
| ----------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| duration    | number                                                 | No  | Animation duration, in ms.<br>Default value: **1000**<br>**NOTE**<br>- If this parameter is set to a value less than 0, the value **0** is used.<br>- Floating-point values will be rounded down to integers. For example, if the value set is 1.2, **1** will be used.|
| curve       | [Curve](../arkui-ts/ts-appendix-enums.md#curve) \| [ICurve](../apis/js-apis-curve.md#icurve) | No   | Animation curve.<br>Default value: **Curve.EaseInOut**|                          |

## dragController.getDragPreview<sup>11+</sup>

getDragPreview(): DragPreview

Obtains the **DragPreview** object, which represents the preview displayed during a drag.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type       | Description                                           |
| ------------| ------------------------------------------------|
| DragPreview | **DragPreview** object. It provides the API for setting the preview style. It does not work in the **OnDrop** and **OnDragEnd** callbacks.|

**Example**

For details, see [animate](#animate11).

## DragPreview<sup>11+</sup>

Implements a **DragPreview** object. This API does not work in the **OnDrop** and **OnDragEnd** callbacks.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### setForegroundColor<sup>11+</sup>

setForegroundColor(color: ResourceColor): void

Sets the mask color of the drag preview. This API does not work in the **OnDrop** and **OnDragEnd** callbacks.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                            | Mandatory| Description                    |
| -------- | -------------------------------- | ---- | ------------------------ |
| color    | [ResourceColor](../arkui-ts/ts-types.md#resourcecolor) | Yes  |      Mask color of the drag preview.                   |

**Example**

For details, see [animate](#animate11).

  ### animate<sup>11+</sup>

animate(options: AnimationOptions, handler: () => void): void

Applies an animation to the background mask color changes. This API does not work in the **OnDrop** and **OnDragEnd** callbacks.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type                            | Mandatory| Description                              |
| -------- | -------------------------------- | ---- | -----------------------------------|
| options  | [AnimationOptions](#animationoptions11)                | Yes  | Animation settings.                          |
| handler  | () => void                         | Yes  | Callback used to change attributes such as the background mask color. |

**Example**

1. In the **EntryAbility.ets** file, obtain the UI context and save it to LocalStorage.
  ```ts
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';
import { UIContext } from '@ohos.arkui.UIContext';

let uiContext: UIContext;
let localStorage: LocalStorage = new LocalStorage('uiContext');

export default class EntryAbility extends UIAbility {
  storage: LocalStorage = localStorage;
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
  }

  onDestroy(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
  }

  onWindowStageCreate(windowStage: window.WindowStage): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onWindowStageCreate');

    windowStage.loadContent('pages/Index', (err, data) => {
      if (err.code) {
        hilog.error(0x0000, 'testTag', 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
        return;
      }
      hilog.info(0x0000, 'testTag', 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
      windowStage.getMainWindow((err, data) =>
      {
        if (err.code) {
          hilog.error(0x0000, 'Failed to abtain the main window. Cause:' + err.message, '');
          return;
        }
        let windowClass: window.Window = data;
        uiContext = windowClass.getUIContext();
        this.storage.setOrCreate<UIContext>('uiContext', uiContext);
      })
    });
  }
  ```
2. In the **Index.ets** file, call **LocalStorage.getShared()** to obtain the UI context and then use the **DragController** object obtained to perform subsequent operations.
  ```ts

import UDC from '@ohos.data.unifiedDataChannel';
import hilog from '@ohos.hilog';
import dragController from "@ohos.arkui.dragController"
import componentSnapshot from '@ohos.arkui.componentSnapshot';
import image from '@ohos.multimedia.image';
import curves from '@ohos.curves';
import { BusinessError } from '@ohos.base';
import { UIContext } from '@ohos.arkui.UIContext';


let storages = LocalStorage.getShared();

@Entry(storages)
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
      Button ('Drag Here').onDragEnter(() => {
          try {
            let uiContext: UIContext = storages.get<UIContext>('uiContext') as UIContext;
            let previewObj: dragController.DragPreview = uiContext.getDragController().getDragPreview();
            let foregroundColor: ResourceColor = Color.Green;

            let previewAnimation: dragController.AnimationOptions = {
              curve: curves.cubicBezierCurve(0.2,0,0,1),
            }
            previewObj.animate(previewAnimation, () => {
              previewObj.setForegroundColor(foregroundColor);
            });
          } catch (error) {
            let msg = (error as BusinessError).message;
            let code = (error as BusinessError).code;
            hilog.error(0x0000, `show error code is ${code}, message is ${msg}`, '');
          }
      })
      .onDrop(() => {

      })
      Button ('Drag').onTouch ((event?:TouchEvent) => {
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
              dragController.executeDrag(() => {
                this.DraggingBuilder()
              }, dragInfo, (err , eve) => {
                hilog.info(0x0000, `ljx ${JSON.stringify(err)}`, '')
                if (eve && eve.event) {
                  if (eve.event.getResult() == DragResult.DRAG_SUCCESSFUL) {
                    hilog.info(0x0000, 'success', '');
                  } else if (eve.event.getResult() == DragResult.DRAG_FAILED) {
                    hilog.info(0x0000, 'failed', '');
                  }
                }
            })
          }
        }
      }).margin({top:100})
    }
    .width('100%')
    .height('100%')
  }
}
