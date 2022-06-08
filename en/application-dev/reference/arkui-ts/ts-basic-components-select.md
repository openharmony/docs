#  Select

> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **<Select\>** component provides a drop-down list box that allows users to select among multiple options.

## Required Permissions

None

## Child Components

None

## APIs

Select(options: Array\<SelectOption>\)

- SelectOption parameters

  | Name| Type| Mandatory| Default Value| Description|
  | ------ | ----------------------------------------------- | ---- | ------ | -------------- |
  | value | [ResourceStr](../../ui/ts-types.md) | Yes | - | Value of an option in the drop-down list box. |
  | icon | [ResourceStr](../../ui/ts-types.md) | No | - | Icon of an option in the drop-down list box. |

## Attributes

| Name| Type| Default Value| Description|
| ----------------------- | --------------------------------------------------- | ------ | ----------------------------------------------- |
| selected                | number                                              | -      | Index of the initial selected option in the drop-down list box. The index of the first option is **0**. |
| value                   | string                                              | -      | Text of the drop-down button. |
| font                    | [Font](../../ui/ts-types.md) | -      | Text font of the drop-down button. |
| fontColor               | [ResourceColor](../../ui/ts-types.md) | -      | Text color of the drop-down button. |
| selectedOptionBgColor   | [ResourceColor](../../ui/ts-types.md) | -      | Background color of the selected option in the drop-down list box. |
| selectedOptionFont      | [Font](../../ui/ts-types.md) | -      | Text font of the selected option in the drop-down list box. |
| selectedOptionFontColor | [ResourceColor](../../ui/ts-types.md) | -      | Text color of the selected option in the drop-down list box. |
| optionBgColor           | [ResourceColor](../../ui/ts-types.md) | -      | Background color of an option in the drop-down list box. |
| optionFont              | [Font](../../ui/ts-types.md) | -      | Text font of an option in the drop-down list box. |
| optionFontColor         | [ResourceColor](../../ui/ts-types.md) | -      | Text color of an option in the drop-down list box. |

## Events

| Name| Description|
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onSelect(callback: (index: number, value?:string) => void) | Invoked when an option in the drop-down list box is selected. **index** indicates the index of the selected option. **value** indicates the value of the selected option. |

##  Example

```
@Entry
@Component
struct SelectExample {
  build() {
    Column() {
      Select([{value:'aaa',icon: "/common/1.png"},
              {value:'bbb',icon: "/common/2.png"},
              {value:'ccc',icon: "/common/3.png"},
              {value:'ddd',icon: "/common/4.png"}])
        .selected(2)
        .value('TTT')
        .font({size: 30, weight:400, family: 'serif', style: FontStyle.Normal })
        .selectedOptionFont({size: 40, weight: 500, family: 'serif', style: FontStyle.Normal })
        .optionFont({size: 30, weight: 400, family: 'serif', style: FontStyle.Normal })
        .onSelecte((index:number)=>{
          console.info("Select:" + index)
        })
    }
  }
}
```

![](figures/select.png)
