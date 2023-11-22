# @system.battery    
该模块提供充电状态及剩余电量的查询功能。  
> **说明**   
>本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
    
## BatteryResponse<sup>(deprecated)</sup>    
包含充电状态及剩余电量的对象。    
从API version 3 开始支持，从API version 6 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| charging<sup>(deprecated)</sup> | boolean | false | true | 从API version 3 开始支持，从API version 6 开始废弃。<br>当前电池是否在充电中。 |  
| level<sup>(deprecated)</sup> | number | false | true | 从API version 3 开始支持，从API version 6 开始废弃。<br>当前电池的电量，取值范围：0.00-1.00。 |  
    
## GetStatusOptions<sup>(deprecated)</sup>    
包含接口调用结果的对象。    
从API version 3 开始支持，从API version 6 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Lite    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Lite    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| success<sup>(deprecated)</sup> | (data: BatteryResponse) => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用成功的回调函数，data为[BatteryResponse](#batteryresponse)类型的返回值。 |  
| fail<sup>(deprecated)</sup> | (data: string, code: number) => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用失败的回调函数。data为错误信息，code为错误码。 |  
| complete<sup>(deprecated)</sup> | () => void | false | false | 从API version 3 开始支持，从API version 6 开始废弃。<br>接口调用结束的回调函数。 |  
    
## Battery<sup>(deprecated)</sup>    
从API version 3 开始支持，从API version 6 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Lite    
### getStatus<sup>(deprecated)</sup>    
获取设备当前的充电状态及剩余电量。  
 **调用形式：**     
- static getStatus(options?: GetStatusOptions): void  
  
 **废弃说明：** 从API version 6 开始废弃。  
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Lite    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| options<sup>(deprecated)</sup> | GetStatusOptions | false |  |  
    
 **示例代码：**   
```js    
battery.getStatus({    success: (data: BatteryResponse) => {        console.log('success get battery level:' + data.level);    },    fail: (data: string, code: number) => {        console.error('fail to get battery level code:' + code + ', data: ' + data);    }});    
```    
  
