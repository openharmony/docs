# 按键事件

按键事件指组件与键盘、遥控器等按键设备交互时触发的事件。

>  **说明：**
>  从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 事件

| 名称                                       | 支持冒泡 | 功能描述                                     |
| ---------------------------------------- | ---- | ---------------------------------------- |
| onKeyEvent(event:&nbsp;(event?:&nbsp;KeyEvent)&nbsp;=&gt;&nbsp;void) | 是    | 按键动作触发该方法调用，event参数见[KeyEvent](#keyevent对象说明)介绍。 |


## KeyEvent对象说明

- 属性
  | 属性名称      | 类型                          | 描述                         |
  | --------- | --------------------------- | -------------------------- |
  | type      | [KeyType](#keytype枚举说明)     | 按键的类型。                     |
  | keyCode   | number                      | 按键的键码。                     |
  | keyText   | string                      | 按键的键值。                     |
  | keySource | [KeySource](#keysource枚举说明) | 触发当前按键的输入设备类型。             |
  | deviceId  | number                      | 触发当前按键的输入设备ID。             |
  | metaKey   | number                      | 按键发生时元键的状态，1表示按压态，0表示未按压态。 |
  | timestamp | number                      | 按键发生时的时间戳。                 |


- 接口
  | 接口名称                         | 功能描述      |
  | ---------------------------- | --------- |
  | stopPropagation():&nbsp;void | 阻塞事件冒泡传递。 |

## KeyType枚举说明
| 名称   | 描述    |
| ---- | ----- |
| Down | 按键按下。 |
| Up   | 按键松开。 |


## KeySource枚举说明
| 名称                      | 描述         |
| ----------------------- | ---------- |
| Unknown                 | 输入设备类型未知。  |
| [KeyCode](#常用keycode说明) | 输入设备类型为键盘。 |

## 常用KeyCode说明
| 数值   | 行为   | 物理按键       |
| ---- | ---- | ---------- |
| 19   | 上    | 向上方向键。     |
| 20   | 下    | 向下方向键。     |
| 21   | 左    | 向左方向键。     |
| 22   | 右    | 向右方向键。     |
| 23   | 确定   | 遥控器的确认键。   |
| 66   | 确定   | 键盘的回车键。    |
| 160  | 确定   | 键盘的小键盘回车键。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct KeyEventExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Column() {
      Button('KeyEvent').backgroundColor(0x2788D9)
        .onKeyEvent((event: KeyEvent) => {
          if (event.type === KeyType.Down) {
            this.eventType = 'Down'
          }
          if (event.type === KeyType.Up) {
            this.eventType = 'Up'
          }
          console.info(this.text = 'KeyType:' + this.eventType + '\nkeyCode:' + event.keyCode + '\nkeyText:' + event.keyText)
        })
      Text(this.text).padding(15)
    }.height(300).width('100%').padding(35)
  }
}
```

![zh-cn_image_0000001174264364](figures/zh-cn_image_0000001174264364.gif)
