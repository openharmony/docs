# @ohos.geoLocationManager    
位置服务提供GNSS定位、网络定位、地理编码、逆地理编码、国家码和地理围栏等基本功能。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import geoLocationManager from '@ohos.geoLocationManager'    
```  
    
## on('locationChange')    
开启位置变化订阅，并发起定位请求。  
 **调用形式：**     
    
- on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“locationChange”，表示位置变化。 |  
| request | LocationRequest | true | 设置位置请求参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收位置变化状态变化监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301200 | Failed to obtain the geographical location. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};  
let locationChange = (location:geoLocationManager.Location):void => {  
    console.log('locationChanger: data: ' + JSON.stringify(location));  
};  
try {  
    geoLocationManager.on('locationChange', requestInfo, locationChange);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## off('locationChange')    
关闭位置变化订阅，并删除对应的定位请求。  
 **调用形式：**     
    
- off(type: 'locationChange', callback?: Callback\<Location>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“locationChange”，表示位置变化。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301200 | Failed to obtain the geographical location. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};  
let locationChange = (location:geoLocationManager.Location):void => {  
  console.log('locationChanger: data: ' + JSON.stringify(location));  
};  
try {  
    geoLocationManager.on('locationChange', requestInfo, locationChange);  
    geoLocationManager.off('locationChange', locationChange);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## on('locationEnabledChange')    
订阅位置服务状态变化。  
 **调用形式：**     
    
- on(type: 'locationEnabledChange', callback: Callback\<boolean>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“locationEnabledChange”，表示位置服务状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收位置服务状态变化监听。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let locationEnabledChange = (state:boolean):void => {  
    console.log('locationEnabledChange: ' + JSON.stringify(state));  
}  
try {  
    geoLocationManager.on('locationEnabledChange', locationEnabledChange);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## off('locationEnabledChange')    
取消订阅位置服务状态变化。  
 **调用形式：**     
    
- off(type: 'locationEnabledChange', callback?: Callback\<boolean>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“locationEnabledChange”，表示位置服务状态。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let locationEnabledChange = (state:boolean):void => {  
    console.log('locationEnabledChange: state: ' + JSON.stringify(state));  
}  
try {  
    geoLocationManager.on('locationEnabledChange', locationEnabledChange);  
    geoLocationManager.off('locationEnabledChange', locationEnabledChange);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## on('cachedGnssLocationsChange')    
订阅缓存GNSS定位结果上报事件。该接口功能由gnss定位芯片提供（仅部分型号支持），如果设备无此芯片或使用的芯片型号不支持该功能，则返回错误码801（Capability not supported）。  
 **调用形式：**     
    
- on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“cachedGnssLocationsChange”，表示GNSS缓存定位结果上报。 |  
| request | CachedGnssLocationsRequest | true | GNSS缓存功能配置参数 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收GNSS缓存位置上报。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301200 | Failed to obtain the geographical location. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let cachedLocationsCb = (locations:Array<geoLocationManager.Location>):void => {  
    console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));  
}  
let requestInfo:geoLocationManager.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};  
try {  
    geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## off('cachedGnssLocationsChange')    
取消订阅缓存GNSS定位结果上报事件。该接口功能由gnss定位芯片提供（仅部分型号支持），如果设备无此芯片或使用的芯片型号不支持该功能，则返回错误码801（Capability not supported）。  
 **调用形式：**     
    
- off(type: 'cachedGnssLocationsChange', callback?: Callback\<Array\<Location>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“cachedGnssLocationsChange”，表示GNSS缓存定位结果上报。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301200 | Failed to obtain the geographical location. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let cachedLocationsCb = (locations:Array<geoLocationManager.Location>):void => {  
    console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));  
}  
let requestInfo:geoLocationManager.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};  
try {  
    geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);  
    geoLocationManager.off('cachedGnssLocationsChange');  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## on('satelliteStatusChange')    
订阅GNSS卫星状态信息上报事件。  
 **调用形式：**     
    
- on(type: 'satelliteStatusChange', callback: Callback\<SatelliteStatusInfo>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“satelliteStatusChange”，表示订阅GNSS卫星状态信息上报。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收GNSS卫星状态信息上报。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let gnssStatusCb = (satelliteStatusInfo:geoLocationManager.SatelliteStatusInfo):void => {  
    console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));  
}  
  
try {  
    geoLocationManager.on('satelliteStatusChange', gnssStatusCb);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## off('satelliteStatusChange')    
取消订阅GNSS卫星状态信息上报事件。  
 **调用形式：**     
    
- off(type: 'satelliteStatusChange', callback?: Callback\<SatelliteStatusInfo>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“satelliteStatusChange”，表示订阅GNSS卫星状态信息上报。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let gnssStatusCb = (satelliteStatusInfo:geoLocationManager.SatelliteStatusInfo):void => {  
    console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));  
}  
try {  
    geoLocationManager.on('satelliteStatusChange', gnssStatusCb);  
    geoLocationManager.off('satelliteStatusChange', gnssStatusCb);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## on('nmeaMessage')    
订阅GNSS NMEA信息上报事件。  
 **调用形式：**     
    
- on(type: 'nmeaMessage', callback: Callback\<string>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“nmeaMessage”，表示订阅GNSSNMEA信息上报。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收GNSSNMEA信息上报。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let nmeaCb = (str:string):void => {  
    console.log('nmeaMessage: ' + JSON.stringify(str));  
}  
  
try {  
    geoLocationManager.on('nmeaMessage', nmeaCb );  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## off('nmeaMessage')    
取消订阅GNSS NMEA信息上报事件。  
 **调用形式：**     
    
- off(type: 'nmeaMessage', callback?: Callback\<string>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION and ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“nmeaMessage”，表示订阅GNSSNMEA信息上报。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let nmeaCb = (str:string):void => {  
    console.log('nmeaMessage: ' + JSON.stringify(str));  
}  
  
try {  
    geoLocationManager.on('nmeaMessage', nmeaCb);  
    geoLocationManager.off('nmeaMessage', nmeaCb);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## on('gnssFenceStatusChange')    
添加一个围栏，并订阅地理围栏事件。该接口功能由gnss定位芯片提供（仅部分型号支持），如果设备无此芯片或使用的芯片型号不支持该功能，则返回错误码801（Capability not supported）。  
 **调用形式：**     
- on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void  
  
 **系统能力:**  SystemCapability.Location.Location.Geofence  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“gnssFenceStatusChange”，表示订阅围栏事件上报。 |  
| request | GeofenceRequest | true | 围栏的配置参数。 |  
| want | WantAgent | true | 用于接收地理围栏事件上报（进出围栏）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301600 | Failed to operate the geofence. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import wantAgent from '@ohos.app.ability.wantAgent';  
import BusinessError from "@ohos.base";  
  
let wantAgentInfo:wantAgent.WantAgentInfo = {  
    wants: [  
        {  
            bundleName: "com.example.myapplication",  
            abilityName: "EntryAbility",  
            action: "action1"  
        }  
    ],  
    operationType: wantAgent.OperationType.START_ABILITY,  
    requestCode: 0,  
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
};  
  
wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {  
  let requestInfo:geoLocationManager.GeofenceRequest = {'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};  
  try {  
      geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);  
  } catch (err) {  
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
  }  
});  
    
```    
  
    
## off('gnssFenceStatusChange')    
删除一个围栏，并取消订阅该围栏事件。该接口功能由gnss定位芯片提供（仅部分型号支持），如果设备无此芯片或使用的芯片型号不支持该功能，则返回错误码801（Capability not supported）。  
 **调用形式：**     
