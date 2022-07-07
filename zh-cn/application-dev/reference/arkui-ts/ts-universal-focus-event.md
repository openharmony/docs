# 焦点事件

焦点事件指页面焦点在组件间移动时触发的事件，组件可使用焦点事件来更改内容。

>  **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 事件

| **名称** | **支持冒泡** | **功能描述** |
| -------- | -------- | -------- |
| onFocus(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | 否 | 当前组件获取焦点时触发的回调。 |
| onBlur(callback:()&nbsp;=&gt;&nbsp;void) | 否 | 当前组件失去焦点时触发的回调。 |

>  **说明：**
> 支持焦点事件的组件：Button、Text、Image、List、Grid。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct FocusEventExample {
  @State textOne: string = ''
  @State textTwo: string = ''
  @State textThree: string = ''
  @State oneButtonColor: string = '#FF0000'
  @State twoButtonColor: string = '#87CEFA'
  @State threeButtonColor: string = '#90EE90'

  build() {
    Column({ space:20 }){
      Button(this.textOne)
        .backgroundColor(this.oneButtonColor)
        .width(260).height(70).fontColor(Color.Black)
        .focusable(true)
        .onFocus(() => {
          this.textOne = 'First Button onFocus'
          this.oneButtonColor = '#AFEEEE'
        })
        .onBlur(() => {
          this.textOne = 'First Button onBlur'
          this.oneButtonColor = '#FFC0CB'
        })
      Button(this.textTwo)
        .backgroundColor(this.twoButtonColor)
        .width(260).height(70).fontColor(Color.Black)
        .focusable(true)
      Button(this.textThree)
        .backgroundColor(this.threeButtonColor)
        .width(260).height(70).fontColor(Color.Black)
        .focusable(true)
        .onFocus(() => {
          this.textThree = 'Third Button onFocus'
          this.threeButtonColor = '#AFEEEE'
        })
        .onBlur(() => {
          this.textThree = 'Third Button onBlur'
          this.threeButtonColor = '#FFC0CB'
        })
    }.width('100%').margin({ top:20 })
  }
}
```
