# 位置服务子系统ChangeLog

## cl.location.1 @system.geolocation.d.ts接口迁移到新增的@ohos.geoLocationManager.d.ts

@system.geolocation.d.ts接口不支持抛出错误码，为了支持错误码功能，把@system.geolocation.d.ts中所有接口，迁移到新增的@ohos.geoLocationManager.d.ts中，并增加错误码描述。

后续需要import @ohos.geoLocationManager才能使用位置服务的接口：

import geoLocationManager from '@ohos.geoLocationManager';


**变更影响**

对位置服务所有接口的使用有影响，需要import @ohos.geoLocationManager才能使用位置服务接口：

import geoLocationManager from '@ohos.geoLocationManager';

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
|Geolocation| class | Geolocation | 接口迁移到@ohos.geoLocationManager.d.ts，使用ohos.geoLocationManager/geoLocationManager代替 | 
|Geolocation| interface | static getLocation(options?: GetLocationOption): void; | 接口迁移到@ohos.geoLocationManager.d.ts，使用ohos.geoLocationManager/geoLocationManager.getCurrentLocation代替 | 
|Geolocation| interface | static getLocationType(options?: GetLocationTypeOption): void; | 接口废弃 | 
|Geolocation| interface | static subscribe(options: SubscribeLocationOption): void; |  接口迁移到@ohos.geoLocationManager.d.ts，使用ohos.geoLocationManager/geoLocationManager.on#event:locationChange代替 | 
|Geolocation| interface | static unsubscribe(): void; |  接口迁移到@ohos.geoLocationManager.d.ts，使用ohos.geoLocationManager/geoLocationManager.off#event:locationChange代替 | 
|Geolocation| interface | static getSupportedCoordTypes(): Array<string>; |  接口废弃 | 
|| interface | GeolocationResponse| 迁移到@ohos.geoLocationManager.d.ts，使用ohos.geoLocationManager/geoLocationManager.Location代替 | 
|| interface | GetLocationOption | 接口迁移到@ohos.geoLocationManager.d.ts，使用ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest代替 | 
|| interface | GetLocationTypeResponse | 接口废弃 | 
|| interface | GetLocationTypeOption | 接口废弃 | 
|| interface | SubscribeLocationOption | 接口迁移到@ohos.geoLocationManager.d.ts，使用ohos.geoLocationManager/geoLocationManager.LocationRequest代替 | 


**适配指导（可选，不涉及则可以删除）**

以enableLocation为例，在新版本上需要使用如下方式进行调用：

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