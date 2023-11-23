# divider    
提供分隔器组件，分隔不同内容块/内容元素。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Divider()    
起始版本： 7    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| vertical |  boolean |  |  
| color |  ResourceColor |  |  
| strokeWidth |  number \| string |  |  
| lineCap |  LineCapStyle |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct DividerExample {  
  build() {  
    Column() {  
      // 使用横向分割线场景  
      Text('Horizontal divider').fontSize(9).fontColor(0xCCCCCC)  
      List() {  
        ForEach([1, 2, 3], (item: number) => {  
          ListItem() {  
            Text('list' + item).width('100%').fontSize(14).fontColor('#182431').textAlign(TextAlign.Start)  
          }.width(244).height(48)  
        }, (item: number) => item.toString())  
      }.padding({ left: 24, bottom: 8 })  
  
      Divider().strokeWidth(8).color('#F1F3F5')  
      List() {  
        ForEach([4, 5], (item: number) => {  
          ListItem() {  
            Text('list' + item).width('100%').fontSize(14).fontColor('#182431').textAlign(TextAlign.Start)  
          }.width(244).height(48)  
        }, (item: number) => item.toString())  
      }.padding({ left: 24, top: 8 })  
  
      // 使用纵向分割线场景  
      Text('Vertical divider').fontSize(9).fontColor(0xCCCCCC)  
      Column() {  
        Column() {  
          Row().width(288).height(64).backgroundColor('#30C9F0').opacity(0.3)  
          Row() {  
            Button('Button')  
              .width(136)  
              .height(22)  
              .fontSize(16)  
              .fontColor('#007DFF')  
              .fontWeight(500)  
              .backgroundColor(Color.Transparent)  
            Divider().vertical(true).height(22).color('#182431').opacity(0.6).margin({ left: 8, right: 8 })  
            Button('Button')  
              .width(136)  
              .height(22)  
              .fontSize(16)  
              .fontColor('#007DFF')  
              .fontWeight(500)  
              .backgroundColor(Color.Transparent)  
          }.margin({ top: 17 })  
        }  
        .width(336)  
        .height(152)  
        .backgroundColor('#FFFFFF')  
        .borderRadius(24)  
        .padding(24)  
      }  
      .width('100%')  
      .height(168)  
      .backgroundColor('#F1F3F5')  
      .justifyContent(FlexAlign.Center)  
      .margin({ top: 8 })  
    }.width('100%').padding({ top: 24 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001174422926](figures/zh-cn_image_0000001174422926.png)  
