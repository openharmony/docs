# Location Subsystem Changelog

## cl.location.1 API Migration from @ohos.geolocation.d.ts to @ohos.geoLocationManager.d.ts

APIs in **@ohos.geolocation.d.ts** do not support throwing error codes. To support this function, all APIs in **@ohos.geolocation.d.ts** are migrated to the newly added **@ohos.geoLocationManager.d.ts** file, and corresponding error code description is added.

To use APIs of the location subsystem, you need to import **@ohos.geoLocationManager**.

import geoLocationManager from '@ohos.geoLocationManager';


**Change Impact**

All APIs of the location subsystem are affected. To ensure normal use of these APIs, you need to import **@ohos.geoLocationManager**.

import geoLocationManager from '@ohos.geoLocationManager';

**Key API/Component Changes**

| Class| API Type| Declaration| Change Type| 
|  -- | -- | -- | -- |
|geolocation| method | function on(type: 'locationChange', request: LocationRequest, callback: Callback<Location>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function off(type: 'locationChange', callback?: Callback<Location>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function on(type: 'locationServiceState', callback: Callback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'locationServiceState'** to **type: 'locationEnabledChange'**.| 
|geolocation| method | function off(type: 'locationServiceState', callback?: Callback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'locationServiceState'** to **type: 'locationEnabledChange'**.| 
|geolocation| method | function on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback<Array<Location>>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'cachedGnssLocationsReporting'** to **type: 'cachedGnssLocationsChange'**.| 
|geolocation| method | function off(type: 'cachedGnssLocationsReporting', callback?: Callback<Array<Location>>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'cachedGnssLocationsReporting'** to **type: 'cachedGnssLocationsChange'**.| 
|geolocation| method | function on(type: 'gnssStatusChange', callback: Callback<SatelliteStatusInfo>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'gnssStatusChange'** to **type: 'satelliteStatusChange'**.| 
|geolocation| method | function off(type: 'gnssStatusChange', callback?: Callback<SatelliteStatusInfo>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'gnssStatusChange'** to **type: 'satelliteStatusChange'**.| 
|geolocation| method | function on(type: 'nmeaMessageChange', callback: Callback<string>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'nmeaMessageChange'** to **type: 'nmeaMessage'**.| 
|geolocation| method | function off(type: 'nmeaMessageChange', callback?: Callback<string>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'nmeaMessageChange'** to **type: 'nmeaMessage'**.| 
|geolocation| method | function on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'fenceStatusChange'** to **type: 'gnssFenceStatusChange'**.| 
|geolocation| method | function off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed **type: 'fenceStatusChange'** to **type: 'gnssFenceStatusChange'**.| 
|geolocation| method | function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback<Location>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getCurrentLocation(callback: AsyncCallback<Location>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getCurrentLocation(request?: CurrentLocationRequest): Promise<Location>; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getLastLocation(callback: AsyncCallback<Location>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function getLastLocation(): Location**.| 
|geolocation| method | function getLastLocation(): Promise<Location>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function getLastLocation(): Location**.| 
|geolocation| method | function isLocationEnabled(callback: AsyncCallback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function isLocationEnabled(): boolean**.| 
|geolocation| method | function isLocationEnabled(): Promise<boolean>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function isLocationEnabled(): boolean**.| 
|geolocation| method | function requestEnableLocation(callback: AsyncCallback<boolean>): void; | Deleted.| 
|geolocation| method | function requestEnableLocation(): Promise<boolean>; | Deleted.| 
|geolocation| method | function enableLocation(callback: AsyncCallback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function enableLocation(): Promise<boolean>; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function disableLocation(callback: AsyncCallback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function disableLocation(): void**.| 
|geolocation| method | function disableLocation(): Promise<boolean>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function disableLocation(): void**.| 
|geolocation| method | function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise<Array<GeoAddress>>; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getAddressesFromLocationName(request: GeoCodeRequest): Promise<Array<GeoAddress>>; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function isGeoServiceAvailable(callback: AsyncCallback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function isGeocoderAvailable(): boolean**.| 
|geolocation| method | function isGeoServiceAvailable(): Promise<boolean>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function isGeocoderAvailable(): boolean**.| 
|geolocation| method | function getCachedGnssLocationsSize(callback: AsyncCallback<number>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function getCachedGnssLocationsSize(): Promise<number>; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function flushCachedGnssLocations(callback: AsyncCallback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function flushCachedGnssLocations(): Promise<boolean>; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function sendCommand(command: LocationCommand, callback: AsyncCallback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function sendCommand(command: LocationCommand): Promise<boolean>; | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| method | function enableLocationMock(callback: AsyncCallback<void>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function enableLocationMock(): void**.| 
|geolocation| method | function enableLocationMock(): Promise<void>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function enableLocationMock(): void**.| 
|geolocation| method | function disableLocationMock(callback: AsyncCallback<void>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function disableLocationMock(): void**.| 
|geolocation| method | function disableLocationMock(): Promise<void>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function disableLocationMock(): void**.| 
|geolocation| method | function setMockedLocations(config: LocationMockConfig, callback: AsyncCallback<void>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function setMockedLocations(config: LocationMockConfig): void**.| 
|geolocation| method | function setMockedLocations(config: LocationMockConfig): Promise<void>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function setMockedLocations(config: LocationMockConfig): void**.| 
|geolocation| method | function enableReverseGeocodingMock(callback: AsyncCallback<void>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function enableReverseGeocodingMock(): void**.| 
|geolocation| method | function enableReverseGeocodingMock(): Promise<void>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function enableReverseGeocodingMock(): void**.| 
|geolocation| method | function disableReverseGeocodingMock(callback: AsyncCallback<void>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function disableReverseGeocodingMock(): void**.| 
|geolocation| method | function disableReverseGeocodingMock(): Promise<void>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function disableReverseGeocodingMock(): void**.| 
|geolocation| method | function setReverseGeocodingMockInfo(mockInfos: Array<ReverseGeocodingMockInfo>, callback: AsyncCallback<void>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function setReverseGeocodingMockInfo(mockInfos: Array<ReverseGeocodingMockInfo>): void**.| 
|geolocation| method | function setReverseGeocodingMockInfo(mockInfos: Array<ReverseGeocodingMockInfo>): Promise<void>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function setReverseGeocodingMockInfo(mockInfos: Array<ReverseGeocodingMockInfo>): void**.| 
|geolocation| method | function isLocationPrivacyConfirmed(type: LocationPrivacyType, callback: AsyncCallback<boolean>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean**.| 
|geolocation| method | function isLocationPrivacyConfirmed(type: LocationPrivacyType,): Promise<boolean>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean**.| 
|geolocation| method | function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean, callback: AsyncCallback<void>): void; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void**.| 
|geolocation| method | function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): Promise<void>; | Migrated to **@ohos.geoLocationManager.d.ts** and changed to **function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void**.| 
|geolocation| interface | SatelliteStatusInfo | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | CachedGnssLocationsRequest | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | GeofenceRequest | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | Geofence | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | ReverseGeoCodeRequest | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | GeoCodeRequest | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | GeoAddress | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | LocationRequest | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | CurrentLocationRequest | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| interface | Location | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| enum | LocationRequestPriority | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| enum | LocationRequestScenario | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| enum | GeoLocationErrorCode | Deprecated.| 
|geolocation| enum | LocationPrivacyType | Migrated to **@ohos.geoLocationManager.d.ts**.| 
|geolocation| enum | LocationCommand | Migrated to **@ohos.geoLocationManager.d.ts**.| 


**(Optional) Adaptation Guide**

The following sample code shows how to call **enableLocation** in the new version:

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
