# blank    
空白填充组件，在容器主轴方向上，空白填充组件具有自动填充容器空余部分的能力。仅当父组件为Row/Column/Flex时生效。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Blank(min?: number | string)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| min | string | false | 空白填充组件在容器主轴上的最小大小。<br/>默认值：0<br/>**说明：** <br/>不支持设置百分比。负值使用默认值。当最小值大于容器可用空间时，使用最小值作为自身大小并超出容器。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| color |  ResourceColor |  |  
    
 **示例代码1：**   
Blank组件在横竖屏占满空余空间效果。  
```ts    
// xxx.ets  
@Entry  
@Component  
struct BlankExample {  
  build() {  
    Column() {  
      Row() {  
        Text('Bluetooth').fontSize(18)  
        Blank()  
        Toggle({ type: ToggleType.Switch }).margin({ top: 14, bottom: 14, left: 6, right: 6 })  
      }.width('100%').backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })  
    }.backgroundColor(0xEFEFEF).padding(20)  
  }  
}  
    
```    
  
竖屏状态  
  
![zh-cn_image_0000001219662649](figures/zh-cn_image_0000001219662649.gif)  
  
横屏状态  
  
![zh-cn_image_0000001174104388](figures/zh-cn_image_0000001174104388.gif)  
    
 **示例代码2：**   
Blank组件的父组件未设置宽度时，min参数的使用效果。  
```ts    
// xxx.ets  
@Entry  
@Component  
struct BlankExample {  
  build() {  
    Column({ space: 20 }) {  
      // blank父组件不设置宽度时，Blank失效，可以通过设置min最小宽度填充固定宽度  
      Row() {  
        Text('Bluetooth').fontSize(18)  
        Blank().color(Color.Yellow)  
        Toggle({ type: ToggleType.Switch }).margin({ top: 14, bottom: 14, left: 6, right: 6 })  
      }.backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })  
  
      Row() {  
        Text('Bluetooth').fontSize(18)  
        // 设置最小宽度为160  
        Blank('160').color(Color.Yellow)  
        Toggle({ type: ToggleType.Switch }).margin({ top: 14, bottom: 14, left: 6, right: 6 })  
      }.backgroundColor(0xFFFFFF).borderRadius(15).padding({ left: 12 })  
  
    }.backgroundColor(0xEFEFEF).padding(20).width('100%')  
  }  
}  
    
```    
  
Blank父组件未设置宽度时，子组件间无空白填充，使用min参数设置填充尺寸  
  
![blankmin](figures/blankmin.png)  
