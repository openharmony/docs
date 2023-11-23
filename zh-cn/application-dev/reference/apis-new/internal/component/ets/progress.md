# progress    
进度条组件，用于显示内容加载或操作处理等进度。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ProgressOptions    
创建进度组件，用于显示内容加载或操作处理进度。  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| value | number | false | true | 指定当前进度值。设置小于0的数值时置为0，设置大于total的数值时置为total。 |  
| total | number | false | false | 指定进度总长。<br/>默认值：100 |  
| style<sup>(deprecated)</sup> | ProgressStyle | false | false | 从API version 7 开始支持，从API version 8 开始废弃。建议使用type替代。<br>指定进度条样式。<br/>该参数从API version8开始废弃，建议使用type替代。<br/>默认值：ProgressStyle.Linear |  
| type<sup>(8+)</sup> | Type | false | false | 指定进度条类型。<br/>默认值：ProgressType.Linear |  
    
## ProgressType<sup>(8+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Linear | 0 | 线性样式。从API version9开始，高度大于宽度的时候自适应垂直显示。 |  
| Ring | 1 | 环形无刻度样式，环形圆环逐渐显示至完全填充效果。 |  
| Eclipse | 2 | 圆形样式，显示类似月圆月缺的进度展示效果，从月牙逐渐变化至满月。 |  
| ScaleRing | 3 | 环形有刻度样式，显示类似时钟刻度形式的进度展示效果。从API version9开始，刻度外圈出现重叠的时候自动转换为环形无刻度进度条。 |  
| Capsule | 4 | 胶囊样式，头尾两端圆弧处的进度展示效果与Eclipse相同；中段处的进度展示效果与Linear相同。高度大于宽度的时候自适应垂直显示。 |  
    
## ProgressStatus<sup>(10+)</sup>    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| LOADING | 0 | 加载中。 |  
| PROGRESSING | 1 | 进度更新中。 |  
    
## ProgressStyleOptions<sup>(8+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| strokeWidth<sup>(8+)</sup> | Length | false | false | 设置进度条宽度（不支持百分比设置）。<br/>默认值：4.0vp |  
| scaleCount<sup>(8+)</sup> | number | false | false | 设置环形进度条总刻度数。<br/>默认值：120。 |  
| scaleWidth<sup>(8+)</sup> | Length | false | false | 设置环形进度条刻度粗细（不支持百分比设置），刻度粗细大于进度条宽度时，为系统默认粗细。<br/>默认值：2.0vp |  
    
## CommonProgressStyleOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| enableSmoothEffect<sup>(10+)</sup> | boolean | false | false | 进度平滑动效的开关。开启平滑动效后设置进度，进度会从当前值渐变至设定值，否则进度从当前值突变至设定值。<br/>默认值：true。 |  
    
## ScanEffectOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| enableScanEffect<sup>(10+)</sup> | boolean | false | false |  |  
    
## EclipseStyleOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## ScaleRingStyleOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| strokeWidth<sup>(10+)</sup> | Length | false | false | 设置进度条宽度（不支持百分比设置）。<br/>默认值：4.0vp |  
| scaleWidth<sup>(10+)</sup> | Length | false | false | 设置环形进度条刻度粗细（不支持百分比设置），刻度粗细大于进度条宽度时，为系统默认粗细。<br/>默认值：2.0vp |  
| scaleCount<sup>(10+)</sup> | number | false | false | 设置环形进度条总刻度数。<br/>默认值：120 |  
    
## RingStyleOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| strokeWidth<sup>(10+)</sup> | Length | false | false | 设置进度条宽度（不支持百分比设置）。<br/>默认值：4.0vp |  
| shadow<sup>(10+)</sup> | boolean | false | false | 进度条阴影开关。<br/>默认值：false。 |  
| status<sup>(10+)</sup> | ProgressStatus | false | false | 进度条状态，当设置为LOADING时会开启检查更新动效，此时设置进度值不生效。当从LOADING设置为PROGRESSING，检查更新动效会执行到终点再停止。<br/>默认值： ProgressStatus.PROGRESSING |  
    
## LinearStyleOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| strokeWidth<sup>(10+)</sup> | Length | false | false | 设置进度条宽度（不支持百分比设置）。<br/>默认值：4.0vp |  
| strokeRadius<sup>(10+)</sup> | PX \| VP \| LPX \| Resource | false | false | 设置线性进度条圆角半径。<br/>取值范围[0, strokeWidth / 2]。默认值：strokeWidth / 2。 |  
    
