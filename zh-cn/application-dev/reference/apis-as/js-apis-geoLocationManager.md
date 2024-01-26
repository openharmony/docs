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

开发者可以在应用配置文件中声明所需要的权限，具体可参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。


## 导入模块

```ts
import geoLocationManager from '@ohos.geoLocationManager';
```


## LocationRequest

位置信息请求类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 是 | 是 | 表示优先级信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestPriority](#locationrequestpriority)的定义。 |
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 是 | 表示场景信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestScenario](#locationrequestscenario)的定义。 |
| timeInterval | number | 是 | 是 | 表示上报位置信息的时间间隔，单位是秒。默认值为1，取值范围为大于等于0。 |
| distanceInterval | number | 是 | 是 | 表示上报位置信息的距离间隔。单位是米，默认值为0，取值范围为大于等于0。 |
| maxAccuracy | number | 是 | 是 | 表示精度信息，单位是米。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。默认值为0，取值范围为大于等于0。 |


## CurrentLocationRequest

当前位置信息请求类型。

**系统能力**：SystemCapability.Location.Location.Core

| 名称 | 类型 | 可读|可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| priority | [LocationRequestPriority](#locationrequestpriority) | 是 | 是 | 表示优先级信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestPriority](#locationrequestpriority)的定义。|
| scenario | [LocationRequestScenario](#locationrequestscenario) | 是 | 是 | 表示场景信息。当scenario取值为UNSET时，priority参数生效，否则priority参数不生效；当scenario和priority均取值为UNSET时，无法发起定位请求。取值范围见[LocationRequestScenario](#locationrequestscenario)的定义。 |
| maxAccuracy | number | 是 | 是| 表示精度信息，单位是米。仅在精确位置功能场景下有效，模糊位置功能生效场景下该字段无意义。默认值为0，取值范围为大于等于0。 |
| timeoutMs | number | 是 | 是 | 表示超时时间，单位是毫秒，最小为1000毫秒。取值范围为大于等于1000。 |


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
  import BusinessError from "@ohos.base";
  let locationChange = (err:BusinessError.BusinessError, location:geoLocationManager.Location) => {
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
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
  import BusinessError from "@ohos.base";
  try {
      let location = geoLocationManager.getLastLocation();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
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
  import BusinessError from "@ohos.base";
  try {
      let locationEnabled = geoLocationManager.isLocationEnabled();
  } catch (err) {
      console.error("errCode:" + (err as BusinessError.BusinessError).code + ",errMessage:" + (err as BusinessError.BusinessError).message);
  }
  ```