# 拖拽控制

设置组件是否可以响应拖拽事件。

> **说明：**
> 
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> 支持拖拽控制的组件：[Text](ts-basic-components-text.md)、[Image](ts-basic-components-image.md)、[Video](ts-media-components-video.md)、[List](ts-container-list.md)、[Grid](ts-container-grid.md)。


## 属性

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| allowDrop | Array\<[UnifiedDataType](../apis/js-apis-data-udmf.md#unifieddatatype)> | 设置该组件上允许落入的数据类型。<br/>默认值：空<br/> |
| draggable | boolean | 设置该组件是否允许进行拖拽。<br/>默认值：false<br/> |


## 示例

```ts
// xxx.ets
import UDMF from '@ohos.data.UDMF';
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
        Image($r('app.media.1'))
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
            ForEach(this.AblockArr, (item, index) => {
              ListItem() {
                Image(item)
                  .width(100)
                  .height(100)
                  .border({width: 1})
              }
              .margin({ left: 30 , top : 30})
            }, item => item)
          }
          .height('90%')
          .width('100%')
          .allowDrop(["File.Media.Text", "File.Media.Image"])
          .onDrop((event: DragEvent, extraParams: string) => {
            let jsonString = JSON.parse(extraParams);
            this.uri = jsonString.extraInfo;
            this.AblockArr.splice(jsonString.insertIndex, 0, this.uri);
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
            ForEach(this.BblockArr, (item, index) => {
              ListItem() {
                Image(item)
                  .width(100)
                  .height(100)
                  .border({width: 1})
              }
              .margin({ left: 30 , top : 30})
            }, item => item)
          }
          .border({width: 1})
          .height('90%')
          .width('100%')
          .allowDrop(["File.Media.Image"])
          .onDrop((event: DragEvent, extraParams: string) => {
            console.log("enter onDrop")
            let dragData = event.getData();
            let summary = event.getSummary();
            if(dragData != undefined) {
              let arr = dragData.getRecords();
              if(arr.length > 0) {
                let image = <UDMF.Image>(arr[0]);
                this.uri = image.imageUri;
                let jsonString = JSON.parse(extraParams);
                this.BblockArr.splice(jsonString.insertIndex, 0, this.uri);
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
