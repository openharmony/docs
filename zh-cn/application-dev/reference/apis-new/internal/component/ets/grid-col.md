# grid_col    
栅格子组件，必须作为栅格容器组件([GridRow](ts-container-gridrow.md))的子组件使用。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## GridColColumnOption    
从API version 9开始，该接口支持在ArkTS卡片中使用。  
  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| xs | number | false | false |  |  
| sm | number | false | false |  |  
| md | number | false | false |  |  
| lg | number | false | false |  |  
| xl | number | false | false |  |  
| xxl | number | false | false |  |  
    
## GridColOptions  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| span | number \| GridColColumnOption | false | false |  |  
| offset | number \| GridColColumnOption | false | false |  |  
| order | number \| GridColColumnOption | false | false |  |  
    
## 接口  
  
  
    
 **调用形式**     
    
- GridCol(option?: GridColOptions)    
起始版本： 9    
**卡片能力：**  从API version 9 开始，该接口支持在ArkTS卡片中使用    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | GridColOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| span |  number \| GridColColumnOption |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| span<sup>10+</sup> |  number \| GridColColumnOption |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
| gridColOffset |  number \| GridColColumnOption |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| gridColOffset<sup>10+</sup> |  number \| GridColColumnOption |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
| order |  number \| GridColColumnOption |     
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |  
| order<sup>10+</sup> |  number \| GridColColumnOption |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct GridRowExample {  
  @State bgColors: Color[] = [Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Pink, Color.Grey, Color.Blue, Color.Brown]  
  @State currentBp: string = 'unknown'  
  
  build() {  
    Column() {  
      GridRow({  
        columns: 5,  
        gutter: { x: 5, y: 10 },  
        breakpoints: { value: ["400vp", "600vp", "800vp"],  
          reference: BreakpointsReference.WindowSize },  
        direction: GridRowDirection.Row  
      }) {  
        ForEach(this.bgColors, (color: Color) => {  
          GridCol({ span: { xs: 1, sm: 2, md: 3, lg: 4 }, offset: 0, order: 0 }) {  
            Row().width("100%").height("20vp")  
          }.borderColor(color).borderWidth(2)  
        })  
      }.width("100%").height("100%")  
      .onBreakpointChange((breakpoint) => {  
        this.currentBp = breakpoint  
      })  
    }.width('80%').margin({ left: 10, top: 5, bottom: 5 }).height(200)  
    .border({ color: '#880606', width: 2 })  
  }  
}  
    
```    
  
![figures/gridrow.png](figures/gridrow.png)  
