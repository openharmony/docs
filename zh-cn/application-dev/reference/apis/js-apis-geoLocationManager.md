# @ohos.geoLocationManager (位置服务)

位置服务提供GNSS定位、网络定位、地理编码、逆地理编码、国家码和地理围栏等基本功能。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 申请权限

应用在使用系统能力前，需要检查是否已经获取用户授权访问设备位置信息。如未获得授权，可以向用户申请需要的位置权限，申请方式请参考下文。

系统提供的定位权限有：
- ohos.permission.LOCATION

- ohos.permission.APPROXIMATELY_LOCATION

- ohos.permission.LOCATION_IN_BACKGROUND

访问设备的位置信息，必须申请权限，并且获得用户授权。

API9之前的版本，申请ohos.permission.LOCATION即可。

API9及之后的版本，需要申请ohos.permission.APPROXIMATELY_LOCATION或者同时申请ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION；无法单独申请ohos.permission.LOCATION。

| 使用的API版本 | 申请位置权限 | 申请结果 | 位置的精确度 |
| -------- | -------- | -------- | -------- |
| 小于9 | ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |
| 大于等于9 | ohos.permission.LOCATION | 失败 | 无法获取位置。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION | 成功 | 获取到模糊位置，精确度为5公里。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |

如果应用在后台运行时也需要访问设备位置，除需要将应用声明为允许后台运行外，还必须申请ohos.permission.LOCATION_IN_BACKGROUND权限，这样应用在切入后台之后，系统可以继续上报位置信息。

开发者可以在应用配置文件中声明所需要的权限，具体可参考[授权申请指导](../../security/accesstoken-guidelines.md)。


## 导入模块

```ts
import geoLocationManager from '@ohos.geoLocationManager';
```


## ReverseGeoCodeRequest

逆地理编码请求接口。

**系统能力**：SystemCapability.Location.Location.Geocoder

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| locale | string | 是 | 是 | 指定位置描述信息的语言，“zh”代表中文，“en”代表英文。 |
| latitude | number | 是 | 是 | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |
| longitude | number | 是 | 是 | 表示经度信息，正值表示东经，负值表示西经。取值范围为-180到180。 |
| maxItems | number | 是 | 是 | 指定返回位置信息的最大个数。取值范围为大于等于0，推荐该值小于10。 |


## GeoCodeRequest

地理编码请求接口。

**系统能力**：SystemCapability.Location.Location.Geocoder

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| locale | string | 是 | 是 | 表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |
| description | string | 是 | 是 | 表示位置信息描述，如“上海市浦东新区xx路xx号”。 |
| maxItems | number | 是 | 是 | 表示返回位置信息的最大个数。取值范围为大于等于0，推荐该值小于10。 |
| minLatitude | number | 是 | 是 | 表示最小纬度信息，与下面三个参数一起，表示一个经纬度范围。取值范围为-90到90。 |
| minLongitude | number | 是 | 是 | 表示最小经度信息。取值范围为-180到180。 |
| maxLatitude | number | 是 | 是 | 表示最大纬度信息。取值范围为-90到90。 |
| maxLongitude | number | 是 | 是 | 表示最大经度信息。取值范围为-180到180。 |


## GeoAddress

地理编码类型。

**系统能力**：SystemCapability.Location.Location.Geocoder

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | 是 | 否  | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |
| longitude | number | 是 | 否  | 表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。 |
| locale | string | 是 | 否  | 表示位置描述信息的语言，“zh”代表中文，“en”代表英文。 |
| placeName | string | 是 | 否  | 表示地区信息。 |
| countryCode | string | 是 | 否  | 表示国家码信息。 |
| countryName | string| 是 | 否 | 表示国家信息。 |
| administrativeArea | string | 是 | 否 | 表示省份区域信息。 |
| subAdministrativeArea | string | 是 | 否 | 表示子区域信息。 |
| locality | string | 是 | 否 | 表示城市信息。 |
| subLocality | string | 是 | 否 | 表示子城市信息。 |
| roadName | string | 是 | 否 |表示路名信息。 |
| subRoadName | string | 是 | 否 | 表示子路名信息。 |
| premises | string| 是 | 否|表示门牌号信息。 |
| postalCode | string | 是 | 否 | 表示邮政编码信息。 |
| phoneNumber | string | 是 | 否 | 表示联系方式信息。 |
| addressUrl | string | 是 | 否 | 表示位置信息附件的网址信息。 |
| descriptions | Array&lt;string&gt; | 是 | 否 | 表示附加的描述信息。 |
| descriptionsSize | number | 是 | 否 | 表示附加的描述信息数量。取值范围为大于等于0，推荐该值小于10。 |
| isFromMock | Boolean | 是 | 否 | 表示地名信息是否来自于逆地理编码模拟功能。<br>**系统API**：此接口为系统接口。 |


