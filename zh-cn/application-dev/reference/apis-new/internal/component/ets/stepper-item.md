# stepper_item    
用作<a href="https://gitee.com/openharmony/docs/blob/weekly_20231010/zh-cn/application-dev/reference/arkui-ts/ts-basic-components-stepper.md">Stepper</a>组件的页面子组件。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## ItemState    
    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| Normal | 0 | 正常状态，右侧文本按钮正常显示，可点击进入下一个StepperItem。 |  
| Disabled | 1 | 不可用状态，右侧文本按钮灰度显示，不可点击进入下一个StepperItem。 |  
| Waiting | 2 | 等待状态，右侧文本按钮不显示，显示等待进度条，不可点击进入下一个StepperItem。 |  
| Skip | 3 | 跳过状态，右侧文本按钮默认显示“跳过”，此时可在Stepper的onSkip回调中自定义相关逻辑。 |  
    
## 接口  
  
  
    
 **调用形式**     
    
- StepperItem()    
起始版本： 8    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| prevLabel |  string |  |  
| nextLabel |  string |  |  
| status | null |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
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
