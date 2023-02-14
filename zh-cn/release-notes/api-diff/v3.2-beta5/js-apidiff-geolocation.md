| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：geoLocationManager<br>方法or属性：function on(type: 'locationChange', request: LocationRequest, callback: Callback<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function off(type: 'locationChange', callback?: Callback<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function on(type: 'locationEnabledChange', callback: Callback<boolean>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function off(type: 'locationEnabledChange', callback?: Callback<boolean>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback<Array<Location>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function off(type: 'cachedGnssLocationsChange', callback?: Callback<Array<Location>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function on(type: 'satelliteStatusChange', callback: Callback<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function off(type: 'satelliteStatusChange', callback?: Callback<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function on(type: 'nmeaMessage', callback: Callback<string>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function off(type: 'nmeaMessage', callback?: Callback<string>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getCurrentLocation(callback: AsyncCallback<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise<Location>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getLastLocation(): Location;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function isLocationEnabled(): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function disableLocation(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise<Array<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise<Array<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function isGeocoderAvailable(): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getCachedGnssLocationsSize(callback: AsyncCallback<number>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function getCachedGnssLocationsSize(): Promise<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function flushCachedGnssLocations(callback: AsyncCallback<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function flushCachedGnssLocations(): Promise<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function sendCommand(command: LocationCommand, callback: AsyncCallback<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function sendCommand(command: LocationCommand): Promise<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function enableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function disableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function setMockedLocations(config: LocationMockConfig): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function enableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function disableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function setReverseGeocodingMockInfo(mockInfos: Array<ReverseGeocodingMockInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager<br>方法or属性：function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;|@ohos.geoLocationManager.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function enableLocation(callback: AsyncCallback<boolean>): void;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function enableLocation(): Promise<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function disableLocation(callback: AsyncCallback<boolean>): void;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function disableLocation(): Promise<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geoLocationManager<br>类名:GeofenceRequest<br>方法 or 属性:priority: LocationRequestPriority;|NA|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：ReverseGeocodingMockInfo<br>方法 or 属性：location: ReverseGeoCodeRequest;<br>访问级别：公开API|类名：ReverseGeocodingMockInfo<br>方法 or 属性：location: ReverseGeoCodeRequest;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：ReverseGeocodingMockInfo<br>方法 or 属性：geoAddress: GeoAddress;<br>访问级别：公开API|类名：ReverseGeocodingMockInfo<br>方法 or 属性：geoAddress: GeoAddress;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationMockConfig<br>方法 or 属性：timeInterval: number;<br>访问级别：公开API|类名：LocationMockConfig<br>方法 or 属性：timeInterval: number;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationMockConfig<br>方法 or 属性：locations: Array<Location>;<br>访问级别：公开API|类名：LocationMockConfig<br>方法 or 属性：locations: Array<Location>;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：GeoAddress<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：公开API|类名：GeoAddress<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：Location<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：公开API|类名：Location<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>访问级别：公开API|类名：LocationPrivacyType<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>方法 or 属性：OTHERS = 0<br>访问级别：公开API|类名：LocationPrivacyType<br>方法 or 属性：OTHERS = 0<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>方法 or 属性：STARTUP<br>访问级别：公开API|类名：LocationPrivacyType<br>方法 or 属性：STARTUP<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>方法 or 属性：CORE_LOCATION<br>访问级别：公开API|类名：LocationPrivacyType<br>方法 or 属性：CORE_LOCATION<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|废弃版本有变化|类名：geolocation<br>废弃版本：N/A|类名：geolocation<br>废弃版本：9<br>代替接口：N/A|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function on(type: 'locationChange', request: LocationRequest, callback: Callback<Location>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function on(type: 'locationChange', request: LocationRequest, callback: Callback<Location>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.on|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function off(type: 'locationChange', callback?: Callback<Location>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function off(type: 'locationChange', callback?: Callback<Location>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.off|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function on(type: 'locationServiceState', callback: Callback<boolean>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function on(type: 'locationServiceState', callback: Callback<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.on|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function off(type: 'locationServiceState', callback?: Callback<boolean>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function off(type: 'locationServiceState', callback?: Callback<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.off|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback<Array<Location>>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback<Array<Location>>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.on|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function off(type: 'cachedGnssLocationsReporting', callback?: Callback<Array<Location>>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function off(type: 'cachedGnssLocationsReporting', callback?: Callback<Array<Location>>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.off|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function on(type: 'gnssStatusChange', callback: Callback<SatelliteStatusInfo>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function on(type: 'gnssStatusChange', callback: Callback<SatelliteStatusInfo>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.on|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function off(type: 'gnssStatusChange', callback?: Callback<SatelliteStatusInfo>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function off(type: 'gnssStatusChange', callback?: Callback<SatelliteStatusInfo>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.off|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function on(type: 'nmeaMessageChange', callback: Callback<string>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function on(type: 'nmeaMessageChange', callback: Callback<string>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.on|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function off(type: 'nmeaMessageChange', callback?: Callback<string>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function off(type: 'nmeaMessageChange', callback?: Callback<string>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.off|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.on|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.off|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback<Location>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback<Location>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.getCurrentLocation     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getCurrentLocation(callback: AsyncCallback<Location>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getCurrentLocation(callback: AsyncCallback<Location>): void;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise<Location>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise<Location>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getLastLocation(callback: AsyncCallback<Location>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getLastLocation(callback: AsyncCallback<Location>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.getLastLocation     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getLastLocation(): Promise<Location>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getLastLocation(): Promise<Location>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function isLocationEnabled(callback: AsyncCallback<boolean>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function isLocationEnabled(callback: AsyncCallback<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.isLocationEnabled     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function isLocationEnabled(): Promise<boolean>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function isLocationEnabled(): Promise<boolean>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function requestEnableLocation(callback: AsyncCallback<boolean>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function requestEnableLocation(callback: AsyncCallback<boolean>): void;<br>废弃版本：9<br>代替接口：N/A|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function requestEnableLocation(): Promise<boolean>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function requestEnableLocation(): Promise<boolean>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.getAddressesFromLocation     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise<Array<GeoAddress>>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise<Array<GeoAddress>>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback<Array<GeoAddress>>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.getAddressesFromLocationName     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise<Array<GeoAddress>>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise<Array<GeoAddress>>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function isGeoServiceAvailable(callback: AsyncCallback<boolean>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function isGeoServiceAvailable(callback: AsyncCallback<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.isGeocoderAvailable     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function isGeoServiceAvailable(): Promise<boolean>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function isGeoServiceAvailable(): Promise<boolean>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getCachedGnssLocationsSize(callback: AsyncCallback<number>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getCachedGnssLocationsSize(callback: AsyncCallback<number>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.getCachedGnssLocationsSize     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function getCachedGnssLocationsSize(): Promise<number>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function getCachedGnssLocationsSize(): Promise<number>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function flushCachedGnssLocations(callback: AsyncCallback<boolean>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function flushCachedGnssLocations(callback: AsyncCallback<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.flushCachedGnssLocations     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function flushCachedGnssLocations(): Promise<boolean>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function flushCachedGnssLocations(): Promise<boolean>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function sendCommand(command: LocationCommand, callback: AsyncCallback<boolean>): void;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function sendCommand(command: LocationCommand, callback: AsyncCallback<boolean>): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.sendCommand     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>方法 or 属性：function sendCommand(command: LocationCommand): Promise<boolean>;<br>废弃版本：N/A|类名：geolocation<br>方法 or 属性：function sendCommand(command: LocationCommand): Promise<boolean>;<br>废弃版本：9|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo<br>废弃版本：N/A|类名：SatelliteStatusInfo<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CachedGnssLocationsRequest<br>废弃版本：N/A|类名：CachedGnssLocationsRequest<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.CachedGnssLocationsRequest     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeofenceRequest<br>废弃版本：N/A|类名：GeofenceRequest<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.GeofenceRequest     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Geofence<br>废弃版本：N/A|类名：Geofence<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.Geofence     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：ReverseGeoCodeRequest<br>废弃版本：N/A|类名：ReverseGeoCodeRequest<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest<br>废弃版本：N/A|类名：GeoCodeRequest<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.GeoCodeRequest     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress<br>废弃版本：N/A|类名：GeoAddress<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.GeoAddress     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequest<br>废弃版本：N/A|类名：LocationRequest<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.LocationRequest     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CurrentLocationRequest<br>废弃版本：N/A|类名：CurrentLocationRequest<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location<br>废弃版本：N/A|类名：Location<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.Location     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestPriority<br>废弃版本：N/A|类名：LocationRequestPriority<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.LocationRequestPriority     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario<br>废弃版本：N/A|类名：LocationRequestScenario<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.LocationRequestScenario     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode<br>废弃版本：N/A|类名：GeoLocationErrorCode<br>废弃版本：9<br>代替接口：N/A|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationPrivacyType<br>废弃版本：N/A|类名：LocationPrivacyType<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.LocationPrivacyType     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationCommand<br>废弃版本：N/A|类名：LocationCommand<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.LocationCommand     |@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeolocationResponse<br>废弃版本：N/A|类名：GeolocationResponse<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.Location |@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationOption<br>废弃版本：N/A|类名：GetLocationOption<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest |@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeResponse<br>废弃版本：N/A|类名：GetLocationTypeResponse<br>废弃版本：9<br>代替接口：N/A|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeOption<br>废弃版本：N/A|类名：GetLocationTypeOption<br>废弃版本：9<br>代替接口：N/A|@system.geolocation.d.ts|
|废弃版本有变化|类名：SubscribeLocationOption<br>废弃版本：N/A|类名：SubscribeLocationOption<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.LocationRequest |@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation<br>废弃版本：N/A|类名：Geolocation<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager |@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation<br>方法 or 属性：static getLocation(options?: GetLocationOption): void;<br>废弃版本：N/A|类名：Geolocation<br>方法 or 属性：static getLocation(options?: GetLocationOption): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.getCurrentLocation   |@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation<br>方法 or 属性：static getLocationType(options?: GetLocationTypeOption): void;<br>废弃版本：N/A|类名：Geolocation<br>方法 or 属性：static getLocationType(options?: GetLocationTypeOption): void;<br>废弃版本：9<br>代替接口：N/A|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation<br>方法 or 属性：static subscribe(options: SubscribeLocationOption): void;<br>废弃版本：N/A|类名：Geolocation<br>方法 or 属性：static subscribe(options: SubscribeLocationOption): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.on|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation<br>方法 or 属性：static unsubscribe(): void;<br>废弃版本：N/A|类名：Geolocation<br>方法 or 属性：static unsubscribe(): void;<br>废弃版本：9<br>代替接口：ohos.geoLocationManager/geoLocationManager.off|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation<br>方法 or 属性：static getSupportedCoordTypes(): Array<string>;<br>废弃版本：N/A|类名：Geolocation<br>方法 or 属性：static getSupportedCoordTypes(): Array<string>;<br>废弃版本：9<br>代替接口：N/A|@system.geolocation.d.ts|
|起始版本有变化|类名：ReverseGeocodingMockInfo<br>方法 or 属性：location: ReverseGeoCodeRequest;<br>起始版本：N/A|类名：ReverseGeocodingMockInfo<br>方法 or 属性：location: ReverseGeoCodeRequest;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：ReverseGeocodingMockInfo<br>方法 or 属性：geoAddress: GeoAddress;<br>起始版本：N/A|类名：ReverseGeocodingMockInfo<br>方法 or 属性：geoAddress: GeoAddress;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationMockConfig<br>方法 or 属性：timeInterval: number;<br>起始版本：N/A|类名：LocationMockConfig<br>方法 or 属性：timeInterval: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationMockConfig<br>方法 or 属性：locations: Array<Location>;<br>起始版本：N/A|类名：LocationMockConfig<br>方法 or 属性：locations: Array<Location>;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：SatelliteStatusInfo<br>方法 or 属性：satellitesNumber: number;<br>起始版本：N/A|类名：SatelliteStatusInfo<br>方法 or 属性：satellitesNumber: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：SatelliteStatusInfo<br>方法 or 属性：satelliteIds: Array<number>;<br>起始版本：N/A|类名：SatelliteStatusInfo<br>方法 or 属性：satelliteIds: Array<number>;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：SatelliteStatusInfo<br>方法 or 属性：carrierToNoiseDensitys: Array<number>;<br>起始版本：N/A|类名：SatelliteStatusInfo<br>方法 or 属性：carrierToNoiseDensitys: Array<number>;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：SatelliteStatusInfo<br>方法 or 属性：altitudes: Array<number>;<br>起始版本：N/A|类名：SatelliteStatusInfo<br>方法 or 属性：altitudes: Array<number>;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：SatelliteStatusInfo<br>方法 or 属性：azimuths: Array<number>;<br>起始版本：N/A|类名：SatelliteStatusInfo<br>方法 or 属性：azimuths: Array<number>;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：SatelliteStatusInfo<br>方法 or 属性：carrierFrequencies: Array<number>;<br>起始版本：N/A|类名：SatelliteStatusInfo<br>方法 or 属性：carrierFrequencies: Array<number>;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CachedGnssLocationsRequest<br>方法 or 属性：reportingPeriodSec: number;<br>起始版本：N/A|类名：CachedGnssLocationsRequest<br>方法 or 属性：reportingPeriodSec: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CachedGnssLocationsRequest<br>方法 or 属性：wakeUpCacheQueueFull: boolean;<br>起始版本：N/A|类名：CachedGnssLocationsRequest<br>方法 or 属性：wakeUpCacheQueueFull: boolean;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeofenceRequest<br>方法 or 属性：scenario: LocationRequestScenario;<br>起始版本：N/A|类名：GeofenceRequest<br>方法 or 属性：scenario: LocationRequestScenario;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeofenceRequest<br>方法 or 属性：geofence: Geofence;<br>起始版本：N/A|类名：GeofenceRequest<br>方法 or 属性：geofence: Geofence;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：Geofence<br>方法 or 属性：latitude: number;<br>起始版本：N/A|类名：Geofence<br>方法 or 属性：latitude: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：Geofence<br>方法 or 属性：longitude: number;<br>起始版本：N/A|类名：Geofence<br>方法 or 属性：longitude: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：Geofence<br>方法 or 属性：radius: number;<br>起始版本：N/A|类名：Geofence<br>方法 or 属性：radius: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：Geofence<br>方法 or 属性：expiration: number;<br>起始版本：N/A|类名：Geofence<br>方法 or 属性：expiration: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：ReverseGeoCodeRequest<br>方法 or 属性：locale?: string;<br>起始版本：N/A|类名：ReverseGeoCodeRequest<br>方法 or 属性：locale?: string;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：ReverseGeoCodeRequest<br>方法 or 属性：latitude: number;<br>起始版本：N/A|类名：ReverseGeoCodeRequest<br>方法 or 属性：latitude: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：ReverseGeoCodeRequest<br>方法 or 属性：longitude: number;<br>起始版本：N/A|类名：ReverseGeoCodeRequest<br>方法 or 属性：longitude: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：ReverseGeoCodeRequest<br>方法 or 属性：maxItems?: number;<br>起始版本：N/A|类名：ReverseGeoCodeRequest<br>方法 or 属性：maxItems?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeoCodeRequest<br>方法 or 属性：locale?: string;<br>起始版本：N/A|类名：GeoCodeRequest<br>方法 or 属性：locale?: string;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeoCodeRequest<br>方法 or 属性：description: string;<br>起始版本：N/A|类名：GeoCodeRequest<br>方法 or 属性：description: string;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeoCodeRequest<br>方法 or 属性：maxItems?: number;<br>起始版本：N/A|类名：GeoCodeRequest<br>方法 or 属性：maxItems?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeoCodeRequest<br>方法 or 属性：minLatitude?: number;<br>起始版本：N/A|类名：GeoCodeRequest<br>方法 or 属性：minLatitude?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeoCodeRequest<br>方法 or 属性：minLongitude?: number;<br>起始版本：N/A|类名：GeoCodeRequest<br>方法 or 属性：minLongitude?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeoCodeRequest<br>方法 or 属性：maxLatitude?: number;<br>起始版本：N/A|类名：GeoCodeRequest<br>方法 or 属性：maxLatitude?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：GeoCodeRequest<br>方法 or 属性：maxLongitude?: number;<br>起始版本：N/A|类名：GeoCodeRequest<br>方法 or 属性：maxLongitude?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequest<br>方法 or 属性：priority?: LocationRequestPriority;<br>起始版本：N/A|类名：LocationRequest<br>方法 or 属性：priority?: LocationRequestPriority;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequest<br>方法 or 属性：scenario?: LocationRequestScenario;<br>起始版本：N/A|类名：LocationRequest<br>方法 or 属性：scenario?: LocationRequestScenario;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequest<br>方法 or 属性：timeInterval?: number;<br>起始版本：N/A|类名：LocationRequest<br>方法 or 属性：timeInterval?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequest<br>方法 or 属性：distanceInterval?: number;<br>起始版本：N/A|类名：LocationRequest<br>方法 or 属性：distanceInterval?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequest<br>方法 or 属性：maxAccuracy?: number;<br>起始版本：N/A|类名：LocationRequest<br>方法 or 属性：maxAccuracy?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CurrentLocationRequest<br>方法 or 属性：priority?: LocationRequestPriority;<br>起始版本：N/A|类名：CurrentLocationRequest<br>方法 or 属性：priority?: LocationRequestPriority;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CurrentLocationRequest<br>方法 or 属性：scenario?: LocationRequestScenario;<br>起始版本：N/A|类名：CurrentLocationRequest<br>方法 or 属性：scenario?: LocationRequestScenario;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CurrentLocationRequest<br>方法 or 属性：maxAccuracy?: number;<br>起始版本：N/A|类名：CurrentLocationRequest<br>方法 or 属性：maxAccuracy?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CurrentLocationRequest<br>方法 or 属性：timeoutMs?: number;<br>起始版本：N/A|类名：CurrentLocationRequest<br>方法 or 属性：timeoutMs?: number;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestPriority<br>方法 or 属性：UNSET = 0x200<br>起始版本：N/A|类名：LocationRequestPriority<br>方法 or 属性：UNSET = 0x200<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestPriority<br>方法 or 属性：ACCURACY<br>起始版本：N/A|类名：LocationRequestPriority<br>方法 or 属性：ACCURACY<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestPriority<br>方法 or 属性：LOW_POWER<br>起始版本：N/A|类名：LocationRequestPriority<br>方法 or 属性：LOW_POWER<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestPriority<br>方法 or 属性：FIRST_FIX<br>起始版本：N/A|类名：LocationRequestPriority<br>方法 or 属性：FIRST_FIX<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestScenario<br>方法 or 属性：UNSET = 0x300<br>起始版本：N/A|类名：LocationRequestScenario<br>方法 or 属性：UNSET = 0x300<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestScenario<br>方法 or 属性：NAVIGATION<br>起始版本：N/A|类名：LocationRequestScenario<br>方法 or 属性：NAVIGATION<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestScenario<br>方法 or 属性：TRAJECTORY_TRACKING<br>起始版本：N/A|类名：LocationRequestScenario<br>方法 or 属性：TRAJECTORY_TRACKING<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestScenario<br>方法 or 属性：CAR_HAILING<br>起始版本：N/A|类名：LocationRequestScenario<br>方法 or 属性：CAR_HAILING<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestScenario<br>方法 or 属性：DAILY_LIFE_SERVICE<br>起始版本：N/A|类名：LocationRequestScenario<br>方法 or 属性：DAILY_LIFE_SERVICE<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationRequestScenario<br>方法 or 属性：NO_POWER<br>起始版本：N/A|类名：LocationRequestScenario<br>方法 or 属性：NO_POWER<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationPrivacyType<br>方法 or 属性：OTHERS = 0<br>起始版本：N/A|类名：LocationPrivacyType<br>方法 or 属性：OTHERS = 0<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationPrivacyType<br>方法 or 属性：STARTUP<br>起始版本：N/A|类名：LocationPrivacyType<br>方法 or 属性：STARTUP<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationPrivacyType<br>方法 or 属性：CORE_LOCATION<br>起始版本：N/A|类名：LocationPrivacyType<br>方法 or 属性：CORE_LOCATION<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationCommand<br>方法 or 属性：scenario: LocationRequestScenario;<br>起始版本：N/A|类名：LocationCommand<br>方法 or 属性：scenario: LocationRequestScenario;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：LocationCommand<br>方法 or 属性：command: string;<br>起始版本：N/A|类名：LocationCommand<br>方法 or 属性：command: string;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CountryCode<br>方法 or 属性：country: string;<br>起始版本：N/A|类名：CountryCode<br>方法 or 属性：country: string;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CountryCode<br>方法 or 属性：type: CountryCodeType;<br>起始版本：N/A|类名：CountryCode<br>方法 or 属性：type: CountryCodeType;<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_LOCALE = 1<br>起始版本：N/A|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_LOCALE = 1<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_SIM<br>起始版本：N/A|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_SIM<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_LOCATION<br>起始版本：N/A|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_LOCATION<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|起始版本有变化|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_NETWORK<br>起始版本：N/A|类名：CountryCodeType<br>方法 or 属性：COUNTRY_CODE_FROM_NETWORK<br>起始版本：9|@ohos.geoLocationManager.d.ts|
|新增(错误码)|NA|类名：geoLocationManager<br>方法 or 属性：function enableLocation(): Promise<void>;<br>错误码内容:201,202,801,3301000|@ohos.geoLocationManager.d.ts|
|新增(错误码)|NA|类名：geoLocationManager<br>方法 or 属性：function getCountryCode(): Promise<CountryCode>;<br>错误码内容:801,3301000,3301500|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：ReverseGeocodingMockInfo<br>方法 or 属性：location: ReverseGeoCodeRequest;<br>访问级别：公开API|类名：ReverseGeocodingMockInfo<br>方法 or 属性：location: ReverseGeoCodeRequest;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：ReverseGeocodingMockInfo<br>方法 or 属性：geoAddress: GeoAddress;<br>访问级别：公开API|类名：ReverseGeocodingMockInfo<br>方法 or 属性：geoAddress: GeoAddress;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationMockConfig<br>方法 or 属性：timeInterval: number;<br>访问级别：公开API|类名：LocationMockConfig<br>方法 or 属性：timeInterval: number;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationMockConfig<br>方法 or 属性：locations: Array<Location>;<br>访问级别：公开API|类名：LocationMockConfig<br>方法 or 属性：locations: Array<Location>;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：GeoAddress<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：公开API|类名：GeoAddress<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：Location<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：公开API|类名：Location<br>方法 or 属性：isFromMock?: Boolean;<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>访问级别：公开API|类名：LocationPrivacyType<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>方法 or 属性：OTHERS = 0<br>访问级别：公开API|类名：LocationPrivacyType<br>方法 or 属性：OTHERS = 0<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>方法 or 属性：STARTUP<br>访问级别：公开API|类名：LocationPrivacyType<br>方法 or 属性：STARTUP<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
|访问级别有变化|类名：LocationPrivacyType<br>方法 or 属性：CORE_LOCATION<br>访问级别：公开API|类名：LocationPrivacyType<br>方法 or 属性：CORE_LOCATION<br>访问级别：系统API|@ohos.geoLocationManager.d.ts|
