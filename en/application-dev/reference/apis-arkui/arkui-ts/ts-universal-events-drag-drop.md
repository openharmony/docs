# Drag Event

A drag event is triggered when a component is dragged.

>  **NOTE**
>
>  This feature is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
> The resource files preset in the application (that is, the resource files that are contained in the HAP file before the application is installed) can be dragged and dropped only within the application.

The ArkUI framework implements the drag and drop capability for the following components, allowing them to serve as the drag source (from which data can be dragged) or drop target (to which data can be dropped). To enable drag and drop for these components, you only need to set their [draggable](ts-universal-attributes-drag-drop.md) attribute to **true**.

- The following component supports drag actions by default: [Search](ts-basic-components-search.md), [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md), [RichEditor](ts-basic-components-richeditor.md), [Text](ts-basic-components-text.md), [Image](ts-basic-components-image.md), [FormComponent](ts-basic-components-formcomponent-sys.md), [Hyperlink](ts-container-hyperlink.md)

- The following component supports drop actions by default: [Search](ts-basic-components-search.md), [TextInput](ts-basic-components-textinput.md), [TextArea](ts-basic-components-textarea.md), [Video](ts-media-components-video.md)

You can also define drag responses by implementing common drag events.

To enable drag and drop for other components, you need to set the **draggable** attribute to **true** and implement data transmission in APIs such as **onDragStart**.

## onDragStart

onDragStart(event: (event: DragEvent, extraParams?: string) => CustomBuilder | DragItemInfo)

Triggered when the component bound to the event is dragged for the first time. A drag operation is recognized only when the long press time is 500 ms or longer and the dragging distance is 10 vp or larger.

