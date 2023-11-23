# @ohos.stationary    
设备状态感知框架提供设备状态感知能力，包括绝对静止和相对静止。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import stationary from '@ohos.stationary'    
```  
    
## ActivityResponse    
服务响应抽象接口。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Stationary    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| state | ActivityState | false | true | 设备状态变化返回值。 |  
    
## ActivityType    
设备状态类型。  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Stationary    
    
| 取值范围 | 说明 |  
| --------| --------|  
| still | 绝对静止。 |  
| relativeStill | 相对静止。 |  
    
## ActivityEvent    
设备状态事件。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ENTER | 1 | 进入。 |  
| EXIT | 2 | 退出。 |  
| ENTER_EXIT | 3 | 进入和退出。 |  
    
## ActivityState    
设备状态返回值。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| ENTER | 1 | 进入。 |  
| EXIT | 2 | 退出。 |  
    
## on    
设备状态管理，订阅设备状态服务。  
 **调用形式：**     
    
- on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback\<ActivityResponse>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Stationary    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| activity | ActivityType | true | 设备状态能力类型。 |  
| event | ActivityEvent | true | 事件类型。 |  
| reportLatencyNs | number | true | 报告延时。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，接收上报状态变化事件。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
let reportLatencyNs = 100;stationary.on('still', stationary.ActivityEvent.ENTER, reportLatencyNs, (data) => {    console.log('data='+ JSON.stringify(data));})    
```    
  
    
## once    
设备状态管理，查询设备状态。  
 **调用形式：**     
    
- once(activity: ActivityType, callback: Callback\<ActivityResponse>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Stationary    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| activity | ActivityType | true | 设备状态能力类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，接收上报状态变化事件。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
stationary.once('still', (data) => {    console.log("data="+ JSON.stringify(data));})    
```    
  
    
## off    
设备状态管理，取消订阅设备状态服务。  
 **调用形式：**     
    
- off(activity: ActivityType, event: ActivityEvent, callback?: Callback\<ActivityResponse>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Msdp.DeviceStatus.Stationary    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| activity | ActivityType | true | 设备状态能力类型。 |  
| event | ActivityEvent | true | 事件类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数，接收上报状态变化事件，如果没有传递callback参数或者传递的类型是undefined，会移除该进程下订阅该类型得所有callback。 |  
    
 **示例代码：**   
示例（callback）:  
```ts    
stationary.off('still', stationary.ActivityEvent.ENTER);    
```    
  
