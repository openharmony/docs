# @ohos.charger    
提供充电类型。  
> **说明**   
>本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import charger from '@ohos.charger'    
```  
    
## ChargeType    
表示充电类型的枚举。  
    
    
 **系统能力:**  SystemCapability.PowerManager.BatteryManager.Core    
 **系统接口：** 此接口为系统接口。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NONE | 0 | 表示未知类型。<br/> |  
| WIRED_NORMAL | 1 | 表示有线正常充电类型。<br/> |  
| WIRED_QUICK | 2 | 表示有线快速充电类型。<br/> |  
| WIRED_SUPER_QUICK | 3 | 表示有线超级快速充电类型。 |  
| WIRELESS_NORMAL | 4 | 表示无线正常充电类型。<br/> |  
| WIRELESS_QUICK | 5 | 表示无线快速充电类型。 |  
| WIRELESS_SUPER_QUICK | 6 | 表示无线超级快速充电类型。 |  
