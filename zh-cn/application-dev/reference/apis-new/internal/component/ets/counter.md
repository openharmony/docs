# counter    
计数器组件，提供相应的增加或者减少的计数操作。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Counter()    
起始版本： 7    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| enableDec<sup>10+</sup> |  boolean |  |  
| enableInc<sup>10+</sup> |  boolean |  |  
    
### onInc<sup>(deprecated)</sup>    
onInc(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onDec<sup>(deprecated)</sup>    
onDec(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct CounterExample {  
  @State value: number = 0  
  
  build() {  
    Column() {  
      Counter() {  
        Text(this.value.toString())  
      }.margin(100)  
      .onInc(() => {  
        this.value++  
      })  
      .onDec(() => {  
        this.value--  
      })  
    }.width("100%")  
  }  
}  
    
```    
  
![zh-cn_image_0000001219982711](figures/zh-cn_image_0000001219982711.gif)  
