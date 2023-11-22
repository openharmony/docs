# @ohos.arkui.dragController    
本模块提供发起主动拖拽的能力，当应用接收到点击或长按等事件时可以主动发起拖拽的动作，并在其中携带拖拽信息。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import dragController from '@ohos.arkui.dragController'    
```  
    
## DragInfo    
拖拽发起后跟手效果所拖拽的对象。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| pointerId | number | false | true | 设置启动拖拽时屏幕上触摸点的Id。 |  
| data | unifiedDataChannel.UnifiedData | false | false | 设置拖拽过程中携带的数据。 |  
| extraParams | string | false | false | 设置拖拽事件额外信息，具体功能暂未实现。 |  
    
## executeDrag  
 **调用形式：**     
    
- executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo, callback: AsyncCallback\<{     event: DragEvent, extraParams: string   }>): void    
起始版本： 10    
- executeDrag(custom: CustomBuilder | DragItemInfo, dragInfo: DragInfo): Promise\<{     event: DragEvent, extraParams: string   }>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| custom | string | true | 拖拽发起后跟手效果所拖拽的对象。 |  
| dragInfo | DragInfo | true | 拖拽信息。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 拖拽结束返回结果的回调。 |  
| Promise<{  
    event: DragEvent, extraParams: string  
  }> |  |  
    
 **示例代码1：**   
示例(callback):  
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
  
    
 **示例代码2：**   
示例(Promise):  
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
  
