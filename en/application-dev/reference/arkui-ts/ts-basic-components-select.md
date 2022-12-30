#  Select

The **<Select\>** component provides a drop-down list box that allows users to select among multiple options.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Child Components

Not supported

## APIs

Select(options: Array\<[SelectOption](#selectoption)\>)

## SelectOption

| Name| Type                           | Mandatory| Description      |
| ------ | ----------------------------------- | ---- | -------------- |
| value  | [ResourceStr](ts-types.md#resourcestr) | Yes  | Value of an option in the drop-down list box.|
| icon   | [ResourceStr](ts-types.md#resourcestr) | No  | Icon of an option in the drop-down list box.|

## Attributes

| Name                   | Type                             | Description                                         |
| ----------------------- | ------------------------------------- | --------------------------------------------- |
| selected                | number                                | Index of the initial selected option in the drop-down list box. The index of the first option is **0**.|
| value                   | string                                | Text of the drop-down button.                 |
| font                    | [Font](ts-types.md#font)          | Text font of the drop-down button.                 |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor) | Text color of the drop-down button.                 |
| selectedOptionBgColor   | [ResourceColor](ts-types.md#resourcecolor) | Background color of the selected option in the drop-down list box.                 |
| selectedOptionFont      | [Font](ts-types.md#font)          | Text font of the selected option in the drop-down list box.               |
| selectedOptionFontColor | [ResourceColor](ts-types.md#resourcecolor) | Text color of the selected option in the drop-down list box.               |
| optionBgColor           | [ResourceColor](ts-types.md#resourcecolor) | Background color of an option in the drop-down list box.                     |
| optionFont              | [Font](ts-types.md#font)          | Text font of an option in the drop-down list box.                   |
| optionFontColor         | [ResourceColor](ts-types.md#resourcecolor) | Text color of an option in the drop-down list box.                   |

## Events

| Name                                                        | Description                                                  |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| onSelect(callback: (index: number, value?: string) => void) | Invoked when an option in the drop-down list box is selected.<br>**index**: index of the selected option.<br>**value**: value of the selected option. |

##  Example

```ts
// xxx.ets
@Entry
@Component
struct SelectExample {
  build() {
    Column() {
      Select([{ value: 'aaa', icon: "/common/public_icon.svg" },
        { value: 'bbb', icon: "/common/public_icon.svg" },
        { value: 'ccc', icon: "/common/public_icon.svg" },
        { value: 'ddd', icon: "/common/public_icon.svg" }])
        .selected(2)
        .value('TTTTT')
        .font({ size: 16, weight: 500 })
        .fontColor('#182431')
        .selectedOptionFont({ size: 16, weight: 400 })
        .optionFont({ size: 16, weight: 400 })
        .onSelect((index: number) => {
          console.info('Select:' + index)
        })
    }.width('100%')
  }
}
```

![](figures/select.png)
