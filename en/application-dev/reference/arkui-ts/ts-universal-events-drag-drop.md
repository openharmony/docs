# Drag Event

A drag event is triggered when a component is dragged.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
>
> The following components support drag and drop actions by default: **\<Search>**, **\<TextInput>**, **\<TextArea>**.
>
> The following component supports drop actions by default: **\<Video>**.
>
> The following components support drag actions by default: **\<Text>**, **\<List>**, **\<Grid>**, **\<FormComponent>**, **\<Image>**, **\<Hyperlink>**.
>
> The resource files preset in the application (that is, the resource files that are contained in the HAP file before the application is installed) can be dragged and dropped only within the application.
## Events

| Name                                                        | Bubbling Supported| Description                                                    |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| onDragStart(event: (event?: [DragEvent](#dragevent), extraParams?: string) =&gt;  [CustomBuilder](ts-types.md#custombuilder8) \| [DragItemInfo](#dragiteminfo)) | No      | Triggered when the component bound to the event is dragged for the first time.<br>- **event**: information about the drag event. For details, see [DragEvent](#dragevent).<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>Return value: component information displayed during dragging.<br>Trigger condition: long press for at least 500 ms.<br>Event priority:<br>- Long press time < 500 ms: Long press event > Drag event<br>- Other: Drag event > Long press event |
| onDragEnter(event: (event?: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No      | Triggered when the dragged item enters a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>This event is valid only when a listener for the **onDrop** event is enabled.|
| onDragMove(event: (event?: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No      | Triggered when the dragged item moves in a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>This event is valid only when a listener for the **onDrop** event is enabled.|
| onDragLeave(event: (event?: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No      | Triggered when the dragged item leaves a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.<br>This event is valid only when a listener for the **onDrop** event is enabled.|
| onDrop(event: (event?: [DragEvent](#dragevent), extraParams?: string) =&gt; void) | No      | Triggered when the dragged item is dropped on a valid drop target.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.|
| onDragEnd(event: (event?: [DragEvent](#dragevent), extraParams?: string) =&gt; void)<sup>10+</sup> | No      | Triggered when the dragging of the component bound to the event ends.<br>- **event**: information about the drag event, including the coordinates of the item that is being dragged.<br>- **extraParams**: additional information about the drag event. For details, see **[extraParams](#extraparams)**.|

## DragItemInfo

| Name     | Type                                    | Mandatory  | Description                               |
| --------- | ---------------------------------------- | ---- | --------------------------------- |
| pixelMap  | [PixelMap](../apis/js-apis-image.md#pixelmap7) | No   | Image to be displayed during dragging.                    |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | No   | Custom component to display during dragging. If **pixelMap** is set, this attribute is ignored.|
| extraInfo | string                                   | No   | Extra information of the dragged item.                          |


## extraParams

Provides additional information required for dragging an item.

**extraParams** is a string converted from a JSON object. You can obtain the following attributes using the JSON object converted from **Json.parse**.

| Name         | Type  | Description                                      |
| ------------- | ------ | ---------------------------------------- |
| selectedIndex | number | Index of the dragged item in the parent container. The value of **selectedindex** starts from **0**.<br>This parameter is valid only in the drag event of the **\<ListItem>** component. |
| insertIndex   | number | Index of the element into which the dragged item is dropped in the **List** component. The value of **insertIndex** starts from **0**.<br>This parameter is valid only in the drag event of the **\<List>** component. |

## DragEvent

| Name    | Type | Description            |
| ------ | ------ | ---------------- |
| useCustomDropAnimation<sup>10+</sup> | boolean | Whether to use the default drop animation when the dragging ends.|
| setData(unifiedData: [UnifiedData](../apis/js-apis-data-udmf.md#unifieddata))<sup>10+</sup> | void | Sets drag-related data in the drag event.|
| getData()<sup>10+</sup> | [UnifiedData](../apis/js-apis-data-udmf.md#unifieddata) | Obtains drag-related data from the drag event.|
| getSummary()<sup>10+</sup> | [Summary](../apis/js-apis-data-udmf.md#summary) | Obtains the summary of drag-related data from the drag event.|
| setResult(dragRect: [DragRet](#dragret10))<sup>10+</sup>| void | Sets the drag and drop result in the drag event.|
| getResult()<sup>10+</sup> | [DragRet](#dragret10)| Obtains the drag and drop result from the drag event.|
| getPrviewRect()<sup>10+</sup> | [Rectangle](ts-universal-attributes-touch-target.md#rectangle) | Obtains the rectangle where the preview image is located.|
| getVelocityX()<sup>10+</sup> | number | Obtains the dragging velocity along the x-axis. The origin of the coordinate axis is the upper left corner of the screen. The unit is vp. The velocity is positive if the movement is from left to right, and it is negative if the movement is from right to left.|
| getVelocityY()<sup>10+</sup> | number | Obtains the dragging velocity along the y-axis. The origin of the coordinate axis is the upper left corner of the screen. The unit is vp. The velocity is positive if the movement is from top to bottom, and it is negative if the movement is from bottom to top.|
| getVelocity()<sup>10+</sup> | number | Obtains the dragging velocity along the main axis. The value is the arithmetic square root of the sum of squares of the velocity along the x- and y-axis.|
| getWindowX()<sup>10+</sup> | number | X coordinate of the drag position relative to the upper left corner of the window, in vp.|
| getWindowY()<sup>10+</sup> | number | Y coordinate of the drag position relative to the upper left corner of the window, in vp.|
| getDisplayX()<sup>10+</sup> | number | X coordinate of the drag position relative to the upper left corner of the screen, in vp.|
| getDisplayY()<sup>10+</sup> | number | Y coordinate of the drag position relative to the upper left corner of the screen, in vp.|
| getX()<sup>(deprecated)</sup> | number | X coordinate of the drag position relative to the upper left corner of the window, in vp.<br>This API is deprecated since API version 10. You are advised to use **getWindowX()** instead.|
| getY()<sup>(deprecated)</sup> | number | Y coordinate of the drag position relative to the upper left corner of the window, in vp.<br>This API is deprecated since API version 10. You are advised to use **getWindowY()** instead.|

## DragRet<sup>10+</sup>

| Name| Description|
| ----- | ----------------- |
| DRAG_SUCCESS | The drag and drop operation succeeded.|
| DRAG_FAILED | The drag and drop operation failed.|
| DRAG_CANCELED | The drag and drop operation was canceled.|
| DROP_ENABLED | The component allows for a drop operation.|
| DROP_DISABLED | The component does not allow for a drop operation.|

## Example

```ts
import udmf from '@ohos.data.UDMF';
import promptAction from '@ohos.promptAction';
@Entry
@Component
struct Index {
  @State targetImage: string = '';
  @State targetText: string = 'Drag Text';
  @State hyperLinkText: string = 'HyperLink';
  @State hyperLinkContent: string = 'HyperLink';
  @State imageWidth: number = 100;
  @State imageHeight: number = 100;
  @State imgState: Visibility = Visibility.Visible;
  @State videoSrc: string = 'resource://RAWFILE/02.mp4';
  @State abstractContent: string = "abstract";
  @State textContent: string = "";

  getDataFromUdmfRetry(event: DragEvent, callback: (data: DragEvent)=>void)
  {
    let data = event.getData();
    if (!data) {
      return false;
    }
    let records: Array<udmf.UnifiedRecord> = data.getRecords();
    if (!records || records.length <= 0) {
      return false;
    }
    callback(event);
    return true;
  }

  getDataFromUdmf(event: DragEvent, callback: (data: DragEvent)=>void)
  {
    if(this.getDataFromUdmfRetry(event, callback)) {
        return;
    }
    setTimeout(()=>{
      this.getDataFromUdmfRetry(event, callback);
    }, 1500);
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
        Image($r('app.media.icon'))
          .width(100)
          .height(100)
          .draggable(true)
          .margin({left: 15})
          .visibility(this.imgState)
          .onDragEnd((event)=>{
          if (event.getResult() === DragRet.DRAG_SUCCESS) {
            promptAction.showToast({duration: 100, message: 'Drag Success'});
          } else if (event.getResult() === DragRet.DRAG_FAILED) {
            promptAction.showToast({duration: 100, message: 'Drag failed'});
          }
        })
        Text('test drag event')
          .width('100%')
          .height(100)
          .draggable(true)
          .margin({left: 15})
          .copyOption(CopyOptions.InApp)
        TextArea({placeholder: 'please input words'})
          .copyOption(CopyOptions.InApp)
          .width('100%')
          .height(50)
          .draggable(true)
        Search({placeholder: 'please input you word'})
          .searchButton('Search')
          .width('100%')
          .height(80)
          .textFont({size: 20})
        Column() {
          Text('change video source')
        }.draggable(true)
        .onDragStart((event)=>{
          let video: udmf.Video = new udmf.Video();
          video.videoUri = 'resource://RAWFILE/01.mp4';
          let data: udmf.UnifiedData = new udmf.UnifiedData(video);
          event.setData(data);
        })
        Column() {
          Text('this is abstract')
            .fontSize(20)
            .width('100%')
        }.margin({left: 40, top: 20})
        .width('100%')
        .height(100)
        .onDragStart((event)=>{
          let data: udmf.PlainText = new udmf.PlainText();
          data.abstract = 'this is abstract';
          data.textContent = 'this is content this is content';
          event.setData(new udmf.UnifiedData(data));
        })
      }.width('45%')
      .height('100%')
      Column() {
        Text('Drag Target Area')
          .fontSize(20)
          .width('100%')
          .height(40)
          .margin(10)
          .backgroundColor('#008888')
        Image(this.targetImage)
          .width(this.imageWidth)
          .height(this.imageHeight)
          .draggable(true)
          .margin({left: 15})
          .border({color: Color.Black, width: 1})
          .allowDrop([udmf.UnifiedDataType.IMAGE])
          .onDrop((dragEvent: DragEvent)=> {
            this.getDataFromUdmf(dragEvent, (event)=>{
              let records: Array<udmf.UnifiedRecord> = event.getData().getRecords();
              let rect: Rectangle = event.getPreviewRect();
              this.imageWidth = Number(rect.width);
              this.imageHeight = Number(rect.height);
              this.targetImage = (<udmf.Image>(records[0])).imageUri;
              event.useCustomDropAnimation = false;
              animateTo({duration: 1000}, ()=>{
                this.imageWidth = 100;
                this.imageHeight = 100;
                this.imgState = Visibility.None;
              })
              event.setResult(DragRet.DRAG_SUCCESS);
            })
          })

        Text(this.targetText)
          .width('100%')
          .height(100)
          .border({color: Color.Black, width: 1})
          .margin(15)
          .allowDrop([udmf.UnifiedDataType.TEXT])
          .onDrop((dragEvent: DragEvent)=>{
            this.getDataFromUdmf(dragEvent, event => {
              let records:Array<udmf.UnifiedRecord> = event.getData().getRecords();
              this.targetText = (<udmf.Text>(records[0])).details['value'];
            })
          })

        Video({src: this.videoSrc, previewUri: $r('app.media.icon')})
          .width('100%')
          .height(200)
          .controls(true)
          .allowDrop([udmf.UnifiedDataType.VIDEO])

        Column() {
          Text(this.abstractContent).fontSize(20).width('100%')
          Text(this.textContent).fontSize(15).width('100%')
        }.width('100%').height(100).margin(20).border({color: Color.Black, width: 1})
        .allowDrop([udmf.UnifiedDataType.PLAIN_TEXT])
        .onDrop((dragEvent)=>{
          this.getDataFromUdmf(dragEvent, event=>{
            let records: Array<udmf.UnifiedRecord> = event.getData().getRecords();
            let plainText: udmf.PlainText = <udmf.PlainText>(records[0]);
            this.abstractContent = plainText.abstract;
            this.textContent = plainText.textContent;
          })
        })
      }.width('45%')
      .height('100%')
      .margin({left: '5%'})
    }
    .height('100%')
  }
}
```
