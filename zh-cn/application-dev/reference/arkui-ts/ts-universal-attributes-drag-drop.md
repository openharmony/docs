# 拖拽控制

设置组件是否可以响应拖拽事件。

> **说明：**
> 
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

ArkUI框架对以下组件实现了默认的拖拽能力，支持对数据的拖出或拖入响应，开发者只需要将这些组件的draggable属性设置为true，即可使用默认拖拽能力。

- 默认支持拖出能力的组件（可从组件上拖出数据）：Search、TextInput、TextArea、RichEditor、Text、Image、FormComponent、Hyperlink

- 默认支持拖入能力的组件（目标组件可响应拖入数据）：Search、TextInput、TextArea、Video

开发者也可以通过实现通用拖拽事件来自定义拖拽响应。

其他组件需要开发者将draggable属性设置为true，并在onDragStart等接口中实现数据传输相关内容，才能正确处理拖拽。


## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| allowDrop | Array\<[UniformDataType](../apis/js-apis-data-uniformTypeDescriptor.md#uniformdatatype)> | 设置该组件上允许落入的数据类型。<br/>默认值：空<br/> |
| draggable | boolean | 设置该组件是否允许进行拖拽。<br/>默认值：false<br/> |
| dragPreview<sup>11+</sup> | [CustomBuilder](ts-types.md#custombuilder8) \| [DragItemInfo](ts-universal-events-drag-drop.md#dragiteminfo说明) | 设置组件长按后浮起的预览图。仅组件支持拖拽情况下有效，当组件支持拖拽并同时设置[bindContextMenu](ts-universal-attributes-menu.md)的预览图时，则长按浮起的预览图以[bindContextMenu](ts-universal-attributes-menu.md)设置的预览图为准。[dragPreview](ts-universal-attributes-drag-drop.md)设置的预览图同时会被用作拖拽的背板图，开发者在[onDragStart](ts-universal-events-drag-drop.md)中返回的背板图优先级低于[dragPreview](ts-universal-attributes-drag-drop.md)设置的预览图。由于[CustomBuilder](ts-types.md#custombuilder8)需要离线渲染之后才能使用，因此存在一定的性能开销和时延，推荐优先使用 [DragItemInfo](ts-universal-events-drag-drop.md#dragiteminfo说明)中的[PixelMap](../apis/js-apis-image.md#pixelmap7)方式。<br/>默认值：空<br/> |
| dragPreviewOptions<sup>11+</sup> | [DragPreviewOptions<sup>11+</sup>](#dragpreviewoptions11) | 设置拖拽过程中背板图处理模式。<br/>默认值：[DragPreviewMode.AUTO](#dragpreviewmode11枚举)<br/> |

## DragPreviewOptions<sup>11+</sup>

| 名称 | 类型 | 必填 | 描述 |
| -------- | -------- | -------- | -------- |
| mode | [DragPreviewMode<sup>11+</sup>](#dragpreviewmode11枚举说明) | 否 | 表示拖拽过程中背板图处理模式。<br/>默认值：AUTO<br/> |

## DragPreviewMode<sup>11+</sup>枚举

| 名称 | 描述 |
| -------- | -------- |
| AUTO  | 拖拽背板图由系统根据场景自动进行处理。系统根据拖拽场景自动改变跟手点位置，根据系统规则自动对拖拽背板图进行缩放变换等。 |
| DISABLE_SCALE  | 禁用系统对拖拽背板图的缩放行为。 |

## 示例
### 示例1
allowDrop与draggable属性用法示例

```ts
// xxx.ets
import UDC from '@ohos.data.unifiedDataChannel';
import UTD from '@ohos.data.uniformTypeDescriptor';

@Entry
@Component
struct ImageExample {
  @State uri: string = ""
  @State AblockArr: string[] = []
  @State BblockArr: string[] = []
  @State AVisible: Visibility = Visibility.Visible
  @State dragSuccess :Boolean = false

  build() {
    Column() {
      Text('Image拖拽')
        .fontSize('30dp')
      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceAround }) {
        Image($r('app.media.icon'))
          .width(100)
          .height(100)
          .border({ width: 1 })
          .visibility(this.AVisible)
          .draggable(true)
          .onDragEnd((event: DragEvent) => {
            let ret = event.getResult();
            if(ret == 0) {
              console.log("enter ret == 0")
              this.AVisible = Visibility.Hidden;
            } else {
              console.log("enter ret != 0")
              this.AVisible = Visibility.Visible;
            }
          })
      }
      .margin({ bottom: 20 })
      Row() {
        Column(){
          Text('不允许释放区域(显示不允许角标但可以释放)')
            .fontSize('15dp')
            .height('10%')
          List(){
            ForEach(this.AblockArr, (item:string, index) => {
              ListItem() {
                Image(item)
                  .width(100)
                  .height(100)
                  .border({width: 1})
              }
              .margin({ left: 30 , top : 30})
            }, (item:string) => item)
          }
          .height('90%')
          .width('100%')
          .allowDrop([UTD.UniformDataType.TEXT])
          .onDrop((event?: DragEvent, extraParams?: string) => {
            this.uri = JSON.parse(extraParams as string).extraInfo;
            this.AblockArr.splice(JSON.parse(extraParams as string).insertIndex, 0, this.uri);
            console.log("ondrop not udmf data");
          })
          .border({width: 1})
        }
        .height("50%")
        .width("45%")
        .border({ width: 1 })
        .margin({ left: 12 })
        Column(){
          Text('可释放区域')
            .fontSize('15dp')
            .height('10%')
          List(){
            ForEach(this.BblockArr, (item:string, index) => {
              ListItem() {
                Image(item)
                  .width(100)
                  .height(100)
                  .border({width: 1})
              }
              .margin({ left: 30 , top : 30})
            }, (item:string) => item)
          }
          .border({width: 1})
          .height('90%')
          .width('100%')
          .allowDrop([UTD.UniformDataType.IMAGE])
          .onDrop((event?: DragEvent, extraParams?: string) => {
            console.log("enter onDrop")
            let dragData:UnifiedData = (event as DragEvent).getData() as UnifiedData;
            if(dragData != undefined) {
              let arr:Array<UDC.UnifiedRecord> = dragData.getRecords();
              if(arr.length > 0) {
                let image = arr[0] as UDC.Image;
                this.uri = image.imageUri;
                this.BblockArr.splice(JSON.parse(extraParams as string).insertIndex, 0, this.uri);
              } else {
                console.log(`dragData arr is null`)
              }
            } else {
              console.log(`dragData  is undefined`)
            }
            console.log("ondrop udmf data");
            this.dragSuccess = true
          })
        }
        .height("50%")
        .width("45%")
        .border({ width: 1 })
        .margin({ left: 12 })
      }
    }.width('100%')
  }
}
```

![dragImage.gif](figures/dragImage.gif)

### 示例2
dragPreview属性用法示例
```ts
// xxx.ets
@Entry
@Component
struct DragPreviewDemo{
  @Builder dragPreviewBuilder() {
    Column() {
      Text("dragPreview")
        .width(150)
        .height(50)
        .fontSize(20)
        .borderRadius(10)
        .textAlign(TextAlign.Center)
        .fontColor(Color.Black)
        .backgroundColor(Color.Pink)
    }
  }

  @Builder MenuBuilder() {
    Flex({ direction: FlexDirection.Column, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text("menu item 1")
        .fontSize(15)
        .width(100)
        .height(40)
        .textAlign(TextAlign.Center)
        .fontColor(Color.Black)
        .backgroundColor(Color.Pink)
      Divider()
        .height(5)
      Text("menu item 2")
        .fontSize(15)
        .width(100)
        .height(40)
        .textAlign(TextAlign.Center)
        .fontColor(Color.Black)
        .backgroundColor(Color.Pink)
    }
    .width(100)
  }

  build() {
    Row() {
      Column() {
        Image('/resource/image.jpeg')
          .width("30%")
          .draggable(true)
          .bindContextMenu(this.MenuBuilder, ResponseType.LongPress)
          .onDragStart(() => {
            console.log("Image onDragStart")
          })
          .dragPreview(this.dragPreviewBuilder)
      }
      .width("100%")
    }
    .height("100%")
  }
}
```

![dragPreview.gif](figures/dragPreview.gif)

### 示例3
dragPreviewOptions属性用法示例
```ts
// xxx.ets
import { DragPreviewOptions } from 'DragControllerParam'
import unifiedDataChannel from '@ohos.data.unifiedDataChannel'

@Entry
@Component
struct dragPreviewOptionsDemo{
  dragOption: DragPreviewOptions = { mode: DragPreviewMode.AUTO }

  build() {
    Row() {
      Column() {
        Button("Button")
          .margin({ top: 20 })
          .fontSize(30)
          .fontColor(Color.Black)
          .height("10%")
          .width("50%")
          .draggable(true)
          .onDragStart(() => {
            console.log("Button onDragStart")
          })
          .dragPreviewOptions(this.dragOption)

        Image('/resource/image.jpeg')
          .margin({ top: 20 })
          .width("60%")
          .border({ width: 1 })
          .borderStyle(BorderStyle.Dashed)
          .borderWidth(5)
          .borderColor(Color.Black)
          .draggable(true)
          .onDragStart(() => {
            console.log("Image onDragStart")
          })
          .dragPreviewOptions(this.dragOption)

        TextArea({ placeholder: 'input your word on here' })
          .margin({ top: 20, bottom: 20 })
          .placeholderColor(Color.Black)
          .caretColor(Color.Blue)
          .fontSize(30)
          .height(50)
          .fontWeight(FontWeight.Bold)
          .fontFamily("sans-serif")
          .fontStyle(FontStyle.Normal)
          .fontColor(Color.Red)
          .backgroundColor(Color.White)
          .dragPreviewOptions(this.dragOption)
      }
      .backgroundColor(Color.Pink)
      .width("100%")
    }
    .height("100%")
  }
}
```