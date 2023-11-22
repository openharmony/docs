# checkboxgroup    
多选框群组，用于控制多选框全选或者不全选状态。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SelectStatus    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| All | 0 | 群组多选择框全部选择。 |  
| Part | 1 | 群组多选择框部分选择。 |  
| None | 2 | 群组多选择框全部没有选择。 |  
    
## CheckboxGroupOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| group | string | false | false | 群组名称。<br/>**说明：** <br/>多个相同群组名称的CheckboxGroup，仅第一个CheckboxGroup生效。 |  
    
## CheckboxGroupResult  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | Array<string> | false | true | 群组内所有被选中的多选框名称。 |  
| status | SelectStatus | false | true | 选中状态。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- CheckboxGroup(options?: CheckboxGroupOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | CheckboxGroupOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| selectAll |  boolean |  |  
| selectedColor |  ResourceColor |  |  
| unselectedColor<sup>10+</sup> |  ResourceColor |  |  
| mark<sup>10+</sup> |  MarkStyle |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (event: CheckboxGroupResult) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct CheckboxExample {  
  build() {  
    Scroll() {  
      Column() {  
        // 全选按钮  
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {  
          CheckboxGroup({ group: 'checkboxGroup' })  
            .selectedColor('#007DFF')  
            .onChange((itemName: CheckboxGroupResult) => {  
              console.info("checkbox group content" + JSON.stringify(itemName))  
            })  
          Text('Select All').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)  
        }  
  
        // 选项1  
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {  
          Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })  
            .selectedColor('#007DFF')  
            .shape(CheckBoxShape.ROUNDED_SQUARE)  
            .onChange((value: boolean) => {  
              console.info('Checkbox1 change is' + value)  
            })  
          Text('Checkbox1').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)  
        }.margin({ left: 36 })  
  
        // 选项2  
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {  
          Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })  
            .selectedColor('#007DFF')  
            .shape(CheckBoxShape.ROUNDED_SQUARE)  
            .onChange((value: boolean) => {  
              console.info('Checkbox2 change is' + value)  
            })  
          Text('Checkbox2').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)  
        }.margin({ left: 36 })  
  
        // 选项3  
        Flex({ justifyContent: FlexAlign.Start, alignItems: ItemAlign.Center }) {  
          Checkbox({ name: 'checkbox3', group: 'checkboxGroup' })  
            .selectedColor('#007DFF')  
            .shape(CheckBoxShape.ROUNDED_SQUARE)  
            .onChange((value: boolean) => {  
              console.info('Checkbox3 change is' + value)  
            })  
          Text('Checkbox3').fontSize(14).lineHeight(20).fontColor('#182431').fontWeight(500)  
        }.margin({ left: 36 })  
      }  
    }  
  }  
}  
    
```    
  
![checkboxGroup](figures/checkboxGroup.gif)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct Index {  
  
  build() {  
    Row() {  
      Column() {  
        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
          CheckboxGroup({ group: 'checkboxGroup' })  
            .selectedColor(Color.Orange)  
            .onChange((itemName: CheckboxGroupResult) => {  
              console.info("checkbox group content" + JSON.stringify(itemName))  
            })  
            .mark({  
              strokeColor:Color.Black,  
              size: 40,  
              strokeWidth: 5  
            })  
            .unselectedColor(Color.Red)  
            .width(30)  
            .height(30)  
          Text('Select All').fontSize(20)  
        }.margin({right:15})  
        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
          Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })  
            .selectedColor(0x39a2db)  
            .shape(CheckBoxShape.ROUNDED_SQUARE)  
            .onChange((value: boolean) => {  
              console.info('Checkbox1 change is'+ value)  
            })  
            .mark({  
              strokeColor:Color.Black,  
              size: 50,  
              strokeWidth: 5  
            })  
            .unselectedColor(Color.Red)  
            .width(30)  
            .height(30)  
          Text('Checkbox1').fontSize(20)  
        }  
        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
          Checkbox({ name: 'checkbox2', group: 'checkboxGroup' })  
            .selectedColor(0x39a2db)  
            .shape(CheckBoxShape.ROUNDED_SQUARE)  
            .onChange((value: boolean) => {  
              console.info('Checkbox2 change is' + value)  
            })  
            .width(30)  
            .height(30)  
          Text('Checkbox2').fontSize(20)  
        }  
        Flex({ justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
          Checkbox({ name: 'checkbox3', group: 'checkboxGroup' })  
            .selectedColor(0x39a2db)  
            .shape(CheckBoxShape.ROUNDED_SQUARE)  
            .onChange((value: boolean) => {  
              console.info('Checkbox3 change is' + value)  
            })  
            .width(30)  
            .height(30)  
          Text('Checkbox3').fontSize(20)  
        }  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
![checkboxGroup](figures/checkboxGroup2.gif)  
