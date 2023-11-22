# radio    
单选框，提供相应的用户交互选择项。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## RadioOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| group | string | false | true | 当前单选框的所属群组名称，相同group的Radio只能有一个被选中。 |  
| value | string | false | true | 当前单选框的值。 |  
    
## RadioStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| checkedBackgroundColor<sup>(10+)</sup> | ResourceColor | false | false | 开启状态底板颜色。 |  
| uncheckedBorderColor<sup>(10+)</sup> | ResourceColor | false | false | 关闭状态描边颜色。 |  
| indicatorColor<sup>(10+)</sup> | ResourceColor | false | false | 开启状态内部圆饼颜色。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Radio(options: RadioOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | RadioOptions | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| checked |  boolean |  |  
| radioStyle<sup>10+</sup> | null |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (isChecked: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct RadioExample {  
  build() {  
    Flex({ direction: FlexDirection.Row, justifyContent: FlexAlign.Center, alignItems: ItemAlign.Center }) {  
      Column() {  
        Text('Radio1')  
        Radio({ value: 'Radio1', group: 'radioGroup' }).checked(true)  
          .radioStyle({  
            checkedBackgroundColor: Color.Pink  
          })  
          .height(50)  
          .width(50)  
          .onChange((isChecked: boolean) => {  
            console.log('Radio1 status is ' + isChecked)  
          })  
      }  
      Column() {  
        Text('Radio2')  
        Radio({ value: 'Radio2', group: 'radioGroup' }).checked(false)  
          .radioStyle({  
            checkedBackgroundColor: Color.Pink  
          })  
          .height(50)  
          .width(50)  
          .onChange((isChecked: boolean) => {  
            console.log('Radio2 status is ' + isChecked)  
          })  
      }  
      Column() {  
        Text('Radio3')  
        Radio({ value: 'Radio3', group: 'radioGroup' }).checked(false)  
          .radioStyle({  
            checkedBackgroundColor: Color.Pink  
          })  
          .height(50)  
          .width(50)  
          .onChange((isChecked: boolean) => {  
            console.log('Radio3 status is ' + isChecked)  
          })  
      }  
    }.padding({ top: 30 })  
  }  
}  
    
```    
  
![radio](figures/radio.gif)  
