# calendar_picker    
日历选择器组件,提供下拉日历弹窗，可以让用户选择日期。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## CalendarAlign    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| START | 0 | 设置选择器与入口组件左对齐的对齐方式。 |  
| CENTER | 1 | 设置选择器与入口组件居中对齐的对齐方式。 |  
| END | 2 | 设置选择器与入口组件右对齐的对齐方式。 |  
    
## CalendarOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| hintRadius | number \| Resource | false | false | 描述日期选中态底板样式。<br/>默认值：底板样式为圆形。<br />**说明：**<br />hintRadius为0，底板样式为直角矩形。hintRadius为0 ~ 16，底板样式为圆角矩形。hintRadius>=16，底板样式为圆形 |  
| selected | Date | false | false | 设置选中项的日期。<br/>默认值：当前系统日期。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- CalendarPicker(options?: CalendarOptions)    
起始版本： 10    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | CalendarOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| edgeAlign | null |  |  
| textStyle |  PickerTextStyle |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: Date) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
## CalendarDialogOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| onAccept | function | false | false |  |  
| onCancel | function | false | false |  |  
| onChange | function | false | false |  |  
    
## CalendarPickerDialog  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### show  
 **调用形式：**     
- static show(options?: CalendarDialogOptions): void  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | CalendarDialogOptions | false |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct CalendarPickerExample {  
  private selectedDate: Date = new Date()  
  build() {  
    Column() {  
      Text('月历日期选择器').fontSize(30)  
      Column() {  
        CalendarPicker({ hintRadius: 10, selected: this.selectedDate })  
          .edgeAlign(CalendarAlign.END)  
          .textStyle({ color: "#ff182431", font: { size: 20, weight: FontWeight.Normal } })  
          .margin(10)  
          .onChange((value) => {  
            console.info("CalendarPicker onChange:" + JSON.stringify(value))  
          })  
      }.alignItems(HorizontalAlign.End).width("100%")  
    }.width('100%').margin({top:350})  
  }  
}  
    
```    
  
![CalendarPicker](figures/CalendarPicker.gif)  
