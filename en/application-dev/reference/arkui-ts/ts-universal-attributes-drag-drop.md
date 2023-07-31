# Drag and Drop Control

The drag and drop control attributes set whether a component can respond to drag events.

> **NOTE**
>
> The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> The following components support drag-and-drop control: [\<Text>](ts-basic-components-text.md), [Image](ts-basic-components-image.md), [\<Video>](ts-media-components-video.md), [\<List>](ts-container-list.md), and [\<Grid>](ts-container-grid.md).


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| allowDrop | Array\<[UnifiedDataType](../apis/js-apis-data-udmf.md#unifieddatatype)> | Type of data that can be dropped to the component.<br>Default value: empty<br>|
| draggable | boolean | Whether the component is draggable.<br>Default value: **false**<br>|


## Example

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
      Text ('Image drag and drop')
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
          Text('Invalid drop target')
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
          Text ('Valid drop target')
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