**Event priority**:<br>Long press time < 500 ms: Long press event > Drag event<br>Other cases: Drag event > Long press event

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                           | Mandatory| Description              |
| ----------- | ------------------------------- | ---- | ------------------ |
| event       | [DragEvent](#dragevent)     | Yes  | Information about the drag event.    |
| extraParams | string | No  | Additional information about the drag event.<br>**NOTE**<br>The value needs to be parsed into the JSON format. For details, see [extraParams](#extraparams).|

**Return value**

| Type                                                        | Description                    |
| ------------------------------------------------------------ | ------------------------ |
| [CustomBuilder](ts-types.md#custombuilder8) \| [DragItemInfo](#dragiteminfo) | Component information displayed during dragging.<br>**NOTE**<br>The global builder is not supported.|

## onDragEnter

onDragEnter(event: (event: DragEvent, extraParams?: string) => void)

Triggered when the dragged item enters a valid drop target. This event takes effect only when a listener for the [onDrop](#ondrop) event is enabled.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                           | Mandatory| Description                          |
| ----------- | ------------------------------- | ---- | ------------------------------ |
| event       | [DragEvent](#dragevent)     | Yes  | Information about the drag event, including the coordinates of the item that is being dragged.|
| extraParams | string | No  | Additional information about the drag event.<br>**NOTE**<br>The value needs to be parsed into the JSON format. For details, see [extraParams](#extraparams).|

## onDragMove

onDragMove(event: (event: DragEvent, extraParams?: string) => void)

Triggered when the dragged item moves in a valid drop target. This event takes effect only when a listener for the [onDrop](#ondrop) event is enabled.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                           | Mandatory| Description                          |
| ----------- | ------------------------------- | ---- | ------------------------------ |
| event       | [DragEvent](#dragevent)     | Yes  | Information about the drag event, including the coordinates of the item that is being dragged.|
| extraParams | string | No  | Additional information about the drag event.<br>**NOTE**<br>The value needs to be parsed into the JSON format. For details, see [extraParams](#extraparams).|

## onDragLeave

onDragLeave(event: (event: DragEvent, extraParams?: string) => void)

Triggered when the dragged item leaves a valid drop target. This event takes effect only when a listener for the [onDrop](#ondrop) event is enabled.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                           | Mandatory| Description                          |
| ----------- | ------------------------------- | ---- | ------------------------------ |
| event       | [DragEvent](#dragevent)     | Yes  | Information about the drag event, including the coordinates of the item that is being dragged.|
| extraParams | string | No  | Additional information about the drag event.<br>**NOTE**<br>The value needs to be parsed into the JSON format. For details, see [extraParams](#extraparams).|

## onDrop

onDrop(event: (event: DragEvent, extraParams?: string) => void)

Triggered when the dragged item is dropped on a valid drop target. If **event.setResult()** is not explicitly used, the default value **DRAG_SUCCESSFUL** will be used as the result.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                           | Mandatory| Description                          |
| ----------- | ------------------------------- | ---- | ------------------------------ |
| event       | [DragEvent](#dragevent)     | Yes  | Information about the drag event, including the coordinates of the item that is being dragged.|
| extraParams | string | No  | Additional information about the drag event.<br>**NOTE**<br>The value needs to be parsed into the JSON format. For details, see [extraParams](#extraparams).|

## onDragEnd

onDragEnd(event: (event: DragEvent, extraParams?: string) => void)

Triggered when the dragging of the component bound to the event ends.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name     | Type                           | Mandatory| Description                          |
| ----------- | ------------------------------- | ---- | ------------------------------ |
| event       | [DragEvent](#dragevent)     | Yes  | Information about the drag event, including the coordinates of the item that is being dragged.|
| extraParams | string | No  | Additional information about the drag event.<br>**NOTE**<br>The value needs to be parsed into the JSON format. For details, see [extraParams](#extraparams).|

## DragItemInfo

| Name     | Type                                    | Mandatory  | Description                               |
| --------- | ---------------------------------------- | ---- | --------------------------------- |
| pixelMap  | [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) | No   | Image to be displayed during dragging.                    |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | No   | Custom component to display during dragging. If **pixelMap** is set, this parameter is ignored.<br> **NOTE**<br>Global builder definition is not supported. If the [\<Image>](ts-basic-components-image.md) component is used in the builder, enable synchronous loading whenever possible, that is, set the [syncLoad](ts-basic-components-image.md#syncload8) attribute of the component to **true**. The builder is used only to generate the image displayed during the current dragging. Changes to the builder, if any, apply to the next dragging, but not to the current dragging.|
| extraInfo | string                                   | No   | Extra information of the dragged item.                          |


## extraParams

  Provides additional information required for dragging an item.

  **extraParams** is a string converted from a JSON object. You can obtain the following attributes using the JSON object converted from **Json.parse**.

| Name         | Type  | Description                                      |
| ------------- | ------ | ---------------------------------------- |
| selectedIndex | number | Index of the dragged item in the parent container. The value of **selectedindex** starts from **0**.<br>This parameter takes effect only in the drag event of the **\<ListItem>** component.|
| insertIndex   | number | Index of the element into which the dragged item is dropped in the **List** component. The value of **insertIndex** starts from **0**.<br>This parameter takes effect only in the drag event of the **\<List>** component.|

## DragEvent

### Attributes

| Name    | Type | Description            |
| ------ | ------ | ---------------- |
| useCustomDropAnimation<sup>10+</sup> | boolean | Whether to use the custom drop animation when the dragging ends.<br>If this parameter is set to **true**, the default drop animation is disabled, and the custom one is used.<br>If this parameter is set to **false** or is not set, the default drop animation is enabled. In this case, to avoid conflicts, the application should not implement any custom drop animation.|
|dragBehavior<sup>10+</sup> | [DragBehavior](#dragbehavior10) | Copy or paste mode.|

### Methods

| Name    | Return Value Type                           | Description                          |
| ----------- | ------------------------------- | ------------------------------ |
| setData(unifiedData: [UnifiedData](../../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata))<sup>10+</sup>       | void   | Sets drag-related data in the drag event.|
| getData()<sup>10+</sup> | [UnifiedData](../../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | Obtains drag-related data from the drag event. For details about the data obtaining result, see the error code description.|
| getSummary()<sup>10+</sup> | [Summary](../../apis-arkdata/js-apis-data-unifiedDataChannel.md#summary) | Obtains the summary of drag-related data from the drag event.|
| setResult(dragRect: [DragResult](#dragresult10))<sup>10+</sup> | void | Sets the drag and drop result in the drag event.|
| getResult()<sup>10+</sup> | [DragResult](#dragresult10) | Obtains the drag and drop result from the drag event.|
| getPreviewRect()<sup>10+</sup> | [Rectangle](ts-universal-attributes-touch-target.md#rectangle) | Obtains the rectangle where the preview image is located.|
| getVelocityX()<sup>10+</sup> | number | Obtains the dragging velocity along the x-axis. The origin of the coordinate axis is the upper left corner of the screen. The unit is vp. The velocity is positive if the movement is from left to right, and it is negative if the movement is from right to left.|
| getVelocityY()<sup>10+</sup> | number | Obtains the dragging velocity along the y-axis. The origin of the coordinate axis is the upper left corner of the screen. The unit is vp. The velocity is positive if the movement is from top to bottom, and it is negative if the movement is from bottom to top.|
| getVelocity()<sup>10+</sup> | number | Obtains the dragging velocity along the main axis. The value is the arithmetic square root of the sum of squares of the velocity along the x- and y-axis.|
| getWindowX()<sup>10+</sup> | number | X coordinate of the drag position relative to the upper left corner of the window, in vp.|
| getWindowY()<sup>10+</sup> | number | Y coordinate of the drag position relative to the upper left corner of the window, in vp.|
| getDisplayX()<sup>10+</sup> | number | X coordinate of the drag position relative to the upper left corner of the screen, in vp.|
| getDisplayY()<sup>10+</sup> | number | Y coordinate of the drag position relative to the upper left corner of the screen, in vp.|
| getX()<sup>(deprecated)</sup> | number | X coordinate of the drag position relative to the upper left corner of the window, in vp.<br>This API is deprecated since API version 10. You are advised to use **getWindowX()** instead.|
| getY()<sup>(deprecated)</sup> | number | Y coordinate of the drag position relative to the upper left corner of the window, in vp.<br>This API is deprecated since API version 10. You are advised to use **getWindowY()** instead.|


**Error codes**

For details about the error codes, see [Drag Event Error Codes](../errorcode-drag-event.md).

| ID  | Error Message|
| --------- | ------- |
| 190001    | GetData failed, data not found. |
| 190002    | GetData failed, data error. |

## DragResult<sup>10+</sup>

| Name| Description|
| ----- | ----------------- |
| DRAG_SUCCESSFUL | The drag and drop operation succeeded. It can be used in **onDrop**.|
| DRAG_FAILED | The drag and drop operation failed. It can be used in **onDrop**.|
| DRAG_CANCELED | The drag and drop operation was canceled. It can be used in **onDrop**.|
| DROP_ENABLED | The component allows for a drop operation. It can be used in **onDragMove**.|
| DROP_DISABLED | The component does not allow for a drop operation. It can be used in **onDragMove**.|

## DragBehavior<sup>10+</sup>

Provides the drag behavior. This API takes effect only when [DragResult](#dragresult10) is set to **DROP_ENABLED** and the [onDrop](#ondrop) callback is implemented.

| Name| Description|
| ----- | ----------------- |
| COPY | Copy mode.|
| MOVE| Paste mode.|


## Example

```ts
// xxx.ets
import UDC from '@ohos.data.unifiedDataChannel';
import UTD from '@ohos.data.uniformTypeDescriptor';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
  @State targetImage: string = '';
  @State targetText: string = 'Drag Text';
  @State imageWidth: number = 100;
  @State imageHeight: number = 100;
  @State imgState: Visibility = Visibility.Visible;
  @State videoSrc: string = 'resource://RAWFILE/02.mp4';
  @State abstractContent: string = "abstract";
  @State textContent: string = "";

  @Builder
  pixelMapBuilder() {
    Column() {
      Image($r('app.media.icon'))
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
      let records: Array<UDC.UnifiedRecord> = data.getRecords();
      if (!records || records.length <= 0) {
        return false;
      }
      callback(event);
      return true;
    } catch (e) {
      console.log("getData failed, code = " + (e as BusinessError).code + ", message = " + (e as BusinessError).message);
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
          .margin({ left: 15 })
          .visibility(this.imgState)
          .onDragEnd((event) => {
            // The result value obtained from onDragEnd is set in onDrop of the drop target.
            if (event.getResult() === DragResult.DRAG_SUCCESSFUL) {
              promptAction.showToast({ duration: 100, message: 'Drag Success' });
            } else if (event.getResult() === DragResult.DRAG_FAILED) {
              promptAction.showToast({ duration: 100, message: 'Drag failed' });
            }
          })
        Text('test drag event')
          .width('100%')
          .height(100)
          .draggable(true)
          .margin({ left: 15 })
          .copyOption(CopyOptions.InApp)
        TextArea({ placeholder: 'please input words' })
          .copyOption(CopyOptions.InApp)
          .width('100%')
          .height(50)
          .draggable(true)
        Search({ placeholder: 'please input you word' })
          .searchButton('Search')
          .width('100%')
          .height(80)
          .textFont({ size: 20 })
        Column() {
          Text('change video source')
        }.draggable(true)
        .onDragStart((event) => {
          let video: UDC.Video = new UDC.Video();
          video.videoUri = '/resources/rawfile/01.mp4';
          let data: UDC.UnifiedData = new UDC.UnifiedData(video);
          (event as DragEvent).setData(data);
          return { builder: () => {
            this.pixelMapBuilder()
          }, extraInfo: 'extra info' };
        })

        Column() {
          Text('this is abstract')
            .fontSize(20)
            .width('100%')
        }.margin({ left: 40, top: 20 })
        .width('100%')
        .height(100)
        .onDragStart((event) => {
          let data: UDC.PlainText = new UDC.PlainText();
          data.abstract = 'this is abstract';
          data.textContent = 'this is content this is content';
          (event as DragEvent).setData(new UDC.UnifiedData(data));
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
          .margin({ left: 15 })
          .border({ color: Color.Black, width: 1 })
          .allowDrop([UTD.UniformDataType.IMAGE])
          .onDrop((dragEvent?: DragEvent) => {
            this.getDataFromUdmf((dragEvent as DragEvent), (event: DragEvent) => {
              let records: Array<UDC.UnifiedRecord> = event.getData().getRecords();
              let rect: Rectangle = event.getPreviewRect();
              this.imageWidth = Number(rect.width);
              this.imageHeight = Number(rect.height);
              this.targetImage = (records[0] as UDC.Image).imageUri;
              event.useCustomDropAnimation = false;
              animateTo({ duration: 1000 }, () => {
                this.imageWidth = 100;
                this.imageHeight = 100;
                this.imgState = Visibility.None;
              })
              // If result is explicitly set to successful, the value is passed in to onDragEnd of the drag source.
              event.setResult(DragResult.DRAG_SUCCESSFUL);
            })
          })

        Text(this.targetText)
          .width('100%')
          .height(100)
          .border({ color: Color.Black, width: 1 })
          .margin(15)
          .allowDrop([UTD.UniformDataType.TEXT])
          .onDrop((dragEvent?: DragEvent) => {
            this.getDataFromUdmf((dragEvent as DragEvent), (event: DragEvent) => {
              let records: Array<UDC.UnifiedRecord> = event.getData().getRecords();
              let plainText: UDC.PlainText = records[0] as UDC.PlainText;
              this.targetText = plainText.textContent;
            })
          })

        Video({ src: this.videoSrc, previewUri: $r('app.media.icon') })
          .width('100%')
          .height(200)
          .controls(true)
          .allowDrop([UTD.UniformDataType.VIDEO])

        Column() {
          Text(this.abstractContent).fontSize(20).width('100%')
          Text(this.textContent).fontSize(15).width('100%')
        }
        .width('100%')
        .height(100)
        .margin(20)
        .border({ color: Color.Black, width: 1 })
        .allowDrop([UTD.UniformDataType.PLAIN_TEXT])
        .onDrop((dragEvent?: DragEvent) => {
          this.getDataFromUdmf((dragEvent as DragEvent), (event: DragEvent) => {
            let records: Array<UDC.UnifiedRecord> = event.getData().getRecords();
            let plainText: UDC.PlainText = records[0] as UDC.PlainText;
            this.abstractContent = plainText.abstract as string;
            this.textContent = plainText.textContent;
          })
        })
      }.width('45%')
      .height('100%')
      .margin({ left: '5%' })
    }
    .height('100%')
  }
}
```
![events-drag-drop](figures/events-drag-drop.png) 
