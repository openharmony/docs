# select    
提供下拉选择菜单，可以让用户在多个选项之间选择。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SelectOption  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value | ResourceStr | false | true | 下拉选项内容。<br/> |  
| icon | ResourceStr | false | false | 下拉选项图片。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Select(options: Array<SelectOption>)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | Array<SelectOption> | true |  |  
    
## ArrowPosition<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| END | 0 | 文字在前，箭头在后<br/> |  
| START | 1 | 箭头在前，文字在后<br/> |  
    
## MenuAlignType<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| START | 0 | 按照语言方向起始端对齐<br/> |  
| CENTER | 1 | 居中对齐<br/> |  
| END | 2 | 按照语言方向末端对齐<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| selected |  number |  |  
| value |  string |  |  
| font |  Font |  |  
| fontColor |  ResourceColor |  |  
| selectedOptionBgColor |  ResourceColor |  |  
| selectedOptionFont |  Font |  |  
| selectedOptionFontColor |  ResourceColor |  |  
| optionBgColor |  ResourceColor |  |  
| optionFont |  Font |  |  
| optionFontColor |  ResourceColor |  |  
| space<sup>10+</sup> |  Length |  |  
| arrowPosition<sup>10+</sup> |  ArrowPosition |  |  
| menuAlign<sup>10+</sup> | null |  |  
    
### onSelect<sup>(deprecated)</sup>    
onSelect(callback: (index: number, value: string) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct SelectExample {  
  @State text: string = "TTTTT"  
  @State index: number = 2  
  @State space: number = 8  
  @State arrowPosition: ArrowPosition = ArrowPosition.END  
  build() {  
    Column() {  
      Select([{ value: 'aaa', icon: "/common/public_icon.svg" },  
        { value: 'bbb', icon: "/common/public_icon.svg" },  
        { value: 'ccc', icon: "/common/public_icon.svg" },  
        { value: 'ddd', icon: "/common/public_icon.svg" }])  
        .selected(this.index)  
        .value(this.text)  
        .font({ size: 16, weight: 500 })  
        .fontColor('#182431')  
        .selectedOptionFont({ size: 16, weight: 400 })  
        .optionFont({ size: 16, weight: 400 })  
        .space(this.space)  
        .arrowPosition(this.arrowPosition)  
        .menuAlign(MenuAlignType.START, {dx:0, dy:0})  
        .onSelect((index:number, text?: string | undefined)=>{  
          console.info('Select:' + index)  
          this.index = index;  
          if(text){  
            this.text = text;  
          }  
        })  
    }.width('100%')  
  }  
}  
    
```    
  
![](figures/select.png)  
