# text_input    
单行文本输入框组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## InputType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Normal | 0 | 基本输入模式。<br/>支持输入数字、字母、下划线、空格、特殊字符。 |  
| Number | 1 | 纯数字输入模式。 |  
| PhoneNumber<sup>(9+)</sup> | 2 | 电话号码输入模式。<br/>支持输入数字、+ 、-、*、#，长度不限。 |  
| Email | 3 | 邮箱地址输入模式。支持数字，字母，下划线，以及80273188261889@ |  
| Password | 4 | 密码输入模式。支持输入数字、字母、下划线、空格、特殊字符。密码显示小眼睛图标并且默认会将文字变成圆点。密码输入模式不支持下划线样式。 |  
    
## EnterKeyType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Go | 0 | 显示为前往样式。 |  
| Search | 1 | 显示为搜索样式。 |  
| Send | 2 | 显示为发送样式。 |  
| Next | 3 | 显示为下一个样式。 |  
| Done | 4 | 显示为确认样式。 |  
    
## TextInputController<sup>(8+)</sup>    
TextInput组件的控制器。  
    
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
设置文本选择区域并高亮显示。  
  
 **调用形式：**     
- setTextSelection(selectionStart: number, selectionEnd: number): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| selectionStart | number | true | 文本选择区域起始位置，文本框中文字的起始位置为0。<br/> |  
| selectionEnd | number | true | 文本选择区域结束位置。<br/> |  
    
### stopEditing<sup>(10+)</sup>    
退出编辑态。  
  
 **调用形式：**     
