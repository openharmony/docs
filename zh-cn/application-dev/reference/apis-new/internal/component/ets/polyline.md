# polyline    
折线绘制组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Polyline(value?: { width?: string | number; height?: string | number })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width | string \| number | false | 多边形的顶点坐标列表。<br/>**说明：**<br/>异常值按照默认值处理。 |  
| height | string \| number | false | 高度。<br/>**说明：** <br/>异常值按照默认值处理。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| points |  Array<any> |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct PolylineExample {  
  build() {  
    Column({ space: 10 }) {  
      // 在 100 * 100 的矩形框中绘制一段折线，起点(0, 0)，经过(20,60)，到达终点(100, 100)  
      Polyline({ width: 100, height: 100 })  
        .points([[0, 0], [20, 60], [100, 100]])  
        .fillOpacity(0)  
        .stroke(Color.Blue)  
        .strokeWidth(3)  
      // 在 100 * 100 的矩形框中绘制一段折线，起点(20, 0)，经过(0,100)，到达终点(100, 90)  
      Polyline()  
        .width(100)  
        .height(100)  
        .fillOpacity(0)  
        .stroke(Color.Red)  
        .strokeWidth(8)  
        .points([[20, 0], [0, 100], [100, 90]])  
          // 设置折线拐角处为圆弧  
        .strokeLineJoin(LineJoinStyle.Round)  
          // 设置折线两端为半圆  
        .strokeLineCap(LineCapStyle.Round)  
    }.width('100%')  
  }  
}  
    
```    
  
![zh-cn_image_0000001219744185](figures/zh-cn_image_0000001219744185.png)  
