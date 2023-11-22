# checkbox    
提供多选框组件，通常用于某选项的打开或关闭。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## CheckboxOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| name | string | false | false | 多选框名称。 |  
| group | string | false | false | 多选框的群组名称。<br/>**说明：** <br/>未配合使用CheckboxGroup组件时，此值无用 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Checkbox(options?: CheckboxOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | CheckboxOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| select |  boolean |  |  
| selectedColor |  ResourceColor |  |  
| unselectedColor<sup>10+</sup> |  ResourceColor |  |  
| mark<sup>10+</sup> |  MarkStyle |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct CheckboxExample {  
  
  build() {  
    Row() {  
      Checkbox({name: 'checkbox1',  group: 'checkboxGroup'})  
        .select(true)  
        .selectedColor(0xed6f21)  
        .shape(CheckBoxShape.ROUNDED_SQUARE)  
        .onChange((value: boolean) => {  
          console.info('Checkbox1 change is'+ value)  
        })  
      Checkbox({name: 'checkbox2',  group: 'checkboxGroup'})  
        .select(false)  
        .selectedColor(0x39a2db)  
        .shape(CheckBoxShape.ROUNDED_SQUARE)  
        .onChange((value: boolean) => {  
          console.info('Checkbox2 change is'+ value)  
        })  
    }  
  }  
}  
    
```    
  
![](figures/checkbox.gif)  
    
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
          Checkbox({ name: 'checkbox1', group: 'checkboxGroup' })  
            .selectedColor(0x39a2db)  
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
            .onChange((value: boolean) => {  
              console.info('Checkbox2 change is' + value)  
            })  
            .width(30)  
            .height(30)  
          Text('Checkbox2').fontSize(20)  
        }  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
![](figures/checkbox2.gif)  
