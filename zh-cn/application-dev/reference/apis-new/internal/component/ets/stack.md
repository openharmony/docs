# stack    
堆叠容器，子组件按照顺序依次入栈，后一个子组件覆盖前一个子组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Stack(value?: { alignContent?: Alignment })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| alignContent | Alignment | false | 设置子组件在容器内的对齐方式。<br/>默认值：Alignment.Center<br/> |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| alignContent |  Alignment |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct StackExample {  
  build() {  
    Stack({ alignContent: Alignment.Bottom }) {  
      Text('First child, show in bottom').width('90%').height('100%').backgroundColor(0xd2cab3).align(Alignment.Top)  
      Text('Second child, show in top').width('70%').height('60%').backgroundColor(0xc1cbac).align(Alignment.Top)  
    }.width('100%').height(150).margin({ top: 5 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001219982699](figures/zh-cn_image_0000001219982699.PNG)  
