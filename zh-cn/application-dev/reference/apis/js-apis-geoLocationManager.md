# 位置服务

位置服务提供GNSS定位、网络定位、地理编码、逆地理编码、国家码和地理围栏等基本功能。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import geoLocationManager from '@ohos.geoLocationManager';
```


## geoLocationManager.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void

开启位置变化订阅，并发起定位请求。定位结果按照[LocationRequest](#locationrequest)的属性进行上报，

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationChange”，表示位置变化。 |
  | request |  [LocationRequest](#locationrequest) | 是 | 设置位置请求参数。 |
  | callback | Callback&lt;[Location](#location)&gt; | 是 | 接收位置变化状态变化监听。 |
  


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  geoLocationManager.on('locationChange', requestInfo, locationChange);
  ```


## geoLocationManager.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void

关闭位置变化订阅，并删除对应的定位请求。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationChange”，表示位置变化。 |
  | callback | Callback&lt;[Location](#location)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  geoLocationManager.on('locationChange', requestInfo, locationChange);
  geoLocationManager.off('locationChange', locationChange);
  ```


## geoLocationManager.on('locationEnabledChange')

on(type: 'locationEnabledChange', callback: Callback&lt;boolean&gt;): void

订阅位置服务状态变化。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.on(type: 'locationEnabledChange', callback: Callback<boolean>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationEnabledChange”，表示位置服务状态。 |
  | callback | Callback&lt;boolean&gt; | 是 | 接收位置服务状态变化监听。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locationEnabledChange = (state) => {
      console.log('locationEnabledChange: ' + JSON.stringify(state));
  }
  geoLocationManager.on('locationEnabledChange', locationEnabledChange);
  ```


## geoLocationManager.off('locationEnabledChange')

off(type: 'locationEnabledChange', callback?: Callback&lt;boolean&gt;): void;

取消订阅位置服务状态变化。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.off(type: 'locationEnabledChange', callback: Callback<boolean>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationEnabledChange”，表示位置服务状态。 |
  | callback | Callback&lt;boolean&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locationEnabledChange = (state) => {
      console.log('locationEnabledChange: state: ' + JSON.stringify(state));
  }
  geoLocationManager.on('locationEnabledChange', locationEnabledChange);
  geoLocationManager.off('locationEnabledChange', locationEnabledChange);
  ```


## geoLocationManager.on('cachedGnssLocationsChange')<sup>8+</sup>

on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;): void;

订阅缓存GNSS定位结果上报事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback<Array<Location>>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“cachedGnssLocationsChange”，表示GNSS缓存定位结果上报。 |
  | request |  [CachedGnssLocationsRequest](#cachedgnsslocationsrequest) | 是 | GNSS缓存功能配置参数 |
  | callback | Callback&lt;boolean&gt; | 是 | 接收GNSS缓存位置上报。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
  ```


## geoLocationManager.off('cachedGnssLocationsChange')<sup>8+</sup>

off(type: 'cachedGnssLocationsChange', callback?: Callback&lt;Array&lt;Location&gt;&gt;): void;

取消订阅缓存GNSS定位结果上报事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.off(type: 'cachedGnssLocationsChange', callback?: Callback<Array<Location>>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“cachedGnssLocationsChange”，表示GNSS缓存定位结果上报。 |
  | callback | Callback&lt;boolean&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  var requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
  geoLocationManager.off('cachedGnssLocationsChange');
  ```


## geoLocationManager.on('satelliteStatusChange')<sup>8+</sup>

on(type: 'satelliteStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;): void;

订阅GNSS卫星状态信息上报事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.on(type: 'satelliteStatusChange', callback: Callback<SatelliteStatusInfo>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“satelliteStatusChange”，表示订阅GNSS卫星状态信息上报。 |
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | 是 | 接收GNSS卫星状态信息上报。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
  ```


## geoLocationManager.off('satelliteStatusChange')<sup>8+</sup>

off(type: 'satelliteStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;): void;

取消订阅GNSS卫星状态信息上报事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.off(type: 'satelliteStatusChange', callback?: Callback<SatelliteStatusInfo>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“satelliteStatusChange”，表示订阅GNSS卫星状态信息上报。 |
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var gnssStatusCb = (satelliteStatusInfo) => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
  geoLocationManager.off('satelliteStatusChange', gnssStatusCb);
  ```


## geoLocationManager.on('nmeaMessage')<sup>8+</sup>

on(type: 'nmeaMessage', callback: Callback&lt;string&gt;): void;

订阅GNSS NMEA信息上报事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.on(type: 'nmeaMessage', callback: Callback<string>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“nmeaMessage”，表示订阅GNSS&nbsp;NMEA信息上报。 |
  | callback | Callback&lt;string&gt; | 是 | 接收GNSS&nbsp;NMEA信息上报。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var nmeaCb = (str) => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }
  geoLocationManager.on('nmeaMessage', nmeaCb );
  ```


## geoLocationManager.off('nmeaMessage')<sup>8+</sup>

off(type: 'nmeaMessage', callback?: Callback&lt;string&gt;): void;

取消订阅GNSS NMEA信息上报事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.off(type: 'nmeaMessage', callback?: Callback<string>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“nmeaMessage”，表示订阅GNSS&nbsp;NMEA信息上报。 |
  | callback | Callback&lt;string&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var nmeaCb = (str) => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }
  geoLocationManager.on('nmeaMessage', nmeaCb);
  geoLocationManager.off('nmeaMessage', nmeaCb);
  ```


## geoLocationManager.on('gnssFenceStatusChange')<sup>8+</sup>

on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

添加一个围栏，并订阅地理围栏事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Geofence

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“gnssFenceStatusChange”，表示订阅围栏事件上报。 |
  | request |  [GeofenceRequest](#geofencerequest) | 是 | 围栏的配置参数。 |
  | want | WantAgent | 是 | 用于接收地理围栏事件上报（进出围栏）。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.wantAgent';
  
  let wantAgentInfo = {
      wants: [
          {
              bundleName: "com.example.myapplication",
              abilityName: "com.example.myapplication.MainAbility",
              action: "action1",
          }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG],
  };
  
  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    var requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
    geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
  });
  ```


## geoLocationManager.off('gnssFenceStatusChange')<sup>8+</sup>

off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

删除一个围栏，并取消订阅该围栏事件。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Geofence

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“gnssFenceStatusChange”，表示订阅围栏事件上报。 |
  | request | [GeofenceRequest](#geofencerequest) | 是 | 围栏的配置参数。 |
  | want | WantAgent | 是 | 用于接收地理围栏事件上报（进出围栏）。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.wantAgent';
  
  let wantAgentInfo = {
      wants: [
          {
              bundleName: "com.example.myapplication",
              abilityName: "com.example.myapplication.MainAbility",
              action: "action1",
          }
      ],
      operationType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags: [wantAgent.WantAgentFlags.UPDATE_PRESENT_FLAG]
  };
  
  wantAgent.getWantAgent(wantAgentInfo).then((wantAgentObj) => {
    var requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
    geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
    geoLocationManager.off('gnssFenceStatusChange', requestInfo, wantAgentObj);
  });
  ```


## geoLocationManager.on('countryCodeChange')

on(type: 'countryCodeChange', callback: Callback&lt;CountryCode&gt;): void;

订阅国家码信息变化事件。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“countryCodeChange”，表示订阅国家码信息变化事件。 |
  | callback | Callback&lt;[CountryCode](#countrycode)&gt; | 是 | 接收国家码信息上报。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301500 | Failed to query the area information.                                       |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }
  geoLocationManager.on('countryCodeChange', callback);
  ```


## geoLocationManager.off('countryCodeChange')

off(type: 'countryCodeChange', callback?: Callback&lt;CountryCode&gt;): void;

取消订阅国家码变化事件。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“countryCodeChange”，表示取消订阅国家码信息变化事件。 |
  | callback | Callback&lt;[CountryCode](#countrycode)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301500 | Failed to query the area information.                                       |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }
  geoLocationManager.on('countryCodeChange', callback);
  geoLocationManager.off('countryCodeChange', callback);
  ```



## geoLocationManager.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void

获取当前位置，使用callback回调异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | 否 | 设置位置请求参数。 |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | 是 | 用来接收位置信息的回调。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  var locationChange = (err, location) => {
      if (err) {
          console.log('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.log('locationChanger: location=' + JSON.stringify(location));
      }
  };
  geoLocationManager.getCurrentLocation(requestInfo, locationChange);
  geoLocationManager.getCurrentLocation(locationChange);
  ```


## geoLocationManager.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt;

获取当前位置，使用Promise方式异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | 否 | 设置位置请求参数。 |

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | 返回位置信息。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  geoLocationManager.getCurrentLocation(requestInfo).then((result) => {
      console.log('current location: ' + JSON.stringify(result));
  });
  ```


## geoLocationManager.getLastLocation

getLastLocation(callback: AsyncCallback&lt;Location&gt;): void

获取上一次位置，使用callback回调异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getLastLocation(): Location;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | 是 | 用来接收上次位置的回调。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getLastLocation((err, data) => {
      if (err) {
          console.log('getLastLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('getLastLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geoLocationManager.getLastLocation

getLastLocation(): Promise&lt;Location&gt;

获取上一次位置，使用Promise方式异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getLastLocation(): Location;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | 返回上次位置信息。 |


**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getLastLocation().then((result) => {
      console.log('getLastLocation: result: ' + JSON.stringify(result));
  });
  ```


## geoLocationManager.isLocationEnabled

isLocationEnabled(callback: AsyncCallback&lt;boolean&gt;): void

判断位置服务是否已经打开，使用callback回调异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.isLocationEnabled(): boolean;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收位置服务状态的回调。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.isLocationEnabled((err, data) => {
      if (err) {
          console.log('isLocationEnabled: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('isLocationEnabled: data=' + JSON.stringify(data));
      }
  });
  ```


## geoLocationManager.requestEnableLocation

requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;): void

请求打开位置服务，使用callback回调异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.requestEnableLocation(callback: AsyncCallback<boolean>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收位置服务状态的回调。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.requestEnableLocation((err, data) => {
      if (err) {
          console.log('requestEnableLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('requestEnableLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geoLocationManager.requestEnableLocation

requestEnableLocation(): Promise&lt;boolean&gt;

请求打开位置服务，使用Promise方式异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.requestEnableLocation(): Promise<boolean>;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回位置服务是否可用。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.requestEnableLocation().then((result) => {
      console.log('promise, requestEnableLocation: ' + JSON.stringify(result));
  });
  ```



## geoLocationManager.enableLocation

enableLocation(callback: AsyncCallback&lt;void&gt;): void;

打开位置服务，使用callback回调异步返回结果。

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableLocation((err, data) => {
      if (err) {
          console.log('enableLocation: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.enableLocation

enableLocation(): Promise&lt;void&gt;

打开位置服务，使用Promise方式异步返回结果。

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;void&gt; | 返回错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableLocation().then((result) => {
      console.log('promise, enableLocation succeed');
  })
  .catch((error) => {
      console.log('promise, enableLocation: error=' + JSON.stringify(error));
  });
  ```

## geoLocationManager.disableLocation

disableLocation(): void;

关闭位置服务。

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

无

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableLocation((err, data) => {
      if (err) {
          console.log('disableLocation: err=' + JSON.stringify(err));
      }
  });
  ```



## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 设置逆地理编码请求的相关参数。 |
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 是 | 设置接收逆地理编码请求的回调参数。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
      if (err) {
          console.log('getAddressesFromLocation: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('getAddressesFromLocation: data=' + JSON.stringify(data));
      }
  });
  ```


## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;;

调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise<Array<GeoAddress>>;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 设置逆地理编码请求的相关参数。 |

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 返回地理描述信息。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
      console.log('getAddressesFromLocation: ' + JSON.stringify(data));
  });
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | 是 | 设置地理编码请求的相关参数。 |
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 是 | 设置接收地理编码请求的回调参数。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
  geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
      if (err) {
          console.log('getAddressesFromLocationName: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('getAddressesFromLocationName: data=' + JSON.stringify(data));
      }
  });
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;

调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getAddressesFromLocationName(request: GeoCodeRequest): Promise<Array<GeoAddress>>;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | 是 | 设置地理编码请求的相关参数。 |

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 设置接收地理编码请求的回调参数。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
  geoLocationManager.getAddressesFromLocationName(geocodeRequest).then((result) => {
      console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
  });
  ```

## geoLocationManager.isGeocoderAvailable

isGeocoderAvailable(callback: AsyncCallback&lt;boolean&gt;): void

判断（逆）地理编码服务状态，使用callback回调异步返回结果。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.isGeocoderAvailable(): boolean;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收地理编码服务状态的回调。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.isGeocoderAvailable((err, data) => {
      if (err) {
          console.log('isGeocoderAvailable: err=' + JSON.stringify(err));
      }
      if (data) {
          console.log('isGeocoderAvailable: data=' + JSON.stringify(data));
      }
  });
  ```


## geoLocationManager.getCachedGnssLocationsSize<sup>8+</sup>

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;): void;

获取GNSS芯片缓存位置的个数。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getCachedGnssLocationsSize(callback: AsyncCallback<number>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | 是 | 用来接收GNSS芯片缓存位置个数的回调。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getCachedGnssLocationsSize((err, size) => {
      if (err) {
          console.log('getCachedGnssLocationsSize: err=' + JSON.stringify(err));
      }
      if (size) {
          console.log('getCachedGnssLocationsSize: size=' + JSON.stringify(size));
      }
  });
  ```


## geoLocationManager.getCachedGnssLocationsSize<sup>8+</sup>

getCachedGnssLocationsSize(): Promise&lt;number&gt;;

获取GNSS芯片缓存位置的个数。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.getCachedGnssLocationsSize(): Promise<number>;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;number&gt; | 返回GNSS缓存位置的个数。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getCachedGnssLocationsSize().then((result) => {
      console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
  });
  ```


## geoLocationManager.flushCachedGnssLocations<sup>8+</sup>

flushCachedGnssLocations(callback: AsyncCallback&lt;boolean&gt;): void;

读取并清空GNSS芯片所有缓存位置。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.flushCachedGnssLocations(callback: AsyncCallback<void>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收清空GNSS芯片缓存位置操作的结果。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.flushCachedGnssLocations((err, result) => {
      if (err) {
          console.log('flushCachedGnssLocations: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('flushCachedGnssLocations: result=' + JSON.stringify(result));
      }
  });
  ```


## geoLocationManager.flushCachedGnssLocations<sup>8+</sup>

flushCachedGnssLocations(): Promise&lt;boolean&gt;;

读取并清空GNSS芯片所有缓存位置。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.flushCachedGnssLocations(): Promise<void>;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 清空所有GNSS缓存位置是否成功。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.flushCachedGnssLocations().then((result) => {
      console.log('promise, flushCachedGnssLocations: ' + JSON.stringify(result));
  });
  ```


## geoLocationManager.sendCommand<sup>8+</sup>

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;boolean&gt;): void;

给位置服务子系统的各个部件发送扩展命令。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.sendCommand(command: LocationCommand, callback: AsyncCallback<void>): void;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | command |  [LocationCommand](#locationcommand) | 是 | 指定目标场景，和将要发送的命令（字符串）。 |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收命令发送的结果。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  geoLocationManager.sendCommand(requestInfo, (err, result) => {
      if (err) {
          console.log('sendCommand: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('sendCommand: result=' + JSON.stringify(result));
      }
  });
  ```


## geoLocationManager.sendCommand<sup>8+</sup>

sendCommand(command: LocationCommand): Promise&lt;boolean&gt;;

给位置服务子系统的各个部件发送扩展命令。

> **说明：**<br/>
> 从API version 9开始废弃，建议使用[geoLocationManager.sendCommand(command: LocationCommand): Promise<void>;<sup>9+</sup>](#)替代。

**需要权限**：ohos.permission.LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | command | [LocationCommand](#locationcommand) | 是 | 指定目标场景，和将要发送的命令（字符串）。 |

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 表示命令发送成功或失败。 |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var requestInfo = {'scenario': 0x301, 'command': "command_1"};
  geoLocationManager.sendCommand(requestInfo).then((result) => {
      console.log('promise, sendCommand: ' + JSON.stringify(result));
  });
  ```


## geoLocationManager.getCountryCode

getCountryCode(callback: AsyncCallback&lt;CountryCode&gt;): void;

查询当前的国家码。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[CountryCode](#countrycode)&gt; | 是 | 用来接收国家码。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.|

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getCountryCode((err, result) => {
      if (err) {
          console.log('getCountryCode: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('getCountryCode: result=' + JSON.stringify(result));
      }
  });
  ```


## geoLocationManager.getCountryCode

getCountryCode(): Promise&lt;CountryCode&gt;;

查询当前的国家码。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

无

**返回值**：

  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;[CountryCode](#countrycode)&gt; | 返回国家码。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.|

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.getCountryCode()
  .then((result) => {
      console.log('promise, getCountryCode: result=' + JSON.stringify(result));
  })
  .catch((error) => {
      console.log('promise, getCountryCode: error=' + JSON.stringify(error));
  });
  ```


## geoLocationManager.enableLocationMock

enableLocationMock(callback: AsyncCallback&lt;void&gt;): void;

使能位置模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收执行结果，如果执行成功就返回nullptr，否则就返回错误信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableLocationMock((err, result) => {
      if (err) {
          console.log('enableLocationMock: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.disableLocationMock

disableLocationMock(callback: AsyncCallback&lt;void&gt;): void;

去使能位置模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收执行结果，如果执行成功就返回nullptr，否则就返回错误信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableLocationMock((err, result) => {
      if (err) {
          console.log('disableLocationMock: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.setMockedLocations

setMockedLocations(config: LocationMockConfig, callback: AsyncCallback&lt;void&gt;): void;

设置模拟的位置信息，后面会以该接口中携带的时间间隔上报模拟位置。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config |  [LocationMockConfig](#locationmockconfig) | 是 | 指示位置模拟的配置参数，包含模拟位置上报的时间间隔和模拟位置数组。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收执行结果，如果执行成功就返回nullptr，否则就返回错误信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var locations = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  var config = {"timeInterval": 5, "locations": locations};
  geoLocationManager.setMockedLocations(config, (err, data) => {
      if (err) {
          console.log('setMockedLocations: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.enableReverseGeocodingMock

enableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void;

使能逆地理编码模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收执行结果，如果执行成功就返回nullptr，否则就返回错误信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.enableReverseGeocodingMock((err, data) => {
      if (err) {
          console.log('enableReverseGeocodingMock: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.disableReverseGeocodingMock

disableReverseGeocodingMock(callback: AsyncCallback&lt;void&gt;): void;

去使能逆地理编码模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收执行结果，如果执行成功就返回nullptr，否则就返回错误信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.disableReverseGeocodingMock((err, result) => {
      if (err) {
          console.log('disableReverseGeocodingMock: err=' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.setReverseGeocodingMockInfo

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;, callback: AsyncCallback&lt;void&gt;): void;

设置逆地理编码模拟功能的配置信息，包含了位置和地名的对应关系，后续进行逆地理编码查询时如果位置信息位于配置信息中，就返回对应的地名。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | mockInfos | Array&lt;[ReverseGeocodingMockInfo](#reversegeocodingmockinfo)&gt; | 是 | 指示逆地理编码模拟功能的配置参数数组。逆地理编码模拟功能的配置参数包含了一个位置和一个地名。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收执行结果，如果执行成功就返回nullptr，否则就返回错误信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  var mockInfos = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1, "isFromMock": true}},
  ];
  geoLocationManager.setReverseGeocodingMockInfo(mockInfos, (err, data) => {
      if (err) {
          console.log('promise, setReverseGeocodingMockInfo, err:' + JSON.stringify(err));
      }
  });
  ```


## geoLocationManager.isLocationPrivacyConfirmed

isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;

查询用户是否同意定位服务隐私申明，是否同意启用定位服务。只有系统应用才能调用。

**系统API**：此接口为系统接口，三方应用不支持调用。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type |  [LocationPrivacyType](#locationprivacytype)| 是 | 指定隐私申明场景，例如开机向导中的隐私申明、开启网络定位功能时弹出的隐私申明等。 |

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| boolean | 表示用户是否同意定位服务隐私申明。。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.isLocationPrivacyConfirmed(1, (err, result) => {
      if (err) {
          console.log('isLocationPrivacyConfirmed: err=' + JSON.stringify(err));
      }
      if (result) {
          console.log('isLocationPrivacyConfirmed: result=' + JSON.stringify(result));
      }
  });
  ```


## geoLocationManager.setLocationPrivacyConfirmStatus

setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;

设置用户勾选定位服务隐私申明的状态，记录用户是否同意启用定位服务。只有系统应用才能调用。

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | [LocationPrivacyType](#locationprivacytype) | 是 | 指定隐私申明场景，例如开机向导中的隐私申明、开启网络定位功能时弹出的隐私申明等。 |
  | isConfirmed | boolean | 是 | 表示用户是否同意定位服务隐私申明。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 接收错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**
  
  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  geoLocationManager.setLocationPrivacyConfirmStatus(1, true, (err, result) => {
      if (err) {
          console.log('setLocationPrivacyConfirmStatus: err=' + JSON.stringify(err));
      }
  });
  ```


## LocationRequestPriority

位置请求中位置信息优先级设置。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| UNSET | 0x200 | 表示未设置优先级。 |
| ACCURACY | 0x201 | 表示精度优先。 |
| LOW_POWER | 0x202 | 表示低功耗优先。 |
| FIRST_FIX | 0x203 | 表示快速获取位置优先，如果应用希望快速拿到1个位置，可以将优先级设置为该字段。 |


## LocationRequestScenario

  位置请求中定位场景设置。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| UNSET | 0x300 | 表示未设置场景信息。 |
| NAVIGATION | 0x301 | 表示导航场景。 |
| TRAJECTORY_TRACKING | 0x302 | 表示运动轨迹记录场景。 |
| CAR_HAILING | 0x303 | 表示打车场景。 |
| DAILY_LIFE_SERVICE | 0x304 | 表示日常服务使用场景。 |
| NO_POWER | 0x305 | 表示无功耗功场景，这种场景下不会主动触发定位，会在其他应用定位时，才给当前应用返回位置。 |


## ReverseGeoCodeRequest

逆地理编码请求接口。

**系统能力**：SystemCapability.Location.Location.Geocoder

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| locale | string | 否 | 指定位置描述信息的语言，“zh”代表中文，“en”代表英文。 |
| latitude | number | 是 | 表示纬度信息，正值表示北纬，负值表示南纬。 |
| longitude | number | 是 | 表示经度信息，正值表示东经，负值表示西经。 |
| maxItems | number | 否 | 指定返回位置信息的最大个数。 |


## GeoCodeRequest

地理编码请求接口。

**系统能力**：SystemCapability.Location.Location.Geocoder

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| locale | string | 否 | 表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |
| description | number | 是 | 表示位置信息描述，如“上海市浦东新区xx路xx号”。 |
| maxItems | number | 否 | 表示返回位置信息的最大个数。 |
| minLatitude | number | 否 | 表示最小纬度信息，与下面三个参数一起，表示一个经纬度范围。 |
| minLongitude | number | 否 | 表示最小经度信息。 |
| maxLatitude | number | 否 | 表示最大纬度信息。 |
| maxLongitude | number | 否 | 表示最大经度信息。 |


## GeoAddress

地理编码类型。

**系统能力**：SystemCapability.Location.Location.Geocoder

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| latitude | number | 否 | 表示纬度信息，正值表示北纬，负值表示南纬。 |
| longitude | number | 否 | 表示经度信息，正值表示东经，负值表是西经。 |
| locale | string | 否 | 表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |
| placeName | string | 否 | 表示地区信息。 |
| countryCode | string | 否 | 表示国家码信息。 |
| countryName | string | 否 | 表示国家信息。 |
| administrativeArea | string | 否 | 表示省份区域信息。 |
| subAdministrativeArea | string | 否 | 表示表示子区域信息。 |
| locality | string | 否 | 表示城市信息。 |
| subLocality | string | 否 | 表示子城市信息。 |
| roadName | string | 否 | 表示路名信息。 |
| subRoadName | string | 否 | 表示子路名信息。 |
| premises | string | 否 | 表示门牌号信息。 |
| postalCode | string | 否 | 表示邮政编码信息。 |
| phoneNumber | string | 否 | 表示联系方式信息。 |
| addressUrl | string | 否 | 表示位置信息附件的网址信息。 |
| descriptions | Array&lt;string&gt; | 否 | 表示附加的描述信息。 |
| descriptionsSize | number | 否 | 表示附加的描述信息数量。 |
| isFromMock | Boolean | 否 | 表示地名信息是否来自于逆地理编码模拟功能。 |


## LocationRequest

位置信息请求类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 否 | 表示优先级信息。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 表示场景信息。 |
| timeInterval | number | 否 | 表示上报位置信息的时间间隔。 |
| distanceInterval | number | 否 | 表示上报位置信息的距离间隔。 |
| maxAccuracy | number | 否 | 表示精度信息。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。 |


## CurrentLocationRequest

当前位置信息请求类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 否 | 表示优先级信息。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 否 | 表示场景信息。 |
| maxAccuracy | number | 否 | 表示精度信息，单位是米。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。 |
| timeoutMs | number | 否 | 表示超时时间，单位是毫秒，最小为1000毫秒。 |


## SatelliteStatusInfo

卫星状态信息。

**系统能力**：SystemCapability.Location.Location.Gnss

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| satellitesNumber | number | 是 | 表示卫星个数。 |
| satelliteIds | Array&lt;number&gt; | 是 | 表示每个卫星的ID，数组类型。 |
| carrierToNoiseDensitys | Array&lt;number&gt; | 是 | 表示载波噪声功率谱密度比，即cn0。 |
| altitudes | Array&lt;number&gt; | 是 | 表示高程信息。 |
| azimuths | Array&lt;number&gt; | 是 | 表示方位角。 |
| carrierFrequencies | Array&lt;number&gt; | 是 | 表示载波频率。 |


## CachedGnssLocationsRequest

请求订阅GNSS缓存位置上报功能接口的配置参数。

**系统能力**：SystemCapability.Location.Location.Gnss

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| reportingPeriodSec | number | 是 | 表示GNSS缓存位置上报的周期，单位是毫秒。 |
| wakeUpCacheQueueFull | boolean | 是 | true表示GNSS芯片底层缓存队列满之后会主动唤醒AP芯片，并把缓存位置上报给应用。<br/>false表示GNSS芯片底层缓存队列满之后不会主动唤醒AP芯片，会把缓存位置直接丢弃。 |


## Geofence

GNSS围栏的配置参数。目前只支持圆形围栏。

**系统能力**：SystemCapability.Location.Location.Geofence

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| latitude | number | 是 | 表示纬度。 |
| longitude | number | 是 | 表示经度。 |
| radius | number | 是 | 表示圆形围栏的半径。 |
| expiration | number | 是 | 围栏存活的时间，单位是毫秒。 |


## GeofenceRequest

请求添加GNSS围栏消息中携带的参数，包括定位优先级、定位场景和围栏信息。

**系统能力**：SystemCapability.Location.Location.Geofence

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 是 | 表示位置信息优先级。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 表示定位场景。 |
| geofence |  [Geofence](#geofence) | 是 | 表示围栏信息。 |


## LocationPrivacyType

定位服务隐私协议类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| OTHERS | 0 | 其他场景。 |
| STARTUP | 1 | 开机向导场景下的隐私协议。 |
| CORE_LOCATION | 2 | 开启网络定位时弹出的隐私协议。 |


## LocationCommand

扩展命令结构体。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 表示定位场景。 |
| command | string | 是 | 扩展命令字符串。 |


## Location

位置信息类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| latitude | number | 是 | 表示纬度信息，正值表示北纬，负值表示南纬。 |
| longitude | number | 是 | 表示经度信息，正值表示东经，负值表是西经。 |
| altitude | number | 是 | 表示高度信息，单位米。 |
| accuracy | number | 是 | 表示精度信息，单位米。 |
| speed | number | 是 | 表示速度信息，单位米每秒。 |
| timeStamp | number | 是 | 表示位置时间戳，UTC格式。 |
| direction | number | 是 | 表示航向信息。 |
| timeSinceBoot | number | 是 | 表示位置时间戳，开机时间格式。 |
| additions | Array&lt;string&gt; | 否 | 附加信息。 |
| additionSize | number | 否 | 附加信息数量。 |
| isFromMock | Boolean | 否 | 表示位置信息是否来自于位置模拟功能。 |


## ReverseGeocodingMockInfo

逆地理编码模拟功能的配置信息，包含一个位置信息和一个地名信息。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| location |  [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 表示经纬度信息。 |
| geoAddress |  [GeoAddress](#geoaddress) | 是 | 表示地名信息。 |


## LocationMockConfig

位置模拟功能的配置参数，包含了模拟位置上报的时间间隔和模拟位置数组。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeInterval | number | 是 | 表示模拟位置上报的时间间隔，单位是秒。 |
| locations | Array&lt;Location&gt; | 是 | 表示模拟位置数组。 |


## CountryCode

国家码信息结构体，包含国家码字符串和国家码的来源信息。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| country | string | 是 | 表示国家码字符串。 |
| type |  [CountryCodeType](#countrycodetype)| 是 | 表示国家码信息来源。 |


## CountryCodeType

国家码来源类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| COUNTRY_CODE_FROM_LOCALE | 1 | 从全球化模块的语言配置信息中获取到的国家码。 |
| COUNTRY_CODE_FROM_SIM | 2 | 从SIM卡中获取到的国家码。 |
| COUNTRY_CODE_FROM_LOCATION | 3 | 基于用户的位置信息，通过逆地理编码查询到的国家码。 |
| COUNTRY_CODE_FROM_NETWORK | 4 | 从蜂窝网络注册信息中获取到的国家码。 |