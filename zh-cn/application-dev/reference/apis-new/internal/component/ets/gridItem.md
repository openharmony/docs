# gridItem    
网格容器中单项内容容器。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## GridItemStyle<sup>(11+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 无样式。 |  
| PLAIN | 1 | 显示Hover、Press态样式。 |  
    
## GridItemOptions<sup>(11+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| style<sup>(11+)</sup> | GridItemStyle | false | false | 设置GridItem样式。<br/>默认值: GridItemStyle.NONE<br/>设置为GridItemStyle.NONE时无样式。<br/>设置为GridItemStyle.PLAIN时，显示Hover、Press态样式。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- GridItem(value?: GridItemOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(7+)</sup> | GridItemOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| rowStart |  number |  |  
| rowEnd |  number |  |  
| columnStart |  number |  |  
| columnEnd |  number |  |  
| forceRebuild<sup>(deprecated)</sup> |  boolean |  |  
| selectable<sup>8+</sup> |  boolean |  |  
| selected<sup>10+</sup> |  boolean |  |  
    
### onSelect<sup>(deprecated)</sup>    
onSelect(event: (isSelected: boolean) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(8+)</sup> | (isSelected: boolean) => void | true |  |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct GridItemExample {  
  @State numbers: string[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15"]  
  
  build() {  
    Column() {  
      Grid() {  
        GridItem() {  
          Text('4')  
            .fontSize(16)  
            .backgroundColor(0xFAEEE0)  
            .width('100%')  
            .height('100%')  
            .textAlign(TextAlign.Center)  
        }.rowStart(1).rowEnd(2).columnStart(1).columnEnd(2) // 同时设置合理的行列号  
  
        ForEach(this.numbers, (item: string) => {  
          GridItem() {  
            Text(item)  
              .fontSize(16)  
              .backgroundColor(0xF9CF93)  
              .width('100%')  
              .height('100%')  
              .textAlign(TextAlign.Center)  
          }  
        }, (item: string) => item)  
  
        GridItem() {  
          Text('5')  
            .fontSize(16)  
            .backgroundColor(0xDBD0C0)  
            .width('100%')  
            .height('100%')  
            .textAlign(TextAlign.Center)  
        }.columnStart(1).columnEnd(4) // 只设置列号，不会从第1列开始布局  
      }  
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')  
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')  
      .width('90%').height(300)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![zh-cn_image_0000001174582870](figures/zh-cn_image_0000001174582870.gif)  
    
 **示例代码2：**   
使用GridItemOptions  
```ts    
// xxx.ets  
@Entry  
@Component  
struct GridItemExample {  
  @State Number: String[] = ['0', '1', '2']  
  
  build() {  
    Column({ space: 5 }) {  
      Grid() {  
        ForEach(this.Number, (day: string) => {  
          ForEach(this.Number, (day: string) => {  
            GridItem({style:GridItemStyle.NONE}) {  
              Text(day)  
                .fontSize(16)  
                .width('100%')  
                .height('100%')  
                .textAlign(TextAlign.Center)  
                .focusable(true)  
            }  
            .backgroundColor(0xF9CF93)  
          }, (day: string) => day)  
        }, (day: string) => day)  
      }  
      .columnsTemplate('1fr 1fr 1fr')  
      .rowsTemplate('1fr 1fr')  
      .columnsGap(4)  
      .rowsGap(4)  
      .width('60%')  
      .backgroundColor(0xFAEEE0)  
      .height(150)  
      .padding('4vp')  
  
      Grid() {  
        ForEach(this.Number, (day: string) => {  
          ForEach(this.Number, (day: string) => {  
            GridItem({style:GridItemStyle.PLAIN}) {  
              Text(day)  
                .fontSize(16)  
                .width('100%')  
                .height('100%')  
                .textAlign(TextAlign.Center)  
                .focusable(true)  
            }  
            .backgroundColor(0xF9CF93)  
          }, (day: string) => day)  
        }, (day: string) => day)  
      }  
      .columnsTemplate('1fr 1fr 1fr')  
      .rowsTemplate('1fr 1fr')  
      .columnsGap(4)  
      .rowsGap(4)  
      .width('60%')  
      .backgroundColor(0xFAEEE0)  
      .height(150)  
      .padding('4vp')  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![zh-ch_image_griditem_griditemoptions](figures/zh-ch_image_griditem_griditemoptions.png)  
