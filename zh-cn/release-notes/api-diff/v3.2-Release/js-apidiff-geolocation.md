| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|删除|类名：geolocation;<br>方法or属性：function enableLocation(callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|类名：geolocation;<br>方法or属性：function enableLocation() : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|类名：geolocation;<br>方法or属性：function disableLocation(callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|类名：geolocation;<br>方法or属性：function disableLocation() : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|类名：geolocation;<br>方法or属性：function isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|类名：geolocation;<br>方法or属性：function isLocationPrivacyConfirmed(type : LocationPrivacyType,) : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|类名：geolocation;<br>方法or属性：function setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean, callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|类名：geolocation;<br>方法or属性：function setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean) : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'locationEnabledChange', callback: Callback\<boolean>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'satelliteStatusChange', callback: Callback\<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'nmeaMessage', callback: Callback\<string>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function on(type: 'countryCodeChange', callback: Callback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'locationChange', callback?: Callback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'locationEnabledChange', callback?: Callback\<boolean>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'cachedGnssLocationsChange', callback?: Callback\<Array\<Location>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'satelliteStatusChange', callback?: Callback\<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'nmeaMessage', callback?: Callback\<string>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function off(type: 'countryCodeChange', callback?: Callback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getCurrentLocation(callback: AsyncCallback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getLastLocation(): Location;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function isLocationEnabled(): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function enableLocation(callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function enableLocation(): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function disableLocation(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function isGeocoderAvailable(): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getCachedGnssLocationsSize(callback: AsyncCallback\<number>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getCachedGnssLocationsSize(): Promise\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function flushCachedGnssLocations(callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function flushCachedGnssLocations(): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function sendCommand(command: LocationCommand, callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function sendCommand(command: LocationCommand): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getCountryCode(callback: AsyncCallback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function getCountryCode(): Promise\<CountryCode>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function enableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function disableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function setMockedLocations(config: LocationMockConfig): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function enableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function disableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：geoLocationManager;<br>方法or属性：function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：ReverseGeocodingMockInfo;<br>方法or属性：location: ReverseGeoCodeRequest;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：ReverseGeocodingMockInfo;<br>方法or属性：geoAddress: GeoAddress;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationMockConfig;<br>方法or属性：timeInterval: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationMockConfig;<br>方法or属性：locations: Array\<Location>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：SatelliteStatusInfo;<br>方法or属性：satellitesNumber: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：SatelliteStatusInfo;<br>方法or属性：satelliteIds: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：SatelliteStatusInfo;<br>方法or属性：carrierToNoiseDensitys: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：SatelliteStatusInfo;<br>方法or属性：altitudes: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：SatelliteStatusInfo;<br>方法or属性：azimuths: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：SatelliteStatusInfo;<br>方法or属性：carrierFrequencies: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CachedGnssLocationsRequest;<br>方法or属性：reportingPeriodSec: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CachedGnssLocationsRequest;<br>方法or属性：wakeUpCacheQueueFull: boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeofenceRequest;<br>方法or属性：scenario: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationCommand;<br>方法or属性：scenario: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeofenceRequest;<br>方法or属性：geofence: Geofence;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Geofence;<br>方法or属性：latitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：ReverseGeoCodeRequest;<br>方法or属性：latitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：latitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Geofence;<br>方法or属性：longitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：ReverseGeoCodeRequest;<br>方法or属性：longitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：longitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Geofence;<br>方法or属性：radius: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Geofence;<br>方法or属性：expiration: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：ReverseGeoCodeRequest;<br>方法or属性：locale?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoCodeRequest;<br>方法or属性：locale?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：locale?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：ReverseGeoCodeRequest;<br>方法or属性：maxItems?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoCodeRequest;<br>方法or属性：maxItems?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoCodeRequest;<br>方法or属性：description: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoCodeRequest;<br>方法or属性：minLatitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoCodeRequest;<br>方法or属性：minLongitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoCodeRequest;<br>方法or属性：maxLatitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoCodeRequest;<br>方法or属性：maxLongitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：latitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：longitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：placeName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：countryCode?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：countryName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：administrativeArea?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：subAdministrativeArea?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：locality?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：subLocality?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：roadName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：subRoadName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：premises?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：postalCode?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：phoneNumber?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：addressUrl?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：descriptions?: Array\<string>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：descriptionsSize?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：GeoAddress;<br>方法or属性：isFromMock?: Boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：isFromMock?: Boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequest;<br>方法or属性：priority?: LocationRequestPriority;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CurrentLocationRequest;<br>方法or属性：priority?: LocationRequestPriority;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequest;<br>方法or属性：scenario?: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CurrentLocationRequest;<br>方法or属性：scenario?: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequest;<br>方法or属性：timeInterval?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequest;<br>方法or属性：distanceInterval?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequest;<br>方法or属性：maxAccuracy?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CurrentLocationRequest;<br>方法or属性：maxAccuracy?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CurrentLocationRequest;<br>方法or属性：timeoutMs?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：altitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：accuracy: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：speed: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：timeStamp: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：direction: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：timeSinceBoot: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：additions?: Array\<string>;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：additionSize?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestPriority;<br>方法or属性：UNSET = 0x200|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestPriority;<br>方法or属性：ACCURACY|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestPriority;<br>方法or属性：LOW_POWER|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestPriority;<br>方法or属性：FIRST_FIX|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestScenario;<br>方法or属性：UNSET = 0x300|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestScenario;<br>方法or属性：NAVIGATION|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestScenario;<br>方法or属性：TRAJECTORY_TRACKING|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestScenario;<br>方法or属性：CAR_HAILING|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestScenario;<br>方法or属性：DAILY_LIFE_SERVICE|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationRequestScenario;<br>方法or属性：NO_POWER|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationPrivacyType;<br>方法or属性：OTHERS = 0|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationPrivacyType;<br>方法or属性：STARTUP|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationPrivacyType;<br>方法or属性：CORE_LOCATION|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：LocationCommand;<br>方法or属性：command: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CountryCode;<br>方法or属性：country: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CountryCode;<br>方法or属性：type: CountryCodeType;|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CountryCodeType;<br>方法or属性：COUNTRY_CODE_FROM_LOCALE = 1|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CountryCodeType;<br>方法or属性：COUNTRY_CODE_FROM_SIM|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CountryCodeType;<br>方法or属性：COUNTRY_CODE_FROM_LOCATION|@ohos.geoLocationManager.d.ts|
|新增|NA|类名：CountryCodeType;<br>方法or属性：COUNTRY_CODE_FROM_NETWORK|@ohos.geoLocationManager.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：declare geolocation<br>旧版本信息：|类名：geolocation;<br>方法or属性：declare geolocation<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.on#event:locationChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function on(type: 'locationServiceState', callback: Callback\<boolean>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function on(type: 'locationServiceState', callback: Callback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.on#event:locationEnabledChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.on#event:cachedGnssLocationsChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function on(type: 'gnssStatusChange', callback: Callback\<SatelliteStatusInfo>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function on(type: 'gnssStatusChange', callback: Callback\<SatelliteStatusInfo>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.on#event:satelliteStatusChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function on(type: 'nmeaMessageChange', callback: Callback\<string>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function on(type: 'nmeaMessageChange', callback: Callback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.on#event:nmeaMessage|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.on#event:gnssFenceStatusChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function off(type: 'locationChange', callback?: Callback\<Location>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function off(type: 'locationChange', callback?: Callback\<Location>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.off#event:locationChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function off(type: 'locationServiceState', callback?: Callback\<boolean>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function off(type: 'locationServiceState', callback?: Callback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.off#event:locationEnabledChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function off(type: 'cachedGnssLocationsReporting', callback?: Callback\<Array\<Location>>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function off(type: 'cachedGnssLocationsReporting', callback?: Callback\<Array\<Location>>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.off#event:cachedGnssLocationsChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function off(type: 'gnssStatusChange', callback?: Callback\<SatelliteStatusInfo>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function off(type: 'gnssStatusChange', callback?: Callback\<SatelliteStatusInfo>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.off#event:satelliteStatusChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function off(type: 'nmeaMessageChange', callback?: Callback\<string>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function off(type: 'nmeaMessageChange', callback?: Callback\<string>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.off#event:nmeaMessage|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.off#event:gnssFenceStatusChange|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getCurrentLocation|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getCurrentLocation(callback: AsyncCallback\<Location>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCurrentLocation(callback: AsyncCallback\<Location>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getCurrentLocation|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getCurrentLocation|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getLastLocation(callback: AsyncCallback\<Location>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getLastLocation(callback: AsyncCallback\<Location>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getLastLocation|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getLastLocation(): Promise\<Location>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getLastLocation(): Promise\<Location>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getLastLocation|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function isLocationEnabled(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function isLocationEnabled(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.isLocationEnabled|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function isLocationEnabled(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function isLocationEnabled(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.isLocationEnabled|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function requestEnableLocation(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function requestEnableLocation(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function requestEnableLocation(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function requestEnableLocation(): Promise\<boolean>;<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getAddressesFromLocation|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getAddressesFromLocation|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getAddressesFromLocationName|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getAddressesFromLocationName|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function isGeoServiceAvailable(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function isGeoServiceAvailable(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.isGeocoderAvailable|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function isGeoServiceAvailable(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function isGeoServiceAvailable(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.isGeocoderAvailable|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getCachedGnssLocationsSize(callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCachedGnssLocationsSize(callback: AsyncCallback\<number>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getCachedGnssLocationsSize|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function getCachedGnssLocationsSize(): Promise\<number>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function getCachedGnssLocationsSize(): Promise\<number>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getCachedGnssLocationsSize|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function flushCachedGnssLocations(callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function flushCachedGnssLocations(callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.flushCachedGnssLocations|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function flushCachedGnssLocations(): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function flushCachedGnssLocations(): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.flushCachedGnssLocations|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function sendCommand(command: LocationCommand, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function sendCommand(command: LocationCommand, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.sendCommand|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation;<br>方法or属性：function sendCommand(command: LocationCommand): Promise\<boolean>;<br>旧版本信息：|类名：geolocation;<br>方法or属性：function sendCommand(command: LocationCommand): Promise\<boolean>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.sendCommand|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo;<br>方法or属性：export interface SatelliteStatusInfo<br>旧版本信息：|类名：SatelliteStatusInfo;<br>方法or属性：export interface SatelliteStatusInfo<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo;<br>方法or属性：satellitesNumber: number;<br>旧版本信息：|类名：SatelliteStatusInfo;<br>方法or属性：satellitesNumber: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo;<br>方法or属性：satelliteIds: Array\<number>;<br>旧版本信息：|类名：SatelliteStatusInfo;<br>方法or属性：satelliteIds: Array\<number>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo;<br>方法or属性：carrierToNoiseDensitys: Array\<number>;<br>旧版本信息：|类名：SatelliteStatusInfo;<br>方法or属性：carrierToNoiseDensitys: Array\<number>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo;<br>方法or属性：altitudes: Array\<number>;<br>旧版本信息：|类名：SatelliteStatusInfo;<br>方法or属性：altitudes: Array\<number>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo;<br>方法or属性：azimuths: Array\<number>;<br>旧版本信息：|类名：SatelliteStatusInfo;<br>方法or属性：azimuths: Array\<number>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：SatelliteStatusInfo;<br>方法or属性：carrierFrequencies: Array\<number>;<br>旧版本信息：|类名：SatelliteStatusInfo;<br>方法or属性：carrierFrequencies: Array\<number>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.SatelliteStatusInfo|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CachedGnssLocationsRequest;<br>方法or属性：export interface CachedGnssLocationsRequest<br>旧版本信息：|类名：CachedGnssLocationsRequest;<br>方法or属性：export interface CachedGnssLocationsRequest<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CachedGnssLocationsRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CachedGnssLocationsRequest;<br>方法or属性：reportingPeriodSec: number;<br>旧版本信息：|类名：CachedGnssLocationsRequest;<br>方法or属性：reportingPeriodSec: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CachedGnssLocationsRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CachedGnssLocationsRequest;<br>方法or属性：wakeUpCacheQueueFull: boolean;<br>旧版本信息：|类名：CachedGnssLocationsRequest;<br>方法or属性：wakeUpCacheQueueFull: boolean;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CachedGnssLocationsRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeofenceRequest;<br>方法or属性：export interface GeofenceRequest<br>旧版本信息：|类名：GeofenceRequest;<br>方法or属性：export interface GeofenceRequest<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeofenceRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeofenceRequest;<br>方法or属性：priority: LocationRequestPriority;<br>旧版本信息：|类名：GeofenceRequest;<br>方法or属性：priority: LocationRequestPriority;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeofenceRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeofenceRequest;<br>方法or属性：scenario: LocationRequestScenario;<br>旧版本信息：|类名：GeofenceRequest;<br>方法or属性：scenario: LocationRequestScenario;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeofenceRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationCommand;<br>方法or属性：scenario: LocationRequestScenario;<br>旧版本信息：|类名：LocationCommand;<br>方法or属性：scenario: LocationRequestScenario;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationCommand|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeofenceRequest;<br>方法or属性：geofence: Geofence;<br>旧版本信息：|类名：GeofenceRequest;<br>方法or属性：geofence: Geofence;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeofenceRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Geofence;<br>方法or属性：export interface Geofence<br>旧版本信息：|类名：Geofence;<br>方法or属性：export interface Geofence<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Geofence|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Geofence;<br>方法or属性：latitude: number;<br>旧版本信息：|类名：Geofence;<br>方法or属性：latitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Geofence|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：ReverseGeoCodeRequest;<br>方法or属性：latitude: number;<br>旧版本信息：|类名：ReverseGeoCodeRequest;<br>方法or属性：latitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：latitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：latitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Geofence;<br>方法or属性：longitude: number;<br>旧版本信息：|类名：Geofence;<br>方法or属性：longitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Geofence|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：ReverseGeoCodeRequest;<br>方法or属性：longitude: number;<br>旧版本信息：|类名：ReverseGeoCodeRequest;<br>方法or属性：longitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：longitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：longitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Geofence;<br>方法or属性：radius: number;<br>旧版本信息：|类名：Geofence;<br>方法or属性：radius: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Geofence|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Geofence;<br>方法or属性：expiration: number;<br>旧版本信息：|类名：Geofence;<br>方法or属性：expiration: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Geofence|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：ReverseGeoCodeRequest;<br>方法or属性：export interface ReverseGeoCodeRequest<br>旧版本信息：|类名：ReverseGeoCodeRequest;<br>方法or属性：export interface ReverseGeoCodeRequest<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：ReverseGeoCodeRequest;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：ReverseGeoCodeRequest;<br>方法or属性：locale?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：locale?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：locale?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：locale?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：ReverseGeoCodeRequest;<br>方法or属性：maxItems?: number;<br>旧版本信息：|类名：ReverseGeoCodeRequest;<br>方法or属性：maxItems?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.ReverseGeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：maxItems?: number;<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：maxItems?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：export interface GeoCodeRequest<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：export interface GeoCodeRequest<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：description: string;<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：description: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：minLatitude?: number;<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：minLatitude?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：minLongitude?: number;<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：minLongitude?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：maxLatitude?: number;<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：maxLatitude?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoCodeRequest;<br>方法or属性：maxLongitude?: number;<br>旧版本信息：|类名：GeoCodeRequest;<br>方法or属性：maxLongitude?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoCodeRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：export interface GeoAddress<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：export interface GeoAddress<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：latitude?: number;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：latitude?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：longitude?: number;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：longitude?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：placeName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：placeName?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：countryCode?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：countryCode?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：countryName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：countryName?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：administrativeArea?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：administrativeArea?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：subAdministrativeArea?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：subAdministrativeArea?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：locality?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：locality?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：subLocality?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：subLocality?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：roadName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：roadName?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：subRoadName?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：subRoadName?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：premises?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：premises?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：postalCode?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：postalCode?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：phoneNumber?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：phoneNumber?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：addressUrl?: string;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：addressUrl?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：descriptions?: Array\<string>;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：descriptions?: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoAddress;<br>方法or属性：descriptionsSize?: number;<br>旧版本信息：|类名：GeoAddress;<br>方法or属性：descriptionsSize?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.GeoAddress|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequest;<br>方法or属性：export interface LocationRequest<br>旧版本信息：|类名：LocationRequest;<br>方法or属性：export interface LocationRequest<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequest;<br>方法or属性：priority?: LocationRequestPriority;<br>旧版本信息：|类名：LocationRequest;<br>方法or属性：priority?: LocationRequestPriority;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CurrentLocationRequest;<br>方法or属性：priority?: LocationRequestPriority;<br>旧版本信息：|类名：CurrentLocationRequest;<br>方法or属性：priority?: LocationRequestPriority;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequest;<br>方法or属性：scenario?: LocationRequestScenario;<br>旧版本信息：|类名：LocationRequest;<br>方法or属性：scenario?: LocationRequestScenario;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CurrentLocationRequest;<br>方法or属性：scenario?: LocationRequestScenario;<br>旧版本信息：|类名：CurrentLocationRequest;<br>方法or属性：scenario?: LocationRequestScenario;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequest;<br>方法or属性：timeInterval?: number;<br>旧版本信息：|类名：LocationRequest;<br>方法or属性：timeInterval?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequest;<br>方法or属性：distanceInterval?: number;<br>旧版本信息：|类名：LocationRequest;<br>方法or属性：distanceInterval?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequest;<br>方法or属性：maxAccuracy?: number;<br>旧版本信息：|类名：LocationRequest;<br>方法or属性：maxAccuracy?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CurrentLocationRequest;<br>方法or属性：maxAccuracy?: number;<br>旧版本信息：|类名：CurrentLocationRequest;<br>方法or属性：maxAccuracy?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CurrentLocationRequest;<br>方法or属性：export interface CurrentLocationRequest<br>旧版本信息：|类名：CurrentLocationRequest;<br>方法or属性：export interface CurrentLocationRequest<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：CurrentLocationRequest;<br>方法or属性：timeoutMs?: number;<br>旧版本信息：|类名：CurrentLocationRequest;<br>方法or属性：timeoutMs?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：export interface Location<br>旧版本信息：|类名：Location;<br>方法or属性：export interface Location<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：altitude: number;<br>旧版本信息：|类名：Location;<br>方法or属性：altitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：accuracy: number;<br>旧版本信息：|类名：Location;<br>方法or属性：accuracy: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：speed: number;<br>旧版本信息：|类名：Location;<br>方法or属性：speed: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：timeStamp: number;<br>旧版本信息：|类名：Location;<br>方法or属性：timeStamp: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：direction: number;<br>旧版本信息：|类名：Location;<br>方法or属性：direction: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：timeSinceBoot: number;<br>旧版本信息：|类名：Location;<br>方法or属性：timeSinceBoot: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：additions?: Array\<string>;<br>旧版本信息：|类名：Location;<br>方法or属性：additions?: Array\<string>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：Location;<br>方法or属性：additionSize?: number;<br>旧版本信息：|类名：Location;<br>方法or属性：additionSize?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestPriority;<br>方法or属性：export enum LocationRequestPriority<br>旧版本信息：|类名：LocationRequestPriority;<br>方法or属性：export enum LocationRequestPriority<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestPriority|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestPriority;<br>方法or属性：UNSET = 0x200<br>旧版本信息：|类名：LocationRequestPriority;<br>方法or属性：UNSET = 0x200<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestPriority|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestPriority;<br>方法or属性：ACCURACY<br>旧版本信息：|类名：LocationRequestPriority;<br>方法or属性：ACCURACY<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestPriority|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestPriority;<br>方法or属性：LOW_POWER<br>旧版本信息：|类名：LocationRequestPriority;<br>方法or属性：LOW_POWER<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestPriority|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestPriority;<br>方法or属性：FIRST_FIX<br>旧版本信息：|类名：LocationRequestPriority;<br>方法or属性：FIRST_FIX<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestPriority|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario;<br>方法or属性：export enum LocationRequestScenario<br>旧版本信息：|类名：LocationRequestScenario;<br>方法or属性：export enum LocationRequestScenario<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestScenario|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario;<br>方法or属性：UNSET = 0x300<br>旧版本信息：|类名：LocationRequestScenario;<br>方法or属性：UNSET = 0x300<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestScenario|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario;<br>方法or属性：NAVIGATION<br>旧版本信息：|类名：LocationRequestScenario;<br>方法or属性：NAVIGATION<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestScenario|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario;<br>方法or属性：TRAJECTORY_TRACKING<br>旧版本信息：|类名：LocationRequestScenario;<br>方法or属性：TRAJECTORY_TRACKING<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestScenario|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario;<br>方法or属性：CAR_HAILING<br>旧版本信息：|类名：LocationRequestScenario;<br>方法or属性：CAR_HAILING<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestScenario|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario;<br>方法or属性：DAILY_LIFE_SERVICE<br>旧版本信息：|类名：LocationRequestScenario;<br>方法or属性：DAILY_LIFE_SERVICE<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestScenario|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationRequestScenario;<br>方法or属性：NO_POWER<br>旧版本信息：|类名：LocationRequestScenario;<br>方法or属性：NO_POWER<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequestScenario|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：export enum GeoLocationErrorCode<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：export enum GeoLocationErrorCode<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：INPUT_PARAMS_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：INPUT_PARAMS_ERROR<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：REVERSE_GEOCODE_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：REVERSE_GEOCODE_ERROR<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：GEOCODE_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：GEOCODE_ERROR<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：LOCATOR_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LOCATOR_ERROR<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_SWITCH_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_SWITCH_ERROR<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：LAST_KNOWN_LOCATION_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LAST_KNOWN_LOCATION_ERROR<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_REQUEST_TIMEOUT_ERROR<br>旧版本信息：|类名：GeoLocationErrorCode;<br>方法or属性：LOCATION_REQUEST_TIMEOUT_ERROR<br>新版本信息：9<br>代替接口：|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationPrivacyType;<br>方法or属性：export enum LocationPrivacyType<br>旧版本信息：|类名：LocationPrivacyType;<br>方法or属性：export enum LocationPrivacyType<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationPrivacyType|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationPrivacyType;<br>方法or属性：OTHERS = 0<br>旧版本信息：|类名：LocationPrivacyType;<br>方法or属性：OTHERS = 0<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationPrivacyType|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationPrivacyType;<br>方法or属性：STARTUP<br>旧版本信息：|类名：LocationPrivacyType;<br>方法or属性：STARTUP<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationPrivacyType|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationPrivacyType;<br>方法or属性：CORE_LOCATION<br>旧版本信息：|类名：LocationPrivacyType;<br>方法or属性：CORE_LOCATION<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationPrivacyType|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationCommand;<br>方法or属性：export interface LocationCommand<br>旧版本信息：|类名：LocationCommand;<br>方法or属性：export interface LocationCommand<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationCommand|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：LocationCommand;<br>方法or属性：command: string;<br>旧版本信息：|类名：LocationCommand;<br>方法or属性：command: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationCommand|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：GeolocationResponse;<br>方法or属性：export interface GeolocationResponse<br>旧版本信息：|类名：GeolocationResponse;<br>方法or属性：export interface GeolocationResponse<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@system.geolocation.d.ts|
|废弃版本有变化|类名：GeolocationResponse;<br>方法or属性：longitude: number;<br>旧版本信息：|类名：GeolocationResponse;<br>方法or属性：longitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@system.geolocation.d.ts|
|废弃版本有变化|类名：GeolocationResponse;<br>方法or属性：latitude: number;<br>旧版本信息：|类名：GeolocationResponse;<br>方法or属性：latitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@system.geolocation.d.ts|
|废弃版本有变化|类名：GeolocationResponse;<br>方法or属性：altitude: number;<br>旧版本信息：|类名：GeolocationResponse;<br>方法or属性：altitude: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@system.geolocation.d.ts|
|废弃版本有变化|类名：GeolocationResponse;<br>方法or属性：accuracy: number;<br>旧版本信息：|类名：GeolocationResponse;<br>方法or属性：accuracy: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@system.geolocation.d.ts|
|废弃版本有变化|类名：GeolocationResponse;<br>方法or属性：time: number;<br>旧版本信息：|类名：GeolocationResponse;<br>方法or属性：time: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.Location|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationOption;<br>方法or属性：export interface GetLocationOption<br>旧版本信息：|类名：GetLocationOption;<br>方法or属性：export interface GetLocationOption<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationOption;<br>方法or属性：timeout?: number;<br>旧版本信息：|类名：GetLocationOption;<br>方法or属性：timeout?: number;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationOption;<br>方法or属性：coordType?: string;<br>旧版本信息：|类名：GetLocationOption;<br>方法or属性：coordType?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：SubscribeLocationOption;<br>方法or属性：coordType?: string;<br>旧版本信息：|类名：SubscribeLocationOption;<br>方法or属性：coordType?: string;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationOption;<br>方法or属性：success?: (data: GeolocationResponse) => void;<br>旧版本信息：|类名：GetLocationOption;<br>方法or属性：success?: (data: GeolocationResponse) => void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：GetLocationOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：GetLocationTypeOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：9<br>代替接口：|@system.geolocation.d.ts|
|废弃版本有变化|类名：SubscribeLocationOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SubscribeLocationOption;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：GetLocationOption;<br>方法or属性：complete?: () => void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.CurrentLocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeOption;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：GetLocationTypeOption;<br>方法or属性：complete?: () => void;<br>新版本信息：9<br>代替接口：|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeResponse;<br>方法or属性：export interface GetLocationTypeResponse<br>旧版本信息：|类名：GetLocationTypeResponse;<br>方法or属性：export interface GetLocationTypeResponse<br>新版本信息：9<br>代替接口：|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeResponse;<br>方法or属性：types: Array\<string>;<br>旧版本信息：|类名：GetLocationTypeResponse;<br>方法or属性：types: Array\<string>;<br>新版本信息：9<br>代替接口：|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeOption;<br>方法or属性：export interface GetLocationTypeOption<br>旧版本信息：|类名：GetLocationTypeOption;<br>方法or属性：export interface GetLocationTypeOption<br>新版本信息：9<br>代替接口：|@system.geolocation.d.ts|
|废弃版本有变化|类名：GetLocationTypeOption;<br>方法or属性：success?: (data: GetLocationTypeResponse) => void;<br>旧版本信息：|类名：GetLocationTypeOption;<br>方法or属性：success?: (data: GetLocationTypeResponse) => void;<br>新版本信息：9<br>代替接口：|@system.geolocation.d.ts|
|废弃版本有变化|类名：SubscribeLocationOption;<br>方法or属性：export interface SubscribeLocationOption<br>旧版本信息：|类名：SubscribeLocationOption;<br>方法or属性：export interface SubscribeLocationOption<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：SubscribeLocationOption;<br>方法or属性：success: (data: GeolocationResponse) => void;<br>旧版本信息：|类名：SubscribeLocationOption;<br>方法or属性：success: (data: GeolocationResponse) => void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.LocationRequest|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation;<br>方法or属性：export default class Geolocation<br>旧版本信息：|类名：Geolocation;<br>方法or属性：export default class Geolocation<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation;<br>方法or属性：static getLocation(options?: GetLocationOption): void;<br>旧版本信息：|类名：Geolocation;<br>方法or属性：static getLocation(options?: GetLocationOption): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.getCurrentLocation|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation;<br>方法or属性：static getLocationType(options?: GetLocationTypeOption): void;<br>旧版本信息：|类名：Geolocation;<br>方法or属性：static getLocationType(options?: GetLocationTypeOption): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation;<br>方法or属性：static subscribe(options: SubscribeLocationOption): void;<br>旧版本信息：|类名：Geolocation;<br>方法or属性：static subscribe(options: SubscribeLocationOption): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.on#event:locationChange|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation;<br>方法or属性：static unsubscribe(): void;<br>旧版本信息：|类名：Geolocation;<br>方法or属性：static unsubscribe(): void;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager.off#event:locationChange|@system.geolocation.d.ts|
|废弃版本有变化|类名：Geolocation;<br>方法or属性：static getSupportedCoordTypes(): Array\<string>;<br>旧版本信息：|类名：Geolocation;<br>方法or属性：static getSupportedCoordTypes(): Array\<string>;<br>新版本信息：9<br>代替接口： ohos.geoLocationManager/geoLocationManager|@system.geolocation.d.ts|
|函数有变化|类名：GeoLocationErrorCode;<br>方法or属性：INPUT_PARAMS_ERROR = 101|类名：GeoLocationErrorCode;<br>方法or属性：INPUT_PARAMS_ERROR|@ohos.geolocation.d.ts|
