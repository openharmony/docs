# scroll_bar    
滚动条组件ScrollBar，用于配合可滚动组件使用，如List、Grid、Scroll。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ScrollBarDirection    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Vertical | 0 | 纵向滚动条。<br/> |  
| Horizontal | 1 | 横向滚动条。<br/> |  
    
## ScrollBarOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scroller | Scroller | false | true | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/> |  
| direction | ScrollBarDirection | false | false | 滚动条的方向，控制可滚动组件对应方向的滚动。<br/>默认值：ScrollBarDirection.Vertical<br/> |  
| state | BarState | false | false | 滚动条状态。<br/>默认值：BarState.Auto<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- ScrollBar(value: ScrollBarOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | ScrollBarOptions | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ScrollBarExample {  
  private scroller: Scroller = new Scroller()  
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]  
  
  build() {  
    Column() {  
      Stack({ alignContent: Alignment.End }) {  
        Scroll(this.scroller) {  
          Flex({ direction: FlexDirection.Column }) {  
            ForEach(this.arr, (item: number) => {  
              Row() {  
                Text(item.toString())  
                  .width('80%')  
                  .height(60)  
                  .backgroundColor('#3366CC')  
                  .borderRadius(15)  
                  .fontSize(16)  
                  .textAlign(TextAlign.Center)  
                  .margin({ top: 5 })  
              }  
            }, (item:number) => item.toString())  
          }.margin({ right: 15 })  
        }  
        .width('90%')  
        .scrollBar(BarState.Off)  
        .scrollable(ScrollDirection.Vertical)  
        ScrollBar({ scroller: this.scroller, direction: ScrollBarDirection.Vertical,state: BarState.Auto }) {  
          Text()  
            .width(20)  
            .height(100)  
            .borderRadius(10)  
            .backgroundColor('#C0C0C0')  
        }.width(20).backgroundColor('#ededed')  
      }  
    }  
  }  
}  
    
```    
  
![zh-cn_image_0000001232775585](figures/zh-cn_image_0000001232775585.gif)  