## CapsuleStyleOptions<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| borderColor<sup>(10+)</sup> | ResourceColor | false | false | 内描边颜色。<br/>默认值：'\#33006cde' |  
| borderWidth<sup>(10+)</sup> | Length | false | false | 文本内容，应用可自定义。 |  
| content<sup>(10+)</sup> | string | false | false | 文本内容，应用可自定义。 |  
| font<sup>(10+)</sup> | Font | false | false | 文本样式。<br/>默认值：<br/>- 文本大小（不支持百分比设置）：12fp <br/>其他文本参数跟随text组件的主题值。 |  
| fontColor<sup>(10+)</sup> | ResourceColor | false | false | 文本颜色。<br/>默认值：'\#ff182431'。 |  
| showDefaultPercentage<sup>(10+)</sup> | boolean | false | false | 显示百分比文本的开关，开启后会在进度条上显示当前进度的百分比。设置了content属性时该属性不生效。<br/>默认值：false |  
    
## ProgressStyle    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Linear | 0 | 线性样式。 |  
| Ring<sup>(8+)</sup> | 1 | 环形无刻度样式，环形圆环逐渐显示至完全填充效果。 |  
| Eclipse | 2 | 圆形样式，显示类似月圆月缺的进度展示效果，从月牙逐渐变化至满月。 |  
| ScaleRing<sup>(8+)</sup> | 3 | 环形有刻度样式，显示类似时钟刻度形式的进度展示效果。 |  
| Capsule<sup>(8+)</sup> | 4 | 胶囊样式，头尾两端圆弧处的进度展示效果与Eclipse相同；中段处的进度展示效果与Linear相同。高度大于宽度的时候自适应垂直显示。 |  
    
## ProgressStyleMap<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| [ProgressType.Linear]<sup>(10+)</sup> | LinearStyleOptions \| ProgressStyleOptions | false | true |  |  
| [ProgressType.Ring]<sup>(10+)</sup> | RingStyleOptions \| ProgressStyleOptions | false | true |  |  
| [ProgressType.Eclipse]<sup>(10+)</sup> | EclipseStyleOptions \| ProgressStyleOptions | false | true |  |  
| [ProgressType.ScaleRing]<sup>(10+)</sup> | ScaleRingStyleOptions \| ProgressStyleOptions | false | true |  |  
| [ProgressType.Capsule]<sup>(10+)</sup> | CapsuleStyleOptions \| ProgressStyleOptions | false | true |  |  
    
## 接口  
  
  
<pre>创建进度组件，用于显示内容加载或操作处理进度。</pre>  
    
 **调用形式**     
    
- Progress<Type extends keyof ProgressStyleMap>(options: ProgressOptions<Type>): ProgressAttribute<Type>    
起始版本： 7    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | ProgressOptions<Type> | true |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| value |  number |  |  
| color |  ResourceColor \| LinearGradient |  |  
| style<sup>8+</sup> |  Style |  |  
    
 **示例代码1：**   
各进度条基础属性效果  
```ts    
// xxx.ets  
@Entry  
@Component  
struct ProgressExample {  
  build() {  
    Column({ space: 15 }) {  
      Text('Linear Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Progress({ value: 10, type: ProgressType.Linear }).width(200)  
      Progress({ value: 20, total: 150, type: ProgressType.Linear }).color(Color.Grey).value(50).width(200)  
  
  
      Text('Eclipse Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Row({ space: 40 }) {  
        Progress({ value: 10, type: ProgressType.Eclipse }).width(100)  
        Progress({ value: 20, total: 150, type: ProgressType.Eclipse }).color(Color.Grey).value(50).width(100)  
      }  
  
      Text('ScaleRing Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Row({ space: 40 }) {  
        Progress({ value: 10, type: ProgressType.ScaleRing }).width(100)  
        Progress({ value: 20, total: 150, type: ProgressType.ScaleRing })  
          .color(Color.Grey).value(50).width(100)  
          .style({ strokeWidth: 15, scaleCount: 15, scaleWidth: 5 })  
      }  
  
      // scaleCount和scaleWidth效果对比  
      Row({ space: 40 }) {  
        Progress({ value: 20, total: 150, type: ProgressType.ScaleRing })  
          .color(Color.Grey).value(50).width(100)  
          .style({ strokeWidth: 20, scaleCount: 20, scaleWidth: 5 })  
        Progress({ value: 20, total: 150, type: ProgressType.ScaleRing })  
          .color(Color.Grey).value(50).width(100)  
          .style({ strokeWidth: 20, scaleCount: 30, scaleWidth: 3 })  
      }  
  
      Text('Ring Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Row({ space: 40 }) {  
        Progress({ value: 10, type: ProgressType.Ring }).width(100)  
        Progress({ value: 20, total: 150, type: ProgressType.Ring })  
          .color(Color.Grey).value(50).width(100)  
          .style({ strokeWidth: 20 })  
      }  
  
      Text('Capsule Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Row({ space: 40 }) {  
        Progress({ value: 10, type: ProgressType.Capsule }).width(100).height(50)  
        Progress({ value: 20, total: 150, type: ProgressType.Capsule })  
          .color(Color.Grey)  
          .value(50)  
          .width(100)  
          .height(50)  
      }  
    }.width('100%').margin({ top: 30 })  
  }  
}  
    
```    
  