- off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void  
  
 **系统能力:**  SystemCapability.Location.Location.Geofence  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“gnssFenceStatusChange”，表示订阅围栏事件上报。 |  
| request | GeofenceRequest | true | 围栏的配置参数。 |  
| want | WantAgent | true | 用于接收地理围栏事件上报（进出围栏）。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301600 | Failed to operate the geofence. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import wantAgent from '@ohos.app.ability.wantAgent';  
import BusinessError from "@ohos.base";  
  
let wantAgentInfo:wantAgent.WantAgentInfo = {  
    wants: [  
        {  
            bundleName: "com.example.myapplication",  
            abilityName: "EntryAbility",  
            action: "action1",  
        }  
    ],  
    operationType: wantAgent.OperationType.START_ABILITY,  
    requestCode: 0,  
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]  
};  
  
wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {  
  let requestInfo:geoLocationManager.GeofenceRequest = {'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};;  
  try {  
      geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);  
      geoLocationManager.off('gnssFenceStatusChange', requestInfo, wantAgentObj);  
  } catch (err) {  
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
  }  
});  
    
```    
  
    
## on('countryCodeChange')    
订阅国家码信息变化事件。  
 **调用形式：**     
    
- on(type: 'countryCodeChange', callback: Callback\<CountryCode>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“countryCodeChange”，表示订阅国家码信息变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301500 | Failed to query the area information. |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let callback = (code:geoLocationManager.CountryCode):void => {  
    console.log('countryCodeChange: ' + JSON.stringify(code));  
}  
  
try {  
    geoLocationManager.on('countryCodeChange', callback);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## off('countryCodeChange')    
取消订阅国家码变化事件。  
 **调用形式：**     
    
- off(type: 'countryCodeChange', callback?: Callback\<CountryCode>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | 设置事件类型。type为“countryCodeChange”，表示取消订阅国家码信息变化事件。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301500 |  |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let callback = (code:geoLocationManager.CountryCode):void => {  
    console.log('countryCodeChange: ' + JSON.stringify(code));  
}  
  
try {  
    geoLocationManager.on('countryCodeChange', callback);  
    geoLocationManager.off('countryCodeChange', callback);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## getCurrentLocation    
获取当前位置。  
 **调用形式：**     
    
- getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>): void    
起始版本： 9    
- getCurrentLocation(callback: AsyncCallback\<Location>): void    
起始版本： 9    
- getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | CurrentLocationRequest | true | 设置位置请求参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 用来接收位置信息的回调。 |  
| Promise<Location> | 返回位置信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301200 | Failed to obtain the geographical location. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};  
let locationChange = (err:BusinessError.BusinessError, location:geoLocationManager.Location):void => {  
    if (err) {  
        console.log('locationChanger: err=' + JSON.stringify(err));  
    }  
    if (location) {  
        console.log('locationChanger: location=' + JSON.stringify(location));  
    }  
};  
  
try {  
    geoLocationManager.getCurrentLocation(requestInfo, locationChange);  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET,'maxAccuracy': 0};  
try {  
    geoLocationManager.getCurrentLocation(requestInfo).then((result) => {  
        console.log('current location: ' + JSON.stringify(result));  
    })    
    .catch((error:number) => {  
        console.log('promise, getCurrentLocation: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## getLastLocation    
获取上一次位置。  
 **调用形式：**     
- getLastLocation(): Location  
  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Location | 位置信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301200 | Failed to obtain the geographical location. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    let location = geoLocationManager.getLastLocation();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## isLocationEnabled    
判断位置服务是否已经使能。  
 **调用形式：**     
- isLocationEnabled(): boolean  
  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 位置服务是否已经使能。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    let locationEnabled = geoLocationManager.isLocationEnabled();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## getAddressesFromLocation    
调用逆地理编码服务，将坐标转换为地理描述。  
 **调用形式：**     
    
- getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void    
起始版本： 9    
- getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | ReverseGeoCodeRequest | true | 设置逆地理编码请求的相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收逆地理编码结果的回调函数。 |  
| Promise<Array<GeoAddress>> | 返回地理描述信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301300 | Reverse geocoding query failed. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};  
try {  
    geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {  
        if (err) {  
            console.log('getAddressesFromLocation: err=' + JSON.stringify(err));  
        }  
        if (data) {  
            console.log('getAddressesFromLocation: data=' + JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};  
try {  
    geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {  
        console.log('getAddressesFromLocation: ' + JSON.stringify(data));  
    })  
    .catch((error:number) => {  
        console.log('promise, getAddressesFromLocation: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## getAddressesFromLocationName    
调用地理编码服务，将地理描述转换为具体坐标。  
 **调用形式：**     
    
- getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void    
起始版本： 9    
- getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request | GeoCodeRequest | true | 设置地理编码请求的相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收地理编码结果的回调函数。 |  
| Promise<Array<GeoAddress>> | 返回地理编码查询结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301400 | Geocoding query failed. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};  
try {  
    geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {  
        if (err) {  
            console.log('getAddressesFromLocationName: err=' + JSON.stringify(err));  
        }  
        if (data) {  
            console.log('getAddressesFromLocationName: data=' + JSON.stringify(data));  
        }  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};  
try {  
    geoLocationManager.getAddressesFromLocationName(geocodeRequest).then((result) => {  
        console.log('getAddressesFromLocationName: ' + JSON.stringify(result));  
    })  
    .catch((error:number) => {  
        console.log('promise, getAddressesFromLocationName: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## isGeocoderAvailable    
判断（逆）地理编码服务状态。  
 **调用形式：**     
- isGeocoderAvailable(): boolean  
  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回（逆）地理编码服务是否可用。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码：**   
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    let isAvailable = geoLocationManager.isGeocoderAvailable();  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## getCachedGnssLocationsSize    
获取GNSS芯片缓存位置的个数。该接口功能由gnss定位芯片提供（仅部分型号支持），如果设备无此芯片或使用的芯片型号不支持该功能，则返回错误码801（Capability not supported）。  
 **调用形式：**     
    
- getCachedGnssLocationsSize(callback: AsyncCallback\<number>): void    
起始版本： 9    
- getCachedGnssLocationsSize(): Promise\<number>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 用来接收GNSS芯片缓存位置个数的回调。 |  
| Promise<number> | 返回GNSS缓存位置的个数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.getCachedGnssLocationsSize((err, size) => {  
        if (err) {  
            console.log('getCachedGnssLocationsSize: err=' + JSON.stringify(err));  
        }  
        if (size) {  
            console.log('getCachedGnssLocationsSize: size=' + JSON.stringify(size));  
        }  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.getCachedGnssLocationsSize().then((result) => {  
        console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));  
    })   
    .catch((error:number) => {  
        console.log('promise, getCachedGnssLocationsSize: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## flushCachedGnssLocations    
读取并清空GNSS芯片所有缓存位置。该接口功能由gnss定位芯片提供（仅部分型号支持），如果设备无此芯片或使用的芯片型号不支持该功能，则返回错误码801（Capability not supported）。  
 **调用形式：**     
    
- flushCachedGnssLocations(callback: AsyncCallback\<void>): void    
起始版本： 9    
- flushCachedGnssLocations(): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.APPROXIMATELY_LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 用来接收错误码信息。 |  
| Promise<void> | 接收错误码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301100 | The location switch is off. |  
| 3301200 | Failed to obtain the geographical location. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.flushCachedGnssLocations((err, result) => {  
        if (err) {  
            console.log('flushCachedGnssLocations: err=' + JSON.stringify(err));  
        }  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.flushCachedGnssLocations().then((result) => {  
        console.log('promise, flushCachedGnssLocations success');  
    })  
    .catch((error:number) => {  
        console.log('promise, flushCachedGnssLocations: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## sendCommand    
给位置服务子系统的各个部件发送扩展命令。  
 **调用形式：**     
    
- sendCommand(command: LocationCommand, callback: AsyncCallback\<void>): void    
起始版本： 9    
- sendCommand(command: LocationCommand): Promise\<void>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command | LocationCommand | true | 指定目标场景，和将要发送的命令（字符串）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 用来接收错误码。 |  
| Promise<void> | 接收错误码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let requestInfo:geoLocationManager.LocationCommand = {'scenario': 0x301, 'command': "command_1"};  
try {  
    geoLocationManager.sendCommand(requestInfo, (err, result) => {  
        if (err) {  
            console.log('sendCommand: err=' + JSON.stringify(err));  
        }  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
let requestInfo:geoLocationManager.LocationCommand = {'scenario': 0x301, 'command': "command_1"};  
try {  
    geoLocationManager.sendCommand(requestInfo).then((result) => {  
        console.log('promise, sendCommand success');  
    })    
    .catch((error:number) => {  
        console.log('promise, sendCommand: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## getCountryCode    
查询当前的国家码。  
 **调用形式：**     
    
- getCountryCode(callback: AsyncCallback\<CountryCode>): void    
起始版本： 9    
- getCountryCode(): Promise\<CountryCode>    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Location.Location.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 用来接收国家码。 |  
| Promise<CountryCode> | 用来接收国家码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3301000 | Location service is unavailable. |  
| 3301500 | Failed to query the area information. |  
    
 **示例代码1：**   
示例（callback）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.getCountryCode((err, result) => {  
        if (err) {  
            console.log('getCountryCode: err=' + JSON.stringify(err));  
        }  
        if (result) {  
            console.log('getCountryCode: result=' + JSON.stringify(result));  
        }  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）：  
```ts    
import geoLocationManager from '@ohos.geoLocationManager';  
import BusinessError from "@ohos.base";  
try {  
    geoLocationManager.getCountryCode()  
    .then((result) => {  
        console.log('promise, getCountryCode: result=' + JSON.stringify(result));  
    })  
    .catch((error:number) => {  
        console.log('promise, getCountryCode: error=' + JSON.stringify(error));  
    });  
} catch (err) {  
    console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);  
}  
    
