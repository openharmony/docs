# 拖拽事件

拖拽事件指组件被长按后拖拽时触发的事件。

>  **说明：**
>
>  从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  已实现默认拖拽效果组件：[Image](../arkui-ts/ts-basic-components-image.md)、[Text](../arkui-ts/ts-basic-components-text.md)、[TextArea](../arkui-ts/ts-basic-components-textarea.md)、[Search](../arkui-ts/ts-basic-components-search.md)。

## 事件

| 名称                                                         | 支持冒泡 | 功能描述                                                     |
| ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| onDragStart(event:&nbsp;(event?:&nbsp;[DragEvent](#dragevent说明),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;&nbsp;[CustomBuilder](ts-types.md#custombuilder8) \| [DragItemInfo](#dragiteminfo说明)) | 否       | 第一次拖拽此事件绑定的组件时，触发回调。<br/>- event：拖拽事件信息，详见[DragEvent](#dragevent说明)。<br/>- extraParams：拖拽事件额外信息，详见[extraParams](#extraparams说明)说明。<br/> 返回值：拖拽过程中显示的组件信息。<br/>触发条件：长按时间 >= 500ms。<br> 事件优先级：长安触发时间 < 500ms，长按事件 > 拖拽事件<br> 其他： 拖拽事件 > 长按事件。 |
| onDragEnter(event:&nbsp;(event?:&nbsp;[DragEvent](#dragevent说明),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 否       | 拖拽进入组件范围内时，触发回调。<br/>- event：拖拽事件信息，包括拖拽点坐标。<br/>- extraParams：拖拽事件额外信息，详见[extraParams](#extraparams说明)说明。<br/>当监听了onDrop事件时，此事件才有效。 |
| onDragMove(event:&nbsp;(event?:&nbsp;[DragEvent](#dragevent说明),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 否       | 拖拽在组件范围内移动时，触发回调。<br/>- event：拖拽事件信息，包括拖拽点坐标。<br/>- extraParams：拖拽事件额外信息，详见[extraParams](#extraparams说明)说明。<br/>当监听了onDrop事件时，此事件才有效。 |
| onDragLeave(event:&nbsp;(event?:&nbsp;[DragEvent](#dragevent说明),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 否       | 拖拽离开组件范围内时，触发回调。<br/>- event：拖拽事件信息，包括拖拽点坐标。<br/>- extraParams：拖拽事件额外信息，详见[extraParams](#extraparams说明)说明。<br/>当监听了onDrop事件时，此事件才有效。 |
| onDrop(event:&nbsp;(event?:&nbsp;[DragEvent](#dragevent说明),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 否       | 绑定此事件的组件可作为拖拽释放目标，当在本组件范围内停止拖拽行为时，触发回调。<br/>- event：拖拽事件信息，包括拖拽点坐标。<br/>- extraParams：拖拽事件额外信息，详见[extraParams](#extraparams说明)说明。 |
| onDragEnd(event:&nbsp;(event?:&nbsp;[DragEvent](#dragevent说明),&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void)<sup>10+</sup> | 否       | 绑定此事件的组件触发的拖拽结束后，触发回调。<br/>- event：拖拽事件信息，包括拖拽点坐标。<br/>- extraParams：拖拽事件额外信息，详见[extraParams](#extraparams说明)说明。 |

## DragItemInfo说明

| 名称      | 类型                                     | 必填   | 描述                                |
| --------- | ---------------------------------------- | ---- | --------------------------------- |
| pixelMap  | [PixelMap](../apis/js-apis-image.md#pixelmap7) | 否    | 设置拖拽过程中显示的图片。                     |
| builder   | [CustomBuilder](ts-types.md#custombuilder8) | 否    | 拖拽过程中显示自定义组件，如果设置了pixelMap，则忽略此值。 |
| extraInfo | string                                   | 否    | 拖拽项的描述。                           |


## extraParams说明

  用于返回组件在拖拽中需要用到的额外信息。

  extraParams是Json对象转换的string字符串，可以通过Json.parse转换的Json对象获取如下属性。

| 名称          | 类型   | 描述                                       |
| ------------- | ------ | ---------------------------------------- |
| selectedIndex | number | 当拖拽事件设在父容器的子元素时，selectedIndex表示当前被拖拽子元素是父容器第selectedIndex个子元素，selectedIndex从0开始。<br/>仅在ListItem组件的拖拽事件中生效。 |
| insertIndex   | number | 当前拖拽元素在List组件中放下时，insertIndex表示被拖拽元素插入该组件的第insertIndex个位置，insertIndex从0开始。<br/>仅在List组件的拖拽事件中生效。 |

## DragEvent说明

| 名称     | 类型  | 描述             |
| ------ | ------ | ---------------- |
| getX() | number | 当前拖拽点相对于屏幕左上角的x轴坐标，单位为vp。 |
| getY() | number | 当前拖拽点相对于屏幕左上角的y轴坐标，单位为vp。 |
| useCustomDropAnimation<sup>10+</sup> | boolean | 当拖拽结束时，是否使用系统默认落入动画。 |
| setData(unifiedData: [UnifiedData](../apis/js-apis-data-udmf.md#unifieddata))<sup>10+</sup> | void | 向DragEvent中设置拖拽相关数据。 |
| getData()<sup>10+</sup> | [UnifiedData](../apis/js-apis-data-udmf.md#unifieddata) | 从DragEvent中获取拖拽相关数据。 |
| getSummary()<sup>10+</sup> | [Summary](../apis/js-apis-data-udmf.md#summary) | 从DragEvent中获取拖拽相关数据的简介。 |
| setResult(dragRect: [DragRet](#dragret10枚举说明))<sup>10+</sup> | void | 向DragEvent中设置拖拽结果。 |
| getResult()<sup>10+</sup> | [DragRet](#dragret10枚举说明) | 从DragEvent中获取拖拽结果。 |
| getPrviewRect()<sup>10+</sup> | [Rectangle](ts-universal-attributes-touch-target.md#rectangle对象说明) | 获取预览图所在的Rectangle。 |
| getVelocityX()<sup>10+</sup> | number | 获取当前拖拽的x轴方向拖动速度。坐标轴原点为屏幕左上角，单位为vp，分正负方向速度，从左往右为正，反之为负。 |
| getVelocityY()<sup>10+</sup> | number | 获取当前拖拽的y轴方向拖动速度。坐标轴原点为屏幕左上角，单位为vp，分正负方向速度，从上往下为正，反之为负。 |
| getVelocity()<sup>10+</sup> | number | 获取当前拖拽的主方向拖动速度。为xy轴方向速度的平方和的算术平方根。 |

## DragRet<sup>10+</sup>枚举说明

| 名称 | 描述 |
| ----- | ----------------- |
| DRAG_SUCCESS | 拖拽成功 |
| DRAG_FAILED | 拖拽失败 |
| DRAG_CANCELED | 拖拽取消 |
| DROP_ENABLED | 组件允许落入 |
| DROP_DISABLED | 组件不允许落入 |

## 示例

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
    let records: Array<udmf.UnifiedRecord> = event.getData().getRecords();
    if (records.length !== 0) {
      callback(event);
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
            this.getDataFromUdmfRetry(dragEvent, (event)=>{
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
            this.getDataFromUdmfRetry(dragEvent, event => {
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
          this.getDataFromUdmfRetry(dragEvent, event=>{
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
