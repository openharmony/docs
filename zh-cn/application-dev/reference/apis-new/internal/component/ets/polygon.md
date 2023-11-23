# polygon    
多边形绘制组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Polygon(value?: { width?: string | number; height?: string | number })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width | string \| number | false | 宽度。<br/>**说明：**<br/>异常值按照默认值处理。 |  
| height | string \| number | false | 高度。<br/>**说明：**<br/>异常值按照默认值处理。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| points |  Array<any> |  |  
| points<sup>9+</sup> |  Array<any> |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| points<sup>10+</sup> |  Array<any> |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct PolygonExample {  
  build() {  
    Column({ space: 10 }) {  
      // 在 100 * 100 的矩形框中绘制一个三角形，起点(0, 0)，经过(50, 100)，终点(100, 0)  
      Polygon({ width: 100, height: 100 })  
        .points([[0, 0], [50, 100], [100, 0]])  
        .fill(Color.Green)  
      // 在 100 * 100 的矩形框中绘制一个四边形，起点(0, 0)，经过(0, 100)和(100, 100)，终点(100, 0)  
      Polygon().width(100).height(100)  
        .points([[0, 0], [0, 100], [100, 100], [100, 0]])  
        .fillOpacity(0)  
        .strokeWidth(5)  
        .stroke(Color.Blue)  
      // 在 100 * 100 的矩形框中绘制一个五边形，起点(50, 0)，依次经过(0, 50)、(20, 100)和(80, 100)，终点(100, 50)  
      Polygon().width(100).height(100)  
        .points([[50, 0], [0, 50], [20, 100], [80, 100], [100, 50]])  
        .fill(Color.Red)  
        .fillOpacity(0.6)  
    }.width('100%').margin({ top: 10 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001174582856](figures/zh-cn_image_0000001174582856.png)  
