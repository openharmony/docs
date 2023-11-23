# text_timer    
通过文本显示计时信息并控制其计时器状态的组件。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## TextTimerController    
TextTimer组件的控制器，用于控制文本计时器。一个TextTimer组件仅支持绑定一个控制器。  
    
### start    
计时开始。  
  
 **调用形式：**     
- start()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### pause    
计时暂停。  
  
 **调用形式：**     
- pause()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### reset    
reset()  
  
 **调用形式：**     
- reset()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## TextTimerOptions  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### 属性    
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isCountDown | boolean | false | false | 是否倒计时。<br/>默认值：false |  
| count | number | false | false | 倒计时时间（isCountDown为true时生效），单位为毫秒。最长不超过86400000毫秒（24小时）。0<count<86400000时，count值为倒计时初始值。否则，使用默认值为倒计时初始值。<br/>默认值：60000<br/> |  
| controller | TextTimerController | false | false | TextTimer控制器。<br/> |  
    
## 接口  
  
  
    
 **调用形式**     
    
- TextTimer(options?: TextTimerOptions)    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options | TextTimerOptions | false |  |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| format |  string |  |  
| fontColor |  ResourceColor |  |  
| fontSize |  Length |  |  
| fontStyle |  FontStyle |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| fontFamily |  ResourceStr |  |  
    
### onTimer<sup>(deprecated)</sup>    
onTimer(event: (utc: number, elapsedTime: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (utc: number, elapsedTime: number) => void | true |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
@Entry  
@Component  
struct TextTimerExample {  
  textTimerController: TextTimerController = new TextTimerController()  
  @State format: string = 'mm:ss.SS'  
  
  build() {  
    Column() {  
      TextTimer({ isCountDown: true, count: 30000, controller: this.textTimerController })  
        .format(this.format)  
        .fontColor(Color.Black)  
        .fontSize(50)  
        .onTimer((utc: number, elapsedTime: number) => {  
          console.info('textTimer notCountDown utc is：' + utc + ', elapsedTime: ' + elapsedTime)  
        })  
      Row() {  
        Button("start").onClick(() => {  
          this.textTimerController.start()  
        })  
        Button("pause").onClick(() => {  
          this.textTimerController.pause()  
        })  
        Button("reset").onClick(() => {  
          this.textTimerController.reset()  
        })  
      }  
    }  
  }  
}  
    
```    
  
![zh-cn_image_0000001251007721](figures/zh-cn_image_0000001251007721.gif)  
