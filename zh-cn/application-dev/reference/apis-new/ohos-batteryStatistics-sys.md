# @ohos.batteryStatistics    
该模块提供软硬件耗电统计信息的查询接口。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import batteryStats from '@ohos.batteryStatistics'    
```  
    
## ConsumptionType    
表示电量消耗类型的枚举值。    
    
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| CONSUMPTION_TYPE_INVALID | -17 | 表示电量消耗类型未知。 |  
| CONSUMPTION_TYPE_APP | -16 | 表示应用消耗的电量类型。 |  
| CONSUMPTION_TYPE_BLUETOOTH | -15 | 表示蓝牙消耗的电量类型。 |  
| CONSUMPTION_TYPE_IDLE | -14 | 表示CPU空闲时消耗的电量类型。 |  
| CONSUMPTION_TYPE_PHONE | -13 | 表示通话来电消耗的电量类型。 |  
| CONSUMPTION_TYPE_RADIO | -12 | 表示无线通讯消耗的电量类型。 |  
| CONSUMPTION_TYPE_SCREEN | -11 | 表示屏幕消耗的电量类型。 |  
| CONSUMPTION_TYPE_USER | -10 | 表示用户消耗的电量类型。 |  
| CONSUMPTION_TYPE_WIFI | -9 | 表示无线网消耗的电量类型。 |  
    
## getBatteryStats  
 **调用形式：**     
    
- getBatteryStats(): Promise\<Array\<BatteryStatsInfo>>    
起始版本： 8    
- getBatteryStats(callback: AsyncCallback\<Array\<BatteryStatsInfo>>): void    
起始版本： 8  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 获取耗电信息列表。使用Promise异步回调。 |  
| Promise<Array<BatteryStatsInfo>> | Promise对象，返回耗电信息列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 4600101 | If connecting to the service failed. |  
| 401 |  |  
    
 **示例代码1：**   
示例(Promise):  
```js    
batteryStats.getBatteryStats().then((data: batteryStats.BatteryStatsInfo[]) => {    console.info('battery statistics info: ' + data);}).catch((err: Error) => {    console.error('get battery statistics failed, err: ' + err);});    
```    
  
    
 **示例代码2：**   
示例(callback):  
```ts    
batteryStats.getBatteryStats((err: Error, data : batteryStats.BatteryStatsInfo[]) => {  
    if (typeof err === 'undefined') {  
        console.info('battery statistics info: ' + data);  
    } else {  
        console.error('get battery statistics failed, err: ' + err);  
    }  
});  
    
```    
  
    
## getAppPowerValue    
获取应用的耗电量。  
 **调用形式：**     
- getAppPowerValue(uid: number): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 应用的UID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | UID对应应用的耗电量，单位毫安时。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 4600101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let value = batteryStats.getAppPowerValue(10021);  
    console.info('battery statistics value of app is: ' + value);  
} catch(err) {  
    console.error('get battery statistics value of app failed, err: ' + err);  
}  
    
```    
  
    
## getAppPowerPercent    
获取应用的耗电百分比。  
 **调用形式：**     
- getAppPowerPercent(uid: number): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uid | number | true | 应用的UID。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | UID对应应用的耗电百分比。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 4600101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let percent = batteryStats.getAppPowerPercent(10021);  
    console.info('battery statistics percent of app is: ' + percent);  
} catch(err) {  
    console.error('get battery statistics percent of app failed, err: ' + err);  
}  
    
```    
  
    
## getHardwareUnitPowerValue    
根据耗电类型获取硬件单元的耗电量。  
 **调用形式：**     
- getHardwareUnitPowerValue(type: ConsumptionType): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | ConsumptionType | true | 电量消耗类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 电量消耗类型对应硬件的耗电量，单位毫安时。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 4600101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let value = batteryStats.getHardwareUnitPowerValue(batteryStats.ConsumptionType.CONSUMPTION_TYPE_SCREEN);  
    console.info('battery statistics value of hardware is: ' + value);  
} catch(err) {  
    console.error('get battery statistics percent of hardware failed, err: ' + err);  
}  
    
```    
  
    
## getHardwareUnitPowerPercent  
 **调用形式：**     
- getHardwareUnitPowerPercent(type: ConsumptionType): number  
  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | ConsumptionType | true | 电量消耗类型。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 电量消耗类型对应硬件的耗电百分比。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 202 |  |  
| 401 |  |  
| 4600101 | If connecting to the service failed. |  
    
 **示例代码：**   
```js    
try {  
    let value = batteryStats.getHardwareUnitPowerValue(batteryStats.ConsumptionType.CONSUMPTION_TYPE_SCREEN);  
    console.info('battery statistics value of hardware is: ' + value);  
} catch(err) {  
    console.error('get battery statistics percent of hardware failed, err: ' + err);  
}  
    
```    
  
    
## BatteryStatsInfo    
设备的耗电信息。  
 **系统API:**  此接口为系统接口。  
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
### 属性    
 **系统能力:**  SystemCapability.PowerManager.BatteryStatistics    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uid | number | false | true | 耗电信息相关的UID。 |  
| type | ConsumptionType | false | true | 耗电信息相关的类型。 |  
| power | number | false | true | 耗电的值，单位毫安时。 |  
