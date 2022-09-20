# 焦点控制

>  **说明：**
> 从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 权限列表

无


## 属性

| **名称** | **参数类型** | **默认值** | **描述** | 
| -------- | -------- | -------- | -------- |
| focusable | boolean | false | 设置当前组件是否可以获焦。 | 

>  **说明：**
> 支持焦点控制的组件：Button、Text、Image、List、Grid。


## 示例

```ts
// xxx.ets
@Entry
@Component
struct FocusableExample {
  @State textOne: string = ''
  @State textTwo: string = ''
  @State textThree: string = 'The third button cannot be focused'
  @State oneButtonColor: string = '#FF0000'
  @State twoButtonColor: string = '#FFC0CB'
  @State threeButtonColor: string = '#87CEFA'

  build() {
    Column({ space:20 }){
      Button(this.textOne)
        .backgroundColor(this.oneButtonColor)
        .width(300).height(70).fontColor(Color.Black)
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
        .width(300).height(70).fontColor(Color.Black)
        .focusable(true)
        .onFocus(() => {
          this.textTwo = 'Second Button onFocus'
          this.twoButtonColor = '#AFEEEE'
        })
        .onBlur(() => {
          this.textTwo = 'Second Button onBlur'
          this.twoButtonColor = '#FFC0CB'
        })
      Button(this.textThree)
        .backgroundColor(this.threeButtonColor)
        .width(300).height(70).fontColor(Color.Black)
        .focusable(false)
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
