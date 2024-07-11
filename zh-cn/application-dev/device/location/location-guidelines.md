# 获取设备的位置信息开发指导

## 场景概述

开发者可以调用OpenHarmony位置相关接口，获取设备实时位置，或者最近的历史位置，以及监听设备的位置变化。

对于位置敏感的应用业务，建议获取设备实时位置信息。如果不需要设备实时位置信息，并且希望尽可能的节省耗电，开发者可以考虑获取最近的历史位置。

## 接口说明

获取设备的位置信息所使用的接口如下，详细说明参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

**表2** 获取设备的位置信息接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| [on(type: 'locationChange', request: LocationRequest &#124; ContinuousLocationRequest, callback: Callback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageronlocationchange) | 开启位置变化订阅，并发起定位请求。 | 
| [off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerofflocationchange) | 关闭位置变化订阅，并删除对应的定位请求。 | 
| [getCurrentLocation(request: CurrentLocationRequest &#124; SingleLocationRequest, callback: AsyncCallback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation) | 获取当前位置，使用callback回调异步返回结果。| 
| [getCurrentLocation(request?: CurrentLocationRequest &#124; SingleLocationRequest): Promise&lt;Location&gt;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation-2) | 获取当前位置，使用Promise方式异步返回结果。| 
| [getLastLocation(): Location](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetlastlocation) | 获取最近一次定位结果。 | 

## 开发步骤

1. 获取设备的位置信息，需要有位置权限，位置权限申请的方法和步骤见[申请位置权限开发指导](location-permission-guidelines.md)。

2. 导入geoLocationManager模块，所有与基础定位能力相关的功能API，都是通过该模块提供的。
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   ```
3. 单次获取当前设备位置。多用于查看当前位置、签到打卡、服务推荐等场景。
   - 方式一：获取系统缓存的最新位置。<br/>
      如果系统当前没有缓存位置会返回错误码。<br/>
      推荐优先使用该接口获取位置，可以减少系统功耗。<br/>
      如果对位置的新鲜度比较敏感，可以先获取缓存位置，将位置中的时间戳与当前时间对比，若新鲜度不满足预期可以使用方式二获取位置。<br/>

      ```ts
      import { geoLocationManager } from '@kit.LocationKit';
      import { BusinessError } from '@kit.BasicServicesKit'
      try {
          let location = geoLocationManager.getLastLocation();
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

   - 方式二：获取当前位置。<br/>
      首先要实例化[SingleLocationRequest](../../reference/apis-location-kit/js-apis-geoLocationManager.md#singlelocationrequest12)对象，用于告知系统该向应用提供何种类型的位置服务，以及单次定位超时时间。<br/>
      - 设置LocatingPriority：<br/>
         如果对位置的返回精度要求较高，建议LocatingPriority参数优先选择PRIORITY_ACCURACY，会将一段时间内精度较好的结果返回给应用。<br/>
         如果对定位速度要求较高，建议LocatingPriority参数选择PRIORITY_LOCATING_SPEED，会将最先拿到的定位结果返回给应用。<br/>
         两种定位策略均会同时使用GNSS定位和网络定位技术，以便在室内和户外场景下均可以获取到位置结果，对设备的硬件资源消耗较大，功耗也较大。<br/>
      - 设置locatingTimeoutMs：<br/>
         因为设备环境、设备所处状态、系统功耗管控策略等的影响，定位返回的时延会有较大波动，建议把单次定位超时时间设置为10秒。<br/>
         
      以快速定位策略(PRIORITY_LOCATING_SPEED)为例，调用方式如下：<br/>

      ```ts
      import { geoLocationManager } from '@kit.LocationKit';
      import { BusinessError } from '@kit.BasicServicesKit'
      let request: geoLocationManager.SingleLocationRequest = {
         'locatingPriority': geoLocationManager.LocatingPriority.PRIORITY_LOCATING_SPEED,
         'locatingTimeoutMs': 10000
      }
      try {
         geoLocationManager.getCurrentLocation(request).then((result) => { // 调用getCurrentLocation获取当前设备位置，通过promise接收上报的位置
            console.log('current location: ' + JSON.stringify(result));
         })
         .catch((error:BusinessError) => { // 接收上报的错误码
            console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
         });
       } catch (err) {
         console.error("errCode:" + JSON.stringify(err));
       }
      ```
4. 持续定位。多用于导航、运动轨迹、出行等场景。</br>
   首先要实例化[ContinuousLocationRequest](../../reference/apis-location-kit/js-apis-geoLocationManager.md#continuouslocationrequest12)对象，用于告知系统该向应用提供何种类型的位置服务，以及位置结果上报的频率。<br/>
   - 设置locationScenario：<br/>
      建议locationScenario参数优先根据应用的使用场景进行设置，该参数枚举值定义参见[UserActivityScenario](../../reference/apis-location-kit/js-apis-geoLocationManager.md#useractivityscenario12)，例如地图在导航时使用NAVIGATION参数，可以持续在室内和室外场景获取位置用于导航。</br>
   - 设置interval：<br/>
      表示上报位置信息的时间间隔，单位是秒，默认值为1秒。如果对位置上报时间间隔无特殊要求，可以不填写该字段。
   
   以地图导航场景为例，调用方式如下：

   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   let request: geoLocationManager.ContinuousLocationRequest= {
      'interval': 1,
      'locationScenario': geoLocationManager.UserActivityScenario.NAVIGATION
   }
   let locationCallback = (location:geoLocationManager.Location):void => {
      console.log('locationCallback: data: ' + JSON.stringify(location));
   };
   try {
      geoLocationManager.on('locationChange', request, locationCallback);
   } catch (err) {
      console.error("errCode:" + JSON.stringify(err));
   }
   ```
   如果不主动结束定位可能导致设备功耗高，耗电快；建议在不需要获取定位信息时及时结束定位。
   ```ts
   geoLocationManager.off('locationChange', locationCallback);
   ```
