# Focus Event


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Events

  | **Name** | **Bubble Supported** | **Description** | 
| -------- | -------- | -------- |
| onFocus(callback: () =&gt; void) | No | Triggered when the current component obtains focus. | 
| onBlur(callback:() =&gt; void) | No | Triggered when the current component loses focus. | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The following components support focus events: **&lt;Button&gt;**, **&lt;Text&gt;**, **&lt;Image&gt;**, **&lt;List&gt;**, and **&lt;Grid&gt;**.


## Example

  
```
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
