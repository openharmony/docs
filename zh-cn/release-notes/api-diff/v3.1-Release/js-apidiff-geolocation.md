# 位置服务子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，位置服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.geolocation | LocationCommand | command: string; | 新增 |
| ohos.geolocation | LocationCommand | scenario: LocationRequestScenario; | 新增 |
| ohos.geolocation | LocationPrivacyType | CORE_LOCATION | 新增 |
| ohos.geolocation | LocationPrivacyType | STARTUP | 新增 |
| ohos.geolocation | LocationPrivacyType | OTHERS = 0 | 新增 |
| ohos.geolocation | GeoLocationErrorCode | LOCATION_REQUEST_TIMEOUT_ERROR | 新增 |
| ohos.geolocation | GeoLocationErrorCode | LAST_KNOWN_LOCATION_ERROR | 新增 |
| ohos.geolocation | GeoLocationErrorCode | LOCATION_SWITCH_ERROR | 新增 |
| ohos.geolocation | GeoLocationErrorCode | LOCATOR_ERROR | 新增 |
| ohos.geolocation | GeoLocationErrorCode | GEOCODE_ERROR | 新增 |
| ohos.geolocation | GeoLocationErrorCode | REVERSE_GEOCODE_ERROR | 新增 |
| ohos.geolocation | GeoLocationErrorCode | INPUT_PARAMS_ERROR = 101 | 新增 |
| ohos.geolocation | LocationRequestScenario | NO_POWER | 新增 |
| ohos.geolocation | LocationRequestScenario | DAILY_LIFE_SERVICE | 新增 |
| ohos.geolocation | LocationRequestScenario | CAR_HAILING | 新增 |
| ohos.geolocation | LocationRequestScenario | TRAJECTORY_TRACKING | 新增 |
| ohos.geolocation | LocationRequestScenario | NAVIGATION | 新增 |
| ohos.geolocation | LocationRequestScenario | UNSET = 0x300 | 新增 |
| ohos.geolocation | LocationRequestPriority | FIRST_FIX | 新增 |
| ohos.geolocation | LocationRequestPriority | LOW_POWER | 新增 |
| ohos.geolocation | LocationRequestPriority | ACCURACY | 新增 |
| ohos.geolocation | LocationRequestPriority | UNSET = 0x200 | 新增 |
| ohos.geolocation | Location | additionSize?: number; | 新增 |
| ohos.geolocation | Location | additions?: Array\<string>; | 新增 |
| ohos.geolocation | Location | timeSinceBoot: number; | 新增 |
| ohos.geolocation | Location | direction: number; | 新增 |
| ohos.geolocation | Location | timeStamp: number; | 新增 |
| ohos.geolocation | Location | speed: number; | 新增 |
| ohos.geolocation | Location | accuracy: number; | 新增 |
| ohos.geolocation | Location | altitude: number; | 新增 |
| ohos.geolocation | Location | longitude: number; | 新增 |
| ohos.geolocation | Location | latitude: number; | 新增 |
| ohos.geolocation | CurrentLocationRequest | timeoutMs?: number; | 新增 |
| ohos.geolocation | CurrentLocationRequest | maxAccuracy?: number; | 新增 |
| ohos.geolocation | CurrentLocationRequest | scenario?: LocationRequestScenario; | 新增 |
| ohos.geolocation | CurrentLocationRequest | priority?: LocationRequestPriority; | 新增 |
| ohos.geolocation | LocationRequest | maxAccuracy?: number; | 新增 |
| ohos.geolocation | LocationRequest | distanceInterval?: number; | 新增 |
| ohos.geolocation | LocationRequest | timeInterval?: number; | 新增 |
| ohos.geolocation | LocationRequest | scenario?: LocationRequestScenario; | 新增 |
| ohos.geolocation | LocationRequest | priority?: LocationRequestPriority; | 新增 |
| ohos.geolocation | GeoAddress | descriptionsSize?: number; | 新增 |
| ohos.geolocation | GeoAddress | descriptions?: Array\<string>; | 新增 |
| ohos.geolocation | GeoAddress | addressUrl?: string; | 新增 |
| ohos.geolocation | GeoAddress | phoneNumber?: string; | 新增 |
| ohos.geolocation | GeoAddress | postalCode?: string; | 新增 |
| ohos.geolocation | GeoAddress | premises?: string; | 新增 |
| ohos.geolocation | GeoAddress | subRoadName?: string; | 新增 |
| ohos.geolocation | GeoAddress | roadName?: string; | 新增 |
| ohos.geolocation | GeoAddress | subLocality?: string; | 新增 |
| ohos.geolocation | GeoAddress | locality?: string; | 新增 |
| ohos.geolocation | GeoAddress | subAdministrativeArea?: string; | 新增 |
| ohos.geolocation | GeoAddress | administrativeArea?: string; | 新增 |
| ohos.geolocation | GeoAddress | countryName?: string; | 新增 |
| ohos.geolocation | GeoAddress | countryCode?: string; | 新增 |
| ohos.geolocation | GeoAddress | placeName?: string; | 新增 |
| ohos.geolocation | GeoAddress | locale?: string; | 新增 |
| ohos.geolocation | GeoAddress | longitude?: number; | 新增 |
| ohos.geolocation | GeoAddress | latitude?: number; | 新增 |
| ohos.geolocation | GeoCodeRequest | maxLongitude?: number; | 新增 |
| ohos.geolocation | GeoCodeRequest | maxLatitude?: number; | 新增 |
| ohos.geolocation | GeoCodeRequest | minLongitude?: number; | 新增 |
| ohos.geolocation | GeoCodeRequest | minLatitude?: number; | 新增 |
| ohos.geolocation | GeoCodeRequest | maxItems?: number; | 新增 |
| ohos.geolocation | GeoCodeRequest | description: string; | 新增 |
| ohos.geolocation | GeoCodeRequest | locale?: string; | 新增 |
| ohos.geolocation | ReverseGeoCodeRequest | maxItems?: number; | 新增 |
| ohos.geolocation | ReverseGeoCodeRequest | longitude: number; | 新增 |
| ohos.geolocation | ReverseGeoCodeRequest | latitude: number; | 新增 |
| ohos.geolocation | ReverseGeoCodeRequest | locale?: string; | 新增 |
| ohos.geolocation | Geofence | expiration: number; | 新增 |
| ohos.geolocation | Geofence | radius: number; | 新增 |
| ohos.geolocation | Geofence | longitude: number; | 新增 |
| ohos.geolocation | Geofence | latitude: number; | 新增 |
| ohos.geolocation | GeofenceRequest | geofence: Geofence; | 新增 |
| ohos.geolocation | GeofenceRequest | scenario: LocationRequestScenario; | 新增 |
| ohos.geolocation | GeofenceRequest | priority: LocationRequestPriority; | 新增 |
| ohos.geolocation | CachedGnssLocationsRequest | wakeUpCacheQueueFull: boolean; | 新增 |
| ohos.geolocation | CachedGnssLocationsRequest | reportingPeriodSec: number; | 新增 |
| ohos.geolocation | SatelliteStatusInfo | carrierFrequencies: Array\<number>; | 新增 |
| ohos.geolocation | SatelliteStatusInfo | azimuths: Array\<number>; | 新增 |
| ohos.geolocation | SatelliteStatusInfo | altitudes: Array\<number>; | 新增 |
| ohos.geolocation | SatelliteStatusInfo | carrierToNoiseDensitys: Array\<number>; | 新增 |
| ohos.geolocation | SatelliteStatusInfo | satelliteIds: Array\<number>; | 新增 |
| ohos.geolocation | SatelliteStatusInfo | satellitesNumber: number; | 新增 |
| ohos.geolocation | geolocation | sendCommand(command: LocationCommand, callback: AsyncCallback\<boolean>) : void;<br>sendCommand(command: LocationCommand) : Promise\<boolean>; | 新增 |
| ohos.geolocation | geolocation | flushCachedGnssLocations(callback: AsyncCallback\<boolean>) : void;<br>flushCachedGnssLocations() : Promise\<boolean>; | 新增 |
| ohos.geolocation | geolocation | getCachedGnssLocationsSize(callback: AsyncCallback\<number>) : void;<br>getCachedGnssLocationsSize() : Promise\<number>; | 新增 |
| ohos.geolocation | geolocation | isGeoServiceAvailable(callback: AsyncCallback\<boolean>) : void;<br>isGeoServiceAvailable() : Promise\<boolean>; | 新增 |
| ohos.geolocation | geolocation | getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>) : void;<br>getAddressesFromLocationName(request: GeoCodeRequest) : Promise\<Array\<GeoAddress>>; | 新增 |
| ohos.geolocation | geolocation | getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>) : void;<br>getAddressesFromLocation(request: ReverseGeoCodeRequest) : Promise\<Array\<GeoAddress>>; | 新增 |
| ohos.geolocation | geolocation | requestEnableLocation(callback: AsyncCallback\<boolean>) : void;<br>requestEnableLocation() : Promise\<boolean>; | 新增 |
| ohos.geolocation | geolocation | isLocationEnabled(callback: AsyncCallback\<boolean>) : void;<br>isLocationEnabled() : Promise\<boolean>; | 新增 |
| ohos.geolocation | geolocation | getLastLocation(callback: AsyncCallback\<Location>) : void;<br>getLastLocation() : Promise\<Location>; | 新增 |
| ohos.geolocation | geolocation | getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>) : void;<br>getCurrentLocation(callback: AsyncCallback\<Location>) : void;<br>getCurrentLocation(request?: CurrentLocationRequest) : Promise\<Location>; | 新增 |
| ohos.geolocation | geolocation | off(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | 新增 |
| ohos.geolocation | geolocation | on(type: 'fenceStatusChange', request: GeofenceRequest, want: WantAgent) : void; | 新增 |
| ohos.geolocation | geolocation | off(type: 'nmeaMessageChange', callback?: Callback\<string>) : void; | 新增 |
| ohos.geolocation | geolocation | on(type: 'nmeaMessageChange', callback: Callback\<string>) : void; | 新增 |
| ohos.geolocation | geolocation | off(type: 'gnssStatusChange', callback?: Callback\<SatelliteStatusInfo>) : void; | 新增 |
| ohos.geolocation | geolocation | on(type: 'gnssStatusChange', callback: Callback\<SatelliteStatusInfo>) : void; | 新增 |
| ohos.geolocation | geolocation | off(type: 'cachedGnssLocationsReporting', callback?: Callback\<Array\<Location>>) : void; | 新增 |
| ohos.geolocation | geolocation | on(type: 'cachedGnssLocationsReporting', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>) : void; | 新增 |
| ohos.geolocation | geolocation | off(type: 'locationServiceState', callback?: Callback\<boolean>) : void; | 新增 |
| ohos.geolocation | geolocation | on(type: 'locationServiceState', callback: Callback\<boolean>) : void; | 新增 |
| ohos.geolocation | geolocation | off(type: 'locationChange', callback?: Callback\<Location>) : void; | 新增 |
| ohos.geolocation | geolocation | on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>) : void; | 新增 |
