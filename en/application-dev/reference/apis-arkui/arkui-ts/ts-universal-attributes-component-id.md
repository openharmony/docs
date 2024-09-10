# Component ID

**id** identifies a component uniquely within an application. This module provides APIs for obtaining the attributes of or sending events to the component with the specified ID.

>  **NOTE**
>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

### id

id(value: string): T

Sets a unique identifier for this component, with uniqueness guaranteed by the user.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type     | Mandatory| Description                      |
| ------ | -------- | -----|---------------------- |
| value  | string   |  Yes | Unique identifier for the component, with uniqueness guaranteed by the user.<br>Default value: **''**<br>|

### key<sup>12+</sup>

key(value: string): T

Sets a unique identifier for this component, with uniqueness guaranteed by the user.

This API is used only for test purposes. When this attribute is used in conjunction with **id**, the value assigned later will override the one assigned earlier. You are advised to set only **id**.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name  | Type     | Mandatory| Description                      |
| ------ | -------- | -----|---------------------- |
| value   | string   | Yes| Unique identifier for the component, with uniqueness guaranteed by the user.<br>Default value: **''**<br>|


## APIs


### getInspectorByKey<sup>9+</sup>

getInspectorByKey(id: string): string

Obtains all attributes of the component with the specified ID, excluding the information about child components.

This API is used only for test purposes. It is time consuming and not recommended.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name  | Type     | Mandatory    | Description       |
| ---- | -------- | ---- | -------------|
| id   | string   | Yes   | ID of the component whose attributes are to be obtained.|

**Return value**

| Type       | Description            |
| -------| -------------- |
| string | JSON string of the component attribute list.<br>**NOTE**<br> The string includes the tag, ID, location (relative to the coordinates in the upper left corner of the window), and other information of the component used for testing.|

### getInspectorTree<sup>9+</sup>

getInspectorTree(): Object

Obtains the component tree and component attributes.

This API is used only for test purposes. It is time consuming and not recommended.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type    | Description                           |
| ------ | --------------------------- |
| Object | JSON object of the component tree and component attribute list.|

### sendEventByKey<sup>9+</sup>

sendEventByKey(id: string, action: number, params: string): boolean

Sends an event to the component with the specified ID.

This API is used only for test purposes. It is time consuming and not recommended.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name      | Type     | Mandatory      | Description                        |
| ------ | -------| ---- | -------------------------- |
| id     | string | Yes   | ID of the component to which the event is to be sent.                     |
| action | number | Yes   | Type of the event to be sent. The options are as follows:<br>- **10**: click event.<br>- **11**: long-click event.|
| params | string | Yes   | Event parameters. If there is no parameter, pass an empty string **""**.           |

**Return value**

| Type         | Description                        |
| -------- | --------------------------|
| boolean  | Returns **true** if the component with the specified ID is found; returns **false** otherwise.|

### sendTouchEvent<sup>9+</sup>

sendTouchEvent(event: TouchObject): boolean

Sends a touch event.

