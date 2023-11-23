# @ohos.arkui.componentSnapshot    
本模块提供获取组件截图的能力，包括已加载的组件的截图和没有加载的组件的截图。组件截图只能够截取组件大小的区域，如果组件的绘制超出了它的区域，或子组件的绘制超出了父组件的区域，这些在组件区域外绘制的内容不会在截图中呈现。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import componentSnapshot from '@ohos.arkui.componentSnapshot'    
```  
    
## get    
获取已加载的组件的截图，传入组件的[组件标识](../arkui-ts/ts-universal-attributes-component-id.md#组件标识)，找到对应组件进行截图。通过回调返回结果。  
 **调用形式：**     
    
- get(id: string, callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 10    
- get(id: string): Promise\<image.PixelMap>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| id | string | true | 目标组件的[组件标识](../arkui-ts/ts-universal-attributes-component-id.md#组件标识) |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 截图返回结果的回调。                               | |  
| Promise<image.PixelMap> | 截图返回的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if id is not valid. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import componentSnapshot from '@ohos.arkui.componentSnapshot'  
import image from '@ohos.multimedia.image'  
  
@Entry  
@Component  
struct SnapshotExample {  
  @State pixmap: image.PixelMap|undefined = undefined  
  
  build() {  
    Column() {  
      Image(this.pixmap)  
        .width(300).height(300)  
      // ...Component  
      // ...Component  
      // ...Component  
      Button("click to generate UI snapshot")  
        .onClick(() => {  
          componentSnapshot.get("root", (error: Error, pixmap: image.PixelMap) => {  
                 this.pixmap = pixmap  
                 // save pixmap to file  
                 // ....  
             })  
        })  
    }  
    .width('80%')  
    .margin({ left: 10, top: 5, bottom: 5 })  
    .height(200)  
    .border({ color: '#880606', width: 2 })  
    .id("root")  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import componentSnapshot from '@ohos.arkui.componentSnapshot'  
import image from '@ohos.multimedia.image'  
  
@Entry  
@Component  
struct SnapshotExample {  
  @State pixmap: image.PixelMap|undefined = undefined  
  
  build() {  
    Column() {  
      Image(this.pixmap)  
        .width(300).height(300)  
      // ...Component  
      // ...Component  
      // ...Component  
      Button("click to generate UI snapshot")  
        .onClick(() => {  
          componentSnapshot.get("root")  
            .then((pixmap: image.PixelMap) => {  
              this.pixmap = pixmap  
              // save pixmap to file  
              // ....  
            })  
        })  
    }  
    .width('80%')  
    .margin({ left: 10, top: 5, bottom: 5 })  
    .height(200)  
    .border({ color: '#880606', width: 2 })  
    .id("root")  
  }  
}  
    
```    
  
    
## createFromBuilder    
在应用后台渲染CustomBuilder自定义组件，并输出其截图。通过回调返回结果并支持在回调中获取离屏组件绘制区域坐标和大小。  
 **调用形式：**     
    
- createFromBuilder(builder: CustomBuilder, callback: AsyncCallback\<image.PixelMap>): void    
起始版本： 10    
- createFromBuilder(builder: CustomBuilder): Promise\<image.PixelMap>    
起始版本： 10  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| builder | CustomBuilder | true | 自定义组件构建函数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 截图返回结果的回调。支持在回调中获取离屏组件绘制区域坐标和大小。 |  
| Promise<image.PixelMap> | if builder is not a valid build function. |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 100001 | if builder is not a valid build function. |  
    
 **示例代码1：**   
示例(callback):  
```ts    
import componentSnapshot from '@ohos.arkui.componentSnapshot'  
import image from '@ohos.multimedia.image'  
import componentUtils from '@ohos.arkui.componentUtils'  
  
@Entry  
@Component  
struct OffscreenSnapshotExample {  
  @State pixmap: image.PixelMap | undefined = undefined  
  
  @Builder  
  RandomBuilder() {  
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
      Text('Test menu item 1')  
        .fontSize(20)  
        .width(100)  
        .height(50)  
        .textAlign(TextAlign.Center)  
      Divider().height(10)  
      Text('Test menu item 2')  
        .fontSize(20)  
        .width(100)  
        .height(50)  
        .textAlign(TextAlign.Center)  
    }  
    .width(100)  
    .id("builder")  
  }  
  
  build() {  
    Column() {  
      Button("click to generate offscreen UI snapshot")  
        .onClick(() => {  
          componentSnapshot.createFromBuilder(()=>{this.RandomBuilder()},  
            (error: Error, pixmap: image.PixelMap) => {  
              this.pixmap = pixmap  
              // save pixmap to file  
              // ....  
              // get component size and location  
              let info = componentUtils.getRectangleById("builder")  
              console.log(info.size.width + ' ' + info.size.height + ' ' + info.localOffset.x + ' ' + info.localOffset.y + ' ' + info.windowOffset.x + ' ' + info.windowOffset.y)  
            })  
        })  
    }.width('80%').margin({ left: 10, top: 5, bottom: 5 }).height(200)  
    .border({ color: '#880606', width: 2 })  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例(Promise):  
```ts    
import componentSnapshot from '@ohos.arkui.componentSnapshot'  
import image from '@ohos.multimedia.image'  
import componentUtils from '@ohos.arkui.componentUtils'  
  
@Entry  
@Component  
struct OffscreenSnapshotExample {  
  @State pixmap: image.PixelMap | undefined = undefined  
  
  @Builder  
  RandomBuilder() {  
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
      Text('Test menu item 1')  
        .fontSize(20)  
        .width(100)  
        .height(50)  
        .textAlign(TextAlign.Center)  
      Divider().height(10)  
      Text('Test menu item 2')  
        .fontSize(20)  
        .width(100)  
        .height(50)  
        .textAlign(TextAlign.Center)  
    }  
    .width(100)  
    .id("builder")  
  }  
  
  build() {  
    Column() {  
      Button("click to generate offscreen UI snapshot")  
        .onClick(() => {  
          componentSnapshot.createFromBuilder(()=>{this.RandomBuilder()})  
            .then((pixmap: image.PixelMap) => {  
              this.pixmap = pixmap  
              // save pixmap to file  
              // ....  
              // get component size and location  
              let info = componentUtils.getRectangleById("builder")  
              console.log(info.size.width + ' ' + info.size.height + ' ' + info.localOffset.x + ' ' + info.localOffset.y + ' ' + info.windowOffset.x + ' ' + info.windowOffset.y)  
            })  
        })  
    }.width('80%').margin({ left: 10, top: 5, bottom: 5 }).height(200)  
    .border({ color: '#880606', width: 2 })  
  }  
}  
    
```    
  
