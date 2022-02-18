# TextClock

> ![](public_sys-resources/icon-note.gif) **说明：** 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

TextClock主要用于显示系统时间，支持不同时区的时间显示，时间显示最高精度到秒级。

## 权限列表

无

## 子组件

无

## 接口

TextClock(options?: {hourswest?: number})

- 参数

  | 参数名   | 参数类型 | 必填 | 默认值             | 参数描述                                                     |
  | -------- | -------- | ---- | ------------------ | ------------------------------------------------------------ |
  | hourwest | number   | 否   | 系统时间所在的时区 | 设置时区信息，时区范围为[-14, 12]，其中负值表示东时区，比如东八区为-8，浮点数也会进行相应的换算（30分钟/0.5时区）；理论上时区范围是[-12,+12]，但是一些国家横跨国际日界线，因此用-13（UTC+13）和-14（UTC+14）来保证整个国家或者区域处在相同的时间。 |

## 属性

| 名称   | 参数类型 | 默认值   | 描述                                                         |
| ------ | -------- | -------- | ------------------------------------------------------------ |
| format | string   | 'hhmmss' | 设置显示时间格式，如“yyyy/mm/dd”、“yyyy-mm-dd”等。支持的时间格式化字符串：yyyy（年份），mm（英文月份简写），mmm（英文月份简写），mmmm（英文月份全称），dd（英文星期简写），ddd（英文星期简写），dddd（英文星期全称），HH（24小时制），hh（12小时制），MM/mm（分钟），SS/ss（秒）。 |
| status | boolean  | -        | 设置文本时钟的启动和停止。true表示文本时钟是启动状态。false表示文本时钟是停止状态。 |

## 事件

支持以下通用事件：onClick，onTouch，onKeyEvent，onDeleteEvent，onAppear，onDisAppear

| 名称                                         | 功能描述                                                     |
| -------------------------------------------- | ------------------------------------------------------------ |
| onDateChange(event: (value: number) => void) | 提供时间变化回调，回调参数为Unix Time Stamp，即自1970年1月1日（UTC）起经过的毫秒数，该事件最小回调间隔为秒。 |

## 示例

```
@Entry
@Component
struct TextClockExmaple {
  format: string = 'hhmmss'
  @State accumulateTime: number = 0
  hourswest: number = -8
  @State isStart: boolean = true

  build() {
    Column() {
      Text('current milliseconds is' + this.accumulateTime)
      TextClock({hourswest:this.hourswest})
        .format(this.format)
        .onDateChange((value: number) => {
          this.accumulateTime = value
        })
        .status(this.isStart)
        .fontSize(50)
      Button("start/stop clock")
        .onClick(()=>{
          this.isStart = !this.isStart
        })
    }
    .align(Alignment.Center)
  }
}
```

![](figures/textclock.png)
