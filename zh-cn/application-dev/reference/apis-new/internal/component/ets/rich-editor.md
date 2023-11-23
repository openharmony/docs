# rich_editor    
支持图文混排和文本交互式编辑的组件。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## RichEditorDeleteDirection    
删除操作的方向。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| BACKWARD | 0 | 向后删除。 |  
| FORWARD | 1 | 向后删除。 |  
    
## RichEditorSpanType    
Span类型信息。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TEXT | 0 | Span为文字类型。 |  
| IMAGE | 1 | Span为图像类型。 |  
| MIXED | 2 | Span为图文混合类型。 |  
    
## RichEditorSpanPosition    
Span位置信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| spanIndex | number | false | true | Span索引值。 |  
| spanRange | [number, number] | false | true | Span内容在RichEditor内的起始和结束位置。 |  
    
## RichEditorTextStyle    
文本样式信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fontColor | ResourceColor | false | false | 文本颜色。<br/> 默认值：Color.Black。 |  
| fontSize | Length \| number | false | false | 设置字体大小，Length为number类型时，使用fp单位。字体默认大小16。不支持设置百分比字符串。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| fontStyle | FontStyle | false | false | 字体样式。<br/>默认值：FontStyle.Normal。 |  
| fontWeight | number \| FontWeight \| string | false | false | 字体粗细。<br/>number类型取值[100,900]，取值间隔为100，默认为400，取值越大，字体越粗。<br/>string类型仅支持number类型取值的字符串形式，例如“400”，以及“bold”、“bolder”、“lighter”、“regular” 、“medium”分别对应FontWeight中相应的枚举值。<br/>默认值：FontWeight.Normal。 |  
| fontFamily | ResourceStr | false | false | 设置字体列表。默认字体'HarmonyOS Sans'，当前支持'HarmonyOS Sans'字体和[注册自定义字体](../apis/js-apis-font.md)。 <br/>默认字体:'HarmonyOS Sans'。 |  
| decoration | object | false | false | 设置文本装饰线样式及其颜色。<br />默认值：{<br/>type:TextDecorationType.None,<br/>color：Color.Black<br/>}。 |  
    
## RichEditorTextSpan  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| spanPosition | RichEditorSpanPosition | false | true |  |  
| value | string | false | true |  |  
| textStyle | RichEditorTextStyle | false | false |  |  
    
## RichEditorImageSpanStyle    
图片样式。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| size | [Dimension, Dimension] | false | false | 图片宽度和高度。 |  
| verticalAlign | ImageSpanAlignment | false | false | 图片垂直对齐方式。<br/>默认值:ImageSpanAlignment.BASELINE |  
| objectFit | ImageFit | false | false | 图片缩放类型。<br/> 默认值:ImageFit.Cover。 |  
    
## RichEditorTextStyleResult    
后端返回的文本样式信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fontColor | ResourceColor | false | true | 文本颜色。 |  
| fontSize | number | false | true | 字体大小。 |  
| fontStyle | FontStyle | false | true | 字体样式。 |  
| fontWeight | number | false | true | 字体粗细。 |  
| fontFamily | string | false | true | 字体列表。 |  
| decoration | object | false | true | 文本装饰线样式及其颜色。 |  
    
## RichEditorTextSpanResult    
文本Span信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| spanPosition | RichEditorSpanPosition | false | true | Span位置。 |  
| value | string | false | true | 文本Span内容。 |  
| textStyle | RichEditorTextStyleResult | false | true | 文本Span样式信息。 |  
| offsetInSpan | [number, number] | false | true | 文本Span内容里有效内容的起始和结束位置。 |  
    
## RichEditorImageSpanStyleResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| size | [number, number] | false | true |  |  
| verticalAlign | ImageSpanAlignment | false | true |  |  
| objectFit | ImageFit | false | true |  |  
    
## RichEditorImageSpanResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| spanPosition | RichEditorSpanPosition | false | true |  |  
| valuePixelMap | PixelMap | false | false |  |  
| valueResourceStr | ResourceStr | false | false |  |  
| imageStyle | RichEditorImageSpanStyleResult | false | true |  |  
| offsetInSpan | [number, number] | false | true |  |  
    
## RichEditorImageSpan  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| spanPosition | RichEditorSpanPosition | false | true |  |  
| value | PixelMap \| ResourceStr | false | true |  |  
| imageStyle | RichEditorImageSpanStyle | false | false |  |  
    
