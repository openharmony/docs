# circle    
用于绘制圆形的组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## CircleOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| width | string \| number | false | false | 宽度。<br>默认值：0<br/>**说明：**<br/>异常值按照默认值处理。 |  
| height | string \| number | false | false | 高度。<br>默认值：0<br/>**说明：**<br/>异常值按照默认值处理 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Circle(value?: CircleOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | CircleOptions | false |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct CircleExample {  
  build() {  
    Column({ space: 10 }) {  
      // 绘制一个直径为150的圆  
      Circle({ width: 150, height: 150 })  
      // 绘制一个直径为150、线条为红色虚线的圆环（宽高设置不一致时以短边为直径）  
      Circle()  
        .width(150)  
        .height(200)  
        .fillOpacity(0)  
        .strokeWidth(3)  
        .stroke(Color.Red)  
        .strokeDashArray([1, 2])  
    }.width('100%')  
  }  
}  
    
```    
  
