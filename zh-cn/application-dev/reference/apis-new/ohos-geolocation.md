# @ohos.geolocation    
位置服务提供GNSS定位、网络定位、地理编码、逆地理编码、国家码和地理围栏等基本功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import geolocation from '@ohos.geolocation'    
```  
    
## on('locationChange')<sup>(deprecated)</sup>    
开启位置变化订阅，并发起定位请求。  
 **调用形式：**     
- on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.on#event:locationChange。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“locationChange”，表示位置变化。 |  
| request<sup>(deprecated)</sup> | LocationRequest | true | [LocationRequest](#locationrequestdeprecated) | 是 | 设置位置请求参数。 |  
| callback<sup>(deprecated)</sup> | Callback<Location> | true | 接收位置变化状态变化监听。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let requestInfo:geolocation.LocationRequest = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};  
let locationChange = (location:geolocation.Location):void => {  
    console.log('locationChanger: data: ' + JSON.stringify(location));  
};  
geolocation.on('locationChange', requestInfo, locationChange);    
```    
  
    
## off('locationChange')<sup>(deprecated)</sup>    
关闭位置变化订阅，并删除对应的定位请求。  
 **调用形式：**     
- off(type: 'locationChange', callback?: Callback\<Location>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.off#event:locationChange。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“locationChange”，表示位置变化。 |  
| callback<sup>(deprecated)</sup> | Callback<Location> | false | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let requestInfo:geolocation.LocationRequest = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};  
let locationChange = (location:geolocation.Location):void => {  
    console.log('locationChanger: data: ' + JSON.stringify(location));  
};  
geolocation.on('locationChange', requestInfo, locationChange);  
geolocation.off('locationChange', locationChange);    
```    
  
    
## on('locationServiceState')<sup>(deprecated)</sup>    
订阅位置服务状态变化。  
 **调用形式：**     
- on(type: 'locationServiceState', callback: Callback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.on#event:locationEnabledChange。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“locationServiceState”，表示位置服务状态。 |  
| callback<sup>(deprecated)</sup> | Callback<boolean> | true | 接收位置服务状态变化监听。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let locationServiceState = (state:boolean):void => {  
    console.log('locationServiceState: ' + JSON.stringify(state));  
}  
geolocation.on('locationServiceState', locationServiceState);    
```    
  
    
## off('locationServiceState')<sup>(deprecated)</sup>    
取消订阅位置服务状态变化。  
 **调用形式：**     
