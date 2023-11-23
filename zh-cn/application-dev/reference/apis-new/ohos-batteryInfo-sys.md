# @ohos.batteryInfo    
该模块主要提供电池状态和充放电状态的查询接口。  
> **说明**   
>本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import batteryInfo from '@ohos.batteryInfo'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| estimatedRemainingChargeTime<sup>(9+)</sup> | number |  | 表示当前设备充满电的预估时间，单位毫秒。此接口为系统接口。 |  
| totalEnergy<sup>(9+)</sup> | number |  | 表示当前设备电池的总容量，单位毫安时。此接口为系统接口。 |  
| nowCurrent<sup>(9+)</sup> | number |  | 表示当前设备电池的电流，单位毫安。此接口为系统接口。 |  
| remainingEnergy<sup>(9+)</sup> | number |  | 表示当前设备电池的剩余容量，单位毫安时。此接口为系统接口。 |  
