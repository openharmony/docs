| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：GeoLocationErrorCode<br>方法or属性：INPUT_PARAMS_ERROR|@ohos.geolocation.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function on(type: 'locationChange', request: LocationRequest, callback: Callback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function off(type: 'locationChange', callback?: Callback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function on(type: 'locationEnabledChange', callback: Callback\<boolean>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function off(type: 'locationEnabledChange', callback?: Callback\<boolean>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function on(type: 'cachedGnssLocationsChange', request: CachedGnssLocationsRequest, callback: Callback\<Array\<Location>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function off(type: 'cachedGnssLocationsChange', callback?: Callback\<Array\<Location>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function on(type: 'satelliteStatusChange', callback: Callback\<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function off(type: 'satelliteStatusChange', callback?: Callback\<SatelliteStatusInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function on(type: 'nmeaMessage', callback: Callback\<string>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function off(type: 'nmeaMessage', callback?: Callback\<string>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function on(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function off(type: 'gnssFenceStatusChange', request: GeofenceRequest, want: WantAgent): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function on(type: 'countryCodeChange', callback: Callback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function off(type: 'countryCodeChange', callback?: Callback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getCurrentLocation(request: CurrentLocationRequest, callback: AsyncCallback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getCurrentLocation(callback: AsyncCallback\<Location>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getCurrentLocation(request?: CurrentLocationRequest): Promise\<Location>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getLastLocation(): Location;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function isLocationEnabled(): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function enableLocation(callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function enableLocation(): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function disableLocation(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getAddressesFromLocation(request: ReverseGeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getAddressesFromLocation(request: ReverseGeoCodeRequest): Promise\<Array\<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getAddressesFromLocationName(request: GeoCodeRequest, callback: AsyncCallback\<Array\<GeoAddress>>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getAddressesFromLocationName(request: GeoCodeRequest): Promise\<Array\<GeoAddress>>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function isGeocoderAvailable(): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getCachedGnssLocationsSize(callback: AsyncCallback\<number>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getCachedGnssLocationsSize(): Promise\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function flushCachedGnssLocations(callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function flushCachedGnssLocations(): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function sendCommand(command: LocationCommand, callback: AsyncCallback\<void>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function sendCommand(command: LocationCommand): Promise\<void>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getCountryCode(callback: AsyncCallback\<CountryCode>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function getCountryCode(): Promise\<CountryCode>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function enableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function disableLocationMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function setMockedLocations(config: LocationMockConfig): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function enableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function disableReverseGeocodingMock(): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function setReverseGeocodingMockInfo(mockInfos: Array\<ReverseGeocodingMockInfo>): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function isLocationPrivacyConfirmed(type: LocationPrivacyType): boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: geoLocationManager<br>方法 or 属性: function setLocationPrivacyConfirmStatus(type: LocationPrivacyType, isConfirmed: boolean): void;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeocodingMockInfo|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeocodingMockInfo<br>方法 or 属性: location: ReverseGeoCodeRequest;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeocodingMockInfo<br>方法 or 属性: geoAddress: GeoAddress;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationMockConfig|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationMockConfig<br>方法 or 属性: timeInterval: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationMockConfig<br>方法 or 属性: locations: Array\<Location>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: SatelliteStatusInfo|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: SatelliteStatusInfo<br>方法 or 属性: satellitesNumber: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: SatelliteStatusInfo<br>方法 or 属性: satelliteIds: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: SatelliteStatusInfo<br>方法 or 属性: carrierToNoiseDensitys: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: SatelliteStatusInfo<br>方法 or 属性: altitudes: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: SatelliteStatusInfo<br>方法 or 属性: azimuths: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: SatelliteStatusInfo<br>方法 or 属性: carrierFrequencies: Array\<number>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CachedGnssLocationsRequest|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CachedGnssLocationsRequest<br>方法 or 属性: reportingPeriodSec: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CachedGnssLocationsRequest<br>方法 or 属性: wakeUpCacheQueueFull: boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeofenceRequest|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeofenceRequest<br>方法 or 属性: scenario: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeofenceRequest<br>方法 or 属性: geofence: Geofence;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Geofence|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Geofence<br>方法 or 属性: latitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Geofence<br>方法 or 属性: longitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Geofence<br>方法 or 属性: radius: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Geofence<br>方法 or 属性: expiration: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeoCodeRequest|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeoCodeRequest<br>方法 or 属性: locale?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeoCodeRequest<br>方法 or 属性: latitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeoCodeRequest<br>方法 or 属性: longitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: ReverseGeoCodeRequest<br>方法 or 属性: maxItems?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest<br>方法 or 属性: locale?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest<br>方法 or 属性: description: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest<br>方法 or 属性: maxItems?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest<br>方法 or 属性: minLatitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest<br>方法 or 属性: minLongitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest<br>方法 or 属性: maxLatitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoCodeRequest<br>方法 or 属性: maxLongitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: latitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: longitude?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: locale?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: placeName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: countryCode?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: countryName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: administrativeArea?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: subAdministrativeArea?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: locality?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: subLocality?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: roadName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: subRoadName?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: premises?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: postalCode?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: phoneNumber?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: addressUrl?: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: descriptions?: Array\<string>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: descriptionsSize?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: GeoAddress<br>方法 or 属性: isFromMock?: Boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequest|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequest<br>方法 or 属性: priority?: LocationRequestPriority;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequest<br>方法 or 属性: scenario?: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequest<br>方法 or 属性: timeInterval?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequest<br>方法 or 属性: distanceInterval?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequest<br>方法 or 属性: maxAccuracy?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CurrentLocationRequest|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CurrentLocationRequest<br>方法 or 属性: priority?: LocationRequestPriority;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CurrentLocationRequest<br>方法 or 属性: scenario?: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CurrentLocationRequest<br>方法 or 属性: maxAccuracy?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CurrentLocationRequest<br>方法 or 属性: timeoutMs?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: latitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: longitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: altitude: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: accuracy: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: speed: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: timeStamp: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: direction: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: timeSinceBoot: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: additions?: Array\<string>;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: additionSize?: number;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: Location<br>方法 or 属性: isFromMock?: Boolean;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestPriority|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestPriority<br>方法 or 属性: UNSET = 0x200|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestPriority<br>方法 or 属性: ACCURACY|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestPriority<br>方法 or 属性: LOW_POWER|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestPriority<br>方法 or 属性: FIRST_FIX|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestScenario|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestScenario<br>方法 or 属性: UNSET = 0x300|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestScenario<br>方法 or 属性: NAVIGATION|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestScenario<br>方法 or 属性: TRAJECTORY_TRACKING|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestScenario<br>方法 or 属性: CAR_HAILING|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestScenario<br>方法 or 属性: DAILY_LIFE_SERVICE|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationRequestScenario<br>方法 or 属性: NO_POWER|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationPrivacyType|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationPrivacyType<br>方法 or 属性: OTHERS = 0|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationPrivacyType<br>方法 or 属性: STARTUP|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationPrivacyType<br>方法 or 属性: CORE_LOCATION|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationCommand|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationCommand<br>方法 or 属性: scenario: LocationRequestScenario;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: LocationCommand<br>方法 or 属性: command: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCode|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCode<br>方法 or 属性: country: string;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCode<br>方法 or 属性: type: CountryCodeType;|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCodeType|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCodeType<br>方法 or 属性: COUNTRY_CODE_FROM_LOCALE = 1|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCodeType<br>方法 or 属性: COUNTRY_CODE_FROM_SIM|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCodeType<br>方法 or 属性: COUNTRY_CODE_FROM_LOCATION|@ohos.geoLocationManager.d.ts|
|新增|NA|模块名: ohos.geoLocationManager<br>类名: CountryCodeType<br>方法 or 属性: COUNTRY_CODE_FROM_NETWORK|@ohos.geoLocationManager.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function enableLocation(callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function enableLocation() : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function disableLocation(callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function disableLocation() : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function isLocationPrivacyConfirmed(type : LocationPrivacyType, callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function isLocationPrivacyConfirmed(type : LocationPrivacyType,) : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean, callback: AsyncCallback\<boolean>) : void;|NA|@ohos.geolocation.d.ts|
|删除|模块名：ohos.geolocation<br>类名:geolocation<br>方法 or 属性:function setLocationPrivacyConfirmStatus(type : LocationPrivacyType, isConfirmed : boolean) : Promise\<boolean>;|NA|@ohos.geolocation.d.ts|
|废弃版本有变化|类名：geolocation<br>废弃版本：N/A|类名：geolocation<br>废弃版本：9<br>代替接口：N/A|@ohos.geolocation.d.ts|
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
|废弃版本有变化|类名：Geolocation<br>方法 or 属性：static getSupportedCoordTypes(): Array\<string>;<br>废弃版本：N/A|类名：Geolocation<br>方法 or 属性：static getSupportedCoordTypes(): Array\<string>;<br>废弃版本：9<br>代替接口：N/A|@system.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：latitude?: number;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：latitude?: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：longitude?: number;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：longitude?: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：locale?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：locale?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：placeName?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：placeName?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：countryCode?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：countryCode?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：countryName?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：countryName?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：administrativeArea?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：administrativeArea?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：subAdministrativeArea?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：subAdministrativeArea?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：locality?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：locality?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：subLocality?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：subLocality?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：roadName?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：roadName?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：subRoadName?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：subRoadName?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：premises?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：premises?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：postalCode?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：postalCode?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：phoneNumber?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：phoneNumber?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：addressUrl?: string;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：addressUrl?: string;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：descriptions?: Array\<string>;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：descriptions?: Array\<string>;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoAddress<br>方法 or 属性：descriptionsSize?: number;<br>起始版本：N/A|类名：GeoAddress<br>方法 or 属性：descriptionsSize?: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：latitude: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：latitude: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：longitude: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：longitude: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：altitude: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：altitude: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：accuracy: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：accuracy: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：speed: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：speed: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：timeStamp: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：timeStamp: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：direction: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：direction: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：timeSinceBoot: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：timeSinceBoot: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：additions?: Array\<string>;<br>起始版本：N/A|类名：Location<br>方法 or 属性：additions?: Array\<string>;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：Location<br>方法 or 属性：additionSize?: number;<br>起始版本：N/A|类名：Location<br>方法 or 属性：additionSize?: number;<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoLocationErrorCode<br>方法 or 属性：REVERSE_GEOCODE_ERROR<br>起始版本：N/A|类名：GeoLocationErrorCode<br>方法 or 属性：REVERSE_GEOCODE_ERROR<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoLocationErrorCode<br>方法 or 属性：GEOCODE_ERROR<br>起始版本：N/A|类名：GeoLocationErrorCode<br>方法 or 属性：GEOCODE_ERROR<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoLocationErrorCode<br>方法 or 属性：LOCATOR_ERROR<br>起始版本：N/A|类名：GeoLocationErrorCode<br>方法 or 属性：LOCATOR_ERROR<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoLocationErrorCode<br>方法 or 属性：LOCATION_SWITCH_ERROR<br>起始版本：N/A|类名：GeoLocationErrorCode<br>方法 or 属性：LOCATION_SWITCH_ERROR<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoLocationErrorCode<br>方法 or 属性：LAST_KNOWN_LOCATION_ERROR<br>起始版本：N/A|类名：GeoLocationErrorCode<br>方法 or 属性：LAST_KNOWN_LOCATION_ERROR<br>起始版本：7|@ohos.geolocation.d.ts|
|起始版本有变化|类名：GeoLocationErrorCode<br>方法 or 属性：LOCATION_REQUEST_TIMEOUT_ERROR<br>起始版本：N/A|类名：GeoLocationErrorCode<br>方法 or 属性：LOCATION_REQUEST_TIMEOUT_ERROR<br>起始版本：7|@ohos.geolocation.d.ts|
