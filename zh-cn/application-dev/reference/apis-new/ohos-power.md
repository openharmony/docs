# @ohos.power    
该模块主要提供重启、关机、查询屏幕状态等接口。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import power from '@ohos.power'    
```  
    
## rebootDevice<sup>(deprecated)</sup>    
重启设备。  
 **调用形式：**     
- rebootDevice(reason: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: power#reboot。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.REBOOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reason<sup>(deprecated)</sup> | string | true | 重启原因。 |  
    
 **示例代码：**   
```js    
power.rebootDevice('reboot_test');    
```    
  
    
## isScreenOn<sup>(deprecated)</sup>    
检测当前设备的亮灭屏状态。使用callback异步回调。  
。  
 **调用形式：**     
- isScreenOn(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: power#isActive。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 回调函数。当检测成功，err为undefined，data为获取到的亮灭屏状态，返回true表示亮屏，返回false表示灭屏；否则为错误对象。 |  
    
 **示例代码：**   
示例（callback）：  
  
```js    
<span style="letter-spacing: 0px;">power.isScreenOn((err: Error, data: boolean) => {</span>  
if (typeof err === 'undefined') {  
console.info('screen on status is ' + data);  
} else {  
console.error('check screen status failed, err: ' + err);  
}  
})  
    
```    
  
    
## isScreenOn<sup>(deprecated)</sup>    
检测当前设备的亮灭屏状态。使用Promise异步回调。  
 **调用形式：**     
- isScreenOn(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: power#isActive。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | Promise对象。返回true表示亮屏；返回false表示灭屏。 |  
    
 **示例代码：**   
示例（Promise）：  
```js    
power.isScreenOn().then((data: boolean) => {    console.info('screen on status is ' + data);}).catch((err: { code: number, message: string }) => {    console.error('check screen status failed, err: ' + err);})    
```    
  
    
## isActive<sup>(9+)</sup>    
检测当前设备是否处于活动状态。有屏的设备为亮屏状态，无屏的设备为非休眠状态。  
 **调用形式：**     
- isActive(): boolean  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let isActive = power.isActive();  
    console.info('power is active: ' + isActive);  
} catch(err) {  
    console.error('check active status failed, err: ' + err);  
}  
    
```    
  
    
## getPowerMode<sup>(9+)</sup>    
获取当前设备的电源模式。  
 **调用形式：**     
- getPowerMode(): DevicePowerMode  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| DevicePowerMode | 电源模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let mode = power.getPowerMode();  
    console.info('power mode: ' + mode);  
} catch(err) {  
    console.error('get power mode failed, err: ' + err);  
}  
    
```    
  
    
## isStandby<sup>(10+)</sup>    
检测当前设备是否进入待机低功耗续航模式。  
 **调用形式：**     
- isStandby(): boolean  
  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 进入待机模式返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let isStandby = power.isStandby();  
    console.info('device is in standby: ' + isStandby);  
} catch(err) {  
    console.error('check isStandby failed, err: ' + err);  
}  
    
```    
  
    
## DevicePowerMode<sup>(9+)</sup>    
表示电源模式的枚举值。    
    
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MODE_NORMAL | 600 | 表示标准模式，默认值。 |  
| MODE_POWER_SAVE | 601 | 表示省电模式。 |  
| MODE_PERFORMANCE | 602 | 表示性能模式。 |  
| MODE_EXTREME_POWER_SAVE | 603 | 表示超级省电模式。 |  
