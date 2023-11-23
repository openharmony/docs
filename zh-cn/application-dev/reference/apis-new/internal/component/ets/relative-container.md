# relative_container    
相对布局组件，用于复杂场景中元素对齐的布局。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- RelativeContainer()    
起始版本： 9    
 **示例代码：**   
```ts    
@Entry  
@Component  
struct Index {  
  build() {  
    Row() {  
  
      RelativeContainer() {  
        Row().width(100).height(100)  
          .backgroundColor("#FF3333")  
          .alignRules({  
            top: {anchor: "__container__", align: VerticalAlign.Top},  
            left: {anchor: "__container__", align: HorizontalAlign.Start}  
          })  
          .id("row1")  
  
        Row().width(100).height(100)  
          .backgroundColor("#FFCC00")  
          .alignRules({  
            top: {anchor: "__container__", align: VerticalAlign.Top},  
            right: {anchor: "__container__", align: HorizontalAlign.End}  
          })  
          .id("row2")  
  
        Row().height(100)  
          .backgroundColor("#FF6633")  
          .alignRules({  
            top: {anchor: "row1", align: VerticalAlign.Bottom},  
            left: {anchor: "row1", align: HorizontalAlign.End},  
            right: {anchor: "row2", align: HorizontalAlign.Start}  
          })  
          .id("row3")  
  
        Row()  
          .backgroundColor("#FF9966")  
          .alignRules({  
            top: {anchor: "row3", align: VerticalAlign.Bottom},  
            bottom: {anchor: "__container__", align: VerticalAlign.Bottom},  
            left: {anchor: "__container__", align: HorizontalAlign.Start},  
            right: {anchor: "row1", align: HorizontalAlign.End}  
          })  
          .id("row4")  
  
        Row()  
          .backgroundColor("#FF66FF")  
          .alignRules({  
            top: {anchor: "row3", align: VerticalAlign.Bottom},  
            bottom: {anchor: "__container__", align: VerticalAlign.Bottom},  
            left: {anchor: "row2", align: HorizontalAlign.Start},  
            right: {anchor: "__container__", align: HorizontalAlign.End}  
          })  
          .id("row5")  
      }  
      .width(300).height(300)  
      .margin({left: 50})  
      .border({width:2, color: "#6699FF"})  
    }  
    .height('100%')  
  }  
}  
    
```    
  
