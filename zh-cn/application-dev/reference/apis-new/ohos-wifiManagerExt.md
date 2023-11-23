# @ohos.wifiManagerExt    
该模块主要提供WLAN扩展接口，供非通用类型产品使用。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import wifiManagerExt from '@ohos.wifiManagerExt'    
```  
    
## enableHotspot<sup>(deprecated)</sup>    
使能WLAN热点。  
 **调用形式：**     
- enableHotspot(): void  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2701000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManagerExt  from '@ohos.wifiManagerExt';  
  
        try {  
            wifiManagerExt.enableHotspot();  
        }catch(error){  
            console.error("failed:" + JSON.stringify(error));  
        }  
    
```    
  
    
## disableHotspot<sup>(deprecated)</sup>    
去使能WLAN热点。  
 **调用形式：**     
- disableHotspot(): void  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2701000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManagerExt  from '@ohos.wifiManagerExt';  
  
        try {  
            wifiManagerExt.disableHotspot();  
        }catch(error){  
            console.error("failed:" + JSON.stringify(error));  
        }  
    
```    
  
    
## getSupportedPowerMode    
获取支持的功率模式  
 **调用形式：**     
    
- getSupportedPowerMode(): Promise\<Array\<PowerMode>>    
起始版本： 9    
- getSupportedPowerMode(callback: AsyncCallback\<Array\<PowerMode>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当操作成功时，err为0，data表示支持的功率模式。如果error为非0，表示处理出现错误。 |  
| Promise<Array<PowerMode>> | Promise对象。表示功率模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2701000 | Operation failed. |  
    
 **示例代码1：**   
示例（Promise）:  
```ts    
import wifiManagerExt  from '@ohos.wifiManagerExt';  
        wifiManagerExt.getSupportedPowerMode((err, data) => {            if (err) {                console.error("get supported power mode info error");                return;            }            console.info("get supported power mode info: " + JSON.stringify(data));        });  
        wifiManagerExt.getSupportedPowerMode().then(data => {            console.info("get supported power mode info: " + JSON.stringify(data));        }).catch((error:number) => {            console.info("get supported power mode error");        });    
```    
  
    
 **示例代码2：**   
示例（<span style="letter-spacing: 0px;">callback</span><span style="letter-spacing: 0px;">）:</span>  
```ts    
import wifiManagerExt  from '@ohos.wifiManagerExt';  
        wifiManagerExt.getSupportedPowerMode((err, data) => {            if (err) {                console.error("get supported power mode info error");                return;            }            console.info("get supported power mode info: " + JSON.stringify(data));        });  
        wifiManagerExt.getSupportedPowerMode().then(data => {            console.info("get supported power mode info: " + JSON.stringify(data));        }).catch((error:number) => {            console.info("get supported power mode error");        });    
```    
  
    
## getPowerMode    
获取功率模式  
 **调用形式：**     
    
- getPowerMode(): Promise\<PowerMode>    
起始版本： 9    
- getPowerMode(callback: AsyncCallback\<PowerMode>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.GET_WIFI_INFO    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调函数。当操作成功时，err为0，data表示功率模式。如果error为非0，表示处理出现错误。 |  
| Promise<PowerMode> | Promise对象。表示功率模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2701000 | Operation failed. |  
    
 **示例代码1：**   
示例（Promise）:  
```ts    
import wifiManagerExt  from '@ohos.wifiManagerExt';  
  
        try {  
            let model = wifiManagerExt.getPowerMode();  
            console.info("model info:" + model);  
        }catch(error){  
            console.error("failed:" + JSON.stringify(error));  
        }  
    
```    
  
    
 **示例代码2：**   
示例（callback）:  
```ts    
import wifiManagerExt  from '@ohos.wifiManagerExt';  
        wifiManagerExt.getPowerMode((err, data) => {            if (err) {                console.error("get linked info error");                return;            }            console.info("get power mode info: " + JSON.stringify(data));        });  
        wifiManagerExt.getPowerMode().then(data => {            console.info("get power mode info: " + JSON.stringify(data));        }).catch((error:number) => {            console.info("get power mode error");        });    
```    
  
    
## setPowerMode<sup>(deprecated)</sup>    
 设置功率模式。  
 **调用形式：**     
- setPowerMode(mode: PowerMode): void  
  
 **废弃说明：** 从API version 10 开始废弃。  
 **系统能力:**  SystemCapability.Communication.WiFi.AP.Extension  
 **需要权限：** ohos.permission.MANAGE_WIFI_HOTSPOT_EXT    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mode<sup>(deprecated)</sup> | PowerMode | true | 功率模式。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 2701000 | Operation failed. |  
    
 **示例代码：**   
```ts    
import wifiManagerExt  from '@ohos.wifiManagerExt';  
  
        try {  
            let model = 0;  
            wifiManagerExt.setPowerMode(model);  
        }catch(error){  
            console.error("failed:" + JSON.stringify(error));  
        }  
    
```    
  
    
## PowerMode    
表示功率模式的枚举。    
    
 **系统能力:**  SystemCapability.Ability.AbilityRuntime.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| SLEEPING | 0 | 睡眠模式。 |  
| GENERAL | 1 | 常规模式。 |  
| THROUGH_WALL | 2 | 穿墙模式。 |  
