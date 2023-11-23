# rating    
提供在给定范围内选择评分的组件。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Rating(options?: { rating: number; indicator?: boolean })    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| rating | number | true | 设置并接收评分值。<br/>默认值：0<br/>取值范围： [0, stars]<br/>小于0取0，大于stars取最大值stars。<br />从API version 10开始，该参数支持[$$](../../quick-start/arkts-two-way-sync.md)双向绑定变量。 |  
| indicator | boolean | false | 设置评分组件作为指示器使用，不可改变评分。<br/>默认值：false, 可进行评分<br/>**说明：** <br/>indicator=true时，默认组件高度height=12.0vp，组件width=height * stars。 <br/>indicator=false时，默认组件高度height=28.0vp，组件width=height * stars。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| stars |  number |  |  
| stepSize |  number |  |  
| starStyle |  { backgroundUri: string; foregroundUri: string; secondaryUri?: string } |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct RatingExample {  
  @State rating: number = 3.5  
  
  build() {  
    Column() {  
      Column() {  
        Rating({ rating: this.rating, indicator: false })  
          .stars(5)  
          .stepSize(0.5)  
          .margin({ top: 24 })  
          .onChange((value: number) => {  
            this.rating = value  
          })  
        Text('current score is ' + this.rating)  
          .fontSize(16)  
          .fontColor('rgba(24,36,49,0.60)')  
          .margin({ top: 16 })  
      }.width(360).height(113).backgroundColor('#FFFFFF').margin({ top: 68 })  
  
      Row() {  
        Image('common/testImage.jpg')  
          .width(40)  
          .height(40)  
          .borderRadius(20)  
          .margin({ left: 24 })  
        Column() {  
          Text('Yue')  
            .fontSize(16)  
            .fontColor('#182431')  
            .fontWeight(500)  
          Row() {  
            Rating({ rating: 3.5, indicator: false }).margin({ top: 1, right: 8 })  
            Text('2021/06/02')  
              .fontSize(10)  
              .fontColor('#182431')  
          }  
        }.margin({ left: 12 }).alignItems(HorizontalAlign.Start)  
  
        Text('1st Floor')  
          .fontSize(10)  
          .fontColor('#182431')  
          .position({ x: 295, y: 8 })  
      }.width(360).height(56).backgroundColor('#FFFFFF').margin({ top: 64 })  
    }.width('100%').height('100%').backgroundColor('#F1F3F5')  
  }  
}  
    
```    
  
![rating](figures/rating.gif)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct RatingExample {  
  @State rating: number = 3.5  
  
  build() {  
    Column() {  
      Rating({ rating: this.rating, indicator: false })  
        .stars(5)  
        .stepSize(0.5)  
        .starStyle({  
          backgroundUri: '/common/imag1.png', // common目录与pages同级  
          foregroundUri: '/common/imag2.png',  
          secondaryUri: '/common/imag3.png'  
        })  
        .margin({ top: 24 })  
        .onChange((value: number) => {  
          this.rating = value  
        })  
      Text('current score is ' + this.rating)  
        .fontSize(16)  
        .fontColor('rgba(24,36,49,0.60)')  
        .margin({ top: 16 })  
    }.width('100%').height('100%').backgroundColor('#F1F3F5')  
  }  
}  
    
```    
  
![rating1](figures/rating1.gif)  
