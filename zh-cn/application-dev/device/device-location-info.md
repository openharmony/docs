# 获取设备的位置信息


## 场景介绍

开发者可以调用OpenHarmony位置相关接口，获取设备实时位置，或者最近的历史位置。

对于位置敏感的应用业务，建议获取设备实时位置信息。如果不需要设备实时位置信息，并且希望尽可能的节省耗电，开发者可以考虑获取最近的历史位置。


## 接口说明

获取设备的位置信息，所使用的接口说明如下。

  **表1** 获取位置信息API功能介绍

| 接口名                                                       | 功能描述                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| on(type: 'locationChange', request: LocationRequest, callback: Callback&lt;Location&gt;) : void | 开启位置变化订阅，并发起定位请求。                           |
| off(type: 'locationChange', callback?: Callback&lt;Location&gt;) : void | 关闭位置变化订阅，并删除对应的定位请求。                     |
| on(type: 'locationServiceState', callback: Callback&lt;boolean&gt;) : void | 订阅位置服务状态变化。                                       |
| off(type: 'locationServiceState', callback: Callback&lt;boolean&gt;) : void | 取消订阅位置服务状态变化。                                   |
| on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback&lt;Array&lt;Location&gt;&gt;) : void; | 订阅缓存GNSS位置上报。                                       |
| off(type: 'cachedGnssLocationsReporting', callback?: Callback&lt;Array&lt;Location&gt;&gt;) : void; | 取消订阅缓存GNSS位置上报。                                   |
| on(type: 'gnssStatusChange', callback: Callback&lt;SatelliteStatusInfo&gt;) : void; | 订阅卫星状态信息更新事件。                                   |
| off(type: 'gnssStatusChange', callback?: Callback&lt;SatelliteStatusInfo&gt;) : void; | 取消订阅卫星状态信息更新事件。                               |
| on(type: 'nmeaMessageChange', callback: Callback&lt;string&gt;) : void; | 订阅GNSS NMEA信息上报。                                      |
| off(type: 'nmeaMessageChange', callback?: Callback&lt;string&gt;) : void; | 取消订阅GNSS NMEA信息上报。                                  |
| on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | 添加围栏，并订阅该围栏事件上报。                             |
| off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | 删除围栏，并取消订阅该围栏事件。                             |
| getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback&lt;Location&gt;) : void | 获取当前位置，使用callback回调异步返回结果。                 |
| getCurrentLocation(request?: CurrentLocationRequest) : Promise&lt;Location&gt; | 获取当前位置，使用Promise方式异步返回结果。                  |
| getLastLocation(callback: AsyncCallback&lt;Location&gt;) : void | 获取上一次位置，使用callback回调异步返回结果。               |
| getLastLocation() : Promise&lt;Location&gt;                  | 获取上一次位置，使用Promise方式异步返回结果。                |
| isLocationEnabled(callback: AsyncCallback&lt;boolean&gt;) : void | 判断位置服务是否已经打开，使用callback回调异步返回结果。     |
| isLocationEnabled() : Promise&lt;boolean&gt;                 | 判断位置服务是否已经开启，使用Promise方式异步返回结果。      |
| requestEnableLocation(callback: AsyncCallback&lt;boolean&gt;) : void | 请求打开位置服务，使用callback回调异步返回结果。             |
| requestEnableLocation() : Promise&lt;boolean&gt;             | 请求打开位置服务，使用Promise方式异步返回结果。              |
| enableLocation(callback: AsyncCallback&lt;boolean&gt;) : void | 打开位置服务，使用callback回调异步返回结果。                 |
| enableLocation() : Promise&lt;boolean&gt;                    | 打开位置服务，使用Promise方式异步返回结果。                  |
| disableLocation(callback: AsyncCallback&lt;boolean&gt;) : void | 关闭位置服务，使用callback回调异步返回结果。                 |
| disableLocation() : Promise&lt;boolean&gt;                   | 关闭位置服务，使用Promise方式异步返回结果。                  |
| getCachedGnssLocationsSize(callback: AsyncCallback&lt;number&gt;) : void; | 获取缓存GNSS位置的个数，使用callback回调异步返回结果。       |
| getCachedGnssLocationsSize() : Promise&lt;number&gt;;        | 获取缓存GNSS位置的个数，使用Promise方式异步返回结果。        |
| flushCachedGnssLocations(callback: AsyncCallback&lt;boolean&gt;) : void; | 获取所有的GNSS缓存位置，并清空GNSS缓存队列，使用callback回调异步返回结果。 |
| flushCachedGnssLocations() : Promise&lt;boolean&gt;;         | 获取所有的GNSS缓存位置，并清空GNSS缓存队列，使用Promise方式异步返回结果。 |
| sendCommand(command: LocationCommand, callback: AsyncCallback&lt;boolean&gt;) : void; | 给位置服务子系统发送扩展命令，使用callback回调异步返回结果。 |
| sendCommand(command: LocationCommand) : Promise&lt;boolean&gt;; | 给位置服务子系统发送扩展命令，使用Promise方式异步返回结果。  |
| isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback&lt;boolean&gt;) : void; | 查询用户是否同意定位服务的隐私申明，使用callback回调异步返回结果。 |
| isLocationPrivacyConfirmed(type : LocationPrivacyType,) : Promise&lt;boolean&gt;; | 查询用户是否同意定位服务的隐私申明，使用Promise方式异步返回结果。 |
| setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean, callback: AsyncCallback&lt;boolean&gt;) : void; | 设置并记录用户是否同意定位服务的隐私申明，使用callback回调异步返回结果。 |
| setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean) : Promise&lt;boolean&gt;; | 设置并记录用户是否同意定位服务的隐私申明，使用Promise方式异步返回结果。 |


