# @system.vibrator    
vibrator模块提供控制马达振动的能力，主要包含灯的列表查询、打开灯、关闭灯等接口，振动器的列表查询、振动器的振动器效果查询、触发/关闭振动器等接口。控制类小器件指的是设备上的LED灯和振动器。其中，LED灯主要用作指示（如充电状态）、闪烁功能（如三色灯）等；振动器主要用于闹钟、开关机振动、来电振动等场景。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import vibrator from '@system.vibrator';  
    
```  
    
## VibrateOptions<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.vibrator/vibrator.VibrateTime替代。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice.Lite    
### 属性    
 **需要权限：** ohos.permission.VIBRATE    
 **系统能力:**  SystemCapability.Sensors.MiscDevice.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | 'long' \| 'short' | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>振动的模式，其中long表示长振动，short表示短振动，默认值为long。 |  
| success<sup>(deprecated)</sup> | () => void | false | true | 从API version 3 开始支持，从API version 8 开始废弃。<br>感应到振动数据变化后的回调函数。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用失败的回调函数。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 8 开始废弃。<br>接口调用结束的回调函数。 |  
    
## Vibrator<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 8 开始废弃。建议使用ohos.vibrator/vibrator替代。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice.Lite    
### vibrate<sup>(deprecated)</sup>    
触发设备振动。  
 **调用形式：**     
- static vibrate(options?: VibrateOptions): void  
  
 **废弃说明：** 从API version 8 开始废弃。替代接口: ohos.vibrator/vibrator#startVibration。  
 **系统能力:**  SystemCapability.Sensors.MiscDevice.Lite  
 **需要权限：** ohos.permission.VIBRATE    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | VibrateOptions | false | 振动模式。 |  
    
 **示例代码：**   
```ts    
import vibrator from '@system.vibrator';  
import { VibrateOptions } from '@system.vibrator';  
  
let vibrateOptions: VibrateOptions = {  
  mode: 'short',  
  success: () => {  
    console.info('Succeed in vibrating');  
  },  
  fail: (data: string, code: number) => {  
    console.info(`Failed to vibrate. Data: ${data}, code: ${code}`);  
  },  
  complete: () => {  
    console.info('completed in vibrating');  
  }  
};  
vibrator.vibrate(vibrateOptions);  
    
```    
  
