# rect    
矩形绘制组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
<p>width：宽度。&lt;br/&gt;<br/>height：高度。&lt;br/&gt;<br/>radius：圆角半径，支持分别设置四个角的圆角度数。&lt;br/&gt;<br/>该属性和radiusWidth/radiusHeight属性效果类似，在组合使用时优先于radiusWidth/radiusHeight生效&lt;br/&gt;<br/>radiusWidth：圆角宽度。&lt;br/&gt;<br/>radiusHeight：圆角高度。&lt;br/&gt;<br/></p><p>**说明：**&nbsp;异常值按照默认值处理。</p>  
    
 **调用形式**     
    
- Rect(     value?:       {         width?: number | string;         height?: number | string;         radius?: number | string | Array<any>;       }       | {         width?: number | string;         height?: number | string;         radiusWidth?: number | string;         radiusHeight?: number | string;       },   )    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | string | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| radiusWidth |  number \| string |  |  
| radiusHeight |  number \| string |  |  
| radius |  number \| string \| Array<any> |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct RectExample {  
  build() {  
    Column({ space: 10 }) {  
      Text('normal').fontSize(11).fontColor(0xCCCCCC).width('90%')  
      // 绘制90% * 50的矩形  
      Column({ space: 5 }) {  
        Text('normal').fontSize(9).fontColor(0xCCCCCC).width('90%')  
        // 绘制90% * 50矩形  
        Rect({ width: '90%', height: 50 })  
          .fill(Color.Pink)  
        // 绘制90% * 50的矩形框  
        Rect()  
          .width('90%')  
          .height(50)  
          .fillOpacity(0)  
          .stroke(Color.Red)  
          .strokeWidth(3)  
  
        Text('with rounded corners').fontSize(11).fontColor(0xCCCCCC).width('90%')  
        // 绘制90% * 80的矩形, 圆角宽高分别为40、20  
        Rect({ width: '90%', height: 80 })  
          .radiusHeight(20)  
          .radiusWidth(40)  
          .fill(Color.Pink)  
        // 绘制90% * 80的矩形, 圆角宽高为20  
        Rect({ width: '90%', height: 80 })  
          .radius(20)  
          .fill(Color.Pink)  
          .stroke(Color.Transparent)  
      }.width('100%').margin({ top: 10 })  
      // 绘制90% * 50矩形, 左上圆角宽高40,右上圆角宽高20,右下圆角宽高40,左下圆角宽高20  
      Rect({ width: '90%', height: 80 })  
        .radius([[40, 40], [20, 20], [40, 40], [20, 20]])  
        .fill(Color.Pink)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001174264386](figures/zh-cn_image_0000001174264386.png)  
