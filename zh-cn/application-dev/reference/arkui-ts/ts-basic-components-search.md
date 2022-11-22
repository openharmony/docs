#  Search

搜索框组件，适用于浏览器的搜索内容输入框等应用场景。

> **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

Search(options?: { value?: string; placeholder?: string; icon?: string; controller?: SearchController })

**参数:**

| 参数名      | 参数类型         | 必填 | 参数描述                                                     |
| ----------- | ---------------- | ---- | ------------------------------------------------------------ |
| value       | string           | 否   | 设置当前显示的搜索文本内容。                                                 |
| placeholder | string           | 否   | 设置无输入时的提示文本。                                         |
| icon        | string           | 否   | 设置搜索图标路径，默认使用系统搜索图标，图标支持的图源格式: svg、jpg和png。 |
| controller  | SearchController | 否   | 设置Search组件控制器。                                                     |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                    | 参数类型                                         | 描述                                           |
| ----------------------- | ------------------------------------------------ | ---------------------------------------------- |
| searchButton            | string                                           | 搜索框末尾搜索按钮文本内容，默认无搜索按钮。         |
| placeholderColor        | [ResourceColor](ts-types.md#resourcecolor)       | 设置placeholder文本颜色。                           |
| placeholderFont         | [Font](ts-types.md#font)                         | 设置placeholder文本样式。                           |
| textFont                | [Font](ts-types.md#font)                         | 设置搜索框内输入文本样式。                               |
| textAlign               | [TextAlign](ts-appendix-enums.md#textalign)      | 设置文本在搜索框中的对齐方式。<br/>默认值：TextAlign.Start    |
| copyOption<sup>9+</sup> | [CopyOptions](ts-appendix-enums.md#copyoptions9) | 设置输入的文本是否可复制。                             |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onSubmit(callback: (value: string) => void) | 点击搜索图标、搜索按钮或者按下软键盘搜索按钮时触发该回调。<br> -value: 当前搜索框中输入的文本内容。 |
| onChange(callback: (value: string) => void) | 输入内容发生变化时，触发该回调。<br> -value: 当前搜索框中输入的文本内容。  |
| onCopy(callback: (value: string) => void) | 长按搜索框弹出剪切板之后，点击剪切板的复制按钮触发该回调。<br> -value: 复制的文本内容。      |
| onCut(callback: (value: string) => void)  | 长按搜索框弹出剪切板之后，点击剪切板的剪切按钮触发该回调。<br> -value: 剪切的文本内容。      |
| onPaste(callback: (value: string) => void) | 长按搜索框弹出剪切板之后，点击剪切板的粘贴按钮触发该回调。<br> -value: 粘贴的文本内容。      |

## SearchController

Search组件的控制器，目前通过它可控制Search组件的光标位置。

### 导入对象
```
controller: SearchController = new SearchController()
```
### caretPosition

caretPosition(value: number): void

设置输入光标的位置。

**参数:**

| 参数名 | 参数类型 | 必填 | 参数描述                           |
| ------ | -------- | ---- | ---------------------------------- |
| value  | number   | 是   | 从字符串开始到光标所在位置的长度。 |

##  示例

```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  @State changeValue: string = ''
  @State submitValue: string = ''
  controller: SearchController = new SearchController()

  build() {
    Column() {
      Text('onSubmit:' + this.submitValue).fontSize(18).margin(15)
      Text('onChange:' + this.changeValue).fontSize(18).margin(15)
      Search({ value: this.changeValue, placeholder: 'Type to search...', controller: this.controller })
        .searchButton('SEARCH')
        .width(400)
        .height(40)
        .backgroundColor(Color.White)
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .textFont({ size: 14, weight: 400 })
        .onSubmit((value: string) => {
          this.submitValue = value
        })
        .onChange((value: string) => {
          this.changeValue = value
        })
        .margin(20)
      Button('Set caretPosition 1')
        .onClick(() => {
          // 设置光标位置到输入的第一个字符后
          this.controller.caretPosition(1)
        })
    }.width('100%')
  }
}
```

![search](figures/search.gif)
