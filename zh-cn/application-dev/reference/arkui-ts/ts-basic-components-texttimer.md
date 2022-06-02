# TextTimer

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


文本计时器组件，支持自定义时间格式。


## 权限列表

无


## 子组件

无


## 接口说明

TextTimer(options: { isCountDown?: boolean, count?: number, controller?: TextTimerController })

- 参数
  | 参数名 | 参数类型 | 必填 | 默认值 | 参数描述 | 
  | -------- | -------- | -------- | -------- | -------- |
  | isCountDown | boolean | 否 | false | 是否倒计时。 | 
  | count | number | 否 | 60000 | 倒计时时间（isCountDown为true时生效），单位为毫秒。<br/>-&nbsp;count&lt;=0时，使用默认值为倒计时初始值。<br/>-&nbsp;count&gt;0时，count值为倒计时初始值。 | 
  | controller | [TextTimerController](#texttimercontroller) | 否 | null | TextTimer控制器。 | 

## 属性

| 名称 | 参数类型 | 默认值 | 描述 | 
| -------- | -------- | -------- | -------- |
| format | string | 'hh:mm:ss.ms' | 自定义格式，需至少包含一个hh、mm、ss、ms中的关键字。 | 


## 事件

| 名称 | 功能描述 | 
| -------- | -------- |
| onTimer(callback:&nbsp;(utc:&nbsp;number,&nbsp;elapsedTime:&nbsp;number)&nbsp;=&gt;&nbsp;void) | 时间文本发生变化时触发。<br/>utc：当前显示的时间，单位为毫秒。<br/>elapsedTime：计时器经过的时间，单位为毫秒。 | 


## TextTimerController

TextTimer组件的控制器，用于控制文本计时器。

### 导入对象

```
textTimerController: TextTimerController = new TextTimerController()

```

### start

start()

计时开始。

### pause

pause()

计时暂停。

### reset

reset()

重置计时器。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct TextTimerExample {
  textTimerController: TextTimerController = new TextTimerController()
  @State format: string = 'hh:mm:ss.ms'

  build() {
    Column() {
      TextTimer({controller: this.textTimerController})
        .format(this.format)
        .fontColor(Color.Black)
        .fontSize(50)
        .onTimer((utc: number, elapsedTime: number) => {
          console.info('textTimer notCountDown utc is：' + utc + ', elapsedTime: ' + elapsedTime)
        })
      Row() {
        Button("start").onClick(() => {
          this.textTimerController.start();
        });
        Button("pause").onClick(() => {
          this.textTimerController.pause();
        });
        Button("reset").onClick(() => {
          this.textTimerController.reset();
        });
      }
    }
  }
}
```


![zh-cn_image_0000001251007721](figures/zh-cn_image_0000001251007721.gif)
