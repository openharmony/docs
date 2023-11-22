# @ohos.power    
该模块主要提供重启、关机、查询屏幕状态等接口。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import power from '@ohos.power'    
```  
    
## shutdown    
系统关机。  
 **调用形式：**     
- shutdown(reason: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.REBOOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reason | string | true | 关机原因。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    power.shutdown('shutdown_test');  
} catch(err) {  
    console.error('shutdown failed, err: ' + err);  
}  
    
```    
  
    
## reboot<sup>(9+)</sup>    
重启设备。  
 **调用形式：**     
- reboot(reason: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.REBOOT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| reason | string | true | 重启原因。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    power.reboot('reboot_test');  
} catch(err) {  
    console.error('reboot failed, err: ' + err);  
}  
    
```    
  
    
## wakeup<sup>(9+)</sup>    
唤醒设备。  
 **调用形式：**     
- wakeup(detail: string): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| detail | string | true | 唤醒原因。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    power.wakeup('wakeup_test');  
} catch(err) {  
    console.error('wakeup failed, err: ' + err);  
}  
    
```    
  
    
## suspend<sup>(9+)</sup>    
休眠设备。  
 **调用形式：**     
- suspend(isImmediate?: boolean): void  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isImmediate | boolean | false | 是否直接休眠设备。不填该参数则默认为false由系统自动检测何时进入休眠。<br>**说明：** 从API version 10开始，支持该参数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    power.suspend();  
} catch(err) {  
    console.error('suspend failed, err: ' + err);  
}  
    
```    
  
    
## setPowerMode<sup>(9+)</sup>    
设置当前设备的电源模式。  
 **调用形式：**     
    
- setPowerMode(mode: DevicePowerMode, callback: AsyncCallback\<void>): void    
起始版本： 9    
- setPowerMode(mode: DevicePowerMode): Promise\<void>    
起始版本： 9  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.PowerManager.Core  
 **需要权限：** ohos.permission.POWER_OPTIMIZATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode | DevicePowerMode | true | 电源模式。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当设置电源模式成功，err为undefined，否则为错误对象。 |  
| Promise<void> | Promise对象。无返回结果的Promise对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 202 |  |  
| 401 |  |  
| 4900101 | If connecting to the service failed. |  
    
 **示例代码1：**   
示例（callback）：  
  
  
```js    
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE, (err: Error) => {  
    if (typeof err === 'undefined') {  
        console.info('set power mode to MODE_PERFORMANCE');  
    } else {  
        console.error('set power mode failed, err: ' + err);  
    }  
});  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
  
```js    
power.setPowerMode(power.DevicePowerMode.MODE_PERFORMANCE).then(() => {    console.info('set power mode to MODE_PERFORMANCE');}).catch((err : Error)=> {    console.error('set power mode failed, err: ' + err);});    
```    
  
