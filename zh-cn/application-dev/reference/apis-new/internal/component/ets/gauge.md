# gauge    
数据量规图表组件，用于将数据展示为环形图表。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Gauge(options: { value: number; min?: number; max?: number })    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | number | true |  |  
| min | number | false |  |  
| max | number | false |  |  
    
## GaugeShadowOptions<sup>(11+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## GaugeIndicatorOptions<sup>(11+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| icon<sup>(11+)</sup> | ResourceStr | false | false |  |  
| space<sup>(11+)</sup> | Dimension | false | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| value |  number |  |  
| startAngle | null |  |  
| endAngle | null |  |  
| colors | null |  |  
| strokeWidth | null |  |  
| description<sup>11+</sup> |  CustomBuilder |  |  
| trackShadow<sup>11+</sup> |  GaugeShadowOptions |  |  
| indicator<sup>11+</sup> |  GaugeIndicatorOptions |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct GaugeExample {  
  build() {  
    Column({ space: 20 }) {  
      // 使用默认的min和max为0-100，角度范围默认0-360，value值设置  
      // 参数中设置当前值为75  
      Gauge({ value: 75 })  
        .width(200).height(200)  
        .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1]])  
        
      // 参数设置当前值为75，属性设置值为25，属性设置优先级高  
      Gauge({ value: 75 })  
        .value(25) // 属性和参数都设置时以属性为准  
        .width(200).height(200)  
        .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1]])  
        
      // 210--150度环形图表  
      Gauge({ value: 30, min: 0, max: 100 })  
        .startAngle(210)  
        .endAngle(150)  
        .colors([[0x317AF7, 0.1], [0x5BA854, 0.2], [0xE08C3A, 0.3], [0x9C554B, 0.4]])  
        .strokeWidth(20)  
        .width(200)  
        .height(200)  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
![gauge](figures/gauge-image.png)  
