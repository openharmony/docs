# stepper    
步骤导航器组件，适用于引导用户按照步骤完成任务的导航场景。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- Stepper(value?: { index?: number })    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | false | 设置步骤导航器当前显示StepperItem的索引值。<br/>默认值：0<br/> |  
    
### onFinish<sup>(deprecated)</sup>    
onFinish(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onSkip<sup>(deprecated)</sup>    
onSkip(callback: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onChange<sup>(deprecated)</sup>    
onChange(callback: (prevIndex: number, index: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onNext<sup>(deprecated)</sup>    
onNext(callback: (index: number, pendingIndex: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
### onPrevious<sup>(deprecated)</sup>    
onPrevious(callback: (index: number, pendingIndex: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **示例代码：**   
```ts    
@Styles function itemStyle () {  
  .width(336)  
  .height(621)  
  .margin({ top: 48, left: 12 })  
  .borderRadius(24)  
  .backgroundColor('#FFFFFF')  
}  
  
@Extend(Text) function itemTextStyle () {  
  .fontColor('#182431')  
  .fontSize(36)  
  .fontWeight(500)  
  .opacity(0.4)  
  .margin({ top: 82, bottom: 40 })  
}  
  
@Entry  
@Component  
struct StepperExample {  
  @State currentIndex: number = 0  
  @State firstState: ItemState = ItemState.Normal  
  @State secondState: ItemState = ItemState.Normal  
  @State thirdState: ItemState = ItemState.Normal  
  
  build() {  
    Stepper({  
      index: this.currentIndex  
    }) {  
      // 第一个步骤页  
      StepperItem() {  
        Column() {  
          Text('Page One')  
            .itemTextStyle()  
          Button('change status:' + this.firstState)  
            .backgroundColor('#007dFF')  
            .onClick(() => {  
              this.firstState = this.firstState === ItemState.Skip ? ItemState.Normal : ItemState.Skip  
            })  
        }.itemStyle()  
      }  
      .nextLabel('Next')  
      .status(this.firstState)  
      // 第二个步骤页  
      StepperItem() {  
        Column() {  
          Text('Page Two')  
            .itemTextStyle()  
          Button('change status:' + this.secondState)  
            .backgroundColor('#007dFF')  
            .onClick(() => {  
              this.secondState = this.secondState === ItemState.Disabled ? ItemState.Normal : ItemState.Disabled  
            })  
        }.itemStyle()  
      }  
      .nextLabel('Next')  
      .prevLabel('Previous')  
      .status(this.secondState)  
      // 第三个步骤页  
      StepperItem() {  
        Column() {  
          Text('Page Three')  
            .itemTextStyle()  
          Button('change status:' + this.thirdState)  
            .backgroundColor('#007dFF')  
            .onClick(() => {  
              this.thirdState = this.thirdState === ItemState.Waiting ? ItemState.Normal : ItemState.Waiting  
            })  
        }.itemStyle()  
      }  
      .status(this.thirdState)  
      // 第四个步骤页  
      StepperItem() {  
        Column() {  
          Text('Page Four')  
            .itemTextStyle()  
        }.itemStyle()  
      }  
    }  
    .backgroundColor('#F1F3F5')  
    .onFinish(() => {  
      // 此处可处理点击最后一页的Finish时的逻辑，例如路由跳转等  
      console.info('onFinish')  
    })  
    .onSkip(() => {  
      // 此处可处理点击跳过时的逻辑，例如动态修改Stepper的index值使其跳转到某一步骤页等  
      console.info('onSkip')  
    })  
    .onChange((prevIndex?: number, index?: number) => {  
      if(index){  
        this.currentIndex = index  
      }  
    })  
  }  
}  
    
```    
  
![stepper](figures/stepper.gif)  
