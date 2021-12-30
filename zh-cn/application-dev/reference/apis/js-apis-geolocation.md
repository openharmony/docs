# 位置服务

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import geolocation from '@ohos.geolocation';
import { LocationEventListener } from '@ohos.geolocation';

var locationEventListener = new LocationEventListener();
```


## 权限

ohos.permission.LOCATION

ohos.permission.LOCATION_IN_BACKGROUND


## locationEventListener.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;) : void

开启位置变化订阅，并发起定位请求。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationChange”，表示位置变化。 |
  | request | LocationRequest | 是 | 设置位置请求参数。 |
  | callback | Callback&lt;[Location](#location)&gt; | 是 | 接收位置变化状态变化监听。 |

- 示例：
  ```
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  locationEventListener.on('locationChange', requestInfo, locationChange);
  ```


## locationEventListener.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;) : void

关闭位置变化订阅，并删除对应的定位请求。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationChange”，表示位置变化。 |
  | callback | Callback&lt;[Location](#location)&gt; | 否 | 接收位置变化状态变化监听。 |

- 示例：
  ```
  var requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  locationEventListener.on('locationChange', requestInfo, locationChange);
  locationEventListener.off('locationChange', locationChange);
  ```


## locationEventListener.on('locationServiceState')

on(type: 'locationServiceState', callback: Callback&lt;boolean&gt;) : void

订阅位置服务状态变化。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationServiceState”，表示位置服务状态。 |
  | callback | Callback&lt;boolean&gt; | 是 | 接收位置服务状态变化监听。 |

- 示例：
  ```
  var locationServiceState = (state) => {
      console.log('locationServiceState: ' + state);
  }
  locationEventListener.on('locationServiceState', locationServiceState);
  ```


## locationEventListener.off('locationServiceState')

off(type: 'locationServiceState', callback: Callback&lt;boolean&gt;) : void

取消订阅位置服务状态变化。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationServiceState”，表示位置服务状态。 |
  | callback | Callback&lt;boolean&gt; | 否 | 接收位置服务状态变化监听。 |

- 示例：
  ```
  var locationServiceState = (state) => {
      console.log('locationServiceState: state: ' + state);
  }
  locationEventListener.on('locationServiceState', locationServiceState);
  locationEventListener.off('locationServiceState', locationServiceState);
  ```


## locationEventListener.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;) : void


获取当前位置，使用callback回调异步返回结果。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | 否 | 设置位置请求参数。 |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | 是 | 用来接收位置信息的回调。 |

- 示例：
  ```
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  var locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  locationEventListener.getCurrentLocation(requestInfo, locationChange);
  locationEventListener.getCurrentLocation(locationChange);
  ```


## locationEventListener.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest) : Promise&lt;Location&gt;


获取当前位置，使用Promise方式异步返回结果。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | 否 | 设置位置请求参数。 |

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | 返回位置信息。 |

- 示例：
  ```
  var requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  locationEventListener.getCurrentLocation(requestInfo).then((result) => {
      console.log('current location: ' + JSON.stringify(result));
  });
  ```


## geolocation.getLastLocation

getLastLocation(callback: AsyncCallback&lt;Location&gt;) : void

获取上一次位置，使用callback回调异步返回结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | 是 | 用来接收上次位置的回调。 |

- 示例：
  ```
  geolocation.getLastLocation((data) => {
      console.log('getLastLocation: data: ' + JSON.stringify(data));
  });
  ```


## geolocation.getLastLocation

getLastLocation() : Promise&lt;Location&gt;

获取上一次位置，使用Promise方式异步返回结果。

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;[Location](#location)&gt; | 返回上次位置信息。 |

- 示例：
  ```
  geolocation.getLastLocation().then((result) => {
      console.log('getLastLocation: result: ' + JSON.stringify(result));
  });
  ```


## geolocation.isLocationEnabled

isLocationEnabled(callback: AsyncCallback&lt;boolean&gt;) : void


判断位置服务是否已经打开，使用callback回调异步返回结果。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收位置服务状态的回调。 |

- 示例：
  ```
  geolocation.isLocationEnabled((data) => {
      console.log('isLocationEnabled: data: ' + data);
  });
  ```


## geolocation.isLocationEnabled

isLocationEnabled() : Promise&lt;boolean&gt;

判断位置服务是否已经开启，使用Promise方式异步返回结果。

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回位置服务是否可用的状态。 |

- 示例：
  ```
  geolocation.isLocationEnabled().then((result) => {
      console.log('promise, isLocationEnabled: ' + result);
  });
  ```


## geolocation.requestEnableLocation

requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;) : void


请求打开位置服务，使用callback回调异步返回结果。


- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收位置服务状态的回调。 |

- 示例：
  ```
  geolocation.requestEnableLocation((data) => {
      console.log('requestEnableLocation: ' + data);
  });
  ```


## geolocation.requestEnableLocation

requestEnableLocation() : Promise&lt;boolean&gt;

请求打开位置服务，使用Promise方式异步返回结果。

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回位置服务是否可用。 |

- 示例：
  ```
  geolocation.requestEnableLocation().then((result) => {
      console.log('promise, requestEnableLocation: ' + result);
  });
  ```


## geolocation.isGeoServiceAvailable

isGeoServiceAvailable(callback: AsyncCallback&lt;boolean&gt;) : void

判断（逆）地理编码服务状态，使用callback回调异步返回结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;boolean&gt; | 是 | 用来接收地理编码服务状态的回调。 |

- 示例：
  ```
  geolocation.isLocationEnabled((data) => {
      console.log('isLocationEnabled: ' + data);
  });
  ```


## geolocation.isGeoServiceAvailable

isGeoServiceAvailable() : Promise&lt;boolean&gt;

判断（逆）地理编码服务状态，使用Promise方式异步返回结果。

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;boolean&gt; | 返回地理编码服务是否可用的状态。 |

- 示例：
  ```
  geolocation.isLocationEnabled().then((result) => {
      console.log('promise, isLocationEnabled: ' + result);
  });
  ```


## geolocation.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void

调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 设置逆地理编码请求的相关参数。 |
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 是 | 设置接收逆地理编码请求的回调参数。 |

- 示例：
  ```
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geolocation.getAddressesFromLocation(reverseGeocodeRequest, (data) => {
      console.log('getAddressesFromLocation: ' + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt;;

调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 设置逆地理编码请求的相关参数。 |

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 返回地理描述信息。 |

- 示例：
  ```
  var reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  geolocation.getAddressesFromLocation(reverseGeocodeRequest, (data) => {
      console.log('getAddressesFromLocation: ' + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;) : void

调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | 是 | 设置地理编码请求的相关参数。 |
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 是 | 设置接收地理编码请求的回调参数。 |

- 示例：
  ```
  var geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
  geolocation.getAddressesFromLocationName(geocodeRequest, (data) => {
      console.log('getAddressesFromLocationName: ' + JSON.stringify(data));
  });
  ```


## geolocation.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest) : Promise&lt;Array&lt;GeoAddress&gt;&gt;

调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。

- 参数：
  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | 是 | 设置地理编码请求的相关参数。 |

- 返回值：
  | 参数名 | 说明 |
  | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 设置接收地理编码请求的回调参数。 |

- 示例：
  ```
  var geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
  geolocation.getAddressesFromLocationName(geocodeRequest).then((result) => {
      console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
  });
  ```


## LocationRequestPriority

位置请求中位置信息优先级设置。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| UNSET | 0x200 | 表示未设置优先级。 |
| ACCURACY | 0x201 | 表示精度优先。 |
| LOW_POWER | 0x202 | 表示低功耗优先。 |
| FIRST_FIX | 0x203 | 表示快速获取位置优先，如果应用希望快速拿到1个位置，可以将优先级设置为该字段。 |


## LocationRequestScenario

位置请求中定位场景设置。
| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| UNSET | 0x300 | 表示未设置场景信息。 |
| NAVIGATION | 0x301 | 表示导航场景。 |
| TRAJECTORY_TRACKING | 0x302 | 表示运动轨迹记录场景。 |
| CAR_HAILING | 0x303 | 表示打车场景。 |
| DAILY_LIFE_SERVICE | 0x304 | 表示日常服务使用场景。 |
| NO_POWER | 0x305 | 表示无功耗功场景，这种场景下不会主动触发定位，会在其他应用定位时，才给当前应用返回位置。 |


## GeoLocationErrorCode

位置服务中的错误码信息。

| 名称 | 默认值 | 说明 |
| -------- | -------- | -------- |
| INPUT_PARAMS_ERROR | 101 | 表示输入参数错误。 |
| REVERSE_GEOCODE_ERROR | 102 | 表示逆地理编码接口调用失败。 |
| GEOCODE_ERROR | 103 | 表示地理编码接口调用失败。 |
| LOCATOR_ERROR | 104 | 表示定位失败。 |
| LOCATION_SWITCH_ERROR | 105 | 表示定位开关。 |
| LAST_KNOWN_LOCATION_ERROR | 106 | 表示获取上次位置失败。 |
| LOCATION_REQUEST_TIMEOUT_ERROR | 107 | 表示单次定位，没有在指定时间内返回位置。 |


## ReverseGeoCodeRequest

逆地理编码请求接口。

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| locale | string | 否 | 指定位置描述信息的语言，“zh”代表中文，“en”代表英文。 |
| latitude | number | 是 | 表示纬度信息，正值表示北纬，负值表示南纬。 |
| longitude | number | 是 | 表示经度信息，正值表示东经，负值表示西经。 |
| maxItems | number | 否 | 指定返回位置信息的最大个数。 |


## GeoCodeRequest

地理编码请求接口。

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


## LocationRequest

位置信息请求类型。

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 否 | 表示优先级信息。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 表示场景信息。 |
| timeInterval | number | 否 | 表示上报位置信息的时间间隔。 |
| distanceInterval | number | 否 | 表示上报位置信息的距离间隔。 |
| maxAccuracy | number | 否 | 表示精度信息。 |


## CurrentLocationRequest

当前位置信息请求类型。

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 否 | 表示优先级信息。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 否 | 表示场景信息。 |
| maxAccuracy | number | 否 | 表示精度信息，单位是米。 |
| timeoutMs | number | 否 | 表示超时时间，单位是毫秒，最小为1000毫秒。 |


## Location

位置信息类型。

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
