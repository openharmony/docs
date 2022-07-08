# 组件标识

id为组件的唯一标识，在整个应用内唯一。本模块提供组件标识相关接口，可以获取指定id组件的属性，也提供向指定id组件发送事件的功能。

>  **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性

| 名称 | 参数说明 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| id | string | '' | 组件的唯一标识，唯一性由使用者保证。 |


## 接口


### getInspectorByKey

getInspectorByKey(id: string): string

获取指定id的组件的所有属性，不包括子组件信息。

- 参数
  | 参数 | 类型 | 必填 | 默认值 | 描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | 是 | - | 要获取属性的组件id。 |

- 返回值
  | 类型 | 描述 |
  | -------- | -------- |
  | string | 组件属性列表的JSON字符串。 |

### getInspectorTree

getInspectorTree(): string

获取组件树及组件属性。

- 返回值

  | 类型   | 描述                               |
  | ------ | ---------------------------------- |
  | string | 组件树及组件属性列表的JSON字符串。 |

### sendEventByKey

sendEventByKey(id: string, action: number, params: string): boolean

给指定id的组件发送事件。

- 参数
  | 参数 | 类型 | 必填 | 默认值 | 描述 |
  | -------- | -------- | -------- | -------- | -------- |
  | id | string | 是 | - | 要触发事件的组件的id。 |
  | action | number | 是 | - | 要触发的事件类型，目前支持取值：<br/>-&nbsp;点击事件Click:&nbsp;10<br/>-&nbsp;长按事件LongClick:&nbsp;11。 |
  | params | string | 是 | - | 事件参数，无参数传空字符串&nbsp;""。 |

- 返回值
  | 类型 | 描述 |
  | -------- | -------- |
  | boolean | 找不到指定id的组件时返回false，其余情况返回true。 |

### sendTouchEvent

sendTouchEvent(event: TouchObject): boolean

发送触摸事件。

- 参数

  | 参数  | 类型        | 必填 | 默认值 | 描述                                                         |
  | ----- | ----------- | ---- | ------ | ------------------------------------------------------------ |
  | event | TouchObject | 是   | -      | 触发触摸事件的位置，event参数见[TouchEvent](ts-universal-events-touch.md#touchevent对象说明)中TouchObject的介绍。 |

- 返回值

  | 类型    | 描述                                        |
  | ------- | ------------------------------------------- |
  | boolean | 事件发送失败时返回false，其余情况返回true。 |

### sendKeyEvent

sendKeyEvent(event: KeyEvent): boolean

发送按键事件。

- 参数

  | 参数  | 类型     | 必填 | 默认值 | 描述                                                         |
  | ----- | -------- | ---- | ------ | ------------------------------------------------------------ |
  | event | KeyEvent | 是   | -      | 按键事件，event参数见[KeyEvent](ts-universal-events-key.md#keyevent对象说明)介绍。 |

- 返回值

  | 类型    | 描述                                          |
  | ------- | --------------------------------------------- |
  | boolean | 事件发送失败时时返回false，其余情况返回true。 |

### sendMouseEvent

sendMouseEvent(event: MouseEvent): boolean

发送鼠标事件。

- 参数

  | 参数  | 类型       | 必填 | 默认值 | 描述                                                         |
  | ----- | ---------- | ---- | ------ | ------------------------------------------------------------ |
  | event | MouseEvent | 是   | -      | 鼠标事件，event参数见[MouseEvent](ts-universal-mouse-key.md#mouseevent对象说明)介绍。 |

- 返回值

  | 类型    | 描述                                          |
  | ------- | --------------------------------------------- |
  | boolean | 事件发送失败时时返回false，其余情况返回true。 |

## 示例

```ts
// xxx.ets
class Utils {
  static rect_left;
  static rect_top;
  static rect_right;
  static rect_bottom;
  static rect_value;

  static getComponentRect(key) {
    let strJson = getInspectorByKey(key);
    let obj = JSON.parse(strJson);
    console.info("[getInspectorByKey] current component obj is: " + JSON.stringify(obj));
    let rectInfo = JSON.parse('[' + obj.$rect + ']')
    console.info("[getInspectorByKey] rectInfo is: " + rectInfo);
    this.rect_left = JSON.parse('[' + rectInfo[0] + ']')[0]
    this.rect_top = JSON.parse('[' + rectInfo[0] + ']')[1]
    this.rect_right = JSON.parse('[' + rectInfo[1] + ']')[0]
    this.rect_bottom = JSON.parse('[' + rectInfo[1] + ']')[1]
    return this.rect_value = {
      "left": this.rect_left, "top": this.rect_top, "right": this.rect_right, "bottom": this.rect_bottom
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
        console.info(getInspectorTree())
        this.text = "Button 'click to start' is clicked"
        setTimeout(() => {
          sendEventByKey("longClick", 11, "")
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
          let rect = Utils.getComponentRect('onTouch')
          let touchPoint: TouchObject = {
            id: 1,
            x: rect.left + (rect.right - rect.left) / 2,
            y: rect.top + (rect.bottom - rect.top) / 2,
            type: TouchType.Down,
            screenX: rect.left + (rect.right - rect.left) / 2,
            screenY: rect.left + (rect.right - rect.left) / 2,
          }
          sendTouchEvent(touchPoint)
          touchPoint.type = TouchType.Up
          sendTouchEvent(touchPoint)
        }, 2000)
      })).id('longClick')

      Button() {
        Text('onTouch').fontSize(25).fontWeight(FontWeight.Bold)
      }.type(ButtonType.Capsule).margin({ top: 20 })
      .onClick(() => {
        console.info('onTouch is clicked')
        this.text = "Button 'onTouch' is clicked"
        setTimeout(() => {
          let rect = Utils.getComponentRect('onMouse')
          let mouseEvent: MouseEvent = {
            button: MouseButton.Left,
            action: MouseAction.Press,
            x: rect.left + (rect.right - rect.left) / 2,
            y: rect.top + (rect.bottom - rect.top) / 2,
            screenX: rect.left + (rect.right - rect.left) / 2,
            screenY: rect.top + (rect.bottom - rect.top) / 2,
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
            source: SourceType.Mouse
          }
          sendMouseEvent(mouseEvent)
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
            timestamp: 0
          }
          sendKeyEvent(keyEvent)
        }, 2000)
      }).id('onMouse')

      Text(this.text).fontSize(25).padding(15)
    }
    .width('100%').height('100%')
  }
}
```