## RichEditorRange    
范围信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| start | number | false | false | 起始位置，省略或者设置负值时表示从0开始。 |  
| end | number | false | false | 结束位置，省略或者超出文本范围时表示到结尾。 |  
    
## RichEditorTextSpanOptions    
添加文本的偏移位置和文本样式信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| offset | number | false | false | 添加文本的位置。省略时，添加到所有文本字符串的最后。 |  
| style | RichEditorTextStyle | false | false | 文本样式信息。省略时，使用系统默认文本信息。 |  
    
## RichEditorImageSpanOptions    
添加图片的偏移位置和图片样式信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| offset | number | false | false | 添加图片的位置。省略时，添加到所有文本字符串的最后。 |  
| imageStyle | RichEditorImageSpanStyle | false | false | 图片样式信息。省略时，使用系统默认图片信息。 |  
    
## RichEditorSpanStyleOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## RichEditorUpdateTextSpanStyleOptions    
文本样式选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| textStyle | RichEditorTextStyle | false | true | 文本样式。 |  
    
## RichEditorUpdateImageSpanStyleOptions    
图片样式选项。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| imageStyle | RichEditorImageSpanStyle | false | true | 图片样式。 |  
    
## RichEditorSelection    
选中内容信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| selection | [number, number] | false | true | 选中范围。 |  
| spans | Array<RichEditorTextSpanResult \| RichEditorImageSpanResult> | false | true | span信息。 |  
    
## RichEditorInsertValue    
插入文本信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| insertOffset | number | false | true | 插入的文本偏移位置。 |  
| insertValue | string | false | true | 插入的文本内容。 |  
    
## RichEditorDeleteValue  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| offset | number | false | true | 删除内容的偏移位置。 |  
| direction | RichEditorDeleteDirection | false | true | 删除操作的方向。 |  
| length | number | false | true | 删除内容长度。 |  
| richEditorDeleteSpans | Array<RichEditorTextSpanResult \| RichEditorImageSpanResult> | false | true | 删除的文本或者图片Span的具体信息。 |  
    
## RichEditorOptions    
RichEditor初始化参数。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| controller | RichEditorController | false | true | 富文本控制器。 |  
    
## SelectionMenuOptions    
范围信息。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onAppear | function | false | false | 自定义选择菜单弹出时回调。 |  
| onDisappear | function | false | false | 自定义选择菜单关闭时回调。 |  
    
## RichEditorController    
RichEditor组件的控制器。    
### getCaretOffset    
返回当前光标所在位置。  
 **调用形式：**     
- getCaretOffset(): number  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 当前光标所在位置。 |  
    
### setCaretOffset    
设置光标位置。  
 **调用形式：**     
- setCaretOffset(offset: number): boolean  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| offset | number | true | 光标偏移位置。超出文本范围时，设置失败。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 光标是否设置成功。 |  
    
### addTextSpan    
添加文本内容。  
 **调用形式：**     
- addTextSpan(value: string, options?: RichEditorTextSpanOptions): number  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 文本内容。 |  
| options | RichEditorTextSpanOptions | false | 文本选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 添加完成的Text Span所在的位置。 |  
    
### addImageSpan    
添加图片内容。  
 **调用形式：**     
- addImageSpan(value: PixelMap | ResourceStr, options?: RichEditorImageSpanOptions): number  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 图片内容。 |  
| options | RichEditorImageSpanOptions | false | 图片选项。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 添加完成的imageSpan所在的位置。 |  
    
### updateSpanStyle    
更新文本或者图片样式。  
若只更新了一个Span的部分内容，则会根据更新部分、未更新部分将该Span拆分为多个Span。  
 **调用形式：**     
