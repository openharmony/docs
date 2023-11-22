# marquee    
跑马灯组件，用于滚动展示一段单行文本。仅当文本内容宽度超过跑马灯组件宽度时滚动，不超过时不滚动。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Marquee(value: { start: boolean; step?: number; loop?: number; fromStart?: boolean; src: string })    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| start | boolean | true | 控制跑马灯是否进入播放状态。<br/>**说明：**<br/>有限的滚动次数播放完毕后，不可以通过改变start重置滚动次数重新开始播放。 |  
| step | number | false | 滚动动画文本滚动步长。<br/>默认值：6，单位vp |  
| loop | number | false | 设置重复滚动的次数，小于等于零时无限循环。<br/>默认值：-1<br/>**说明：**<br/>ArkTS卡片上该参数设置任意值都仅在可见时滚动一次。 |  
| fromStart | boolean | false | 设置文本从头开始滚动或反向滚动。<br/>默认值：true |  
| src | string | true | 需要滚动的文本 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| fontColor |  ResourceColor |  |  
| fontSize |  Length |  |  
| allowScale |  boolean |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| fontFamily |  string \| Resource |  |  
    
### onStart<sup>(deprecated)</sup>    
onStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onBounce<sup>(deprecated)</sup>    
onBounce(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onFinish<sup>(deprecated)</sup>    
onFinish(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct MarqueeExample {  
  @State start: boolean = false  
  private fromStart: boolean = true  
  private step: number = 50  
  private loop: number = Number.POSITIVE_INFINITY  
  private src: string = "Running Marquee starts rolling"  
  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {  
      Marquee({  
        start: this.start,  
        step: this.step,  
        loop: this.loop,  
        fromStart: this.fromStart,  
        src: this.src  
      })  
        .width(360)  
        .height(80)  
        .fontColor('#FFFFFF')  
        .fontSize(48)  
        .fontWeight(700)  
        .backgroundColor('#182431')  
        .margin({ bottom: 40 })  
        .onStart(() => {  
          console.info('Marquee animation complete onStart')  
        })  
        .onBounce(() => {  
          console.info('Marquee animation complete onBounce')  
        })  
        .onFinish(() => {  
          console.info('Marquee animation complete onFinish')  
        })  
      Button('Start')  
        .onClick(() => {  
          this.start = true  
        })  
        .width(120)  
        .height(40)  
        .fontSize(16)  
        .fontWeight(500)  
        .backgroundColor('#007DFF')  
    }  
    .width('100%')  
    .height('100%')  
  }  
}  
    
```    
  
![marquee](figures/marquee.gif)  
