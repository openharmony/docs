# TextPicker

The **TextPicker** component allows users to scroll to select text.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

TextPicker(options?: {range: string[] | [Resource](ts-types.md#resource), selected?: number, value?: string})

Creates a text picker based on the selection range specified by **range**.

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| range | string[] \| [Resource](ts-types.md#resource)| Yes| Data selection range of the picker.|
| selected | number | No| Index of the selected item in the range.<br>Default value: **0**|
| value | string | No| Value of the selected item. The priority of this parameter is lower than that of **selected**.<br>Default value: value of the first item|

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| defaultPickerItemHeight | number \| string | Default height of an item in the picker.|

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
