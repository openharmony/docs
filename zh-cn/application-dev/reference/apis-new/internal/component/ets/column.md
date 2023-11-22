# column    
沿垂直方向布局的容器。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Column(value?: { space?: string | number })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| space | string \| number | false |  纵向布局元素垂直方向间距。<br/>从API version 9开始，space为负数或者justifyContent设置为FlexAlign.SpaceBetween、FlexAlign.SpaceAround、FlexAlign.SpaceEvenly时不生效。<br/>默认值：0<br/>**说明：**<br/>可选值为大于等于0的数字，或者可以转换为数字的字符串。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| alignItems |  HorizontalAlign |  |  
| justifyContent<sup>8+</sup> |  FlexAlign |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct ColumnExample {  
  build() {  
    Column({ space: 5 }) {  
      // 设置子元素垂直方向间距为5  
      Text('space').width('90%')  
      Column({ space: 5 }) {  
        Column().width('100%').height(30).backgroundColor(0xAFEEEE)  
        Column().width('100%').height(30).backgroundColor(0x00FFFF)  
      }.width('90%').height(100).border({ width: 1 })  
  
      // 设置子元素水平方向对齐方式  
      Text('alignItems(Start)').width('90%')  
      Column() {  
        Column().width('50%').height(30).backgroundColor(0xAFEEEE)  
        Column().width('50%').height(30).backgroundColor(0x00FFFF)  
      }.alignItems(HorizontalAlign.Start).width('90%').border({ width: 1 })  
  
      Text('alignItems(End)').width('90%')  
      Column() {  
        Column().width('50%').height(30).backgroundColor(0xAFEEEE)  
        Column().width('50%').height(30).backgroundColor(0x00FFFF)  
      }.alignItems(HorizontalAlign.End).width('90%').border({ width: 1 })  
  
      Text('alignItems(Center)').width('90%')  
      Column() {  
        Column().width('50%').height(30).backgroundColor(0xAFEEEE)  
        Column().width('50%').height(30).backgroundColor(0x00FFFF)  
      }.alignItems(HorizontalAlign.Center).width('90%').border({ width: 1 })  
  
      // 设置子元素垂直方向的对齐方式  
      Text('justifyContent(Center)').width('90%')  
      Column() {  
        Column().width('90%').height(30).backgroundColor(0xAFEEEE)  
        Column().width('90%').height(30).backgroundColor(0x00FFFF)  
      }.height(100).border({ width: 1 }).justifyContent(FlexAlign.Center)  
  
      Text('justifyContent(End)').width('90%')  
      Column() {  
        Column().width('90%').height(30).backgroundColor(0xAFEEEE)  
        Column().width('90%').height(30).backgroundColor(0x00FFFF)  
      }.height(100).border({ width: 1 }).justifyContent(FlexAlign.End)  
    }.width('100%').padding({ top: 5 })  
  }  
}  
    
```    
  
![column](figures/column.png)  
