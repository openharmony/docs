# alphabet_indexer    
可以与容器组件联动用于按逻辑结构快速定位容器显示区域的组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## IndexerAlign    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Left | 0 | 弹框显示在索引条右侧。 |  
| Right | 1 | 弹框显示在索引条左侧。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- AlphabetIndexer(value: { arrayValue: Array<string>; selected: number })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| arrayValue | Array<string> | true | 字母索引字符串数组，不可设置为空。 |  
| selected | number | true | 初始选中项索引值，若超出索引值范围，则取默认值0。<br />从API version 10开始，该参数支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| color |  ResourceColor |  |  
| selectedColor |  ResourceColor |  |  
| popupColor |  ResourceColor |  |  
| selectedBackgroundColor |  ResourceColor |  |  
| popupBackground |  ResourceColor |  |  
| popupSelectedColor<sup>10+</sup> |  ResourceColor |  |  
| popupUnselectedColor<sup>10+</sup> |  ResourceColor |  |  
| popupItemBackgroundColor<sup>10+</sup> |  ResourceColor |  |  
| usingPopup |  boolean |  |  
| selectedFont |  Font |  |  
| popupFont |  Font |  |  
| popupItemFont<sup>10+</sup> |  Font |  |  
| itemSize |  string \| number |  |  
| font |  Font |  |  
| alignStyle |  IndexerAlign, offset?: Length |  |  
| selected<sup>8+</sup> | null |  |  
| popupPosition<sup>8+</sup> |  Position |  |  
    
### onSelected    
onSelected(callback: (index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (index: number) => void | true |  |  
    
### onSelect<sup>(deprecated)</sup>    
onSelect(callback: (index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onRequestPopupData<sup>(deprecated)</sup>    
onRequestPopupData(callback: (index: number) => Array<string>)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onPopupSelect<sup>(deprecated)</sup>    
onPopupSelect(callback: (index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct AlphabetIndexerSample {  
  private arrayA: string[] = ['安']  
  private arrayB: string[] = ['卜', '白', '包', '毕', '丙']  
  private arrayC: string[] = ['曹', '成', '陈', '催']  
  private arrayL: string[] = ['刘', '李', '楼', '梁', '雷', '吕', '柳', '卢']  
  private value: string[] = ['#', 'A', 'B', 'C', 'D', 'E', 'F', 'G',  
  'H', 'I', 'J', 'K', 'L', 'M', 'N',  
  'O', 'P', 'Q', 'R', 'S', 'T', 'U',  
  'V', 'W', 'X', 'Y', 'Z']  
  
  build() {  
    Stack({ alignContent: Alignment.Start }) {  
      Row() {  
        List({ space: 20, initialIndex: 0 }) {  
          ForEach(this.arrayA, (item: string) => {  
            ListItem() {  
              Text(item)  
                .width('80%')  
                .height('5%')  
                .fontSize(30)  
                .textAlign(TextAlign.Center)  
            }.editable(true)  
          }, (item: string) => item)  
  
          ForEach(this.arrayB, (item: string) => {  
            ListItem() {  
              Text(item)  
                .width('80%')  
                .height('5%')  
                .fontSize(30)  
                .textAlign(TextAlign.Center)  
            }.editable(true)  
          }, (item: string) => item)  
  
          ForEach(this.arrayC, (item: string) => {  
            ListItem() {  
              Text(item)  
                .width('80%')  
                .height('5%')  
                .fontSize(30)  
                .textAlign(TextAlign.Center)  
            }.editable(true)  
          }, (item: string) => item)  
  
          ForEach(this.arrayL, (item: string) => {  
            ListItem() {  
              Text(item)  
                .width('80%')  
                .height('5%')  
                .fontSize(30)  
                .textAlign(TextAlign.Center)  
            }.editable(true)  
          }, (item: string) => item)  
        }  
        .width('50%')  
        .height('100%')  
  
        AlphabetIndexer({ arrayValue: this.value, selected: 0 })  
          .selectedColor(0xFFFFFF) // 选中项文本颜色  
          .popupColor(0xFFFAF0) // 弹出框文本颜色  
          .selectedBackgroundColor(0xCCCCCC) // 选中项背景颜色  
          .popupBackground(0xD2B48C) // 弹出框背景颜色  
          .usingPopup(true) // 是否显示弹出框  
          .selectedFont({ size: 16, weight: FontWeight.Bolder }) // 选中项字体样式  
          .popupFont({ size: 30, weight: FontWeight.Bolder }) // 弹出框内容的字体样式  
          .itemSize(28) // 每一项的尺寸大小  
          .alignStyle(IndexerAlign.Left) // 弹出框在索引条右侧弹出  
          .popupSelectedColor(0x00FF00)  
          .popupUnselectedColor(0x0000FF)  
          .popupItemFont({ size: 30, style: FontStyle.Normal })  
          .popupItemBackgroundColor(0xCCCCCC)  
          .onSelect((index: number) => {  
            console.info(this.value[index] + ' Selected!')  
          })  
          .onRequestPopupData((index: number) => {  
            if (this.value[index] == 'A') {  
              return this.arrayA // 当选中A时，弹出框里面的提示文本列表显示A对应的列表arrayA，选中B、C、L时也同样  
            } else if (this.value[index] == 'B') {  
              return this.arrayB  
            } else if (this.value[index] == 'C') {  
              return this.arrayC  
            } else if (this.value[index] == 'L') {  
              return this.arrayL  
            } else {  
              return [] // 选中其余子母项时，提示文本列表为空  
            }  
          })  
          .onPopupSelect((index: number) => {  
            console.info('onPopupSelected:' + index)  
          })  
      }  
      .width('100%')  
      .height('100%')  
    }  
  }  
}  
    
```    
  
![alphabet](figures/alphabet.gif)  
