# grid_row    
栅格布局可以为布局提供规律性的结构，解决多尺寸多设备的动态布局问题，保证不同设备上各个模块的布局一致性。栅格容器组件，仅可以和栅格子组件([GridCol](ts-container-gridcol.md))在栅格布局场景中使用。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## GridRowSizeOption    
栅格在不同宽度设备类型下，gutter的大小。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| xs | Length | false | false | 在最小宽度类型设备上，栅格子组件的间距。<br/> |  
| sm | Length | false | false | 在小宽度类型设备上，栅格子组件的间距。<br/> |  
| md | Length | false | false | 在中等宽度类型设备上，栅格子组件的间距。<br/> |  
| lg | Length | false | false | 在大宽度类型设备上，栅格子组件的间距。<br/> |  
| xl | Length | false | false | 在特大宽度类型设备上，栅格子组件的间距。<br/> |  
| xxl | Length | false | false | 在超大宽度类型设备上，栅格子组件的间距。<br/> |  
    
## GridRowColumnOption    
栅格在不同宽度设备类型下，栅格列数。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| xs | number | false | false | 在最小宽度类型设备上，栅格容器组件的栅格列数。<br/> |  
| sm | number | false | false | 在小宽度类型设备上，栅格容器组件的栅格列数。<br/> |  
| md | number | false | false | 在中等宽度类型设备上，栅格容器组件的栅格列数。<br/> |  
| lg | number | false | false | 在大宽度类型设备上，栅格容器组件的栅格列数。<br/> |  
| xl | number | false | false | 在特大宽度类型设备上，栅格容器组件的栅格列数。<br/> |  
| xxl | number | false | false | 在超大宽度类型设备上，栅格容器组件的栅格列数。<br/> |  
    
## GutterOption    
栅格布局间距类型，用于描述栅格子组件不同方向的间距。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| x | Length \| GridRowSizeOption | false | false | 栅格子组件水平方向间距。<br/> |  
| y | Length \| GridRowSizeOption | false | false | 栅格子组件竖直方向间距。<br/> |  
    
## BreakpointsReference    
从API version 9开始，该接口支持在ArkTS卡片中使用。  
    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| WindowSize | 0 | 以窗口为参照。<br/> |  
| ComponentSize | 1 | 以容器为参照。 |  
    
## GridRowDirection    
从API version 9开始，该接口支持在ArkTS卡片中使用。  
    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Row | 0 | 栅格元素按照行方向排列。 |  
| RowReverse | 1 | 栅格元素按照逆序行方向排列。 |  
    
## BreakPoints    
设置栅格容器组件的断点。从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value | Array<string> | false | false | 设置断点位置的单调递增数组。<br/>默认值：["320vp", "600vp", "840vp"]<br/> |  
| reference | BreakpointsReference | false | false | 断点切换参照物。<br/>默认值：BreakpointsReference.WindowSize<br/> |  
    
## GridRowOptions  
 **卡片能力:**     
从API version 9开始，该接口支持在ArkTS卡片中使用。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| gutter | Length \| GutterOption | false | false | 栅格布局间距。<br/> |  
| columns | number \| GridRowColumnOption | false | false | 设置布局列数。<br/> |  
| breakpoints | BreakPoints | false | false | 设置断点值的断点数列以及基于窗口或容器尺寸的相应参照。<br/> |  
| direction | GridRowDirection | false | false | 栅格布局排列方向。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- GridRow(option?: GridRowOptions)    
起始版本： 9    
**卡片能力：**  从API version 9 开始，该接口支持在ArkTS卡片中使用    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | GridRowOptions | false |  |  
    
## 属性  
    
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| alignItems<sup>10+</sup> |  ItemAlign |     
 **卡片能力：** 从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
    
### onBreakpointChange<sup>(deprecated)</sup>    
onBreakpointChange(callback: (breakpoints: string) => void)    
 **卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
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
