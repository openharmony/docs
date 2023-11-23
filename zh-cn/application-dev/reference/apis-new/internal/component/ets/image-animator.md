# image_animator    
提供帧动画组件来实现逐帧播放图片的能力，可以配置需要播放的图片列表，每张图片可以配置时长。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## 接口  
  
  
    
 **调用形式**     
    
- ImageAnimator()    
起始版本： 7    
## ImageFrameInfo  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| src | string \| Resource | false | true | 图片路径，图片格式为svg，png和jpg，从API Version9开始支持Resource类型的路径。  
从API version 10开始，该接口支持在ArkTS卡片中使用。 |  
| width | number \| string | false | false | 图片宽度。  
默认值：0  
从API version 10开始，该接口支持在ArkTS卡片中使用 |  
| height | number \| string | false | false | 图片高度。  
默认值：0  
从API version 10开始，该接口支持在ArkTS卡片中使用 |  
| top | number \| string | false | false | 图片相对于组件左上角的纵向坐标。  
默认值：0  
从API version 10开始，该接口支持在ArkTS卡片中使用 |  
| left | number \| string | false | false | 图片相对于组件左上角的横向坐标。  
默认值：0  
从API version 10开始，该接口支持在ArkTS卡片中使用 |  
| duration | number | false | false | 每一帧图片的播放时长，单位毫秒。  
默认值：0。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| images |  Array<ImageFrameInfo> |  |  
| state |  AnimationStatus |  |  
| duration |  number |  |  
| reverse |  boolean |  |  
| fixedSize |  boolean |  |  
| preDecode<sup>(deprecated)</sup> |  number |  |  
| fillMode |  FillMode |  |  
| iterations |  number |  |  
    
### onStart<sup>(deprecated)</sup>    
onStart(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onPause<sup>(deprecated)</sup>    
onPause(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onRepeat<sup>(deprecated)</sup>    
onRepeat(event: () => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | () => void | true |  |  
    
### onCancel<sup>(deprecated)</sup>    
onCancel(event: () => void)    
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
struct ImageAnimatorExample {  
  @State state: AnimationStatus = AnimationStatus.Initial  
  @State reverse: boolean = false  
  @State iterations: number = 1  
  
  build() {  
    Column({ space: 10 }) {  
      ImageAnimator()  
        .images([  
          {  
            src: $r('app.media.img1')  
          },  
          {  
            src: $r('app.media.img2')  
          },  
          {  
            src: $r('app.media.img3')  
          },  
          {  
            src: $r('app.media.img4')  
          }  
        ])  
        .duration(2000)  
        .state(this.state).reverse(this.reverse)  
        .fillMode(FillMode.None).iterations(this.iterations).width(340).height(240)  
        .margin({ top: 100 })  
        .onStart(() => {  
          console.info('Start')  
        })  
        .onPause(() => {  
          console.info('Pause')  
        })  
        .onRepeat(() => {  
          console.info('Repeat')  
        })  
        .onCancel(() => {  
          console.info('Cancel')  
        })  
        .onFinish(() => {  
          console.info('Finish')  
          this.state = AnimationStatus.Stopped  
        })  
      Row() {  
        Button('start').width(100).padding(5).onClick(() => {  
          this.state = AnimationStatus.Running  
        }).margin(5)  
        Button('pause').width(100).padding(5).onClick(() => {  
          this.state = AnimationStatus.Paused     // 显示当前帧图片  
        }).margin(5)  
        Button('stop').width(100).padding(5).onClick(() => {  
          this.state = AnimationStatus.Stopped    // 显示动画的起始帧图片  
        }).margin(5)  
      }  
  
      Row() {  
        Button('reverse').width(100).padding(5).onClick(() => {  
          this.reverse = !this.reverse  
        }).margin(5)  
        Button('once').width(100).padding(5).onClick(() => {  
          this.iterations = 1  
        }).margin(5)  
        Button('infinite').width(100).padding(5).onClick(() => {  
          this.iterations = -1 // 无限循环播放  
        }).margin(5)  
      }  
    }.width('100%').height('100%')  
  }  
}  
    
```    
  
![imageAnimator](figures/imageAnimator.gif)  
