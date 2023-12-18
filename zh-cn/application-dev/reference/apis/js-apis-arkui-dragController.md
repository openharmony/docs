# @ohos.arkui.dragController (DragController)

本模块提供发起主动拖拽的能力，当应用接收到触摸或长按等事件时可以主动发起拖拽的动作，并在其中携带拖拽信息。

> **说明：**
>
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 示例效果请以真机运行为准，当前 IDE 预览器不支持。


## 导入模块

```ts
import dragController from "@ohos.arkui.dragController";
```

## dragController.executeDrag

executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo, callback: AsyncCallback&lt; {event: DragEvent, extraParams: string}&gt;): void

主动发起拖拽能力，传入拖拽发起后跟手效果所拖拽的对象以及携带拖拽信息。通过回调返回结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明) | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [DragInfo](#draginfo)                                        | 是   | 拖拽信息。                       |
| callback | [AsyncCallback](./js-apis-base.md#asynccallback)&lt;{event: [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent说明), extraParams: string}&gt; | 是   | 拖拽结束返回结果的回调<br/>- event：拖拽事件信息，仅包括拖拽结果。<br/>- extraParams：拖拽事件额外信息。          |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | if the parameters checking failed. |
| 100001   | if some internal handling failed. |

**示例：**

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

主动发起拖拽能力，传入拖拽发起后跟手效果所拖拽的对象以及携带拖拽信息。通过Promise返回结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------- |
| custom   | [CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明) | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [DragInfo](#draginfo)                                        | 是   | 拖拽信息。                       |

**返回值：** 

| 类型                                                   | 说明               |
| ------------------------------------------------------ | ------------------ |
| Promise&lt;{event: [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent说明), extraParams: string}&gt; | 拖拽结束返回结果的回调<br/>- event：拖拽事件信息，仅包括拖拽结果。<br/>- extraParams：拖拽事件额外信息。 |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | if the parameters checking failed. |
| 100001   | if some internal handling failed. |

**示例：**

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

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

发起拖拽所需要的属性和拖拽时携带的信息。

| 名称        | 类型                                                   | 必填 | 说明                                     |
| ----------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| pointerId   | number                                                 | 是   | 设置启动拖拽时屏幕上触摸点的Id。         |
| data        | [unifiedDataChannel.UnifiedData](js-apis-data-unifiedDataChannel.md#unifieddata) | 否   | 设置拖拽过程中携带的数据。               |
| extraParams | string                                                 | 否   | 设置拖拽事件额外信息，具体功能暂未实现。 |
| touchPoint<sup>11+</sup>    | [TouchPoint](../arkui-ts/ts-types.md#touchpoint)  | 否   | 配置跟手点坐标，不配置时，默认居中。      |
| previewOptions<sup>11+</sup>| DragPreviewOptions                                     | 否   | 拖拽背板自定义配置。 |

## DragStatus<sup>11+</sup>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

拖拽开始和结束状态。

| 名称          | 数值                                                   | 说明                                     |
| -----------   | ------------------------------------------------------| ---------------------------------------- |
| STARTED       | 0                                                  | 拖拽已成功发起。         |
| ENDED        | 1                                                  | 拖拽结束。               |

## DragAndDropInfo<sup>11+</sup>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

拖拽过程中监听到status改变时上报的数据。

| 名称          | 类型                                                   | 必填 | 说明                                     |
| -----------   | ------------------------------------------------------ | ---- | ---------------------------------------- |
| status       | DragStatus                                                 | 是   | 当前拖拽状态（启动和结束）。         |
| event        | [DragEvent](../arkui-ts/ts-universal-events-drag-drop.md#dragevent说明) | 否   | 当前状态所对应的拖拽事件。               |
| extraParams| string                                                 | 否   | 设置拖拽事件额外信息，具体功能暂未实现。 |

## DragAction<sup>11+</sup>

监听状态改变，启动拖拽服务的对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### startDrag<sup>11+</sup>

startDrag()：Promise&lt;void&gt;

启动拖拽服务，返回Promise对象，回调启动成功和失败的结果。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**示例：**
```ts
dragAction.startDrag().then(()=>{}).catch((err:Error)=>{
  console.log("start drag Error:" + err.message);
})
```

### on('statusChange')<sup>11+</sup>

on(type: 'statusChange', callback: Callback&lt;[DragAndDropInfo](#draganddropinfo)&gt;): void

注册监听拖拽状态改变事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 名称     | 类型  | 必填    | 描述             |
| ------ | ------ | ------- | ---------------- |
|  type  | string | 是      | 监听事件，固定为'statusChange'，即注册监听拖拽状态改变事件。|
|  callback  | Callback&lt;[DragAndDropInfo](#draganddropinfo)&gt; | 是      | 回调函数，返回当前的[DragAndDropInfo](#draganddropinfo)组件状态。|

**示例：**
```ts
dragAction.on('statusChange', (dragAndDropInfo)=>{
  console.info("Register to listen on drag status", JSON.stringify(dragAndDropInfo);
})
```

### off('statusChange')<sup>11+</sup>

 off(type: 'statusChange', callback: Callback&lt;[DragAndDropInfo](#draganddropinfo)&gt;): void

取消注册监听拖拽状态改变事件。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 名称     | 类型  | 必填    | 描述             |
| ------ | ------ | ------- | ---------------- |
|  type  | string | 是      | 监听事件，固定为'statusChange'，即取消监听拖拽状态改变事件。|
|  callback  | Callback&lt;[DragAndDropInfo](#draganddropinfo)&gt; | 是      | 回调函数，返回当前的[DragAndDropInfo](#draganddropinfo)组件状态。|

**示例：**
```ts
dragAction.off('statusChange', (dragAndDropInfo)=>{
  console.info("Cancel listening on drag status", JSON.stringify(dragAndDropInfo)
})
```

## dragController.createDragAction<sup>11+</sup>

createDragAction(customArray: Array&lt;CustomBuilder \| DragItemInfo&gt;, dragInfo: DragInfo): DragAction

创建拖拽的Action对象，需要显式指定拖拽背板图(可多个)，以及拖拽的数据，跟手点等信息；当通过一个已创建的 Action 对象发起的拖拽未结束时，无法再次创建新的 Action 对象，接口会抛出异常。

**说明：** 建议控制传递的拖拽背板数量，传递过多容易导致拖起的效率问题。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                             |
| --------      | ------------------------------------------------------------ | ---- | -------------------------------- |
| customArray  | Array&lt;[CustomBuilder](../arkui-ts/ts-types.md#custombuilder8) \| [DragItemInfo](../arkui-ts/ts-universal-events-drag-drop.md#dragiteminfo说明)&gt; | 是   | 拖拽发起后跟手效果所拖拽的对象。 |
| dragInfo | [DragInfo](#draginfo)                                        | 是   | 拖拽信息。                       |

**返回值：** 

| 类型                                                   | 说明               |
| ------------------------------------------------------ | ------------------ |
| [DragAction](#dragaction11)| 创建拖拽Action对象，主要用于后面实现注册监听拖拽状态改变事件和启动拖拽服务。 |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Invalid input parameter |
| 100001   | Internal error |

**示例：**

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
        Text("测试")
      }
      .width(100)
      .height(100)
      .backgroundColor(Color.Red)

      Button('多对象dragAction customBuilder拖拽').onTouch((event?:TouchEvent) => {
        if(event){
          if (event.type == TouchType.Down) {
            console.log("muti drag Down by listener");
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
                this.customBuilders.splice(0, this.customBuilders.length)
                this.dragAction.off('statusChange')
              }
            })
            this.dragAction.startDrag().then(()=>{}).catch((err:Error)=>{
              console.log("start drag Error:" + err.message);
            })
          }
        }
      }).margin({top:20})
    }
  }
}
```
## AnimationOptions<sup>11+</sup>

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

发起拖拽所需要的属性和拖拽时携带的信息。

| 名称        | 类型                                                   | 必填 | 说明                                     |
| ----------- | ------------------------------------------------------ | ---- | ---------------------------------------- |
| duration    | number                                                 | 否   | 动画持续时间，单位为毫秒。<br/>默认值：1000<br/>**说明：**<br/>-&nbsp;设置小于0的值时按0处理。<br/>-&nbsp;设置浮点型类型的值时，向下取整。例如，设置值为1.2，按照1处理。|
| curve       |&nbsp;[Curve](../arkui-ts/ts-appendix-enums.md#curve)&nbsp;\|&nbsp;[ICurve](../apis/js-apis-curve.md#icurve) | 否    | 设置动画曲线。<br/>默认值：Curve.EaseInOut|                          |

## dragController.getDragPreview<sup>11+</sup>

getDragPreview(): DragPreview

返回一个代表拖拽背板的对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型        | 说明                                            |
| ------------| ------------------------------------------------|
| DragPreview | 一个代表拖拽背板的对象，提供背板样式设置的接口。 |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 401      | Invalid input parameter |
| 100001   | Internal error |

**示例：**

请参考[animate](#animate11)

## DragPreview<sup>11+</sup>

拖拽背板的对象。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setForegroundColor<sup>11+</sup>

setForegroundColor(color: ResourceColor): void

设置背板蒙版颜色。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                             | 必填 | 说明                     |
| -------- | -------------------------------- | ---- | ------------------------ |
| color    | [ResourceColor](../arkui-ts/ts-types.md#resourcecolor) | 是   |      背板蒙版颜色。                    |

**示例：**

请参考[animate](#animate11)

  ### animate<sup>11+</sup>

animate(options: AnimationOptions, handler: () => void): void

设置背板蒙版颜色变化动效。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型                             | 必填 | 说明                               |
| -------- | -------------------------------- | ---- | -----------------------------------|
| options  | [AnimationOptions](#animationoptions11)                | 是   | 动效参数                           |
| handler  | () => void                         | 是   | 用于修改背板蒙版颜色等属性的回调方法。  |

**示例：**

  ```ts

import UDC from '@ohos.data.unifiedDataChannel';
import dragController from "@ohos.arkui.dragController"
import componentSnapshot from '@ohos.arkui.componentSnapshot';
import image from '@ohos.multimedia.image';
import curves from '@ohos.curves';
import { BusinessError } from '@ohos.base';

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
      Button('拖拽至此处').onDragEnter(() => {
          try {
            let previewObj: dragController.DragPreview = dragController.getDragPreview();
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
            console.error(`show error code is ${code}, message is ${msg}`);
          }
      })
      .onDrop(() => {

      })
      Button('拖起').onTouch((event?:TouchEvent) => {
        if(event){
          if (event.type == TouchType.Down) {
            let text = new UDC.Text()
            let unifiedData = new UDC.UnifiedData(text)
            console.log("one drag Down");
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
            console.log(`ljx ${JSON.stringify(err)}`)
                if (eve && eve.event) {
                  if (eve.event.getResult() == DragResult.DRAG_SUCCESSFUL) {
                    console.log('success');
                  } else if (eve.event.getResult() == DragResult.DRAG_FAILED) {
                    console.log('failed');
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
