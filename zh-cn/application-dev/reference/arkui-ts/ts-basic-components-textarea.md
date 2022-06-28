# TextArea

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


提供多行文本输入组件。


## 权限列表

无


## 子组件

无


## 接口

TextArea(value?:{placeholder?: string, controller?: TextAreaController})

- 参数
  | 参数名                     | 参数类型                                     | 必填   | 默认值  | 参数描述           |
  | ----------------------- | ---------------------------------------- | ---- | ---- | -------------- |
  | placeholder             | string                                   | 否    | -    | 无输入时的提示文本。     |
  | controller<sup>8+</sup> | [TextAreaController](#textareacontroller8) | 否    | -    | 设置TextArea控制器。 |


## 属性

除支持通用属性外，还支持以下属性：

| 名称                       | 参数类型                                     | 默认值   | 描述                                       |
| ------------------------ | ---------------------------------------- | ----- | ---------------------------------------- |
| placeholderColor         | Color                                    | -     | 设置placeholder文本颜色。                       |
| placeholderFont          | {<br/>size?:&nbsp;number,<br/>weight?:number&nbsp;\|&nbsp;[FontWeight](ts-universal-attributes-text-style.md)，<br/>family?:&nbsp;string,<br/>style?:&nbsp;[FontStyle](ts-universal-attributes-text-style.md)<br/>} | -     | 设置placeholder文本样式：<br/>-&nbsp;size:&nbsp;设置文本尺寸，Length为number类型时，使用fp单位。<br/>-&nbsp;weight:&nbsp;设置文本的字体粗细，number类型取值[100,&nbsp;900]，取值间隔为100，默认为400，取值越大，字体越粗。<br/>-&nbsp;family:&nbsp;设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效，例如：'Arial,&nbsp;sans-serif'。<br/>-&nbsp;style:&nbsp;设置文本的字体样式。 |
| textAlign                | TextAlign                                | Start | 设置文本水平对齐方式。                              |
| caretColor               | Color                                    | -     | 设置输入框光标颜色。                               |
| inputFilter<sup>8+</sup> | {<br/>value:&nbsp;[ResourceStr](../../ui/ts-types.md)<sup>8+</sup>,<br/>error?:&nbsp;(value:&nbsp;string)<br/>} | -     | 通过正则表达式设置输入过滤器。满足表达式的输入允许显示，不满足的输入被忽略。仅支持单个字符匹配，不支持字符串匹配。例如：^(?=.\*\d)(?=.\*[a-z])(?=.\*[A-Z]).{8,10}$，不支持过滤8到10位的强密码。<br/>-&nbsp;value：设置正则表达式。<br/>-&nbsp;error：正则匹配失败时，返回被忽略的内容。 |

- TextAlign枚举说明
  | 名称     | 描述      |
  | ------ | ------- |
  | Start  | 水平对齐首部。 |
  | Center | 水平居中对齐。 |
  | End    | 水平对齐尾部。 |


## 事件

| 名称                                       | 功能描述                                     |
| ---------------------------------------- | ---------------------------------------- |
| onChange(callback:&nbsp;(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 输入发生变化时，触发回调。                            |
| onCopy<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 长按输入框内部区域弹出剪贴板后，点击剪切板复制按钮，触发回调。<br/>value：复制的文本内容。 |
| onCut<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 长按输入框内部区域弹出剪贴板后，点击剪切板剪切按钮，触发回调。<br/>value：剪切的文本内容。 |
| onPaste<sup>8+</sup>(callback:(value:&nbsp;string)&nbsp;=&gt;&nbsp;void) | 长按输入框内部区域弹出剪贴板后，点击剪切板粘贴按钮，触发回调。<br/>value：粘贴的文本内容。 |

## TextAreaController<sup>8+</sup>

TextArea组件的控制器，通过它操作TextArea组件。

### 导入对象

```
controller: TextAreaController = new TextAreaController()

```

### caretPosition<sup>8+</sup>

caretPosition(value: number): void

设置输入光标的位置。

- 参数
  | 参数名   | 参数类型   | 必填   | 默认值  | 参数描述                |
  | ----- | ------ | ---- | ---- | ------------------- |
  | value | number | 是    | -    | 从字符串开始到光标所在位置的字符长度。 |


## 示例


### 多行文本输入

```
@Entry
@Component
struct TextAreaExample1 {
  controller: TextAreaController = new TextAreaController()
  @State text: string = ''
  build() {
    Column() {
      TextArea({ placeholder: 'input your word', controller: this.controller})
        .placeholderColor("rgb(0,0,225)")
        .placeholderFont({ size: 30, weight: 100, family: 'cursive', style: FontStyle.Italic })
        .textAlign(TextAlign.Center)
        .caretColor(Color.Blue)
        .height(50)
        .fontSize(30)
        .fontWeight(FontWeight.Bold)
        .fontFamily("sans-serif")
        .fontStyle(FontStyle.Normal)
        .fontColor(Color.Red)
        .inputFilter('^[\u4E00-\u9FA5A-Za-z0-9_]+$',(value: string) => {
          console.info("hyb"+value)
        })
        .onChange((value: string) => {
          this.text = value
          this.controller.caretPosition(-1)
        })
      Text(this.text).width('90%')
    }
  }
}
```

![zh-cn_image_0000001251087311](figures/zh-cn_image_0000001251087311.gif)


### 设置光标

```
@Entry
@Component
struct TextAreaExample2 {
    controller: TextAreaController = new TextAreaController()
    build() {
        Column() {
            TextArea({ placeholder: 'input your word',controller:this.controller })
            Button('caretPosition')
                .onClick(() => {
                    this.controller.caretPosition(4)
                })
          }
    }
}
```

![zh-cn_image_0000001252653499](figures/zh-cn_image_0000001252653499.png)
