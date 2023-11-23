# ellipse    
椭圆绘制组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Ellipse(value?: { width?: string | number; height?: string | number })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width | string \| number | false |  |  
| height | string \| number | false |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct EllipseExample {  
  build() {  
    Column({ space: 10 }) {  
      // 绘制一个 150 * 80 的椭圆  
      Ellipse({ width: 150, height: 80 })  
      // 绘制一个 150 * 100 、线条为蓝色的椭圆环  
      Ellipse()  
        .width(150)  
        .height(100)  
        .fillOpacity(0)  
        .stroke(Color.Blue)  
        .strokeWidth(3)  
    }.width('100%')  
  }  
}  
    
```    
  
