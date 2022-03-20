# Focus Control


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This attribute is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes

  | **Name** | **Type** | **Default Value** | **Description** | 
| -------- | -------- | -------- | -------- |
| focusable | boolean | false | Whether the current component is focusable. | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The following components support focus control: **&lt;Button&gt;**, **&lt;Text&gt;**, **&lt;Image&gt;**, **&lt;List&gt;**, and **&lt;Grid&gt;**.


## Example

  
```
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