- updateSpanStyle(value: RichEditorUpdateTextSpanStyleOptions | RichEditorUpdateImageSpanStyleOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | true | 文本或者图片的样式选项信息。 |  
    
### deleteSpans    
删除指定范围内的文本和图片。  
 **调用形式：**     
- deleteSpans(value?: RichEditorRange): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | RichEditorRange | false | 删除范围。省略时，删除所有文本和图片。 |  
    
### getSpans    
获取span信息。  
 **调用形式：**     
- getSpans(value?: RichEditorRange): Array\<RichEditorImageSpanResult | RichEditorTextSpanResult>  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | RichEditorRange | false | 需要获取span范围。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<RichEditorImageSpanResult | RichEditorTextSpanResult> | 文本和图片Span信息。 |  
    
### closeSelectionMenu    
关闭自定义选择菜单或系统默认选择菜单。  
 **调用形式：**     
- closeSelectionMenu(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| aboutToIMEInput(callback:  |  RichEditorInsertValue) => boolean |  |  
| aboutToDelete(callback:  |  RichEditorDeleteValue) => boolean |  |  
| copyOptions |  CopyOptions |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
| bindSelectionMenu | null |  |  
| customKeyboard |  CustomBuilder |  |  
    
### onReady<sup>(deprecated)</sup>    
onReady(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onSelect<sup>(deprecated)</sup>    
onSelect(callback: (value: RichEditorSelection) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onIMEInputComplete<sup>(deprecated)</sup>    
onIMEInputComplete(callback: (value: RichEditorTextSpanResult) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onDeleteComplete<sup>(deprecated)</sup>    
onDeleteComplete(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
## 接口  
  
  
    
 **调用形式**     
    
- RichEditor(value: RichEditorOptions)    
起始版本： 10    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | RichEditorOptions | true |  |  
    
 **示例代码1：**   
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
            if(typeof(item as RichEditorImageSpanResult)['imageStyle'] != 'undefined'){  
              this.content += (item as RichEditorImageSpanResult).valueResourceStr;  
              this.content += "\n"  
            } else {  
              this.content += (item as RichEditorTextSpanResult).value;  
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
            this.start = value.selection[0];  
            this.end = value.selection[1];  
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
              if (typeof(item as RichEditorImageSpanResult)['imageStyle'] != 'undefined') {  
                console.log("image:" + (item as RichEditorImageSpanResult).valueResourceStr)  
              } else {  
                console.log("text:" + (item as RichEditorTextSpanResult).value)  
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
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct RichEditorExample {  
  controller: RichEditorController = new RichEditorController()  
  
  // 自定义键盘组件  
  @Builder CustomKeyboardBuilder() {  
    Column() {  
      Grid() {  
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item: number | string) => {  
          GridItem() {  
            Button(item + "")  
              .width(110).onClick(() => {  
              this.controller.addTextSpan(item + '', {  
                offset: this.controller.getCaretOffset(),  
                style:  
                {  
                  fontColor: Color.Orange,  
                  fontSize: 30  
                }  
              })  
              this.controller.setCaretOffset(this.controller.getCaretOffset() + item.toString().length)  
            })  
          }  
        })  
      }.maxCount(3).columnsGap(10).rowsGap(10).padding(5)  
    }.backgroundColor(Color.Gray)  
  }  
  
  build() {  
    Column() {  
      RichEditor({ controller: this.controller })  
        // 绑定自定义键盘  
        .customKeyboard(this.CustomKeyboardBuilder()).margin(10).border({ width: 1 })  
        .height(200)  
        .borderWidth(1)  
        .borderColor(Color.Red)  
        .width("100%")  
    }  
  }  
}  
    
```    
  
![customKeyboard](figures/richEditorCustomKeyboard.gif)  
    
 **示例代码3：**   
```ts    
// xxx.ets  
import pasteboard from '@ohos.pasteboard'  
import { BusinessError } from '@ohos.base';  
class info{  
  imageSrc: Resource=$r('sys.media.ohos_ic_public_cut')  
  id: string=''  
  label: string=''  
}  
@Entry  
@Component  
struct SelectionMenu {  
  @State message: string = 'Hello World'  
  @State textSize: number = 40  
  @State sliderShow: boolean = false  
  @State start: number = -1  
  @State end: number = -1  
  @State colorTransparent: Color = Color.Transparent  
  controller: RichEditorController = new RichEditorController();  
  options: RichEditorOptions = { controller: this.controller }  
  private iconArr: Array<Resource> =  
    [$r('app.media.icon'), $r("app.media.icon"), $r('app.media.icon'),  
      $r("app.media.icon"), $r('app.media.icon')]  
  private listArr: Array<Object> =  
    [{ imageSrc: $r('sys.media.ohos_ic_public_cut'), id: '剪切', label: "Ctrl+X" } as info,  
      { imageSrc: $r('sys.media.ohos_ic_public_copy'), id: '复制', label: "Ctrl+C" } as info,  
      { imageSrc: $r('sys.media.ohos_ic_public_paste'), id: '粘贴', label: "Ctrl+V" } as info,  
      { imageSrc: $r('sys.media.ohos_ic_public_select_all'), id: '全选', label: "Ctrl+A" } as info,  
      { imageSrc: $r('sys.media.ohos_ic_public_share'), id: '分享', label: "" } as info,  
      { imageSrc: $r('sys.media.ohos_ic_public_translate_c2e'), id: '翻译', label: "" } as info,  
      { imageSrc: $r('sys.media.ohos_ic_public_search_filled'), id: '搜索', label: "" } as info]  
  @State iconBgColor: ResourceColor[] = new Array(this.iconArr.length).fill(this.colorTransparent)  
  @State listBgColor: ResourceColor[] = new Array(this.listArr.length).fill(this.colorTransparent)  
  @State iconIsFocus: boolean[] = new Array(this.iconArr.length).fill(false)  
  @State listIsFocus: boolean[] = new Array(this.iconArr.length).fill(false)  
  @State clickWeightNum: number = 0  
  @State clickNum: number[] = [0, 0, 0]  
  
  build() {  
    Column() {  
      Column() {  
        RichEditor(this.options)  
          .onReady(() => {  
            this.controller.addTextSpan(this.message, { style: { fontColor: Color.Orange, fontSize: 30 } })  
          })  
          .onSelect((value: RichEditorSelection) => {  
            if (value.selection[0] == -1  value.selection[1] == -1) {  
              return  
            }  
            this.start = value.selection[0]  
            this.end = value.selection[1]  
          })  
          .bindSelectionMenu(RichEditorSpanType.TEXT, this.panel(), ResponseType.LongPress, { onDisappear: () => {  
            this.sliderShow = false  
          }})  
          .borderWidth(1)  
          .borderColor(Color.Red)  
          .width(200)  
          .height(200)  
      }.width('100%').backgroundColor(Color.White)  
    }.height('100%')  
  }  
  
  @Builder  
  panel() {  
    Column() {  
      this.iconPanel()  
      if (!this.sliderShow) {  
        this.listPanel()  
      } else {  
        this.sliderPanel()  
      }  
    }.width(256)  
  }  
  
  @Builder iconPanel() {  
    Column() {  
      Row({ space: 2 }) {  
        ForEach(this.iconArr, (item:Resource, index ?: number) => {  
          Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
            Image(item).fillColor($r('sys.color.ohos_id_color_primary')).width(24).height(24).focusable(true)  
          }  
          .border({ width: this.iconIsFocus[index as number] ? 2 : 0, color: $r('sys.color.ohos_id_color_focused_outline') })  
          .borderRadius($r('sys.float.ohos_id_corner_radius_default_m'))  
          .width(48)  
          .height(48)  
          .focusable(true)  
          .focusOnTouch(true)  
          .onClick(() => {  
            if (index as number == 0) {  
              this.clickNum[0]++  
              this.sliderShow = false  
              this.controller.updateSpanStyle({ start: this.start, end: this.end, textStyle: {  
                fontWeight: this.clickNum[0] % 2 !== 0 ? FontWeight.Bolder : FontWeight.Normal  
              } })  
            } else if (index as number == 1) {  
              this.clickNum[1]++  
              this.sliderShow = false  
              this.controller.updateSpanStyle({ start: this.start, end: this.end, textStyle: {  
                fontStyle: this.clickNum[1] % 2 !== 0 ? FontStyle.Italic : FontStyle.Normal  
              } })  
            } else if (index as number == 2) {  
              this.clickNum[2]++  
              this.sliderShow = false  
              this.controller.updateSpanStyle({ start: this.start, end: this.end, textStyle: {  
                decoration: {  
                  type: this.clickNum[2] % 2 !== 0 ? TextDecorationType.Underline : TextDecorationType.None  
                } } })  
            } else if (index as number == 3) {  
              this.sliderShow = !this.sliderShow  
            } else if (index as number == 4) {  
              this.sliderShow = false  
            }  
          })  
          .onTouch((event?: TouchEvent | undefined) => {  
            if(event != undefined){  
              if (event.type === TouchType.Down) {  
                this.iconBgColor[index as number] = $r('sys.color.ohos_id_color_click_effect')  
              }  
              if (event.type === TouchType.Up) {  
                this.iconBgColor[index as number] = this.colorTransparent  
              }  
            }  
          })  
          .onHover((isHover?: boolean, event?: HoverEvent) => {  
            this.iconBgColor.forEach((icon:ResourceColor, index1) => {  
              this.iconBgColor[index1] = this.colorTransparent  
            })  
            if(isHover != undefined) {  
              this.iconBgColor[index as number] = $r('sys.color.ohos_id_color_hover')  
            }else{  
              this.listBgColor[index as number] = this.colorTransparent  
            }  
          })  
          .onFocus(() => {  
            this.iconIsFocus[index as number] = true  
          })  
          .onBlur(() => {  
            this.iconIsFocus[index as number] = false  
          })  
          .backgroundColor(this.iconBgColor[index as number])  
        })  
      }  
    }  
    .borderRadius($r('sys.float.ohos_id_corner_radius_card'))  
    .width(248)  
    .height(48)  
    .margin({ bottom: 8 })  
    .shadow(ShadowStyle.OUTER_DEFAULT_MD)  
  }  
  
  @Builder listPanel() {  
    Column() {  
      List({ space: 0, initialIndex: 0 }) {  
        ForEach(this.listArr, (item:info, index:number | undefined) => {  
          ListItem() {  
            listChild({  
              item,  
              index,  
              listBgColor: $listBgColor,  
              colorTransparent: $colorTransparent  
            })  
              .onClick(() => {  
                let sysBoard = pasteboard.getSystemPasteboard()  
                let pasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, '')  
                this.controller.getSpans({ start: this.start, end: this.end })  
                  .forEach((item, i) => {  
                    if(typeof(item as RichEditorImageSpanResult)['imageStyle'] != 'undefined'){  
                      let style = (item as RichEditorImageSpanResult).imageStyle  
                      if((item as RichEditorImageSpanResult).valuePixelMap != undefined) {  
                        let data = pasteboard.createRecord(pasteboard.MIMETYPE_PIXELMAP, ((item as RichEditorImageSpanResult).valuePixelMap as PixelMap));  
                        let prop = pasteData.getProperty()  
                        let temp:Record<string, Object> = { 'width': style.size[0], 'height': style.size[1], 'fit': style.objectFit }  
                        prop.additions[i] = temp;  
                        pasteData.addRecord(data)  
                        pasteData.setProperty(prop)  
                      }  
                    } else {  
                      let style = (item as RichEditorTextSpanResult).textStyle  
                      let data = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_PLAIN, (item as RichEditorTextSpanResult).value)  
                      let prop = pasteData.getProperty()  
                      let temp:Record<string, Object> = { 'color': style.fontColor, 'size': style.fontSize, 'style': style.fontStyle,  
                        'weight': style.fontWeight }  
                      prop.additions[i] = temp;  
                      pasteData.addRecord(data)  
                      pasteData.setProperty(prop)  
                    }  
                  })  
                if(index == undefined){ return }  
                switch (index) {  
                  case 0:  
                    this.controller.deleteSpans({ start: this.start, end: this.end })  
                  case 1:  
                    sysBoard.clearData()  
                    sysBoard.setData(pasteData).then(() => {  
                      console.info('Succeeded in setting PasteData.');  
                    }).catch((err: BusinessError) => {  
                      console.error('Failed to set PasteData. Cause: ' + err.message);  
                    })  
                    break  
                  case 2:  
                    sysBoard.getData((err, data) => {  
                      if (err) {  
                        return  
                      }  
                      let count = data.getRecordCount()  
                      for (let m = 0; m < count; m++) {  
                        const element = data.getRecord(m);  
                        let tex: RichEditorTextStyle = {  
                          fontSize: 30,  
                          fontColor: Color.Orange,  
                          fontWeight: FontWeight.Normal  
                        }  
                        let im: RichEditorImageSpanStyle = { objectFit: ImageFit.Contain, size: [50, 50] }  
                        if(im.size == undefined){ break }  
                        if (data.getProperty().additions[m]) {  
                          const tmp = data.getProperty().additions[m] as Record<string, Object | undefined>;  
                          if (tmp['width'] != undefined) {  
                            im.size[0] = tmp['width'] as Dimension;  
                          }  
                          if (tmp['height'] != undefined){  
                            im.size[1] = tmp['height'] as Dimension;  
                          }  
                          if (tmp['fit'] != undefined){  
                            im.objectFit = tmp['fit'] as ImageFit;  
                          }  
                          if (tmp['color'] != undefined){  
                            tex.fontColor = tmp['color'] as ResourceColor;  
                          }  
                          if (tmp['size'] != undefined){  
                            tex.fontSize = tmp['size'] as number;  
                          }  
                          if (tmp['style'] != undefined){  
                            tex.fontStyle = tmp['style'] as FontStyle;  
                          }  
                          if (tmp['weight'] != undefined){  
                            tex.fontWeight = tmp['weight'] as number;  
                          }  
                        }  
  
                        if (element.mimeType == pasteboard.MIMETYPE_TEXT_PLAIN) {  
                          this.controller.addTextSpan(element.plainText,  
                            {  
                              style: tex,  
                              offset: this.controller.getCaretOffset()  
                            })  
                        }  
                        if (element.mimeType == pasteboard.MIMETYPE_PIXELMAP) {  
                          this.controller.addImageSpan(element.pixelMap,  
                            {  
                              imageStyle: im,  
                              offset: this.controller.getCaretOffset()  
                            })  
                        }  
                      }  
                    })  
                    break  
                }  
              })  
          }  
          .height(48)  
          .borderRadius($r('sys.float.ohos_id_corner_radius_card'))  
          .focusable(true)  
          .focusOnTouch(true)  
          .border({ width: this.listIsFocus[index as number] ? 2 : 0, color: $r('sys.color.ohos_id_color_focused_outline') })  
          .onFocus(() => {  
            this.listIsFocus[index as number] = true  
          })  
          .onBlur(() => {  
            this.listIsFocus[index as number] = false  
          })  
        }, (item:number) => item.toString())  
      }  
    }  
    .focusable(true)  
    .width(248)  
    .backgroundColor(this.colorTransparent)  
    .borderRadius($r('sys.float.ohos_id_corner_radius_card'))  
    .shadow(ShadowStyle.OUTER_DEFAULT_MD)  
  }  
  
  @Builder sliderPanel() {  
    Column() {  
      Flex({ justifyContent: FlexAlign.SpaceBetween, alignItems: ItemAlign.Center }) {  
        Text('A').fontSize(15)  
        Slider({ value: this.textSize, step: 10, style: SliderStyle.InSet })  
          .width(210)  
          .onChange((value: number, mode: SliderChangeMode) => {  
            this.textSize = value  
            this.controller.updateSpanStyle({ start: this.start, end: this.end, textStyle: { fontSize: this.textSize }  
            })  
          })  
        Text('A').fontSize(20).fontWeight(FontWeight.Medium)  
      }.borderRadius($r('sys.float.ohos_id_corner_radius_card'))  
    }  
    .backgroundColor(this.colorTransparent)  
    .borderRadius($r('sys.float.ohos_id_corner_radius_card'))  
    .padding(15)  
    .width(248)  
    .height(48)  
  }  
}  
  
@Component  
struct listChild {  
  item:info = new info()  
  index: number = 0  
  @Link listBgColor: (Resource | Color)[]  
  @Link colorTransparent: Resource  
  
  build() {  
    Column() {  
      Flex({  
        direction: FlexDirection.Row, justifyContent: FlexAlign.SpaceBetween, alignItems: ItemAlign.Center  
      }) {  
        Row() {  
          Image(this.item.imageSrc)  
            .width(20)  
            .height(20)  
            .margin({ right: 8 })  
            .fillColor($r('sys.color.ohos_id_color_primary'))  
            .focusable(true)  
          Text('' + this.item.id)  
            .textAlign(TextAlign.Center)  
            .borderRadius(10)  
            .focusable(true)  
            .fontColor($r('sys.color.ohos_id_color_primary'))  
            .fontSize($r('sys.float.ohos_id_text_size_body1'))  
        }  
  
        Row() {  
          Text('' + this.item.label)  
            .fontColor($r('sys.color.ohos_id_color_text_secondary')).fontSize($r('sys.float.ohos_id_text_size_body1'))  
        }  
      }  
      .onTouch((event?: TouchEvent) => {  
        if (event != undefined  event.type === TouchType.Down) {  
          this.listBgColor[this.index] = $r('sys.color.ohos_id_color_click_effect')  
        }  
        if (event != undefined  event.type === TouchType.Up) {  
          this.listBgColor[this.index] = this.colorTransparent  
        }  
      })  
      .onHover((isHover?: boolean) => {  
        this.listBgColor[this.index] = isHover ? $r('sys.color.ohos_id_color_hover') : this.colorTransparent  
      })  
      .backgroundColor(this.listBgColor[this.index])  
      .padding({ right: 12, left: 12 })  
      .height('48')  
      .focusable(true)  
      .borderRadius($r('sys.float.ohos_id_corner_radius_default_m'))  
    }  
  }  
}  
    
```    
  
![selectionMenu](figures/richEditorSelectionMenu.png)  
