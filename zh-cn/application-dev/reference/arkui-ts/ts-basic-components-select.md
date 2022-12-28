#  Select

提供下拉选择菜单，可以让用户在多个选项之间选择。

>  **说明：** 
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

Select(options: Array\<[SelectOption](#selectoption对象说明)\>)

## SelectOption对象说明

| 参数名 | 参数类型                            | 必填 | 参数描述       |
| ------ | ----------------------------------- | ---- | -------------- |
| value  | [ResourceStr](ts-types.md#resourcestr) | 是   | 下拉选项内容。 |
| icon   | [ResourceStr](ts-types.md#resourcestr) | 否   | 下拉选项图片。 |

## 属性

| 名称                    | 参数类型                              | 描述                                          |
| ----------------------- | ------------------------------------- | --------------------------------------------- |
| selected                | number                                | 设置下拉菜单初始选项的索引，第一项的索引为0。 |
| value                   | string                                | 设置下拉按钮本身的文本内容。                  |
| font                    | [Font](ts-types.md#font)          | 设置下拉按钮本身的文本样式。                  |
| fontColor               | [ResourceColor](ts-types.md#resourcecolor) | 设置下拉按钮本身的文本颜色。                  |
| selectedOptionBgColor   | [ResourceColor](ts-types.md#resourcecolor) | 设置下拉菜单选中项的背景色。                  |
| selectedOptionFont      | [Font](ts-types.md#font)          | 设置下拉菜单选中项的文本样式。                |
| selectedOptionFontColor | [ResourceColor](ts-types.md#resourcecolor) | 设置下拉菜单选中项的文本颜色。                |
| optionBgColor           | [ResourceColor](ts-types.md#resourcecolor) | 设置下拉菜单项的背景色。                      |
| optionFont              | [Font](ts-types.md#font)          | 设置下拉菜单项的文本样式。                    |
| optionFontColor         | [ResourceColor](ts-types.md#resourcecolor) | 设置下拉菜单项的文本颜色。                    |

## 事件

| 名称                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onSelect(callback: (index: number, value?:&nbsp;string) => void) | 下拉菜单选中某一项的回调。<br/>index：选中项的索引。<br/>value：选中项的值。 |

##  示例

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