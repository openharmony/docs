# 位置服务子系统ChangeLog

## cl.location.1 @ohos.geolocation.d.ts接口迁移到新增的@ohos.geoLocationManager.d.ts

@ohos.geolocation.d.ts接口不支持抛出错误码，为了支持错误码功能，把@ohos.geolocation.d.ts中所有接口，迁移到新增的@ohos.geoLocationManager.d.ts中，并增加错误码描述。

后续需要import @ohos.geoLocationManager才能使用位置服务的接口：

import geoLocationManager from '@ohos.geoLocationManager';


**变更影响**

对位置服务所有接口的使用有影响，需要import @ohos.geoLocationManager才能使用位置服务接口：

import geoLocationManager from '@ohos.geoLocationManager';

**关键的接口/组件变更**

| 类名 | 接口类型 | 接口声明 | 变更类型 | 
|  -- | -- | -- | -- |
|geolocation| namespace | declare namespace geolocation| 迁移到@ohos.geoLocationManager.d.ts，使用namespace geoLocationManager代替 | 
|geolocation| method | function on(type: 'locationChange', request: LocationRequest, callback: Callback<Location>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function off(type: 'locationChange', callback?: Callback<Location>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function on(type: 'locationServiceState', callback: Callback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function off(type: 'locationServiceState', callback?: Callback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback<Array<Location>>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function off(type: 'cachedGnssLocationsReporting', callback?: Callback<Array<Location>>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function on(type: 'gnssStatusChange', callback: Callback<SatelliteStatusInfo>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function off(type: 'gnssStatusChange', callback?: Callback<SatelliteStatusInfo>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function on(type: 'nmeaMessageChange', callback: Callback<string>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function off(type: 'nmeaMessageChange', callback?: Callback<string>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback<Location>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getCurrentLocation(callback: AsyncCallback<Location>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getCurrentLocation(request?: CurrentLocationRequest): Promise<Location>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getLastLocation(callback: AsyncCallback<Location>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getLastLocation(): Promise<Location>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function isLocationEnabled(callback: AsyncCallback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function isLocationEnabled(): Promise<boolean>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function requestEnableLocation(callback: AsyncCallback<boolean>): void; | 接口删除 | 
|geolocation| method | function requestEnableLocation(): Promise<boolean>; | 接口删除 | 
|geolocation| method | function enableLocation(callback: AsyncCallback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function enableLocation(): Promise<boolean>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function disableLocation(callback: AsyncCallback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function disableLocation(): Promise<boolean>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise<Array<GeoAddress>>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getAddressesFromLocationName(request: GeoCodeRequest): Promise<Array<GeoAddress>>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function isGeoServiceAvailable(callback: AsyncCallback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function isGeoServiceAvailable(): Promise<boolean>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getCachedGnssLocationsSize(callback: AsyncCallback<number>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function getCachedGnssLocationsSize(): Promise<number>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function flushCachedGnssLocations(callback: AsyncCallback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function flushCachedGnssLocations(): Promise<boolean>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function sendCommand(command: LocationCommand, callback: AsyncCallback<boolean>): void; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| method | function sendCommand(command: LocationCommand): Promise<boolean>; | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | SatelliteStatusInfo | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | CachedGnssLocationsRequest | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | GeofenceRequest | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | Geofence | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | ReverseGeoCodeRequest | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | GeoCodeRequest | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | GeoAddress | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | LocationRequest | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | CurrentLocationRequest | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| interface | Location | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| enum | LocationRequestPriority | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| enum | LocationRequestScenario | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| enum | GeoLocationErrorCode | 接口废弃 | 
|geolocation| enum | LocationPrivacyType | 接口迁移到@ohos.geoLocationManager.d.ts | 
|geolocation| enum | LocationCommand | 接口迁移到@ohos.geoLocationManager.d.ts | 


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