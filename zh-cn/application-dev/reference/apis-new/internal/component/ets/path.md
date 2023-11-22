# path    
路径绘制组件，根据绘制路径生成封闭的自定义形状。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Path(value?: { width?: number | string; height?: number | string; commands?: string })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| width | number \| string | false | 路径所在矩形的宽度<br/>默认值：0<br/>**说明：**<br/>异常值按照默认值处理。 |  
| height | number \| string | false | 路径所在矩形的高度<br/>默认值：0<br/>**说明：**<br/>异常值按照默认值处理。 |  
| commands | string | false | 路径绘制的命令字符串<br/>默认值：''<br/>**说明：**<br/>异常值按照默认值处理。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| commands |  string |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct PathExample {  
  build() {  
    Column({ space: 10 }) {  
      Text('Straight line')  
        .fontSize(11)  
        .fontColor(0xCCCCCC)  
        .width('90%')  
      // 绘制一条长600px，宽3vp的直线  
      Path()  
        .width('600px')  
        .height('10px')  
        .commands('M0 0 L600 0')  
        .stroke(Color.Black)  
        .strokeWidth(3)  
  
      Text('Straight line graph')  
        .fontSize(11)  
        .fontColor(0xCCCCCC)  
        .width('90%')  
      // 绘制直线图形  
      Flex({ justifyContent: FlexAlign.SpaceBetween }) {  
        Path()  
          .width('210px')  
          .height('310px')  
          .commands('M100 0 L200 240 L0 240 Z')  
          .fillOpacity(0)  
          .stroke(Color.Black)  
          .strokeWidth(3)  
        Path()  
          .width('210px')  
          .height('310px')  
          .commands('M0 0 H200 V200 H0 Z')  
          .fillOpacity(0)  
          .stroke(Color.Black)  
          .strokeWidth(3)  
        Path()  
          .width('210px')  
          .height('310px')  
          .commands('M100 0 L0 100 L50 200 L150 200 L200 100 Z')  
          .fillOpacity(0)  
          .stroke(Color.Black)  
          .strokeWidth(3)  
      }.width('95%')  
  
      Text('Curve graphics').fontSize(11).fontColor(0xCCCCCC).width('90%')  
      // 绘制弧线图形  
      Flex({ justifyContent: FlexAlign.SpaceBetween }) {  
        Path()  
          .width('250px')  
          .height('310px')  
          .commands("M0 300 S100 0 240 300 Z")  
          .fillOpacity(0)  
          .stroke(Color.Black)  
          .strokeWidth(3)  
        Path()  
          .width('210px')  
          .height('310px')  
          .commands('M0 150 C0 100 140 0 200 150 L100 300 Z')  
          .fillOpacity(0)  
          .stroke(Color.Black)  
          .strokeWidth(3)  
        Path()  
          .width('210px')  
          .height('310px')  
          .commands('M0 100 A30 20 20 0 0 200 100 Z')  
          .fillOpacity(0)  
          .stroke(Color.Black)  
          .strokeWidth(3)  
      }.width('95%')  
    }.width('100%')  
    .margin({ top: 5 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001219744193](figures/zh-cn_image_0000001219744193.png)  