This API is used only for test purposes. It is time consuming and not recommended.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name     | Type           | Mandatory | Description                                                        |
| ----- | ----------- | ---- | ------------------------------------------------------------ |
| event | [TouchObject](ts-universal-events-touch.md#touchobject) | Yes   | Location where a touch event is triggered. For details, see [TouchEvent](ts-universal-events-touch.md#touchevent).|

**Return value**

| Type     | Description                        |
| ------- | ---------------------------|
| boolean | Returns **true** if the event is sent successfully; returns **false** otherwise.|

### sendKeyEvent<sup>9+</sup>

sendKeyEvent(event: KeyEvent): boolean

Sends a key event.

This API is used only for test purposes. It is time consuming and not recommended.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name   | Type    | Mandatory     | Description                                                        |
| ----- | -------- | ----  | ------------------------------------------------------------ |
| event | [KeyEvent](ts-universal-events-key.md#keyevent) | Yes    | Key event. For details, see [KeyEvent](ts-universal-events-key.md#keyevent).|

**Return value**

| Type     | Description                          |
| ------- | ------------------------------|
| boolean | Returns **true** if the event is sent successfully; returns **false** otherwise.|

### sendMouseEvent<sup>9+</sup>

sendMouseEvent(event: MouseEvent): boolean

Sends a mouse event.

This API is used only for test purposes. It is time consuming and not recommended.

**Atomic service API**: This API can be used in atomic services since API version 11.

**Parameters**

| Name    | Type      | Mandatory      | Description                                    |
| ----- | ---------- | ----  | --------------------------------------- |
| event | [MouseEvent](ts-universal-mouse-key.md#mouseevent) | Yes   | Mouse event. For details, see [MouseEvent](ts-universal-mouse-key.md#mouseevent).|

**Return value**

| Type     | Description                                |
| ------- | ---------------------------------- |
| boolean | Returns **true** if the event is sent successfully; returns **false** otherwise.|

## Example

```ts
// xxx.ets
import { IntentionCode } from '@kit.InputKit'

class Utils {
  static rect_left: number
  static rect_top: number
  static rect_right: number
  static rect_bottom: number
  static rect_value: Record<string, number>

  // Obtain the coordinates of the rectangular area occupied by the component.
  static getComponentRect(key:string):Record<string, number> {
    let strJson = getInspectorByKey(key)
    let obj:Record<string, string> = JSON.parse(strJson)
    console.info("[getInspectorByKey] current component obj is: " + JSON.stringify(obj))
    let rectInfo:string[] = JSON.parse('[' + obj.$rect + ']')
    console.info("[getInspectorByKey] rectInfo is: " + rectInfo)
    Utils.rect_left = JSON.parse('[' + rectInfo[0] + ']')[0]
    Utils.rect_top = JSON.parse('[' + rectInfo[0] + ']')[1]
    Utils.rect_right = JSON.parse('[' + rectInfo[1] + ']')[0]
    Utils.rect_bottom = JSON.parse('[' + rectInfo[1] + ']')[1]
    return Utils.rect_value = {
      "left": Utils.rect_left, "top": Utils.rect_top, "right": Utils.rect_right, "bottom": Utils.rect_bottom
    }
  }
}

@Entry
@Component
struct IdExample {
  @State text: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {

      Button() {
        Text('onKeyTab').fontSize(25).fontWeight(FontWeight.Bold)
      }.margin({ top: 20 }).backgroundColor('#0D9FFB')
      .onKeyEvent(() => {
        this.text = "onKeyTab"
      })

      Button() {
        Text('click to start').fontSize(25).fontWeight(FontWeight.Bold)
      }.margin({ top: 20 })
      .onClick(() => {
        console.info(getInspectorByKey("click"))
        console.info(JSON.stringify(getInspectorTree()))
        this.text = "Button 'click to start' is clicked"
        setTimeout(() => {
          sendEventByKey("longClick", 11, "") // Send a long-click event to the component whose ID is "longClick".
        }, 2000)
      }).id('click')

      Button() {
        Text('longClick').fontSize(25).fontWeight(FontWeight.Bold)
      }.margin({ top: 20 }).backgroundColor('#0D9FFB')
      .gesture(
      LongPressGesture().onActionEnd(() => {
        console.info('long clicked')
        this.text = "Button 'longClick' is longclicked"
        setTimeout(() => {
          let rect = Utils.getComponentRect('onTouch') // Obtain the coordinates of the rectangular area occupied by the component whose ID is "onTouch".
          let touchPoint: TouchObject = {
            id: 1,
            type: TouchType.Down,
            x: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the component.
            y: rect.top + (rect.bottom - rect.top) / 2, // Y coordinate relative to the upper left corner of the component.
            screenX: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the application window. This API is deprecated since API version 10. Use windowX instead.
            screenY: rect.left + (rect.right - rect.left) / 2, // Y coordinate relative to the upper left corner of the application window. This API is deprecated since API version 10. Use windowY instead.
            windowX: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the application window.
            windowY: rect.left + (rect.right - rect.left) / 2, // Y coordinate relative to the upper left corner of the application window.
            displayX: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the device screen.
            displayY: rect.left + (rect.right - rect.left) / 2, // Y coordinate relative to the upper left corner of the device screen.
          }
          sendTouchEvent(touchPoint) // Send a touch event.
          touchPoint.type = TouchType.Up
          sendTouchEvent(touchPoint) // Send a touch event.
        }, 2000)
      })).id('longClick')

      Button() {
        Text('onTouch').fontSize(25).fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule).margin({ top: 20 })
      .onClick(() => {
        console.info('onTouch is clicked')
        this.text = "Button 'onTouch' is clicked"
        setTimeout(() => {
          let rect = Utils.getComponentRect('onMouse') // Obtain the coordinates of the rectangular area occupied by the component whose ID is "onMouse".
          let mouseEvent: MouseEvent = {
            button: MouseButton.Left,
            action: MouseAction.Press,
            x: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the component.
            y: rect.top + (rect.bottom - rect.top) / 2, // Y coordinate relative to the upper left corner of the component.
            screenX: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the application window. This API is deprecated since API version 10. Use windowX instead.
            screenY: rect.left + (rect.right - rect.left) / 2, // Y coordinate relative to the upper left corner of the application window. This API is deprecated since API version 10. Use windowY instead.
            windowX: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the application window.
            windowY: rect.left + (rect.right - rect.left) / 2, // Y coordinate relative to the upper left corner of the application window.
            displayX: rect.left + (rect.right - rect.left) / 2, // X coordinate relative to the upper left corner of the device screen.
            displayY: rect.left + (rect.right - rect.left) / 2, // Y coordinate relative to the upper left corner of the device screen.
            stopPropagation: () => {
            },
            timestamp: 1,
            target: {
              area: {
                width: 1,
                height: 1,
                position: {
                  x: 1,
                  y: 1
                },
                globalPosition: {
                  x: 1,
                  y: 1
                }
              }
            },
            source: SourceType.Mouse,
            pressure: 1,
            tiltX: 1,
            tiltY: 1,
            sourceTool: SourceTool.Unknown
          }
          sendMouseEvent(mouseEvent) // Send a mouse event.
        }, 2000)
      }).id('onTouch')

      Button() {
        Text('onMouse').fontSize(25).fontWeight(FontWeight.Bold)
      }.margin({ top: 20 }).backgroundColor('#0D9FFB')
      .onMouse(() => {
        console.info('onMouse')
        this.text = "Button 'onMouse' in onMouse"
        setTimeout(() => {
          let keyEvent: KeyEvent = {
            type: KeyType.Down,
            keyCode: 2049,
            keyText: 'tab',
            keySource: 4,
            deviceId: 0,
            metaKey: 0,
            timestamp: 0,
            stopPropagation: () => {
            },
            intentionCode: IntentionCode.INTENTION_DOWN
          }
          sendKeyEvent(keyEvent) // Send a key event.
        }, 2000)
      }).id('onMouse')

      Text(this.text).fontSize(25).padding(15)
    }
    .width('100%').height('100%')
  }
}
```
