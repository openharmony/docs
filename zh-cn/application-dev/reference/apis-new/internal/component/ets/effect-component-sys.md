# effect_component    
特效合并容器组件，用于子节点特效绘制的合并，实现特效的绘制性能优化。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- EffectComponent()    
起始版本： 10    
 **示例代码：**   
```ts    
//Index.ets  
@Entry  
@Component  
struct Index {  
  build() {  
    Stack() {  
      Image($r("app.media.example"))  
        .autoResize(true)  
      EffectComponent() {  
        Column({ space: 20 }) {  
          // 使用backgroundBlurStyle进行模糊绘制  
          Text("Normal text with backgroundBlurStyle")  
            .textAlign(TextAlign.Center)  
            .fontSize(16)  
            .fontWeight(FontWeight.Medium)  
            .backgroundBlurStyle(BlurStyle.Thick)  
            .borderRadius(16)  
            .width('90%')  
            .height('48')  
  
          // 不进行模糊绘制  
          Text("Normal text without blur effect")  
            .textAlign(TextAlign.Center)  
            .fontSize(16)  
            .fontWeight(FontWeight.Medium)  
            .border({ width: 1 })  
            .borderRadius(16)  
            .width('90%')  
            .height('48')  
  
          // 使用useEffect进行模糊合并绘制，继承EffectComponent的模糊参数  
          Text("Normal text with useeffcet blur 1")  
            .textAlign(TextAlign.Center)  
            .useEffect(true)  
            .fontSize(16)  
            .fontWeight(FontWeight.Medium)  
            .borderRadius(16)  
            .width('90%')  
            .height('48')  
  
          // 使用useEffect进行模糊合并绘制，继承EffectComponent的模糊参数  
          Text("Normal text with useeffcet blur 2")  
            .textAlign(TextAlign.Center)  
            .useEffect(true)  
            .fontSize(16)  
            .fontWeight(FontWeight.Medium)  
            .borderRadius(16)  
            .width('90%')  
            .height('48')  
        }  
        .width('100%')  
      }  
      .backgroundBlurStyle(BlurStyle.Thin)  
    }  
    .backgroundColor(Color.Black)  
    .width('100%')  
    .height('100%')  
  }  
}  
    
```    
  
![zh-cn_image_effectcomponent](figures/zh-cn_image_effectcomponent.png)  