## LocationRequest

位置信息请求类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 是 | 是 | 表示优先级信息。取值范围见[LocationRequestPriority](#locationrequestpriority)的定义。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 是 | 表示场景信息。取值范围见[LocationRequestScenario](#locationrequestscenario)的定义。 |
| timeInterval | number | 是 | 是 | 表示上报位置信息的时间间隔，单位是秒。取值范围为大于0。 |
| distanceInterval | number | 是 | 是 | 表示上报位置信息的距离间隔。单位是米，取值范围为大于0。 |
| maxAccuracy | number | 是 | 是 | 表示精度信息。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。取值范围为大于0。 |


## CurrentLocationRequest

当前位置信息请求类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 是 | 是 | 表示优先级信息。取值范围见[LocationRequestPriority](#locationrequestpriority)的定义。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 是 | 表示场景信息。取值范围见[LocationRequestScenario](#locationrequestscenario)的定义。 |
| maxAccuracy | number | 是 | 是| 表示精度信息，单位是米。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。取值范围为大于0。 |
| timeoutMs | number | 是 | 是 | 表示超时时间，单位是毫秒，最小为1000毫秒。取值范围为大于等于1000。 |


## SatelliteStatusInfo

卫星状态信息。

**系统能力**：SystemCapability.Location.Location.Gnss

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| satellitesNumber | number | 是 | 否 | 表示卫星个数。取值范围为大于等于0。 |
| satelliteIds | Array&lt;number&gt; | 是 | 否 | 表示每个卫星的ID，数组类型。取值范围为大于等于0。 |
| carrierToNoiseDensitys | Array&lt;number&gt; | 是 | 否 | 表示载波噪声功率谱密度比，即cn0。取值范围为大于0。 |
| altitudes | Array&lt;number&gt; | 是 | 否 | 表示卫星高度角信息。单位是“度”，取值范围为-90到90。 |
| azimuths | Array&lt;number&gt; | 是 | 否 | 表示方位角。单位是“度”，取值范围为0到360。 |
| carrierFrequencies | Array&lt;number&gt; | 是 | 否 | 表示载波频率。单位是Hz，取值范围为大于等于0。 |


## CachedGnssLocationsRequest

请求订阅GNSS缓存位置上报功能接口的配置参数。

**系统能力**：SystemCapability.Location.Location.Gnss

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| reportingPeriodSec | number | 是 | 是 | 表示GNSS缓存位置上报的周期，单位是毫秒。取值范围为大于0。 |
| wakeUpCacheQueueFull | boolean | 是 | 是  | true表示GNSS芯片底层缓存队列满之后会主动唤醒AP芯片，并把缓存位置上报给应用。<br/>false表示GNSS芯片底层缓存队列满之后不会主动唤醒AP芯片，会把缓存位置直接丢弃。 |


## Geofence

GNSS围栏的配置参数。目前只支持圆形围栏。

**系统能力**：SystemCapability.Location.Location.Geofence

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| latitude | number | 是 | 是 |表示纬度。取值范围为-90到90。 |
| longitude | number | 是 |是 | 表示经度。取值范围为-180到180。 |
| radius | number | 是 |是 | 表示圆形围栏的半径。单位是米，取值范围为大于0。 |
| expiration | number | 是 |是 | 围栏存活的时间，单位是毫秒。取值范围为大于0。 |


## GeofenceRequest

请求添加GNSS围栏消息中携带的参数，包括定位优先级、定位场景和围栏信息。

**系统能力**：SystemCapability.Location.Location.Geofence

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 是  |  表示定位场景。 |
| geofence |  [Geofence](#geofence)| 是 | 是  |  表示围栏信息。 |


## LocationCommand

扩展命令结构体。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| scenario | [LocationRequestScenario](#locationrequestscenario)  | 是 | 是  | 表示定位场景。 |
| command | string | 是 | 是  | 扩展命令字符串。 |


## Location

位置信息类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| latitude | number| 是 | 否 | 表示纬度信息，正值表示北纬，负值表示南纬。取值范围为-90到90。 |
| longitude | number| 是 | 否 | 表示经度信息，正值表示东经，负值表是西经。取值范围为-180到180。 |
| altitude | number | 是 | 否 | 表示高度信息，单位米。 |
| accuracy | number | 是 | 否 | 表示精度信息，单位米。 |
| speed | number | 是 | 否 |表示速度信息，单位米每秒。 |
| timeStamp | number | 是 | 否 | 表示位置时间戳，UTC格式。 |
| direction | number | 是 | 否 | 表示航向信息。单位是“度”，取值范围为0到360。 |
| timeSinceBoot | number | 是 | 否 | 表示位置时间戳，开机时间格式。 |
| additions | Array&lt;string&gt; | 是 | 否 | 附加信息。 |
| additionSize | number | 是 | 否 | 附加信息数量。取值范围为大于等于0。  |
| isFromMock | Boolean | 是 | 否 | 表示位置信息是否来自于位置模拟功能。<br>**系统API**：此接口为系统接口。 |


## ReverseGeocodingMockInfo

逆地理编码模拟功能的配置信息，包含一个位置信息和一个地名信息。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| location |  [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 是 | 表示经纬度信息。 |
| geoAddress |  [GeoAddress](#geoaddress) | 是 | 是 |表示地名信息。 |


## LocationMockConfig

位置模拟功能的配置参数，包含了模拟位置上报的时间间隔和模拟位置数组。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| timeInterval | number | 是 | 是 | 表示模拟位置上报的时间间隔，单位是秒。 |
| locations | Array&lt;[Location](#location)&gt; | 是 | 是 | 表示模拟位置数组。 |


## CountryCode

国家码信息结构体，包含国家码字符串和国家码的来源信息。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| country | string | 是 | 否 | 表示国家码字符串。 |
| type |  [CountryCodeType](#countrycodetype) | 是 | 否 | 表示国家码信息来源。 |


## LocationRequestPriority

位置请求中位置信息优先级设置。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| UNSET | 0x200 | 表示未设置优先级，表示[LocationRequestPriority](#locationrequestpriority)无效。 |
| ACCURACY | 0x201 | 表示精度优先。<br/>定位精度优先策略主要以GNSS定位技术为主，在开阔场景下可以提供米级的定位精度，具体性能指标依赖用户设备的定位硬件能力，但在室内等强遮蔽定位场景下，无法提供准确的位置服务。 |
| LOW_POWER | 0x202 | 表示低功耗优先。<br/>低功耗定位优先策略主要使用基站定位和WLAN、蓝牙定位技术，也可以同时提供室内和户外场景下的位置服务，因为其依赖周边基站、可见WLAN、蓝牙设备的分布情况，定位结果的精度波动范围较大，如果对定位结果精度要求不高，或者使用场景多在有基站、可见WLAN、蓝牙设备高密度分布的情况下，推荐使用，可以有效节省设备功耗。 |
| FIRST_FIX | 0x203 | 表示快速获取位置优先，如果应用希望快速拿到一个位置，可以将优先级设置为该字段。<br/>快速定位优先策略会同时使用GNSS定位、基站定位和WLAN、蓝牙定位技术，以便室内和户外场景下，通过此策略都可以获得位置结果，当各种定位技术都有提供位置结果时，系统会选择其中精度较好的结果返回给应用。因为对各种定位技术同时使用，对设备的硬件资源消耗较大，功耗也较大。 |


## LocationRequestScenario

  位置请求中定位场景设置。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| UNSET | 0x300 | 表示未设置场景信息。<br/>表示[LocationRequestScenario](#locationrequestscenario)字段无效。 |
| NAVIGATION | 0x301 | 表示导航场景。<br/>适用于在户外定位设备实时位置的场景，如车载、步行导航。<br/>在此场景下，为保证系统提供位置结果精度最优，主要使用GNSS定位技术提供定位服务<br/>此场景默认以最小1秒间隔上报定位结果。 |
| TRAJECTORY_TRACKING | 0x302 | 表示运动轨迹记录场景。<br/>适用于记录用户位置轨迹的场景，如运动类应用记录轨迹功能。主要使用GNSS定位技术提供定位服务。<br/>此场景默认以最小1秒间隔上报定位结果。 |
| CAR_HAILING | 0x303 | 表示打车场景。<br/>适用于用户出行打车时定位当前位置的场景，如网约车类应用。<br/>此场景默认以最小1秒间隔上报定位结果。 |
| DAILY_LIFE_SERVICE | 0x304 | 表示日常服务使用场景。<br/>适用于不需要定位用户精确位置的使用场景，如新闻资讯、网购、点餐类应用，做推荐、推送时定位用户大致位置即可。<br/>此场景默认以最小1秒间隔上报定位结果。 |
| NO_POWER | 0x305 | 表示无功耗功场景，这种场景下不会主动触发定位，会在其他应用定位时，才给当前应用返回位置。 |


## LocationPrivacyType

定位服务隐私协议类型。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| OTHERS | 0 | 其他场景。预留字段。 |
| STARTUP | 1 | 开机向导场景下的隐私协议。在开机时弹出协议，提醒用户阅读并选择是否授权。 |
| CORE_LOCATION | 2 | 开启网络定位时弹出的隐私协议。 |


## CountryCodeType

国家码来源类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| COUNTRY_CODE_FROM_LOCALE | 1 | 从全球化模块的语言配置信息中获取到的国家码。 |
| COUNTRY_CODE_FROM_SIM | 2 | 从SIM卡中获取到的国家码。 |
| COUNTRY_CODE_FROM_LOCATION | 3 | 基于用户的位置信息，通过逆地理编码查询到的国家码。 |
| COUNTRY_CODE_FROM_NETWORK | 4 | 从蜂窝网络注册信息中获取到的国家码。 |


## geoLocationManager.on('locationChange')

on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void

开启位置变化订阅，并发起定位请求。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationChange”，表示位置变化。 |
  | request |  [LocationRequest](#locationrequest) | 是 | 设置位置请求参数。 |
  | callback | Callback&lt;[Location](#location)&gt; | 是 | 接收位置变化状态变化监听。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  let locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  
  ```


## geoLocationManager.off('locationChange')

off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void

关闭位置变化订阅，并删除对应的定位请求。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationChange”，表示位置变化。 |
  | callback | Callback&lt;[Location](#location)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let requestInfo = {'priority': 0x203, 'scenario': 0x300, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
  let locationChange = (location) => {
      console.log('locationChanger: data: ' + JSON.stringify(location));
  };
  try {
      geoLocationManager.on('locationChange', requestInfo, locationChange);
      geoLocationManager.off('locationChange', locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('locationEnabledChange')

on(type: 'locationEnabledChange', callback: Callback&lt;boolean&gt;): void

订阅位置服务状态变化。

**系统能力**：SystemCapability.Location.Location.Core

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationEnabledChange”，表示位置服务状态。 |
  | callback | Callback&lt;boolean&gt; | 是 | 接收位置服务状态变化监听。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let locationEnabledChange = (state) => {
      console.log('locationEnabledChange: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('locationEnabledChange')

off(type: 'locationEnabledChange', callback?: Callback&lt;boolean&gt;): void;

取消订阅位置服务状态变化。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“locationEnabledChange”，表示位置服务状态。 |
  | callback | Callback&lt;boolean&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let locationEnabledChange = (state) => {
      console.log('locationEnabledChange: state: ' + JSON.stringify(state));
  }
  try {
      geoLocationManager.on('locationEnabledChange', locationEnabledChange);
      geoLocationManager.off('locationEnabledChange', locationEnabledChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('cachedGnssLocationsChange')

on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;): void;

订阅缓存GNSS定位结果上报事件。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“cachedGnssLocationsChange”，表示GNSS缓存定位结果上报。 |
  | request |  [CachedGnssLocationsRequest](#cachedgnsslocationsrequest) | 是 | GNSS缓存功能配置参数 |
  | callback | Callback&lt;boolean&gt; | 是 | 接收GNSS缓存位置上报。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('cachedGnssLocationsChange')

off(type: 'cachedGnssLocationsChange', callback?: Callback&lt;Array&lt;Location&gt;&gt;): void;

取消订阅缓存GNSS定位结果上报事件。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“cachedGnssLocationsChange”，表示GNSS缓存定位结果上报。 |
  | callback | Callback&lt;boolean&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.                                       |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let cachedLocationsCb = (locations) => {
      console.log('cachedGnssLocationsChange: locations: ' + JSON.stringify(locations));
  }
  let requestInfo = {'reportingPeriodSec': 10, 'wakeUpCacheQueueFull': true};
  try {
      geoLocationManager.on('cachedGnssLocationsChange', requestInfo, cachedLocationsCb);
      geoLocationManager.off('cachedGnssLocationsChange');
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('satelliteStatusChange')

on(type: 'satelliteStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;): void;

订阅GNSS卫星状态信息上报事件。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“satelliteStatusChange”，表示订阅GNSS卫星状态信息上报。 |
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | 是 | 接收GNSS卫星状态信息上报。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let gnssStatusCb = (satelliteStatusInfo) => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }

  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('satelliteStatusChange')

off(type: 'satelliteStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;): void;

取消订阅GNSS卫星状态信息上报事件。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“satelliteStatusChange”，表示订阅GNSS卫星状态信息上报。 |
  | callback | Callback&lt;[SatelliteStatusInfo](#satellitestatusinfo)&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let gnssStatusCb = (satelliteStatusInfo) => {
      console.log('satelliteStatusChange: ' + JSON.stringify(satelliteStatusInfo));
  }
  try {
      geoLocationManager.on('satelliteStatusChange', gnssStatusCb);
      geoLocationManager.off('satelliteStatusChange', gnssStatusCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('nmeaMessage')

on(type: 'nmeaMessage', callback: Callback&lt;string&gt;): void;

订阅GNSS NMEA信息上报事件。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“nmeaMessage”，表示订阅GNSS&nbsp;NMEA信息上报。 |
  | callback | Callback&lt;string&gt; | 是 | 接收GNSS&nbsp;NMEA信息上报。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let nmeaCb = (str) => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb );
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.off('nmeaMessage')

off(type: 'nmeaMessage', callback?: Callback&lt;string&gt;): void;

取消订阅GNSS NMEA信息上报事件。

**需要权限**：ohos.permission.LOCATION 和 ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“nmeaMessage”，表示订阅GNSS&nbsp;NMEA信息上报。 |
  | callback | Callback&lt;string&gt; | 否 | 需要取消订阅的回调函数。若无此参数，则取消当前类型的所有订阅。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |


**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let nmeaCb = (str) => {
      console.log('nmeaMessage: ' + JSON.stringify(str));
  }

  try {
      geoLocationManager.on('nmeaMessage', nmeaCb);
      geoLocationManager.off('nmeaMessage', nmeaCb);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.on('gnssFenceStatusChange')

on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

添加一个围栏，并订阅地理围栏事件。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Geofence

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“gnssFenceStatusChange”，表示订阅围栏事件上报。 |
  | request |  [GeofenceRequest](#geofencerequest) | 是 | 围栏的配置参数。 |
  | want | [WantAgent](js-apis-app-ability-wantAgent.md) | 是 | 用于接收地理围栏事件上报（进出围栏）。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.app.ability.wantAgent';
  
  let wantAgentInfo = {
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
    let requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
    try {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
    } catch (err) {
        console.error("errCode:" + err.code + ",errMessage:" + err.message);
    }
  });
  ```


## geoLocationManager.off('gnssFenceStatusChange')

off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;

删除一个围栏，并取消订阅该围栏事件。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Geofence

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | type | string | 是 | 设置事件类型。type为“gnssFenceStatusChange”，表示订阅围栏事件上报。 |
  | request | [GeofenceRequest](#geofencerequest) | 是 | 围栏的配置参数。 |
  | want | [WantAgent](js-apis-app-ability-wantAgent.md) | 是 | 用于接收地理围栏事件上报（进出围栏）。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301600 | Failed to operate the geofence.                                     |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  import wantAgent from '@ohos.app.ability.wantAgent';
  
  let wantAgentInfo = {
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
    let requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
    try {
        geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
        geoLocationManager.off('gnssFenceStatusChange', requestInfo, wantAgentObj);
    } catch (err) {
        console.error("errCode:" + err.code + ",errMessage:" + err.message);
    }
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
|3301500 | Failed to query the area information.                                       |


**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
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
|3301500 | Failed to query the area information.                                       |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let callback = (code) => {
      console.log('countryCodeChange: ' + JSON.stringify(code));
  }

  try {
      geoLocationManager.on('countryCodeChange', callback);
      geoLocationManager.off('countryCodeChange', callback);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```



## geoLocationManager.getCurrentLocation

getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void

获取当前位置，使用callback回调异步返回结果。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | 是 | 设置位置请求参数。 |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | 是 | 用来接收位置信息的回调。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  let locationChange = (err, location) => {
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
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(callback: AsyncCallback&lt;Location&gt;): void;

获取当前位置，通过callback方式异步返回结果。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[Location](#location)&gt; | 是 | 用来接收位置信息的回调。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let locationChange = (err, location) => {
      if (err) {
          console.log('locationChanger: err=' + JSON.stringify(err));
      }
      if (location) {
          console.log('locationChanger: location=' + JSON.stringify(location));
      }
  };

  try {
      geoLocationManager.getCurrentLocation(locationChange);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.getCurrentLocation

getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt;

获取当前位置，使用Promise方式异步返回结果。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [CurrentLocationRequest](#currentlocationrequest) | 否 | 设置位置请求参数。 |

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;[Location](#location)&gt;  | [Location](#location) | NA | 返回位置信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.                                                 |
|3301200 | Failed to obtain the geographical location.  |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let requestInfo = {'priority': 0x203, 'scenario': 0x300,'maxAccuracy': 0};
  try {
      geoLocationManager.getCurrentLocation(requestInfo).then((result) => {
          console.log('current location: ' + JSON.stringify(result));
      })  
      .catch((error) => {
          console.log('promise, getCurrentLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getLastLocation

getLastLocation(): Location

获取上一次位置。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Location  | [Location](#location) | NA | 位置信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |
|3301100 | The location switch is off.  |
|3301200 |Failed to obtain the geographical location.  |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      let location = geoLocationManager.getLastLocation();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.isLocationEnabled

isLocationEnabled(): boolean

判断位置服务是否已经使能。

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | boolean  | boolean | NA | 位置服务是否已经使能。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.  |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      let locationEnabled = geoLocationManager.isLocationEnabled();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
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
  try {
      geoLocationManager.enableLocation((err, data) => {
          if (err) {
              console.log('enableLocation: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableLocation

enableLocation(): Promise&lt;void&gt;

打开位置服务，使用Promise方式异步返回结果。

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;void&gt;  | void | NA | 返回错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableLocation().then((result) => {
          console.log('promise, enableLocation succeed');
      })
      .catch((error) => {
          console.log('promise, enableLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.disableLocation

disableLocation(): void;

关闭位置服务。

**系统API**：此接口为系统接口，三方应用不支持调用。

**需要权限**：ohos.permission.MANAGE_SECURE_SETTINGS

**系统能力**：SystemCapability.Location.Location.Core

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.disableLocation();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```



## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 设置逆地理编码请求的相关参数。 |
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 是 | 接收逆地理编码结果的回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301300 | Reverse geocoding query failed.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
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
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getAddressesFromLocation

getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;;

调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [ReverseGeoCodeRequest](#reversegeocoderequest) | 是 | 设置逆地理编码请求的相关参数。 |

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt;  | Array&lt;[GeoAddress](#geoaddress)&gt; | NA | 返回地理描述信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301300 | Reverse geocoding query failed.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest).then((data) => {
          console.log('getAddressesFromLocation: ' + JSON.stringify(data));
      })
      .catch((error) => {
          console.log('promise, getAddressesFromLocation: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void

调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | 是 | 设置地理编码请求的相关参数。 |
  | callback | AsyncCallback&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt; | 是 | 接收地理编码结果的回调函数。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301400 | Geocoding query failed.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
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
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getAddressesFromLocationName

getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt;

调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。

**系统能力**：SystemCapability.Location.Location.Geocoder

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | request | [GeoCodeRequest](#geocoderequest) | 是 | 设置地理编码请求的相关参数。 |

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;Array&lt;[GeoAddress](#geoaddress)&gt;&gt;  | Array&lt;[GeoAddress](#geoaddress)&gt; | NA | 返回地理编码查询结果。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301400 | Geocoding query failed.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
  try {
      geoLocationManager.getAddressesFromLocationName(geocodeRequest).then((result) => {
          console.log('getAddressesFromLocationName: ' + JSON.stringify(result));
      })
      .catch((error) => {
          console.log('promise, getAddressesFromLocationName: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```

## geoLocationManager.isGeocoderAvailable

isGeocoderAvailable(): boolean;

判断（逆）地理编码服务状态。

**系统能力**：SystemCapability.Location.Location.Geocoder

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | boolean  | boolean | NA | 返回（逆）地理编码服务是否可用。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      let isAvailable = geoLocationManager.isGeocoderAvailable();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;): void;

获取GNSS芯片缓存位置的个数。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;number&gt; | 是 | 用来接收GNSS芯片缓存位置个数的回调。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
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
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getCachedGnssLocationsSize

getCachedGnssLocationsSize(): Promise&lt;number&gt;;

获取GNSS芯片缓存位置的个数。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;number&gt;  | number | NA | 返回GNSS缓存位置的个数。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.getCachedGnssLocationsSize().then((result) => {
          console.log('promise, getCachedGnssLocationsSize: ' + JSON.stringify(result));
      }) 
      .catch((error) => {
          console.log('promise, getCachedGnssLocationsSize: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(callback: AsyncCallback&lt;void&gt;): void;

读取并清空GNSS芯片所有缓存位置。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收错误码信息。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.flushCachedGnssLocations((err, result) => {
          if (err) {
              console.log('flushCachedGnssLocations: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.flushCachedGnssLocations

flushCachedGnssLocations(): Promise&lt;void&gt;;

读取并清空GNSS芯片所有缓存位置。

**需要权限**：ohos.permission.APPROXIMATELY_LOCATION

**系统能力**：SystemCapability.Location.Location.Gnss

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;void&gt;  | void | NA | 接收错误码。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |
|3301100 | The location switch is off.   |
|3301200 | Failed to obtain the geographical location.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.flushCachedGnssLocations().then((result) => {
          console.log('promise, flushCachedGnssLocations success');
      })
      .catch((error) => {
          console.log('promise, flushCachedGnssLocations: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand, callback: AsyncCallback&lt;void&gt;): void;

给位置服务子系统的各个部件发送扩展命令。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | command |  [LocationCommand](#locationcommand) | 是 | 指定目标场景，和将要发送的命令（字符串）。 |
  | callback | AsyncCallback&lt;void&gt; | 是 | 用来接收错误码。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.   |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let requestInfo = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo, (err, result) => {
          if (err) {
              console.log('sendCommand: err=' + JSON.stringify(err));
          }
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.sendCommand

sendCommand(command: LocationCommand): Promise&lt;void&gt;;

给位置服务子系统的各个部件发送扩展命令。

**系统能力**：SystemCapability.Location.Location.Core

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | command | [LocationCommand](#locationcommand) | 是 | 指定目标场景，和将要发送的命令（字符串）。 |

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;void&gt;  | void | NA | 接收错误码。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let requestInfo = {'scenario': 0x301, 'command': "command_1"};
  try {
      geoLocationManager.sendCommand(requestInfo).then((result) => {
          console.log('promise, sendCommand success');
      })  
      .catch((error) => {
          console.log('promise, sendCommand: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
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
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.getCountryCode

getCountryCode(): Promise&lt;CountryCode&gt;;

查询当前的国家码。

**系统能力**：SystemCapability.Location.Location.Core

**返回值**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | Promise&lt;[CountryCode](#countrycode)&gt; | [CountryCode](#countrycode) | NA | 用来接收国家码。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301500 | Failed to query the area information.|

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.getCountryCode()
      .then((result) => {
          console.log('promise, getCountryCode: result=' + JSON.stringify(result));
      })
      .catch((error) => {
          console.log('promise, getCountryCode: error=' + JSON.stringify(error));
      });
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableLocationMock

enableLocationMock(): void;

使能位置模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableLocationMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.disableLocationMock

disableLocationMock(): void;

去使能位置模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.disableLocationMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.setMockedLocations

setMockedLocations(config: LocationMockConfig): void;

设置模拟的位置信息，后面会以该接口中携带的时间间隔上报模拟位置。

该接口需要在调用[geoLocationManager.enableLocationMock](#geolocationmanagerenablelocationmock)之后才能调用。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | config |  [LocationMockConfig](#locationmockconfig) | 是 | 指示位置模拟的配置参数，包含模拟位置上报的时间间隔和模拟位置数组。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |
|3301100 | The location switch is off.|

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let locations = [
      {"latitude": 30.12, "longitude": 120.11, "altitude": 123, "accuracy": 1, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 1000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 31.13, "longitude": 121.11, "altitude": 123, "accuracy": 2, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 2000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 32.14, "longitude": 122.11, "altitude": 123, "accuracy": 3, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 3000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 33.15, "longitude": 123.11, "altitude": 123, "accuracy": 4, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 4000000000, "additionSize": 0, "isFromMock": true},
      {"latitude": 34.16, "longitude": 124.11, "altitude": 123, "accuracy": 5, "speed": 5.2, "timeStamp": 16594326109, "direction": 123.11, "timeSinceBoot": 5000000000, "additionSize": 0, "isFromMock": true}
  ];
  let config = {"timeInterval": 5, "locations": locations};
  try {
      geoLocationManager.enableLocationMock();
      geoLocationManager.setMockedLocations(config);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.enableReverseGeocodingMock

enableReverseGeocodingMock(): void;

使能逆地理编码模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.enableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.disableReverseGeocodingMock

disableReverseGeocodingMock(): void;

去使能逆地理编码模拟功能。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.disableReverseGeocodingMock();
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```


## geoLocationManager.setReverseGeocodingMockInfo

setReverseGeocodingMockInfo(mockInfos: Array&lt;ReverseGeocodingMockInfo&gt;): void;

设置逆地理编码模拟功能的配置信息，包含了位置和地名的对应关系，后续进行逆地理编码查询时如果位置信息位于配置信息中，就返回对应的地名。

该接口需要在调用[geoLocationManager.enableReverseGeocodingMock](#geolocationmanagerenablereversegeocodingmock)之后才能调用。

**系统能力**：SystemCapability.Location.Location.Core

**系统API**：此接口为系统接口，三方应用不支持调用。

**参数**：

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | mockInfos | Array&lt;[ReverseGeocodingMockInfo](#reversegeocodingmockinfo)&gt; | 是 | 指示逆地理编码模拟功能的配置参数数组。逆地理编码模拟功能的配置参数包含了一个位置和一个地名。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  let mockInfos = [
      {"location": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 30.12, "longitude": 120.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 31.12, "longitude": 121.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 32.12, "longitude": 122.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 33.12, "longitude": 123.11, "maxItems": 1, "isFromMock": true}},
      {"location": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1}, "geoAddress": {"locale": "zh", "latitude": 34.12, "longitude": 124.11, "maxItems": 1, "isFromMock": true}},
  ];
  try {
      geoLocationManager.enableReverseGeocodingMock();
      geoLocationManager.setReverseGeocodingMockInfo(mockInfos);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
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

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | boolean  | boolean | NA | 表示用户是否同意定位服务隐私申明。 |

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      let isConfirmed = geoLocationManager.isLocationPrivacyConfirmed(1);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
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

**错误码**：

以下错误码的详细介绍请参见[位置服务子系统错误码](../errorcodes/errorcode-geoLocationManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
|3301000 | Location service is unavailable.                                            |

**示例**

  ```ts
  import geoLocationManager from '@ohos.geoLocationManager';
  try {
      geoLocationManager.setLocationPrivacyConfirmStatus(1, true);
  } catch (err) {
      console.error("errCode:" + err.code + ",errMessage:" + err.message);
  }
  ```
