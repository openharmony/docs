# Focus Event

A focus event is triggered when the page focus moves between components. It can be used to change the content of a component.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Events

| Name                                  | Bubbling Supported| Description       |
| ---------------------------------------- | -------- | --------------- |
| onFocus(event: () =&gt; void) | No       | Triggered when the current component obtains focus.|
| onBlur(event:() =&gt; void)    | No       | Triggered when the current component loses focus.|

>  **NOTE**
>
>  The following components support focus events: **\<Button>**, **\<Text>**, **\<Image>**, **\<List>**, and **\<Grid>**.


## Example

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
