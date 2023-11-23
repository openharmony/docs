# button    
按钮组件，可快速创建不同样式的按钮。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ButtonType    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Capsule | 0 | 胶囊型按钮（圆角默认为高度的一半）。 |  
| Circle | 1 | 圆形按钮。 |  
| Normal | 2 | 普通按钮（默认不带圆角）。 |  
    
## ButtonOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | ButtonType | false | false | 设置Button样式。<br/>默认值：ButtonType.Capsule |  
| stateEffect | boolean | false | false | 按钮按下时是否开启按压态显示效果，当设置为false时，按压效果关闭。<br/>默认值：true<br/>**说明：** <br/>当开启按压态显示效果，开发者设置状态样式时，会基于状态样式设置完成后的背景色再进行颜色叠加。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- Button()    
起始版本： 7    
    
- Button(label: ResourceStr, options?: ButtonOptions)    
起始版本： 7    
    
- Button(options: ButtonOptions)    
起始版本： 7    
## LabelStyle<sup>(10+)</sup>  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| overflow<sup>(10+)</sup> | TextOverflow | false | false | 设置Label文本超长时的显示方式。文本截断是按字截断。例如，英文以单词为最小单位进行截断，若需要以字母为单位进行截断，可在字母间添加零宽空格。 |  
| maxLines<sup>(10+)</sup> | number | false | false | 设置Label文本的最大行数。默认情况下，文本是自动折行的，如果指定此参数，则文本最多不会超过指定的行。如果有多余的文本，可以通过textOverflow来指定截断方式。 |  
| minFontSize<sup>(10+)</sup> | number \| ResourceStr | false | false | 设置Label文本最小显示字号。需配合maxFontSize以及maxLines或布局大小限制使用。 |  
| maxFontSize<sup>(10+)</sup> | number \| ResourceStr | false | false | 设置Label文本最大显示字号。需配合minFontSize以及maxLines或布局大小限制使用。 |  
| heightAdaptivePolicy<sup>(10+)</sup> | TextHeightAdaptivePolicy | false | false | 设置Label文本自适应高度的方式。 |  
| font<sup>(10+)</sup> | Font | false | false | 设置Label文本字体样式。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| type |  ButtonType |  |  
| stateEffect |  boolean |  |  
| fontColor |  ResourceColor |  |  
| fontSize |  Length |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| fontStyle<sup>8+</sup> |  FontStyle |  |  
| fontFamily<sup>8+</sup> |  string \| Resource |  |  
| labelStyle<sup>10+</sup> |  LabelStyle |  |  
    
 **示例代码1：**   
```ts    
@Entry  
@Component  
struct ButtonExample {  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {  
      Text('Normal button').fontSize(9).fontColor(0xCCCCCC)  
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {  
        Button('OK', { type: ButtonType.Normal, stateEffect: true })  
          .borderRadius(8)  
          .backgroundColor(0x317aff)  
          .width(90)  
          .onClick(() => {  
            console.log('ButtonType.Normal')  
          })  
        Button({ type: ButtonType.Normal, stateEffect: true }) {  
          Row() {  
            LoadingProgress().width(20).height(20).margin({ left: 12 }).color(0xFFFFFF)  
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })  
          }.alignItems(VerticalAlign.Center)  
        }.borderRadius(8).backgroundColor(0x317aff).width(90).height(40)  
  
        Button('Disable', { type: ButtonType.Normal, stateEffect: false }).opacity(0.4)  
          .borderRadius(8).backgroundColor(0x317aff).width(90)  
      }  
  
      Text('Capsule button').fontSize(9).fontColor(0xCCCCCC)  
      Flex({ alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {  
        Button('OK', { type: ButtonType.Capsule, stateEffect: true }).backgroundColor(0x317aff).width(90)  
        Button({ type: ButtonType.Capsule, stateEffect: true }) {  
          Row() {  
            LoadingProgress().width(20).height(20).margin({ left: 12 }).color(0xFFFFFF)  
            Text('loading').fontSize(12).fontColor(0xffffff).margin({ left: 5, right: 12 })  
          }.alignItems(VerticalAlign.Center).width(90).height(40)  
        }.backgroundColor(0x317aff)  
  
        Button('Disable', { type: ButtonType.Capsule, stateEffect: false }).opacity(0.4)  
          .backgroundColor(0x317aff).width(90)  
      }  
  
      Text('Circle button').fontSize(9).fontColor(0xCCCCCC)  
      Flex({ alignItems: ItemAlign.Center, wrap: FlexWrap.Wrap }) {  
        Button({ type: ButtonType.Circle, stateEffect: true }) {  
          LoadingProgress().width(20).height(20).color(0xFFFFFF)  
        }.width(55).height(55).backgroundColor(0x317aff)  
  
        Button({ type: ButtonType.Circle, stateEffect: true }) {  
          LoadingProgress().width(20).height(20).color(0xFFFFFF)  
        }.width(55).height(55).margin({ left: 20 }).backgroundColor(0xF55A42)  
      }  
    }.height(400).padding({ left: 35, right: 35, top: 35 })  
  }  
}  
    
```    
  
![button](figures/button.gif)  
    
 **示例代码2：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct SwipeGestureExample {  
  @State count: number = 0  
  
  build() {  
    Column() {  
      Text(`${this.count}`)  
        .fontSize(30)  
        .onClick(() => {  
          this.count++  
        })  
      if (this.count <= 0) {  
        Button('count is negative').fontSize(30).height(50)  
      } else if (this.count % 2 === 0) {  
        Button('count is even').fontSize(30).height(50)  
      } else {  
        Button('count is odd').fontSize(30).height(50)  
      }  
    }.height('100%').width('100%').justifyContent(FlexAlign.Center)  
  }  
}  
    
```    
  
![ifButton](figures/ifButton.gif)  
    
 **示例代码3：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct buttonTestDemo {  
  @State txt: string = 'overflowTextOverlengthTextOverflow.Clip';  
  @State widthShortSize: number = 200;  
  
  build() {  
    Row() {  
      Column() {  
        Button(this.txt)  
          .width(this.widthShortSize)  
          .height(100)  
          .labelStyle({ overflow: TextOverflow.Clip,  
            maxLines: 1,  
            minFontSize: 20,  
            maxFontSize: 20,  
            font: {  
              size: 20,  
              weight: FontWeight.Bolder,  
              family: 'cursive',  
              style: FontStyle.Italic  
            }  
          })  
          .fontSize(40)  
      }  
      .width('100%')  
    }  
    .height('100%')  
  }  
}  
    
```    
  
![image-20230711171138661](figures/imageButtonLabelStyle.png)  
