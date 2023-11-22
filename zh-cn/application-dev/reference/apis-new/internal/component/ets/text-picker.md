# text_picker    
滑动选择文本内容的组件。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## TextPickerRangeContent<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| icon<sup>(10+)</sup> | string \| Resource | false | true | 图片资源。 |  
| text<sup>(10+)</sup> | string \| Resource | false | false | 文本信息。 |  
    
## TextCascadePickerRangeContent<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| text<sup>(10+)</sup> | string \| Resource | false | true | 文本信息。 |  
| children<sup>(10+)</sup> | TextCascadePickerRangeContent[] | false | false | 联动数据。 |  
    
## TextPickerOptions    
根据range指定的选择范围创建文本选择器。  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| range | string[] \| string[][] \| Resource \| TextPickerRangeContent[] \| TextCascadePickerRangeContent[] | false | true | 选择器的数据选择列表。不可设置为空数组，若设置为空数组，则不显示；若动态变化为空数组，则保持当前正常值显示。<br/><strong>说明</strong>：单列数据选择器使用string[]，Resource，TextPickerRangeContent[]类型。<br/>多列数据选择器使用string[][]类型。<br/>多列联动数据选择器使用TextCascadePickerRangeContent[]类型。<br/>Resource类型只支持strarray.json。 |  
| value | string \| string[] | false | false | 设置默认选中项在数组中的索引值。<br/>默认值：0<br/><strong>说明</strong>：单列数据选择器使用number类型。<br/>多列、多列联动数据选择器使用number[]类型。<br/>从API version 10开始，该参数支持$$双向绑定变量。 |  
| selected | number \| number[] | false | false | 设置默认选中项的值，优先级低于selected。<br/>默认值：第一个元素值<br/><strong>说明</strong>：只有显示文本列表时该值有效。显示图片或图片加文本的列表时，该值无效。<br/>单列数据选择器使用string类型。<br/>多列、多列联动数据选择器使用string[]类型。<br/>从API version 10开始，该参数支持$$双向绑定变量。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- TextPicker(options?: TextPickerOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | TextPickerOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| defaultPickerItemHeight |  number \| string |  |  
| canLoop<sup>10+</sup> |  boolean |  |  
| disappearTextStyle<sup>10+</sup> |  PickerTextStyle |  |  
| textStyle<sup>10+</sup> |  PickerTextStyle |  |  
| selectedTextStyle<sup>10+</sup> |  PickerTextStyle |  |  
| selectedIndex<sup>10+</sup> |  number \| number[] |  |  
    
### onAccept    
onAccept(callback: (value: string, index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (value: string, index: number) => void | true |  |  
    
### onCancel    
onCancel(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | () => void | true |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: string | string[], index: number | number[]) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
## TextPickerResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value | string \| string[] | false | true |  |  
| index | number \| number[] | false | true |  |  
    
## TextPickerDialogOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| defaultPickerItemHeight | number \| string | false | false |  |  
| canLoop<sup>(10+)</sup> | boolean | false | false |  |  
| disappearTextStyle<sup>(10+)</sup> | PickerTextStyle | false | false |  |  
| textStyle<sup>(10+)</sup> | PickerTextStyle | false | false |  |  
| selectedTextStyle<sup>(10+)</sup> | PickerTextStyle | false | false |  |  
| onAccept | function | false | false |  |  
| onCancel | function | false | false |  |  
| onChange | function | false | false |  |  
| maskRect<sup>(10+)</sup> | Rectangle | false | false |  |  
| alignment<sup>(10+)</sup> | DialogAlignment | false | false |  |  
| offset<sup>(10+)</sup> | Offset | false | false |  |  
    
## TextPickerDialog    
### show  
 **调用形式：**     
- static show(options?: TextPickerDialogOptions)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | TextPickerDialogOptions | false |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
class bottom {  
  bottom:number = 50  
}  
let bott:bottom = new bottom()  
@Entry  
@Component  
struct TextPickerExample {  
  private select: number = 1  
  private apfruits: string[] = ['apple1', 'apple2', 'apple3', 'apple4']  
  private orfruits: string[] = ['orange1', 'orange2', 'orange3', 'orange4']  
  private pefruits: string[] = ['peach1', 'peach2', 'peach3', 'peach4']  
  private multi: string[][] = [this.apfruits, this.orfruits, this.pefruits]  
  private cascade: TextCascadePickerRangeContent[] = [  
    {  
      text: '辽宁省',  
      children: [{ text: '沈阳市', children: [{ text: '沈河区' }, { text: '和平区' }, { text: '浑南区' }] },  
        { text: '大连市', children: [{ text: '中山区' }, { text: '金州区' }, { text: '长海县' }] }]  
    },  
    {  
      text: '吉林省',  
      children: [{ text: '长春市', children: [{ text: '南关区' }, { text: '宽城区' }, { text: '朝阳区' }] },  
        { text: '四平市', children: [{ text: '铁西区' }, { text: '铁东区' }, { text: '梨树县' }] }]  
    },  
    {  
      text: '黑龙江省',  
      children: [{ text: '哈尔滨市', children: [{ text: '道里区' }, { text: '道外区' }, { text: '南岗区' }] },  
        { text: '牡丹江市', children: [{ text: '东安区' }, { text: '西安区' }, { text: '爱民区' }] }]  
    }  
  ]  
  
  build() {  
    Column() {  
  
      TextPicker({ range: this.apfruits, selected: this.select })  
        .onChange((value: string | string[], index: number | number[]) => {  
          console.info('Picker item changed, value: ' + value + ', index: ' + index)  
        }).margin(bott)  
  
      TextPicker({ range: this.multi })  
        .onChange((value: string | string[], index: number | number[]) => {  
          console.info('TextPicker 多列:onChange ' + JSON.stringify(value) + ', ' + 'index: ' + JSON.stringify(index))  
        }).margin(bott)  
  
      TextPicker({ range: this.cascade })  
        .onChange((value: string | string[], index: number | number[]) => {  
          console.info('TextPicker 多列联动:onChange ' + JSON.stringify(value) + ', ' + 'index: ' + JSON.stringify(index))  
        })  
    }  
  }  
}  
    
```    
  
![textpicker](figures/textpicker1.gif)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct TextPickerExample {  
  private select: number = 1  
  private fruits: string[] = ['apple1', 'orange2', 'peach3', 'grape4']  
  
  build() {  
    Column() {  
      TextPicker({ range: this.fruits, selected: this.select })  
        .onChange((value: string | string[], index: number | number[]) => {  
          console.info('Picker item changed, value: ' + value + ', index: ' + index)  
        })  
        .disappearTextStyle({color: Color.Red, font: {size: 15, weight: FontWeight.Lighter}})  
        .textStyle({color: Color.Black, font: {size: 20, weight: FontWeight.Normal}})  
        .selectedTextStyle({color: Color.Blue, font: {size: 30, weight: FontWeight.Bolder}})  
    }.width('100%').height('100%')  
  }  
}  
    
```    
  
![textpicker](figures/textpicker1.gif)  