![progress](figures/arkts-progress.png)  
    
 **示例代码2：**   
环形进度条视觉属性  
```ts    
@Entry  
@Component  
struct ProgressExample {  
  private gradientColor: LinearGradient = new LinearGradient([{ color: Color.Yellow, offset: 0.5 },  
                                                              { color: Color.Orange, offset: 1.0 }])  
  build() {  
    Column({ space: 15 }) {  
      Text('Gradient Color').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Progress({ value: 70, total: 100, type: ProgressType.Ring })  
        .width(100).style({ strokeWidth: 20 })  
        .color(this.gradientColor)  
  
      Text('Shadow').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Progress({ value: 70, total: 100, type: ProgressType.Ring })  
        .width(120).color(Color.Orange)  
        .style({ strokeWidth: 20, shadow: true })  
    }.width('100%').padding({ top: 5 })  
  }  
}  
    
```    
  
![ringProgressStyleEffect](figures/arkts-ringProgressStyleEffect.png)  
    
 **示例代码3：**   
环形进度条动效  
```ts    
@Entry  
@Component  
struct ProgressExample {  
  private gradientColor: LinearGradient = new LinearGradient([{ color: Color.Yellow, offset: 0.5 },  
                                                              { color: Color.Orange, offset: 1.0 }])  
  build() {  
    Column({ space: 15 }) {  
      Text('Loading Effect').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Progress({ value: 0, total: 100, type: ProgressType.Ring })  
        .width(100).color(Color.Blue)  
        .style({ strokeWidth: 20, status: ProgressStatus.LOADING })  
  
      Text('Scan Effect').fontSize(9).fontColor(0xCCCCCC).width('90%')  
      Progress({ value: 30, total: 100, type: ProgressType.Ring })  
        .width(100).color(Color.Orange)  
        .style({ strokeWidth: 20, enableScanEffect: true })  
    }.width('100%').padding({ top: 5 })  
  }  
}  
    
```    
  
![ringProgressAnimation](figures/arkts-ringProgressAnimation.gif)  
    
 **示例代码4：**   
胶囊形进度条视觉属性  
```ts    
@Entry  
@Component  
struct ProgressExample {  
  
  build() {  
    Column({ space: 15 }) {  
      Row({ space: 40 }) {  
        Progress({ value: 100, total: 100,type: ProgressType.Capsule }).width(100).height(50)  
          .style({borderColor: Color.Blue, borderWidth: 1, content: 'Installing...',  
                  font: {size: 13, style: FontStyle.Normal}, fontColor: Color.Gray,  
                  enableScanEffect: false, showDefaultPercentage: false})  
      }  
    }.width('100%').padding({ top: 5 })  
  }  
}  
    
```    
  
![capsuleProgressStyleEffect](figures/arkts-capsuleProgressStyleEffect.png)  
    
 **示例代码5：**   
进度平滑动效  
```ts    
@Entry  
@Component  
struct Index {  
  @State value: number = 0  
  
  build() {  
    Column({space: 10}) {  
      Text('enableSmoothEffect: true').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(5)  
        .margin({top: 20})  
      Progress({value: this.value, total: 100, type:ProgressType.Linear})  
        .style({strokeWidth: 10, enableSmoothEffect: true})  
  
      Text('enableSmoothEffect: false').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(5)  
      Progress({value: this.value, total: 100, type:ProgressType.Linear})  
        .style({strokeWidth: 10, enableSmoothEffect: false})  
  
      Button('value +10').onClick(() => {  
        this.value += 10  
      })  
        .width(75)  
        .height(15)  
        .fontSize(9)  
    }  
    .width('50%')  
    .height('100%')  
    .margin({left:20})  
  }  
}  
    
```    
  
![progressSmoothEffect](figures/arkts-progressSmoothEffect.gif)  
