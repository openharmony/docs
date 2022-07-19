# TextPicker


The **\<TextPicker>** component allows users to select text from a list of options.


> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

Not supported


## APIs

TextPicker(value: {range: string[] | Resource, value?: string, selected?: number})

Creates a text picker based on the selection range specified by **range**.

- Parameters
  | Name | Type | Mandatory | Default Value | Description |
  | -------- | -------- | -------- | -------- | -------- |
  | range | string[]\|&nbsp;[Resource](../../ui/ts-types.md) | Yes | - | Data selection range of the picker. |
  | value | string | No | - | Search text. |
  | selected | number | No | Index of the first item | Index of the selected item in the array. |


## Attributes

| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| defaultPickerItemHeight | Length | - | Default height of an item in the picker. |


## Events

| Name | Description |
| -------- | -------- |
| onChange(callback: (value: string, index: number) =&gt; void) | Triggered when an item in the picker is selected.<br/>- **value**: text of the selected item.<br/>- **index**: index of the selected item. |


## Example


```ts
// xxx.ets
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
