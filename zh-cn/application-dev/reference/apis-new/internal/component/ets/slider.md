# slider    
滑动条组件，通常用于快速调节设置值，如音量调节、亮度调节等应用场景。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## SliderStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OutSet | 0 | 滑块在滑轨上<br/> |  
| InSet | 1 | 滑块在滑轨上<br/> |  
    
## SliderChangeMode    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Begin | 0 | 手势/鼠标接触或者按下滑块<br/> |  
| Moving | 1 | 正在拖动滑块过程中<br/> |  
| End | 2 | 手势/鼠标离开滑块<br/> |  
| Click<sup>(8+)</sup> | 3 | 点击滑动条使滑块位置移动<br/> |  
    
## SliderOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value | number | false | false | 当前进度值。<br/>默认值：参数min<br/> |  
| min | number | false | false | 设置最小值。<br/>默认值：0<br/> |  
| max | number | false | false | 设置最大值。<br/>默认值：100<br/><strong>说明：</strong><br/>min >= max异常情况，min取默认值0，max取默认值100。<br/>value不在[min, max]范围之内，取min/max，靠近min取min，靠近max取max。<br/> |  
| step | number | false | false | 设置Slider滑动步长。<br/>默认值：1<br/>取值范围：[0.01, max]<br/><strong>说明：</strong><br/>设置小于0或百分比的值时，按默认值显示<br/> |  
| style | SliderStyle | false | false | 设置Slider的滑块与滑轨显示样式。<br/>默认值：SliderStyle.OutSet<br/> |  
| direction<sup>(8+)</sup> | Axis | false | false | 设置滑动条滑动方向为水平或竖直方向。<br/>默认值：Axis.Horizontal<br/> |  
| reverse<sup>(8+)</sup> | boolean | false | false | 设置滑动条取值范围是否反向，横向Slider默认为从左往右滑动，竖向Slider默认为从上往下滑动。<br/>默认值：false<br/> |  
    
## SliderBlockType<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| DEFAULT | 0 | 使用默认滑块（圆形）<br/> |  
| IMAGE | 1 | 使用图片资源作为滑块。<br/> |  
| SHAPE | 2 | 使用自定义形状作为滑块<br/> |  
    
## SliderBlockStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type<sup>(10+)</sup> | SliderBlockType | false | true | 设置滑块形状。<br/>默认值：SliderBlockType.DEFAULT，使用圆形滑块<br/> |  
| image<sup>(10+)</sup> | ResourceStr | false | false | 设置滑块图片资源。<br/>图片显示区域大小由blockSize属性控制，请勿输入尺寸过大的图片。<br/> |  
| shape<sup>(10+)</sup> | CircleAttribute \| EllipseAttribute \| PathAttribute \| RectAttribute | false | false | 设置滑块使用的自定义形状<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Slider(options?: SliderOptions)    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(7+)</sup> | SliderOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| blockColor |  ResourceColor |  |  
| trackColor |  ResourceColor |  |  
| selectedColor |  ResourceColor |  |  
| minLabel<sup>(deprecated)</sup> |  string |  |  
| maxLabel<sup>(deprecated)</sup> |  string |  |  
| showSteps |  boolean |  |  
| showTips |  boolean, content?: ResourceStr |  |  
| trackThickness<sup>8+</sup> |  Length |  |  
| blockBorderColor<sup>10+</sup> |  ResourceColor |  |  
| blockBorderWidth<sup>10+</sup> |  Length |  |  
| stepColor<sup>10+</sup> |  ResourceColor |  |  
| trackBorderRadius<sup>10+</sup> |  Length |  |  
| blockSize<sup>10+</sup> |  SizeOptions |  |  
| blockStyle<sup>10+</sup> |  SliderBlockStyle |  |  
| stepSize<sup>10+</sup> |  Length |  |  
    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (value: number, mode: SliderChangeMode) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码1：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct SliderExample {  
  @State outSetValueOne: number = 40  
  @State inSetValueOne: number = 40  
  @State outSetValueTwo: number = 40  
  @State inSetValueTwo: number = 40  
  @State vOutSetValueOne: number = 40  
  @State vInSetValueOne: number = 40  
  @State vOutSetValueTwo: number = 40  
  @State vInSetValueTwo: number = 40  
  
  build() {  
    Column({ space: 8 }) {  
      Text('outset slider').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(15)  
      Row() {  
        Slider({  
          value: this.outSetValueOne,  
          min: 0,  
          max: 100,  
          style: SliderStyle.OutSet  
        })  
          .showTips(true)  
          .onChange((value: number, mode: SliderChangeMode) => {  
            this.outSetValueOne = value  
            console.info('value:' + value + 'mode:' + mode.toString())  
          })  
        // toFixed(0)将滑动条返回值处理为整数精度  
        Text(this.outSetValueOne.toFixed(0)).fontSize(12)  
      }  
      .width('80%')  
      Row() {  
        Slider({  
          value: this.outSetValueTwo,  
          step: 10,  
          style: SliderStyle.OutSet  
        })  
          .showSteps(true)  
          .onChange((value: number, mode: SliderChangeMode) => {  
            this.outSetValueTwo = value  
            console.info('value:' + value + 'mode:' + mode.toString())  
          })  
        Text(this.outSetValueTwo.toFixed(0)).fontSize(12)  
      }  
      .width('80%')  
  
      Text('inset slider').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(15)  
      Row() {  
        Slider({  
          value: this.inSetValueOne,  
          min: 0,  
          max: 100,  
          style: SliderStyle.InSet  
        })  
          .blockColor('#191970')  
          .trackColor('#ADD8E6')  
          .selectedColor('#4169E1')  
          .showTips(true)  
          .onChange((value: number, mode: SliderChangeMode) => {  
            this.inSetValueOne = value  
            console.info('value:' + value + 'mode:' + mode.toString())  
          })  
        Text(this.inSetValueOne.toFixed(0)).fontSize(12)  
      }  
      .width('80%')  
      Row() {  
        Slider({  
          value: this.inSetValueTwo,  
          step: 10,  
          style: SliderStyle.InSet  
        })  
          .blockColor('#191970')  
          .trackColor('#ADD8E6')  
          .selectedColor('#4169E1')  
          .showSteps(true)  
          .onChange((value: number, mode: SliderChangeMode) => {  
            this.inSetValueTwo = value  
            console.info('value:' + value + 'mode:' + mode.toString())  
          })  
        Text(this.inSetValueTwo.toFixed(0)).fontSize(12)  
      }  
      .width('80%')  
  
      Row() {  
        Column() {  
          Text('vertical outset slider').fontSize(9).fontColor(0xCCCCCC).width('50%').margin(15)  
          Row() {  
            Slider({  
              value: this.vOutSetValueOne,  
              style: SliderStyle.OutSet,  
              direction: Axis.Vertical  
            })  
              .blockColor('#191970')  
              .trackColor('#ADD8E6')  
              .selectedColor('#4169E1')  
              .showTips(true)  
              .onChange((value: number, mode: SliderChangeMode) => {  
                this.vOutSetValueOne = value  
                console.info('value:' + value + 'mode:' + mode.toString())  
              })  
            Slider({  
              value: this.vOutSetValueTwo,  
              step: 10,  
              style: SliderStyle.OutSet,  
              direction: Axis.Vertical  
            })  
              .blockColor('#191970')  
              .trackColor('#ADD8E6')  
              .selectedColor('#4169E1')  
              .showSteps(true)  
              .onChange((value: number, mode: SliderChangeMode) => {  
                this.vOutSetValueTwo = value  
                console.info('value:' + value + 'mode:' + mode.toString())  
              })  
          }  
        }.width('50%').height(300)  
  
        Column() {  
          Text('vertical inset slider').fontSize(9).fontColor(0xCCCCCC).width('50%').margin(15)  
          Row() {  
            Slider({  
              value: this.vInSetValueOne,  
              style: SliderStyle.InSet,  
              direction: Axis.Vertical,  
              reverse: true // 竖向的Slider默认是上端是min值，下端是max值，因此想要从下往上滑动，需要设置reverse为true  
            })  
              .showTips(true)  
              .onChange((value: number, mode: SliderChangeMode) => {  
                this.vInSetValueOne = value  
                console.info('value:' + value + 'mode:' + mode.toString())  
              })  
            Slider({  
              value: this.vInSetValueTwo,  
              step: 10,  
              style: SliderStyle.InSet,  
              direction: Axis.Vertical,  
              reverse: true  
            })  
              .showSteps(true)  
              .onChange((value: number, mode: SliderChangeMode) => {  
                this.vInSetValueTwo = value  
                console.info('value:' + value + 'mode:' + mode.toString())  
              })  
          }  
        }.width('50%').height(300)  
      }  
    }.width('100%')  
  }  
}  
    
```    
  
![zh-cn_image_0000001179613854](figures/zh-cn_image_0000001179613854.gif)  
    
 **示例代码2：**   
```ts    
@Entry  
@Component  
struct SliderExample {  
  @State tipsValue: number = 40  
  
  build() {  
    Column({ space: 8 }) {  
      Text('block').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      Slider({ style: SliderStyle.OutSet, value: 40 })  
        .blockSize({ width: 40, height: 40 })  
        .blockBorderColor(Color.Red)  
        .blockBorderWidth(5)  
      Divider()  
      Text('step').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      Slider({ style: SliderStyle.InSet, value: 40, step: 10 })  
        .showSteps(true)  
        .stepSize(8)  
        .stepColor(Color.Yellow)  
      Divider()  
      Text('track').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      Slider({ style: SliderStyle.InSet, value: 40 })  
        .trackBorderRadius(2)  
      Divider()  
      Text('blockStyle').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      Slider({ style: SliderStyle.OutSet, value: 40 })  
        .blockStyle({ type: SliderBlockType.DEFAULT })  
      Slider({ style: SliderStyle.OutSet, value: 40 })  
        .blockStyle({ type: SliderBlockType.IMAGE, image: $r('sys.media.ohos_app_icon') })  
      Slider({ style: SliderStyle.OutSet, value: 40 })  
        .blockSize({ width: '60px', height: '60px' })  
        .blockColor(Color.Red)  
        .blockStyle({ type: SliderBlockType.SHAPE, shape: new Path({ commands: 'M60 60 M30 30 L15 56 L45 56 Z' }) })  
      Divider()  
      Text('tips').fontSize(9).fontColor(0xCCCCCC).margin(15).width('90%')  
      Slider({ style: SliderStyle.InSet, value: this.tipsValue })  
        .showTips(true, 'value:' + this.tipsValue.toFixed())  
        .onChange(value => {  
          this.tipsValue = value  
        })  
    }  
  }  
}  
    
```    
  
![](figures/slider_2.png)  
  
