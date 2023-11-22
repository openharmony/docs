# loading_progress    
用于显示加载动效的组件。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## LoadingProgressStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Default | 0 |  |  
| Circular | 1 |  |  
| Orbital | 2 |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- LoadingProgress()    
起始版本： 8    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| color |  ResourceColor |  |  
| enableLoading<sup>10+</sup> |  boolean |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct LoadingProgressExample {  
  build() {  
    Column({ space: 5 }) {  
      Text('Orbital LoadingProgress ').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      LoadingProgress()  
        .color(Color.Blue)  
        .layoutWeight(1)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![LoadingProgress](figures/LoadingProgress.gif)  