```    
  
    
## SatelliteStatusInfo    
卫星状态信息。  
 **系统能力:**  SystemCapability.Location.Location.Gnss    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Gnss    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| satellitesNumber | number | false | true | 表示卫星个数。取值范围为大于等于0。 |  
| satelliteIds | Array<number> | false | true | 表示每个卫星的ID，数组类型。取值范围为大于等于0。 |  
| carrierToNoiseDensitys | Array<number> | false | true | 表示载波噪声功率谱密度比，即cn0。取值范围为大于0。 |  
| altitudes | Array<number> | false | true | 表示卫星高度角信息。单位是“度”，取值范围为-90到90。 |  
| azimuths | Array<number> | false | true | 表示方位角。单位是“度”，取值范围为0到360。 |  
| carrierFrequencies | Array<number> | false | true | 表示载波频率。单位是Hz，取值范围为大于等于0。 |  
    
## CachedGnssLocationsRequest    
请求订阅GNSS缓存位置上报功能接口的配置参数。  
 **系统能力:**  SystemCapability.Location.Location.Gnss    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Gnss    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| reportingPeriodSec | number | false | true | 表示GNSS缓存位置上报的周期，单位是毫秒。取值范围为大于0。 |  
| wakeUpCacheQueueFull | boolean | false | true | true表示GNSS芯片底层缓存队列满之后会主动唤醒AP芯片，并把缓存位置上报给应用。 |  
    
## GeofenceRequest    
请求添加GNSS围栏消息中携带的参数，包括定位优先级、定位场景和围栏信息。  
 **系统能力:**  SystemCapability.Location.Location.Geofence    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Geofence    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scenario | LocationRequestScenario | false | true | 表示定位场景。 |  
| geofence | Geofence | false | true | 表示围栏信息。 |  
    
## Geofence    
GNSS围栏的配置参数。目前只支持圆形围栏。  
 **系统能力:**  SystemCapability.Location.Location.Geofence    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Geofence    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude | number | false | true | 表示纬度。取值范围为-90到90。 |  
| longitude | number | false | true | 表示经度。取值范围为-180到180。 |  
| radius | number | false | true | 表示圆形围栏的半径。单位是米，取值范围为大于0。 |  
| expiration | number | false | true | 围栏存活的时间，单位是毫秒。取值范围为大于0。 |  
    
## ReverseGeoCodeRequest    
逆地理编码请求接口。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale | string | false | false | 指定位置描述信息的语言，“zh”代表中文，“en”代表英文。 |  
| latitude | number | false | true | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |  
| longitude | number | false | true | 表示经度信息，正值表示东经，负值表示西经。取值范围为-180到180。 |  
| maxItems | number | false | false | 指定返回位置信息的最大个数。取值范围为大于等于0，推荐该值小于10。 |  
    
## GeoCodeRequest    
地理编码请求接口。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale | string | false | false | 表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |  
| description | string | false | true | 表示位置信息描述，如“上海市浦东新区xx路xx号”。 |  
| maxItems | number | false | false | 表示返回位置信息的最大个数。取值范围为大于等于0，推荐该值小于10。 |  
| minLatitude | number | false | false | 表示最小纬度信息，与下面三个参数一起，表示一个经纬度范围。取值范围为-90到90。 |  
| minLongitude | number | false | false | 表示最小经度信息。取值范围为-180到180。 |  
| maxLatitude | number | false | false | 表示最大纬度信息。取值范围为-90到90。 |  
| maxLongitude | number | false | false | 表示最大经度信息。取值范围为-180到180。 |  
    
## GeoAddress    
地理编码类型。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude | number | false | false | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |  
| longitude | number | false | false | 表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。 |  
| locale | string | false | false | 表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |  
| placeName | string | false | false | 表示地区信息。 |  
| countryCode | string | false | false | 表示国家码信息。 |  
| countryName | string | false | false | 表示国家信息。 |  
| administrativeArea | string | false | false | 表示省份区域信息。 |  
| subAdministrativeArea | string | false | false | 表示子区域信息。 |  
| locality | string | false | false | 表示城市信息。 |  
| subLocality | string | false | false | 表示子城市信息。 |  
| roadName | string | false | false | 表示路名信息。 |  
| subRoadName | string | false | false | 表示子路名信息。 |  
| premises | string | false | false | 表示门牌号信息。 |  
| postalCode | string | false | false | 表示邮政编码信息。 |  
| phoneNumber | string | false | false | 表示联系方式信息。 |  
| addressUrl | string | false | false | 表示位置信息附件的网址信息。 |  
| descriptions | Array<string> | false | false | 表示附加的描述信息。 |  
| descriptionsSize | number | false | false | 表示附加的描述信息数量。取值范围为大于等于0，推荐该值小于10。 |  
    
## LocationRequest    
位置信息请求类型。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| priority | LocationRequestPriority | false | false | 表示优先级信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestPriority](#locationrequestpriority)的定义。 |  
| scenario | LocationRequestScenario | false | false | 表示场景信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestScenario](#locationrequestscenario)的定义。 |  
| timeInterval | number | false | false | 表示上报位置信息的时间间隔，单位是秒。默认值为1，取值范围为大于等于0。 |  
| distanceInterval | number | false | false | 表示上报位置信息的距离间隔。单位是米，默认值为0，取值范围为大于等于0。 |  
| maxAccuracy | number | false | false | 表示精度信息，单位是米。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。默认值为0，取值范围为大于等于0。 |  
    
## CurrentLocationRequest    
当前位置信息请求类型。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| priority | LocationRequestPriority | false | false | 表示优先级信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestPriority](#locationrequestpriority)的定义。 |  
| scenario | LocationRequestScenario | false | false | 表示场景信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestScenario](#locationrequestscenario)的定义。 |  
| maxAccuracy | number | false | false | 表示精度信息，单位是米。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。默认值为0，取值范围为大于等于0。 |  
| timeoutMs | number | false | false | 表示超时时间，单位是毫秒，最小为1000毫秒。取值范围为大于等于1000。 |  
    
## Location    
位置信息类型。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude | number | false | true | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |  
| longitude | number | false | true | 表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。 |  
| altitude | number | false | true | 表示高度信息，单位米。 |  
| accuracy | number | false | true |  |  
| speed | number | false | true | 表示速度信息，单位米每秒。 |  
| timeStamp | number | false | true | 表示位置时间戳，UTC格式。 |  
| direction | number | false | true | 表示航向信息。单位是“度”，取值范围为0到360。 |  
| timeSinceBoot | number | false | true | 表示位置时间戳，开机时间格式。 |  
| additions | Array<string> | false | false | 附加信息。 |  
| additionSize | number | false | false | 附加信息数量。取值范围为大于等于0。 |  
    
## LocationRequestPriority    
位置请求中位置信息优先级设置。    
    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSET | 0x200 |  |  
| ACCURACY | 513 | 定位精度优先策略主要以GNSS定位技术为主，在开阔场景下可以提供米级的定位精度，具体性能指标依赖用户设备的定位硬件能力，但在室内等强遮蔽定位场景下，无法提供准确的位置服务。 |  
| LOW_POWER | 514 | 低功耗定位优先策略主要使用基站定位和WLAN、蓝牙定位技术，也可以同时提供室内和户外场景下的位置服务，因为其依赖周边基站、可见WLAN、蓝牙设备的分布情况，定位结果的精度波动范围较大，如果对定位结果精度要求不高，或者使用场景多在有基站、可见WLAN、蓝牙设备高密度分布的情况下，推荐使用，可以有效节省设备功耗。 |  
| FIRST_FIX | 515 | 快速定位优先策略会同时使用GNSS定位、基站定位和WLAN、蓝牙定位技术，以便室内和户外场景下，通过此策略都可以获得位置结果，当各种定位技术都有提供位置结果时，系统会选择其中精度较好的结果返回给应用。因为对各种定位技术同时使用，对设备的硬件资源消耗较大，功耗也较大。 |  
    
## LocationRequestScenario    
位置请求中定位场景设置。    
    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSET | 0x300 | 表示未设置场景信息。<br/>表示[LocationRequestScenario](#locationrequestscenario)字段无效。 |  
| NAVIGATION | 769 | 表示导航场景。<br/>适用于在户外定位设备实时位置的场景，如车载、步行导航。<br/>在此场景下，为保证系统提供位置结果精度最优，主要使用GNSS定位技术提供定位服务<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| TRAJECTORY_TRACKING | 770 | 表示运动轨迹记录场景。<br/>适用于记录用户位置轨迹的场景，如运动类应用记录轨迹功能。主要使用GNSS定位技术提供定位服务。<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| CAR_HAILING | 771 | 表示打车场景。<br/>适用于用户出行打车时定位当前位置的场景，如网约车类应用。<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| DAILY_LIFE_SERVICE | 772 | 表示日常服务使用场景。<br/>适用于不需要定位用户精确位置的使用场景，如新闻资讯、网购、点餐类应用，做推荐、推送时定位用户大致位置即可。<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| NO_POWER | 773 | 表示无功耗功场景，这种场景下不会主动触发定位，会在其他应用定位时，才给当前应用返回位置。 |  
    
## LocationCommand    
扩展命令结构体。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scenario | LocationRequestScenario | false | true | 表示定位场景。 |  
| command | string | false | true | 扩展命令字符串。 |  
    
## CountryCode    
国家码信息结构体，包含国家码字符串和国家码的来源信息。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| country | string | false | true | 表示国家码字符串。 |  
| type | CountryCodeType | false | true | 表示国家码信息来源。 |  
    
## CountryCodeType    
国家码来源类型。    
    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| COUNTRY_CODE_FROM_LOCALE | 1 | 从全球化模块的语言配置信息中获取到的国家码。 |  
| COUNTRY_CODE_FROM_SIM | 2 | 从SIM卡中获取到的国家码。 |  
| COUNTRY_CODE_FROM_LOCATION | 3 | 基于用户的位置信息，通过逆地理编码查询到的国家码。 |  
| COUNTRY_CODE_FROM_NETWORK | 4 | 从蜂窝网络注册信息中获取到的国家码。 |  
