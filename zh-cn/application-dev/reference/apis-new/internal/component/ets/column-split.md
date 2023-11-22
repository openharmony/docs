# column_split    
将子组件纵向布局，并在每个子组件之间插入一根横向的分割线。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- ColumnSplit()    
起始版本： 7    
## ColumnSplitDividerStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| startMargin<sup>(10+)</sup> | Dimension | false | false | 分割线与其上方子组件的距离。 |  
| endMargin<sup>(10+)</sup> | Dimension | false | false | 分割线与其下方子组件的距离。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| resizeable |  boolean |  |  
| divider<sup>10+</sup> |  ColumnSplitDividerStyle \| null |  |  
    
 **示例代码：**   
```js    
// xxx.ets  
@Entry  
@Component  
struct ColumnSplitExample {  
  build() {  
    Column(){  
      Text('The secant line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      ColumnSplit() {  
        Text('1').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)  
        Text('2').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)  
        Text('3').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)  
        Text('4').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)  
        Text('5').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)  
      }  
      .borderWidth(1)  
      .resizeable(true) // 可拖动  
      .width('90%').height('60%')  
    }.width('100%')  
  }  
}  
    
```    
  
![zh-cn_image_0000001219982708](figures/zh-cn_image_0000001219982708.gif)  
