# TextPicker

The **TextPicker** component allows users to scroll to select text.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

Not supported


## APIs

TextPicker(value: {range: string[] | Resource, value?: string, selected?: number})

Creates a text picker based on the selection range specified by **range**.

- Parameters
  | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | range | string[] \| [Resource](../../ui/ts-types.md#resource-type)| Yes| - | Data selection range of the picker.|
  | value | string | No | - | Value of the selected item. This parameter does not take effect when the **selected** parameter is set. If the value is not within the range, the first item in the range is used instead. |
  | selected | number | No| First item | Index of the selected item in the range.        |


## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| defaultPickerItemHeight | Length | - | Default height of an item in the picker.|


## Events

| Name| Description|
| -------- | -------- |
| onChange(callback: (value: string, index: number) =&gt; void) | Triggered when an item in the picker is selected.<br>- **value**: value of the selected item.<br>- **index**: index of the selected item.|


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
