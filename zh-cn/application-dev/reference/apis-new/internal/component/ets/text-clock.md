# text_clock    
TextClock组件通过文本将当前系统时间显示在设备上。支持不同时区的时间显示，最高精度到秒级。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
 **子组件**   
无  
    
## TextClockController    
TextClock容器组件的控制器，可以将该控制器绑定到TextClock组件，通过它控制文本时钟的启动与停止。一个TextClock组件仅支持绑定一个控制器。  
    
### start    
启动文本时钟。  
  
 **调用形式：**     
- start()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
### stop    
停止文本时钟。  
  
 **调用形式：**     
- stop()  
  
 **系统能力:**  SystemCapability.ArkUI.ArkUI.Full    
## 接口  
  
  
    
 **调用形式**     
    
- TextClock(options?: { timeZoneOffset?: number; controller?: TextClockController })    
起始版本： 8    
    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| timeZoneOffset | number | false | 设置时区偏移量。<br>取值范围为[-14, 12]，表示东十二区到西十二区，其中负值表示东时区，正值表示西时区，比如东八区为-8。<br>对横跨国际日界线的国家或地区，用-13（UTC+13）和-14（UTC+14）来保证整个国家或者区域处在相同的时间，当设置的值不在取值范围内时，将使用当前系统的时区偏移量。<br/>默认值：当前系统的时区偏移量 |  
| controller | TextClockController | false | 绑定一个控制器，用来控制文本时钟的状态。 |  
    
## 属性  
    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
| 名称 | 类型 | 说明 |  
| --------| --------| --------|  
| format |  string |  |  
| format<sup>10+</sup> |  string |  |  
| fontColor |  ResourceColor |  |  
| fontColor<sup>10+</sup> |  ResourceColor |  |  
| fontSize |  Length |  |  
| fontSize<sup>10+</sup> |  Length |  |  
| fontStyle |  FontStyle |  |  
| fontStyle<sup>10+</sup> |  FontStyle |  |  
| fontWeight |  number \| FontWeight \| string |  |  
| fontWeight<sup>10+</sup> |  number \| FontWeight \| string |  |  
| fontFamily |  ResourceStr |  |  
| fontFamily<sup>10+</sup> |  ResourceStr |  |  
    
### onDateChange<sup>(deprecated)</sup>    
onDateChange(event: (value: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event | (value: number) => void | true |  |  
    
### onDateChange<sup>(deprecated)</sup>    
onDateChange(event: (value: number) => void)    
 **系统能力：** SystemCapability.ArkUI.ArkUI.Full    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| event<sup>(10+)</sup> | (value: number) => void | true |  |  
    
 **示例代码：**   
```null    
@Entry  
@Component  
struct Second {  
  @State accumulateTime: number = 0  
  // 导入对象  
  controller: TextClockController = new TextClockController()  
  build() {  
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {  
      Text('Current milliseconds is ' + this.accumulateTime)  
        .fontSize(20)  
      // 以12小时制显示东八区的系统时间，精确到秒。  
      TextClock({ timeZoneOffset: -8, controller: this.controller })  
        .format('aa hh:mm:ss')  
        .onDateChange((value: number) => {  
          this.accumulateTime = value  
        })  
        .margin(20)  
        .fontSize(30)  
      Button("start TextClock")  
        .margin({ bottom: 10 })  
        .onClick(() => {  
          // 启动文本时钟  
          this.controller.start()  
        })  
      Button("stop TextClock")  
        .onClick(() => {  
          // 停止文本时钟  
          this.controller.stop()  
        })  
    }  
    .width('100%')  
    .height('100%')  
  }  
}  
    
```    
  
![text_clock](figures/text_clock.gif)  
