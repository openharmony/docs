# search    
搜索框组件，适用于浏览器的搜索内容输入框等应用场景。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SearchController    
Search组件的控制器，目前通过它可控制Search组件的光标位置。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### caretPosition    
设置输入光标的位置  
  
 **调用形式：**     
- caretPosition(value: number): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true | 从字符串开始到光标所在位置的长度<br/> |  
    
### stopEditing<sup>(10+)</sup>    
退出编辑态  
  
 **调用形式：**     
- stopEditing(): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## CancelButtonStyle<sup>(10+)</sup>    
  
    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONSTANT | 0 | 清除按钮常显样式。<br/> |  
| INVISIBLE | 1 | 清除按钮常隐样式。<br/> |  
| INPUT | 2 | 清除按钮常显样式。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Search(options?: {     /**      * Text input in the search text box      *      * @type { ?string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     value?: string;      /**      * Text displayed when there is no input      *      * @type { string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     /**      * Text displayed when there is no input      *      * @type { ?ResourceStr }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 10      */     placeholder?: ResourceStr;      /**      * Path to the search icon      *      * @type { ?string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     icon?: string;      /**      * Controller of the <Search> component      *      * @type { ?SearchController }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     controller?: SearchController   })    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | {     /**      * Text input in the search text box      *      * @type { ?string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     value?: string;      /**      * Text displayed when there is no input      *      * @type { string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     /**      * Text displayed when there is no input      *      * @type { ?ResourceStr }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 10      */     placeholder?: ResourceStr;      /**      * Path to the search icon      *      * @type { ?string }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     icon?: string;      /**      * Controller of the <Search> component      *      * @type { ?SearchController }      * @syscap SystemCapability.ArkUI.ArkUI.Full      * @since 8      */     controller?: SearchController   } | false |  |  
    
## IconOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| size<sup>(10+)</sup> | Length | false | false | 图标尺寸，不支持百分比<br/> |  
| color<sup>(10+)</sup> | ResourceColor | false | false | 图标颜色<br/> |  
| src<sup>(10+)</sup> | ResourceStr | false | false | 图标/图片源<br/> |  
    
## CaretStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width<sup>(10+)</sup> | Length | false | false | 光标尺寸，不支持百分比<br/> |  
| color<sup>(10+)</sup> | ResourceColor | false | false | 光标颜色<br/> |  
    
## SearchButtonOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| fontSize<sup>(10+)</sup> | Length | false | false | 文本按钮字体大小，不支持百分比<br/> |  
| fontColor<sup>(10+)</sup> | ResourceColor | false | false | 文本按钮字体颜色<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| searchButton |  string, option?: SearchButtonOptions |  |  
| fontColor<sup>10+</sup> |  ResourceColor |  |  
| searchIcon<sup>10+</sup> |  IconOptions |  |  
| cancelButton<sup>10+</sup> |  { style?: CancelButtonStyle, icon?: IconOptions } |  |  
| caretStyle<sup>10+</sup> |  CaretStyle |  |  
| placeholderColor |  ResourceColor |  |  
| placeholderFont | null |  |  
| textFont | null |  |  
| copyOption<sup>9+</sup> |  CopyOptions |  |  
| textAlign<sup>9+</sup> |  TextAlign |  |  
| enableKeyboardOnFocus<sup>10+</sup> |  boolean |  |  
| selectionMenuHidden<sup>10+</sup> |  boolean |  |  
| customKeyboard<sup>10+</sup> |  CustomBuilder |  |  
    
### onSubmit<sup>(deprecated)</sup>    
onSubmit(callback: (value: string) => void)    
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
    
 **示例代码2：**   
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
    
 **示例代码3：**   
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
    
```    
  
![customKeyboard](figures/searchCustomKeyboard.png)  
