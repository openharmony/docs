# TextPicker


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;TextPicker&gt;** component allows users to select text from a list of options.


## Required Permissions

None


## Child Component

None


## APIs

TextPicker(value: {range: string[], selected?: number})

Creates a text picker based on the selection range specified by **range**.

- Parameter
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | range | string[] | Yes | - | Data&nbsp;selection&nbsp;range&nbsp;of&nbsp;the&nbsp;picker. | 
  | selected | number | No | First&nbsp;element | Index&nbsp;value&nbsp;of&nbsp;the&nbsp;selected&nbsp;item&nbsp;in&nbsp;the&nbsp;array. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| defaultPickerItemHeight | Length | - | Default&nbsp;height&nbsp;of&nbsp;a&nbsp;Picker&nbsp;content&nbsp;item&nbsp;element. | 


## Events

  | Name | Description | 
| -------- | -------- | 
| onChange(callback:&nbsp;(value:&nbsp;string,&nbsp;index:&nbsp;number)&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;an&nbsp;item&nbsp;in&nbsp;the&nbsp;picker&nbsp;is&nbsp;selected.<br/>-&nbsp;**value**:&nbsp;text&nbsp;of&nbsp;the&nbsp;selected&nbsp;item.<br/>-&nbsp;**index**:&nbsp;index&nbsp;of&nbsp;the&nbsp;selected&nbsp;item. | 


## Example


```
@Entry
@Component
struct TextPickerExample {
  private select: number = 1
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4']

  build() {
    Column() {
      TextPicker({range: this.fruits, selected: this.select})
        .onChange((value: string, index: number) => {
          console.info('Picker item changed, value: ' + value + ', index: ' + index)
        })
    }
  }
}
```

![en-us_image_0000001257058417](figures/en-us_image_0000001257058417.png)
