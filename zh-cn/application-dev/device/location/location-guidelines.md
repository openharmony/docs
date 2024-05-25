# Location Kit开发指南

## 申请位置权限开发指导

### 场景概述

应用在使用[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)系统能力前，需要检查是否已经获取用户授权访问设备位置信息。如未获得授权，可以向用户申请需要的位置权限。

系统提供的定位权限有：

- ohos.permission.LOCATION：用于获取精准位置，精准度在米级别。

- ohos.permission.APPROXIMATELY_LOCATION：用于获取模糊位置，精确度为5公里。

- ohos.permission.LOCATION_IN_BACKGROUND：用于应用切换到后台仍然需要获取定位信息的场景。

Location Kit接口对权限的要求参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

### 开发步骤

1. 开发者可以在应用配置文件中声明所需要的权限并向用户申请授权，具体可参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md#向用户申请授权)。

2. 当APP运行在前台，且访问设备位置信息时，申请位置权限的方式如下：

**表1** 位置权限申请方式介绍

| [targetAPIVersion(应用运行需要的API目标版本)](../../quick-start/app-configuration-file.md#配置文件标签) | 申请位置权限的方式 | 是否允许申请 | 申请成功后获取的位置的精确度 |
| -------- | -------- | -------- | -------- |
| 小于9 | 申请ohos.permission.LOCATION | 是 | 获取到精准位置，精准度在米级别。 |
| 大于等于9 | 申请ohos.permission.LOCATION | 否 | 无法获取位置。 |
| 大于等于9 | 申请ohos.permission.APPROXIMATELY_LOCATION | 是 | 获取到模糊位置，精确度为5公里。 |
| 大于等于9 | 同时申请ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION | 是 | 获取到精准位置，精准度在米级别。 |

3. 当APP运行在后台时，申请位置权限的方式如下：

如果应用在后台运行时也需要访问设备位置，除了按照步骤2申请权限外，还需要申请ohos.permission.LOCATION_IN_BACKGROUND权限或申请LOCATION类型的长时任务。

（1）应用如需使用ohos.permission.LOCATION_IN_BACKGROUND权限，需要在设置界面由用户手动授予，具体授权方式可参考[ohos.permission.LOCATION_IN_BACKGROUND权限说明](../../security/AccessToken/permissions-for-all.md#ohospermissionlocation_in_background)。

（2）长时任务申请可参考：[长时任务介绍](../../task-management/continuous-task.md)<!--Del-->，[长时任务开发示例](../../performance/reasonable-running-backgroundTask.md#长时任务)<!--DelEnd-->。



## 获取设备的位置信息开发指导

### 场景概述

开发者可以调用OpenHarmony位置相关接口，获取设备实时位置，或者最近的历史位置，以及监听设备的位置变化。

对于位置敏感的应用业务，建议获取设备实时位置信息。如果不需要设备实时位置信息，并且希望尽可能的节省耗电，开发者可以考虑获取最近的历史位置。

### 接口说明

获取设备的位置信息所使用的接口如下，详细说明参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

**表2** 获取设备的位置信息接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| [on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageronlocationchange) | 开启位置变化订阅，并发起定位请求。 | 
| [off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerofflocationchange) | 关闭位置变化订阅，并删除对应的定位请求。 | 
| [getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation) | 获取当前位置，使用callback回调异步返回结果。 | 
| [getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation-2) | 获取当前位置，使用Promise方式异步返回结果。 | 
| [getLastLocation(): Location](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetlastlocation) | 获取最近一次定位结果。 | 

### 开发步骤

1. 获取设备的位置信息，需要有位置权限，位置权限申请的方法和步骤见[申请位置权限开发指导](#申请位置权限开发指导)。

2. 导入geoLocationManager模块，所有与基础定位能力相关的功能API，都是通过该模块提供的。
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   ```
3. 获取历史定位结果。

   如果应用使用场景不需要实时的设备位置，可以获取系统缓存的最近一次历史定位结果。

   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   import { BusinessError } from '@kit.BasicServicesKit'
   try {
       let location = geoLocationManager.getLastLocation();
   } catch (err) {
       console.error("errCode:" + JSON.stringify(err));
   }
   ```
   
4. 实例化LocationRequest对象，用于告知系统该向应用提供何种类型的定位服务，以及位置结果上报的频率。<br/>

   LocationRequest中定义了2个变量scenario（方式一）和priority（方式二）用于指定定位服务类型。<br/>scenario（方式一）从用户活动场景角度进行定义，priority（方式二）从定位精度、定位速度和功耗等角度进行定义。<br/>如果开发者能明确用户的活动场景，可以选择方式一；如果开发者开发者需对定位精度、定位速度、功耗等有要求可以选择方式二。

   <details>
   <summary>方式一：</summary>

   为了面向开发者提供贴近其使用场景的API使用方式，系统定义了几种常见的位置能力使用场景，并针对使用场景做了适当的优化处理。系统当前支持场景如下表所示。

   ***定位场景类型说明***
   
   - 导航场景：NAVIGATION<br/>
   适用于在户外获取设备实时位置的场景，如车载、步行导航。主要使用GNSS定位技术提供定位服务，功耗较高。
   
   - 轨迹跟踪场景：TRAJECTORY_TRACKING<br/>
   适用于记录用户位置轨迹的场景，如运动类应用记录轨迹功能。主要使用GNSS定位技术提供定位服务，功耗较高。
   
   - 出行约车场景：CAR_HAILING<br/>
   适用于用户出行打车时定位当前位置的场景，如网约车类应用。主要使用GNSS定位技术提供定位服务，功耗较高。
   
   当使用NAVIGATION/TRAJECTORY_TRACKING/CAR_HAILING场景时，如果用户在室内或车库等环境，我们会在GNSS提供稳定位置结果之前，使用网络定位技术（蜂窝基站、WLAN、蓝牙定位技术）向应用提供定位服务。
   
   - 生活服务场景：DAILY_LIFE_SERVICE<br/>
   适用于不需要定位用户精确位置的使用场景，如新闻资讯、网购、点餐类应用。该场景仅使用网络定位技术提供定位服务，功耗较低。
   
   - 无功耗场景：NO_POWER<br/>
   适用于不需要主动启动定位的业务。系统在响应其他应用启动定位并上报位置时，会同时向请求此场景的应用程序上报定位结果，当前的应用程序不产生定位功耗。


   ```ts
       export enum LocationRequestScenario {
            UNSET = 0x300,//默认值
            NAVIGATION,//导航场景
            TRAJECTORY_TRACKING,//轨迹跟踪场景
            CAR_HAILING,//出行约车场景
            DAILY_LIFE_SERVICE,//生活服务场景
            NO_POWER,//无功耗场景
        }
   ```


   以导航场景为例，实例化方式如下：

   ```ts
   let requestInfo:geoLocationManager.LocationRequest = {'scenario': geoLocationManager.LocationRequestScenario.NAVIGATION, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

   </details>

   <details>
   <summary>方式二：</summary>

   如果定义的现有场景类型不能满足所需的开发场景，系统提供了基本的定位优先级策略类型。

   ***定位优先级策略类型说明***

   - 定位精度优先策略：ACCURACY<br/>
      定位精度优先策略主要以GNSS定位技术为主，仅在长时间无法获取GNSS定位结果时使用网络定位技术。对设备的硬件资源消耗较大，功耗较大。

   - 低功耗定位优先策略：LOW_POWER<br/>
      低功耗定位优先策略主要使用网络定位技术，在室内和户外场景均可提供定位服务，因为其依赖周边基站、可见WLAN、蓝牙设备的分布情况，定位结果的精度波动范围较大，推荐在对定位结果精度要求不高的场景下使用该策略，可以有效节省设备功耗。

   - 快速定位优先策略：FIRST_FIX<br/>
      快速定位优先策略会同时使用GNSS定位和网络定位技术，以便在室内和户外场景下均可以快速获取到位置结果；当各种定位技术都有提供位置结果时，系统会选择其中精度较好的结果返回给应用。因为对各种定位技术同时使用，对设备的硬件资源消耗较大，功耗也较大。
      
   ```ts
       export enum LocationRequestPriority {
            UNSET = 0x200,//默认值
            ACCURACY,//定位精度优先策略
            LOW_POWER,//低功耗定位优先策略
            FIRST_FIX,//快速定位优先策略
        }
   ```

   以定位精度优先策略为例，实例化方式如下：

   ```ts
   let requestInfo:geoLocationManager.LocationRequest = {'priority': geoLocationManager.LocationRequestPriority.ACCURACY, 'timeInterval': 1, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```
   </details>

5. 实例化Callback对象，用于向系统提供位置上报的途径。
     应用需要自行实现系统定义好的回调接口，并将其实例化。系统在定位成功确定设备的实时位置结果时，会通过该接口上报给应用。应用程序可以在接口的实现中完成自己的业务逻辑。
     
   ```ts
   let locationChange = (location:geoLocationManager.Location):void => {
       console.log('locationChanger: data: ' + JSON.stringify(location));
   };
   ```

6. 启动持续定位。
   
   ```ts
   geoLocationManager.on('locationChange', requestInfo, locationChange);
   ```

7. （可选）结束持续定位。

   如果不主动结束定位可能导致设备功耗高，耗电快；建议在不需要获取定位信息时及时结束定位。

   ```ts
   geoLocationManager.off('locationChange', locationChange);
   ```

8. 单次获取当前设备位置。

   如果应用仅需要获取一次设备位置，可以使用[getCurrentLocation](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetcurrentlocation-2)。
   
   [CurrentLocationRequest](../../reference/apis-location-kit/js-apis-geoLocationManager.md#currentlocationrequest)的实例化可以参考步骤4。

   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   import { BusinessError } from '@kit.BasicServicesKit'
   //实例化CurrentLocationRequest对象，指定快速定位优先策略，指定定位超时时间为5秒。
   let requestInfo:geoLocationManager.CurrentLocationRequest = {'priority': geoLocationManager.LocationRequestPriority.FIRST_FIX, 'scenario': geoLocationManager.LocationRequestScenario.UNSET, 'timeoutMs': 5000};
   try {
       geoLocationManager.getCurrentLocation(requestInfo).then((result) => {//调用getCurrentLocation获取当前设备位置，通过promise接收上报的位置
           console.log('current location: ' + JSON.stringify(result));
       })  
       .catch((error:BusinessError.BusinessError) => {//接收上报的错误码
           console.error('promise, getCurrentLocation: error=' + JSON.stringify(error));
       });
   } catch (err) {
       console.error("errCode:" + JSON.stringify(err));
   }
   ```


## 地理编码转化与逆地理编码转化开发指导

### 场景概述

使用坐标描述一个位置，非常准确，但是并不直观，面向用户表达并不友好。系统向开发者提供了以下两种转化能力。

- 地理编码转化：将地理描述转化为具体坐标。

- 逆地理编码转化能力：将坐标转化为地理描述。

其中地理编码包含多个属性来描述位置，包括国家、行政区划、街道、门牌号、地址描述等等，这样的信息更便于用户理解。

### 接口说明

进行坐标和地理编码信息的相互转化，所使用的接口说明如下，详细信息参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

**表3** 地理编码转化与逆地理编码转化接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| [isGeocoderAvailable(): boolean;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerisgeocoderavailable) | 判断地理编码与逆地理编码服务是否可用。 | 
| [getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetaddressesfromlocation) | 调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。 | 
| [getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetaddressesfromlocationname) | 调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。 | 

### 开发步骤

> **说明：**
> 地理编码与逆地理编码功能需要访问后端服务，请确保设备联网，以进行信息获取。

1. 导入geoLocationManager模块，所有与地理编码转化&逆地理编码转化能力相关的功能API，都是通过该模块提供的。
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   ```

2. 查询地理编码与逆地理编码服务是否可用。
   - 调用isGeoServiceAvailable查询地理编码与逆地理编码服务是否可用，如果服务可用再继续进行步骤3。如果服务不可用，说明该设备不具备地理编码与逆地理编码能力，请勿使用相关接口。
     
      ```ts
      import { geoLocationManager } from '@kit.LocationKit';
      import { BusinessError } from '@kit.BasicServicesKit'
      try {
          let isAvailable = geoLocationManager.isGeocoderAvailable();
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

3. 获取转化结果。
   - 调用getAddressesFromLocation，把坐标转化为地理位置信息。应用可以获得与此坐标匹配的[GeoAddress](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geoaddress)（地理编码地址信息）列表，应用可以根据实际使用需求，读取相应的参数数据。
     
      ```ts
      let reverseGeocodeRequest:geoLocationManager.ReverseGeoCodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocation err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocation data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

   - 调用getAddressesFromLocationName把位置描述转化为坐标。
     
      ```ts
      let geocodeRequest:geoLocationManager.GeoCodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocationName err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocationName data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + JSON.stringify(err));
      }
      ```

      应用可以获得与位置描述相匹配的[GeoAddress](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geoaddress)（地理编码地址信息）列表，其中包含对应的坐标数据。

      如果需要查询的位置描述可能出现多地重名的请求，可以设置GeoCodeRequest，通过设置一个经纬度范围，以高效地获取期望的准确结果。


## 地理围栏开发指导

### 场景概述

地理围栏就是虚拟地理边界，当设备进入、离开某个特定地理区域时，可以接收自动通知和警告。

目前仅支持圆形围栏，并且依赖GNSS芯片的地理围栏功能，仅在室外开阔区域才能准确识别用户进出围栏事件。

应用场景举例：开发者可以使用地理围栏，在企业周围创建一个区域进行广告定位，在不同的地点，在移动设备上进行有针对性的促销优惠。

### 接口说明

地理围栏所使用的接口如下，详细说明参见：[Location Kit](../../reference/apis-location-kit/js-apis-geoLocationManager.md)。

**表4** 地理围栏接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| [on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagerongnssfencestatuschange) | 添加一个围栏，并订阅地理围栏事件。 | 
| [off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;](../../reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageroffgnssfencestatuschange) | 删除一个围栏，并取消订阅该围栏事件。 | 

### 开发步骤

1. 使用地理围栏功能，需要有权限ohos.permission.APPROXIMATELY_LOCATION，位置权限申请的方法和步骤见[申请位置权限开发指导](#申请位置权限开发指导)。

2. 导入geoLocationManager模块、wantAgent模块和BusinessError模块。
   
   ```ts
   import { geoLocationManager } from '@kit.LocationKit';
   import { wantAgent } from '@kit.AbilityKit';
   import { BusinessError } from '@kit.BasicServicesKit'
   ```

3. 创建WantAgentInfo信息。

   场景一：创建拉起Ability的WantAgentInfo信息。

   ```ts
   let wantAgentObj:_wantAgent|null = null; // 用于保存创建成功的wantAgent对象，后续使用其完成触发的动作。
   
   // 通过WantAgentInfo的operationType设置动作类型
   let wantAgentInfo:wantAgent.WantAgentInfo = {
       wants: [
           {
               deviceId: '',
               bundleName: 'com.example.myapplication',
               abilityName: 'EntryAbility',
               action: '',
               entities: [],
               uri: '',
               parameters: {}
           }
       ],
       operationType: wantAgent.OperationType.START_ABILITY,
       requestCode: 0,
       wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
   };
   ```

   场景二：创建发布公共事件的WantAgentInfo信息。

   ```ts
   let wantAgentObj:_wantAgent|null = null; // 用于保存创建成功的WantAgent对象，后续使用其完成触发的动作。
   
   // 通过WantAgentInfo的operationType设置动作类型
   let wantAgentInfo:wantAgent.WantAgentInfo = {
       wants: [
           {
               action: 'event_name', // 设置事件名
               parameters: {},
           }
       ],
       operationType: wantAgent.OperationType.SEND_COMMON_EVENT,
       requestCode: 0,
       wantAgentFlags: [wantAgent.WantAgentFlags.CONSTANT_FLAG],
   }
   ```

4. 调用getWantAgent()方法进行创建WantAgent。

   并且在获取到WantAgent对象之后调用地理围栏接口添加围栏，当设备进入或者退出该围栏时，系统会自动触发WantAgent的动作。

   ```ts
   // 创建WantAgent
   wantAgent.getWantAgent(wantAgentInfo, (err, data) => {
       if (err) {
         console.error('getWantAgent err=' + JSON.stringify(err));
         return;
       }
       console.info('getWantAgent success');
       wantAgentObj = data;
       let requestInfo:geoLocationManager.GeofenceRequest = {'scenario': 0x301, "geofence": {"latitude": 31.12, "longitude": 121.11, "radius": 100, "expiration": 10000}};
       try {
           geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
       } catch (err) {
           console.error("errCode:" + JSON.stringify(err));
       }
   });
   ```

## 相关实例

针对位置开发，有以下相关实例可供参考：

- [位置服务（ArkTS）(API9)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Location)