## 开发步骤

如需要获取设备位置相关接口信息，请参考[位置服务](../reference/apis/js-apis-geolocation.md)。

1. 应用在使用系统能力前，需要检查是否已经获取用户授权访问设备位置信息。如未获得授权，可以向用户申请需要的位置权限，申请方式请参考下文。
     系统提供的定位权限有：
   - ohos.permission.LOCATION
   
   - ohos.permission.LOCATION_IN_BACKGROUND

   访问设备的位置信息，必须申请ohos.permission.LOCATION权限，并且获得用户授权。

   如果应用在后台运行时也需要访问设备位置，除需要将应用声明为允许后台运行外，还必须申请ohos.permission.LOCATION_IN_BACKGROUND权限，这样应用在切入后台之后，系统可以继续上报位置信息。

   开发者可以在应用配置文件中声明所需要的权限，具体可参考[授权申请指导](../security/accesstoken-guidelines.md)。

2. 导入geolocation模块，所有与基础定位能力相关的功能API，都是通过该模块提供的。
   
   ```
   import geolocation from '@ohos.geolocation';
   ```

3. 实例化LocationRequest对象，用于告知系统该向应用提供何种类型的位置服务，以及位置结果上报的频率。<br/>
   **方式一：**

   为了面向开发者提供贴近其使用场景的API使用方式，系统定义了几种常见的位置能力使用场景，并针对使用场景做了适当的优化处理，应用可以直接匹配使用，简化开发复杂度。系统当前支持场景如下表所示。

   
   ```
       export enum LocationRequestScenario {
            UNSET = 0x300,
            NAVIGATION,
            TRAJECTORY_TRACKING,
            CAR_HAILING,
            DAILY_LIFE_SERVICE,
            NO_POWER,
        }
   ```

   
     **表2** 定位场景类型说明
   
   | 场景名称     | 常量定义            | 说明                                                         |
   | ------------ | ------------------- | ------------------------------------------------------------ |
   | 导航场景     | NAVIGATION          | 适用于在户外定位设备实时位置的场景，如车载、步行导航。在此场景下，为保证系统提供位置结果精度最优，主要使用GNSS定位技术提供定位服务，结合场景特点，在导航启动之初，用户很可能在室内、车库等遮蔽环境，GNSS技术很难提供位置服务。为解决此问题，我们会在GNSS提供稳定位置结果之前，使用系统网络定位技术，向应用提供位置服务，以在导航初始阶段提升用户体验。<br/>此场景默认以最小1秒间隔上报定位结果，使用此场景的应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。 |
   | 轨迹跟踪场景 | TRAJECTORY_TRACKING | 适用于记录用户位置轨迹的场景，如运动类应用记录轨迹功能。主要使用GNSS定位技术提供定位服务。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。 |
   | 出行约车场景 | CAR_HAILING         | 适用于用户出行打车时定位当前位置的场景，如网约车类应用。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。 |
   | 生活服务场景 | DAILY_LIFE_SERVICE  | 生活服务场景，适用于不需要定位用户精确位置的使用场景，如新闻资讯、网购、点餐类应用，做推荐、推送时定位用户大致位置即可。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用至少申请ohos.permission.LOCATION权限，同时获得用户授权。 |
   | 无功耗场景   | NO_POWER            | 无功耗场景，适用于不需要主动启动定位业务。系统在响应其他应用启动定位业务并上报位置结果时，会同时向请求此场景的应用程序上报定位结果，当前的应用程序不产生定位功耗。<br/>此场景默认以最小1秒间隔上报定位结果，并且应用需要申请ohos.permission.LOCATION权限，同时获得用户授权。 |

     以导航场景为例，实例化方式如下：
   
   ```
   var requestInfo = {'scenario': geolocation.LocationRequestScenario.NAVIGATION, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

   **方式二：**

   如果定义的现有场景类型不能满足所需的开发场景，系统提供了基本的定位优先级策略类型。

   
   ```
       export enum LocationRequestPriority {
            UNSET = 0x200,
            ACCURACY,
            LOW_POWER,
            FIRST_FIX,
        }
   ```

   
     **表3** 定位优先级策略类型说明：
   
   | 策略类型           | 常量定义       | 说明                                                         |
   | ------------------ | -------------- | ------------------------------------------------------------ |
   | 定位精度优先策略   | ACCURACY       | 定位精度优先策略主要以GNSS定位技术为主，在开阔场景下可以提供米级的定位精度，具体性能指标依赖用户设备的定位硬件能力，但在室内等强遮蔽定位场景下，无法提供准确的位置服务。<br/>应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。 |
   | 快速定位优先策略   | FAST_FIRST_FIX | 快速定位优先策略会同时使用GNSS定位、基站定位和WLAN、蓝牙定位技术，以便室内和户外场景下，通过此策略都可以获得位置结果，当各种定位技术都有提供位置结果时，系统会选择其中精度较好的结果返回给应用。因为对各种定位技术同时使用，对设备的硬件资源消耗较大，功耗也较大。<br/>应用必须申请ohos.permission.LOCATION权限，同时获得用户授权。 |
   | 低功耗定位优先策略 | LOW_POWER      | 低功耗定位优先策略主要使用基站定位和WLAN、蓝牙定位技术，也可以同时提供室内和户外场景下的位置服务，因为其依赖周边基站、可见WLAN、蓝牙设备的分布情况，定位结果的精度波动范围较大，如果对定位结果精度要求不高，或者使用场景多在有基站、可见WLAN、蓝牙设备高密度分布的情况下，推荐使用，可以有效节省设备功耗。<br/>应用至少申请ohos.permission.LOCATION权限，同时获得用户授权。 |

     以定位精度优先策略为例，实例化方式如下：
   
   ```
   var requestInfo = {'priority': geolocation.LocationRequestPriority.ACCURACY, 'timeInterval': 0, 'distanceInterval': 0, 'maxAccuracy': 0};
   ```

4. 实例化Callback对象，用于向系统提供位置上报的途径。
     应用需要自行实现系统定义好的回调接口，并将其实例化。系统在定位成功确定设备的实时位置结果时，会通过该接口上报给应用。应用程序可以在接口的实现中完成自己的业务逻辑。
     
   ```
   var locationChange = (location) => {
       console.log('locationChanger: data: ' + JSON.stringify(location));
   };
   ```

5. 启动定位。
   
   ```
   geolocation.on('locationChange', requestInfo, locationChange);
   ```

6. （可选）结束定位。
   
   ```
   geolocation.off('locationChange', locationChange);
   ```

如果应用使用场景不需要实时的设备位置，可以获取系统缓存的最近一次历史定位结果。
     
   ```
   geolocation.getLastLocation((err, data) => {
       if (err) {
           console.log('getLastLocation: err: ' + JSON.stringify(err));
       } else {
           console.log('getLastLocation: data: ' + JSON.stringify(data));
       }
   });
   ```

   此接口的使用需要应用向用户申请ohos.permission.LOCATION权限。