- off(type: 'locationServiceState', callback?: Callback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.off#event:locationEnabledChange。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“locationServiceState”，表示位置服务状态。 |  
| callback<sup>(deprecated)</sup> | Callback<boolean> | false | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let locationServiceState = (state:boolean):void => {  
    console.log('locationServiceState: state: ' + JSON.stringify(state));  
}  
geolocation.on('locationServiceState', locationServiceState);  
geolocation.off('locationServiceState', locationServiceState);    
```    
  
    
## on('cachedGnssLocationsReporting')<sup>(deprecated)</sup>    
订阅缓存GNSS定位结果上报事件。  
 **调用形式：**     
- on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.on#event:cachedGnssLocationsChange。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“cachedGnssLocationsReporting”，表示GNSS缓存定位结果上报。 |  
| request<sup>(deprecated)</sup> | CachedGnssLocationsRequest | true | [CachedGnssLocationsRequest](#cachedgnsslocationsrequestdeprecated) | 是 | GNSS缓存功能配置参数 |  
| callback<sup>(deprecated)</sup> | Callback<Array<Location>> | true | 接收GNSS缓存位置上报。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let cachedLocationsCb = (locations:Array<geolocation.Location>):void => {  
    console.log('cachedGnssLocationsReporting: locations: ' + JSON.stringify(locations));  
}  
let requestInfo:geolocation.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};  
geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);    
```    
  
    
## off('cachedGnssLocationsReporting')<sup>(deprecated)</sup>    
取消订阅缓存GNSS定位结果上报事件。  
 **调用形式：**     
- off(type: 'cachedGnssLocationsReporting', callback?: Callback\<Array\<Location>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.off#event:cachedGnssLocationsChange。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“cachedGnssLocationsReporting”，表示GNSS缓存定位结果上报。 |  
| callback<sup>(deprecated)</sup> | Callback<Array<Location>> | false | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let cachedLocationsCb = (locations:Array<geolocation.Location>):void => {  
    console.log('cachedGnssLocationsReporting: locations: ' + JSON.stringify(locations));  
}  
let requestInfo:geolocation.CachedGnssLocationsRequest = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};  
geolocation.on('cachedGnssLocationsReporting', requestInfo, cachedLocationsCb);  
geolocation.off('cachedGnssLocationsReporting');    
```    
  
    
## on('gnssStatusChange')<sup>(deprecated)</sup>    
订阅GNSS卫星状态信息上报事件。  
 **调用形式：**     
- on(type: 'gnssStatusChange', callback: Callback\<SatelliteStatusInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.on#event:satelliteStatusChange。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“gnssStatusChange”，表示订阅GNSS卫星状态信息上报。 |  
| callback<sup>(deprecated)</sup> | Callback<SatelliteStatusInfo> | true | 接收GNSS卫星状态信息上报。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let gnssStatusCb = (satelliteStatusInfo:geolocation.SatelliteStatusInfo):void => {  
    console.log('gnssStatusChange: ' + JSON.stringify(satelliteStatusInfo));  
}  
geolocation.on('gnssStatusChange', gnssStatusCb);    
```    
  
    
## off('gnssStatusChange')<sup>(deprecated)</sup>    
取消订阅GNSS卫星状态信息上报事件。  
 **调用形式：**     
- off(type: 'gnssStatusChange', callback?: Callback\<SatelliteStatusInfo>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.off#event:satelliteStatusChange。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“gnssStatusChange”，表示订阅GNSS卫星状态信息上报。 |  
| callback<sup>(deprecated)</sup> | Callback<SatelliteStatusInfo> | false | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let gnssStatusCb = (satelliteStatusInfo:geolocation.SatelliteStatusInfo) => {  
    console.log('gnssStatusChange: ' + JSON.stringify(satelliteStatusInfo));  
}  
geolocation.on('gnssStatusChange', gnssStatusCb);  
geolocation.off('gnssStatusChange', gnssStatusCb);    
```    
  
    
## on('nmeaMessageChange')<sup>(deprecated)</sup>    
订阅GNSS NMEA信息上报事件。  
 **调用形式：**     
- on(type: 'nmeaMessageChange', callback: Callback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.on#event:nmeaMessage。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“nmeaMessageChange”，表示订阅GNSSNMEA信息上报。 |  
| callback<sup>(deprecated)</sup> | Callback<string> | true | 接收GNSSNMEA信息上报。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let nmeaCb = (str:string):void => {  
    console.log('nmeaMessageChange: ' + JSON.stringify(str));  
}  
geolocation.on('nmeaMessageChange', nmeaCb );    
```    
  
    
## off('nmeaMessageChange')<sup>(deprecated)</sup>    
取消订阅GNSS NMEA信息上报事件。  
 **调用形式：**     
- off(type: 'nmeaMessageChange', callback?: Callback\<string>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.off#event:nmeaMessage。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“nmeaMessageChange”，表示订阅GNSSNMEA信息上报。 |  
| callback<sup>(deprecated)</sup> | Callback<string> | false | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let nmeaCb = (str:string):void => {  
    console.log('nmeaMessageChange: ' + JSON.stringify(str));  
}  
geolocation.on('nmeaMessageChange', nmeaCb);  
geolocation.off('nmeaMessageChange', nmeaCb);    
```    
  
    
## on('fenceStatusChange')<sup>(deprecated)</sup>    
添加一个围栏，并订阅地理围栏事件。  
 **调用形式：**     
- on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.on#event:gnssFenceStatusChange。  
 **系统能力:**  SystemCapability.Location.Location.Geofence  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“fenceStatusChange”，表示订阅围栏事件上报。 |  
| request<sup>(deprecated)</sup> | GeofenceRequest | true | 围栏的配置参数。 |  
| want<sup>(deprecated)</sup> | WantAgent | true | 用于接收地理围栏事件上报（进出围栏）。 |  
    
 **示例代码：**   
```ts    
import geolocation from '@ohos.geolocation';  
import wantAgent from '@ohos.app.ability.wantAgent';  
  
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
    wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],  
};  
  
wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {  
  let requestInfo:geolocation.GeofenceRequest = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};  
  geolocation.on('fenceStatusChange', requestInfo, wantAgentObj);  
});    
```    
  
    
## off('fenceStatusChange')<sup>(deprecated)</sup>    
删除一个围栏，并取消订阅该围栏事件。  
 **调用形式：**     
- off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.off#event:gnssFenceStatusChange。  
 **系统能力:**  SystemCapability.Location.Location.Geofence  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type<sup>(deprecated)</sup> | string | true | 设置事件类型。type为“fenceStatusChange”，表示订阅围栏事件上报。 |  
| request<sup>(deprecated)</sup> | GeofenceRequest | true | 围栏的配置参数。 |  
| want<sup>(deprecated)</sup> | WantAgent | true | 用于接收地理围栏事件上报（进出围栏）。 |  
    
 **示例代码：**   
```ts    
import geolocation from '@ohos.geolocation';  
import wantAgent from '@ohos.app.ability.wantAgent';  
  
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
  let requestInfo:geolocation.GeofenceRequest = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};  
  geolocation.on('fenceStatusChange', requestInfo, wantAgentObj);  
  geolocation.off('fenceStatusChange', requestInfo, wantAgentObj);  
});    
```    
  
    
## getCurrentLocation<sup>(deprecated)</sup>    
获取当前位置，使用callback回调异步返回结果。  
 **调用形式：**     
- getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getCurrentLocation。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | CurrentLocationRequest | true | 设置位置请求参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Location> | true | 用来接收位置信息的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
import BusinessError from "@ohos.base"  
let requestInfo:geolocation.CurrentLocationRequest = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};  
let locationChange = (err:BusinessError.BusinessError, location:geolocation.Location) => {  
    if (err) {  
        console.log('locationChanger: err=' + JSON.stringify(err));  
    }  
    if (location) {  
        console.log('locationChanger: location=' + JSON.stringify(location));  
    }  
};  
geolocation.getCurrentLocation(requestInfo, locationChange);    
```    
  
    
## getCurrentLocation<sup>(deprecated)</sup>    
获取当前位置，使用callback回调异步返回结果。  
 **调用形式：**     
