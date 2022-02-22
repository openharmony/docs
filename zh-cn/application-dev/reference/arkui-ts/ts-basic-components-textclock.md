# TextClock

> ![](public_sys-resources/icon-note.gif) **说明：** 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

TextClock通过文本显示当前系统时间，支持不同时区的时间显示，时间显示最高精度到秒级。

## 权限列表

无

## 子组件

无

## 接口

TextClock(options?: {timeZoneOffset?: number, contorller?: TextClockController})

- 参数

  | 参数名   | 参数类型 | 必填 | 默认值             | 参数描述                                                     |
  | -------- | -------- | ---- | ------------------ | ------------------------------------------------------------ |
  | timeZoneOffset | number   | 否   | 时区偏移量 | 设置时区偏移量。取值范围为[-14, 12]，表示东十二区到西十二区，其中负值表示东时区，正值表示西时区，比如东八区为-8；对横跨国际日界线的国家或地区，用-13（UTC+13）和-14（UTC+14）来保证整个国家或者区域处在相同的时间。 |
  | contorller | [TextClockContorller](#TextClockController) | 否 | null | 绑定一个控制器，用来控制文本时钟的状态。|

## 属性

| 名称   | 参数类型 | 默认值   | 描述                                                         |
| ------ | -------- | -------- | ------------------------------------------------------------ |
| format | string   | 'hhmmss' | 设置显示时间格式，如“yyyy/mm/dd”、“yyyy-mm-dd”等。支持的时间格式化字符串：<ul><li>yyyy（年份）</li><li>mm（英文月份简写）</li><li>mmm（英文月份简写）</li><li>mmmm（英文月份全称）</li><li>dd（英文星期简写）</li><li>ddd（英文星期简写）</li><li>dddd（英文星期全称）</li><li>HH（24小时制）</li><li>hh（12小时制）</li><li>MM/mm（分钟）</li><li>SS/ss（秒）</li></ul> |

## TextClockController

TextClock容器组件的控制器，可以将此对象绑定至TextClock组件，然后通过它控制文本时钟状态的启动与停止。

| 接口名称                                         | 功能描述                                                     |
| -------------------------------------------- | ------------------------------------------------------------ |
| start() | 启动文本时钟。 |
| stop() | 停止文本时钟。 |


## 事件

| 名称                                         | 功能描述                                                     |
| -------------------------------------------- | ------------------------------------------------------------ |
| onDateChange(event: (value: number) => void) | 提供时间变化回调,该事件最小回调间隔为秒。<br /> value: Unix Time Stamp，即自1970年1月1日（UTC）起经过的毫秒数。 |

## 示例

```
@Entry
@Component
struct Second {
  @State accumulateTime: number = 0
  controller: TextClockController = new TextClockController()

  build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center}) {
        Text('current milliseconds is' + this.accumulateTime)
          .fontSize(20)
        TextClock({timeZoneOffset: -8, controller: this.controller})
          .format('hhmmss')
          .onDateChange((value: number) => {
            this.accumulateTime = value
          })
          .margin(20)
          .fontSize(30)
        Button("start TextClock")
          .margin({ bottom: 10 })
          .onClick(()=>{
            this.controller.start()
          })
        Button("stop TextClock")
          .onClick(()=>{
            this.controller.stop()
          })
      }
    .width('100%')
    .height('100%')
  }
}
```
![](figures/text_clock.png)

