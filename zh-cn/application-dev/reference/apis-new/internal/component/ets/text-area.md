# text_area    
多行文本输入框组件，当输入的文本内容超过组件宽度时会自动换行显示。高度未设置时，组件无默认高度，自适应内容高度。宽度未设置时，默认撑满最大宽度。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## TextAreaController<sup>(8+)</sup>    
### caretPosition<sup>(8+)</sup>    
设置输入光标的位置。  
  
 **调用形式：**     
- caretPosition(value: number): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 从字符串开始到光标所在位置的字符长度。<br/> |  
    
### setTextSelection<sup>(10+)</sup>    
组件在获焦状态下，调用该接口设置文本选择区域并高亮显示，且只有在selectionStart小于selectionEnd时，文字才会被选取、高亮显示。  
  
 **调用形式：**     
- setTextSelection(selectionStart: number, selectionEnd: number): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| selectionStart | number | true | 文本选择区域起始位置，文本框中文字的起始位置为0。<br/>当selectionStart小于0时、按照0处理；当selectionStart大于文字最大长度时、按照文字最大长度处理。<br/> |  
| selectionEnd | number | true | 文本选择区域结束位置。<br/>当selectionEnd小于0时、按照0处理；当selectionEnd大于文字最大长度时、按照文字最大长度处理。<br/> |  
    
### stopEditing<sup>(10+)</sup>    
退出编辑态。  
  
 **调用形式：**     
- stopEditing(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## TextAreaOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| placeholder | ResourceStr | false | false | 设置无输入时的提示文本。输入内容后，提示文本不显示。<br/>仅设置placeholder属性时，手柄依然跟随拖动，手柄松开后光标停留在文字开头位置。 |  
| text | ResourceStr | false | false | 设置输入框当前的文本内容。<br/>当组件设置<a href="https://file+.vscode-resource.vscode-cdn.net/c:/Code/test/ts-universal-attributes-polymorphic-style.md">stateStyles</a>等刷新属性时，建议通过onChange事件将状态变量与文本实时绑定，<br/>避免组件刷新时TextArea中的文本内容异常。<br/> |  
| controller<sup>(8+)</sup> | TextAreaController | false | false | 设置TextArea控制器。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- TextArea(value?: TextAreaOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(7+)</sup> | TextAreaOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| placeholderColor |  ResourceColor |  |  
| placeholderFont |  Font |  |  
| textAlign |  TextAlign |  |  
| caretColor |  ResourceColor |  |  
| fontColor |  ResourceColor |  |  
| fontSize |  Length |  |  
| fontStyle |  FontStyle |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| fontFamily |  ResourceStr |  |  
| inputFilter(value: ResourceStr, error?: <sup>8+</sup> |  string) => void |  |  
| copyOption<sup>9+</sup> |  CopyOptions |  |  
| enableKeyboardOnFocus<sup>10+</sup> |  boolean |  |  
| maxLength<sup>10+</sup> |  number |  |  
| showCounter<sup>10+</sup> |  boolean |  |  
| style<sup>10+</sup> |  TextContentStyle |  |  
| barState<sup>10+</sup> |  BarState |  |  
| selectionMenuHidden<sup>10+</sup> |  boolean |  |  
| maxLines<sup>10+</sup> |  number |  |  
| customKeyboard<sup>10+</sup> |  CustomBuilder |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: string) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onTextSelectionChange<sup>(deprecated)</sup>    
onTextSelectionChange(callback: (selectionStart: number, selectionEnd: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onContentScroll<sup>(deprecated)</sup>    
onContentScroll(callback: (totalOffsetX: number, totalOffsetY: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onEditChange<sup>(deprecated)</sup>    
onEditChange(callback: (isEditing: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onCopy<sup>(deprecated)</sup>    
onCopy(callback: (value: string) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onCut<sup>(deprecated)</sup>    
onCut(callback: (value: string) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onPaste<sup>(deprecated)</sup>    
onPaste(callback: (value: string) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct TextAreaExample {  
  @State text: string = ''  
  controller: TextAreaController = new TextAreaController()  
  
  build() {  
    Column() {  
      TextArea({  
        text: this.text,  
        placeholder: 'The text area can hold an unlimited amount of text. input your word...',  
        controller: this.controller  
      })  
        .placeholderFont({ size: 16, weight: 400 })  
        .width(336)  
        .height(56)  
        .margin(20)  
        .fontSize(16)  
        .fontColor('#182431')  
        .backgroundColor('#FFFFFF')  
        .onChange((value: string) => {  
          this.text = value  
        })  
      Text(this.text)  
      Button('Set caretPosition 1')  
        .backgroundColor('#007DFF')  
        .margin(15)  
        .onClick(() => {  
          // 设置光标位置到第一个字符后  
          this.controller.caretPosition(1)  
        })  
    }.width('100%').height('100%').backgroundColor('#F1F3F5')  
  }  
}  
    
```    
  
![textArea](figures/textArea.gif)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct TextAreaExample {  
  @State text: string = 'test'  
  @State counterVisible: boolean = false  
  @State maxNumber: number = -1  
  controller: TextAreaController = new TextAreaController()  
  
  build() {  
    Column() {  
      TextArea({  
        text: this.text,  
        placeholder: 'The text area can hold an unlimited amount of text. input your word...',  
        controller: this.controller  
      })  
        .placeholderFont({ size: 16, weight: 400 })  
        .width(336)  
        .height(56)  
        .margin(20)  
        .fontSize(16)  
        .fontColor('#182431')  
        .maxLength(4)  
        .showCounter(true)  
        .backgroundColor('#FFFFFF')  
        .onChange((value: string) => {  
          this.text = value  
        })  
    }.width('100%').height('100%').backgroundColor('#F1F3F5')  
  }  
}  
    
```    
  
![maxLength](figures/maxLength.png)  
    
 **示例代码3：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct TextAreaExample {  
  controller: TextAreaController = new TextAreaController()  
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
      TextArea({ controller: this.controller, text: this.inputValue})  
        // 绑定自定义键盘  
        .customKeyboard(this.CustomKeyboardBuilder()).margin(10).border({ width: 1 })  
        .height(200)  
    }  
  }  
}  
    
```    
  
![customKeyboard](figures/textAreaCustomKeyboard.png)  