- getCurrentLocation(callback: AsyncCallback\<Location>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getCurrentLocation。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Location> | true | 用来接收位置信息的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
import BusinessError from "@ohos.base"  
let locationChange = (err:BusinessError.BusinessError, location:geolocation.Location):void => {  
    if (err) {  
        console.log('locationChanger: err=' + JSON.stringify(err));  
    }  
    if (location) {  
        console.log('locationChanger: location=' + JSON.stringify(location));  
    }  
};  
geolocation.getCurrentLocation(locationChange);    
```    
  
    
## getCurrentLocation<sup>(deprecated)</sup>    
获取当前位置，使用Promise方式异步返回结果。  
 **调用形式：**     
- getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getCurrentLocation。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | CurrentLocationRequest | false | 设置位置请求参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Location> | 返回位置信息。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
let requestInfo:geolocation.CurrentLocationRequest = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};  
geolocation.getCurrentLocation(requestInfo).then((result) => {  
    console.log('current location: ' + JSON.stringify(result));  
});    
```    
  
    
## getLastLocation<sup>(deprecated)</sup>    
获取上一次位置，使用callback回调异步返回结果。  
 **调用形式：**     
- getLastLocation(callback: AsyncCallback\<Location>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getLastLocation。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<Location> | true | 用来接收上次位置的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.getLastLocation((err, data) => {  
    if (err) {  
        console.log('getLastLocation: err=' + JSON.stringify(err));  
    }  
    if (data) {  
        console.log('getLastLocation: data=' + JSON.stringify(data));  
    }  
});    
```    
  
    
## getLastLocation<sup>(deprecated)</sup>    
获取上一次位置，使用Promise方式异步返回结果。  
 **调用形式：**     
- getLastLocation(): Promise\<Location>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getLastLocation。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Location> | 返回上次位置信息。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.getLastLocation().then((result) => {  
    console.log('getLastLocation: result: ' + JSON.stringify(result));  
});    
```    
  
    
## isLocationEnabled<sup>(deprecated)</sup>    
判断位置服务是否已经打开，使用callback回调异步返回结果。  
 **调用形式：**     
- isLocationEnabled(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.isLocationEnabled。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 用来接收位置服务状态的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.isLocationEnabled((err, data) => {  
    if (err) {  
        console.log('isLocationEnabled: err=' + JSON.stringify(err));  
    }  
    if (data) {  
        console.log('isLocationEnabled: data=' + JSON.stringify(data));  
    }  
});    
```    
  
    
## isLocationEnabled<sup>(deprecated)</sup>    
判断位置服务是否已经开启，使用Promise方式异步返回结果。  
 **调用形式：**     
- isLocationEnabled(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.isLocationEnabled。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 返回位置服务是否可用的状态。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.isLocationEnabled().then((result) => {  
    console.log('promise, isLocationEnabled: ' + JSON.stringify(result));  
});    
```    
  
    
## requestEnableLocation<sup>(deprecated)</sup>    
请求打开位置服务，使用callback回调异步返回结果。  
 **调用形式：**     
- requestEnableLocation(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 用来接收位置服务状态的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.requestEnableLocation((err, data) => {  
    if (err) {  
        console.log('requestEnableLocation: err=' + JSON.stringify(err));  
    }  
    if (data) {  
        console.log('requestEnableLocation: data=' + JSON.stringify(data));  
    }  
});    
```    
  
    
## requestEnableLocation<sup>(deprecated)</sup>    
请求打开位置服务，使用Promise方式异步返回结果。  
 **调用形式：**     
- requestEnableLocation(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 返回位置服务是否可用。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.requestEnableLocation().then((result) => {  
    console.log('promise, requestEnableLocation: ' + JSON.stringify(result));  
});    
```    
  
    
## getAddressesFromLocation<sup>(deprecated)</sup>    
调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。  
 **调用形式：**     
- getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getAddressesFromLocation。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | ReverseGeoCodeRequest | true | 设置逆地理编码请求的相关参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<GeoAddress>> | true | 设置接收逆地理编码请求的回调参数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let reverseGeocodeRequest:geolocation.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};  
geolocation.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {  
    if (err) {  
        console.log('getAddressesFromLocation: err=' + JSON.stringify(err));  
    }  
    if (data) {  
        console.log('getAddressesFromLocation: data=' + JSON.stringify(data));  
    }  
});    
```    
  
    
## getAddressesFromLocation<sup>(deprecated)</sup>    
调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。  
 **调用形式：**     
- getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getAddressesFromLocation。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | ReverseGeoCodeRequest | true | 设置逆地理编码请求的相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<GeoAddress>> | 返回地理描述信息。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
let reverseGeocodeRequest:geolocation.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};  
geolocation.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {  
    console.log('getAddressesFromLocation: ' + JSON.stringify(data));  
});    
```    
  
    
## getAddressesFromLocationName<sup>(deprecated)</sup>    
调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。  
 **调用形式：**     
- getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getAddressesFromLocationName。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | GeoCodeRequest | true | 设置地理编码请求的相关参数。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<Array<GeoAddress>> | true | 设置接收地理编码请求的回调参数。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let geocodeRequest:geolocation.GeoCodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};  
geolocation.getAddressesFromLocationName(geocodeRequest, (err, data) => {  
    if (err) {  
        console.log('getAddressesFromLocationName: err=' + JSON.stringify(err));  
    }  
    if (data) {  
        console.log('getAddressesFromLocationName: data=' + JSON.stringify(data));  
    }  
});    
```    
  
    
## getAddressesFromLocationName<sup>(deprecated)</sup>    
调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。  
 **调用形式：**     
- getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getAddressesFromLocationName。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| request<sup>(deprecated)</sup> | GeoCodeRequest | true | 设置地理编码请求的相关参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<Array<GeoAddress>> | 设置接收地理编码请求的回调参数。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
let geocodeRequest:geolocation.GeoCodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};  
geolocation.getAddressesFromLocationName(geocodeRequest).then((result) => {  
    console.log('getAddressesFromLocationName: ' + JSON.stringify(result));  
});    
```    
  
    
## isGeoServiceAvailable<sup>(deprecated)</sup>    
判断（逆）地理编码服务状态，使用callback回调异步返回结果。  
 **调用形式：**     
- isGeoServiceAvailable(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.isGeocoderAvailable。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 用来接收地理编码服务状态的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.isGeoServiceAvailable((err, data) => {  
    if (err) {  
        console.log('isGeoServiceAvailable: err=' + JSON.stringify(err));  
    }  
    if (data) {  
        console.log('isGeoServiceAvailable: data=' + JSON.stringify(data));  
    }  
});    
```    
  
    
## isGeoServiceAvailable<sup>(deprecated)</sup>    
判断（逆）地理编码服务状态，使用Promise方式异步返回结果。  
 **调用形式：**     
- isGeoServiceAvailable(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.isGeocoderAvailable。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder  
 **需要权限：** ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 返回地理编码服务是否可用的状态。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.isGeoServiceAvailable().then((result) => {  
    console.log('promise, isGeoServiceAvailable: ' + JSON.stringify(result));  
});    
```    
  
    
## getCachedGnssLocationsSize<sup>(deprecated)</sup>    
获取GNSS芯片缓存位置的个数。  
 **调用形式：**     
- getCachedGnssLocationsSize(callback: AsyncCallback\<number>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getCachedGnssLocationsSize。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<number> | true | 用来接收GNSS芯片缓存位置个数的回调。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.getCachedGnssLocationsSize((err, size) => {  
    if (err) {  
        console.log('getCachedGnssLocationsSize: err=' + JSON.stringify(err));  
    }  
    if (size) {  
        console.log('getCachedGnssLocationsSize: size=' + JSON.stringify(size));  
    }  
});    
```    
  
    
## getCachedGnssLocationsSize<sup>(deprecated)</sup>    
获取GNSS芯片缓存位置的个数。  
 **调用形式：**     
- getCachedGnssLocationsSize(): Promise\<number>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.getCachedGnssLocationsSize。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<number> | 返回GNSS缓存位置的个数。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.getCachedGnssLocationsSize().then((result) => {  
    console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));  
});    
```    
  
    
## flushCachedGnssLocations<sup>(deprecated)</sup>    
读取并清空GNSS芯片所有缓存位置。  
 **调用形式：**     
- flushCachedGnssLocations(callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.flushCachedGnssLocations。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 用来接收清空GNSS芯片缓存位置操作的结果。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.flushCachedGnssLocations((err, result) => {  
    if (err) {  
        console.log('flushCachedGnssLocations: err=' + JSON.stringify(err));  
    }  
    if (result) {  
        console.log('flushCachedGnssLocations: result=' + JSON.stringify(result));  
    }  
});    
```    
  
    
## flushCachedGnssLocations<sup>(deprecated)</sup>    
读取并清空GNSS芯片所有缓存位置。  
 **调用形式：**     
- flushCachedGnssLocations(): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.flushCachedGnssLocations。  
 **系统能力:**  SystemCapability.Location.Location.Gnss  
 **需要权限：** ohos.permission.LOCATION    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 清空所有GNSS缓存位置是否成功。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
geolocation.flushCachedGnssLocations().then((result) => {  
    console.log('promise, flushCachedGnssLocations: ' + JSON.stringify(result));  
});    
```    
  
    
## sendCommand<sup>(deprecated)</sup>    
给位置服务子系统的各个部件发送扩展命令。  
 **调用形式：**     
- sendCommand(command: LocationCommand, callback: AsyncCallback\<boolean>): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.sendCommand。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command<sup>(deprecated)</sup> | LocationCommand | true | 指定目标场景，和将要发送的命令（字符串）。 |  
| callback<sup>(deprecated)</sup> | AsyncCallback<boolean> | true | 用来接收命令发送的结果。 |  
    
 **示例代码：**   
示例（callback）：  
```ts    
import geolocation from '@ohos.geolocation';  
let requestInfo:geolocation.LocationCommand = {'scenario': 0x301, 'command': "command_1"};  
geolocation.sendCommand(requestInfo, (err, result) => {  
    if (err) {  
        console.log('sendCommand: err=' + JSON.stringify(err));  
    }  
    if (result) {  
        console.log('sendCommand: result=' + JSON.stringify(result));  
    }  
});    
```    
  
    
## sendCommand<sup>(deprecated)</sup>    
给位置服务子系统的各个部件发送扩展命令。  
 **调用形式：**     
- sendCommand(command: LocationCommand): Promise\<boolean>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.geoLocationManager/geoLocationManager.sendCommand。  
 **系统能力:**  SystemCapability.Location.Location.Core  
 **需要权限：** ohos.permission.LOCATION    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| command<sup>(deprecated)</sup> | LocationCommand | true | 指定目标场景，和将要发送的命令（字符串）。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Promise<boolean> | 表示命令发送成功或失败。 |  
    
 **示例代码：**   
示例（Promise）：  
```ts    
import geolocation from '@ohos.geolocation';  
let requestInfo:geolocation.LocationCommand = {'scenario': 0x301, 'command': "command_1"};  
geolocation.sendCommand(requestInfo).then((result) => {  
    console.log('promise, sendCommand: ' + JSON.stringify(result));  
});    
```    
  
    
## SatelliteStatusInfo<sup>(deprecated)</sup>    
卫星状态信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo替代。  
 **系统能力:**  SystemCapability.Location.Location.Gnss    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| satellitesNumber | number | false | true | 表示卫星个数。取值范围为大于等于0。 |  
| satelliteIds | Array<number> | false | true | 表示每个卫星的ID，数组类型。取值范围为大于等于0。 |  
| carrierToNoiseDensitys | Array<number> | false | true | 表示载波噪声功率谱密度比，即cn0。取值范围为大于0。 |  
| altitudes | Array<number> | false | true | 表示卫星高度角信息。单位是“度”，取值范围为-90到90。 |  
| azimuths | Array<number> | false | true | 表示方位角。单位是“度”，取值范围为0到360。 |  
| carrierFrequencies | Array<number> | false | true | 表示载波频率。单位是Hz，取值范围为大于等于0。 |  
    
## CachedGnssLocationsRequest<sup>(deprecated)</sup>    
请求订阅GNSS缓存位置上报功能接口的配置参数。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.CachedGnssLocationsRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Gnss    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| reportingPeriodSec | number | false | true | 表示GNSS缓存位置上报的周期，单位是毫秒。取值范围为大于0。 |  
| wakeUpCacheQueueFull | boolean | false | true | true表示GNSS芯片底层缓存队列满之后会主动唤醒AP芯片，并把缓存位置上报给应用。<br/>false表示GNSS芯片底层缓存队列满之后不会主动唤醒AP芯片，会把缓存位置直接丢弃。 |  
    
## GeofenceRequest<sup>(deprecated)</sup>    
请求添加GNSS围栏消息中携带的参数，包括定位优先级、定位场景和围栏信息。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.GeofenceRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Geofence    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| priority | LocationRequestPriority | false | true | 表示位置信息优先级。 |  
| scenario | LocationRequestScenario | false | true | 表示定位场景。 |  
| geofence | Geofence | false | true | 表示围栏信息。 |  
    
## Geofence<sup>(deprecated)</sup>    
GNSS围栏的配置参数。目前只支持圆形围栏。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.Geofence替代。  
 **系统能力:**  SystemCapability.Location.Location.Geofence    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude | number | false | true | 表示纬度。取值范围为-90到90。 |  
| longitude | number | false | true | 表示经度。取值范围为-180到180。 |  
| radius | number | false | true | 表示圆形围栏的半径。单位是米，取值范围为大于0。 |  
| expiration | number | false | true | 围栏存活的时间，单位是毫秒。取值范围为大于0。 |  
    
## ReverseGeoCodeRequest<sup>(deprecated)</sup>    
逆地理编码请求接口。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale | string | false | false | 指定位置描述信息的语言，“zh”代表中文，“en”代表英文。 |  
| latitude | number | false | true | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |  
| longitude | number | false | true | 表示经度信息，正值表示东经，负值表示西经。取值范围为-180到180。 |  
| maxItems | number | false | false | 指定返回位置信息的最大个数。取值范围为大于等于0，推荐该值小于10。 |  
    
## GeoCodeRequest<sup>(deprecated)</sup>    
地理编码请求接口。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.GeoCodeRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| locale | string | false | false | 表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |  
| description | string | false | true | 表示位置信息描述，如“上海市浦东新区xx路xx号”。 |  
| maxItems | number | false | false | 表示返回位置信息的最大个数。取值范围为大于等于0，推荐该值小于10。 |  
| minLatitude | number | false | false | 表示最小纬度信息，与下面三个参数一起，表示一个经纬度范围。取值范围为-90到90。 |  
| minLongitude | number | false | false | 表示最小经度信息。取值范围为-180到180。 |  
| maxLatitude | number | false | false | 表示最大纬度信息。取值范围为-90到90。 |  
| maxLongitude | number | false | false | 表示最大经度信息。取值范围为-180到180。 |  
    
## GeoAddress<sup>(deprecated)</sup>    
地理编码类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.GeoAddress替代。  
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
### 属性    
 **需要权限：** ohos.permission.LOCATION    
 **系统能力:**  SystemCapability.Location.Location.Geocoder    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |  
| longitude<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。 |  
| locale<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |  
| placeName<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示地区信息。 |  
| countryCode<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示国家码信息。 |  
| countryName<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示国家信息。 |  
| administrativeArea<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示省份区域信息。 |  
| subAdministrativeArea<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示表示子区域信息。 |  
| locality<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示城市信息。 |  
| subLocality<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示子城市信息。 |  
| roadName<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示路名信息。 |  
| subRoadName<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示子路名信息。 |  
| premises<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示门牌号信息。 |  
| postalCode<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示邮政编码信息。 |  
| phoneNumber<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示联系方式信息。 |  
| addressUrl<sup>(deprecated)</sup> | string | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示位置信息附件的网址信息。 |  
| descriptions<sup>(deprecated)</sup> | Array<string> | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示附加的描述信息。 |  
| descriptionsSize<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示附加的描述信息数量。取值范围为大于等于0，推荐该值小于10。 |  
    
## LocationRequest<sup>(deprecated)</sup>    
位置信息请求类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.LocationRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| priority | LocationRequestPriority | false | false | 表示优先级信息。取值范围见[LocationRequestPriority](#locationrequestprioritydeprecated)的定义。 |  
| scenario | LocationRequestScenario | false | false | 表示场景信息。取值范围见[LocationRequestScenario](#locationrequestscenariodeprecated)的定义。 |  
| timeInterval | number | false | false | 表示上报位置信息的时间间隔，单位是秒。取值范围为大于0。 |  
| distanceInterval | number | false | false | 表示上报位置信息的距离间隔。单位是米，取值范围为大于0。 |  
| maxAccuracy | number | false | false | 表示精度信息。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。取值范围为大于0。 |  
    
## CurrentLocationRequest<sup>(deprecated)</sup>    
当前位置信息请求类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest替代。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| priority | LocationRequestPriority | false | false | 表示优先级信息。取值范围见[LocationRequestPriority](#locationrequestprioritydeprecated)的定义。 |  
| scenario | LocationRequestScenario | false | false | 表示场景信息。取值范围见[LocationRequestScenario](#locationrequestscenariodeprecated)的定义。 |  
| maxAccuracy | number | false | false | 表示精度信息，单位是米。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。取值范围为大于0。 |  
| timeoutMs | number | false | false | 表示超时时间，单位是毫秒，最小为1000毫秒。取值范围为大于等于1000。 |  
    
## Location<sup>(deprecated)</sup>    
位置信息类型。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.Location替代。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
 **需要权限：** ohos.permission.LOCATION    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| latitude<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |  
| longitude<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。 |  
| altitude<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示高度信息，单位米。 |  
| accuracy<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示精度信息，单位米。 |  
| speed<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示速度信息，单位米每秒。 |  
| timeStamp<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示位置时间戳，UTC格式。 |  
| direction<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示航向信息。单位是“度”，取值范围为0到360。 |  
| timeSinceBoot<sup>(deprecated)</sup> | number | false | true | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示位置时间戳，开机时间格式。 |  
| additions<sup>(deprecated)</sup> | Array<string> | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>附加信息。 |  
| additionSize<sup>(deprecated)</sup> | number | false | false | 从API version 7 开始支持，从API version 9 开始废弃。<br>附加信息数量。取值范围为大于等于0。 |  
    
## LocationRequestPriority<sup>(deprecated)</sup>    
位置请求中位置信息优先级设置。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.LocationRequestPriority替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSET | 0x200 | 表示未设置优先级，表示[LocationRequestPriority](#locationrequestprioritydeprecated)无效。 |  
| ACCURACY | 513 | 表示精度优先。<br/>定位精度优先策略主要以GNSS定位技术为主，在开阔场景下可以提供米级的定位精度，具体性能指标依赖用户设备的定位硬件能力，但在室内等强遮蔽定位场景下，无法提供准确的位置服务。 |  
| LOW_POWER | 514 | 表示低功耗优先。<br/>低功耗定位优先策略主要使用基站定位和WLAN、蓝牙定位技术，也可以同时提供室内和户外场景下的位置服务，因为其依赖周边基站、可见WLAN、蓝牙设备的分布情况，定位结果的精度波动范围较大，如果对定位结果精度要求不高，或者使用场景多在有基站、可见WLAN、蓝牙设备高密度分布的情况下，推荐使用，可以有效节省设备功耗。 |  
| FIRST_FIX | 515 | 表示快速获取位置优先，如果应用希望快速拿到一个位置，可以将优先级设置为该字段。<br/>快速定位优先策略会同时使用GNSS定位、基站定位和WLAN、蓝牙定位技术，以便室内和户外场景下，通过此策略都可以获得位置结果，当各种定位技术都有提供位置结果时，系统会选择其中精度较好的结果返回给应用。因为对各种定位技术同时使用，对设备的硬件资源消耗较大，功耗也较大。 |  
    
## LocationRequestScenario<sup>(deprecated)</sup>    
位置请求中定位场景设置。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.LocationRequestScenario替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| UNSET | 0x300 | 表示未设置场景信息。<br/>表示[LocationRequestScenario](#locationrequestscenariodeprecated)字段无效。 |  
| NAVIGATION | 769 | 表示导航场景。<br/>适用于在户外定位设备实时位置的场景，如车载、步行导航。<br/>在此场景下，为保证系统提供位置结果精度最优，主要使用GNSS定位技术提供定位服务<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| TRAJECTORY_TRACKING | 770 | 表示运动轨迹记录场景。<br/>适用于记录用户位置轨迹的场景，如运动类应用记录轨迹功能。主要使用GNSS定位技术提供定位服务。<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| CAR_HAILING | 771 | 表示打车场景。<br/>适用于用户出行打车时定位当前位置的场景，如网约车类应用。<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| DAILY_LIFE_SERVICE | 772 | 表示日常服务使用场景。<br/>适用于不需要定位用户精确位置的使用场景，如新闻资讯、网购、点餐类应用，做推荐、推送时定位用户大致位置即可。<br/>此场景默认以最小1秒间隔上报定位结果。 |  
| NO_POWER | 773 | 表示无功耗功场景，这种场景下不会主动触发定位，会在其他应用定位时，才给当前应用返回位置。 |  
    
## GeoLocationErrorCode<sup>(deprecated)</sup>    
位置服务中的错误码信息。    
从API version 7 开始支持，从API version 9 开始废弃。    
    
 **系统能力:**  SystemCapability.Location.Location.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| INPUT_PARAMS_ERROR<sup>(deprecated)</sup> | 0 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示输入参数错误。 |  
| REVERSE_GEOCODE_ERROR<sup>(deprecated)</sup> | 1 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示逆地理编码接口调用失败。 |  
| GEOCODE_ERROR<sup>(deprecated)</sup> | 2 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示地理编码接口调用失败。 |  
| LOCATOR_ERROR<sup>(deprecated)</sup> | 3 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示定位失败。 |  
| LOCATION_SWITCH_ERROR<sup>(deprecated)</sup> | 4 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示定位开关。 |  
| LAST_KNOWN_LOCATION_ERROR<sup>(deprecated)</sup> | 5 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示获取上次位置失败。 |  
| LOCATION_REQUEST_TIMEOUT_ERROR<sup>(deprecated)</sup> | 6 | 从API version 7 开始支持，从API version 9 开始废弃。<br>表示单次定位，没有在指定时间内返回位置。 |  
    
## LocationPrivacyType<sup>(deprecated)</sup>    
定位服务隐私协议类型。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.LocationPrivacyType替代。    
    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OTHERS | 0 | 其他场景。预留字段。 |  
| STARTUP | 1 | 开机向导场景下的隐私协议。在开机时弹出协议，提醒用户阅读并选择是否授权。 |  
| CORE_LOCATION | 2 | 开启网络定位时弹出的隐私协议。 |  
    
## LocationCommand<sup>(deprecated)</sup>    
扩展命令结构体。    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.geoLocationManager/geoLocationManager.LocationCommand替代。  
 **系统能力:**  SystemCapability.Location.Location.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| scenario | LocationRequestScenario | false | true | 表示定位场景。 |  
| command | string | false | true | 扩展命令字符串。 |  
