# Focus Control

>  **NOTE**<br>
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| focusable | boolean | false | Whether the current component is focusable.|
| tabIndex<sup>9+<sup> | number | 0 | How the current component participates in sequential keyboard navigation.<br>- **tabIndex** >= 0: The component is focusable in sequential keyboard navigation, with its order defined by the value. A component with a larger value is focused after one with a smaller value. If multiple components share the same **tabIndex** value, their focus order follows their position in the component tree.<br>- **tabIndex** < 0 (usually **tabIndex** = -1): The component is focusable, but cannot be reached through sequential keyboard navigation. |

>  **NOTE**<br>
> The following components support focus control: **\<Button>**, **\<Text>**, **\<Image>**, **\<List>**, and **\<Grid>**.


## Example

```ts
// xxx.ets
@Entry
@Component
struct FocusableExample {
  @State text1: string = 'TabIndex=3'
  @State text2: string = 'TabIndex=2'
  @State text3: string = 'focusable=false'
  @State text4: string = 'TabIndex=-1'
  @State text5: string = 'TabIndex=1'
  @State text6: string = 'TabIndex=1'
  @State text7: string = 'focusable=true'
  @State text8: string = 'focusable=true'

  build() {
    Column({ space:20 }){
      Button(this.text1)  // This component is the fourth component that is focused when the Tab key is pressed.
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(3)
      Button(this.text2)  // This component is the third component that is focused when the Tab key is pressed.
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(2)
      Button(this.text3)  // This component is not focusable.
        .width(300).height(70).fontColor(Color.Black)
        .focusable(false)
      Button(this.text4) // This component is focusable, but cannot be reached through sequential keyboard navigation.
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(-1)
      Button(this.text5)  // This component is the first component that is focused when the Tab key is pressed.
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(1)
      Button(this.text6)  // This component is the second component that is focused when the Tab key is pressed.
        .width(300).height(70).fontColor(Color.Black)
        .tabIndex(1)
      Button(this.text7)  // This component is the fifth component that is focused when the Tab key is pressed.
        .width(300).height(70).fontColor(Color.Black)
        .focusable(true)
      Button(this.text8)  // This component is the sixth component that is focused when the Tab key is pressed.
        .width(300).height(70).fontColor(Color.Black)
        .focusable(true)
    }.width('100%').margin({ top:20 })
  }
}
```