- stopEditing(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## TextInputOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| placeholder | ResourceStr | false | false | 设置无输入时的提示文本。 |  
| text | ResourceStr | false | false | 设置输入框当前的文本内容。<br/>当组件设置<a href="https://file+.vscode-resource.vscode-cdn.net/c:/Code/test/ts-universal-attributes-polymorphic-style.md">stateStyles</a>等刷新属性时，建议通过onChange事件将状态变量与文本实时绑定，<br/>避免组件刷新时TextInput中的文本内容异常。 |  
| controller<sup>(8+)</sup> | TextInputController | false | false | 设置TextInput控制器。<br/> |  
    
## TextInputStyle<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Default | 0 | 默认风格，光标宽1.5vp，光标高度与文本选中底板高度和字体大小相关。 |  
| Inline | 1 | 内联输入风格。文本选中底板高度与输入框高度相同。<br/>内联输入是在有明显的编辑态/非编辑态的区分场景下使用，例如：文件列表视图中的重命名。<br/>不支持showError属性。<br/> |  
    
## 接口  
  
  
  
    
 **调用形式**     
    
- TextInput(value?: TextInputOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(7+)</sup> | TextInputOptions | false |  |  
    
## CaretStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width<sup>(10+)</sup> | Length | false | false |  |  
    
## PasswordIcon<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onIconSrc<sup>(10+)</sup> | string \| Resource | false | false | 密码输入模式时，能够切换密码隐藏的显示状态的图标。 |  
| offIconSrc<sup>(10+)</sup> | string \| Resource | false | false | <span style="letter-spacing: 0px;"></span><span style="letter-spacing: 0px;">密码输入模式时，能够切换密码显示的隐藏状态的图标。</span><br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| type |  InputType |  |  
| placeholderColor |  ResourceColor |  |  
| placeholderFont | null |  |  
| enterKeyType |  EnterKeyType |  |  
| caretColor |  ResourceColor |  |  
| maxLength |  number |  |  
| fontColor |  ResourceColor |  |  
| fontSize |  Length |  |  
| fontStyle |  FontStyle |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| fontFamily |  ResourceStr |  |  
| inputFilter(value: ResourceStr, error?: <sup>8+</sup> |  string) => void |  |  
| copyOption<sup>9+</sup> |  CopyOptions |  |  
| showPasswordIcon<sup>9+</sup> |  boolean |  |  
| textAlign<sup>9+</sup> |  TextAlign |  |  
| style<sup>9+</sup> |  TextInputStyle \| TextContentStyle |  |  
| caretStyle<sup>10+</sup> |  CaretStyle |  |  
| selectedBackgroundColor<sup>10+</sup> |  ResourceColor |  |  
| caretPosition<sup>10+</sup> |  number |  |  
| enableKeyboardOnFocus<sup>10+</sup> |  boolean |  |  
| passwordIcon<sup>10+</sup> |  PasswordIcon |  |  
| showError<sup>10+</sup> | null |  |  
| showUnit<sup>10+</sup> |  CustomBuilder |  |  
| showUnderline<sup>10+</sup> |  boolean |  |  
| selectionMenuHidden<sup>10+</sup> |  boolean |  |  
| barState<sup>10+</sup> |  BarState |  |  
| maxLines<sup>10+</sup> |  number |  |  
| customKeyboard<sup>10+</sup> |  CustomBuilder |  |  
    
### onEditChanged    
onEditChanged(callback: (isEditing: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (isEditing: boolean) => void | true |  |  
    
### onEditChange<sup>(deprecated)</sup>    
onEditChange(callback: (isEditing: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onSubmit<sup>(deprecated)</sup>    
onSubmit(callback: (enterKey: EnterKeyType) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: string) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onTextSelectionChange<sup>(deprecated)</sup>    
onTextSelectionChange(callback: (selectionStart: number, selectionEnd: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onContentScroll<sup>(deprecated)</sup>    
onContentScroll(callback: (totalOffsetX: number, totalOffsetY: number) => void)    
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
struct TextInputExample {  
  @State text: string = ''  
  controller: TextInputController = new TextInputController()  
  
  build() {  
    Column() {  
      TextInput({ text: this.text, placeholder: 'input your word...', controller: this.controller })  
        .placeholderColor(Color.Grey)  
        .placeholderFont({ size: 14, weight: 400 })  
        .caretColor(Color.Blue)  
        .width(400)  
        .height(40)  
        .margin(20)  
        .fontSize(14)  
        .fontColor(Color.Black)  
        .inputFilter('[a-z]', (e) => {  
          console.log(JSON.stringify(e))  
        })  
        .onChange((value: string) => {  
          this.text = value  
        })  
      Text(this.text)  
      Button('Set caretPosition 1')  
        .margin(15)  
        .onClick(() => {  
          // 将光标移动至第一个字符后  
          this.controller.caretPosition(1)  
        })  
      // 密码输入框  
      TextInput({ placeholder: 'input your password...' })  
        .width(400)  
        .height(40)  
        .margin(20)  
        .type(InputType.Password)  
        .maxLength(9)  
        .showPasswordIcon(true)  
      // 内联风格输入框  
      TextInput({ text: 'inline style' })  
        .width(400)  
        .height(50)  
        .margin(20)  
        .borderRadius(0)  
        .style(TextInputStyle.Inline)  
    }.width('100%')  
  }  
}  
    
```    
  
![TextInput](figures/TextInput.png)  
    
 **示例代码2：**   
```ts    
@Entry  
@Component  
struct TextInputExample {  
  @State PassWordSrc1: Resource = $r('app.media.onIcon')  
  @State PassWordSrc2: Resource = $r('app.media.offIcon')  
  @State TextError: string = ''  
  @State Text: string = ''  
  @State NameText: string = 'test'  
  
  @Builder itemEnd() {  
    Select([{ value: 'KB' },  
      { value: 'MB' },  
      { value: 'GB' },  
      { value: 'TB', }])  
      .height("48vp")  
      .borderRadius(0)  
      .selected(2)  
      .align(Alignment.Center)  
      .value('MB')  
      .font({ size: 20, weight: 500 })  
      .fontColor('#182431')  
      .selectedOptionFont({ size: 20, weight: 400 })  
      .optionFont({ size: 20, weight: 400 })  
      .backgroundColor(Color.Transparent)  
      .responseRegion({ height: "40vp", width: "80%", x: '10%', y: '6vp' })  
      .onSelect((index: number) => {  
        console.info('Select:' + index)  
      })  
  }  
  
  build() {  
    Column({ space: 20 }) {  
      // 自定义密码显示图标  
      TextInput({ placeholder: 'user define password icon' })  
        .type(InputType.Password)  
        .width(380)  
        .height(60)  
        .passwordIcon({ onIconSrc: this.PassWordSrc1, offIconSrc: this.PassWordSrc2 })  
      // 下划线模式  
      TextInput({ placeholder: 'underline style' })  
        .showUnderline(true)  
        .width(380)  
        .height(60)  
        .showError('Error')  
        .showUnit(this.itemEnd.bind(this))  
  
      Text(`用户名：${this.Text}`)  
        .width('95%')  
      TextInput({ placeholder: '请输入用户名', text: this.Text })  
        .showUnderline(true)  
        .width(380)  
        .showError(this.TextError)  
        .onChange((value: string) => {  
          this.Text = value  
        })  
        .onSubmit(() => { // 用户名不正确会清空输入框和用户名并提示错误文本  
          if (this.Text == this.NameText) {  
            this.TextError = ''  
          } else {  
            this.TextError = '用户名输入错误'  
            this.Text = ''  
          }  
        })  
  
    }.width('100%')  
  }  
}  
    
```    
  
![TextInputError](figures/TextInputError.png)  
    
 **示例代码3：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct TextInputExample {  
  controller: TextInputController = new TextInputController()  
  @State inputValue: string = ""  
  
  // 自定义键盘组件  
  @Builder CustomKeyboardBuilder() {  
    Column() {  
      Button('x').onClick(() => {  
        // 关闭自定义键盘  
        this.controller.stopEditing()  
      })  
      Grid() {  
        ForEach([1, 2, 3, 4, 5, 6, 7, 8, 9, '*', 0, '#'], (item:number|string) => {  
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
      TextInput({ controller: this.controller, text: this.inputValue })  
        // 绑定自定义键盘  
        .customKeyboard(this.CustomKeyboardBuilder()).margin(10).border({ width: 1 })  
    }  
  }  
}  
    
```    
  
![customKeyboard](figures/textInputCustomKeyboard.png)  
