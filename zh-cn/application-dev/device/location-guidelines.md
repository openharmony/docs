# 位置服务开发指南

## 位置服务开发概述

移动终端设备已经深入人们日常生活的方方面面，如查看所在城市的天气、新闻轶事、出行打车、旅行导航、运动记录。这些习以为常的活动，都离不开定位用户终端设备的位置。

当用户处于这些丰富的使用场景中时，系统的位置能力可以提供实时准确的位置数据。对于开发者，设计基于位置体验的服务，也可以使应用的使用体验更贴近每个用户。

当应用在实现基于设备位置的功能时，如：驾车导航，记录运动轨迹等，可以调用该模块的API接口，完成位置信息的获取。

### 位置服务简介

位置子系统使用多种定位技术提供服务，如GNSS定位、基站定位、WLAN/蓝牙定位（基站定位、WLAN/蓝牙定位后续统称“网络定位技术”）；通过这些定位技术，无论用户设备在室内或是户外，都可以准确地确定设备位置。

位置服务除了提供基础的定位服务之外，还提供了地理围栏、地理编码、逆地理编码、国家码等功能和接口。

- **坐标**<br/>
  系统以1984年世界大地坐标系统为参考，使用经度、纬度数据描述地球上的一个位置。

- **GNSS定位**<br/>
  基于全球导航卫星系统，包含：GPS、GLONASS、北斗、Galileo等，通过导航卫星、设备芯片提供的定位算法，来确定设备准确位置。定位过程具体使用哪些定位系统，取决于用户设备的硬件能力。

- **基站定位**<br/>
  根据设备当前驻网基站和相邻基站的位置，估算设备当前位置。此定位方式的定位结果精度相对较低，并且需要设备可以访问蜂窝网络。

- **WLAN、蓝牙定位**<br/>
  根据设备可搜索到的周围WLAN、蓝牙设备位置，估算设备当前位置。此定位方式的定位结果精度依赖设备周围可见的固定WLAN、蓝牙设备的分布，密度较高时，精度也相较于基站定位方式更高，同时也需要设备可以访问网络。

### 运作机制

位置能力作为系统为应用提供的一种基础服务，需要应用在所使用的业务场景，向系统主动发起请求，并在业务场景结束时，主动结束此请求，在此过程中系统会将实时的定位结果上报给应用。

### 约束与限制

使用设备的位置能力，需要用户进行确认并主动开启位置开关。如果位置开关没有开启，系统不会向任何应用提供位置服务。

设备位置信息属于用户敏感数据，所以即使用户已经开启位置开关，应用在获取设备位置前仍需向用户申请位置访问权限。在用户确认允许后，系统才会向应用提供位置服务。

### 相关实例

针对位置服务，有以下相关实例可供参考：

- [`Location`：位置服务（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/BasicFeature/DeviceManagement/Location)


## 申请位置权限开发指导

### 场景概述

应用在使用位置服务系统能力前，需要检查是否已经获取用户授权访问设备位置信息。如未获得授权，可以向用户申请需要的位置权限。

系统提供的定位权限有：

- ohos.permission.LOCATION：用于获取精准位置，精准度在米级别。

- ohos.permission.APPROXIMATELY_LOCATION：用于获取模糊位置，精确度为5公里。

- ohos.permission.LOCATION_IN_BACKGROUND：用于应用切换到后台仍然需要获取定位信息的场景。

访问设备的位置信息，必须申请权限，并且获得用户授权。

**表1** 位置权限申请方式介绍

| target API level | 申请位置权限 | 申请结果 | 位置的精确度 |
| -------- | -------- | -------- | -------- |
| 小于9 | ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |
| 大于等于9 | ohos.permission.LOCATION | 失败 | 无法获取位置。 |
| 大于等于9 | ohos.permission.APPROXIMATELY_LOCATION | 成功 | 获取到模糊位置，精确度为5公里。 |
| 大于等于9 | 同时申请ohos.permission.APPROXIMATELY_LOCATION和ohos.permission.LOCATION | 成功 | 获取到精准位置，精准度在米级别。 |

如果应用在后台运行时也需要访问设备位置，除需要将应用声明为允许后台运行外，还必须申请ohos.permission.LOCATION_IN_BACKGROUND权限，这样应用在切入后台之后，系统可以继续上报位置信息。

开发者可以在应用配置文件中声明所需要的权限，具体可参考[授权申请指导](../security/accesstoken-guidelines.md)。

位置服务每个接口需要申请哪些权限可以参见如下文档：[位置服务](../reference/apis/js-apis-geoLocationManager.md)。

