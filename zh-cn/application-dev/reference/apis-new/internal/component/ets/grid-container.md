# grid_container    
纵向排布栅格布局容器，仅在栅格布局场景中使用。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SizeType<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用grid_col/[GridColColumnOption]替代。    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Auto<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>根据设备类型进行选择。 |  
| XS<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>最小宽度类型设备。 |  
| SM<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>小宽度类型设备。 |  
| MD<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>中等宽度类型设备。 |  
| LG<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。<br>大宽度类型设备。 |  
    
## GridContainerOptions<sup>(deprecated)</sup>    
从API version 7 开始支持，从API version 9 开始废弃。建议使用grid_col/[GridColOptions]替代。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| columns<sup>(deprecated)</sup> | number \| "auto" | false | false | 从API version 7 开始支持，从API version 9 开始废弃。 |  
| sizeType<sup>(deprecated)</sup> | SizeType | false | false | 从API version 7 开始支持，从API version 9 开始废弃。 |  
| gutter<sup>(deprecated)</sup> | number \| string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。 |  
| margin<sup>(deprecated)</sup> | number \| string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- GridContainer(value?: GridContainerOptions)    
起始版本： 7    
废弃版本： 9    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value<sup>(deprecated)</sup> | GridContainerOptions | false |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct GridContainerExample {  
  @State sizeType: SizeType = SizeType.XS  
  
  build() {  
    Column({ space: 5 }) {  
      GridContainer({ columns: 12, sizeType: this.sizeType, gutter: 10, margin: 20 }) {  
        Row() {  
          Text('1')  
            .useSizeType({  
              xs: { span: 6, offset: 0 },  
              sm: { span: 2, offset: 0 },  
              md: { span: 2, offset: 0 },  
              lg: { span: 2, offset: 0 }  
            })  
            .height(50).backgroundColor(0x4682B4).textAlign(TextAlign.Center)  
          Text('2')  
            .useSizeType({  
              xs: { span: 2, offset: 6 },  
              sm: { span: 6, offset: 2 },  
              md: { span: 2, offset: 2 },  
              lg: { span: 2, offset: 2 }  
            })  
            .height(50).backgroundColor(0x00BFFF).textAlign(TextAlign.Center)  
          Text('3')  
            .useSizeType({  
              xs: { span: 2, offset: 8 },  
              sm: { span: 2, offset: 8 },  
              md: { span: 6, offset: 4 },  
              lg: { span: 2, offset: 4 }  
            })  
            .height(50).backgroundColor(0x4682B4).textAlign(TextAlign.Center)  
          Text('4')  
            .useSizeType({  
              xs: { span: 2, offset: 10 },  
              sm: { span: 2, offset: 10 },  
              md: { span: 2, offset: 10 },  
              lg: { span: 6, offset: 6 }  
            })  
            .height(50).backgroundColor(0x00BFFF).textAlign(TextAlign.Center)  
        }  
      }.width('90%')  
  
      Text('Click Simulate to change the device width').fontSize(9).width('90%').fontColor(0xCCCCCC)  
      Row() {  
        Button('XS')  
          .onClick(() => {  
            this.sizeType = SizeType.XS  
          }).backgroundColor(0x317aff)  
        Button('SM')  
          .onClick(() => {  
            this.sizeType = SizeType.SM  
          }).backgroundColor(0x317aff)  
        Button('MD')  
          .onClick(() => {  
            this.sizeType = SizeType.MD  
          }).backgroundColor(0x317aff)  
        Button('LG')  
          .onClick(() => {  
            this.sizeType = SizeType.LG  
          }).backgroundColor(0x317aff)  
      }  
    }.width('100%').margin({ top: 5 })  
  }  
}  
    
```    
  
