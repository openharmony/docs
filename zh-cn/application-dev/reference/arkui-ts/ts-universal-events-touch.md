# 触摸事件

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 事件

| 名称                                       | 是否冒泡 | 功能描述                                     |
| ---------------------------------------- | ---- | ---------------------------------------- |
| onTouch(callback:&nbsp;(event?:&nbsp;TouchEvent)&nbsp;=&gt;&nbsp;void) | 是    | 触摸动作触发该方法调用，event参数见[TouchEvent](#touchevent对象说明)介绍。 |


### TouchEvent对象说明

- 属性
  | 属性名称                | 类型                                       | 描述           |
  | ------------------- | ---------------------------------------- | ------------ |
  | type                | TouchType                                | 触摸事件的类型。     |
  | touches             | ArrayTouchObject&gt;                     | 全部手指信息。      |
  | changedTouches      | ArrayTouchObject&gt;                     | 当前发生变化的手指信息。 |
  | timestamp           | number                                   | 事件时间戳。       |
  | target<sup>8+</sup> | [EventTarget](ts-universal-events-click.md) | 被触摸元素对象。     |


- 接口
  | 接口名称                   | 功能描述    |
  | ---------------------- | ------- |
  | stopPropagation()：void | 阻塞事件冒泡。 |


- TouchObject对象说明
  | 属性名称    | 类型        | 描述                  |
  | ------- | --------- | ------------------- |
  | type    | TouchType | 触摸事件的类型。            |
  | id      | number    | 手指唯一标识符。            |
  | screenX | number    | 触摸点相对于设备屏幕左边沿的X坐标。  |
  | screenY | number    | 触摸点相对于设备屏幕上边沿的Y坐标。  |
  | x       | number    | 触摸点相对于被触摸元素左边沿的X坐标。 |
  | y       | number    | 触摸点相对于被触摸元素上边沿的Y坐标。 |


- TouchType枚举说明
  | 名称     | 描述              |
  | ------ | --------------- |
  | Down   | 手指按下时触发。        |
  | Up     | 手指抬起时触发。        |
  | Move   | 手指按压态在屏幕上移动时触发。 |
  | Cancel | 触摸事件取消时触发。      |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TouchExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Button('Touch').backgroundColor(0x2788D9).height(40).width(80)
        .onTouch((event: TouchEvent) => {
          if (event.type === TouchType.Down) {
            this.eventType = 'Down'
          }
          if (event.type === TouchType.Up) {
            this.eventType = 'Up'
          }
          if (event.type === TouchType.Move) {
            this.eventType = 'Move'
          }
          console.info(this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: '
          + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y + '\ncomponent globalPos:('
          + event.target.area.globalPosition.x + ',' + event.target.area.globalPosition.y + ')\nwidth:'
          + event.target.area.width + '\nheight:' + event.target.area.height)
        })
      Text(this.text)
    }.height(200).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![zh-cn_image_0000001209874754](figures/zh-cn_image_0000001209874754.gif)
