# line    
直线绘制组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Line(value?: { width?: string | number; height?: string | number })    
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
| startPoint |  Array<any> |  |  
| endPoint |  Array<any> |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct LineExample {  
  build() {  
    Column({ space: 10 }) {  
      // 线条绘制的起止点坐标均是相对于Line组件本身绘制区域的坐标  
      Line()  
        .width(200)  
        .height(150)  
        .startPoint([0, 0])  
        .endPoint([50, 100])  
        .stroke(Color.Black)  
        .backgroundColor('#F5F5F5')  
      Line()  
        .width(200)  
        .height(150)  
        .startPoint([50, 50])  
        .endPoint([150, 150])  
        .strokeWidth(5)  
        .stroke(Color.Orange)  
        .strokeOpacity(0.5)  
        .backgroundColor('#F5F5F5')  
      // strokeDashOffset用于定义关联虚线strokeDashArray数组渲染时的偏移  
      Line()  
        .width(200)  
        .height(150)  
        .startPoint([0, 0])  
        .endPoint([100, 100])  
        .stroke(Color.Black)  
        .strokeWidth(3)  
        .strokeDashArray([10, 3])  
        .strokeDashOffset(5)  
        .backgroundColor('#F5F5F5')  
      // 当坐标点设置的值超出Line组件的宽高范围时，线条会画出组件绘制区域  
      Line()  
        .width(50)  
        .height(50)  
        .startPoint([0, 0])  
        .endPoint([100, 100])  
        .stroke(Color.Black)  
        .strokeWidth(3)  
        .strokeDashArray([10, 3])  
        .backgroundColor('#F5F5F5')  
    }  
  }  
}  
    
```    
  
![zh-cn_image_0000001219982725](figures/zh-cn_image_0000001219982725.png)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct LineExample1 {  
  build() {  
    Row({ space: 10 }) {  
      // 当LineCapStyle值为Butt时  
      Line()  
        .width(100)  
        .height(200)  
        .startPoint([50, 50])  
        .endPoint([50, 200])  
        .stroke(Color.Black)  
        .strokeWidth(20)  
        .strokeLineCap(LineCapStyle.Butt)  
        .backgroundColor('#F5F5F5').margin(10)  
      // 当LineCapStyle值为Round时  
      Line()  
        .width(100)  
        .height(200)  
        .startPoint([50, 50])  
        .endPoint([50, 200])  
        .stroke(Color.Black)  
        .strokeWidth(20)  
        .strokeLineCap(LineCapStyle.Round)  
        .backgroundColor('#F5F5F5')  
      // 当LineCapStyle值为Square时  
      Line()  
        .width(100)  
        .height(200)  
        .startPoint([50, 50])  
        .endPoint([50, 200])  
        .stroke(Color.Black)  
        .strokeWidth(20)  
        .strokeLineCap(LineCapStyle.Square)  
        .backgroundColor('#F5F5F5')  
    }  
  }  
}  
    
```    
  
![zh-cn_image1_0000001219982725](figures/zh-cn_image1_0000001219982725.png)  
    
 **示例代码3：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct LineExample {  
  build() {  
    Column() {  
      Line()  
        .width(300)  
        .height(30)  
        .startPoint([50, 30])  
        .endPoint([300, 30])  
        .stroke(Color.Black)  
        .strokeWidth(10)  
      // 设置strokeDashArray的数组间隔为 50  
      Line()  
        .width(300)  
        .height(30)  
        .startPoint([50, 20])  
        .endPoint([300, 20])  
        .stroke(Color.Black)  
        .strokeWidth(10)  
        .strokeDashArray([50])  
      // 设置strokeDashArray的数组间隔为 50, 10  
      Line()  
        .width(300)  
        .height(30)  
        .startPoint([50, 20])  
        .endPoint([300, 20])  
        .stroke(Color.Black)  
        .strokeWidth(10)  
        .strokeDashArray([50, 10])  
      // 设置strokeDashArray的数组间隔为 50, 10, 20  
      Line()  
        .width(300)  
        .height(30)  
        .startPoint([50, 20])  
        .endPoint([300, 20])  
        .stroke(Color.Black)  
        .strokeWidth(10)  
        .strokeDashArray([50, 10, 20])  
      // 设置strokeDashArray的数组间隔为 50, 10, 20, 30  
      Line()  
        .width(300)  
        .height(30)  
        .startPoint([50, 20])  
        .endPoint([300, 20])  
        .stroke(Color.Black)  
        .strokeWidth(10)  
        .strokeDashArray([50, 10, 20, 30])  
  
    }  
  }  
}  
    
```    
  
![zh-cn_image2_0000001219982725](figures/zh-cn_image2_0000001219982725.PNG)`  