### 开发步骤

具体可参考[授权申请指导](../security/accesstoken-guidelines.md)。


## 获取设备的位置信息开发指导

### 场景概述

开发者可以调用OpenHarmony位置相关接口，获取设备实时位置，或者最近的历史位置。

对于位置敏感的应用业务，建议获取设备实时位置信息。如果不需要设备实时位置信息，并且希望尽可能的节省耗电，开发者可以考虑获取最近的历史位置。

### 接口说明

获取设备的位置信息所使用的接口如下，详细说明参见：[位置服务](../reference/apis/js-apis-geoLocationManager.md)。

**表2** 获取设备的位置信息接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;): void | 开启位置变化订阅，并发起定位请求。 | 
| off(type: 'locationChange', callback?: Callback&lt;Location&gt;): void | 关闭位置变化订阅，并删除对应的定位请求。 | 
| getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;): void | 获取当前位置，使用callback回调异步返回结果。 | 
| getCurrentLocation(request?: CurrentLocationRequest): Promise&lt;Location&gt; | 获取当前位置，使用Promise方式异步返回结果。 | 
| getLastLocation(): Location | 获取最近一次定位结果。 | 

### 开发步骤

1. 获取设备的位置信息，需要有位置权限，位置权限申请的方法和步骤见[申请位置权限开发指导](#申请位置权限开发指导)。

2. 导入geoLocationManager模块，所有与基础定位能力相关的功能API，都是通过该模块提供的。
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   ```

3. 实例化LocationRequest对象，用于告知系统该向应用提供何种类型的位置服务，以及位置结果上报的频率。<br/>
   **方式一：**

   为了面向开发者提供贴近其使用场景的API使用方式，系统定义了几种常见的位置能力使用场景，并针对使用场景做了适当的优化处理，应用可以直接匹配使用，简化开发复杂度。系统当前支持场景如下表所示。

   ***定位场景类型说明***
   
   - 导航场景：NAVIGATION<br/>
   适用于在户外定位设备实时位置的场景，如车载、步行导航。<br/>在此场景下，为保证系统提供位置结果精度最优，主要使用GNSS定位技术提供定位服务，结合场景特点，在导航启动之初，用户很可能在室内、车库等遮蔽环境，GNSS技术很难提供位置服务。<br/>为解决此问题，我们会在GNSS提供稳定位置结果之前，使用系统网络定位技术，向应用提供位置服务，以在导航初始阶段提升用户体验。<br/>此场景默认以最小1秒间隔上报定位结果，使用此场景的应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。
   
   - 轨迹跟踪场景：TRAJECTORY_TRACKING<br/>
   适用于记录用户位置轨迹的场景，如运动类应用记录轨迹功能。主要使用GNSS定位技术提供定位服务。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。
   
   - 出行约车场景：CAR_HAILING<br/>
   适用于用户出行打车时定位当前位置的场景，如网约车类应用。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。
   
   - 生活服务场景：DAILY_LIFE_SERVICE<br/>
   生活服务场景，适用于不需要定位用户精确位置的使用场景，如新闻资讯、网购、点餐类应用，做推荐、推送时定位用户大致位置即可。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用至少申请ohos.permission.LOCATION权限，同时获得用户授权。
   
   - 无功耗场景：NO_POWER<br/>
   无功耗场景，适用于不需要主动启动定位业务。系统在响应其他应用启动定位业务并上报位置结果时，会同时向请求此场景的应用程序上报定位结果，当前的应用程序不产生定位功耗。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用需要申请ohos.permission.LOCATION权限，同时获得用户授权。


   ```ts
       export enum LocationRequestScenario {
            UNSET = 0x300,
            NAVIGATION,
            TRAJECTORY_TRACKING,
            CAR_HAILING,
            DAILY_LIFE_SERVICE,
            NO_POWER,
        }
   ```


   以导航场景为例，实例化方式如下：

   ```ts
   let requestInfo = {'scenario': geoLocationManager.LocationRequestScenario.NAVIGATION, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

   **方式二：**

   如果定义的现有场景类型不能满足所需的开发场景，系统提供了基本的定位优先级策略类型。

   ***定位优先级策略类型说明***

   - 定位精度优先策略：ACCURACY<br/>
      定位精度优先策略主要以GNSS定位技术为主，在开阔场景下可以提供米级的定位精度，具体性能指标依赖用户设备的定位硬件能力，但在室内等强遮蔽定位场景下，无法提供准确的位置服务。

   - 快速定位优先策略：FIRST_FIX<br/>
      快速定位优先策略会同时使用GNSS定位、基站定位和WLAN、蓝牙定位技术，以便室内和户外场景下，通过此策略都可以获得位置结果，当各种定位技术都有提供位置结果时，系统会选择其中精度较好的结果返回给应用。因为对各种定位技术同时使用，对设备的硬件资源消耗较大，功耗也较大。

   - 低功耗定位优先策略：LOW_POWER<br/>
      低功耗定位优先策略主要使用基站定位和WLAN、蓝牙定位技术，也可以同时提供室内和户外场景下的位置服务，因为其依赖周边基站、可见WLAN、蓝牙设备的分布情况，定位结果的精度波动范围较大，如果对定位结果精度要求不高，或者使用场景多在有基站、可见WLAN、蓝牙设备高密度分布的情况下，推荐使用，可以有效节省设备功耗。

   ```ts
       export enum LocationRequestPriority {
            UNSET = 0x200,
            ACCURACY,
            LOW_POWER,
            FIRST_FIX,
        }
   ```

   以定位精度优先策略为例，实例化方式如下：

   ```ts
   let requestInfo = {'priority': geoLocationManager.LocationRequestPriority.ACCURACY, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

4. 实例化Callback对象，用于向系统提供位置上报的途径。
     应用需要自行实现系统定义好的回调接口，并将其实例化。系统在定位成功确定设备的实时位置结果时，会通过该接口上报给应用。应用程序可以在接口的实现中完成自己的业务逻辑。
     
   ```ts
   let locationChange = (location) => {
       console.log('locationChanger: data: ' + JSON.stringify(location));
   };
   ```

5. 启动定位。
   
   ```ts
   geoLocationManager.on('locationChange', requestInfo, locationChange);
   ```

6. （可选）结束定位。

   如果不主动结束定位可能导致设备功耗高，耗电快；建议在不需要获取定位信息时及时结束定位。

   ```ts
   geoLocationManager.off('locationChange', locationChange);
   ```

   如果应用使用场景不需要实时的设备位置，可以获取系统缓存的最近一次历史定位结果。

   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   try {
       let location = geoLocationManager.getLastLocation();
   } catch (err) {
       console.error("errCode:" + err.code + ",errMessage:" + err.message);
   }
   ```


## （逆）地理编码转化开发指导

### 场景概述

使用坐标描述一个位置，非常准确，但是并不直观，面向用户表达并不友好。系统向开发者提供了以下两种转化能力。

- 地理编码转化：将地理描述转化为具体坐标。

- 逆地理编码转化能力：将坐标转化为地理描述。

其中地理编码包含多个属性来描述位置，包括国家、行政区划、街道、门牌号、地址描述等等，这样的信息更便于用户理解。

### 接口说明

进行坐标和地理编码信息的相互转化，所使用的接口说明如下，详细信息参见：[位置服务](../reference/apis/js-apis-geoLocationManager.md)。

**表3** （逆）地理编码转化接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| isGeocoderAvailable(): boolean; | 判断（逆）地理编码服务状态。 | 
| getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void | 调用逆地理编码服务，将坐标转换为地理描述，使用callback回调异步返回结果。 | 
| getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt; | 调用逆地理编码服务，将坐标转换为地理描述，使用Promise方式异步返回结果。 | 
| getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback&lt;Array&lt;GeoAddress&gt;&gt;): void | 调用地理编码服务，将地理描述转换为具体坐标，使用callback回调异步返回结果。 | 
| getAddressesFromLocationName(request: GeoCodeRequest): Promise&lt;Array&lt;GeoAddress&gt;&gt; | 调用地理编码服务，将地理描述转换为具体坐标，使用Promise方式异步返回结果。 | 

### 开发步骤

> **说明：**
> GeoConvert需要访问后端服务，请确保设备联网，以进行信息获取。

1. 导入geoLocationManager模块，所有与（逆）地理编码转化能力相关的功能API，都是通过该模块提供的。
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   ```

2. 查询geoCoder服务是否可用。
   - 调用isGeoServiceAvailable查询geoCoder服务是否可用，如果服务可用再继续进行步骤3。
     
      ```ts
      import geoLocationManager from '@ohos.geoLocationManager';
      try {
          let isAvailable = geoLocationManager.isGeocoderAvailable();
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

3. 获取转化结果。
   - 调用getAddressesFromLocation，坐标转化地理位置信息。
     
      ```ts
      let reverseGeocodeRequest = {"latitude": 31.12, "longitude": 121.11, "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocation(reverseGeocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocation err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocation data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

      参考接口API说明[位置服务](../reference/apis/js-apis-geoLocationManager.md)，应用可以获得与此坐标匹配的GeoAddress列表，应用可以根据实际使用需求，读取相应的参数数据。
   - 调用getAddressesFromLocationName位置描述转化坐标。
     
      ```ts
      let geocodeRequest = {"description": "上海市浦东新区xx路xx号", "maxItems": 1};
      try {
          geoLocationManager.getAddressesFromLocationName(geocodeRequest, (err, data) => {
              if (err) {
                  console.log('getAddressesFromLocationName err: ' + JSON.stringify(err));
              } else {
                  console.log('getAddressesFromLocationName data: ' + JSON.stringify(data));
              }
          });
      } catch (err) {
          console.error("errCode:" + err.code + ",errMessage:" + err.message);
      }
      ```

      参考接口API说明[位置服务](../reference/apis/js-apis-geoLocationManager.md)，应用可以获得与位置描述相匹配的GeoAddress列表，其中包含对应的坐标数据，请参考API使用。

      如果需要查询的位置描述可能出现多地重名的请求，可以设置GeoCodeRequest，通过设置一个经纬度范围，以高效地获取期望的准确结果。


## 地理围栏开发指导

### 场景概述

地理围栏就是虚拟地理边界，当设备进入、离开某个特定地理区域时，可以接收自动通知和警告。

目前仅支持圆形围栏，并且依赖GNSS芯片的地理围栏功能。

应用场景举例：开发者可以使用地理围栏，在企业周围创建一个区域进行广告定位，在不同的地点，在移动设备上进行有针对性的促销优惠。

### 接口说明

地理围栏所使用的接口如下，详细说明参见：[位置服务](../reference/apis/js-apis-geoLocationManager.md)。

**表4** 地理围栏接口介绍

| 接口名 | 功能描述 | 
| -------- | -------- |
| on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | 添加一个围栏，并订阅地理围栏事件。 | 
| off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | 删除一个围栏，并取消订阅该围栏事件。 | 

### 开发步骤

1. 使用地理围栏功能，需要有权限ohos.permission.APPROXIMATELY_LOCATION，位置权限申请的方法和步骤见[申请位置权限开发指导](#申请位置权限开发指导)。

2. 导入[geoLocationManager](../reference/apis/js-apis-geoLocationManager.md)模块和[wantAgent](../reference/apis/js-apis-app-ability-wantAgent.md)模块。
   
   ```ts
   import geoLocationManager from '@ohos.geoLocationManager';
   import wantAgent from '@ohos.app.ability.wantAgent';
   ```

3. 创建[WantAgentInfo](../reference/apis/js-apis-inner-wantAgent-wantAgentInfo.md)信息。

   场景一：创建拉起Ability的WantAgentInfo信息。

   ```ts
   let wantAgentObj = null; // 用于保存创建成功的wantAgent对象，后续使用其完成触发的动作。
   
   // 通过WantAgentInfo的operationType设置动作类型
   let wantAgentInfo = {
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

   场景二：创建发布[公共事件](../application-models/common-event-overview.md)的WantAgentInfo信息。

   ```ts
   let wantAgentObj = null; // 用于保存创建成功的WantAgent对象，后续使用其完成触发的动作。
   
   // 通过WantAgentInfo的operationType设置动作类型
   let wantAgentInfo = {
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

4. 调用[getWantAgent()](../reference/apis/js-apis-app-ability-wantAgent.md#wantagentgetwantagent)方法进行创建WantAgent。

并且在获取到WantAgent对象之后调用地理围栏接口添加围栏。

   ```ts
   // 创建WantAgent
   wantAgent.getWantAgent(wantAgentInfo, (err, data) => {
       if (err) {
         console.error('getWantAgent err=' + JSON.stringify(err));
         return;
       }
       console.info('getWantAgent success');
       wantAgentObj = data;
       let requestInfo = {'priority': 0x201, 'scenario': 0x301, "geofence": {"latitude": 121, "longitude": 26, "radius": 100, "expiration": 10000}};
       try {
           geoLocationManager.on('gnssFenceStatusChange', requestInfo, wantAgentObj);
       } catch (err) {
           console.error("errCode:" + err.code + ",errMessage:" + err.message);
       }
   });
   ```

5. 当设备进入或者退出该围栏时，系统会自动触发WantAgent的动作。

## 相关实例

针对位置开发，有以下相关实例可供参考：

- [位置服务（ArkTS）(API9)](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Release/code/BasicFeature/DeviceManagement/Location)