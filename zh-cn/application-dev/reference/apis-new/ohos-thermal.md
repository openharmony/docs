# @ohos.thermal    
该模块提供热管理相关的接口，包括热档位查询及注册回调等功能。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import thermal from '@ohos.thermal'    
```  
    
## ThermalLevel    
热档位信息。    
    
 **系统能力:**  SystemCapability.PowerManager.ThermalManager    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COOL | 0 | 表明设备处于低温的状态，业务执行不受热控的限制。 |  
| NORMAL | 1 | 表明设备处于正常工作状态，但温度不低，需要注意是否临近发热状态  |  
| WARM | 2 | 表明设备已经进入温热状态，部分无感知业务需要考虑停止或延迟执行。 |  
| HOT | 3 | 表明设备已经明显发热，无感知业务应全面停止，其他业务应考虑降规格及负载。 |  
| OVERHEATED | 4 | 表明设备已经发热严重，无感知业务应全面停止，主要业务需降低规格及负载。 |  
| WARNING | 5 | 表明设备已经发热严重并且即将进入紧急状态，无感知业务应全面停止，主要业务应降低至最低规格。 |  
| EMERGENCY | 6 | 表明设备已经进入紧急状态，所有业务应当全面停止工作，可保留部分紧急求助功能。 |  
    
## subscribeThermalLevel<sup>(deprecated)</sup>    
订阅热档位变化时的回调提醒。  
 **调用形式：**     
- subscribeThermalLevel(callback: AsyncCallback\<ThermalLevel>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: thermal#registerThermalLevelCallback。  
 **系统能力:**  SystemCapability.PowerManager.ThermalManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<ThermalLevel> | true |  回调函数。AsyncCallback只返回一个参数，为热档位信息。 |  
    
 **示例代码：**   
```ts    
thermal.subscribeThermalLevel((err: Error, level: thermal.ThermalLevel) => {    console.info('thermal level is: ' + level);});    
```    
  
    
## registerThermalLevelCallback<sup>(9+)</sup>    
订阅热档位变化时的回调提醒。  
 **调用形式：**     
    
- registerThermalLevelCallback(callback: Callback\<ThermalLevel>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.PowerManager.ThermalManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，返回变化后的热档位。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 4800101 | If connecting to the service failed. |  
    
 **示例代码：**   
```ts    
try {  
    thermal.registerThermalLevelCallback((level: thermal.ThermalLevel) => {  
        console.info('thermal level is: ' + level);  
    });  
    console.info('register thermal level callback success.');  
} catch(err) {  
    console.error('register thermal level callback failed, err: ' + err);  
}  
    
```    
  
    
## unsubscribeThermalLevel<sup>(deprecated)</sup>    
取消订阅热档位变化时的回调提醒。  
 **调用形式：**     
- unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: thermal#unregisterThermalLevelCallback。  
 **系统能力:**  SystemCapability.PowerManager.ThermalManager    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<void> | false | 回调函数，无返回值。不填该参数则取消所有回调。 |  
    
 **示例代码：**   
```null    
thermal.unsubscribeThermalLevel(() => {    console.info('unsubscribe thermal level success.');});    
```    
  
    
## unregisterThermalLevelCallback<sup>(9+)</sup>    
取消订阅热档位变化时的回调提醒。  
 **调用形式：**     
    
- unregisterThermalLevelCallback(callback?: Callback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.PowerManager.ThermalManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，无返回值。不填该参数则取消所有回调。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 4800101 | If connecting to the service failed. |  
    
 **示例代码：**   
```ts    
try {  
    thermal.unregisterThermalLevelCallback(() => {  
        console.info('unsubscribe thermal level success.');  
    });  
    console.info('unregister thermal level callback success.');  
} catch(err) {  
    console.error('unregister thermal level callback failed, err: ' + err);  
}  
    
```    
  
    
## getThermalLevel<sup>(deprecated)</sup>    
获取当前热档位信息。  
 **调用形式：**     
- getThermalLevel(): ThermalLevel  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: thermal#getLevel。  
 **系统能力:**  SystemCapability.PowerManager.ThermalManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ThermalLevel | 热档位信息。 |  
    
 **示例代码：**   
```ts    
let level = thermal.getThermalLevel();console.info('thermal level is: ' + level);    
```    
  
    
## getLevel<sup>(9+)</sup>    
获取当前热档位信息。  
 **调用形式：**     
- getLevel(): ThermalLevel  
  
 **系统能力:**  SystemCapability.PowerManager.ThermalManager    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ThermalLevel | 热档位信息 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 4800101 | If connecting to the service failed. |  
    
 **示例代码：**   
```ts    
try {  
    let level = thermal.getLevel();  
    console.info('thermal level is: ' + level);  
} catch(err) {  
    console.error('get thermal level failed, err: ' + err);  
}  
    
```    
  
