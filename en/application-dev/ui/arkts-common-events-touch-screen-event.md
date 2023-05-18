# Touchscreen Event


A touchscreen event refer to a callback event triggered when a finger or stylus is pressed, slides, or is lifted from a component. Touchscreen events include the [click event](#click-event), [drag event](#drag-event), and [touch event](#touch-event).


**Figure 1** Touchscreen event principles


![en-us_image_0000001562700461](figures/en-us_image_0000001562700461.png)


## Click Event

A click event refers to a complete press and lift action performed by using a finger or a stylus. When a click event occurs, the following callback is triggered:



```ts
onClick(event: (event?: ClickEvent) => void)
```


The **event** parameter provides the coordinates of the click event relative to the window or component and the event source where the click occurs.


  For example, the click event of a button is used to control the display and hiding of an image.

```ts
@Entry
@Component
struct IfElseTransition {
  @State flag: boolean = true;
  @State btnMsg: string = 'show';

  build() {
    Column() {
      Button(this.btnMsg).width(80).height(30).margin(30)
        .onClick(() => {
          if (this.flag) {
            this.btnMsg = 'hide';
          } else {
            this.btnMsg = 'show';
          }
          // Click the button to control the display and hiding of the image.
          this.flag = !this.flag;
        })
      if (this.flag) {
        Image($r('app.media.icon')).width(200).height(200)
      }
    }.height('100%').width('100%')
  }
}
```


## Drag Event

A drag event is triggered when a user presses and holds a component (&gt;=500 ms) using a finger or stylus and drags the component to the drop target. The process of triggering a drag event is as follows:


![en-us_image_0000001562820825](figures/en-us_image_0000001562820825.png)


Whether a drag event can be triggered depends on the distance of long-pressing and dragging with the finger or stylus on the screen. The drag event is triggered when this distance reaches 5 vp. ArkUI supports intra-application and cross-application drag events.


The drag event provides the following [APIs](../reference/arkui-ts/ts-universal-events-drag-drop.md).


| API                                    | Description                                      |
| ---------------------------------------- | ---------------------------------------- |
| onDragStart(event:&nbsp;(event?:&nbsp;DragEvent,&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;CustomBuilder&nbsp;\|&nbsp;DragItemInfo) | Triggered when dragging starts. Currently, only custom **pixelmap** objects and custom components are supported.          |
| onDragEnter(event:&nbsp;(event?:&nbsp;DragEvent,&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered when the dragged item enters a valid drop target. **DragEvent** indicates the position where the drag occurs. **extraParmas** indicates the additional information about the drag event.|
| onDragLeave(event:&nbsp;(event?:&nbsp;DragEvent,&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered when the dragged item leaves a valid drop target. **DragEvent** indicates the position where the drag occurs. **extraParmas** indicates the additional information about the drag event.|
| onDragMove(event:&nbsp;(event?:&nbsp;DragEvent,&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered when the dragged item moves in a valid drop target. **DragEvent** indicates the position where the drag occurs. **extraParmas** indicates the additional information about the drag event.|
| onDrop(event:&nbsp;(event?:&nbsp;DragEvent,&nbsp;extraParams?:&nbsp;string)&nbsp;=&gt;&nbsp;void) | Triggered when the dragged item is dropped on a valid drop target. **DragEvent** indicates the position where the drag occurs. **extraParmas** indicates the additional information about the drag event.|


The following is an example of dragging a component out of a window in cross-window dragging:



```ts
import image from '@ohos.multimedia.image';

@Entry
@Component
struct Index {
  @State text: string = ''
  @State bool1: boolean = false
  @State bool2: boolean = false
  @State visible: Visibility = Visibility.Visible
  @State pixelMap: PixelMap = undefined
  private pixelMapReader = undefined

  aboutToAppear() {
    console.info('begin to create pixmap has info message: ')
    this.createPixelMap()
  }

  createPixelMap() {
    let color = new ArrayBuffer(4 * 96 * 96);
    var buffer = new Uint8Array(color);
    for (var i = 0; i < buffer.length; i++) {
      buffer[i] = (i + 1) % 255;
    }
    let opts = {
      alphaType: 0,
      editable: true,
      pixelFormat: 4,
      scaleMode: 1,
      size: { height: 96, width: 96 }
    }
    const promise = image.createPixelMap(color, opts);
    promise.then((data) => {
      console.info('create pixmap has info message: ' + JSON.stringify(data))
      this.pixelMap = data;
      this.pixelMapReader = data;
    })
  }

  @Builder pixelMapBuilder() {
    Text('drag item')
      .width('100%')
      .height(100)
      .fontSize(16)
      .textAlign(TextAlign.Center)
      .borderRadius(10)
      .backgroundColor(0xFFFFFF)
  }

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('App1')
        .width('40%')
        .height(80)
        .fontSize(20)
        .margin(30)
        .textAlign(TextAlign.Center)
        .backgroundColor(Color.Pink)
        .visibility(Visibility.Visible)

      Text('Across Window Drag This')
        .width('80%')
        .height(80)
        .fontSize(16)
        .margin(30)
        .textAlign(TextAlign.Center)
        .backgroundColor(Color.Pink)
        .visibility(this.visible)
        .onDragStart(() => {                    // Triggered when cross-window dragging starts.
          console.info('Text onDrag start')
          this.bool1 = true
          this.text = 'TextDrag'
          return { pixelMap: this.pixelMapReader, extraInfo: 'custom extra info.' }
        })
        .onDrop((event: DragEvent, extraParams: string) => {
          console.info('Text onDragDrop,  ')
          this.visible = Visibility.None                    // Make the source invisible after the dragging is complete.
        })
    }

    .width('100%')
    .height('100%')
  }
}
```


The following is an example of dragging a component into a window in cross-window dragging:



```ts

@Entry
@Component
struct Index {
  @State number: string[] = ['drag here']
  @State text: string = ''
  @State bool1: boolean = false
  @State bool2: boolean = false
  @State visible: Visibility = Visibility.Visible
  @State visible2: Visibility = Visibility.None
  scroller: Scroller = new Scroller()

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Text('App2')
        .width('40%')
        .height(80)
        .fontSize(20)
        .margin(30)
        .textAlign(TextAlign.Center)
        .backgroundColor(Color.Pink)
        .visibility(Visibility.Visible)

      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.number, (item) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(80)
              .fontSize(16)
              .borderRadius(10)
              .textAlign(TextAlign.Center)
              .backgroundColor(0xFFFFFF)
          }
        }, item => item)

        ListItem() {
          Text('Across Window Drag This')
            .width('80%')
            .height(80)
            .fontSize(16)
            .margin(30)
            .textAlign(TextAlign.Center)
            .backgroundColor(Color.Pink)
            .visibility(this.visible2)
        }
      }
      .height('50%')
      .width('90%')
      .border({ width: 1 })
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 })
      .onDragEnter((event: DragEvent, extraParams: string) => {                         // Drag the component into the window.
        console.info('List onDragEnter, ' + extraParams)
      })
      .onDragMove((event: DragEvent, extraParams: string) => {                          // Move the component during dragging.
        console.info('List onDragMove, ' + extraParams)
      })
      .onDragLeave((event: DragEvent, extraParams: string) => {                         // Drag the component out of the window.
        console.info('List onDragLeave, ' + extraParams)
      })
      .onDrop((event: DragEvent, extraParams: string) => {                              // Release the component.
        console.info('List onDragDrop, ' + extraParams)
        this.visible2 = Visibility.Visible                                              // Make the dragged object visible.
      })
    }
    .width('100%')
    .height('100%')
  }
}
```


## Touch Event

When a finger or stylus touches a component, a touch event corresponding to the action is triggered, such as a press (Down), slide (Move), or lift (Up) event.


```ts
onTouch(event: (event?: TouchEvent) => void)
```

- If **event.type** is **TouchType.Down**, the finger or stylus is pressed.

- If** event.type** is **TouchType.Up**, the finger or stylus is lifted.

- If **event.type** is **TouchType.Move**, the finger or stylus is pressed and moved.

The touch event may be triggered by multiple fingers at the same time. Information such as the location of the finger that triggers the event, unique identifier of the finger, finger information changed, and an input device source may be obtained by using the **event** parameter.


```ts
// xxx.ets
@Entry
@Component
struct TouchExample {
  @State text: string = '';
  @State eventType: string = '';

  build() {
    Column() {
      Button('Touch').height(40).width(100)
        .onTouch((event: TouchEvent) => {
          if (event.type === TouchType.Down) {
            this.eventType = 'Down';
          }
          if (event.type === TouchType.Up) {
            this.eventType = 'Up';
          }
          if (event.type === TouchType.Move) {
            this.eventType = 'Move';
          }
          this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
          + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\nComponent globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
          + event.target.area.width + '\nheight:' + event.target.area.height
        })
      Button('Touch').height(50).width(200).margin(20)
        .onTouch((event: TouchEvent) => {
          if (event.type === TouchType.Down) {
            this.eventType = 'Down';
          }
          if (event.type === TouchType.Up) {
            this.eventType = 'Up';
          }
          if (event.type === TouchType.Move) {
            this.eventType = 'Move';
          }
          this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
          + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\nComponent globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
          + event.target.area.width + '\nheight:' + event.target.area.height
        })
      Text(this.text)
    }.width('100%').padding(30)
  }
}
```


![en-us_image_0000001511900468](figures/en-us_image_0000001511900468.gif)
