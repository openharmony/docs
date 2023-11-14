#  Search

搜索框组件，适用于浏览器的搜索内容输入框等应用场景。

> **说明：**
>
> 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 子组件

无

## 接口

Search(options?: { value?: string, placeholder?: ResourceStr, icon?: string, controller?: SearchController })

**参数:**

| 参数名      | 参数类型                                             | 必填 | 参数描述                                                     |
| ----------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value       | string                                               | 否   | 设置当前显示的搜索文本内容。<br />从API version 10开始，该参数支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |
| placeholder | [ResourceStr](ts-types.md#resourcestr)<sup>10+</sup> | 否   | 设置无输入时的提示文本。                                     |
| icon        | string                                               | 否   | 设置搜索图标路径，默认使用系统搜索图标。<br/>**说明：** <br/>icon的数据源支持本地图片和网络图片。<br/>-&nbsp;支持的图片格式包括png、jpg、bmp、svg、gif和pixelmap。<br/>-&nbsp;支持Base64字符串。格式data:image/[png\|jpeg\|bmp\|webp];base64,[base64 data], 其中[base64 data]为Base64字符串数据。<br/>如果与属性searchIcon同时设置，则searchIcon优先。 |
| controller  | SearchController                                     | 否   | 设置Search组件控制器。                                       |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称                    | 参数类型                                         | 描述                                           |
| ----------------------- | ------------------------------------------------ | ---------------------------------------------- |
| searchButton<sup>10+</sup> | value: string,<br />option?: [SearchButtonOptions](#searchbuttonoptions10对象说明)            | 搜索框末尾搜索按钮文本内容，默认无搜索按钮。               |
| placeholderColor        | [ResourceColor](ts-types.md#resourcecolor)       | 设置placeholder文本颜色。<br />默认值：'#99182431'。   |
| placeholderFont         | [Font](ts-types.md#font)                         | 设置placeholder文本样式，包括字体大小，字体粗细，字体族，字体风格。目前仅支持默认字体族。                         |
| textFont                | [Font](ts-types.md#font)                         | 设置搜索框内输入文本样式，包括字体大小，字体粗细，字体族，字体风格。目前仅支持默认字体族。                           |
| textAlign               | [TextAlign](ts-appendix-enums.md#textalign)      | 设置文本在搜索框中的对齐方式。目前支持的对齐方式有：Start、Center、End。<br/>默认值：TextAlign.Start    |
| copyOption<sup>9+</sup> | [CopyOptions](ts-appendix-enums.md#copyoptions9) | 设置输入的文本是否可复制。<br />默认值：CopyOptions.LocalDevice，支持设备内复制。<br/>设置CopyOptions.None时，当前Search中的文字无法被复制或剪切，仅支持粘贴。<br> 从API Version 11开始，支持设置CopyOptions.CROSS_DEVICE。|
| searchIcon<sup>10+</sup>   | [IconOptions](#iconoptions10对象说明)                                                  | 设置左侧搜索图标样式。                                       |
| cancelButton<sup>10+</sup> | {<br/>style? : [CancelButtonStyle](#cancelbuttonstyle10枚举说明)<br/>icon?: [IconOptions](#iconoptions10对象说明) <br/>} | 设置右侧清除按钮样式。<br />默认值：<br />{<br />style：CancelButtonStyle.INPUT<br />} |
| fontColor<sup>10+</sup>    | [ResourceColor](ts-types.md#resourcecolor)                   | 设置输入文本的字体颜色。<br />默认值：'#FF182431'。<br />**说明：**<br />[文本通用属性](ts-universal-attributes-text-style.md)fontSize、fontStyle、fontWeight和fontFamily在textFont属性中设置。 |
| caretStyle<sup>10+</sup>  | [CaretStyle](#caretstyle10对象说明)                                                  | 设置光标样式。<br />默认值：<br />{<br />width: '1.5vp',<br />color: '#007DFF'<br />} |
| enableKeyboardOnFocus<sup>10+</sup> | boolean | Search获焦时，是否绑定输入法<br/>默认值：true。从API version 10开始，获焦默认绑定输入法。 |
| selectionMenuHidden<sup>10+</sup> | boolean | 设置长按输入框或者右键输入框时，是否弹出文本选择菜单。<br />默认值：false |
| customKeyboard<sup>10+</sup> | [CustomBuilder](ts-types.md#custombuilder8) | 设置自定义键盘。<br/>**说明：**<br/>当设置自定义键盘时，输入框激活后不会打开系统输入法，而是加载指定的自定义组件。<br/>自定义键盘的高度可以通过自定义组件根节点的height属性设置，宽度不可设置，使用系统默认值。<br/>自定义键盘采用覆盖原始界面的方式呈现，不会对应用原始界面产生压缩或者上提。<br/>自定义键盘无法获取焦点，但是会拦截手势事件。<br/>默认在输入控件失去焦点时，关闭自定义键盘，开发者也可以通过[stopEditing](#stopediting10)方法控制键盘关闭。 | 
| type<sup>11+</sup>                     | [SearchType](#searchtype11枚举说明)     | 设置输入框类型。<br/>默认值：SearchType.Normal        |
| maxLength<sup>11+</sup>   | number                                                       | 设置文本的最大输入字符数。<br/>默认不设置最大输入字符数限制。<br/>到达文本最大字符限制，将无法继续输入字符。 | 

## IconOptions<sup>10+</sup>对象说明

| 参数名 | 参数类型                                   | 必填 | 参数描述    |
| ------ | ------------------------------------------ | ---- | ----------- |
| size   | [Length](ts-types.md#length)               | 否   | 图标尺寸，不支持百分比。    |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 否   | 图标颜色。    |
| src    | [ResourceStr](ts-types.md#resourcestr)     | 否   | 图标/图片源。 |

## CaretStyle<sup>10+</sup>对象说明

| 参数名 | 参数类型                                   | 必填 | 参数描述 |
| ------ | ------------------------------------------ | ---- | -------- |
| width  | [Length](ts-types.md#length)               | 否   | 光标尺寸，不支持百分比。 |
| color  | [ResourceColor](ts-types.md#resourcecolor) | 否   | 光标颜色。 |

## SearchButtonOptions<sup>10+</sup>对象说明

| 参数名    | 参数类型                                   | 必填 | 参数描述         |
| --------- | ------------------------------------------ | ---- | ---------------- |
| fontSize  | [Length](ts-types.md#length)               | 否   | 文本按钮字体大小，不支持百分比。 |
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否   | 文本按钮字体颜色。 |

## CancelButtonStyle<sup>10+</sup>枚举说明

| 名称                    | 描述             |
| ----------------------- | ---------------- |
| CONSTANT  | 清除按钮常显样式。 |
| INVISIBLE | 清除按钮常隐样式。 |
| INPUT     | 清除按钮输入样式。 |

## SearchType<sup>11+</sup>枚举说明

| 名称                 | 描述            |
| ------------------ | ------------- |
| Normal   | 基本输入模式。<br/>支持输入数字、字母、下划线、空格、特殊字符。 |
| Email    | 邮箱地址输入模式。支持数字，字母，下划线，以及@字符（只能存在一个@字符）。 |
| Number   | 纯数字输入模式。      |
| PhoneNumber | 电话号码输入模式。<br/>支持输入数字、+ 、-、*、#，长度不限。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onSubmit(callback: (value: string) => void)                  | 点击搜索图标、搜索按钮或者按下软键盘搜索按钮时触发该回调。<br> -value: 当前搜索框中输入的文本内容。 |
| onChange(callback: (value: string) => void)                  | 输入内容发生变化时，触发该回调。<br> -value: 当前搜索框中输入的文本内容。 |
| onCopy(callback: (value: string) => void)                    | 长按搜索框弹出剪切板之后，点击剪切板的复制按钮触发该回调。<br> -value: 复制的文本内容。 |
| onCut(callback: (value: string) => void)                     | 长按搜索框弹出剪切板之后，点击剪切板的剪切按钮触发该回调。<br> -value: 剪切的文本内容。 |
| onPaste(callback: (value: string) => void)                   | 长按搜索框弹出剪切板之后，点击剪切板的粘贴按钮触发该回调。<br> -value: 粘贴的文本内容。 |
| onTextSelectionChange(callback: (selectionStart: number, selectionEnd: number) => void)<sup>10+</sup> | 文本选择的位置发生变化时，触发该回调。<br />selectionStart：文本选择区域起始位置，文本框中文字的起始位置为0。<br />selectionEnd：文本选择区域结束位置。 |
| onContentScroll(callback: (totalOffsetX: number, totalOffsetY: number) => void)<sup>10+</sup> | 文本内容滚动时，触发该回调。<br />totalOffsetX：文本在内容区的横坐标偏移。<br />totalOffsetY：文本在内容区的纵坐标偏移。 |

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

### stopEditing<sup>10+</sup>

stopEditing(): void

退出编辑态。

### getTextContentRect<sup>10+</sup>

getTextContentRect(): [RectResult](#rectresult)

获取已编辑文本内容区域相对组件的位置和大小，返回值单位为像素。

**返回值：**

| 类型       | 说明       |
| -------------------  | -------- |
| [RectResult](#rectresult) | 已编辑文本内容的相对组件的位置和大小。 |

> **说明：**
>
> - 返回的位置信息是相对Search组件中搜索图标的偏移值。
> - 不输入文本时，返回值中有相对Search组件的位置信息，但大小为0。
> - 返回值中的位置信息是第一个字符相对于可编辑组件的位置。

### RectResult<sup>10+</sup>

位置和大小。

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| x     | number | 水平方向横坐标。|
| y     | number | 竖直方向纵坐标。|
| width | number | 内容宽度大小。|
| height | number | 内容高度大小。|


### getTextContentLineCount<sup>10+</sup>

getTextContentLineCount(): number

获取已编辑文本内容的行数。

**返回值：**

| 类型  | 说明       |
| ----- | -------- |
| number| 已编辑文本内容行数。 |

### getCaretOffset<sup>11+</sup>

getCaretOffset(): [CaretOffset](ts-basic-components-textinput.md#caretoffset11对象说明)

返回当前光标所在位置信息。

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| [CaretOffset](ts-basic-components-textinput.md#caretoffset11对象说明) | 光标相对输入框的位置 |

##  示例

### 示例1

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
        .width('95%')
        .height(40)
        .backgroundColor('#F5F5F5')
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

### 示例2

```ts
// xxx.ets
@Entry
@Component
struct SearchButtoonExample {
  @State submitValue: string = ''

  build() {
    Column() {
      Text('onSubmit:' + this.submitValue).fontSize(18).margin(15)
      Search({ placeholder: 'Type to search...' })
        .searchButton('SEARCH')
        .searchIcon({
          src: $r('app.media.search')
        })
        .cancelButton({
          style: CancelButtonStyle.CONSTANT,
          icon: {
            src: $r('app.media.cancel')
          }
        })
        .width('90%')
        .height(40)
        .backgroundColor('#F5F5F5')
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 14, weight: 400 })
        .textFont({ size: 14, weight: 400 })
        .onSubmit((value: string) => {
          this.submitValue = value
        })
        .margin(20)
    }.width('100%')
  }
}
```

![searchButton](figures/searchButton.gif)


### 示例3

```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  controller: SearchController = new SearchController()
  @State inputValue: string = ""

  // 自定义键盘组件
  @Builder CustomKeyboardBuilder() {
    Column() {
      Button('x').onClick(() => {
        // 关闭自定义键盘
        this.controller.stopEditing()
      })
      Grid() {
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item: number | string) => {
          GridItem() {
            Button(item + "")
              .width(110).onClick(() => {
              this.inputValue += item
            })
          }
        })
      }.maxCount(3).columnsGap(10).rowsGap(10).padding(5)
    }.backgroundColor(Color.Gray)
  }

  build() {
    Column() {
      Search({ controller: this.controller, value: this.inputValue})
        // 绑定自定义键盘
        .customKeyboard(this.CustomKeyboardBuilder()).margin(10).border({ width: 1 })
    }
  }
}
````

![customKeyboard](figures/searchCustomKeyboard.png)