# @ohos.wifiext    
该模块主要提供WLAN扩展接口，供非通用类型产品使用。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wifiext from '@ohos.wifiext'    
```  
    
## enableHotspot<sup>(deprecated)</sup>    
使能WLAN热点。  
 **调用形式：**     
- enableHotspot(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManagerExt/wifiManagerExt.enableHotspot。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 操作结果， true: 成功， false: 失败。 |  
    
## disableHotspot<sup>(deprecated)</sup>    
去使能WLAN热点。  
 **调用形式：**     
- disableHotspot(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManagerExt/wifiManagerExt.disableHotspot。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 操作结果， true: 成功， false: 失败。 |  
    
## getSupportedPowerModel<sup>(deprecated)</sup>    
获取支持的功率模式，使用Promise异步回调。  
 **调用形式：**     
- getSupportedPowerModel(): Promise\<Array\<PowerModel>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<PowerModel>> | Promise<Array<[PowerModel](#powermodel)>> | Promise对象。表示功率模式。 |  
    
## getSupportedPowerModel<sup>(deprecated)</sup>    
获取支持的功率模式，使用callback异步回调。  
 **调用形式：**     
- getSupportedPowerModel(callback: AsyncCallback\<Array\<PowerModel>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManagerExt/wifiManagerExt.getSupportedPowerMode。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<PowerModel>> | true | AsyncCallbacklt;Arraylt;[PowerModel](#powermodel)gt;gt; | 是 | 回调函数。当操作成功时，err为0，data表示支持的功率模式。如果error为非0，表示处理出现错误。 |  
    
## getPowerModel<sup>(deprecated)</sup>    
获取功率模式，使用Promise异步回调。  
 **调用形式：**     
- getPowerModel(): Promise\<PowerModel>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManagerExt/wifiManagerExt.getPowerMode。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<PowerModel> | Promise<[PowerModel](#powermodel)> | Promise对象。表示功率模式。 |  
    
## getPowerModel<sup>(deprecated)</sup>    
获取功率模式，使用callback异步回调。  
 **调用形式：**     
- getPowerModel(callback: AsyncCallback\<PowerModel>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManagerExt/wifiManagerExt.getPowerMode。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<PowerModel> | true | AsyncCallbacklt;[PowerModel](#powermodel)gt; | 是 | 回调函数。当操作成功时，err为0，data表示功率模式。如果error为非0，表示处理出现错误。 |  
    
## setPowerModel<sup>(deprecated)</sup>    
设置功率模式。  
 **调用形式：**     
- setPowerModel(model: PowerModel): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.wifiManagerExt/wifiManagerExt.setPowerMode。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| model<sup>(deprecated)</sup> | PowerModel | true | 功率模式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 操作结果， true: 成功， false: 失败。 |  
    
## PowerModel<sup>(deprecated)</sup>    
表示功率模式的枚举。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManagerExt/wifiManagerExt.PowerMode替代。    
    
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SLEEPING<sup>(deprecated)</sup> | 0 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManagerExt/wifiManagerExt.PowerMode替代。<br>睡眠模式。 |  
| GENERAL<sup>(deprecated)</sup> | 1 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManagerExt/wifiManagerExt.PowerMode替代。<br>常规模式。 |  
| THROUGH_WALL<sup>(deprecated)</sup> | 2 | 从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.wifiManagerExt/wifiManagerExt.PowerMode替代。<br>穿墙模式。 |  
