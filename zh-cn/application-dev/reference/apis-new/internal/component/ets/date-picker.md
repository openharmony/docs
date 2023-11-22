# date_picker    
日期选择器组件，用于根据指定日期范围创建日期滑动选择器。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## DatePickerResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| year | number | false | false |  |  
| month | number | false | false |  |  
| day | number | false | false |  |  
    
## DatePickerOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| start | Date | false | false |  |  
| end | Date | false | false |  |  
| selected | Date | false | false |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- DatePicker(options?: DatePickerOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | DatePickerOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| lunar |  boolean |  |  
| disappearTextStyle<sup>10+</sup> |  PickerTextStyle |  |  
| textStyle<sup>10+</sup> |  PickerTextStyle |  |  
| selectedTextStyle<sup>10+</sup> |  PickerTextStyle |  |  
    
### onChange    
onChange(callback: (value: DatePickerResult) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | (value: DatePickerResult) => void | true |  |  
    
### onDateChange<sup>(deprecated)</sup>    
onDateChange(callback: (value: Date) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
## DatePickerDialogOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| lunar | boolean | false | false |  |  
| lunarSwitch<sup>(10+)</sup> | boolean | false | false |  |  
| showTime<sup>(10+)</sup> | boolean | false | false |  |  
| useMilitaryTime<sup>(10+)</sup> | boolean | false | false |  |  
| disappearTextStyle<sup>(10+)</sup> | PickerTextStyle | false | false |  |  
| textStyle<sup>(10+)</sup> | PickerTextStyle | false | false |  |  
| selectedTextStyle<sup>(10+)</sup> | PickerTextStyle | false | false |  |  
| maskRect<sup>(10+)</sup> | Rectangle | false | false |  |  
| alignment<sup>(10+)</sup> | DialogAlignment | false | false |  |  
| offset<sup>(10+)</sup> | Offset | false | false |  |  
| onAccept<sup>(deprecated)</sup> | function | false | false | 从API version 8 开始支持，从API version 10 开始废弃。建议使用datePicker/DatePickerDialogOptions#onDateAccept替代。 |  
| onCancel | function | false | false |  |  
| onChange<sup>(deprecated)</sup> | function | false | false | 从API version 8 开始支持，从API version 10 开始废弃。建议使用datePicker/DatePickerDialogOptions#onDateChange替代。 |  
| onDateAccept<sup>(10+)</sup> | function | false | false |  |  
| onDateChange<sup>(10+)</sup> | function | false | false |  |  
    
## DatePickerDialog  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### show  
 **调用形式：**     
- static show(options?: DatePickerDialogOptions)  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | DatePickerDialogOptions | false |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct DatePickerExample {  
  @State isLunar: boolean = false  
  private selectedDate: Date = new Date('2021-08-08')  
  
  build() {  
    Column() {  
      Button('切换公历农历')  
        .margin({ top: 30, bottom: 30 })  
        .onClick(() => {  
          this.isLunar = !this.isLunar  
        })  
      DatePicker({  
        start: new Date('1970-1-1'),  
        end: new Date('2100-1-1'),  
        selected: this.selectedDate  
      })  
        .disappearTextStyle({color: Color.Gray, font: {size: '16fp', weight: FontWeight.Bold}})  
        .textStyle({color: '#ff182431', font: {size: '18fp', weight: FontWeight.Normal}})  
        .selectedTextStyle({color: '#ff0000FF', font: {size: '26fp', weight: FontWeight.Regular}})  
        .lunar(this.isLunar)  
        .onDateChange((value: Date) => {  
          this.selectedDate = value  
          console.info('select current date is: ' + value.toString())  
        })  
  
    }.width('100%')  
  }  
}  
    
```    
  
![datePicker](figures/DatePickerApi10.gif)  
