#  Search

> **说明：** 该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

提供搜索框组件，用于提供用户搜索内容的输入区域。

## 权限列表

无

## 子组件

无

## 接口

Search(options?: { value?: string; placeholder?: string; icon?: string; controller?: SearchController })

- 参数

  | 参数名         | 参数类型             | 必填   | 默认值  | 参数描述                                     |
  | ----------- | ---------------- | ---- | ---- | ---------------------------------------- |
  | value       | string           | 否    | -    | 搜索文本值。                                   |
  | placeholder | string           | 否    | -    | 无输入时的提示文本。                               |
  | icon        | string           | 否    | -    | 搜索图标路径，默认使用系统搜索图标，支持的图标格式: svg, jpg和png。 |
  | controller  | SearchController | 否    | -    | 控制器。                                     |


## 属性

| 名称               | 参数类型                                  | 默认值  | 描述                    |
| ---------------- | ------------------------------------- | ---- | --------------------- |
| searchButton     | string                                | 无    | 搜索框末尾搜索按钮文本值，默认无搜索按钮。 |
| placeholderColor | [ResourceColor](../../ui/ts-types.md) | -    | 设置placeholder颜色。      |
| placeholderFont  | [Font](../../ui/ts-types.md)          | -    | 设置placeholder文本样式。    |
| textFont         | [Font](../../ui/ts-types.md)          | -    | 设置搜索框内文本样式。           |
| copyOption<sup>9+</sup> | boolean\|[CopyOption](ts-basic-components-text.md) | true | 设置文本是否可复制。 |

## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onSubmit(callback: (value: string) => void) | 点击搜索图标、搜索按钮或者按下软键盘搜索按钮时触发。<br> -value: 当前输入文本框的内容。 |
| onChange(callback: (value: string) => void) | 输入内容发生变化时，触发回调。<br> -value: 当前输入文本框的内容。  |
| onCopy(callback: (value: string) => void) | 组件触发系统剪切板复制操作。<br> -value: 复制的文本内容。      |
| onCut(callback: (value: string) => void) | 组件触发系统剪切板剪切操作。<br> -value: 剪切的文本内容。      |
| onPaste(callback: (value: string) => void) | 组件触发系统剪切板粘贴操作。<br> -value: 粘贴的文本内容。      |

## SearchController

Search组件的控制器，通过它操作Search组件。

#### 导入对象
```
controller: SearchController = new SearchController()
```
#### caretPosition

creatPosition(value: number): void

设置输入光标的位置。

- 参数

  | 参数名   | 参数类型   | 必填   | 默认值  | 参数描述              |
  | ----- | ------ | ---- | ---- | ----------------- |
  | value | number | 是    | -    | 从字符串开始到光标所在位置的长度。 |



##  示例

```ts
// xxx.ets
@Entry
@Component
struct SearchExample {
  @State changevalue: string = ''
  @State submitvalue: string = ''
  controller: SearchController = new SearchController()

  build() {
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {
      Text(this.submitvalue)
      Text(this.changevalue)
      Search({value: '', placeholder: 'Type to search', controller: this.controller})
        .searchButton('Search')
        .width(400)
        .height(35)
        .backgroundColor(Color.White)
        .placeholderColor(Color.Grey)
        .placeholderFont({ size: 50, weight: 10, family: 'serif', style: FontStyle.Normal })
        .onSubmit((value: string) => {
          this.submitvalue = value
        })
        .onChange((value: string) => {
          this.changevalue = value
        })
        .margin({ top: 30 })
    }
  }
}
```
