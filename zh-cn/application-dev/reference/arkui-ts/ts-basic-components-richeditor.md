# RichEditor

支持图文混排和文本交互式编辑的组件。

>  **说明：**
>
>  该组件从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含[Span](ts-basic-components-span.md)和[ImageSpan](ts-basic-components-imagespan.md)子组件。


## 接口

RichEditor(value: RichEditorOptions)

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | [RichEditorOptions](#richeditoroptions)  | 是 | 富文本组件初始化选项。 |


## 属性

支持[通用属性](ts-universal-attributes-size.md)。

## 事件

除支持[通用事件](ts-universal-events-click.md)外，还支持以下事件：

| 名称                                                         | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| onReady(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | 富文本组件初始化完成后，触发回调。 |
| onSelect(callback:&nbsp;(value:&nbsp;[RichEditorSelection](#richeditorselection))&nbsp;=&gt;&nbsp;void) | 鼠标左键按下选择，松开左键后触发回调。<br />- value：选中的所有span信息。 |
| aboutToIMEInput(callback:&nbsp;(value:&nbsp;[RichEditorInsertValue](#richeditorinsertvalue))&nbsp;=&gt;&nbsp;boolean) | 输入法输入内容前，触发回调。<br />- value：输入法将要输入内容信息。|
| onIMEInputComplete(callback:&nbsp;(value:&nbsp;[RichEditorTextSpanResult](#richeditortextspanresult))&nbsp;=&gt;&nbsp;void) | 输入法输完成输入后，触发回调。<br />- value：输入法完成输入后的文本Span信息。 |
| aboutToDelete(callback:&nbsp;(value:&nbsp;[RichEditorDeleteValue](#richeditordeletevalue))&nbsp;=&gt;&nbsp;boolean) | 输入法删除内容前，触发回调。 <br />- value：准备删除的内容所在的文本Span信息。|
| onDeleteComplete(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | 输入法完成删除后，触发回调。 |

## RichEditorInsertValue

插入文本信息。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| insertOffset | number  | 是 | 插入的文本偏移位置。 |
| insertValue | string  | 是 | 插入的文本内容。 |


## RichEditorDeleteValue

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| offset | number  | 是 | 删除内容的偏移位置。 |
| direction | [RichEditorDeleteDirection](#richeditordeletedirection)  | 是 | 删除操作的方向。 |
| length | number | 是 | 删除内容长度。 |
| richEditorDeleteSpans | Array<[RichEditorTextSpanResult](#richeditortextspanresult) \| [RichEditorImageSpanResult](#richeditorimagespanresult)> | 是 | 删除的文本或者图片Span的具体信息。 |


## RichEditorDeleteDirection

删除操作的方向。

| 名称    | 描述                          |
| -------- | ------------------------------ |
| BACKWARD      | 向后删除。  |
| FORWARD   | 向前删除。      |


## RichEditorTextSpanResult

文本Span信息。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| spanPosition | [RichEditorSpanPosition](#richeditorspanposition)  | 是 | Span位置。 |
| value | string | 是 | 文本Span内容。 |
| textStyle | [RichEditorTextStyleResult](#richeditortextstyleresult) | 是 | 文本Span样式信息。 |
| offsetInSpan | [number, number] | 是 | 文本Span内容里有效内容的起始和结束位置。 |


## RichEditorSpanPosition

Span位置信息。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| spanIndex | number  | 是 | Span索引值。 |
| spanRange | [number, number]  | 是 | Span内容在RichEditor内的起始和结束位置。 |


## RichEditorTextStyleResult

后端返回的文本样式信息。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 是 | 文本颜色。 |
| fontSize |  number   | 是 | 字体大小。 |
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | 是 | 字体样式。 |
| fontWeight |  number | 是 | 字体粗细。 |
| fontFamily  |  string | 是 | 字体列表。 |
| decoration  | {<br/>type:&nbsp;[TextDecorationType](ts-appendix-enums.md#textdecorationtype),<br/>color?:&nbsp;[ResourceColor](ts-types.md#resourcecolor)<br/>} | 是 | 文本装饰线样式及其颜色。 |


## RichEditorImageSpanResult

后端返回的图片样式信息。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| size | [number, number] | 是 | 图片的宽度和高度。 |
| verticalAlign  | [ImageSpanAlignment](ts-basic-components-imagespan.md#imagespanalignment) | 是  | 图片垂直对齐方式。 |
| objectFit  | [ImageFit]((ts-basic-components-imagespan.md#imagefit)) | 是 | 图片缩放类型。 |


## RichEditorOptions

RichEditor初始化参数。

| 名称 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| controller | [RichEditorController](#richeditorcontroller)  | 是 | 富文本控制器。 |


## RichEditorController

RichEditor组件的控制器。

### 导入对象

```
controller: RichEditorController = new RichEditorController()
```

### getCaretOffset

getCaretOffset(): number

返回当前光标所在位置。

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| number | 当前光标所在位置。 |

### setCaretOffset

setCaretOffset(offset: number): boolean

设置光标位置。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| offset | number | 是 | 光标偏移位置。 |

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| boolean | 光标是否设置成功。 |

### addTextSpan

addTextSpan(value: string, options?: RichEditorTextSpanOptions): number

添加文本内容。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| value  | string   | 是   | 文本内容。 |
| options  | [RichEditorTextSpanOptions](#richeditortextspanoptions)   | 否   | 文本选项。 |

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| number | 添加完成的Text Span所在的位置。 |

### addImageSpan

addImageSpan(value: PixelMap | ResourceStr, options?: RichEditorImageSpanOptions): number

添加图片内容。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| value  | [PixelMap](../apis/js-apis-image.md#pixelmap7)\|[ResourceStr](ts-types.md#ResourceStr)   | 是   | 图片内容。 |
| options  | [RichEditorImageSpanOptions](#richeditorimagespanoptions)   | 否   | 图片选项。 |

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| number | 添加完成的imageSpan所在的位置。 |


### updateSpanStyle

updateSpanStyle(value: RichEditorUpdateTextSpanStyleOptions | RichEditorUpdateImageSpanStyleOptions): void

更新文本或者图片样式。

**参数：**

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| value | [RichEditorUpdateTextSpanStyleOptions](#richeditorupdatetextspanstyleoptions) \| [RichEditorUpdateImageSpanStyleOptions](#richeditorupdatetextspanstyleoptions) | 是 | 文本或者图片的样式选项信息。 |


### getSpans

getSpans(value?: RichEditorRange): Array<RichEditorTextSpanResult| RichEditorImageSpanResult>

获取span信息。

**参数：**

| 参数名 | 参数类型                            | 必填 | 参数描述         |
| ------ | ----------------------------------- | ---- | ---------------- |
| value  | [RichEditorRange](#richeditorrange) | 否   | 需要获取span范围。 |

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| Array<[RichEditorTextSpanResult](#richeditortextspanresult) \| [RichEditorImageSpanResult](#richeditorimagespanresult)> | 文本和图片Span信息。 |

### deleteSpans

deleteSpans(value?: RichEditorRange): void

删除指定范围内的文本和图片。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| value | [RichEditorRange](#richeditorrange) | 否 | 删除范围。省略时，删除所有文本和图片。|


## RichEditorSelection

选中内容信息。

| 名称      | 类型                                                         | 必填 | 说明       |
| --------- | ------------------------------------------------------------ | ---- | ---------- |
| selection | [number, number]                                             | 是   | 选中范围。 |
| spans     | Array<[RichEditorTextSpanResult](#richeditortextspanresult)\| [RichEditorImageSpanResult](#richeditorimagespanresult)> | 是   | span信息。   |


## RichEditorUpdateTextSpanStyleOptions

文本样式选项。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| start | number   | 否 | 需要更新样式的文本起始位置，省略时表示从0开始。 |
| end | number | 否 | 需要更新样式的文本结束位置，省略时表示到结尾。 |
| textStyle | [RichEditorTextStyle](#richeditortextstyle) | 是 | 文本样式。 |


## RichEditorUpdateImageSpanStyleOptions

图片样式选项。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| start | number   | 否 | 需要更新样式的图片起始位置，省略时表示从0开始。 |
| end | number | 否 | 需要更新样式的图片结束位置，省略时表示到结尾。 |
| imageStyle | [RichEditorImageSpanStyle](#richeditorimagespanstyle) | 是 | 图片样式。 |


## RichEditorTextSpanOptions

添加文本的偏移位置和文本样式信息。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| offset  | number   | 否   | 添加文本的位置。省略时，添加到所有文本字符串的最后。 |
| style  | [RichEditorTextStyle](#richeditortextstyle)   | 否   | 文本样式信息。省略时，使用系统默认文本信息。|

## RichEditorTextStyle

文本样式信息。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 文本颜色。 |
| fontSize | [Length](ts-types.md#length) \| number   | 否 | 字体大小。 |
| fontStyle | [FontStyle](ts-appendix-enums.md#fontstyle) | 否 | 字体样式。 |
| fontWeight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | 否 | 字体粗细。 |
| fontFamily  | [ResourceStr](ts-types.md#resourcestr) \| number \| string | 否 | 设置字体列表。默认字体'HarmonyOS Sans'，且当前只支持这种字体。 |
| decoration  | {<br/>type:&nbsp;[TextDecorationType](ts-appendix-enums.md#textdecorationtype),<br/>color?:&nbsp;[ResourceColor](ts-types.md#resourcecolor)<br/>} \| number \| string | 否 | 设置文本装饰线样式及其颜色。 |


## RichEditorImageSpanOptions

添加图片的偏移位置和图片样式信息。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| offset  | number   | 否   | 添加图片的位置。省略时，添加到所有文本字符串的最后。 |
| imageStyle  | [RichEditorImageSpanStyle](#richeditorimagespanstyle)   | 否   | 图片样式信息。省略时，使用系统默认图片信息。|

## RichEditorImageSpanStyle

图片样式。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| size  | [Dimension, Dimension]  | 否 | 图片宽度和高度。 |
| verticalAlign  | [ImageSpanAlignment](ts-basic-components-imagespan.md#imagespanalignment) | 否   | 图片垂直对齐方式。 |
| objectFit  | [ImageFit]((ts-basic-components-imagespan.md#imagefit)) | 否 | 图片缩放类型。 |

## RichEditorRange

范围信息。

| 名称 | 类型 | 必填 | 描述                               |
| ------ | -------- | ---- | -------------------------------------- |
| start | number   | 否 | 起始位置，省略时表示从0开始。 |
| end | number | 否 | 结束位置，省略时表示到结尾。 |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct Index {
  controller: RichEditorController = new RichEditorController();
  options: RichEditorOptions = { controller: this.controller };
  private start: number = -1;
  private end: number = -1;
  @State message: string = "[-1, -1]"
  @State content: string = ""

  build() {
    Column() {
      Column() {
        Text("selection range:").width("100%")
        Text() {
          Span(this.message)
        }.width("100%")
        Text("selection content:").width("100%")
        Text() {
          Span(this.content)
        }.width("100%")
      }
      .borderWidth(1)
      .borderColor(Color.Red)
      .width("100%")
      .height("20%")

      Row() {
        Button("更新样式:加粗").onClick(() => {
          this.controller.updateSpanStyle({
            start: this.start,
            end: this.end,
            textStyle:
            {
              fontWeight: FontWeight.Bolder
            }
          })
        })
        Button("获取选择内容").onClick(() => {
          this.content = "";
          this.controller.getSpans({
            start: this.start,
            end: this.end
          }).forEach(item => {
            if ("imageStyle" in item) {
              this.content += item.valueResourceStr;
              this.content += "\n"
            } else {
              this.content += item.value;
              this.content += "\n"
            }
          })
        })
        Button("删除选择内容").onClick(() => {
          this.controller.deleteSpans({
            start: this.start,
            end: this.end
          })
          this.start = -1;
          this.end = -1;
          this.message = "[" + this.start + ", " + this.end + "]"
        })
      }
      .borderWidth(1)
      .borderColor(Color.Red)
      .width("100%")
      .height("10%")

      Column() {
        RichEditor(this.options)
          .onReady(() => {
            this.controller.addTextSpan("0123456789",
              {
                style:
                {
                  fontColor: Color.Orange,
                  fontSize: 30
                }
              })
            this.controller.addImageSpan($r("app.media.icon"),
              {
                imageStyle:
                {
                  size: ["57px", "57px"]
                }
              })
            this.controller.addTextSpan("0123456789",
              {
                style:
                {
                  fontColor: Color.Black,
                  fontSize: 30
                }
              })
          })
          .onSelect((value: RichEditorSelection) => {
            [this.start, this.end] = value.selection;
            this.message = "[" + this.start + ", " + this.end + "]"
          })
          .aboutToIMEInput((value: RichEditorInsertValue) => {
            console.log("---------------------- aboutToIMEInput ----------------------")
            console.log("insertOffset:" + value.insertOffset)
            console.log("insertValue:" + value.insertValue)
            return true;
          })
          .onIMEInputComplete((value: RichEditorTextSpanResult) => {
            console.log("---------------------- onIMEInputComplete ---------------------")
            console.log("spanIndex:" + value.spanPosition.spanIndex)
            console.log("spanRange:[" + value.spanPosition.spanRange[0] + "," + value.spanPosition.spanRange[1] + "]")
            console.log("offsetInSpan:[" + value.offsetInSpan[0] + "," + value.offsetInSpan[1] + "]")
            console.log("value:" + value.value)
          })
          .aboutToDelete((value: RichEditorDeleteValue) => {
            console.log("---------------------- aboutToDelete --------------------------")
            console.log("offset:" + value.offset)
            console.log("direction:" + value.direction)
            console.log("length:" + value.length)
            value.richEditorDeleteSpans.forEach(item => {
              console.log("---------------------- item --------------------------")
              console.log("spanIndex:" + item.spanPosition.spanIndex)
              console.log("spanRange:[" + item.spanPosition.spanRange[0] + "," + item.spanPosition.spanRange[1] + "]")
              console.log("offsetInSpan:[" + item.offsetInSpan[0] + "," + item.offsetInSpan[1] + "]")
              if ("imageStyle" in item) {
                console.log("image:" + item.valueResourceStr)
              } else {
                console.log("text:" + item.value)
              }
            })
            return true;
          })
          .onDeleteComplete(() => {
            console.log("---------------------- onDeleteComplete ------------------------")
          })
          .borderWidth(1)
          .borderColor(Color.Green)
          .width("100%")
          .height("30%")
      }
      .borderWidth(1)
      .borderColor(Color.Red)
      .width("100%")
      .height("70%")
    }
  }
}
```
![richeditor](figures/richeditor.gif)
